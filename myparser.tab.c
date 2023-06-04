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
	#define MAX_COMPS 100 	//number of comp types / functions permitted in ka language
	#define MAX_COMP_VARS 100 //number of variables permitted per comp in ka language
	#define MAX_CHARS_FOR_FUNCTIONS 3000	//number of characters permitted for .c functions being translated from .ka language 

	char expression[100], toBeReplaced[100], replacer[100];		//for list comprehension
	char comp_func_to_C[MAX_CHARS_FOR_FUNCTIONS];			//used for printinf struct functions after their declaration
	char helper_comp_func[500];	//used to store self functions (ctor)
	char* comps[MAX_COMPS];	//name of comp types will be stored here
	char* comp_vars[MAX_COMP_VARS];	//name of comp variables will be stored here for each comp, during comp declaration. After that elements will be erased. 
	char* comp_funcs[MAX_COMP_VARS];	//name of comp functions will be stored here for each comp, during comp declaration. After that elements will be erased. 
	char* temp;		//used to temporarily store name of a Comp(multiple var decl per line)
	char* comp_var_name;		//used to temporarily store name of a Comp variable
	
	int insideCompDecl = 0;	//used to indicate that we are inside a comp declaration. For function comp variables handling inside functions
	int numOfCompVars = 0; //num of variables per comp. Used in conjunction with comp_vars[MAX_COMP_VARS]
	int numOfCompFuncs = 0; //num of functions per comp. Used in conjunction with comp_funcs[MAX_COMP_VARS]
	
	int isStr = 0;	//used for multiple variables declaration in one line
	int numOfComps = 0;		//number of different Comp types declared in program
	int isComp = 0; // used for Comp type variables
	
	void replaceWord(char* str, char* oldWord, char* newWord);
	extern int yylex(void);
	int find_comp(char* compToSearch, char* whereToSearch);



#line 104 "myparser.tab.c"

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
#line 35 "myparser.y"

	char* str;

