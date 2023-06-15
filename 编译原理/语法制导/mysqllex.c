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
* mysql4lex.c
* C source file generated from mysql4lex.l.
* 
* Date: 06/26/20
* Time: 08:46:48
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mysql4lex.l"

/****************************************************************************
mysql4lex.l
ParserWizard generated Lex file.

Date: 2020年6月11日
****************************************************************************/

#include "mysql4yacc.h"
#include<stdlib.h>
#include<String.h>
char* stop;


#line 55 "mysql4lex.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mysql4lex.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 19 ".\\mysql4lex.l"

#line 176 "mysql4lex.c"
		}
		break;
	case 2:
		{
#line 20 ".\\mysql4lex.l"


			
#line 185 "mysql4lex.c"
		}
		break;
	case 3:
		{
#line 23 ".\\mysql4lex.l"

			//printf("移进 CREATE\n");
			return CREATE;
			
#line 195 "mysql4lex.c"
		}
		break;
	case 4:
		{
#line 27 ".\\mysql4lex.l"

			//printf("移进 DATABASE\n");
			return DATABASE;
			
#line 205 "mysql4lex.c"
		}
		break;
	case 5:
		{
#line 31 ".\\mysql4lex.l"

			//printf("移进 USE\n");
			return USE;
			
#line 215 "mysql4lex.c"
		}
		break;
	case 6:
		{
#line 35 ".\\mysql4lex.l"

			return SHOW;
			
#line 224 "mysql4lex.c"
		}
		break;
	case 7:
		{
#line 38 ".\\mysql4lex.l"

			return DATABASES;
			
#line 233 "mysql4lex.c"
		}
		break;
	case 8:
		{
#line 41 ".\\mysql4lex.l"

			return DROP;
			
#line 242 "mysql4lex.c"
		}
		break;
	case 9:
		{
#line 44 ".\\mysql4lex.l"

			//printf("移进 TABLE\n");
			return TABLE;
			
#line 252 "mysql4lex.c"
		}
		break;
	case 10:
		{
#line 48 ".\\mysql4lex.l"

			//printf("移进 TABLES\n");
			return TABLES;
			
#line 262 "mysql4lex.c"
		}
		break;
	case 11:
		{
#line 52 ".\\mysql4lex.l"

			//printf("移进 INT\n");
			return INT;
			
#line 272 "mysql4lex.c"
		}
		break;
	case 12:
		{
#line 56 ".\\mysql4lex.l"

			//printf("移进 CHAR\n");
			return CHAR;
			
#line 282 "mysql4lex.c"
		}
		break;
	case 13:
		{
#line 60 ".\\mysql4lex.l"

			return INSERT;
			
#line 291 "mysql4lex.c"
		}
		break;
	case 14:
		{
#line 63 ".\\mysql4lex.l"

			return INTO;
			
#line 300 "mysql4lex.c"
		}
		break;
	case 15:
		{
#line 66 ".\\mysql4lex.l"

			return VALUES;
			
#line 309 "mysql4lex.c"
		}
		break;
	case 16:
		{
#line 69 ".\\mysql4lex.l"

			//printf("移进 select\n");
			return SELECT;
			
#line 319 "mysql4lex.c"
		}
		break;
	case 17:
		{
#line 73 ".\\mysql4lex.l"

			//printf("移进 from\n");
			return FROM;
			
#line 329 "mysql4lex.c"
		}
		break;
	case 18:
		{
#line 77 ".\\mysql4lex.l"

			return WHERE;
			
#line 338 "mysql4lex.c"
		}
		break;
	case 19:
		{
#line 80 ".\\mysql4lex.l"

			return AND;
			
#line 347 "mysql4lex.c"
		}
		break;
	case 20:
		{
#line 83 ".\\mysql4lex.l"

			return OR;
			
#line 356 "mysql4lex.c"
		}
		break;
	case 21:
		{
#line 86 ".\\mysql4lex.l"

			return NOT;
			
#line 365 "mysql4lex.c"
		}
		break;
	case 22:
		{
#line 89 ".\\mysql4lex.l"

			return TRUE;
			
#line 374 "mysql4lex.c"
		}
		break;
	case 23:
		{
#line 92 ".\\mysql4lex.l"

			return FALSE;
			
#line 383 "mysql4lex.c"
		}
		break;
	case 24:
		{
#line 95 ".\\mysql4lex.l"

		return DELETE;
		
#line 392 "mysql4lex.c"
		}
		break;
	case 25:
		{
#line 98 ".\\mysql4lex.l"

		return UPDATE;
		
#line 401 "mysql4lex.c"
		}
		break;
	case 26:
		{
#line 101 ".\\mysql4lex.l"

		return SET;
		
#line 410 "mysql4lex.c"
		}
		break;
	case 27:
		{
#line 104 ".\\mysql4lex.l"

			return EXIT;
			
#line 419 "mysql4lex.c"
		}
		break;
	case 28:
		{
#line 107 ".\\mysql4lex.l"

			return QUIT;
			
#line 428 "mysql4lex.c"
		}
		break;
	case 29:
		{
#line 110 ".\\mysql4lex.l"

			//printf("移进 \"(\"\n");
			return '(';
#line 437 "mysql4lex.c"
		}
		break;
	case 30:
		{
#line 113 ".\\mysql4lex.l"

			//printf("移进 \")\"\n");
			return ')';
#line 446 "mysql4lex.c"
		}
		break;
	case 31:
		{
#line 116 ".\\mysql4lex.l"

			//printf("移进 \",\"\n");
			return ',';
#line 455 "mysql4lex.c"
		}
		break;
	case 32:
		{
#line 119 ".\\mysql4lex.l"

			//printf("移进 \";\"\n");
			return ';';
#line 464 "mysql4lex.c"
		}
		break;
	case 33:
		{
#line 122 ".\\mysql4lex.l"

			//printf("移进 \"+\"\n");
			return '+';
#line 473 "mysql4lex.c"
		}
		break;
	case 34:
		{
#line 125 ".\\mysql4lex.l"

			//printf("移进 \"-\"\n");
			return '-';
#line 482 "mysql4lex.c"
		}
		break;
	case 35:
		{
#line 128 ".\\mysql4lex.l"

			//printf("移进 \"*\"\n");
			return '*';
#line 491 "mysql4lex.c"
		}
		break;
	case 36:
		{
#line 131 ".\\mysql4lex.l"

			//printf("移进 \"/\"\n");
			return '/';
#line 500 "mysql4lex.c"
		}
		break;
	case 37:
		{
#line 134 ".\\mysql4lex.l"

			//printf("移进 \">\"\n");
			return '>';
#line 509 "mysql4lex.c"
		}
		break;
	case 38:
		{
#line 137 ".\\mysql4lex.l"

			//printf("移进 \"<\"\n");
			return '<';
#line 518 "mysql4lex.c"
		}
		break;
	case 39:
		{
#line 140 ".\\mysql4lex.l"

			//printf("移进 \"=\"\n");
			return '=';
#line 527 "mysql4lex.c"
		}
		break;
	case 40:
		{
#line 143 ".\\mysql4lex.l"

			//printf("移进 \"!\"\n");
			return '!';
#line 536 "mysql4lex.c"
		}
		break;
	case 41:
		{
#line 146 ".\\mysql4lex.l"

			//printf("移进 \"/'"\n");
			return '\'';
#line 545 "mysql4lex.c"
		}
		break;
	case 42:
		{
#line 149 ".\\mysql4lex.l"

			//yylval.num=strtod(yytext,&stop);
			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 数字===%s\n",yylval.yych);
			return NUMBER;
			
#line 558 "mysql4lex.c"
		}
		break;
