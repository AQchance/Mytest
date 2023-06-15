/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 37 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mysql4yacc.c
* C source file generated from mysql4yacc.y.
* 
* Date: 06/26/20
* Time: 08:46:48
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\mysql4yacc.y"

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

#line 115 "mysql4yacc.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\mysql4yacc.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 143 ".\\mysql4yacc.y"

			//printf("规约-statements : statements statement\n");
			printf("\nmysql>");
			
#line 244 "mysql4yacc.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 148 ".\\mysql4yacc.y"

			//printf("规约-statements : statement\n");
			printf("\nmysql>");
			
#line 260 "mysql4yacc.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 155 ".\\mysql4yacc.y"

			exit(0);
			
#line 275 "mysql4yacc.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 160 ".\\mysql4yacc.y"

			//printf("规约-usedatabasesql : USE databasename \';\'  database=%s\n",$2);
			useDB(yyattribute(2 - 3).yych);
			
#line 291 "mysql4yacc.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 165 ".\\mysql4yacc.y"

			//printf("规约-showsql : SHOW DATABASES \';\'\n");
			showDBs();
			
#line 307 "mysql4yacc.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 170 ".\\mysql4yacc.y"

			//printf("规约-showsql : SHOW TABLES \';\'\n");
			if(database==NULL){
				printf("请先选定数据库，再做查看操作\n");
				return;
			}
			showTables();
			
#line 327 "mysql4yacc.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 179 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(1 - 1).yych));
			yyval.yych=yyattribute(1 - 1).yych;
			//printf("规约-databasename : ID         databasename=%s\n",$$);
			
#line 344 "mysql4yacc.c"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 187 ".\\mysql4yacc.y"

            //printf("规约-createdatabasesql : CREATE DATABASE databasename \';\'  database=%s\n",database);
			addDB(yyattribute(3 - 4).yych);
            
#line 360 "mysql4yacc.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 192 ".\\mysql4yacc.y"

			if(database==NULL){
				printf("请先选定数据库\n");
				return;
			}
			if(containsTable(yyattribute(3 - 7).yych)){
				printf("%s已存在\n",yyattribute(3 - 7).yych);
				return;
			}
			//printf("规约-createsql : CREATE TABLE table \'(\' fieldsdefinition \')\' \';\'  table=%s\n",$3);
			addTable(yyattribute(3 - 7).yych,yyattribute(5 - 7).cfdef_var);
			
#line 384 "mysql4yacc.c"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 207 ".\\mysql4yacc.y"

			//printf("规约-dropsql : DROP DATABASE databasename \';\' \n");
			dropDB(yyattribute(3 - 4).yych);
			
#line 400 "mysql4yacc.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 212 ".\\mysql4yacc.y"

			if(database==NULL){
				printf("请先选定数据库，再做删除操作\n");
				return;
			}
			//printf("[debug]yacc %d %s\n",containsTable($3),$3);
			//printf("规约-dropsql : DROP TABLE table \';\' \n");
			dropTable(yyattribute(3 - 4).yych);
			
#line 421 "mysql4yacc.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[12];
			yyinitdebug(yya, 12);
