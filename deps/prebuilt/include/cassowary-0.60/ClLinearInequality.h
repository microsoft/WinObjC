// $Id: ClLinearInequality.h,v 1.24 1999/11/24 23:41:00 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearInequality.h

#ifndef ClLinearInequality_H
#define ClLinearInequality_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "ClLinearConstraint.h"

class ClVariable;

class ClLinearInequality : public ClLinearConstraint {
 private: typedef ClLinearConstraint super;

 public:
 //// Constructors
 // ClLinearInequality(expr,...)  is expr >= 0
 ClLinearInequality(const ClLinearExpression &cle,
		    const ClStrength &strength = ClsRequired(),
		    double weight = 1.0) :
   ClLinearConstraint(cle,strength, weight),
   _fStrictInequality(false)
   { }

 // ClLinearInequality(var,OP,expr) is  var >= expr
 ClLinearInequality(const ClVariable clv,
		    ClCnRelation op,
		    const ClLinearExpression &cle,
		    const ClStrength &strength = ClsRequired(),
		    double weight = 1.0) :
   ClLinearConstraint( cle, strength, weight),
   _fStrictInequality(false)
   { 
   if (op == cnGEQ || op == cnGT)
     {
     _expression.MultiplyMe(-1.0);
     _expression.AddVariable(clv,1.0);
     }
   else if (op == cnLEQ || op == cnGEQ)
     {
     _expression.AddVariable(clv,-1.0);
     }
   else
     {
       throw ExCLEditMisuse("Cannot use that operator for ClLinearInequality objects");
     }
   if (op == cnLT || op == cnGT) {
     _fStrictInequality = true;
   }
   }

#ifdef FIXGJB_AMBIGUOUS
 // ClLinearInequality(expr,OP,var) is  var ?<>? expr
 ClLinearInequality(const ClLinearExpression &cle,
		    ClCnRelation op,
		    const ClVariable clv,
		    const ClStrength &strength = ClsRequired(),
		    double weight = 1.0) :
   ClLinearConstraint( cle, strength, weight),
   _fStrictInequality(false)
   { 
   if (op == cnLEQ || op == cnLT)
     {
     _expression.MultiplyMe(-1.0);
     _expression.AddVariable(clv,1.0);
     }
   else if (op == cnGEQ || op == cnGT)
     {
     _expression.AddVariable(clv,-1.0);
     }
   if (op == cnLT || op == cnGT) {
     _fStrictInequality = true;
   }
   }
#endif

 // ClLinearInequality(expr,OP,expr) is  expr >= expr
 ClLinearInequality(const ClLinearExpression &cle1,
		    ClCnRelation op,
		    const ClLinearExpression &cle2,
		    const ClStrength &strength = ClsRequired(),
		    double weight = 1.0) :
   ClLinearConstraint( cle2, strength, weight),
   _fStrictInequality(false)
   { 
   if (op == cnGEQ || op == cnGT)
     {
     _expression.MultiplyMe(-1.0);
     _expression.AddExpression(cle1);
     }
   else if (op == cnLEQ || op == cnLT)
     {
     _expression.AddExpression(cle1,-1.0);
     }
   if (op == cnLT || op == cnGT) {
     _fStrictInequality = true;
   }
   }

#ifdef FIXGJB_AMBIGUOUS
 // ClLinearInequality(var,OP,var) is  var ?<>? var
 ClLinearInequality(const ClVariable clv1,
		    ClCnRelation op,
		    const ClVariable clv2,
		    const ClStrength &strength = ClsRequired(),
		    double weight = 1.0) :
   ClLinearConstraint( clv2, strength, weight),
   _fStrictInequality(false)
   { 
   if (op == cnGEQ || op == cnGT)
     {
     _expression.MultiplyMe(-1.0);
     _expression.AddVariable(clv1,1.0);
     }
   else if (op == cnLEQ || op == cnLT)
     {
     _expression.AddVariable(clv1,-1.0);
     }
   if (op == cnLT || op == cnGT) {
     _fStrictInequality = true;
   }
   }
#endif

 
 // Return true if this is an inequality constraint and
 // false if it is an equality constraint.  The default is
 // that it is not.
 virtual bool IsInequality() const
   { return true; }

 virtual bool IsStrictInequality() const
   { return _fStrictInequality; }

#ifndef CL_NO_IO 
 virtual ostream &PrintOn(ostream &xo) const
   {  super::PrintOn(xo); xo << " >= 0 )"; return xo; }
#endif

  virtual bool FIsSatisfied() const
    { 
      Number v = _expression.Evaluate();
      if (_fStrictInequality) 
        return (v > 0);
      else 
        return (v >= 0);
    }

 private:

  bool _fStrictInequality;
};

#endif