#line 208 "myparser.tab.c"

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  385

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
       2,     2,     2,     2,     2,    64,     2,    53,     2,     2,
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
       0,   108,   108,   109,   110,   111,   112,   116,   117,   121,
     122,   123,   127,   128,   129,   130,   135,   136,   140,   156,
     173,   174,   175,   180,   181,   185,   186,   190,   191,   195,
     196,   197,   202,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   234,   235,   236,
     237,   238,   244,   245,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     268,   272,   276,   280,   284,   288,   295,   296,   297,   298,
     299,   300,   307,   308,   312,   313,   314,   315,   319,   324,
     338,   339,   343,   371,   375,   376,   381,   382,   386,   387,
     388,   392,   401,   412,   421,   432,   444,   473,   474,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   491,   492,
     496,   497,   501,   507,   508,   512,   513,   514,   518,   524,
     533,   539,   548,   557,   569,   570,   571,   572,   573
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
  "UPLUS", "'.'", "'('", "')'", "'['", "']'", "':'", "';'", "','", "'#'",
  "$accept", "program", "main_block", "function_param_decl",
  "function_return_type", "function_blocks", "function_block",
  "function_call_no_assgn", "func_param_call", "listofexpr", "expr",
  "listofinstructions", "statements", "statement", "fict_token",
  "if_statement", "while_statement", "for_statement",
  "listCompr_with_int_values", "listCompr_with_array", "comp_declarations",
  "comp_declaration", "listof_comp_instructions", "comp_var_declarations",
  "comp_var_declaration", "comp_multi_var", "comp_multi_var_3",
  "comp_multi_var_2", "comp_multi_var_1", "const_declarations",
  "const_declaration", "var_declarations", "var_declaration", "one_var",
  "multi_var", "multi_var_3", "multi_var_2", "multi_var_1", "data_type", YY_NULLPTR
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
      93,    58,    59,    44,    35
};
# endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,    41,    18,    38,    55,    75,  -146,    61,    32,     9,
      39,    27,    69,    17,    74,  -146,  -146,  -146,  -146,  -146,
      13,   337,    87,    88,    93,   110,   121,  -146,  -146,   124,
    -146,   127,    27,  -146,   134,    17,  -146,   180,    61,   137,
    -146,   140,   -29,  -146,  -146,  -146,  -146,  -146,  -146,    58,
    -146,   203,   155,   148,   152,  -146,  -146,    17,  -146,    61,
    -146,  -146,    59,   337,   214,   337,   -25,  -146,   160,   163,
     164,   173,   176,   189,    67,   106,   238,   228,    -3,   194,
    -146,  -146,  -146,  -146,    61,  -146,   337,   254,  -146,   207,
    -146,  -146,   -11,   203,   184,   249,   246,   241,   247,   250,
     225,   227,   231,   233,    71,  -146,  -146,   271,   240,  -146,
    -146,  -146,   251,  -146,   248,   242,   267,   257,  -146,    66,
     308,   261,   262,   263,   273,   276,  -146,   325,   280,   312,
     616,  -146,   193,   282,   287,   288,   289,   290,   427,   427,
    -146,  -146,  -146,  -146,  -146,   331,   330,   336,   335,    22,
     301,  -146,   362,    80,  -146,  -146,  -146,  -146,   305,    28,
     370,   313,   255,    25,   347,  -146,  -146,  -146,   342,   342,
     320,  -146,   309,   -13,  -146,   342,   342,   342,   342,   342,
     342,   342,  -146,  -146,  -146,  -146,  -146,   616,   635,   616,
     441,  -146,  -146,  -146,  -146,   324,    94,   382,  -146,   343,
     337,   365,  -146,   345,   342,   371,   342,    85,  -146,  -146,
    -146,   342,  -146,  -146,   342,   342,   342,  -146,   402,  -146,
      45,  1087,   353,   354,   356,   277,  1087,   311,   171,  -146,
     187,   668,   687,   737,   753,   803,   819,   333,   616,   616,
     159,   363,   172,   179,  -146,  -146,   397,   869,   342,  1076,
     342,  1144,     4,     4,  1062,  -146,  -146,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,  -146,    59,   342,   372,  1087,   374,   376,
     377,   381,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   367,
     440,  -146,   337,   337,  -146,   417,   885,   443,  1000,  -146,
    1087,     4,   373,   373,   128,   128,  1144,  1134,   128,   128,
      36,    36,     4,     4,     4,  -146,   950,   378,   444,  -146,
    -146,  -146,   449,  -146,   399,  -146,  -146,  -146,   428,   401,
    -146,   342,   409,  -146,   415,  -146,   470,   404,   400,  -146,
     640,   935,   487,   411,  -146,  -146,   472,   186,   421,   453,
     423,   342,  -146,   499,   513,   425,   337,   426,   485,   532,
    1014,  -146,  -146,   550,   204,  -146,   337,   460,  -146,   569,
     434,  -146,   337,  -146,   492,  -146,   583,  -146,   437,  -146,
     602,   438,  -146,   337,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   137,   136,   135,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      16,     0,     0,   100,     0,     0,   117,     0,     0,     0,
     128,     0,     0,   148,   144,   145,   146,   147,   132,     0,
     143,     9,     0,     0,     0,    17,   101,     0,   118,     0,
       4,   129,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   110,   109,   108,     0,     5,     0,     0,   134,     0,
     139,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   102,   103,     0,   104,
       6,   133,     0,   141,     0,     0,     0,     0,    11,    80,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
      59,    62,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   119,   125,   126,   127,     0,     0,     0,     0,     0,
       0,   105,     0,     0,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,    74,    75,     7,     0,     0,
      81,    76,     0,    80,    63,     0,     0,     0,     0,     0,
       0,     0,    71,    73,    72,    77,    78,    61,     0,    60,
       0,   123,   120,   124,   121,     0,     0,     0,   116,     0,
       0,     0,    18,     0,     0,     0,     0,    31,    29,    30,
      33,     0,    35,    34,     0,     0,     0,    24,     0,    56,
       0,    25,     0,     0,     0,     0,    27,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    57,
       0,     0,     0,     0,   138,    20,     0,     0,     0,     0,
       0,    38,    52,    51,     0,    32,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    82,     0,     0,    28,     0,     0,
       0,     0,    65,    66,    67,    69,    68,    70,    64,     0,
       0,   112,     0,     0,    19,     0,     0,     0,     0,    53,
      26,    50,    40,    39,    42,    41,    37,    36,    43,    44,
      45,    46,    47,    48,    49,    55,     0,     0,     0,    85,
      83,    82,     0,   114,     0,   115,   140,    22,     0,     0,
      54,     0,     0,    87,     0,    93,     0,     0,     0,    21,
       0,     0,     0,     0,    86,    92,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,     0,     0,   111,     0,     0,    97,     0,
       0,    88,     0,    98,     0,    96,     0,   113,     0,    95,
       0,     0,    94,     0,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,     7,  -146,  -146,    -4,    11,   -91,  -146,  -145,
     -99,  -104,  -123,  -125,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,   489,  -146,  -146,   429,  -146,   260,   224,   364,     1,
      -5,     8,     0,   439,  -146,   454,   432,   498,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    66,   117,     7,     8,   219,   220,   225,
     226,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       9,    10,    77,    78,    79,    80,    81,    82,    83,   138,
      12,   139,    14,    15,    16,    17,    18,    19,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    11,    91,   128,   161,   174,    34,   115,    13,    38,
      32,   258,   159,    39,    28,   187,   189,    41,    29,    35,
       1,    23,    37,   111,   227,   128,   195,    34,   222,   223,
       1,    59,    63,    92,    64,    39,   237,     3,    93,   128,
      57,    25,    37,   258,   162,    60,   230,   128,   128,    29,
     116,    67,     4,    84,    24,     3,   205,    39,    26,   202,
     272,    76,   174,   221,   174,   238,    85,   239,   203,   128,
      29,   100,   101,    42,   107,    27,   231,   232,   233,   234,
     235,   236,   196,   161,     1,    42,     2,   269,   270,   271,
      49,   110,   272,   118,    30,    29,   128,   128,   128,   128,
      20,    33,    21,   256,    22,   247,     2,   249,   257,     3,
     102,   103,   251,   174,   174,   252,   253,   254,    29,    65,
      86,    22,    87,   162,     4,   163,   277,    21,   277,    22,
     149,    36,    21,    34,   150,   258,    40,   244,   277,    39,
     190,   200,   162,    64,   250,    51,   188,   128,   128,   296,
      52,   298,    69,    70,    71,    63,    53,   241,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   279,   280,   316,   267,   268,   269,
     270,   271,    54,    23,   272,    34,    55,   119,    39,    56,
     222,   281,    72,    73,   334,   336,    58,    74,    75,    61,
      62,   175,   176,   177,   178,   179,     1,   120,   121,   174,
     180,   174,     3,    68,   122,   123,    76,    89,   124,   353,
      86,    94,   289,   125,    95,    96,   128,   128,   174,   325,
     326,   363,   341,   292,    97,   150,   369,    98,   174,   181,
     293,   104,    87,   128,   174,   128,   126,   356,   127,   241,
      99,   128,   360,   380,   106,   174,   109,   112,   207,   208,
     209,   210,   128,   128,   154,   372,   114,   289,   128,   155,
     119,   140,   128,   141,   142,   156,   211,   349,   128,   157,
     207,   208,   209,   210,   143,   128,   145,   144,   146,   128,
     120,   121,   147,   365,   148,     3,    37,   122,   211,   212,
     213,   124,   151,   373,   214,   215,   125,   158,   153,   377,
     152,   164,   216,   217,   207,   208,   209,   210,   160,   218,
     384,   212,   213,   165,   166,   167,   214,   215,   170,   126,
     168,   127,   211,   169,   216,   276,   207,   208,   209,   210,
      43,   218,   171,   172,   182,   207,   208,   209,   210,   183,
     184,   185,   186,   191,   211,   212,   213,   192,   193,    44,
     214,   215,   194,   211,    45,   197,   199,   201,   216,   278,
      46,   229,   206,   119,    47,   218,   224,   212,   213,   228,
     258,   173,   214,   215,   240,   242,   212,   213,   261,   262,
     216,   214,   215,   120,   121,   288,   245,   218,     3,   216,
     122,   120,   121,   243,   124,   255,   218,   246,   122,   125,
     204,   248,   124,   273,   274,   275,   332,   125,   173,   333,
     265,   266,   267,   268,   269,   270,   271,   290,   294,   272,
     119,   322,   126,   317,   127,   318,   319,   320,   120,   121,
     126,   321,   127,   324,   173,   122,   329,   173,   327,   124,
     120,   121,   337,   343,   125,     3,   344,   122,   338,   339,
     347,   124,   340,   346,   120,   121,   125,   120,   121,     3,
     342,   122,   354,   173,   122,   124,   355,   126,   124,   127,
     125,   357,   358,   125,   359,   364,   335,   366,   367,   126,
     173,   127,   374,   120,   121,   376,   378,   381,    31,   383,
     122,   291,   173,   126,   124,   127,   126,   108,   127,   125,
     120,   121,   345,   323,   198,   105,   173,   122,    90,   113,
      50,   124,   120,   121,     0,     0,   125,     0,   352,   122,
       0,     0,   126,   124,   127,   173,   120,   121,   125,     0,
     361,     0,     0,   122,     0,     0,     0,   124,     0,   126,
       0,   127,   125,   173,   362,   120,   121,     0,     0,     0,
       0,   126,   122,   127,     0,     0,   124,   368,     0,     0,
       0,   125,   173,   120,   121,   126,     0,   127,     0,     0,
     122,     0,     0,     0,   124,     0,   173,     0,     0,   125,
       0,   371,   120,   121,   126,     0,   127,     0,     0,   122,
       0,     0,     0,   124,   375,   173,   120,   121,   125,     0,
       0,     0,   126,   122,   127,     0,     0,   124,   379,   173,
       0,     0,   125,     0,     0,   120,   121,     0,     0,     0,
       0,   126,   122,   127,     0,     0,   124,   382,   119,   120,
     121,   125,     0,    43,   348,   126,   122,   127,     0,     0,
     124,     0,     0,     0,     0,   125,     0,     0,   120,   121,
       0,     0,    44,     0,   126,   122,   127,    45,     0,   124,
       0,     0,     0,    46,   125,   258,     0,    47,   126,     0,
     127,   259,   260,   261,   262,     0,     0,   263,   264,     0,
       0,     0,     0,     0,   258,     0,     0,   126,     0,   127,
     259,   260,   261,   262,     0,     0,   263,   264,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,   268,   269,
     270,   271,     0,     0,   272,     0,     0,     0,     0,     0,
     282,     0,     0,     0,   265,   266,   267,   268,   269,   270,
     271,     0,     0,   272,   258,     0,     0,     0,     0,   283,
     259,   260,   261,   262,     0,     0,   263,   264,     0,     0,
     258,     0,     0,     0,     0,     0,   259,   260,   261,   262,
       0,     0,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,   268,   269,   270,
     271,     0,     0,   272,     0,     0,     0,     0,     0,   284,
     265,   266,   267,   268,   269,   270,   271,     0,     0,   272,
     258,     0,     0,     0,     0,   285,   259,   260,   261,   262,
       0,     0,   263,   264,     0,     0,   258,     0,     0,     0,
       0,     0,   259,   260,   261,   262,     0,     0,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,   268,   269,   270,   271,     0,     0,   272,
       0,     0,     0,     0,     0,   286,   265,   266,   267,   268,
     269,   270,   271,     0,     0,   272,   258,     0,     0,     0,
       0,   287,   259,   260,   261,   262,     0,     0,   263,   264,
       0,     0,   258,     0,     0,     0,     0,     0,   259,   260,
     261,   262,     0,     0,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,   268,
     269,   270,   271,     0,     0,   272,     0,     0,     0,     0,
       0,   295,   265,   266,   267,   268,   269,   270,   271,     0,
       0,   272,   258,     0,     0,     0,     0,   328,   259,   260,
     261,   262,     0,     0,   263,   264,     0,   258,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   267,   268,   269,   270,   271,     0,
       0,   272,     0,     0,     0,   350,   351,   265,   266,   267,
     268,   269,   270,   271,     0,     0,   272,   258,     0,     0,
       0,   331,     0,   259,   260,   261,   262,     0,     0,   263,
     264,   258,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
     268,   269,   270,   271,     0,     0,   272,     0,     0,     0,
     330,   265,   266,   267,   268,   269,   270,   271,     0,   258,
     272,     0,     0,     0,   370,   259,   260,   261,   262,     0,
       0,   263,   264,   258,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,   258,   263,   264,     0,     0,   297,
     259,   260,   261,   262,     0,     0,   263,   264,     0,   265,
     266,   267,   268,   269,   270,   271,     0,     0,   272,     0,
     299,     0,     0,   265,   266,   267,   268,   269,   270,   271,
       0,     0,   272,     0,   265,   266,   267,   268,   269,   270,
     271,   258,     0,   272,     0,     0,     0,   259,   260,   261,
     262,   258,     0,   263,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,   268,   269,   270,   271,     0,     0,
     272,   265,   266,   267,   268,   269,   270,   271,     0,     0,
     272
};

