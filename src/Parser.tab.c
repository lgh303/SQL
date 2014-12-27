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
	#include "DBFileManager.h"
	#include "DBBufManager.h"
	#include "SemValue.h"
	#include "OrderPack.h"
	#define YYSTYPE SemValue
	void yyerror(const char*);
	void prompt();
	int yylex(void);
	extern FILE* yyin;
	bool isInterp = true;
	using namespace std;


/* Line 268 of yacc.c  */
#line 89 "Parser.tab.c"

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
     DROP = 265,
     USE = 266,
     SHOW = 267,
     TB = 268,
     TBS = 269,
     INDEX = 270,
     DESC = 271,
     NOT = 272,
     IS = 273,
     NUL = 274,
     IN = 275,
     PRIMARY = 276,
     FOREIGN = 277,
     KEY = 278,
     CHECK = 279,
     REFER = 280,
     INS_INTO = 281,
     VALUES = 282,
     DELETE = 283,
     WHERE = 284,
     UPDATE = 285,
     SET = 286,
     SELECT = 287,
     FROM = 288,
     LIKE = 289,
     AND = 290,
     OR = 291,
     SUM = 292,
     AVG = 293,
     MAX = 294,
     MIN = 295,
     GRP_BY = 296,
     INT = 297,
     CHAR = 298,
     VCHAR = 299
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
#line 175 "Parser.tab.c"

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
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,    47,    45,    53,    46,    56,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      55,    52,    54,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    12,    18,    24,    29,
      34,    43,    49,    54,    63,    70,    79,    89,    98,   107,
     110,   111,   114,   115,   118,   122,   124,   130,   138,   144,
     149,   160,   162,   164,   166,   170,   172,   174,   176,   180,
     184,   186,   190,   194,   198,   202,   206,   212,   214,   216,
     218,   220,   224,   226,   228,   233,   238,   243,   248,   250,
     254,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    58,    59,    -1,    -1,     6,    -1,     7,
       6,    -1,     8,     9,     4,    49,     6,    -1,    10,     9,
       4,    49,     6,    -1,    11,     4,    49,     6,    -1,    12,
      14,    49,     6,    -1,     8,    13,     4,    50,    62,    51,
      49,     6,    -1,    10,    13,     4,    49,     6,    -1,    16,
       4,    49,     6,    -1,    26,     4,    27,    50,    65,    51,
      49,     6,    -1,    28,    33,     4,    60,    49,     6,    -1,
      32,    70,    33,    73,    60,    61,    49,     6,    -1,    30,
       4,    31,     4,    52,    66,    60,    49,     6,    -1,     8,
      15,     4,    50,     4,    51,    49,     6,    -1,    10,    15,
       4,    50,     4,    51,    49,     6,    -1,     1,     6,    -1,
      -1,    29,    67,    -1,    -1,    41,    72,    -1,    62,    53,
      63,    -1,    63,    -1,     4,    64,    50,     3,    51,    -1,
       4,    64,    50,     3,    51,    17,    19,    -1,    21,    23,
      50,     4,    51,    -1,    24,    50,    67,    51,    -1,    22,
      23,    50,     4,    51,    25,     4,    50,     4,    51,    -1,
      42,    -1,    43,    -1,    44,    -1,    65,    53,    66,    -1,
      66,    -1,     3,    -1,     5,    -1,    67,    35,    68,    -1,
      67,    36,    68,    -1,    68,    -1,    69,    52,    69,    -1,
      69,    54,    69,    -1,    69,    55,    69,    -1,    72,    18,
      19,    -1,    72,    34,     5,    -1,    72,    20,    50,    65,
      51,    -1,    72,    -1,     3,    -1,     5,    -1,    47,    -1,
      70,    53,    71,    -1,    71,    -1,    72,    -1,    37,    50,
      72,    51,    -1,    38,    50,    72,    51,    -1,    39,    50,
      72,    51,    -1,    40,    50,    72,    51,    -1,     4,    -1,
       4,    56,     4,    -1,    73,    53,     4,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    33,    33,    34,    37,    41,    45,    54,    63,    72,
      79,    91,   100,   109,   121,   132,   151,   170,   181,   192,
     201,   204,   212,   215,   222,   226,   234,   239,   244,   249,
     254,   262,   263,   264,   268,   272,   280,   281,   285,   289,
     293,   300,   304,   308,   312,   319,   327,   338,   343,   348,
     356,   360,   365,   373,   378,   383,   388,   393,   399,   403,
     410,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "IDENTIFIER", "LITERAL",
  "ENDLINE", "QUIT", "CREATE", "DB", "DROP", "USE", "SHOW", "TB", "TBS",
  "INDEX", "DESC", "NOT", "IS", "NUL", "IN", "PRIMARY", "FOREIGN", "KEY",
  "CHECK", "REFER", "INS_INTO", "VALUES", "DELETE", "WHERE", "UPDATE",
  "SET", "SELECT", "FROM", "LIKE", "AND", "OR", "SUM", "AVG", "MAX", "MIN",
  "GRP_BY", "INT", "CHAR", "VCHAR", "'+'", "'-'", "'*'", "'/'", "';'",
  "'('", "')'", "'='", "','", "'>'", "'<'", "'.'", "$accept", "Program",
  "Stmt", "WhereClause", "GroupClause", "AttrDefList", "AttrDefItem",
  "Type", "ValueList", "ValueItem", "CondList", "Cond", "Expr", "AttrList",
  "AttrAggr", "Attr", "TableList", 0
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
     295,   296,   297,   298,   299,    43,    45,    42,    47,    59,
      40,    41,    61,    44,    62,    60,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    71,    72,    72,
      73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     5,     5,     4,     4,
       8,     5,     4,     8,     6,     8,     9,     8,     8,     2,
       0,     2,     0,     2,     3,     1,     5,     7,     5,     4,
      10,     1,     1,     1,     3,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     5,     1,     1,     1,
       1,     3,     1,     1,     4,     4,     4,     4,     1,     3,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    19,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,    50,     0,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    12,     0,     0,     0,
       0,    59,     0,     0,     0,     0,    61,    20,    51,     6,
       0,     0,     0,     0,     0,    25,     0,     7,    11,     0,
      36,    37,     0,    35,    48,    49,    21,    40,     0,    47,
       0,     0,    54,    55,    56,    57,     0,    22,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      20,    60,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    34,    38,    39,    41,    47,    42,    43,
      44,     0,    45,     0,    23,     0,     0,     0,     0,    29,
      10,    17,    18,    13,     0,     0,    15,    26,    28,     0,
      46,    16,     0,     0,    27,     0,     0,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    69,   133,    84,    85,   111,    92,    93,
      96,    97,    98,    36,    37,    99,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
     -85,     3,   -85,    31,   -85,    47,    15,    49,    17,    18,
      72,    79,    51,    81,     8,   -85,   -85,   -85,    82,    83,
      84,    85,    86,    87,    43,    44,    45,    68,    92,    66,
      42,    50,    52,    53,    54,   -85,   -26,   -85,   -85,    57,
      55,    58,    63,    64,    65,    93,    95,   101,    67,    90,
     110,   112,   116,   116,   116,   116,   117,    12,   118,     1,
     119,   120,   121,   124,   -85,   -85,   -85,    39,    56,    73,
      77,   -85,    74,    80,    88,    89,   -85,   -27,   -85,   -85,
      25,   107,   109,    91,   -45,   -85,    94,   -85,   -85,    96,
     -85,   -85,    26,   -85,   -85,   -85,    35,   -85,    11,     0,
     127,    39,   -85,   -85,   -85,   -85,   130,    97,   -85,   -85,
     -85,    98,    99,   100,    56,   102,     1,   103,   104,   105,
      39,    56,    56,    56,    56,    56,   123,   106,   131,   -85,
      90,   -85,   116,   108,   132,   133,   139,    21,   138,   -85,
     140,   149,   152,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,    39,   -85,   111,   -85,   153,   113,   114,   115,   -85,
     -85,   -85,   -85,   -85,    27,   155,   -85,   145,   -85,   142,
     -85,   -85,   144,   164,   -85,   122,   165,   125,   -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,   -76,   -85,   -85,    59,   -85,    19,   -84,
      60,   -40,   -50,   -85,   126,   -14,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,   107,    68,     2,     3,    80,   115,    56,   116,     4,
       5,     6,    30,     7,     8,     9,    30,   130,   126,    10,
     127,    24,    81,    82,    18,    83,   106,    57,    19,    11,
      20,    12,    25,    13,   128,    14,   143,    16,    72,    73,
      74,    75,    90,    38,    91,    31,    32,    33,    34,    31,
      32,    33,    34,    17,   153,    35,   121,   122,    21,    94,
      30,    95,    22,   123,    23,   124,   125,   108,   109,   110,
     121,   122,   159,   146,   148,   149,    26,   119,   170,   120,
     120,   144,   145,    27,    28,    29,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    64,
      52,    65,    53,    54,    55,    59,    58,    66,    60,   147,
     147,   147,    61,    62,    70,    63,    71,    67,   154,    68,
      30,    76,   100,    86,    79,   102,    87,    88,    89,   101,
     112,   103,   113,   129,   131,   156,   152,   157,   132,   104,
     105,   114,   150,   158,   160,   117,   161,   118,   134,   135,
     136,   138,   140,   141,   142,   162,   151,   155,   163,   166,
     165,   171,   172,   174,   167,   168,   169,   173,   175,   177,
     164,     0,   176,     0,   137,   139,   178,     0,     0,     0,
       0,     0,     0,    78
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-85))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      14,    77,    29,     0,     1,     4,    51,    33,    53,     6,
       7,     8,     4,    10,    11,    12,     4,   101,    18,    16,
      20,     4,    21,    22,     9,    24,    53,    53,    13,    26,
      15,    28,    14,    30,    34,    32,   120,     6,    52,    53,
      54,    55,     3,    57,     5,    37,    38,    39,    40,    37,
      38,    39,    40,     6,   130,    47,    35,    36,     9,     3,
       4,     5,    13,    52,    15,    54,    55,    42,    43,    44,
      35,    36,    51,   123,   124,   125,     4,    51,    51,    53,
      53,   121,   122,     4,    33,     4,     4,     4,     4,     4,
       4,     4,    49,    49,    49,    27,     4,    31,    56,     6,
      50,     6,    50,    50,    50,    50,    49,     6,    50,   123,
     124,   125,    49,    49,     4,    50,     4,    50,   132,    29,
       4,     4,    49,     4,     6,    51,     6,     6,     4,    52,
      23,    51,    23,     6,     4,     3,     5,     4,    41,    51,
      51,    50,    19,     4,     6,    51,     6,    51,    50,    50,
      50,    49,    49,    49,    49,     6,    50,    49,     6,     6,
      49,     6,    17,    19,    51,    51,    51,    25,     4,     4,
     151,    -1,    50,    -1,   114,   116,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     1,     6,     7,     8,    10,    11,    12,
      16,    26,    28,    30,    32,    59,     6,     6,     9,    13,
      15,     9,    13,    15,     4,    14,     4,     4,    33,     4,
       4,    37,    38,    39,    40,    47,    70,    71,    72,     4,
       4,     4,     4,     4,     4,    49,    49,    49,    27,     4,
      31,    56,    50,    50,    50,    50,    33,    53,    49,    50,
      50,    49,    49,    50,     6,     6,     6,    50,    29,    60,
       4,     4,    72,    72,    72,    72,     4,    73,    71,     6,
       4,    21,    22,    24,    62,    63,     4,     6,     6,     4,
       3,     5,    65,    66,     3,     5,    67,    68,    69,    72,
      49,    52,    51,    51,    51,    51,    53,    60,    42,    43,
      44,    64,    23,    23,    50,    51,    53,    51,    51,    51,
      53,    35,    36,    52,    54,    55,    18,    20,    34,     6,
      66,     4,    41,    61,    50,    50,    50,    67,    49,    63,
      49,    49,    49,    66,    68,    68,    69,    72,    69,    69,
      19,    50,     5,    60,    72,    49,     3,     4,     4,    51,
       6,     6,     6,     6,    65,    49,     6,    51,    51,    51,
      51,     6,    17,    25,    19,     4,    50,     4,    51
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
#line 38 "Parser.y"
    {
				prompt();
		   }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 42 "Parser.y"
    {
				exit(0);
           }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 46 "Parser.y"
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
#line 55 "Parser.y"
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
#line 64 "Parser.y"
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
#line 73 "Parser.y"
    {
				OrderPack pack(OrderPack::SHOW);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
		   }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 80 "Parser.y"
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

  case 11:

