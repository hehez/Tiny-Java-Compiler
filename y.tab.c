/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PUBLIC = 258,
     PRIVATE = 259,
     CLASS = 260,
     STATIC = 261,
     VOID = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     NEW = 267,
     RETURN = 268,
     NUL = 269,
     INT = 270,
     FLOAT = 271,
     SWITCH = 272,
     CASE = 273,
     DIGIT = 274,
     DQUOTE = 275,
     SQUOTE = 276,
     DOT = 277,
     COMMA = 278,
     SEMI = 279,
     COLON = 280,
     IDENT = 281,
     INTEGERLITERAL = 282,
     EXPONENT = 283,
     FLOATINGLITERAL = 284,
     STRING = 285,
     ERR1 = 286,
     ERR2 = 287,
     ERR3 = 288,
     PLUS = 289,
     MINUS = 290,
     TIMES = 291,
     DIVIDE = 292,
     EQUALS = 293,
     GREAT = 294,
     LESS = 295,
     YEQUAL = 296,
     NEQUAL = 297,
     GEQUAL = 298,
     LEQUAL = 299,
     INCRE = 300,
     DECRE = 301,
     LPAR = 302,
     RPAR = 303,
     LBRACK = 304,
     RBRACK = 305,
     LBRACE = 306,
     RBRACE = 307
   };
#endif
/* Tokens.  */
#define PUBLIC 258
#define PRIVATE 259
#define CLASS 260
#define STATIC 261
#define VOID 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define NEW 267
#define RETURN 268
#define NUL 269
#define INT 270
#define FLOAT 271
#define SWITCH 272
#define CASE 273
#define DIGIT 274
#define DQUOTE 275
#define SQUOTE 276
#define DOT 277
#define COMMA 278
#define SEMI 279
#define COLON 280
#define IDENT 281
#define INTEGERLITERAL 282
#define EXPONENT 283
#define FLOATINGLITERAL 284
#define STRING 285
#define ERR1 286
#define ERR2 287
#define ERR3 288
#define PLUS 289
#define MINUS 290
#define TIMES 291
#define DIVIDE 292
#define EQUALS 293
#define GREAT 294
#define LESS 295
#define YEQUAL 296
#define NEQUAL 297
#define GEQUAL 298
#define LEQUAL 299
#define INCRE 300
#define DECRE 301
#define LPAR 302
#define RPAR 303
#define LBRACK 304
#define RBRACK 305
#define LBRACE 306
#define RBRACE 307




/* Copy the first part of user declarations.  */
#line 5 "tjc.y"


#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

// include the AST Library header file
//
// If you'd like to change the definition of the ENTRY macro,
// it should be done here.  For example:
//
// #define ENTRY  MyEntry
//
//
#include "Ast.h"
#include "SymTab.h"

#define YYERROR_VERBOSE

using namespace std;

// this global variable is defined in main-ast.cpp
// this parser will build a syntax tree and assign
// the root of the tree to this global variable
// so that the main program can traverse it
//
extern ClassDeclaration *expTree;
extern int yylineno;

ClassDeclaration *classDecl;
MethodDeclaration *methodDecl;
ReturnEntry *e;
int yyerrstatus;

void free(void *ptr);