#line 156 ".\\mysql4lex.l"
			
#line 563 "mysql4lex.c"
	case 43:
		{
#line 157 ".\\mysql4lex.l"

			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 ID===%s\n",yylval.yych);
			return ID;
			
#line 573 "mysql4lex.c"
		}
		break;
	case 44:
		{
#line 163 ".\\mysql4lex.l"

			yylval.yych=(char*)malloc(strlen(yytext)+1);
			strcpy(yylval.yych,yytext);
			//printf("移进 STRING===%s\n",yylval.yych);
			return STRING;
			
#line 585 "mysql4lex.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 383;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 3, 3 },
	{ 4, 4 },
	{ 0, 0 },
	{ 50, 30 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 14, 14 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 51, 30 },
	{ 4, 1 },
	{ 5, 1 },
	{ 35, 19 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 6, 1 },
	{ 7, 1 },
	{ 8, 1 },
	{ 9, 1 },
	{ 10, 1 },
	{ 11, 1 },
	{ 12, 1 },
	{ 50, 30 },
	{ 13, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 14, 1 },
	{ 42, 24 },
	{ 15, 1 },
	{ 16, 1 },
	{ 17, 1 },
	{ 18, 1 },
	{ 51, 30 },
	{ 36, 21 },
	{ 19, 1 },
	{ 35, 19 },
	{ 21, 1 },
	{ 22, 1 },
	{ 23, 1 },
	{ 24, 1 },
	{ 44, 25 },
	{ 69, 48 },
	{ 25, 1 },
	{ 37, 21 },
	{ 43, 24 },
	{ 65, 44 },
	{ 66, 44 },
	{ 26, 1 },
	{ 27, 1 },
	{ 70, 48 },
	{ 28, 1 },
	{ 54, 32 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 33, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 42, 24 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 34, 1 },
	{ 36, 21 },
	{ 19, 1 },
	{ 55, 33 },
	{ 21, 1 },
	{ 22, 1 },
	{ 23, 1 },
	{ 24, 1 },
	{ 44, 25 },
	{ 69, 48 },
	{ 25, 1 },
	{ 37, 21 },
	{ 43, 24 },
	{ 65, 44 },
	{ 66, 44 },
	{ 26, 1 },
	{ 27, 1 },
	{ 70, 48 },
	{ 28, 1 },
	{ 54, 32 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 33, 1 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 55, 33 },
	{ 52, 31 },
	{ 45, 26 },
	{ 48, 29 },
	{ 53, 31 },
	{ 0, 0 },
	{ 49, 29 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 52, 31 },
	{ 45, 26 },
	{ 48, 29 },
	{ 53, 31 },
	{ 34, 34 },
	{ 49, 29 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 34, 34 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 0, 0 },
	{ 56, 35 },
	{ 57, 36 },
	{ 58, 37 },
	{ 59, 38 },
	{ 0, 0 },
	{ 60, 39 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 56, 35 },
	{ 57, 36 },
	{ 58, 37 },
	{ 59, 38 },
	{ 20, 116 },
	{ 60, 39 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 20, 116 },
	{ 38, 22 },
	{ 61, 40 },
	{ 62, 41 },
	{ 63, 42 },
	{ 39, 22 },
	{ 64, 43 },
	{ 46, 27 },
	{ 67, 45 },
	{ 68, 47 },
	{ 47, 28 },
	{ 71, 49 },
	{ 72, 50 },
	{ 73, 51 },
	{ 74, 52 },
	{ 75, 53 },
	{ 76, 54 },
	{ 77, 55 },
	{ 40, 22 },
	{ 78, 57 },
	{ 79, 58 },
	{ 80, 59 },
	{ 81, 60 },
	{ 82, 61 },
	{ 83, 62 },
	{ 84, 63 },
	{ 85, 64 },
	{ 86, 65 },
	{ 87, 66 },
	{ 88, 68 },
	{ 89, 69 },
	{ 90, 71 },
	{ 91, 72 },
	{ 38, 22 },
	{ 61, 40 },
	{ 62, 41 },
	{ 63, 42 },
	{ 39, 22 },
	{ 64, 43 },
	{ 46, 27 },
	{ 67, 45 },
	{ 68, 47 },
	{ 47, 28 },
	{ 71, 49 },
	{ 72, 50 },
	{ 73, 51 },
	{ 74, 52 },
	{ 75, 53 },
	{ 76, 54 },
	{ 77, 55 },
	{ 40, 22 },
	{ 78, 57 },
	{ 79, 58 },
	{ 80, 59 },
	{ 81, 60 },
	{ 82, 61 },
	{ 83, 62 },
	{ 84, 63 },
	{ 85, 64 },
	{ 86, 65 },
	{ 87, 66 },
	{ 88, 68 },
	{ 89, 69 },
	{ 90, 71 },
	{ 91, 72 },
	{ 92, 73 },
	{ 93, 74 },
	{ 94, 76 },
	{ 95, 77 },
	{ 96, 79 },
	{ 97, 80 },
	{ 98, 81 },
	{ 99, 84 },
	{ 100, 86 },
	{ 101, 89 },
	{ 102, 91 },
	{ 103, 93 },
	{ 104, 94 },
	{ 105, 95 },
	{ 106, 96 },
	{ 107, 97 },
	{ 108, 98 },
	{ 109, 100 },
	{ 110, 101 },
	{ 111, 102 },
	{ 112, 103 },
	{ 113, 104 },
	{ 114, 107 },
	{ 115, 114 },
	{ 116, 115 },
	{ 41, 23 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 92, 73 },
	{ 93, 74 },
	{ 94, 76 },
	{ 95, 77 },
	{ 96, 79 },
	{ 97, 80 },
	{ 98, 81 },
	{ 99, 84 },
	{ 100, 86 },
	{ 101, 89 },
	{ 102, 91 },
	{ 103, 93 },
	{ 104, 94 },
	{ 105, 95 },
	{ 106, 96 },
	{ 107, 97 },
	{ 108, 98 },
	{ 109, 100 },
	{ 110, 101 },
	{ 111, 102 },
	{ 112, 103 },
	{ 113, 104 },
	{ 114, 107 },
	{ 115, 114 },
	{ 116, 115 },
	{ 41, 23 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 116, -9, 0 },
	{ 1, 0, 0 },
	{ 0, -8, 2 },
	{ 0, -29, 1 },
	{ 0, 0, 40 },
	{ 0, 0, 41 },
	{ 0, 0, 29 },
	{ 0, 0, 30 },
	{ 0, 0, 35 },
	{ 0, 0, 33 },
	{ 0, 0, 31 },
	{ 0, 0, 34 },
	{ 0, 0, 36 },
	{ 34, -42, 42 },
	{ 0, 0, 32 },
	{ 0, 0, 38 },
	{ 0, 0, 39 },
	{ 0, 0, 37 },
	{ 116, -53, 43 },
	{ 116, 0, 43 },
	{ 116, -17, 43 },
	{ 116, 196, 43 },
	{ 116, 262, 43 },
	{ 116, -16, 43 },
	{ 116, -16, 43 },
	{ 116, 44, 43 },
	{ 116, 185, 43 },
	{ 116, 185, 43 },
	{ 116, 55, 43 },
	{ 116, -60, 43 },
	{ 116, 42, 43 },
	{ 116, 8, 43 },
	{ 116, 17, 43 },
	{ 0, 63, 44 },
	{ 116, 129, 43 },
	{ 116, 133, 43 },
	{ 116, 130, 43 },
	{ 116, 116, 43 },
	{ 116, 126, 43 },
	{ 116, 183, 43 },
	{ 116, 190, 43 },
	{ 116, 188, 43 },
	{ 116, 187, 43 },
	{ 116, -16, 43 },
	{ 116, 184, 43 },
	{ 116, 0, 20 },
	{ 116, 196, 43 },
	{ 116, -13, 43 },
	{ 116, 192, 43 },
	{ 116, 206, 43 },
	{ 116, 188, 43 },
	{ 116, 206, 43 },
	{ 116, 206, 43 },
	{ 116, 200, 43 },
	{ 116, 208, 43 },
	{ 116, 0, 19 },
	{ 116, 197, 43 },
	{ 116, 215, 43 },
	{ 116, 216, 43 },
	{ 116, 213, 43 },
	{ 116, 203, 43 },
	{ 116, 200, 43 },
	{ 116, 202, 43 },
	{ 116, 209, 43 },
	{ 116, 218, 43 },
	{ 116, 209, 11 },
	{ 116, 0, 21 },
	{ 116, 205, 43 },
	{ 116, 221, 43 },
	{ 116, 0, 26 },
	{ 116, 204, 43 },
	{ 116, 216, 43 },
	{ 116, 256, 43 },
	{ 116, 261, 43 },
	{ 116, 0, 5 },
	{ 116, 242, 43 },
	{ 116, 246, 43 },
	{ 116, 0, 12 },
	{ 116, 245, 43 },
	{ 116, 264, 43 },
	{ 116, 247, 43 },
	{ 116, 0, 8 },
	{ 116, 0, 27 },
	{ 116, 263, 43 },
	{ 116, 0, 17 },
	{ 116, 251, 43 },
	{ 116, 0, 14 },
	{ 116, 0, 28 },
	{ 116, 267, 43 },
	{ 116, 0, 6 },
	{ 116, 266, 43 },
	{ 116, 0, 22 },
	{ 116, 252, 43 },
	{ 116, 268, 43 },
	{ 116, 269, 43 },
	{ 116, 270, 43 },
	{ 116, 275, 43 },
	{ 116, 272, 43 },
	{ 116, 0, 23 },
	{ 116, 258, 43 },
	{ 116, 259, 43 },
	{ 116, 261, 9 },
	{ 116, 276, 43 },
	{ 116, 263, 43 },
	{ 116, 0, 18 },
	{ 116, 0, 3 },
	{ 116, 264, 43 },
	{ 116, 0, 24 },
	{ 116, 0, 13 },
	{ 116, 0, 16 },
	{ 116, 0, 10 },
	{ 116, 0, 25 },
	{ 116, 0, 15 },
	{ 116, 279, 43 },
	{ 116, 266, 4 },
	{ 0, 138, 7 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 174 ".\\mysql4lex.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


