/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "rules.y"

    #include <Foundation/Foundation.h>
    #include <Foundation/NSPredicate.h>
    #include <Foundation/NSExpression.h>
    #include "ExpressionHelpers.h"

    typedef void* yyscan_t;
    typedef void* YY_BUFFER_STATE;

    typedef NSExpression* (^ nextArgument)(NSString* type);
    extern int yyparse(yyscan_t lexer, nextArgument nextArg, NSPredicate **predicate);

    extern void lexer_init(const char *parseString, yyscan_t *lexer, YY_BUFFER_STATE *state);
    extern void lexer_destroy(yyscan_t lexer, YY_BUFFER_STATE state);

    void yyerror(yyscan_t scanner, nextArgument nextArg, NSPredicate** predicate, const char *error);

    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunreachable-code"

    NSPredicate *_parsePredicateFormatString(NSString *format, nextArgument nextArg);
    #pragma clang-format off

/* Line 371 of yacc.c  */
#line 92 "rules.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "rules.tab.h".  */
#ifndef YY_YY_RULES_TAB_H_INCLUDED
# define YY_YY_RULES_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AT = 258,
     NUMBER = 259,
     STRING = 260,
     IDENTIFIER = 261,
     LEFT_PARENTHESIS = 262,
     RIGHT_PARENTHESIS = 263,
     LEFT_CURLY_BRACES = 264,
     RIGHT_CURLY_BRACES = 265,
     LEFT_BRACKETS = 266,
     RIGHT_BRACKETS = 267,
     EQUAL = 268,
     NOT_EQUAL = 269,
     LESS_THAN = 270,
     GREATER_THAN = 271,
     EQUAL_AND_LESS_THAN = 272,
     EQUAL_AND_GREATER_THAN = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     PERIOD = 277,
     MINUS = 278,
     PLUS = 279,
     DIVIDE = 280,
     MULTIPLY = 281,
     EXPONENT = 282,
     ASSIGN = 283,
     COMA = 284,
     DOLLAR = 285,
     PERCENT = 286,
     BETWEEN = 287,
     CONTAINS = 288,
     YY_IN = 289,
     BEGINS_WITH = 290,
     ENDS_WITH = 291,
     LIKE = 292,
     MATCHES = 293,
     ANY = 294,
     ALL = 295,
     NONE = 296,
     SOME = 297,
     TRUE_PREDICATE = 298,
     FALSE_PREDICATE = 299,
     NULL_FLAG = 300,
     TRUE_FLAG = 301,
     FALSE_FLAG = 302,
     SELF = 303,
     FIRST = 304,
     LAST = 305,
     YY_SIZE = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 33 "rules.y"

    NSPredicate *predicate;
    NSNumber *number;
    NSString* string;
    NSMutableArray *array;
    NSExpression *expression;

    NSMutableString *parserString;

    struct {
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } operatorR;

    struct {
        NSExpression *lhs;
        NSExpression *rhs;
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } comparisonS;

    NSPredicateOperatorType operatorType;
    va_list arguments;


