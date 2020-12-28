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
    extern int br_count;
    extern ofstream fout;
    extern vector<pair<int,int> > br_list;
    int yylex();
    int yyerror( char const * );
    map<pair<string,int>,TreeNode*> id_list;
    void add_id(TreeNode* t){
        auto x=make_pair(t->var_name,t->scope.first);
        if(id_list.find(x)==id_list.end())id_list[x]=t;
        else cerr<<"in line"<<lineno<<", Variable "<<t->var_name<<" repeated definition"<<endl,exit(0);
    }
    TreeNode* find_id(TreeNode* t){
        auto s=make_pair(-1,-1);
        Type* tp=nullptr;
        auto y=make_pair(t->var_name,0);
        //for(auto x:id_list)fout<<x.first.first<<" "<<x.first.second<<endl;
        if(id_list.find(y)!=id_list.end())s=make_pair(0,0),tp=id_list[y]->type;
        for(auto x:br_list){
            auto y=make_pair(t->var_name,x.first);
            if(id_list.find(y)!=id_list.end())s=x,tp=id_list[y]->type;
        }
        if(s.first==-1&&t->type!=nullptr&&t->type->type==COMPOSE_FUNCTION)return t;
        if(s.first==-1){
            auto y=make_pair(t->var_name,br_count+1);
            if(id_list.find(y)!=id_list.end()){
                t->scope=id_list[y]->scope;
                t->type=id_list[y]->type;
                cerr<<"in line"<<id_list[y]->lineno;
                cerr<<", warning，use bracket when write a statement."<<endl;
                return t;
            }
            else cerr<<"in line"<<lineno<<", Variable "<<t->var_name<<" undefinied"<<endl,exit(0);
        }
        t->scope=s;t->type=tp;
        return t;
    }
    inline bool rd(TreeNode* t1,TreeNode* t2){
        return t1->nodeType==NODE_CONST&&t2->nodeType==NODE_CONST;
    }
    inline bool rd(TreeNode* t){
        return t->nodeType==NODE_CONST;
    }

#line 119 "src/main.tab.cpp"

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
    ADDR = 292,
    STAR = 293,
    LEFTBR = 294,
    RIGHTBR = 295,
    LOG_NOT = 296,
    BIT_NOT = 297,
    UMINUS = 298,
    UADD = 299,
    INCR = 300,
    DECR = 301,
    LBRACE = 302,
    RBRACE = 303,
    M_LBR = 304,
    M_RBR = 305,
    BACK_INCR = 306,
    BACK_DECR = 307,
    SEMICOLON = 308,
    COMMA = 309,
    IDENTIFIER = 310,
    INTEGER = 311,
    CHAR = 312,
    BOOL = 313,
    STRING = 314,
    HEX_INTEGER = 315,
    IF = 316,
    WHILE = 317,
    FOR = 318,
    RETURN = 319,
    CONST = 320,
    ELSE = 321,
    BREAK = 322,
    CONTINUE = 323
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   762

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

