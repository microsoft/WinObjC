// $Id: ClVariable.h,v 1.46 1999/04/29 09:45:31 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClVariable.h
// A handle on ClAbstractVariable-s

#ifndef ClVariable_H
#define ClVariable_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <stdio.h>
#include <map>
#include <string>
#include "Cassowary.h"
#include "ClFloatVariable.h"
#include "ClFDVariable.h"

class ClVariable;
typedef map<const string,ClVariable> StringToVarMap;


class ClVariable {
  ClAbstractVariable *pclv;
public:
  // converters from raw ClAbstractVariable
  ClVariable(ClAbstractVariable *pclv_) : pclv(pclv_) { }
  ClVariable(ClAbstractVariable &clv_) : pclv(&clv_) { }

  // Copy ctr
  ClVariable(const ClVariable &clv_) : pclv(clv_.pclv) { }

  /// These ctrs build ClFloatVariable-s
  ClVariable(string name, Number Value = 0.0) 
      : pclv(new ClFloatVariable(name,Value)) 
    { if (pmapStrPclv) { (*pmapStrPclv)[name] = *this; }  }
  ClVariable(Number Value = 0.0) 
      : pclv(new ClFloatVariable(Value)) { }
  ClVariable(long number, char *prefix, Number Value = 0.0)
      : pclv(new ClFloatVariable(number,prefix,Value)) { }

  // This one builds a ClFDVariable
  ClVariable(ClFDVariable *pcfv)
      : pclv(pcfv) 
    { if (pmapStrPclv) { (*pmapStrPclv)[pcfv->Name()] = *this; } }

  /// permit ClVariables to be used as pointers to pclvs
  ClAbstractVariable *operator->() { return pclv; }
  const ClAbstractVariable *operator->() const { return pclv; }

  /// and also forward the function calls along

  
  bool IsFloatVariable() const { assert(pclv); return pclv->IsFloatVariable(); }
  bool IsFDVariable() const { assert(pclv); return pclv->IsFDVariable(); }
  bool IsDummy() const { assert(pclv); return pclv->IsDummy(); }
  bool IsExternal() const { assert(pclv); return pclv->IsExternal(); }
  bool IsPivotable() const { assert(pclv); return pclv->IsPivotable(); }
  bool IsRestricted() const { assert(pclv); return pclv->IsRestricted(); }

  string Name() const { assert(pclv); return pclv->Name(); }

  Number Value() const { assert(pclv); return pclv->Value(); }
  int IntValue() const { assert(pclv); return pclv->IntValue(); }
  void SetValue(Number Value) 
    { assert(pclv); pclv->SetValue(Value); }
  void ChangeValue(Number Value) 
    { assert(pclv); pclv->ChangeValue(Value); }
  void SetPv(void *pv) 
    { assert(pclv); pclv->SetPv(pv); }
  void *Pv() const 
    { assert(pclv); return pclv->Pv(); }

  void SetName(string const &nm) {
    assert(pclv);
    if (pmapStrPclv) {
      pmapStrPclv->erase(Name());
      (*pmapStrPclv)[nm] = *this;
    }
    pclv->SetName(nm);
  }

  ClAbstractVariable *get_pclv() const { return pclv; } 
  bool IsNil() const { return pclv == NULL; }

  virtual FDNumber DesiredValue() const
    { assert(false); return 0; }

  virtual list<FDNumber> *PlfdnDomain()
    { assert(false); return NULL; }

  static void SetVarMap(StringToVarMap *pmap) { pmapStrPclv = pmap; }
  static StringToVarMap *VarMap() { return pmapStrPclv; }
  static StringToVarMap *pmapStrPclv;
#ifndef CL_NO_IO
  ostream &PrintOn(ostream &xo) const
    { 
      if (pclv) return pclv->PrintOn(xo); /* return xo << "@" << pclv << endl; */
      return xo << "clvNil";
    }
#endif

  friend bool operator<(ClVariable cl1, ClVariable cl2)
    { return cl1.pclv < cl2.pclv; }

  friend bool operator==(ClVariable cl1, ClVariable cl2)
    { return cl1.pclv == cl2.pclv; }

  friend bool operator!=(ClVariable cl1, ClVariable cl2)
    { return !(cl1 == cl2); }

};

#ifndef CL_NO_IO
inline ostream &operator<<(ostream &xo, const ClVariable &clv)
{ return clv.PrintOn(xo); }
#endif

#ifdef CL_USE_HASH_MAP_AND_SET
struct hash<ClVariable> { 
  size_t operator()(const ClVariable & v) const
    { return size_t((unsigned long)v.get_pclv()/CL_PTR_HASH_DIVISOR);  }
};
#endif


#include <math.h>

// Compare two double-s approximately, since equality is no good
inline bool ClApprox(double a, double b)
{
  const double epsilon = 1.0e-8;
  if (a > b) {
    return (a - b) < epsilon;
  } else {
    return (b - a) < epsilon;
  }
}

// Can remove these if I decide to 
// autoconvert from ClVariable-s to double-s
inline bool ClApprox(ClVariable clv, double b)
{
  return ClApprox(clv->Value(),b);
}

inline bool ClApprox(double a, ClVariable clv)
{
  return ClApprox(a,clv->Value());
}

extern ClVariable clvNil;

#endif
