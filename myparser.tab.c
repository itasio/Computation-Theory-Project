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
	char* all_comp_vars[MAX_COMP_VARS];	//name of all comp variables declared in .ka program
	char* all_comp_funcs[MAX_COMP_VARS];	//name of all comp functions declared in .ka program
	char* temp;		//used to temporarily store name of a Comp(multiple var decl per line)
	char* comp_var_name;		//used to temporarily store name of a Comp variable
	
	int insideCompDecl = 0;	//used to indicate that we are inside a comp declaration. For function comp variables handling inside functions
	int numOfCompVars = 0; //num of variables per comp. Used in conjunction with comp_vars[MAX_COMP_VARS]
	int numOfCompFuncs = 0; //num of functions per comp. Used in conjunction with comp_funcs[MAX_COMP_VARS]
	int numOfAllCompVars = 0;	//num of all variables declared in .ka program
	int numOfAllCompFuncs = 0;	//num of all functions declared in .ka program
	int isStr = 0;	//used for multiple variables declaration in one line
	int numOfComps = 0;		//number of different Comp types declared in program
	int isComp = 0; // used for Comp type variables
	
	void replaceWord(char* str, char* oldWord, char* newWord);
	extern int yylex(void);
	int find_comp(char* compToSearch, char* whereToSearch);



#line 107 "myparser.tab.c"

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
#line 38 "myparser.y"

	char* str;

