%{
/****************************************************************************
mysql4yacc.y
ParserWizard generated YACC file.

Date: 2020年6月11日
****************************************************************************/

#include "mysql4lex.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <direct.h> 
#include <io.h>
#include<ctype.h>
#include<windows.h>
#define FILE_OPEN_ERROR -1 //文件打开失败
#define IS_NULL -2 //数据库没有数据
#define DUPLICATED -3//已存在
#define null NULL
char dbsystempath[]="C:\\data";//数据库目录
char dbpath[] = "C:\\data\\dat.txt";//数据库信息文件，记录数据库名称
char** dbdatas;//暂存数据
int dbsize;//dbdatas的行数
FILE *fp;//文件指针
char* buff;//缓存
char* database;//当前数据库

char** fieldmap;//表列名和列号对应
int fieldmapsize;//fieldmap的行数
char** valuemap;//即将插入表的数据与列号对应

struct Datastruct{
	char** value;
	int length;
	struct Datastruct* next;
	struct Datastruct* pre;
};

int init();

int readDBs();//从文件中读取数据库信息
int readTables();//从文件中读取表信息
int readTablesName();//调用readTables并处理数据，只留下表名
struct Datastruct* readTableData(char* table);
void useDB(char*);
void lowercase(char*);//转换成小写
void initfieldmap(char* table);//将表的列和列号对应
void initvaluemap(char *table,struct Createfieldsdef* fields,struct Insertvaluedef* values);
int startsWith(char* ,char*);
int postorder(struct Datastruct* data,struct Conditions*  conditions);
char* getValue(struct Datastruct* data,char *field);
int containsDB(char*);
int containsTable(char*);

int* getPosition(char* table,struct Fieldstar* fields);//获取field所在列号
void showDBs();//展示所有数据库
void showTables();

void addDB(char*);
void addTable(char *table,struct Createfieldsdef* fields);

void deleteDBDefinition(char*);//删除数据库时，从dat.txt删除数据库的定义
void deleteTableDefinition(char*);//从dat.txt中删除表的定义

void dropDB(char*);
void dropTable(char*);

void deleteTable(char* table,struct Conditions* conditions);
void insert(char* table,struct Createfieldsdef* fields,struct Insertvaluedef* values);

void selectTable(char* table,struct Conditions* conditions);
void updateTable(char* table,struct Conditions* conditions,char* value);
%}

%union
{
	int num;
	char * yych;//字面量
	struct Createfieldsdef{//create语句中的字段定义
		char *test;
		char *field;//字段名称
		char *type;//字段类型
		struct Createfieldsdef *next;//下一字段
	} *cfdef_var;//字段定义
	
	
	struct Insertvaluedef{//insert value的结构
		char* value;
		struct Insertvaluedef *next;
	}*ivdef_var;
	
	struct Conditions{
		struct Conditions *left;
		struct Conditions *right;
		char* com_op;
		int type;//0是字段 1字符串 2数字
		char* value;
		char* table;
	}*con_var;
	
	struct Fieldstar{
		char* field;
		struct Fieldstar* next;
	}*fs_var;
	
	struct Tables{
		char* table;
		struct Tables* next;
	}*t_var;
	
	struct Updatestruct{
		char* field;
		char* value;
		struct Updatestruct* next;
	}*u_var;
}

%left OR
%left AND
%right NOT
%nonassoc '=' '>' '<'
%left '+','-'
%left '*','/'
%term  CREATE TABLE CHAR INT  DATABASE USE SHOW DATABASES  
%term EXIT QUIT DROP TABLE TABLES INSERT INTO VALUES 
%term SELECT FROM WHERE FALSE TRUE AND NOT OR  DELETE UPDATE SET 
%term<yych> ID NUMBER STRING
%nonterm<yych> table field type databasename  data string expr
%nonterm<cfdef_var> fieldsdefinition field_type fields
%nonterm<ivdef_var> datas 
%nonterm  usedatabasesql showsql exitsql dropsql insertsql selectsql deletesql updatesql createsql 
%nonterm<fs_var> fields_star selectfields
%nonterm<t_var> tables  
%nonterm<con_var>  conditions
%nonterm<con_var>  condition
%nonterm<u_var>  fields_values
%nonterm  statement statements 

%%

statements : statements statement 
			{
			//printf("规约-statements : statements statement\n");
			printf("\nmysql>");
			}
			 | statement
			{
			//printf("规约-statements : statement\n");
			printf("\nmysql>");
			};

statement : usedatabasesql | showsql | createsql | dropsql | insertsql | selectsql | deletesql | updatesql 
			| exitsql 
			{
			exit(0);
			};

usedatabasesql : USE databasename ';'
			{
			//printf("规约-usedatabasesql : USE databasename \';\'  database=%s\n",$2);
			useDB($2);
			};
showsql : SHOW DATABASES ';'
			{
			//printf("规约-showsql : SHOW DATABASES \';\'\n");
			showDBs();
			}
			| SHOW TABLES ';'
			{
			//printf("规约-showsql : SHOW TABLES \';\'\n");
			if(database==NULL){
				printf("请先选定数据库，再做查看操作\n");
				return;
			}
			showTables();
			};
databasename : ID 
			{
			$$=(char*)malloc(strlen($1));
			$$=$1;
			//printf("规约-databasename : ID         databasename=%s\n",$$);
			};

createsql : 
            CREATE DATABASE databasename ';' 
            {
            //printf("规约-createdatabasesql : CREATE DATABASE databasename \';\'  database=%s\n",database);
			addDB($3);
            }
			| CREATE TABLE table '(' fieldsdefinition ')' ';' 
			{
			if(database==NULL){
				printf("请先选定数据库\n");
				return;
			}
			if(containsTable($3)){
				printf("%s已存在\n",$3);
				return;
			}
			//printf("规约-createsql : CREATE TABLE table \'(\' fieldsdefinition \')\' \';\'  table=%s\n",$3);
			addTable($3,$5);
			};

dropsql : 
			DROP DATABASE databasename ';' 
			{
			//printf("规约-dropsql : DROP DATABASE databasename \';\' \n");
			dropDB($3);
			}
			| DROP TABLE table ';'
			{
			if(database==NULL){
				printf("请先选定数据库，再做删除操作\n");
				return;
			}
			//printf("[debug]yacc %d %s\n",containsTable($3),$3);
			//printf("规约-dropsql : DROP TABLE table \';\' \n");
			dropTable($3);
			};