static const yytype_int16 yycheck[] =
{
      63,     0,    65,    94,    17,   130,    11,    18,     0,    13,
       9,     7,   116,    13,     7,   138,   139,     4,     7,    11,
       3,     3,    25,    86,   169,   116,     4,    32,     3,     4,
       3,    35,    61,    58,    63,    35,   181,    28,    63,   130,
      32,     3,    25,     7,    57,    38,    59,   138,   139,    38,
      61,    51,    43,    57,    36,    28,   160,    57,     3,    31,
      56,    64,   187,   162,   189,   188,    59,   190,    40,   160,
      59,     4,     5,    60,    78,     0,   175,   176,   177,   178,
     179,   180,    60,    17,     3,    60,    25,    51,    52,    53,
       3,    84,    56,    93,    62,    84,   187,   188,   189,   190,
      59,    62,    61,    58,    63,   204,    25,   206,    63,    28,
       4,     5,   211,   238,   239,   214,   215,   216,   107,    61,
      61,    63,    63,    57,    43,    59,   225,    61,   227,    63,
      59,    62,    61,   138,    63,     7,    62,   200,   237,   139,
     139,    61,    57,    63,    59,    57,   138,   238,   239,   248,
      57,   250,     4,     5,     6,    61,    46,    63,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,     3,     4,   275,    49,    50,    51,
      52,    53,    61,     3,    56,   190,    62,     3,   188,    62,
       3,     4,    44,    45,   317,   318,    62,    49,    50,    62,
      60,     8,     9,    10,    11,    12,     3,    23,    24,   334,
      17,   336,    28,    58,    30,    31,    64,     3,    34,   342,
      61,    61,    63,    39,    61,    61,   317,   318,   353,   292,
     293,   354,   331,    61,    61,    63,   359,    61,   363,    46,
      61,     3,    63,   334,   369,   336,    62,    61,    64,    63,
      61,   342,   351,   376,    26,   380,    62,     3,     3,     4,
       5,     6,   353,   354,    22,    61,    59,    63,   359,    27,
       3,    22,   363,    27,    33,    33,    21,   340,   369,    37,
       3,     4,     5,     6,    37,   376,    61,    37,    61,   380,
      23,    24,    61,   356,    61,    28,    25,    30,    21,    44,
      45,    34,    62,   366,    49,    50,    39,    40,    60,   372,
      59,     3,    57,    58,     3,     4,     5,     6,    61,    64,
     383,    44,    45,    62,    62,    62,    49,    50,     3,    62,
      57,    64,    21,    57,    57,    58,     3,     4,     5,     6,
       3,    64,    62,    31,    62,     3,     4,     5,     6,    62,
      62,    62,    62,    22,    21,    44,    45,    27,    22,    22,
      49,    50,    27,    21,    27,    64,     4,    62,    57,    58,
      33,    62,    59,     3,    37,    64,    29,    44,    45,    59,
       7,     3,    49,    50,    60,     3,    44,    45,    15,    16,
      57,    49,    50,    23,    24,    62,    31,    64,    28,    57,
      30,    23,    24,    60,    34,     3,    64,    62,    30,    39,
      40,    40,    34,    60,    60,    59,    38,    39,     3,    41,
      47,    48,    49,    50,    51,    52,    53,    64,    31,    56,
       3,    64,    62,    61,    64,    61,    60,    60,    23,    24,
      62,    60,    64,     3,     3,    30,     3,     3,    31,    34,
      23,    24,     3,    38,    39,    28,    41,    30,    59,    31,
      60,    34,    61,    59,    23,    24,    39,    23,    24,    28,
      61,    30,    61,     3,    30,    34,     4,    62,    34,    64,
      39,    60,    29,    39,    61,    60,    42,    61,     3,    62,
       3,    64,    32,    23,    24,    61,     4,    60,     9,    61,
      30,   241,     3,    62,    34,    64,    62,    78,    64,    39,
      23,    24,    42,   289,   150,    76,     3,    30,    64,    87,
      22,    34,    23,    24,    -1,    -1,    39,    -1,    41,    30,
      -1,    -1,    62,    34,    64,     3,    23,    24,    39,    -1,
      41,    -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    62,
      -1,    64,    39,     3,    41,    23,    24,    -1,    -1,    -1,
      -1,    62,    30,    64,    -1,    -1,    34,    35,    -1,    -1,
      -1,    39,     3,    23,    24,    62,    -1,    64,    -1,    -1,
      30,    -1,    -1,    -1,    34,    -1,     3,    -1,    -1,    39,
      -1,    41,    23,    24,    62,    -1,    64,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,     3,    23,    24,    39,    -1,
      -1,    -1,    62,    30,    64,    -1,    -1,    34,    35,     3,
      -1,    -1,    39,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    62,    30,    64,    -1,    -1,    34,    35,     3,    23,
      24,    39,    -1,     3,     4,    62,    30,    64,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    39,    -1,    -1,    23,    24,
      -1,    -1,    22,    -1,    62,    30,    64,    27,    -1,    34,
      -1,    -1,    -1,    33,    39,     7,    -1,    37,    62,    -1,
      64,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    62,    -1,    64,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    62,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,     7,    -1,    -1,    -1,    -1,    62,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,
      -1,    61,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      60,    47,    48,    49,    50,    51,    52,    53,    -1,     7,
      56,    -1,    -1,    -1,    60,    13,    14,    15,    16,    -1,
      -1,    19,    20,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,     7,    19,    20,    -1,    -1,    23,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      58,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    47,    48,    49,    50,    51,    52,
      53,     7,    -1,    56,    -1,    -1,    -1,    13,    14,    15,
      16,     7,    -1,    19,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    25,    28,    43,    66,    67,    70,    71,    85,
      86,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      59,    61,    63,     3,    36,     3,     3,     0,    67,    71,
      62,    86,    94,    62,    95,    96,    62,    25,    70,    97,
      62,     4,    60,     3,    22,    27,    33,    37,   103,     3,
     102,    57,    57,    46,    61,    62,    62,    96,    62,    70,
      67,    62,    60,    61,    63,    61,    68,    97,    58,     4,
       5,     6,    44,    45,    49,    50,    64,    87,    88,    89,
      90,    91,    92,    93,    70,    67,    61,    63,   103,     3,
     100,   103,    58,    63,    61,    61,    61,    61,    61,    61,
       4,     5,     4,     5,     3,    98,    26,    70,    89,    62,
      67,   103,     3,   101,    59,    18,    61,    69,    97,     3,
      23,    24,    30,    31,    34,    39,    62,    64,    72,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    94,    96,
      22,    27,    33,    37,    37,    61,    61,    61,    61,    59,
      63,    62,    59,    60,    22,    27,    33,    37,    40,    76,
      61,    17,    57,    59,     3,    62,    62,    62,    57,    57,
       3,    62,    31,     3,    78,     8,     9,    10,    11,    12,
      17,    46,    62,    62,    62,    62,    62,    77,    96,    77,
      94,    22,    27,    22,    27,     4,    60,    64,    93,     4,
      61,    62,    31,    40,    40,    76,    59,     3,     4,     5,
       6,    21,    44,    45,    49,    50,    57,    58,    64,    72,
      73,    75,     3,     4,    29,    74,    75,    74,    59,    62,
      59,    75,    75,    75,    75,    75,    75,    74,    77,    77,
      60,    63,     3,    60,   103,    31,    62,    75,    40,    75,
      59,    75,    75,    75,    75,     3,    58,    63,     7,    13,
      14,    15,    16,    19,    20,    47,    48,    49,    50,    51,
      52,    53,    56,    60,    60,    59,    58,    75,    58,     3,
       4,     4,    62,    62,    62,    62,    62,    62,    62,    63,
      64,    91,    61,    61,    31,    62,    75,    23,    75,    58,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    61,    61,    60,
      60,    60,    64,    92,     3,   103,   103,    31,    62,     3,
      60,    61,    38,    41,    77,    42,    77,     3,    59,    31,
      61,    75,    61,    38,    41,    42,    59,    60,     4,   103,
      60,    61,    41,    77,    61,     4,    61,    60,    29,    61,
      75,    41,    41,    77,    60,   103,    61,     3,    35,    77,
      60,    41,    61,   103,    32,    35,    61,   103,     4,    35,
      77,    60,    35,    61,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    84,
      85,    85,    86,    87,    88,    88,    89,    89,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     5,     7,     8,     0,
       1,     3,     2,     2,     2,     2,     2,     3,     8,    10,
       9,    12,    11,     4,     3,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     4,     3,     1,     3,     3,     1,
       2,     2,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     2,     4,     5,     4,     5,     7,     6,    10,     9,
       9,     8,     7,     6,    13,    12,    11,    10,    11,    15,
       2,     3,     5,     2,     2,     3,     2,     1,     1,     1,
       1,    11,     6,    13,     7,     7,     4,     2,     3,     6,
       7,     7,     6,     7,     7,     6,     6,     6,     2,     3,
       1,     1,     3,     6,     5,     1,     1,     1,     9,     5,
      11,     6,     5,     3,     1,     1,     1,     1,     1
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
#line 108 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1802 "myparser.tab.c"
    break;

  case 3:
#line 109 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1808 "myparser.tab.c"
    break;

  case 4:
#line 110 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1814 "myparser.tab.c"
    break;

  case 5:
#line 111 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1820 "myparser.tab.c"
    break;

  case 6:
#line 112 "myparser.y"
                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1826 "myparser.tab.c"
    break;

  case 7:
#line 116 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1832 "myparser.tab.c"
    break;

  case 8:
#line 117 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1838 "myparser.tab.c"
    break;

  case 9:
#line 121 "myparser.y"
               {(yyval.str) = template("");}
#line 1844 "myparser.tab.c"
    break;

  case 10:
#line 122 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1850 "myparser.tab.c"
    break;

  case 11:
#line 123 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1856 "myparser.tab.c"
    break;

  case 12:
#line 127 "myparser.y"
                               {(yyval.str) = template("int");}
#line 1862 "myparser.tab.c"
    break;

  case 13:
#line 128 "myparser.y"
                                {(yyval.str) = template("double");}
#line 1868 "myparser.tab.c"
    break;

  case 14:
#line 129 "myparser.y"
                             {(yyval.str) = template("char*");}
#line 1874 "myparser.tab.c"
    break;

  case 15:
#line 130 "myparser.y"
                                  {(yyval.str) = template("int");}
#line 1880 "myparser.tab.c"
    break;

  case 16:
#line 135 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1886 "myparser.tab.c"
    break;

  case 17:
#line 136 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1892 "myparser.tab.c"
    break;

  case 18:
#line 140 "myparser.y"
                                                                                     {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-6].str);
			numOfCompFuncs ++;
			if(strcmp((yyvsp[-4].str), "") == 0) (yyval.str) = template("void (*%s)(SELF);", (yyvsp[-6].str)); //empty parameters 
			else (yyval.str) = template("void (*%s)(SELF, %s);", (yyvsp[-6].str), (yyvsp[-4].str)); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, (yyvsp[-6].str)); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp((yyvsp[-4].str), "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, (yyvsp[-4].str)); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, (yyvsp[-1].str));   strcat(comp_func_to_C, "\n}\n");
		}else{
			(yyval.str) = template("void %s(%s){\n%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));
		}
	}