#line 211 "myparser.tab.c"

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
#define YYLAST   1303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  408

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
       0,   111,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   125,   126,   130,   131,   132,   136,   144,
     145,   149,   167,   185,   203,   222,   244,   245,   249,   250,
     254,   255,   259,   260,   261,   266,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   305,   317,
     318,   322,   323,   324,   325,   326,   332,   333,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   358,   362,   372,   376,
     380,   384,   388,   392,   406,   407,   408,   409,   410,   411,
     418,   419,   423,   424,   425,   426,   430,   435,   449,   450,
     454,   482,   486,   487,   492,   496,   500,   501,   502,   506,
     517,   529,   540,   552,   566,   596,   597,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   614,   615,   619,   620,
     624,   630,   631,   635,   636,   637,   641,   647,   656,   662,
     671,   680,   692,   693,   694,   695,   696
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

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,    79,    93,    12,    26,    35,  -171,   -17,   -19,   197,
      39,    80,    49,   100,    52,  -171,  -171,  -171,  -171,  -171,
      27,   402,    94,    10,    77,    97,    37,  -171,  -171,    88,
    -171,  -171,   -17,    91,    74,   112,  -171,  -171,   -17,    95,
     112,  -171,  -171,   -17,   108,  -171,   122,   118,  -171,  -171,
    -171,  -171,  -171,  -171,   138,  -171,   136,   128,   307,   134,
    -171,  -171,  -171,   112,   212,   -17,  -171,  -171,   -17,  -171,
    -171,   148,   402,   215,   402,    63,  -171,   169,   176,   203,
     206,   211,   224,   157,   219,   289,   267,    16,   232,  -171,
    -171,  -171,  -171,   -17,  -171,  -171,   402,   292,  -171,   238,
    -171,  -171,     1,   136,   121,   276,   291,   283,   284,   288,
     271,   278,   279,   285,   143,  -171,  -171,   303,   275,  -171,
    -171,  -171,   286,  -171,   287,   402,    45,   293,  -171,   193,
     341,   297,   299,   300,   306,   315,  -171,   345,   302,   318,
     659,  -171,  1135,   311,   312,   314,   317,   320,   347,   347,
    -171,  -171,  -171,  -171,  -171,   361,   358,   381,   377,    29,
     354,  -171,   415,   153,  -171,   359,   -15,   296,   364,   114,
      18,   393,  -171,  -171,  -171,   411,   411,   367,  -171,   366,
      73,  -171,   411,   411,   411,   411,   411,   411,   411,   411,
    -171,  -171,  -171,  -171,  -171,   659,   681,   659,   461,  -171,
    -171,  -171,  -171,   373,   183,   433,  -171,   378,   402,   409,
    -171,   380,   411,   403,   411,   188,  -171,  -171,  -171,   411,
    -171,  -171,   411,   411,   411,  -171,   441,  -171,    64,  1190,
     387,   389,   447,   392,   163,  1190,   184,     8,  -171,    36,
     711,   733,   783,   799,   849,   865,   265,   391,  1169,   659,
     659,   198,   390,   202,   214,  -171,  -171,   426,   915,   411,
    1179,   411,  1247,     0,     0,  1122,   399,  -171,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,  -171,   148,   405,   411,   401,  1190,
     406,   414,   417,   460,   418,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,   411,   416,   463,  -171,   402,   402,  -171,
     450,   931,   479,  1046,  -171,   411,  1190,     0,   685,   685,
     124,   124,  1247,  1237,   124,   124,   141,   141,     0,     0,
       0,  -171,  -171,   996,   407,   473,  -171,  -171,   432,  -171,
     363,   483,  -171,   435,  -171,  -171,  -171,   467,   438,  -171,
    1060,   411,   440,  -171,   449,  -171,   506,  -171,  -171,   443,
     444,  -171,   254,  -171,   981,   519,   445,  -171,  -171,   501,
     217,   448,   481,   453,   411,  -171,   541,   554,   456,   402,
     457,   514,   576,  1108,  -171,  -171,   589,   221,  -171,   402,
     487,  -171,   611,   459,  -171,   402,  -171,   517,  -171,   624,
    -171,   464,  -171,   646,   465,  -171,   402,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   145,   144,   143,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      19,     6,     0,     0,     0,     0,   108,     5,     0,     0,
       0,   125,     4,     0,     0,   136,     0,     0,   156,   152,
     153,   154,   155,   140,     0,   151,    15,     0,     0,     0,
      20,     8,   109,     0,     0,     0,     7,   126,     0,     9,
     137,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     118,   117,   116,     0,    11,    10,     0,     0,   142,     0,
     147,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   110,   111,     0,   112,
      12,   141,     0,   149,     0,     0,     0,     0,    17,    86,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
      63,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   127,   133,   134,   135,     0,     0,     0,     0,     0,
       0,   113,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    13,     0,     0,    87,    77,     0,
      86,    67,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    80,    79,    83,    84,    65,     0,    64,     0,   131,
     128,   132,   129,     0,     0,     0,   124,     0,     0,     0,
      21,     0,     0,     0,     0,    34,    32,    33,    36,     0,
      38,    37,     0,     0,     0,    27,     0,    60,     0,    28,
       0,     0,     0,     0,     0,    30,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,    62,
      61,     0,     0,     0,     0,   146,    23,     0,     0,     0,
       0,     0,    41,    55,    54,     0,    35,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    88,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    69,    70,    71,    73,    72,
      74,    68,    75,     0,     0,     0,   120,     0,     0,    22,
       0,     0,     0,     0,    56,     0,    29,    53,    43,    42,
      45,    44,    40,    39,    46,    47,    48,    49,    50,    51,
      52,    59,    93,     0,     0,     0,    92,    89,     0,    88,
       0,     0,   122,     0,   123,   148,    25,     0,     0,    57,
       0,     0,     0,    95,     0,   101,     0,    91,    76,     0,
       0,    24,     0,    58,     0,     0,     0,    94,   100,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,     0,   119,     0,
       0,   105,     0,     0,    96,     0,   106,     0,   104,     0,
     121,     0,   103,     0,     0,   102,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,    23,  -171,  -171,    41,     6,  -103,  -171,  -170,
     119,   -61,  -139,  -137,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,   518,  -171,  -171,   446,  -171,   280,   227,   368,     5,
      -7,    17,     7,   454,  -171,   468,   437,   516,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    75,   127,     7,     8,   227,   228,   234,
     235,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       9,    10,    86,    87,    88,    89,    90,    91,    92,   148,
      12,   149,    14,    15,    16,    17,    18,    19,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   138,   101,   181,    39,    11,   236,   269,     2,   195,
     197,   291,   292,    29,    34,    25,   210,    13,   246,   125,
      44,   230,   231,   138,   121,   211,    35,    39,    40,    26,
      28,    46,    31,   203,    37,    27,    42,   138,    29,   230,
     294,    64,    44,    30,    29,   138,   138,    44,   129,    29,
      32,    63,    38,   164,    43,    61,   283,   249,   181,   250,
     181,    66,   126,    76,   138,   166,    69,    56,   130,   131,
      44,    29,   293,     3,    29,   132,    65,     1,    47,   134,
      85,    68,   232,     1,   135,   165,   247,    47,    94,   204,
     168,    95,   138,   138,   138,   138,    23,    54,    59,    29,
     232,    36,     3,     1,    93,     2,   213,   136,     3,   137,
     128,    41,   181,   181,    45,     1,   120,   215,   216,   217,
     218,   102,   267,    29,   129,     2,   103,   268,   117,    24,
     169,   269,   239,   340,    57,   219,   255,    64,    20,     1,
      21,    39,    22,    58,   130,   131,   138,   138,   269,     3,
      60,   132,   133,    62,   198,   134,    44,    67,   220,   221,
     135,   110,   111,   222,   223,   196,   215,   216,   217,   218,
      70,   224,   225,   278,   279,   280,   281,   282,   226,    72,
     283,    73,    71,   136,   219,   137,    77,   215,   216,   217,
     218,    39,   280,   281,   282,   354,   356,   283,    85,    74,
       1,    22,   159,    44,    21,   219,   160,   220,   221,    96,
     168,    97,   222,   223,   208,    23,    73,   181,    99,   181,
     224,   288,     2,   112,   113,     3,   376,   226,   220,   221,
     104,   138,   138,   222,   223,   344,   345,   105,   386,   181,
       4,   224,   290,   392,    72,   169,   252,   261,   226,   181,
     169,   138,   170,   138,    21,   181,    22,    48,   371,    96,
     403,   304,   138,   307,   106,   160,   181,   107,   215,   216,
     217,   218,   108,   138,   138,   308,    49,    97,   379,   138,
     252,    50,   395,   138,   304,   109,   219,    51,   229,   138,
     372,    52,   114,   116,   119,   122,   138,   124,   150,   129,
     138,   240,   241,   242,   243,   244,   245,   388,   248,   220,
     221,    78,    79,    80,   222,   223,   152,   396,   151,   130,
     131,   153,   224,   400,     3,   154,   132,   301,    64,   226,
     134,   258,   155,   260,   407,   135,   212,   161,   262,   156,
     157,   263,   264,   265,   171,   162,   158,   163,   177,   179,
     129,    81,    82,   289,   167,   289,    83,    84,   136,   172,
     137,   173,   174,   175,   178,   289,   215,   216,   217,   218,
     130,   131,   176,   190,   191,     3,   192,   132,   311,   193,
     313,   134,   194,   199,   219,   200,   135,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   201,   202,    48,   333,   220,   221,   136,
     180,   137,   222,   223,   215,   216,   217,   218,   205,   207,
     224,   209,   233,   214,    49,   358,   237,   226,   238,    50,
     130,   131,   219,   251,   350,    51,   253,   132,   254,    52,
     256,   134,   257,   259,   266,   352,   135,   284,   353,   285,
     286,   287,   180,   302,   305,   220,   221,   309,   315,   289,
     222,   223,   334,   338,   180,   332,   343,   335,   224,   136,
     364,   137,   130,   131,   336,   226,   180,   337,   339,   132,
     341,   346,   348,   134,   130,   131,   359,   366,   135,     3,
     367,   132,   357,   383,   360,   134,   130,   131,   361,   362,
     135,   365,   369,   132,   370,   378,   377,   134,   380,   180,
     381,   136,   135,   137,   382,   355,   387,   390,   389,   397,
     399,   401,   180,   136,   404,   137,   406,    33,   206,   130,
     131,   342,   306,   118,   123,   136,   132,   137,    55,   115,
     134,   100,   130,   131,   180,   135,     0,     0,   368,   132,
       0,     0,     0,   134,     0,     0,     0,   180,   135,     0,
     375,     0,     0,     0,   130,   131,     0,     0,   136,     0,
     137,   132,     0,     0,     0,   134,     0,   130,   131,   180,
     135,   136,   384,   137,   132,     0,     0,     0,   134,     0,
       0,     0,   180,   135,     0,   385,     0,     0,     0,   130,
     131,     0,     0,   136,     0,   137,   132,     0,     0,     0,
     134,   391,   130,   131,   180,   135,   136,     0,   137,   132,
       0,     0,     0,   134,     0,     0,     0,   180,   135,     0,
     394,     0,     0,     0,   130,   131,     0,     0,   136,     0,
     137,   132,     0,     0,     0,   134,   398,   130,   131,   180,
     135,   136,     0,   137,   132,     0,     0,     0,   134,   402,
       0,     0,   180,   135,     0,     0,     0,     0,     0,   130,
     131,     0,     0,   136,     0,   137,   132,     0,     0,     0,
     134,   405,   130,   131,   129,   135,   136,     0,   137,   132,
       0,     0,   269,   134,     0,     0,     0,     0,   135,     0,
     272,   273,     0,     0,   130,   131,     0,     0,   136,     0,
     137,   132,     0,     0,     0,   134,     0,     0,   269,     0,
     135,   136,     0,   137,   270,   271,   272,   273,     0,     0,
     274,   275,   276,   277,   278,   279,   280,   281,   282,     0,
     269,   283,     0,   136,     0,   137,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,     0,     0,   276,   277,
     278,   279,   280,   281,   282,     0,     0,   283,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,     0,   296,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   269,     0,     0,     0,
       0,     0,   270,   271,   272,   273,     0,     0,   274,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
       0,     0,     0,     0,     0,   297,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,     0,
       0,   298,   270,   271,   272,   273,     0,     0,   274,   275,
       0,     0,   269,     0,     0,     0,     0,     0,   270,   271,
     272,   273,     0,     0,   274,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,     0,     0,     0,     0,
       0,   299,   276,   277,   278,   279,   280,   281,   282,     0,
       0,   283,   269,     0,     0,     0,     0,   300,   270,   271,
     272,   273,     0,     0,   274,   275,     0,     0,   269,     0,
       0,     0,     0,     0,   270,   271,   272,   273,     0,     0,
     274,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   277,   278,   279,   280,   281,   282,     0,
       0,   283,     0,     0,     0,     0,     0,   310,   276,   277,
     278,   279,   280,   281,   282,     0,     0,   283,   269,     0,
       0,     0,     0,   347,   270,   271,   272,   273,     0,     0,
     274,   275,     0,   269,     0,     0,     0,     0,     0,   270,
     271,   272,   273,     0,     0,   274,   275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   277,
     278,   279,   280,   281,   282,     0,     0,   283,     0,     0,
       0,   373,   374,   276,   277,   278,   279,   280,   281,   282,
       0,     0,   283,   269,     0,     0,     0,   351,     0,   270,
     271,   272,   273,     0,     0,   274,   275,   269,     0,     0,
       0,     0,     0,   270,   271,   272,   273,     0,     0,   274,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,   277,   278,   279,   280,   281,   282,
       0,     0,   283,     0,     0,     0,   349,   276,   277,   278,
     279,   280,   281,   282,     0,   269,   283,     0,     0,     0,
     363,   270,   271,   272,   273,     0,     0,   274,   275,   269,
       0,     0,     0,     0,     0,   270,   271,   272,   273,     0,
       0,   274,   275,   182,   183,   184,   185,   186,     0,     0,
       0,     0,   187,     0,     0,   276,   277,   278,   279,   280,
     281,   282,     0,     0,   283,     0,     0,     0,   393,   276,
     277,   278,   279,   280,   281,   282,   269,     0,   283,     0,
     314,   188,   270,   271,   272,   273,   269,     0,   274,   275,
       0,   189,   270,   271,   272,   273,     0,   269,   274,   275,
       0,     0,   312,   270,   271,   272,   273,     0,     0,   274,
     275,     0,     0,     0,     0,   303,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,     0,   276,   277,   278,
     279,   280,   281,   282,   269,     0,   283,     0,     0,     0,
     270,   271,   272,   273,   269,     0,   274,     0,     0,     0,
     270,   271,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,   277,   278,   279,   280,   281,
     282,     0,     0,   283,   276,   277,   278,   279,   280,   281,
     282,     0,     0,   283
};

