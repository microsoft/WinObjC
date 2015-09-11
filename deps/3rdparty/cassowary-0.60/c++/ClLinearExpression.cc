// $Id: ClLinearExpression.cc,v 1.46 1999/04/20 00:24:59 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearExpression.cc


#include "ClLinearExpression.h"
#include "ClSymbolicWeight.h"  /// needed only to instantiate with T=ClSymbolicWeight
#include "ClVariable.h"
#include "ClTableau.h"
#include "ClErrors.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

template <class T>
ClGenericLinearExpression<T>::ClGenericLinearExpression(T num) :
    _constant(num)
{ }

// Convert from ClVariable to a ClLinearExpression
// this replaces ClVariable::asLinearExpression
template <class T>
ClGenericLinearExpression<T>::ClGenericLinearExpression(ClVariable clv, T value,
                                                        T Constant) :
  _constant(Constant)
{
  _terms[clv] = value;
}

template <class T>
ClGenericLinearExpression<T>::~ClGenericLinearExpression()
{ }

#ifndef CL_NO_IO
template <class T>
ostream &
ClGenericLinearExpression<T>::PrintOn(ostream &xo) const
{
  typename ClVarToCoeffMap::const_iterator i = _terms.begin();

  if (!ClApprox(_constant,0.0) || i == _terms.end())
    {
    xo << _constant;
    }
  else
    {
    if (i == _terms.end())
      return xo;
    xo << (*i).second << "*" << (*i).first;
    ++i;
    }
  for ( ; i != _terms.end(); ++i)
    {
    xo << " + " << (*i).second << "*" << (*i).first;
    }
  return xo;
}
#endif



// Destructively multiply self by x.
// (private memfn)
template <class T>
ClGenericLinearExpression<T> &
ClGenericLinearExpression<T>::MultiplyMe(T x)
{
  _constant *= x;

  typename ClVarToCoeffMap::const_iterator i = _terms.begin();
  for ( ; i != _terms.end(); ++i)
    {
    _terms[(*i).first] = (*i).second * x;
    }
  return *this;
}

// Return a new linear expression formed by multiplying self by x.
// (Note that this result must be linear.)
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Times(Number x) const
{
  ClGenericLinearExpression<T> result = *this;
  return result.MultiplyMe(x);
}

// Return a new linear expression formed by multiplying self by x.
// (Note that this result must be linear.)
// The above function optimizes the specific case of multiplying
// by a Constant, here is the more general case
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Times(const ClGenericLinearExpression<T> &expr) const
{
  if (IsConstant())
    {
    return expr.Times(_constant);
    }
  else if (!expr.IsConstant())
    {
    // neither are constants, so we'd introduce non-linearity
    throw ExCLNonlinearExpression();
    }	
  return Times(expr._constant);
}


// Return a new linear expression formed by adding x to self.
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Plus(const ClGenericLinearExpression<T> &expr) const
{
  ClGenericLinearExpression<T> result = *this;
  result.AddExpression(expr,1.0);
  return result;
}

// Return a new linear expression formed by subtracting x from self.
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Minus(const ClGenericLinearExpression<T> &expr) const
{
  ClGenericLinearExpression<T> result = *this;
  result.AddExpression(expr,-1.0);
  return result;
}

// Return a new linear expression formed by dividing self by x.
// (Note that this result must be linear.)
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Divide(Number x) const
{
  if (ClApprox(x,0.0))
    {
    throw ExCLNonlinearExpression();
    }
  return Times(1.0/x);
}

// Return a new linear expression formed by dividing self by x.
// (Note that this result must be linear.)
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::Divide(const ClGenericLinearExpression<T> &expr) const
{
  if (!expr.IsConstant())
    {
    throw ExCLNonlinearExpression();
    }
  return Divide(expr._constant);
}


// Return a new linear expression (expr/this).  Since the result
// must be linear, this is permissible only if 'this' is a Constant.
template <class T>
ClGenericLinearExpression<T> 
ClGenericLinearExpression<T>::DivFrom(const ClGenericLinearExpression<T> &expr) const
{
  if (!IsConstant() || ClApprox(_constant,0.0))
    {
    throw ExCLNonlinearExpression();
    }
  return expr.Divide(_constant);
}

