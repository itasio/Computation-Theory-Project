/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "myparser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
  	#include "cgen.h"
	#define MAX_COMPS 100 	//number of comp types permitted in ka language
	extern int yylex(void);
	int isStr = 0;	//used for multiple variables declaration in one line
	char expression[100], toBeReplaced[100], replacer[100];		//for list comprehension
	void replaceWord(char* str, char* oldWord, char* newWord);
	char* comps[MAX_COMPS];	//name of comp types will be stored here
	int numOfComps = 1;
	int isComp = 0; // used for Comp type variables
	char* temp;		//used to temporarily store name of an Adress(multiple var decl per line)
	int find_comp(char* compToSearch);



#line 90 "myparser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MYPARSER_TAB_H_INCLUDED
# define YY_YY_MYPARSER_TAB_H_INCLUDED
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
    TK_IDENT = 258,
    TK_CONSTINT = 259,
    TK_CONSTFLOAT = 260,
    TK_CONSTSTR = 261,
    TK_POW = 262,
    TK_PLUEQ = 263,
    TK_MINEQ = 264,
    TK_MULEQ = 265,
    TK_DIVEQ = 266,
    TK_MODEQ = 267,
    TK_EQEQ = 268,
    TK_NOTEQ = 269,
    TK_GREEQ = 270,
    TK_LESEQ = 271,
    TK_COLEQ = 272,
    TK_FUNC_RET = 273,
    KW_AND = 274,
    KW_OR = 275,
    KW_NOT = 276,
    KW_INTEGER = 277,
    KW_FOR = 278,
    KW_BREAK = 279,
    KW_DEF = 280,
    KW_ENDCOMP = 281,
    KW_SCALAR = 282,
    KW_CONST = 283,
    KW_IN = 284,
    KW_CONTINUE = 285,
    KW_ENDDEF = 286,
    KW_OF = 287,
    KW_STR = 288,
    KW_IF = 289,
    KW_ENDFOR = 290,
    KW_MAIN = 291,
    KW_BOOLEAN = 292,
    KW_ELSE = 293,
    KW_WHILE = 294,
    KW_RETURN = 295,
    KW_ENDIF = 296,
    KW_ENDWHILE = 297,
    KW_COMP = 298,
    KW_TRUE = 299,
    KW_FALSE = 300,
    UMINUS = 301,
    UPLUS = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "myparser.y"

	char* str;

