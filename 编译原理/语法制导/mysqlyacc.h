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
* mysql4yacc.h
* C header file generated from mysql4yacc.y.
* 
* Date: 06/26/20
* Time: 08:46:48
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYSQL4YACC_H
#define _MYSQL4YACC_H

#include <yypars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 77 ".\\mysql4yacc.y"

	int num;
	char * yych;//������
	struct Createfieldsdef{//create����е��ֶζ���
		char *test;
		char *field;//�ֶ�����
		char *type;//�ֶ�����
		struct Createfieldsdef *next;//��һ�ֶ�
	} *cfdef_var;//�ֶζ���
	
	
	struct Insertvaluedef{//insert value�Ľṹ
		char* value;
		struct Insertvaluedef *next;
	}*ivdef_var;
	
	struct Conditions{
		struct Conditions *left;
		struct Conditions *right;
		char* com_op;
		int type;//0���ֶ� 1�ַ��� 2����
		char* value;
		char* table;
	}*con_var;
	
	struct Fieldstar{
		char* field;
		struct Fieldstar* next;
	}*fs_var;
	
	struct Tables{
		char* table;
		struct Tables* next;
	}*t_var;
	
	struct Updatestruct{
		char* field;
		char* value;
		struct Updatestruct* next;
	}*u_var;

#line 77 "mysql4yacc.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

extern YYSTYPE YYNEAR yylval;

#define OR 257
#define AND 258
#define NOT 259
#define CREATE 260
#define TABLE 261
#define CHAR 262
#define INT 263
#define DATABASE 264
#define USE 265
#define SHOW 266
#define DATABASES 267
#define EXIT 268
#define QUIT 269
#define DROP 270
#define TABLES 271
#define INSERT 272
#define INTO 273
#define VALUES 274
#define SELECT 275
#define FROM 276
#define WHERE 277
#define FALSE 278
#define TRUE 279
#define DELETE 280
#define UPDATE 281
#define SET 282
#define ID 283
#define NUMBER 284
#define STRING 285
#endif
