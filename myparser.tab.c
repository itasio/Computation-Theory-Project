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
#define YYLAST   1207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  405

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
     254,   255,   259,   260,   261,   266,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   304,   316,
     317,   321,   322,   323,   324,   325,   331,   332,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   356,   360,   365,   369,   373,
     377,   381,   385,   392,   393,   394,   395,   396,   397,   404,
     405,   409,   410,   411,   412,   416,   421,   435,   436,   440,
     468,   472,   473,   478,   482,   486,   487,   488,   492,   503,
     515,   526,   538,   552,   582,   583,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   600,   601,   605,   606,   610,
     616,   617,   621,   622,   623,   627,   633,   642,   648,   657,
     666,   678,   679,   680,   681,   682
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

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    80,    19,    30,    46,    62,  -143,    51,    45,    14,
      49,    22,    55,    15,   101,  -143,  -143,  -143,  -143,  -143,
       1,   211,   100,   128,   140,   158,   150,  -143,  -143,   154,
    -143,  -143,    51,   159,    81,    38,  -143,  -143,    51,   160,
      38,  -143,  -143,    51,   167,  -143,   152,   -27,  -143,  -143,
    -143,  -143,  -143,  -143,    39,  -143,   236,   182,   156,   186,
    -143,  -143,  -143,    38,   252,    51,  -143,  -143,    51,  -143,
    -143,    53,   211,   253,   211,   -28,  -143,   200,   204,   208,
     213,   217,   221,   117,   176,   269,   255,   -13,   222,  -143,
    -143,  -143,  -143,    51,  -143,  -143,   211,   282,  -143,   229,
    -143,  -143,    -9,   236,   399,   268,   264,   259,   258,   261,
     235,   242,   244,   245,   135,  -143,  -143,   283,   256,  -143,
    -143,  -143,   248,  -143,   266,   211,   179,   254,  -143,    74,
     310,   267,   270,   271,   281,   285,  -143,   325,   277,   312,
     678,  -143,   313,   286,   287,   295,   299,   300,   475,   475,
    -143,  -143,  -143,  -143,  -143,   336,   320,   349,   345,     7,
     309,  -143,   370,    64,  -143,   315,    37,   418,   319,   296,
      11,   350,  -143,  -143,  -143,   387,   387,   323,  -143,   322,
      31,  -143,   387,   387,   387,   387,   387,   387,   387,   382,
    -143,  -143,  -143,  -143,  -143,   678,   691,   678,   488,  -143,
    -143,  -143,  -143,   326,    65,   384,  -143,   334,   211,   365,
    -143,   335,   387,   358,   387,   168,  -143,  -143,  -143,   387,
    -143,  -143,   387,   387,   387,  -143,   396,  -143,    41,  1065,
     340,   341,   400,   346,   306,  1065,   331,    23,  -143,    25,
     719,   743,   769,   793,   819,   843,   362,   347,   348,   678,
     678,    77,   351,   165,   205,  -143,  -143,   378,   869,   387,
    1088,   387,  1135,    13,    13,  1041,   354,  -143,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,  -143,    53,   356,   387,   353,  1065,
     357,   360,   368,   414,   374,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,   361,   436,  -143,   211,   211,  -143,   409,
     893,   440,   969,  -143,   387,  1065,    13,  1151,  1151,   137,
     137,  1135,  1112,   137,   137,    98,    98,    13,    13,    13,
    -143,  -143,   943,   432,   501,  -143,  -143,   385,  -143,   444,
    -143,   390,  -143,  -143,  -143,   419,   392,  -143,   993,   387,
     398,  -143,   451,  -143,   525,  -143,   401,   404,  -143,   220,
    -143,   919,   538,   406,  -143,  -143,   461,   212,   408,   443,
     415,   387,  -143,   551,   573,   417,   211,   422,   466,   595,
    1017,  -143,  -143,   608,   216,  -143,   211,   447,  -143,   621,
     423,  -143,   211,  -143,   482,  -143,   643,  -143,   427,  -143,
     665,   434,  -143,   211,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,   144,   143,   142,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      19,     6,     0,     0,     0,     0,   107,     5,     0,     0,
       0,   124,     4,     0,     0,   135,     0,     0,   155,   151,
     152,   153,   154,   139,     0,   150,    15,     0,     0,     0,
      20,     8,   108,     0,     0,     0,     7,   125,     0,     9,
     136,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     117,   116,   115,     0,    11,    10,     0,     0,   141,     0,
     146,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   109,   110,     0,   111,
      12,   140,     0,   148,     0,     0,     0,     0,    17,    85,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
      63,    66,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   126,   132,   133,   134,     0,     0,     0,     0,     0,
       0,   112,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    13,     0,     0,    86,    76,     0,
      85,    67,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    79,    78,    82,    83,    65,     0,    64,     0,   130,
     127,   131,   128,     0,     0,     0,   123,     0,     0,     0,
      21,     0,     0,     0,     0,    34,    32,    33,    36,     0,
      38,    37,     0,     0,     0,    27,     0,    60,     0,    28,
       0,     0,     0,     0,     0,    30,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      61,     0,     0,     0,     0,   145,    23,     0,     0,     0,
       0,     0,    41,    55,    54,     0,    35,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    87,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    69,    70,    71,    73,    72,
      74,    68,    75,     0,     0,   119,     0,     0,    22,     0,
       0,     0,     0,    56,     0,    29,    53,    43,    42,    45,
      44,    40,    39,    46,    47,    48,    49,    50,    51,    52,
      59,    92,     0,     0,     0,    91,    88,     0,    87,     0,
     121,     0,   122,   147,    25,     0,     0,    57,     0,     0,
       0,    94,     0,   100,     0,    90,     0,     0,    24,     0,
      58,     0,     0,     0,    93,    99,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,     0,   118,     0,     0,   104,     0,
       0,    95,     0,   105,     0,   103,     0,   120,     0,   102,
       0,     0,   101,     0,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   251,  -143,  -143,    61,    91,  -103,  -143,   -91,
    -104,   -94,  -142,  -137,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   479,  -143,  -143,   410,  -143,   241,   197,   342,     4,
      -3,    10,     3,   416,  -143,   433,   411,   485,   -72
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
      98,   138,   101,   181,    11,    46,   195,   197,    39,   125,
      13,   203,    64,    34,   230,   231,    44,     1,     1,    35,
     269,    40,    23,   138,   121,     1,   291,   292,   230,   294,
     102,    39,   166,    25,    72,   103,    73,   138,    44,     2,
       2,     1,     3,    44,    63,   138,   138,     2,   168,    26,
       3,    85,   126,   164,   249,    24,   250,     4,   181,    76,
     181,    47,    27,    64,   138,   229,    44,   204,   210,   283,
      32,    47,    38,   213,    43,   232,     2,   211,   240,   241,
     242,   243,   244,   245,     1,   236,   248,   293,   169,   232,
     239,   168,   138,   138,   138,   138,    65,   246,    29,   267,
      74,    68,    22,    54,   268,   269,   128,    30,   258,     3,
     260,    36,   181,   181,    96,   262,    97,    41,   263,   264,
     265,   110,   111,    29,    93,   208,    72,    73,   252,    29,
     289,   169,   289,   170,    29,    21,   255,    22,    96,    20,
     303,    21,   289,    22,   269,    39,   138,   138,   117,   280,
     281,   282,    44,   198,   283,   310,    29,   312,   196,    29,
      78,    79,    80,    45,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     112,   113,   129,   332,    29,    56,   278,   279,   280,   281,
     282,   352,   354,   283,   159,    39,    21,    57,   160,    44,
      81,    82,   130,   131,    58,    83,    84,     3,    29,   132,
     348,    59,    71,   134,    48,   181,    60,   181,   135,   165,
     373,    62,    67,    48,   368,   169,   306,   261,   160,    70,
     138,   138,   383,    49,   342,   343,   181,   389,    50,     1,
      77,   136,    49,   137,    51,   361,   181,    50,    52,   138,
      85,   138,   181,    51,   400,    23,    99,    52,    28,   138,
      31,   104,    37,   181,    42,   105,   307,   380,    97,   106,
     138,   138,   114,   376,   107,   252,   138,   392,   108,   303,
     138,   116,   109,    61,   119,   122,   138,   369,   124,    66,
     150,   151,   152,   138,    69,   153,   155,   138,   154,   215,
     216,   217,   218,   156,   385,   157,   158,   162,    64,   215,
     216,   217,   218,   171,   393,   167,    94,   219,   161,    95,
     397,   182,   183,   184,   185,   186,   163,   219,   177,   172,
     187,   404,   173,   174,   215,   216,   217,   218,   175,   178,
     220,   221,   176,   179,   120,   222,   223,   200,   190,   191,
     220,   221,   219,   224,   225,   222,   223,   192,   199,   188,
     226,   193,   194,   224,   288,   215,   216,   217,   218,   189,
     226,   201,   202,   205,   207,   220,   221,   209,   214,   233,
     222,   223,   237,   219,   238,   247,   251,   253,   224,   290,
     215,   216,   217,   218,   254,   226,   256,   257,   259,   266,
     284,   285,   129,   286,   169,   287,   220,   221,   219,   308,
     302,   222,   223,   314,   333,   304,   331,   337,   334,   224,
     335,   129,   130,   131,   301,   339,   226,     3,   336,   132,
     133,   220,   221,   134,   338,   180,   222,   223,   135,   341,
     344,   130,   131,   346,   224,   355,     3,   356,   132,   357,
     358,   226,   134,   359,   180,   130,   131,   135,   212,   362,
     366,   136,   132,   137,   367,   375,   134,   374,   377,   387,
     350,   135,   378,   351,   130,   131,   379,   384,   129,   394,
     136,   132,   137,   386,   396,   134,   398,   401,    33,   363,
     135,   180,   364,   305,   136,   403,   137,   118,   130,   131,
     340,   115,   206,     3,   180,   132,   100,    55,   123,   134,
       0,   130,   131,   136,   135,   137,     3,     0,   132,     0,
       0,     0,   134,     0,   130,   131,     0,   135,   180,     0,
       0,   132,     0,     0,     0,   134,     0,   136,     0,   137,
     135,   180,     0,   353,     0,     0,     0,     0,   130,   131,
     136,     0,   137,     0,   180,   132,     0,     0,     0,   134,
       0,   130,   131,   136,   135,   137,     0,   365,   132,     0,
       0,     0,   134,     0,   130,   131,   180,   135,     0,   372,
       0,   132,     0,     0,     0,   134,     0,   136,     0,   137,
     135,     0,   381,     0,     0,     0,   130,   131,   180,     0,
     136,     0,   137,   132,     0,     0,     0,   134,     0,     0,
       0,   180,   135,   136,   382,   137,     0,     0,   130,   131,
       0,     0,     0,     0,   180,   132,     0,     0,     0,   134,
     388,   130,   131,     0,   135,   136,     0,   137,   132,     0,
       0,     0,   134,     0,   130,   131,   180,   135,     0,   391,
       0,   132,     0,     0,     0,   134,   395,   136,     0,   137,
     135,     0,     0,     0,     0,     0,   130,   131,   180,     0,
     136,     0,   137,   132,     0,     0,     0,   134,   399,     0,
       0,   180,   135,   136,     0,   137,     0,     0,   130,   131,
       0,     0,     0,     0,   129,   132,     0,     0,     0,   134,
     402,   130,   131,     0,   135,   136,     0,   137,   132,     0,
       0,     0,   134,     0,   130,   131,     0,   135,     0,     0,
       0,   132,     0,     0,     0,   134,   269,   136,     0,   137,
     135,     0,   270,   271,   272,   273,     0,     0,   274,   275,
     136,     0,   137,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,   136,     0,   137,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,     0,
       0,   295,   270,   271,   272,   273,     0,     0,   274,   275,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,     0,   296,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,     0,
       0,   297,   270,   271,   272,   273,     0,     0,   274,   275,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,     0,   298,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,     0,
       0,   299,   270,   271,   272,   273,     0,     0,   274,   275,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,     0,   300,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,     0,
       0,   309,   270,   271,   272,   273,     0,     0,   274,   275,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,     0,   345,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   283,   269,     0,     0,   370,
     371,     0,   270,   271,   272,   273,     0,     0,   274,   275,
     276,   277,   278,   279,   280,   281,   282,     0,     0,   283,
     269,     0,     0,     0,   349,     0,   270,   271,   272,   273,
       0,     0,   274,   275,     0,     0,   276,   277,   278,   279,
     280,   281,   282,     0,   269,   283,     0,     0,     0,   347,
     270,   271,   272,   273,     0,     0,   274,   275,     0,     0,
     276,   277,   278,   279,   280,   281,   282,     0,   269,   283,
       0,     0,     0,   360,   270,   271,   272,   273,     0,     0,
     274,   275,     0,     0,   276,   277,   278,   279,   280,   281,
     282,     0,   269,   283,     0,     0,     0,   390,   270,   271,
     272,   273,     0,     0,   274,   275,     0,     0,   276,   277,
     278,   279,   280,   281,   282,   269,     0,   283,     0,   313,
       0,   270,   271,   272,   273,     0,     0,   274,   275,     0,
       0,   311,   276,   277,   278,   279,   280,   281,   282,   269,
       0,   283,     0,     0,     0,   270,   271,   272,   273,     0,
       0,   274,     0,     0,     0,   276,   277,   278,   279,   280,
     281,   282,   269,     0,   283,     0,     0,     0,   270,   271,
     272,   273,     0,     0,     0,     0,     0,     0,   269,   276,
     277,   278,   279,   280,   281,   282,   272,   273,   283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   277,   278,   279,   280,   281,   282,     0,
       0,   283,     0,     0,     0,     0,     0,     0,   276,   277,
     278,   279,   280,   281,   282,     0,     0,   283
};

