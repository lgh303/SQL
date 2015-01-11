/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

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

#line 90 "Parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 187 "Parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "Expr", "AttrList", "AttrAggr", "Attr", "TableList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   -79,  -101,  -101,    55,  -101,    18,  -100,
      60,   -59,   -39,  -101,   128,   -14,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    72,   137,    87,    88,   115,    96,    97,
     100,   101,   102,    37,    38,   103,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 45 "Parser.y" /* yacc.c:1646  */
    {
				prompt();
		   }
#line 1382 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 49 "Parser.y" /* yacc.c:1646  */
    {
                mybufmanager->AllWriteback();
				delete mybufmanager;
				delete myfilemanager;
				delete indexManager;
				exit(0);
           }
#line 1394 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::CREATE_DB);
				pack.dbname = (yyvsp[-2]).id;
				pack.process();
				/* std::cout << "create db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
#line 1407 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::DROP_DB);
				pack.dbname = (yyvsp[-2]).id;
				pack.process();
				/* std::cout << "drop db "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
#line 1420 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::USE);
				pack.dbname = (yyvsp[-2]).id;
				pack.process();
				/* std::cout << "use db "; */
				/* std::cout << $2.id << std::endl; */
				prompt();
		   }
#line 1433 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "Parser.y" /* yacc.c:1646  */
    {
                OrderPack pack(OrderPack::SHOWDBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
        }
#line 1444 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::SHOWTBS);
				pack.process();
				/* std::cout << "show tables" << std::endl; */
				prompt();
		   }
#line 1455 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::CREATE_TB);
				pack.tbname = (yyvsp[-5]).id;
				pack.schema = (yyvsp[-3]).schema;
				pack.process();
				/* std::cout << "create tb "; */
				/* std::cout << $3.id << std::endl; */
				/* std::cout << "Schema :" << std::endl; */
				/* $5.schema.print(); */
				prompt();
		   }
#line 1471 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::DROP_TB);
				pack.tbname = (yyvsp[-2]).id;
				pack.process();
				/* std::cout << "drop tb "; */
				/* std::cout << $3.id << std::endl; */
				prompt();
		   }
#line 1484 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::DESC);
				pack.tbname = (yyvsp[-2]).id;
				pack.process();
				/* cout << "describe table "; */
				/* cout << $2.id << endl; */
				prompt();
		   }
#line 1497 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::INSERT);
				pack.tbname = (yyvsp[-6]).id;
				pack.values = (yyvsp[-3]).values;
				pack.process();
		   		/* cout << "insert into table "; */
				/* cout << $2.id << endl; */
				/* cout << "values : " << endl; */
				/* $5.printValues(); */
				prompt();
		   }
#line 1513 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 140 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::DELETE);
				pack.tbname = (yyvsp[-3]).id;
				pack.condition = (yyvsp[-2]).condition;
				pack.process();
				/* cout << "delete from table "; */
				/* cout << $3.id << endl; */
				/* $4.condition.print(); */
				prompt();
		   }
#line 1528 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 151 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::SELECT);
				pack.allAttrs = (yyvsp[-6]).allAttrs;
				pack.attrs = (yyvsp[-6]).attrList;
				pack.tables = (yyvsp[-4]).tableList;
				pack.condition = (yyvsp[-3]).condition;
				pack.groupbyAttr = (yyvsp[-2]).attr;
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
#line 1551 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::UPDATE);
				pack.tbname = (yyvsp[-7]).id;
				pack.updateAttr = (yyvsp[-5]).id;
				pack.updateValue = (yyvsp[-3]).value;
				pack.condition = (yyvsp[-2]).condition;
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
#line 1574 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::CREATE_INDEX);
				pack.tbname = (yyvsp[-5]).id;
				pack.indexAttr = (yyvsp[-3]).id;
				pack.process();
				/* cout << "create index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
#line 1589 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "Parser.y" /* yacc.c:1646  */
    {
				OrderPack pack(OrderPack::DROP_INDEX);
				pack.tbname = (yyvsp[-5]).id;
				pack.indexAttr = (yyvsp[-3]).id;
				pack.process();
				/* cout << "drop index " << endl; */
				/* cout << "TB : " << $3.id << endl; */
				/* cout << "ATTR : " << $5.id << endl; */
				prompt();
		   }
#line 1604 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 211 "Parser.y" /* yacc.c:1646  */
    {
				std::cout << "Syntax Error" << std::endl;
				prompt();
		   }
#line 1613 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condition.clear();
		   }
#line 1621 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "Parser.y" /* yacc.c:1646  */
    {
		   		 (yyval).condition = (yyvsp[0]).condition;
		   }
#line 1629 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr.clear();
		   }
#line 1637 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 234 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[0]).attr;
		   }
#line 1645 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 241 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schema.process((yyvsp[0]).schemaEntry);
		   }
#line 1653 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 245 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schema = Schema();
				(yyval).schema.process((yyvsp[0]).schemaEntry);
		   }
#line 1662 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 253 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[-4]).id, (yyvsp[-3]).datatype, (yyvsp[-1]).length, 0);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
#line 1671 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 258 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schemaEntry = SchemaEntry((yyvsp[-6]).id, (yyvsp[-5]).datatype, (yyvsp[-3]).length, 1);
				(yyval).schemaEntry.entrykind = SchemaEntry::NORMAL;
		   }