// Add n*expr to this expression for another expression expr.
template <class T>
ClGenericLinearExpression<T> &
ClGenericLinearExpression<T>::AddExpression(const ClGenericLinearExpression<T> &expr, Number n)
{
  IncrementConstant(expr.Constant()*n);

  typename ClVarToCoeffMap::const_iterator i = expr._terms.begin();
  for ( ; i != expr._terms.end(); ++i)
    {
    AddVariable((*i).first, (*i).second * n);
    }
  return *this;
}

// Add n*expr to this expression for another expression expr.
// Notify the solver if a variable is added or deleted from this
// expression.
template <class T>
ClGenericLinearExpression<T> &
ClGenericLinearExpression<T>::AddExpression(const ClGenericLinearExpression<T> &expr, Number n,
				  ClVariable subject,
				  ClTableau &solver)
{
  IncrementConstant(expr.Constant() * n);

  typename ClVarToCoeffMap::const_iterator i = expr._terms.begin();
  for ( ; i != expr._terms.end(); ++i)
    {
    AddVariable((*i).first, (*i).second * n, subject, solver);
    }
  return *this;
}

// Add a term c*v to this expression.  If the expression already
// contains a term involving v, Add c to the existing coefficient.
// If the new coefficient is approximately 0, delete v.
template <class T>
ClGenericLinearExpression<T> &
ClGenericLinearExpression<T>::AddVariable(ClVariable v, T c)
{ // body largely duplicated below
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << v << ", " << c << ")" << endl;
#endif
  typename ClVarToCoeffMap::iterator i = _terms.find(v);
  if (i != _terms.end())
    {
    // expression already contains that variable, so Add to it
    T new_coefficient = 0;
    new_coefficient = (*i).second + c;
    if (ClApprox(new_coefficient,0.0))
      {
      // new coefficient is Zero, so erase it
      _terms.erase(i);
      }
    else
      {
      (*i).second = new_coefficient;
      }
    }
  else // expression did not contain that variable
    {
    if (!ClApprox(c,0.0))
      {
      _terms[v] = c;
      }
    }
  return *this;
}

// Add a term c*v to this expression.  If the expression already
// contains a term involving v, Add c to the existing coefficient.
// If the new coefficient is approximately 0, delete v.  Notify the
// solver if v appears or disappears from this expression.
template <class T>
ClGenericLinearExpression<T> &
ClGenericLinearExpression<T>::AddVariable(ClVariable v, T c,
                                          ClVariable subject,
                                          ClTableau &solver)
{ // body largely duplicated above
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << v << ", " << c << ", " << subject << ", ...)" << endl;
#endif
  typename ClVarToCoeffMap::iterator i = _terms.find(v);
  if (i != _terms.end())
    {
    // expression already contains that variable, so Add to it
    T new_coefficient = (*i).second + c;
    if (ClApprox(new_coefficient,0.0))
      {
      // new coefficient is Zero, so erase it
      solver.NoteRemovedVariable((*i).first,subject);
      _terms.erase(i);
      }
    else
      {
      (*i).second = new_coefficient;
      }
    }
  else // expression did not contain that variable
    {
    if (!ClApprox(c,0.0))
      {
      _terms[v] = c;
      solver.NoteAddedVariable(v,subject);
      }
    }
#ifdef CL_TRACE
  cerr << "Now *this == " << *this << endl;
#endif
  return *this;
}

// Return a variable in this expression.  (It is an error if this
// expression is Constant -- signal ExCLInternalError in that case).
template <class T>
ClVariable
ClGenericLinearExpression<T>::AnyPivotableVariable() const
{
  if (IsConstant())
    {
    throw ExCLInternalError("(ExCLInternalError) No pivotable variables in Constant expression");
    }
  typename ClVarToCoeffMap::const_iterator i = _terms.begin();
  for ( ; i != _terms.end(); ++i)
    {
    ClVariable v = (*i).first;
    if (v.IsPivotable())
      return v;
    }
  return clvNil;
}