static const yytype_int16 yycheck[] =
{
      72,   104,    74,   140,     0,     4,   148,   149,    11,    18,
       0,     4,    25,     9,     3,     4,    13,     3,     3,     9,
       7,    11,     3,   126,    96,     3,     3,     4,     3,     4,
      58,    34,   126,     3,    61,    63,    63,   140,    35,    25,
      25,     3,    28,    40,    34,   148,   149,    25,    17,     3,
      28,    64,    61,   125,   196,    36,   198,    43,   195,    56,
     197,    60,     0,    25,   167,   169,    63,    60,    31,    56,
       9,    60,    11,   167,    13,    64,    25,    40,   182,   183,
     184,   185,   186,   187,     3,   176,   189,    64,    57,    64,
      59,    17,   195,   196,   197,   198,    35,   188,     7,    58,
      61,    40,    63,     3,    63,     7,   103,    62,   212,    28,
     214,    62,   249,   250,    61,   219,    63,    62,   222,   223,
     224,     4,     5,    32,    63,    61,    61,    63,    63,    38,
     234,    57,   236,    59,    43,    61,   208,    63,    61,    59,
      63,    61,   246,    63,     7,   148,   249,   250,    87,    51,
      52,    53,   149,   149,    56,   259,    65,   261,   148,    68,
       4,     5,     6,    62,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       4,     5,     3,   287,    93,    57,    49,    50,    51,    52,
      53,   333,   334,    56,    59,   198,    61,    57,    63,   196,
      44,    45,    23,    24,    46,    49,    50,    28,   117,    30,
     314,    61,    60,    34,     3,   352,    62,   354,    39,    40,
     362,    62,    62,     3,     4,    57,    61,    59,    63,    62,
     333,   334,   374,    22,   306,   307,   373,   379,    27,     3,
      58,    62,    22,    64,    33,   349,   383,    27,    37,   352,
      64,   354,   389,    33,   396,     3,     3,    37,     7,   362,
       9,    61,    11,   400,    13,    61,    61,   371,    63,    61,
     373,   374,     3,    61,    61,    63,   379,    61,    61,    63,
     383,    26,    61,    32,    62,     3,   389,   359,    59,    38,
      22,    27,    33,   396,    43,    37,    61,   400,    37,     3,
       4,     5,     6,    61,   376,    61,    61,    59,    25,     3,
       4,     5,     6,     3,   386,    61,    65,    21,    62,    68,
     392,     8,     9,    10,    11,    12,    60,    21,     3,    62,
      17,   403,    62,    62,     3,     4,     5,     6,    57,    62,
      44,    45,    57,    31,    93,    49,    50,    27,    62,    62,
      44,    45,    21,    57,    58,    49,    50,    62,    22,    46,
      64,    62,    62,    57,    58,     3,     4,     5,     6,    56,
      64,    22,    27,    64,     4,    44,    45,    62,    59,    29,
      49,    50,    59,    21,    62,     3,    60,     3,    57,    58,
       3,     4,     5,     6,    60,    64,    31,    62,    40,     3,
      60,    60,     3,     3,    57,    59,    44,    45,    21,    31,
      62,    49,    50,    59,    61,    64,    60,     3,    61,    57,
      60,     3,    23,    24,    62,    64,    64,    28,    60,    30,
      31,    44,    45,    34,    60,     3,    49,    50,    39,     3,
      31,    23,    24,     3,    57,    60,    28,     3,    30,    59,
      31,    64,    34,    61,     3,    23,    24,    39,    40,    61,
      59,    62,    30,    64,    60,     4,    34,    61,    60,     3,
      38,    39,    29,    41,    23,    24,    61,    60,     3,    32,
      62,    30,    64,    61,    61,    34,     4,    60,     9,    38,
      39,     3,    41,   252,    62,    61,    64,    87,    23,    24,
     303,    85,   160,    28,     3,    30,    73,    22,    97,    34,
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
      53,    -1,     7,    56,    -1,    -1,    -1,    60,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,     7,    -1,    56,    -1,    58,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    23,    47,    48,    49,    50,    51,    52,    53,     7,
      -1,    56,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,     7,    -1,    56,    -1,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,     7,    47,
      48,    49,    50,    51,    52,    53,    15,    16,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56
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
      75,    75,    75,    75,    75,    75,    74,     3,    72,    77,
      77,    60,    63,     3,    60,   103,    31,    62,    75,    40,
      75,    59,    75,    75,    75,    75,     3,    58,    63,     7,
      13,    14,    15,    16,    19,    20,    47,    48,    49,    50,
      51,    52,    53,    56,    60,    60,     3,    59,    58,    75,
      58,     3,     4,    64,     4,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    64,    91,    61,    61,    31,    62,
      75,    23,    75,    58,    59,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    60,    75,    61,    61,    60,    60,     3,    60,    64,
      92,     3,   103,   103,    31,    62,     3,    60,    75,    61,
      38,    41,    77,    42,    77,    60,     3,    59,    31,    61,
      60,    75,    61,    38,    41,    42,    59,    60,     4,   103,
      60,    61,    41,    77,    61,     4,    61,    60,    29,    61,
      75,    41,    41,    77,    60,   103,    61,     3,    35,    77,
      60,    41,    61,   103,    32,    35,    61,   103,     4,    35,
      77,    60,    35,    61,   103
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
      78,    78,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    83,    84,    85,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103
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
       4,     4,     4,     4,     4,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     2,     4,     5,     4,
       6,     5,     5,     7,     6,    10,     9,     9,     8,     7,
       6,    13,    12,    11,    10,    11,    15,     2,     3,     5,
       2,     2,     3,     2,     1,     1,     1,     1,    11,     6,
      13,     7,     7,     4,     2,     3,     6,     7,     7,     6,
       7,     7,     6,     6,     6,     2,     3,     1,     1,     3,
       6,     5,     1,     1,     1,     9,     5,    11,     6,     5,
       3,     1,     1,     1,     1,     1
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
#line 1814 "myparser.tab.c"
    break;

  case 3:
#line 112 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1820 "myparser.tab.c"
    break;

  case 4:
#line 113 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1826 "myparser.tab.c"
    break;

  case 5:
#line 114 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1832 "myparser.tab.c"
    break;

  case 6:
#line 115 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1838 "myparser.tab.c"
    break;

  case 7:
#line 116 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1844 "myparser.tab.c"
    break;

  case 8:
#line 117 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1850 "myparser.tab.c"
    break;

  case 9:
#line 118 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1856 "myparser.tab.c"
    break;

  case 10:
#line 119 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1862 "myparser.tab.c"
    break;

  case 11:
#line 120 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1868 "myparser.tab.c"
    break;

  case 12:
#line 121 "myparser.y"
                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1874 "myparser.tab.c"
    break;

  case 13:
#line 125 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1880 "myparser.tab.c"
    break;

  case 14:
#line 126 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1886 "myparser.tab.c"
    break;

  case 15:
#line 130 "myparser.y"
               {(yyval.str) = template("");}
#line 1892 "myparser.tab.c"
    break;

  case 16:
#line 131 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1898 "myparser.tab.c"
    break;

  case 17:
#line 132 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1904 "myparser.tab.c"
    break;

  case 18:
#line 136 "myparser.y"
                              {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1910 "myparser.tab.c"
    break;

  case 19:
#line 144 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1916 "myparser.tab.c"
    break;

  case 20:
#line 145 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1922 "myparser.tab.c"
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
#line 1945 "myparser.tab.c"
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
#line 1968 "myparser.tab.c"
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
#line 1991 "myparser.tab.c"
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
#line 2015 "myparser.tab.c"
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
#line 2038 "myparser.tab.c"
    break;

  case 26:
#line 244 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2044 "myparser.tab.c"
    break;

  case 27:
#line 245 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2050 "myparser.tab.c"
    break;

  case 28:
#line 249 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2056 "myparser.tab.c"
    break;

  case 29:
#line 250 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2062 "myparser.tab.c"
    break;

  case 30:
#line 254 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2068 "myparser.tab.c"
    break;

  case 31:
#line 255 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2074 "myparser.tab.c"
    break;

  case 34:
#line 261 "myparser.y"
                        {
				if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
							yyerror("Comp variables are preceded by # ");
				}else {(yyval.str) = template("%s", (yyvsp[0].str));}
				}
#line 2084 "myparser.tab.c"
    break;

  case 35:
#line 266 "myparser.y"
                        {
					if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
							(yyval.str) = template("self->%s", (yyvsp[0].str));
					}else if ((insideCompDecl == 1) && (find_comp((yyvsp[0].str), "all_comp_vars"))){
						//first if stmt will catch variables that belong to current
						//comp declaration
						//this if stmt will catch vars that belong to other comps
						(yyval.str) = template("%s", (yyvsp[0].str));
					}
					else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
					}