#endif
			{
#line 223 ".\\mysql4yacc.y"

			//printf("规约- insertsql : INSERT INTO %s ( fields ) VALUES ( datas ) ; \n",$3);
			if(database==NULL){
				printf("请先选定数据库，再做插入操作\n");
				return;
			}
			//initvaluemap($3,$5,$9);	
			insert(yyattribute(3 - 11).yych,yyattribute(5 - 11).cfdef_var,yyattribute(9 - 11).ivdef_var);
			
#line 442 "mysql4yacc.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[9];
			yyinitdebug(yya, 9);
#endif
			{
#line 233 ".\\mysql4yacc.y"

			//printf("规约- insertsql : INSERT INTO %s VALUES ( datas ) ; \n",$3);
			if(database==NULL){
				printf("请先选定数据库，再做插入操作\n");
				return;
			}
			insert(yyattribute(3 - 8).yych,NULL,yyattribute(6 - 8).ivdef_var);
			//while($6!=null){
			//	printf("[debug] %s %p\n",$6->value,$6->next);
			//	$6=$6->next;
			//}
			
#line 466 "mysql4yacc.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 247 ".\\mysql4yacc.y"

				//printf("规约-selectsql :SELECT fields_star FROM tables ; \n");
					while(yyattribute(4 - 5).t_var!=null){
						selectTable(yyattribute(4 - 5).t_var->table,yyattribute(2 - 5).fs_var,null);
						yyattribute(4 - 5).t_var=yyattribute(4 - 5).t_var->next;
					}
				
#line 485 "mysql4yacc.c"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 255 ".\\mysql4yacc.y"

				//printf("规约-selectsql :SELECT fields_star FROM tables WHERE conditions; \n");
				//printf("规约-selectsql :SELECT fields_star FROM tables WHERE conditions; \ncur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$6,$6->left,$6->right,$6->com_op
				//		,$6->type,$6->value);
				//if($6->left!=null)
				//printf("left   =(value=%s,type=%d,left=%p,right=%p)\n",$6->left->value,$6->left->type,$6->left->left,$6->left->right);
				//if($6->right!=null)
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$6->right->value,$6->right->type,$6->right->left,$6->right->right);
					while(yyattribute(4 - 7).t_var!=null){
						selectTable(yyattribute(4 - 7).t_var->table,yyattribute(2 - 7).fs_var,yyattribute(6 - 7).con_var);
						yyattribute(4 - 7).t_var=yyattribute(4 - 7).t_var->next;
					}
				
#line 510 "mysql4yacc.c"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[7];
			yyinitdebug(yya, 7);
#endif
			{
#line 269 ".\\mysql4yacc.y"

				//printf("规约-deletesql : DELETE FROM table WHERE conditions ;\n");
				deleteTable(yyattribute(3 - 6).yych,yyattribute(5 - 6).con_var);
				
#line 526 "mysql4yacc.c"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 274 ".\\mysql4yacc.y"

				//printf("规约-deletesql : DELETE FROM table ;\n");
				deleteTable(yyattribute(3 - 4).yych,null);
				
#line 542 "mysql4yacc.c"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 279 ".\\mysql4yacc.y"

				//printf("规约-updatesql : UPDATE table SET field = expr ;\n");
				while(yyattribute(4 - 5).u_var!=null){
					updateTable(yyattribute(2 - 5).yych,null,yyattribute(4 - 5).u_var->field,yyattribute(4 - 5).u_var->value);
					yyattribute(4 - 5).u_var=yyattribute(4 - 5).u_var->next;
				}
				
				
#line 562 "mysql4yacc.c"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 288 ".\\mysql4yacc.y"

				//printf("规约-updatesql : UPDATE table SET field = expr WHERE conditions;\n");
				while(yyattribute(4 - 7).u_var!=null){
					updateTable(yyattribute(2 - 7).yych,yyattribute(6 - 7).con_var,yyattribute(4 - 7).u_var->field,yyattribute(4 - 7).u_var->value);
					yyattribute(4 - 7).u_var=yyattribute(4 - 7).u_var->next;
				}
				
				
#line 582 "mysql4yacc.c"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 297 ".\\mysql4yacc.y"

				yyval.u_var=(struct Updatestruct*)malloc(sizeof(struct Updatestruct));
				yyval.u_var->field=yyattribute(1 - 5).yych;
				yyval.u_var->value=yyattribute(3 - 5).yych;
				yyval.u_var->next=yyattribute(5 - 5).u_var;
				
#line 600 "mysql4yacc.c"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 304 ".\\mysql4yacc.y"

				yyval.u_var=(struct Updatestruct*)malloc(sizeof(struct Updatestruct));
				yyval.u_var->field=yyattribute(1 - 3).yych;
				yyval.u_var->value=yyattribute(3 - 3).yych;
				yyval.u_var->next=NULL;
				
#line 618 "mysql4yacc.c"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 311 ".\\mysql4yacc.y"

				yyval.t_var=(struct Tables*)malloc(sizeof(struct Tables));
				yyval.t_var->table=yyattribute(1 - 3).yych;
				yyval.t_var->next=yyattribute(3 - 3).t_var;
				//printf("tables : table , tables   table=%s next=%p\n",$$->table,$$->next);
				
#line 636 "mysql4yacc.c"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 318 ".\\mysql4yacc.y"

				yyval.t_var=(struct Tables*)malloc(sizeof(struct Tables));
				yyval.t_var->table=yyattribute(1 - 1).yych;
				yyval.t_var->next=null;
				//printf("tables : table   table=%s  next=%p\n",$$->table,$$->next);
				
#line 654 "mysql4yacc.c"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 325 ".\\mysql4yacc.y"

				yyval.fs_var=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				yyval.fs_var=yyattribute(1 - 1).fs_var;
				//printf("规约-fields_star :selectfields field=%s next=%p \n",$$->field,$$->next);
				
#line 671 "mysql4yacc.c"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 331 ".\\mysql4yacc.y"

				yyval.fs_var=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				yyval.fs_var->field=(char*)malloc(strlen("*")*sizeof(char));
				strcpy(yyval.fs_var->field,"*");
				yyval.fs_var->next=null;
				//printf("规约-fields_star : *  field=%s next=%p \n",$$->field,$$->next);
				
#line 690 "mysql4yacc.c"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 339 ".\\mysql4yacc.y"

				yyval.fs_var=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				yyval.fs_var->field=yyattribute(1 - 3).yych;
				yyval.fs_var->next=yyattribute(3 - 3).fs_var;
				//printf("规约-selectfields : field,selectfields  field=%s next=%p \n",$$->field,$$->next);
				
#line 708 "mysql4yacc.c"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 346 ".\\mysql4yacc.y"

				yyval.fs_var=(struct Fieldstar*)malloc(sizeof(struct Fieldstar));
				yyval.fs_var->field=yyattribute(1 - 1).yych;
				yyval.fs_var->next=null;
				//printf("规约-selectfields : field,selectfields  field=%s next=%p \n",$$->field,$$->next);
				
#line 726 "mysql4yacc.c"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 354 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var=yyattribute(2 - 3).con_var;
				//printf("规约-conditions : (condition) cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 744 "mysql4yacc.c"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 361 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 3).con_var;
				yyval.con_var->right=yyattribute(3 - 3).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("AND")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"AND");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions : conditions AND conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 767 "mysql4yacc.c"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 373 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 3).con_var;
				yyval.con_var->right=yyattribute(3 - 3).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("OR")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"OR");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  conditions OR conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 790 "mysql4yacc.c"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 385 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(2 - 2).con_var;
				yyval.con_var->right=yyattribute(2 - 2).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("NOT")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"NOT");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions : NOT conditions  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 813 "mysql4yacc.c"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 396 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 4).con_var;
				yyval.con_var->right=yyattribute(4 - 4).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("<>")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"<>");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition >= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				//printf("left=(value=%s,type=%d,left=%p,right=%p)\n",$$->left->value,$$->left->type,$$->left->left,$$->left->right);
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$$->right->value,$$->right->type,$$->right->left,$$->right->right);
				
