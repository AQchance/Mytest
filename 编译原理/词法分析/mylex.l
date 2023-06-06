/*设置大小写不敏感*/
%option caseless			

%{
	#include <stdio.h>
	#define NUMBER 0
	#define ID 1
	#define CREATE 2
	#define SHOW 3
	#define DROP 4	
	#define USE 5
	#define DATABASE 6
	#define DATABASES 7
	#define TABLE 8
	#define TABLES 9
	#define CHAR 10
	#define INT 11
	#define INSERT 12
	#define INTO 13
	#define VALUES 14
	#define SELECT 15
	#define FROM 16
	#define WHERE 17
	#define AND 18
	#define OR 19
	#define UPDATE 20
	#define SET 21
%}

%%

create  {printf("Identify keywords: CREATE.\n");return CREATE;}
show {printf("Identify keywords: show.\n");return SHOW;}
drop  {printf("Identify keywords: drop.\n");return DROP;}
use  {printf("Identify keywords: USE.\n");return USE;}
database  {printf("Identify keywords: DATABASE.\n");return DATABASE;}
databases  {printf("Identify keywords: DATABASES.\n");return DATABASES;}
table  {printf("Identify keywords: TABLE.\n");return TABLE;}
tables  {printf("Identify keywords: TABLES.\n");return TABLES;}
char  {printf("Identify keywords: CHAR.\n");return CHAR;}
int  {printf("Identify keywords: INT.\n");return INT;}
insert  {printf("Identify keywords: INSERT.\n");return INSERT;}
into  {printf("Identify keywords: INTO.\n");return INTO;}
values  {printf("Identify keywords: VALUES.\n");return VALUES;}
select  {printf("Identify keywords: SELECT.\n");return SELECT;}
from  {printf("Identify keywords: FROM.\n");return FROM;}
where  {printf("Identify keywords: WHERE.\n");return WHERE;}
and  {printf("Identify keywords: AND.\n");return AND;}
or  {printf("Identify keywords: OR.\n");return OR;}
update  {printf("Identify keywords: UPDATE.\n");return UPDATE;}
set  {printf("Identify keywords: SET.\n");return SET;}

[0-9]+ {
	printf("Identify digits.\n");
	return NUMBER;
}

[a-zA-Z][a-zA-Z0-9_]* {
	printf("Identify ID.\n");
	return ID;
}

","		|
";"		|
"("		|
")"		|
">"		|
"<"		|
"="		|
"+"		|
"-"		|
"*"		|
"/"		{printf("Identify %c.\n",yytext[0]);return yytext[0];}

.       ECHO;
%%
int main(int argc, char* argv[]) {
    while(1){
		yylex();
	}
    return 0;
}

int yywrap() { 
    return 1;
}