#line 2100 "myparser.tab.c"
    break;

  case 37:
#line 278 "myparser.y"
                        {(yyval.str) = template("0");}
#line 2106 "myparser.tab.c"
    break;

  case 38:
#line 279 "myparser.y"
                        {(yyval.str) = template("1");}
#line 2112 "myparser.tab.c"
    break;

  case 39:
#line 280 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2118 "myparser.tab.c"
    break;

  case 40:
#line 281 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2124 "myparser.tab.c"
    break;

  case 41:
#line 282 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 2130 "myparser.tab.c"
    break;

  case 42:
#line 283 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2136 "myparser.tab.c"
    break;

  case 43:
#line 284 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2142 "myparser.tab.c"
    break;

  case 44:
#line 285 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2148 "myparser.tab.c"
    break;

  case 45:
#line 286 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2154 "myparser.tab.c"
    break;

  case 46:
#line 287 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2160 "myparser.tab.c"
    break;

  case 47:
#line 288 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2166 "myparser.tab.c"
    break;

  case 48:
#line 289 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2172 "myparser.tab.c"
    break;

  case 49:
#line 290 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2178 "myparser.tab.c"
    break;

  case 50:
#line 291 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2184 "myparser.tab.c"
    break;

  case 51:
#line 292 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2190 "myparser.tab.c"
    break;

  case 52:
#line 293 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2196 "myparser.tab.c"
    break;

  case 53:
#line 294 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2202 "myparser.tab.c"
    break;

  case 54:
#line 295 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 2208 "myparser.tab.c"
    break;

  case 55:
#line 296 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2214 "myparser.tab.c"
    break;

  case 56:
#line 297 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 2220 "myparser.tab.c"
    break;

  case 57:
#line 298 "myparser.y"
                                { 
			if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
				yyerror("Comp variables are preceded by # ");
			}else {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
		
		}
#line 2231 "myparser.tab.c"
    break;

  case 58:
#line 304 "myparser.y"
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
#line 2248 "myparser.tab.c"
    break;

  case 59:
#line 316 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2254 "myparser.tab.c"
    break;

  case 60:
#line 317 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2260 "myparser.tab.c"
    break;

  case 61:
#line 321 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2266 "myparser.tab.c"
    break;

  case 62:
#line 322 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2272 "myparser.tab.c"
    break;

  case 63:
#line 323 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2278 "myparser.tab.c"
    break;

  case 64:
#line 324 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2284 "myparser.tab.c"
    break;

  case 65:
#line 325 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2290 "myparser.tab.c"
    break;

  case 66:
#line 331 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2296 "myparser.tab.c"
    break;

  case 67:
#line 332 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2302 "myparser.tab.c"
    break;

  case 68:
#line 336 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2308 "myparser.tab.c"
    break;

  case 69:
#line 337 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2314 "myparser.tab.c"
    break;

  case 70:
#line 338 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2320 "myparser.tab.c"
    break;

  case 71:
#line 339 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2326 "myparser.tab.c"
    break;

  case 72:
#line 340 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2332 "myparser.tab.c"
    break;

  case 73:
#line 341 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2338 "myparser.tab.c"
    break;

  case 74:
#line 342 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2344 "myparser.tab.c"
    break;

  case 75:
#line 343 "myparser.y"
                                                    {(yyval.str) = template("%s.%s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2350 "myparser.tab.c"
    break;

  case 76:
#line 344 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2356 "myparser.tab.c"
    break;

  case 77:
#line 345 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2362 "myparser.tab.c"
    break;

  case 78:
#line 346 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2368 "myparser.tab.c"
    break;

  case 79:
#line 347 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2374 "myparser.tab.c"
    break;

  case 80:
#line 348 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2380 "myparser.tab.c"
    break;

  case 81:
#line 349 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2386 "myparser.tab.c"
    break;

  case 82:
#line 350 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2392 "myparser.tab.c"
    break;

  case 83:
#line 351 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2398 "myparser.tab.c"
    break;

  case 84:
#line 352 "myparser.y"
              {(yyval.str) = template("");}
#line 2404 "myparser.tab.c"
    break;

  case 85:
#line 356 "myparser.y"
                 { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
			   		yyerror("Comp variables are preceded by # ");
			   }else {(yyval.str) = template("%s", (yyvsp[0].str));}
			 }
#line 2413 "myparser.tab.c"
    break;

  case 86:
#line 360 "myparser.y"
                       { if( (insideCompDecl == 1) && (find_comp((yyvsp[0].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
			   			(yyval.str) = template("self->%s", (yyvsp[0].str));
						
			   		}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		 }
#line 2423 "myparser.tab.c"
    break;

  case 87:
#line 365 "myparser.y"
                                        { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
									}
#line 2432 "myparser.tab.c"
    break;

  case 88:
#line 369 "myparser.y"
                                           {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
										}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2441 "myparser.tab.c"
    break;

  case 89:
#line 373 "myparser.y"
                                    { if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) ){ //if inside comp declaration and token is member of comp then error(should have '#')
										yyerror("Comp variables are preceded by # ");
									}else {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
		}
#line 2450 "myparser.tab.c"
    break;

  case 90:
#line 377 "myparser.y"
                                            {if( (insideCompDecl == 1) && (find_comp((yyvsp[-4].str), "comp_vars")) && (find_comp((yyvsp[-1].str), "comp_vars"))){ //if inside comp declaration and tokens are member of comp then correct
											(yyval.str) = template("self->%s[self->%s]",(yyvsp[-4].str), (yyvsp[-1].str));
									}else {yyerror("Only comp variables inside comp declarations are preceded by # ");}
		}
#line 2459 "myparser.tab.c"
    break;

  case 91:
#line 381 "myparser.y"
                                        {if( (insideCompDecl == 1) && (find_comp((yyvsp[-3].str), "comp_vars")) && (!find_comp((yyvsp[-1].str), "comp_vars")) ){ //if inside comp declaration, 1st token is member of comp and 2nd isn't then correct
											(yyval.str) = template("self->%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
#line 2468 "myparser.tab.c"
    break;

  case 92:
#line 385 "myparser.y"
                                        {if( (insideCompDecl == 1) && (!find_comp((yyvsp[-4].str), "comp_vars")) && (find_comp((yyvsp[-1].str), "comp_vars")) ){ //if inside comp declaration, 1st token not member of comp and 2nd is then correct
											(yyval.str) = template("%s[self->%s]",(yyvsp[-4].str), (yyvsp[-1].str));
									}else {yyerror("Comp variables inside comp declarations are preceded by # ");}
		}
#line 2477 "myparser.tab.c"
    break;

  case 93:
#line 392 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2483 "myparser.tab.c"
    break;

  case 94:
#line 393 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2489 "myparser.tab.c"
    break;

  case 95:
#line 394 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2495 "myparser.tab.c"
    break;

  case 96:
#line 395 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2501 "myparser.tab.c"
    break;

  case 97:
#line 396 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2507 "myparser.tab.c"
    break;

  case 98:
#line 397 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2513 "myparser.tab.c"
    break;

  case 99:
#line 404 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2519 "myparser.tab.c"
    break;

  case 100:
#line 405 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2525 "myparser.tab.c"
    break;

  case 101:
#line 409 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2531 "myparser.tab.c"
    break;

  case 102:
#line 410 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2537 "myparser.tab.c"
    break;

  case 103:
#line 411 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2543 "myparser.tab.c"
    break;

  case 104:
#line 412 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2549 "myparser.tab.c"
    break;

  case 105:
#line 417 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2555 "myparser.tab.c"
    break;

  case 106:
#line 422 "myparser.y"
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
#line 2570 "myparser.tab.c"
    break;

  case 107:
#line 435 "myparser.y"
                             {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 2576 "myparser.tab.c"
    break;

  case 108:
#line 436 "myparser.y"
                                                 {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2582 "myparser.tab.c"
    break;

  case 109:
#line 441 "myparser.y"
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
#line 2609 "myparser.tab.c"
    break;

  case 110:
#line 468 "myparser.y"
                                              {(yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2615 "myparser.tab.c"
    break;

  case 111:
#line 472 "myparser.y"
                                 {(yyval.str) = template("%s;", (yyvsp[-1].str)); insideCompDecl = 1;}
#line 2621 "myparser.tab.c"
    break;

  case 112:
#line 473 "myparser.y"
                                                         { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2627 "myparser.tab.c"
    break;

  case 113:
#line 478 "myparser.y"
                    {
				(yyval.str) = template("%s", (yyvsp[0].str)); comp_vars[numOfCompVars] = comp_var_name; numOfCompVars++;
				all_comp_vars[numOfAllCompVars] = comp_var_name; numOfAllCompVars++;
				}
#line 2636 "myparser.tab.c"
    break;

  case 114:
#line 482 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2642 "myparser.tab.c"
    break;

  case 115:
#line 486 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2648 "myparser.tab.c"
    break;

  case 116:
#line 487 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2654 "myparser.tab.c"
    break;

  case 117:
#line 488 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2660 "myparser.tab.c"
    break;

  case 118:
#line 492 "myparser.y"
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
#line 2676 "myparser.tab.c"
    break;

  case 119:
#line 503 "myparser.y"
                                                     {	if(isStr == 1){
														(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
													else{
														(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
													}
										comp_vars[numOfCompVars] = (yyvsp[-4].str); numOfCompVars++;
										all_comp_vars[numOfAllCompVars] = (yyvsp[-4].str); numOfAllCompVars++;
										}
#line 2690 "myparser.tab.c"
    break;

  case 120:
#line 515 "myparser.y"
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
#line 2706 "myparser.tab.c"
    break;

  case 121:
#line 526 "myparser.y"
                                                                {	if(isStr == 1){
																	(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
																else{
																	(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
																}
								comp_vars[numOfCompVars] = (yyvsp[-5].str); numOfCompVars++;
								all_comp_vars[numOfAllCompVars] = (yyvsp[-5].str); numOfAllCompVars++;
								}
#line 2720 "myparser.tab.c"
    break;

  case 122:
#line 538 "myparser.y"
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
#line 2739 "myparser.tab.c"
    break;

  case 123:
#line 552 "myparser.y"
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
#line 2756 "myparser.tab.c"
    break;

  case 124:
#line 582 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2762 "myparser.tab.c"
    break;

  case 125:
#line 583 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2768 "myparser.tab.c"
    break;

  case 126:
#line 587 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2774 "myparser.tab.c"
    break;

  case 127:
#line 588 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2780 "myparser.tab.c"
    break;

  case 128:
#line 589 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2786 "myparser.tab.c"
    break;

  case 129:
#line 590 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2792 "myparser.tab.c"
    break;

  case 130:
#line 591 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2798 "myparser.tab.c"
    break;

  case 131:
#line 592 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2804 "myparser.tab.c"
    break;

  case 132:
#line 593 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2810 "myparser.tab.c"
    break;

  case 133:
#line 594 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2816 "myparser.tab.c"
    break;

  case 134:
#line 595 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2822 "myparser.tab.c"
    break;

  case 135:
#line 600 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2828 "myparser.tab.c"
    break;

  case 136:
#line 601 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2834 "myparser.tab.c"
    break;

  case 137:
#line 605 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2840 "myparser.tab.c"
    break;

  case 138:
#line 606 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2846 "myparser.tab.c"
    break;

  case 139:
#line 610 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else{
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
							comp_var_name = (yyvsp[-2].str);	//maybe not a comp var, but i need it if it is
							 }
#line 2857 "myparser.tab.c"
    break;

  case 140:
#line 616 "myparser.y"
                                                     {	(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));	comp_var_name = (yyvsp[-5].str);}
#line 2863 "myparser.tab.c"
    break;

  case 141:
#line 617 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str)); comp_var_name = (yyvsp[-4].str);}
#line 2869 "myparser.tab.c"
    break;

  case 142:
#line 621 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2875 "myparser.tab.c"
    break;

  case 143:
#line 622 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2881 "myparser.tab.c"
    break;

  case 144:
#line 623 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2887 "myparser.tab.c"
    break;

  case 145:
#line 627 "myparser.y"
                                                            {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2898 "myparser.tab.c"
    break;

  case 146:
#line 633 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2909 "myparser.tab.c"
    break;

  case 147:
#line 642 "myparser.y"
                                                                                    {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2920 "myparser.tab.c"
    break;

  case 148:
#line 648 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2931 "myparser.tab.c"
    break;

  case 149:
#line 657 "myparser.y"
                                            {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2945 "myparser.tab.c"
    break;

  case 150:
#line 666 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2959 "myparser.tab.c"
    break;

  case 151:
#line 678 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2965 "myparser.tab.c"
    break;

  case 152:
#line 679 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0; isStr = 0;}
#line 2971 "myparser.tab.c"
    break;

  case 153:
#line 680 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0; isStr = 1;}
#line 2977 "myparser.tab.c"
    break;

  case 154:
#line 681 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2983 "myparser.tab.c"
    break;

  case 155:
#line 682 "myparser.y"
                   { isStr = 0;
					if(find_comp((yyvsp[0].str), "comps") == 1){		//allow Comp data_type only if it is already declared 
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 2997 "myparser.tab.c"
    break;


#line 3001 "myparser.tab.c"

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
#line 694 "myparser.y"

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


