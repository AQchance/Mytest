#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 37 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# mysql4yacc.v
# YACC verbose file generated from mysql4yacc.y.
# 
# Date: 06/26/20
# Time: 08:46:48
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : statements $end

    1  statements : statements statement
    2             | statement

    3  statement : usedatabasesql
    4            | showsql
    5            | createsql
    6            | dropsql
    7            | insertsql
    8            | selectsql
    9            | deletesql
   10            | updatesql
   11            | exitsql

   12  usedatabasesql : USE databasename ';'

   13  showsql : SHOW DATABASES ';'
   14          | SHOW TABLES ';'

   15  databasename : ID

   16  createsql : CREATE DATABASE databasename ';'
   17            | CREATE TABLE table '(' fieldsdefinition ')' ';'

   18  dropsql : DROP DATABASE databasename ';'
   19          | DROP TABLE table ';'

   20  insertsql : INSERT INTO table '(' fields ')' VALUES '(' datas ')' ';'
   21            | INSERT INTO table VALUES '(' datas ')' ';'

   22  selectsql : SELECT fields_star FROM tables ';'
   23            | SELECT fields_star FROM tables WHERE conditions ';'

   24  deletesql : DELETE FROM table WHERE conditions ';'
   25            | DELETE FROM table ';'

   26  updatesql : UPDATE table SET fields_values ';'
   27            | UPDATE table SET fields_values WHERE conditions ';'

   28  fields_values : field '=' data ',' fields_values
   29                | field '=' data

   30  tables : table ',' tables
   31         | table

   32  fields_star : selectfields
   33              | '*'

   34  selectfields : field ',' selectfields
   35               | field

   36  conditions : '(' conditions ')'
   37             | conditions AND conditions
   38             | conditions OR conditions
   39             | NOT conditions
   40             | condition '<' '>' condition
   41             | condition '!' '=' condition
   42             | condition '>' condition
   43             | condition '>' '=' condition
   44             | condition '<' condition
   45             | condition '<' '=' condition
   46             | condition '=' condition
   47             | TRUE
   48             | FALSE

   49  condition : expr
   50            | field
   51            | string

   52  expr : expr '+' expr
   53       | expr '-' expr
   54       | expr '*' expr
   55       | expr '/' expr
   56       | NUMBER

   57  fields : field ',' fields
   58         | field

   59  datas : data
   60        | data ',' datas

   61  data : string
   62       | NUMBER

   63  string : '\'' STRING '\''
   64         | '\'' ID '\''
   65         | '\'' NUMBER '\''

   66  table : ID

   67  fieldsdefinition : field_type
   68                   | field_type ',' fieldsdefinition

   69  field_type : field type

   70  field : ID

   71  type : CHAR '(' NUMBER ')'
   72       | INT

   73  exitsql : EXIT
   74          | QUIT


##############################################################################
# States
##############################################################################

state 0
	$accept : . statements $end

	CREATE  shift 1
	USE  shift 2
	SHOW  shift 3
	EXIT  shift 4
	QUIT  shift 5
	DROP  shift 6
	INSERT  shift 7
	SELECT  shift 8
	DELETE  shift 9
	UPDATE  shift 10

	updatesql  goto 11
	showsql  goto 12
	selectsql  goto 13
	exitsql  goto 14
	deletesql  goto 15
	createsql  goto 16
	usedatabasesql  goto 17
	insertsql  goto 18
	dropsql  goto 19
	statements  goto 20
	statement  goto 21


state 1
	createsql : CREATE . DATABASE databasename ';'
	createsql : CREATE . TABLE table '(' fieldsdefinition ')' ';'

	TABLE  shift 22
	DATABASE  shift 23


state 2
	usedatabasesql : USE . databasename ';'

	ID  shift 24

	databasename  goto 25


state 3
	showsql : SHOW . DATABASES ';'
	showsql : SHOW . TABLES ';'

	DATABASES  shift 26
	TABLES  shift 27


