// $Id: ClFDVariable.h,v 1.5 1999/04/30 00:12:16 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDVariable.h

#ifndef ClFDVariable_H
#define ClFDVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <stdio.h>
#include <map>
#include <string>
#include <list>
#include "Cassowary.h"
#include "ClAbstractVariable.h"

class ClFDVariable : public ClAbstractVariable {
public:
  typedef ClAbstractVariable super;

#if 0 /* GJB:FIXME:: */
  ClFDVariable(string name, FDNumber Value) :
    ClAbstractVariable(name),
    _value(Value),
    _fSet(true),
    _desired_value(Value),
    _plfdnInitialDomain(NULL)
    { }
#endif

  ClFDVariable(string name, FDNumber Value, const list<FDNumber> &initial_domain) :
    ClAbstractVariable(name),
    _value(Value),
    _fSet(true),
    _desired_value(Value),
    _plfdnInitialDomain(new list<FDNumber>())
    {
      *_plfdnInitialDomain = initial_domain;
    }

  virtual bool IsFDVariable() const
    { return true; }

  // Return true if this a variable known outside the solver.  
  // (We need to give such variables a Value after solving is complete.)
  virtual bool IsExternal() const
    { return true; }

#ifndef CL_NO_IO
  // Prints a semi-descriptive representation to the stream, using the
  // name if there is one, and otherwise the hash number of this
  // object.
  //	EXAMPLE
  //	  [x:10.0]		-- name = "x", Value = 10.0
  virtual ostream &PrintOn(ostream &xo) const;
#endif
  
  // Return the current Value I hold.
  Number Value() const
    { return _value; }

  // Round the Value to an integer and return it
  int IntValue() const
    { return _value; }

  // change the Value held -- should *not* use this if the variable is
  // in a solver -- instead use AddEditVar() and SuggestValue() interface
  void SetValue(FDNumber Value)
    { _value = Value; }

  // permit overriding in subclasses in case something needs to be
  // done when the Value is changed by the solver
  // may be called when the Value hasn't actually changed -- just 
  // means the solver is setting the external variable
  virtual void ChangeValue(FDNumber Value)
    { _value = Value; }

  virtual bool FIsSet()
    { return _fSet; }

  virtual void SetFIsSet(bool f)
    { _fSet = f; }

  virtual FDNumber DesiredValue() const
    { return _desired_value; }

  virtual const list<FDNumber> *PlfdnDomain() const
    { return _plfdnInitialDomain; }

protected:

  // similar to SetValue -- see caveat above -- made private for now
  // since it's probably the wrong thing and is too easy to invoke
  FDNumber operator=(FDNumber Value)
    { _value = Value; return Value; }

  // Copy constructor left undefined since we want to
  // outlaw passing by Value!  Will get a link error if you
  // try to use within ClFDVariable.c, compile-time error everywhere else
  ClFDVariable(const ClFDVariable &);

  FDNumber _value;

  // has the _value been set?  Used during solves.
  bool _fSet;

  FDNumber _desired_value;

  list<FDNumber> *_plfdnInitialDomain;
};

#endif
