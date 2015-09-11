// $Id: ClLinearExpression.h,v 1.51 1999/07/12 02:38:59 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearExpression.h

#ifndef ClLinearExpression_H
#define ClLinearExpression_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "ClMap.h"
#include "Cassowary.h"
#include "debug.h"
#include "ClVariable.h"
#include "ClLinearExpression_fwd.h"

using namespace std;

class ClSimplexSolver;
class ClTableau;
class ClSymbolicWeight;

ClLinearExpression &cleNil();

template <class T>
#ifdef USE_GC_EXP
class ClGenericLinearExpression : public gc {
#else
class ClGenericLinearExpression  {
#endif
 public:
  typedef ClMap<ClVariable,T> ClVarToCoeffMap;

  // convert Number-s into ClLinearExpression-s
  ClGenericLinearExpression(T num = 0.0);

  // Convert from ClVariable to a ClLinearExpression
  // this replaces ClVariable::asLinearExpression
  ClGenericLinearExpression(ClVariable clv, T value = 1.0, T constant = 0.0);

  // copy ctr
  ClGenericLinearExpression(const ClGenericLinearExpression<T> &expr) :
    _constant(expr._constant),
    _terms(expr._terms)
    { }

  virtual ~ClGenericLinearExpression();

  // Return a new linear expression formed by multiplying self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> Times(Number x) const;

  // Return a new linear expression formed by multiplying self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> Times(const ClGenericLinearExpression<T> &expr) const;

  // Return a new linear expression formed by adding x to self.
  ClGenericLinearExpression<T> Plus(const ClGenericLinearExpression<T> &expr) const;

  // Return a new linear expression formed by subtracting x from self.
  ClGenericLinearExpression<T> Minus(const ClGenericLinearExpression<T> &expr) const;

  // Return a new linear expression formed by dividing self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> Divide(Number x) const;



  // Return a new linear expression formed by multiplying self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> *P_times(Number x) const
    { return new ClGenericLinearExpression<T>(Times(x)); }

  // Return a new linear expression formed by adding x to self.
  ClGenericLinearExpression<T> *P_plus(const ClGenericLinearExpression<T> &expr) const
    { return new ClGenericLinearExpression<T>(Plus(expr)); }

  // Return a new linear expression formed by subtracting x from self.
  ClGenericLinearExpression<T> *P_minus(const ClGenericLinearExpression<T> &expr) const
    { return new ClGenericLinearExpression<T>(Minus(expr)); }

  // Return a new linear expression formed by dividing self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> *P_divide(Number x) const
    { return new ClGenericLinearExpression<T>(Divide(x)); }

  // Return a new linear expression formed by dividing self by x.
  // (Note that this result must be linear.)
  ClGenericLinearExpression<T> Divide(const ClGenericLinearExpression<T> &expr) const;

  // Return a new linear expression (aNumber/this).  Since the result
  // must be linear, this is permissible only if 'this' is a constant.
  ClGenericLinearExpression<T> DivFrom(const ClGenericLinearExpression<T> &expr) const;

  // Return a new linear expression (aNumber-this).
  ClGenericLinearExpression<T> SubtractFrom(const ClGenericLinearExpression<T> &expr) const
  { return expr.Minus(*this); }

  // Add n*expr to this expression from another expression expr.
  ClGenericLinearExpression<T> &AddExpression(const ClGenericLinearExpression<T> &expr, 
				    Number n = 1.0);

  // Add n*expr to this expression from another expression expr.
  // Notify the solver if a variable is added or deleted from this
  // expression.
  ClGenericLinearExpression<T> &AddExpression(const ClGenericLinearExpression<T> &expr, Number n,
				    ClVariable subject,
				    ClTableau &solver);

  // Add a term c*v to this expression.  If the expression already
  // contains a term involving v, Add c to the existing coefficient.
  // If the new coefficient is approximately 0, delete v.
  ClGenericLinearExpression<T> &AddVariable(ClVariable v, T c = 1.0);

  // Add a term c*v to this expression.  If the expression already
  // contains a term involving v, Add c to the existing coefficient.
  // If the new coefficient is approximately 0, delete v.
  ClGenericLinearExpression<T> &setVariable(ClVariable v, T c)
    {assert(c != 0.0);  _terms[v] = c; return *this; }

  // Add a term c*v to this expression.  If the expression already
  // contains a term involving v, Add c to the existing coefficient.
  // If the new coefficient is approximately 0, delete v.  Notify the
  // solver if v appears or disappears from this expression.
  ClGenericLinearExpression<T> &AddVariable(ClVariable v, T c,
				  ClVariable subject,
				  ClTableau &solver);

  // Return a pivotable variable in this expression.  (It is an error
  // if this expression is constant -- signal ExCLInternalError in
  // that case).  Return NULL if no pivotable variables
  ClVariable AnyPivotableVariable() const;

  // Replace var with a symbolic expression expr that is equal to it.
  // If a variable has been added to this expression that wasn't there
  // before, or if a variable has been dropped from this expression
  // because it now has a coefficient of 0, inform the solver.
  // PRECONDITIONS:
  //   var occurs with a non-Zero coefficient in this expression.
  void SubstituteOut(ClVariable v, 
		     const ClGenericLinearExpression<T> &expr,
		     ClVariable subject,
		     ClTableau &solver);