#define YYUNDEFTOK  2
#define YYMAXUTOK   323


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   106,   107,   108,   109,   113,   136,   147,
     155,   159,   160,   164,   165,   174,   182,   183,   184,   192,
     208,   215,   223,   229,   234,   239,   244,   250,   251,   252,
     255,   256,   259,   272,   280,   295,   310,   327,   328,   336,
     344,   352,   360,   368,   375,   385,   399,   410,   417,   423,
     424,   428,   429,   439,   440,   447,   448,   449,   458,   461,
     464,   467,   470,   473,   476,   485,   493,   501,   509,   517,
     525,   533,   541,   549,   557,   565,   573,   581,   589,   597,
     605,   613,   621,   629,   637,   644,   651,   658,   665,   672,
     679,   686,   693,   700,   707,   714,   721,   728,   735,   741,
     747,   753,   759,   765,   771,   780,   781,   789,   790,   791,
     792,   793
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
  "LE", "LSHIFT", "RSHIFT", "ADD", "SUB", "MUL", "DIV", "SUR", "ADDR",
  "STAR", "LEFTBR", "RIGHTBR", "LOG_NOT", "BIT_NOT", "UMINUS", "UADD",
  "INCR", "DECR", "LBRACE", "RBRACE", "M_LBR", "M_RBR", "BACK_INCR",
  "BACK_DECR", "SEMICOLON", "COMMA", "IDENTIFIER", "INTEGER", "CHAR",
  "BOOL", "STRING", "HEX_INTEGER", "IF", "WHILE", "FOR", "RETURN", "CONST",
  "ELSE", "BREAK", "CONTINUE", "$accept", "program", "units", "function",
  "PARMS", "block_item", "block_items", "block", "statement", "for_expr",
  "for_LEFTBR", "for_RIGHTBR", "declaration", "CONST_EXP", "ARRAY",
  "ARRAY2", "LVAL", "decl_item", "IDENTIFIERS", "PAS", "expr", "T", "T1", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,  -203,  -203,  -203,  -203,  -203,   103,    22,    28,  -203,
     -23,   -18,    51,    31,    50,    61,  -203,  -203,    68,  -203,
      -3,    84,  -203,    75,  -203,   126,   128,   129,  -203,   292,
    -203,   -14,   226,   -14,    88,    82,   -14,    90,   292,   292,
     292,   292,   292,   292,   292,   292,   292,    86,  -203,  -203,
    -203,  -203,   264,   744,   552,   -14,   -14,  -203,   121,   -34,
      92,   140,   144,  -203,  -203,   152,  -203,    -5,    -5,    -5,
      -5,   468,    -5,    -5,    -5,    -5,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,  -203,  -203,
    -203,    80,   -14,   -14,   -14,   -14,   -14,  -203,  -203,   226,
     101,  -203,  -203,  -203,   -33,   552,   404,   436,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   579,
     605,   630,   654,   677,   698,   698,   705,   705,   705,   705,
     253,   253,    -7,    -7,    -5,    -5,    -5,  -203,   145,    10,
      10,  -203,  -203,   102,  -203,  -203,  -203,   292,  -203,  -203,
    -203,   160,   552,  -203,  -203,   122,   123,   130,   261,   115,
     135,  -203,  -203,  -203,   138,   334,   141,   292,   292,    85,
    -203,   369,  -203,  -203,  -203,  -203,    -6,   496,   524,   142,
    -203,   552,  -203,   203,   203,    85,   131,  -203,   147,   203,
      85,  -203,   163,   203,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   108,   107,   110,   109,   111,     0,     0,     2,     4,
       0,     0,   105,     0,     0,     0,     1,     6,     0,     3,
      51,    33,    53,    32,   106,     0,     0,     0,     5,     0,
      30,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    61,
      62,    60,    63,     0,    52,     0,     0,    37,     0,     0,
       0,     0,    51,    54,    35,    34,    36,    98,    95,    94,
      99,     0,    96,    97,   100,   101,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
      43,     0,     0,     0,     0,     0,     0,    45,    31,     0,
       0,     8,    46,   104,     0,    57,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    92,    91,    93,    82,
      81,    73,    74,    72,    75,    76,    78,    77,    80,    79,
      70,    71,    65,    66,    67,    68,    69,    44,    42,    38,
      39,    40,    41,     0,    13,     7,    64,     0,    47,    48,
       9,     0,    56,    15,    16,     0,     0,     0,     0,     0,
       0,    14,    17,    11,     0,     0,     0,     0,     0,    29,
      23,     0,    24,    25,    12,    26,    51,     0,     0,     0,
      27,    28,    22,     0,     0,    29,    20,    18,     0,     0,
      29,    21,     0,     0,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,   196,  -203,  -203,  -203,    89,   -81,  -202,
      33,    -1,    18,   -32,  -203,  -203,  -203,   178,  -203,  -203,
     -29,    79,  -203
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    59,   181,   171,   182,   183,   199,
      32,   120,   200,    58,    21,    52,    53,    22,    23,   124,
     185,   186,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    61,    29,   208,    65,    29,   118,   166,   212,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    10,    55,
     119,   167,    16,   110,   111,    56,    18,   105,   106,   107,
      19,     1,     2,     3,     4,     5,    30,    20,   108,   109,
     108,   109,    57,    31,   115,   116,    31,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    11,
     158,   159,   160,   161,   162,    24,    25,    11,     1,     2,
       3,     4,     5,     6,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    26,    13,    14,    38,    15,
     112,    60,   113,   114,   115,   116,    27,    39,    40,    41,
     157,    28,   206,   207,    42,    76,    43,    44,   211,    34,
      45,    46,   214,    33,    35,    77,    36,    37,   172,    64,
      47,    48,    49,    62,    50,    51,    66,   121,   164,   191,
       6,   112,    29,   113,   114,   115,   116,   170,   197,   198,
     201,   187,   188,     1,     2,     3,     4,     5,   192,    30,
     112,   117,   113,   114,   115,   116,   201,   113,   114,   115,
     116,   201,   112,    38,   113,   114,   115,   116,   193,   184,
     122,   194,    39,    40,    41,   205,   196,   209,   163,    42,
     210,    43,    44,   118,    17,    45,    46,   164,   173,   165,
     189,   213,    63,   174,     0,    47,    48,    49,     0,    50,
      51,   175,   176,   177,   178,     6,    38,   179,   180,     1,
       2,     3,     4,     5,     0,    39,    40,    41,     0,     0,
       0,     0,    42,     0,    43,    44,     0,     0,    45,    46,
     164,     0,     0,     0,     0,     0,   174,     0,    47,    48,
      49,     0,    50,    51,   175,   176,   177,   178,     0,     0,
     179,   180,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,     0,    38,   103,   104,   105,   106,   107,
       0,     0,     0,    39,    40,    41,     0,     0,   108,   109,
      42,     0,    43,    44,     0,     0,    45,    46,     0,     0,
       0,     0,     0,    78,   190,    38,    47,    48,    49,     0,
      50,    51,     0,     0,    39,    40,    41,     0,     0,     0,
       0,    42,     0,    43,    44,     0,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,    49,
       0,    50,    51,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,     0,     0,     0,     0,     0,     0,   195,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,     0,     0,     0,     0,
       0,     0,   202,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,     0,     0,     0,   168,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,     0,     0,     0,   169,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,   123,     0,
       0,     0,     0,   108,   109,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,   203,     0,     0,     0,
       0,   108,   109,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,   204,     0,     0,     0,     0,   108,
     109,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   109,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,     0,     0,
     108,   109,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      29,    33,     8,   205,    36,     8,    40,    40,   210,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    33,
      54,    54,     0,    55,    56,    39,     8,    34,    35,    36,
      53,     3,     4,     5,     6,     7,    39,    55,    45,    46,
      45,    46,    56,    49,    34,    35,    49,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     112,   113,   114,   115,   116,    34,    55,     8,     3,     4,
       5,     6,     7,    65,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    55,     3,     4,    23,     6,
      30,    32,    32,    33,    34,    35,    55,    32,    33,    34,
      40,    53,   203,   204,    39,    39,    41,    42,   209,    54,
      45,    46,   213,    49,     8,    49,     8,     8,   167,    57,
      55,    56,    57,    55,    59,    60,    56,    55,    47,   178,
      65,    30,     8,    32,    33,    34,    35,    55,   187,   188,
     189,    39,    39,     3,     4,     5,     6,     7,    53,    39,
      30,    50,    32,    33,    34,    35,   205,    32,    33,    34,
      35,   210,    30,    23,    32,    33,    34,    35,    53,   171,
      50,    53,    32,    33,    34,    53,    55,    66,   119,    39,
      53,    41,    42,    40,     8,    45,    46,    47,    48,   120,
     177,   212,    34,    53,    -1,    55,    56,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    23,    67,    68,     3,
       4,     5,     6,     7,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    -1,    41,    42,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      57,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    23,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    32,    33,    34,    -1,    -1,    45,    46,
      39,    -1,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    49,    53,    23,    55,    56,    57,    -1,
      59,    60,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    45,    46,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    45,    46,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    45,
      46,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    30,    31,    32,    33,    34,
      35,    36,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      45,    46,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    65,    70,    71,    72,
      81,    90,    91,     3,     4,     6,     0,    72,    81,    53,
      55,    83,    86,    87,    34,    55,    55,    55,    53,     8,
      39,    49,    79,    49,    54,     8,     8,     8,    23,    32,
      33,    34,    39,    41,    42,    45,    46,    55,    56,    57,
      59,    60,    84,    85,    89,    33,    39,    56,    82,    73,
      90,    82,    55,    86,    57,    82,    56,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    39,    49,    49,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    45,    46,
      82,    82,    30,    32,    33,    34,    35,    50,    40,    54,
      80,    55,    50,    40,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    40,    82,    82,
      82,    82,    82,    90,    47,    76,    40,    54,    50,    50,
      55,    75,    89,    48,    53,    61,    62,    63,    64,    67,
      68,    74,    76,    77,    81,    89,    90,    39,    39,    79,
      53,    89,    53,    53,    53,    53,    55,    89,    89,    78,
      81,    89,    53,    40,    40,    53,    77,    77,    78,    66,
      53,    77,    78,    80,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    72,    73,    73,
      73,    74,    74,    75,    75,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    80,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     6,     2,     4,
       0,     1,     2,     0,     2,     3,     1,     1,     5,     9,
       5,     7,     3,     2,     2,     2,     2,     1,     1,     0,
       1,     1,     2,     2,     5,     5,     5,     1,     3,     3,
       3,     3,     3,     2,     3,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     1
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
#line 102 "src/main.y"
        {root = new TreeNode(0, NODE_PROG); root->addChild(yyvsp[0]);root->type=TYPE_VOID;}