insertsql : INSERT INTO table '(' fields ')' VALUES '(' datas ')' ';' 
			{
			//printf("规约- insertsql : INSERT INTO %s ( fields ) VALUES ( datas ) ; \n",$3);
			if(database==NULL){
				printf("请先选定数据库，再做插入操作\n");
				return;
			}
			//initvaluemap($3,$5,$9);	
			insert($3,$5,$9);
			} 
			| INSERT INTO table VALUES '(' datas ')' ';' 
			{
			//printf("规约- insertsql : INSERT INTO %s VALUES ( datas ) ; \n",$3);
			if(database==NULL){
				printf("请先选定数据库，再做插入操作\n");
				return;
			}
			insert($3,NULL,$6);
			//while($6!=null){
			//	printf("[debug] %s %p\n",$6->value,$6->next);
			//	$6=$6->next;
			//}
			};
			
selectsql : SELECT fields_star FROM tables ';' 
				{
				//printf("规约-selectsql :SELECT fields_star FROM tables ; \n");
					while($4!=null){
						selectTable($4->table,$2,null);
						$4=$4->next;
					}
				}
				| SELECT fields_star FROM tables WHERE conditions ';' 
				{
				//printf("规约-selectsql :SELECT fields_star FROM tables WHERE conditions; \n");
				//printf("规约-selectsql :SELECT fields_star FROM tables WHERE conditions; \ncur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$6,$6->left,$6->right,$6->com_op
				//		,$6->type,$6->value);
				//if($6->left!=null)
				//printf("left   =(value=%s,type=%d,left=%p,right=%p)\n",$6->left->value,$6->left->type,$6->left->left,$6->left->right);
				//if($6->right!=null)
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$6->right->value,$6->right->type,$6->right->left,$6->right->right);
					while($4!=null){
						selectTable($4->table,$2,$6);
						$4=$4->next;
					}
				};
deletesql : DELETE FROM table WHERE conditions ';'
				{
				//printf("规约-deletesql : DELETE FROM table WHERE conditions ;\n");
				deleteTable($3,$5);
				}
				| DELETE FROM table ';'
				{
				//printf("规约-deletesql : DELETE FROM table ;\n");
				deleteTable($3,null);
				};
updatesql : UPDATE table SET fields_values ';'
				{
				//printf("规约-updatesql : UPDATE table SET field = expr ;\n");
				while($4!=null){
					updateTable($2,null,$4->field,$4->value);
					$4=$4->next;
				}
				
				}
				| UPDATE table SET fields_values WHERE conditions ';'
				{
				//printf("规约-updatesql : UPDATE table SET field = expr WHERE conditions;\n");
				while($4!=null){
					updateTable($2,$6,$4->field,$4->value);
					$4=$4->next;
				}
				
				};
fields_values    : field '=' data ',' fields_values
				{
				$$=(struct Updatestruct*)malloc(sizeof(struct Updatestruct));
				$$->field=$1;
				$$->value=$3;
				$$->next=$5;
				}
				|  field '=' data
				{
				$$=(struct Updatestruct*)malloc(sizeof(struct Updatestruct));
				$$->field=$1;
				$$->value=$3;
				$$->next=NULL;
				};
tables : table ',' tables
				{
				$$=(struct Tables*)malloc(sizeof(struct Tables));
				$$->table=$1;
				$$->next=$3;
				//printf("tables : table , tables   table=%s next=%p\n",$$->table,$$->next);
				}
				| table
				{
				$$=(struct Tables*)malloc(sizeof(struct Tables));
				$$->table=$1;
				$$->next=null;
				//printf("tables : table   table=%s  next=%p\n",$$->table,$$->next);
				};
fields_star : selectfields 
				{
				$$=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				$$=$1;
				//printf("规约-fields_star :selectfields field=%s next=%p \n",$$->field,$$->next);
				}
				| '*'
				{
				$$=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				$$->field=(char*)malloc(strlen("*")*sizeof(char));
				strcpy($$->field,"*");
				$$->next=null;
				//printf("规约-fields_star : *  field=%s next=%p \n",$$->field,$$->next);
				}; 
selectfields : field ',' selectfields
				{
				$$=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				$$->field=$1;
				$$->next=$3;
				//printf("规约-selectfields : field,selectfields  field=%s next=%p \n",$$->field,$$->next);
				}
				| field
				{
				$$=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				$$->field=$1;
				$$->next=null;
				//printf("规约-selectfields : field,selectfields  field=%s next=%p \n",$$->field,$$->next);
				};
conditions : 
				 '(' conditions ')'
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$=$2;
				//printf("规约-conditions : (condition) cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| conditions AND conditions 
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$3;
				$$->com_op=(char*)malloc((strlen("AND")+1)*sizeof(char));
				strcpy($$->com_op,"AND");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions : conditions AND conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| conditions OR conditions 
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$3;
				$$->com_op=(char*)malloc((strlen("OR")+1)*sizeof(char));
				strcpy($$->com_op,"OR");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  conditions OR conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| NOT conditions
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$2;
				$$->right=$2;
				$$->com_op=(char*)malloc((strlen("NOT")+1)*sizeof(char));
				strcpy($$->com_op,"NOT");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions : NOT conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}| condition '<' '>' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$4;
				$$->com_op=(char*)malloc((strlen("<>")+1)*sizeof(char));
				strcpy($$->com_op,"<>");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition >= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				//printf("left=(value=%s,type=%d,left=%p,right=%p)\n",$$->left->value,$$->left->type,$$->left->left,$$->left->right);
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$$->right->value,$$->right->type,$$->right->left,$$->right->right);
				}
				| condition '!' '=' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$4;
				$$->com_op=(char*)malloc((strlen("!=")+1)*sizeof(char));
				strcpy($$->com_op,"!=");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition != condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				//printf("left=(value=%s,type=%d,left=%p,right=%p)\n",$$->left->value,$$->left->type,$$->left->left,$$->left->right);
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$$->right->value,$$->right->type,$$->right->left,$$->right->right);
				}
				| condition '>' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$3;
				$$->com_op=(char*)malloc((strlen(">")+1)*sizeof(char));
				strcpy($$->com_op,">");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition > condition  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| condition '>' '=' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$4;
				$$->com_op=(char*)malloc((strlen(">=")+1)*sizeof(char));
				strcpy($$->com_op,">=");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition >= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				} 
				| condition '<' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$3;
				$$->com_op=(char*)malloc((strlen("<")+1)*sizeof(char));
				strcpy($$->com_op,"<");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition < condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| condition '<' '=' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$4;
				$$->com_op=(char*)malloc((strlen("<=")+1)*sizeof(char));
				strcpy($$->com_op,"<=");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition <= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| condition  '=' condition
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->left=$1;
				$$->right=$3;
				$$->com_op=(char*)malloc((strlen("=")+1)*sizeof(char));
				strcpy($$->com_op,"=");
				$$->type=-1;
				$$->value=null;
				//printf("规约-conditions :  condition = condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				}
				| TRUE 
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->type=1;
				$$->value=(char*)malloc((strlen("TRUE")+1)*sizeof(char));
				strcpy($$->value,"TRUE");
				$$->left=null;
				$$->right=null;
				$$->com_op=null;
				//printf("规约-condition : TRUE  type=%d value=%s\n",$$->type,$$->value);
				}
				| FALSE 
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->type=1;
				$$->value=(char*)malloc((strlen("FALSE")+1)*sizeof(char));
				strcpy($$->value,"FALSE");
				$$->left=null;
				$$->right=null;
				$$->com_op=null;
				//printf("规约-condition : FALSE  type=%d value=%s\n",$$->type,$$->value);
				};