state 4
	exitsql : EXIT .  (73)

	.  reduce 73


state 5
	exitsql : QUIT .  (74)

	.  reduce 74


state 6
	dropsql : DROP . DATABASE databasename ';'
	dropsql : DROP . TABLE table ';'

	TABLE  shift 28
	DATABASE  shift 29


state 7
	insertsql : INSERT . INTO table '(' fields ')' VALUES '(' datas ')' ';'
	insertsql : INSERT . INTO table VALUES '(' datas ')' ';'

	INTO  shift 30


state 8
	selectsql : SELECT . fields_star FROM tables ';'
	selectsql : SELECT . fields_star FROM tables WHERE conditions ';'

	'*'  shift 31
	ID  shift 32

	fields_star  goto 33
	selectfields  goto 34
	field  goto 35


state 9
	deletesql : DELETE . FROM table WHERE conditions ';'
	deletesql : DELETE . FROM table ';'

	FROM  shift 36


state 10
	updatesql : UPDATE . table SET fields_values ';'
	updatesql : UPDATE . table SET fields_values WHERE conditions ';'

	ID  shift 37

	table  goto 38


state 11
	statement : updatesql .  (10)

	.  reduce 10


state 12
	statement : showsql .  (4)

	.  reduce 4


state 13
	statement : selectsql .  (8)

	.  reduce 8


state 14
	statement : exitsql .  (11)

	.  reduce 11


state 15
	statement : deletesql .  (9)

	.  reduce 9


state 16
	statement : createsql .  (5)

	.  reduce 5


state 17
	statement : usedatabasesql .  (3)

	.  reduce 3


state 18
	statement : insertsql .  (7)

	.  reduce 7


state 19
	statement : dropsql .  (6)

	.  reduce 6


state 20
	$accept : statements . $end  (0)
	statements : statements . statement

	$end  accept
	CREATE  shift 1
	USE  shift 2
	SHOW  shift 3
	EXIT  shift 4
	QUIT  shift 5
	DROP  shift 6
	INSERT  shift 7
	SELECT  shift 8
	DELETE  shift 9
	UPDATE  shift 10

	updatesql  goto 11
	showsql  goto 12
	selectsql  goto 13
	exitsql  goto 14
	deletesql  goto 15
	createsql  goto 16
	usedatabasesql  goto 17
	insertsql  goto 18
	dropsql  goto 19
	statement  goto 39


state 21
	statements : statement .  (2)

	.  reduce 2


state 22
	createsql : CREATE TABLE . table '(' fieldsdefinition ')' ';'

	ID  shift 37

	table  goto 40


state 23
	createsql : CREATE DATABASE . databasename ';'

	ID  shift 24

	databasename  goto 41


state 24
	databasename : ID .  (15)

	.  reduce 15


state 25
	usedatabasesql : USE databasename . ';'

	';'  shift 42


state 26
	showsql : SHOW DATABASES . ';'

	';'  shift 43


state 27
	showsql : SHOW TABLES . ';'

	';'  shift 44


state 28
	dropsql : DROP TABLE . table ';'

	ID  shift 37

	table  goto 45


state 29
	dropsql : DROP DATABASE . databasename ';'

	ID  shift 24

	databasename  goto 46


state 30
	insertsql : INSERT INTO . table '(' fields ')' VALUES '(' datas ')' ';'
	insertsql : INSERT INTO . table VALUES '(' datas ')' ';'

	ID  shift 37

	table  goto 47


state 31
	fields_star : '*' .  (33)

	.  reduce 33


state 32
	field : ID .  (70)

	.  reduce 70


state 33
	selectsql : SELECT fields_star . FROM tables ';'
	selectsql : SELECT fields_star . FROM tables WHERE conditions ';'

	FROM  shift 48


state 34
	fields_star : selectfields .  (32)

	.  reduce 32


