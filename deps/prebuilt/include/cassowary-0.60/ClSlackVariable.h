// $Id: ClSlackVariable.h,v 1.17 1999/04/20 00:25:14 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSlackVariable.h

#ifndef ClSlackVariable_H
#define ClSlackVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClAbstractVariable.h"

class ClTableau;
class ClSimplexSolver;


class ClSlackVariable : public ClAbstractVariable {
public:
#ifdef CL_FIND_LEAK
  ~ClSlackVariable() { --cSlackVariables; };

  static long cSlackVariables;
#endif

protected:
  friend ClTableau;
  friend ClSimplexSolver;

  ClSlackVariable(string Name = "") :
    ClAbstractVariable(Name)
    {
#ifdef CL_FIND_LEAK
      ++cSlackVariables; 
#endif
    }

  ClSlackVariable(long number, char *prefix) :
    ClAbstractVariable(number,prefix)
    { 
#ifdef CL_FIND_LEAK
      ++cSlackVariables; 
#endif
    }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const
  {  
    xo << "[" << Name() << ":slack]";
    return xo;
  }
#endif

  virtual bool IsExternal() const
    { return false; }

  virtual bool IsPivotable() const
    { return true; }

  virtual bool IsRestricted() const
    { return true; }

};


#endif
