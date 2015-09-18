// $Id: ClPoint.h,v 1.13 1999/04/20 00:25:06 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClPoint.h

#ifndef ClPoint_H
#define ClPoint_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClVariable.h"

// ClPoint is just a convenience class for pairs of
// ClVariables -- often useful for coordinate pairs in 2-space
class ClPoint {
 public:
  ClPoint(Number x, Number y)
    : _clv_x(x), _clv_y(y)
    { }

  ClPoint()
    { }

  ClVariable X()
    { return _clv_x; }

  ClVariable Y()
    { return _clv_y; }

  const ClVariable X() const
    { return _clv_x; }

  const ClVariable Y() const
    { return _clv_y; }

  void SetXY(Number x, Number y)
    { _clv_x.SetValue(x); _clv_y.SetValue(y); }

  Number Xvalue() const
    { return X().Value(); }

  Number Yvalue() const
    { return Y().Value(); }

 private:
  ClVariable _clv_x;
  ClVariable _clv_y;

#ifndef CL_NO_IO
  friend ostream &operator<<(ostream &xo, const ClPoint &clp);
#endif
  
};

#ifndef CL_NO_IO
inline ostream &
operator<<(ostream &xo, const ClPoint &clp)
{
  xo << "(" << clp._clv_x << ", " << clp._clv_y << ")";
  return xo;
}
#endif

#endif