int yylex(void);
int yyerror(const char *msg);
void error(const char *msg);
void fatal(const char *, const char *);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 104 "tjc.y"
{
    int                         ival;
    char                        *sval;
    Entry                       *eval;
    Statement                   *tval;
    BlockStatement              *bval;
    Expression                  *xval;
    LiteralExpression           *lxval;
    MethodCallExpression        *mval;
    Declaration                 *dval;
    std::vector<int>            *vival;
    std::vector<Expression *>   *vxval;
    std::vector<Declaration *>  *vdval;
}
/* Line 193 of yacc.c.  */
#line 260 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    14,    16,    19,    21,    23,
      30,    31,    32,    44,    45,    46,    58,    59,    69,    70,
      80,    81,    96,    98,   102,   104,   108,   110,   114,   117,
     120,   123,   125,   131,   134,   136,   139,   141,   146,   154,
     160,   168,   174,   186,   201,   204,   208,   210,   214,   217,
     224,   229,   235,   239,   241,   245,   247,   251,   255,   257,
     261,   265,   269,   273,   275,   279,   283,   285,   289,   293,
     295,   298,   301,   304,   307,   312,   314,   316,   321,   327,
     333,   335,   339,   341,   343,   345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    -1,     3,     5,    26,    56,
      51,    57,    52,    -1,    58,    -1,    58,    57,    -1,    59,
      -1,    60,    -1,     6,    68,    26,    38,    86,    24,    -1,
      -1,    -1,     6,    68,    26,    47,    61,    69,    48,    62,
      51,    71,    52,    -1,    -1,    -1,     6,     7,    26,    47,
      63,    69,    48,    64,    51,    71,    52,    -1,    -1,     6,
      68,    26,    47,    48,    65,    51,    71,    52,    -1,    -1,
       6,     7,    26,    47,    48,    66,    51,    71,    52,    -1,
      -1,     3,     6,     7,    26,    47,    26,    49,    50,    26,
      48,    67,    51,    71,    52,    -1,    15,    -1,    15,    49,
      50,    -1,    16,    -1,    16,    49,    50,    -1,    70,    -1,
      70,    23,    69,    -1,    68,    26,    -1,    72,    74,    -1,
      73,    72,    -1,    87,    -1,    68,    26,    38,    86,    24,
      -1,    76,    74,    -1,    77,    -1,    76,    75,    -1,    87,
      -1,    26,    38,    80,    24,    -1,    26,    49,    85,    50,
      38,    80,    24,    -1,     8,    47,    80,    48,    76,    -1,
       8,    47,    80,    48,    76,     9,    76,    -1,    10,    47,
      80,    48,    76,    -1,    11,    47,    26,    38,    80,    24,
      80,    24,    80,    48,    76,    -1,    11,    47,    26,    49,
      80,    50,    38,    80,    24,    80,    24,    80,    48,    76,
      -1,    78,    24,    -1,    51,    75,    52,    -1,    24,    -1,
      13,    80,    24,    -1,    13,    24,    -1,    26,    22,    26,
      47,    79,    48,    -1,    26,    47,    79,    48,    -1,    26,
      22,    26,    47,    48,    -1,    26,    47,    48,    -1,    80,
      -1,    79,    23,    80,    -1,    81,    -1,    81,    41,    81,
      -1,    81,    42,    81,    -1,    82,    -1,    82,    40,    82,
      -1,    82,    39,    82,    -1,    82,    44,    82,    -1,    82,
      43,    82,    -1,    83,    -1,    82,    34,    83,    -1,    82,
      35,    83,    -1,    84,    -1,    83,    36,    84,    -1,    83,
      37,    84,    -1,    85,    -1,    85,    45,    -1,    85,    46,
      -1,    34,    84,    -1,    35,    84,    -1,    47,    68,    48,
      84,    -1,    86,    -1,    26,    -1,    26,    49,    85,    50,
      -1,    12,    15,    49,    85,    50,    -1,    12,    16,    49,
      85,    50,    -1,    78,    -1,    47,    80,    48,    -1,    27,
      -1,    29,    -1,    30,    -1,    14,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   172,   171,   178,   184,   191,   196,   202,
     209,   214,   208,   220,   225,   219,   231,   230,   238,   237,
     245,   244,   265,   270,   275,   280,   286,   292,   299,   305,
     312,   318,   324,   330,   336,   343,   349,   355,   360,   365,
     370,   375,   380,   385,   390,   395,   400,   406,   411,   417,
     423,   429,   435,   442,   448,   455,   460,   465,   471,   476,
     481,   486,   491,   497,   502,   507,   513,   518,   523,   529,
     534,   539,   544,   549,   554,   560,   565,   571,   577,   582,
     587,   592,   598,   603,   608,   613,   619
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PUBLIC", "PRIVATE", "CLASS", "STATIC",
  "VOID", "IF", "ELSE", "WHILE", "FOR", "NEW", "RETURN", "NUL", "INT",
  "FLOAT", "SWITCH", "CASE", "DIGIT", "DQUOTE", "SQUOTE", "DOT", "COMMA",
  "SEMI", "COLON", "IDENT", "INTEGERLITERAL", "EXPONENT",
  "FLOATINGLITERAL", "STRING", "ERR1", "ERR2", "ERR3", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "EQUALS", "GREAT", "LESS", "YEQUAL", "NEQUAL",
  "GEQUAL", "LEQUAL", "INCRE", "DECRE", "LPAR", "RPAR", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "$accept", "tiny_java_program", "class_decl", "@1",
  "member_decl_list", "member_decl", "field_decl", "method_decl", "@2",
  "@3", "@4", "@5", "@6", "@7", "@8", "type", "formal_param_list",
  "formal_param", "method_body", "local_decl_list", "local_decl",
  "method_statement_list", "statement_list", "statement",
  "return_statement", "method_invocation", "argument_list", "expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "primary_expression",
  "literal", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    56,    55,    57,    57,    58,    58,    59,
      61,    62,    60,    63,    64,    60,    65,    60,    66,    60,
      67,    60,    68,    68,    68,    68,    69,    69,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     7,     1,     2,     1,     1,     6,
       0,     0,    11,     0,     0,    11,     0,     9,     0,     9,
       0,    14,     1,     3,     1,     3,     1,     3,     2,     2,
       2,     1,     5,     2,     1,     2,     1,     4,     7,     5,
       7,     5,    11,    14,     2,     3,     1,     3,     2,     6,
       4,     5,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     4,     5,     5,
       1,     3,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     3,     0,     0,     0,
       0,     0,     5,     7,     8,     0,     0,    22,    24,     0,
       4,     6,     0,     0,     0,     0,     0,     0,    13,    23,
      25,     0,    10,     0,    18,     0,    85,    82,    83,    84,
       0,    16,     0,     0,     0,     0,     0,    26,     9,     0,
       0,     0,    86,    28,    14,     0,    86,    11,     0,     0,
       0,     0,    86,    31,     0,    27,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    46,     0,    86,    29,     0,
      34,     0,    30,    86,    17,    86,    20,     0,     0,     0,
       0,     0,    48,    76,     0,     0,     0,    80,     0,    55,
      58,    63,    66,    69,    75,     0,     0,     0,     0,     0,
      86,    36,    33,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,    52,     0,    53,     0,     0,    45,    35,
      15,    12,    86,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    56,    57,    64,    65,    60,    59,    62,
      61,    67,    68,     0,    37,     0,    50,     0,     0,    39,
      41,     0,     0,     0,     0,    77,    74,    51,     0,    54,
       0,    21,     0,     0,     0,    78,    79,    49,     0,    40,
       0,     0,    38,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    11,    12,    13,    14,    42,    67,
      35,    64,    49,    44,   116,    59,    46,    47,    60,    61,
      62,    78,   109,    79,    80,    97,   144,   127,    99,   100,
     101,   102,   103,   104,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
       7,    28,    65,  -103,    47,  -103,  -103,    26,     9,    77,
      75,    23,     9,  -103,  -103,    82,    66,    56,    70,    91,
    -103,  -103,    94,    76,    46,    72,   -25,    81,    78,  -103,
    -103,    49,    87,   103,  -103,    37,  -103,  -103,  -103,  -103,
     106,  -103,    37,    95,    85,   119,   101,   130,  -103,   104,
     108,   107,    37,  -103,  -103,    37,    37,  -103,   128,   132,
     110,    16,    37,  -103,   112,  -103,   114,   118,   111,   133,
    -103,   123,   134,   135,   181,  -103,    17,    35,  -103,    16,
    -103,   151,  -103,    37,  -103,    37,  -103,    49,   192,   192,
     153,    69,  -103,    13,   192,   192,   162,  -103,   156,   -10,
      68,    62,  -103,    55,  -103,   157,   192,   113,   211,   142,
      35,  -103,  -103,  -103,   146,   147,   136,   160,   152,   154,
     -24,   141,   163,   211,  -103,  -103,   155,   165,  -103,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,  -103,
    -103,   167,   177,  -103,     0,  -103,   192,   170,  -103,  -103,
    -103,  -103,    37,  -103,    35,    35,   192,   192,   211,   211,
     174,   192,  -103,  -103,  -103,    62,    62,    79,    79,    79,
      79,  -103,  -103,   138,  -103,   192,  -103,   179,   178,   220,
    -103,   207,   182,   183,   184,  -103,  -103,  -103,    24,  -103,
     192,  -103,    35,   192,   197,  -103,  -103,  -103,   212,  -103,
     218,   192,  -103,   192,   219,   196,   192,    35,   221,  -103,
     192,   198,    35,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,  -103,   235,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,    -1,   -38,  -103,   -55,   186,
    -103,   171,   139,   -74,  -103,   -61,    80,   -69,   -20,   -65,
     -16,   -87,  -102,   -29,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      81,    66,    40,   110,    50,    98,   147,   124,   125,    19,
       1,   111,     9,    31,   156,    10,    81,    65,    81,   118,
     119,   160,    32,   175,    71,   157,    72,    73,   114,    74,
     115,   129,   130,     4,    45,   105,   110,   142,   145,   105,
      75,    45,    76,    71,   111,    72,    73,   175,   176,    81,
     171,   172,    17,    18,    45,   106,   183,   184,   117,    75,
     107,    76,   123,    36,   107,     5,   108,    77,   167,   168,
     169,   170,   197,     6,   186,    20,    37,     8,    38,    39,
     179,   180,    16,    15,   121,   122,    77,   181,   182,    22,
      17,    18,    23,    81,    81,   126,    29,   178,   137,   138,
     139,   140,   131,   132,   145,    24,   189,   133,   134,   163,
     164,   135,   136,   131,   132,   165,   166,    26,   199,    25,
      27,   198,    30,    28,   200,    91,    34,    36,    33,    43,
      48,    81,   204,   209,   205,    41,    52,   208,   213,    93,
      37,   211,    38,    39,    51,    53,    81,    94,    95,    54,
      91,    81,    36,    55,    68,    56,    57,    58,    69,    86,
      96,   143,    70,    83,    93,    37,    84,    38,    39,    85,
      88,    87,    94,    95,    91,   113,    36,    17,    18,   120,
     128,    89,    90,   141,   153,    96,   187,   152,    93,    37,
     158,    38,    39,    91,   148,    36,    94,    95,   150,   151,
     154,   174,   155,   161,    91,    92,    36,    93,    37,    96,
      38,    39,   159,   162,   173,    94,    95,   190,    93,    37,
     177,    38,    39,    91,   185,    36,    94,    95,    96,   192,
     191,   193,   194,   195,   196,   201,   202,    93,    37,    96,
      38,    39,   203,   206,   207,   210,   212,    21,    82,   149,
     112,     0,     0,   188,     0,     0,     0,     0,   146
};

