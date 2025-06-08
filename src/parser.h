/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EVALEX = 258,                  /* EVALEX  */
    SCRIPT = 259,                  /* SCRIPT  */
    INFIXL = 260,                  /* INFIXL  */
    INFIXR = 261,                  /* INFIXR  */
    INFIX = 262,                   /* INFIX  */
    FUNARROW = 263,                /* FUNARROW  */
    UPTO = 264,                    /* UPTO  */
    CASEXP = 265,                  /* CASEXP  */
    OF = 266,                      /* OF  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    ELSE = 269,                    /* ELSE  */
    WHERE = 270,                   /* WHERE  */
    TYPE = 271,                    /* TYPE  */
    DATA = 272,                    /* DATA  */
    FROM = 273,                    /* FROM  */
    LET = 274,                     /* LET  */
    IN = 275,                      /* IN  */
    VAROP = 276,                   /* VAROP  */
    VARID = 277,                   /* VARID  */
    NUMLIT = 278,                  /* NUMLIT  */
    CHARLIT = 279,                 /* CHARLIT  */
    STRINGLIT = 280,               /* STRINGLIT  */
    REPEAT = 281,                  /* REPEAT  */
    CONOP = 282,                   /* CONOP  */
    CONID = 283,                   /* CONID  */
    TCLASS = 284,                  /* TCLASS  */
    IMPLIES = 285,                 /* IMPLIES  */
    TINSTANCE = 286,               /* TINSTANCE  */
    DO = 287,                      /* DO  */
    TRUNST = 288,                  /* TRUNST  */
    PRIMITIVE = 289,               /* PRIMITIVE  */
    DEFAULT = 290,                 /* DEFAULT  */
    DERIVING = 291,                /* DERIVING  */
    HIDING = 292,                  /* HIDING  */
    IMPORT = 293,                  /* IMPORT  */
    INTERFACE = 294,               /* INTERFACE  */
    MODULE = 295,                  /* MODULE  */
    RENAMING = 296,                /* RENAMING  */
    TO = 297,                      /* TO  */
    CTYPE = 298                    /* CTYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define EVALEX 258
#define SCRIPT 259
#define INFIXL 260
#define INFIXR 261
#define INFIX 262
#define FUNARROW 263
#define UPTO 264
#define CASEXP 265
#define OF 266
#define IF 267
#define THEN 268
#define ELSE 269
#define WHERE 270
#define TYPE 271
#define DATA 272
#define FROM 273
#define LET 274
#define IN 275
#define VAROP 276
#define VARID 277
#define NUMLIT 278
#define CHARLIT 279
#define STRINGLIT 280
#define REPEAT 281
#define CONOP 282
#define CONID 283
#define TCLASS 284
#define IMPLIES 285
#define TINSTANCE 286
#define DO 287
#define TRUNST 288
#define PRIMITIVE 289
#define DEFAULT 290
#define DERIVING 291
#define HIDING 292
#define IMPORT 293
#define INTERFACE 294
#define MODULE 295
#define RENAMING 296
#define TO 297
#define CTYPE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
