// $Id: ClFDBinaryOneWayConstraint.cc,v 1.3 1999/04/29 09:45:17 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDBinaryOneWayConstraint.cc


#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#include "ClFDBinaryOneWayConstraint.h"
#include "ClLinearConstraint.h"
#include "ClTypedefs.h"
#include "ClLinearExpression.h"


void 
ClFDBinaryOneWayConstraint::EnsurePreconditionsForCn(const ClConstraint &cn)
{
  ClVarSet setRO = cn.ReadOnlyVars();
  if (setRO.size() > 1) 
    throw ExCLTooDifficultSpecial("Only 0 or 1 read only variables are allowed");
  const ClLinearExpression &expr = cn.Expression();
  const ClVarToNumberMap &terms = expr.Terms();
  if (terms.size() > 2)
    throw ExCLTooDifficultSpecial("Cannot have more than 2 variables");
  if (terms.size() == 0)
    throw ExCLTooDifficultSpecial("Must have at least 1 variable");
  if (terms.size() == 2 && setRO.size() == 0)
    throw ExCLTooDifficultSpecial("Both variables cannot be read-write, one must be read-only");
  if (terms.size() == 1 && setRO.size() == 1)
    throw ExCLTooDifficultSpecial("Single read-only variable in LinearConstraint -- must not be read-only.");
  ClVariable clv = (*terms.begin()).first;
  /* GJB:FIXME:: iterate over all the variables */
  if (!clv->IsFDVariable()) {
    throw ExCLTooDifficultSpecial("FD constraint contains non-FD variables");
  }
}

bool 
ClFDBinaryOneWayConstraint::FCanConvertCn(const ClConstraint &cn)
{
  try {
    EnsurePreconditionsForCn(cn);
    return true;
  } catch (...) {
    return false;
  }
}


ClFDBinaryOneWayConstraint::ClFDBinaryOneWayConstraint(const ClConstraint &cn)
    :ClFDConstraint(cn.strength(), cn.weight())
{
  EnsurePreconditionsForCn(cn);
  list<FDNumber> l;
  /* GJB:FIXME:: varargs inteface, with sentinel as first arg? */
  l.push_back(9);
  l.push_back(10);
  l.push_back(12);
  l.push_back(14);
  l.push_back(20);

  ClVarSet setRO = cn.ReadOnlyVars();

  ClVariable clvRO = clvNil;
  ClVariable clvROLinear = clvNil;
  Number coeffRO = 0;

  ClVariable clvRW = clvNil;
  Number coeffRW = 0;

  if (setRO.size() == 1) {
    const ClVariable &clv = *(setRO.begin());
    if (clv->IsFDVariable())
      clvRO = clv;
    else
      clvRO = new ClFDVariable(clv.Name(),clv.IntValue(),l);
    clvROLinear = clv;
  }
  const ClLinearExpression &expr = cn.Expression();
  const ClVarToNumberMap &terms = expr.Terms();

  for (ClVarToNumberMap::const_iterator it = terms.begin();
       it != terms.end();
       ++it) {
    ClVariable clv = (*it).first;
    if (clv == clvROLinear) {
      coeffRO = (*it).second;
    } else {
      if (clv->IsFDVariable())
        clvRW = clv;
      else
        clvRW = new ClFDVariable(clv.Name(),clv.Value(),l);
      coeffRW = (*it).second;
    }
  }
  assert(!clvRW.IsNil());
  if (coeffRW == 0) {
    throw ExCLTooDifficultSpecial("RW variable's coefficient must be non-zero");
  }

  bool fInequality = cn.IsInequality();
  bool fStrictInequality = cn.IsStrictInequality();
  double rhs_constant = expr.Constant();

  // now we have:
  // coeffRW * clvRW + coeffRO * clvRO <REL> rhs_constant
  //   where <REL> is >= if fInequality, or = if !fInequality
  // 
  // need:
  //   clvRW <REL> coefficient * clvRO + constant
  // 
  // so:
  // coefficient = -coeffRO/coeffRW
  // constant = rhs_constant/coeffRW

  if (fStrictInequality)
    _rel = cnGT;
  else if (fInequality)
    _rel = cnGEQ;
  else
    _rel = cnEQ;

  if (coeffRW < 0)
    _rel = ReverseInequality(_rel);

  _coefficient = -coeffRO/coeffRW;
  _constant = -rhs_constant/coeffRW;
  _vRW = clvRW;
  _vRO = clvRO;
  return;
}