#line 1913 "myparser.tab.c"
    break;

  case 19:
#line 156 "myparser.y"
                                                                                                     {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-8].str);
			numOfCompFuncs ++;
			if(strcmp((yyvsp[-6].str), "") == 0) (yyval.str) = template("void (*%s)(SELF);", (yyvsp[-8].str)); //empty parameters 
			else (yyval.str) = template("void (*%s)(SELF, %s);", (yyvsp[-8].str), (yyvsp[-6].str)); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, (yyvsp[-8].str)); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp((yyvsp[-6].str), "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, (yyvsp[-6].str)); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, (yyvsp[-3].str));   strcat(comp_func_to_C, "\nreturn;\n}\n");
		}else{
			(yyval.str) = template("void %s(%s){\n%s\nreturn;\n}", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str));
		}
		
	}
#line 1935 "myparser.tab.c"
    break;

  case 20:
#line 173 "myparser.y"
                                                                                   {(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));}
#line 1941 "myparser.tab.c"
    break;

  case 21:
#line 174 "myparser.y"
                                                                                                                                {(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1947 "myparser.tab.c"
    break;

  case 22:
#line 175 "myparser.y"
                                                                                                              {(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1953 "myparser.tab.c"
    break;

  case 23:
#line 180 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1959 "myparser.tab.c"
    break;

  case 24:
#line 181 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 1965 "myparser.tab.c"
    break;

  case 25:
#line 185 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1971 "myparser.tab.c"
    break;

  case 26:
#line 186 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1977 "myparser.tab.c"
    break;

  case 27:
#line 190 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1983 "myparser.tab.c"
    break;

  case 28:
#line 191 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1989 "myparser.tab.c"
    break;

  case 31:
#line 197 "myparser.y"
                        {
				if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
							yyerror("Comp variables are preceded by # ");
				}else {(yyval.str) = template("%s", (yyvsp[0].str));}
				}
#line 1999 "myparser.tab.c"
    break;

  case 32:
#line 202 "myparser.y"
                        {
					if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
							(yyval.str) = template("self->%s", (yyvsp[0].str));
					}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
					}
#line 2009 "myparser.tab.c"
    break;

  case 34:
#line 208 "myparser.y"
                        {(yyval.str) = template("0");}
#line 2015 "myparser.tab.c"
    break;

  case 35:
#line 209 "myparser.y"
                        {(yyval.str) = template("1");}
#line 2021 "myparser.tab.c"
    break;

  case 36:
#line 210 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2027 "myparser.tab.c"
    break;

  case 37:
#line 211 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2033 "myparser.tab.c"
    break;

  case 38:
#line 212 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 2039 "myparser.tab.c"
    break;

  case 39:
#line 213 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2045 "myparser.tab.c"
    break;

  case 40:
#line 214 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2051 "myparser.tab.c"
    break;

  case 41:
#line 215 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2057 "myparser.tab.c"
    break;

  case 42:
#line 216 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2063 "myparser.tab.c"
    break;

  case 43:
#line 217 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2069 "myparser.tab.c"
    break;

  case 44:
#line 218 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2075 "myparser.tab.c"
    break;

  case 45:
#line 219 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2081 "myparser.tab.c"
    break;

  case 46:
#line 220 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2087 "myparser.tab.c"
    break;

  case 47:
#line 221 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2093 "myparser.tab.c"
    break;

  case 48:
#line 222 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2099 "myparser.tab.c"
    break;

  case 49:
#line 223 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2105 "myparser.tab.c"
    break;

  case 50:
#line 224 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2111 "myparser.tab.c"
    break;

  case 51:
#line 225 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 2117 "myparser.tab.c"
    break;

  case 52:
#line 226 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2123 "myparser.tab.c"
    break;

  case 53:
#line 227 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 2129 "myparser.tab.c"
    break;

  case 54:
#line 228 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2135 "myparser.tab.c"
    break;

  case 55:
#line 229 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2141 "myparser.tab.c"
    break;

  case 56:
#line 230 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2147 "myparser.tab.c"
    break;

  case 57:
#line 234 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2153 "myparser.tab.c"
    break;

  case 58:
#line 235 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2159 "myparser.tab.c"
    break;

  case 59:
#line 236 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2165 "myparser.tab.c"
    break;

  case 60:
#line 237 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2171 "myparser.tab.c"
    break;

  case 61:
#line 238 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2177 "myparser.tab.c"
    break;

  case 62:
#line 244 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2183 "myparser.tab.c"
    break;

  case 63:
#line 245 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2189 "myparser.tab.c"
    break;

  case 64:
#line 249 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2195 "myparser.tab.c"
    break;

  case 65:
#line 250 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2201 "myparser.tab.c"
    break;

  case 66:
#line 251 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2207 "myparser.tab.c"
    break;

  case 67:
#line 252 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2213 "myparser.tab.c"
    break;

  case 68:
#line 253 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2219 "myparser.tab.c"
    break;

  case 69:
#line 254 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2225 "myparser.tab.c"
    break;

  case 70:
#line 255 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2231 "myparser.tab.c"
    break;

  case 71:
#line 256 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2237 "myparser.tab.c"
    break;

  case 72:
#line 257 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2243 "myparser.tab.c"
    break;

  case 73:
#line 258 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2249 "myparser.tab.c"
    break;

  case 74:
#line 259 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2255 "myparser.tab.c"
    break;

  case 75:
#line 260 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2261 "myparser.tab.c"
    break;

  case 76:
#line 261 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2267 "myparser.tab.c"
    break;

  case 77:
#line 262 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2273 "myparser.tab.c"
    break;

  case 78:
#line 263 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2279 "myparser.tab.c"
    break;

  case 79:
#line 264 "myparser.y"
              {(yyval.str) = template("");}
#line 2285 "myparser.tab.c"
    break;

  case 80:
#line 268 "myparser.y"
                 { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
			   		yyerror("Comp variables are preceded by # ");
			   }else {(yyval.str) = template("%s", (yyvsp[0].str));}
			 }
#line 2294 "myparser.tab.c"
    break;

  case 81:
#line 272 "myparser.y"
                       { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
			   			(yyval.str) = template("self->%s", (yyvsp[0].str));
			   		}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		 }