condition : 
				 expr {
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->type=2;
				$$->value=(char*)malloc((strlen($1)+1)*sizeof(char));
				strcpy($$->value,$1);
				$$->left=null;
				$$->right=null;
				$$->com_op=null;
				//printf("规约-condition : expr  type=%d value=%s\n",$$->type,$$->value);
				}
				| field
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->type=0;
				$$->value=(char*)malloc((strlen($1)+1)*sizeof(char));
				strcpy($$->value,$1);
				$$->left=null;
				$$->right=null;
				$$->com_op=null;
				//printf("规约-condition : field  type=%d value=%s\n",$$->type,$$->value);
				}
				| string
				{
				$$=(struct Conditions*)malloc(sizeof(struct Conditions));
				$$->type=1;
				$$->value=(char*)malloc((strlen($1)+1)*sizeof(char));
				strcpy($$->value,$1);
				$$->left=null;
				$$->right=null;
				$$->com_op=null;
				//printf("规约-condition : field  type=%d value=%s\n",$$->type,$$->value);
				}
				;
expr   : expr '+' expr {
			int tmp=atoi($1)+atoi($3);
			$$=(char*)malloc(12*sizeof(char));
			sprintf($$,"%d",tmp);
			//printf("识别e+e %s+%s=%s\n",$1,$3,$$);
			}
			| expr '-' expr {
			int tmp=atoi($1)-atoi($3);
			$$=(char*)malloc(12*sizeof(char));
			sprintf($$,"%d",tmp);
			//printf("识别e-e %s-%s=%s\n",$1,$3,$$);
			}
			| expr '*' expr {
			int tmp=atoi($1)*atoi($3);
			$$=(char*)malloc(12*sizeof(char));
			sprintf($$,"%d",tmp);
			//printf("识别e*e %s*%s=%s\n",$1,$3,$$);
			}
			| expr '/' expr {
			int tmp=atoi($1)/atoi($3);
			$$=(char*)malloc(12*sizeof(char));
			sprintf($$,"%d",tmp);
			//printf("识别e/e %s/%s=%s\n",$1,$3,$$);
			}
			| NUMBER {
			$$=(char*)malloc(12*sizeof(char));
			sprintf($$,"%s",$1);
			//printf("识别数字%s\n",$$);
			};
fields : field ',' fields  
			 { 
			 $$=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			 $$->field=$1;
			 $$->next=$3;
			 //printf("规约-fields : fields , field=%s next=%p\n",$1,$3);
			 } 
			 | 
			 field 
			 {
			 $$=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			 $$->field=$1;
			 $$->next=NULL;
			 //printf("规约-fields : field=%s next=%p\n",$$->field,$$->next);
			 } ;

datas :   data 
			{
			$$=(struct Insertvaluedef*)malloc(sizeof(struct Insertvaluedef));
			$$->value=$1;
			$$->next=NULL;
			//printf("规约-datas : datas ,data=%s next=%p\n",$$->value,$$->next);
			} 
			|   data ',' datas
			{
			$$=(struct Insertvaluedef*)malloc(sizeof(struct Insertvaluedef));
			$$->value=$1;
			$$->next=$3;
			//printf("规约-datas : datas ,data=%s next=%p\n",$$->value,$$->next);
			};
data : string
			{
			$$=(char*)malloc(strlen($1)*sizeof(char));
			strcpy($$,$1);
			//printf("规约-data: string=%s\n",$$);
			}
			| NUMBER  
			{
			$$=(char*)malloc(strlen($1)*sizeof(char));
			strcpy($$,$1);
			//printf("规约-data: NUMBER=%s\n",$$);
			};
string :   '\'' STRING '\''
			{
			$$=(char*)malloc(strlen($2)*sizeof(char));
			strcpy($$,$2);
			//printf("规约-string: string=%s\n",$$);
			}
			| '\'' ID '\''
			{
			$$=(char*)malloc(strlen($2)*sizeof(char));
			strcpy($$,$2);
			//printf("规约-string: ID=%s\n",$$);
			}
			| '\'' NUMBER '\''
			{
			$$=(char*)malloc(strlen($2)*sizeof(char));
			strcpy($$,$2);
			//printf("规约-string: NUMBER=%s\n",$$);
			};
			
table : ID {
			$$=(char*)malloc(strlen($1)*sizeof(char));
			sprintf($$,"%s",$1);
			//printf("规约-table : ID     ID=%s\n",$1);
			};

fieldsdefinition : field_type 
			{
			$$=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			$$->field=$1->field;
			$$->type=$1->type;
			$$->next=NULL;
			//printf("规约-fieldsdefinition : field_type   field=%s    type=%s  next=%p\n",$$->field,$$->type,$$->next);
			} 
			|  field_type  ',' fieldsdefinition
			{
			$$=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			$$=$1;
			$$->next=$3;
			//printf("规约-fieldsdefinition : fieldsdefinition ',' field_type    field=%s  type=%s next=%p\n",$$->field,$$->type,$$->next);
			};

field_type : field  type 
			{
			$$=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			$$->field=$1;
			$$->type=$2;
			//printf("规约-field_type : field type        field=%s     type=%s\n",$$->field,$$->type);
			};

