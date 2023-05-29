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
	
	extern int yylex(void);
	int isStr = 0;



#line 83 "myparser.tab.c"

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
#line 14 "myparser.y"

	char* str;

#line 187 "myparser.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   911

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

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
       0,    85,    85,    86,    87,    88,    93,    94,    98,    99,
     100,   104,   105,   106,   107,   112,   113,   117,   118,   119,
     120,   121,   125,   126,   130,   131,   132,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   163,   164,   165,
     166,   167,   173,   174,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   194,   195,   196,
     197,   198,   199,   212,   213,   217,   218,   219,   220,   224,
     225,   229,   230,   231,   232,   233,   238,   239,   243,   244,
     248,   249,   250,   254,   255,   260,   268,   278,   286,   296,
     297,   298,   299
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
  "$accept", "program", "main_block", "function_param",
  "function_return_type", "function_blocks", "function_block",
  "listofexpr", "expr", "listofinstructions", "statements", "statement",
  "if_statement", "while_statement", "for_statement", "const_declarations",
  "const_declaration", "var_declarations", "var_declaration", "one_var",
  "multi_var", "multi_var_2", "multi_var_1", "data_type", YY_NULLPTR
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

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,    65,    25,    27,     6,   -91,    26,   -27,    12,    -3,
      11,    16,   -91,   -91,   -91,   -91,     0,   129,    59,    52,
      79,    28,   -91,   -91,    82,   -91,    90,    11,   -91,   138,
      26,    96,   -91,   105,    98,   -91,   -91,   -91,   -91,   -91,
      42,   -91,   170,   118,    13,   -91,   -91,    26,   -91,   -91,
      47,   129,   129,   -29,   -91,   124,   127,   131,   134,   136,
     137,   -91,   129,   176,   -91,   -91,   -11,   170,    99,   179,
     175,   177,   171,   180,   -91,   154,   -91,   230,   144,   142,
     -91,   488,   220,   162,   164,   167,   189,   201,   -91,   233,
     356,   -91,   200,   204,   207,   188,   188,   -91,   -91,   -91,
     -91,   -91,   267,   -91,   -91,   -91,   -91,   210,    67,   147,
     579,   579,   579,   579,   579,   579,   579,   245,   -91,   -91,
     -91,   579,   579,   213,   400,   -91,   -91,   -91,   -91,   356,
     359,   356,   191,   216,   252,   -91,   222,   579,   246,   238,
     -91,   -91,   579,   579,   579,   579,   387,   409,   459,   475,
     525,   541,   228,   798,   241,   427,   559,   -91,   356,   356,
     119,   -91,   261,   591,   579,   579,   855,     9,     9,   784,
     579,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   579,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   798,   579,   240,   244,   129,   -91,   276,   607,
     722,   -91,     9,    64,    64,   186,   186,   855,   808,   186,
     186,   192,   192,     9,     9,     9,   -91,   672,     8,   217,
     -91,   -91,   281,   -91,   579,   249,   -91,   166,   -91,   231,
     -91,   657,   257,   255,   -91,   -91,   256,   579,   -91,   265,
     279,   291,   736,   -91,   -91,   305,   -91,   308,   262,   -91,
     -91,   334,   -91,   342,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,    88,    89,    94,    93,     0,     0,     0,     0,
       0,     0,     1,     3,     0,    15,     0,     0,    79,     0,
       0,     0,    86,     0,     0,    99,   100,   101,   102,    90,
       0,    98,     8,     0,     0,    16,    80,     0,     4,    87,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     5,     0,     0,    92,    97,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,    96,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      49,    52,     0,     0,     0,     0,     0,    82,    81,    83,
      84,    85,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
       6,     0,     0,     0,     0,    53,    61,    63,    62,    51,
       0,    50,     0,     0,     0,    17,     0,     0,     0,    26,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     7,    48,    47,
       0,    19,     0,     0,     0,     0,    29,    43,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    59,    58,
      60,    54,    23,     0,     0,     0,     0,    18,     0,     0,
       0,    44,    41,    31,    30,    33,    32,    28,    27,    34,
      35,    36,    37,    38,    39,    40,    46,     0,     0,     0,
      95,    21,     0,    45,     0,     0,    68,     0,    74,     0,
      20,     0,     0,     0,    67,    73,     0,     0,    72,     0,
       0,     0,     0,    70,    71,     0,    78,     0,     0,    69,
      77,     0,    76,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,    95,   -91,   -91,    17,   113,   -49,   -89,   -45,
     -87,   -90,   -91,   -91,   -91,     3,     2,     5,    10,   -91,
     -91,   259,   306,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    53,    79,     6,     7,   152,   153,    89,
      90,    91,    92,    93,    94,    95,     9,    96,    11,    12,
      13,    14,    15,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     125,    64,    65,     8,    33,    10,    22,    77,   129,   131,
      26,   124,    74,    27,     1,     1,   170,    56,    57,    58,
      31,   146,   147,   148,   149,   150,   151,    30,    19,    66,
      21,    82,    83,   108,    67,    25,    29,    31,    84,   125,
       3,   125,    86,   158,    47,   159,   225,    87,   163,   226,
      78,     2,    54,   166,   167,   168,   169,    59,    60,    28,
      34,    20,    40,   192,   138,   184,   192,   192,   125,   125,
      88,   170,   155,   156,    44,   199,   200,    80,    32,   173,
     174,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,     1,    26,   135,   132,
     130,    23,    81,    52,   217,    18,    31,   136,    62,    42,
      63,   177,   178,   179,   180,   181,   182,   183,     2,    24,
     184,     3,    82,    83,    16,    48,    17,     3,    18,    84,
      85,   227,   229,    86,    26,   231,    43,   125,    87,   125,
      31,    19,    61,    24,    45,   239,   220,    81,   242,   125,
      81,    35,    46,   245,   247,   125,    36,   125,    49,    51,
      24,    88,    37,   125,   253,    50,    38,    82,    83,   124,
      82,    83,     3,     1,    84,     3,    55,    84,    86,    75,
     196,    86,    63,    87,   107,    68,    87,   137,    69,    82,
      83,    81,    70,   170,   124,    71,    84,    72,    73,   170,
      86,    97,    98,   109,   233,    87,    88,   234,   100,    88,
      99,    82,    83,   102,    82,    83,     3,   101,    84,     3,
     124,    84,    86,   117,   118,    86,   119,    87,    88,   120,
      87,   139,   140,   141,   124,   179,   180,   181,   182,   183,
      82,    83,   184,   181,   182,   183,   121,    84,   184,   142,
      88,    86,   103,    88,    82,    83,    87,   104,   122,   228,
     124,    84,   126,   105,   123,    86,   127,   106,   124,   128,
      87,   133,   134,   235,   154,   157,   160,   143,   144,    88,
      82,    83,   124,   161,   162,   145,   164,    84,    82,    83,
     191,    86,   197,    88,   124,    84,    87,   165,   238,    86,
     193,   218,    82,    83,    87,   219,   243,   221,   124,    84,
     232,   124,   230,    86,    82,    83,   240,   241,    87,    88,
     244,    84,    76,   251,    41,    86,   246,    88,    82,    83,
      87,    82,    83,     0,     0,    84,     0,   124,    84,    86,
       0,    88,    86,   250,    87,   124,   249,    87,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    82,    83,   124,
       0,     0,    81,     0,    84,    82,    83,    88,    86,   252,
      88,     0,    84,    87,     0,     0,    86,   254,     0,    82,
      83,    87,    82,    83,     0,     0,    84,     0,     0,    84,
      86,     0,     0,    86,   170,    87,    88,     0,    87,     0,
     171,   172,   173,   174,    88,     0,   175,   176,   110,   111,
     112,   113,   114,     0,     0,     0,   170,   115,    88,     0,
       0,    88,   171,   172,   173,   174,     0,     0,   175,   176,
     139,   140,   141,     0,   177,   178,   179,   180,   181,   182,
     183,     0,     0,   184,     0,     0,   116,     0,   142,   185,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,     0,     0,   184,   170,     0,     0,     0,
       0,   186,   171,   172,   173,   174,   143,   144,   175,   176,
       0,     0,   170,     0,   145,   194,     0,     0,   171,   172,
     173,   174,     0,     0,   175,   176,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   177,   178,   179,   180,
     181,   182,   183,     0,     0,   184,     0,     0,     0,     0,
       0,   187,   177,   178,   179,   180,   181,   182,   183,     0,
       0,   184,   170,     0,   116,     0,     0,   188,   171,   172,
     173,   174,     0,     0,   175,   176,     0,    16,   170,    17,
       0,    18,     0,     0,   171,   172,   173,   174,     0,     0,
     175,   176,   139,   140,   141,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,     0,
     142,   184,   139,   140,   141,     0,     0,   189,   177,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   170,     0,
     142,     0,     0,   190,   171,   172,   173,   174,   143,   144,
     175,   176,     0,     0,   170,     0,   145,   195,     0,     0,
     171,   172,   173,   174,     0,     0,   175,   176,   143,   144,
       0,     0,     0,     0,     0,     0,   145,     0,   177,   178,
     179,   180,   181,   182,   183,     0,     0,   184,     0,     0,
       0,     0,     0,   198,   177,   178,   179,   180,   181,   182,
     183,     0,     0,   184,   170,     0,     0,     0,     0,   222,
     171,   172,   173,   174,     0,     0,   175,   176,     0,   170,
       0,     0,     0,     0,     0,   171,   172,   173,   174,     0,
       0,   175,   176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,     0,     0,   184,     0,     0,     0,   236,   237,   177,
     178,   179,   180,   181,   182,   183,     0,     0,   184,   170,
       0,     0,     0,   224,     0,   171,   172,   173,   174,     0,
       0,   175,   176,   170,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,   175,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,     0,     0,   184,     0,
       0,     0,   223,   177,   178,   179,   180,   181,   182,   183,
       0,   170,   184,     0,     0,     0,   248,   171,   172,   173,
     174,     0,     0,   175,   176,   170,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   170,     0,   175,   176,     0,
       0,   171,   172,   173,   174,     0,     0,   175,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,     0,     0,
     184,     0,   201,     0,     0,   177,   178,   179,   180,   181,
     182,   183,     0,     0,   184,   177,   178,   179,   180,   181,
     182,   183,   170,     0,   184,     0,     0,     0,   171,   172,
     173,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,     0,
       0,   184
};

