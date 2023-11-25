/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>

	#include<math.h>

    #include"lex.yy.c"
    void yyerror(const char *s);
    int yylex();
    int yywrap();

	void addSymbolToTable(char *, char *, char *, int lineNmber, int );

	void inorderTraversal(struct Node *);
    void validateDeclaration(char *);
	void verifyReturnType(char *);
	int compareDataTypes(char *, char *);
	char *retrieveDataType(char *);
	struct Node* mkNode(struct Node *left, struct Node *right, char *token);

    void addSymbol(char);
    void setType();
    int findSymbol(char *);

	void displaySyntaxTree(struct Node*);
	void writeJSON(struct Node* , FILE* );
	void clearLevel();

    struct dataType {
    char * id_name;
    char * data_type;
    char * type;
    int line_no;
    int scope_level; 
} symbol_table[40];
	int currentScopeLevel = 0;

    int symbolCount=0;
    int q;
	char type[10];
    extern int countn;
	struct Node *head;
	int semanticErrors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int forLoopFlag=0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
	char icg[50][100];

	struct Node { 
		struct Node *left; 
		struct Node *right; 
		char *token; 
	};



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 63 "parser.y"
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
/* Line 193 of yacc.c.  */
#line 245 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 258 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      35,    36,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    15,    16,    19,    22,    24,    26,
      28,    30,    32,    33,    34,    35,    47,    48,    49,    63,
      66,    67,    74,    77,    78,    88,    89,    95,    96,   100,
     102,   104,   105,   106,   111,   112,   117,   118,   123,   124,
     128,   131,   134,   137,   138,   142,   144,   146,   148,   150,
     152,   154,   156,   158,   160,   162,   164,   166,   168,   170,
     172,   173,   178
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    47,    35,    36,    37,    49,    70,
      38,    -1,    45,    33,    -1,    -1,    33,    46,    -1,    48,
      28,    -1,    18,    -1,    14,    -1,    19,    -1,    20,    -1,
       1,    -1,    -1,    -1,    -1,    22,    50,    35,    59,    36,
      51,    37,    49,    38,    52,    57,    -1,    -1,    -1,    21,
      53,    35,    60,    39,    59,    39,    60,    36,    37,    49,
      54,    38,    -1,    49,    49,    -1,    -1,    16,    55,    35,
      31,    36,    39,    -1,    60,    39,    -1,    -1,    17,    56,
      35,    31,    40,    41,    28,    36,    39,    -1,    -1,    23,
      58,    37,    49,    38,    -1,    -1,    69,    68,    69,    -1,
      24,    -1,    25,    -1,    -1,    -1,    48,    28,    61,    65,
      -1,    -1,    28,    62,    42,    66,    -1,    -1,    28,    63,
      68,    66,    -1,    -1,    28,    64,    32,    -1,    32,    28,
      -1,     1,    39,    -1,    42,    69,    -1,    -1,    66,    67,
      66,    -1,    69,    -1,     4,    -1,     3,    -1,     6,    -1,
       5,    -1,    12,    -1,    10,    -1,    11,    -1,     9,    -1,
       8,    -1,     7,    -1,    26,    -1,    27,    -1,    15,    -1,
      28,    -1,    -1,    34,    71,    69,    39,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,   102,   103,   103,   107,   110,   111,   112,
     113,   114,   118,   118,   118,   118,   122,   122,   122,   127,
     128,   128,   129,   130,   130,   134,   134,   135,   138,   151,
     152,   153,   156,   156,   184,   184,   220,   220,   221,   221,
     232,   245,   248,   249,   255,   296,   299,   300,   301,   302,
     305,   306,   307,   308,   309,   310,   313,   314,   315,   316,
     319,   319,   320
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUBTRACT", "ADD", "DIVIDE", "MULTIPLY",
  "NE", "EQ", "GE", "GT", "LE", "LT", "ASSIGN", "VOID", "CHARACTER",
  "PRINTFF", "SCANFF", "INT", "FLOAT", "CHAR", "FOR", "IF", "ELSE", "TRUE",
  "FALSE", "NUMBER", "FLOAT_NUM", "ID", "AND", "OR", "STR", "UNARY",
  "INCLUDE", "RETURN", "'('", "')'", "'{'", "'}'", "';'", "','", "'&'",
  "'='", "$accept", "program", "headers", "@1", "main", "datatype", "body",
  "@2", "@3", "@4", "@5", "@6", "@7", "@8", "else", "@9", "condition",
  "statement", "@10", "@11", "@12", "@13", "init", "expression",
  "arithmetic", "relop", "value", "return", "@14", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    40,    41,   123,   125,    59,
      44,    38,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    45,    47,    48,    48,    48,
      48,    48,    50,    51,    52,    49,    53,    54,    49,    49,
      55,    49,    49,    56,    49,    58,    57,    57,    59,    59,
      59,    59,    61,    60,    62,    60,    63,    60,    64,    60,
      60,    60,    65,    65,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      71,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     0,     0,     0,    11,     0,     0,    13,     2,
       0,     6,     2,     0,     9,     0,     5,     0,     3,     1,
       1,     0,     0,     4,     0,     4,     0,     4,     0,     3,
       2,     2,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,    11,     8,     7,     9,
      10,     3,     0,     0,     0,     6,     0,     0,    11,    20,
      23,    16,    12,    36,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,    40,    32,    60,     0,
       0,    22,     0,     0,     0,    31,     0,    55,    54,    53,
      51,    52,    50,     0,    39,    43,     0,     2,     0,     0,
       0,    58,    29,    30,    56,    57,    59,     0,     0,    35,
      45,    37,     0,    33,     0,     0,     0,    31,    13,     0,
      47,    46,    49,    48,     0,    42,    61,    21,     0,     0,
       0,    28,    44,     0,     0,     0,     0,     0,     0,    24,
       0,    14,     0,    27,     0,    25,    15,     0,     0,    18,
       0,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    12,    25,    39,    32,    90,   103,
      31,   107,    29,    30,   106,   108,    67,    27,    55,    33,
      34,    35,    73,    69,    84,    53,    70,    40,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     -22,   -51,    12,   112,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -19,   -15,   -12,   -51,   -11,   133,    -9,   -51,
     -51,   -51,   -51,   -28,    -1,     0,     1,    -8,   -51,    -3,
       2,    14,    18,    -6,    -2,    15,   -51,   -51,   -51,    24,
      16,   -51,    26,    29,   155,   152,    46,   -51,   -51,   -51,
     -51,   -51,   -51,    46,   -51,    13,    46,   -51,    28,    36,
      44,   -51,   -51,   -51,   -51,   -51,   -51,    48,    -2,    85,
     -51,    85,    46,   -51,    47,    62,    63,   152,   -51,    46,
     -51,   -51,   -51,   -51,    46,   -51,   -51,   -51,    75,    66,
      70,   -51,    85,    72,   155,   133,    73,    88,    49,   -51,
      74,   -51,   133,    86,    78,   -51,   -51,    76,    90,   -51,
     133,   101,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,   -51,   122,   -17,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    51,   -43,   -51,   -51,
     -51,   -51,   -51,   -50,   -51,    67,     3,   -51,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int8 yytable[] =
{
      26,    60,    18,    71,   -38,    47,    48,    49,    50,    51,
      52,     1,     5,    15,   -34,     7,    14,    19,    20,     8,
       9,    10,    21,    22,    16,    18,    17,    36,    37,    23,
      28,    41,    42,    24,    92,    38,    46,    43,     7,   -62,
      19,    20,     8,     9,    10,    21,    22,    54,    68,    44,
      18,    97,    23,    45,    57,    72,    24,    58,   -19,    74,
      59,    61,   -19,     7,    75,    19,    20,     8,     9,    10,
      21,    22,    64,    65,    66,    85,    76,    23,    98,    18,
      68,    24,    91,    77,    78,   104,    86,   101,    80,    81,
      82,    83,     7,   111,    19,    20,     8,     9,    10,    21,
      22,    87,    18,    93,    88,    94,    23,    95,    96,   105,
      24,   102,    99,     6,   109,     7,   -17,    19,    20,     8,
       9,    10,    21,    22,   100,    13,     7,   110,    89,    23,
       8,     9,    10,    24,    18,    79,     0,     0,     0,   112,
       0,     0,     0,     0,     0,    11,     0,     7,     0,    19,
      20,     8,     9,    10,    21,    22,    18,     0,     0,     0,
       0,    23,     0,     0,     0,    24,     0,    61,     0,     7,
       0,     0,     0,     8,     9,    10,    62,    63,    64,    65,
      66,     0,     0,    23,     0,     0,     0,    24
};

