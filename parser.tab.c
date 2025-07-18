
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include "ast.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern void yyerror(const char *s);
extern FILE *yyin;
extern char *yytext;
extern int yylineno;

ASTNode *root;
int syntax_error = 0;



/* Line 189 of yacc.c  */
#line 92 "parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUERY = 258,
     RESULT_OF_QUERY = 259,
     EXEC = 260,
     IF = 261,
     FOR = 262,
     IN = 263,
     EMPTY = 264,
     URL_EXISTS = 265,
     NOT_EMPTY = 266,
     BEGIN_KW = 267,
     END_KW = 268,
     SET_UNION = 269,
     SET_DIFFERENCE = 270,
     SET_INTERSECTION = 271,
     POW = 272,
     PLUS = 273,
     MINUS = 274,
     MULT = 275,
     OR = 276,
     LT = 277,
     GT = 278,
     LBRACKET = 279,
     RBRACKET = 280,
     LPAREN = 281,
     RPAREN = 282,
     COMMA = 283,
     SEMICOLON = 284,
     COLON = 285,
     EQUALS = 286,
     MINUS_EQ = 287,
     ID = 288,
     STRING = 289,
     UMINUS = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "parser.y"

    char *str;
    struct ASTNode *ast;



/* Line 214 of yacc.c  */
#line 170 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 182 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNRULES -- Number of states.  */
#define YYNSTATES  99

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    17,    23,    27,    29,
      32,    36,    42,    50,    53,    58,    63,    69,    75,    81,
      86,    93,    98,   102,   104,   106,   110,   113,   115,   117,
     121,   125,   127,   130,   134,   138,   142,   146,   148,   150,
     153,   156,   160
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    40,    -1,    39,    -1,    38,    39,
      -1,     3,    33,    31,    45,    29,    -1,     3,    33,    31,
      44,    29,    -1,     4,    33,    29,    -1,    41,    -1,    40,
      41,    -1,     5,    33,    29,    -1,     6,    43,    12,    40,
      13,    -1,     7,    33,     8,    44,    12,    40,    13,    -1,
      42,    29,    -1,    33,    32,     5,    33,    -1,    33,    31,
       5,    33,    -1,    33,    31,    33,    14,    33,    -1,    33,
      31,    33,    15,    33,    -1,    33,    31,    33,    16,    33,
      -1,     9,    26,    33,    27,    -1,    10,    26,    33,    28,
      34,    27,    -1,    11,    26,    33,    27,    -1,    24,    46,
      25,    -1,    45,    -1,    33,    -1,    22,    47,    23,    -1,
      22,    23,    -1,    45,    -1,    33,    -1,    46,    28,    45,
      -1,    46,    28,    33,    -1,    48,    -1,    47,    48,    -1,
      47,    21,    48,    -1,    47,    18,    48,    -1,    47,    19,
      48,    -1,    47,    17,    48,    -1,    33,    -1,    49,    -1,
      18,    48,    -1,    19,    48,    -1,    26,    47,    27,    -1,
      33,    30,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    53,    57,    66,    70,    74,    79,    83,
      92,    96,   100,   104,   108,   112,   116,   120,   124,   129,
     133,   137,   142,   145,   149,   154,   158,   163,   167,   171,
     179,   188,   192,   196,   200,   204,   208,   213,   217,   220,
     224,   228,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUERY", "RESULT_OF_QUERY", "EXEC", "IF",
  "FOR", "IN", "EMPTY", "URL_EXISTS", "NOT_EMPTY", "BEGIN_KW", "END_KW",
  "SET_UNION", "SET_DIFFERENCE", "SET_INTERSECTION", "POW", "PLUS",
  "MINUS", "MULT", "OR", "LT", "GT", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "COMMA", "SEMICOLON", "COLON", "EQUALS", "MINUS_EQ", "ID",
  "STRING", "UMINUS", "$accept", "program", "declarations", "declaration",
  "commands", "command", "assign_command", "condition", "list_of_queries",
  "query", "query_list", "terms", "term", "directive", 0
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
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      41,    41,    41,    41,    42,    42,    42,    42,    42,    43,
      43,    43,    44,    44,    44,    45,    45,    46,    46,    46,
      46,    47,    47,    47,    47,    47,    47,    48,    48,    48,
      48,    48,    49
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     5,     5,     3,     1,     2,
       3,     5,     7,     2,     4,     4,     5,     5,     5,     4,
       6,     4,     3,     1,     1,     3,     2,     1,     1,     3,
       3,     1,     2,     3,     3,     3,     3,     1,     1,     2,
       2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     0,     0,     1,     0,
       0,     0,     0,     4,     2,     8,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    13,     0,
       0,    24,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    37,     0,    31,
      38,    28,    27,     0,     6,     5,     0,     0,     0,     0,
       0,    23,    15,     0,     0,     0,    14,    39,    40,     0,
       0,     0,     0,     0,     0,    25,    32,    22,     0,    19,
       0,    21,    11,     0,    16,    17,    18,    41,    42,    36,
      34,    35,    33,    30,    29,     0,     0,    20,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    14,    15,    16,    23,    32,    33,
      53,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int8 yypact[] =
{
      36,   -28,   -10,    42,     8,   -41,    12,    26,   -41,    25,
      27,    34,    57,   -41,    20,   -41,    39,    41,   -41,    46,
      45,    55,    64,    79,    84,     2,    89,   -41,   -41,    54,
      -3,   -41,    66,    67,   -41,    65,    68,    70,    20,    41,
      71,    69,    72,    60,    60,   -41,    60,    76,    33,   -41,
     -41,   -41,   -41,   -19,   -41,   -41,    73,    74,    80,    11,
      85,   -41,   -41,    75,    77,    78,   -41,   -41,   -41,    43,
      81,    60,    60,    60,    60,   -41,   -41,   -41,    24,   -41,
      82,   -41,   -41,    20,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,    86,    15,   -41,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,    95,   -36,   -14,   -41,   -41,    83,   -29,
     -41,    63,   -40,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    52,    59,    67,    68,     6,    77,    40,    76,    78,
      61,     1,     2,     9,    10,    11,     9,    10,    11,    29,
       9,    10,    11,     7,    82,     9,    10,    11,    98,    76,
      51,    89,    90,    91,    92,    41,    20,    21,    22,     1,
       2,    12,     8,    17,    12,    27,    29,    96,    12,    94,
      71,    72,    73,    12,    74,    18,    75,    93,    19,    46,
      71,    72,    73,    29,    74,    30,    47,    24,    28,    46,
      87,    35,    43,    44,    31,    34,    47,    45,    43,    44,
      46,    36,    27,    63,    64,    65,    46,    47,    25,    26,
      37,    38,    39,    47,    42,    54,    55,    83,    56,    13,
      79,    57,    80,    58,    62,    66,    70,    81,    84,    69,
      85,    86,     0,    97,    88,     0,    95,     0,     0,     0,
       0,     0,    60
};

