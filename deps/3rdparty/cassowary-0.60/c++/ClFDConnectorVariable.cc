// $Id: ClFDConnectorVariable.cc,v 1.1 1999/04/30 00:12:10 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDConnectorVariable.cc

#include "ClFDConnectorVariable.h"
#include "ClSolver.h" // for list<FDNumber> printing

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

// Use < > for ClFDConnector-s, instead of [ ]
#ifndef CL_NO_IO
ostream &ClFDConnectorVariable::PrintOn(ostream &xo) const
{  
  xo << "<" << Name() << "=" << Value() 
     << "{" << _clvFloat << "}"
     << ":" << *PlfdnDomain() << ">";
  return xo;
}
#endif