field : ID 
			{
			$$=(char*)malloc(strlen($1)*sizeof(char));
			$$=$1;
			//printf("规约-field : ID         field=%s\n",$$);
			};

type : CHAR '('NUMBER')'  
			{
			$$=(char*)malloc(strlen("CHAR")+strlen($3)*sizeof(char)+1);
			sprintf($$,"CHAR %s",$3);
			//printf("规约-type : CHAR (NUMBER)          type= %s\n",$$);
			} 
			| INT 
			{
			$$=(char*)malloc(strlen("INT")+1);
			$$="INT";
			//printf("规约-type: INT   type=%s\n",$$);
			};

exitsql : EXIT | QUIT;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section
int init(){
	if(access(dbsystempath,4)==-1){
		if(mkdir(dbsystempath)== -1){
			printf("系统目录%s创建失败\n",dbsystempath);
			return FILE_OPEN_ERROR;
		}
	}
	if(access(dbpath,4)==-1){
		if((fp=fopen(dbpath,"w"))==NULL){
			printf("系统文件%s创建失败\n",dbpath);
			return FILE_OPEN_ERROR;
		}
	}
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("***					***\n");
	printf("***		MySQL Database		***\n");
	printf("***					***\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
	buff=(char*)malloc(1024*sizeof(char));
	return 0;
}
//从本地读取所有数据库
int readDBs(){
	if((fp=fopen(dbpath,"r"))==NULL){
		printf("文件%s打开失败\n",dbpath);
		return FILE_OPEN_ERROR;
	}
	//统计数据库的数量
	dbsize=0;
	while(fgets(buff,1024,fp)!=NULL){
		dbsize++;
	}
	if(dbsize==0)
		return IS_NULL;
	//初始化dbdatas的行数，等于数据库的数量
	dbdatas=(char**)malloc(dbsize*sizeof(char*));
	dbsize=0;
	//重新打开文件
	if((fp=fopen(dbpath,"r"))==NULL){
		printf("文件%s打开失败\n",dbpath);
		return FILE_OPEN_ERROR;
	}
	//从文件读取数据写入dbdatas
	while(fgets(buff,1024,fp)!=NULL){
		int size=strlen(buff);
		dbdatas[dbsize]=(char*)malloc(size*sizeof(char));
		strcpy(dbdatas[dbsize],buff);
		dbdatas[dbsize][size-1]='\0';
		dbsize++;
	}
	fclose(fp);
	return 0;
}

int readTables(){
	sprintf(buff,"%s\\%s\\dat.txt",dbsystempath,database);
	if((fp=fopen(buff,"r"))==NULL){
		printf("文件%s打开失败in readTables\n",buff);
		return FILE_OPEN_ERROR;
	}
	//统计数据库的数量
	dbsize=0;
	while(fgets(buff,1024,fp)!=NULL){
		dbsize++;
	}
	if(dbsize==0)
		return IS_NULL;
	fclose(fp);
	//if(dbdatas!=NULL)
	//	free(dbdatas);
	//初始化dbdatas的行数，等于数据库的数量
	dbdatas=(char**)malloc(dbsize*sizeof(char*));
	dbsize=0;
	sprintf(buff,"%s\\%s\\dat.txt",dbsystempath,database);
	//重新打开文件
	if((fp=fopen(buff,"r"))==NULL){
		printf("文件%s打开失败 in readTables\n",buff);
		return FILE_OPEN_ERROR;
	}
	//从文件读取数据写入dbdatas
	while(fgets(buff,1024,fp)!=NULL){
		int size=strlen(buff);
		dbdatas[dbsize]=(char*)malloc(size*sizeof(char));
		strcpy(dbdatas[dbsize],buff);
		dbdatas[dbsize][size-1]='\0';
		dbsize++;
	}
	//for(i=0;i<dbsize;i++)
	//	printf("%s\n",dbdatas[i]);
	fclose(fp);
	return 0;
}
//读取该数据库的所有表，并进行处理，只留下表名
int readTablesName(){
	unsigned int j;
	int i;
	if(readTables()==FILE_OPEN_ERROR)
		return FILE_OPEN_ERROR;
	//for(i=0;i<dbsize;i++)
	//	printf("[debug]containsTableName %s\n",dbdatas[i]);
	//一行数据的格式为    表名 列名 列属性   例如：student id CHAR 18
	//删掉第一个空格及后面的数据，留下表名
	for(i=0;i<dbsize;i++){
		for(j=0;j<strlen(dbdatas[i]);j++){
			if(dbdatas[i][j]==' '){
				dbdatas[i][j]='\0';
				break;
			}
		}
	}
	return 0;
}
//展示所有数据库
void showDBs(){
	int i;
	if(readDBs()==FILE_OPEN_ERROR)
		return;
	if(dbsize==0)
		printf("暂无数据\n");
	for(i=0;i<dbsize;i++)
		printf("%s\n",dbdatas[i]);
}
//展示所有表
void showTables(){
	int i;
	char* pre=(char*)malloc(128*sizeof(char));
	if(readTablesName()==FILE_OPEN_ERROR)
		return;
	if(dbsize==0){
		printf("暂无数据\n");
		return;
	}
	printf("%s\n",dbdatas[0]);
	pre=dbdatas[0];
	for(i=1;i<dbsize;i++)
		if(strcmp(pre,dbdatas[i])!=0){
			printf("%s\n",dbdatas[i]);
			strcpy(pre,dbdatas[i]);
		}
	return;
}
//查看已有数据库是否包含target
int containsDB(char* target){
	int i;
	if(readDBs()==FILE_OPEN_ERROR)
		return FILE_OPEN_ERROR;
	for(i=0;i<dbsize;i++)
		if(strcmp(target,dbdatas[i])==0)
			return 1;
	return 0;
}
//判断是否包含该表
int containsTable(char* table){
	int i;
	lowercase(table);
	if(readTablesName()==FILE_OPEN_ERROR)
		return FILE_OPEN_ERROR;
	//for(i=0;i<dbsize;i++)
	//	printf("[debug]containsTable table=%s\n",dbdatas[i]);
	for(i=0;i<dbsize;i++){
		if(strcmp(table,dbdatas[i])==0){
			return 1;
		}
	}
	return 0;
}
//转换成小写
void lowercase(char* target){
	int i;
	for(i=0;target[i]!='\0';i++)
		if(target[i]>='A'&&target[i]<='Z')
			target[i]+=('a'-'A');
}
//添加数据库
void addDB(char* databaseName ){
	lowercase(databaseName);
	if(containsDB(databaseName)==1){
		printf("该数据库已存在\n");
		return;
	}
	if((fp=fopen(dbpath,"a"))==NULL){
		printf("文件%s打开失败\n",dbpath);
		return;
	}
	//写入记录数据库名称的文件
	fprintf(fp,"%s\n",databaseName);
	fclose(fp);
	//创建目录
	sprintf(buff,"%s\\%s",dbsystempath,databaseName);
	if(mkdir(buff)== -1){
		printf("系统目录%s创建失败\n",dbsystempath);
		return;
	}
	sprintf(buff,"%s\\dat.txt",buff);
	//创建系统文件
	if((fp=fopen(buff,"w+"))==NULL){
		printf("系统文件创建失败\n");
	}
	fclose(fp);
	return;
}
//添加表
void addTable(char *table,struct Createfieldsdef* fields){
	unsigned int i=1;
	FILE* fp;
	sprintf(buff,"%s\\%s\\dat.txt",dbsystempath,database);
	if((fp=fopen(buff,"a"))==NULL){
		printf("文件打开失败,路径：%s\n",buff);
		return;
	}
	//printf("[debug] addTable路径=%s\n",buff);
	while(fields!=NULL){
		//printf("[debug] addTable table=%s field=%s type=%s\n",table,fields->field,fields->type);
		fprintf(fp,"%s %d %s %s\n",table,i++,fields->field,fields->type);
		fields=fields->next;
	}
	fclose(fp);
	sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,database,table);
	//printf("[debug] addTable路径=%s\n",buff);
	if((fp=fopen(buff,"w"))==NULL){
		printf("表文件创建失败,路径=%s\n",buff);
	}
	//printf("[debug] addTable  END\n");
	fclose(fp);
}

