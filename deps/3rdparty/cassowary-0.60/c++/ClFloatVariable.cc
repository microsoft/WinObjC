// $Id: ClFloatVariable.cc,v 1.8 1999/04/30 00:12:17 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFloatVariable.cc

#include "ClFloatVariable.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#ifndef CL_NO_IO
ostream &ClFloatVariable::PrintOn(ostream &xo) const
{  
  xo << "[" << Name() << ":" << _value << "]";
  return xo;
}
#endif
