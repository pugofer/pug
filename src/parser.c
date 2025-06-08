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
#line 18 "parser.y"

#ifndef lint
#define lint
#endif

#include "prelude.h"
#include "storage.h"
#include "connect.h"
#include "command.h"
#include "errors.h"
#include "input.h"
#include "parser.h"
#include <ctype.h>

#define defTycon(n,l,lhs,rhs,w)	 tyconDefn(intOf(l),lhs,rhs,w); sp-=n
#define sigdecl(l,vs,t)		 ap(SIGDECL,triple(l,vs,t))
#define grded(gs)		 ap(GUARDED,gs)
#define letrec(bs,e)		 (nonNull(bs) ? ap(LETREC,pair(bs,e)) : e)
#define yyerror(s)		 /* errors handled elsewhere */
#define YYSTYPE			 Cell

/*RPM*/
#define opap(lArg,op,rArg) (ap2(op,lArg,rArg))
#define opapd(lArg,op,rArg) (newSyntax && isDot(op) ? ap(lArg,rArg) :\
		    opap(lArg,op,rArg))
static Void local typeSyntaxChk(String context, Cell token);
static Cell local ct1Const(int line, Cell type, Cell conid);
static Cell local ct1Clause(int line, Cell type, Cell conids);
static Bool local tEquals(int line, Cell t1, Cell t2);
static Bool local isArrow(Cell x);
/*RPM*/

static Cell   local gcShadow     Args((Int,Cell));
Void   syntaxError  Args((String));
static String local unexpected   Args((Void));
static Cell   local checkPrec    Args((Cell));
static Void   local fixDefn      Args((Syntax,Cell,Cell,List));
static Void   local setSyntax    Args((Int,Syntax,Cell));
static Cell   local buildTuple   Args((List));
static Cell   local checkClass   Args((Cell));
static List   local checkContext Args((List));
static Pair   local checkDo	 Args((List));
static Cell   local checkTyLhs	 Args((Cell));
static Cell   local oTidyInfix    Args((Cell));
static Cell   local nTidyInfix    Args((Cell));
static Cell   local (*tidyInfix[2]) Args((Cell)) = {oTidyInfix, nTidyInfix};

/* For the purposes of reasonably portable garbage collection, it is
 * necessary to simulate the YACC stack on the Gofer stack to keep
 * track of all intermediate constructs.  The lexical analyser
 * pushes a token onto the stack for each token that is found, with
 * these elements being removed as reduce actions are performed,
 * taking account of look-ahead tokens as described by gcShadow()
 * below.
 *
 * Of the non-terminals used below, only start, topDecl & begin do not leave
 * any values on the Gofer stack.  The same is true for the terminals
 * EVALEX and SCRIPT.  At the end of a successful parse, there should only
 * be one element left on the stack, containing the result of the parse.
 */

#define gc0(e)			 gcShadow(0,e)
#define gc1(e)			 gcShadow(1,e)
#define gc2(e)			 gcShadow(2,e)
#define gc3(e)			 gcShadow(3,e)
#define gc4(e)			 gcShadow(4,e)
#define gc5(e)			 gcShadow(5,e)
#define gc6(e)			 gcShadow(6,e)
#define gc7(e)			 gcShadow(7,e)