//切换数据库
void useDB(char* databaseName){
	lowercase(databaseName);
	if(containsDB(databaseName)==1){
		database=(char*)malloc(strlen(databaseName)*sizeof(char));
		strcpy(database,databaseName);
		printf("切换成功，当前数据库:%s\n",database);
	}else{
		printf("数据库%s不存在\n",databaseName);
	}
}
//删除数据库
void dropDB(char* databaseName){
	int i;
	lowercase(databaseName);
	if(containsDB(databaseName)==1){
		//删除表
		database=databaseName;
		readTablesName();//读取表名
		//删除表文件  表名.txt
		for(i=0;i<dbsize;i++){
			sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,databaseName,dbdatas[i]);
			remove(buff);
			//printf("[debug]dropDB remove(path)=%d path=%s\n",,buff);
		}
		fclose(fp);
		//删除系统文件  dat.txt
		sprintf(buff,"%s\\%s\\dat.txt",dbsystempath,databaseName);
		//printf("[debug]dropDBremove(path)=%d path=%s\n",,buff);
		remove(buff);
		//删除目录   
		sprintf(buff,"%s\\%s",dbsystempath,databaseName);
		//printf("[debug]dropDB rmdir(path)=%d path=%s\n",,buff);
		rmdir(buff);
		//系统文件中删除该数据库
		deleteDBDefinition(databaseName);
	}else{
		printf("数据库%s不存在\n",databaseName);
	}
}

void dropTable(char* table){
	//printf("droptable %s\n",table);
	lowercase(table);
	if(containsTable(table)==1){
		deleteTableDefinition(table);
		sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,database,table);
		if(access(buff,"r")==0){//先测试该文件是否存在
			remove(buff);
		}else{
			printf("[debug]droptable 表%s不存在,路径: %s\n",table,buff);
			return;
		}
		
	}else{
		printf("[debug]droptable 表%s不存在\n",table);
		return;
	}
	printf("成功删除数据库%s下的%s表\n",database,table);
}
//更新数据库系统文件
void deleteDBDefinition(char* databaseName){
	int i;
	lowercase(databaseName);
	if(readDBs()==FILE_OPEN_ERROR)
		return;
	//找到该数据库名并将开头换成$
	for(i=0;i<dbsize;i++)
		if(strcmp(databaseName,dbdatas[i])==0){
			dbdatas[i][0]='$';
		}
	if((fp=fopen(dbpath,"w"))==NULL){
		printf("文件%s打开失败\n",dbpath);
		return;
	}
	//不写已$开头的数据
	for(i=0;i<dbsize;i++)
		if(dbdatas[i][0]!='$'){
			fprintf(fp,"%s\n",dbdatas[i]);
		}
	fclose(fp);
}

void deleteTableDefinition(char* table){
	int i;
	lowercase(table);
	if(readTablesName()==FILE_OPEN_ERROR)
		return;
	readTables();
	//找到该表名并将开头换成$
	for(i=0;i<dbsize;i++){
		if(startsWith(dbdatas[i],table)==1){
				dbdatas[i][0]='$';
		}
	}
	//for(i=0;i<dbsize;i++)
	//	printf("[debug] deleteTableDefinition %s\n",dbdatas[i]);
	sprintf(buff,"%s\\%s\\dat.txt",dbsystempath,database);
	if((fp=fopen(buff,"w"))==NULL){
		printf("文件%s打开失败\n",buff);
		return;
	}
	
	//不写已$开头的数据
	for(i=0;i<dbsize;i++)
		if(dbdatas[i][0]!='$'){
			fprintf(fp,"%s\n",dbdatas[i]);
		}
	fclose(fp);
}

