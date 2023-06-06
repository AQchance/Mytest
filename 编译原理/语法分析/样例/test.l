%{
#include "test.tab.h"
%}

%%
[" "]+             {}
[0-9]+          { yylval = atoi(yytext); return T_NUM; }
[-/+*()]      { return yytext[0]; }
"\n"           { return 0; }
%%

int yywrap(void) { 
    return 1;
}