#line 2303 "myparser.tab.c"
    break;

  case 82:
#line 276 "myparser.y"
                                        { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
									}
#line 2312 "myparser.tab.c"
    break;

  case 83:
#line 280 "myparser.y"
                                           {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
										}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2321 "myparser.tab.c"
    break;

  case 84:
#line 284 "myparser.y"
                                    { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
		}
#line 2330 "myparser.tab.c"
    break;

  case 85:
#line 288 "myparser.y"
                                        {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
									}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2339 "myparser.tab.c"
    break;

  case 86:
#line 295 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2345 "myparser.tab.c"
    break;

  case 87:
#line 296 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2351 "myparser.tab.c"
    break;

  case 88:
#line 297 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2357 "myparser.tab.c"
    break;

  case 89:
#line 298 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2363 "myparser.tab.c"
    break;

  case 90:
#line 299 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2369 "myparser.tab.c"
    break;

  case 91:
#line 300 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2375 "myparser.tab.c"
    break;

  case 92:
#line 307 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2381 "myparser.tab.c"
    break;

  case 93:
#line 308 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2387 "myparser.tab.c"
    break;

  case 94:
#line 312 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2393 "myparser.tab.c"
    break;

  case 95:
#line 313 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2399 "myparser.tab.c"
    break;

  case 96:
#line 314 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2405 "myparser.tab.c"
    break;

  case 97:
#line 315 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2411 "myparser.tab.c"
    break;

  case 98:
#line 320 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2417 "myparser.tab.c"
    break;

  case 99:
#line 325 "myparser.y"
        {	strcpy(expression, (yyvsp[-11].str));
		strcpy(toBeReplaced, (yyvsp[-9].str));
		strcpy(replacer, (yyvsp[-5].str));
		strcat(replacer, "[");
		strcat(replacer, (yyvsp[-5].str));
		strcat(replacer, "_i]");
		//strcpy(replacer, $10);
		replaceWord(expression, toBeReplaced, replacer);
		(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i)\n%s[%s_i] = %s", (yyvsp[0].str), (yyvsp[-14].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-14].str), (yyvsp[-5].str), expression);
		}
#line 2432 "myparser.tab.c"
    break;

  case 100:
#line 338 "myparser.y"
                             {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 2438 "myparser.tab.c"
    break;

  case 101:
#line 339 "myparser.y"
                                                 {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2444 "myparser.tab.c"
    break;

  case 102:
#line 344 "myparser.y"
        {	for(int i=0; i< numOfCompFuncs; i++){
			if(i>0) strcat(helper_comp_func, ", ");
			strcat(helper_comp_func, ".");
			strcat(helper_comp_func, comp_funcs[i]);
			strcat(helper_comp_func, "=");
			strcat(helper_comp_func, comp_funcs[i]);
		}
		(yyval.str) = template("#define SELF struct %s *self\ntypedef struct %s{\n%s\n}%s;\n\n%s\n\nconst %s ctor_%s = {%s};\n#undef SELF\n",(yyvsp[-3].str), (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[-3].str), comp_func_to_C, (yyvsp[-3].str), (yyvsp[-3].str), helper_comp_func);
		comps[numOfComps] = (yyvsp[-3].str);
		numOfComps++;
		insideCompDecl = 0;
		for(int i=numOfCompVars; i>=0; i--){
			comp_vars[i] = '\0';
		}
		numOfCompVars = 0;
		for(int i=numOfCompFuncs; i>=0; i--){
			comp_funcs[i] = '\0';
		}
		numOfCompFuncs = 0;
		strcpy(comp_func_to_C, "\0");
		strcpy(helper_comp_func, "\0");
	}
#line 2471 "myparser.tab.c"
    break;

  case 103:
#line 371 "myparser.y"
                                              {(yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2477 "myparser.tab.c"
    break;

  case 104:
#line 375 "myparser.y"
                                 {(yyval.str) = template("%s;", (yyvsp[-1].str)); insideCompDecl = 1;}
#line 2483 "myparser.tab.c"
    break;

  case 105:
#line 376 "myparser.y"
                                                         { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2489 "myparser.tab.c"
    break;

  case 106:
#line 381 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str)); comp_vars[numOfCompVars] = comp_var_name; numOfCompVars++;}
#line 2495 "myparser.tab.c"
    break;

  case 107:
#line 382 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2501 "myparser.tab.c"
    break;

  case 108:
#line 386 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2507 "myparser.tab.c"
    break;

  case 109:
#line 387 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2513 "myparser.tab.c"
    break;

  case 110:
#line 388 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2519 "myparser.tab.c"
    break;

  case 111:
#line 392 "myparser.y"
                                                                    {	if(isStr == 1){
																		(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
																	else{
																		(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
										comp_vars[numOfCompVars] = (yyvsp[-9].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										}
#line 2533 "myparser.tab.c"
    break;

  case 112:
#line 401 "myparser.y"
                                                     {	if(isStr == 1){
														(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
													else{
														(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										}
#line 2546 "myparser.tab.c"
    break;

  case 113:
#line 412 "myparser.y"
                                                                                            {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										comp_vars[numOfCompVars] = (yyvsp[-11].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
										}
#line 2560 "myparser.tab.c"
    break;

  case 114:
#line 421 "myparser.y"
                                                                {	if(isStr == 1){
																	(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
																else{
																	(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
								comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
								}
#line 2573 "myparser.tab.c"
    break;

  case 115:
#line 432 "myparser.y"
                                                    {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-2].str));
										}
										comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-2].str); numOfCompVars++;
										}
#line 2590 "myparser.tab.c"
    break;

  case 116:
#line 444 "myparser.y"
                                            {	if(isStr == 1){
												(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
											}
											else{
												if(isComp == 1){
													(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
												}else
												(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
											}
								comp_vars[numOfCompVars] = (yyvsp[-2].str); numOfCompVars++;
								}
#line 2606 "myparser.tab.c"
    break;

  case 117:
#line 473 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2612 "myparser.tab.c"
    break;

  case 118:
#line 474 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2618 "myparser.tab.c"
    break;

  case 119:
#line 478 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2624 "myparser.tab.c"
    break;

  case 120:
#line 479 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2630 "myparser.tab.c"
    break;

  case 121:
#line 480 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2636 "myparser.tab.c"
    break;

  case 122:
#line 481 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2642 "myparser.tab.c"
    break;

  case 123:
#line 482 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2648 "myparser.tab.c"
    break;

  case 124:
#line 483 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2654 "myparser.tab.c"
    break;

  case 125:
#line 484 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2660 "myparser.tab.c"
    break;

  case 126:
#line 485 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2666 "myparser.tab.c"
    break;

  case 127:
#line 486 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2672 "myparser.tab.c"
    break;

  case 128:
#line 491 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2678 "myparser.tab.c"
    break;

  case 129:
#line 492 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2684 "myparser.tab.c"
    break;

  case 130:
#line 496 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2690 "myparser.tab.c"
    break;

  case 131:
#line 497 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2696 "myparser.tab.c"
    break;

  case 132:
#line 501 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else{
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
							comp_var_name = (yyvsp[-2].str);	//maybe not a comp var, but i need it if it is
							 }
#line 2707 "myparser.tab.c"
    break;

  case 133:
#line 507 "myparser.y"
                                                     {	(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));	comp_var_name = (yyvsp[-5].str);}
#line 2713 "myparser.tab.c"
    break;

  case 134:
#line 508 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str)); comp_var_name = (yyvsp[-4].str);}
#line 2719 "myparser.tab.c"
    break;

  case 135:
#line 512 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2725 "myparser.tab.c"
    break;

  case 136:
#line 513 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2731 "myparser.tab.c"
    break;

  case 137:
#line 514 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2737 "myparser.tab.c"
    break;

  case 138:
#line 518 "myparser.y"
                                                            {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2748 "myparser.tab.c"
    break;

  case 139:
#line 524 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2759 "myparser.tab.c"
    break;

  case 140:
#line 533 "myparser.y"
                                                                                    {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2770 "myparser.tab.c"
    break;

  case 141:
#line 539 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2781 "myparser.tab.c"
    break;

  case 142:
#line 548 "myparser.y"
                                            {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2795 "myparser.tab.c"
    break;

  case 143:
#line 557 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2809 "myparser.tab.c"
    break;

  case 144:
#line 569 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2815 "myparser.tab.c"
    break;

  case 145:
#line 570 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0; isStr = 0;}
#line 2821 "myparser.tab.c"
    break;

  case 146:
#line 571 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0; isStr = 1;}
#line 2827 "myparser.tab.c"
    break;

  case 147:
#line 572 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2833 "myparser.tab.c"
    break;

  case 148:
#line 573 "myparser.y"
                   { isStr = 0;
					if(find_comp((yyvsp[0].str), "comps") == 1){		//allow Comp data_type only if it is already declared 
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 2847 "myparser.tab.c"
    break;


#line 2851 "myparser.tab.c"

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
#line 585 "myparser.y"

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

int find_comp(char* compToSearch, char* whereToSearch){
	if(strcmp(whereToSearch, "comps") == 0){	//search in list of comps declared
		for(int i = 0; i< numOfComps; i++){
			if(strcmp(compToSearch, comps[i]) == 0){
				temp = compToSearch;
				return 1;	//comp exists
			}
		}
		return 0; //comp does not exist
	}
	else if(strcmp(whereToSearch, "comp_vars") == 0){
		for(int i = 0; i< numOfCompVars; i++){
			if(strcmp(compToSearch, comp_vars[i]) == 0){
				return 1;	//comp var exists
			}
		}
		return 0; //comp does not exist
	}
	else{
		yyerror("Unknown Comp / Comp variable");
		return -1;
	}
}

int main ()
{
	comps[0] = "Adress";
	yyparse();
}


