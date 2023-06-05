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
#define YYLAST   1184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

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
       0,   108,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   122,   123,   127,   128,   129,   133,   141,
     142,   146,   162,   178,   194,   211,   231,   232,   236,   237,
     241,   242,   246,   247,   248,   253,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     285,   286,   287,   288,   289,   295,   296,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   320,   324,   328,   332,   336,   340,
     347,   348,   349,   350,   351,   352,   359,   360,   364,   365,
     366,   367,   371,   376,   390,   391,   395,   423,   427,   428,
     433,   434,   438,   439,   440,   444,   453,   464,   473,   484,
     496,   525,   526,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   543,   544,   548,   549,   553,   559,   560,   564,
     565,   566,   570,   576,   585,   591,   600,   609,   621,   622,
     623,   624,   625
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

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     178,    88,    13,    19,    25,    59,  -157,     0,     5,   178,
      38,    95,    45,     6,    52,  -157,  -157,  -157,  -157,  -157,
      14,    82,    87,    71,    93,   110,   128,  -157,  -157,   131,
    -157,  -157,     0,   134,   107,    80,  -157,  -157,     0,   140,
      80,  -157,  -157,     0,   158,  -157,   162,    61,  -157,  -157,
    -157,  -157,  -157,  -157,    79,  -157,   231,   183,   259,   175,
    -157,  -157,  -157,    80,   244,     0,  -157,  -157,     0,  -157,
    -157,   122,    82,   245,    82,   -20,  -157,   205,   207,   208,
     211,   212,   215,    36,   139,   275,   254,   -12,   220,  -157,
    -157,  -157,  -157,     0,  -157,  -157,    82,   280,  -157,   227,
    -157,  -157,   -13,   231,   389,   265,   266,   261,   260,   269,
     235,   237,   249,   251,   146,  -157,  -157,   288,   252,  -157,
    -157,  -157,   256,  -157,   258,    82,   408,   255,  -157,   121,
     316,   267,   270,   271,   263,   264,  -157,   320,   272,   297,
     668,  -157,  1128,   276,   277,   285,   287,   289,   465,   465,
    -157,  -157,  -157,  -157,  -157,   315,   325,   326,   332,    22,
     298,  -157,   357,   151,  -157,   301,    56,   422,   305,   286,
      11,   338,  -157,  -157,  -157,   377,   377,   309,  -157,   307,
      16,  -157,   377,   377,   377,   377,   377,   377,   377,   369,
    -157,  -157,  -157,  -157,  -157,   668,   681,   668,   478,  -157,
    -157,  -157,  -157,   314,   154,   372,  -157,   317,    82,   345,
    -157,   322,   377,   346,   377,   159,  -157,  -157,  -157,   377,
    -157,  -157,   377,   377,   377,  -157,   384,  -157,    68,  1031,
     328,   329,   331,   296,  1031,   321,   156,  -157,   226,   709,
     733,   759,   783,   809,   833,   352,   334,   333,   668,   668,
     172,   330,   177,   192,  -157,  -157,   362,   859,   377,  1054,
     377,  1101,    28,    28,  1007,  -157,  -157,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,  -157,   122,   377,   339,  1031,   342,   344,
     347,   348,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
     335,   402,  -157,    82,    82,  -157,   375,   883,   407,   959,
    -157,  1031,    28,  1117,  1117,   148,   148,  1101,  1078,   148,
     148,    81,    81,    28,    28,    28,  -157,   933,    27,   491,
    -157,  -157,  -157,   412,  -157,   359,  -157,  -157,  -157,   393,
     368,  -157,   377,   374,  -157,   441,  -157,   515,   371,   373,
    -157,   248,   909,   528,   376,  -157,  -157,   435,   196,   380,
     414,   388,   377,  -157,   541,   563,   394,    82,   396,   452,
     585,   983,  -157,  -157,   598,   197,  -157,    82,   426,  -157,
     611,   398,  -157,    82,  -157,   456,  -157,   633,  -157,   403,
    -157,   655,   405,  -157,    82,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   141,   140,   139,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      19,     6,     0,     0,     0,     0,   104,     5,     0,     0,
       0,   121,     4,     0,     0,   132,     0,     0,   152,   148,
     149,   150,   151,   136,     0,   147,    15,     0,     0,     0,
      20,     8,   105,     0,     0,     0,     7,   122,     0,     9,
     133,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     114,   113,   112,     0,    11,    10,     0,     0,   138,     0,
     143,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   106,   107,     0,   108,
      12,   137,     0,   145,     0,     0,     0,     0,    17,    84,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
      62,    65,     0,     0,     0,     0,     0,     0,     0,     0,
     126,   123,   129,   130,   131,     0,     0,     0,     0,     0,
       0,   109,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    13,     0,     0,    85,    75,     0,
      84,    66,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    78,    77,    81,    82,    64,     0,    63,     0,   127,
     124,   128,   125,     0,     0,     0,   120,     0,     0,     0,
      21,     0,     0,     0,     0,    34,    32,    33,    36,     0,
      38,    37,     0,     0,     0,    27,     0,    59,     0,    28,
       0,     0,     0,     0,    30,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    60,
       0,     0,     0,     0,   142,    23,     0,     0,     0,     0,
       0,    41,    55,    54,     0,    35,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    86,     0,     0,    31,     0,     0,
       0,     0,    68,    69,    70,    72,    71,    73,    67,    74,
       0,     0,   116,     0,     0,    22,     0,     0,     0,     0,
      56,    29,    53,    43,    42,    45,    44,    40,    39,    46,
      47,    48,    49,    50,    51,    52,    58,     0,     0,     0,
      89,    87,    86,     0,   118,     0,   119,   144,    25,     0,
       0,    57,     0,     0,    91,     0,    97,     0,     0,     0,
      24,     0,     0,     0,     0,    90,    96,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,   115,     0,     0,   101,
       0,     0,    92,     0,   102,     0,   100,     0,   117,     0,
      99,     0,     0,    98,     0,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,   181,  -157,  -157,    90,     4,  -103,  -157,  -156,
    -106,   -97,  -142,  -137,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,   458,  -157,  -157,   382,  -157,   222,   174,   318,     8,
      -7,    10,    -1,   391,  -157,   404,   386,   463,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    75,   127,     7,     8,   227,   228,   233,
     234,   139,   140,   141,   142,   143,   144,   145,   146,   147,
       9,    10,    86,    87,    88,    89,    90,    91,    92,   148,
      12,   149,    14,    15,    16,    17,    18,    19,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   138,   101,   181,    39,   125,   195,   197,    11,     1,
      13,    29,    44,    64,   230,   231,    23,    34,    46,    35,
     235,    40,    25,   138,   121,     2,   203,    39,    26,   166,
     180,     2,   245,   168,    44,   268,    29,   138,   102,    44,
     110,   111,    29,   103,    63,   138,   138,    29,   126,    24,
     130,   131,    85,   164,   248,    76,   249,   132,   181,    27,
     181,   134,    44,   229,   138,   343,   135,    30,   344,    29,
     213,    47,    29,   169,    47,   238,   239,   240,   241,   242,
     243,   244,   204,     1,   282,    48,   247,   210,   268,   136,
      54,   137,   138,   138,   138,   138,   211,    29,     1,    32,
      36,    38,   128,    43,    49,    64,   257,    41,   259,    50,
       1,   181,   181,   261,    45,    51,   262,   263,   264,    52,
       2,    29,    72,     3,    73,    65,   266,   287,    56,   287,
      68,   267,   279,   280,   281,     3,   254,   282,   168,   287,
      74,    39,    22,   112,   113,   138,   138,    20,    44,    21,
      57,    22,   307,    93,   309,   268,    58,   198,   196,   289,
     290,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   117,   169,   327,
     170,     1,    21,    96,    22,    97,   345,   347,    28,    59,
      31,    39,    37,    60,    42,    44,    62,   277,   278,   279,
     280,   281,    67,     2,   282,   159,     3,    21,   181,   160,
     181,   364,   208,    61,    73,    72,   169,   251,   260,    66,
      70,     4,    71,   374,    69,   138,   138,   181,   380,   230,
     291,   336,   337,    96,     1,   300,   352,   181,   303,    85,
     160,    77,   138,   181,   138,   391,    94,    23,    99,    95,
     138,    48,   359,   304,   181,    97,   371,   367,   383,   251,
     300,   138,   138,    78,    79,    80,   104,   138,   105,   106,
      49,   138,   107,   108,   120,    50,   109,   138,   114,   360,
     116,    51,   119,   122,   138,    52,   124,   150,   138,   215,
     216,   217,   218,   151,   152,   376,   155,   153,   156,   215,
     216,   217,   218,    81,    82,   384,   154,   219,    83,    84,
     157,   388,   158,    64,   161,   162,   167,   219,   163,   171,
     175,   176,   395,   177,   215,   216,   217,   218,   179,   172,
     220,   221,   173,   174,   178,   222,   223,   199,   190,   191,
     220,   221,   219,   224,   225,   222,   223,   192,   201,   193,
     226,   194,   200,   224,   286,   215,   216,   217,   218,   202,
     226,   207,   205,   209,   214,   220,   221,   232,   236,   237,
     222,   223,   246,   219,   250,   252,   255,   253,   224,   288,
     215,   216,   217,   218,   256,   226,   258,   265,   283,   284,
     285,   169,   129,   305,   301,   299,   220,   221,   219,   333,
     328,   222,   223,   329,   330,   335,   338,   331,   332,   224,
     340,   129,   130,   131,   298,   348,   226,     3,   349,   132,
     133,   220,   221,   134,   350,   129,   222,   223,   135,   351,
     357,   130,   131,   358,   224,   353,     3,   365,   132,   366,
     368,   226,   134,   369,   180,   130,   131,   135,   165,   370,
       3,   136,   132,   137,   375,   378,   134,   377,   385,   387,
     389,   135,   212,   392,   130,   131,   394,    33,   129,   118,
     136,   132,   137,   302,   334,   134,   115,   100,   206,   354,
     135,   180,   355,   123,   136,    55,   137,     0,   130,   131,
       0,     0,     0,     3,   180,   132,     0,     0,     0,   134,
       0,   130,   131,   136,   135,   137,     3,     0,   132,     0,
       0,     0,   134,     0,   130,   131,     0,   135,   180,     0,
       0,   132,     0,     0,     0,   134,     0,   136,     0,   137,
     135,   180,     0,   346,     0,     0,     0,     0,   130,   131,
     136,     0,   137,     0,   180,   132,     0,     0,     0,   134,
       0,   130,   131,   136,   135,   137,     0,   356,   132,     0,
       0,     0,   134,     0,   130,   131,   180,   135,     0,   363,
       0,   132,     0,     0,     0,   134,     0,   136,     0,   137,
     135,     0,   372,     0,     0,     0,   130,   131,   180,     0,
     136,     0,   137,   132,     0,     0,     0,   134,     0,     0,
       0,   180,   135,   136,   373,   137,     0,     0,   130,   131,
       0,     0,     0,     0,   180,   132,     0,     0,     0,   134,
     379,   130,   131,     0,   135,   136,     0,   137,   132,     0,
       0,     0,   134,     0,   130,   131,   180,   135,     0,   382,
       0,   132,     0,     0,     0,   134,   386,   136,     0,   137,
     135,     0,     0,     0,     0,     0,   130,   131,   180,     0,
     136,     0,   137,   132,     0,     0,     0,   134,   390,     0,
       0,   180,   135,   136,     0,   137,     0,     0,   130,   131,
       0,     0,     0,     0,   129,   132,     0,     0,     0,   134,
     393,   130,   131,     0,   135,   136,     0,   137,   132,     0,
       0,     0,   134,     0,   130,   131,     0,   135,     0,     0,
       0,   132,     0,     0,     0,   134,   268,   136,     0,   137,
     135,     0,   269,   270,   271,   272,     0,     0,   273,   274,
     136,     0,   137,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,   136,     0,   137,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,     0,   282,   268,     0,     0,     0,
       0,   292,   269,   270,   271,   272,     0,     0,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   282,
     268,     0,     0,     0,     0,   293,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,     0,   282,   268,     0,     0,     0,
       0,   294,   269,   270,   271,   272,     0,     0,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   282,
     268,     0,     0,     0,     0,   295,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,     0,   282,   268,     0,     0,     0,
       0,   296,   269,   270,   271,   272,     0,     0,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   282,
     268,     0,     0,     0,     0,   297,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,     0,   282,   268,     0,     0,     0,
       0,   306,   269,   270,   271,   272,     0,     0,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   282,
     268,     0,     0,     0,     0,   339,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,     0,   282,   268,     0,     0,   361,
     362,     0,   269,   270,   271,   272,     0,     0,   273,   274,
     275,   276,   277,   278,   279,   280,   281,     0,     0,   282,
     268,     0,     0,     0,   342,     0,   269,   270,   271,   272,
       0,     0,   273,   274,     0,     0,   275,   276,   277,   278,
     279,   280,   281,     0,   268,   282,     0,     0,     0,   341,
     269,   270,   271,   272,     0,     0,   273,   274,     0,     0,
     275,   276,   277,   278,   279,   280,   281,     0,   268,   282,
       0,     0,     0,   381,   269,   270,   271,   272,     0,     0,
     273,   274,     0,     0,   275,   276,   277,   278,   279,   280,
     281,   268,     0,   282,     0,   310,     0,   269,   270,   271,
     272,     0,     0,   273,   274,     0,     0,   308,   275,   276,
     277,   278,   279,   280,   281,   268,     0,   282,     0,     0,
       0,   269,   270,   271,   272,     0,     0,   273,     0,     0,
       0,   275,   276,   277,   278,   279,   280,   281,   268,     0,
     282,     0,     0,     0,   269,   270,   271,   272,     0,     0,
       0,     0,     0,     0,   268,   275,   276,   277,   278,   279,
     280,   281,   271,   272,   282,     0,   182,   183,   184,   185,
     186,     0,     0,     0,     0,   187,     0,     0,   275,   276,
     277,   278,   279,   280,   281,     0,     0,   282,     0,     0,
       0,     0,     0,     0,   275,   276,   277,   278,   279,   280,
     281,     0,     0,   282,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189
};