static const yytype_int16 yycheck[] =
{
      61,    56,    31,    77,    42,    74,   108,    94,    95,    10,
       3,    77,     3,    38,    38,     6,    77,    55,    79,    88,
      89,   123,    47,    23,     8,    49,    10,    11,    83,    13,
      85,    41,    42,     5,    35,    22,   110,   106,   107,    22,
      24,    42,    26,     8,   110,    10,    11,    23,    48,   110,
     137,   138,    15,    16,    55,    38,   158,   159,    87,    24,
      47,    26,    49,    14,    47,     0,    49,    51,   133,   134,
     135,   136,    48,    26,   161,    52,    27,    51,    29,    30,
     154,   155,     7,     6,    15,    16,    51,   156,   157,     7,
      15,    16,    26,   154,   155,    96,    50,   152,    36,    37,
      45,    46,    34,    35,   173,    49,   175,    39,    40,   129,
     130,    43,    44,    34,    35,   131,   132,    26,   192,    49,
      26,   190,    50,    47,   193,    12,    48,    14,    47,    26,
      24,   192,   201,   207,   203,    48,    51,   206,   212,    26,
      27,   210,    29,    30,    49,    26,   207,    34,    35,    48,
      12,   212,    14,    23,    26,    51,    48,    50,    26,    48,
      47,    48,    52,    51,    26,    27,    52,    29,    30,    51,
      47,    38,    34,    35,    12,    24,    14,    15,    16,    26,
      24,    47,    47,    26,    24,    47,    48,    51,    26,    27,
      49,    29,    30,    12,    52,    14,    34,    35,    52,    52,
      48,    24,    48,    48,    12,    24,    14,    26,    27,    47,
      29,    30,    49,    48,    47,    34,    35,    38,    26,    27,
      50,    29,    30,    12,    50,    14,    34,    35,    47,     9,
      52,    24,    50,    50,    50,    38,    24,    26,    27,    47,
      29,    30,    24,    24,    48,    24,    48,    12,    62,   110,
      79,    -1,    -1,   173,    -1,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,     5,     0,    26,    56,    51,     3,
       6,    57,    58,    59,    60,     6,     7,    15,    16,    68,
      52,    57,     7,    26,    49,    49,    26,    26,    47,    50,
      50,    38,    47,    47,    48,    63,    14,    27,    29,    30,
      86,    48,    61,    26,    66,    68,    69,    70,    24,    65,
      69,    49,    51,    26,    48,    23,    51,    48,    50,    68,
      71,    72,    73,    87,    64,    69,    71,    62,    26,    26,
      52,     8,    10,    11,    13,    24,    26,    51,    74,    76,
      77,    78,    72,    51,    52,    51,    48,    38,    47,    47,
      47,    12,    24,    26,    34,    35,    47,    78,    80,    81,
      82,    83,    84,    85,    86,    22,    38,    47,    49,    75,
      76,    87,    74,    24,    71,    71,    67,    86,    80,    80,
      26,    15,    16,    49,    84,    84,    68,    80,    24,    41,
      42,    34,    35,    39,    40,    43,    44,    36,    37,    45,
      46,    26,    80,    48,    79,    80,    47,    85,    52,    75,
      52,    52,    51,    24,    48,    48,    38,    49,    49,    49,
      85,    48,    48,    81,    81,    83,    83,    82,    82,    82,
      82,    84,    84,    47,    24,    23,    48,    50,    71,    76,
      76,    80,    80,    85,    85,    50,    84,    48,    79,    80,
      38,    52,     9,    24,    50,    50,    50,    48,    80,    76,
      80,    38,    24,    24,    80,    80,    24,    48,    80,    76,
      24,    80,    48,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 166 "tjc.y"
    {
        expTree = classDecl;
    }
    break;

  case 3:
#line 172 "tjc.y"
    {
        classDecl = new ClassDeclaration(yylineno, (yyvsp[(3) - (3)].sval));
    }
    break;

  case 5:
#line 179 "tjc.y"
    {
        (yyval.vdval) = new vector<Declaration*>();
        (yyval.vdval)->push_back((yyvsp[(1) - (1)].dval));
    }
    break;

  case 6:
#line 185 "tjc.y"
    {
        (yyval.vdval) = (yyvsp[(2) - (2)].vdval);
        (yyval.vdval)->push_back((yyvsp[(1) - (2)].dval));
    }
    break;

  case 7:
#line 192 "tjc.y"
    {
        (yyval.dval) = (yyvsp[(1) - (1)].dval);
    }
    break;

  case 8:
#line 197 "tjc.y"
    {
        (yyval.dval) = (yyvsp[(1) - (1)].dval);
    }
    break;

  case 9:
#line 203 "tjc.y"
    {
        classDecl->addMember(new FieldDeclaration(yylineno, (yyvsp[(3) - (6)].sval), (yyvsp[(2) - (6)].ival), (yyvsp[(5) - (6)].lxval)));
    }
    break;

  case 10:
#line 209 "tjc.y"
    {
        methodDecl = new MethodDeclaration(yylineno, (yyvsp[(3) - (4)].sval), (yyvsp[(2) - (4)].ival));
        classDecl->addMember(methodDecl);
    }
    break;

  case 11:
#line 214 "tjc.y"
    {
        methodDecl->setParameters((yyvsp[(6) - (7)].vdval));
    }
    break;

  case 13:
#line 220 "tjc.y"
    {
        methodDecl = new MethodDeclaration(yylineno, (yyvsp[(3) - (4)].sval), AstNode::TVOID);
        classDecl->addMember(methodDecl);
    }
    break;

  case 14:
#line 225 "tjc.y"
    {
        methodDecl->setParameters((yyvsp[(6) - (7)].vdval));
    }
    break;

  case 16:
#line 231 "tjc.y"
    {
        methodDecl = new MethodDeclaration(yylineno, (yyvsp[(3) - (5)].sval), (yyvsp[(2) - (5)].ival));
        classDecl->addMember(methodDecl);
    }
    break;

  case 18:
#line 238 "tjc.y"
    {
        methodDecl = new MethodDeclaration(yylineno, (yyvsp[(3) - (5)].sval), AstNode::TVOID);
        classDecl->addMember(methodDecl);
    }
    break;

  case 20:
#line 245 "tjc.y"
    {
        ParameterDeclaration *pd = NULL;
        if(strcmp((yyvsp[(6) - (10)].sval), "String") == 0)
        {
            pd = new ParameterDeclaration(yylineno, (yyvsp[(9) - (10)].sval), AstNode::TSTRINGA);
        }
        else
        {
            pd = new ParameterDeclaration(yylineno, (yyvsp[(9) - (10)].sval), 0);
        }
        vector<Declaration*> *pv = new vector<Declaration*>();
        pv->push_back(pd);
        methodDecl = new MethodDeclaration(yylineno, (yyvsp[(4) - (10)].sval), AstNode::TVOID);
        methodDecl->setParameters(pv);
        methodDecl->setPublicMethod(true);
        classDecl->addMember(methodDecl);
    }
    break;

  case 22:
#line 266 "tjc.y"
    {
        (yyval.ival) = AstNode::TINT;
    }
    break;

  case 23:
#line 271 "tjc.y"
    {
        (yyval.ival) = AstNode::TINTA;
    }
    break;

  case 24:
#line 276 "tjc.y"
    {
        (yyval.ival) = AstNode::TFLOAT;
    }
    break;

  case 25:
#line 281 "tjc.y"
    {
        (yyval.ival) = AstNode::TFLOATA;
    }
    break;

  case 26:
#line 287 "tjc.y"
    {
        (yyval.vdval) = new vector<Declaration*>();
        (yyval.vdval)->push_back((yyvsp[(1) - (1)].dval));
    }
    break;

  case 27:
#line 293 "tjc.y"
    {
        (yyval.vdval) = (yyvsp[(3) - (3)].vdval);
        (yyval.vdval)->insert((yyval.vdval)->begin(), (yyvsp[(1) - (3)].dval));
    }
    break;

  case 28:
#line 300 "tjc.y"
    {
        (yyval.dval) = new ParameterDeclaration(yylineno, (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].ival));
    }
    break;

  case 29:
#line 306 "tjc.y"
    {
        methodDecl->setVariables((yyvsp[(1) - (2)].vdval));
        methodDecl->setBody((yyvsp[(2) - (2)].bval));
    }
    break;

  case 30:
#line 313 "tjc.y"
    {
        (yyval.vdval) = (yyvsp[(2) - (2)].vdval);
        (yyval.vdval)->push_back((yyvsp[(1) - (2)].dval));
    }
    break;

  case 31:
#line 319 "tjc.y"
    {
        (yyval.vdval) = new vector<Declaration*>();
    }
    break;

  case 32:
#line 325 "tjc.y"
    {
        (yyval.dval) = new VariableDeclaration(yylineno, (yyvsp[(2) - (5)].sval), (yyvsp[(1) - (5)].ival), (yyvsp[(4) - (5)].lxval));
    }
    break;

  case 33:
#line 331 "tjc.y"
    {
        (yyval.bval) = (yyvsp[(2) - (2)].bval);
        (yyval.bval)->prependStatement((yyvsp[(1) - (2)].tval));
    }
    break;

  case 34:
#line 337 "tjc.y"
    {
        (yyval.bval) = new BlockStatement(yylineno);
        (yyval.bval)->prependStatement((yyvsp[(1) - (1)].tval));
    }
    break;

  case 35:
#line 344 "tjc.y"
    {
        (yyval.bval) = (yyvsp[(2) - (2)].bval);
        (yyval.bval)->prependStatement((yyvsp[(1) - (2)].tval));
    }
    break;

  case 36:
#line 350 "tjc.y"
    {
        (yyval.bval) = new BlockStatement(yylineno);
    }
    break;

  case 37:
#line 356 "tjc.y"
    {
        (yyval.tval) = new AssignStatement(yylineno, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].xval));
    }
    break;

  case 38:
#line 361 "tjc.y"
    {
        (yyval.tval) = new AssignStatement(yylineno, (yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].xval), (yyvsp[(6) - (7)].xval));
    }
    break;

  case 39:
#line 366 "tjc.y"
    {
        (yyval.tval) = new IfStatement(yylineno, (yyvsp[(3) - (5)].xval), (yyvsp[(5) - (5)].tval), NULL);
    }
    break;

  case 40:
#line 371 "tjc.y"
    {
        (yyval.tval) = new IfStatement(yylineno, (yyvsp[(3) - (7)].xval), (yyvsp[(5) - (7)].tval), (yyvsp[(7) - (7)].tval));
    }
    break;

  case 41:
#line 376 "tjc.y"
    {
        (yyval.tval) = new WhileStatement(yylineno, (yyvsp[(3) - (5)].xval), (yyvsp[(5) - (5)].tval));
    }
    break;

  case 42:
#line 381 "tjc.y"
    {
        (yyval.tval) = new ForStatement(yylineno, (yyvsp[(3) - (11)].sval), (yyvsp[(5) - (11)].xval), (yyvsp[(7) - (11)].xval), (yyvsp[(9) - (11)].xval), (yyvsp[(11) - (11)].tval));
    }
    break;

  case 43:
#line 386 "tjc.y"
    {
        (yyval.tval) = new ForStatement(yylineno, (yyvsp[(3) - (14)].sval), (yyvsp[(5) - (14)].xval), (yyvsp[(8) - (14)].xval), (yyvsp[(10) - (14)].xval), (yyvsp[(12) - (14)].xval), (yyvsp[(14) - (14)].tval));
    }
    break;

  case 44:
#line 391 "tjc.y"
    {
        (yyval.tval) = new MethodCallStatement(yylineno, (yyvsp[(1) - (2)].xval));
    }
    break;

  case 45:
#line 396 "tjc.y"
    {
        (yyval.tval) = (yyvsp[(2) - (3)].bval);
    }
    break;

  case 46:
#line 401 "tjc.y"
    {
        (yyval.tval) = new EmptyStatement(yylineno);
    }
    break;

  case 47:
#line 407 "tjc.y"
    {
        (yyval.tval) = new ReturnStatement(yylineno, e, (yyvsp[(2) - (3)].xval));
    }
    break;

  case 48:
#line 412 "tjc.y"
    {
        (yyval.tval) = new ReturnStatement(yylineno, e, NULL);
    }
    break;

  case 49:
#line 418 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(3) - (6)].sval));
        (yyval.xval) = new MethodCallExpression(yylineno, (yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].vxval));
    }
    break;

  case 50:
#line 424 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(1) - (4)].sval));
        (yyval.xval) = new MethodCallExpression(yylineno, NULL, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].vxval));
    }
    break;

  case 51:
#line 430 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(3) - (5)].sval));
        (yyval.xval) = new MethodCallExpression(yylineno, (yyvsp[(1) - (5)].sval), (yyvsp[(3) - (5)].sval), (vector<Expression *> *) NULL);
    }
    break;

  case 52:
#line 436 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(1) - (3)].sval));
        (yyval.xval) = new MethodCallExpression(yylineno, NULL, (yyvsp[(1) - (3)].sval), (vector<Expression *> *) NULL);
    }
    break;

  case 53:
#line 443 "tjc.y"
    {
        (yyval.vxval) = new vector<Expression *>();
        (yyval.vxval)->push_back((yyvsp[(1) - (1)].xval));
    }
    break;

  case 54:
#line 449 "tjc.y"
    {
        (yyval.vxval) = (yyvsp[(1) - (3)].vxval);
        (yyval.vxval)->push_back((yyvsp[(3) - (3)].xval));
    }
    break;

  case 55:
#line 456 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 56:
#line 461 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::EQOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 57:
#line 466 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::NEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 58:
#line 472 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 59:
#line 477 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::LTOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 60:
#line 482 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::GTOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 61:
#line 487 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::LEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 62:
#line 492 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::GEOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 63:
#line 498 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 64:
#line 503 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::ADDOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 65:
#line 508 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::SUBOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 66:
#line 514 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 67:
#line 519 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::MULOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 68:
#line 524 "tjc.y"
    {
        (yyval.xval) = new BinaryExpression(yylineno, AstNode::DIVOP, (yyvsp[(1) - (3)].xval), (yyvsp[(3) - (3)].xval));
    }
    break;

  case 69:
#line 530 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 70:
#line 535 "tjc.y"
    {
        (yyval.xval) = new UnaryExpression(yylineno, AstNode::INCOP, (yyvsp[(1) - (2)].xval), true);
    }
    break;

  case 71:
#line 540 "tjc.y"
    {
        (yyval.xval) = new UnaryExpression(yylineno, AstNode::DECOP, (yyvsp[(1) - (2)].xval), true);
    }
    break;

  case 72:
#line 545 "tjc.y"
    {
        (yyval.xval) = new UnaryExpression(yylineno, AstNode::ADDOP, (yyvsp[(2) - (2)].xval));
    }
    break;

  case 73:
#line 550 "tjc.y"
    {
        (yyval.xval) = new UnaryExpression(yylineno, AstNode::SUBOP, (yyvsp[(2) - (2)].xval));
    }
    break;

  case 74:
#line 555 "tjc.y"
    {
        (yyval.xval) = new CastExpression(yylineno, (yyvsp[(2) - (4)].ival), (yyvsp[(4) - (4)].xval));
    }
    break;

  case 75:
#line 561 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].lxval);
    }
    break;

  case 76:
#line 566 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(1) - (1)].sval));
        (yyval.xval) = new ReferenceExpression(yylineno, (yyvsp[(1) - (1)].sval));
    }
    break;

  case 77:
#line 572 "tjc.y"
    {
        e = new ReturnEntry((yyvsp[(1) - (4)].sval));
        (yyval.xval) = new ReferenceExpression(yylineno, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].xval));
    }
    break;

  case 78:
#line 578 "tjc.y"
    {
        (yyval.xval) = new NewExpression(yylineno, AstNode::TINTA, (yyvsp[(4) - (5)].xval));
    }
    break;

  case 79:
#line 583 "tjc.y"
    {
        (yyval.xval) = new NewExpression(yylineno, AstNode::TFLOATA, (yyvsp[(4) - (5)].xval));
    }
    break;

  case 80:
#line 588 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(1) - (1)].xval);
    }
    break;

  case 81:
#line 593 "tjc.y"
    {
        (yyval.xval) = (yyvsp[(2) - (3)].xval);
    }
    break;

  case 82:
#line 599 "tjc.y"
    {
        (yyval.lxval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TINT);
    }
    break;

  case 83:
#line 604 "tjc.y"
    {
        (yyval.lxval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TFLOAT);
    }
    break;

  case 84:
#line 609 "tjc.y"
    {
        (yyval.lxval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TSTRING);
    }
    break;

  case 85:
#line 614 "tjc.y"
    {
        (yyval.lxval) = new LiteralExpression(yylineno, (yyvsp[(1) - (1)].sval), AstNode::TREF);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2242 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 622 "tjc.y"



/*void
yyerror(const char *msg)
{
    printf("Line %d: %s\n", yylineno, msg);
    yyclearin;
    yyerrok;
}*/

int
yyerror(const char *msg)
{
    cerr << "Line: " << yylineno << ": " << msg << endl;
    cerr.flush();
    yyclearin;
    yyerrok;
}