/* Line 1806 of yacc.c  */
#line 92 "Parser.y"
    {
				OrderPack pack(OrderPack::DROP_TB);
				pack.tbname = (yyvsp[(3) - (5)]).id;
				pack.process();
				/* std::cout << "drop tb "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 101 "Parser.y"
    {
				OrderPack pack(OrderPack::DESC);
				pack.tbname = (yyvsp[(2) - (4)]).id;
				pack.process();
				/* cout << "describe table "; */
				/* cout << $2.id << endl; */
				prompt();
		   }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 110 "Parser.y"
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

  case 14:

/* Line 1806 of yacc.c  */
#line 122 "Parser.y"
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

  case 15:

/* Line 1806 of yacc.c  */
#line 133 "Parser.y"
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

  case 16:

/* Line 1806 of yacc.c  */
#line 152 "Parser.y"
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

  case 17:

/* Line 1806 of yacc.c  */
#line 171 "Parser.y"
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

  case 18:

/* Line 1806 of yacc.c  */
#line 182 "Parser.y"
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

  case 19:

/* Line 1806 of yacc.c  */
#line 193 "Parser.y"
    {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 201 "Parser.y"
    {
				(yyval).condition.clear();
		   }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 205 "Parser.y"
    {	 
		   		 (yyval).condition = (yyvsp[(2) - (2)]).condition;
		   }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 212 "Parser.y"
    {
				(yyval).attr.clear();
		   }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 216 "Parser.y"
    {
				(yyval).attr = (yyvsp[(2) - (2)]).attr;
		   }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 223 "Parser.y"
    {
				(yyval).schema.process((yyvsp[(3) - (3)]).schemaEntry);
		   }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 227 "Parser.y"
    {
				(yyval).schema = Schema();
				(yyval).schema.process((yyvsp[(1) - (1)]).schemaEntry);
		   }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 235 "Parser.y"
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[(1) - (5)]).id, (yyvsp[(2) - (5)]).datatype, (yyvsp[(4) - (5)]).length, 0);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 240 "Parser.y"
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[(1) - (7)]).id, (yyvsp[(2) - (7)]).datatype, (yyvsp[(4) - (7)]).length, 1);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 245 "Parser.y"
    {
				(yyval).schemaEntry.primaryKey = (yyvsp[(4) - (5)]).id;
				(yyval).schemaEntry.entrykind = SchemaEntry::PRIMARY;
		   }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 250 "Parser.y"
    {
				(yyval).schemaEntry.constrain = (yyvsp[(3) - (4)]).condition;
				(yyval).schemaEntry.entrykind = SchemaEntry::CHECK;
		   }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 255 "Parser.y"
    {
				(yyval).schemaEntry.foreignKey = (yyvsp[(4) - (10)]).id;
				(yyval).schemaEntry.foreignAttr = Attr((yyvsp[(7) - (10)]).id, (yyvsp[(9) - (10)]).id);
				(yyval).schemaEntry.entrykind = SchemaEntry::FOREIGN;
		   }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 262 "Parser.y"
    { (yyval).datatype = "int"; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 263 "Parser.y"
    { (yyval).datatype = "char"; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 264 "Parser.y"
    { (yyval).datatype = "varchar"; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 269 "Parser.y"
    {
				(yyval).values.push_back((yyvsp[(3) - (3)]).value);
		   }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 273 "Parser.y"
    {
				(yyval).values.clear();
				(yyval).values.push_back((yyvsp[(1) - (1)]).value);
		   }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 280 "Parser.y"
    { (yyval).value = Value(0, (yyvsp[(1) - (1)]).length, ""); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 281 "Parser.y"
    { (yyval).value = Value(1, 0, (yyvsp[(1) - (1)]).literal); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 286 "Parser.y"
    {
				(yyval).condition.add(Condition::AND, (yyvsp[(3) - (3)]).condEntry);
		   }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 290 "Parser.y"
    {
				(yyval).condition.add(Condition::OR, (yyvsp[(3) - (3)]).condEntry);
		   }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 294 "Parser.y"
    {
				(yyval).condition = Condition((yyvsp[(1) - (1)]).condEntry);
		   }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 301 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::EQUAL, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 305 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::GREATER, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 309 "Parser.y"
    {
				(yyval).condEntry = CondEntry(CondEntry::LESS, (yyvsp[(1) - (3)]).expr, (yyvsp[(3) - (3)]).expr);
		   }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 313 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IS;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (3)]).attr;
		   }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 320 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::LIKE;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (3)]).attr;
				(yyval).condEntry.mode = (yyvsp[(3) - (3)]).literal;		   
		   }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 328 "Parser.y"
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IN;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[(1) - (5)]).attr;
				(yyval).condEntry.values = (yyvsp[(4) - (5)]).values;
		   }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 339 "Parser.y"
    {
				(yyval).expr = Expr(Expr::ATTR);
				(yyval).expr.attr = (yyvsp[(1) - (1)]).attr;
		   }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 344 "Parser.y"
    {
				(yyval).expr = Expr(Expr::INTEGER);
				(yyval).expr.integer = (yyvsp[(1) - (1)]).length;
		   }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 349 "Parser.y"
    {
				(yyval).expr = Expr(Expr::LITERAL);
				(yyval).expr.literal = (yyvsp[(1) - (1)]).literal;
		   }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 357 "Parser.y"
    {
				(yyval).allAttrs = true;
		   }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 361 "Parser.y"
    {
				(yyval).allAttrs = false;
				(yyval).attrList.push_back((yyvsp[(3) - (3)]).attr);
		   }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 366 "Parser.y"
    {
				(yyval).allAttrs = false;
				(yyval).attrList.clear();
				(yyval).attrList.push_back((yyvsp[(1) - (1)]).attr);
		   }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 374 "Parser.y"
    {
				(yyval).attr = (yyvsp[(1) - (1)]).attr;
				(yyval).attr.aggr = Attr::NONE;
		   }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 379 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::SUM;
		   }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 384 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::AVG;
		   }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 389 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::MAX;
		   }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 394 "Parser.y"
    {
				(yyval).attr = (yyvsp[(3) - (4)]).attr;
				(yyval).attr.aggr = Attr::MIN;
		   }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 400 "Parser.y"
    {	
		   		(yyval).attr = Attr("", (yyvsp[(1) - (1)]).id);
		   }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 404 "Parser.y"
    {
				(yyval).attr = Attr((yyvsp[(1) - (3)]).id, (yyvsp[(3) - (3)]).id);
		   }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 411 "Parser.y"
    {
				(yyval).tableList.push_back((yyvsp[(3) - (3)]).id);
		   }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 415 "Parser.y"
    {
				(yyval).tableList.clear();
				(yyval).tableList.push_back((yyvsp[(1) - (1)]).id);
		   }
    break;



/* Line 1806 of yacc.c  */
#line 2178 "Parser.tab.c"
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
#line 420 "Parser.y"


void prompt()
{
	if (isInterp)
	{
		std::cout << " sql> ";
	}
	else
	{
		cout << "--------------" << endl;
    }
}

void yyerror(const char *s)
{
	/* Do Nothing */
}

DBFileManager* myfilemanager = NULL;
DBBufManager *mybufmanager = NULL;

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return -1;
	}
	
	myfilemanager = new DBFileManager();
	mybufmanager = new DBBufManager();

	if (argc == 2)
	{
		FILE* pFile = fopen(argv[1], "r");
		if (!pFile)
		{
			std::cout << "Input File not Exist!" << std::endl;
			return -1;
		}
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

