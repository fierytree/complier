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
#line 1 "src/main.y"

    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern vector<pair<int,int> > br_list2;
    int yylex();
    int yyerror( char const * );
    map<pair<string,int>,TreeNode*> id_list2;

#line 81 "src/main.tab.cpp"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    LOP_ASS = 263,
    ADD_ASS = 264,
    SUB_ASS = 265,
    MUL_ASS = 266,
    DIV_ASS = 267,
    SUR_ASS = 268,
    LS_ASS = 269,
    RS_ASS = 270,
    AND_ASS = 271,
    OR_ASS = 272,
    XOR_ASS = 273,
    LOG_OR = 274,
    LOG_AND = 275,
    BIT_OR = 276,
    BIT_XOR = 277,
    BIT_AND = 278,
    EQ = 279,
    UEQ = 280,
    GT = 281,
    LT = 282,
    GE = 283,
    LE = 284,
    LSHIFT = 285,
    RSHIFT = 286,
    ADD = 287,
    SUB = 288,
    MUL = 289,
    DIV = 290,
    SUR = 291,
    BIT_NOT = 292,
    LOG_NOT = 293,
    INCR = 294,
    DECR = 295,
    LEFTBR = 296,
    RIGHTBR = 297,
    LBRACE = 298,
    RBRACE = 299,
    SEMICOLON = 300,
    COMMA = 301,
    IDENTIFIER = 302,
    INTEGER = 303,
    CHAR = 304,
    BOOL = 305,
    STRING = 306,
    IF = 307,
    WHILE = 308,
    FOR = 309,
    RETURN = 310,
    ADDR = 311,
    UMINUS = 312,
    UADD = 313,
    BACK_INCR = 314,
    BACK_DECR = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */



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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1027

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    62,    63,    64,    65,    69,    82,    97,
     107,   119,   120,   124,   125,   126,   133,   142,   151,   158,
     164,   169,   175,   185,   196,   207,   217,   223,   233,   234,
     238,   254,   257,   260,   263,   284,   304,   311,   318,   325,
     332,   339,   346,   353,   360,   367,   374,   381,   388,   395,
     402,   409,   416,   423,   430,   437,   444,   451,   458,   465,
     472,   479,   486,   493,   500,   507,   513,   519,   525,   531,
     537,   543,   549,   555,   561,   569,   570,   571,   572,   573
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_VOID", "LOP_ASS", "ADD_ASS", "SUB_ASS", "MUL_ASS", "DIV_ASS",
  "SUR_ASS", "LS_ASS", "RS_ASS", "AND_ASS", "OR_ASS", "XOR_ASS", "LOG_OR",
  "LOG_AND", "BIT_OR", "BIT_XOR", "BIT_AND", "EQ", "UEQ", "GT", "LT", "GE",
  "LE", "LSHIFT", "RSHIFT", "ADD", "SUB", "MUL", "DIV", "SUR", "BIT_NOT",
  "LOG_NOT", "INCR", "DECR", "LEFTBR", "RIGHTBR", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING",
  "IF", "WHILE", "FOR", "RETURN", "ADDR", "UMINUS", "UADD", "BACK_INCR",
  "BACK_DECR", "$accept", "program", "units", "function", "PARMS",
  "statements", "statement", "for_decl", "declaration", "IDENTIFIERS",
  "PAS", "expr", "T", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,   -63,   -63,   -63,   -63,   -63,    16,    85,   -63,   -28,
     -22,   -63,   -63,   -19,   -63,    56,    15,   -63,   935,    17,
     -20,   935,   935,   935,   935,   935,   935,   935,   935,    21,
     -63,   -63,   -63,   901,    41,    32,    38,   -63,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   726,   153,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   935,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   935,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   -63,   -63,   439,    50,
      85,   -63,   -63,   -63,    54,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   901,   901,   901,   967,   987,   213,
     265,   318,   368,   368,    36,    36,    36,    36,   -21,   -21,
      47,    47,   -38,   -38,   -38,   -63,    57,    63,    64,   915,
     117,   -63,    61,   536,    52,   439,    60,   -63,   935,   935,
     935,   492,   -63,   574,   -63,   -63,   -63,   -63,   100,   174,
     -63,   901,   761,   796,    70,    72,   612,    62,   -63,   -63,
      82,    83,    85,   935,   935,   119,   439,   439,    81,   650,
     688,   935,   227,   280,   121,   935,   935,   901,   -63,   -63,
     935,   831,   866,   901,    87,    88,   439,   439,   333,   386,
     -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    76,    75,    78,    77,    79,     0,     2,     4,     0,
       0,     1,     6,     0,     3,    26,    25,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,    32,    33,    24,     0,     0,     0,    27,    69,    66,
      65,    68,    67,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,     0,
       0,     9,    74,    35,     0,    28,    54,    55,    56,    57,
      58,    59,    60,    61,    63,    62,    64,    53,    52,    44,
      45,    43,    46,    47,    49,    48,    51,    50,    41,    42,
      36,    37,    38,    39,    40,    13,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    20,     0,     8,    12,    14,    21,    26,     0,
      10,    29,     0,     0,     0,     0,     0,     0,    19,     7,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,    22,    18,    15,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      17,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   125,     2,   -62,   -60,   -63,    73,   -63,
     -63,   -18,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    35,   120,   121,   145,   122,    16,
      84,   123,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    76,    77,    38,    39,    40,    41,    42,    43,    44,
      45,    71,    72,    73,    74,    75,    11,    14,    76,    77,
       1,     2,     3,     4,     5,    15,    17,    37,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    10,    34,
     135,    20,    46,   139,    18,    10,    69,    70,    71,    72,
      73,    74,    75,     9,    79,    76,    77,    36,    80,   135,
      13,    73,    74,    75,    78,    81,    76,    77,     1,     2,
       3,     4,     5,   125,   162,   163,   127,    19,   129,   138,
     128,   133,   135,   135,   130,   131,   136,   140,    18,   155,
     141,   142,   143,   146,   178,   179,   152,   153,   135,   135,
       1,     2,     3,     4,     5,   156,   157,   161,   164,   170,
     176,   177,    12,   144,     0,   159,   160,     0,   126,     0,
      21,     0,     0,   167,     0,     0,     0,   171,   172,    22,
      23,     0,   173,     0,    24,    25,    26,    27,    28,     0,
       0,   134,   115,     0,    29,    30,    31,     0,    32,   116,
     117,   118,   119,     0,     0,     0,    21,     1,     2,     3,
       4,     5,     0,     0,     0,    22,    23,     0,     0,   147,
      24,    25,    26,    27,    28,    83,     0,    21,     0,     0,
      29,    30,    31,     0,    32,     0,    22,    23,     0,     0,
     158,    24,    25,    26,    27,    28,     0,     0,   149,   115,
       0,    29,    30,    31,     0,    32,   116,   117,   118,   119,
       1,     2,     3,     4,     5,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      21,     0,    76,    77,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,    24,    25,    26,    27,    28,     0,
       0,   168,   115,     0,    29,    30,    31,     0,    32,   116,
     117,   118,   119,     1,     2,     3,     4,     5,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,    21,    76,    77,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,    24,    25,    26,
      27,    28,     0,     0,   169,   115,     0,    29,    30,    31,
       0,    32,   116,   117,   118,   119,     1,     2,     3,     4,
       5,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    21,    76,    77,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
      24,    25,    26,    27,    28,     0,     0,   180,   115,     0,
      29,    30,    31,     0,    32,   116,   117,   118,   119,     1,
       2,     3,     4,     5,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,    21,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,    24,    25,    26,    27,    28,     0,     0,
     181,   115,     0,    29,    30,    31,     0,    32,   116,   117,
     118,   119,     1,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,     0,     0,     0,    24,    25,    26,    27,
      28,     0,     0,     0,   115,     0,    29,    30,    31,     0,
      32,   116,   117,   118,   119,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,    29,
      30,    31,     0,    32,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
       0,   137,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,     0,   148,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,     0,   154,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,     0,   165,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,     0,   166,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,    82,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,   150,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,   151,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,   174,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,   175,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    21,     0,
      76,    77,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,    24,    25,    26,    27,    28,     0,    21,     0,
     132,     0,    29,    30,    31,     0,    32,    22,    23,     0,
       0,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,    30,    31,     0,    32,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77
};