static const yytype_int8 yycheck[] =
{
      14,    30,    38,    43,    44,    33,    25,     5,    48,    28,
      39,     3,     4,     5,     6,     7,     5,     6,     7,    22,
       5,     6,     7,    33,    13,     5,     6,     7,    13,    69,
      33,    71,    72,    73,    74,    33,     9,    10,    11,     3,
       4,    33,     0,    31,    33,    59,    22,    83,    33,    78,
      17,    18,    19,    33,    21,    29,    23,    33,    33,    26,
      17,    18,    19,    22,    21,    24,    33,    33,    29,    26,
      27,    26,    18,    19,    33,    29,    33,    23,    18,    19,
      26,    26,    96,    14,    15,    16,    26,    33,    31,    32,
      26,    12,     8,    33,     5,    29,    29,    12,    33,     4,
      27,    33,    28,    33,    33,    33,    30,    27,    33,    46,
      33,    33,    -1,    27,    33,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    37,    38,    39,    33,    33,     0,     5,
       6,     7,    33,    39,    40,    41,    42,    31,    29,    33,
       9,    10,    11,    43,    33,    31,    32,    41,    29,    22,
      24,    33,    44,    45,    29,    26,    26,    26,    12,     8,
       5,    33,     5,    18,    19,    23,    26,    33,    47,    48,
      49,    33,    45,    46,    29,    29,    33,    33,    33,    40,
      44,    45,    33,    14,    15,    16,    33,    48,    48,    47,
      30,    17,    18,    19,    21,    23,    48,    25,    28,    27,
      28,    27,    13,    12,    33,    33,    33,    27,    33,    48,
      48,    48,    48,    33,    45,    34,    40,    27,    13
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 46 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createProgramNode((yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), loc);
    root = (yyval.ast);
    printf("\nParsiranje uspjesno!\n");
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createDeclarationsNode((yyvsp[(1) - (1)].ast), NULL, loc);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    {
    ASTNode *tail = (yyvsp[(1) - (2)].ast);
    while (tail->declarations.more_decls != NULL)
        tail = tail->declarations.more_decls;
    SourceLocation loc = {yylineno, 0};
    tail->declarations.more_decls = createDeclarationsNode((yyvsp[(2) - (2)].ast), NULL, loc);
    (yyval.ast) = (yyvsp[(1) - (2)].ast);
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryDeclarationNode((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].ast), loc);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryListDeclarationNode((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].ast), loc);
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createResultOfQueryNode((yyvsp[(2) - (3)].str), loc);
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createCommandsNode((yyvsp[(1) - (1)].ast), NULL, loc);
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {
    ASTNode *tail = (yyvsp[(1) - (2)].ast);
    while (tail->commands.more_cmds != NULL)
        tail = tail->commands.more_cmds;
    SourceLocation loc = {yylineno, 0};
    tail->commands.more_cmds = createCommandsNode((yyvsp[(2) - (2)].ast), NULL, loc);
    (yyval.ast) = (yyvsp[(1) - (2)].ast);
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createExecCommandNode((yyvsp[(2) - (3)].str), loc);
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createIfCommandNode((yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast), loc);
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createForCommandNode((yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].ast), (yyvsp[(6) - (7)].ast), loc);
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {
    (yyval.ast) = (yyvsp[(1) - (2)].ast);
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createAssignCommandNode((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].str), loc);
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createAssignCommandNode((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].str), loc);
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createSetOperationNode((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str), SET_UNION_OP, (yyvsp[(1) - (5)].str), loc);
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createSetOperationNode((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str), SET_DIFFERENCE_OP, (yyvsp[(1) - (5)].str), loc);
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createSetOperationNode((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str), SET_INTERSECTION_OP, (yyvsp[(1) - (5)].str), loc);
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createEmptyConditionNode((yyvsp[(3) - (4)].str), loc);
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createUrlExistsConditionNode((yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str), loc);
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createNotEmptyConditionNode((yyvsp[(3) - (4)].str), loc);
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {
    (yyval.ast) = (yyvsp[(2) - (3)].ast);
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryListNode((yyvsp[(1) - (1)].ast), NULL, loc);
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryListNode(createIDReferenceQueryNode((yyvsp[(1) - (1)].str), loc), NULL, loc);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryNode((yyvsp[(2) - (3)].ast), loc);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {  
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryNode(NULL, loc);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryListNode((yyvsp[(1) - (1)].ast), NULL, loc);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createQueryListNode(createIDReferenceQueryNode((yyvsp[(1) - (1)].str), loc), NULL, loc);
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {
    ASTNode *tail = (yyvsp[(1) - (3)].ast);
    while (tail->query_list.more_queries != NULL)
        tail = tail->query_list.more_queries;
    SourceLocation loc = {yylineno, 0};
    tail->query_list.more_queries = createQueryListNode((yyvsp[(3) - (3)].ast), NULL, loc);
    (yyval.ast) = (yyvsp[(1) - (3)].ast);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
    ASTNode *tail = (yyvsp[(1) - (3)].ast);
    while (tail->query_list.more_queries != NULL)
        tail = tail->query_list.more_queries;
    SourceLocation loc = {yylineno, 0};
    tail->query_list.more_queries = createQueryListNode(createIDReferenceQueryNode((yyvsp[(3) - (3)].str), loc), NULL, loc);
    (yyval.ast) = (yyvsp[(1) - (3)].ast);
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createTermsNode((yyvsp[(1) - (1)].ast), NULL, loc);
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createBinaryOpNode(JUXTAPOSITION_OP, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), loc);
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createBinaryOpNode(OR_OP, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), loc);
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createBinaryOpNode(PLUS_OP, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), loc);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createBinaryOpNode(MINUS_OP, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), loc);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createBinaryOpNode(POW_OP, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), loc);
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createTermNode((yyvsp[(1) - (1)].str), NULL, NULL, loc);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {
    (yyval.ast) = (yyvsp[(1) - (1)].ast);
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createUnaryOpNode(PLUS_OP, (yyvsp[(2) - (2)].ast), loc);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createUnaryOpNode(MINUS_OP, (yyvsp[(2) - (2)].ast), loc);
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {
    (yyval.ast) = (yyvsp[(2) - (3)].ast);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {
    SourceLocation loc = {yylineno, 0};
    (yyval.ast) = createDirectiveNode((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), loc);
;}
    break;



/* Line 1455 of yacc.c  */
#line 1881 "parser.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 237 "parser.y"


void yyerror(const char *s) {
    report_syntax_error(s, yylineno, 0);
    syntax_error = 1;
}
