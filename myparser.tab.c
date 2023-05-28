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
	#include <math.h>
  	#include "cgen.h"
	
	extern int yylex(void);
	int i1, i2;
	double d1, d2;


#line 82 "myparser.tab.c"

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
    KW_AND = 273,
    KW_OR = 274,
    KW_NOT = 275,
    KW_INTEGER = 276,
    KW_FOR = 277,
    KW_BREAK = 278,
    KW_DEF = 279,
    KW_ENDCOMP = 280,
    KW_SCALAR = 281,
    KW_CONST = 282,
    KW_IN = 283,
    KW_CONTINUE = 284,
    KW_ENDDEF = 285,
    KW_OF = 286,
    KW_STR = 287,
    KW_IF = 288,
    KW_ENDFOR = 289,
    KW_MAIN = 290,
    KW_BOOLEAN = 291,
    KW_ELSE = 292,
    KW_WHILE = 293,
    KW_RETURN = 294,
    KW_ENDIF = 295,
    KW_ENDWHILE = 296,
    KW_COMP = 297,
    KW_TRUE = 298,
    KW_FALSE = 299,
    UMINUS = 300,
    UPLUS = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "myparser.y"

	char* str;

#line 185 "myparser.tab.c"

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


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
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      56,    57,    50,    48,     2,    49,    55,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    61,
      46,    45,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
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
      53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    83,    84,    85,    90,    91,    95,    96,
     100,   101,   105,   106,   110,   111,   112,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   143,   144,   145,
     151,   152,   156,   157,   158,   159,   160,   161,   162,   163,
     167,   168,   172,   173,   177,   178,   179,   180,   181,   185,
     186,   190,   194,   195,   196,   197
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
  "TK_LESEQ", "TK_COLEQ", "KW_AND", "KW_OR", "KW_NOT", "KW_INTEGER",
  "KW_FOR", "KW_BREAK", "KW_DEF", "KW_ENDCOMP", "KW_SCALAR", "KW_CONST",
  "KW_IN", "KW_CONTINUE", "KW_ENDDEF", "KW_OF", "KW_STR", "KW_IF",
  "KW_ENDFOR", "KW_MAIN", "KW_BOOLEAN", "KW_ELSE", "KW_WHILE", "KW_RETURN",
  "KW_ENDIF", "KW_ENDWHILE", "KW_COMP", "KW_TRUE", "KW_FALSE", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "UPLUS",
  "'.'", "'('", "')'", "'['", "']'", "':'", "';'", "$accept", "program",
  "main_block", "function_blocks", "function_block", "listofexpr", "expr",
  "listofinstructions", "statements", "statement", "if_statement",
  "const_declarations", "const_declaration", "var_declarations",
  "var_declaration", "data_type", YY_NULLPTR
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
     295,   296,   297,   298,   299,    61,    60,    62,    43,    45,
      42,    47,    37,   300,   301,    46,    40,    41,    91,    93,
      58,    59
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   -55,     5,     7,    23,   -83,   -12,   -39,    17,   -33,
      73,   -32,   330,   -21,    19,    24,   -83,   -83,    39,   -83,
      40,    73,   -83,    88,   -12,    50,   -83,   -83,   -83,   -83,
     -83,   -83,    66,    67,   136,   -83,   -83,   -12,   -83,   -83,
      54,    83,    84,    85,    86,    87,    96,   -83,   145,   223,
     139,   131,   129,   126,   127,   310,   113,    35,    21,   -83,
     112,    17,    17,   115,   144,   -83,   -83,   -83,   -83,   -83,
      22,    22,    22,    22,    22,    22,    22,    22,   -83,   116,
     180,   -83,   -83,    30,   259,   -83,   124,   135,   -83,   -83,
      22,    22,    22,    22,   103,   152,   168,   217,   233,   282,
      12,   358,    33,   164,    21,    21,   -83,    22,   414,     2,
       2,   345,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   358,   146,   -83,   298,   -83,     2,
     396,   396,    44,    44,   414,   368,    44,    44,    57,    57,
       2,     2,     2,   -83,    21,   -83,     8,   148,   -83,    21,
      10,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     3,     0,     8,
       0,     0,    52,     0,     0,     0,    59,    62,    63,    64,
      65,    61,     0,     0,     0,     9,    53,     0,     4,    60,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,     0,     0,     0,    55,    54,    56,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,    41,    49,     0,     0,     6,     0,    16,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    38,    37,     7,     0,    19,    33,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
      47,    46,    48,    42,    13,     0,    11,     0,    34,    31,
      21,    20,    23,    22,    18,    17,    24,    25,    26,    27,
      28,    29,    30,    36,     0,    35,     0,     0,    50,     0,
       0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,    15,     9,    25,   118,    13,   147,   -82,   -58,
     -83,     4,    -5,     6,    -3,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,   100,   101,    57,    58,    59,
      60,    61,     9,    62,    11,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,   104,   105,    20,     8,    12,    10,    25,    13,   112,
      15,    80,     2,    80,    21,    87,    88,    89,    25,    24,
       1,    17,    19,    16,    80,    87,    88,    89,    22,    26,
      37,    18,    90,    55,     1,    32,    87,    88,    89,    38,
      14,    56,    90,    56,     3,   157,    81,    81,   158,    18,
     161,   112,    47,    90,    56,     2,    20,   126,     3,    25,
      91,    92,    18,    56,   112,    78,    84,    83,    93,    34,
      91,    92,   156,   133,    79,    33,     1,   160,    93,    20,
      25,    91,    92,    94,    95,    96,    97,    98,    99,    93,
     135,    13,   121,   122,   123,   124,   125,    23,    81,   126,
      35,    36,    81,   108,   109,   110,   111,   123,   124,   125,
     112,    39,   126,   134,    48,   134,   113,   114,   115,   116,
     137,   117,   118,    40,    41,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
      42,    43,    44,    49,    50,    51,    52,    53,    55,   119,
     120,   121,   122,   123,   124,   125,    54,    66,   126,   112,
      65,    67,    68,    69,   127,   113,   114,   115,   116,    77,
     117,   118,     3,    82,    86,   112,    85,   103,    56,    45,
      46,   113,   114,   115,   116,   106,   117,   118,    70,    71,
      72,    73,    74,   107,   136,   102,    64,    75,   119,   120,
     121,   122,   123,   124,   125,     0,   154,   126,   159,     0,
       0,     0,     0,   128,   119,   120,   121,   122,   123,   124,
     125,     0,     0,   126,   112,    76,    55,     0,     0,   129,
     113,   114,   115,   116,     0,   117,   118,     0,     0,     0,
     112,     0,     0,     0,     0,     0,   113,   114,   115,   116,
       3,   117,   118,    63,     0,     0,    56,     0,     0,     0,
       0,     0,    80,   119,   120,   121,   122,   123,   124,   125,
       0,     0,   126,     0,     0,     0,     0,     0,   130,   119,
     120,   121,   122,   123,   124,   125,     3,     0,   126,   112,
       0,     0,    56,     0,   131,   113,   114,   115,   116,     0,
     117,   118,     0,     0,     0,   112,     0,     0,     0,     0,
       0,   113,   114,   115,   116,     0,   117,   118,    70,    71,
      72,    73,    74,     0,     0,     0,     0,    75,   119,   120,
     121,   122,   123,   124,   125,     0,     0,   126,     0,     0,
       0,     0,     0,   132,   119,   120,   121,   122,   123,   124,
     125,    27,   112,   126,     0,    76,    28,   155,   113,   114,
     115,   116,    29,   117,   118,   112,    30,     0,     0,     0,
      12,   113,   114,   115,   116,   112,   117,   118,     0,     0,
       0,   113,   114,   115,   116,     0,   117,     0,     0,     0,
       0,   119,   120,   121,   122,   123,   124,   125,     0,     0,
     126,     0,   138,   112,   119,   120,   121,   122,   123,   124,
     125,   115,   116,   126,   119,   120,   121,   122,   123,   124,
     125,   112,     0,   126,     0,     0,     0,   113,   114,   115,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,   124,   125,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,   121,   122,   123,   124,   125,     0,     0,   126
};