  // This linear expression currently represents the equation
  // oldSubject=self.  Destructively modify it so that it represents
  // the equation NewSubject=self.
  //
  // Precondition: NewSubject currently has a nonzero coefficient in
  // this expression.
  //
  // NOTES
  //   Suppose this expression is c + a*NewSubject + a1*v1 + ... + an*vn.
  //
  //   Then the current equation is 
  //       oldSubject = c + a*NewSubject + a1*v1 + ... + an*vn.
  //   The new equation will be
  //        NewSubject = -c/a + oldSubject/a - (a1/a)*v1 - ... - (an/a)*vn.
  //   Note that the term involving NewSubject has been dropped.
  void ChangeSubject(ClVariable old_subject,
		     ClVariable new_subject);

  // This linear expression currently represents the equation self=0.  Destructively modify it so 
  // that subject=self represents an equivalent equation.  
  //
  // Precondition: subject must be one of the variables in this expression.
  // NOTES
  //   Suppose this expression is
  //     c + a*subject + a1*v1 + ... + an*vn
  //   representing 
  //     c + a*subject + a1*v1 + ... + an*vn = 0
  // The modified expression will be
  //    subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn
  //   representing
  //    subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn
  //
  // Note that the term involving subject has been dropped.
  // Returns the reciprocal, so ChangeSubject can use it, too
  T NewSubject(ClVariable subject);

  // Return the value of the linear expression
  // given the current assignments of values to contained variables
  T Evaluate() const;

  // Return the coefficient corresponding to variable var, i.e.,
  // the 'ci' corresponding to the 'vi' that var is:
  //     v1*c1 + v2*c2 + .. + vn*cn + c
  T CoefficientFor(ClVariable var) const
    { 
    typename ClVarToCoeffMap::const_iterator it = _terms.find(var);
    if (it != _terms.end())
      return (*it).second;
    return 0.0;
    }

  T Constant() const
    { return _constant; }

  void Set_constant(T c)
    { _constant = c; }

  const ClVarToCoeffMap &Terms() const
    { return _terms; }

  ClVarToCoeffMap &Terms() 
    { return _terms; }

  void IncrementConstant(T c)
    { _constant += c; }

  bool IsConstant() const
    { return _terms.size() == 0; }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const;

  friend ostream &operator<<(ostream &xo,const ClGenericLinearExpression<T> &cle)
    { return cle.PrintOn(xo); }
#endif

  friend ClGenericLinearExpression<T> operator+(const ClGenericLinearExpression<T> &e1,
				      const ClGenericLinearExpression<T> &e2)
    { return e1.Plus(e2); }

  friend ClGenericLinearExpression<T> operator-(const ClGenericLinearExpression<T> &e1,
				      const ClGenericLinearExpression<T> &e2)
    { return e1.Minus(e2); }

  friend ClGenericLinearExpression<T> operator*(const ClGenericLinearExpression<T> &e1,
				      const ClGenericLinearExpression<T> &e2)
    { return e1.Times(e2); }


  friend ClGenericLinearExpression<T> operator/(const ClGenericLinearExpression<T> &e1,
				      const ClGenericLinearExpression<T> &e2)
    { return e1.Divide(e2); }

  // FIXGJB -- this may be wrong -- should test underlying expression for equality
  friend bool operator==(const ClGenericLinearExpression<T> &e1,
			 const ClGenericLinearExpression<T> &e2)
    { return &e1 == &e2; }

  /// Named versions of the operator functions for ease of
  /// wrapping, or expressing using prefix notation

  friend ClGenericLinearExpression<T> Plus(const ClGenericLinearExpression<T> &e1,
				 const ClGenericLinearExpression<T> &e2)
    { return e1.Plus(e2); }

  friend ClGenericLinearExpression<T> Minus(const ClGenericLinearExpression<T> &e1,
				  const ClGenericLinearExpression<T> &e2)
    { return e1.Minus(e2); }

  friend ClGenericLinearExpression<T> Times(const ClGenericLinearExpression<T> &e1,
				  const ClGenericLinearExpression<T> &e2)
    { return e1.Times(e2); }


  friend ClGenericLinearExpression<T> *Divide(const ClGenericLinearExpression<T> &e1,
				   const ClGenericLinearExpression<T> &e2)
    { return new ClGenericLinearExpression<T>(e1.Divide(e2)); }

  friend ClGenericLinearExpression<T> *p_Plus(const ClGenericLinearExpression<T> &e1,
				   const ClGenericLinearExpression<T> &e2)
    { return new ClGenericLinearExpression<T>(e1.Plus(e2)); }

  friend ClGenericLinearExpression<T> *p_Minus(const ClGenericLinearExpression<T> &e1,
				    const ClGenericLinearExpression<T> &e2)
    { return new ClGenericLinearExpression<T>(e1.Minus(e2)); }

  friend ClGenericLinearExpression<T> *p_Times(const ClGenericLinearExpression<T> &e1,
				    const ClGenericLinearExpression<T> &e2)
    { return new ClGenericLinearExpression<T>(e1.Times(e2)); }

  friend ClGenericLinearExpression<T> *p_Divide(const ClGenericLinearExpression<T> &e1,
				     const ClGenericLinearExpression<T> &e2)
    { return new ClGenericLinearExpression<T>(e1.Divide(e2)); }


  // FIXGJB -- this may be wrong -- should test underlying expression for equality
  friend bool FEquals(const ClGenericLinearExpression<T> &e1,
		      const ClGenericLinearExpression<T> &e2)
    { return &e1 == &e2; }

  ClGenericLinearExpression<T> &MultiplyMe(T x);

 private:

  T _constant;
  ClVarToCoeffMap _terms;

};

typedef ClGenericLinearExpression<Number>::ClVarToCoeffMap ClVarToNumberMap;

#endif