#line 143 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EVALEX = 3,                     /* EVALEX  */
  YYSYMBOL_SCRIPT = 4,                     /* SCRIPT  */
  YYSYMBOL_5_ = 5,                         /* '='  */
  YYSYMBOL_INFIXL = 6,                     /* INFIXL  */
  YYSYMBOL_INFIXR = 7,                     /* INFIXR  */
  YYSYMBOL_INFIX = 8,                      /* INFIX  */
  YYSYMBOL_FUNARROW = 9,                   /* FUNARROW  */
  YYSYMBOL_10_ = 10,                       /* '-'  */
  YYSYMBOL_11_ = 11,                       /* ','  */
  YYSYMBOL_12_ = 12,                       /* '@'  */
  YYSYMBOL_13_ = 13,                       /* '('  */
  YYSYMBOL_14_ = 14,                       /* ')'  */
  YYSYMBOL_15_ = 15,                       /* '|'  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_UPTO = 17,                      /* UPTO  */
  YYSYMBOL_18_ = 18,                       /* '['  */
  YYSYMBOL_19_ = 19,                       /* ']'  */
  YYSYMBOL_CASEXP = 20,                    /* CASEXP  */
  YYSYMBOL_OF = 21,                        /* OF  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_WHERE = 25,                     /* WHERE  */
  YYSYMBOL_TYPE = 26,                      /* TYPE  */
  YYSYMBOL_DATA = 27,                      /* DATA  */
  YYSYMBOL_FROM = 28,                      /* FROM  */
  YYSYMBOL_29_ = 29,                       /* '\\'  */
  YYSYMBOL_30_ = 30,                       /* '~'  */
  YYSYMBOL_LET = 31,                       /* LET  */
  YYSYMBOL_IN = 32,                        /* IN  */
  YYSYMBOL_33_ = 33,                       /* '`'  */
  YYSYMBOL_VAROP = 34,                     /* VAROP  */
  YYSYMBOL_VARID = 35,                     /* VARID  */
  YYSYMBOL_NUMLIT = 36,                    /* NUMLIT  */
  YYSYMBOL_CHARLIT = 37,                   /* CHARLIT  */
  YYSYMBOL_STRINGLIT = 38,                 /* STRINGLIT  */
  YYSYMBOL_REPEAT = 39,                    /* REPEAT  */
  YYSYMBOL_CONOP = 40,                     /* CONOP  */
  YYSYMBOL_CONID = 41,                     /* CONID  */
  YYSYMBOL_TCLASS = 42,                    /* TCLASS  */
  YYSYMBOL_IMPLIES = 43,                   /* IMPLIES  */
  YYSYMBOL_TINSTANCE = 44,                 /* TINSTANCE  */
  YYSYMBOL_DO = 45,                        /* DO  */
  YYSYMBOL_TRUNST = 46,                    /* TRUNST  */
  YYSYMBOL_PRIMITIVE = 47,                 /* PRIMITIVE  */
  YYSYMBOL_DEFAULT = 48,                   /* DEFAULT  */
  YYSYMBOL_DERIVING = 49,                  /* DERIVING  */
  YYSYMBOL_HIDING = 50,                    /* HIDING  */
  YYSYMBOL_IMPORT = 51,                    /* IMPORT  */
  YYSYMBOL_INTERFACE = 52,                 /* INTERFACE  */
  YYSYMBOL_MODULE = 53,                    /* MODULE  */
  YYSYMBOL_RENAMING = 54,                  /* RENAMING  */
  YYSYMBOL_TO = 55,                        /* TO  */
  YYSYMBOL_CTYPE = 56,                     /* CTYPE  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59___ = 59,                     /* '_'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_start = 62,                     /* start  */
  YYSYMBOL_topModule = 63,                 /* topModule  */
  YYSYMBOL_begin = 64,                     /* begin  */
  YYSYMBOL_topDecls = 65,                  /* topDecls  */
  YYSYMBOL_ctDecls = 66,                   /* ctDecls  */
  YYSYMBOL_ctDecl = 67,                    /* ctDecl  */
  YYSYMBOL_conids = 68,                    /* conids  */
  YYSYMBOL_pvarop = 69,                    /* pvarop  */
  YYSYMBOL_topDecl = 70,                   /* topDecl  */
  YYSYMBOL_71_1 = 71,                      /* $@1  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_typeLhs = 73,                   /* typeLhs  */
  YYSYMBOL_invars = 74,                    /* invars  */
  YYSYMBOL_rsvars = 75,                    /* rsvars  */
  YYSYMBOL_rsvar = 76,                     /* rsvar  */
  YYSYMBOL_constrs = 77,                   /* constrs  */
  YYSYMBOL_constr = 78,                    /* constr  */
  YYSYMBOL_deriving = 79,                  /* deriving  */
  YYSYMBOL_derivs0 = 80,                   /* derivs0  */
  YYSYMBOL_derivs = 81,                    /* derivs  */
  YYSYMBOL_sigType = 82,                   /* sigType  */
  YYSYMBOL_context = 83,                   /* context  */
  YYSYMBOL_type = 84,                      /* type  */
  YYSYMBOL_ctype = 85,                     /* ctype  */
  YYSYMBOL_atype = 86,                     /* atype  */
  YYSYMBOL_tupCommas = 87,                 /* tupCommas  */
  YYSYMBOL_typeTuple = 88,                 /* typeTuple  */
  YYSYMBOL_optdigit = 89,                  /* optdigit  */
  YYSYMBOL_ops = 90,                       /* ops  */
  YYSYMBOL_op = 91,                        /* op  */
  YYSYMBOL_varop = 92,                     /* varop  */
  YYSYMBOL_conop = 93,                     /* conop  */
  YYSYMBOL_prims = 94,                     /* prims  */
  YYSYMBOL_prim = 95,                      /* prim  */
  YYSYMBOL_classHead = 96,                 /* classHead  */
  YYSYMBOL_classBody = 97,                 /* classBody  */
  YYSYMBOL_instBody = 98,                  /* instBody  */
  YYSYMBOL_csigdecls = 99,                 /* csigdecls  */
  YYSYMBOL_csigdecl = 100,                 /* csigdecl  */
  YYSYMBOL_decl = 101,                     /* decl  */
  YYSYMBOL_decls = 102,                    /* decls  */
  YYSYMBOL_rhs = 103,                      /* rhs  */
  YYSYMBOL_rhs1 = 104,                     /* rhs1  */
  YYSYMBOL_wherePart = 105,                /* wherePart  */
  YYSYMBOL_gdefs = 106,                    /* gdefs  */
  YYSYMBOL_gdef = 107,                     /* gdef  */
  YYSYMBOL_vars = 108,                     /* vars  */
  YYSYMBOL_var = 109,                      /* var  */
  YYSYMBOL_varid = 110,                    /* varid  */
  YYSYMBOL_conid = 111,                    /* conid  */
  YYSYMBOL_exp = 112,                      /* exp  */
  YYSYMBOL_opExp = 113,                    /* opExp  */
  YYSYMBOL_opExp0 = 114,                   /* opExp0  */
  YYSYMBOL_pfxExp = 115,                   /* pfxExp  */
  YYSYMBOL_pats = 116,                     /* pats  */
  YYSYMBOL_appExp = 117,                   /* appExp  */
  YYSYMBOL_atomic = 118,                   /* atomic  */
  YYSYMBOL_exps2 = 119,                    /* exps2  */
  YYSYMBOL_alts = 120,                     /* alts  */
  YYSYMBOL_alt = 121,                      /* alt  */
  YYSYMBOL_altRhs = 122,                   /* altRhs  */
  YYSYMBOL_altRhs1 = 123,                  /* altRhs1  */
  YYSYMBOL_guardAlts = 124,                /* guardAlts  */
  YYSYMBOL_guardAlt = 125,                 /* guardAlt  */
  YYSYMBOL_list = 126,                     /* list  */
  YYSYMBOL_quals = 127,                    /* quals  */
  YYSYMBOL_qual = 128,                     /* qual  */
  YYSYMBOL_close = 129,                    /* close  */
  YYSYMBOL_close1 = 130                    /* close1  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      13,    14,     2,     2,    11,    10,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    16,
       2,     5,     2,     2,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,    29,    19,     2,    59,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    15,    60,    30,     2,     2,     2,
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
       6,     7,     8,     9,    17,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   110,   111,   112,   125,   128,   130,   131,
     132,   133,   134,   138,   139,   141,   143,   144,   147,   148,
     151,   151,   153,   153,   157,   158,   161,   167,   170,   171,
     173,   174,   176,   177,   179,   181,   183,   184,   186,   187,
     190,   192,   193,   194,   196,   197,   199,   200,   211,   212,
     214,   216,   217,   218,   220,   224,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   237,   238,   241,   242,
     247,   248,   249,   251,   252,   254,   255,   257,   258,   259,
     261,   262,   264,   265,   270,   272,   273,   274,   276,   281,
     282,   283,   285,   286,   288,   289,   291,   292,   294,   295,
     297,   298,   303,   304,   306,   307,   309,   310,   311,   313,
     314,   316,   318,   319,   321,   328,   329,   331,   332,   334,
     335,   337,   338,   340,   341,   346,   347,   348,   350,   351,
     353,   355,   356,   359,   364,   367,   368,   369,   370,   372,
     373,   375,   385,   386,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     405,   406,   408,   409,   411,   413,   414,   416,   417,   418,
     420,   421,   423,   428,   429,   430,   431,   432,   433,   434,
     435,   438,   439,   441,   442,   446,   447,   473,   474,   476,
     477
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
  "\"end of file\"", "error", "\"invalid token\"", "EVALEX", "SCRIPT",
  "'='", "INFIXL", "INFIXR", "INFIX", "FUNARROW", "'-'", "','", "'@'",
  "'('", "')'", "'|'", "';'", "UPTO", "'['", "']'", "CASEXP", "OF", "IF",
  "THEN", "ELSE", "WHERE", "TYPE", "DATA", "FROM", "'\\\\'", "'~'", "LET",
  "IN", "'`'", "VAROP", "VARID", "NUMLIT", "CHARLIT", "STRINGLIT",
  "REPEAT", "CONOP", "CONID", "TCLASS", "IMPLIES", "TINSTANCE", "DO",
  "TRUNST", "PRIMITIVE", "DEFAULT", "DERIVING", "HIDING", "IMPORT",
  "INTERFACE", "MODULE", "RENAMING", "TO", "CTYPE", "':'", "'{'", "'_'",
  "'}'", "$accept", "start", "topModule", "begin", "topDecls", "ctDecls",
  "ctDecl", "conids", "pvarop", "topDecl", "$@1", "$@2", "typeLhs",
  "invars", "rsvars", "rsvar", "constrs", "constr", "deriving", "derivs0",
  "derivs", "sigType", "context", "type", "ctype", "atype", "tupCommas",
  "typeTuple", "optdigit", "ops", "op", "varop", "conop", "prims", "prim",
  "classHead", "classBody", "instBody", "csigdecls", "csigdecl", "decl",
  "decls", "rhs", "rhs1", "wherePart", "gdefs", "gdef", "vars", "var",
  "varid", "conid", "exp", "opExp", "opExp0", "pfxExp", "pats", "appExp",
  "atomic", "exps2", "alts", "alt", "altRhs", "altRhs1", "guardAlts",
  "guardAlt", "list", "quals", "qual", "close", "close1", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-180)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     233,  -272,   566,   122,   145,  -272,   743,   428,   470,   566,
     566,   758,   758,    78,  -272,  -272,  -272,  -272,  -272,  -272,
     758,  -272,   150,  -272,  -272,   154,   107,    84,    84,   758,
    -272,  -272,  -272,   384,  -272,   758,   139,  -272,    71,   188,
     204,   758,   758,   186,    84,   202,    39,   238,   244,   240,
     246,   173,  -272,  -272,   728,  -272,   758,   207,  -272,   273,
    -272,  -272,  -272,   728,  -272,  -272,   728,  -272,  -272,   232,
     232,   232,    29,   273,   273,   273,    50,   273,   273,    17,
    -272,  -272,    10,     8,   104,  -272,   234,   237,  -272,  -272,
     261,   262,   566,  -272,   696,   566,  -272,   566,   598,   502,
    -272,   227,   566,   566,  -272,  -272,    22,  -272,   728,  -272,
     438,   704,  -272,  -272,  -272,   247,   251,   463,  -272,  -272,
      84,  -272,    84,    84,    84,  -272,  -272,    47,   253,   282,
     254,   251,   264,   274,  -272,    76,    23,  -272,   268,  -272,
     266,   251,  -272,   297,  -272,  -272,  -272,    40,   273,  -272,
     566,   566,  -272,   154,   136,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,   294,   255,   103,   301,  -272,  -272,   728,
     292,  -272,   242,   286,    22,   306,  -272,  -272,   224,   219,
     231,   245,  -272,   302,   273,   273,  -272,   152,   728,   314,
    -272,   314,   314,   273,   295,    29,   368,   273,   271,  -272,
     279,  -272,   317,   188,    40,   273,  -272,    29,   315,  -272,
    -272,  -272,  -272,  -272,   335,   342,  -272,   566,  -272,   534,
     728,   566,   566,   598,   180,    27,  -272,   566,  -272,   566,
    -272,  -272,   273,  -272,   119,  -272,  -272,   273,  -272,  -272,
    -272,  -272,  -272,  -272,    84,   316,  -272,    69,    15,    34,
    -272,   123,  -272,   630,   728,  -272,  -272,   100,   291,   662,
     566,   335,  -272,    22,  -272,  -272,  -272,  -272,   566,   728,
    -272,   154,   337,  -272,   242,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,    40,  -272,   368,   368,    18,  -272,   309,   273,
    -272,    31,  -272,  -272,    22,   330,    55,   566,  -272,  -272,
     286,  -272,   349,  -272,  -272,  -272,   351,  -272,   303,    34,
    -272,   323,  -272,  -272,   341,  -272,  -272,   307,   326,    44,
    -272,    35,  -272,   246,   566,    40,   273,  -272,  -272,   353,
     357,  -272,  -272,    55,   204,    28,  -272,    55,   273,  -272,
    -272,  -272,  -272,   332,    44,  -272,  -272,  -272,  -272,  -272
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   150,   151,   152,   153,   123,
       0,   147,   144,   119,   148,     2,   126,   130,   128,   138,
     143,     7,     4,     0,     1,   133,     0,   149,     0,    80,
      82,     0,     0,     0,   128,     0,   174,   175,     0,     0,
       0,     0,   140,   146,     0,   142,     0,     0,     3,     0,
      79,    80,    82,     0,    77,    78,     0,   141,    12,    74,
      74,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,   144,     0,   120,     0,     0,   122,   124,
       0,     0,     0,   154,     0,     0,   155,     0,     0,     0,
     156,     0,     0,     0,   139,   105,     0,   145,     0,    53,
       0,     0,    56,    57,   125,     0,    49,    51,    55,   131,
     129,    73,     0,     0,     0,    29,    28,    19,     0,    50,
       0,    93,    95,    97,    87,     0,     0,    86,     0,    91,
       0,    20,   190,     0,   189,     6,   188,     0,     0,   108,
       0,     0,   103,   107,   110,   113,    81,    83,   158,   159,
     161,   157,   160,   161,     0,   185,   176,   182,   177,     0,
       0,   134,     0,     0,     0,     0,    67,    58,     0,    19,
       0,     0,    65,     0,     0,     0,    18,     0,     0,    70,
      76,    71,    72,     0,     0,     0,     0,     0,     0,    89,
       0,    90,     0,     0,     0,     0,    88,     0,     0,     8,
       9,   187,   117,   102,   109,     0,   106,     0,   112,     0,
       0,     0,     0,     0,     0,     0,   163,     0,   104,     0,
     111,    59,     0,    60,     0,    66,    62,     0,    63,    64,
      48,    52,    54,   132,     0,    31,    27,    19,    40,    41,
      37,    39,    92,     0,     0,    85,    84,    19,     0,     0,
       0,     0,   180,     0,   184,   183,   181,   169,     0,     0,
     164,   166,   167,   171,     0,   137,   136,   135,    69,    61,
      68,    75,     0,    24,     0,     0,     0,    25,     0,     0,
     101,     0,    99,   100,     0,     0,     0,     0,   116,   114,
     186,   168,     0,   165,   170,   162,    30,    33,    35,    41,
      36,    44,    42,    38,     0,    94,    96,     0,     0,     0,
      14,     0,    17,   115,     0,     0,     0,    26,    47,     0,
      45,   101,    98,     0,     0,     0,    21,     0,     0,   172,
      32,    34,    43,     0,     0,    13,    16,    15,    46,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,  -272,  -272,  -272,  -272,    41,    48,  -272,  -100,   241,
    -272,  -272,   -81,  -272,  -272,    63,    91,   108,    80,  -272,
    -272,  -134,    93,   -38,   285,   209,  -272,  -272,   170,    83,
     -18,   391,    -3,  -272,   195,   333,  -272,  -272,  -272,    98,
     -22,   -93,  -272,  -272,  -141,  -272,   263,  -272,   -32,  -272,
    -271,    -2,   -30,  -272,    -5,  -272,    21,    87,   397,  -272,
     133,  -272,  -272,  -272,   144,  -272,  -272,   201,   -90,  -130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,    32,    33,    79,   319,   320,   321,   194,    80,
     208,   295,   127,   283,   306,   307,   249,   250,   287,   329,
     330,   114,   115,   116,   117,   118,   180,   181,   122,   189,
     190,    64,    65,   136,   137,   132,   199,   201,   291,   292,
     105,   106,   152,   153,    58,   154,   155,    82,    22,    23,
      24,   165,    26,    27,    28,    51,    29,    30,    45,   225,
     226,   270,   271,   272,   273,    48,   166,   167,   145,   146
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    83,    44,    84,    42,    43,    46,    49,    50,    63,
      66,    81,   216,   211,   213,   174,   173,   187,   142,  -118,
      56,   147,    83,   142,    84,   322,    94,    35,   142,   142,
     125,   311,   142,   143,   204,   129,   131,   131,   172,   139,
     141,   318,   211,   274,   138,   142,   337,   314,   -53,   285,
      97,   134,   193,   135,    98,   -53,    99,    35,   119,   312,
     335,   120,   322,   135,   322,  -118,   346,   148,   318,    19,
     126,   256,   178,   183,   284,    14,    83,   144,    84,   187,
     205,   186,   144,   286,   230,    14,   202,   144,   144,   120,
     160,   144,   338,   162,    60,   163,    19,   168,    52,    53,
     170,   171,   188,   186,   144,   149,    86,    55,   221,   150,
     203,    83,    87,    84,   247,   212,    67,    38,    61,   151,
     109,   210,    67,    31,    62,   -22,   257,   263,    90,    91,
     303,   222,   110,   279,   186,   275,    54,   111,   104,   224,
      83,   217,    84,   107,   211,    34,   240,   241,   214,   215,
     228,   151,     7,    85,   112,   245,   288,     8,   251,   252,
     113,   294,    56,    62,    59,   110,   128,   130,   130,    12,
     111,   140,   138,   300,    14,    15,    16,    17,    18,    57,
      19,   267,   103,   243,   211,    20,     7,   112,    83,   268,
      84,     8,   341,   113,   278,   269,   241,    92,    21,   280,
      93,   315,    88,    12,   316,   211,   191,   192,    14,    15,
      16,    17,    18,    95,    19,   261,    96,   262,    89,   264,
     265,    83,    83,    84,    84,   276,   281,   277,   234,   336,
     -51,   293,    21,   -51,     1,   232,     2,     3,   233,   302,
     123,   124,   235,   142,   224,   236,   251,   251,   289,    95,
     308,   313,     6,   186,   349,     7,   237,   298,   299,   238,
       8,   101,     9,   100,    10,   108,   301,   156,   121,   102,
     157,    11,    12,    13,   109,   158,   159,    14,    15,    16,
      17,    18,    83,    19,    84,   169,   110,   196,    20,   198,
     184,   111,   293,   308,   -50,   323,   195,   197,   142,   200,
     347,    21,   144,    69,    70,    71,   206,     6,   112,   207,
       7,   219,   223,   220,   113,     8,   227,     9,   229,    10,
     231,   239,   339,    72,    73,   244,    11,    12,    13,   253,
     246,    85,    14,    15,    16,    17,    18,   254,    19,    74,
     258,    75,   331,    20,    76,    77,   259,   260,   282,   296,
      87,     6,   269,    78,     7,   317,    21,   144,   324,     8,
     326,     9,   325,    10,   328,   333,   334,   342,   343,   248,
      11,    12,    13,   348,   344,   309,    14,    15,    16,    17,
      18,   110,    19,   345,   209,    68,   111,    20,   340,   327,
      69,    70,    71,   310,     6,   179,   242,     7,    41,   255,
      21,   144,     8,   112,     9,    47,    10,   305,   133,   113,
      72,    73,   332,    11,    12,    13,   304,   218,     0,    14,
      15,    16,    17,    18,   266,    19,    74,     0,    75,     5,
      20,    76,    77,     0,     0,     0,     0,     0,    36,   109,
      78,     7,    37,    21,     0,     0,     8,   175,     9,   176,
      10,   110,   177,     0,     0,     0,   111,    11,    12,    13,
       0,    38,    39,    14,    15,    16,    17,    18,    40,    19,
       0,     5,   185,   112,    20,     0,   -19,     0,     0,   113,
       6,   -19,     0,     7,     0,     0,     0,    21,     8,  -173,
       9,     0,    10,     0,     0,     0,     0,   186,   -19,    11,
      12,    13,     0,     5,   -19,    14,    15,    16,    17,    18,
       0,    19,     6,     0,     0,     7,    20,     0,     0,     0,
       8,  -179,     9,     0,    10,     0,     0,     0,     0,    21,
       0,    11,    12,    13,     0,     5,     0,    14,    15,    16,
      17,    18,     0,    19,     6,     0,     0,     7,    20,     0,
       0,     0,     8,  -178,     9,     0,    10,     0,     0,     0,
       0,    21,     0,    11,    12,    13,     0,     5,     0,    14,
      15,    16,    17,    18,     0,    19,     6,     0,     0,     7,
      20,     0,     0,     0,     8,     0,     9,     0,    10,     0,
       0,     0,     0,    21,     0,    11,    12,    13,     0,     5,
       0,    14,    15,    16,    17,    18,     0,    19,     6,     0,
       0,     7,    20,     0,     0,     0,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    21,     0,    11,    12,   164,
       0,   290,     0,    14,    15,    16,    17,    18,     0,    19,
       6,     0,     0,     7,    20,     0,     0,     0,     8,     0,
       9,     0,    10,     0,     0,     0,     0,    21,     0,    11,
      12,    13,     0,     5,     0,    14,    15,    16,    17,    18,
       0,    19,     6,     0,     0,     7,    20,     0,     0,     0,
       8,     0,     9,     0,   297,     0,     0,     0,     0,    21,
       0,    11,    12,    13,     0,     0,     0,    14,    15,    16,
      17,    18,     0,    19,     0,   109,     6,     0,    20,     7,
     161,     0,     0,     0,     8,     0,     9,   110,    10,     0,
       0,    21,   111,   182,     0,    11,    12,    13,     0,     0,
       0,    14,    15,    16,    17,    18,     0,    19,     6,   112,
       0,     7,    20,     0,     0,   113,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    21,     7,    11,    12,    13,
       0,     8,     0,    14,    15,    16,    17,    18,     0,    19,
       0,     7,     0,    12,    20,     0,     8,     0,    14,    15,
      16,    17,    18,     0,    19,     0,     0,    21,    12,    20,
       0,     0,     0,    14,    15,    16,    17,    18,     0,    19,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
       2,    33,     7,    33,     7,     7,     8,     9,    10,    27,
      28,    33,   153,   143,   148,   108,   106,   117,     1,    11,
      12,    11,    54,     1,    54,   296,    44,     6,     1,     1,
       1,    13,     1,    16,    11,    73,    74,    75,    16,    77,
      78,    13,   172,    16,    76,     1,    11,    16,    33,    15,
      11,     1,     5,    13,    15,    40,    17,    36,    63,    41,
      16,    66,   333,    13,   335,    57,   337,    57,    13,    41,
      41,   205,   110,   111,     5,    35,   108,    60,   108,   179,
      57,    34,    60,    49,   174,    35,    10,    60,    60,    94,
      92,    60,    57,    95,    10,    97,    41,    99,    11,    12,
     102,   103,   120,    34,    60,     1,    35,    20,     5,     5,
      34,   143,    41,   143,   195,   147,    29,    33,    34,    15,
       1,   143,    35,     1,    40,    25,   207,   220,    41,    42,
     271,    28,    13,    14,    34,   225,    58,    18,    51,   169,
     172,     5,   172,    56,   274,     0,   184,   185,   150,   151,
     172,    15,    13,    14,    35,   193,    33,    18,   196,   197,
      41,   254,    12,    40,    57,    13,    73,    74,    75,    30,
      18,    78,   204,   263,    35,    36,    37,    38,    39,    25,
      41,     1,     9,   188,   314,    46,    13,    35,   220,     9,
     220,    18,   326,    41,   232,    15,   234,    11,    59,   237,
      14,   291,    14,    30,   294,   335,   123,   124,    35,    36,
      37,    38,    39,    11,    41,   217,    14,   219,    14,   221,
     222,   253,   254,   253,   254,   227,   244,   229,     9,   319,
      11,   253,    59,    14,     1,    11,     3,     4,    14,   269,
      70,    71,    11,     1,   274,    14,   284,   285,   251,    11,
     282,   289,    10,    34,   344,    13,    11,   259,   260,    14,
      18,    21,    20,    19,    22,    58,   268,    33,    36,    23,
      33,    29,    30,    31,     1,    14,    14,    35,    36,    37,
      38,    39,   314,    41,   314,    58,    13,     5,    46,    25,
      43,    18,   314,   325,    43,   297,    43,    43,     1,    25,
     338,    59,    60,     6,     7,     8,    38,    10,    35,    43,
      13,    17,    11,    58,    41,    18,    24,    20,    32,    22,
      14,    19,   324,    26,    27,    11,    29,    30,    31,    58,
      35,    14,    35,    36,    37,    38,    39,    58,    41,    42,
      25,    44,     1,    46,    47,    48,    11,     5,    32,    58,
      41,    10,    15,    56,    13,    25,    59,    60,     9,    18,
      57,    20,    11,    22,    41,    58,    40,    14,    11,     1,
      29,    30,    31,    41,   333,   284,    35,    36,    37,    38,
      39,    13,    41,   335,   143,     1,    18,    46,   325,   309,
       6,     7,     8,   285,    10,   110,   187,    13,     7,   204,
      59,    60,    18,    35,    20,     8,    22,   274,    75,    41,
      26,    27,   314,    29,    30,    31,   272,   154,    -1,    35,
      36,    37,    38,    39,   223,    41,    42,    -1,    44,     1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    10,     1,
      56,    13,    14,    59,    -1,    -1,    18,     9,    20,    11,
      22,    13,    14,    -1,    -1,    -1,    18,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,     1,     9,    35,    46,    -1,    13,    -1,    -1,    41,
      10,    18,    -1,    13,    -1,    -1,    -1,    59,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    34,    35,    29,
      30,    31,    -1,     1,    41,    35,    36,    37,    38,    39,
      -1,    41,    10,    -1,    -1,    13,    46,    -1,    -1,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    59,
      -1,    29,    30,    31,    -1,     1,    -1,    35,    36,    37,
      38,    39,    -1,    41,    10,    -1,    -1,    13,    46,    -1,
      -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    59,    -1,    29,    30,    31,    -1,     1,    -1,    35,
      36,    37,    38,    39,    -1,    41,    10,    -1,    -1,    13,
      46,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    59,    -1,    29,    30,    31,    -1,     1,
      -1,    35,    36,    37,    38,    39,    -1,    41,    10,    -1,
      -1,    13,    46,    -1,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    59,    -1,    29,    30,    31,
      -1,     1,    -1,    35,    36,    37,    38,    39,    -1,    41,
      10,    -1,    -1,    13,    46,    -1,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    59,    -1,    29,
      30,    31,    -1,     1,    -1,    35,    36,    37,    38,    39,
      -1,    41,    10,    -1,    -1,    13,    46,    -1,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    59,
      -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    41,    -1,     1,    10,    -1,    46,    13,
      14,    -1,    -1,    -1,    18,    -1,    20,    13,    22,    -1,
      -1,    59,    18,    19,    -1,    29,    30,    31,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    41,    10,    35,
      -1,    13,    46,    -1,    -1,    41,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    59,    13,    29,    30,    31,
      -1,    18,    -1,    35,    36,    37,    38,    39,    -1,    41,
      -1,    13,    -1,    30,    46,    -1,    18,    -1,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    59,    30,    46,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    62,     1,    10,    13,    18,    20,
      22,    29,    30,    31,    35,    36,    37,    38,    39,    41,
      46,    59,   109,   110,   111,   112,   113,   114,   115,   117,
     118,     1,    63,    64,     0,   117,    10,    14,    33,    34,
      40,    92,    93,   112,   115,   119,   112,   119,   126,   112,
     112,   116,   118,   118,    58,   118,    12,    25,   105,    57,
      10,    34,    40,    91,    92,    93,    91,   118,     1,     6,
       7,     8,    26,    27,    42,    44,    47,    48,    56,    65,
      70,   101,   108,   109,   113,    14,    35,    41,    14,    14,
     118,   118,    11,    14,    91,    11,    14,    11,    15,    17,
      19,    21,    23,     9,   118,   101,   102,   118,    58,     1,
      13,    18,    35,    41,    82,    83,    84,    85,    86,   115,
     115,    36,    89,    89,    89,     1,    41,    73,    83,    84,
      83,    84,    96,    96,     1,    13,    94,    95,   109,    84,
      83,    84,     1,    16,    60,   129,   130,    11,    57,     1,
       5,    15,   103,   104,   106,   107,    33,    33,    14,    14,
     112,    14,   112,   112,    31,   112,   127,   128,   112,    58,
     112,   112,    16,   129,   102,     9,    11,    14,    84,    85,
      87,    88,    19,    84,    43,     9,    34,    69,    91,    90,
      91,    90,    90,     5,    69,    43,     5,    43,    25,    97,
      25,    98,    10,    34,    11,    57,    38,    43,    71,    70,
     101,   130,   109,    82,   112,   112,   105,     5,   107,    17,
      58,     5,    28,    11,   113,   120,   121,    24,   101,    32,
     129,    14,    11,    14,     9,    11,    14,    11,    14,    19,
      84,    84,    86,   115,    11,    84,    35,    73,     1,    77,
      78,    84,    84,    58,    58,    95,    82,    73,    25,    11,
       5,   112,   112,   102,   112,   112,   128,     1,     9,    15,
     122,   123,   124,   125,    16,   129,   112,   112,    84,    14,
      84,    91,    32,    74,     5,    15,    49,    79,    33,    93,
       1,    99,   100,   101,   102,    72,    58,    22,   112,   112,
     129,   112,   113,   105,   125,   121,    75,    76,   109,    77,
      78,    13,    41,    84,    16,   129,   129,    25,    13,    66,
      67,    68,   111,   112,     9,    11,    57,    79,    41,    80,
      81,     1,   100,    58,    40,    16,   129,    11,    57,   112,
      76,    82,    14,    11,    66,    67,   111,    84,    41,   129
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    63,    64,    65,    65,
      65,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      71,    70,    72,    70,    70,    70,    70,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      70,    70,    70,    89,    89,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    70,    94,    94,    94,    95,    70,
      70,    70,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   105,   106,   106,   107,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   113,   113,
     113,   114,   114,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   121,   122,   122,   123,   123,   123,
     124,   124,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     130
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     1,     3,     3,     1,     1,     0,
       0,     7,     0,     9,     5,     5,     7,     3,     1,     1,
       2,     0,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     0,     2,     4,     0,     1,     3,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     2,     3,
       3,     4,     3,     3,     3,     2,     2,     1,     3,     3,
       3,     3,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     4,     3,     1,     1,     2,     3,
       3,     2,     3,     1,     4,     0,     4,     0,     3,     1,
       1,     1,     3,     2,     3,     1,     2,     1,     1,     2,
       1,     4,     2,     1,     4,     5,     4,     3,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     1,     1,     3,
       1,     3,     5,     2,     4,     6,     6,     6,     1,     2,
       1,     2,     2,     1,     1,     3,     2,     1,     1,     2,
       1,     1,     1,     1,     3,     3,     3,     4,     4,     4,
       3,     3,     3,     1,     2,     2,     1,     1,     2,     1,
       2,     1,     4,     0,     1,     1,     3,     3,     4,     2,
       5,     3,     1,     3,     3,     1,     4,     2,     1,     1,
       1
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
  case 2: /* start: EVALEX exp  */