/* Line 387 of yacc.c  */
#line 212 "rules.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void*  scanner, nextArgument nextArg, NSPredicate **predicate);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_RULES_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 239 "rules.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    17,    21,
      25,    28,    30,    33,    36,    39,    42,    44,    46,    48,
      53,    55,    57,    59,    61,    63,    65,    67,    69,    71,
      73,    75,    77,    81,    83,    85,    87,    89,    91,    95,
      98,   102,   106,   110,   114,   118,   123,   127,   129,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   152,   155,
     157,   159,   163,   165,   168
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    56,    -1,    55,    -1,     7,
      54,     8,    -1,    43,    -1,    44,    -1,    54,    19,    54,
      -1,    54,    20,    54,    -1,    21,    54,    -1,    61,    -1,
      40,    61,    -1,    41,    61,    -1,    42,    61,    -1,    39,
      61,    -1,    32,    -1,    58,    -1,    59,    -1,    59,    11,
       6,    12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    38,    -1,     7,    60,     8,
      -1,    62,    -1,    63,    -1,    69,    -1,    70,    -1,    65,
      -1,    60,    57,    60,    -1,    23,    60,    -1,    60,    24,
      60,    -1,    60,    23,    60,    -1,    60,    26,    60,    -1,
      60,    25,    60,    -1,    60,    27,    60,    -1,     6,     7,
      64,     8,    -1,     6,     7,     8,    -1,    60,    -1,    64,
      29,    60,    -1,     4,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,     5,    -1,    66,    -1,    67,    -1,    30,
       6,    -1,    31,    68,    -1,     3,    -1,     6,    -1,    66,
      28,    60,    -1,     6,    -1,     3,     6,    -1,    60,    22,
      60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   153,   153,   155,   157,   157,   161,   162,
     163,   166,   168,   171,   173,   174,   178,   179,   182,   183,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   202,   204,   206,   208,   210,   212,   215,   219,
     220,   221,   222,   223,   224,   227,   229,   232,   233,   237,
     238,   239,   240,   241,   242,   243,   244,   247,   250,   253,
     254,   257,   260,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AT", "NUMBER", "STRING", "IDENTIFIER",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_CURLY_BRACES",
  "RIGHT_CURLY_BRACES", "LEFT_BRACKETS", "RIGHT_BRACKETS", "EQUAL",
  "NOT_EQUAL", "LESS_THAN", "GREATER_THAN", "EQUAL_AND_LESS_THAN",
  "EQUAL_AND_GREATER_THAN", "AND", "OR", "NOT", "PERIOD", "MINUS", "PLUS",
  "DIVIDE", "MULTIPLY", "EXPONENT", "ASSIGN", "COMA", "DOLLAR", "PERCENT",
  "BETWEEN", "CONTAINS", "IN", "BEGINS_WITH", "ENDS_WITH", "LIKE",
  "MATCHES", "ANY", "ALL", "NONE", "SOME", "TRUE_PREDICATE",
  "FALSE_PREDICATE", "NULL_FLAG", "TRUE_FLAG", "FALSE_FLAG", "SELF",
  "FIRST", "LAST", "SIZE", "$accept", "predicate_main", "NS_Predicate",
  "NS_CompoundPredicate", "NS_ComparisonPredicate", "Operator",
  "Operator_With_Options", "Operator_Type", "Expression",
  "Simple_Expression_Comparsion", "Binary_Expression",
  "Function_Expression", "Expression_List", "Value_Expression",
  "Predicate_Variable", "Predicate_Argument", "Format_Argument",
  "Assignment_Expression", "Keypath_Expression", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    67,    68,
      68,    69,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     3,     3,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     3,     3,     4,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     3,     1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    49,    54,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,    50,    51,    52,    53,
       0,     2,     4,     3,     0,    11,    33,    34,    37,    55,
      56,    35,    36,    63,     0,     0,     0,    10,     0,    39,
      57,    59,    60,    58,    15,    12,    13,    14,     1,     0,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,    16,    26,    27,    28,    29,    30,    31,
       0,    17,    18,     0,    46,    47,     0,     5,    32,     0,
       8,     9,    64,    41,    40,    43,    42,    44,    38,     0,
      61,    45,     0,     0,    48,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    70,    71,    72,    24,    25,
      26,    27,    76,    28,    29,    30,    43,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -16