#line 838 "mysql4yacc.c"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 410 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 4).con_var;
				yyval.con_var->right=yyattribute(4 - 4).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("!=")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"!=");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition != condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				//printf("left=(value=%s,type=%d,left=%p,right=%p)\n",$$->left->value,$$->left->type,$$->left->left,$$->left->right);
				//printf("right=(value=%s,type=%d,left=%p,right=%p)\n",$$->right->value,$$->right->type,$$->right->left,$$->right->right);
				
#line 863 "mysql4yacc.c"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 424 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 3).con_var;
				yyval.con_var->right=yyattribute(3 - 3).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen(">")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,">");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition > condition  cur=%p  left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 886 "mysql4yacc.c"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 436 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 4).con_var;
				yyval.con_var->right=yyattribute(4 - 4).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen(">=")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,">=");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition >= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 909 "mysql4yacc.c"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 448 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 3).con_var;
				yyval.con_var->right=yyattribute(3 - 3).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("<")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"<");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition < condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 932 "mysql4yacc.c"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 460 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 4).con_var;
				yyval.con_var->right=yyattribute(4 - 4).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("<=")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"<=");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition <= condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 955 "mysql4yacc.c"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 472 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->left=yyattribute(1 - 3).con_var;
				yyval.con_var->right=yyattribute(3 - 3).con_var;
				yyval.con_var->com_op=(char*)malloc((strlen("=")+1)*sizeof(char));
				strcpy(yyval.con_var->com_op,"=");
				yyval.con_var->type=-1;
				yyval.con_var->value=null;
				//printf("规约-conditions :  condition = condition cur=%p   left=%p  right=%p  com_op=%s  type=%d  value=%s\n",$$,$$->left,$$->right,$$->com_op
				//		,$$->type,$$->value);
				
#line 978 "mysql4yacc.c"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 484 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->type=1;
				yyval.con_var->value=(char*)malloc((strlen("TRUE")+1)*sizeof(char));
				strcpy(yyval.con_var->value,"TRUE");
				yyval.con_var->left=null;
				yyval.con_var->right=null;
				yyval.con_var->com_op=null;
				//printf("规约-condition : TRUE  type=%d value=%s\n",$$->type,$$->value);
				
#line 1000 "mysql4yacc.c"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 495 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->type=1;
				yyval.con_var->value=(char*)malloc((strlen("FALSE")+1)*sizeof(char));
				strcpy(yyval.con_var->value,"FALSE");
				yyval.con_var->left=null;
				yyval.con_var->right=null;
				yyval.con_var->com_op=null;
				//printf("规约-condition : FALSE  type=%d value=%s\n",$$->type,$$->value);
				
#line 1022 "mysql4yacc.c"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 506 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->type=2;
				yyval.con_var->value=(char*)malloc((strlen(yyattribute(1 - 1).yych)+1)*sizeof(char));
				strcpy(yyval.con_var->value,yyattribute(1 - 1).yych);
				yyval.con_var->left=null;
				yyval.con_var->right=null;
				yyval.con_var->com_op=null;
				//printf("规约-condition : expr  type=%d value=%s\n",$$->type,$$->value);
				
#line 1044 "mysql4yacc.c"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 517 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->type=0;
				yyval.con_var->value=(char*)malloc((strlen(yyattribute(1 - 1).yych)+1)*sizeof(char));
				strcpy(yyval.con_var->value,yyattribute(1 - 1).yych);
				yyval.con_var->left=null;
				yyval.con_var->right=null;
				yyval.con_var->com_op=null;
				//printf("规约-condition : field  type=%d value=%s\n",$$->type,$$->value);
				
#line 1066 "mysql4yacc.c"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 528 ".\\mysql4yacc.y"

				yyval.con_var=(struct Conditions*)malloc(sizeof(struct Conditions));
				yyval.con_var->type=1;
				yyval.con_var->value=(char*)malloc((strlen(yyattribute(1 - 1).yych)+1)*sizeof(char));
				strcpy(yyval.con_var->value,yyattribute(1 - 1).yych);
				yyval.con_var->left=null;
				yyval.con_var->right=null;
				yyval.con_var->com_op=null;
				//printf("规约-condition : field  type=%d value=%s\n",$$->type,$$->value);
				
#line 1088 "mysql4yacc.c"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 539 ".\\mysql4yacc.y"

			int tmp=atoi(yyattribute(1 - 3).yych)+atoi(yyattribute(3 - 3).yych);
			yyval.yych=(char*)malloc(12*sizeof(char));
			sprintf(yyval.yych,"%d",tmp);
			//printf("识别e+e %s+%s=%s\n",$1,$3,$$);
			
#line 1106 "mysql4yacc.c"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 545 ".\\mysql4yacc.y"

			int tmp=atoi(yyattribute(1 - 3).yych)-atoi(yyattribute(3 - 3).yych);
			yyval.yych=(char*)malloc(12*sizeof(char));
			sprintf(yyval.yych,"%d",tmp);
			//printf("识别e-e %s-%s=%s\n",$1,$3,$$);
			