#line 109 "parser.y"
                                        {inputExpr = yyvsp[0];	    sp-=1;}
#line 1725 "y.tab.c"
    break;

  case 3: /* start: EVALEX exp wherePart  */
#line 110 "parser.y"
                                        {inputExpr = letrec(yyvsp[0],yyvsp[-1]); sp-=2;}
#line 1731 "y.tab.c"
    break;

  case 4: /* start: SCRIPT topModule  */
#line 111 "parser.y"
                                        {valDefns  = yyvsp[0];	    sp-=1;}
#line 1737 "y.tab.c"
    break;

  case 5: /* start: error  */
#line 112 "parser.y"
                                        {syntaxError("input");}
#line 1743 "y.tab.c"
    break;

  case 6: /* topModule: begin topDecls close  */
#line 125 "parser.y"
                                        {yyval = gc2(yyvsp[-1]);}
#line 1749 "y.tab.c"
    break;

  case 7: /* begin: error  */
#line 128 "parser.y"
                                        {yyerrok; goOffside(startColumn);}
#line 1755 "y.tab.c"
    break;

  case 8: /* topDecls: topDecls ';' topDecl  */
#line 130 "parser.y"
                                        {yyval = gc2(yyvsp[-2]);}
#line 1761 "y.tab.c"
    break;

  case 9: /* topDecls: topDecls ';' decl  */
