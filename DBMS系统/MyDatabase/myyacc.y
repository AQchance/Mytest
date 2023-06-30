%{
    #include <stdio.h>
    #include "include/dbms.h"
    void yyerror(const char* msg) {
        printf("Syntax error!\n");
    }

%}
%token  NUMBER
%token  ID
%token  CREATE 
%token SHOW 
%token  DROP 
%token  USE 
%token  DATABASE 
%token  DATABASES 
%token  TABLE 
%token  TABLES 
%token  CHAR
%token  INT
%token  INSERT 
%token  INTO 
%token  VALUES 
%token  SELECT 
%token  FROM 
%token  WHERE 
%token  UPDATE 
%token  SET
%token  OR
%token  AND
%token  DELETE
%token  STRING
%token  NNN
%token  ',' ';' '(' ')'
%token  '='
%token  '>' '<'
%left OR
%left AND
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%
start       :   statements NNN  {return 0;}
            ;

statements  :   statements  statement   {printf("YES!\n");}
            |   statement   {printf("YES!\n");}
            ;


statement   :   createsql   {CreateDataBase("MyDataBase");}
            |   insertsql
            |   selectsql
            |   deletesql
            |   updatesql
            |   opersql
            ;


opersql     :   CREATE DATABASE ID ';'
            |   SHOW DATABASES  ';'
            |   DROP DATABASE ID ';'
            |   USE ID ';'
            |   SHOW TABLES ';'
            |   DROP TABLE ID ';'
            ;

createsql   :   CREATE TABLE ID '(' tablecolumn ')' ';'
            ;

tablecolumn :   tablecolumn ',' ID type
            |   ID type
            ;

type        :   CHAR '(' NUMBER ')'
            |   INT
            ;

insertsql   :   INSERT INTO ID VALUES '(' insertvalues ')' ';'
            |   INSERT INTO ID '(' column ')' VALUES '(' insertvalues ')'
            ;
    
column      :   column ',' ID
            |   ID
            ;

value       :   STRING
            |   NUMBER
            ;

insertvalues:   insertvalues ',' value
            |   value
            ;

selectsql   :   SELECT column FROM column WHERE conditions ';'
            |   SELECT column FROM column ';'
            |   SELECT '*' FROM column ';'
            |   SELECT '*' FROM column WHERE conditions ';'
            ;

conditions  :   conditions logic myconditions
            |   myconditions
            ;

myconditions:   '(' conditions ')'
            |   ID compare expression
            ;

logic       :   OR
            |   AND
            ;

compare     :   '>'
            |   '='
            |   '<'
            |   '!' '='
            ;

expression  :   expression '+' expression
            |   expression '-' expression
            |   expression '*' expression
            |   expression '/' expression
            |   expression '%' expression
            |   '(' expression ')'
            |   value
            ;

updatesql   :   UPDATE ID SET updatevalues WHERE conditions ';'
            ;

updatevalues:   updatevalues ',' myupdatavalues
            |   myupdatavalues
myupdatavalues:   ID '=' STRING
            |   ID '=' NUMBER
            ;

deletesql   :   DELETE FROM ID WHERE conditions
            ;
%%

int main(){
    while(1){
        yyparse();
    }
}