// Replace var with a symbolic expression expr that is equal to it.
// If a variable has been added to this expression that wasn't there
// before, or if a variable has been dropped from this expression
// because it now has a coefficient of 0, inform the solver.
// PRECONDITIONS:
//   var occurs with a non-Zero coefficient in this expression.
template <class T>
void 
ClGenericLinearExpression<T>::SubstituteOut(ClVariable var, 
                                            const ClGenericLinearExpression<T> &expr,
                                            ClVariable subject,
                                            ClTableau &solver)
{
#ifdef CL_TRACE
  cerr << "* ClGenericLinearExpression::";
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << var << ", " << expr << ", " << subject << ", " 
       << solver << ")" << endl;
  cerr << "*this == " << *this << endl;
#endif

  typename ClVarToCoeffMap::iterator pv = _terms.find(var);

#ifndef NDEBUG
  if (pv == _terms.end())
    {
#ifndef CL_NO_IO
    cerr << "SubstituteOut: pv != _terms.end()" << endl;
    cerr << "(" << var << ", " << expr << ", " << subject << ", " 
         << ")" << endl;
    cerr << "*this == " << *this << endl;
#endif
    throw "SubstituteOut: pv != _terms.end()";
    }
#endif
  assert(pv != _terms.end());
  // FIXGJB: this got thrown! assert(!ClApprox((*pv).second,0.0));

  T multiplier = (*pv).second;
  _terms.erase(pv);
  IncrementConstant(multiplier * expr._constant);
  typename ClVarToCoeffMap::const_iterator i = expr._terms.begin();
  for ( ; i != expr._terms.end(); ++i)
    {
    ClVariable v = (*i).first;
    T c = (*i).second;
    typename ClVarToCoeffMap::iterator poc = _terms.find(v);
    if (poc != _terms.end())
      { // if oldCoeff is not nil
#ifdef CL_TRACE
      cerr << "Considering (*poc) == " << (*poc).second << "*" << (*poc).first << endl;
#endif
      // found it, so new coefficient is old one Plus what is in *i
      T newCoeff = (*poc).second + (multiplier*c);
      if (ClApprox(newCoeff,0.0))
	{
	solver.NoteRemovedVariable((*poc).first,subject);
	_terms.erase(poc);
	}
      else
	{
	(*poc).second = newCoeff;
	}
      }
    else
      { // did not have that variable already (oldCoeff == nil)
#ifdef CL_TRACE
      cerr << "Adding (*i) == " << (*i).second << "*" << (*i).first << endl;
#endif
      _terms[v] = multiplier * c;
      solver.NoteAddedVariable(v,subject);
      }
    }
#ifdef CL_TRACE
  cerr << "Now (*this) is " << *this << endl;
#endif
}

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
// 
// Basically, we consider the expression to be an equation with oldSubject
// equal to the expression, then Resolve the equation for NewSubject,
// and destructively make the expression what NewSubject is then equal to
template <class T>
void 
ClGenericLinearExpression<T>::ChangeSubject(ClVariable old_subject,
                                            ClVariable new_subject)
{
  _terms[old_subject] = NewSubject(new_subject);
}

inline double ReciprocalOf(double n)
{ return 1.0/n; }

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
//    subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn = 0
//
// Note that the term involving subject has been dropped.
//
// Returns the reciprocal, so that NewSubject can be used by ChangeSubject
template <class T>
T
ClGenericLinearExpression<T>::NewSubject(ClVariable subject)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << subject << ")" << endl;
#endif
  typename ClVarToCoeffMap::iterator pnewSubject = _terms.find(subject);
  assert(pnewSubject != _terms.end());
  //  assert(!ClApprox((*pnewSubject).second,0.0));
  T reciprocal = ReciprocalOf((*pnewSubject).second);
  _terms.erase(pnewSubject);
  MultiplyMe(-reciprocal);
  return reciprocal;
}

template <class T>
T
ClGenericLinearExpression<T>::Evaluate() const
{
  T answer = _constant;
  typename ClVarToCoeffMap::const_iterator i = _terms.begin();

  for ( ; i != _terms.end(); ++i)
    {
    ClVariable v = (*i).first;
    answer += (*i).second * v.Value();
    }
  return answer;
}


template class ClGenericLinearExpression<Number>;
// template class ClGenericLinearExpression<ClSymbolicWeight>;
