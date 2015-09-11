// $Id: ClLinearConstraint.h,v 1.18 1999/05/02 00:43:51 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearConstraint.h

#ifndef ClLinearConstraint_H
#define ClLinearConstraint_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClConstraint.h"
#include "ClLinearExpression.h"


// Add the ClLinearExpression member variable needed for both
// ClLinearEquation and ClLinearInequality
class ClLinearConstraint : public ClConstraint {
 private: typedef ClConstraint super;

 public:

  // Constructor
  ClLinearConstraint(const ClLinearExpression &cle,
		     const ClStrength &strength = ClsRequired(),
		     double weight = 1.0) :
    ClConstraint(strength, weight),
    _expression(cle)
    { }

  // Return my linear Expression.  (For linear equations, this
  // constraint represents Expression=0; for linear inequalities it
  // represents Expression>=0.)
  ClLinearExpression Expression() const
    { return _expression; }

  // do not do this if *this is inside a solver
  void ChangeConstant(Number constant)
    { _expression.Set_constant(constant); }

 protected:

  ClLinearExpression _expression;

  virtual void setExpression( const ClLinearExpression &expr)
    { _expression = expr; }

};

#endif
