/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUBTRACT = 258,
     ADD = 259,
     DIVIDE = 260,
     MULTIPLY = 261,
     NE = 262,
     EQ = 263,
     GE = 264,
     GT = 265,
     LE = 266,
     LT = 267,
     ASSIGN = 268,
     VOID = 269,
     CHARACTER = 270,
     PRINTFF = 271,
     SCANFF = 272,
     INT = 273,
     FLOAT = 274,
     CHAR = 275,
     FOR = 276,
     IF = 277,
     ELSE = 278,
     TRUE = 279,
     FALSE = 280,
     NUMBER = 281,
     FLOAT_NUM = 282,
     ID = 283,
     AND = 284,
     OR = 285,
     STR = 286,
     UNARY = 287,
     INCLUDE = 288,
     RETURN = 289
   };
#endif
/* Tokens.  */
#define SUBTRACT 258
#define ADD 259
#define DIVIDE 260
#define MULTIPLY 261
#define NE 262
#define EQ 263
#define GE 264
#define GT 265
#define LE 266
#define LT 267
#define ASSIGN 268
#define VOID 269
#define CHARACTER 270
#define PRINTFF 271
#define SCANFF 272
#define INT 273
#define FLOAT 274
#define CHAR 275
#define FOR 276
#define IF 277
#define ELSE 278
#define TRUE 279
#define FALSE 280
#define NUMBER 281
#define FLOAT_NUM 282
#define ID 283
#define AND 284
#define OR 285
#define STR 286
#define UNARY 287
#define INCLUDE 288
#define RETURN 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 60 "parser.y"
{ struct var_name { 
			char name[100]; 
			struct Node* nd;
		} node_obj;

		struct var_name2 { 
			char name[100]; 
			struct Node* nd;
			char type[5];
		} exp_obj; 

		struct var_name3 {
			char name[100];
			struct Node* nd;
			char if_body[5];
			char else_body[5];
		} if_obj;
	}
/* Line 1529 of yacc.c.  */
#line 136 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