static const yytype_int16 yycheck[] =
{
      72,   104,    74,   140,    11,     0,   176,     7,    25,   148,
     149,     3,     4,     7,     9,     3,    31,     0,   188,    18,
      13,     3,     4,   126,    96,    40,     9,    34,    11,     3,
       7,     4,     9,     4,    11,     0,    13,   140,    32,     3,
       4,    25,    35,    62,    38,   148,   149,    40,     3,    43,
       9,    34,    11,   125,    13,    32,    56,   196,   195,   198,
     197,    38,    61,    56,   167,   126,    43,    57,    23,    24,
      63,    65,    64,    28,    68,    30,    35,     3,    60,    34,
      64,    40,    64,     3,    39,    40,   189,    60,    65,    60,
      17,    68,   195,   196,   197,   198,     3,     3,    61,    93,
      64,    62,    28,     3,    63,    25,   167,    62,    28,    64,
     103,    62,   249,   250,    62,     3,    93,     3,     4,     5,
       6,    58,    58,   117,     3,    25,    63,    63,    87,    36,
      57,     7,    59,   303,    57,    21,   208,    25,    59,     3,
      61,   148,    63,    46,    23,    24,   249,   250,     7,    28,
      62,    30,    31,    62,   149,    34,   149,    62,    44,    45,
      39,     4,     5,    49,    50,   148,     3,     4,     5,     6,
      62,    57,    58,    49,    50,    51,    52,    53,    64,    61,
      56,    63,    60,    62,    21,    64,    58,     3,     4,     5,
       6,   198,    51,    52,    53,   334,   335,    56,    64,    61,
       3,    63,    59,   196,    61,    21,    63,    44,    45,    61,
      17,    63,    49,    50,    61,     3,    63,   354,     3,   356,
      57,    58,    25,     4,     5,    28,   365,    64,    44,    45,
      61,   334,   335,    49,    50,   307,   308,    61,   377,   376,
      43,    57,    58,   382,    61,    57,    63,    59,    64,   386,
      57,   354,    59,   356,    61,   392,    63,     3,     4,    61,
     399,    63,   365,    61,    61,    63,   403,    61,     3,     4,
       5,     6,    61,   376,   377,    61,    22,    63,    61,   382,
      63,    27,    61,   386,    63,    61,    21,    33,   169,   392,
     362,    37,     3,    26,    62,     3,   399,    59,    22,     3,
     403,   182,   183,   184,   185,   186,   187,   379,   189,    44,
      45,     4,     5,     6,    49,    50,    33,   389,    27,    23,
      24,    37,    57,   395,    28,    37,    30,    62,    25,    64,
      34,   212,    61,   214,   406,    39,    40,    62,   219,    61,
      61,   222,   223,   224,     3,    59,    61,    60,     3,    31,
       3,    44,    45,   234,    61,   236,    49,    50,    62,    62,
      64,    62,    62,    57,    62,   246,     3,     4,     5,     6,
      23,    24,    57,    62,    62,    28,    62,    30,   259,    62,
     261,    34,    62,    22,    21,    27,    39,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    22,    27,     3,   287,    44,    45,    62,
       3,    64,    49,    50,     3,     4,     5,     6,    64,     4,
      57,    62,    29,    59,    22,    62,    59,    64,    62,    27,
      23,    24,    21,    60,   315,    33,     3,    30,    60,    37,
      31,    34,    62,    40,     3,    38,    39,    60,    41,    60,
       3,    59,     3,    62,    64,    44,    45,    31,    59,   340,
      49,    50,    61,     3,     3,    60,     3,    61,    57,    62,
     351,    64,    23,    24,    60,    64,     3,    60,    60,    30,
      64,    31,     3,    34,    23,    24,     3,    38,    39,    28,
      41,    30,    60,   374,    59,    34,    23,    24,    31,    61,
      39,    61,    59,    30,    60,     4,    61,    34,    60,     3,
      29,    62,    39,    64,    61,    42,    60,     3,    61,    32,
      61,     4,     3,    62,    60,    64,    61,     9,   160,    23,
      24,   304,   252,    87,    97,    62,    30,    64,    22,    85,
      34,    73,    23,    24,     3,    39,    -1,    -1,    42,    30,
      -1,    -1,    -1,    34,    -1,    -1,    -1,     3,    39,    -1,
      41,    -1,    -1,    -1,    23,    24,    -1,    -1,    62,    -1,
      64,    30,    -1,    -1,    -1,    34,    -1,    23,    24,     3,
      39,    62,    41,    64,    30,    -1,    -1,    -1,    34,    -1,
      -1,    -1,     3,    39,    -1,    41,    -1,    -1,    -1,    23,
      24,    -1,    -1,    62,    -1,    64,    30,    -1,    -1,    -1,
      34,    35,    23,    24,     3,    39,    62,    -1,    64,    30,
      -1,    -1,    -1,    34,    -1,    -1,    -1,     3,    39,    -1,
      41,    -1,    -1,    -1,    23,    24,    -1,    -1,    62,    -1,
      64,    30,    -1,    -1,    -1,    34,    35,    23,    24,     3,
      39,    62,    -1,    64,    30,    -1,    -1,    -1,    34,    35,
      -1,    -1,     3,    39,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    62,    -1,    64,    30,    -1,    -1,    -1,
      34,    35,    23,    24,     3,    39,    62,    -1,    64,    30,
      -1,    -1,     7,    34,    -1,    -1,    -1,    -1,    39,    -1,
      15,    16,    -1,    -1,    23,    24,    -1,    -1,    62,    -1,
      64,    30,    -1,    -1,    -1,    34,    -1,    -1,     7,    -1,
      39,    62,    -1,    64,    13,    14,    15,    16,    -1,    -1,
      19,    20,    47,    48,    49,    50,    51,    52,    53,    -1,
       7,    56,    -1,    62,    -1,    64,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
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
      15,    16,    -1,    -1,    19,    20,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,     7,    -1,
      -1,    -1,    -1,    62,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,     7,    -1,    -1,    -1,    61,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    60,    47,    48,    49,
      50,    51,    52,    53,    -1,     7,    56,    -1,    -1,    -1,
      60,    13,    14,    15,    16,    -1,    -1,    19,    20,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    60,    47,
      48,    49,    50,    51,    52,    53,     7,    -1,    56,    -1,
      58,    46,    13,    14,    15,    16,     7,    -1,    19,    20,
      -1,    56,    13,    14,    15,    16,    -1,     7,    19,    20,
      -1,    -1,    23,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    47,    48,    49,
      50,    51,    52,    53,     7,    -1,    56,    -1,    -1,    -1,
      13,    14,    15,    16,     7,    -1,    19,    -1,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    25,    28,    43,    66,    67,    70,    71,    85,
      86,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      59,    61,    63,     3,    36,     3,     3,     0,    67,    71,
      62,    67,    70,    86,    94,    96,    62,    67,    70,    95,
      96,    62,    67,    70,    97,    62,     4,    60,     3,    22,
      27,    33,    37,   103,     3,   102,    57,    57,    46,    61,
      62,    67,    62,    96,    25,    70,    67,    62,    70,    67,
      62,    60,    61,    63,    61,    68,    97,    58,     4,     5,
       6,    44,    45,    49,    50,    64,    87,    88,    89,    90,
      91,    92,    93,    70,    67,    67,    61,    63,   103,     3,
     100,   103,    58,    63,    61,    61,    61,    61,    61,    61,
       4,     5,     4,     5,     3,    98,    26,    70,    89,    62,
      67,   103,     3,   101,    59,    18,    61,    69,    97,     3,
      23,    24,    30,    31,    34,    39,    62,    64,    72,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    94,    96,
      22,    27,    33,    37,    37,    61,    61,    61,    61,    59,
      63,    62,    59,    60,   103,    40,    76,    61,    17,    57,
      59,     3,    62,    62,    62,    57,    57,     3,    62,    31,
       3,    78,     8,     9,    10,    11,    12,    17,    46,    56,
      62,    62,    62,    62,    62,    77,    96,    77,    94,    22,
      27,    22,    27,     4,    60,    64,    93,     4,    61,    62,
      31,    40,    40,    76,    59,     3,     4,     5,     6,    21,
      44,    45,    49,    50,    57,    58,    64,    72,    73,    75,
       3,     4,    64,    29,    74,    75,    74,    59,    62,    59,
      75,    75,    75,    75,    75,    75,    74,    72,    75,    77,
      77,    60,    63,     3,    60,   103,    31,    62,    75,    40,
      75,    59,    75,    75,    75,    75,     3,    58,    63,     7,
      13,    14,    15,    16,    19,    20,    47,    48,    49,    50,
      51,    52,    53,    56,    60,    60,     3,    59,    58,    75,
      58,     3,     4,    64,     4,    62,    62,    62,    62,    62,
      62,    62,    62,    46,    63,    64,    91,    61,    61,    31,
      62,    75,    23,    75,    58,    59,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    60,    75,    61,    61,    60,    60,     3,    60,
      74,    64,    92,     3,   103,   103,    31,    62,     3,    60,
      75,    61,    38,    41,    77,    42,    77,    60,    62,     3,
      59,    31,    61,    60,    75,    61,    38,    41,    42,    59,
      60,     4,   103,    60,    61,    41,    77,    61,     4,    61,
      60,    29,    61,    75,    41,    41,    77,    60,   103,    61,
       3,    35,    77,    60,    41,    61,   103,    32,    35,    61,
     103,     4,    35,    77,    60,    35,    61,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    83,    84,    85,    85,
      86,    87,    88,    88,    89,    89,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    99,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     3,     3,     3,
       4,     4,     5,     7,     8,     0,     1,     3,     2,     2,
       3,     8,    10,     9,    12,    11,     4,     3,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     4,     5,     3,
       1,     3,     3,     1,     2,     2,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     2,     4,     5,
       4,     6,     5,     5,     7,     6,    10,     9,     9,     8,
       7,     6,    13,    12,    11,    10,    11,    15,     2,     3,
       5,     2,     2,     3,     2,     1,     1,     1,     1,    11,
       6,    13,     7,     7,     4,     2,     3,     6,     7,     7,
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
#line 111 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1834 "myparser.tab.c"
    break;

  case 3:
#line 112 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1840 "myparser.tab.c"
    break;

  case 4:
#line 113 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1846 "myparser.tab.c"
    break;

  case 5:
#line 114 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1852 "myparser.tab.c"
    break;

  case 6:
#line 115 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1858 "myparser.tab.c"
    break;

  case 7:
#line 116 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1864 "myparser.tab.c"
    break;

  case 8:
#line 117 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1870 "myparser.tab.c"
    break;

  case 9:
#line 118 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1876 "myparser.tab.c"
    break;

  case 10:
#line 119 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1882 "myparser.tab.c"
    break;

  case 11:
#line 120 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1888 "myparser.tab.c"
    break;

  case 12:
#line 121 "myparser.y"
                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1894 "myparser.tab.c"
    break;

  case 13:
#line 125 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1900 "myparser.tab.c"
    break;

  case 14:
#line 126 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1906 "myparser.tab.c"
    break;

  case 15:
#line 130 "myparser.y"
               {(yyval.str) = template("");}
#line 1912 "myparser.tab.c"
    break;

  case 16:
#line 131 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1918 "myparser.tab.c"
    break;

  case 17:
#line 132 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1924 "myparser.tab.c"
    break;

  case 18:
#line 136 "myparser.y"
                              {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1930 "myparser.tab.c"
    break;

  case 19:
#line 144 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1936 "myparser.tab.c"
    break;

  case 20:
#line 145 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1942 "myparser.tab.c"
    break;

  case 21:
#line 149 "myparser.y"
                                                                                     {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-6].str);
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = (yyvsp[-6].str);
			numOfAllCompFuncs ++;
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
#line 1965 "myparser.tab.c"
    break;

  case 22:
#line 167 "myparser.y"
                                                                                                     {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-8].str);
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = (yyvsp[-8].str);
			numOfAllCompFuncs ++;
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
#line 1988 "myparser.tab.c"
    break;

  case 23:
#line 185 "myparser.y"
                                                                                   {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-7].str);
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = (yyvsp[-7].str);
			numOfAllCompFuncs ++;
			if(strcmp((yyvsp[-5].str), "") == 0) (yyval.str) = template("void (*%s)(SELF);", (yyvsp[-7].str)); //empty parameters 
			else (yyval.str) = template("void (*%s)(SELF, %s);", (yyvsp[-7].str), (yyvsp[-5].str)); 
			strcat(comp_func_to_C, "void ");
			strcat(comp_func_to_C, (yyvsp[-7].str)); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp((yyvsp[-5].str), "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, (yyvsp[-5].str)); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, "return;\n}\n");
		}else{
			(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));
		}
	}
#line 2011 "myparser.tab.c"
    break;

  case 24:
#line 203 "myparser.y"
                                                                                                                                {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-10].str);
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = (yyvsp[-10].str);
			numOfAllCompFuncs ++;
			if(strcmp((yyvsp[-8].str), "") == 0) (yyval.str) = template("%s (*%s)(SELF);", (yyvsp[-6].str), (yyvsp[-10].str)); //empty parameters 
			else (yyval.str) = template("%s (*%s)(SELF, %s);", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str)); 
			strcat(comp_func_to_C, (yyvsp[-6].str)); strcat(comp_func_to_C, " ");
			strcat(comp_func_to_C, (yyvsp[-10].str)); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp((yyvsp[-8].str), "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, (yyvsp[-8].str)); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, (yyvsp[-4].str));
			strcat(comp_func_to_C, "\nreturn "); strcat(comp_func_to_C, (yyvsp[-2].str)); strcat(comp_func_to_C, ";\n}");
		}else{
			(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));
		}
	}