#line 1673 "src/main.tab.cpp"
    break;

  case 3:
#line 106 "src/main.y"
                       {yyval=yyvsp[-1];}
#line 1679 "src/main.tab.cpp"
    break;

  case 4:
#line 107 "src/main.y"
           {yyval=yyvsp[0];}
#line 1685 "src/main.tab.cpp"
    break;

  case 5:
#line 108 "src/main.y"
                             {yyval=yyvsp[-2];yyval->addSibling(yyvsp[-1]);}
#line 1691 "src/main.tab.cpp"
    break;

  case 6:
#line 109 "src/main.y"
                 {yyval=yyvsp[-1];yyval->addSibling(yyvsp[0]);}
#line 1697 "src/main.tab.cpp"
    break;

  case 7:
#line 113 "src/main.y"
                                                 {
    TreeNode* node = new TreeNode(yyvsp[-5]->lineno, NODE_FUNC);
    
    yyvsp[-4]->type=new Type(COMPOSE_FUNCTION);
    yyvsp[-4]->type->retType=yyvsp[-5]->type;
    yyvsp[-4]->type->paramType=yyvsp[-2]->type;
    add_id(yyvsp[-4]);

    yyvsp[0]->pa_func=node;
    yyvsp[-4]->pa_func=node;
    node->stack_size=0;
    node->reg_count=0;
    node->var_name=yyvsp[-4]->var_name;
    node->type=yyvsp[-4]->type->retType;
    node->addChild(yyvsp[-5]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 1722 "src/main.tab.cpp"
    break;

  case 8:
#line 136 "src/main.y"
              {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_PARA);

    node->type=new Type(COMPOSE_UNION);
    node->type->addChild(yyvsp[-1]->type);
    yyvsp[0]->type=yyvsp[-1]->type;
    add_id(yyvsp[0]);
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 1738 "src/main.tab.cpp"
    break;

  case 9:
#line 147 "src/main.y"
                          {
    yyval=yyvsp[-3];
    add_id(yyvsp[0]);
    yyvsp[0]->type=yyvsp[-1]->type;
    yyvsp[-3]->addChild(yyvsp[-1]);
    yyvsp[-3]->addChild(yyvsp[0]);
    yyvsp[-3]->type->addChild(yyvsp[-1]->type);
}
#line 1751 "src/main.tab.cpp"
    break;

  case 10:
#line 155 "src/main.y"
  {yyval = new TreeNode(lineno, NODE_PARA);yyval->type=new Type(COMPOSE_UNION);}
#line 1757 "src/main.tab.cpp"
    break;

  case 11:
#line 159 "src/main.y"
            {yyval=yyvsp[0];}
#line 1763 "src/main.tab.cpp"
    break;

  case 12:
#line 160 "src/main.y"
                        {yyval = yyvsp[-1];}
#line 1769 "src/main.tab.cpp"
    break;

  case 13:
#line 164 "src/main.y"
  {yyval = new TreeNode(lineno, NODE_STMT); yyval->stype = STMT_SKIP;}
#line 1775 "src/main.tab.cpp"
    break;

  case 14:
#line 165 "src/main.y"
                         {
    if(yyvsp[-1]->nodeType==NODE_STMT&&yyvsp[-1]->stype == STMT_SKIP)yyval=yyvsp[0];
    else{
        yyval=yyvsp[-1]; yyval->addSibling(yyvsp[0]);
    }   
}
#line 1786 "src/main.tab.cpp"
    break;

  case 15:
#line 174 "src/main.y"
                          {
    TreeNode* node = new TreeNode(lineno, NODE_STMT); 
    node->stype = STMT_BLOCK;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1797 "src/main.tab.cpp"
    break;

  case 16:
#line 182 "src/main.y"
             {yyval = new TreeNode(lineno, NODE_STMT); yyval->stype = STMT_SKIP;}
#line 1803 "src/main.tab.cpp"
    break;

  case 17:
#line 183 "src/main.y"
        {yyval=yyvsp[0];}
#line 1809 "src/main.tab.cpp"
    break;

  case 18:
#line 184 "src/main.y"
                                     {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyvsp[0]->pa_loop=node;
    yyval=node;
}
#line 1822 "src/main.tab.cpp"
    break;

  case 19:
#line 192 "src/main.y"
                                                                                     {
    TreeNode* node = new TreeNode(yyvsp[-6]->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild(yyvsp[-6]);
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyvsp[0]->pa_loop=node;
    yyval=node;
    for(auto x:id_list){
        if(x.first.second==br_count+1){
            ++br_count;
            fout<<"omit bracket"<<endl;break;
        }
    }
}
#line 1843 "src/main.tab.cpp"
    break;

  case 20:
#line 208 "src/main.y"
                                  {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 1855 "src/main.tab.cpp"
    break;

  case 21:
#line 215 "src/main.y"
                                                 {
    TreeNode* node = new TreeNode(yyvsp[-4]->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild(yyvsp[-4]);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 1868 "src/main.tab.cpp"
    break;

  case 22:
#line 223 "src/main.y"
                       {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 1879 "src/main.tab.cpp"
    break;

  case 23:
#line 229 "src/main.y"
                  {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    yyval=node;
}
#line 1889 "src/main.tab.cpp"
    break;

  case 24:
#line 234 "src/main.y"
                 {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_BREAK;
    yyval=node;
}
#line 1899 "src/main.tab.cpp"
    break;

  case 25:
#line 239 "src/main.y"
                    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_CONTINUE;
    yyval=node;
}
#line 1909 "src/main.tab.cpp"
    break;

  case 26:
#line 244 "src/main.y"
                {
    yyval=yyvsp[-1];
}
#line 1917 "src/main.tab.cpp"
    break;

  case 29:
#line 252 "src/main.y"
  {yyval = new TreeNode(lineno, NODE_STMT); yyval->stype = STMT_SKIP;yyval->place="$1";}
#line 1923 "src/main.tab.cpp"
    break;

  case 30:
#line 255 "src/main.y"
                 {yyval=yyvsp[0];br_list.push_back(make_pair(br_count+1,lineno));}
#line 1929 "src/main.tab.cpp"
    break;

  case 31:
#line 256 "src/main.y"
                   {yyval=yyvsp[0];br_list.pop_back();}
#line 1935 "src/main.tab.cpp"
    break;

  case 32:
#line 259 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    TreeNode* tmp=yyvsp[0];
    while(tmp!=nullptr){
        tmp->type=yyvsp[-1]->type;
        if(tmp->child!=nullptr)tmp->child->type=yyvsp[-1]->type;
        tmp=tmp->siblings;
    }
    yyval = node;   
}
#line 1953 "src/main.tab.cpp"
    break;

  case 33:
#line 272 "src/main.y"
          {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild(yyvsp[-1]);
    node->addChild(yyvsp[0]);
    yyvsp[0]->type->addret(yyvsp[-1]->type);
    yyval = node;
}
#line 1966 "src/main.tab.cpp"
    break;

  case 34:
#line 280 "src/main.y"
                                          {
    TreeNode* node1 = new TreeNode(yyvsp[-2]->lineno, NODE_TYPE);node1->type=TYPE_INT;    
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    yyvsp[-2]->is_const=1;
    yyvsp[-2]->type=TYPE_INT;
    add_id(yyvsp[-2]);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild(yyvsp[-2]);
    node2->addChild(yyvsp[0]);
    yyval = node;
}
#line 1986 "src/main.tab.cpp"
    break;

  case 35:
#line 295 "src/main.y"
                                      {
    TreeNode* node1 = new TreeNode(yyvsp[-2]->lineno, NODE_TYPE);node1->type=TYPE_CHAR;    
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    yyvsp[-2]->is_const=1;
    yyvsp[-2]->type=TYPE_CHAR;
    add_id(yyvsp[-2]);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild(yyvsp[-2]);
    node2->addChild(yyvsp[0]);
    yyval = node;
}
#line 2006 "src/main.tab.cpp"
    break;

  case 36:
#line 310 "src/main.y"
                                         {
    TreeNode* node1 = new TreeNode(yyvsp[-2]->lineno, NODE_TYPE);node1->type=TYPE_BOOL;    
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    yyvsp[-2]->is_const=1;
    yyvsp[-2]->type=TYPE_BOOL;
    add_id(yyvsp[-2]);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild(yyvsp[-2]);
    node2->addChild(yyvsp[0]);
    yyval = node;
}
#line 2026 "src/main.tab.cpp"
    break;

  case 37:
#line 327 "src/main.y"
          {yyval=yyvsp[0];}
#line 2032 "src/main.tab.cpp"
    break;

  case 38:
#line 328 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->int_val=yyvsp[-2]->int_val+yyvsp[0]->int_val;
    yyval = node;
}
#line 2045 "src/main.tab.cpp"
    break;

  case 39:
#line 336 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->int_val=yyvsp[-2]->int_val-yyvsp[0]->int_val;
    yyval = node;
}
#line 2058 "src/main.tab.cpp"
    break;

  case 40:
#line 344 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->int_val=yyvsp[-2]->int_val*yyvsp[0]->int_val;
    yyval = node;
}
#line 2071 "src/main.tab.cpp"
    break;

  case 41:
#line 352 "src/main.y"
                         {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->int_val=yyvsp[-2]->int_val/yyvsp[0]->int_val;
    yyval = node;
}
#line 2084 "src/main.tab.cpp"
    break;

  case 42:
#line 360 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->int_val=yyvsp[-2]->int_val<<yyvsp[0]->int_val;
    yyval = node;
}
#line 2097 "src/main.tab.cpp"
    break;

  case 43:
#line 368 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild(yyvsp[0]);
    node->int_val=-yyvsp[0]->int_val;
    yyval = node;
}
#line 2109 "src/main.tab.cpp"
    break;

  case 44:
#line 375 "src/main.y"
                          {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild(yyvsp[-1]);
    node->int_val=yyvsp[-1]->int_val;
    yyval = node;
}
#line 2121 "src/main.tab.cpp"
    break;

  case 45:
#line 385 "src/main.y"
                                  {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_ARRAY);

    yyvsp[-3]->type=new Type(COMPOSE_ARRAY);
    yyvsp[-3]->type->size=yyvsp[-1]->int_val;
    yyvsp[-3]->array_dim=1;
    
    add_id(yyvsp[-3]);
    node->array_dim=1;
    node->addChild(yyvsp[-3]);
    node->addChild(yyvsp[-1]);
    node->type=yyvsp[-3]->type;
    yyval=node;
}
#line 2140 "src/main.tab.cpp"
    break;

  case 46:
#line 399 "src/main.y"
                             {
    yyvsp[-3]->array_dim+=1;
    yyval=yyvsp[-3];
    yyvsp[-3]->addChild(yyvsp[-1]);
    Type* at=new Type(COMPOSE_ARRAY);
    at->size=yyvsp[-1]->int_val;
    yyvsp[-3]->type->addret(at);
}
#line 2153 "src/main.tab.cpp"
    break;

  case 47:
#line 410 "src/main.y"
                              {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_ARRAY);
    node->array_dim=1;
    node->addChild(find_id(yyvsp[-3]));
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 2165 "src/main.tab.cpp"
    break;

  case 48:
#line 417 "src/main.y"
                          {
    yyvsp[-3]->array_dim+=1;
    yyval=yyvsp[-3];
    yyvsp[-3]->addChild(yyvsp[-1]);
}
#line 2175 "src/main.tab.cpp"
    break;

  case 50:
#line 424 "src/main.y"
             {yyval=find_id(yyvsp[0]);}
#line 2181 "src/main.tab.cpp"
    break;

  case 51:
#line 428 "src/main.y"
             {yyval=yyvsp[0];add_id(yyvsp[0]);}
#line 2187 "src/main.tab.cpp"
    break;

  case 52:
#line 429 "src/main.y"
                         {
    TreeNode* node=new TreeNode(yyvsp[-2]->lineno,NODE_EXPR);
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    node->optype=OP_LOP_ASS;
    add_id(yyvsp[-2]);
    yyval=node;
}
#line 2200 "src/main.tab.cpp"
    break;

  case 54:
#line 440 "src/main.y"
                             {
    yyval=yyvsp[-2];
    yyval->addSibling(yyvsp[0]);
}
#line 2209 "src/main.tab.cpp"
    break;

  case 55:
#line 447 "src/main.y"
  {yyval = new TreeNode(lineno, NODE_PARA);yyval->type=new Type(COMPOSE_UNION);}
#line 2215 "src/main.tab.cpp"
    break;

  case 56:
#line 448 "src/main.y"
                 {yyval=yyvsp[-2];yyvsp[-2]->addChild(yyvsp[0]);}
#line 2221 "src/main.tab.cpp"
    break;

  case 57:
#line 449 "src/main.y"
       {
    TreeNode* node=new TreeNode(lineno, NODE_PARA);
    node->type=new Type(COMPOSE_UNION);
    node->addChild(yyvsp[0]);
    yyval=node;
}
#line 2232 "src/main.tab.cpp"
    break;

  case 58:
#line 458 "src/main.y"
             {
    yyval=find_id(yyvsp[0]);
}
#line 2240 "src/main.tab.cpp"
    break;

  case 59:
#line 461 "src/main.y"
          {
    yyval = yyvsp[0];
}
#line 2248 "src/main.tab.cpp"
    break;

  case 60:
#line 464 "src/main.y"
              {
    yyval = yyvsp[0];
}
#line 2256 "src/main.tab.cpp"
    break;

  case 61:
#line 467 "src/main.y"
       {
    yyval = yyvsp[0];
}
#line 2264 "src/main.tab.cpp"
    break;

  case 62:
#line 470 "src/main.y"
         {
    yyval = yyvsp[0];
}
#line 2272 "src/main.tab.cpp"
    break;

  case 63:
#line 473 "src/main.y"
        {
    yyval = yyvsp[0];
}
#line 2280 "src/main.tab.cpp"
    break;

  case 64:
#line 476 "src/main.y"
                               {
    TreeNode* node = new TreeNode(yyvsp[-3]->lineno, NODE_STMT);
    node->stype=STMT_FUNC_USE;
    node->var_name=yyvsp[-3]->var_name;
    yyvsp[-3]->type=new Type(COMPOSE_FUNCTION);
    node->addChild(find_id(yyvsp[-3]));
    node->addChild(yyvsp[-1]);
    yyval=node;
}
#line 2294 "src/main.tab.cpp"
    break;

  case 65:
#line 485 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()+yyvsp[0]->val();
}
#line 2307 "src/main.tab.cpp"
    break;

  case 66:
#line 493 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()-yyvsp[0]->val();
}
#line 2320 "src/main.tab.cpp"
    break;

  case 67:
#line 501 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()*yyvsp[0]->val();
}
#line 2333 "src/main.tab.cpp"
    break;

  case 68:
#line 509 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()/yyvsp[0]->val();
}
#line 2346 "src/main.tab.cpp"
    break;

  case 69:
#line 517 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()%yyvsp[0]->val();
}
#line 2359 "src/main.tab.cpp"
    break;

  case 70:
#line 525 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()<<yyvsp[0]->val();
}
#line 2372 "src/main.tab.cpp"
    break;

  case 71:
#line 533 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_RSHIFT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()>>yyvsp[0]->val();
}
#line 2385 "src/main.tab.cpp"
    break;

  case 72:
#line 541 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_AND;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()&yyvsp[0]->val();
}
#line 2398 "src/main.tab.cpp"
    break;

  case 73:
#line 549 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_OR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()|yyvsp[0]->val();
}
#line 2411 "src/main.tab.cpp"
    break;

  case 74:
#line 557 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_BIT_XOR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()^yyvsp[0]->val();
}
#line 2424 "src/main.tab.cpp"
    break;

  case 75:
#line 565 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_EQ;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()==yyvsp[0]->val();
}
#line 2437 "src/main.tab.cpp"
    break;

  case 76:
#line 573 "src/main.y"
                {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_UEQ;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()!=yyvsp[0]->val();
}
#line 2450 "src/main.tab.cpp"
    break;

  case 77:
#line 581 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()<yyvsp[0]->val();
}
#line 2463 "src/main.tab.cpp"
    break;

  case 78:
#line 589 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_GT;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()>yyvsp[0]->val();
}
#line 2476 "src/main.tab.cpp"
    break;

  case 79:
#line 597 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()<=yyvsp[0]->val();
}
#line 2489 "src/main.tab.cpp"
    break;

  case 80:
#line 605 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_GE;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()>=yyvsp[0]->val();
}
#line 2502 "src/main.tab.cpp"
    break;

  case 81:
#line 613 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LOG_AND;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()&&yyvsp[0]->val();
}
#line 2515 "src/main.tab.cpp"
    break;

  case 82:
#line 621 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LOG_OR;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd2())node->int_val=yyvsp[-2]->val()||yyvsp[0]->val();
}
#line 2528 "src/main.tab.cpp"
    break;

  case 83:
#line 629 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
    if(yyvsp[-2]->is_const)fout<<"const Variable can't be assigned!"<<endl;
	node->optype = OP_LOP_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2541 "src/main.tab.cpp"
    break;

  case 84:
#line 637 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_ADD_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2553 "src/main.tab.cpp"
    break;

  case 85:
#line 644 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUB_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2565 "src/main.tab.cpp"
    break;

  case 86:
#line 651 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_MUL_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2577 "src/main.tab.cpp"
    break;

  case 87:
#line 658 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_DIV_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2589 "src/main.tab.cpp"
    break;

  case 88:
#line 665 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_SUR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2601 "src/main.tab.cpp"
    break;

  case 89:
#line 672 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_LS_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2613 "src/main.tab.cpp"
    break;

  case 90:
#line 679 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_RS_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2625 "src/main.tab.cpp"
    break;

  case 91:
#line 686 "src/main.y"
                   {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_OR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2637 "src/main.tab.cpp"
    break;

  case 92:
#line 693 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_AND_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2649 "src/main.tab.cpp"
    break;

  case 93:
#line 700 "src/main.y"
                    {
    TreeNode* node = new TreeNode(yyvsp[-2]->lineno, NODE_EXPR);
	node->optype = OP_XOR_ASS;
    node->addChild(yyvsp[-2]);
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2661 "src/main.tab.cpp"
    break;

  case 94:
#line 707 "src/main.y"
                        {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd())node->int_val=-yyvsp[0]->val();
}
#line 2673 "src/main.tab.cpp"
    break;

  case 95:
#line 714 "src/main.y"
                      {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_UADD;
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd())node->int_val=yyvsp[0]->val();
}
#line 2685 "src/main.tab.cpp"
    break;

  case 96:
#line 721 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_LOG_NOT;
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd())node->int_val=!yyvsp[0]->val();
}
#line 2697 "src/main.tab.cpp"
    break;

  case 97:
#line 728 "src/main.y"
               {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BIT_NOT;
    node->addChild(yyvsp[0]);
    yyval = node;
    if(node->rd())node->int_val=~yyvsp[0]->val();
}
#line 2709 "src/main.tab.cpp"
    break;

  case 98:
#line 735 "src/main.y"
                          {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_ADDR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2720 "src/main.tab.cpp"
    break;

  case 99:
#line 741 "src/main.y"
                      {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_STAR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2731 "src/main.tab.cpp"
    break;

  case 100:
#line 747 "src/main.y"
            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_INCR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2742 "src/main.tab.cpp"
    break;

  case 101:
#line 753 "src/main.y"
            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_DECR;
    node->addChild(yyvsp[0]);
    yyval = node;
}
#line 2753 "src/main.tab.cpp"
    break;

  case 102:
#line 759 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BACK_INCR;
    node->addChild(yyvsp[-1]);
    yyval = node;
}
#line 2764 "src/main.tab.cpp"
    break;

  case 103:
#line 765 "src/main.y"
                            {
    TreeNode* node = new TreeNode(yyvsp[0]->lineno, NODE_EXPR);
	node->optype = OP_BACK_DECR;
    node->addChild(yyvsp[-1]);
    yyval = node;
}
#line 2775 "src/main.tab.cpp"
    break;

  case 104:
#line 771 "src/main.y"
                      {
    TreeNode* node = new TreeNode(yyvsp[-1]->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild(yyvsp[-1]);
    yyval = node;
    if(node->rd())node->int_val=yyvsp[-1]->val();
}
#line 2787 "src/main.tab.cpp"
    break;

  case 106:
#line 781 "src/main.y"
                   {
    TreeNode* node = new TreeNode(lineno, NODE_TYPE);
    node->type=new Type(COMPOSE_POINTER);
    node->type->retType=yyvsp[-1]->type;
    yyval=node;
}
#line 2798 "src/main.tab.cpp"
    break;

  case 107:
#line 789 "src/main.y"
          {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_INT;}
#line 2804 "src/main.tab.cpp"
    break;

  case 108:
#line 790 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_CHAR;}
#line 2810 "src/main.tab.cpp"
    break;

  case 109:
#line 791 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_BOOL;}
#line 2816 "src/main.tab.cpp"
    break;

  case 110:
#line 792 "src/main.y"
           {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_STRING;}
#line 2822 "src/main.tab.cpp"
    break;

  case 111:
#line 793 "src/main.y"
         {yyval = new TreeNode(lineno, NODE_TYPE); yyval->type = TYPE_VOID;}
#line 2828 "src/main.tab.cpp"
    break;


#line 2832 "src/main.tab.cpp"

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
#line 796 "src/main.y"


int yyerror(char const* message)
{
  fout << message << " at line " << lineno << endl;
  return -1;
}