#line 131 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 1767 "y.tab.c"
    break;

  case 10: /* topDecls: topDecl  */
#line 132 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1773 "y.tab.c"
    break;

  case 11: /* topDecls: decl  */
#line 133 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 1779 "y.tab.c"
    break;

  case 12: /* topDecls: error  */
#line 134 "parser.y"
                                        {syntaxError("definition");}
#line 1785 "y.tab.c"
    break;

  case 13: /* ctDecls: ctDecls ';' ctDecl  */
#line 138 "parser.y"
                              {yyval = gc3(appendOnto(yyvsp[-2], yyvsp[0]));}
#line 1791 "y.tab.c"
    break;

  case 14: /* ctDecls: ctDecl  */
#line 139 "parser.y"
                  {yyval = yyvsp[0];}
#line 1797 "y.tab.c"
    break;

  case 15: /* ctDecl: conids ':' type  */
#line 141 "parser.y"
                           {yyval = gc3(ct1Clause(intOf(yyvsp[-1]), yyvsp[0], yyvsp[-2]));}
#line 1803 "y.tab.c"
    break;

  case 16: /* conids: conids ',' conid  */
#line 143 "parser.y"
                            {yyval = gc3(cons(yyvsp[0], yyvsp[-2]));}
#line 1809 "y.tab.c"
    break;

  case 17: /* conids: conid  */
#line 144 "parser.y"
                 {yyval = gc1(singleton(yyvsp[0]));}
#line 1815 "y.tab.c"
    break;

  case 18: /* pvarop: VAROP  */
#line 147 "parser.y"
                        {yyval = gc1(yyvsp[0]);}
#line 1821 "y.tab.c"
    break;

  case 19: /* pvarop: %empty  */
#line 148 "parser.y"
                        {yyval = gc0(NIL);}
#line 1827 "y.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 151 "parser.y"
                     {typeLhs = yyvsp[0];}
#line 1833 "y.tab.c"
    break;

  case 21: /* topDecl: CTYPE type $@1 WHERE '{' ctDecls close  */
#line 152 "parser.y"
          {defTycon(6,yyvsp[-6], checkTyLhs(yyvsp[-5]), yyvsp[-1], DATATYPE); typeLhs = NIL;}
#line 1839 "y.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 153 "parser.y"
                                        {typeLhs = yyvsp[0];}
#line 1845 "y.tab.c"
    break;

  case 23: /* topDecl: CTYPE context IMPLIES typeLhs $@2 WHERE '{' ctDecls close  */
#line 154 "parser.y"
          {defTycon(8,yyvsp[-8], yyvsp[-5], ap(QUAL,pair (yyvsp[-7],yyvsp[-1])), DATATYPE); typeLhs = NIL;}
#line 1851 "y.tab.c"
    break;

  case 24: /* topDecl: TYPE typeLhs '=' type invars  */
#line 157 "parser.y"
                                                {defTycon(5,yyvsp[-2],yyvsp[-3],yyvsp[-1],yyvsp[0]);}
#line 1857 "y.tab.c"
    break;

  case 25: /* topDecl: DATA type '=' constrs deriving  */
#line 159 "parser.y"
                                        {defTycon(5,yyvsp[-2],checkTyLhs(yyvsp[-3]),
							rev(yyvsp[-1]),DATATYPE);}
#line 1864 "y.tab.c"
    break;

  case 26: /* topDecl: DATA context IMPLIES typeLhs '=' constrs deriving  */
#line 162 "parser.y"
                                        {defTycon(7,yyvsp[-2],yyvsp[-3],
						  ap(QUAL,pair(yyvsp[-5],rev(yyvsp[-1]))),
						  DATATYPE);}
#line 1872 "y.tab.c"
    break;

  case 27: /* typeLhs: typeLhs pvarop VARID  */
#line 167 "parser.y"
                                        {typeSyntaxChk("type Lhs", yyvsp[-1]);
					 yyval = gc3(ap(yyvsp[-2],yyvsp[0]));
					}
#line 1880 "y.tab.c"
    break;

  case 28: /* typeLhs: CONID  */
#line 170 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1886 "y.tab.c"
    break;

  case 29: /* typeLhs: error  */
#line 171 "parser.y"
                                        {syntaxError("type defn lhs");}
#line 1892 "y.tab.c"
    break;

  case 30: /* invars: IN rsvars  */
#line 173 "parser.y"
                                        {yyval = gc2(yyvsp[0]);}
#line 1898 "y.tab.c"
    break;

  case 31: /* invars: %empty  */