state 35
	selectfields : field . ',' selectfields
	selectfields : field .  (35)

	','  shift 49
	.  reduce 35


state 36
	deletesql : DELETE FROM . table WHERE conditions ';'
	deletesql : DELETE FROM . table ';'

	ID  shift 37

	table  goto 50


state 37
	table : ID .  (66)

	.  reduce 66


state 38
	updatesql : UPDATE table . SET fields_values ';'
	updatesql : UPDATE table . SET fields_values WHERE conditions ';'

	SET  shift 51


state 39
	statements : statements statement .  (1)

	.  reduce 1


state 40
	createsql : CREATE TABLE table . '(' fieldsdefinition ')' ';'

	'('  shift 52


state 41
	createsql : CREATE DATABASE databasename . ';'

	';'  shift 53


state 42
	usedatabasesql : USE databasename ';' .  (12)

	.  reduce 12


state 43
	showsql : SHOW DATABASES ';' .  (13)

	.  reduce 13


state 44
	showsql : SHOW TABLES ';' .  (14)

	.  reduce 14


state 45
	dropsql : DROP TABLE table . ';'

	';'  shift 54


state 46
	dropsql : DROP DATABASE databasename . ';'

	';'  shift 55


state 47
	insertsql : INSERT INTO table . '(' fields ')' VALUES '(' datas ')' ';'
	insertsql : INSERT INTO table . VALUES '(' datas ')' ';'

	'('  shift 56
	VALUES  shift 57


state 48
	selectsql : SELECT fields_star FROM . tables ';'
	selectsql : SELECT fields_star FROM . tables WHERE conditions ';'

	ID  shift 37

	table  goto 58
	tables  goto 59


state 49
	selectfields : field ',' . selectfields

	ID  shift 32

	selectfields  goto 60
	field  goto 35


state 50
	deletesql : DELETE FROM table . WHERE conditions ';'
	deletesql : DELETE FROM table . ';'

	';'  shift 61
	WHERE  shift 62


state 51
	updatesql : UPDATE table SET . fields_values ';'
	updatesql : UPDATE table SET . fields_values WHERE conditions ';'

	ID  shift 32

	field  goto 63
	fields_values  goto 64


state 52
	createsql : CREATE TABLE table '(' . fieldsdefinition ')' ';'

	ID  shift 32

	fieldsdefinition  goto 65
	field_type  goto 66
	field  goto 67


state 53
	createsql : CREATE DATABASE databasename ';' .  (16)

	.  reduce 16


state 54
	dropsql : DROP TABLE table ';' .  (19)

	.  reduce 19


state 55
	dropsql : DROP DATABASE databasename ';' .  (18)

	.  reduce 18


state 56
	insertsql : INSERT INTO table '(' . fields ')' VALUES '(' datas ')' ';'

	ID  shift 32

	fields  goto 68
	field  goto 69


state 57
	insertsql : INSERT INTO table VALUES . '(' datas ')' ';'

	'('  shift 70


state 58
	tables : table . ',' tables
	tables : table .  (31)

	','  shift 71
	.  reduce 31


state 59
	selectsql : SELECT fields_star FROM tables . ';'
	selectsql : SELECT fields_star FROM tables . WHERE conditions ';'

	';'  shift 72
	WHERE  shift 73


state 60
	selectfields : field ',' selectfields .  (34)

	.  reduce 34


state 61
	deletesql : DELETE FROM table ';' .  (25)

	.  reduce 25


state 62
	deletesql : DELETE FROM table WHERE . conditions ';'

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 83
	condition  goto 84


state 63
	fields_values : field . '=' data
	fields_values : field . '=' data ',' fields_values

	'='  shift 85


state 64
	updatesql : UPDATE table SET fields_values . ';'
	updatesql : UPDATE table SET fields_values . WHERE conditions ';'

	';'  shift 86
	WHERE  shift 87


