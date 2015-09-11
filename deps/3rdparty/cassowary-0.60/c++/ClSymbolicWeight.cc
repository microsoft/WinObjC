// $Id: ClSymbolicWeight.cc,v 1.19 1999/09/06 19:27:43 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSymbolicWeight.cc

#include "Cassowary.h"
#include "ClSymbolicWeight.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

// Help g++ out, tell it to instantiate this
//template vector<double> &vector<double>::operator =(const vector<double> &);

ClSymbolicWeight::ClSymbolicWeight(int CLevels, double value) :
  _values(CLevels, value)
{ 
  assert(_values.size() == CLevels);
}

ClSymbolicWeight::ClSymbolicWeight(double w1, double w2, double w3)
{
  _values.push_back(w1);
  _values.push_back(w2);
  _values.push_back(w3);
  assert(_values.size() == 3);
}

ClSymbolicWeight::ClSymbolicWeight(const vector<double> &weights) :
  _values(weights)
{ }

ClSymbolicWeight &
ClSymbolicWeight::Zero()
{
  static ClSymbolicWeight Zero(0.0, 0.0, 0.0);
  return Zero;
}


ClSymbolicWeight &
ClSymbolicWeight::negated()
{
  vector<double>::iterator it = _values.begin();
  for (; it != _values.end(); ++it)
    {
    *it = -*it;
    }
  return *this;
}

ClSymbolicWeight &
ClSymbolicWeight::MultiplyMe(Number n)
{
  vector<double>::iterator it = _values.begin();
  for (; it != _values.end(); ++it)
    {
    *it *= n;
    }
  return *this;
}


ClSymbolicWeight 
ClSymbolicWeight::DivideBy(Number n) const
{
  assert(n!=0);
  ClSymbolicWeight clsw(0);
  vector<double>::const_iterator i = _values.begin();
  for (; i != _values.end(); ++i)
    {
    clsw.push_back(*i / n);
    }
  return clsw;
}

ClSymbolicWeight &
ClSymbolicWeight::addtoMe(const ClSymbolicWeight &cl)
{
  assert(cl.CLevels() == CLevels());

  vector<double>::iterator i1 = _values.begin();
  vector<double>::const_iterator i2 = cl._values.begin();
  for (; i1 != _values.end(); ++i1, ++i2)
    {
    *i1 += *i2;
    }
  return *this;
}

ClSymbolicWeight 
ClSymbolicWeight::Subtract(const ClSymbolicWeight &cl) const
{
  assert(cl.CLevels() == CLevels());

  ClSymbolicWeight clsw(0);
  vector<double>::const_iterator i1 = _values.begin();
  vector<double>::const_iterator i2 = cl._values.begin();
  for (; i1 != _values.end(); ++i1, ++i2)
    {
    clsw.push_back(*i1 - *i2);
    }
  return clsw;
}


bool 
ClSymbolicWeight::lessThan(const ClSymbolicWeight &cl) const
{
  return _values < cl._values;
}

bool 
ClSymbolicWeight::lessThanOrEqual(const ClSymbolicWeight &cl) const
{
  return _values <= cl._values;
}

bool 
ClSymbolicWeight::equal(const ClSymbolicWeight &cl) const
{
  return _values == cl._values;
}

bool 
ClSymbolicWeight::greaterThan(const ClSymbolicWeight &cl) const
{
  return _values > cl._values;
}

bool 
ClSymbolicWeight::greaterThanOrEqual(const ClSymbolicWeight &cl) const
{
  return _values >= cl._values;
}

bool 
ClSymbolicWeight::isNegative() const
{
  return _values < Zero()._values;
}