#line 174 "parser.y"
                                        {yyval = gc0(SYNONYM);}
#line 1904 "y.tab.c"
    break;

  case 32: /* rsvars: rsvars ',' rsvar  */
#line 176 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 1910 "y.tab.c"
    break;

  case 33: /* rsvars: rsvar  */
#line 177 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 1916 "y.tab.c"
    break;

  case 34: /* rsvar: var ':' sigType  */
#line 179 "parser.y"
                                        {yyval = gc3(sigdecl(yyvsp[-1],singleton(yyvsp[-2]),
							     yyvsp[0]));}
#line 1923 "y.tab.c"
    break;

  case 35: /* rsvar: var  */
#line 181 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1929 "y.tab.c"
    break;

  case 36: /* constrs: constrs '|' constr  */
#line 183 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 1935 "y.tab.c"
    break;

  case 37: /* constrs: constr  */
#line 184 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 1941 "y.tab.c"
    break;

  case 38: /* constr: type conop type  */
#line 186 "parser.y"
                                        {yyval = gc3(ap(ap(yyvsp[-1],yyvsp[-2]),yyvsp[0]));}
#line 1947 "y.tab.c"
    break;

  case 39: /* constr: type  */
#line 187 "parser.y"
                                        {if (!isCon(getHead(yyvsp[0])))
					     syntaxError("data constructor");
					 yyval = yyvsp[0];}
#line 1955 "y.tab.c"
    break;

  case 40: /* constr: error  */
#line 190 "parser.y"
                                        {syntaxError("data type definition");}
#line 1961 "y.tab.c"
    break;

  case 41: /* deriving: %empty  */
#line 192 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1967 "y.tab.c"
    break;

  case 42: /* deriving: DERIVING CONID  */
#line 193 "parser.y"
                                        {yyval = gc2(singleton(yyvsp[0]));}
#line 1973 "y.tab.c"
    break;

  case 43: /* deriving: DERIVING '(' derivs0 ')'  */
#line 194 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 1979 "y.tab.c"
    break;

  case 44: /* derivs0: %empty  */
#line 196 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1985 "y.tab.c"
    break;

  case 45: /* derivs0: derivs  */
#line 197 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1991 "y.tab.c"
    break;

  case 46: /* derivs: derivs ',' CONID  */
#line 199 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 1997 "y.tab.c"
    break;

  case 47: /* derivs: CONID  */
#line 200 "parser.y"
                                        {yyval = gc1(singleton(yyvsp[0]));}
#line 2003 "y.tab.c"
    break;

  case 48: /* sigType: context IMPLIES type  */
#line 211 "parser.y"
                                        {yyval = gc3(ap(QUAL,pair(yyvsp[-2],yyvsp[0])));}
#line 2009 "y.tab.c"
    break;

  case 49: /* sigType: type  */
#line 212 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2015 "y.tab.c"
    break;

  case 50: /* context: type  */
#line 214 "parser.y"
                                        {yyval = gc1(checkContext(yyvsp[0]));}
#line 2021 "y.tab.c"
    break;

  case 51: /* type: ctype  */
#line 216 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2027 "y.tab.c"
    break;

  case 52: /* type: ctype FUNARROW type  */
#line 217 "parser.y"
                                        {yyval = gc3(ap(ap(ARROW,yyvsp[-2]),yyvsp[0]));}
#line 2033 "y.tab.c"
    break;

  case 53: /* type: error  */
#line 218 "parser.y"
                                        {syntaxError("type expression");}
#line 2039 "y.tab.c"
    break;

  case 54: /* ctype: ctype pvarop atype  */
#line 220 "parser.y"
                                        {typeSyntaxChk("type expression", yyvsp[-1]);
					 yyval = gc3(ap(yyvsp[-2],yyvsp[0]));
					}
#line 2047 "y.tab.c"
    break;

  case 55: /* ctype: atype  */
#line 224 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2053 "y.tab.c"
    break;

  case 56: /* atype: VARID  */
#line 226 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2059 "y.tab.c"
    break;

  case 57: /* atype: CONID  */
#line 227 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2065 "y.tab.c"
    break;

  case 58: /* atype: '(' ')'  */
#line 228 "parser.y"
                                        {yyval = gc2(UNIT);}
#line 2071 "y.tab.c"
    break;

  case 59: /* atype: '(' FUNARROW ')'  */
#line 229 "parser.y"
                                        {yyval = gc3(ARROW);}
#line 2077 "y.tab.c"
    break;

  case 60: /* atype: '(' type ')'  */
#line 230 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2083 "y.tab.c"
    break;

  case 61: /* atype: '(' ctype FUNARROW ')'  */
#line 231 "parser.y"
                                        {yyval = gc4(ap(ARROW,yyvsp[-2]));}
#line 2089 "y.tab.c"
    break;

  case 62: /* atype: '(' tupCommas ')'  */
#line 232 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2095 "y.tab.c"
    break;

  case 63: /* atype: '(' typeTuple ')'  */
#line 233 "parser.y"
                                        {yyval = gc3(buildTuple(yyvsp[-1]));}
#line 2101 "y.tab.c"
    break;

  case 64: /* atype: '[' type ']'  */
#line 234 "parser.y"
                                        {yyval = gc3(ap(LIST,yyvsp[-1]));}
#line 2107 "y.tab.c"
    break;

  case 65: /* atype: '[' ']'  */
#line 235 "parser.y"
                                        {yyval = gc2(LIST);}
#line 2113 "y.tab.c"
    break;

  case 66: /* tupCommas: tupCommas ','  */
#line 237 "parser.y"
                                        {yyval = gc2(mkTuple(tupleOf(yyvsp[-1])+1));}
#line 2119 "y.tab.c"
    break;

  case 67: /* tupCommas: ','  */
#line 238 "parser.y"
                                        {yyval = gc1(mkTuple(2));}
#line 2125 "y.tab.c"
    break;

  case 68: /* typeTuple: typeTuple ',' type  */
#line 241 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2131 "y.tab.c"
    break;

  case 69: /* typeTuple: type ',' type  */
#line 242 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],cons(yyvsp[-2],NIL)));}
#line 2137 "y.tab.c"
    break;

  case 70: /* topDecl: INFIXL optdigit ops  */
#line 247 "parser.y"
                                        {fixDefn(LEFT_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]); sp-=3;}
#line 2143 "y.tab.c"
    break;

  case 71: /* topDecl: INFIXR optdigit ops  */
#line 248 "parser.y"
                                        {fixDefn(RIGHT_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]);sp-=3;}
#line 2149 "y.tab.c"
    break;

  case 72: /* topDecl: INFIX optdigit ops  */
#line 249 "parser.y"
                                        {fixDefn(NON_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]);  sp-=3;}
#line 2155 "y.tab.c"
    break;

  case 73: /* optdigit: NUMLIT  */
#line 251 "parser.y"
                                        {yyval = gc1(checkPrec(yyvsp[0]));}
#line 2161 "y.tab.c"
    break;

  case 74: /* optdigit: %empty  */
#line 252 "parser.y"
                                        {yyval = gc0(mkInt(DEF_PREC));}
#line 2167 "y.tab.c"
    break;

  case 75: /* ops: ops ',' op  */
#line 254 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2173 "y.tab.c"
    break;

  case 76: /* ops: op  */
#line 255 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2179 "y.tab.c"
    break;

  case 77: /* op: varop  */
#line 257 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2185 "y.tab.c"
    break;

  case 78: /* op: conop  */
#line 258 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2191 "y.tab.c"
    break;

  case 79: /* op: '-'  */
#line 259 "parser.y"
                                        {yyval = gc1(varMinus);}
#line 2197 "y.tab.c"
    break;

  case 80: /* varop: VAROP  */
#line 261 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2203 "y.tab.c"
    break;

  case 81: /* varop: '`' VARID '`'  */
#line 262 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2209 "y.tab.c"
    break;

  case 82: /* conop: CONOP  */
#line 264 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2215 "y.tab.c"
    break;

  case 83: /* conop: '`' CONID '`'  */
#line 265 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2221 "y.tab.c"
    break;

  case 84: /* topDecl: PRIMITIVE prims ':' sigType  */
#line 270 "parser.y"
                                       {primDefn(yyvsp[-3],yyvsp[-2],yyvsp[0]); sp-=4;}
#line 2227 "y.tab.c"
    break;

  case 85: /* prims: prims ',' prim  */
#line 272 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2233 "y.tab.c"
    break;

  case 86: /* prims: prim  */
#line 273 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2239 "y.tab.c"
    break;

  case 87: /* prims: error  */
#line 274 "parser.y"
                                        {syntaxError("primitive defn");}
#line 2245 "y.tab.c"
    break;

  case 88: /* prim: var STRINGLIT  */
#line 276 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2251 "y.tab.c"
    break;

  case 89: /* topDecl: TCLASS classHead classBody  */
#line 281 "parser.y"
                                        {classDefn(intOf(yyvsp[-2]),yyvsp[-1],yyvsp[0]); sp-=3;}
#line 2257 "y.tab.c"
    break;

  case 90: /* topDecl: TINSTANCE classHead instBody  */
#line 282 "parser.y"
                                        {instDefn(intOf(yyvsp[-2]),yyvsp[-1],yyvsp[0]);  sp-=3;}
#line 2263 "y.tab.c"
    break;

  case 91: /* topDecl: DEFAULT type  */
#line 283 "parser.y"
                                        {sp-=2;}
#line 2269 "y.tab.c"
    break;

  case 92: /* classHead: context IMPLIES type  */
#line 285 "parser.y"
                                        {yyval = gc3(pair(yyvsp[-2],checkClass(yyvsp[0])));}
#line 2275 "y.tab.c"
    break;

  case 93: /* classHead: type  */
#line 286 "parser.y"
                                        {yyval = gc1(pair(NIL,checkClass(yyvsp[0])));}
#line 2281 "y.tab.c"
    break;

  case 94: /* classBody: WHERE '{' csigdecls close  */
#line 288 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2287 "y.tab.c"
    break;

  case 95: /* classBody: %empty  */
#line 289 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2293 "y.tab.c"
    break;

  case 96: /* instBody: WHERE '{' decls close  */
#line 291 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2299 "y.tab.c"
    break;

  case 97: /* instBody: %empty  */
#line 292 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2305 "y.tab.c"
    break;

  case 98: /* csigdecls: csigdecls ';' csigdecl  */
#line 294 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2311 "y.tab.c"
    break;

  case 99: /* csigdecls: csigdecl  */
#line 295 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2317 "y.tab.c"
    break;

  case 100: /* csigdecl: decl  */
