// clang-format off
/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_RULES_TAB_H_INCLUDED
# define YY_YY_RULES_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AT = 258,
     NUMBER = 259,
     STRING = 260,
     IDENTIFIER = 261,
     LEFT_PARENTHESIS = 262,
     RIGHT_PARENTHESIS = 263,
     LEFT_CURLY_BRACES = 264,
     RIGHT_CURLY_BRACES = 265,
     LEFT_BRACKETS = 266,
     RIGHT_BRACKETS = 267,
     EQUAL = 268,
     NOT_EQUAL = 269,
     LESS_THAN = 270,
     GREATER_THAN = 271,
     EQUAL_AND_LESS_THAN = 272,
     EQUAL_AND_GREATER_THAN = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     PERIOD = 277,
     MINUS = 278,
     PLUS = 279,
     DIVIDE = 280,
     MULTIPLY = 281,
     EXPONENT = 282,
     ASSIGN = 283,
     COMA = 284,
     DOLLAR = 285,
     PERCENT = 286,
     BETWEEN = 287,
     CONTAINS = 288,
     YY_IN = 289,
     BEGINS_WITH = 290,
     ENDS_WITH = 291,
     LIKE = 292,
     MATCHES = 293,
     ANY = 294,
     ALL = 295,
     NONE = 296,
     SOME = 297,
     TRUE_PREDICATE = 298,
     FALSE_PREDICATE = 299,
     NULL_FLAG = 300,
     TRUE_FLAG = 301,
     FALSE_FLAG = 302,
     SELF = 303,
     FIRST = 304,
     LAST = 305,
     YY_SIZE = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 33 "rules.y"

    NSPredicate *predicate;
    NSNumber *number;
    NSString* string;
    NSMutableArray *array;
    NSExpression *expression;

    NSMutableString *parserString;

    struct {
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } operatorR;

    struct {
        NSExpression *lhs;
        NSExpression *rhs;
        NSPredicateOperatorType type;
        NSComparisonPredicateOptions options;
    } comparisonS;

    NSPredicateOperatorType operatorType;
    va_list arguments;


/* Line 2058 of yacc.c  */
#line 134 "rules.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void*  scanner, nextArgument nextArg, NSPredicate **predicate);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_RULES_TAB_H_INCLUDED  */

// clang-format on