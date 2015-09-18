// $Id: ClFDConnectorVariable.h,v 1.2 1999/05/06 09:05:03 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDConnectorVariable.h

#ifndef ClFDConnectorVariable_H
#define ClFDConnectorVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <stdio.h>
#include <map>
#include <string>
#include <list>
#include "Cassowary.h"
#include "ClVariable.h"
#include "ClFDVariable.h"
#include "ClLinearEquation.h"
#include "ClSimplexSolver.h"

/* Creates a new variable in the FD region
   that sets clvFloat in solver (simplex region)
   when it changes */
class ClFDConnectorVariable : public ClFDVariable {
public:
  typedef ClFDVariable super;

  ClFDConnectorVariable(string name, FDNumber Value, const list<FDNumber> &initial_domain,
                        ClSimplexSolver &solver, ClVariable clvFloat) :
      ClFDVariable(name,Value,initial_domain),
      _solver(solver),
      _clvFloat(clvFloat),
      _pcnRequiredLink(new ClLinearEquation(clvFloat,Value))
    { solver.AddConstraint(_pcnRequiredLink); }

#ifndef CL_NO_IO
  // Prints a semi-descriptive representation to the stream, using the
  // name if there is one, and otherwise the hash number of this
  // object.
  //	EXAMPLE
  //	  [x:10.0]		-- name = "x", Value = 10.0
  virtual ostream &PrintOn(ostream &xo) const;
#endif
  
  // permit overriding in subclasses in case something needs to be
  // done when the Value is changed by the solver
  // may be called when the Value hasn't actually changed -- just 
  // means the solver is setting the external variable
  virtual void ChangeValue(FDNumber Value)
    { 
      if (_value != Value) {
        _value = Value;
        cerr << "Updating " << _clvFloat << " now!" << endl;
        _solver.RemoveConstraint(_pcnRequiredLink);
        _pcnRequiredLink->ChangeConstant(_value);
        _solver.AddConstraint(_pcnRequiredLink);
      }
    }

private:

  // similar to SetValue -- see caveat above -- made private for now
  // since it's probably the wrong thing and is too easy to invoke
  FDNumber operator=(FDNumber Value)
    { _value = Value; return Value; }

  // Copy constructor left undefined since we want to
  // outlaw passing by Value!  Will get a link error if you
  // try to use within ClFDConnectorVariable.c, compile-time error everywhere else
  ClFDConnectorVariable(const ClFDConnectorVariable &);

  ClSimplexSolver &_solver;

  ClVariable _clvFloat;

  ClLinearEquation *_pcnRequiredLink;
  
};

#endif
