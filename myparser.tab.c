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
	int isStr = 0;	//used for multiple variables declaration in one line
	char expression[100], toBeReplaced[100], replacer[100];		//for list comprehension
	void replaceWord(char* str, char* oldWord, char* newWord);



#line 85 "myparser.tab.c"

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
#line 16 "myparser.y"

	char* str;

#line 189 "myparser.tab.c"

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
#define YYLAST   1017

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

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
       0,    87,    87,    88,    89,    90,    95,    96,   100,   101,
     102,   106,   107,   108,   109,   114,   115,   119,   120,   121,
     122,   123,   147,   148,   152,   153,   157,   158,   162,   163,
     164,   165,   166,   167,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   199,   200,   201,   202,   203,
     209,   210,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   233,   234,
     235,   239,   240,   241,   242,   243,   244,   257,   258,   262,
     263,   264,   265,   269,   274,   288,   289,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   306,   307,   311,   312,
     316,   317,   318,   322,   323,   324,   328,   336,   346,   354,
     364,   372,   382,   383,   384,   385
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

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,    76,    36,    44,    20,   -98,    54,    38,    16,    64,
      18,    86,   -98,   -98,   -98,   -98,   -98,    13,   228,   104,
      72,   124,   128,   -98,   -98,   116,   -98,   122,    18,   -98,
     199,    54,   141,   -98,   145,    53,   -98,   -98,   -98,   -98,
     -98,   114,   -98,   209,   156,   575,   -98,   -98,    54,   -98,
     -98,   119,   228,   212,   228,   -13,   -98,   155,   163,   164,
     166,   168,   170,    23,   139,   -98,   228,   230,   -98,   182,
     -98,   -98,   -12,   209,    31,   223,   219,   216,   210,   220,
     195,   197,   201,   203,   -98,   222,   -98,   208,   281,   117,
     218,   -98,    75,   266,   211,   229,   231,   238,   239,   -98,
     235,   254,   417,   -98,   461,   240,   242,   247,   253,   255,
     260,   260,   -98,   -98,   -98,   -98,   -98,   298,   294,   302,
     307,   321,   126,   -98,   -98,   -98,   -98,   267,    17,   214,
     271,   688,     6,   309,   -98,   -98,   -98,   509,   509,   -98,
     274,    -6,   -98,   509,   509,   509,   509,   509,   509,   509,
     -98,   -98,   -98,   -98,   -98,   417,   420,   417,   277,   -98,
     -98,   -98,   -98,   280,   228,   310,   -98,   282,   509,   306,
     509,    49,   -98,   -98,   -98,   509,   -98,   -98,   509,   509,
     509,   -98,   -98,    67,   875,   283,   287,   290,   707,   875,
     737,   -98,   191,   448,   470,   520,   536,   586,   602,    19,
     417,   417,   127,   -98,   -98,   317,   652,   509,   898,   509,
     945,    11,    11,   851,   -98,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   -98,   119,   509,   297,   875,   299,   301,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   228,   -98,   319,   668,   361,
     803,   -98,   875,    11,   961,   961,    45,    45,   945,   922,
      45,    45,   148,   148,    11,    11,    11,   -98,   777,   236,
     289,   -98,   -98,   -98,   336,   308,   -98,   509,   311,   -98,
     248,   -98,   303,   -98,     9,   753,   329,   322,   -98,   -98,
     320,   353,   325,   509,   -98,   332,   351,   326,   392,   354,
     827,   -98,   -98,   373,   228,   370,   -98,   376,   343,   -98,
     -98,   401,   -98,   395,   348,   -98,   398,   356,   -98,   228,
     -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,   108,   109,   115,   114,   113,     0,     0,     0,
       0,     0,     0,     1,     3,     0,    15,     0,     0,    95,
       0,     0,     0,   106,     0,     0,   122,   123,   124,   125,
     110,     0,   121,     8,     0,     0,    16,    96,     0,     4,
     107,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,   112,     0,
     117,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   119,     0,     0,     0,
       0,    10,    78,     0,     0,     0,     0,     0,     0,    77,
       0,     0,    57,    60,     0,     0,     0,     0,     0,     0,
       0,     0,   100,    97,   103,   104,   105,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     6,     0,     0,    74,
       0,    78,    61,     0,     0,     0,     0,     0,     0,     0,
      69,    71,    70,    75,    76,    59,     0,    58,     0,   101,
      98,   102,    99,     0,     0,     0,    17,     0,     0,     0,
       0,    30,    28,    29,    31,     0,    33,    32,     0,     0,
       0,    23,    54,     0,    24,     0,     0,     0,     0,    26,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    55,     0,   116,    19,     0,     0,     0,     0,     0,
      36,    50,    49,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    79,     0,     0,    27,     0,     0,    63,    64,
      65,    67,    66,    68,    62,     0,    18,     0,     0,     0,
       0,    51,    25,    48,    38,    37,    40,    39,    35,    34,
      41,    42,    43,    44,    45,    46,    47,    53,     0,     0,
       0,    79,   118,    21,     0,     0,    52,     0,     0,    82,
       0,    88,     0,    20,     0,     0,     0,     0,    81,    87,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,    92,     0,     0,    83,
      93,     0,    91,     0,     0,    90,     0,     0,    89,     0,
      94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,    71,   -98,   -98,     2,   180,   -73,   -98,   -39,
     -57,   -54,   -78,   -97,   -98,   -98,   -98,   -98,   -98,   -98,
       4,    -5,     7,    -2,   -98,   -98,   371,   342,   407,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    55,    90,     6,     7,   182,   183,   188,
     189,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     9,   111,    11,    12,    13,    14,    15,    16,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,   100,    71,    27,     8,   142,    88,    10,    32,   185,
     186,   130,    31,   290,    84,    28,   100,    34,   216,     1,
      23,     1,   171,   172,   173,   174,    32,    80,    81,   100,
      48,    36,   155,   157,    92,   128,    37,   100,   100,    20,
     175,    56,    38,    30,     3,    72,    39,    22,   166,    89,
      73,   131,   216,   192,    93,    94,   100,   167,   142,     3,
     142,    95,    96,   176,   177,    97,    35,   230,   178,   179,
      98,    91,    21,    35,   184,   169,   180,    24,   200,     2,
     201,   244,   100,   100,   100,   100,   193,   194,   195,   196,
     197,   198,   130,    99,   225,   226,   227,   228,   229,   190,
      26,   230,    49,   142,   142,    27,   131,    41,   209,    32,
     199,   206,   203,   208,    52,   158,    53,   156,   210,    65,
      92,   211,   212,   213,     1,   214,    29,   100,   100,    43,
     215,   235,   131,   235,   132,    17,    18,    18,    19,    19,
      93,    94,   235,    82,    83,     3,     2,    95,    33,     3,
     248,    97,   250,    27,    32,   216,    98,   127,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,    45,    54,   268,    19,    46,    99,
      66,    44,    67,   142,    47,   142,    25,   164,   245,    53,
      67,   280,   282,   272,   185,   237,   100,   100,   142,   227,
     228,   229,    20,    50,   230,    51,   142,   100,   295,   100,
     142,    25,     1,   100,    57,    69,    74,    92,   303,   142,
     285,   307,   100,   100,    75,    76,   100,    77,    25,    78,
     100,    79,   291,    85,   100,   316,   300,    93,    94,   141,
     100,    87,     3,   100,    95,   112,   113,   115,    97,   114,
      36,   141,   310,    98,   168,    37,   117,   116,   118,    93,
      94,    38,   119,    92,   120,    39,    95,   320,   122,   133,
      97,    93,    94,   134,   278,    98,    99,   279,    95,   129,
     141,   121,    97,    93,    94,   140,   287,    98,     3,   288,
      95,   135,   141,   136,    97,   137,   138,   139,    99,    98,
      93,    94,   150,   123,   151,     3,   141,    95,   124,   152,
      99,    97,    93,    94,   125,   153,    98,   154,   126,    95,
     159,   160,    99,    97,   161,   163,    93,    94,    98,   165,
     170,   281,   141,    95,   162,   141,   191,    97,   187,    99,
     202,   204,    98,   231,   205,   289,   207,   232,   246,   233,
     273,    99,    93,    94,   141,    93,    94,   141,   269,    95,
     270,   271,    95,    97,   275,    99,    97,   283,    98,   284,
     294,    98,   286,   301,    93,    94,   141,    93,    94,   141,
     297,    95,   298,   296,    95,    97,   299,   304,    97,   306,
      98,    99,   302,    98,    99,   305,    93,    94,   141,    93,
      94,   141,   311,    95,   313,   314,    95,    97,   317,    86,
      97,   312,    98,    99,   309,    98,    99,   319,    93,    94,
     141,    93,    94,    92,    70,    95,    42,     0,    95,    97,
     315,     0,    97,   318,    98,    99,     0,    98,    99,     0,
      93,    94,     0,    93,    94,     0,     0,    95,     0,     0,
      95,    97,     0,     0,    97,   216,    98,    99,     0,    98,
      99,   217,   218,   219,   220,     0,     0,   221,   222,   143,
     144,   145,   146,   147,     0,     0,     0,   216,   148,    99,
       0,     0,    99,   217,   218,   219,   220,     0,     0,   221,
     222,     0,     0,     0,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,   230,     0,     0,   149,     0,     0,
     238,     0,   171,   172,   173,   174,     0,   223,   224,   225,
     226,   227,   228,   229,     0,     0,   230,   216,     0,     0,
     175,     0,   239,   217,   218,   219,   220,     0,     0,   221,
     222,     0,     0,   216,     0,     0,     0,     0,     0,   217,
     218,   219,   220,   176,   177,   221,   222,     0,   178,   179,
       0,     0,     0,     0,     0,     0,   180,   223,   224,   225,
     226,   227,   228,   229,     0,     0,   230,     0,     0,    58,
      59,    60,   240,   223,   224,   225,   226,   227,   228,   229,
       0,     0,   230,   216,     0,     0,     0,     0,   241,   217,
     218,   219,   220,     0,     0,   221,   222,     0,     0,   216,
       0,     0,     0,     0,     0,   217,   218,   219,   220,    61,
      62,   221,   222,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   225,   226,   227,   228,   229,
       0,     0,   230,     0,     0,     0,     0,     0,   242,   223,
     224,   225,   226,   227,   228,   229,     0,     0,   230,   216,
       0,     0,     0,     0,   243,   217,   218,   219,   220,     0,
       0,   221,   222,     0,     0,   216,     0,     0,     0,     0,
       0,   217,   218,   219,   220,     0,     0,   221,   222,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,   223,
     224,   225,   226,   227,   228,   229,     0,     0,   230,   175,
     171,   172,   173,   174,   247,   223,   224,   225,   226,   227,
     228,   229,     0,     0,   230,     0,     0,     0,   175,     0,
     274,     0,   176,   177,     0,     0,     0,   178,   179,     0,
     171,   172,   173,   174,     0,   180,   181,     0,     0,     0,
       0,   176,   177,     0,     0,     0,   178,   179,   175,     0,
     216,     0,     0,     0,   180,   234,   217,   218,   219,   220,
       0,     0,   221,   222,     0,     0,     0,     0,     0,     0,
       0,   176,   177,     0,   216,     0,   178,   179,     0,     0,
     217,   218,   219,   220,   180,   236,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,     0,     0,   230,
     216,     0,     0,   292,   293,     0,   217,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,     0,   230,   216,     0,     0,     0,   277,     0,
     217,   218,   219,   220,     0,     0,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,     0,   216,   230,
       0,     0,     0,   276,   217,   218,   219,   220,     0,     0,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,     0,   216,   230,     0,     0,     0,   308,   217,   218,
     219,   220,     0,     0,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   216,     0,   230,     0,   251,
       0,   217,   218,   219,   220,     0,     0,   221,   222,     0,
       0,   249,   223,   224,   225,   226,   227,   228,   229,   216,
       0,   230,     0,     0,     0,   217,   218,   219,   220,     0,
       0,   221,     0,     0,     0,   223,   224,   225,   226,   227,
     228,   229,   216,     0,   230,     0,     0,     0,   217,   218,
     219,   220,     0,     0,     0,     0,     0,     0,   216,   223,
     224,   225,   226,   227,   228,   229,   219,   220,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,   224,   225,   226,   227,   228,   229,     0,
       0,   230,     0,     0,     0,     0,     0,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,   230
};