#line 1124 "mysql4yacc.c"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 551 ".\\mysql4yacc.y"

			int tmp=atoi(yyattribute(1 - 3).yych)*atoi(yyattribute(3 - 3).yych);
			yyval.yych=(char*)malloc(12*sizeof(char));
			sprintf(yyval.yych,"%d",tmp);
			//printf("识别e*e %s*%s=%s\n",$1,$3,$$);
			
#line 1142 "mysql4yacc.c"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 557 ".\\mysql4yacc.y"

			int tmp=atoi(yyattribute(1 - 3).yych)/atoi(yyattribute(3 - 3).yych);
			yyval.yych=(char*)malloc(12*sizeof(char));
			sprintf(yyval.yych,"%d",tmp);
			//printf("识别e/e %s/%s=%s\n",$1,$3,$$);
			
#line 1160 "mysql4yacc.c"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 563 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(12*sizeof(char));
			sprintf(yyval.yych,"%s",yyattribute(1 - 1).yych);
			//printf("识别数字%s\n",$$);
			
#line 1177 "mysql4yacc.c"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 569 ".\\mysql4yacc.y"
 
			 yyval.cfdef_var=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			 yyval.cfdef_var->field=yyattribute(1 - 3).yych;
			 yyval.cfdef_var->next=yyattribute(3 - 3).cfdef_var;
			 //printf("规约-fields : fields , field=%s next=%p\n",$1,$3);
			 
#line 1195 "mysql4yacc.c"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 577 ".\\mysql4yacc.y"

			 yyval.cfdef_var=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			 yyval.cfdef_var->field=yyattribute(1 - 1).yych;
			 yyval.cfdef_var->next=NULL;
			 //printf("规约-fields : field=%s next=%p\n",$$->field,$$->next);
			 
#line 1213 "mysql4yacc.c"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 585 ".\\mysql4yacc.y"

			yyval.ivdef_var=(struct Insertvaluedef*)malloc(sizeof(struct Insertvaluedef));
			yyval.ivdef_var->value=yyattribute(1 - 1).yych;
			yyval.ivdef_var->next=NULL;
			//printf("规约-datas : datas ,data=%s next=%p\n",$$->value,$$->next);
			
#line 1231 "mysql4yacc.c"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 592 ".\\mysql4yacc.y"

			yyval.ivdef_var=(struct Insertvaluedef*)malloc(sizeof(struct Insertvaluedef));
			yyval.ivdef_var->value=yyattribute(1 - 3).yych;
			yyval.ivdef_var->next=yyattribute(3 - 3).ivdef_var;
			//printf("规约-datas : datas ,data=%s next=%p\n",$$->value,$$->next);
			
#line 1249 "mysql4yacc.c"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 599 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(1 - 1).yych)*sizeof(char));
			strcpy(yyval.yych,yyattribute(1 - 1).yych);
			//printf("规约-data: string=%s\n",$$);
			
#line 1266 "mysql4yacc.c"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 605 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(1 - 1).yych)*sizeof(char));
			strcpy(yyval.yych,yyattribute(1 - 1).yych);
			//printf("规约-data: NUMBER=%s\n",$$);
			
#line 1283 "mysql4yacc.c"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 611 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(2 - 3).yych)*sizeof(char));
			strcpy(yyval.yych,yyattribute(2 - 3).yych);
			//printf("规约-string: string=%s\n",$$);
			
#line 1300 "mysql4yacc.c"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 617 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(2 - 3).yych)*sizeof(char));
			strcpy(yyval.yych,yyattribute(2 - 3).yych);
			//printf("规约-string: ID=%s\n",$$);
			
#line 1317 "mysql4yacc.c"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 623 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(2 - 3).yych)*sizeof(char));
			strcpy(yyval.yych,yyattribute(2 - 3).yych);
			//printf("规约-string: NUMBER=%s\n",$$);
			
#line 1334 "mysql4yacc.c"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 629 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(1 - 1).yych)*sizeof(char));
			sprintf(yyval.yych,"%s",yyattribute(1 - 1).yych);
			//printf("规约-table : ID     ID=%s\n",$1);
			
#line 1351 "mysql4yacc.c"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 636 ".\\mysql4yacc.y"

			yyval.cfdef_var=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			yyval.cfdef_var->field=yyattribute(1 - 1).cfdef_var->field;
			yyval.cfdef_var->type=yyattribute(1 - 1).cfdef_var->type;
			yyval.cfdef_var->next=NULL;
			//printf("规约-fieldsdefinition : field_type   field=%s    type=%s  next=%p\n",$$->field,$$->type,$$->next);
			
#line 1370 "mysql4yacc.c"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 644 ".\\mysql4yacc.y"

			yyval.cfdef_var=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			yyval.cfdef_var=yyattribute(1 - 3).cfdef_var;
			yyval.cfdef_var->next=yyattribute(3 - 3).cfdef_var;
			//printf("规约-fieldsdefinition : fieldsdefinition ',' field_type    field=%s  type=%s next=%p\n",$$->field,$$->type,$$->next);
			
#line 1388 "mysql4yacc.c"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 652 ".\\mysql4yacc.y"

			yyval.cfdef_var=(struct Createfieldsdef*)malloc(sizeof(struct Createfieldsdef));
			yyval.cfdef_var->field=yyattribute(1 - 2).yych;
			yyval.cfdef_var->type=yyattribute(2 - 2).yych;
			//printf("规约-field_type : field type        field=%s     type=%s\n",$$->field,$$->type);
			