static const yytype_int16 yycheck[] =
{
      58,    83,    84,     8,     0,    60,     0,    10,     3,     7,
       3,     3,    24,     3,     8,     3,     4,     5,    21,    10,
       3,     6,    61,     0,     3,     3,     4,     5,    61,    61,
      21,     6,    20,     3,     3,    56,     3,     4,     5,    24,
      35,    33,    20,    33,    27,    37,   104,   105,    40,    24,
      40,     7,    37,    20,    33,    24,    61,    55,    27,    62,
      48,    49,    37,    33,     7,    30,    62,    61,    56,    45,
      48,    49,   154,    61,    39,    56,     3,   159,    56,    84,
      83,    48,    49,    70,    71,    72,    73,    74,    75,    56,
      57,     3,    48,    49,    50,    51,    52,    24,   156,    55,
      61,    61,   160,    90,    91,    92,    93,    50,    51,    52,
       7,    61,    55,   100,    60,   102,    13,    14,    15,    16,
     107,    18,    19,    57,    57,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       4,     5,     6,    60,    60,    60,    60,    60,     3,    46,
      47,    48,    49,    50,    51,    52,    60,    26,    55,     7,
      21,    32,    36,    36,    61,    13,    14,    15,    16,    56,
      18,    19,    27,    61,    30,     7,    61,    61,    33,    43,
      44,    13,    14,    15,    16,    61,    18,    19,     8,     9,
      10,    11,    12,    58,    30,    77,    49,    17,    46,    47,
      48,    49,    50,    51,    52,    -1,    60,    55,    60,    -1,
      -1,    -1,    -1,    61,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,     7,    45,     3,    -1,    -1,    61,
      13,    14,    15,    16,    -1,    18,    19,    -1,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      27,    18,    19,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,     3,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    46,
      47,    48,    49,    50,    51,    52,    27,    -1,    55,     7,
      -1,    -1,    33,    -1,    61,    13,    14,    15,    16,    -1,
      18,    19,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    18,    19,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    61,    46,    47,    48,    49,    50,    51,
      52,    21,     7,    55,    -1,    45,    26,    59,    13,    14,
      15,    16,    32,    18,    19,     7,    36,    -1,    -1,    -1,
      60,    13,    14,    15,    16,     7,    18,    19,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55,    -1,    57,     7,    46,    47,    48,    49,    50,    51,
      52,    15,    16,    55,    46,    47,    48,    49,    50,    51,
      52,     7,    -1,    55,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    24,    27,    63,    64,    65,    66,    73,    74,
      75,    76,    60,     3,    35,     3,     0,    64,    66,    61,
      74,    75,    61,    24,    65,    76,    61,    21,    26,    32,
      36,    77,    56,    56,    45,    61,    61,    65,    64,    61,
      57,    57,     4,     5,     6,    43,    44,    64,    60,    60,
      60,    60,    60,    60,    60,     3,    33,    69,    70,    71,
      72,    73,    75,    30,    69,    21,    26,    32,    36,    36,
       8,     9,    10,    11,    12,    17,    45,    56,    30,    39,
       3,    71,    61,    75,    73,    61,    30,     3,     4,     5,
      20,    48,    49,    56,    68,    68,    68,    68,    68,    68,
      67,    68,    67,    61,    70,    70,    61,    58,    68,    68,
      68,    68,     7,    13,    14,    15,    16,    18,    19,    46,
      47,    48,    49,    50,    51,    52,    55,    61,    61,    61,
      61,    61,    61,    61,    68,    57,    30,    68,    57,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    60,    59,    70,    37,    40,    60,
      70,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    75,
      75,    76,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     4,     7,     8,     2,     3,
       7,     9,     1,     2,     1,     1,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     4,     3,     3,     3,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     2,
       7,    10,     2,     3,     6,     6,     6,     6,     6,     2,
       3,     3,     1,     1,     1,     1
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
#line 82 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1530 "myparser.tab.c"
    break;

  case 3:
#line 83 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1536 "myparser.tab.c"
    break;

  case 4:
#line 84 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1542 "myparser.tab.c"
    break;

  case 5:
#line 85 "myparser.y"
                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1548 "myparser.tab.c"
    break;

  case 6:
#line 90 "myparser.y"
                                                 { printf("q");(yyval.str) = template("int main(){}");}
#line 1554 "myparser.tab.c"
    break;

  case 7:
#line 91 "myparser.y"
                                                                      { printf("w");(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1560 "myparser.tab.c"
    break;

  case 8:
#line 95 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1566 "myparser.tab.c"
    break;

  case 9:
#line 96 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1572 "myparser.tab.c"
    break;

  case 10:
#line 100 "myparser.y"
                                                                 { printf("e");(yyval.str) = template("void %s(){\n%s\n}", (yyvsp[-5].str), (yyvsp[-1].str));}
#line 1578 "myparser.tab.c"
    break;

  case 11:
#line 101 "myparser.y"
                                                                                 { printf("r");(yyval.str) = template("void %s(){\n%s\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-3].str));}
#line 1584 "myparser.tab.c"
    break;

  case 12:
#line 105 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1590 "myparser.tab.c"
    break;

  case 13:
#line 106 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1596 "myparser.tab.c"
    break;

  case 17:
#line 120 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1602 "myparser.tab.c"
    break;

  case 18:
#line 121 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1608 "myparser.tab.c"
    break;

  case 19:
#line 122 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1614 "myparser.tab.c"
    break;

  case 20:
#line 123 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1620 "myparser.tab.c"
    break;

  case 21:
#line 124 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1626 "myparser.tab.c"
    break;

  case 22:
#line 125 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1632 "myparser.tab.c"
    break;

  case 23:
#line 126 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1638 "myparser.tab.c"
    break;

  case 24:
#line 127 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1644 "myparser.tab.c"
    break;

  case 25:
#line 128 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1650 "myparser.tab.c"
    break;

  case 26:
#line 129 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1656 "myparser.tab.c"
    break;

  case 27:
#line 130 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1662 "myparser.tab.c"
    break;

  case 28:
#line 131 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1668 "myparser.tab.c"
    break;

  case 29:
#line 132 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1674 "myparser.tab.c"
    break;

  case 30:
#line 133 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1680 "myparser.tab.c"
    break;

  case 31:
#line 134 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1686 "myparser.tab.c"
    break;

  case 32:
#line 135 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 1692 "myparser.tab.c"
    break;

  case 33:
#line 136 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1698 "myparser.tab.c"
    break;

  case 34:
#line 137 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 1704 "myparser.tab.c"
    break;

  case 35:
#line 138 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1710 "myparser.tab.c"
    break;

  case 36:
#line 139 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1716 "myparser.tab.c"
    break;

  case 37:
#line 143 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 1722 "myparser.tab.c"
    break;

  case 38:
#line 144 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 1728 "myparser.tab.c"
    break;

  case 39:
#line 145 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 1734 "myparser.tab.c"
    break;

  case 40:
#line 151 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 1740 "myparser.tab.c"
    break;

  case 41:
#line 152 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1746 "myparser.tab.c"
    break;

  case 42:
#line 156 "myparser.y"
                                    {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1752 "myparser.tab.c"
    break;

  case 43:
#line 157 "myparser.y"
                                     {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1758 "myparser.tab.c"
    break;

  case 44:
#line 158 "myparser.y"
                                     {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1764 "myparser.tab.c"
    break;

  case 45:
#line 159 "myparser.y"
                                     {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1770 "myparser.tab.c"
    break;

  case 46:
#line 160 "myparser.y"
                                     {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1776 "myparser.tab.c"
    break;

  case 47:
#line 161 "myparser.y"
                                     {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1782 "myparser.tab.c"
    break;

  case 48:
#line 162 "myparser.y"
                                     {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 1788 "myparser.tab.c"
    break;

  case 49:
#line 163 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 1794 "myparser.tab.c"
    break;

  case 50:
#line 167 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1800 "myparser.tab.c"
    break;

  case 51:
#line 168 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\nelse{\n%s\n}\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1806 "myparser.tab.c"
    break;

  case 52:
#line 172 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 1812 "myparser.tab.c"
    break;

  case 53:
#line 173 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1818 "myparser.tab.c"
    break;

  case 54:
#line 177 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1824 "myparser.tab.c"
    break;

  case 55:
#line 178 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1830 "myparser.tab.c"
    break;

  case 56:
#line 179 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1836 "myparser.tab.c"
    break;

  case 57:
#line 180 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 1842 "myparser.tab.c"
    break;

  case 58:
#line 181 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 1848 "myparser.tab.c"
    break;

  case 59:
#line 185 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 1854 "myparser.tab.c"
    break;

  case 60:
#line 186 "myparser.y"
                                               {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1860 "myparser.tab.c"
    break;

  case 61:
#line 190 "myparser.y"
                               {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1866 "myparser.tab.c"
    break;

  case 62:
#line 194 "myparser.y"
                   {(yyval.str) = template("int");}
#line 1872 "myparser.tab.c"
    break;

  case 63:
#line 195 "myparser.y"
                    {(yyval.str) = template("double");}
#line 1878 "myparser.tab.c"
    break;

  case 64:
#line 196 "myparser.y"
                 {(yyval.str) = template("char*");}
#line 1884 "myparser.tab.c"
    break;

  case 65:
#line 197 "myparser.y"
                      {(yyval.str) = template("int");}
#line 1890 "myparser.tab.c"
    break;


#line 1894 "myparser.tab.c"

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
#line 208 "myparser.y"

int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