#line 297 "parser.y"
                                        {yyval = gc1(yyvsp[0]);}
#line 2323 "y.tab.c"
    break;

  case 101: /* csigdecl: error  */
#line 298 "parser.y"
                                        {syntaxError("class body");}
#line 2329 "y.tab.c"
    break;

  case 102: /* decl: vars ':' sigType  */
#line 303 "parser.y"
                                        {yyval = gc3(sigdecl(yyvsp[-1],yyvsp[-2],yyvsp[0]));}
#line 2335 "y.tab.c"
    break;

  case 103: /* decl: opExp rhs  */
#line 304 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2341 "y.tab.c"
    break;

  case 104: /* decls: decls ';' decl  */
#line 306 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2347 "y.tab.c"
    break;

  case 105: /* decls: decl  */
#line 307 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2353 "y.tab.c"
    break;

  case 106: /* rhs: rhs1 wherePart  */
#line 309 "parser.y"
                                        {yyval = gc2(letrec(yyvsp[0],yyvsp[-1]));}
#line 2359 "y.tab.c"
    break;

  case 107: /* rhs: rhs1  */
#line 310 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2365 "y.tab.c"
    break;

  case 108: /* rhs: error  */
#line 311 "parser.y"
                                        {syntaxError("declaration");}
#line 2371 "y.tab.c"
    break;

  case 109: /* rhs1: '=' exp  */
#line 313 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2377 "y.tab.c"
    break;

  case 110: /* rhs1: gdefs  */
#line 314 "parser.y"
                                        {yyval = gc1(grded(rev(yyvsp[0])));}
#line 2383 "y.tab.c"
    break;

  case 111: /* wherePart: WHERE '{' decls close  */
#line 316 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2389 "y.tab.c"
    break;

  case 112: /* gdefs: gdefs gdef  */
#line 318 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2395 "y.tab.c"
    break;

  case 113: /* gdefs: gdef  */
#line 319 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2401 "y.tab.c"
    break;

  case 114: /* gdef: '|' exp '=' exp  */
#line 321 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-1],pair(yyvsp[-2],yyvsp[0])));}
#line 2407 "y.tab.c"
    break;

  case 115: /* gdef: '=' exp ',' IF exp  */
#line 328 "parser.y"
                                        {yyval = gc5(pair(yyvsp[-4],pair(yyvsp[0],yyvsp[-3])));}
#line 2413 "y.tab.c"
    break;

  case 116: /* gdef: '=' exp ',' exp  */
#line 329 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-3],pair(yyvsp[0],yyvsp[-2])));}
#line 2419 "y.tab.c"
    break;

  case 117: /* vars: vars ',' var  */
#line 331 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2425 "y.tab.c"
    break;

  case 118: /* vars: var  */
#line 332 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2431 "y.tab.c"
    break;

  case 119: /* var: varid  */
#line 334 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2437 "y.tab.c"
    break;

  case 120: /* var: '(' '-' ')'  */
#line 335 "parser.y"
                                        {yyval = gc3(varMinus);}
#line 2443 "y.tab.c"
    break;

  case 121: /* varid: VARID  */
#line 337 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2449 "y.tab.c"
    break;

  case 122: /* varid: '(' VAROP ')'  */
#line 338 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2455 "y.tab.c"
    break;

  case 123: /* conid: CONID  */
#line 340 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2461 "y.tab.c"
    break;

  case 124: /* conid: '(' CONOP ')'  */
#line 341 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2467 "y.tab.c"
    break;

  case 125: /* exp: opExp ':' sigType  */
#line 346 "parser.y"
                                        {yyval = gc3(ap(ESIGN,pair(yyvsp[-2],yyvsp[0])));}
#line 2473 "y.tab.c"
    break;

  case 126: /* exp: opExp  */
#line 347 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2479 "y.tab.c"
    break;

  case 127: /* exp: error  */
#line 348 "parser.y"
                                        {syntaxError("expression");}
#line 2485 "y.tab.c"
    break;

  case 128: /* opExp: pfxExp  */
#line 350 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2491 "y.tab.c"
    break;

  case 129: /* opExp: pfxExp op pfxExp  */
#line 351 "parser.y"
                                        {yyval = gc3(opapd(yyvsp[-2],yyvsp[-1],yyvsp[0]));}
#line 2497 "y.tab.c"
    break;

  case 130: /* opExp: opExp0  */
#line 353 "parser.y"
                                        {yyval = gc1((*tidyInfix[newSyntax])(yyvsp[0]));}
#line 2503 "y.tab.c"
    break;

  case 131: /* opExp0: opExp0 op pfxExp  */
#line 355 "parser.y"
                                        {yyval = gc3(opap(yyvsp[-2],yyvsp[-1],yyvsp[0]));}
#line 2509 "y.tab.c"
    break;

  case 132: /* opExp0: pfxExp op pfxExp op pfxExp  */
#line 356 "parser.y"
                                        {yyval =
 		  gc5(opap(opap(singleton(yyvsp[-4]), yyvsp[-3], yyvsp[-2]),yyvsp[-1],yyvsp[0]));}
#line 2516 "y.tab.c"
    break;

  case 133: /* pfxExp: '-' appExp  */
#line 359 "parser.y"
                                        {if (isInt(yyvsp[0]))
					     yyval = gc2(mkInt(-intOf(yyvsp[0])));
					 else
					     yyval = gc2(ap(varNegate,yyvsp[0]));
					}
#line 2526 "y.tab.c"
    break;

  case 134: /* pfxExp: '\\' pats FUNARROW exp  */
#line 364 "parser.y"
                                        {yyval = gc4(ap(LAMBDA,
						     pair(rev(yyvsp[-2]),
						          pair(yyvsp[-1],yyvsp[0]))));}
#line 2534 "y.tab.c"
    break;

  case 135: /* pfxExp: LET '{' decls close IN exp  */
#line 367 "parser.y"
                                        {yyval = gc6(letrec(yyvsp[-3],yyvsp[0]));}
#line 2540 "y.tab.c"
    break;

  case 136: /* pfxExp: IF exp THEN exp ELSE exp  */
#line 368 "parser.y"
                                        {yyval = gc6(ap(COND,triple(yyvsp[-4],yyvsp[-2],yyvsp[0])));}
#line 2546 "y.tab.c"
    break;

  case 137: /* pfxExp: CASEXP exp OF '{' alts close  */
#line 369 "parser.y"
                                        {yyval = gc6(ap(CASE,pair(yyvsp[-4],rev(yyvsp[-1]))));}
#line 2552 "y.tab.c"
    break;

  case 138: /* pfxExp: appExp  */
#line 370 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2558 "y.tab.c"
    break;

  case 139: /* pats: pats atomic  */
#line 372 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2564 "y.tab.c"
    break;

  case 140: /* pats: atomic  */
#line 373 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2570 "y.tab.c"
    break;

  case 141: /* appExp: appExp atomic  */
#line 376 "parser.y"
              {
		if (newSyntax)
		{
		  ERROR(row) "Juxtaposition has no meaning. Use ."
		  EEND;
		}
		else
		  yyval = gc2(ap(yyvsp[-1],yyvsp[0]));
	      }
#line 2584 "y.tab.c"
    break;

  case 142: /* appExp: TRUNST atomic  */
#line 385 "parser.y"
                                        {yyval = gc2(ap(RUNST,yyvsp[0]));}
#line 2590 "y.tab.c"
    break;

  case 143: /* appExp: atomic  */
#line 386 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2596 "y.tab.c"
    break;

  case 144: /* atomic: var  */
#line 388 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2602 "y.tab.c"
    break;

  case 145: /* atomic: var '@' atomic  */
#line 389 "parser.y"
                                        {yyval = gc3(ap(ASPAT,pair(yyvsp[-2],yyvsp[0])));}
#line 2608 "y.tab.c"
    break;

  case 146: /* atomic: '~' atomic  */
#line 390 "parser.y"
                                        {yyval = gc2(ap(LAZYPAT,yyvsp[0]));}
#line 2614 "y.tab.c"
    break;

  case 147: /* atomic: '_'  */
#line 391 "parser.y"
                                        {yyval = gc1(WILDCARD);}
#line 2620 "y.tab.c"
    break;

  case 148: /* atomic: conid  */
#line 392 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2626 "y.tab.c"
    break;

  case 149: /* atomic: '(' ')'  */
#line 393 "parser.y"
                                        {yyval = gc2(UNIT);}
#line 2632 "y.tab.c"
    break;

  case 150: /* atomic: NUMLIT  */
#line 394 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2638 "y.tab.c"
    break;

  case 151: /* atomic: CHARLIT  */
#line 395 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2644 "y.tab.c"
    break;

  case 152: /* atomic: STRINGLIT  */
#line 396 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2650 "y.tab.c"
    break;

  case 153: /* atomic: REPEAT  */
#line 397 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2656 "y.tab.c"
    break;

  case 154: /* atomic: '(' exp ')'  */
#line 398 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2662 "y.tab.c"
    break;

  case 155: /* atomic: '(' exps2 ')'  */
#line 399 "parser.y"
                                        {yyval = gc3(buildTuple(yyvsp[-1]));}
#line 2668 "y.tab.c"
    break;

  case 156: /* atomic: '[' list ']'  */
#line 400 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2674 "y.tab.c"
    break;

  case 157: /* atomic: '(' pfxExp op ')'  */
#line 401 "parser.y"
                                        {yyval = gc4(ap(yyvsp[-1],yyvsp[-2]));}
#line 2680 "y.tab.c"
    break;

  case 158: /* atomic: '(' varop atomic ')'  */
#line 402 "parser.y"
                                        {yyval = gc4(ap(ap(varFlip,yyvsp[-2]),yyvsp[-1]));}
#line 2686 "y.tab.c"
    break;

  case 159: /* atomic: '(' conop atomic ')'  */
#line 403 "parser.y"
                                        {yyval = gc4(ap(ap(varFlip,yyvsp[-2]),yyvsp[-1]));}
#line 2692 "y.tab.c"
    break;

  case 160: /* exps2: exps2 ',' exp  */
#line 405 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2698 "y.tab.c"
    break;

  case 161: /* exps2: exp ',' exp  */
#line 406 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],cons(yyvsp[-2],NIL)));}
#line 2704 "y.tab.c"
    break;

  case 162: /* alts: alts ';' alt  */
#line 408 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2710 "y.tab.c"
    break;

  case 163: /* alts: alt  */
#line 409 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2716 "y.tab.c"
    break;

  case 164: /* alt: opExp altRhs  */
