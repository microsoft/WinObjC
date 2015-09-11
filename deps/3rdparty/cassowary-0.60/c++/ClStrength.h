// $Id: ClStrength.h,v 1.20 1999/04/20 00:25:17 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClStrength.h

#ifndef ClStrength_H
#define ClStrength_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClSymbolicWeight.h"

class ClStrength;

const ClStrength &ClsRequired();
const ClStrength &ClsStrong();
const ClStrength &ClsMedium();
const ClStrength &ClsWeak();

#ifdef USE_GC_STRENGTH
class ClStrength : public gc {
#else
class ClStrength {
#endif
 public:

  ClStrength(const string &Name, const ClSymbolicWeight &symbolicWeight) :
    _name(Name), _symbolicWeight(symbolicWeight)
    { }

  // special case for when nLevels = 3, should assert nLevels() == 3
  ClStrength(const string &Name, double w1, double w2, double w3);

  virtual ~ClStrength()
    { }

  virtual bool IsRequired() const
    { return (_symbolicWeight == ClsRequired()._symbolicWeight); }

#ifndef CL_NO_IO
  virtual ostream &PrintOn(ostream &xo) const
    { 
    xo << Name(); 
    if (!IsRequired())
      xo << ":" << symbolicWeight(); 
    return xo; 
    }

  friend ostream& operator<<(ostream &xos, const ClStrength &Cls)
    { Cls.PrintOn(xos); return xos; }

#endif

  virtual const ClSymbolicWeight &symbolicWeight() const
    { return _symbolicWeight; }

  void SetPv(void *pv)
    { _pv = pv; }

  void *Pv() const
    { return _pv; }

 private:
  string Name() const
    { return _name; }

  void SetName(string Name)
    { _name = Name; }

  void SetSymbolicWeight(const ClSymbolicWeight &symbolicWeight)
    { _symbolicWeight = symbolicWeight; }

  // instance variables
  string _name;
  ClSymbolicWeight _symbolicWeight;

  void *_pv;

};

#endif