#line 194 "myparser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      57,    58,    51,    49,    63,    50,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    62,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
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
      45,    54,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    93,    94,    95,   100,   101,   105,   106,
     107,   111,   112,   113,   114,   119,   120,   124,   125,   126,
     127,   128,   133,   134,   138,   139,   143,   144,   148,   149,
     150,   151,   152,   153,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   185,   186,   187,   188,   189,
     195,   196,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   219,   220,
     221,   225,   226,   227,   228,   229,   230,   237,   238,   242,
     243,   244,   245,   249,   254,   268,   269,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   286,   287,   291,   292,
     296,   300,   301,   305,   306,   307,   311,   319,   329,   337,
     347,   358,   371,   372,   373,   374,   375
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_IDENT", "TK_CONSTINT",
  "TK_CONSTFLOAT", "TK_CONSTSTR", "TK_POW", "TK_PLUEQ", "TK_MINEQ",
  "TK_MULEQ", "TK_DIVEQ", "TK_MODEQ", "TK_EQEQ", "TK_NOTEQ", "TK_GREEQ",
  "TK_LESEQ", "TK_COLEQ", "TK_FUNC_RET", "KW_AND", "KW_OR", "KW_NOT",
  "KW_INTEGER", "KW_FOR", "KW_BREAK", "KW_DEF", "KW_ENDCOMP", "KW_SCALAR",
  "KW_CONST", "KW_IN", "KW_CONTINUE", "KW_ENDDEF", "KW_OF", "KW_STR",
  "KW_IF", "KW_ENDFOR", "KW_MAIN", "KW_BOOLEAN", "KW_ELSE", "KW_WHILE",
  "KW_RETURN", "KW_ENDIF", "KW_ENDWHILE", "KW_COMP", "KW_TRUE", "KW_FALSE",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS",
  "UPLUS", "'.'", "'('", "')'", "'['", "']'", "':'", "';'", "','",
  "$accept", "program", "main_block", "function_param_decl",
  "function_return_type", "function_blocks", "function_block",
  "function_call_no_assgn", "func_param_call", "listofexpr", "expr",
  "listofinstructions", "statements", "statement", "fict_token",
  "if_statement", "while_statement", "for_statement",
  "listCompr_with_int_values", "listCompr_with_array",
  "const_declarations", "const_declaration", "var_declarations",
  "var_declaration", "one_var", "multi_var", "multi_var_3", "multi_var_2",
  "multi_var_1", "data_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    61,    60,    62,    43,
      45,    42,    47,    37,   301,   302,    46,    40,    41,    91,
      93,    58,    59,    44
};
# endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     175,   -33,    39,    24,    50,   -99,    41,    19,    20,    55,
      10,    62,   -99,   -99,   -99,   -99,   -99,     3,    12,   127,
      77,    88,   110,   -99,   -99,   112,   -99,   122,    10,   -99,
     191,    41,   143,   -99,   156,    46,   -99,   -99,   -99,   -99,
     -99,   -99,    94,   -99,   222,   169,   650,   -99,   -99,    41,
     -99,   -99,   119,    12,   225,    12,   -38,   -99,   170,   172,
     185,   186,   190,   194,   207,   210,   -99,    12,   236,   -99,
     198,   -99,   -99,    -6,   222,   214,   237,   242,   230,   227,
     234,   212,   213,   223,   232,   -99,   216,   -99,   244,   259,
     226,   249,   -99,   118,   284,   250,   252,   253,   241,   264,
     -99,   254,   291,   419,   -99,   178,   261,   265,   271,   272,
     274,   279,   279,   -99,   -99,   -99,   -99,   -99,   315,   312,
     318,   316,   340,   138,   -99,   -99,   -99,   -99,   289,   101,
     255,   294,   657,     7,   328,   -99,   -99,   -99,   737,   737,
     -99,   298,    14,   -99,   737,   737,   737,   737,   737,   737,
     737,   -99,   -99,   -99,   -99,   -99,   419,   445,   419,   296,
     -99,   -99,   -99,   -99,   305,    12,   336,   -99,   306,   737,
     329,   737,    42,   -99,   -99,   -99,   737,   -99,   -99,   737,
     737,   737,   -99,   -99,    86,   896,   311,   313,   319,   677,
     896,   687,   -99,    40,   447,   473,   497,   523,   547,   573,
      48,   419,   419,   141,   -99,   -99,   341,   597,   737,   885,
     737,   953,     1,     1,   838,   -99,   737,   737,   737,   737,
     737,   737,   737,   737,   737,   737,   737,   737,   737,   737,
     737,   737,   -99,   119,   737,   327,   896,   330,   317,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,    12,   -99,   349,   623,
     383,   776,   -99,   896,     1,   924,   924,    87,    87,   953,
     906,    87,    87,    95,    95,     1,     1,     1,   -99,   754,
      38,   238,   -99,   -99,   -99,   364,   343,   -99,   737,   347,
     -99,   267,   -99,   308,   -99,    92,   704,   322,   348,   -99,
     -99,   342,   372,   355,   737,   -99,   325,   351,   356,   415,
     359,   824,   -99,   -99,   373,    12,   388,   -99,   376,   362,
     -99,   -99,   420,   -99,   402,   367,   -99,   416,   368,   -99,
      12,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,   108,   109,   115,   114,   113,     0,     0,     0,
       0,     0,     0,     1,     3,     0,    15,     0,     0,    95,
       0,     0,     0,   106,     0,     0,   126,   122,   123,   124,
     125,   110,     0,   121,     8,     0,     0,    16,    96,     0,
       4,   107,     0,     0,     0,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,   112,
       0,   117,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   119,     0,     0,
       0,     0,    10,    78,     0,     0,     0,     0,     0,     0,
      77,     0,     0,    57,    60,     0,     0,     0,     0,     0,
       0,     0,     0,   100,    97,   103,   104,   105,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     6,     0,     0,
      74,     0,    78,    61,     0,     0,     0,     0,     0,     0,
       0,    69,    71,    70,    75,    76,    59,     0,    58,     0,
     101,    98,   102,    99,     0,     0,     0,    17,     0,     0,
       0,     0,    30,    28,    29,    31,     0,    33,    32,     0,
       0,     0,    23,    54,     0,    24,     0,     0,     0,     0,
      26,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    55,     0,   116,    19,     0,     0,     0,     0,
       0,    36,    50,    49,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    79,     0,     0,    27,     0,     0,    63,
      64,    65,    67,    66,    68,    62,     0,    18,     0,     0,
       0,     0,    51,    25,    48,    38,    37,    40,    39,    35,
      34,    41,    42,    43,    44,    45,    46,    47,    53,     0,
       0,     0,    79,   118,    21,     0,     0,    52,     0,     0,
      82,     0,    88,     0,    20,     0,     0,     0,     0,    81,
      87,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,    92,     0,     0,
      83,    93,     0,    91,     0,     0,    90,     0,     0,    89,
       0,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,    15,   -99,   -99,     8,    16,   -74,   -99,   -24,
     -58,   -71,   -79,   -98,   -99,   -99,   -99,   -99,   -99,   -99,
       4,    -5,     9,    -4,   -99,   -99,   374,   363,   411,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    56,    91,     6,     7,   183,   184,   189,
     190,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     9,   112,    11,    12,    13,    14,    15,    16,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,   101,    72,    27,     8,   143,    32,    34,   217,    10,
     186,   187,    89,     1,    85,    36,   101,    28,    31,   129,
      73,    24,    25,     1,    32,    74,    17,    22,    18,   101,
      19,   131,   156,   158,    37,    30,    49,   101,   101,    38,
      57,   142,    20,   186,   238,    39,    50,    25,     3,    40,
      23,   172,   173,   174,   175,    90,   101,   231,   143,   170,
     143,    94,    95,    35,    66,    25,     2,    35,    96,   176,
      92,   132,    98,   193,   185,    21,   279,    99,   201,   280,
     202,    26,   101,   101,   101,   101,   194,   195,   196,   197,
     198,   199,   177,   178,   217,    36,   291,   179,   180,   132,
     100,   210,   217,   143,   143,   181,    27,    53,    32,    54,
     245,   207,   204,   209,    37,   191,   159,    29,   211,    38,
     157,   212,   213,   214,    33,    39,   200,   101,   101,    40,
      42,   236,   167,   236,    44,   131,   226,   227,   228,   229,
     230,   168,   236,   231,   215,    45,   228,   229,   230,   216,
     249,   231,   251,    32,    27,    55,    46,    19,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    47,   132,   269,   133,     1,    18,
      67,    19,    68,   143,    48,   143,   144,   145,   146,   147,
     148,   281,   283,   273,    20,   149,   101,   101,   143,   165,
       2,    54,   246,     3,    68,    51,   143,   101,   296,   101,
     143,    81,    82,   101,    83,    84,    52,    93,   304,   143,
     286,   308,   101,   101,   150,     1,   101,    58,    70,    93,
     101,    75,   292,    76,   101,   317,   301,    94,    95,    86,
     101,   142,     3,   101,    96,    97,    77,    78,    98,    94,
      95,    79,   311,    99,     3,    80,    96,    88,    93,   113,
      98,    94,    95,   115,   116,    99,   128,   321,    96,   114,
     142,   117,    98,   118,   119,   122,   100,    99,    94,    95,
     282,   124,    93,     3,   120,    96,   125,   134,   100,    98,
      94,    95,   126,   121,    99,   169,   127,    96,   138,   142,
     100,    98,    94,    95,   123,   288,    99,     3,   289,    96,
     130,   142,   135,    98,   136,   137,   140,   100,    99,    94,
      95,   139,   141,   151,     3,   142,    96,   152,   142,   100,
      98,    94,    95,   153,   154,    99,   155,   160,    96,   161,
     162,   100,    98,   163,   164,    94,    95,    99,    94,    95,
     290,   166,    96,   171,   142,    96,    98,   188,   100,    98,
     192,    99,   142,   295,    99,   203,   302,   205,   206,   208,
     100,   232,   247,   233,    94,    95,   142,   272,   234,   142,
     274,    96,    94,    95,   100,    98,   276,   100,   270,    96,
      99,   271,   303,    98,   307,   284,    94,    95,    99,    94,
      95,   299,   298,    96,   285,   142,    96,    98,   287,   297,
      98,   313,    99,   100,   310,    99,   300,   305,   306,   142,
     312,   100,   142,   314,   315,    94,    95,   318,    71,   320,
      43,    87,    96,     0,     0,   100,    98,   316,   100,    94,
      95,    99,    94,    95,     0,     0,    96,     0,    93,    96,
      98,   319,     0,    98,   217,    99,     0,     0,    99,     0,
     218,   219,   220,   221,   100,     0,   222,   223,    94,    95,
       0,     0,     0,     0,     0,    96,     0,     0,   100,    98,
     217,   100,     0,     0,    99,     0,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,     0,     0,   231,   217,     0,     0,   100,     0,   239,
     218,   219,   220,   221,     0,     0,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,     0,     0,   231,
     217,     0,     0,     0,     0,   240,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,     0,     0,   231,   217,     0,     0,     0,     0,   241,
     218,   219,   220,   221,     0,     0,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,     0,     0,   231,
     217,     0,     0,     0,     0,   242,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,     0,     0,   231,   217,     0,     0,     0,     0,   243,
     218,   219,   220,   221,     0,     0,   222,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,     0,     0,   231,
     217,     0,     0,     0,     0,   244,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,     0,     0,   231,    59,    60,    61,     0,     0,   248,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
     224,   225,   226,   227,   228,   229,   230,     0,   176,   231,
     172,   173,   174,   175,     0,   275,     0,     0,     0,     0,
     172,   173,   174,   175,    62,    63,     0,     0,   176,    64,
      65,   177,   178,     0,     0,     0,   179,   180,   176,     0,
       0,   217,     0,     0,   181,   182,     0,   218,   219,   220,
     221,   177,   178,   222,   223,     0,   179,   180,     0,     0,
       0,   177,   178,     0,   181,   235,   179,   180,     0,     0,
     172,   173,   174,   175,   181,   237,     0,     0,     0,     0,
       0,   224,   225,   226,   227,   228,   229,   230,   176,     0,
     231,   217,     0,     0,   293,   294,     0,   218,   219,   220,
     221,     0,     0,   222,   223,     0,     0,     0,     0,     0,
       0,   177,   178,   217,     0,     0,   179,   180,     0,   218,
     219,   220,   221,     0,   181,   222,   223,     0,     0,     0,
       0,   224,   225,   226,   227,   228,   229,   230,     0,     0,
     231,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,     0,     0,   224,   225,   226,   227,   228,   229,   230,
       0,   217,   231,     0,     0,     0,   277,   218,   219,   220,
     221,     0,     0,   222,   223,   217,     0,     0,     0,     0,
       0,   218,   219,   220,   221,     0,     0,   222,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,   225,   226,   227,   228,   229,   230,     0,     0,
     231,     0,     0,     0,   309,   224,   225,   226,   227,   228,
     229,   230,   217,     0,   231,     0,   252,     0,   218,   219,
     220,   221,     0,   217,   222,   223,     0,     0,   250,   218,
     219,   220,   221,   217,     0,   222,   223,     0,     0,   218,
     219,   220,   221,     0,     0,   222,     0,     0,     0,     0,
       0,   217,   224,   225,   226,   227,   228,   229,   230,   220,
     221,   231,     0,   224,   225,   226,   227,   228,   229,   230,
       0,     0,   231,   224,   225,   226,   227,   228,   229,   230,
     217,     0,   231,     0,     0,     0,   218,   219,   220,   221,
       0,   224,   225,   226,   227,   228,   229,   230,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   225,   226,   227,   228,   229,   230,     0,     0,   231
};