#line 411 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2722 "y.tab.c"
    break;

  case 165: /* altRhs: altRhs1 wherePart  */
#line 413 "parser.y"
                                        {yyval = gc2(letrec(yyvsp[0],yyvsp[-1]));}
#line 2728 "y.tab.c"
    break;

  case 166: /* altRhs: altRhs1  */
#line 414 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2734 "y.tab.c"
    break;

  case 167: /* altRhs1: guardAlts  */
#line 416 "parser.y"
                                        {yyval = gc1(grded(rev(yyvsp[0])));}
#line 2740 "y.tab.c"
    break;

  case 168: /* altRhs1: FUNARROW exp  */
#line 417 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2746 "y.tab.c"
    break;

  case 169: /* altRhs1: error  */
#line 418 "parser.y"
                                        {syntaxError("case expression");}
#line 2752 "y.tab.c"
    break;

  case 170: /* guardAlts: guardAlts guardAlt  */
#line 420 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2758 "y.tab.c"
    break;

  case 171: /* guardAlts: guardAlt  */
#line 421 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2764 "y.tab.c"
    break;

  case 172: /* guardAlt: '|' opExp FUNARROW exp  */
#line 423 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-1],pair(yyvsp[-2],yyvsp[0])));}
#line 2770 "y.tab.c"
    break;

  case 173: /* list: %empty  */
#line 428 "parser.y"
                                        {yyval = gc0(nameNil);}
#line 2776 "y.tab.c"
    break;

  case 174: /* list: exp  */
#line 429 "parser.y"
                                        {yyval = gc1(ap(FINLIST,cons(yyvsp[0],NIL)));}
#line 2782 "y.tab.c"
    break;

  case 175: /* list: exps2  */
#line 430 "parser.y"
                                        {yyval = gc1(ap(FINLIST,rev(yyvsp[0])));}
#line 2788 "y.tab.c"
    break;

  case 176: /* list: exp '|' quals  */
#line 431 "parser.y"
                                        {yyval = gc3(ap(COMP,pair(yyvsp[-2],rev(yyvsp[0]))));}
#line 2794 "y.tab.c"
    break;

  case 177: /* list: exp UPTO exp  */
#line 432 "parser.y"
                                        {yyval = gc3(ap(ap(varFromTo,yyvsp[-2]),yyvsp[0]));}
#line 2800 "y.tab.c"
    break;

  case 178: /* list: exp ',' exp UPTO  */
#line 433 "parser.y"
                                        {yyval = gc4(ap(ap(varFromThen,yyvsp[-3]),yyvsp[-1]));}
#line 2806 "y.tab.c"
    break;

  case 179: /* list: exp UPTO  */
#line 434 "parser.y"
                                        {yyval = gc2(ap(varFrom,yyvsp[-1]));}
#line 2812 "y.tab.c"
    break;

  case 180: /* list: exp ',' exp UPTO exp  */
#line 435 "parser.y"
                                        {yyval = gc5(ap(ap(ap(varFromThenTo,
                                                               yyvsp[-4]),yyvsp[-2]),yyvsp[0]));}
#line 2819 "y.tab.c"
    break;

  case 181: /* quals: quals ',' qual  */
#line 438 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2825 "y.tab.c"
    break;

  case 182: /* quals: qual  */
#line 439 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2831 "y.tab.c"
    break;

  case 183: /* qual: exp FROM exp  */
#line 441 "parser.y"
                                        {yyval = gc3(ap(FROMQUAL,pair(yyvsp[-2],yyvsp[0])));}
#line 2837 "y.tab.c"
    break;

  case 184: /* qual: exp '=' exp  */
#line 442 "parser.y"
                                        {yyval = gc3(ap(QWHERE,
						     singleton(
							pair(yyvsp[-2],pair(yyvsp[-1],
								     yyvsp[0])))));}
#line 2846 "y.tab.c"
    break;

  case 185: /* qual: exp  */
#line 446 "parser.y"
                                        {yyval = gc1(ap(BOOLQUAL,yyvsp[0]));}
#line 2852 "y.tab.c"
    break;

  case 186: /* qual: LET '{' decls close  */
#line 447 "parser.y"
                                        {yyval = gc4(ap(QWHERE,yyvsp[-1]));}
#line 2858 "y.tab.c"
    break;

  case 187: /* close: ';' close1  */
#line 473 "parser.y"
                                        {yyval = gc2(yyvsp[0]);}
#line 2864 "y.tab.c"
    break;

  case 188: /* close: close1  */
#line 474 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2870 "y.tab.c"
    break;

  case 189: /* close1: '}'  */
#line 476 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2876 "y.tab.c"
    break;

  case 190: /* close1: error  */
#line 477 "parser.y"
                                        {yyerrok;
                                         if (canUnOffside()) {
                                             unOffside();
					     /* insert extra token on stack*/
					     push(NIL);
					     pushed(0) = pushed(1);
					     pushed(1) = mkInt(column);
					 }
                                         else
                                             syntaxError("definition");
                                        }
#line 2892 "y.tab.c"
    break;


#line 2896 "y.tab.c"

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

#line 492 "parser.y"


static Cell local gcShadow(n,e)		/* keep parsed fragments on stack  */
Int  n;
Cell e; {
    /* If a look ahead token is held then the required stack transformation
     * is:
     *   pushed: n               1     0          1     0
     *           x1  |  ...  |  xn  |  la   ===>  e  |  la
     *                                top()            top()
     *
     * Othwerwise, the transformation is:
     *   pushed: n-1             0        0
     *           x1  |  ...  |  xn  ===>  e
     *                         top()     top()
     */
    if (yychar>=0) {
	pushed(n-1) = top();
        pushed(n)   = e;
    }
    else
	pushed(n-1) = e;
    sp -= (n-1);
    return e;
}

Void syntaxError(s)       /* report on syntax error           */
String s; {
    ERROR(row) "Syntax error in %s (unexpected %s)", s, unexpected()
    EEND;
}

static String local unexpected() {	/* find name for unexpected token  */
    static char buffer[100];
    static char *fmt = "%s \"%s\"";
    static char *kwd = "keyword";
    static char *hkw = "(Haskell) keyword";

    switch (yychar) {
	case 0	       : return "end of input";

#define keyword(kw) sprintf(buffer,fmt,kwd,kw); return buffer;
	case INFIXL    : keyword("infixl");
	case INFIXR    : keyword("infixr");
	case INFIX     : keyword("infix");
	case TINSTANCE : keyword("instance");
	case TCLASS    : keyword("class");
	case PRIMITIVE : keyword("primitive");
	case CASEXP    : keyword("case");
	case OF        : keyword("of");
	case IF        : keyword("if");
	case DO	       : keyword("do");
	case TRUNST    : keyword("runST");
	case THEN      : keyword("then");
	case ELSE      : keyword("else");
	case WHERE     : keyword("where");
	case TYPE      : keyword("type");
	case CTYPE     : keyword("ctype");
	case LET       : keyword("let");
	case IN        : keyword("in");
#undef keyword

#define hasword(kw) sprintf(buffer,fmt,hkw,kw); return buffer;
	case DEFAULT   : hasword("default");
	case DERIVING  : hasword("deriving");
	case HIDING    : hasword("hiding");
	case IMPORT    : hasword("import");
	case INTERFACE : hasword("interface");
	case MODULE    : hasword("module");
	case RENAMING  : hasword("renaming");
	case TO	       : hasword("to");
#undef hasword

	case FUNARROW  : return "`->'";
	case '='       : return "`='";
	case ':'      :
	   sprintf(buffer,"`%s'", typeStr[newSyntax]);
	   return buffer;
	case '-'       : return "`-'";
	case ','       : return "comma";
	case '@'       : return "`@'";
	case '('       : return "`('";
	case ')'       : return "`)'";
	case '|'       : return "`|'";
	case ';'       : return "separator";
	case UPTO      :
	   sprintf(buffer,"`%s'", uptoStr[newSyntax]);
	   return buffer;
	case '['       : return "`['";
	case ']'       : return "`]'";
	case FROM      : return "`<-'";
	case '\\'      : return "backslash (lambda)";
	case '~'       : return "tilde";
	case '`'       : return "backquote";
	case VAROP     :
	case VARID     :
	case CONOP     :
	case CONID     : sprintf(buffer,"symbol \"%s\"",
				 textToStr(textOf(yylval)));
			 return buffer;
	case NUMLIT    : return "numeric literal";
	case CHARLIT   : return "character literal";
	case STRINGLIT : return "string literal";
	case IMPLIES   : return "`=>'";
	default	       : return "token";
    }
}

static Cell local checkPrec(p)         /* Check for valid precedence value */
Cell p; {
    if (!isInt(p) || intOf(p)<MIN_PREC || intOf(p)>MAX_PREC) {
        ERROR(row) "Precedence value must be an integer in the range [%d..%d]",
                   MIN_PREC, MAX_PREC
        EEND;
    }
    return p;
}

static Void local fixDefn(a,line,p,ops)/* Declare syntax of operators      */
Syntax a;
Cell   line;
Cell   p;
List   ops; {
    Int l = intOf(line);
    a     = mkSyntax(a,intOf(p));
    map2Proc(setSyntax,l,a,ops);
}

static Void local setSyntax(line,sy,op)/* set syntax of individ. operator  */
Int    line;
Syntax sy;
Cell   op; {
    addSyntax(line,textOf(op),sy);
    opDefns = cons(op,opDefns);
}

static Cell local buildTuple(tup)      /* build tuple (x1,...,xn) from list*/
List tup; {                            /* [xn,...,x1]                      */
    Int  n = 0;
    Cell t = tup;
    Cell x;

    do {                               /*     .                    .       */
        x      = fst(t);               /*    / \                  / \      */
        fst(t) = snd(t);               /*   xn  .                .   xn    */
        snd(t) = x;                    /*        .    ===>      .          */
        x      = t;                    /*         .            .           */
        t      = fun(x);               /*          .          .            */
        n++;                           /*         / \        / \           */
    } while (nonNull(t));              /*        x1  NIL   (n)  x1         */
    fst(x) = mkTuple(n);
    return tup;
}

/* The yacc parser presented above is not sufficiently powerful to
 * determine whether a tuple at the front of a sigType is part of a
 * context:    e.g. (Eq a, Num a) => a -> a -> a
 * or a type:  e.g.  (Tree a, Tree a) -> Tree a
 *
 * Rather than complicate the grammar, both are parsed as tuples of types,
 * using the following checks afterwards to ensure that the correct syntax
 * is used in the case of a tupled context.
 */