#line 1680 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 263 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schemaEntry.primaryKey = (yyvsp[-1]).id;
				(yyval).schemaEntry.entrykind = SchemaEntry::PRIMARY;
		   }
#line 1689 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 268 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schemaEntry.constrain = (yyvsp[-1]).condition;
				(yyval).schemaEntry.entrykind = SchemaEntry::CHECK;
		   }
#line 1698 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 273 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).schemaEntry.foreignKey = (yyvsp[-6]).id;
				(yyval).schemaEntry.foreignAttr = Attr((yyvsp[-3]).id, (yyvsp[-1]).id);
				(yyval).schemaEntry.entrykind = SchemaEntry::FOREIGN;
		   }
#line 1708 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 280 "Parser.y" /* yacc.c:1646  */
    { (yyval).datatype = "int"; }
#line 1714 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 281 "Parser.y" /* yacc.c:1646  */
    { (yyval).datatype = "char"; }
#line 1720 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 282 "Parser.y" /* yacc.c:1646  */
    { (yyval).datatype = "varchar"; }
#line 1726 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 287 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).values.push_back((yyvsp[0]).value);
		   }
#line 1734 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 291 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).values.clear();
				(yyval).values.push_back((yyvsp[0]).value);
		   }
#line 1743 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 298 "Parser.y" /* yacc.c:1646  */
    { (yyval).value = Value(0, (yyvsp[0]).length, ""); }
#line 1749 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 299 "Parser.y" /* yacc.c:1646  */
    { (yyval).value = Value(1, 0, (yyvsp[0]).literal); }
#line 1755 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 300 "Parser.y" /* yacc.c:1646  */
    {(yyval).value = Value(2, 0, "");}
#line 1761 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 305 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condition.add(Condition::AND, (yyvsp[0]).condEntry);
		   }
#line 1769 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 309 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condition.add(Condition::OR, (yyvsp[0]).condEntry);
		   }
#line 1777 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 313 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condition = Condition((yyvsp[0]).condEntry);
		   }
#line 1785 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 320 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry(CondEntry::EQUAL, (yyvsp[-2]).expr, (yyvsp[0]).expr);
		   }
#line 1793 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 324 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry(CondEntry::GREATER, (yyvsp[-2]).expr, (yyvsp[0]).expr);
		   }
#line 1801 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 328 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry(CondEntry::LESS, (yyvsp[-2]).expr, (yyvsp[0]).expr);
		   }
#line 1809 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 332 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IS;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[-2]).attr;
		   }
#line 1820 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 339 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::LIKE;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[-2]).attr;
				(yyval).condEntry.mode = (yyvsp[0]).literal;
		   }
#line 1832 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 347 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).condEntry = CondEntry();
				(yyval).condEntry.op = CondEntry::IN;
				(yyval).condEntry.left = Expr(Expr::ATTR);
				(yyval).condEntry.left.attr = (yyvsp[-4]).attr;
				(yyval).condEntry.values = (yyvsp[-1]).values;
		   }
#line 1844 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 358 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).expr = Expr(Expr::ATTR);
				(yyval).expr.attr = (yyvsp[0]).attr;
		   }
#line 1853 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 363 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).expr = Expr(Expr::INTEGER);
				(yyval).expr.integer = (yyvsp[0]).length;
		   }
#line 1862 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).expr = Expr(Expr::LITERAL);
				(yyval).expr.literal = (yyvsp[0]).literal;
		   }
#line 1871 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 376 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).allAttrs = true;
		   }
#line 1879 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 380 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).allAttrs = false;
				(yyval).attrList.push_back((yyvsp[0]).attr);
		   }
#line 1888 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).allAttrs = false;
				(yyval).attrList.clear();
				(yyval).attrList.push_back((yyvsp[0]).attr);
		   }
#line 1898 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 393 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[0]).attr;
				(yyval).attr.aggr = Attr::NONE;
		   }
#line 1907 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 398 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[-1]).attr;
				(yyval).attr.aggr = Attr::SUM;
		   }
#line 1916 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 403 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[-1]).attr;
				(yyval).attr.aggr = Attr::AVG;
		   }
#line 1925 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 408 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[-1]).attr;
				(yyval).attr.aggr = Attr::MAX;
		   }
#line 1934 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = (yyvsp[-1]).attr;
				(yyval).attr.aggr = Attr::MIN;
		   }
#line 1943 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "Parser.y" /* yacc.c:1646  */
    {
		   		(yyval).attr = Attr("", (yyvsp[0]).id);
		   }
#line 1951 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 423 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).attr = Attr((yyvsp[-2]).id, (yyvsp[0]).id);
		   }
#line 1959 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 430 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).tableList.push_back((yyvsp[0]).id);
		   }
#line 1967 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 434 "Parser.y" /* yacc.c:1646  */
    {
				(yyval).tableList.clear();
				(yyval).tableList.push_back((yyvsp[0]).id);
		   }
#line 1976 "Parser.tab.c" /* yacc.c:1646  */
    break;


#line 1980 "Parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 439 "Parser.y" /* yacc.c:1906  */


void prompt()
{
	if (isInterp)
	{
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
