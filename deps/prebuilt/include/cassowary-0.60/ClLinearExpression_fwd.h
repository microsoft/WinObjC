// $Id: ClLinearExpression_fwd.h,v 1.6 1999/04/20 00:25:02 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearExpression.h

#ifndef ClLinearExpression_fwd_H
#define ClLinearExpression_fwd_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"

template <class T> class ClGenericLinearExpression;
typedef ClGenericLinearExpression<Number> ClLinearExpression;
typedef ClLinearExpression *PClLinearExpression;

#endif