static List local checkContext(con)	/* validate type class context	   */
Type con; {
    if (con==UNIT)			/* allows empty context ()	   */
	return NIL;
    else if (whatIs(getHead(con))==TUPLE) {
	List qs = NIL;

	while (isAp(con)) {		/* undo work of buildTuple  :-(    */
	    Cell temp = fun(con);
	    fun(con)  = arg(con);
	    arg(con)  = qs;
	    qs	      = con;
	    con       = temp;
	    checkClass(hd(qs));
	}
	return qs;
    }
    else				/* single context expression	   */
	return singleton(checkClass(con));
}

static Cell local checkClass(c)		/* check that type expr is a class */
Cell c; {				/* constrnt of the form C t1 .. tn */
    Cell cn = getHead(c);

    if (!isCon(cn))
	syntaxError("class expression");
    else if (argCount<1) {
	ERROR(row) "Class \"%s\" must have at least one argument",
		   textToStr(textOf(cn))
	EEND;
    }
    return c;
}

static Pair local checkDo(dqs)		/* convert reversed list of dquals */
List dqs; {				/* to a (expr,quals) pair	   */
#if DO_COMPS
    if (isNull(dqs) || whatIs(hd(dqs))!=DOQUAL) {
	ERROR(row) "Last generator in do {...} must be an expression"
	EEND;
    }
    fst(dqs) = snd(fst(dqs));		/* put expression in fst of pair   */
    snd(dqs) = rev(snd(dqs));		/* & reversed list of quals in snd */
#endif
    return dqs;
}

static Cell local checkTyLhs(c)		/* check that lhs is of the form   */
Cell c; {				/* T a1 ... a			   */
    Cell tlhs = c;
    while (isAp(tlhs) && whatIs(arg(tlhs))==VARIDCELL)
	tlhs = fun(tlhs);
    if (whatIs(tlhs)!=CONIDCELL) {
	ERROR(row) "Illegal left hand side in datatype definition"
	EEND;
    }
    return c;
}

/* expressions involving a sequence of two or more infix operator symbols
 * are parsed as elements of type:
 *    InfixExpr ::= [Expr]
 *		 |  ap(ap(Operator,InfixExpr),Expr)
 *
 * thus x0 +1 x1 ... +n xn is parsed as: +n (....(+1 [x0] x1)....) xn
 *
 * Once the expression has been completely parsed, this parsed form is
 * `tidied' according to the precedences and associativities declared for
 * each operator symbol.
 *
 * The tidy process uses a `stack' of type:
 *    TidyStack ::= ap(ap(Operator,TidyStack),Expr)
 *		 |  NIL
 * when the ith layer of an InfixExpr has been transferred to the stack, the
 * stack is of the form: +i (....(+n NIL xn)....) xi
 *
 * The tidy function is based on a simple shift-reduce parser:
 *
 *  tidy                :: InfixExpr -> TidyStack -> Expr
 *  tidy [m]   ss        = foldl (\x f-> f x) m ss
 *  tidy (m*n) []        = tidy m [(*n)]
 *  tidy (m*n) ((+o):ss)
 *	       | amb     = error "Ambiguous"
 *	       | shift   = tidy m ((*n):(+o):ss)
 *	       | reduce  = tidy (m*(n+o)) ss
 *			   where sye     = syntaxOf (*)
 *				 (ae,pe) = sye
 *				 sys     = syntaxOf (+)
 *				 (as,ps) = sys
 *				 amb     = pe==ps && (ae/=as || ae==NON_ASS)
 *				 shift   = pe>ps || (ps==pe && ae==LEFT_ASS)
 *				 reduce  = otherwise
 *
 * N.B. the conditions amb, shift, reduce are NOT mutually exclusive and
 * must be tested in that order.
 *
 * As a concession to efficiency, we lower the number of calls to syntaxOf
 * by keeping track of the values of sye, sys throughout the process.  The
 * value APPLIC is used to indicate that the syntax value is unknown.
 */

static Cell local oTidyInfix(e)         /* convert InfixExpr to Expr        */
Cell e; {                              /* :: InfixExpr                     */
    Cell   s   = NIL;                  /* :: TidyStack                     */
    Syntax sye = APPLIC;               /* Syntax of op in e (init unknown) */
    Syntax sys = APPLIC;               /* Syntax of op in s (init unknown) */
    Cell   temp;

    while (nonNull(tl(e))) {
        if (isNull(s)) {
            s           = e;
            e           = arg(fun(s));
            arg(fun(s)) = NIL;
            sys         = sye;
            sye         = APPLIC;
        }
        else {
            if (sye==APPLIC) {         /* calculate sye (if unknown)       */
                sye = syntaxOf(textOf(fun(fun(e))));
                if (sye==APPLIC) sye=DEF_OPSYNTAX;
            }
            if (sys==APPLIC) {         /* calculate sys (if unknown)       */
                sys = syntaxOf(textOf(fun(fun(s))));
                if (sys==APPLIC) sys=DEF_OPSYNTAX;
            }

            if (precOf(sye)==precOf(sys) &&                      /* amb    */
                   (assocOf(sye)!=assocOf(sys) || assocOf(sye)==NON_ASS)) {
                ERROR(row) "Ambiguous use of operator \"%s\" with \"%s\"",
                           textToStr(textOf(fun(fun(e)))),
                           textToStr(textOf(fun(fun(s))))
                EEND;
            }
            else if (precOf(sye)>precOf(sys) ||                  /* shift  */
                       (precOf(sye)==precOf(sys) && assocOf(sye)==LEFT_ASS)) {
                temp        = arg(fun(e));
                arg(fun(e)) = s;
                s           = e;
                e           = temp;
                sys         = sye;
                sye         = APPLIC;
            }
            else {                                               /* reduce */
                temp        = arg(fun(s));
                arg(fun(s)) = arg(e);
                arg(e)      = s;
                s           = temp;
                sys         = APPLIC;
                /* sye unchanged */
            }
        }
    }

    e = hd(e);
    while (nonNull(s)) {
        temp        = arg(fun(s));
        arg(fun(s)) = e;
        e           = s;
        s           = temp;
    }

    return e;
}
/*-------------------------------------------------------------------------*/
#ifdef __GNUC__
inline 
#endif
static Void local sc(e) /*short circuit dot applications */
Cell e;
{
  Cell temp;
  temp = fun(e);
  if (isDot(fun(temp)))
     fun(e) = arg(temp);
}

static Cell local nTidyInfix(e)         /* convert InfixExpr to Expr        */
Cell e; {                              /* :: InfixExpr                     */
    Cell   s   = NIL;                  /* :: TidyStack                     */
    Syntax sye = APPLIC;               /* Syntax of op in e (init unknown) */
    Syntax sys = APPLIC;               /* Syntax of op in s (init unknown) */
    Cell   temp;

    while (nonNull(tl(e))) {
        if (isNull(s)) {
            s           = e;
            e           = arg(fun(s));
            arg(fun(s)) = NIL;
            sys         = sye;
            sye         = APPLIC;
        }
        else {
            if (sye==APPLIC) {         /* calculate sye (if unknown)       */
                sye = syntaxOf(textOf(fun(fun(e))));
                if (sye==APPLIC) sye=DEF_OPSYNTAX;
            }
            if (sys==APPLIC) {         /* calculate sys (if unknown)       */
                sys = syntaxOf(textOf(fun(fun(s))));
                if (sys==APPLIC) sys=DEF_OPSYNTAX;
            }

            if (precOf(sye)==precOf(sys) &&                      /* amb    */
                   (assocOf(sye)!=assocOf(sys) || assocOf(sye)==NON_ASS)) {
                ERROR(row) "Ambiguous use of operator \"%s\" with \"%s\"",
                           textToStr(textOf(fun(fun(e)))),
                           textToStr(textOf(fun(fun(s))))
                EEND;
            }
            else if (precOf(sye)>precOf(sys) ||                  /* shift  */
                       (precOf(sye)==precOf(sys) && assocOf(sye)==LEFT_ASS)) {
                temp        = arg(fun(e));
                arg(fun(e)) = s;
                s           = e;
                e           = temp;
                sys         = sye;
                sye         = APPLIC;
            }
            else {                                               /* reduce */
                temp        = arg(fun(s));
                arg(fun(s)) = arg(e);
                arg(e)      = s;
                s           = temp;
		sc(arg(e)); /*RPM*/
                sys         = APPLIC;
                /* sye unchanged */
            }
        }
    }

    e = hd(e);
    while (nonNull(s)) {
        temp        = arg(fun(s));
        arg(fun(s)) = e;
        e           = s;
        s           = temp;
	sc(e); /*RPM*/
    }

    return e;
}

/*RPM*/
/*Arunachala Siva Arunachala Ramana*/
#define lType(x) (snd(fst(x)))
#define rType(x) (snd(x))
static Bool local isArrow(Cell x)
{
  return isPair(x) && isPair(fst(x)) && fst(fst(x)) == ARROW;
}
static Bool local tEquals(int line, Cell t1, Cell t2)
/*Assumes Conid ('.' Varid)*  format*/
{
  if (whatIs(t1) == AP && whatIs(t2) == AP)
    return isVar(arg(t1)) && isVar(arg(t2)) &&
                 textOf(arg(t1)) == textOf(arg(t2)) &&
		 tEquals(line, fun(t1), fun(t2));
  else
    return isCon(t1) && isCon(t2) && textOf(t1) == textOf(t2);
}
static Cell local ct1Clause(int line, Cell type, Cell conids)
{
  push(NIL);
  for(; nonNull(conids); conids=tl(conids))
    top() = cons(ct1Const(line, type, hd(conids)), top());

  return pop();
}
static Cell local dupStruct(Cell l)
{
  return isAp(l) ? ap(dupStruct(fst(l)), dupStruct(snd(l))) : l;
}

static Cell local ct1Const(int line, Cell type, Cell conid)
{
  push(conid);
  for (; isArrow(type); type = rType(type))
    top() = ap(top(), dupStruct(lType(type)));

  if (!tEquals(line, typeLhs, type))
  {
    ERROR(line) "ctype target " ETHEN
    ERREXPR(type);
    ERRTEXT " must match header\n" EEND;
  }
  return pop();
}

static Void local typeSyntaxChk(String context, Cell token)
{
  if (newSyntax && !isDot(token))
  {
    ERROR(row) "Syntax Error in %s (application expected)", context EEND;
  }
  else if (!newSyntax && !isNull(token))
  {
     ERROR(row) "Syntax error in %s (unexpected %s)", context,
     textToStr(textOf(token))
     EEND;
  }
}

