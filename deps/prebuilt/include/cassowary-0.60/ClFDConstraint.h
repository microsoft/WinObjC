// $Id: ClFDConstraint.h,v 1.3 1999/04/29 09:45:19 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDConstraint.h

#ifndef ClFDConstraint_H
#define ClFDConstraint_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClConstraint.h"


// Just a node in the class hierarchy for now
class ClFDConstraint : public ClConstraint {
 private: typedef ClConstraint super;

 public:
  // Constructor
  ClFDConstraint(const ClStrength &strength = ClsRequired(),
		     double weight = 1.0) 
      : ClConstraint(strength, weight) { }

  virtual bool FIsOkayForSimplexSolver() const { return false; }

 protected:

};

#endif