static const yytype_int16 yypact[] =
{
       0,    14,   -16,   -16,    25,     0,     0,    66,    32,    31,
      66,    66,    66,    66,   -16,   -16,   -16,   -16,   -16,   -16,
      49,    47,   -16,   -16,   128,   -16,   -16,   -16,   -16,    22,
     -16,   -16,   -16,   -16,    55,     5,   102,   -16,    66,     1,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,     0,
       0,   -16,   -16,   -16,   -16,   -16,   -16,    66,    66,    66,
      66,    66,    66,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
      66,   -16,    40,    66,   -16,    -8,    -7,   -16,   -16,    68,
      44,   -16,   -15,     1,     1,    48,    48,   -16,    -8,    82,
     -16,   -16,    66,    62,    -8,   -16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,    30,   -16,   -16,   -16,   -16,   -16,    -5,    71,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      36,    91,    39,     1,     2,     3,     4,     5,    58,    59,
      60,    61,    62,    77,    57,    58,    59,    60,    61,    62,
      33,     6,    92,     7,    49,    50,    60,    61,    62,    75,
       8,     9,    34,    79,    41,    35,    37,    42,    40,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    48,
      73,    89,    82,    83,    84,    85,    86,    87,     1,     2,
       3,     4,    38,    74,    50,    88,    49,    50,    90,     1,
       2,     3,     4,    38,    95,    62,    78,     0,     7,    80,
      81,    44,    45,    46,    47,     8,     9,    94,    93,     7,
      57,    58,    59,    60,    61,    62,     8,     9,     0,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
      78,    16,    17,    18,    19,    51,    52,    53,    54,    55,
      56,     0,     0,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    51,    52,    53,    54,    55,    56,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-16)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       5,     8,     7,     3,     4,     5,     6,     7,    23,    24,
      25,    26,    27,     8,    22,    23,    24,    25,    26,    27,
       6,    21,    29,    23,    19,    20,    25,    26,    27,    34,
      30,    31,     7,    38,     3,     5,     6,     6,     6,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
      28,    11,    57,    58,    59,    60,    61,    62,     3,     4,
       5,     6,     7,     8,    20,    70,    19,    20,    73,     3,
       4,     5,     6,     7,    12,    27,     8,    -1,    23,    49,
      50,    10,    11,    12,    13,    30,    31,    92,     6,    23,
      22,    23,    24,    25,    26,    27,    30,    31,    -1,    -1,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    45,    46,    47,    48,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    21,    23,    30,    31,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      53,    54,    55,    56,    60,    61,    62,    63,    65,    66,
      67,    69,    70,     6,     7,    54,    60,    54,     7,    60,
       6,     3,     6,    68,    61,    61,    61,    61,     0,    19,
      20,    13,    14,    15,    16,    17,    18,    22,    23,    24,
      25,    26,    27,    32,    33,    34,    35,    36,    37,    38,
      57,    58,    59,    28,     8,    60,    64,     8,     8,    60,
      54,    54,    60,    60,    60,    60,    60,    60,    60,    11,
      60,     8,    29,     6,    60,    12
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
      yyerror (scanner, nextArg, predicate, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, scanner)
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
		  Type, Value, scanner, nextArg, predicate); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void*  scanner, nextArgument nextArg, NSPredicate **predicate)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner, nextArg, predicate)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void*  scanner;
    nextArgument nextArg;
    NSPredicate **predicate;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (scanner);
  YYUSE (nextArg);
  YYUSE (predicate);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void*  scanner, nextArgument nextArg, NSPredicate **predicate)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, scanner, nextArg, predicate)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void*  scanner;
    nextArgument nextArg;
    NSPredicate **predicate;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner, nextArg, predicate);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, void*  scanner, nextArgument nextArg, NSPredicate **predicate)