void insert(char* table,struct Createfieldsdef* fields,struct Insertvaluedef* values){
	int i;
	char *path;
	lowercase(table);
	if(containsTable(table)==0){
		printf("该表不存在\n");
		return;
	}
	readTables();
	if(fields==NULL){
		strcpy(buff,values->value);
		values=values->next;
		while(values!=null){
			sprintf(buff,"%s %s",buff,values->value);
			values=values->next;
		}
		i=strlen(buff);
	}else{
		initvaluemap(table,fields,values);
		strcpy(buff,(valuemap[0]==null?"null":valuemap[0]));
		for(i=1;i<fieldmapsize;i++)
			sprintf(buff,"%s %s",buff,valuemap[i]);
		i=strlen(buff);
	}
	path=(char*)malloc(1024*sizeof(char));
	sprintf(path,"%s\\%s\\%s.txt",dbsystempath,database,table);
	if((fp=fopen(path,"a"))==NULL){
		printf("表不存在，路径:%s\n",buff);
		return;
	}
	//printf("[debug] insert buff=%s\n",buff);
	//printf("[debug] insert success=%d\n",);
	fprintf(fp,"%s\n",buff);
	fclose(fp);
}
void initfieldmap(char* table){
	int i,j,k;
	int num=0;
	fieldmapsize=0;
	lowercase(table);
	if(containsTable(table)==0){
		printf("表%s不存在\n",table);
		return;
	}
	readTables(table);
	fieldmap=(char**)malloc(dbsize*sizeof(char*));
	valuemap=(char**)malloc(dbsize*sizeof(char*));
	for(i=0;i<dbsize;i++){
		//printf("[debug] initfieldmap res=%d s1=\"%s\" s2=\"%s\"\n",startsWith(dbdatas[i],table),dbdatas[i],table);
		if(startsWith(dbdatas[i],table)==1){
			fieldmapsize++;
			//跳过表名
			for(j=0;dbdatas[i][j]!=' ';j++);
			j++;
			//读取数字
			num=0;
			for(;dbdatas[i][j]!=' ';j++){
				num*=10;
				num+=dbdatas[i][j]-'0';
			}
			j++;
			//读取属性名
			for(k=0;dbdatas[i][j]!=' '&&dbdatas[i][j]!='\0';j++){
				buff[k++]=dbdatas[i][j];
			}
			buff[k]='\0';
			fieldmap[num-1]=(char*)malloc(strlen(buff)*sizeof(char));
			strcpy(fieldmap[num-1],buff);
		}
	}
	//printf("%d\n",size);
	//for(i=0;i<size;i++)
	//	printf("%d %s\n",i,fieldmap[i]);
}
void initvaluemap(char *table,struct Createfieldsdef* fields,struct Insertvaluedef* values){
	int num;
	int i;
	initfieldmap(table);
	valuemap=(char**)malloc(fieldmapsize*sizeof(char*));
	//值初始化为null
	for(i=0;i<fieldmapsize;i++){
		valuemap[i]=(char*)malloc(sizeof("null"));
		strcpy(valuemap[i],"null");
	}
	while(fields!=null){
		//printf("[begin] initvaluemap %s\n",fields->field);
		if(values==null){
			printf("属性和值的数量不一致\n");
			return;
		}
		//列号
		if(fields->field[0]>='0'&&fields->field[0]<='9'){
			num=atoi(fields->field);
			strcpy(valuemap[num-1],values->value);
			fields=fields->next;
			values=values->next;
			continue;
		}
		//列属性
		for(i=0;i<fieldmapsize&&strcmp(fields->field,fieldmap[i])!=0;i++);
		if(i==fieldmapsize){
			printf("未找到属性%s\n",fields->field);
			return;
		}
		valuemap[i]=(char*)malloc(strlen(fields->field)*sizeof(char));
		strcpy(valuemap[i],values->value);
		//printf("%p %p\n",fields->next,values->next);
		fields=fields->next;
		values=values->next;
		
	}
	//for(i=0;i<fieldmapsize;i++)
	//	printf("[debug] initvaluemap %d %s\n",i,valuemap[i]);
}
int startsWith(char* s1,char* s2){
	unsigned int i=0;
	for(;i<strlen(s1)&&i<strlen(s2);i++){
		if(s1[i]!=s2[i])
			return 0;
	}
	return 1;
}
//获取field所在列号
int* getPosition(char* table,struct Fieldstar* fields){
	int* res;
	int i,j;
	initfieldmap(table);
	res=(int*)malloc(20*sizeof(int));
	i=0;
	while(fields!=null){
		printf("\n");
		for(j=0;j<dbsize;j++){
			//printf("%s\n",fieldmap[j]);
			if(strcmp(fields->field,fieldmap[j])==0){
				res[i++]=j;
				break;
			}
		}
		if(j==dbsize){
			printf("属性%s未找到\n",fields->field);
		}
		fields=fields->next;
	}
	//for(j=0;j<i;j++)
	//	printf("%d %s\n",res[j],fieldmap[res[j]]);
	res[i]=-1;//以-1结尾
	return res;
}
void selectTable(char* table,struct Fieldstar* fields,struct Conditions* conditions){
	int i,j;
	int* targetfield;//输出目标列
	struct Datastruct* cur;
	struct Datastruct* head;
	lowercase(table);
	if(containsTable(table)==0){
		printf("该表%s不存在\n",table);
		return;
	}
	head=readTableData(table);
	//printf("[debug]selectTable cur=%p com_op=%s  value=%s type=%d\n",conditions,conditions->com_op,conditions->value,conditions->type);
	//printf("[debug]selectTable left   =(value=%s,type=%d,left=%p,right=%p)\n",conditions->left->value,conditions->left->type,conditions->left->left,conditions->left->right);
	//printf("[debug]selectTable  left      com_op=%s\n",conditions->left->com_op);
	//printf("[debug]selectTable  right       com_op=%s  value=%s type=%d\n",conditions->right->com_op,conditions->right->value,conditions->right->type);
	if(head==null){
		for(i=0;i<fieldmapsize;i++){
			printf("  %10s  |",fieldmap[i]);
		}
		printf("\n");
		return;
	}
	if(strcmp(fields->field,"*")==0)
	{
		if(conditions==null)
		{
			for(i=0;i<fieldmapsize;i++){
				printf("  %10s  |",fieldmap[i]);
			}
			printf("\n");
			cur=head;
			while(cur!=null){
				for(i=0;i<cur->length;i++)
					printf("  %10s  |",cur->value[i]);
				printf("\n");
				cur=cur->next;
			}
			printf("\n");
		}else{
			for(i=0;i<fieldmapsize;i++){
				printf("  %10s  |",fieldmap[i]);
			}
			printf("\n");
			cur=head;
			while(cur!=null){
				//printf("com_op=%s  value=%s type=%d\n",conditions->com_op,conditions->value,conditions->type);
				//printf("[debug]selectTable  left       com_op=%s  value=%s type=%d\n",conditions->left->com_op,conditions->left->value,conditions->left->type);
				//printf("[debug]selectTable  right       com_op=%s  value=%s type=%d\n",conditions->right->com_op,conditions->right->value,conditions->right->type);
			//	printf("--\n");
			//	printf("%s\n",cur->value[0]);
				if(postorder(cur,conditions)==0){
					//printf("--------------\n");
					cur=cur->next;
					continue;//不符合条件
				}
				for(i=0;i<cur->length;i++)
					printf("  %10s  |",cur->value[i]);
				printf("\n");
				cur=cur->next;
			}
			printf("\n");
		}
	}else{//查出指定列
		if(conditions==null)
		{
			//for(i=0;i<fieldmapsize;i++){
			//	printf("  %10s  |",fieldmap[i]);
			//}
			
			//for(j=0;targetfield[j]!=-1;j++)
			//	printf("%d ",targetfield[j]);
			//printf("\n");
			targetfield=getPosition(table,fields);//指定列索引
			for(j=0;targetfield[j]!=-1;j++)
				printf("  %10s  |",fieldmap[targetfield[j]]);
			printf("\n");
			cur=head;
			while(cur!=null){
				//for(i=0;i<cur->length;i++)
				//	printf("  %10s  |",cur->value[i]);
				for(j=0;targetfield[j]!=-1;j++)
					printf("  %10s  |",cur->value[targetfield[j]]);
				printf("\n");
				cur=cur->next;
			}
			printf("\n");
		}else{
			//for(i=0;i<fieldmapsize;i++){
			//	printf("  %10s  |",fieldmap[i]);
			//}
			//printf("\n");
			targetfield=getPosition(table,fields);//指定列索引
			for(j=0;targetfield[j]!=-1;j++)
				printf("  %10s  |",fieldmap[targetfield[j]]);
			printf("\n");
			cur=head;
			while(cur!=null){
				//printf("com_op=%s  value=%s type=%d\n",conditions->com_op,conditions->value,conditions->type);
				//printf("[debug]selectTable  left       com_op=%s  value=%s type=%d\n",conditions->left->com_op,conditions->left->value,conditions->left->type);
				//printf("[debug]selectTable  right       com_op=%s  value=%s type=%d\n",conditions->right->com_op,conditions->right->value,conditions->right->type);
				if(postorder(cur,conditions)==0){
					//printf("---------------------------------\n");
					cur=cur->next;
					continue;//不符合条件
				}
				//for(i=0;i<cur->length;i++)
				//	printf("  %10s  |",cur->value[i]);
				for(j=0;targetfield[j]!=-1;j++)
					printf("  %10s  |",cur->value[targetfield[j]]);
				printf("\n");
				cur=cur->next;
			}
			printf("\n");
		}	
	}
	
}
int postorder(struct Datastruct* data,struct Conditions*  conditions){
	int resl=1;
	int resr=1;
	char* vall;
	char* valr;
	if(conditions==null)
		return 1;
	if(conditions->type==1)
	{	
		if(strcmp(conditions->value,"TRUE")==0||strcmp(conditions->value,"true")==0)
			return 1;
		if(strcmp(conditions->value,"FALSE")==0||strcmp(conditions->value,"false")==0)
			return 0;
	}
	//printf("[debug]postorder  com_op=%s  value=%s type=%d\n",conditions->com_op,conditions->value,conditions->type);
	//printf("[debug]postorder  left=%p right=%p\n",conditions->left,conditions->right);
	//printf("[debug]postorder  left       com_op=%s  value=%s type=%d\n",conditions->left->com_op,conditions->left->value,conditions->left->type);
	//printf("[debug]postorder  right       com_op=%s  value=%s type=%d\n",conditions->right->com_op,conditions->right->value,conditions->right->type);
	if(conditions->left!=null)
		resl=postorder(data,conditions->left);
		
	if(conditions->right!=null)
		resr=postorder(data,conditions->right);
	//printf("[debug]postorder resl=%d resr=%d\n",resl,resr);
	if(conditions->com_op==null)
		return 1;
	if(strcmp(conditions->com_op,"AND")==0)
		return (resl+resr==2?1:0);
	if(strcmp(conditions->com_op,"OR")==0)
		return (resl+resr>=1?1:0);
	if(strcmp(conditions->com_op,"NOT")==0)
		return resl==0?1:0;
	if(conditions->left->type==0){//左边是字段，从data中获取该字段的值
		vall=getValue(data,conditions->left->value);
		//printf("[debug] postorder vall getValue  %s\n",vall);
	}else{
		//printf("[debug] postorder vall value");
		vall=conditions->left->value;
	}
	if(conditions->right->type==0){//右边是字段，从data中获取该字段的值
		//printf("[debug] postorder valr getValue");
		valr=getValue(data,conditions->right->value);
	}else{
		//printf("[debug] postorder valr value");
		valr=conditions->right->value;
	}
	//printf("[debug] postorder  vall=%s valr=%s  com_op=%s\n",vall,valr,conditions->com_op);
	//printf("com_op==!=  %d\n",strcmp(conditions->com_op,"!="));
	//为空值
	if(strcmp(vall,"null")==0||strcmp(vall,"NULL")==0||strcmp(valr,"null")==0||strcmp(valr,"NULL")==0){
		//printf("[debug] vall或valr为null\n");
		return 0;//为null时返回1
	}
		
	if(strcmp(conditions->com_op,"!=")==0){
		//printf("[debug]postorder   if()  vall=%d valrr%d  vall==valr?=%d\n",atoi(vall),atoi(valr),atoi(vall)!=atoi(valr));
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)!=atoi(valr);
		else
			return strcmp(vall,valr)!=0?1:0;
	}
	if(strcmp(conditions->com_op,">")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)>atoi(valr);
		else{
			printf("数字才能进行比较\n  %s  %s",vall,valr);
		}
	}
	if(strcmp(conditions->com_op,"<")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)<atoi(valr);
		else{
			printf("数字才能进行比较\n  %s  %s",vall,valr);
		}
	}
	if(strcmp(conditions->com_op,">=")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)>=atoi(valr);
		else{
			printf("数字才能进行比较\n  %s  %s",vall,valr);
		}
	}
	if(strcmp(conditions->com_op,"<=")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)<=atoi(valr);
		else{
			printf("数字才能进行比较\n  %s  %s",vall,valr);
		}
	}
	if(strcmp(conditions->com_op,"<>")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)!=atoi(valr);
		else
			return strcmp(vall,valr)==0?1:0;
	}
	
	if(strcmp(conditions->com_op,"=")==0){
		if(conditions->left->type==2||conditions->right->type==2)
			return atoi(vall)==atoi(valr);
		else
			return strcmp(vall,valr)==0?1:0;
	}
	return 1;
}
//获取属性field的值
char* getValue(struct Datastruct* data,char *field){
	int i;
	for(i=0;i<fieldmapsize;i++)
		if(strcmp(field,fieldmap[i])==0)
			break;
	//printf("[debug]getValue i=%d\n",i);
	if(i<0||i>=fieldmapsize){
		printf("属性%s不存在",field);
		return "null";
	}
	return data->value[i];
}
//读取表信息,数据库一行是Datastruct一个节点，每一列属性放在char**的一行
struct Datastruct* readTableData(char* table){
	struct Datastruct* head;
	struct Datastruct* cur;
	FILE* fp2;
	char* path2;
	int i,j,k,size=0;
	head=(struct Datastruct*)malloc(sizeof(struct Datastruct));
	cur=head;
	//printf("[debug]readTableData head=%p cur=%p\n",head,cur);
	lowercase(table);
	if(database==null){
		printf("请选定数据库\n");
		return;
	}
	if(containsTable(table)==0){
		printf("表%s不存在\n",table);
		return;
	}
	sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,database,table);
	path2=(char*)malloc(strlen(buff)*sizeof(char));
	strcpy(path2,buff);
	if((fp2=fopen(path2,"r"))==null){
		printf("文件%s不存在\n",path2);
		return;
	}
	initfieldmap(table);
	//printf("path=%s fp2=%p\n",path2,fp2);
	while(fgets(buff,1024,fp2)!=null)
	{
		buff[strlen(buff)-1]='\0';
		size++;
		//printf("[debug]readTableData   strlen(line)=%d\n",strlen(buff));
		//if(strlen(buff)<=1)
		//	break;
		//if(buff==null||strlen(buff)<=1)
		//	break;
		//printf("[debug]readTableData   line=%s\n",buff);
		//printf("[debug]readTableData strlen(buff)=%d\n",strlen(buff));
		//将值放在数组中，便于挑选
		//printf("[debug]selectTable fieldmapsize=%d\n",fieldmapsize);
		
		cur->next=(struct Datastruct*)malloc(sizeof(struct Datastruct));
		cur->next->pre=cur;
		cur=cur->next;
		cur->next=null;
		cur->length=fieldmapsize;
		cur->value=(char**)malloc(fieldmapsize*sizeof(char*));
		//printf("[debug]readTableData  cur->next=%p cur->length=%d\n",cur->next,cur->length);
		for(i=0,j=0;buff[i]!='\0'&&buff[i]!='\n';){
			cur->value[j]=(char*)malloc(128);
			//将buff的数据写入链表
			for(k=0;buff[i]!=' '&&buff[i]!='\0'&&buff[i]!='\n';i++,k++){
				cur->value[j][k]=buff[i];
			}
			cur->value[j][k]='\0';
			//printf("[debug]readTableData cur->value[j]=%s\n",cur->value[j]);
			j++;
			if(j==fieldmapsize)
				break;
			//跳过空格
			for(;buff[i]!='\0'&&buff[i]!='\n'&&buff[i]==' ';i++);
		}
	}
	//printf("[debug] readTableData  数据数量=%d\n",size);
	if(size==0){
		printf("表%s暂无数据\n",table);
		return null;
	}
	fclose(fp2);
	/*
	cur=head->next;
	while(cur!=null){
		for(i=0;i<cur->length;i++)
			printf("   %s  |",cur->value[i]);
		printf("\n");
		cur=cur->next;
	}
	*/
	return head->next;
}

