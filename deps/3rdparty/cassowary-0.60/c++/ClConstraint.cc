// $Id: ClConstraint.cc,v 1.12 1999/04/25 01:43:31 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClConstraint.cc

#include "ClConstraint.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#ifndef CL_NO_IO
#include "ClTableau.h" // for VarSet printing

ostream &
ClConstraint::PrintOn(ostream &xo) const 
{
  // Note that the trailing "= 0)" or ">= 0)" is missing, as derived classes will
  // print the right thing after calling this function
  xo << strength() << " w{" << weight() << "} ta{" 
     << _times_added << "} RO" << _readOnlyVars << " " << "(" << Expression();
  return xo;
}

#endif
