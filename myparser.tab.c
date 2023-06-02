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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

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
       0,    94,    94,    95,    96,    97,    98,   102,   103,   107,
     108,   109,   113,   114,   115,   116,   121,   122,   126,   127,
     128,   129,   130,   135,   136,   140,   141,   145,   146,   150,
     151,   152,   153,   154,   155,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   187,   188,   189,   190,
     191,   197,   198,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     222,   223,   227,   228,   229,   230,   231,   232,   239,   240,
     244,   245,   246,   247,   251,   256,   270,   271,   275,   279,
     285,   286,   294,   295,   299,   300,   301,   305,   311,   320,
     326,   335,   344,   368,   369,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   386,   387,   391,   392,   396,   400,
     401,   405,   406,   407,   411,   417,   426,   432,   441,   450,
     462,   463,   464,   465,   466
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

#define YYPACT_NINF (-154)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,    61,     9,    14,    26,   103,  -154,    88,    73,     3,
      76,    10,    82,     7,   100,  -154,  -154,  -154,  -154,  -154,
      15,   235,   120,   108,   113,   128,   114,  -154,  -154,   116,
    -154,   121,    10,  -154,   129,     7,  -154,   179,    88,   144,
    -154,   151,   -13,  -154,  -154,  -154,  -154,  -154,  -154,   134,
    -154,   193,   165,   127,   166,  -154,  -154,     7,  -154,    88,
    -154,  -154,   142,   235,   226,   235,    19,  -154,   176,   185,
     204,   213,   214,   217,    32,    95,   278,   256,   166,   238,
    -154,  -154,  -154,  -154,    88,  -154,   235,   286,  -154,   245,
    -154,  -154,   -14,   193,    50,   275,   290,   272,   281,   287,
     266,   267,   279,   283,   181,  -154,  -154,   280,  -154,  -154,
    -154,   270,  -154,   289,    92,   170,   285,  -154,   262,   344,
     293,   299,   300,   294,   295,  -154,   302,   337,   442,  -154,
     486,   304,   308,   315,   316,   321,   292,   292,  -154,  -154,
    -154,  -154,  -154,   362,   358,   364,   361,    16,   325,  -154,
     386,   180,  -154,  -154,  -154,  -154,   330,    70,   224,   334,
     713,    12,   365,  -154,  -154,  -154,   534,   534,  -154,   343,
      -8,  -154,   534,   534,   534,   534,   534,   534,   534,  -154,
    -154,  -154,  -154,  -154,   442,   445,   442,   309,  -154,  -154,
    -154,  -154,   347,   192,   405,  -154,   351,   235,   381,  -154,
     354,   534,   380,   534,   167,  -154,  -154,  -154,   534,  -154,
    -154,   534,   534,   534,  -154,  -154,    53,   900,   367,   369,
     371,   732,   900,   762,  -154,   124,   473,   495,   545,   561,
     611,   627,   163,   442,   442,   198,   370,   227,   233,  -154,
    -154,   402,   677,   534,   923,   534,   970,    27,    27,   876,
    -154,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,  -154,   142,   534,
     388,   900,   390,   382,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   392,   449,  -154,   235,   235,  -154,   430,   693,   461,
     828,  -154,   900,    27,   986,   986,   136,   136,   970,   947,
     136,   136,    34,    34,    27,    27,    27,  -154,   802,   246,
     311,  -154,   464,  -154,   411,  -154,  -154,  -154,   440,   412,
    -154,   534,   413,  -154,   268,  -154,   333,   418,   431,  -154,
     617,   778,   335,   417,  -154,  -154,   479,   240,   439,   471,
     429,   534,  -154,   357,   376,   441,   235,   444,   503,   379,
     852,  -154,  -154,   398,   250,  -154,   235,   480,  -154,   401,
     452,  -154,   235,  -154,   512,  -154,   420,  -154,   457,  -154,
     423,   458,  -154,   235,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,   133,   132,   131,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      16,     0,     0,    96,     0,     0,   113,     0,     0,     0,
     124,     0,     0,   144,   140,   141,   142,   143,   128,     0,
     139,     9,     0,     0,     0,    17,    97,     0,   114,     0,
       4,   125,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
     103,   106,   105,   104,     0,     5,     0,     0,   130,     0,
     135,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,    98,     0,   100,     6,
     129,     0,   137,     0,     0,     0,     0,    11,    79,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    58,    61,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   115,
     121,   122,   123,     0,     0,     0,     0,     0,     0,   101,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     7,     0,     0,    75,     0,
      79,    62,     0,     0,     0,     0,     0,     0,     0,    70,
      72,    71,    76,    77,    60,     0,    59,     0,   119,   116,
     120,   117,     0,     0,     0,   112,     0,     0,     0,    18,
       0,     0,     0,     0,    31,    29,    30,    32,     0,    34,
      33,     0,     0,     0,    24,    55,     0,    25,     0,     0,
       0,     0,    27,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    56,     0,     0,     0,     0,   134,
      20,     0,     0,     0,     0,     0,    37,    51,    50,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    80,     0,
       0,    28,     0,     0,    64,    65,    66,    68,    67,    69,
      63,     0,     0,   108,     0,     0,    19,     0,     0,     0,
       0,    52,    26,    49,    39,    38,    41,    40,    36,    35,
      42,    43,    44,    45,    46,    47,    48,    54,     0,     0,
       0,    80,     0,   110,     0,   111,   136,    22,     0,     0,
      53,     0,     0,    83,     0,    89,     0,     0,     0,    21,
       0,     0,     0,     0,    82,    88,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,   107,     0,     0,    93,     0,
       0,    84,     0,    94,     0,    92,     0,   109,     0,    91,
       0,     0,    90,     0,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,     4,  -154,  -154,    -5,    20,   -93,  -154,  -153,
    -106,   -94,  -130,  -125,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   509,  -154,  -154,   450,  -154,   291,   249,   383,    24,
      -6,    28,     5,   460,  -154,   469,   447,   519,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    66,   116,     7,     8,   215,   216,   221,
     222,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       9,    10,    77,    78,    79,    80,    81,    82,    83,   136,
      12,   137,    14,    15,    16,    17,    18,    19,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,   126,    91,   171,   114,    34,   184,   186,    38,   159,
       1,    28,    23,     1,   223,   218,   219,    25,    39,    41,
     192,   157,   126,   110,    11,   232,    34,    29,    13,    26,
      59,     3,    37,    32,   252,   126,   100,   101,     3,    35,
      39,   252,    60,   126,   126,    24,     4,   115,    63,   160,
      64,   225,    84,   118,   217,   233,    67,   234,    29,   171,
      57,   171,    39,    85,   202,   126,   226,   227,   228,   229,
     230,   231,    42,   119,   120,    42,   193,    92,     3,    29,
     121,   122,    93,   266,   123,   263,   264,   265,   109,   124,
     266,   126,   126,   126,   126,   242,     1,   244,   117,   102,
     103,   199,   246,    27,    29,   247,   248,   249,   171,   171,
     200,   250,   125,     2,   152,   271,   251,   271,     2,   153,
      20,     3,    21,    49,    22,   154,   271,   218,   273,   155,
      34,    69,    70,    71,   239,    30,     4,   288,    33,   290,
     126,   126,    39,   252,    36,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   187,    40,   308,   185,    51,   204,   205,   206,   207,
      52,    72,    73,   118,    53,    54,    74,    75,    55,   324,
     326,    34,    23,    56,   208,   261,   262,   263,   264,   265,
      39,    58,   266,   119,   120,    65,     1,    22,     3,   171,
     121,   171,   343,    86,   123,    87,    61,   209,   210,   124,
     156,    62,   211,   212,   353,   331,   126,   126,   171,   359,
     213,   315,   316,    68,   160,   280,   245,   118,   171,    89,
      76,   126,   125,   126,   171,   350,   370,    94,    43,   126,
     147,   197,    21,    64,   148,   171,    95,   119,   120,   170,
     126,   126,     3,    63,   121,   236,   126,    44,   123,    86,
     126,   281,    45,   124,   201,    96,   126,   339,    46,   119,
     120,   170,    47,   126,    97,    98,   121,   126,    99,   159,
     123,   104,   106,   355,   322,   124,   125,   323,   284,   111,
     148,   119,   120,   363,   285,   118,    87,   138,   121,   367,
     108,   346,   123,   236,   113,   140,   333,   124,   125,   334,
     374,   362,   170,   281,   170,   119,   120,   139,   141,   160,
       3,   161,   121,    21,   142,    22,   123,   143,   144,   150,
     125,   124,   119,   120,   119,   120,   170,     3,   170,   121,
     145,   121,   149,   123,   146,   123,   158,   162,   124,   151,
     124,   166,   167,   325,   125,   163,   119,   120,   119,   120,
     170,   164,   165,   121,   168,   121,   179,   123,   169,   123,
     180,   125,   124,   125,   124,   335,   342,   181,   182,   170,
     119,   120,   170,   183,   188,   189,   190,   121,   191,   194,
     196,   123,   198,   203,   220,   125,   124,   125,   351,   119,
     120,   170,   119,   120,   170,   224,   121,   235,   237,   121,
     123,   238,   240,   123,   358,   124,   241,   352,   124,   125,
     243,   119,   120,   170,   119,   120,   170,   267,   121,   268,
     269,   121,   123,   286,   282,   123,   365,   124,   125,   361,
     124,   125,   311,   119,   120,   170,   119,   120,   118,   309,
     121,   310,   314,   121,   123,   369,   312,   123,   372,   124,
     125,   317,   124,   125,   319,   119,   120,   327,   119,   120,
     328,   329,   121,   330,   332,   121,   123,   336,   344,   123,
     252,   124,   125,   345,   124,   125,   253,   254,   255,   256,
     349,   337,   257,   258,   172,   173,   174,   175,   176,   347,
     348,   354,   252,   177,   125,   356,   357,   125,   253,   254,
     255,   256,   364,   366,   257,   258,   368,   371,    31,   373,
     259,   260,   261,   262,   263,   264,   265,   283,   107,   266,
     313,   195,   178,    90,   112,   274,   105,   204,   205,   206,
     207,    50,   259,   260,   261,   262,   263,   264,   265,     0,
       0,   266,   252,     0,     0,   208,     0,   275,   253,   254,
     255,   256,     0,     0,   257,   258,     0,     0,   252,     0,
       0,     0,     0,     0,   253,   254,   255,   256,   209,   210,
     257,   258,     0,   211,   212,     0,     0,     0,     0,     0,
       0,   213,   259,   260,   261,   262,   263,   264,   265,     0,
       0,   266,     0,     0,     0,     0,     0,   276,   259,   260,
     261,   262,   263,   264,   265,     0,     0,   266,   252,     0,
      43,   338,     0,   277,   253,   254,   255,   256,     0,     0,
     257,   258,     0,     0,   252,     0,     0,     0,     0,    44,
     253,   254,   255,   256,    45,     0,   257,   258,     0,     0,
      46,     0,     0,     0,    47,     0,     0,     0,   259,   260,
     261,   262,   263,   264,   265,     0,     0,   266,     0,     0,
       0,     0,     0,   278,   259,   260,   261,   262,   263,   264,
     265,     0,     0,   266,   252,     0,     0,     0,     0,   279,
     253,   254,   255,   256,     0,     0,   257,   258,     0,     0,
     252,     0,     0,     0,     0,     0,   253,   254,   255,   256,
       0,     0,   257,   258,     0,     0,   204,   205,   206,   207,
       0,     0,     0,     0,   259,   260,   261,   262,   263,   264,
     265,     0,     0,   266,   208,   204,   205,   206,   207,   287,
     259,   260,   261,   262,   263,   264,   265,     0,     0,   266,
       0,     0,     0,   208,     0,   318,     0,   209,   210,     0,
       0,     0,   211,   212,     0,   204,   205,   206,   207,     0,
     213,   214,     0,     0,     0,     0,   209,   210,     0,     0,
       0,   211,   212,   208,     0,   252,     0,     0,     0,   213,
     270,   253,   254,   255,   256,     0,     0,   257,   258,     0,
       0,     0,     0,     0,     0,     0,   209,   210,     0,   252,
       0,   211,   212,     0,     0,   253,   254,   255,   256,   213,
     272,   257,   258,     0,     0,   259,   260,   261,   262,   263,
     264,   265,     0,     0,   266,   252,     0,     0,   340,   341,
       0,   253,   254,   255,   256,     0,     0,   257,   258,   259,
     260,   261,   262,   263,   264,   265,     0,     0,   266,   252,
       0,     0,     0,   321,     0,   253,   254,   255,   256,     0,
       0,   257,   258,     0,     0,   259,   260,   261,   262,   263,
     264,   265,     0,   252,   266,     0,     0,     0,   320,   253,
     254,   255,   256,     0,     0,   257,   258,     0,     0,   259,
     260,   261,   262,   263,   264,   265,     0,   252,   266,     0,
       0,     0,   360,   253,   254,   255,   256,     0,     0,   257,
     258,     0,     0,   259,   260,   261,   262,   263,   264,   265,
     252,     0,   266,     0,   291,     0,   253,   254,   255,   256,
       0,     0,   257,   258,     0,     0,   289,   259,   260,   261,
     262,   263,   264,   265,   252,     0,   266,     0,     0,     0,
     253,   254,   255,   256,     0,     0,   257,     0,     0,     0,
     259,   260,   261,   262,   263,   264,   265,   252,     0,   266,
       0,     0,     0,   253,   254,   255,   256,     0,     0,     0,
       0,     0,     0,   252,   259,   260,   261,   262,   263,   264,
     265,   255,   256,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,   263,   264,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,   263,   264,   265,
       0,     0,   266
};