static const yytype_int16 yycheck[] =
{
      18,    39,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    32,    33,    34,    35,    36,     0,    45,    39,    40,
       3,     4,     5,     6,     7,    47,    45,    47,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    42,
     120,    46,    41,   125,     8,     7,    30,    31,    32,    33,
      34,    35,    36,     0,    42,    39,    40,    19,    46,   139,
       7,    34,    35,    36,    43,    47,    39,    40,     3,     4,
       5,     6,     7,    43,   156,   157,    42,    41,    41,    47,
      46,   119,   162,   163,    41,    41,    45,    47,     8,    47,
     128,   129,   130,   131,   176,   177,    46,    45,   178,   179,
       3,     4,     5,     6,     7,    43,    43,     8,    47,     8,
      43,    43,     7,   131,    -1,   153,   154,    -1,    80,    -1,
      23,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,    32,
      33,    -1,   170,    -1,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    23,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    32,    33,    -1,    -1,   131,
      37,    38,    39,    40,    41,    42,    -1,    23,    -1,    -1,
      47,    48,    49,    -1,    51,    -1,    32,    33,    -1,    -1,
     152,    37,    38,    39,    40,    41,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      23,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,     3,     4,     5,     6,     7,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    23,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,     3,     4,     5,     6,
       7,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    23,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    -1,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    51,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,    45,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    45,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    45,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    45,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    42,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    -1,    42,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    42,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    -1,    42,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    42,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    23,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    23,    -1,
      45,    -1,    47,    48,    49,    -1,    51,    32,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    51,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    62,    63,    64,    69,
      73,     0,    64,    69,    45,    47,    70,    45,     8,    41,
      46,    23,    32,    33,    37,    38,    39,    40,    41,    47,
      48,    49,    51,    72,    42,    65,    73,    47,    72,    72,
      72,    72,    72,    72,    72,    72,    41,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    39,    40,    43,    42,
      46,    47,    42,    42,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    45,    52,    53,    54,    55,
      66,    67,    69,    72,    73,    43,    73,    42,    46,    41,
      41,    41,    45,    72,    44,    67,    45,    45,    47,    66,
      47,    72,    72,    72,    65,    68,    72,    73,    45,    44,
      42,    42,    46,    45,    45,    47,    43,    43,    73,    72,
      72,     8,    66,    66,    47,    45,    45,    72,    44,    44,
       8,    72,    72,    72,    42,    42,    43,    43,    66,    66,
      44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     8,     7,     2,
       4,     1,     2,     1,     2,     7,    11,    11,     7,     3,
       2,     2,     4,     6,     4,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     1
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
#line 58 "src/main.y"
        {root = new TreeNode(0, NODE_PROG); root->addChild(yyvsp[0]);}
#line 1653 "src/main.tab.cpp"
    break;

  case 3:
#line 62 "src/main.y"
                       {yyval=yyvsp[-1];}
#line 1659 "src/main.tab.cpp"
    break;

  case 4:
#line 63 "src/main.y"
           {yyval=yyvsp[0];}
#line 1665 "src/main.tab.cpp"
    break;

  case 5:
#line 64 "src/main.y"
                             {yyval=yyvsp[-2];yyval->addSibling(yyvsp[-1]);}
#line 1671 "src/main.tab.cpp"
    break;

  case 6:
#line 65 "src/main.y"
                 {yyval=yyvsp[-1];yyval->addSibling(yyvsp[0]);}
#line 1677 "src/main.tab.cpp"
    break;

  case 7:
#line 69 "src/main.y"
                                                            {
    TreeNode* node = new TreeNode(yyvsp[-7]->lineno, NODE_FUNC);
    auto x=make_pair(yyvsp[-6]->var_name,yyvsp[-6]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[-6];
    else cout<<"Variable "<<yyvsp[-6]->var_name<<" repeated definition"<<endl;
    node->var_name=yyvsp[-6]->var_name;
    node->type=yyvsp[-7]->type;
    node->addChild(yyvsp[-7]);
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1695 "src/main.tab.cpp"
    break;

  case 8:
#line 82 "src/main.y"
                                                      {
    TreeNode* node = new TreeNode(yyvsp[-6]->lineno, NODE_FUNC);
    auto x=make_pair(yyvsp[-5]->var_name,yyvsp[-5]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[-5];
    else cout<<"Variable "<<yyvsp[-5]->var_name<<" repeated definition"<<endl;
    node->var_name=yyvsp[-5]->var_name;
    node->type=yyvsp[-6]->type;
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-5]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1712 "src/main.tab.cpp"
    break;

  case 9:
#line 97 "src/main.y"
              {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_PARA);
    yyvsp[0]->scope.first=br_list2.size()+1;yyvsp[0]->scope.second=yyvsp[-1]->lineno;
    auto x=make_pair(yyvsp[0]->var_name,yyvsp[0]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[0];
    else cout<<"Variable "<<yyvsp[0]->var_name<<" repeated definition"<<endl;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 1727 "src/main.tab.cpp"
    break;

  case 10:
#line 107 "src/main.y"
                          {
    yyval=yyvsp[-3];
    yyvsp[0]->scope.first=br_list2.size()+1;yyvsp[0]->scope.second=yyvsp[-1]->lineno;
    auto x=make_pair(yyvsp[0]->var_name,yyvsp[0]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[0];
    else cout<<"Variable "<<yyvsp[0]->var_name<<" repeated definition"<<endl;
    yyvsp[-3]->addChild(yyvsp[-1]);
    yyvsp[-3]->addChild(yyvsp[0]);
}
#line 1741 "src/main.tab.cpp"
    break;

  case 11:
#line 119 "src/main.y"
             {yyval=yyvsp[0];}
#line 1747 "src/main.tab.cpp"
    break;

  case 12:
#line 120 "src/main.y"
                        {yyval=yyvsp[-1]; yyval->addSibling(yyvsp[0]);}
#line 1753 "src/main.tab.cpp"
    break;

  case 13:
#line 124 "src/main.y"
             {yyval = new TreeNode(lineno, NODE_STMT); yyval->stype = STMT_SKIP;}
#line 1759 "src/main.tab.cpp"
    break;

  case 14:
#line 125 "src/main.y"
                        {yyval = yyvsp[-1];}
#line 1765 "src/main.tab.cpp"
    break;

  case 15:
#line 126 "src/main.y"
                                                    {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno, NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1777 "src/main.tab.cpp"
    break;

  case 16:
#line 133 "src/main.y"
                                                                                {
    TreeNode* node = new TreeNode(yyvsp[-8]->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild(yyvsp[-8]);
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1791 "src/main.tab.cpp"
    break;

  case 17:
#line 142 "src/main.y"
                                                                                    {
    TreeNode* node = new TreeNode(yyvsp[-8]->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild(yyvsp[-8]);
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1805 "src/main.tab.cpp"
    break;

  case 18:
#line 151 "src/main.y"
                                                 {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1817 "src/main.tab.cpp"
    break;

  case 19:
#line 158 "src/main.y"
                       {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1828 "src/main.tab.cpp"
    break;

  case 20:
#line 164 "src/main.y"
                  {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    yyval=node;
}
#line 1838 "src/main.tab.cpp"
    break;

  case 21:
#line 169 "src/main.y"
                {
    yyval=yyvsp[-1];
}
#line 1846 "src/main.tab.cpp"
    break;

  case 22:
#line 175 "src/main.y"
                           {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    yyvsp[-2]->scope.first=br_list2.size()+1;yyvsp[-2]->scope.second=yyvsp[-3]->lineno;
    auto x=make_pair(yyvsp[-2]->var_name,yyvsp[-2]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[-2];
    else cout<<"Variable "<<yyvsp[-2]->var_name<<" repeated definition"<<endl;
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-2]);
    yyval=node;
}
#line 1861 "src/main.tab.cpp"
    break;

  case 23:
#line 185 "src/main.y"
                                       {
    yyval=yyvsp[-5];
    yyvsp[-2]->scope.first=br_list2.size()+1;yyvsp[-2]->scope.second=yyvsp[-3]->lineno;
    auto x=make_pair(yyvsp[-2]->var_name,yyvsp[-2]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[-2];
    else cout<<"Variable "<<yyvsp[-2]->var_name<<" repeated definition"<<endl;
    yyvsp[-5]->addChild(yyvsp[-3]);
    yyvsp[-5]->addChild(yyvsp[-2]);
}
#line 1875 "src/main.tab.cpp"
    break;

  case 24:
#line 196 "src/main.y"
                           { 
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    auto x=make_pair(yyvsp[-2]->var_name,yyvsp[-2]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[-2];
    else cout<<"Variable "<<yyvsp[-2]->var_name<<" repeated definition"<<endl;
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;   
}
#line 1891 "src/main.tab.cpp"
    break;

  case 25:
#line 207 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    yyval = node;   
}
#line 1903 "src/main.tab.cpp"
    break;

  case 26:
#line 217 "src/main.y"
            {
    yyval=yyvsp[0];
    auto x=make_pair(yyvsp[0]->var_name,yyvsp[0]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[0];
    else cout<<"Variable "<<yyvsp[0]->var_name<<" repeated definition"<<endl;
}
#line 1914 "src/main.tab.cpp"
    break;

  case 27:
#line 223 "src/main.y"
                              {
    yyval=yyvsp[-2];
    yyval->addSibling(yyvsp[0]);
    auto x=make_pair(yyvsp[0]->var_name,yyvsp[0]->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=yyvsp[0];
    else cout<<"Variable "<<yyvsp[0]->var_name<<" repeated definition"<<endl;
}
#line 1926 "src/main.tab.cpp"
    break;

  case 28:
#line 233 "src/main.y"
       {yyval=yyvsp[0];}
#line 1932 "src/main.tab.cpp"
    break;

  case 29:
#line 234 "src/main.y"
                 {yyval=yyvsp[-2];yyvsp[-2]->addSibling(yyvsp[0]);}
#line 1938 "src/main.tab.cpp"
    break;

  case 30:
#line 238 "src/main.y"
             {
    int s=-1;
    TreeNode* v=nullptr;
    for(auto x:id_list2){
        if(x.first.first==yyvsp[0]->var_name){
            if(x.first.second>s){
                s=x.first.second;
                v=new TreeNode(yyvsp[0]->lineno, NODE_VAR);
                v->var_name=x.second->var_name;
                v->scope=x.second->scope;
            }
        }
    }
    if(s==-1||v==nullptr)cout<<"Variable "<<yyvsp[0]->var_name<<" undefinied"<<endl;
    else yyval=v;
}
#line 1959 "src/main.tab.cpp"
    break;

  case 31:
#line 254 "src/main.y"
          {
    yyval = yyvsp[0];
}
#line 1967 "src/main.tab.cpp"
    break;

  case 32:
#line 257 "src/main.y"
       {
    yyval = yyvsp[0];
}
#line 1975 "src/main.tab.cpp"
    break;

  case 33:
#line 260 "src/main.y"
         {
    yyval = yyvsp[0];
}
#line 1983 "src/main.tab.cpp"
    break;

  case 34:
#line 263 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    int s=-1;
    TreeNode*v=nullptr;
    for(auto x:id_list2){
        if(x.first.first==yyvsp[-3]->var_name){
            if(x.first.second>s){
                s=x.first.second;
                v=new TreeNode(yyvsp[-3]->lineno, NODE_VAR);
                v->var_name=x.second->var_name;
                v->scope=x.second->scope;
            }
        }
    }
    if(s==-1||v==nullptr)cout<<"func name "<<yyvsp[-3]->var_name<<" undefinied"<<endl;
    node->stype=STMT_FUNC_USE;
    node->var_name=yyvsp[-3]->var_name;
    node->addChild(v);
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 2009 "src/main.tab.cpp"
    break;

  case 35:
#line 284 "src/main.y"
                           {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    int s=-1;
    TreeNode*v=nullptr;
    for(auto x:id_list2){
        if(x.first.first==yyvsp[-2]->var_name){
            if(x.first.second>s){
                s=x.first.second;
                v=new TreeNode(yyvsp[-2]->lineno, NODE_VAR);
                v->var_name=x.second->var_name;
                v->scope=x.second->scope;
            }
        }
    }
    if(s==-1||v==nullptr)cout<<"func name "<<yyvsp[-2]->var_name<<" undefinied"<<endl;
    node->stype=STMT_FUNC_USE;
    node->var_name=yyvsp[-2]->var_name;
    node->addChild(v);
    yyval=node;
}
#line 2034 "src/main.tab.cpp"
    break;

  case 36:
#line 304 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2046 "src/main.tab.cpp"
    break;

  case 37:
#line 311 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2058 "src/main.tab.cpp"
    break;

  case 38:
#line 318 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2070 "src/main.tab.cpp"
    break;

  case 39:
#line 325 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2082 "src/main.tab.cpp"
    break;

  case 40:
#line 332 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2094 "src/main.tab.cpp"
    break;

  case 41:
#line 339 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2106 "src/main.tab.cpp"
    break;

  case 42:
#line 346 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_RSHIFT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2118 "src/main.tab.cpp"
    break;

  case 43:
#line 353 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_AND;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2130 "src/main.tab.cpp"
    break;

  case 44:
#line 360 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_OR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2142 "src/main.tab.cpp"
    break;

  case 45:
#line 367 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_XOR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2154 "src/main.tab.cpp"
    break;

  case 46:
#line 374 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_EQ;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2166 "src/main.tab.cpp"
    break;

  case 47:
#line 381 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_UEQ;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2178 "src/main.tab.cpp"
    break;

  case 48:
#line 388 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2190 "src/main.tab.cpp"
    break;

  case 49:
#line 395 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_GT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2202 "src/main.tab.cpp"
    break;

  case 50:
#line 402 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2214 "src/main.tab.cpp"
    break;

  case 51:
#line 409 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_GE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2226 "src/main.tab.cpp"
    break;

  case 52:
#line 416 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LOG_AND;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2238 "src/main.tab.cpp"
    break;

  case 53:
#line 423 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LOG_OR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2250 "src/main.tab.cpp"
    break;

  case 54:
#line 430 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LOP_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2262 "src/main.tab.cpp"
    break;

  case 55:
#line 437 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_ADD_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2274 "src/main.tab.cpp"
    break;

  case 56:
#line 444 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUB_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2286 "src/main.tab.cpp"
    break;

  case 57:
#line 451 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_MUL_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2298 "src/main.tab.cpp"
    break;

  case 58:
#line 458 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_DIV_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2310 "src/main.tab.cpp"
    break;

  case 59:
#line 465 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2322 "src/main.tab.cpp"
    break;

  case 60:
#line 472 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LS_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2334 "src/main.tab.cpp"
    break;

  case 61:
#line 479 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_RS_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2346 "src/main.tab.cpp"
    break;

  case 62:
#line 486 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_OR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2358 "src/main.tab.cpp"
    break;

  case 63:
#line 493 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_AND_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2370 "src/main.tab.cpp"
    break;

  case 64:
#line 500 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_XOR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2382 "src/main.tab.cpp"
    break;

  case 65:
#line 507 "src/main.y"
                        {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2393 "src/main.tab.cpp"
    break;

  case 66:
#line 513 "src/main.y"
                      {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_UADD;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2404 "src/main.tab.cpp"
    break;

  case 67:
#line 519 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_LOG_NOT;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2415 "src/main.tab.cpp"
    break;

  case 68:
#line 525 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BIT_NOT;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2426 "src/main.tab.cpp"
    break;

  case 69:
#line 531 "src/main.y"
                          {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_ADDR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2437 "src/main.tab.cpp"
    break;

  case 70:
#line 537 "src/main.y"
            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_INCR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2448 "src/main.tab.cpp"
    break;

  case 71:
#line 543 "src/main.y"
            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_DECR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2459 "src/main.tab.cpp"
    break;

  case 72:
#line 549 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BACK_INCR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2470 "src/main.tab.cpp"
    break;

  case 73:
#line 555 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BACK_DECR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2481 "src/main.tab.cpp"
    break;

  case 74:
#line 561 "src/main.y"
                      {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild(yyvsp[-1]);
    yyval = node;
}
#line 2492 "src/main.tab.cpp"
    break;

  case 75:
#line 569 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_INT;}
#line 2498 "src/main.tab.cpp"
    break;

  case 76:
#line 570 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_CHAR;}
#line 2504 "src/main.tab.cpp"
    break;

  case 77:
#line 571 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_BOOL;}
#line 2510 "src/main.tab.cpp"
    break;

  case 78:
#line 572 "src/main.y"
           {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_STRING;}
#line 2516 "src/main.tab.cpp"
    break;

  case 79:
#line 573 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_VOID;}
#line 2522 "src/main.tab.cpp"
    break;


#line 2526 "src/main.tab.cpp"

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
#line 576 "src/main.y"


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