state 65
	createsql : CREATE TABLE table '(' fieldsdefinition . ')' ';'

	')'  shift 88


state 66
	fieldsdefinition : field_type .  (67)
	fieldsdefinition : field_type . ',' fieldsdefinition

	','  shift 89
	.  reduce 67


state 67
	field_type : field . type

	CHAR  shift 90
	INT  shift 91

	type  goto 92


state 68
	insertsql : INSERT INTO table '(' fields . ')' VALUES '(' datas ')' ';'

	')'  shift 93


state 69
	fields : field .  (58)
	fields : field . ',' fields

	','  shift 94
	.  reduce 58


state 70
	insertsql : INSERT INTO table VALUES '(' . datas ')' ';'

	'\''  shift 74
	NUMBER  shift 95

	string  goto 96
	datas  goto 97
	data  goto 98


state 71
	tables : table ',' . tables

	ID  shift 37

	table  goto 58
	tables  goto 99


state 72
	selectsql : SELECT fields_star FROM tables ';' .  (22)

	.  reduce 22


state 73
	selectsql : SELECT fields_star FROM tables WHERE . conditions ';'

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 100
	condition  goto 84


state 74
	string : '\'' . ID '\''
	string : '\'' . NUMBER '\''
	string : '\'' . STRING '\''

	ID  shift 101
	NUMBER  shift 102
	STRING  shift 103


state 75
	conditions : '(' . conditions ')'

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 104
	condition  goto 84


state 76
	conditions : NOT . conditions

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 105
	condition  goto 84


state 77
	conditions : FALSE .  (48)

	.  reduce 48


state 78
	conditions : TRUE .  (47)

	.  reduce 47


state 79
	expr : NUMBER .  (56)

	.  reduce 56


state 80
	condition : string .  (51)

	.  reduce 51


state 81
	expr : expr . '+' expr
	condition : expr .  (49)
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : expr . '-' expr

	'*'  shift 106
	'+'  shift 107
	'-'  shift 108
	'/'  shift 109
	.  reduce 49


state 82
	condition : field .  (50)

	.  reduce 50


state 83
	deletesql : DELETE FROM table WHERE conditions . ';'
	conditions : conditions . OR conditions
	conditions : conditions . AND conditions

	';'  shift 110
	OR  shift 111
	AND  shift 112


state 84
	conditions : condition . '<' '>' condition
	conditions : condition . '<' condition
	conditions : condition . '>' condition
	conditions : condition . '>' '=' condition
	conditions : condition . '<' '=' condition
	conditions : condition . '=' condition
	conditions : condition . '!' '=' condition

	'!'  shift 113
	'<'  shift 114
	'='  shift 115
	'>'  shift 116


state 85
	fields_values : field '=' . data
	fields_values : field '=' . data ',' fields_values

	'\''  shift 74
	NUMBER  shift 95

	string  goto 96
	data  goto 117


state 86
	updatesql : UPDATE table SET fields_values ';' .  (26)

	.  reduce 26


state 87
	updatesql : UPDATE table SET fields_values WHERE . conditions ';'

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 118
	condition  goto 84


state 88
	createsql : CREATE TABLE table '(' fieldsdefinition ')' . ';'

	';'  shift 119


state 89
	fieldsdefinition : field_type ',' . fieldsdefinition

	ID  shift 32

	fieldsdefinition  goto 120
	field_type  goto 66
	field  goto 67


state 90
	type : CHAR . '(' NUMBER ')'

	'('  shift 121


state 91
	type : INT .  (72)

	.  reduce 72


state 92
	field_type : field type .  (69)

	.  reduce 69


state 93
	insertsql : INSERT INTO table '(' fields ')' . VALUES '(' datas ')' ';'

	VALUES  shift 122


state 94
	fields : field ',' . fields

	ID  shift 32

	fields  goto 123
	field  goto 69


state 95
	data : NUMBER .  (62)

	.  reduce 62


