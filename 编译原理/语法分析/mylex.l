/*设置大小写不敏感*/
%option caseless			

%{
	#include <stdio.h>
	#include "myyacc.tab.h"
%}

%%
[" "]+   {}
create  {return CREATE;}
show {return SHOW;}
drop  {return DROP;}
use  {return USE;}
database  {return DATABASE;}
databases  {return DATABASES;}
table  {return TABLE;}
tables  {return TABLES;}
char  {return CHAR;}
int  {return INT;}
insert  {return INSERT;}
into  {return INTO;}
values  {return VALUES;}
select  {return SELECT;}
from  {return FROM;}
where  {return WHERE;}
and  {return AND;}
or  {return OR;}
update  {return UPDATE;}
set  {return SET;}
delete  {return DELETE;}

[0-9]+ {
	return NUMBER;
}

[a-zA-Z][a-zA-Z0-9_]* {
	return ID;
}

\'[^\']*\'   { return STRING; }



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
"!"		|
"%"		|
"/"		{return yytext[0];}

"\n" {return NNN;}

%%

int yywrap() { 
    return 1;
}