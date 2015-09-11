// $Id: ClEditConstraint.h,v 1.17 1999/04/20 00:24:52 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClEditConstraint.h

#ifndef ClEditConstraint_H
#define ClEditConstraint_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClEditOrStayConstraint.h"

class ClEditConstraint : public ClEditOrStayConstraint {
     typedef ClEditOrStayConstraint super;
 public:
  
  ClEditConstraint(const ClVariable var,
		   const ClStrength &strength = ClsStrong(), double weight = 1.0 ) :
    ClEditOrStayConstraint(var,strength,weight)
    { }

  // Returns true if this is an edit constraint
  virtual bool IsEditConstraint() const
    { return true; }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const 
    { super::PrintOn(xo); return xo << "= edit)"; }
#endif

 private:

};

#endif