#else
static void
yy_reduce_print (yyvsp, yyrule, scanner, nextArg, predicate)
    YYSTYPE *yyvsp;
    int yyrule;
    void*  scanner;
    nextArgument nextArg;
    NSPredicate **predicate;
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
		       		       , scanner, nextArg, predicate);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, scanner, nextArg, predicate); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void*  scanner, nextArgument nextArg, NSPredicate **predicate)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, scanner, nextArg, predicate)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    void*  scanner;
    nextArgument nextArg;
    NSPredicate **predicate;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  YYUSE (nextArg);
  YYUSE (predicate);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




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
yyparse (void*  scanner, nextArgument nextArg, NSPredicate **predicate)
#else
int
yyparse (scanner, nextArg, predicate)
    void*  scanner;
    nextArgument nextArg;
    NSPredicate **predicate;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 150 "rules.y"
    { *predicate = (yyvsp[(1) - (1)].predicate); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 153 "rules.y"
    {(yyval.predicate) = (yyvsp[(1) - (1)].predicate);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 153 "rules.y"
    {(yyval.predicate) = (yyvsp[(1) - (1)].predicate);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 155 "rules.y"
    {(yyval.predicate) = (yyvsp[(2) - (3)].predicate);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 157 "rules.y"
    { (yyval.predicate) = [NSPredicate predicateWithValue:YES]; }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 157 "rules.y"
    {(yyval.predicate) = [NSPredicate predicateWithValue:NO];}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 161 "rules.y"
    {(yyval.predicate) = [NSCompoundPredicate andPredicateWithSubpredicates:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].predicate), (yyvsp[(3) - (3)].predicate), nil]];}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 162 "rules.y"
    {(yyval.predicate) = [NSCompoundPredicate orPredicateWithSubpredicates:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].predicate), (yyvsp[(3) - (3)].predicate), nil]];}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 163 "rules.y"
    {(yyval.predicate) = [ NSCompoundPredicate notPredicateWithSubpredicate:(yyvsp[(2) - (2)].predicate)];}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 166 "rules.y"
    {(yyval.predicate) = [NSComparisonPredicate predicateWithLeftExpression:(yyvsp[(1) - (1)].comparisonS).lhs rightExpression:(yyvsp[(1) - (1)].comparisonS).rhs modifier:NSDirectPredicateModifier type:(yyvsp[(1) - (1)].comparisonS).type options:(yyvsp[(1) - (1)].comparisonS).options]; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 168 "rules.y"
    { (yyval.predicate) = [NSComparisonPredicate predicateWithLeftExpression:(yyvsp[(2) - (2)].comparisonS).lhs rightExpression:(yyvsp[(2) - (2)].comparisonS).rhs modifier:NSAllPredicateModifier type:(yyvsp[(2) - (2)].comparisonS).type options:(yyvsp[(2) - (2)].comparisonS).options]; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 171 "rules.y"
    {(yyval.predicate) = [NSCompoundPredicate notPredicateWithSubpredicate:[NSComparisonPredicate predicateWithLeftExpression:(yyvsp[(2) - (2)].comparisonS).lhs rightExpression:(yyvsp[(2) - (2)].comparisonS).rhs modifier:NSAnyPredicateModifier type:(yyvsp[(2) - (2)].comparisonS).type options:(yyvsp[(2) - (2)].comparisonS).options]];}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 173 "rules.y"
    { (yyval.predicate) = [NSComparisonPredicate predicateWithLeftExpression:(yyvsp[(2) - (2)].comparisonS).lhs rightExpression:(yyvsp[(2) - (2)].comparisonS).rhs modifier:NSAnyPredicateModifier type:(yyvsp[(2) - (2)].comparisonS).type options:(yyvsp[(2) - (2)].comparisonS).options]; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 174 "rules.y"
    { (yyval.predicate) = [NSComparisonPredicate predicateWithLeftExpression:(yyvsp[(2) - (2)].comparisonS).lhs rightExpression:(yyvsp[(2) - (2)].comparisonS).rhs modifier:NSAnyPredicateModifier type:(yyvsp[(2) - (2)].comparisonS).type options:(yyvsp[(2) - (2)].comparisonS).options]; }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 178 "rules.y"
    { (yyval.operatorR).type = NSBetweenPredicateOperatorType; (yyval.operatorR).options = 0; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 179 "rules.y"
    { (yyval.operatorR) = (yyvsp[(1) - (1)].operatorR); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 182 "rules.y"
    { (yyval.operatorR).type = (yyvsp[(1) - (1)].operatorType); (yyval.operatorR).options = 0; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 183 "rules.y"
    { (yyval.operatorR).type = (yyvsp[(1) - (4)].operatorType); (yyval.operatorR).options = [NSComparisonPredicate extractOptions:(yyvsp[(3) - (4)].string)]; }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 187 "rules.y"
    { (yyval.operatorType) = NSEqualToPredicateOperatorType; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 188 "rules.y"
    { (yyval.operatorType) = NSNotEqualToPredicateOperatorType; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 189 "rules.y"
    { (yyval.operatorType) = NSLessThanPredicateOperatorType; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 190 "rules.y"
    { (yyval.operatorType) = NSGreaterThanPredicateOperatorType; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 191 "rules.y"
    { (yyval.operatorType) = NSLessThanOrEqualToPredicateOperatorType; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 192 "rules.y"
    { (yyval.operatorType) = NSGreaterThanOrEqualToPredicateOperatorType; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 193 "rules.y"
    { (yyval.operatorType) = NSContainsPredicateOperatorType; }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 194 "rules.y"
    { (yyval.operatorType) = NSInPredicateOperatorType; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 195 "rules.y"
    { (yyval.operatorType) = NSBeginsWithPredicateOperatorType; }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 196 "rules.y"
    { (yyval.operatorType) = NSEndsWithPredicateOperatorType; }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 197 "rules.y"
    { (yyval.operatorType) = NSLikePredicateOperatorType; }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 198 "rules.y"
    { (yyval.operatorType) = NSMatchesPredicateOperatorType; }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 202 "rules.y"
    {(yyval.expression) = (yyvsp[(2) - (3)].expression);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 204 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 206 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 208 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 210 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 212 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 215 "rules.y"
    {(yyval.comparisonS).lhs = (yyvsp[(1) - (3)].expression); (yyval.comparisonS).rhs = (yyvsp[(3) - (3)].expression);  (yyval.comparisonS).options = (yyvsp[(2) - (3)].operatorR).options; (yyval.comparisonS).type = (yyvsp[(2) - (3)].operatorR).type;}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 219 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"multiply:second:" arguments:[NSArray arrayWithObjects:[NSExpression expressionForConstantValue:[NSNumber numberWithInt:-1]],(yyvsp[(2) - (2)].expression),nil]];}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 220 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"plus:second:" arguments:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),nil]];}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 221 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"minus:second:" arguments:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),nil]];}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 222 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"multiply:second:" arguments:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),nil]];}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 223 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"divideBy:second:" arguments:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),nil]];}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 224 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:@"exp:to:" arguments:[NSArray arrayWithObjects:(yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),nil]];}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 227 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:(yyvsp[(1) - (4)].string) arguments:(yyvsp[(3) - (4)].array)]; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 229 "rules.y"
    {(yyval.expression) = [NSExpression expressionForFunction:(yyvsp[(1) - (3)].string) arguments:nil]; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 232 "rules.y"
    { (yyval.array) = [NSMutableArray arrayWithObject:(yyvsp[(1) - (1)].expression)]; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 233 "rules.y"
    { [(yyvsp[(1) - (3)].array) addObject:(yyvsp[(3) - (3)].expression)]; (yyval.array) = (yyvsp[(1) - (3)].array); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 237 "rules.y"
    {(yyval.expression) = [NSExpression expressionForConstantValue:(yyvsp[(1) - (1)].number)];}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 238 "rules.y"
    {(yyval.expression) = [NSExpression expressionForConstantValue:[NSNull null]];}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 239 "rules.y"
    {(yyval.expression) = [NSExpression expressionForConstantValueTrue];}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 240 "rules.y"
    {(yyval.expression) = [NSExpression expressionForConstantValueFalse];}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 241 "rules.y"
    {(yyval.expression) = [NSExpression expressionForEvaluatedObject];}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 242 "rules.y"
    {(yyval.expression) = [NSExpression expressionForConstantValue:(yyvsp[(1) - (1)].string)];}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 243 "rules.y"
    {(yyval.expression) = [NSExpression expressionForVariable:(yyvsp[(1) - (1)].string)];}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 244 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 247 "rules.y"
    {(yyval.string) = (yyvsp[(2) - (2)].string);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 250 "rules.y"
    {(yyval.expression) = (yyvsp[(2) - (2)].expression);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 253 "rules.y"
    {(yyval.expression) = nextArg((yyvsp[(1) - (1)].string)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 254 "rules.y"
    {(yyval.expression) = nextArg((yyvsp[(1) - (1)].string));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 257 "rules.y"
    {(yyval.expression) = [[[NSExpressionVariable alloc] initWithVariableName:(yyvsp[(1) - (3)].string) expression:(yyvsp[(3) - (3)].expression)] autorelease]; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 260 "rules.y"
    { (yyval.expression) = [NSExpression expressionForKeyPath:(yyvsp[(1) - (1)].string)]; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 261 "rules.y"
    { (yyval.expression) = [NSExpression expressionForKeyPath:[(yyvsp[(1) - (2)].string) stringByAppendingString:(yyvsp[(2) - (2)].string)]]; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 262 "rules.y"
    { (yyval.expression) = [NSExpression expressionforKeyValueAccess:(yyvsp[(3) - (3)].expression) leftExpression:(yyvsp[(1) - (3)].expression)]; }
    break;


/* Line 1792 of yacc.c  */
#line 1951 "rules.tab.c"
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
      yyerror (scanner, nextArg, predicate, YY_("syntax error"));
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
        yyerror (scanner, nextArg, predicate, yymsgp);
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
		      yytoken, &yylval, scanner, nextArg, predicate);
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
		  yystos[yystate], yyvsp, scanner, nextArg, predicate);
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
  yyerror (scanner, nextArg, predicate, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner, nextArg, predicate);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, scanner, nextArg, predicate);
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


/* Line 2055 of yacc.c  */
#line 264 "rules.y"
 

void yyerror(yyscan_t scanner, nextArgument nextArg, NSPredicate **predicate, const char *error)
{
    [NSException raise:NSInvalidArgumentException format:@"Unable to parse: %s", error];
}




static  NSPredicate *_parsePredicateFormatString(NSString *format, nextArgument nextArg)
{
    const char *formatBytes = [format UTF8String];

    yyscan_t lexer;
    YY_BUFFER_STATE state;
    //Need to call into lexer for init.
    lexer_init(formatBytes, &lexer, &state);

    NSPredicate *predicate = nil;
    yyparse(lexer, nextArg,&predicate);

    lexer_destroy(lexer, state);

    return predicate;
}