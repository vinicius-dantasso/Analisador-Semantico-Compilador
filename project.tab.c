/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project.y"

/* analisador sintático para reconhecer frases em português */
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include "semantic.h"
using namespace std;

char vet[200];
int isClass = 0;
string key = "";
extern char * yytext;

vector<int> token;
unordered_map< string, vector<string> > image;
vector<string> faixa;
Semantic * semantic;
vector<string> vec_proprie;
string valueString;
int yylex(void);
int yyparse(void);
void yyerror(const char *);

#line 97 "project.tab.c"

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

#include "project.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RESERVED_WORD = 3,              /* RESERVED_WORD  */
  YYSYMBOL_IDCLASS = 4,                    /* IDCLASS  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_EQUIVALENTTO = 6,               /* EQUIVALENTTO  */
  YYSYMBOL_SUBCLASSOF = 7,                 /* SUBCLASSOF  */
  YYSYMBOL_DISJOINTCLASSES = 8,            /* DISJOINTCLASSES  */
  YYSYMBOL_IDINDIVIDUALS = 9,              /* IDINDIVIDUALS  */
  YYSYMBOL_INDIVIDUALS = 10,               /* INDIVIDUALS  */
  YYSYMBOL_RELOP = 11,                     /* RELOP  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_PROPERTIE_IS = 13,              /* PROPERTIE_IS  */
  YYSYMBOL_PROPERTIE_HAS = 14,             /* PROPERTIE_HAS  */
  YYSYMBOL_PROPERTIE = 15,                 /* PROPERTIE  */
  YYSYMBOL_DATA_TYPE = 16,                 /* DATA_TYPE  */
  YYSYMBOL_YYACCEPT = 17,                  /* $accept  */
  YYSYMBOL_classes = 18,                   /* classes  */
  YYSYMBOL_classPri = 19,                  /* classPri  */
  YYSYMBOL_classDefAnin = 20,              /* classDefAnin  */
  YYSYMBOL_classAxi = 21,                  /* classAxi  */
  YYSYMBOL_classEnum = 22,                 /* classEnum  */
  YYSYMBOL_classCober = 23,                /* classCober  */
  YYSYMBOL_class = 24,                     /* class  */
  YYSYMBOL_subClassOf = 25,                /* subClassOf  */
  YYSYMBOL_subClass_list = 26,             /* subClass_list  */
  YYSYMBOL_composedBySubClass = 27,        /* composedBySubClass  */
  YYSYMBOL_subClass_list2 = 28,            /* subClass_list2  */
  YYSYMBOL_subClassOf_Axi = 29,            /* subClassOf_Axi  */
  YYSYMBOL_subClass_AxiList = 30,          /* subClass_AxiList  */
  YYSYMBOL_equivalentTo = 31,              /* equivalentTo  */
  YYSYMBOL_equivalent = 32,                /* equivalent  */
  YYSYMBOL_descAnin = 33,                  /* descAnin  */
  YYSYMBOL_descAnin2 = 34,                 /* descAnin2  */
  YYSYMBOL_equivalentToCober = 35,         /* equivalentToCober  */
  YYSYMBOL_cober_list = 36,                /* cober_list  */
  YYSYMBOL_equivalentToEnum = 37,          /* equivalentToEnum  */
  YYSYMBOL_enum_list = 38,                 /* enum_list  */
  YYSYMBOL_disjointClasses = 39,           /* disjointClasses  */
  YYSYMBOL_disjointClasses_list = 40,      /* disjointClasses_list  */
  YYSYMBOL_individuals = 41,               /* individuals  */
  YYSYMBOL_individuals_list = 42,          /* individuals_list  */
  YYSYMBOL_propertie = 43,                 /* propertie  */
  YYSYMBOL_reserverd_words = 44,           /* reserverd_words  */
  YYSYMBOL_id_class = 45,                  /* id_class  */
  YYSYMBOL_num = 46,                       /* num  */
  YYSYMBOL_relop = 47,                     /* relop  */
  YYSYMBOL_num_proprie = 48                /* num_proprie  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    32,    32,    33,    34,    35,    36,    37,    42,    43,
      44,    45,    46,    50,    51,    55,    59,    63,    67,    75,
      76,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    98,    99,
     102,   103,   104,   108,   112,   113,   114,   118,   119,   122,
     123,   124,   127,   128,   129,   130,   131,   134,   135,   136,
     137,   138,   139,   140,   141,   145,   149,   150,   154,   158,
     159,   163,   167,   168,   172,   176,   177,   181,   182,   183,
     186,   189,   192,   194,   196
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RESERVED_WORD",
  "IDCLASS", "CLASS", "EQUIVALENTTO", "SUBCLASSOF", "DISJOINTCLASSES",
  "IDINDIVIDUALS", "INDIVIDUALS", "RELOP", "NUM", "PROPERTIE_IS",
  "PROPERTIE_HAS", "PROPERTIE", "DATA_TYPE", "$accept", "classes",
  "classPri", "classDefAnin", "classAxi", "classEnum", "classCober",
  "class", "subClassOf", "subClass_list", "composedBySubClass",
  "subClass_list2", "subClassOf_Axi", "subClass_AxiList", "equivalentTo",
  "equivalent", "descAnin", "descAnin2", "equivalentToCober", "cober_list",
  "equivalentToEnum", "enum_list", "disjointClasses",
  "disjointClasses_list", "individuals", "individuals_list", "propertie",
  "reserverd_words", "id_class", "num", "relop", "num_proprie", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,     9,    29,    11,    11,    11,    11,    11,    60,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    73,     8,    91,  -104,
      20,    -2,  -104,  -104,  -104,    24,  -104,    43,    39,  -104,
    -104,  -104,  -104,  -104,    23,     4,    52,    71,    20,    95,
    -104,    79,    70,  -104,    28,   117,  -104,  -104,   147,   173,
      43,    53,    40,  -104,    23,    93,   118,  -104,  -104,   121,
    -104,  -104,   127,    43,    43,   130,    43,  -104,   158,    24,
     170,  -104,    43,   141,    74,    52,   126,   136,   138,   173,
    -104,     8,     8,    23,    36,    40,    52,   143,    68,    52,
      52,  -104,   163,  -104,   173,    43,  -104,   173,    43,  -104,
     164,    52,   139,   178,    52,   179,     8,     8,    43,  -104,
    -104,    36,   180,  -104,  -104,    43,  -104,   181,  -104,   182,
      43,   106,    43,  -104,  -104,   184,   183,     8,  -104,     8,
       8,  -104,  -104,  -104,     4,   109,   185,     8,  -104,   186,
     187,   105,    52,    43,  -104,   192,     8,  -104,  -104,  -104,
      52,   193,     8,    43,  -104,    79,    52,   194,    43,  -104,
    -104,  -104,   195,   111,  -104,  -104,   196,    43,   197,   112,
    -104,   124,  -104,   201,   202,    52,    43,    43,  -104,  -104,
     203,   173,  -104,    43,   205,  -104,  -104,   173,  -104,    43,
    -104,   206,    43,    52,    43,   209,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     7,     7,     7,     7,     7,     0,    18,
       1,     2,     3,     4,     5,     6,     0,     0,     8,    15,
      14,     0,    17,    16,    81,     0,    65,    67,     0,    78,
      77,    79,    19,    43,     0,    20,     0,     0,     9,    10,
      13,     0,     0,    48,    64,     0,    68,    80,     0,     0,
       0,     0,     0,    34,     0,     0,    71,    73,    76,    74,
      12,    11,     0,     0,    67,     0,    64,    55,     0,    70,
       0,    66,     0,     0,     0,     0,     0,    32,    28,     0,
      33,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,    83,     0,    56,     0,     0,    69,     0,     0,    51,
       0,     0,    30,     0,     0,    24,     0,     0,     0,    36,
      35,     0,    28,    72,    75,    64,    54,     0,    82,     0,
       0,     0,     0,    49,    84,     0,    26,     0,    46,     0,
       0,    22,    21,    45,     0,     0,    28,     0,    53,     0,
       0,     0,     0,    64,    50,     0,     0,    31,    23,    25,
       0,     0,     0,    64,    47,     0,     0,     0,    64,    62,
      37,    27,     0,    40,    44,    52,     0,     0,     0,    64,
      63,     0,    41,     0,     0,     0,    64,    64,    60,    38,
       0,     0,    42,    64,     0,    59,    61,     0,    39,     0,
      58,     0,     0,     0,    64,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,   160,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    72,
      15,    49,  -104,  -103,  -104,  -104,  -104,    67,  -104,   -13,
    -104,   154,   188,  -104,   -14,  -104,    -7,    48,   -16,  -104,
    -104,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,     7,     8,    18,    53,
      81,    82,    19,    33,    20,    21,    43,    67,    22,    71,
      23,    46,    38,    56,    39,    59,    54,    68,    55,   119,
      92,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    35,    24,    26,   133,    44,    40,    28,    24,    41,
      34,    28,    24,     9,    42,    52,     1,    29,    30,    31,
      57,    29,    30,    31,    60,    64,    47,    50,    62,    10,
      37,    47,    64,    45,    63,    78,    29,    30,    31,    66,
      24,    72,    73,    28,    24,    83,    47,    50,    76,   164,
      49,    79,    77,    29,    30,    31,    24,    24,   102,    64,
     105,    95,   103,    98,    75,    76,    16,    17,   112,    77,
     113,    47,   108,   117,    64,    48,    50,    24,    24,   115,
      58,    65,    51,    24,    25,   126,   101,   120,   129,    32,
     122,   134,    29,    30,    31,   136,    28,    24,    74,    36,
      34,    37,    84,    36,    85,   143,    29,    30,    31,    24,
      24,    89,    90,    24,    47,    47,   155,   156,   142,   151,
      99,   150,   172,   177,    80,   157,   158,    47,    69,    86,
      24,   111,    87,    93,   162,   179,   134,   104,    88,    64,
     168,    91,   166,   121,   100,    34,   123,   106,   167,   107,
     127,    24,   114,   109,   110,   116,   135,    80,    70,   184,
      29,    30,    31,    11,    12,    13,    14,    15,   141,    94,
     144,    29,    30,    31,   189,   118,   124,   151,   131,   132,
     192,    97,   138,    29,    30,    31,    29,    30,    31,   128,
     130,   137,   139,   140,   146,   188,   152,   153,   154,   147,
     145,   148,   149,   160,   163,   169,   171,   174,   176,   132,
     159,   173,   181,   183,   187,   175,   191,   194,   161,   180,
     165,   150,   182,    96,   132,   170,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   193,     0,     0,
     195,     0,     0,   185,   186,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196
};

static const yytype_int16 yycheck[] =
{
      16,    17,     4,    16,   107,    21,    20,     3,     4,    11,
      17,     3,     4,     4,    16,    11,     5,    13,    14,    15,
      36,    13,    14,    15,    38,    41,     3,    34,    41,     0,
      10,     3,    48,     9,    41,    51,    13,    14,    15,    11,
       4,    48,    49,     3,     4,    52,     3,    54,    12,   152,
      11,    11,    16,    13,    14,    15,     4,     4,    74,    75,
      76,    68,    75,    70,    11,    12,     6,     7,    84,    16,
      86,     3,    79,    89,    90,    27,    83,     4,     4,    11,
       9,    11,    34,     4,    11,   101,    12,    94,   104,    17,
      97,   107,    13,    14,    15,   111,     3,     4,    50,     8,
     107,    10,    54,     8,    11,   121,    13,    14,    15,     4,
       4,    63,    64,     4,     3,     3,    11,    12,    12,   135,
      72,    12,    11,    11,    52,   141,   142,     3,    11,    11,
       4,    83,    11,    66,   150,    11,   152,    11,    11,   155,
     156,    11,   155,    95,     3,   152,    98,    11,   155,    11,
      11,     4,     9,    81,    82,    88,   108,    85,    11,   175,
      13,    14,    15,     3,     4,     5,     6,     7,   120,    11,
     122,    13,    14,    15,   181,    12,    12,   193,   106,   107,
     187,    11,   115,    13,    14,    15,    13,    14,    15,    11,
      11,    11,    11,    11,    11,   180,    11,    11,    11,   127,
      16,   129,   130,    11,    11,    11,    11,    11,    11,   137,
     143,   163,    11,    11,    11,   167,    11,    11,   146,   171,
     153,    12,   173,    69,   152,   158,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,   189,    -1,    -1,
     192,    -1,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    18,    19,    20,    21,    22,    23,    24,     4,
       0,    18,    18,    18,    18,    18,     6,     7,    25,    29,
      31,    32,    35,    37,     4,    11,    36,    45,     3,    13,
      14,    15,    26,    30,    43,    45,     8,    10,    39,    41,
      41,    11,    16,    33,    45,     9,    38,     3,    44,    11,
      43,    44,    11,    26,    43,    45,    40,    45,     9,    42,
      41,    39,    36,    43,    45,    11,    11,    34,    44,    11,
      11,    36,    43,    43,    44,    11,    12,    16,    45,    11,
      26,    27,    28,    43,    44,    11,    11,    11,    11,    44,
      44,    11,    47,    34,    11,    43,    38,    11,    43,    44,
       3,    12,    45,    36,    11,    45,    11,    11,    43,    26,
      26,    44,    45,    45,     9,    11,    34,    45,    12,    46,
      43,    44,    43,    44,    12,    48,    45,    11,    11,    45,
      11,    26,    26,    30,    45,    44,    45,    11,    34,    11,
      11,    44,    12,    45,    44,    16,    11,    26,    26,    26,
      12,    45,    11,    11,    11,    11,    12,    45,    45,    34,
      11,    26,    45,    11,    30,    34,    36,    43,    45,    11,
      34,    11,    11,    44,    11,    44,    11,    11,    34,    11,
      44,    11,    28,    11,    45,    34,    34,    11,    27,    43,
      34,    11,    43,    44,    11,    44,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    17,    18,    18,    18,    18,    18,    18,    19,    19,
      19,    19,    19,    20,    20,    21,    22,    23,    24,    25,
      25,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    27,    27,
      28,    28,    28,    29,    30,    30,    30,    31,    31,    32,
      32,    32,    33,    33,    33,    33,    33,    34,    34,    34,
      34,    34,    34,    34,    34,    35,    36,    36,    37,    38,
      38,    39,    40,    40,    41,    42,    42,    43,    43,    43,
      44,    45,    46,    47,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     2,     3,
       3,     4,     4,     3,     2,     2,     2,     2,     2,     2,
       2,     5,     5,     6,     4,     6,     5,     7,     3,     5,
       4,     6,     3,     3,     2,     4,     4,     7,     7,     8,
       5,     6,     7,     2,     7,     5,     5,     7,     2,     6,
       7,     5,     7,     5,     4,     2,     3,    11,     9,     8,
       7,     8,     5,     6,     0,     2,     3,     1,     3,     3,
       2,     2,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 8: /* classPri: class subClassOf  */
