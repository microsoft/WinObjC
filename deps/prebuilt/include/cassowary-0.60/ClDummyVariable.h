// $Id: ClDummyVariable.h,v 1.18 1999/04/20 00:24:51 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClDummyVariable.h

#ifndef ClDummyVariable_H
#define ClDummyVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClAbstractVariable.h"

class ClTableau;
class ClSimplexSolver;

class ClDummyVariable : public ClAbstractVariable {

public:

#ifdef CL_FIND_LEAK
  ~ClDummyVariable() { --cDummyVariables; };

  static long cDummyVariables;

#endif

protected:
  friend ClTableau;
  friend ClSimplexSolver;

  ClDummyVariable(string Name = "") :
    ClAbstractVariable(Name)
    { 
#ifdef CL_FIND_LEAK
      ++cDummyVariables; 
#endif
    }

  ClDummyVariable(long number, char *prefix) :
    ClAbstractVariable(number,prefix)
    { 
#ifdef CL_FIND_LEAK
      ++cDummyVariables; 
#endif
    }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const
  {  
    xo << "[" << Name() << ":dummy]";
    return xo;
  }
#endif

  // Return true if this a dummy variable (used as a marker variable
  // for required equality constraints).  Such variables aren't
  // allowed to enter the basis when pivoting.
  virtual bool IsDummy() const
    { return true; }

  // Return true if this a variable known outside the solver.  
  // (We need to give such variables a Value after solving is complete.)
  virtual bool IsExternal() const
    { return false; }

  // Return true if we can Pivot on this variable.
  virtual bool IsPivotable() const
    { return false; }

  // Return true if this is a restricted (or slack) variable.  Such
  // variables are constrained to be non-negative and occur only
  // internally to the simplex solver.
  virtual bool IsRestricted() const
    { return true; }

};

#endif