static const yytype_int16 yycheck[] =
{
      63,    94,    65,   128,    18,    11,   136,   137,    13,    17,
       3,     7,     3,     3,   167,     3,     4,     3,    13,     4,
       4,   115,   115,    86,     0,   178,    32,     7,     0,     3,
      35,    28,    25,     9,     7,   128,     4,     5,    28,    11,
      35,     7,    38,   136,   137,    36,    43,    61,    61,    57,
      63,    59,    57,     3,   160,   185,    51,   187,    38,   184,
      32,   186,    57,    59,   158,   158,   172,   173,   174,   175,
     176,   177,    60,    23,    24,    60,    60,    58,    28,    59,
      30,    31,    63,    56,    34,    51,    52,    53,    84,    39,
      56,   184,   185,   186,   187,   201,     3,   203,    93,     4,
       5,    31,   208,     0,    84,   211,   212,   213,   233,   234,
      40,    58,    62,    25,    22,   221,    63,   223,    25,    27,
      59,    28,    61,     3,    63,    33,   232,     3,     4,    37,
     136,     4,     5,     6,   197,    62,    43,   243,    62,   245,
     233,   234,   137,     7,    62,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   137,    62,   269,   136,    57,     3,     4,     5,     6,
      57,    44,    45,     3,    46,    61,    49,    50,    62,   309,
     310,   187,     3,    62,    21,    49,    50,    51,    52,    53,
     185,    62,    56,    23,    24,    61,     3,    63,    28,   324,
      30,   326,   332,    61,    34,    63,    62,    44,    45,    39,
      40,    60,    49,    50,   344,   321,   309,   310,   343,   349,
      57,   284,   285,    58,    57,    62,    59,     3,   353,     3,
      64,   324,    62,   326,   359,   341,   366,    61,     3,   332,
      59,    61,    61,    63,    63,   370,    61,    23,    24,     3,
     343,   344,    28,    61,    30,    63,   349,    22,    34,    61,
     353,    63,    27,    39,    40,    61,   359,   330,    33,    23,
      24,     3,    37,   366,    61,    61,    30,   370,    61,    17,
      34,     3,    26,   346,    38,    39,    62,    41,    61,     3,
      63,    23,    24,   356,    61,     3,    63,    22,    30,   362,
      62,    61,    34,    63,    59,    33,    38,    39,    62,    41,
     373,    61,     3,    63,     3,    23,    24,    27,    37,    57,
      28,    59,    30,    61,    37,    63,    34,    61,    61,    59,
      62,    39,    23,    24,    23,    24,     3,    28,     3,    30,
      61,    30,    62,    34,    61,    34,    61,     3,    39,    60,
      39,    57,    57,    42,    62,    62,    23,    24,    23,    24,
       3,    62,    62,    30,    62,    30,    62,    34,    31,    34,
      62,    62,    39,    62,    39,    42,    41,    62,    62,     3,
      23,    24,     3,    62,    22,    27,    22,    30,    27,    64,
       4,    34,    62,    59,    29,    62,    39,    62,    41,    23,
      24,     3,    23,    24,     3,    62,    30,    60,     3,    30,
      34,    60,    31,    34,    35,    39,    62,    41,    39,    62,
      40,    23,    24,     3,    23,    24,     3,    60,    30,    60,
      59,    30,    34,    31,    64,    34,    35,    39,    62,    41,
      39,    62,    60,    23,    24,     3,    23,    24,     3,    61,
      30,    61,     3,    30,    34,    35,    64,    34,    35,    39,
      62,    31,    39,    62,     3,    23,    24,     3,    23,    24,
      59,    31,    30,    61,    61,    30,    34,    59,    61,    34,
       7,    39,    62,     4,    39,    62,    13,    14,    15,    16,
      61,    60,    19,    20,     8,     9,    10,    11,    12,    60,
      29,    60,     7,    17,    62,    61,     3,    62,    13,    14,
      15,    16,    32,    61,    19,    20,     4,    60,     9,    61,
      47,    48,    49,    50,    51,    52,    53,   236,    78,    56,
     281,   148,    46,    64,    87,    62,    76,     3,     4,     5,
       6,    22,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,     7,    -1,    -1,    21,    -1,    62,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    44,    45,
      19,    20,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,     7,    -1,
       3,     4,    -1,    62,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,    -1,     7,    -1,    -1,    -1,    -1,    22,
      13,    14,    15,    16,    27,    -1,    19,    20,    -1,    -1,
      33,    -1,    -1,    -1,    37,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    21,     3,     4,     5,     6,    62,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    21,    -1,    62,    -1,    44,    45,    -1,
      -1,    -1,    49,    50,    -1,     3,     4,     5,     6,    -1,
      57,    58,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    49,    50,    21,    -1,     7,    -1,    -1,    -1,    57,
      58,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,     7,
      -1,    49,    50,    -1,    -1,    13,    14,    15,    16,    57,
      58,    19,    20,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,     7,    -1,    -1,    60,    61,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,     7,
      -1,    -1,    -1,    61,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,     7,    56,    -1,    -1,    -1,    60,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,     7,    56,    -1,
      -1,    -1,    60,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
       7,    -1,    56,    -1,    58,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    23,    47,    48,    49,
      50,    51,    52,    53,     7,    -1,    56,    -1,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,     7,    -1,    56,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    47,    48,    49,    50,    51,    52,
      53,    15,    16,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56
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
       4,     5,     4,     5,     3,    98,    26,    89,    62,    67,
     103,     3,   101,    59,    18,    61,    69,    97,     3,    23,
      24,    30,    31,    34,    39,    62,    72,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    94,    96,    22,    27,
      33,    37,    37,    61,    61,    61,    61,    59,    63,    62,
      59,    60,    22,    27,    33,    37,    40,    76,    61,    17,
      57,    59,     3,    62,    62,    62,    57,    57,    62,    31,
       3,    78,     8,     9,    10,    11,    12,    17,    46,    62,
      62,    62,    62,    62,    77,    96,    77,    94,    22,    27,
      22,    27,     4,    60,    64,    93,     4,    61,    62,    31,
      40,    40,    76,    59,     3,     4,     5,     6,    21,    44,
      45,    49,    50,    57,    58,    72,    73,    75,     3,     4,
      29,    74,    75,    74,    62,    59,    75,    75,    75,    75,
      75,    75,    74,    77,    77,    60,    63,     3,    60,   103,
      31,    62,    75,    40,    75,    59,    75,    75,    75,    75,
      58,    63,     7,    13,    14,    15,    16,    19,    20,    47,
      48,    49,    50,    51,    52,    53,    56,    60,    60,    59,
      58,    75,    58,     4,    62,    62,    62,    62,    62,    62,
      62,    63,    64,    91,    61,    61,    31,    62,    75,    23,
      75,    58,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    61,
      61,    60,    64,    92,     3,   103,   103,    31,    62,     3,
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
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    84,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     5,     7,     8,     0,
       1,     3,     2,     2,     2,     2,     2,     3,     8,    10,
       9,    12,    11,     4,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     4,     3,     1,     3,     3,     1,     2,
       2,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       4,     4,     7,     6,    10,     9,     9,     8,     7,     6,
      13,    12,    11,    10,    11,    15,     2,     3,     5,     1,
       2,     3,     2,     1,     1,     1,     1,    11,     6,    13,
       7,     7,     4,     2,     3,     6,     7,     7,     6,     7,
       7,     6,     6,     6,     2,     3,     1,     1,     3,     6,
       5,     1,     1,     1,     9,     5,    11,     6,     5,     3,
       1,     1,     1,     1,     1
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
#line 94 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1753 "myparser.tab.c"
    break;

  case 3:
#line 95 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1759 "myparser.tab.c"
    break;

  case 4:
#line 96 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1765 "myparser.tab.c"
    break;

  case 5:
#line 97 "myparser.y"
                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1771 "myparser.tab.c"
    break;

  case 6:
#line 98 "myparser.y"
                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s\n%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1777 "myparser.tab.c"
    break;

  case 7:
#line 102 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1783 "myparser.tab.c"
    break;

  case 8:
#line 103 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1789 "myparser.tab.c"
    break;

  case 9:
#line 107 "myparser.y"
               {(yyval.str) = template("");}
#line 1795 "myparser.tab.c"
    break;

  case 10:
#line 108 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1801 "myparser.tab.c"
    break;

  case 11:
#line 109 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1807 "myparser.tab.c"
    break;

  case 12:
#line 113 "myparser.y"
                               {(yyval.str) = template("int");}
#line 1813 "myparser.tab.c"
    break;

  case 13:
#line 114 "myparser.y"
                                {(yyval.str) = template("double");}
#line 1819 "myparser.tab.c"
    break;

  case 14:
#line 115 "myparser.y"
                             {(yyval.str) = template("char*");}
#line 1825 "myparser.tab.c"
    break;

  case 15:
#line 116 "myparser.y"
                                  {(yyval.str) = template("int");}
#line 1831 "myparser.tab.c"
    break;

  case 16:
#line 121 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1837 "myparser.tab.c"
    break;

  case 17:
#line 122 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1843 "myparser.tab.c"
    break;

  case 18:
#line 126 "myparser.y"
                                                                                     {(yyval.str) = template("void %s(%s){\n%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1849 "myparser.tab.c"
    break;

  case 19:
#line 127 "myparser.y"
                                                                                                     {(yyval.str) = template("void %s(%s){\n%s\nreturn;\n}", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str));}
#line 1855 "myparser.tab.c"
    break;

  case 20:
#line 128 "myparser.y"
                                                                                   {(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));}
#line 1861 "myparser.tab.c"
    break;

  case 21:
#line 129 "myparser.y"
                                                                                                                                {(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1867 "myparser.tab.c"
    break;

  case 22:
#line 130 "myparser.y"
                                                                                                              {(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1873 "myparser.tab.c"
    break;

  case 23:
#line 135 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1879 "myparser.tab.c"
    break;

  case 24:
#line 136 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 1885 "myparser.tab.c"
    break;

  case 25:
#line 140 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1891 "myparser.tab.c"
    break;

  case 26:
#line 141 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1897 "myparser.tab.c"
    break;

  case 27:
#line 145 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1903 "myparser.tab.c"
    break;

  case 28:
#line 146 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1909 "myparser.tab.c"
    break;

  case 33:
#line 154 "myparser.y"
                        {(yyval.str) = template("0");}
#line 1915 "myparser.tab.c"
    break;

  case 34:
#line 155 "myparser.y"
                        {(yyval.str) = template("1");}
#line 1921 "myparser.tab.c"
    break;

  case 35:
#line 163 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1927 "myparser.tab.c"
    break;

  case 36:
#line 164 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1933 "myparser.tab.c"
    break;

  case 37:
#line 165 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1939 "myparser.tab.c"
    break;

  case 38:
#line 166 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1945 "myparser.tab.c"
    break;

  case 39:
#line 167 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1951 "myparser.tab.c"
    break;

  case 40:
#line 168 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1957 "myparser.tab.c"
    break;

  case 41:
#line 169 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1963 "myparser.tab.c"
    break;

  case 42:
#line 170 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1969 "myparser.tab.c"
    break;

  case 43:
#line 171 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1975 "myparser.tab.c"
    break;

  case 44:
#line 172 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1981 "myparser.tab.c"
    break;

  case 45:
#line 173 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1987 "myparser.tab.c"
    break;

  case 46:
#line 174 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1993 "myparser.tab.c"
    break;

  case 47:
#line 175 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1999 "myparser.tab.c"
    break;

  case 48:
#line 176 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2005 "myparser.tab.c"
    break;

  case 49:
#line 177 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2011 "myparser.tab.c"
    break;

  case 50:
#line 178 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 2017 "myparser.tab.c"
    break;

  case 51:
#line 179 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2023 "myparser.tab.c"
    break;

  case 52:
#line 180 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 2029 "myparser.tab.c"
    break;

  case 53:
#line 181 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 2035 "myparser.tab.c"
    break;

  case 54:
#line 182 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2041 "myparser.tab.c"
    break;

  case 55:
#line 183 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2047 "myparser.tab.c"
    break;

  case 56:
#line 187 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2053 "myparser.tab.c"
    break;

  case 57:
#line 188 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2059 "myparser.tab.c"
    break;

  case 58:
#line 189 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2065 "myparser.tab.c"
    break;

  case 59:
#line 190 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2071 "myparser.tab.c"
    break;

  case 60:
#line 191 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2077 "myparser.tab.c"
    break;

  case 61:
#line 197 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2083 "myparser.tab.c"
    break;

  case 62:
#line 198 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2089 "myparser.tab.c"
    break;

  case 63:
#line 202 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2095 "myparser.tab.c"
    break;

  case 64:
#line 203 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2101 "myparser.tab.c"
    break;

  case 65:
#line 204 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2107 "myparser.tab.c"
    break;

  case 66:
#line 205 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2113 "myparser.tab.c"
    break;

  case 67:
#line 206 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2119 "myparser.tab.c"
    break;

  case 68:
#line 207 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2125 "myparser.tab.c"
    break;

  case 69:
#line 208 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2131 "myparser.tab.c"
    break;

  case 70:
#line 209 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2137 "myparser.tab.c"
    break;

  case 71:
#line 210 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2143 "myparser.tab.c"
    break;

  case 72:
#line 211 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2149 "myparser.tab.c"
    break;

  case 73:
#line 212 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2155 "myparser.tab.c"
    break;

  case 74:
#line 213 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2161 "myparser.tab.c"
    break;

  case 75:
#line 214 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2167 "myparser.tab.c"
    break;

  case 76:
#line 215 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2173 "myparser.tab.c"
    break;

  case 77:
#line 216 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2179 "myparser.tab.c"
    break;

  case 78:
#line 217 "myparser.y"
              {(yyval.str) = template("");}
#line 2185 "myparser.tab.c"
    break;

  case 79:
#line 221 "myparser.y"
                 { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2191 "myparser.tab.c"
    break;

  case 80:
#line 222 "myparser.y"
                                       {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2197 "myparser.tab.c"
    break;

  case 81:
#line 223 "myparser.y"
                                    {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2203 "myparser.tab.c"
    break;

  case 82:
#line 227 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2209 "myparser.tab.c"
    break;

  case 83:
#line 228 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2215 "myparser.tab.c"
    break;

  case 84:
#line 229 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2221 "myparser.tab.c"
    break;

  case 85:
#line 230 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2227 "myparser.tab.c"
    break;

  case 86:
#line 231 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2233 "myparser.tab.c"
    break;

  case 87:
#line 232 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2239 "myparser.tab.c"
    break;

  case 88:
#line 239 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2245 "myparser.tab.c"
    break;

  case 89:
#line 240 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2251 "myparser.tab.c"
    break;

  case 90:
#line 244 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2257 "myparser.tab.c"
    break;

  case 91:
#line 245 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2263 "myparser.tab.c"
    break;

  case 92:
#line 246 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2269 "myparser.tab.c"
    break;

  case 93:
#line 247 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2275 "myparser.tab.c"
    break;

  case 94:
#line 252 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2281 "myparser.tab.c"
    break;

  case 95:
#line 257 "myparser.y"
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
#line 2296 "myparser.tab.c"
    break;

  case 96:
#line 270 "myparser.y"
                             {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2302 "myparser.tab.c"
    break;

  case 97:
#line 271 "myparser.y"
                                                 {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2308 "myparser.tab.c"
    break;

  case 98:
#line 275 "myparser.y"
                                                                 {(yyval.str) = template("typedef struct %s{\n%s\n}%s", (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[-3].str)); comps[numOfComps] = (yyvsp[-3].str); numOfComps++; printf("%d", numOfComps);}
#line 2314 "myparser.tab.c"
    break;

  case 99:
#line 279 "myparser.y"
                                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2320 "myparser.tab.c"
    break;

  case 100:
#line 285 "myparser.y"
                                 {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2326 "myparser.tab.c"
    break;

  case 101:
#line 286 "myparser.y"
                                                         { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2332 "myparser.tab.c"
    break;

  case 102:
#line 294 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2338 "myparser.tab.c"
    break;

  case 103:
#line 295 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2344 "myparser.tab.c"
    break;

  case 104:
#line 299 "myparser.y"
                         {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2350 "myparser.tab.c"
    break;

  case 105:
#line 300 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2356 "myparser.tab.c"
    break;

  case 106:
#line 301 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2362 "myparser.tab.c"
    break;

  case 107:
#line 305 "myparser.y"
                                                                    {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-9].str), (yyvsp[-4].str));
										}}
#line 2373 "myparser.tab.c"
    break;

  case 108:
#line 311 "myparser.y"
                                                     {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2384 "myparser.tab.c"
    break;

  case 109:
#line 320 "myparser.y"
                                                                                            {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-11].str), (yyvsp[-9].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2395 "myparser.tab.c"
    break;

  case 110:
#line 326 "myparser.y"
                                                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2406 "myparser.tab.c"
    break;

  case 111:
#line 335 "myparser.y"
                                                    {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-2].str));
										}}
#line 2420 "myparser.tab.c"
    break;

  case 112:
#line 344 "myparser.y"
                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2434 "myparser.tab.c"
    break;

  case 113:
#line 368 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2440 "myparser.tab.c"
    break;

  case 114:
#line 369 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2446 "myparser.tab.c"
    break;

  case 115:
#line 373 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2452 "myparser.tab.c"
    break;

  case 116:
#line 374 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2458 "myparser.tab.c"
    break;

  case 117:
#line 375 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2464 "myparser.tab.c"
    break;

  case 118:
#line 376 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2470 "myparser.tab.c"
    break;

  case 119:
#line 377 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2476 "myparser.tab.c"
    break;

  case 120:
#line 378 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2482 "myparser.tab.c"
    break;

  case 121:
#line 379 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2488 "myparser.tab.c"
    break;

  case 122:
#line 380 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2494 "myparser.tab.c"
    break;

  case 123:
#line 381 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2500 "myparser.tab.c"
    break;

  case 124:
#line 386 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2506 "myparser.tab.c"
    break;

  case 125:
#line 387 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2512 "myparser.tab.c"
    break;

  case 126:
#line 391 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2518 "myparser.tab.c"
    break;

  case 127:
#line 392 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2524 "myparser.tab.c"
    break;

  case 128:
#line 396 "myparser.y"
                               {if(isComp == 1){
							(yyval.str) = template("%s %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
							}else
							(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2533 "myparser.tab.c"
    break;

  case 129:
#line 400 "myparser.y"
                                                     {	(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));	}
#line 2539 "myparser.tab.c"
    break;

  case 130:
#line 401 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2545 "myparser.tab.c"
    break;

  case 131:
#line 405 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2551 "myparser.tab.c"
    break;

  case 132:
#line 406 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2557 "myparser.tab.c"
    break;

  case 133:
#line 407 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2563 "myparser.tab.c"
    break;

  case 134:
#line 411 "myparser.y"
                                                            {if(isStr == 1){
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2574 "myparser.tab.c"
    break;

  case 135:
#line 417 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2585 "myparser.tab.c"
    break;

  case 136:
#line 426 "myparser.y"
                                                                                    {if(isStr == 1){
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2596 "myparser.tab.c"
    break;

  case 137:
#line 432 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2607 "myparser.tab.c"
    break;

  case 138:
#line 441 "myparser.y"
                                            {if (isStr == 1){
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											if(isComp == 1){
												(yyval.str) = template("%s %s = ctor_%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[0].str), (yyvsp[-2].str), (yyvsp[0].str));
											}else
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2621 "myparser.tab.c"
    break;

  case 139:
#line 450 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									if(isComp == 1){
										(yyval.str) = template("%s, %s = ctor_%s", (yyvsp[0].str), (yyvsp[-2].str), temp);
									}else
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2635 "myparser.tab.c"
    break;

  case 140:
#line 462 "myparser.y"
                   {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2641 "myparser.tab.c"
    break;

  case 141:
#line 463 "myparser.y"
                    {(yyval.str) = template("double"); isComp = 0; isStr = 0;}
#line 2647 "myparser.tab.c"
    break;

  case 142:
#line 464 "myparser.y"
                 {(yyval.str) = template("char*"); isComp = 0; isStr = 1;}
#line 2653 "myparser.tab.c"
    break;

  case 143:
#line 465 "myparser.y"
                      {(yyval.str) = template("int"); isComp = 0; isStr = 0;}
#line 2659 "myparser.tab.c"
    break;

  case 144:
#line 466 "myparser.y"
                   { isStr = 0;
					if(find_comp((yyvsp[0].str)) == 1){
					isComp = 1;
					(yyval.str) = template("%s", (yyvsp[0].str));
					}else{
						yyerror("Unknown data type");
					}

				}
#line 2673 "myparser.tab.c"
    break;


#line 2677 "myparser.tab.c"

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
#line 478 "myparser.y"

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