state 96
	data : string .  (61)

	.  reduce 61


state 97
	insertsql : INSERT INTO table VALUES '(' datas . ')' ';'

	')'  shift 124


state 98
	datas : data . ',' datas
	datas : data .  (59)

	','  shift 125
	.  reduce 59


state 99
	tables : table ',' tables .  (30)

	.  reduce 30


state 100
	selectsql : SELECT fields_star FROM tables WHERE conditions . ';'
	conditions : conditions . OR conditions
	conditions : conditions . AND conditions

	';'  shift 126
	OR  shift 111
	AND  shift 112


state 101
	string : '\'' ID . '\''

	'\''  shift 127


state 102
	string : '\'' NUMBER . '\''

	'\''  shift 128


state 103
	string : '\'' STRING . '\''

	'\''  shift 129


state 104
	conditions : conditions . OR conditions
	conditions : '(' conditions . ')'
	conditions : conditions . AND conditions

	')'  shift 130
	OR  shift 111
	AND  shift 112


state 105
	conditions : NOT conditions .  (39)
	conditions : conditions . OR conditions
	conditions : conditions . AND conditions

	.  reduce 39


state 106
	expr : expr '*' . expr

	NUMBER  shift 79

	expr  goto 131


state 107
	expr : expr '+' . expr

	NUMBER  shift 79

	expr  goto 132


state 108
	expr : expr '-' . expr

	NUMBER  shift 79

	expr  goto 133


state 109
	expr : expr '/' . expr

	NUMBER  shift 79

	expr  goto 134


state 110
	deletesql : DELETE FROM table WHERE conditions ';' .  (24)

	.  reduce 24


state 111
	conditions : conditions OR . conditions

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 135
	condition  goto 84


state 112
	conditions : conditions AND . conditions

	'\''  shift 74
	'('  shift 75
	NOT  shift 76
	FALSE  shift 77
	TRUE  shift 78
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	conditions  goto 136
	condition  goto 84


state 113
	conditions : condition '!' . '=' condition

	'='  shift 137


state 114
	conditions : condition '<' . '>' condition
	conditions : condition '<' . condition
	conditions : condition '<' . '=' condition

	'\''  shift 74
	'='  shift 138
	'>'  shift 139
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 140


state 115
	conditions : condition '=' . condition

	'\''  shift 74
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 141


state 116
	conditions : condition '>' . condition
	conditions : condition '>' . '=' condition

	'\''  shift 74
	'='  shift 142
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 143


state 117
	fields_values : field '=' data .  (29)
	fields_values : field '=' data . ',' fields_values

	','  shift 144
	.  reduce 29


state 118
	updatesql : UPDATE table SET fields_values WHERE conditions . ';'
	conditions : conditions . OR conditions
	conditions : conditions . AND conditions

	';'  shift 145
	OR  shift 111
	AND  shift 112


state 119
	createsql : CREATE TABLE table '(' fieldsdefinition ')' ';' .  (17)

	.  reduce 17


state 120
	fieldsdefinition : field_type ',' fieldsdefinition .  (68)

	.  reduce 68


state 121
	type : CHAR '(' . NUMBER ')'

	NUMBER  shift 146


state 122
	insertsql : INSERT INTO table '(' fields ')' VALUES . '(' datas ')' ';'

	'('  shift 147


state 123
	fields : field ',' fields .  (57)

	.  reduce 57


state 124
	insertsql : INSERT INTO table VALUES '(' datas ')' . ';'

	';'  shift 148


state 125
	datas : data ',' . datas

	'\''  shift 74
	NUMBER  shift 95

	string  goto 96
	datas  goto 149
	data  goto 98


state 126
	selectsql : SELECT fields_star FROM tables WHERE conditions ';' .  (23)

	.  reduce 23


state 127
	string : '\'' ID '\'' .  (64)

	.  reduce 64


state 128
	string : '\'' NUMBER '\'' .  (65)

	.  reduce 65


