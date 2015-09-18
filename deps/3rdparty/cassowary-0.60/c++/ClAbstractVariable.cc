// $Id: ClAbstractVariable.cc,v 1.11 1999/04/20 00:24:44 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClAbstractVariable.cc

#include "ClAbstractVariable.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

long ClAbstractVariable::iVariableNumber = 0;
#ifdef CL_FIND_LEAK
long ClAbstractVariable::cAbstractVariables = 0;
#endif