#line 42 "project.y"
                           { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); }
#line 1268 "project.tab.c"
    break;

  case 9: /* classPri: class subClassOf disjointClasses  */
#line 43 "project.y"
                                                   { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe primitiva válida\n"; }
#line 1274 "project.tab.c"
    break;

  case 10: /* classPri: class subClassOf individuals  */
#line 44 "project.y"
                                               { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe primitiva válida\n"; }
#line 1280 "project.tab.c"
    break;

  case 11: /* classPri: class subClassOf individuals disjointClasses  */
#line 45 "project.y"
                                                               { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); /* Forçando erro */ }
#line 1286 "project.tab.c"
    break;

  case 12: /* classPri: class subClassOf disjointClasses individuals  */
#line 46 "project.y"
                                                               { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe primitiva válida\n"; }
#line 1292 "project.tab.c"
    break;

  case 13: /* classDefAnin: class equivalentTo individuals  */
#line 50 "project.y"
                                             { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe Definida válida\n"; }
#line 1298 "project.tab.c"
    break;

  case 14: /* classDefAnin: class equivalentTo  */
#line 51 "project.y"
                                             { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); }
#line 1304 "project.tab.c"
    break;

  case 15: /* classAxi: class subClassOf_Axi  */
#line 55 "project.y"
                               { semantic = new Semantic(token, image, 1, faixa, valueString); token.clear(); cout << "Classe com axioma de fechamento válida\n"; }
#line 1310 "project.tab.c"
    break;

  case 16: /* classEnum: class equivalentToEnum  */
#line 59 "project.y"
                                  { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe enumerada válida\n"; }
#line 1316 "project.tab.c"
    break;

  case 17: /* classCober: class equivalentToCober  */
#line 63 "project.y"
                                    { semantic = new Semantic(token, image, 0, faixa, valueString); token.clear(); cout << "Classe coberta válida\n"; }
#line 1322 "project.tab.c"
    break;

  case 18: /* class: CLASS IDCLASS  */
#line 67 "project.y"
                     { 
		isClass = 1; 
		strcpy(vet,yytext);
		token.push_back(CLASSTOKEN);
 	}
#line 1332 "project.tab.c"
    break;

  case 19: /* subClassOf: SUBCLASSOF subClass_list  */
#line 75 "project.y"
                                     { token.push_back(SUBCLASSTOKEN); }
#line 1338 "project.tab.c"
    break;

  case 20: /* subClassOf: SUBCLASSOF id_class  */
#line 76 "project.y"
                                        { token.push_back(SUBCLASSTOKEN); }
#line 1344 "project.tab.c"
    break;

  case 43: /* subClassOf_Axi: SUBCLASSOF subClass_AxiList  */
#line 108 "project.y"
                                            { token.push_back(SUBCLASSTOKEN); }
#line 1350 "project.tab.c"
    break;

  case 48: /* equivalentTo: equivalent descAnin  */
#line 119 "project.y"
                                              { cout << "Classe Definida/Aninhada válida\n"; }
#line 1356 "project.tab.c"
    break;

  case 71: /* disjointClasses: DISJOINTCLASSES disjointClasses_list  */
#line 163 "project.y"
                                                      { token.push_back(DISJOINTTOKEN); }
#line 1362 "project.tab.c"
    break;

  case 74: /* individuals: INDIVIDUALS individuals_list  */
#line 172 "project.y"
                                          { token.push_back(INDIVIDUALSTOKEN); }
#line 1368 "project.tab.c"
    break;

  case 77: /* propertie: PROPERTIE_HAS  */
#line 181 "project.y"
                         { key = yytext; image[key]; }
#line 1374 "project.tab.c"
    break;

  case 78: /* propertie: PROPERTIE_IS  */
#line 182 "project.y"
                        { key = yytext; image[key]; }
#line 1380 "project.tab.c"
    break;

  case 79: /* propertie: PROPERTIE  */
#line 183 "project.y"
                     { key = yytext; image[key]; }
#line 1386 "project.tab.c"
    break;

  case 80: /* reserverd_words: RESERVED_WORD  */
#line 186 "project.y"
                               { image[key].push_back(yytext); }
#line 1392 "project.tab.c"
    break;

  case 81: /* id_class: IDCLASS  */
#line 189 "project.y"
                  { image[key].push_back(yytext); }
#line 1398 "project.tab.c"
    break;

  case 82: /* num: NUM  */
#line 192 "project.y"
         {faixa.push_back(yytext);}
#line 1404 "project.tab.c"
    break;

  case 83: /* relop: RELOP  */
#line 194 "project.y"
             {faixa.push_back(yytext);}
#line 1410 "project.tab.c"
    break;

  case 84: /* num_proprie: NUM  */
#line 196 "project.y"
                 {valueString = yytext;}
#line 1416 "project.tab.c"
    break;


#line 1420 "project.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 198 "project.y"


/* definido pelo analisador léxico */
extern FILE * yyin;  

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	extern int yylineno;    
  

	if(isClass == 1) {
		/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
    	cout << "Erro sintático: símbolo \"" << yytext << "\" (linha " << yylineno << ") Na classe " << vet << "\n";
		isClass = 2;
	}
	yyparse();
}
