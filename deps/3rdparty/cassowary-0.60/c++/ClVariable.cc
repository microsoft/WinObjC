// $Id: ClVariable.cc,v 1.12 1999/04/20 00:25:27 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClVariable.cc

#include "ClVariable.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

StringToVarMap *ClVariable::pmapStrPclv = NULL;
ClVariable clvNil(static_cast<ClAbstractVariable*>(0));