static const yytype_int8 yycheck[] =
{
      17,    44,     1,    53,    32,     7,     8,     9,    10,    11,
      12,    33,     0,    28,    42,    14,    35,    16,    17,    18,
      19,    20,    21,    22,    36,     1,    37,    28,    28,    28,
      39,    39,    35,    32,    84,    34,    42,    35,    14,    38,
      16,    17,    18,    19,    20,    21,    22,    32,    45,    35,
       1,    94,    28,    35,    38,    42,    32,    31,    34,    56,
      31,    15,    38,    14,    36,    16,    17,    18,    19,    20,
      21,    22,    26,    27,    28,    72,    40,    28,    95,     1,
      77,    32,    79,    39,    36,   102,    39,    38,     3,     4,
       5,     6,    14,   110,    16,    17,    18,    19,    20,    21,
      22,    39,     1,    28,    41,    39,    28,    37,    36,    23,
      32,    37,    39,     1,    38,    14,    38,    16,    17,    18,
      19,    20,    21,    22,    36,     3,    14,    37,    77,    28,
      18,    19,    20,    32,     1,    68,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,     1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    32,    -1,    15,    -1,    14,
      -1,    -1,    -1,    18,    19,    20,    24,    25,    26,    27,
      28,    -1,    -1,    28,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    44,    45,    46,     0,     1,    14,    18,    19,
      20,    33,    47,    48,    35,    28,    36,    37,     1,    16,
      17,    21,    22,    28,    32,    48,    49,    60,    39,    55,
      56,    53,    50,    62,    63,    64,    28,    28,    34,    49,
      70,    39,    35,    35,    35,    35,    42,     7,     8,     9,
      10,    11,    12,    68,    32,    61,    71,    38,    31,    31,
      60,    15,    24,    25,    26,    27,    28,    59,    69,    66,
      69,    66,    42,    65,    69,    36,    40,    39,    36,    68,
       3,     4,     5,     6,    67,    69,    39,    39,    41,    59,
      51,    69,    66,    28,    39,    37,    36,    60,    49,    39,
      36,    38,    37,    52,    49,    23,    57,    54,    58,    38,
      37,    49,    38
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "parser.y"
    { 
	(yyvsp[(2) - (8)].node_obj).nd = mkNode((yyvsp[(6) - (8)].node_obj).nd, (yyvsp[(7) - (8)].node_obj).nd, "main");
 	(yyval.node_obj).nd = mkNode((yyvsp[(1) - (8)].node_obj).nd, (yyvsp[(2) - (8)].node_obj).nd, "program"); 

	head = (yyval.node_obj).nd;
}
    break;

  case 3:
#line 102 "parser.y"
    { (yyval.node_obj).nd = mkNode((yyvsp[(1) - (2)].node_obj).nd, (yyvsp[(2) - (2)].node_obj).nd, "headers"); }
    break;

  case 4:
#line 103 "parser.y"
    { addSymbol('H'); }
    break;

  case 5:
#line 103 "parser.y"
    { (yyval.node_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (2)].node_obj).name); }
    break;

  case 6:
#line 107 "parser.y"
    { addSymbol('F'); }
    break;

  case 7:
#line 110 "parser.y"
    { setType(); }
    break;

  case 8:
#line 111 "parser.y"
    { setType(); }
    break;

  case 9:
#line 112 "parser.y"
    { setType(); }
    break;

  case 10:
#line 113 "parser.y"
    { setType(); }
    break;

  case 11:
#line 114 "parser.y"
    { yyerror("Expected a data type (int, float, etc.)"); }
    break;

  case 12:
#line 118 "parser.y"
    { addSymbol('K'); forLoopFlag = 0; }
    break;

  case 13:
#line 118 "parser.y"
    { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (5)].if_obj).if_body); }
    break;

  case 14:
#line 118 "parser.y"
    { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(4) - (9)].if_obj).else_body); }
    break;

  case 15:
#line 118 "parser.y"
    { 
	(yyval.node_obj).nd = mkNode(mkNode((yyvsp[(4) - (11)].if_obj).nd, (yyvsp[(8) - (11)].node_obj).nd, (yyvsp[(1) - (11)].node_obj).name), (yyvsp[(11) - (11)].node_obj).nd, "if-else"); 
	sprintf(icg[ic_idx++], "GOTO next\n");
}
    break;

  case 16:
#line 122 "parser.y"
    { addSymbol('K'); forLoopFlag = 1; currentScopeLevel++; }
    break;

  case 17:
#line 122 "parser.y"
    { currentScopeLevel--; clearLevel();}
    break;

  case 18:
#line 122 "parser.y"
    { 
	(yyval.node_obj).nd = mkNode(mkNode((yyvsp[(4) - (13)].node_obj).nd, mkNode((yyvsp[(6) - (13)].if_obj).nd, (yyvsp[(8) - (13)].node_obj).nd, "CONDITION"), "CONDITION"), (yyvsp[(11) - (13)].node_obj).nd, (yyvsp[(1) - (13)].node_obj).name); 
	sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[(6) - (13)].if_obj).if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[(6) - (13)].if_obj).else_body);
}
    break;

  case 19:
#line 127 "parser.y"
    { (yyval.node_obj).nd = mkNode((yyvsp[(1) - (2)].node_obj).nd, (yyvsp[(2) - (2)].node_obj).nd, "statements"); }
    break;

  case 20:
#line 128 "parser.y"
    { addSymbol('K'); }
    break;

  case 21:
#line 128 "parser.y"
    { (yyval.node_obj).nd = mkNode(NULL, NULL, "printf"); }
    break;

  case 22:
#line 129 "parser.y"
    { (yyval.node_obj).nd = (yyvsp[(1) - (2)].node_obj).nd; }
    break;

  case 23:
#line 130 "parser.y"
    { addSymbol('K'); }
    break;

  case 24:
#line 130 "parser.y"
    { (yyval.node_obj).nd = mkNode(NULL, NULL, "scanf"); }
    break;

  case 25:
#line 134 "parser.y"
    { addSymbol('K'); }
    break;

  case 26:
#line 134 "parser.y"
    { (yyval.node_obj).nd = mkNode(NULL, (yyvsp[(4) - (5)].node_obj).nd, (yyvsp[(1) - (5)].node_obj).name); }
    break;

  case 27:
#line 135 "parser.y"
    { (yyval.node_obj).nd = NULL; }
    break;

  case 28:
#line 138 "parser.y"
    { 
	(yyval.if_obj).nd = mkNode((yyvsp[(1) - (3)].exp_obj).nd, (yyvsp[(3) - (3)].exp_obj).nd, (yyvsp[(2) - (3)].node_obj).name); 
	if(forLoopFlag) {
		sprintf((yyval.if_obj).if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.if_obj).if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[(1) - (3)].exp_obj).name, (yyvsp[(2) - (3)].node_obj).name, (yyvsp[(3) - (3)].exp_obj).name, label);
		sprintf((yyval.if_obj).else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[(1) - (3)].exp_obj).name, (yyvsp[(2) - (3)].node_obj).name, (yyvsp[(3) - (3)].exp_obj).name, label, label+1);
		sprintf((yyval.if_obj).if_body, "L%d", label++);
		sprintf((yyval.if_obj).else_body, "L%d", label++);
	}
}
    break;

  case 29:
#line 151 "parser.y"
    { addSymbol('K'); (yyval.if_obj).nd = NULL; }
    break;

  case 30:
#line 152 "parser.y"
    { addSymbol('K'); (yyval.if_obj).nd = NULL; }
    break;

  case 31:
#line 153 "parser.y"
    { (yyval.if_obj).nd = NULL; }
    break;

  case 32:
#line 156 "parser.y"
    { addSymbol('V'); }
    break;

  case 33:
#line 156 "parser.y"
    { 
	(yyvsp[(2) - (4)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(2) - (4)].node_obj).name); 
	int t = compareDataTypes((yyvsp[(1) - (4)].node_obj).name, (yyvsp[(4) - (4)].exp_obj).type); 
	if(t>0) { 
		if(t == 1) {
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "floattoint"), "declaration"); 
		} 
		else if(t == 2) { 
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "inttofloat"), "declaration"); 
		} 
		else if(t == 3) { 
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "chartoint"), "declaration"); 
		} 
		else if(t == 4) { 
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "inttochar"), "declaration"); 
		} 
		else if(t == 5) { 
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "chartofloat"), "declaration"); 
		} 
		else{
			(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "floattochar"), "declaration"); 
		}
	} 
	else { 
		(yyval.node_obj).nd = mkNode((yyvsp[(2) - (4)].node_obj).nd, (yyvsp[(4) - (4)].exp_obj).nd, "declaration"); 
	} 
	sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[(2) - (4)].node_obj).name, (yyvsp[(4) - (4)].exp_obj).name);
}
    break;

  case 34:
#line 184 "parser.y"
    { validateDeclaration((yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 35:
#line 184 "parser.y"
    {
	(yyvsp[(1) - (4)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (4)].node_obj).name); 
	char *id_type = retrieveDataType((yyvsp[(1) - (4)].node_obj).name); 
	if(strcmp(id_type, (yyvsp[(4) - (4)].exp_obj).type)) {
		if(!strcmp(id_type, "int")) {
			if(!strcmp((yyvsp[(4) - (4)].exp_obj).type, "float")){
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "floattoint"), "="); 
			}
			else{
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "chartoint"), "="); 
			}
			
		}
		else if(!strcmp(id_type, "float")) {
			if(!strcmp((yyvsp[(4) - (4)].exp_obj).type, "int")){
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "inttofloat"), "="); 
			}
			else{
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "chartofloat"), "="); 
			}
			
		}
		else{
			if(!strcmp((yyvsp[(4) - (4)].exp_obj).type, "int")){
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd,  mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "inttochar"), "="); 
			}
			else{
				(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, mkNode(NULL, (yyvsp[(4) - (4)].exp_obj).nd, "floattochar"), "="); 
			}
		}
	}
	else {
		(yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, (yyvsp[(4) - (4)].exp_obj).nd, "="); 
	}
	sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[(1) - (4)].node_obj).name, (yyvsp[(4) - (4)].exp_obj).name);
}
    break;

  case 36:
#line 220 "parser.y"
    { validateDeclaration((yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 37:
#line 220 "parser.y"
    { (yyvsp[(1) - (4)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (4)].node_obj).name); (yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, (yyvsp[(4) - (4)].exp_obj).nd, (yyvsp[(3) - (4)].node_obj).name); }
    break;

  case 38:
#line 221 "parser.y"
    { validateDeclaration((yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 39:
#line 221 "parser.y"
    { 
	(yyvsp[(1) - (3)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (3)].node_obj).name); 
	(yyvsp[(3) - (3)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(3) - (3)].node_obj).name); 
	(yyval.node_obj).nd = mkNode((yyvsp[(1) - (3)].node_obj).nd, (yyvsp[(3) - (3)].node_obj).nd, "ITERATOR");  
	if(!strcmp((yyvsp[(3) - (3)].node_obj).name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (3)].node_obj).name, (yyvsp[(1) - (3)].node_obj).name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(1) - (3)].node_obj).name, (yyvsp[(1) - (3)].node_obj).name, temp_var++);
	}
}
    break;

  case 40:
#line 232 "parser.y"
    { 
	validateDeclaration((yyvsp[(2) - (2)].node_obj).name); 
	(yyvsp[(1) - (2)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (2)].node_obj).name); 
	(yyvsp[(2) - (2)].node_obj).nd = mkNode(NULL, NULL, (yyvsp[(2) - (2)].node_obj).name); 
	(yyval.node_obj).nd = mkNode((yyvsp[(1) - (2)].node_obj).nd, (yyvsp[(2) - (2)].node_obj).nd, "ITERATOR"); 
	if(!strcmp((yyvsp[(1) - (2)].node_obj).name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].node_obj).name, (yyvsp[(2) - (2)].node_obj).name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[(2) - (2)].node_obj).name, (yyvsp[(2) - (2)].node_obj).name, temp_var++);

	}
}
    break;

  case 41:
#line 245 "parser.y"
    { yyerror("Expected an expression before ';'."); }
    break;

  case 42:
#line 248 "parser.y"
    { (yyval.exp_obj).nd = (yyvsp[(2) - (2)].exp_obj).nd; sprintf((yyval.exp_obj).type, (yyvsp[(2) - (2)].exp_obj).type); strcpy((yyval.exp_obj).name, (yyvsp[(2) - (2)].exp_obj).name); }
    break;

  case 43:
#line 249 "parser.y"
    { sprintf((yyval.exp_obj).type, "null"); 
(yyval.exp_obj).nd = mkNode(NULL, NULL, "NULL"); 
strcpy((yyval.exp_obj).name, "NULL"); 
}
    break;

  case 44:
#line 255 "parser.y"
    { 
	if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, (yyvsp[(3) - (3)].exp_obj).type)) {
		sprintf((yyval.exp_obj).type, (yyvsp[(1) - (3)].exp_obj).type);
		(yyval.exp_obj).nd = mkNode((yyvsp[(1) - (3)].exp_obj).nd, (yyvsp[(3) - (3)].exp_obj).nd, (yyvsp[(2) - (3)].node_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, "int") && !strcmp((yyvsp[(3) - (3)].exp_obj).type, "float")) {
			struct Node *temp = mkNode(NULL, (yyvsp[(1) - (3)].exp_obj).nd, "inttofloat");
			sprintf((yyval.exp_obj).type, (yyvsp[(3) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode(temp, (yyvsp[(3) - (3)].exp_obj).nd, (yyvsp[(2) - (3)].node_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, "float") && !strcmp((yyvsp[(3) - (3)].exp_obj).type, "int")) {
			struct Node *temp = mkNode(NULL, (yyvsp[(3) - (3)].exp_obj).nd, "inttofloat");
			sprintf((yyval.exp_obj).type, (yyvsp[(1) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode((yyvsp[(1) - (3)].exp_obj).nd, temp, (yyvsp[(2) - (3)].node_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, "int") && !strcmp((yyvsp[(3) - (3)].exp_obj).type, "char")) {
			struct Node *temp = mkNode(NULL, (yyvsp[(3) - (3)].exp_obj).nd, "chartoint");
			sprintf((yyval.exp_obj).type, (yyvsp[(1) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode((yyvsp[(1) - (3)].exp_obj).nd, temp, (yyvsp[(2) - (3)].node_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, "char") && !strcmp((yyvsp[(3) - (3)].exp_obj).type, "int")) {
			struct Node *temp = mkNode(NULL, (yyvsp[(1) - (3)].exp_obj).nd, "chartoint");
			sprintf((yyval.exp_obj).type, (yyvsp[(3) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode(temp, (yyvsp[(3) - (3)].exp_obj).nd, (yyvsp[(2) - (3)].node_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].exp_obj).type, "float") && !strcmp((yyvsp[(3) - (3)].exp_obj).type, "char")) {
			struct Node *temp = mkNode(NULL, (yyvsp[(3) - (3)].exp_obj).nd, "chartofloat");
			sprintf((yyval.exp_obj).type, (yyvsp[(1) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode((yyvsp[(1) - (3)].exp_obj).nd, temp, (yyvsp[(2) - (3)].node_obj).name);
		}
		else {
			struct Node *temp = mkNode(NULL, (yyvsp[(1) - (3)].exp_obj).nd, "chartofloat");
			sprintf((yyval.exp_obj).type, (yyvsp[(3) - (3)].exp_obj).type);
			(yyval.exp_obj).nd = mkNode(temp, (yyvsp[(3) - (3)].exp_obj).nd, (yyvsp[(2) - (3)].node_obj).name);
		}
	}
	sprintf((yyval.exp_obj).name, "t%d", temp_var);
	temp_var++;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.exp_obj).name, (yyvsp[(1) - (3)].exp_obj).name, (yyvsp[(2) - (3)].node_obj).name, (yyvsp[(3) - (3)].exp_obj).name);
}
    break;

  case 45:
#line 296 "parser.y"
    { strcpy((yyval.exp_obj).name, (yyvsp[(1) - (1)].exp_obj).name); sprintf((yyval.exp_obj).type, (yyvsp[(1) - (1)].exp_obj).type); (yyval.exp_obj).nd = (yyvsp[(1) - (1)].exp_obj).nd; }
    break;

  case 56:
#line 313 "parser.y"
    { strcpy((yyval.exp_obj).name, (yyvsp[(1) - (1)].node_obj).name); sprintf((yyval.exp_obj).type, "int"); addSymbol('C'); (yyval.exp_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 57:
#line 314 "parser.y"
    { strcpy((yyval.exp_obj).name, (yyvsp[(1) - (1)].node_obj).name); sprintf((yyval.exp_obj).type, "float"); addSymbol('C'); (yyval.exp_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 58:
#line 315 "parser.y"
    { strcpy((yyval.exp_obj).name, (yyvsp[(1) - (1)].node_obj).name); sprintf((yyval.exp_obj).type, "char"); addSymbol('C'); (yyval.exp_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 59:
#line 316 "parser.y"
    { strcpy((yyval.exp_obj).name, (yyvsp[(1) - (1)].node_obj).name); char *id_type = retrieveDataType((yyvsp[(1) - (1)].node_obj).name); sprintf((yyval.exp_obj).type, id_type); validateDeclaration((yyvsp[(1) - (1)].node_obj).name); (yyval.exp_obj).nd = mkNode(NULL, NULL, (yyvsp[(1) - (1)].node_obj).name); }
    break;

  case 60:
#line 319 "parser.y"
    { addSymbol('K'); }
    break;

  case 61:
#line 319 "parser.y"
    { verifyReturnType((yyvsp[(3) - (4)].exp_obj).name); (yyvsp[(1) - (4)].node_obj).nd = mkNode(NULL, NULL, "return"); (yyval.node_obj).nd = mkNode((yyvsp[(1) - (4)].node_obj).nd, (yyvsp[(3) - (4)].exp_obj).nd, "RETURN"); }
    break;

  case 62:
#line 320 "parser.y"
    { (yyval.node_obj).nd = NULL; }
    break;


/* Line 1267 of yacc.c.  */
#line 1971 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 323 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, column %d\n", s, countn + 1, countc + 1);
}

int main() {
    yyparse();
	printf("Lex analysis \n\n");
	int i=0;
	for(i=0; i<symbolCount; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<symbolCount;i++) {
		if(!strcmp(symbol_table[i].id_name, "")) free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("Syntax analysis");
	displaySyntaxTree(head); 
	printf("Semantic analysis");
	if(semanticErrors>0) {
		printf("Semantic analysis completed with %d errors", semanticErrors);
		for(int i=0; i<semanticErrors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed successfully");
	}
}

int findSymbol(char *name) {
    for (int i = symbolCount - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, name) == 0 && symbol_table[i].scope_level <= currentScopeLevel) {
            return -1; 
        }
    }
    return 0; 
}

void clearLevel() {
    for (int i = symbolCount - 1; i >= 0; i--) {
        if (symbol_table[i].scope_level > currentScopeLevel) {
			strcpy(symbol_table[i].id_name, "");
        }
    }
}



void validateDeclaration(char *c) {
    q = findSymbol(c);
    if(!q) {
        sprintf(errors[semanticErrors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		semanticErrors++;
    }
}

void verifyReturnType(char *value) {
    char *main_datatype = retrieveDataType("main");
    char *return_datatype = retrieveDataType(value);
    if ((strcmp(main_datatype, "int") == 0 && strcmp(return_datatype, "CONST") == 0) || strcmp(main_datatype, return_datatype) == 0) {
        return;
    } else {
        sprintf(errors[semanticErrors], "Line %d: Return type mismatch\n", countn + 1);
        semanticErrors++;
    }
}


int compareDataTypes(char *type1, char *type2){
	if(!strcmp(type2, "null"))return -1;
	if(!strcmp(type1, type2))return 0;
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))return 6;
}

char *retrieveDataType(char *var){
	for(int i=0; i<symbolCount; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void addSymbolToTable(char *name, char *dataType, char *symbolType, int lineNumber, int scopeLevel) {
    symbol_table[symbolCount].id_name = strdup(name);
    symbol_table[symbolCount].data_type = strdup(dataType);
    symbol_table[symbolCount].line_no = lineNumber;
    symbol_table[symbolCount].type = strdup(symbolType);
    symbol_table[symbolCount].scope_level = scopeLevel;
    symbolCount++;
}



void addSymbol(char c) {
    if (c == 'V') {
        for (int i = 0; i < 10; i++) {
            if (!strcmp(reserved[i], yytext)) {
                sprintf(errors[semanticErrors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn + 1, yytext);
                semanticErrors++;
                return;
            }
        }
    }

    q = findSymbol(yytext);
    if (!q) {
        char *dataType = (c == 'K') ? "N/A" : ((c == 'C') ? "CONST" : type);
        char *symbolType = (c == 'H') ? "Header" : 
                           (c == 'K') ? "Keyword\t" : 
                           (c == 'V') ? "Variable" : 
                           (c == 'C') ? "Constant" : 
                           (c == 'F') ? "Function" : "Unknown";

        addSymbolToTable(yytext, dataType, symbolType, countn, currentScopeLevel);
    } else if (c == 'V') {
        sprintf(errors[semanticErrors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn + 1, yytext);
        semanticErrors++;
    }
}


struct Node* mkNode(struct Node *left, struct Node *right, char *token) {	
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newNode->left = left;
	newNode->right = right;
	newNode->token = newstr;
	return(newNode);
}

void displaySyntaxTree(struct Node* tree) {
	// displaySyntaxTree_util(tree, 0);
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	FILE* file = fopen("tree.json", "w");
	writeJSON(tree, file);
}

void writeJSON(struct Node* root, FILE* file) {
	//printf("Hehhh");
    if (root == NULL) return;

    fprintf(file, "{\"name\": \"%s\"", root->token);
    if (root->left || root->right) {
        fprintf(file, ", \"children\": [");
        if (root->left) {
            writeJSON(root->left, file);
            if (root->right) fprintf(file, ", ");
        }
        if (root->right) {
            writeJSON(root->right, file);
        }
        fprintf(file, "]");
    }
    fprintf(file, "}");
}

void setType() {
	strcpy(type, yytext);
}

