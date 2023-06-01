/*设置大小写不敏感*/
%option caseless			

%{
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

create  {printf("Identify keywords: CREATE.");return CREATE;}
show {printf("Identify keywords: show.");return SHOW;}
drop  {printf("Identify keywords: drop.");return DROP;}
use  {printf("Identify keywords: USE.");return USE;}
database  {printf("Identify keywords: DATABASE.");return DATABASE;}
databases  {printf("Identify keywords: DATABASES.");return DATABASES;}
table  {printf("Identify keywords: TABLE.");return TABLE;}
tables  {printf("Identify keywords: TABLES.");return TABLES;}
char  {printf("Identify keywords: CHAR.");return CHAR;}
int  {printf("Identify keywords: INT.");return INT;}
insert  {printf("Identify keywords: INSERT.");return INSERT;}
into  {printf("Identify keywords: INTO.");return INTO;}
values  {printf("Identify keywords: VALUES.");return VALUES;}
select  {printf("Identify keywords: SELECT.");return SELECT;}
from  {printf("Identify keywords: FROM.");return FROM;}
where  {printf("Identify keywords: WHERE.");return WHERE;}
and  {printf("Identify keywords: AND.");return AND;}
or  {printf("Identify keywords: OR.");return OR;}
update  {printf("Identify keywords: UPDATE.");return UPDATE;}
set  {printf("Identify keywords: SET.");return SET;}

[0-9]+ {
	printf("Identify digits.");
	return NUMBER;
}

[a-zA-Z][a-zA-Z0-9_]* {
	printf("Identify ID.");
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
"/"		|
"."		|
"!"		{return yytext[0];}

.       ECHO;
%%
int main(int argc, char* argv[]) {
    yylex();
    return 0;
}

int yywrap() { 
    return 1;
}