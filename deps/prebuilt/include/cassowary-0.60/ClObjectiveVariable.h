// $Id: ClObjectiveVariable.h,v 1.14 1999/04/20 00:25:04 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClObjectiveVariable.h

#ifndef ClObjectiveVariable_H
#define ClObjectiveVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClAbstractVariable.h"

class ClTableau;
class ClSimplexSolver;

class ClObjectiveVariable : public ClAbstractVariable {
protected:
  friend ClTableau;
  friend ClSimplexSolver;

  ClObjectiveVariable(string name = "") :
    ClAbstractVariable(name)
    { }

  ClObjectiveVariable(long number, char *prefix) :
    ClAbstractVariable(number,prefix)
    { }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const
  {  
    xo << "[" << Name() << ":obj]";
    return xo;
  }
#endif

  // We don't need to give such variables a Value after solving is complete.
  virtual bool IsExternal() const 
    { return false; }

  // Return true if we can Pivot on this variable.
  virtual bool IsPivotable() const 
    { return false; }

  // Return true if this is a restricted (or slack) variable.  Such
  // variables are constrained to be non-negative and occur only
  // internally to the simplex solver.
  virtual bool IsRestricted() const 
    { return false; }

};

#endif