static const yytype_int16 yycheck[] =
{
      72,   104,    74,   140,    11,    18,   148,   149,     0,     3,
       0,     7,    13,    25,     3,     4,     3,     9,     4,     9,
     176,    11,     3,   126,    96,    25,     4,    34,     3,   126,
       3,    25,   188,    17,    35,     7,    32,   140,    58,    40,
       4,     5,    38,    63,    34,   148,   149,    43,    61,    36,
      23,    24,    64,   125,   196,    56,   198,    30,   195,     0,
     197,    34,    63,   169,   167,    38,    39,    62,    41,    65,
     167,    60,    68,    57,    60,    59,   182,   183,   184,   185,
     186,   187,    60,     3,    56,     3,   189,    31,     7,    62,
       3,    64,   195,   196,   197,   198,    40,    93,     3,     9,
      62,    11,   103,    13,    22,    25,   212,    62,   214,    27,
       3,   248,   249,   219,    62,    33,   222,   223,   224,    37,
      25,   117,    61,    28,    63,    35,    58,   233,    57,   235,
      40,    63,    51,    52,    53,    28,   208,    56,    17,   245,
      61,   148,    63,     4,     5,   248,   249,    59,   149,    61,
      57,    63,   258,    63,   260,     7,    46,   149,   148,     3,
       4,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,    87,    57,   285,
      59,     3,    61,    61,    63,    63,   328,   329,     7,    61,
       9,   198,    11,    62,    13,   196,    62,    49,    50,    51,
      52,    53,    62,    25,    56,    59,    28,    61,   345,    63,
     347,   353,    61,    32,    63,    61,    57,    63,    59,    38,
      62,    43,    60,   365,    43,   328,   329,   364,   370,     3,
       4,   303,   304,    61,     3,    63,   342,   374,    61,    64,
      63,    58,   345,   380,   347,   387,    65,     3,     3,    68,
     353,     3,     4,    61,   391,    63,   362,    61,    61,    63,
      63,   364,   365,     4,     5,     6,    61,   370,    61,    61,
      22,   374,    61,    61,    93,    27,    61,   380,     3,   351,
      26,    33,    62,     3,   387,    37,    59,    22,   391,     3,
       4,     5,     6,    27,    33,   367,    61,    37,    61,     3,
       4,     5,     6,    44,    45,   377,    37,    21,    49,    50,
      61,   383,    61,    25,    62,    59,    61,    21,    60,     3,
      57,    57,   394,     3,     3,     4,     5,     6,    31,    62,
      44,    45,    62,    62,    62,    49,    50,    22,    62,    62,
      44,    45,    21,    57,    58,    49,    50,    62,    22,    62,
      64,    62,    27,    57,    58,     3,     4,     5,     6,    27,
      64,     4,    64,    62,    59,    44,    45,    29,    59,    62,
      49,    50,     3,    21,    60,     3,    31,    60,    57,    58,
       3,     4,     5,     6,    62,    64,    40,     3,    60,    60,
      59,    57,     3,    31,    64,    62,    44,    45,    21,    64,
      61,    49,    50,    61,    60,     3,    31,    60,    60,    57,
       3,     3,    23,    24,    62,     3,    64,    28,    59,    30,
      31,    44,    45,    34,    31,     3,    49,    50,    39,    61,
      59,    23,    24,    60,    57,    61,    28,    61,    30,     4,
      60,    64,    34,    29,     3,    23,    24,    39,    40,    61,
      28,    62,    30,    64,    60,     3,    34,    61,    32,    61,
       4,    39,    40,    60,    23,    24,    61,     9,     3,    87,
      62,    30,    64,   251,   300,    34,    85,    73,   160,    38,
      39,     3,    41,    97,    62,    22,    64,    -1,    23,    24,
      -1,    -1,    -1,    28,     3,    30,    -1,    -1,    -1,    34,
      -1,    23,    24,    62,    39,    64,    28,    -1,    30,    -1,
      -1,    -1,    34,    -1,    23,    24,    -1,    39,     3,    -1,
      -1,    30,    -1,    -1,    -1,    34,    -1,    62,    -1,    64,
      39,     3,    -1,    42,    -1,    -1,    -1,    -1,    23,    24,
      62,    -1,    64,    -1,     3,    30,    -1,    -1,    -1,    34,
      -1,    23,    24,    62,    39,    64,    -1,    42,    30,    -1,
      -1,    -1,    34,    -1,    23,    24,     3,    39,    -1,    41,
      -1,    30,    -1,    -1,    -1,    34,    -1,    62,    -1,    64,
      39,    -1,    41,    -1,    -1,    -1,    23,    24,     3,    -1,
      62,    -1,    64,    30,    -1,    -1,    -1,    34,    -1,    -1,
      -1,     3,    39,    62,    41,    64,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,     3,    30,    -1,    -1,    -1,    34,
      35,    23,    24,    -1,    39,    62,    -1,    64,    30,    -1,
      -1,    -1,    34,    -1,    23,    24,     3,    39,    -1,    41,
      -1,    30,    -1,    -1,    -1,    34,    35,    62,    -1,    64,
      39,    -1,    -1,    -1,    -1,    -1,    23,    24,     3,    -1,
      62,    -1,    64,    30,    -1,    -1,    -1,    34,    35,    -1,
      -1,     3,    39,    62,    -1,    64,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,     3,    30,    -1,    -1,    -1,    34,
      35,    23,    24,    -1,    39,    62,    -1,    64,    30,    -1,
      -1,    -1,    34,    -1,    23,    24,    -1,    39,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,     7,    62,    -1,    64,
      39,    -1,    13,    14,    15,    16,    -1,    -1,    19,    20,
      62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    62,    -1,    64,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    60,
      61,    -1,    13,    14,    15,    16,    -1,    -1,    19,    20,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    -1,    61,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,     7,    56,    -1,    -1,    -1,    60,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,     7,    56,
      -1,    -1,    -1,    60,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,     7,    -1,    56,    -1,    58,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    -1,    23,    47,    48,
      49,    50,    51,    52,    53,     7,    -1,    56,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,     7,    -1,
      56,    -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    47,    48,    49,    50,    51,
      52,    53,    15,    16,    56,    -1,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56
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
       3,     4,    29,    74,    75,    74,    59,    62,    59,    75,
      75,    75,    75,    75,    75,    74,     3,    72,    77,    77,
      60,    63,     3,    60,   103,    31,    62,    75,    40,    75,
      59,    75,    75,    75,    75,     3,    58,    63,     7,    13,
      14,    15,    16,    19,    20,    47,    48,    49,    50,    51,
      52,    53,    56,    60,    60,    59,    58,    75,    58,     3,
       4,     4,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    91,    61,    61,    31,    62,    75,    23,    75,
      58,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    61,    61,
      60,    60,    60,    64,    92,     3,   103,   103,    31,    62,
       3,    60,    61,    38,    41,    77,    42,    77,     3,    59,
      31,    61,    75,    61,    38,    41,    42,    59,    60,     4,
     103,    60,    61,    41,    77,    61,     4,    61,    60,    29,
      61,    75,    41,    41,    77,    60,   103,    61,     3,    35,
      77,    60,    41,    61,   103,    32,    35,    61,   103,     4,
      35,    77,    60,    35,    61,   103
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
      76,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    84,    85,    85,    86,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     3,     3,     3,
       4,     4,     5,     7,     8,     0,     1,     3,     2,     2,
       3,     8,    10,     9,    12,    11,     4,     3,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     4,     3,     1,
       3,     3,     1,     2,     2,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     2,     4,     5,     4,     5,
       7,     6,    10,     9,     9,     8,     7,     6,    13,    12,
      11,    10,    11,    15,     2,     3,     5,     2,     2,     3,
       2,     1,     1,     1,     1,    11,     6,    13,     7,     7,
       4,     2,     3,     6,     7,     7,     6,     7,     7,     6,
       6,     6,     2,     3,     1,     1,     3,     6,     5,     1,
       1,     1,     9,     5,    11,     6,     5,     3,     1,     1,
       1,     1,     1
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
#line 1804 "myparser.tab.c"
    break;

  case 3:
#line 109 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1810 "myparser.tab.c"
    break;

  case 4:
#line 110 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1816 "myparser.tab.c"
    break;

  case 5:
#line 111 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1822 "myparser.tab.c"
    break;

  case 6:
#line 112 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1828 "myparser.tab.c"
    break;

  case 7:
#line 113 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1834 "myparser.tab.c"
    break;

  case 8:
#line 114 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1840 "myparser.tab.c"
    break;

  case 9:
#line 115 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1846 "myparser.tab.c"
    break;

  case 10:
#line 116 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1852 "myparser.tab.c"
    break;

  case 11:
#line 117 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1858 "myparser.tab.c"
    break;

  case 12:
#line 118 "myparser.y"
                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1864 "myparser.tab.c"
    break;

  case 13:
#line 122 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1870 "myparser.tab.c"
    break;

  case 14:
#line 123 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1876 "myparser.tab.c"
    break;

  case 15:
#line 127 "myparser.y"
               {(yyval.str) = template("");}
#line 1882 "myparser.tab.c"
    break;

  case 16:
#line 128 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1888 "myparser.tab.c"
    break;

  case 17:
#line 129 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1894 "myparser.tab.c"
    break;

  case 18:
#line 133 "myparser.y"
                              {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1900 "myparser.tab.c"
    break;

  case 19:
#line 141 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1906 "myparser.tab.c"
    break;

  case 20:
#line 142 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1912 "myparser.tab.c"
    break;

  case 21:
#line 146 "myparser.y"
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
#line 1933 "myparser.tab.c"
    break;

  case 22:
#line 162 "myparser.y"
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
#line 1954 "myparser.tab.c"
    break;

  case 23:
#line 178 "myparser.y"
                                                                                   {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-7].str);
			numOfCompFuncs ++;
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
#line 1975 "myparser.tab.c"
    break;

  case 24:
#line 194 "myparser.y"
                                                                                                                                {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-10].str);
			numOfCompFuncs ++;
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
#line 1997 "myparser.tab.c"
    break;

  case 25:
#line 211 "myparser.y"
                                                                                                              {
		if (insideCompDecl == 1){
			comp_funcs[numOfCompFuncs] = (yyvsp[-9].str);
			numOfCompFuncs ++;
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
#line 2018 "myparser.tab.c"
    break;

  case 26:
#line 231 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2024 "myparser.tab.c"
    break;

  case 27:
#line 232 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2030 "myparser.tab.c"
    break;

  case 28:
#line 236 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2036 "myparser.tab.c"
    break;

  case 29:
#line 237 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2042 "myparser.tab.c"
    break;

  case 30:
#line 241 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2048 "myparser.tab.c"
    break;

  case 31:
#line 242 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2054 "myparser.tab.c"
    break;

  case 34:
#line 248 "myparser.y"
                        {
				if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
							yyerror("Comp variables are preceded by # ");
				}else {(yyval.str) = template("%s", (yyvsp[0].str));}
				}
#line 2064 "myparser.tab.c"
    break;

  case 35:
#line 253 "myparser.y"
                        {
					if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
							(yyval.str) = template("self->%s", (yyvsp[0].str));
					}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
					}
#line 2074 "myparser.tab.c"
    break;

  case 37:
#line 259 "myparser.y"
                        {(yyval.str) = template("0");}
#line 2080 "myparser.tab.c"
    break;

  case 38:
#line 260 "myparser.y"
                        {(yyval.str) = template("1");}
#line 2086 "myparser.tab.c"
    break;

  case 39:
#line 261 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2092 "myparser.tab.c"
    break;

  case 40:
#line 262 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2098 "myparser.tab.c"
    break;

  case 41:
#line 263 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 2104 "myparser.tab.c"
    break;

  case 42:
#line 264 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2110 "myparser.tab.c"
    break;

  case 43:
#line 265 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2116 "myparser.tab.c"
    break;

  case 44:
#line 266 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2122 "myparser.tab.c"
    break;

  case 45:
#line 267 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2128 "myparser.tab.c"
    break;

  case 46:
#line 268 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2134 "myparser.tab.c"
    break;

  case 47:
#line 269 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2140 "myparser.tab.c"
    break;

  case 48:
#line 270 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2146 "myparser.tab.c"
    break;

  case 49:
#line 271 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2152 "myparser.tab.c"
    break;

  case 50:
#line 272 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2158 "myparser.tab.c"
    break;

  case 51:
#line 273 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2164 "myparser.tab.c"
    break;

  case 52:
#line 274 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2170 "myparser.tab.c"
    break;

  case 53:
#line 275 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2176 "myparser.tab.c"
    break;

  case 54:
#line 276 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 2182 "myparser.tab.c"
    break;

  case 55:
#line 277 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2188 "myparser.tab.c"
    break;

  case 56:
#line 278 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 2194 "myparser.tab.c"
    break;

  case 57:
#line 279 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2200 "myparser.tab.c"
    break;

  case 58:
#line 280 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2206 "myparser.tab.c"
    break;

  case 59:
#line 281 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2212 "myparser.tab.c"
    break;

  case 60:
#line 285 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2218 "myparser.tab.c"
    break;

  case 61:
#line 286 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2224 "myparser.tab.c"
    break;

  case 62:
#line 287 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2230 "myparser.tab.c"
    break;

  case 63:
#line 288 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2236 "myparser.tab.c"
    break;

  case 64:
#line 289 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2242 "myparser.tab.c"
    break;

  case 65:
#line 295 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2248 "myparser.tab.c"
    break;

  case 66:
#line 296 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2254 "myparser.tab.c"
    break;

  case 67:
#line 300 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2260 "myparser.tab.c"
    break;

  case 68:
#line 301 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2266 "myparser.tab.c"
    break;

  case 69:
#line 302 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2272 "myparser.tab.c"
    break;

  case 70:
#line 303 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2278 "myparser.tab.c"
    break;

  case 71:
#line 304 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2284 "myparser.tab.c"
    break;

  case 72:
#line 305 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2290 "myparser.tab.c"
    break;

  case 73:
#line 306 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2296 "myparser.tab.c"
    break;

  case 74:
#line 307 "myparser.y"
                                                    {(yyval.str) = template("%s.%s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2302 "myparser.tab.c"
    break;

  case 75:
#line 308 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2308 "myparser.tab.c"
    break;

  case 76:
#line 309 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2314 "myparser.tab.c"
    break;

  case 77:
#line 310 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2320 "myparser.tab.c"
    break;

  case 78:
#line 311 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2326 "myparser.tab.c"
    break;

  case 79:
#line 312 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2332 "myparser.tab.c"
    break;

  case 80:
#line 313 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2338 "myparser.tab.c"
    break;

  case 81:
#line 314 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2344 "myparser.tab.c"
    break;

  case 82:
#line 315 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2350 "myparser.tab.c"
    break;

  case 83:
#line 316 "myparser.y"
              {(yyval.str) = template("");}
#line 2356 "myparser.tab.c"
    break;

  case 84:
#line 320 "myparser.y"
                 { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
			   		yyerror("Comp variables are preceded by # ");
			   }else {(yyval.str) = template("%s", (yyvsp[0].str));}
			 }
#line 2365 "myparser.tab.c"
    break;

  case 85:
#line 324 "myparser.y"
                       { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
			   			(yyval.str) = template("self->%s", (yyvsp[0].str));
			   		}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		 }