void deleteTable(char* table,struct Conditions* conditions){
	int i,j,size=0;
	struct Datastruct* cur;
	struct Datastruct* head=(struct Datastruct*)malloc(sizeof(struct Datastruct));
	struct Datastruct* tmp=readTableData(table);
	FILE* fp2;
	head->next=tmp;
	tmp->pre=head;
	cur=head->next;
	while(cur!=null){
		if(postorder(cur,conditions)==1){
			//printf("%s\n",cur->value[0]);
			tmp=cur->next;
			if(cur->next!=null){
				cur->next->pre=cur->pre;
			}
			cur->pre->next=cur->next;
			free(cur);
			cur=tmp;
			size++;
			continue;//符合条件
		}
		cur=cur->next;
	}
	sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,database,table);
	if((fp=fopen(buff,"w"))==NULL){
		printf("系统文件%s无法打开，删除失败\n",buff);
		return;
	}
	cur=head->next;
	while(cur!=null){
		//printf("cur->length=%d\n",cur->length);
		sprintf(buff,"%s",cur->value[0]);
		for(i=1;i<cur->length;i++){
			sprintf(buff,"%s %s",buff,cur->value[i]);
		}
		j=strlen(buff);
		buff[j]='\n';//最后的空格替换为\n
		buff[j+1]='\0';
		fprintf(fp,"%s",buff);
		cur=cur->next;
	}
	fclose(fp);
	printf("成功删除%d行数据\n",size);
}
void updateTable(char* table,struct Conditions* conditions,char* field,char* value){
	int i,j,size=0;
	struct Datastruct* cur;
	struct Datastruct* head=(struct Datastruct*)malloc(sizeof(struct Datastruct));
	struct Datastruct* tmp=readTableData(table);
	FILE* fp2;
	int target;
	head->next=tmp;
	tmp->pre=head;
	cur=head->next;
	initfieldmap(table);
	for(target=0;target<fieldmapsize;target++)
		if(strcmp(fieldmap[target],field)==0){
			break;
		}
	if(target==fieldmapsize){
		printf("属性%s不存在\n",field);
		return;
	}
	while(cur!=null){
		if(postorder(cur,conditions)==1){
			//printf("%s\n",cur->value[0]);
			strcpy(cur->value[target],value);
			size++;
		}
		cur=cur->next;
	}
	sprintf(buff,"%s\\%s\\%s.txt",dbsystempath,database,table);
	if((fp=fopen(buff,"w"))==NULL){
		printf("系统文件%s无法打开，删除失败\n",buff);
		return;
	}
	cur=head->next;
	while(cur!=null){
		//printf("cur->length=%d\n",cur->length);
		sprintf(buff,"%s",cur->value[0]);
		for(i=1;i<cur->length;i++){
			sprintf(buff,"%s %s",buff,cur->value[i]);
		}
		j=strlen(buff);
		buff[j]='\n';//最后的空格替换为\n
		buff[j+1]='\0';
		fprintf(fp,"%s",buff);
		//printf("%s",buff);
		cur=cur->next;
	}
	fclose(fp);
	printf("成功更新%d行数据\n",size);
}
int main(void)
{
	if(init()==FILE_OPEN_ERROR){
		system("pause");
		return -1;
	}
	while(1){
		printf("mysql> ");
		yyparse();
	}
	return 0;
}