static const yytype_int16 yycheck[] =
{
      53,    75,    55,     8,     0,   103,    10,     4,     7,     0,
       3,     4,    18,     3,    67,     3,    90,     8,    10,    90,
      58,     6,     6,     3,    28,    63,    59,     3,    61,   103,
      63,    17,   111,   112,    22,    25,    28,   111,   112,    27,
      44,     3,     3,     3,     4,    33,    31,    31,    28,    37,
       0,     3,     4,     5,     6,    61,   130,    56,   156,   130,
     158,    23,    24,    60,    49,    49,    25,    60,    30,    21,
      74,    57,    34,    59,   132,    36,    38,    39,   157,    41,
     159,    62,   156,   157,   158,   159,   144,   145,   146,   147,
     148,   149,    44,    45,     7,     3,     4,    49,    50,    57,
      62,    59,     7,   201,   202,    57,   111,    61,   112,    63,
      62,   169,   165,   171,    22,   139,   112,    62,   176,    27,
     111,   179,   180,   181,    62,    33,   150,   201,   202,    37,
       3,   189,    31,   191,    57,    17,    49,    50,    51,    52,
      53,    40,   200,    56,    58,    57,    51,    52,    53,    63,
     208,    56,   210,   157,   159,    61,    46,    63,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,    62,    57,   234,    59,     3,    61,
      61,    63,    63,   281,    62,   283,     8,     9,    10,    11,
      12,   270,   271,   246,     3,    17,   270,   271,   296,    61,
      25,    63,    61,    28,    63,    62,   304,   281,   287,   283,
     308,     4,     5,   287,     4,     5,    60,     3,   297,   317,
     278,   300,   296,   297,    46,     3,   300,    58,     3,     3,
     304,    61,   285,    61,   308,   314,   294,    23,    24,     3,
     314,     3,    28,   317,    30,    31,    61,    61,    34,    23,
      24,    61,   305,    39,    28,    61,    30,    59,     3,    22,
      34,    23,    24,    33,    37,    39,    40,   320,    30,    27,
       3,    37,    34,    61,    61,    59,    62,    39,    23,    24,
      42,    22,     3,    28,    61,    30,    27,     3,    62,    34,
      23,    24,    33,    61,    39,    40,    37,    30,    57,     3,
      62,    34,    23,    24,    60,    38,    39,    28,    41,    30,
      61,     3,    62,    34,    62,    62,    62,    62,    39,    23,
      24,    57,    31,    62,    28,     3,    30,    62,     3,    62,
      34,    23,    24,    62,    62,    39,    62,    22,    30,    27,
      22,    62,    34,    27,     4,    23,    24,    39,    23,    24,
      42,    62,    30,    59,     3,    30,    34,    29,    62,    34,
      62,    39,     3,    41,    39,    60,    41,    31,    62,    40,
      62,    60,    31,    60,    23,    24,     3,    60,    59,     3,
      31,    30,    23,    24,    62,    34,     3,    62,    61,    30,
      39,    61,    41,    34,    35,    31,    23,    24,    39,    23,
      24,    29,    60,    30,    61,     3,    30,    34,    61,    61,
      34,    35,    39,    62,    41,    39,    61,    61,     3,     3,
      32,    62,     3,    61,     4,    23,    24,    60,    54,    61,
      19,    68,    30,    -1,    -1,    62,    34,    35,    62,    23,
      24,    39,    23,    24,    -1,    -1,    30,    -1,     3,    30,
      34,    35,    -1,    34,     7,    39,    -1,    -1,    39,    -1,
      13,    14,    15,    16,    62,    -1,    19,    20,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    62,    34,
       7,    62,    -1,    -1,    39,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    62,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     4,     5,     6,    -1,    -1,    62,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    21,    56,
       3,     4,     5,     6,    -1,    62,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    44,    45,    -1,    -1,    21,    49,
      50,    44,    45,    -1,    -1,    -1,    49,    50,    21,    -1,
      -1,     7,    -1,    -1,    57,    58,    -1,    13,    14,    15,
      16,    44,    45,    19,    20,    -1,    49,    50,    -1,    -1,
      -1,    44,    45,    -1,    57,    58,    49,    50,    -1,    -1,
       3,     4,     5,     6,    57,    58,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    21,    -1,
      56,     7,    -1,    -1,    60,    61,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,     7,    -1,    -1,    49,    50,    -1,    13,
      14,    15,    16,    -1,    57,    19,    20,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,     7,    56,    -1,    -1,    -1,    60,    13,    14,    15,
      16,    -1,    -1,    19,    20,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    60,    47,    48,    49,    50,    51,
      52,    53,     7,    -1,    56,    -1,    58,    -1,    13,    14,
      15,    16,    -1,     7,    19,    20,    -1,    -1,    23,    13,
      14,    15,    16,     7,    -1,    19,    20,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,     7,    47,    48,    49,    50,    51,    52,    53,    15,
      16,    56,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    47,    48,    49,    50,    51,    52,    53,
       7,    -1,    56,    -1,    -1,    -1,    13,    14,    15,    16,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    25,    28,    65,    66,    69,    70,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    59,    61,    63,
       3,    36,     3,     0,    66,    70,    62,    85,    86,    62,
      25,    69,    87,    62,     4,    60,     3,    22,    27,    33,
      37,    93,     3,    92,    57,    57,    46,    62,    62,    69,
      66,    62,    60,    61,    63,    61,    67,    87,    58,     4,
       5,     6,    44,    45,    49,    50,    66,    61,    63,    93,
       3,    90,    93,    58,    63,    61,    61,    61,    61,    61,
      61,     4,     5,     4,     5,    93,     3,    91,    59,    18,
      61,    68,    87,     3,    23,    24,    30,    31,    34,    39,
      62,    71,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    86,    22,    27,    33,    37,    37,    61,    61,
      61,    61,    59,    60,    22,    27,    33,    37,    40,    75,
      61,    17,    57,    59,     3,    62,    62,    62,    57,    57,
      62,    31,     3,    77,     8,     9,    10,    11,    12,    17,
      46,    62,    62,    62,    62,    62,    76,    86,    76,    84,
      22,    27,    22,    27,     4,    61,    62,    31,    40,    40,
      75,    59,     3,     4,     5,     6,    21,    44,    45,    49,
      50,    57,    58,    71,    72,    74,     3,     4,    29,    73,
      74,    73,    62,    59,    74,    74,    74,    74,    74,    74,
      73,    76,    76,    60,    93,    31,    62,    74,    40,    74,
      59,    74,    74,    74,    74,    58,    63,     7,    13,    14,
      15,    16,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    56,    60,    60,    59,    58,    74,    58,     4,    62,
      62,    62,    62,    62,    62,    62,    61,    31,    62,    74,
      23,    74,    58,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      61,    61,    60,    93,    31,    62,     3,    60,    61,    38,
      41,    76,    42,    76,    31,    61,    74,    61,    38,    41,
      42,     4,    93,    60,    61,    41,    76,    61,    60,    29,
      61,    74,    41,    41,    76,    61,     3,    35,    76,    60,
      41,    93,    32,    35,    61,     4,    35,    76,    60,    35,
      61,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     7,     8,     0,     1,
       3,     2,     2,     2,     2,     2,     3,     8,    10,     9,
      12,    11,     4,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     4,     3,     1,     3,     3,     1,     2,     2,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     4,
       4,     7,     6,    10,     9,     9,     8,     7,     6,    13,
      12,    11,    10,    11,    15,     2,     3,     6,     7,     7,
       6,     7,     7,     6,     6,     6,     2,     3,     1,     1,
       3,     6,     5,     1,     1,     1,     9,     5,    11,     6,
       5,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 92 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1720 "myparser.tab.c"
    break;

  case 3:
#line 93 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1726 "myparser.tab.c"
    break;

  case 4:
#line 94 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1732 "myparser.tab.c"
    break;

  case 5:
#line 95 "myparser.y"
                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1738 "myparser.tab.c"
    break;

  case 6:
#line 100 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1744 "myparser.tab.c"
    break;

  case 7:
#line 101 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1750 "myparser.tab.c"
    break;

  case 8:
#line 105 "myparser.y"
               {(yyval.str) = template("");}
#line 1756 "myparser.tab.c"
    break;

  case 9:
#line 106 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1762 "myparser.tab.c"
    break;

  case 10:
#line 107 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1768 "myparser.tab.c"
    break;

  case 11:
#line 111 "myparser.y"
                               {(yyval.str) = template("int");}
#line 1774 "myparser.tab.c"
    break;

  case 12:
#line 112 "myparser.y"
                                {(yyval.str) = template("double");}
#line 1780 "myparser.tab.c"
    break;

  case 13:
#line 113 "myparser.y"
                             {(yyval.str) = template("char*");}
#line 1786 "myparser.tab.c"
    break;

  case 14:
#line 114 "myparser.y"
                                  {(yyval.str) = template("int");}
#line 1792 "myparser.tab.c"
    break;

  case 15:
#line 119 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1798 "myparser.tab.c"
    break;

  case 16:
#line 120 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1804 "myparser.tab.c"
    break;

  case 17:
#line 124 "myparser.y"
                                                                                     {(yyval.str) = template("void %s(%s){\n%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1810 "myparser.tab.c"
    break;

  case 18:
#line 125 "myparser.y"
                                                                                                     {(yyval.str) = template("void %s(%s){\n%s\nreturn;\n}", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str));}
#line 1816 "myparser.tab.c"
    break;

  case 19:
#line 126 "myparser.y"
                                                                                   {(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));}
#line 1822 "myparser.tab.c"
    break;

  case 20:
#line 127 "myparser.y"
                                                                                                                                {(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1828 "myparser.tab.c"
    break;

  case 21:
#line 128 "myparser.y"
                                                                                                              {(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1834 "myparser.tab.c"
    break;

  case 22:
#line 133 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1840 "myparser.tab.c"
    break;

  case 23:
#line 134 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 1846 "myparser.tab.c"
    break;

  case 24:
#line 138 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1852 "myparser.tab.c"
    break;

  case 25:
#line 139 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1858 "myparser.tab.c"
    break;

  case 26:
#line 143 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1864 "myparser.tab.c"
    break;

  case 27:
#line 144 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1870 "myparser.tab.c"
    break;

  case 32:
#line 152 "myparser.y"
                        {(yyval.str) = template("0");}
#line 1876 "myparser.tab.c"
    break;

  case 33:
#line 153 "myparser.y"
                        {(yyval.str) = template("1");}
#line 1882 "myparser.tab.c"
    break;

  case 34:
#line 161 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1888 "myparser.tab.c"
    break;

  case 35:
#line 162 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1894 "myparser.tab.c"
    break;

  case 36:
#line 163 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1900 "myparser.tab.c"
    break;

  case 37:
#line 164 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1906 "myparser.tab.c"
    break;

  case 38:
#line 165 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1912 "myparser.tab.c"
    break;

  case 39:
#line 166 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1918 "myparser.tab.c"
    break;

  case 40:
#line 167 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1924 "myparser.tab.c"
    break;

  case 41:
#line 168 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1930 "myparser.tab.c"
    break;

  case 42:
#line 169 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1936 "myparser.tab.c"
    break;

  case 43:
#line 170 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1942 "myparser.tab.c"
    break;

  case 44:
#line 171 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1948 "myparser.tab.c"
    break;

  case 45:
#line 172 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1954 "myparser.tab.c"
    break;

  case 46:
#line 173 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1960 "myparser.tab.c"
    break;

  case 47:
#line 174 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1966 "myparser.tab.c"
    break;

  case 48:
#line 175 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1972 "myparser.tab.c"
    break;

  case 49:
#line 176 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 1978 "myparser.tab.c"
    break;

  case 50:
#line 177 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1984 "myparser.tab.c"
    break;

  case 51:
#line 178 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 1990 "myparser.tab.c"
    break;

  case 52:
#line 179 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1996 "myparser.tab.c"
    break;

  case 53:
#line 180 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2002 "myparser.tab.c"
    break;

  case 54:
#line 181 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2008 "myparser.tab.c"
    break;

  case 55:
#line 185 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2014 "myparser.tab.c"
    break;

  case 56:
#line 186 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2020 "myparser.tab.c"
    break;

  case 57:
#line 187 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2026 "myparser.tab.c"
    break;

  case 58:
#line 188 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2032 "myparser.tab.c"
    break;

  case 59:
#line 189 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2038 "myparser.tab.c"
    break;

  case 60:
#line 195 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2044 "myparser.tab.c"
    break;

  case 61:
#line 196 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2050 "myparser.tab.c"
    break;

  case 62:
#line 200 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2056 "myparser.tab.c"
    break;

  case 63:
#line 201 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2062 "myparser.tab.c"
    break;

  case 64:
#line 202 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2068 "myparser.tab.c"
    break;

  case 65:
#line 203 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2074 "myparser.tab.c"
    break;

  case 66:
#line 204 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2080 "myparser.tab.c"
    break;

  case 67:
#line 205 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2086 "myparser.tab.c"
    break;

  case 68:
#line 206 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2092 "myparser.tab.c"
    break;

  case 69:
#line 207 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2098 "myparser.tab.c"
    break;

  case 70:
#line 208 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2104 "myparser.tab.c"
    break;

  case 71:
#line 209 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2110 "myparser.tab.c"
    break;

  case 72:
#line 210 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2116 "myparser.tab.c"
    break;

  case 73:
#line 211 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2122 "myparser.tab.c"
    break;

  case 74:
#line 212 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2128 "myparser.tab.c"
    break;

  case 75:
#line 213 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2134 "myparser.tab.c"
    break;

  case 76:
#line 214 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2140 "myparser.tab.c"
    break;

  case 77:
#line 215 "myparser.y"
              {(yyval.str) = template("");}
#line 2146 "myparser.tab.c"
    break;

  case 78:
#line 219 "myparser.y"
                 { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2152 "myparser.tab.c"
    break;

  case 79:
#line 220 "myparser.y"
                                       {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2158 "myparser.tab.c"
    break;

  case 80:
#line 221 "myparser.y"
                                    {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2164 "myparser.tab.c"
    break;

  case 81:
#line 225 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2170 "myparser.tab.c"
    break;

  case 82:
#line 226 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2176 "myparser.tab.c"
    break;

  case 83:
#line 227 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2182 "myparser.tab.c"
    break;

  case 84:
#line 228 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2188 "myparser.tab.c"
    break;

  case 85:
#line 229 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2194 "myparser.tab.c"
    break;

  case 86:
#line 230 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2200 "myparser.tab.c"
    break;

  case 87:
#line 237 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2206 "myparser.tab.c"
    break;

  case 88:
#line 238 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2212 "myparser.tab.c"
    break;

  case 89:
#line 242 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2218 "myparser.tab.c"
    break;

  case 90:
#line 243 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2224 "myparser.tab.c"
    break;

  case 91:
#line 244 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2230 "myparser.tab.c"
    break;

  case 92:
#line 245 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2236 "myparser.tab.c"
    break;

  case 93:
#line 250 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2242 "myparser.tab.c"
    break;

  case 94:
#line 255 "myparser.y"
        {	strcpy(expression, (yyvsp[-11].str));
		strcpy(toBeReplaced, (yyvsp[-9].str));
		strcpy(replacer, (yyvsp[-5].str));
		strcat(replacer, "[");
		strcat(replacer, (yyvsp[-5].str));
		strcat(replacer, "_i]");
		//strcpy(replacer, $10);							//strcat($10,strcat("[", strcat( $10, "_i]")))
		replaceWord(expression, toBeReplaced, replacer);
		(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i)\n%s[%s_i] = %s", (yyvsp[0].str), (yyvsp[-14].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-14].str), (yyvsp[-5].str), expression);
		}
#line 2257 "myparser.tab.c"
    break;

  case 95:
#line 268 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2263 "myparser.tab.c"
    break;

  case 96:
#line 269 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2269 "myparser.tab.c"
    break;

  case 97:
#line 273 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2275 "myparser.tab.c"
    break;

  case 98:
#line 274 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2281 "myparser.tab.c"
    break;

  case 99:
#line 275 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2287 "myparser.tab.c"
    break;

  case 100:
#line 276 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2293 "myparser.tab.c"
    break;

  case 101:
#line 277 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2299 "myparser.tab.c"
    break;

  case 102:
#line 278 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2305 "myparser.tab.c"
    break;

  case 103:
#line 279 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2311 "myparser.tab.c"
    break;

  case 104:
#line 280 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2317 "myparser.tab.c"
    break;

  case 105:
#line 281 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2323 "myparser.tab.c"
    break;

  case 106:
#line 286 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2329 "myparser.tab.c"
    break;

  case 107:
#line 287 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2335 "myparser.tab.c"
    break;

  case 108:
#line 291 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2341 "myparser.tab.c"
    break;

  case 109:
#line 292 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2347 "myparser.tab.c"
    break;

  case 110:
#line 296 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2356 "myparser.tab.c"
    break;

  case 111:
#line 300 "myparser.y"
                                                     {(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));}
#line 2362 "myparser.tab.c"
    break;

  case 112:
#line 301 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2368 "myparser.tab.c"
    break;

  case 113:
#line 305 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2374 "myparser.tab.c"
    break;

  case 114:
#line 306 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2380 "myparser.tab.c"
    break;

  case 115:
#line 307 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2386 "myparser.tab.c"
    break;

  case 116:
#line 311 "myparser.y"
                                                            {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2399 "myparser.tab.c"
    break;

  case 117:
#line 319 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2411 "myparser.tab.c"
    break;

  case 118:
#line 329 "myparser.y"
                                                                                    {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2424 "myparser.tab.c"
    break;

  case 119:
#line 337 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									isStr = 0;
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2436 "myparser.tab.c"
    break;

  case 120:
#line 347 "myparser.y"
                                            {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											isStr = 0;
											if(isComp == 1){
											(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2452 "myparser.tab.c"
    break;

  case 121:
#line 358 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									isStr = 0;
									if(isComp == 1){
									(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2467 "myparser.tab.c"
    break;

  case 122:
#line 371 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0;}
#line 2473 "myparser.tab.c"
    break;

  case 123:
#line 372 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0;}
#line 2479 "myparser.tab.c"
    break;

  case 124:
#line 373 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0;}
#line 2485 "myparser.tab.c"
    break;

  case 125:
#line 374 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0;}
#line 2491 "myparser.tab.c"
    break;

  case 126:
#line 375 "myparser.y"
                   { if(find_comp((yyvsp[0].str)) == 1){
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 2504 "myparser.tab.c"
    break;


#line 2508 "myparser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 386 "myparser.y"

void replaceWord(char* str, char* oldWord, char* newWord)
{
	char *pos, temp[1000];
	int index = 0;
	int owlen;

	owlen = strlen(oldWord);

	// Repeat This loop until all occurrences are replaced.

	while ((pos = strstr(str, oldWord)) != NULL) {
		// Bakup current line
		strcpy(temp, str);

		// Index of current found word
		index = pos - str;

		// Terminate str after word found index
		str[index] = '\0';

		// Concatenate str with new word
		strcat(str, newWord);

		// Concatenate str with remaining words after
		// oldword found index.
		strcat(str, temp + index + owlen);
	}
}

int find_comp(char* compToSearch){
	for(int i = 0; i< numOfComps; i++){
		if(strcmp(compToSearch, comps[i]) == 0){
			temp = compToSearch;
			return 1;	//comp exists
		}
	}
	return 0; //comp does not exist
}

int main ()
{
	comps[0] = "Adress";
	yyparse();
}