#line 2374 "myparser.tab.c"
    break;

  case 86:
#line 328 "myparser.y"
                                        { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
									}
#line 2383 "myparser.tab.c"
    break;

  case 87:
#line 332 "myparser.y"
                                           {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
										}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2392 "myparser.tab.c"
    break;

  case 88:
#line 336 "myparser.y"
                                    { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
		}
#line 2401 "myparser.tab.c"
    break;

  case 89:
#line 340 "myparser.y"
                                        {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
									}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2410 "myparser.tab.c"
    break;

  case 90:
#line 347 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2416 "myparser.tab.c"
    break;

  case 91:
#line 348 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2422 "myparser.tab.c"
    break;

  case 92:
#line 349 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2428 "myparser.tab.c"
    break;

  case 93:
#line 350 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2434 "myparser.tab.c"
    break;

  case 94:
#line 351 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2440 "myparser.tab.c"
    break;

  case 95:
#line 352 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2446 "myparser.tab.c"
    break;

  case 96:
#line 359 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2452 "myparser.tab.c"
    break;

  case 97:
#line 360 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2458 "myparser.tab.c"
    break;

  case 98:
#line 364 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2464 "myparser.tab.c"
    break;

  case 99:
#line 365 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2470 "myparser.tab.c"
    break;

  case 100:
#line 366 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2476 "myparser.tab.c"
    break;

  case 101:
#line 367 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2482 "myparser.tab.c"
    break;

  case 102:
#line 372 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2488 "myparser.tab.c"
    break;

  case 103:
#line 377 "myparser.y"
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
#line 2503 "myparser.tab.c"
    break;

  case 104:
#line 390 "myparser.y"
                             {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 2509 "myparser.tab.c"
    break;

  case 105:
#line 391 "myparser.y"
                                                 {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2515 "myparser.tab.c"
    break;

  case 106:
#line 396 "myparser.y"
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
#line 2542 "myparser.tab.c"
    break;

  case 107:
#line 423 "myparser.y"
                                              {(yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2548 "myparser.tab.c"
    break;

  case 108:
#line 427 "myparser.y"
                                 {(yyval.str) = template("%s;", (yyvsp[-1].str)); insideCompDecl = 1;}
#line 2554 "myparser.tab.c"
    break;

  case 109:
#line 428 "myparser.y"
                                                         { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2560 "myparser.tab.c"
    break;

  case 110:
#line 433 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str)); comp_vars[numOfCompVars] = comp_var_name; numOfCompVars++;}
#line 2566 "myparser.tab.c"
    break;

  case 111:
#line 434 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2572 "myparser.tab.c"
    break;

  case 112:
#line 438 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2578 "myparser.tab.c"
    break;

  case 113:
#line 439 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2584 "myparser.tab.c"
    break;

  case 114:
#line 440 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2590 "myparser.tab.c"
    break;

  case 115:
#line 444 "myparser.y"
                                                                    {	if(isStr == 1){
																		(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
																	else{
																		(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
																	}
										comp_vars[numOfCompVars] = (yyvsp[-9].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										}
#line 2604 "myparser.tab.c"
    break;

  case 116:
#line 453 "myparser.y"
                                                     {	if(isStr == 1){
														(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
													else{
														(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										}
#line 2617 "myparser.tab.c"
    break;

  case 117:
#line 464 "myparser.y"
                                                                                            {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										comp_vars[numOfCompVars] = (yyvsp[-11].str); numOfCompVars++;
										comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
										}
#line 2631 "myparser.tab.c"
    break;

  case 118:
#line 473 "myparser.y"
                                                                {	if(isStr == 1){
																	(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
																else{
																	(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
								comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
								}
#line 2644 "myparser.tab.c"
    break;

  case 119:
#line 484 "myparser.y"
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
#line 2661 "myparser.tab.c"
    break;

  case 120:
#line 496 "myparser.y"
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
#line 2677 "myparser.tab.c"
    break;

  case 121:
#line 525 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2683 "myparser.tab.c"
    break;

  case 122:
#line 526 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2689 "myparser.tab.c"
    break;

  case 123:
#line 530 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2695 "myparser.tab.c"
    break;

  case 124:
#line 531 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2701 "myparser.tab.c"
    break;

  case 125:
#line 532 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2707 "myparser.tab.c"
    break;

  case 126:
#line 533 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2713 "myparser.tab.c"
    break;

  case 127:
#line 534 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2719 "myparser.tab.c"
    break;

  case 128:
#line 535 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2725 "myparser.tab.c"
    break;

  case 129:
#line 536 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2731 "myparser.tab.c"
    break;

  case 130:
#line 537 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2737 "myparser.tab.c"
    break;

  case 131:
#line 538 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2743 "myparser.tab.c"
    break;

  case 132:
#line 543 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2749 "myparser.tab.c"
    break;

  case 133:
#line 544 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2755 "myparser.tab.c"
    break;

  case 134:
#line 548 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2761 "myparser.tab.c"
    break;

  case 135:
#line 549 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2767 "myparser.tab.c"
    break;

  case 136:
#line 553 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else{
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
							comp_var_name = (yyvsp[-2].str);	//maybe not a comp var, but i need it if it is
							 }
#line 2778 "myparser.tab.c"
    break;

  case 137:
#line 559 "myparser.y"
                                                     {	(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));	comp_var_name = (yyvsp[-5].str);}
#line 2784 "myparser.tab.c"
    break;

  case 138:
#line 560 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str)); comp_var_name = (yyvsp[-4].str);}
#line 2790 "myparser.tab.c"
    break;

  case 139:
#line 564 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2796 "myparser.tab.c"
    break;

  case 140:
#line 565 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2802 "myparser.tab.c"
    break;

  case 141:
#line 566 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2808 "myparser.tab.c"
    break;

  case 142:
#line 570 "myparser.y"
                                                            {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2819 "myparser.tab.c"
    break;

  case 143:
#line 576 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2830 "myparser.tab.c"
    break;

  case 144:
#line 585 "myparser.y"
                                                                                    {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2841 "myparser.tab.c"
    break;

  case 145:
#line 591 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2852 "myparser.tab.c"
    break;

  case 146:
#line 600 "myparser.y"
                                            {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2866 "myparser.tab.c"
    break;

  case 147:
#line 609 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2880 "myparser.tab.c"
    break;

  case 148:
#line 621 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2886 "myparser.tab.c"
    break;

  case 149:
#line 622 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0; isStr = 0;}
#line 2892 "myparser.tab.c"
    break;

  case 150:
#line 623 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0; isStr = 1;}
#line 2898 "myparser.tab.c"
    break;

  case 151:
#line 624 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2904 "myparser.tab.c"
    break;

  case 152:
#line 625 "myparser.y"
                   { isStr = 0;
					if(find_comp((yyvsp[0].str), "comps") == 1){		//allow Comp data_type only if it is already declared 
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 2918 "myparser.tab.c"
    break;


#line 2922 "myparser.tab.c"

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
#line 637 "myparser.y"

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