state 129
	string : '\'' STRING '\'' .  (63)

	.  reduce 63


state 130
	conditions : '(' conditions ')' .  (36)

	.  reduce 36


state 131
	expr : expr . '+' expr
	expr : expr '*' expr .  (54)
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : expr . '-' expr

	.  reduce 54


state 132
	expr : expr '+' expr .  (52)
	expr : expr . '+' expr
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : expr . '-' expr

	'*'  shift 106
	'/'  shift 109
	.  reduce 52


state 133
	expr : expr . '+' expr
	expr : expr . '*' expr
	expr : expr . '/' expr
	expr : expr '-' expr .  (53)
	expr : expr . '-' expr

	'*'  shift 106
	'/'  shift 109
	.  reduce 53


state 134
	expr : expr . '+' expr
	expr : expr . '*' expr
	expr : expr '/' expr .  (55)
	expr : expr . '/' expr
	expr : expr . '-' expr

	.  reduce 55


state 135
	conditions : conditions OR conditions .  (38)
	conditions : conditions . OR conditions
	conditions : conditions . AND conditions

	AND  shift 112
	.  reduce 38


state 136
	conditions : conditions . OR conditions
	conditions : conditions AND conditions .  (37)
	conditions : conditions . AND conditions

	.  reduce 37


state 137
	conditions : condition '!' '=' . condition

	'\''  shift 74
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 150


state 138
	conditions : condition '<' '=' . condition

	'\''  shift 74
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 151


state 139
	conditions : condition '<' '>' . condition

	'\''  shift 74
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 152


state 140
	conditions : condition '<' condition .  (44)

	.  reduce 44


state 141
	conditions : condition '=' condition .  (46)

	.  reduce 46


state 142
	conditions : condition '>' '=' . condition

	'\''  shift 74
	ID  shift 32
	NUMBER  shift 79

	string  goto 80
	expr  goto 81
	field  goto 82
	condition  goto 153


state 143
	conditions : condition '>' condition .  (42)

	.  reduce 42


state 144
	fields_values : field '=' data ',' . fields_values

	ID  shift 32

	field  goto 63
	fields_values  goto 154


state 145
	updatesql : UPDATE table SET fields_values WHERE conditions ';' .  (27)

	.  reduce 27


state 146
	type : CHAR '(' NUMBER . ')'

	')'  shift 155


state 147
	insertsql : INSERT INTO table '(' fields ')' VALUES '(' . datas ')' ';'

	'\''  shift 74
	NUMBER  shift 95

	string  goto 96
	datas  goto 156
	data  goto 98


state 148
	insertsql : INSERT INTO table VALUES '(' datas ')' ';' .  (21)

	.  reduce 21


state 149
	datas : data ',' datas .  (60)

	.  reduce 60


state 150
	conditions : condition '!' '=' condition .  (41)

	.  reduce 41


state 151
	conditions : condition '<' '=' condition .  (45)

	.  reduce 45


state 152
	conditions : condition '<' '>' condition .  (40)

	.  reduce 40


state 153
	conditions : condition '>' '=' condition .  (43)

	.  reduce 43


state 154
	fields_values : field '=' data ',' fields_values .  (28)

	.  reduce 28


state 155
	type : CHAR '(' NUMBER ')' .  (71)

	.  reduce 71


state 156
	insertsql : INSERT INTO table '(' fields ')' VALUES '(' datas . ')' ';'

	')'  shift 157


state 157
	insertsql : INSERT INTO table '(' fields ')' VALUES '(' datas ')' . ';'

	';'  shift 158


state 158
	insertsql : INSERT INTO table '(' fields ')' VALUES '(' datas ')' ';' .  (20)

	.  reduce 20


##############################################################################
# Summary
##############################################################################

44 token(s), 29 nonterminal(s)
75 grammar rule(s), 159 state(s)


##############################################################################
# End of File
##############################################################################