#line 1406 "mysql4yacc.c"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 660 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen(yyattribute(1 - 1).yych)*sizeof(char));
			yyval.yych=yyattribute(1 - 1).yych;
			//printf("规约-field : ID         field=%s\n",$$);
			
#line 1423 "mysql4yacc.c"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 667 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen("CHAR")+strlen(yyattribute(3 - 4).yych)*sizeof(char)+1);
			sprintf(yyval.yych,"CHAR %s",yyattribute(3 - 4).yych);
			//printf("规约-type : CHAR (NUMBER)          type= %s\n",$$);
			
#line 1440 "mysql4yacc.c"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 673 ".\\mysql4yacc.y"

			yyval.yych=(char*)malloc(strlen("INT")+1);
			yyval.yych="INT";
			//printf("规约-type: INT   type=%s\n",$$);
			
#line 1457 "mysql4yacc.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\'!\'", 33 },
	{ "\'\\\'\'", 39 },
	{ "\'(\'", 40 },
	{ "\')\'", 41 },
	{ "\'*\'", 42 },
	{ "\'+\'", 43 },
	{ "\',\'", 44 },
	{ "\'-\'", 45 },
	{ "\'/\'", 47 },
	{ "\';\'", 59 },
	{ "\'<\'", 60 },
	{ "\'=\'", 61 },
	{ "\'>\'", 62 },
	{ "error", 256 },
	{ "OR", 257 },
	{ "AND", 258 },
	{ "NOT", 259 },
	{ "CREATE", 260 },
	{ "TABLE", 261 },
	{ "CHAR", 262 },
	{ "INT", 263 },
	{ "DATABASE", 264 },
	{ "USE", 265 },
	{ "SHOW", 266 },
	{ "DATABASES", 267 },
	{ "EXIT", 268 },
	{ "QUIT", 269 },
	{ "DROP", 270 },
	{ "TABLES", 271 },
	{ "INSERT", 272 },
	{ "INTO", 273 },
	{ "VALUES", 274 },
	{ "SELECT", 275 },
	{ "FROM", 276 },
	{ "WHERE", 277 },
	{ "FALSE", 278 },
	{ "TRUE", 279 },
	{ "DELETE", 280 },
	{ "UPDATE", 281 },
	{ "SET", 282 },
	{ "ID", 283 },
	{ "NUMBER", 284 },
	{ "STRING", 285 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: statements",
	"statements: statements statement",
	"statements: statement",
	"statement: usedatabasesql",
	"statement: showsql",
	"statement: createsql",
	"statement: dropsql",
	"statement: insertsql",
	"statement: selectsql",
	"statement: deletesql",
	"statement: updatesql",
	"statement: exitsql",
	"usedatabasesql: USE databasename \';\'",
	"showsql: SHOW DATABASES \';\'",
	"showsql: SHOW TABLES \';\'",
	"databasename: ID",
	"createsql: CREATE DATABASE databasename \';\'",
	"createsql: CREATE TABLE table \'(\' fieldsdefinition \')\' \';\'",
	"dropsql: DROP DATABASE databasename \';\'",
	"dropsql: DROP TABLE table \';\'",
	"insertsql: INSERT INTO table \'(\' fields \')\' VALUES \'(\' datas \')\' \';\'",
	"insertsql: INSERT INTO table VALUES \'(\' datas \')\' \';\'",
	"selectsql: SELECT fields_star FROM tables \';\'",
	"selectsql: SELECT fields_star FROM tables WHERE conditions \';\'",
	"deletesql: DELETE FROM table WHERE conditions \';\'",
	"deletesql: DELETE FROM table \';\'",
	"updatesql: UPDATE table SET fields_values \';\'",
	"updatesql: UPDATE table SET fields_values WHERE conditions \';\'",
	"fields_values: field \'=\' data \',\' fields_values",
	"fields_values: field \'=\' data",
	"tables: table \',\' tables",
	"tables: table",
	"fields_star: selectfields",
	"fields_star: \'*\'",
	"selectfields: field \',\' selectfields",
	"selectfields: field",
	"conditions: \'(\' conditions \')\'",
	"conditions: conditions AND conditions",
	"conditions: conditions OR conditions",
	"conditions: NOT conditions",
	"conditions: condition \'<\' \'>\' condition",
	"conditions: condition \'!\' \'=\' condition",
	"conditions: condition \'>\' condition",
	"conditions: condition \'>\' \'=\' condition",
	"conditions: condition \'<\' condition",
	"conditions: condition \'<\' \'=\' condition",
	"conditions: condition \'=\' condition",
	"conditions: TRUE",
	"conditions: FALSE",
	"condition: expr",
	"condition: field",
	"condition: string",
	"expr: expr \'+\' expr",
	"expr: expr \'-\' expr",
	"expr: expr \'*\' expr",
	"expr: expr \'/\' expr",
	"expr: NUMBER",
	"fields: field \',\' fields",
	"fields: field",
	"datas: data",
	"datas: data \',\' datas",
	"data: string",
	"data: NUMBER",
	"string: \'\\\'\' STRING \'\\\'\'",
	"string: \'\\\'\' ID \'\\\'\'",
	"string: \'\\\'\' NUMBER \'\\\'\'",
	"table: ID",
	"fieldsdefinition: field_type",
	"fieldsdefinition: field_type \',\' fieldsdefinition",
	"field_type: field type",
	"field: ID",
	"type: CHAR \'(\' NUMBER \')\'",
	"type: INT",
	"exitsql: EXIT",
	"exitsql: QUIT"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 2, 0 },
	{ 1, 1, 1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, -1 },
	{ 2, 1, 2 },
	{ 3, 3, 3 },
	{ 4, 3, 4 },
	{ 4, 3, 5 },
	{ 5, 1, 6 },
	{ 6, 4, 7 },
	{ 6, 7, 8 },
	{ 7, 4, 9 },
	{ 7, 4, 10 },
	{ 8, 11, 11 },
	{ 8, 8, 12 },
	{ 9, 5, 13 },
	{ 9, 7, 14 },
	{ 10, 6, 15 },
	{ 10, 4, 16 },
	{ 11, 5, 17 },
	{ 11, 7, 18 },
	{ 12, 5, 19 },
	{ 12, 3, 20 },
	{ 13, 3, 21 },
	{ 13, 1, 22 },
	{ 14, 1, 23 },
	{ 14, 1, 24 },
	{ 15, 3, 25 },
	{ 15, 1, 26 },
	{ 16, 3, 27 },
	{ 16, 3, 28 },
	{ 16, 3, 29 },
	{ 16, 2, 30 },
	{ 16, 4, 31 },
	{ 16, 4, 32 },
	{ 16, 3, 33 },
	{ 16, 4, 34 },
	{ 16, 3, 35 },
	{ 16, 4, 36 },
	{ 16, 3, 37 },
	{ 16, 1, 38 },
	{ 16, 1, 39 },
	{ 17, 1, 40 },
	{ 17, 1, 41 },
	{ 17, 1, 42 },
	{ 18, 3, 43 },
	{ 18, 3, 44 },
	{ 18, 3, 45 },
	{ 18, 3, 46 },
	{ 18, 1, 47 },
	{ 19, 3, 48 },
	{ 19, 1, 49 },
	{ 20, 1, 50 },
	{ 20, 3, 51 },
	{ 21, 1, 52 },
	{ 21, 1, 53 },
	{ 22, 3, 54 },
	{ 22, 3, 55 },
	{ 22, 3, 56 },
	{ 23, 1, 57 },
	{ 24, 1, 58 },
	{ 24, 3, 59 },
	{ 25, 2, 60 },
	{ 26, 1, 61 },
	{ 27, 4, 62 },
	{ 27, 1, 63 },
	{ 28, 1, -1 },
	{ 28, 1, -1 }
};

