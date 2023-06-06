%{
#include <stdio.h>
void yyerror(const char* msg) {
    printf("Syntax error!\n");
}
%}

%token T_NUM

%left '+' '-'
%left '*' '/'

%%
E   :   E '+' E         {printf("+++++\n"); }
    |   E '-' E         {printf("-----\n"); }
    |   E '*' E         {printf("*****\n"); }
    |   E '/' E         {printf("/////\n"); }
    |   T_NUM           {printf("nnnnn\n"); }
    |   '(' E ')'       {printf("kkkkk\n"); }
    ;

%%

int main() {
    while(1){
        yyparse();
    }
}