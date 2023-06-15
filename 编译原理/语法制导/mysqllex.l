%{
/****************************************************************************
mysql4lex.l
ParserWizard generated Lex file.

Date: 2020年6月11日
****************************************************************************/

#include "mysql4yacc.h"
#include<stdlib.h>
#include<String.h>
char* stop;

%}
digit [0-9]
digits {digit}+

%%
[ ]+ {}
[\n]+ {

			}
"CREATE" {
			//printf("移进 CREATE\n");
			return CREATE;
			}
"DATABASE" {
			//printf("移进 DATABASE\n");
			return DATABASE;
			}
"USE" {
			//printf("移进 USE\n");
			return USE;
			}
"SHOW" {
			return SHOW;
			}
"DATABASES" {
			return DATABASES;
			}
"DROP" {
			return DROP;
			}
"TABLE" {
			//printf("移进 TABLE\n");
			return TABLE;
			}
"TABLES" {
			//printf("移进 TABLES\n");
			return TABLES;
			}
"INT"  {
			//printf("移进 INT\n");
			return INT;
			}
"CHAR" {
			//printf("移进 CHAR\n");
			return CHAR;
			}
"INSERT" {
			return INSERT;
			}
"INTO" {
			return INTO;
			}
"VALUES" {
			return VALUES;
			}
"SELECT" {
			//printf("移进 select\n");
			return SELECT;
			}
"FROM" {
			//printf("移进 from\n");
			return FROM;
			}
"WHERE" {
			return WHERE;
			}
"AND" {
			return AND;
			}
"OR" {
			return OR;
			}
"NOT" {
			return NOT;
			}
"TRUE" {
			return TRUE;
			}
"FALSE" {
			return FALSE;
			}
"DELETE" {
		return DELETE;
		}
"UPDATE" {
		return UPDATE;
		}
"SET" {
		return SET;
		}
"EXIT" {
			return EXIT;
			}
"QUIT" {
			return QUIT;
			}
"("     {
			//printf("移进 \"(\"\n");
			return '(';}
")"     {
			//printf("移进 \")\"\n");
			return ')';}
","     {
			//printf("移进 \",\"\n");
			return ',';}
";"     {
			//printf("移进 \";\"\n");
			return ';';}
"+"     {
			//printf("移进 \"+\"\n");
			return '+';}
"-"     {
			//printf("移进 \"-\"\n");
			return '-';}
"*"     {
			//printf("移进 \"*\"\n");
			return '*';}
"/"     {
			//printf("移进 \"/\"\n");
			return '/';}
">"     {
			//printf("移进 \">\"\n");
			return '>';}
"<"     {
			//printf("移进 \"<\"\n");
			return '<';}
"="     {
			//printf("移进 \"=\"\n");
			return '=';}
"!"     {
			//printf("移进 \"!\"\n");
			return '!';}	
"\'"    {
			//printf("移进 \"/'"\n");
			return '\'';}
{digits} {
			//yylval.num=strtod(yytext,&stop);
			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 数字===%s\n",yylval.yych);
			return NUMBER;
			}
			
[a-zA-Z][a-zA-Z0-9_]* {
			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 ID===%s\n",yylval.yych);
			return ID;
			}
[a-zA-Z0-9_]* {
			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 STRING===%s\n",yylval.yych);
			return STRING;
			}
/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

