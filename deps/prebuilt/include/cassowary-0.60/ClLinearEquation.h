// $Id: ClLinearEquation.h,v 1.23 1999/04/20 00:24:58 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearEquation.h

#ifndef ClLinearEquation_H
#define ClLinearEquation_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClLinearConstraint.h"
#include "ClLinearExpression.h"

class ClStrength;
class ClVariable;

class ClLinearEquation : public ClLinearConstraint {
 private: typedef ClLinearConstraint super;

 public:
 //// Constructors

 // ClLinearEquation(expr,...)    is   expr == 0
 ClLinearEquation(const ClLinearExpression &cle,
		  const ClStrength &strength = ClsRequired(),
		  double weight = 1.0) :
   ClLinearConstraint(cle,strength, weight)
   { }

 // ClLinearEquation(var,expr,...)  is   var == expr
 ClLinearEquation(ClVariable clv,
		  const ClLinearExpression &cle,
		  const ClStrength &strength = ClsRequired(),
		  double weight = 1.0) :
   ClLinearConstraint(cle,strength,weight)
   { _expression.AddVariable(clv,-1.0); }

 // ClLinearEquation(expr,var,...) is   var == expr
 ClLinearEquation(const ClLinearExpression &cle,
		  ClVariable clv,
		  const ClStrength &strength = ClsRequired(),
		  double weight = 1.0) :
   ClLinearConstraint(cle,strength,weight)
   { _expression.AddVariable(clv,-1.0); }

 // ClLinearEquation(expr,expr,...) is   expr == expr
 ClLinearEquation(const ClLinearExpression &cle1,
		  const ClLinearExpression &cle2,
		  const ClStrength &strength = ClsRequired(),
		  double weight = 1.0) :
   ClLinearConstraint(cle1,strength,weight)
   { _expression.AddExpression(cle2,-1.0); }

#ifndef CL_NO_IO 
 virtual ostream &PrintOn(ostream &xo) const
   {  super::PrintOn(xo); xo << " = 0 )"; return xo; }
#endif

  virtual bool FIsSatisfied() const
    { return (_expression.Evaluate() == 0); }

};

#endif