int YYNEAR YYDCDECL yytokenaction_size = 282;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 20, YYAT_ACCEPT, 0 },
	{ 147, YYAT_SHIFT, 74 },
	{ 112, YYAT_SHIFT, 75 },
	{ 47, YYAT_SHIFT, 56 },
	{ 64, YYAT_SHIFT, 86 },
	{ 59, YYAT_SHIFT, 72 },
	{ 50, YYAT_SHIFT, 61 },
	{ 118, YYAT_SHIFT, 145 },
	{ 84, YYAT_SHIFT, 113 },
	{ 104, YYAT_SHIFT, 130 },
	{ 81, YYAT_SHIFT, 106 },
	{ 81, YYAT_SHIFT, 107 },
	{ 133, YYAT_SHIFT, 106 },
	{ 81, YYAT_SHIFT, 108 },
	{ 132, YYAT_SHIFT, 106 },
	{ 81, YYAT_SHIFT, 109 },
	{ 157, YYAT_SHIFT, 158 },
	{ 133, YYAT_SHIFT, 109 },
	{ 156, YYAT_SHIFT, 157 },
	{ 132, YYAT_SHIFT, 109 },
	{ 74, YYAT_SHIFT, 101 },
	{ 74, YYAT_SHIFT, 102 },
	{ 74, YYAT_SHIFT, 103 },
	{ 6, YYAT_SHIFT, 28 },
	{ 3, YYAT_SHIFT, 26 },
	{ 146, YYAT_SHIFT, 155 },
	{ 6, YYAT_SHIFT, 29 },
	{ 104, YYAT_ERROR, 0 },
	{ 3, YYAT_SHIFT, 27 },
	{ 1, YYAT_SHIFT, 22 },
	{ 142, YYAT_SHIFT, 32 },
	{ 142, YYAT_SHIFT, 79 },
	{ 1, YYAT_SHIFT, 23 },
	{ 114, YYAT_SHIFT, 138 },
	{ 114, YYAT_SHIFT, 139 },
	{ 84, YYAT_SHIFT, 114 },
	{ 84, YYAT_SHIFT, 115 },
	{ 84, YYAT_SHIFT, 116 },
	{ 67, YYAT_SHIFT, 90 },
	{ 67, YYAT_SHIFT, 91 },
	{ 144, YYAT_SHIFT, 32 },
	{ 135, YYAT_SHIFT, 112 },
	{ 124, YYAT_SHIFT, 148 },
	{ 122, YYAT_SHIFT, 147 },
	{ 121, YYAT_SHIFT, 146 },
	{ 117, YYAT_SHIFT, 144 },
	{ 116, YYAT_SHIFT, 142 },
	{ 113, YYAT_SHIFT, 137 },
	{ 109, YYAT_SHIFT, 79 },
	{ 103, YYAT_SHIFT, 129 },
	{ 102, YYAT_SHIFT, 128 },
	{ 101, YYAT_SHIFT, 127 },
	{ 100, YYAT_SHIFT, 126 },
	{ 98, YYAT_SHIFT, 125 },
	{ 97, YYAT_SHIFT, 124 },
	{ 93, YYAT_SHIFT, 122 },
	{ 90, YYAT_SHIFT, 121 },
	{ 88, YYAT_SHIFT, 119 },
	{ 83, YYAT_SHIFT, 110 },
	{ 71, YYAT_SHIFT, 37 },
	{ 69, YYAT_SHIFT, 94 },
	{ 68, YYAT_SHIFT, 93 },
	{ 66, YYAT_SHIFT, 89 },
	{ 65, YYAT_SHIFT, 88 },
	{ 63, YYAT_SHIFT, 85 },
	{ 58, YYAT_SHIFT, 71 },
	{ 57, YYAT_SHIFT, 70 },
	{ 46, YYAT_SHIFT, 55 },
	{ 45, YYAT_SHIFT, 54 },
	{ 41, YYAT_SHIFT, 53 },
	{ 40, YYAT_SHIFT, 52 },
	{ 38, YYAT_SHIFT, 51 },
	{ 35, YYAT_SHIFT, 49 },
	{ 33, YYAT_SHIFT, 48 },
	{ 29, YYAT_SHIFT, 24 },
	{ 27, YYAT_SHIFT, 44 },
	{ 26, YYAT_SHIFT, 43 },
	{ 25, YYAT_SHIFT, 42 },
	{ 9, YYAT_SHIFT, 36 },
	{ 8, YYAT_SHIFT, 31 },
	{ 7, YYAT_SHIFT, 30 },
	{ 0, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 118, YYAT_SHIFT, 111 },
	{ 118, YYAT_SHIFT, 112 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 112, YYAT_SHIFT, 76 },
	{ 64, YYAT_SHIFT, 87 },
	{ 59, YYAT_SHIFT, 73 },
	{ 50, YYAT_SHIFT, 62 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 47, YYAT_SHIFT, 57 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 112, YYAT_SHIFT, 77 },
	{ 112, YYAT_SHIFT, 78 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 147, YYAT_SHIFT, 95 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 1 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 2 },
	{ 20, YYAT_SHIFT, 3 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 4 },
	{ 20, YYAT_SHIFT, 5 },
	{ 20, YYAT_SHIFT, 6 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 7 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 8 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 20, YYAT_SHIFT, 9 },
	{ 20, YYAT_SHIFT, 10 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ 81, 1, YYAT_DEFAULT, 20 },
	{ -232, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 29 },
	{ -243, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 73 },
	{ 0, 0, YYAT_REDUCE, 74 },
	{ -238, 1, YYAT_ERROR, 0 },
	{ -193, 1, YYAT_ERROR, 0 },
	{ 37, 1, YYAT_DEFAULT, 144 },
	{ -198, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ 0, 0, YYAT_REDUCE, 4 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ 0, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ 0, 0, YYAT_DEFAULT, 29 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 18, 1, YYAT_ERROR, 0 },
	{ 17, 1, YYAT_ERROR, 0 },
	{ 16, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ -209, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ 0, 0, YYAT_REDUCE, 33 },
	{ 0, 0, YYAT_REDUCE, 70 },
	{ -203, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ 28, 1, YYAT_REDUCE, 35 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ 0, 0, YYAT_REDUCE, 66 },
	{ -211, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ 30, 1, YYAT_ERROR, 0 },
	{ 10, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 9, 1, YYAT_ERROR, 0 },
	{ 8, 1, YYAT_ERROR, 0 },
	{ -37, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 71 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ -53, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ 0, 0, YYAT_REDUCE, 16 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ 26, 1, YYAT_ERROR, 0 },
	{ 21, 1, YYAT_REDUCE, 31 },
	{ -54, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 34 },
	{ 0, 0, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ 3, 1, YYAT_ERROR, 0 },
	{ -55, 1, YYAT_ERROR, 0 },
	{ 22, 1, YYAT_ERROR, 0 },
	{ 18, 1, YYAT_REDUCE, 67 },
	{ -224, 1, YYAT_ERROR, 0 },
	{ 20, 1, YYAT_ERROR, 0 },
	{ 16, 1, YYAT_REDUCE, 58 },
	{ 0, 0, YYAT_DEFAULT, 147 },
	{ -224, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 22 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ -263, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ 0, 0, YYAT_REDUCE, 48 },
	{ 0, 0, YYAT_REDUCE, 47 },
	{ 0, 0, YYAT_REDUCE, 56 },
	{ 0, 0, YYAT_REDUCE, 51 },
	{ -32, 1, YYAT_REDUCE, 49 },
	{ 0, 0, YYAT_REDUCE, 50 },
	{ -1, 1, YYAT_DEFAULT, 118 },
	{ -25, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 147 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ -2, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ 16, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 72 },
	{ 0, 0, YYAT_REDUCE, 69 },
	{ -219, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 144 },
	{ 0, 0, YYAT_REDUCE, 62 },
	{ 0, 0, YYAT_REDUCE, 61 },
	{ 13, 1, YYAT_ERROR, 0 },
	{ 9, 1, YYAT_REDUCE, 59 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ -7, 1, YYAT_DEFAULT, 118 },
	{ 12, 1, YYAT_ERROR, 0 },
	{ 11, 1, YYAT_ERROR, 0 },
	{ 10, 1, YYAT_ERROR, 0 },
	{ -32, 1, YYAT_DEFAULT, 118 },
	{ 0, 0, YYAT_REDUCE, 39 },
	{ 0, 0, YYAT_DEFAULT, 109 },
	{ 0, 0, YYAT_DEFAULT, 109 },
	{ 0, 0, YYAT_DEFAULT, 109 },
	{ -236, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_DEFAULT, 112 },
	{ -38, 1, YYAT_DEFAULT, 142 },
	{ -14, 1, YYAT_ERROR, 0 },
	{ -28, 1, YYAT_DEFAULT, 142 },
	{ 0, 0, YYAT_DEFAULT, 142 },
	{ -15, 1, YYAT_DEFAULT, 142 },
	{ 1, 1, YYAT_REDUCE, 29 },
	{ -52, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_REDUCE, 68 },
	{ -240, 1, YYAT_ERROR, 0 },
	{ 3, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 57 },
	{ -17, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 147 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ 0, 0, YYAT_REDUCE, 64 },
	{ 0, 0, YYAT_REDUCE, 65 },
	{ 0, 0, YYAT_REDUCE, 63 },
	{ 0, 0, YYAT_REDUCE, 36 },
	{ 0, 0, YYAT_REDUCE, 54 },
	{ -28, 1, YYAT_REDUCE, 52 },
	{ -30, 1, YYAT_REDUCE, 53 },
	{ 0, 0, YYAT_REDUCE, 55 },
	{ -217, 1, YYAT_REDUCE, 38 },
	{ 0, 0, YYAT_REDUCE, 37 },
	{ 0, 0, YYAT_DEFAULT, 142 },
	{ 0, 0, YYAT_DEFAULT, 142 },
	{ 0, 0, YYAT_DEFAULT, 142 },
	{ 0, 0, YYAT_REDUCE, 44 },
	{ 0, 0, YYAT_REDUCE, 46 },
	{ -253, 1, YYAT_DEFAULT, 147 },
	{ 0, 0, YYAT_REDUCE, 42 },
	{ -243, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ -16, 1, YYAT_ERROR, 0 },
	{ -38, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ 0, 0, YYAT_REDUCE, 60 },
	{ 0, 0, YYAT_REDUCE, 41 },
	{ 0, 0, YYAT_REDUCE, 45 },
	{ 0, 0, YYAT_REDUCE, 40 },
	{ 0, 0, YYAT_REDUCE, 43 },
	{ 0, 0, YYAT_REDUCE, 28 },
	{ 0, 0, YYAT_REDUCE, 71 },
	{ -23, 1, YYAT_ERROR, 0 },
	{ -43, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 20 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 66;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 20, 39 },
	{ 20, 17 },
	{ 20, 12 },
	{ 144, 154 },
	{ 20, 16 },
	{ 20, 19 },
	{ 20, 18 },
	{ 20, 13 },
	{ 20, 15 },
	{ 20, 11 },
	{ 142, 153 },
	{ 142, 81 },
	{ 49, 60 },
	{ 94, 123 },
	{ 71, 99 },
	{ 142, 80 },
	{ 139, 152 },
	{ 144, 63 },
	{ 138, 151 },
	{ 142, 82 },
	{ 94, 69 },
	{ 147, 156 },
	{ 147, 98 },
	{ 49, 35 },
	{ 71, 58 },
	{ 137, 150 },
	{ 20, 14 },
	{ 89, 120 },
	{ 89, 66 },
	{ 89, 67 },
	{ 112, 136 },
	{ 112, 84 },
	{ 85, 117 },
	{ 85, 96 },
	{ 8, 33 },
	{ 8, 34 },
	{ 0, 20 },
	{ 0, 21 },
	{ 125, 149 },
	{ 116, 143 },
	{ 115, 141 },
	{ 114, 140 },
	{ 111, 135 },
	{ 109, 134 },
	{ 108, 133 },
	{ 107, 132 },
	{ 106, 131 },
	{ 87, 118 },
	{ 76, 105 },
	{ 75, 104 },
	{ 73, 100 },
	{ 70, 97 },
	{ 67, 92 },
	{ 62, 83 },
	{ 56, 68 },
	{ 52, 65 },
	{ 51, 64 },
	{ 48, 59 },
	{ 36, 50 },
	{ 30, 47 },
	{ 29, 46 },
	{ 28, 45 },
	{ 23, 41 },
	{ 22, 40 },
	{ 10, 38 },
	{ 2, 25 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 35, 20 },
	{ 0, -1 },
	{ 60, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 20, 49 },
	{ 0, -1 },
	{ 41, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -2, -1 },
	{ 0, -1 },
	{ 40, -1 },
	{ 57, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 38, -1 },
	{ 55, -1 },
	{ 36, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 35, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 44, 71 },
	{ -3, -1 },
	{ 0, -1 },
	{ 44, 144 },
	{ 31, 89 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 35, 94 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 37, 112 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 25, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 31, 147 },
	{ 1, -1 },
	{ 0, -1 },
	{ 34, 112 },
	{ 0, -1 },
	{ 33, 112 },
	{ 32, 112 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 11, -1 },
	{ 0, -1 },
	{ 31, 112 },
	{ 0, -1 },
	{ 3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -6, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 28, -1 },
	{ 27, -1 },
	{ 26, -1 },
	{ 25, -1 },
	{ 0, -1 },
	{ 26, 112 },
	{ 14, 142 },
	{ 0, -1 },
	{ 24, 142 },
	{ 23, 142 },
	{ 22, 142 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 18, 147 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 8, 142 },
	{ 1, 142 },
	{ -1, 142 },
	{ 0, -1 },
	{ 0, -1 },
	{ -7, -1 },
	{ 0, -1 },
	{ -9, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 1, 85 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 680 ".\\mysql4yacc.y"


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