static const yytype_int16 yycheck[] =
{
      52,    74,    54,     8,     0,   102,    18,     0,    10,     3,
       4,    17,    10,     4,    66,     8,    89,     4,     7,     3,
       0,     3,     3,     4,     5,     6,    28,     4,     5,   102,
      28,    22,   110,   111,     3,    89,    27,   110,   111,     3,
      21,    43,    33,    25,    28,    58,    37,     3,    31,    61,
      63,    57,     7,    59,    23,    24,   129,    40,   155,    28,
     157,    30,    31,    44,    45,    34,    60,    56,    49,    50,
      39,    73,    36,    60,   131,   129,    57,     6,   156,    25,
     158,    62,   155,   156,   157,   158,   143,   144,   145,   146,
     147,   148,    17,    62,    49,    50,    51,    52,    53,   138,
      62,    56,    31,   200,   201,   110,    57,     3,    59,   111,
     149,   168,   164,   170,    61,   111,    63,   110,   175,    48,
       3,   178,   179,   180,     3,    58,    62,   200,   201,    57,
      63,   188,    57,   190,    59,    59,    61,    61,    63,    63,
      23,    24,   199,     4,     5,    28,    25,    30,    62,    28,
     207,    34,   209,   158,   156,     7,    39,    40,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    46,    61,   233,    63,    62,    62,
      61,    57,    63,   280,    62,   282,     6,    61,    61,    63,
      63,   269,   270,   245,     3,     4,   269,   270,   295,    51,
      52,    53,     3,    62,    56,    60,   303,   280,   286,   282,
     307,    31,     3,   286,    58,     3,    61,     3,   296,   316,
     277,   299,   295,   296,    61,    61,   299,    61,    48,    61,
     303,    61,   284,     3,   307,   313,   293,    23,    24,     3,
     313,    59,    28,   316,    30,    22,    27,    37,    34,    33,
      22,     3,   304,    39,    40,    27,    61,    37,    61,    23,
      24,    33,    61,     3,    61,    37,    30,   319,    60,     3,
      34,    23,    24,    62,    38,    39,    62,    41,    30,    61,
       3,    59,    34,    23,    24,    31,    38,    39,    28,    41,
      30,    62,     3,    62,    34,    57,    57,    62,    62,    39,
      23,    24,    62,    22,    62,    28,     3,    30,    27,    62,
      62,    34,    23,    24,    33,    62,    39,    62,    37,    30,
      22,    27,    62,    34,    22,     4,    23,    24,    39,    62,
      59,    42,     3,    30,    27,     3,    62,    34,    29,    62,
      60,    31,    39,    60,    62,    42,    40,    60,    31,    59,
      31,    62,    23,    24,     3,    23,    24,     3,    61,    30,
      61,    60,    30,    34,     3,    62,    34,    31,    39,    61,
      41,    39,    61,    41,    23,    24,     3,    23,    24,     3,
      60,    30,    29,    61,    30,    34,    61,    61,    34,    35,
      39,    62,    41,    39,    62,     3,    23,    24,     3,    23,
      24,     3,    32,    30,    61,     4,    30,    34,    60,    67,
      34,    35,    39,    62,    41,    39,    62,    61,    23,    24,
       3,    23,    24,     3,    53,    30,    19,    -1,    30,    34,
      35,    -1,    34,    35,    39,    62,    -1,    39,    62,    -1,
      23,    24,    -1,    23,    24,    -1,    -1,    30,    -1,    -1,
      30,    34,    -1,    -1,    34,     7,    39,    62,    -1,    39,
      62,    13,    14,    15,    16,    -1,    -1,    19,    20,     8,
       9,    10,    11,    12,    -1,    -1,    -1,     7,    17,    62,
      -1,    -1,    62,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    46,    -1,    -1,
      62,    -1,     3,     4,     5,     6,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,     7,    -1,    -1,
      21,    -1,    62,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    44,    45,    19,    20,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    -1,     4,
       5,     6,    62,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,     7,    -1,    -1,    -1,    -1,    62,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    44,
      45,    19,    20,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,     7,
      -1,    -1,    -1,    -1,    62,    13,    14,    15,    16,    -1,
      -1,    19,    20,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    21,
       3,     4,     5,     6,    62,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    21,    -1,
      62,    -1,    44,    45,    -1,    -1,    -1,    49,    50,    -1,
       3,     4,     5,     6,    -1,    57,    58,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    49,    50,    21,    -1,
       7,    -1,    -1,    -1,    57,    58,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,     7,    -1,    49,    50,    -1,    -1,
      13,    14,    15,    16,    57,    58,    19,    20,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
       7,    -1,    -1,    60,    61,    -1,    13,    14,    15,    16,
      -1,    -1,    19,    20,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,     7,    -1,    -1,    -1,    61,    -1,
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
       0,     3,    25,    28,    65,    66,    69,    70,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    59,    61,    63,
       3,    36,     3,     0,    66,    70,    62,    85,    86,    62,
      25,    69,    87,    62,     4,    60,    22,    27,    33,    37,
      93,     3,    92,    57,    57,    46,    62,    62,    69,    66,
      62,    60,    61,    63,    61,    67,    87,    58,     4,     5,
       6,    44,    45,    49,    50,    66,    61,    63,    93,     3,
      90,    93,    58,    63,    61,    61,    61,    61,    61,    61,
       4,     5,     4,     5,    93,     3,    91,    59,    18,    61,
      68,    87,     3,    23,    24,    30,    31,    34,    39,    62,
      71,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    86,    22,    27,    33,    37,    37,    61,    61,    61,
      61,    59,    60,    22,    27,    33,    37,    40,    75,    61,
      17,    57,    59,     3,    62,    62,    62,    57,    57,    62,
      31,     3,    77,     8,     9,    10,    11,    12,    17,    46,
      62,    62,    62,    62,    62,    76,    86,    76,    84,    22,
      27,    22,    27,     4,    61,    62,    31,    40,    40,    75,
      59,     3,     4,     5,     6,    21,    44,    45,    49,    50,
      57,    58,    71,    72,    74,     3,     4,    29,    73,    74,
      73,    62,    59,    74,    74,    74,    74,    74,    74,    73,
      76,    76,    60,    93,    31,    62,    74,    40,    74,    59,
      74,    74,    74,    74,    58,    63,     7,    13,    14,    15,
      16,    19,    20,    47,    48,    49,    50,    51,    52,    53,
      56,    60,    60,    59,    58,    74,    58,     4,    62,    62,
      62,    62,    62,    62,    62,    61,    31,    62,    74,    23,
      74,    58,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    61,
      61,    60,    93,    31,    62,     3,    60,    61,    38,    41,
      76,    42,    76,    31,    61,    74,    61,    38,    41,    42,
       4,    93,    60,    61,    41,    76,    61,    60,    29,    61,
      74,    41,    41,    76,    61,     3,    35,    76,    60,    41,
      93,    32,    35,    61,     4,    35,    76,    60,    35,    61,
      93
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
      92,    92,    93,    93,    93,    93
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
       5,     3,     1,     1,     1,     1
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
#line 87 "myparser.y"
                                                                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n", (yyvsp[0].str));}}
#line 1717 "myparser.tab.c"
    break;

  case 3:
#line 88 "myparser.y"
                                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1723 "myparser.tab.c"
    break;

  case 4:
#line 89 "myparser.y"
                                                                                                                                {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1729 "myparser.tab.c"
    break;

  case 5:
#line 90 "myparser.y"
                                                                                                                        {if (yyerror_count == 0) {puts(c_prologue); printf("%s\n%s\n%s\n%s", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}}
#line 1735 "myparser.tab.c"
    break;

  case 6:
#line 95 "myparser.y"
                                                 {(yyval.str) = template("int main(){}");}
#line 1741 "myparser.tab.c"
    break;

  case 7:
#line 96 "myparser.y"
                                                                      {(yyval.str) = template("int main(){\n%s\n}",(yyvsp[-2].str));}
#line 1747 "myparser.tab.c"
    break;

  case 8:
#line 100 "myparser.y"
               {(yyval.str) = template("");}
#line 1753 "myparser.tab.c"
    break;

  case 9:
#line 101 "myparser.y"
                          {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1759 "myparser.tab.c"
    break;

  case 10:
#line 102 "myparser.y"
                                                  {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1765 "myparser.tab.c"
    break;

  case 11:
#line 106 "myparser.y"
                               {(yyval.str) = template("int");}
#line 1771 "myparser.tab.c"
    break;

  case 12:
#line 107 "myparser.y"
                                {(yyval.str) = template("double");}
#line 1777 "myparser.tab.c"
    break;

  case 13:
#line 108 "myparser.y"
                             {(yyval.str) = template("char*");}
#line 1783 "myparser.tab.c"
    break;

  case 14:
#line 109 "myparser.y"
                                  {(yyval.str) = template("int");}
#line 1789 "myparser.tab.c"
    break;

  case 15:
#line 114 "myparser.y"
                           {(yyval.str) = template("%s", (yyvsp[-1].str));}
#line 1795 "myparser.tab.c"
    break;

  case 16:
#line 115 "myparser.y"
                                             {(yyval.str) = template("%s \n%s", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 1801 "myparser.tab.c"
    break;

  case 17:
#line 119 "myparser.y"
                                                                                     {(yyval.str) = template("void %s(%s){\n%s\n}", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 1807 "myparser.tab.c"
    break;

  case 18:
#line 120 "myparser.y"
                                                                                                     {(yyval.str) = template("void %s(%s){\n%s\nreturn;\n}", (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-3].str));}
#line 1813 "myparser.tab.c"
    break;

  case 19:
#line 121 "myparser.y"
                                                                                   {(yyval.str) = template("void %s(%s){\nreturn;\n}", (yyvsp[-7].str), (yyvsp[-5].str));}
#line 1819 "myparser.tab.c"
    break;

  case 20:
#line 122 "myparser.y"
                                                                                                                                {(yyval.str) = template("%s %s(%s){\n%s\nreturn %s;\n}", (yyvsp[-6].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-4].str), (yyvsp[-2].str));}
#line 1825 "myparser.tab.c"
    break;

  case 21:
#line 123 "myparser.y"
                                                                                                              {(yyval.str) = template("%s %s(%s){\nreturn %s;\n}", (yyvsp[-5].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1831 "myparser.tab.c"
    break;

  case 22:
#line 147 "myparser.y"
                                         {(yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1837 "myparser.tab.c"
    break;

  case 23:
#line 148 "myparser.y"
                           {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 1843 "myparser.tab.c"
    break;

  case 24:
#line 152 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1849 "myparser.tab.c"
    break;

  case 25:
#line 153 "myparser.y"
                                   {(yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1855 "myparser.tab.c"
    break;

  case 26:
#line 157 "myparser.y"
             {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1861 "myparser.tab.c"
    break;

  case 27:
#line 158 "myparser.y"
                          {(yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1867 "myparser.tab.c"
    break;

  case 32:
#line 166 "myparser.y"
                        {(yyval.str) = template("0");}
#line 1873 "myparser.tab.c"
    break;

  case 33:
#line 167 "myparser.y"
                        {(yyval.str) = template("1");}
#line 1879 "myparser.tab.c"
    break;

  case 34:
#line 175 "myparser.y"
                          {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1885 "myparser.tab.c"
    break;

  case 35:
#line 176 "myparser.y"
                           {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1891 "myparser.tab.c"
    break;

  case 36:
#line 177 "myparser.y"
                      {(yyval.str) = template("!%s", (yyvsp[0].str));}
#line 1897 "myparser.tab.c"
    break;

  case 37:
#line 178 "myparser.y"
                             {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1903 "myparser.tab.c"
    break;

  case 38:
#line 179 "myparser.y"
                            {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1909 "myparser.tab.c"
    break;

  case 39:
#line 180 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1915 "myparser.tab.c"
    break;

  case 40:
#line 181 "myparser.y"
                             {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1921 "myparser.tab.c"
    break;

  case 41:
#line 182 "myparser.y"
                        {(yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1927 "myparser.tab.c"
    break;

  case 42:
#line 183 "myparser.y"
                        {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1933 "myparser.tab.c"
    break;

  case 43:
#line 184 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1939 "myparser.tab.c"
    break;

  case 44:
#line 185 "myparser.y"
                        {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1945 "myparser.tab.c"
    break;

  case 45:
#line 186 "myparser.y"
                        {(yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1951 "myparser.tab.c"
    break;

  case 46:
#line 187 "myparser.y"
                        {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1957 "myparser.tab.c"
    break;

  case 47:
#line 188 "myparser.y"
                        {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1963 "myparser.tab.c"
    break;

  case 48:
#line 189 "myparser.y"
                           {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1969 "myparser.tab.c"
    break;

  case 49:
#line 190 "myparser.y"
                                {(yyval.str) = template("- %s", (yyvsp[0].str));}
#line 1975 "myparser.tab.c"
    break;

  case 50:
#line 191 "myparser.y"
                               {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 1981 "myparser.tab.c"
    break;

  case 51:
#line 192 "myparser.y"
                       {(yyval.str) = template("(%s)", (yyvsp[-1].str));}
#line 1987 "myparser.tab.c"
    break;

  case 52:
#line 193 "myparser.y"
                                {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1993 "myparser.tab.c"
    break;

  case 53:
#line 194 "myparser.y"
                        {(yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1999 "myparser.tab.c"
    break;

  case 54:
#line 195 "myparser.y"
                                 {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2005 "myparser.tab.c"
    break;

  case 55:
#line 199 "myparser.y"
                                                       {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2011 "myparser.tab.c"
    break;

  case 56:
#line 200 "myparser.y"
                                                         {(yyval.str) = template("%s\n%s\n%s",(yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2017 "myparser.tab.c"
    break;

  case 57:
#line 201 "myparser.y"
                     {(yyval.str) = template("%s",(yyvsp[0].str));}
#line 2023 "myparser.tab.c"
    break;

  case 58:
#line 202 "myparser.y"
                                      {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2029 "myparser.tab.c"
    break;

  case 59:
#line 203 "myparser.y"
                                        {(yyval.str) = template("%s\n%s",(yyvsp[-1].str), (yyvsp[0].str));}
#line 2035 "myparser.tab.c"
    break;

  case 60:
#line 209 "myparser.y"
                   { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2041 "myparser.tab.c"
    break;

  case 61:
#line 210 "myparser.y"
                               { (yyval.str) = template("%s \n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2047 "myparser.tab.c"
    break;

  case 62:
#line 214 "myparser.y"
                                      {(yyval.str) = template("%s = %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2053 "myparser.tab.c"
    break;

  case 63:
#line 215 "myparser.y"
                                       {(yyval.str) = template("%s += %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2059 "myparser.tab.c"
    break;

  case 64:
#line 216 "myparser.y"
                                       {(yyval.str) = template("%s -= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2065 "myparser.tab.c"
    break;

  case 65:
#line 217 "myparser.y"
                                       {(yyval.str) = template("%s *= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2071 "myparser.tab.c"
    break;

  case 66:
#line 218 "myparser.y"
                                       {(yyval.str) = template("%s %= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2077 "myparser.tab.c"
    break;

  case 67:
#line 219 "myparser.y"
                                       {(yyval.str) = template("%s /= %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2083 "myparser.tab.c"
    break;

  case 68:
#line 220 "myparser.y"
                                       {(yyval.str) = template("%s := %s;",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2089 "myparser.tab.c"
    break;

  case 69:
#line 221 "myparser.y"
                           {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2095 "myparser.tab.c"
    break;

  case 70:
#line 222 "myparser.y"
                            {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2101 "myparser.tab.c"
    break;

  case 71:
#line 223 "myparser.y"
                              {(yyval.str) = template("%s",(yyvsp[-1].str));}
#line 2107 "myparser.tab.c"
    break;

  case 72:
#line 224 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2113 "myparser.tab.c"
    break;

  case 73:
#line 225 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2119 "myparser.tab.c"
    break;

  case 74:
#line 226 "myparser.y"
                                     {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2125 "myparser.tab.c"
    break;

  case 75:
#line 227 "myparser.y"
                                       {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2131 "myparser.tab.c"
    break;

  case 76:
#line 228 "myparser.y"
                                   {(yyval.str) = template("%s;",(yyvsp[-1].str));}
#line 2137 "myparser.tab.c"
    break;

  case 77:
#line 229 "myparser.y"
              {(yyval.str) = template("");}
#line 2143 "myparser.tab.c"
    break;

  case 78:
#line 233 "myparser.y"
                 { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2149 "myparser.tab.c"
    break;

  case 79:
#line 234 "myparser.y"
                                       {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2155 "myparser.tab.c"
    break;

  case 80:
#line 235 "myparser.y"
                                    {(yyval.str) = template("%s[%s]",(yyvsp[-3].str), (yyvsp[-1].str));}
#line 2161 "myparser.tab.c"
    break;

  case 81:
#line 239 "myparser.y"
                                                         {(yyval.str) = template("if(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2167 "myparser.tab.c"
    break;

  case 82:
#line 240 "myparser.y"
                                                {(yyval.str) = template("if(%s){\n}", (yyvsp[-3].str));}
#line 2173 "myparser.tab.c"
    break;

  case 83:
#line 241 "myparser.y"
                                                                                  {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n%s\n}", (yyvsp[-7].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2179 "myparser.tab.c"
    break;

  case 84:
#line 242 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n}\nelse{\n%s\n}", (yyvsp[-6].str), (yyvsp[-1].str));}
#line 2185 "myparser.tab.c"
    break;

  case 85:
#line 243 "myparser.y"
                                                                        {(yyval.str) = template("if(%s){\n%s\n}\nelse{\n}", (yyvsp[-6].str), (yyvsp[-3].str));}
#line 2191 "myparser.tab.c"
    break;

  case 86:
#line 244 "myparser.y"
                                                             {(yyval.str) = template("if(%s){\n}\nelse{\n}", (yyvsp[-5].str));}
#line 2197 "myparser.tab.c"
    break;

  case 87:
#line 257 "myparser.y"
                                                               {(yyval.str) = template("while(%s){\n%s\n}", (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2203 "myparser.tab.c"
    break;

  case 88:
#line 258 "myparser.y"
                                                      {(yyval.str) = template("while(%s){\n}", (yyvsp[-3].str));}
#line 2209 "myparser.tab.c"
    break;

  case 89:
#line 262 "myparser.y"
                                                                                      {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n%s\n}", (yyvsp[-11].str), (yyvsp[-8].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-4].str), (yyvsp[-1].str));}
#line 2215 "myparser.tab.c"
    break;

  case 90:
#line 263 "myparser.y"
                                                                             {(yyval.str) = template("for (int %s=%s; %s<%s; %s+=%s){\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-3].str));}
#line 2221 "myparser.tab.c"
    break;

  case 91:
#line 264 "myparser.y"
                                                                               {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n%s\n}", (yyvsp[-9].str), (yyvsp[-6].str), (yyvsp[-9].str), (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-1].str));}
#line 2227 "myparser.tab.c"
    break;

  case 92:
#line 265 "myparser.y"
                                                                    {(yyval.str) = template("for (int %s=%s; %s<%s; %s++){\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-8].str), (yyvsp[-3].str), (yyvsp[-8].str));}
#line 2233 "myparser.tab.c"
    break;

  case 93:
#line 270 "myparser.y"
        {(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor(int %s = 0; %s < %s; ++%s)\n%s[%s] = %s", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[0].str), (yyvsp[-3].str), (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-7].str));}
#line 2239 "myparser.tab.c"
    break;

  case 94:
#line 275 "myparser.y"
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
#line 2254 "myparser.tab.c"
    break;

  case 95:
#line 288 "myparser.y"
                              {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2260 "myparser.tab.c"
    break;

  case 96:
#line 289 "myparser.y"
                                                   {(yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2266 "myparser.tab.c"
    break;

  case 97:
#line 293 "myparser.y"
                                                          {(yyval.str) = template("const double %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2272 "myparser.tab.c"
    break;

  case 98:
#line 294 "myparser.y"
                                                                {(yyval.str) = template("const double %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2278 "myparser.tab.c"
    break;

  case 99:
#line 295 "myparser.y"
                                                                {(yyval.str) = template("const double %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2284 "myparser.tab.c"
    break;

  case 100:
#line 296 "myparser.y"
                                                                 {(yyval.str) = template("const int %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2290 "myparser.tab.c"
    break;

  case 101:
#line 297 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = %s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2296 "myparser.tab.c"
    break;

  case 102:
#line 298 "myparser.y"
                                                                     {(yyval.str) = template("const int %s = -%s", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2302 "myparser.tab.c"
    break;

  case 103:
#line 299 "myparser.y"
                                                             {(yyval.str) = template("const char* %s = %s", (yyvsp[-4].str), (yyvsp[-2].str));}
#line 2308 "myparser.tab.c"
    break;

  case 104:
#line 300 "myparser.y"
                                                             {(yyval.str) = template("const int %s = 1", (yyvsp[-4].str));}
#line 2314 "myparser.tab.c"
    break;

  case 105:
#line 301 "myparser.y"
                                                              {(yyval.str) = template("const int %s = 0", (yyvsp[-4].str));}
#line 2320 "myparser.tab.c"
    break;

  case 106:
#line 306 "myparser.y"
                            {(yyval.str) = template("%s;", (yyvsp[-1].str));}
#line 2326 "myparser.tab.c"
    break;

  case 107:
#line 307 "myparser.y"
                                               { (yyval.str) = template("%s \n%s;", (yyvsp[-2].str), (yyvsp[-1].str));}
#line 2332 "myparser.tab.c"
    break;

  case 108:
#line 311 "myparser.y"
                {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2338 "myparser.tab.c"
    break;

  case 109:
#line 312 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2344 "myparser.tab.c"
    break;

  case 110:
#line 316 "myparser.y"
                               {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2350 "myparser.tab.c"
    break;

  case 111:
#line 317 "myparser.y"
                                                     {(yyval.str) = template("%s %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));}
#line 2356 "myparser.tab.c"
    break;

  case 112:
#line 318 "myparser.y"
                                         {(yyval.str) = template("%s* %s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2362 "myparser.tab.c"
    break;

  case 113:
#line 322 "myparser.y"
                    {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2368 "myparser.tab.c"
    break;

  case 114:
#line 323 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2374 "myparser.tab.c"
    break;

  case 115:
#line 324 "myparser.y"
                      {(yyval.str) = template("%s", (yyvsp[0].str));}
#line 2380 "myparser.tab.c"
    break;

  case 116:
#line 328 "myparser.y"
                                                            {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s* %s, **%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s* %s, *%s", (yyvsp[0].str), (yyvsp[-8].str), (yyvsp[-4].str));
										}}
#line 2393 "myparser.tab.c"
    break;

  case 117:
#line 336 "myparser.y"
                                            {if(isStr == 1){
											(yyval.str) = template("%s, **%s", (yyvsp[0].str), (yyvsp[-4].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-4].str));
										}}
#line 2405 "myparser.tab.c"
    break;

  case 118:
#line 346 "myparser.y"
                                                                                    {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s[%s], *%s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s %s[%s], %s[%s]", (yyvsp[0].str), (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-3].str));
										}}
#line 2418 "myparser.tab.c"
    break;

  case 119:
#line 354 "myparser.y"
                                                                {if(isStr == 1){
									(yyval.str) = template("%s, *%s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}
								else{
									isStr = 0;
									(yyval.str) = template("%s, %s[%s]", (yyvsp[0].str), (yyvsp[-5].str), (yyvsp[-3].str));
								}}
#line 2430 "myparser.tab.c"
    break;

  case 120:
#line 364 "myparser.y"
                                            {if(strcmp((yyvsp[0].str), "char*") == 0){
											isStr = 1;
											(yyval.str) = template("%s %s, *%s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}
										else{
											isStr = 0;
											(yyval.str) = template("%s %s, %s", (yyvsp[0].str), (yyvsp[-4].str), (yyvsp[-2].str));
										}}
#line 2443 "myparser.tab.c"
    break;

  case 121:
#line 372 "myparser.y"
                                        {if(isStr == 1){
									(yyval.str) = template("%s, *%s", (yyvsp[0].str), (yyvsp[-2].str));
								}
								else{
									isStr = 0;
									(yyval.str) = template("%s, %s", (yyvsp[0].str), (yyvsp[-2].str));
								}}
#line 2455 "myparser.tab.c"
    break;

  case 122:
#line 382 "myparser.y"
                   {(yyval.str) = template("int");}
#line 2461 "myparser.tab.c"
    break;

  case 123:
#line 383 "myparser.y"
                    {(yyval.str) = template("double");}
#line 2467 "myparser.tab.c"
    break;

  case 124:
#line 384 "myparser.y"
                 {(yyval.str) = template("char*");}
#line 2473 "myparser.tab.c"
    break;

  case 125:
#line 385 "myparser.y"
                      {(yyval.str) = template("int");}
#line 2479 "myparser.tab.c"
    break;


#line 2483 "myparser.tab.c"

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
#line 395 "myparser.y"

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

int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}


