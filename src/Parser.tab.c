/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "Parser.y"

	#include <cstdio>
	#include <cstdlib>
	#include <iostream>
	#include <unistd.h>
	#include "DBFileManager.h"
	#include "DBBufManager.h"
	#include "IndexManager.h"
	#include "DBFile.h"
	#include "SemValue.h"
	#include "OrderPack.h"
	#define YYSTYPE SemValue
	void yyerror(const char*);
	void prompt();
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
	using namespace std;

	DBFileManager* myfilemanager = NULL;
	DBBufManager *mybufmanager = NULL;
	IndexManager *indexManager = NULL;


/* Line 268 of yacc.c  */
#line 96 "Parser.tab.c"

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
     INTEGER = 258,
     IDENTIFIER = 259,
     LITERAL = 260,
     ENDLINE = 261,
     QUIT = 262,
     CREATE = 263,
     DB = 264,
     DBS = 265,
     DROP = 266,
     USE = 267,
     SHOW = 268,
     TB = 269,
     TBS = 270,
     INDEX = 271,
     DESC = 272,
     NOT = 273,
     IS = 274,
     NUL = 275,
     IN = 276,
     PRIMARY = 277,
     FOREIGN = 278,
     KEY = 279,
     CHECK = 280,
     REFER = 281,
     INS_INTO = 282,
     VALUES = 283,
     DELETE = 284,
     WHERE = 285,
     UPDATE = 286,
     SET = 287,
     SELECT = 288,
     FROM = 289,
     LIKE = 290,
     AND = 291,
     OR = 292,
     SUM = 293,
     AVG = 294,
     MAX = 295,
     MIN = 296,
     GRP_BY = 297,
     INT = 298,
     CHAR = 299,
     VCHAR = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 183 "Parser.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,    48,    46,    54,    47,    57,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      56,    53,    55,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    12,    18,    24,    29,
      34,    39,    48,    54,    59,    68,    75,    84,    94,   103,
     112,   115,   116,   119,   120,   123,   127,   129,   135,   143,
     149,   154,   165,   167,   169,   171,   175,   177,   179,   181,
     183,   187,   191,   193,   197,   201,   205,   209,   213,   219,
     221,   223,   225,   227,   231,   233,   235,   240,   245,   250,
     255,   257,   261,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    59,    60,    -1,    -1,     6,    -1,     7,
       6,    -1,     8,     9,     4,    50,     6,    -1,    11,     9,
       4,    50,     6,    -1,    12,     4,    50,     6,    -1,    13,
      10,    50,     6,    -1,    13,    15,    50,     6,    -1,     8,
      14,     4,    51,    63,    52,    50,     6,    -1,    11,    14,
       4,    50,     6,    -1,    17,     4,    50,     6,    -1,    27,
       4,    28,    51,    66,    52,    50,     6,    -1,    29,    34,
       4,    61,    50,     6,    -1,    33,    71,    34,    74,    61,
      62,    50,     6,    -1,    31,     4,    32,     4,    53,    67,
      61,    50,     6,    -1,     8,    16,     4,    51,     4,    52,
      50,     6,    -1,    11,    16,     4,    51,     4,    52,    50,
       6,    -1,     1,     6,    -1,    -1,    30,    68,    -1,    -1,
      42,    73,    -1,    63,    54,    64,    -1,    64,    -1,     4,
      65,    51,     3,    52,    -1,     4,    65,    51,     3,    52,
      18,    20,    -1,    22,    24,    51,     4,    52,    -1,    25,
      51,    68,    52,    -1,    23,    24,    51,     4,    52,    26,
       4,    51,     4,    52,    -1,    43,    -1,    44,    -1,    45,
      -1,    66,    54,    67,    -1,    67,    -1,     3,    -1,     5,
      -1,    20,    -1,    68,    36,    69,    -1,    68,    37,    69,
      -1,    69,    -1,    70,    53,    70,    -1,    70,    55,    70,
      -1,    70,    56,    70,    -1,    73,    19,    20,    -1,    73,
      35,     5,    -1,    73,    21,    51,    66,    52,    -1,    73,
      -1,     3,    -1,     5,    -1,    48,    -1,    71,    54,    72,
      -1,    72,    -1,    73,    -1,    38,    51,    73,    52,    -1,
      39,    51,    73,    52,    -1,    40,    51,    73,    52,    -1,
      41,    51,    73,    52,    -1,     4,    -1,     4,    57,     4,
      -1,    74,    54,     4,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    41,    44,    48,    56,    65,    74,    83,
      90,    97,   109,   118,   127,   139,   150,   169,   188,   199,
     210,   219,   222,   230,   233,   240,   244,   252,   257,   262,
     267,   272,   280,   281,   282,   286,   290,   298,   299,   300,
     304,   308,   312,   319,   323,   327,   331,   338,   346,   357,
     362,   367,   375,   379,   384,   392,   397,   402,   407,   412,
     418,   422,   429,   433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "IDENTIFIER", "LITERAL",
  "ENDLINE", "QUIT", "CREATE", "DB", "DBS", "DROP", "USE", "SHOW", "TB",
  "TBS", "INDEX", "DESC", "NOT", "IS", "NUL", "IN", "PRIMARY", "FOREIGN",
  "KEY", "CHECK", "REFER", "INS_INTO", "VALUES", "DELETE", "WHERE",
  "UPDATE", "SET", "SELECT", "FROM", "LIKE", "AND", "OR", "SUM", "AVG",
  "MAX", "MIN", "GRP_BY", "INT", "CHAR", "VCHAR", "'+'", "'-'", "'*'",
  "'/'", "';'", "'('", "')'", "'='", "','", "'>'", "'<'", "'.'", "$accept",
  "Program", "Stmt", "WhereClause", "GroupClause", "AttrDefList",
  "AttrDefItem", "Type", "ValueList", "ValueItem", "CondList", "Cond",
  "Expr", "AttrList", "AttrAggr", "Attr", "TableList", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,    45,    42,    47,
      59,    40,    41,    61,    44,    62,    60,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     5,     5,     4,     4,
       4,     8,     5,     4,     8,     6,     8,     9,     8,     8,
       2,     0,     2,     0,     2,     3,     1,     5,     7,     5,
       4,    10,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     5,     1,
       1,     1,     1,     3,     1,     1,     4,     4,     4,     4,
       1,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    20,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,    52,     0,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    13,
       0,     0,     0,     0,    61,     0,     0,     0,     0,    63,
      21,    53,     6,     0,     0,     0,     0,     0,    26,     0,
       7,    12,     0,    37,    38,    39,     0,    36,    50,    51,
      22,    42,     0,    49,     0,     0,    56,    57,    58,    59,
       0,    23,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    21,    62,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,    35,    40,    41,
      43,    49,    44,    45,    46,     0,    47,     0,    24,     0,
       0,     0,     0,    30,    11,    18,    19,    14,     0,     0,
      16,    27,    29,     0,    48,    17,     0,     0,    28,     0,
       0,     0,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    72,   137,    87,    88,   115,    96,    97,
     100,   101,   102,    37,    38,   103,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
    -101,    51,  -101,    29,  -101,    47,     1,    56,     4,    -3,
      65,    67,    43,    72,    -2,  -101,  -101,  -101,    75,    77,
      79,    87,    88,    89,    44,    45,    46,    48,    69,    95,
      68,    49,    50,    52,    53,    54,  -101,   -28,  -101,  -101,
      57,    58,    59,    61,    62,    66,    96,   102,   110,   112,
      73,    90,   115,   117,   119,   119,   119,   119,   121,     9,
     120,     0,   123,   122,   124,   125,  -101,  -101,  -101,  -101,
      11,    70,    81,    80,  -101,    82,    83,    84,    85,  -101,
     -27,  -101,  -101,    42,   108,   114,    91,   -43,  -101,    92,
    -101,  -101,    93,  -101,  -101,  -101,   -33,  -101,  -101,  -101,
      24,  -101,   -23,    -1,   133,    11,  -101,  -101,  -101,  -101,
     136,    99,  -101,  -101,  -101,    97,    98,   100,    70,   103,
       0,   104,   105,   106,    11,    70,    70,    70,    70,    70,
     126,   101,   138,  -101,    90,  -101,   119,   107,   144,   146,
     154,    -8,   153,  -101,   155,   156,   157,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    11,  -101,   116,  -101,   158,
     113,   118,   127,  -101,  -101,  -101,  -101,  -101,     2,   161,
    -101,   142,  -101,   143,  -101,  -101,   148,   167,  -101,   129,
     168,   130,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   -79,  -101,  -101,    55,  -101,    18,  -100,
      60,   -59,   -39,  -101,   128,   -14,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,   111,    31,    71,    83,   134,    58,    25,    24,   119,
      18,   120,    26,    31,    93,    19,    94,    20,   130,   123,
     131,   124,    84,    85,   147,    86,    59,   110,   125,   126,
     127,    95,   128,   129,   132,    16,    32,    33,    34,    35,
      75,    76,    77,    78,   163,    39,    36,    32,    33,    34,
      35,     2,     3,    17,   174,   157,   124,     4,     5,     6,
     125,   126,     7,     8,     9,    21,   148,   149,    10,    27,
      22,    28,    23,    98,    31,    99,    30,    29,    11,    40,
      12,    41,    13,    42,    14,   112,   113,   114,   150,   152,
     153,    43,    44,    45,    46,    47,    48,    50,    49,    51,
      52,    54,    66,    55,    56,    57,    53,    60,    67,    61,
      62,    63,    64,   151,   151,   151,    68,    65,    69,    73,
      71,    74,   158,    31,    70,    79,    82,    89,    90,    92,
      91,   104,   116,   105,   106,   107,   108,   109,   117,   133,
     135,   136,   118,   156,   121,   122,   154,   160,   138,   139,
     161,   140,   155,   142,   144,   145,   146,   159,   162,   164,
     176,   165,   166,   167,   170,   171,   169,   175,   178,   177,
     172,   179,   181,   168,     0,   143,     0,     0,   141,   173,
     180,     0,   182,     0,     0,     0,     0,    81
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-101))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      14,    80,     4,    30,     4,   105,    34,    10,     4,    52,
       9,    54,    15,     4,     3,    14,     5,    16,    19,    52,
      21,    54,    22,    23,   124,    25,    54,    54,    36,    37,
      53,    20,    55,    56,    35,     6,    38,    39,    40,    41,
      54,    55,    56,    57,    52,    59,    48,    38,    39,    40,
      41,     0,     1,     6,    52,   134,    54,     6,     7,     8,
      36,    37,    11,    12,    13,     9,   125,   126,    17,     4,
      14,     4,    16,     3,     4,     5,     4,    34,    27,     4,
      29,     4,    31,     4,    33,    43,    44,    45,   127,   128,
     129,     4,     4,     4,    50,    50,    50,    28,    50,     4,
      32,    51,     6,    51,    51,    51,    57,    50,     6,    51,
      51,    50,    50,   127,   128,   129,     6,    51,     6,     4,
      30,     4,   136,     4,    51,     4,     6,     4,     6,     4,
       6,    50,    24,    53,    52,    52,    52,    52,    24,     6,
       4,    42,    51,     5,    52,    52,    20,     3,    51,    51,
       4,    51,    51,    50,    50,    50,    50,    50,     4,     6,
      18,     6,     6,     6,     6,    52,    50,     6,    20,    26,
      52,     4,     4,   155,    -1,   120,    -1,    -1,   118,    52,
      51,    -1,    52,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,     0,     1,     6,     7,     8,    11,    12,    13,
      17,    27,    29,    31,    33,    60,     6,     6,     9,    14,
      16,     9,    14,    16,     4,    10,    15,     4,     4,    34,
       4,     4,    38,    39,    40,    41,    48,    71,    72,    73,
       4,     4,     4,     4,     4,     4,    50,    50,    50,    50,
      28,     4,    32,    57,    51,    51,    51,    51,    34,    54,
      50,    51,    51,    50,    50,    51,     6,     6,     6,     6,
      51,    30,    61,     4,     4,    73,    73,    73,    73,     4,
      74,    72,     6,     4,    22,    23,    25,    63,    64,     4,
       6,     6,     4,     3,     5,    20,    66,    67,     3,     5,
      68,    69,    70,    73,    50,    53,    52,    52,    52,    52,
      54,    61,    43,    44,    45,    65,    24,    24,    51,    52,
      54,    52,    52,    52,    54,    36,    37,    53,    55,    56,
      19,    21,    35,     6,    67,     4,    42,    62,    51,    51,
      51,    68,    50,    64,    50,    50,    50,    67,    69,    69,
      70,    73,    70,    70,    20,    51,     5,    61,    73,    50,
       3,     4,     4,    52,     6,     6,     6,     6,    66,    50,
       6,    52,    52,    52,    52,     6,    18,    26,    20,     4,
      51,     4,    52
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
        case 4:

/* Line 1806 of yacc.c  */
#line 45 "Parser.y"
    {
				prompt();
		   }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 49 "Parser.y"
    {
                mybufmanager->AllWriteback();
				delete mybufmanager;
				delete myfilemanager;
				delete indexManager;
				exit(0);
           }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 57 "Parser.y"
    {
				OrderPack pack(OrderPack::CREATE_DB);
				pack.dbname = (yyvsp[(3) - (5)]).id;
				pack.process();
				/* std::cout << "create db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 66 "Parser.y"
    {
				OrderPack pack(OrderPack::DROP_DB);
				pack.dbname = (yyvsp[(3) - (5)]).id;
				pack.process();
				/* std::cout << "drop db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 75 "Parser.y"
    {
				OrderPack pack(OrderPack::USE);
				pack.dbname = (yyvsp[(2) - (4)]).id;
				pack.process();
				/* std::cout << "use db "; */
				/* std::cout << $2.id << std::endl; */
				prompt();
		   }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 84 "Parser.y"
    {
                OrderPack pack(OrderPack::SHOWDBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
        }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 91 "Parser.y"
    {
				OrderPack pack(OrderPack::SHOWTBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
		   }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 98 "Parser.y"
    {
				OrderPack pack(OrderPack::CREATE_TB);
				pack.tbname = (yyvsp[(3) - (8)]).id;
				pack.schema = (yyvsp[(5) - (8)]).schema;
				pack.process();
				/* std::cout << "create tb "; */
				/* std::cout << $3.id << std::endl; */
				/* std::cout << "Schema :" << std::endl; */
				/* $5.schema.print(); */
				prompt();
		   }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 110 "Parser.y"
    {
				OrderPack pack(OrderPack::DROP_TB);
				pack.tbname = (yyvsp[(3) - (5)]).id;
				pack.process();
				/* std::cout << "drop tb "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 119 "Parser.y"
    {
				OrderPack pack(OrderPack::DESC);
				pack.tbname = (yyvsp[(2) - (4)]).id;
				pack.process();
				/* cout << "describe table "; */
				/* cout << $2.id << endl; */
				prompt();
		   }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 128 "Parser.y"
    {
				OrderPack pack(OrderPack::INSERT);
				pack.tbname = (yyvsp[(2) - (8)]).id;
				pack.values = (yyvsp[(5) - (8)]).values;
				pack.process();
		   		/* cout << "insert into table "; */
				/* cout << $2.id << endl; */
				/* cout << "values : " << endl; */
				/* $5.printValues(); */
				prompt();
		   }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 140 "Parser.y"
    {
				OrderPack pack(OrderPack::DELETE);
				pack.tbname = (yyvsp[(3) - (6)]).id;
				pack.condition = (yyvsp[(4) - (6)]).condition;
				pack.process();
				/* cout << "delete from table "; */
				/* cout << $3.id << endl; */
				/* $4.condition.print(); */
				prompt();
		   }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 151 "Parser.y"
    {
				OrderPack pack(OrderPack::SELECT);
				pack.allAttrs = (yyvsp[(2) - (8)]).allAttrs;
				pack.attrs = (yyvsp[(2) - (8)]).attrList;
				pack.tables = (yyvsp[(4) - (8)]).tableList;
				pack.condition = (yyvsp[(5) - (8)]).condition;
				pack.groupbyAttr = (yyvsp[(6) - (8)]).attr;
				pack.process();
				/* cout << "select from table " << endl; */
				/* cout << "ATTR : "; */
				/* $2.printAttrs(); */
				/* cout << "TB : "; */
				/* $4.printTables(); */
				/* cout << "Cond : "; */
				/* $5.condition.print(); */
				/* cout << "GRP_BY : " << $6.attr.toString() << endl; */
				prompt();
		   }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 170 "Parser.y"
    {
				OrderPack pack(OrderPack::UPDATE);
				pack.tbname = (yyvsp[(2) - (9)]).id;
				pack.updateAttr = (yyvsp[(4) - (9)]).id;
				pack.updateValue = (yyvsp[(6) - (9)]).value;
				pack.condition = (yyvsp[(7) - (9)]).condition;
				pack.process();
				/* cout << "update table " <<  endl; */
				/* cout << "TB : " << $2.id << endl; */
				/* cout << "ATTR : " << $4.id << endl; */
				/* cout << "VAL : "; */
				/* if ($6.value.type == 0) */
				/*    cout << $6.value.integer << endl; */
				/* else */
				/*    cout << $6.value.literal << endl; */
				/* $7.condition.print(); */
				prompt();
		   }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 189 "Parser.y"
    {
				OrderPack pack(OrderPack::CREATE_INDEX);
				pack.tbname = (yyvsp[(3) - (8)]).id;
				pack.indexAttr = (yyvsp[(5) - (8)]).id;
				pack.process();
				/* cout << "create index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 200 "Parser.y"
    {
				OrderPack pack(OrderPack::DROP_INDEX);
				pack.tbname = (yyvsp[(3) - (8)]).id;
				pack.indexAttr = (yyvsp[(5) - (8)]).id;
				pack.process();
				/* cout << "drop index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 211 "Parser.y"
    {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 219 "Parser.y"
    {
				(yyval).condition.clear();
		   }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 223 "Parser.y"
    {
		   		 (yyval).condition = (yyvsp[(2) - (2)]).condition;
		   }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 230 "Parser.y"
    {
				(yyval).attr.clear();
		   }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 234 "Parser.y"
    {
				(yyval).attr = (yyvsp[(2) - (2)]).attr;
		   }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 241 "Parser.y"
    {
				(yyval).schema.process((yyvsp[(3) - (3)]).schemaEntry);
		   }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 245 "Parser.y"
    {
				(yyval).schema = Schema();
				(yyval).schema.process((yyvsp[(1) - (1)]).schemaEntry);
		   }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 253 "Parser.y"
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[(1) - (5)]).id, (yyvsp[(2) - (5)]).datatype, (yyvsp[(4) - (5)]).length, 0);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 258 "Parser.y"
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[(1) - (7)]).id, (yyvsp[(2) - (7)]).datatype, (yyvsp[(4) - (7)]).length, 1);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 263 "Parser.y"
    {
				(yyval).schemaEntry.primaryKey = (yyvsp[(4) - (5)]).id;
				(yyval).schemaEntry.entrykind = SchemaEntry::PRIMARY;
		   }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 268 "Parser.y"
    {
				(yyval).schemaEntry.constrain = (yyvsp[(3) - (4)]).condition;
				(yyval).schemaEntry.entrykind = SchemaEntry::CHECK;
		   }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 273 "Parser.y"
    {
				(yyval).schemaEntry.foreignKey = (yyvsp[(4) - (10)]).id;
				(yyval).schemaEntry.foreignAttr = Attr((yyvsp[(7) - (10)]).id, (yyvsp[(9) - (10)]).id);
				(yyval).schemaEntry.entrykind = SchemaEntry::FOREIGN;
		   }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 280 "Parser.y"
    { (yyval).datatype = "int"; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 281 "Parser.y"
    { (yyval).datatype = "char"; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 282 "Parser.y"
    { (yyval).datatype = "varchar"; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 287 "Parser.y"
    {
				(yyval).values.push_back((yyvsp[(3) - (3)]).value);
		   }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 291 "Parser.y"
    {
				(yyval).values.clear();
				(yyval).values.push_back((yyvsp[(1) - (1)]).value);
		   }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 298 "Parser.y"
    { (yyval).value = Value(0, (yyvsp[(1) - (1)]).length, ""); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 299 "Parser.y"
    { (yyval).value = Value(1, 0, (yyvsp[(1) - (1)]).literal); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 300 "Parser.y"
    {(yyval).value = Value(2, 0, "");}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 305 "Parser.y"
    {
				(yyval).condition.add(Condition::AND, (yyvsp[(3) - (3)]).condEntry);
		   }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 309 "Parser.y"
    {
				(yyval).condition.add(Condition::OR, (yyvsp[(3) - (3)]).condEntry);
		   }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 313 "Parser.y"
    {
				(yyval).condition = Condition((yyvsp[(1) - (1)]).condEntry);
		   }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 320 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::EQUAL, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 324 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::GREATER, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 328 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::LESS, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 332 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IS;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (3)]).attr;
		   }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 339 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::LIKE;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (3)]).attr;
				(yyval).condEntry.mode = (yyvsp[(3) - (3)]).literal;
		   }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 347 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IN;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (5)]).attr;
				(yyval).condEntry.values = (yyvsp[(4) - (5)]).values;
		   }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 358 "Parser.y"
    {
				(yyval).expr = Expr(Expr::ATTR);
				(yyval).expr.attr = (yyvsp[(1) - (1)]).attr;
		   }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 363 "Parser.y"
    {
				(yyval).expr = Expr(Expr::INTEGER);
				(yyval).expr.integer = (yyvsp[(1) - (1)]).length;
		   }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 368 "Parser.y"
    {
				(yyval).expr = Expr(Expr::LITERAL);
				(yyval).expr.literal = (yyvsp[(1) - (1)]).literal;
		   }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 376 "Parser.y"
    {
				(yyval).allAttrs = true;
		   }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 380 "Parser.y"
    {
				(yyval).allAttrs = false;
				(yyval).attrList.push_back((yyvsp[(3) - (3)]).attr);
		   }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 385 "Parser.y"
    {
				(yyval).allAttrs = false;
				(yyval).attrList.clear();
				(yyval).attrList.push_back((yyvsp[(1) - (1)]).attr);
		   }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 393 "Parser.y"
    {
				(yyval).attr = (yyvsp[(1) - (1)]).attr;
				(yyval).attr.aggr = Attr::NONE;
		   }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 398 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::SUM;
		   }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 403 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::AVG;
		   }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 408 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::MAX;
		   }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 413 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::MIN;
		   }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 419 "Parser.y"
    {
		   		(yyval).attr = Attr("", (yyvsp[(1) - (1)]).id);
		   }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 423 "Parser.y"
    {
				(yyval).attr = Attr((yyvsp[(1) - (3)]).id, (yyvsp[(3) - (3)]).id);
		   }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 430 "Parser.y"
    {
				(yyval).tableList.push_back((yyvsp[(3) - (3)]).id);
		   }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 434 "Parser.y"
    {
				(yyval).tableList.clear();
				(yyval).tableList.push_back((yyvsp[(1) - (1)]).id);
		   }
    break;



/* Line 1806 of yacc.c  */
#line 2214 "Parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 439 "Parser.y"


void prompt()
{
	if (isInterp)
	{
		 std::cout << std::endl;
		std::cout << " sql> ";
	}
	else
	{
//		cout << "--------------" << endl;
    }
}

void yyerror(const char *s)
{
	/* Do Nothing */
}

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return -1;
	}

	FILE *pFile = NULL;
	if (argc == 2)
	{
		pFile = fopen(argv[1], "r");
		if (!pFile)
		{
			std::cout << "Input File not Exist!" << std::endl;
			return -1;
		}
	}

	chdir("../db");

	myfilemanager = new DBFileManager();
	mybufmanager = new DBBufManager();
	indexManager = new IndexManager();
	tmpbuf = new DBFile();

	if (argc == 2)
	{
		isInterp = false;
		yyin = pFile;
		yyparse();
	}
	if (argc == 1)
	{
		isInterp = true;
		prompt();
		yyparse();
	}
	return 0;
}