#line 2035 "myparser.tab.c"
    break;

  case 25:
#line 222 "myparser.y"
                                                                                                              {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-9].str);
			numOfCompFuncs ++;
			all_comp_funcs[numOfAllCompFuncs] = (yyvsp[-9].str);
			numOfAllCompFuncs ++;
			if(strcmp((yyvsp[-7].str), "") == 0) (yyval.str) = template("%s (*%s)(SELF);", (yyvsp[-5].str), (yyvsp[-9].str)); //empty parameters 
			else (yyval.str) = template("%s (*%s)(SELF, %s);", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str)); 
			strcat(comp_func_to_C, (yyvsp[-5].str)); strcat(comp_func_to_C, " ");
			strcat(comp_func_to_C, (yyvsp[-9].str)); 
			strcat(comp_func_to_C, "(SELF");
			if(strcmp((yyvsp[-7].str), "") != 0) strcat(comp_func_to_C, ", ");	//if not empty parameters
			strcat(comp_func_to_C, (yyvsp[-7].str)); strcat(comp_func_to_C, "){\n");
			strcat(comp_func_to_C, "return "); strcat(comp_func_to_C, (yyvsp[-2].str)); strcat(comp_func_to_C, ";\n}");
		}else{
			(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));
		}
	}
#line 2058 "myparser.tab.c"
    break;

  case 26:
#line 244 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2064 "myparser.tab.c"
    break;

  case 27:
#line 245 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2070 "myparser.tab.c"
    break;

  case 28:
#line 249 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2076 "myparser.tab.c"
    break;

  case 29:
#line 250 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2082 "myparser.tab.c"
    break;

  case 30:
#line 254 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2088 "myparser.tab.c"
    break;

  case 31:
#line 255 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2094 "myparser.tab.c"
    break;

  case 34:
#line 261 "myparser.y"
                        {
				if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
							yyerror("Comp variables are preceded by # ");
				}else {(yyval.str) = template("%s", (yyvsp[0].str));}
				}
#line 2104 "myparser.tab.c"
    break;

  case 35:
#line 266 "myparser.y"
                        {
					if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
							(yyval.str) = template("self->%s", (yyvsp[0].str));
					}else if (/*(insideCompDecl == 1) &&*/ (find_comp((yyvsp[0].str), "all_comp_vars"))){
						//first if stmt will catch variables that belong to current
						//comp declaration
						//this if stmt will catch vars that belong to other comps
						(yyval.str) = template("%s", (yyvsp[0].str));
					}

					else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
					}
#line 2121 "myparser.tab.c"
    break;

  case 37:
#line 279 "myparser.y"
                        {(yyval.str) = template("0");}
#line 2127 "myparser.tab.c"
    break;

  case 38:
#line 280 "myparser.y"
                        {(yyval.str) = template("1");}
#line 2133 "myparser.tab.c"
    break;

  case 39:
#line 281 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2139 "myparser.tab.c"
    break;

  case 40:
#line 282 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2145 "myparser.tab.c"
    break;

  case 41:
#line 283 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 2151 "myparser.tab.c"
    break;

  case 42:
#line 284 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2157 "myparser.tab.c"
    break;

  case 43:
#line 285 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2163 "myparser.tab.c"
    break;

  case 44:
#line 286 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2169 "myparser.tab.c"
    break;

  case 45:
#line 287 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2175 "myparser.tab.c"
    break;

  case 46:
#line 288 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2181 "myparser.tab.c"
    break;

  case 47:
#line 289 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2187 "myparser.tab.c"
    break;

  case 48:
#line 290 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2193 "myparser.tab.c"
    break;

  case 49:
#line 291 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2199 "myparser.tab.c"
    break;

  case 50:
#line 292 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2205 "myparser.tab.c"
    break;

  case 51:
#line 293 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2211 "myparser.tab.c"
    break;

  case 52:
#line 294 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2217 "myparser.tab.c"
    break;

  case 53:
#line 295 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2223 "myparser.tab.c"
    break;

  case 54:
#line 296 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 2229 "myparser.tab.c"
    break;

  case 55:
#line 297 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2235 "myparser.tab.c"
    break;

  case 56:
#line 298 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 2241 "myparser.tab.c"
    break;

  case 57:
#line 299 "myparser.y"
                                { 
			if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
				yyerror("Comp variables are preceded by # ");
			}else {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
		
		}
#line 2252 "myparser.tab.c"
    break;

  case 58:
#line 305 "myparser.y"
                                    { 
			if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
				(yyval.str) = template("self->%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));
			}else if ((insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "all_comp_vars"))){
				//first if stmt will catch variables that belong to current
				//comp declaration
				//this if stmt will catch vars that belong to other comps
				(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));
			}
			else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		
		}
#line 2269 "myparser.tab.c"
    break;

  case 59:
#line 317 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2275 "myparser.tab.c"
    break;

  case 60:
#line 318 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2281 "myparser.tab.c"
    break;

  case 61:
#line 322 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2287 "myparser.tab.c"
    break;

  case 62:
#line 323 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2293 "myparser.tab.c"
    break;

  case 63:
#line 324 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2299 "myparser.tab.c"
    break;

  case 64:
#line 325 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2305 "myparser.tab.c"
    break;

  case 65:
#line 326 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2311 "myparser.tab.c"
    break;

  case 66:
#line 332 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2317 "myparser.tab.c"
    break;

  case 67:
#line 333 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2323 "myparser.tab.c"
    break;

  case 68:
#line 337 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2329 "myparser.tab.c"
    break;

  case 69:
#line 338 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2335 "myparser.tab.c"
    break;

  case 70:
#line 339 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2341 "myparser.tab.c"
    break;

  case 71:
#line 340 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2347 "myparser.tab.c"
    break;

  case 72:
#line 341 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2353 "myparser.tab.c"
    break;

  case 73:
#line 342 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2359 "myparser.tab.c"
    break;

  case 74:
#line 343 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2365 "myparser.tab.c"
    break;

  case 75:
#line 344 "myparser.y"
                                                    {(yyval.str) = template("%s.%s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2371 "myparser.tab.c"
    break;

  case 76:
#line 345 "myparser.y"
                                                 {(yyval.str) = template("%s.%s = %s;",(yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2377 "myparser.tab.c"
    break;

  case 77:
#line 346 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2383 "myparser.tab.c"
    break;

  case 78:
#line 347 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2389 "myparser.tab.c"
    break;

  case 79:
#line 348 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2395 "myparser.tab.c"
    break;

  case 80:
#line 349 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2401 "myparser.tab.c"
    break;

  case 81:
#line 350 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2407 "myparser.tab.c"
    break;

  case 82:
#line 351 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2413 "myparser.tab.c"
    break;

  case 83:
#line 352 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2419 "myparser.tab.c"
    break;

  case 84:
#line 353 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2425 "myparser.tab.c"
    break;

  case 85:
#line 354 "myparser.y"
              {(yyval.str) = template("");}
#line 2431 "myparser.tab.c"
    break;

  case 86:
#line 358 "myparser.y"
                 { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
			   		yyerror("Comp variables are preceded by # ");
			   }else {(yyval.str) = template("%s", (yyvsp[0].str));}
			 }
#line 2440 "myparser.tab.c"
    break;

  case 87:
#line 362 "myparser.y"
                       { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
			   			(yyval.str) = template("self->%s", (yyvsp[0].str));
			   		}//else if(find_comp($2, "all_comp_vars")){	
					//	//first if stmt will catch variables that belong to current
					//	//comp declaration
					//	//this if stmt will catch vars that belong to other comps 
					//	$$ = template("%s", $2);
					//}
					else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		 }
#line 2455 "myparser.tab.c"
    break;

  case 88:
#line 372 "myparser.y"
                                        { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
									}
#line 2464 "myparser.tab.c"
    break;

  case 89:
#line 376 "myparser.y"
                                           {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
										}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2473 "myparser.tab.c"
    break;

  case 90:
#line 380 "myparser.y"
                                    { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
		}
#line 2482 "myparser.tab.c"
    break;

  case 91:
#line 384 "myparser.y"
                                            {if( (insideCompDecl == 1) && (find_comp((yyvsp[-4].str), "comp_vars")) && (find_comp((yyvsp[-1].str), "comp_vars"))){ //if inside comp declaration and tokens are member of comp then correct
											(yyval.str) = template("self->%s[self->%s]",(yyvsp[-4].str), (yyvsp[-1].str));
									}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2491 "myparser.tab.c"
    break;

  case 92:
#line 388 "myparser.y"
                                        {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) && (!find_comp((yyvsp[-1].str), "comp_vars")) ){ //if inside comp declaration, 1st token is member of comp and 2nd isn't then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
#line 2500 "myparser.tab.c"
    break;

  case 93:
#line 392 "myparser.y"
                                        {if( (insideCompDecl == 1) && (!find_comp((yyvsp[-4].str), "comp_vars")) && (find_comp((yyvsp[-1].str), "comp_vars")) ){ //if inside comp declaration, 1st token not member of comp and 2nd is then correct
											(yyval.str) = template("%s[self->%s]",(yyvsp[-4].str), (yyvsp[-1].str));
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
#line 2509 "myparser.tab.c"
    break;

  case 94:
#line 406 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2515 "myparser.tab.c"
    break;

  case 95:
#line 407 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2521 "myparser.tab.c"
    break;

  case 96:
#line 408 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2527 "myparser.tab.c"
    break;

  case 97:
#line 409 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2533 "myparser.tab.c"
    break;

  case 98:
#line 410 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2539 "myparser.tab.c"
    break;

  case 99:
#line 411 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2545 "myparser.tab.c"
    break;

  case 100:
#line 418 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2551 "myparser.tab.c"
    break;

  case 101:
#line 419 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2557 "myparser.tab.c"
    break;

  case 102:
#line 423 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2563 "myparser.tab.c"
    break;

  case 103:
#line 424 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2569 "myparser.tab.c"
    break;

  case 104:
#line 425 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2575 "myparser.tab.c"
    break;

  case 105:
#line 426 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2581 "myparser.tab.c"
    break;

  case 106:
#line 431 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2587 "myparser.tab.c"
    break;

  case 107:
#line 436 "myparser.y"
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
#line 2602 "myparser.tab.c"
    break;

  case 108:
#line 449 "myparser.y"
                             {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 2608 "myparser.tab.c"
    break;

  case 109:
#line 450 "myparser.y"
                                                 {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2614 "myparser.tab.c"
    break;

  case 110:
#line 455 "myparser.y"
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
#line 2641 "myparser.tab.c"
    break;

  case 111:
#line 482 "myparser.y"
                                              {(yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2647 "myparser.tab.c"
    break;

  case 112:
#line 486 "myparser.y"
                                 {(yyval.str) = template("%s;", (yyvsp[-1].str)); insideCompDecl = 1;}
#line 2653 "myparser.tab.c"
    break;

  case 113:
#line 487 "myparser.y"
                                                         { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2659 "myparser.tab.c"
    break;

  case 114:
#line 492 "myparser.y"
                    {
				(yyval.str) = template("%s", (yyvsp[0].str)); comp_vars[numOfCompVars] = comp_var_name; numOfCompVars++;
				all_comp_vars[numOfAllCompVars] = comp_var_name; numOfAllCompVars++;
				}
#line 2668 "myparser.tab.c"
    break;

  case 115:
#line 496 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2674 "myparser.tab.c"
    break;

  case 116:
#line 500 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2680 "myparser.tab.c"
    break;

  case 117:
#line 501 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2686 "myparser.tab.c"
    break;

  case 118:
#line 502 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2692 "myparser.tab.c"
    break;

  case 119:
#line 506 "myparser.y"
                                                                    {	if(isStr == 1){
																		(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
																	else{
																		(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
										comp_vars[numOfCompVars] = (yyvsp[-9].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-9].str); numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-4].str); numOfAllCompVars++;
										}
#line 2708 "myparser.tab.c"
    break;

  case 120:
#line 517 "myparser.y"
                                                     {	if(isStr == 1){
														(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
													else{
														(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-4].str); numOfAllCompVars++;
										}
#line 2722 "myparser.tab.c"
    break;

  case 121:
#line 529 "myparser.y"
                                                                                            {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										comp_vars[numOfCompVars] = (yyvsp[-11].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-11].str); numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-5].str); numOfAllCompVars++;
										}
#line 2738 "myparser.tab.c"
    break;

  case 122:
#line 540 "myparser.y"
                                                                {	if(isStr == 1){
																	(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
																else{
																	(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
								comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
								all_comp_vars[numOfAllCompVars] = (yyvsp[-5].str); numOfAllCompVars++;
								}
#line 2752 "myparser.tab.c"
    break;

  case 123:
#line 552 "myparser.y"
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
										all_comp_vars[numOfAllCompVars] = (yyvsp[-5].str); numOfAllCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-2].str); numOfAllCompVars++;
										}
#line 2771 "myparser.tab.c"
    break;

  case 124:
#line 566 "myparser.y"
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
								all_comp_vars[numOfAllCompVars] = (yyvsp[-2].str); numOfAllCompVars++;
								}
#line 2788 "myparser.tab.c"
    break;

  case 125:
#line 596 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2794 "myparser.tab.c"
    break;

  case 126:
#line 597 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2800 "myparser.tab.c"
    break;

  case 127:
#line 601 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2806 "myparser.tab.c"
    break;

  case 128:
#line 602 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2812 "myparser.tab.c"
    break;

  case 129:
#line 603 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2818 "myparser.tab.c"
    break;

  case 130:
#line 604 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2824 "myparser.tab.c"
    break;

  case 131:
#line 605 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2830 "myparser.tab.c"
    break;

  case 132:
#line 606 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2836 "myparser.tab.c"
    break;

  case 133:
#line 607 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2842 "myparser.tab.c"
    break;

  case 134:
#line 608 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2848 "myparser.tab.c"
    break;

  case 135:
#line 609 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2854 "myparser.tab.c"
    break;

  case 136:
#line 614 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2860 "myparser.tab.c"
    break;

  case 137:
#line 615 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2866 "myparser.tab.c"
    break;

  case 138:
#line 619 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2872 "myparser.tab.c"
    break;

  case 139:
#line 620 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2878 "myparser.tab.c"
    break;

  case 140:
#line 624 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else{
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
							comp_var_name = (yyvsp[-2].str);	//maybe not a comp var, but i need it if it is
							 }
#line 2889 "myparser.tab.c"
    break;

  case 141:
#line 630 "myparser.y"
                                                     {	(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));	comp_var_name = (yyvsp[-5].str);}
#line 2895 "myparser.tab.c"
    break;

  case 142:
#line 631 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str)); comp_var_name = (yyvsp[-4].str);}
#line 2901 "myparser.tab.c"
    break;

  case 143:
#line 635 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2907 "myparser.tab.c"
    break;

  case 144:
#line 636 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2913 "myparser.tab.c"
    break;

  case 145:
#line 637 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2919 "myparser.tab.c"
    break;

  case 146:
#line 641 "myparser.y"
                                                            {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2930 "myparser.tab.c"
    break;

  case 147:
#line 647 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2941 "myparser.tab.c"
    break;

  case 148:
#line 656 "myparser.y"
                                                                                    {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2952 "myparser.tab.c"
    break;

  case 149:
#line 662 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2963 "myparser.tab.c"
    break;

  case 150:
#line 671 "myparser.y"
                                            {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2977 "myparser.tab.c"
    break;

  case 151:
#line 680 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2991 "myparser.tab.c"
    break;

  case 152:
#line 692 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2997 "myparser.tab.c"
    break;

  case 153:
#line 693 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0; isStr = 0;}
#line 3003 "myparser.tab.c"
    break;

  case 154:
#line 694 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0; isStr = 1;}
#line 3009 "myparser.tab.c"
    break;

  case 155:
#line 695 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 3015 "myparser.tab.c"
    break;

  case 156:
#line 696 "myparser.y"
                   { isStr = 0;
					if(find_comp((yyvsp[0].str), "comps") == 1){		//allow Comp data_type only if it is already declared 
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 3029 "myparser.tab.c"
    break;


#line 3033 "myparser.tab.c"

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
#line 708 "myparser.y"

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
		return 0; //comp var does not exist
	}
	else if(strcmp(whereToSearch, "all_comp_vars") == 0){
		for(int i = 0; i< numOfAllCompVars; i++){
			if(strcmp(compToSearch, all_comp_vars[i]) == 0){
				return 1;	//comp var exists
			}
		}
		return 0; //comp var does not exist
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


