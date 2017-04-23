/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 168 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

