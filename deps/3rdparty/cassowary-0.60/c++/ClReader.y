/*
 $Id: ClReader.y,v 1.7 1999/04/28 02:25:57 gjb Exp $

 Cassowary Incremental Constraint Solver
 Original Smalltalk Implementation by Alan Borning
 This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
 http://www.cs.washington.edu/homes/gjb
 (C) 1998, 1999 Greg J. Badros and Alan Borning
 See ../LICENSE for legal details regarding this software

 ClReader.y
 Original implementation contributed by Steve Wolfman
 Subsequently largely revised by Greg J. Badros

 Supports parsing of read-only variables in constraints via "?" suffix
 annotations on variables.  If a variable is followed by "?" in any of
 its occurrences in the constraint, that variable is deemed read-only
 and entered into the constraint object as such.  E.g.,

  x = 2*y?

  is a one-way constraint that sets x from y's value.

  x = y + y?
    and
  x = y? + y
 
  are identical one-way constraints with y read-only.  One would prefer
  to have it written like so:

  x = y? + y?

  but it need not be, and no warning or error is raised.
*/


%{
  /* C Declarations */

#include "Cl.h"
#include <string>
#include <map>

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#ifdef USE_CRUMMY_LEXER
string current;  /* Global to help in debugging/error messages */
#endif

/* Get yyparse, yylex to have an extra argument (type void *) */
#define YYPARSE_PARAM cl_parse_data
#define YYLEX_PARAM cl_parse_data
#ifndef YYERROR_VERBOSE
#define YYERROR_VERBOSE
#endif
#define YYDEBUG 1

%}


/* Bison Declarations */

%pure_parser

%union {
  double num;
  const ClVariable *pclv;
  ClLinearExpression *pcle;
  ClConstraint *pcn;
}

%{
int yylex(YYSTYPE *lvalp, void *YYLEX_PARAM);
void yyerror(const char *sz);
%}

%start constraint

%token <num> NUM
%token <pclv> VAR
%token <pclv> RO_VAR

%token GEQ
%token GT
%token LEQ
%token LT

%type <pcle> expr
%type <pcn> constraint equation inequality

%left '-' '+'
%left '*' '/'
%left NEG

%%
/* Grammar Rules */

constraint:     equation  { $$ = $1; ((ClParseData*)YYPARSE_PARAM)->_pcn = $1; }
            | inequality  { $$ = $1; ((ClParseData*)YYPARSE_PARAM)->_pcn = $1; }
;

equation:  expr '=' expr  { $$ = new ClLinearEquation(*$1, *$3);   }
;

inequality: expr GEQ expr { $$ = new ClLinearInequality(*$1, cnGEQ, *$3); }
          | expr LEQ expr { $$ = new ClLinearInequality(*$1, cnLEQ, *$3); }
          | expr LT  expr { $$ = new ClLinearInequality(*$1, cnLT,  *$3); }
          | expr GT  expr { $$ = new ClLinearInequality(*$1, cnGT,  *$3); }
;

expr:     NUM                { $$ = new ClLinearExpression($1);        }
	| VAR                { $$ = new ClLinearExpression(*$1);       }
        | RO_VAR             { $$ = new ClLinearExpression(*$1);
                               ((ClParseData*)YYPARSE_PARAM)->_readOnlyVarsSoFar.insert(*$1); }
	| expr '+' expr      { $$ = new ClLinearExpression(*$1 + *$3); }
	| expr '-' expr      { $$ = new ClLinearExpression(*$1 - *$3); }
	| expr '*' expr      { $$ = new ClLinearExpression(*$1 * *$3); }
	| expr '/' expr      { $$ = new ClLinearExpression(*$1 / *$3); }
	| '-' expr %prec NEG { $$ = new ClLinearExpression(-1 * *$2);  }
	| '(' expr ')'       { $$ = $2;                                }
;

%%

void clerror(const char *sz)
{
  throw ExCLParseErrorMisc(sz);
}

extern istream *pxi_lexer;

// xi is the stream from which to read the constraint.
// aVars is an array of variables large enough to account for
// each one that might be mentioned in a constraint
ClConstraint *PcnParseConstraint(istream &xi, const ClVarLookupFunction &lookup_func, 
	const ClStrength &strength)
{
  ClParseData cl_parse_data(xi, lookup_func);
  pxi_lexer = &xi;
  if (yyparse(&cl_parse_data) == 0) { // success
#ifdef DEBUG_PARSER
    cerr << *cl_parse_data.Pcn() << endl;
#endif
    cl_parse_data.Pcn()->ChangeStrength(strength);
    cl_parse_data.Pcn()->AddROVars(cl_parse_data._readOnlyVarsSoFar);
    return cl_parse_data.Pcn();
  }
  else { // failed
    return 0;
  }
}