static const yytype_int16 yycheck[] =
{
      90,    51,    52,     0,     4,     0,     0,    18,    95,    96,
       8,     3,    62,     8,     3,     3,     7,     4,     5,     6,
      10,   110,   111,   112,   113,   114,   115,    10,     3,    58,
       3,    23,    24,    78,    63,    62,    25,    27,    30,   129,
      28,   131,    34,   130,    27,   132,    38,    39,   137,    41,
      61,    25,    42,   142,   143,   144,   145,    44,    45,    62,
      60,    36,     3,   152,   109,    56,   155,   156,   158,   159,
      62,     7,   121,   122,    46,   164,   165,    67,    62,    15,
      16,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     3,    95,    31,    96,
      95,     6,     3,    61,   193,    63,    96,    40,    61,    57,
      63,    47,    48,    49,    50,    51,    52,    53,    25,     6,
      56,    28,    23,    24,    59,    30,    61,    28,    63,    30,
      31,   218,   219,    34,   132,   224,    57,   227,    39,   229,
     130,     3,    47,    30,    62,   232,   196,     3,   237,   239,
       3,    22,    62,   240,   241,   245,    27,   247,    62,    61,
      47,    62,    33,   253,   251,    60,    37,    23,    24,     3,
      23,    24,    28,     3,    30,    28,    58,    30,    34,     3,
      61,    34,    63,    39,    40,    61,    39,    40,    61,    23,
      24,     3,    61,     7,     3,    61,    30,    61,    61,     7,
      34,    22,    27,    61,    38,    39,    62,    41,    37,    62,
      33,    23,    24,    59,    23,    24,    28,    37,    30,    28,
       3,    30,    34,     3,    62,    34,    62,    39,    62,    62,
      39,     3,     4,     5,     3,    49,    50,    51,    52,    53,
      23,    24,    56,    51,    52,    53,    57,    30,    56,    21,
      62,    34,    22,    62,    23,    24,    39,    27,    57,    42,
       3,    30,    62,    33,    31,    34,    62,    37,     3,    62,
      39,     4,    62,    42,    29,    62,    60,    49,    50,    62,
      23,    24,     3,    31,    62,    57,    40,    30,    23,    24,
      62,    34,    31,    62,     3,    30,    39,    59,    41,    34,
      59,    61,    23,    24,    39,    61,    41,    31,     3,    30,
      61,     3,    31,    34,    23,    24,    61,    61,    39,    62,
      41,    30,    63,    61,    18,    34,    35,    62,    23,    24,
      39,    23,    24,    -1,    -1,    30,    -1,     3,    30,    34,
      -1,    62,    34,    35,    39,     3,    41,    39,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    23,    24,     3,
      -1,    -1,     3,    -1,    30,    23,    24,    62,    34,    35,
      62,    -1,    30,    39,    -1,    -1,    34,    35,    -1,    23,
      24,    39,    23,    24,    -1,    -1,    30,    -1,    -1,    30,
      34,    -1,    -1,    34,     7,    39,    62,    -1,    39,    -1,
      13,    14,    15,    16,    62,    -1,    19,    20,     8,     9,
      10,    11,    12,    -1,    -1,    -1,     7,    17,    62,    -1,
      -1,    62,    13,    14,    15,    16,    -1,    -1,    19,    20,
       3,     4,     5,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    46,    -1,    21,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,    -1,
      -1,    62,    13,    14,    15,    16,    49,    50,    19,    20,
      -1,    -1,     7,    -1,    57,    58,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    19,    20,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,     7,    -1,    46,    -1,    -1,    62,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    59,     7,    61,
      -1,    63,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      19,    20,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      21,    56,     3,     4,     5,    -1,    -1,    62,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,     7,    -1,
      21,    -1,    -1,    62,    13,    14,    15,    16,    49,    50,
      19,    20,    -1,    -1,     7,    -1,    57,    58,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    19,    20,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    62,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    60,    61,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,     7,
      -1,    -1,    -1,    61,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    60,    47,    48,    49,    50,    51,    52,    53,
      -1,     7,    56,    -1,    -1,    -1,    60,    13,    14,    15,
      16,    -1,    -1,    19,    20,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,     7,    -1,    19,    20,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    58,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    47,    48,    49,    50,    51,
      52,    53,     7,    -1,    56,    -1,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    25,    28,    65,    66,    69,    70,    79,    80,
      81,    82,    83,    84,    85,    86,    59,    61,    63,     3,
      36,     3,     0,    66,    70,    62,    80,    81,    62,    25,
      69,    82,    62,     4,    60,    22,    27,    33,    37,    87,
       3,    86,    57,    57,    46,    62,    62,    69,    66,    62,
      60,    61,    61,    67,    82,    58,     4,     5,     6,    44,
      45,    66,    61,    63,    87,    87,    58,    63,    61,    61,
      61,    61,    61,    61,    87,     3,    85,    18,    61,    68,
      82,     3,    23,    24,    30,    31,    34,    39,    62,    73,
      74,    75,    76,    77,    78,    79,    81,    22,    27,    33,
      37,    37,    59,    22,    27,    33,    37,    40,    73,    61,
       8,     9,    10,    11,    12,    17,    46,     3,    62,    62,
      62,    57,    57,    31,     3,    75,    62,    62,    62,    74,
      81,    74,    79,     4,    62,    31,    40,    40,    73,     3,
       4,     5,    21,    49,    50,    57,    72,    72,    72,    72,
      72,    72,    71,    72,    29,    71,    71,    62,    74,    74,
      60,    31,    62,    72,    40,    59,    72,    72,    72,    72,
       7,    13,    14,    15,    16,    19,    20,    47,    48,    49,
      50,    51,    52,    53,    56,    62,    62,    62,    62,    62,
      62,    62,    72,    59,    58,    58,    61,    31,    62,    72,
      72,    58,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    61,    61,
      87,    31,    62,    60,    61,    38,    41,    74,    42,    74,
      31,    72,    61,    38,    41,    42,    60,    61,    41,    74,
      61,    61,    72,    41,    41,    74,    35,    74,    60,    41,
      35,    61,    35,    74,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     7,     8,     0,     1,
       3,     2,     2,     2,     2,     2,     3,     8,    10,     9,
      12,    11,     1,     2,     1,     1,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     4,     3,     3,     3,     1,
       2,     2,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     2,     2,     1,     7,     6,    10,
       9,     9,     8,     7,     6,    13,    12,    11,    10,     2,
       3,     6,     6,     6,     6,     6,     2,     3,     1,     1,
       3,     6,     5,     1,     1,    11,     6,     5,     3,     1,
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
#line 85 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1665 "myparser.tab.c"
    break;

  case 3:
#line 86 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1671 "myparser.tab.c"
    break;

  case 4:
#line 87 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1677 "myparser.tab.c"
    break;

  case 5:
#line 88 "myparser.y"
                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1683 "myparser.tab.c"
    break;

  case 6:
#line 93 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1689 "myparser.tab.c"
    break;

  case 7:
#line 94 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1695 "myparser.tab.c"
    break;

  case 8:
#line 98 "myparser.y"
               {(yyval.str) = template("");}
#line 1701 "myparser.tab.c"
    break;

  case 9:
#line 99 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1707 "myparser.tab.c"
    break;

  case 10:
#line 100 "myparser.y"
                                             {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1713 "myparser.tab.c"
    break;

  case 11:
#line 104 "myparser.y"
                               {(yyval.str) = template("int");}
#line 1719 "myparser.tab.c"
    break;

  case 12:
#line 105 "myparser.y"
                                {(yyval.str) = template("double");}
#line 1725 "myparser.tab.c"
    break;

  case 13:
#line 106 "myparser.y"
                             {(yyval.str) = template("char*");}
#line 1731 "myparser.tab.c"
    break;

  case 14:
#line 107 "myparser.y"
                                  {(yyval.str) = template("int");}
#line 1737 "myparser.tab.c"
    break;

  case 15:
#line 112 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1743 "myparser.tab.c"
    break;

  case 16:
#line 113 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1749 "myparser.tab.c"
    break;

  case 17:
#line 117 "myparser.y"
                                                                                {(yyval.str) = template("void %s(%s){\n%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1755 "myparser.tab.c"
    break;

  case 18:
#line 118 "myparser.y"
                                                                                                {(yyval.str) = template("void %s(%s){\n%s\nreturn;\n}", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str));}
#line 1761 "myparser.tab.c"
    break;

  case 19:
#line 119 "myparser.y"
                                                                              {(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));}
#line 1767 "myparser.tab.c"
    break;

  case 20:
#line 120 "myparser.y"
                                                                                                                           {(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1773 "myparser.tab.c"
    break;

  case 21:
#line 121 "myparser.y"
                                                                                                         {(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1779 "myparser.tab.c"
    break;

  case 22:
#line 125 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1785 "myparser.tab.c"
    break;

  case 23:
#line 126 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1791 "myparser.tab.c"
    break;

  case 27:
#line 140 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1797 "myparser.tab.c"
    break;

  case 28:
#line 141 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1803 "myparser.tab.c"
    break;

  case 29:
#line 142 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1809 "myparser.tab.c"
    break;

  case 30:
#line 143 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1815 "myparser.tab.c"
    break;

  case 31:
#line 144 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1821 "myparser.tab.c"
    break;

  case 32:
#line 145 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1827 "myparser.tab.c"
    break;

  case 33:
#line 146 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1833 "myparser.tab.c"
    break;

  case 34:
#line 147 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1839 "myparser.tab.c"
    break;

  case 35:
#line 148 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1845 "myparser.tab.c"
    break;

  case 36:
#line 149 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1851 "myparser.tab.c"
    break;

  case 37:
#line 150 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1857 "myparser.tab.c"
    break;

  case 38:
#line 151 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1863 "myparser.tab.c"
    break;

  case 39:
#line 152 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1869 "myparser.tab.c"
    break;

  case 40:
#line 153 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1875 "myparser.tab.c"
    break;

  case 41:
#line 154 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1881 "myparser.tab.c"
    break;

  case 42:
#line 155 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 1887 "myparser.tab.c"
    break;

  case 43:
#line 156 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1893 "myparser.tab.c"
    break;

  case 44:
#line 157 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 1899 "myparser.tab.c"
    break;

  case 45:
#line 158 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1905 "myparser.tab.c"
    break;

  case 46:
#line 159 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1911 "myparser.tab.c"
    break;

  case 47:
#line 163 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 1917 "myparser.tab.c"
    break;

  case 48:
#line 164 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 1923 "myparser.tab.c"
    break;

  case 49:
#line 165 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 1929 "myparser.tab.c"
    break;

  case 50:
#line 166 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 1935 "myparser.tab.c"
    break;

  case 51:
#line 167 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 1941 "myparser.tab.c"
    break;

  case 52:
#line 173 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 1947 "myparser.tab.c"
    break;

  case 53:
#line 174 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1953 "myparser.tab.c"
    break;

  case 54:
#line 178 "myparser.y"
                                    {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1959 "myparser.tab.c"
    break;

  case 55:
#line 179 "myparser.y"
                                     {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1965 "myparser.tab.c"
    break;

  case 56:
#line 180 "myparser.y"
                                     {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1971 "myparser.tab.c"
    break;

  case 57:
#line 181 "myparser.y"
                                     {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1977 "myparser.tab.c"
    break;

  case 58:
#line 182 "myparser.y"
                                     {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1983 "myparser.tab.c"
    break;

  case 59:
#line 183 "myparser.y"
                                     {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1989 "myparser.tab.c"
    break;

  case 60:
#line 184 "myparser.y"
                                     {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1995 "myparser.tab.c"
    break;

  case 61:
#line 185 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2001 "myparser.tab.c"
    break;

  case 62:
#line 186 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2007 "myparser.tab.c"
    break;

  case 63:
#line 187 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2013 "myparser.tab.c"
    break;

  case 64:
#line 188 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2019 "myparser.tab.c"
    break;

  case 65:
#line 189 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2025 "myparser.tab.c"
    break;

  case 66:
#line 190 "myparser.y"
              {(yyval.str) = template("");}
#line 2031 "myparser.tab.c"
    break;

  case 67:
#line 194 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2037 "myparser.tab.c"
    break;

  case 68:
#line 195 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2043 "myparser.tab.c"
    break;

  case 69:
#line 196 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2049 "myparser.tab.c"
    break;

  case 70:
#line 197 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2055 "myparser.tab.c"
    break;

  case 71:
#line 198 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2061 "myparser.tab.c"
    break;

  case 72:
#line 199 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2067 "myparser.tab.c"
    break;

  case 73:
#line 212 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2073 "myparser.tab.c"
    break;

  case 74:
#line 213 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2079 "myparser.tab.c"
    break;

  case 75:
#line 217 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2085 "myparser.tab.c"
    break;

  case 76:
#line 218 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2091 "myparser.tab.c"
    break;

  case 77:
#line 219 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2097 "myparser.tab.c"
    break;

  case 78:
#line 220 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2103 "myparser.tab.c"
    break;

  case 79:
#line 224 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2109 "myparser.tab.c"
    break;

  case 80:
#line 225 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2115 "myparser.tab.c"
    break;

  case 81:
#line 229 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2121 "myparser.tab.c"
    break;

  case 82:
#line 230 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2127 "myparser.tab.c"
    break;

  case 83:
#line 231 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2133 "myparser.tab.c"
    break;

  case 84:
#line 232 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2139 "myparser.tab.c"
    break;

  case 85:
#line 233 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2145 "myparser.tab.c"
    break;

  case 86:
#line 238 "myparser.y"
                            {printf("b\n");(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2151 "myparser.tab.c"
    break;

  case 87:
#line 239 "myparser.y"
                                               {printf("a\n"); (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2157 "myparser.tab.c"
    break;

  case 88:
#line 243 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2163 "myparser.tab.c"
    break;

  case 89:
#line 244 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2169 "myparser.tab.c"
    break;

  case 90:
#line 248 "myparser.y"
                               {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2175 "myparser.tab.c"
    break;

  case 91:
#line 249 "myparser.y"
                                                     {(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));}
#line 2181 "myparser.tab.c"
    break;

  case 92:
#line 250 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2187 "myparser.tab.c"
    break;

  case 93:
#line 254 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2193 "myparser.tab.c"
    break;

  case 94:
#line 255 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2199 "myparser.tab.c"
    break;

  case 95:
#line 260 "myparser.y"
                                                                                    {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2212 "myparser.tab.c"
    break;

  case 96:
#line 268 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									isStr = 0;
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2224 "myparser.tab.c"
    break;

  case 97:
#line 278 "myparser.y"
                                            {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2237 "myparser.tab.c"
    break;

  case 98:
#line 286 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									isStr = 0;
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2249 "myparser.tab.c"
    break;

  case 99:
#line 296 "myparser.y"
                   {(yyval.str) = template("int");}
#line 2255 "myparser.tab.c"
    break;

  case 100:
#line 297 "myparser.y"
                    {(yyval.str) = template("double");}
#line 2261 "myparser.tab.c"
    break;

  case 101:
#line 298 "myparser.y"
                 {(yyval.str) = template("char*");}
#line 2267 "myparser.tab.c"
    break;

  case 102:
#line 299 "myparser.y"
                      {(yyval.str) = template("int");}
#line 2273 "myparser.tab.c"
    break;


#line 2277 "myparser.tab.c"

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
#line 309 "myparser.y"

int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
