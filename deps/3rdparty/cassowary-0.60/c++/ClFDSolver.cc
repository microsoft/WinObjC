// $Id: ClFDSolver.cc,v 1.9 1999/09/30 15:17:48 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClFDSolver.cc


#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClFDSolver.h"
#include "ClFDBinaryOneWayConstraint.h"
#include "ClVariable.h"
#include "debug.h"
#include <GTL/topsort.h>
#include <pair.h>
#include <math.h>
#include <stdarg.h>

static int fDebugFDSolve;

ClFDSolver &
ClFDSolver::AddConstraint(ClConstraint *const pcn)
{
  AddConstraintInternal(pcn);
  if (_fAutosolve) Solve();
  return *this;
}

ClFDSolver &
ClFDSolver::RemoveConstraint(ClConstraint *const pcn)
{
  RemoveConstraintInternal(pcn);
  if (_fAutosolve) Solve();
  return *this;
}

ClFDSolver &
ClFDSolver::AddConstraintInternal(ClConstraint *const pcn)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << *pcn << ")" << endl;
#endif

  ClFDBinaryOneWayConstraint *const pcnfd = 
    dynamic_cast<ClFDBinaryOneWayConstraint *const>(pcn);
  if (!pcnfd) {
    throw ExCLTooDifficultSpecial("Can only add ClFDBinaryOneWayConstraint-s to ClFDSolvers");
  }
  ClVariable rw = pcnfd->ClvRW();
  ClVariable ro = pcnfd->ClvRO();
  if (!rw.IsFDVariable()) {
    throw ExCLTooDifficultSpecial("RW variable must be an FDVariable");
  }
  if (!(ro.IsNil() || ro.IsFDVariable())) {
    throw ExCLTooDifficultSpecial("RO variable must be an FDVariable or clvNil");
  }
  // add the constraint to our set of cns
  _setCns.insert(pcn);
  // and add the constraint to the cns that affect var rw
  assert(!rw.IsNil());
  _mapClvToCns[rw].insert(pcn);


  node nRw = GetVarNode(rw);
  if (!ro.IsNil()) {
    node nRo = GetVarNode(ro);
    edge e = G.new_edge(nRo, nRw);

    _mapCnToEdge[pcn] = e;

    if (!G.is_acyclic()) {
      /* there is a cycle... give up after cleaning up */
      RemoveConstraint(pcn);
      throw ExCLCycleNotAllowed();
    }
  }
  return *this;
}

ClFDSolver &
ClFDSolver::RemoveConstraintInternal(ClConstraint *const pcn)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << *pcn << ")" << endl;
#endif

  ClFDBinaryOneWayConstraint *const pcnfd = 
    dynamic_cast<ClFDBinaryOneWayConstraint *const>(pcn);

  if (!pcnfd) {
    throw ExCLInternalError("Could not downcast to a ClFDBinaryOneWayConstraint");
  }

  ClConstraintSet::iterator itCn = _setCns.find(pcnfd);
  if (itCn == _setCns.end()) {
    throw ExCLConstraintNotFound();
  }
  _setCns.erase(itCn);
  
  ClVariable rw = pcnfd->ClvRW();
  ClVariable ro = pcnfd->ClvRO();
  ClConstraintSet &_cnsAffectingRW = _mapClvToCns[rw];
  ClConstraintSet::iterator it = _cnsAffectingRW.find(pcnfd);
  if (it == _cnsAffectingRW.end()) {
    throw ExCLInternalError("Cannot find pcnfd");
  }
  _cnsAffectingRW.erase(it);

  if (!ro.IsNil()) {
    edge e = _mapCnToEdge[pcn];
    G.del_edge(e);
    _mapCnToEdge.erase(pcn);

    if (_mapVarToNode.find(ro) != _mapVarToNode.end() &&
        _mapVarToNode[ro].degree() == 0) {
      G.del_node(_mapVarToNode[ro]);
      _mapVarToNode.erase(ro);
    }
  }
  if (_mapVarToNode.find(rw) != _mapVarToNode.end() &&
      _mapVarToNode[rw].degree() == 0) {
    G.del_node(_mapVarToNode[rw]);
    _mapVarToNode.erase(rw);
  }
  if (_mapClvToCns[rw].size() == 0) {
    _mapClvToCns.erase(rw);
  }

  return *this;
}

ClFDSolver &
ClFDSolver::Solve()
{
  topsort t;
  t.run(G);
  topsort::topsort_iterator it = t.top_order_begin();
  topsort::topsort_iterator end = t.top_order_end();
  ClSymbolicWeight errorTotal;
  ResetSetFlagsOnVariables();
  for (; it != end; ++it) {
    ClVariable clv = nodeToVar[*it];
    ClFDVariable *pcldv = dynamic_cast<ClFDVariable*>(clv.get_pclv());
#ifndef NO_FDSOLVE_DEBUG
    if (fDebugFDSolve) {
      if (!clv.IsNil()) cout << "node " << (*it) << " is " << clv << endl;
      cerr << "Set from: " << endl;
      for (ClConstraintSet::iterator itCns = _mapClvToCns[clv].begin();
           itCns != _mapClvToCns[clv].end();
           ++itCns) {
        const ClConstraint *pcn = *itCns;
        cerr << *pcn << endl;
      }
      cerr << endl;
    }
#endif
    pair<ClSymbolicWeight,FDNumber> p = ComputeBest(pcldv);
    ClSymbolicWeight e = p.first;
    FDNumber v = p.second;
    if (v == FDN_NOTSET)
      throw ExCLRequiredFailure();
    pcldv->ChangeValue(v);
    pcldv->SetFIsSet(true);
    errorTotal += e;
  }
  return *this;
}

/* return the best (lowest) incremental error and the value
   at which that error occurs */
pair<ClSymbolicWeight,FDNumber>
ClFDSolver::ComputeBest(ClFDVariable *pcldv)
{
  assert(pcldv);
  //  assert(!pcldv->FIsSet()); //GJB:FIXME::
  ClSymbolicWeight minError = ClsRequired().symbolicWeight();
  FDNumber bestValue = FDN_NOTSET;
  //  ClVariable clv(pcldv);
  // for each domain value
  for (list<FDNumber>::const_iterator itVal= pcldv->PlfdnDomain()->begin();
       itVal != pcldv->PlfdnDomain()->end();
       ++itVal) {
    FDNumber value = *itVal;
    ClSymbolicWeight error;
    const ClConstraintSet &setCns = _mapClvToCns[pcldv];
    // for each constraint affecting *pcldv
    for (ClConstraintSet::const_iterator itCn = setCns.begin();
         itCn != setCns.end();
         ++itCn) {
      const ClConstraint *pcn = *itCn;
      ClSymbolicWeight e = ErrorForClvAtValSubjectToCn(pcldv,value,*pcn);
      error += e;
    }
    // now error is the total error for binding clv <- value
    if (error < minError) {
      minError = error;
      bestValue = value;
    }
  }
  // now minError is the lowest error we can get for clv
  // and it occurs binding clv <- bestValue
  if  (bestValue == FDN_NOTSET)
    throw ExCLRequiredFailure();
  return pair<ClSymbolicWeight,FDNumber>(minError,bestValue);
}

ClSymbolicWeight
ClFDSolver::ErrorForClvAtValSubjectToCn(ClFDVariable *pcldv,FDNumber value,const ClConstraint &cn)
{
  const ClFDBinaryOneWayConstraint *pcnFd = dynamic_cast<const ClFDBinaryOneWayConstraint*>(&cn);
  if (!pcnFd) throw ExCLInternalError("Not a binary FD constraint.");
  ClCnRelation rel = pcnFd->Relation();
  double m = pcnFd->Coefficient();
  double b = pcnFd->Constant();
  ClVariable rw = pcnFd->ClvRW();
  ClVariable ro = pcnFd->ClvRO();
  assert(rw.get_pclv() == pcldv);
  double e;
  double x = ro.IsNil()? 0 : ro.Value();
  // return the error in satisfying:
  // value REL m*x + b
  double rhs = m*x + b;
  switch (rel) {
  case cnLEQ:
    if (value <= rhs) e = 0;
    else e = 1 + value-rhs;
    break;
  case cnLT:
    if (value < rhs) e = 0;
    else e = 1 + value-rhs;
    break;
  case cnGEQ:
    if (value >= rhs) e = 0;
    else e = 1+ rhs-value;
    break;
  case cnGT:
    if (value > rhs) e = 0;
    else e = 1 + rhs-value;
    break;
  case cnEQ:
    if (value == rhs) e = 0;
    else e = 1 + fabs(rhs-value);
    break;
  case cnNEQ:
    if (value != rhs) e = 0;
    else e = 1; /* GJB:FIXME:: what makes sense here? */
    break;
  default:
    e = 0; /* quiet warning */
    assert(false);
  }

  ClSymbolicWeight err;
  if (cn.IsRequired() && e > 0)
    err = ClsRequired().symbolicWeight();
  else
    err = cn.symbolicWeight() * (e*cn._weight);
#ifndef NO_FDSOLVE_DEBUG
  if (fDebugFDSolve) {
    cerr << "Error at " << value << " = " << err << endl;
  }
#endif
  return err;
}


ClFDSolver &
ClFDSolver::ShowSolve()
{
  topsort t;
  t.run(G);
  topsort::topsort_iterator it = t.top_order_begin();
  topsort::topsort_iterator end = t.top_order_end();
  for (; it != end; ++it) {
    ClVariable clv = nodeToVar[*it];
    if (!clv.IsNil()) cout << "Node " << (*it) << " is " << clv << endl;
    cout << "Set from: " << endl;
    for (ClConstraintSet::iterator itCns = _mapClvToCns[clv].begin();
         itCns != _mapClvToCns[clv].end();
         ++itCns) {
      const ClConstraint *pcn = *itCns;
      cout << *pcn << endl;
    }
    cout << endl;
  }
  return *this;
}


/* Turn all FDVariable FIsSet() flags to false */
void 
ClFDSolver::ResetSetFlagsOnVariables()
{
  for (ClVarToConstraintSetMap::iterator it = _mapClvToCns.begin();
       it != _mapClvToCns.end();
       ++it) {
    ClVariable clv = (*it).first;
    ClFDVariable *pcldv = dynamic_cast<ClFDVariable*>(clv.get_pclv());
    assert(pcldv);
    pcldv->SetFIsSet(false);
  }
}


ostream &
ClFDSolver::PrintOn(ostream &xo) const
{
  xo << "FDSolver: " 
     << _setCns
     << "Graph nodes, edges = " << G.number_of_nodes() << ", " << G.number_of_edges()
     << endl;
  return xo;
}

ostream &
ClFDSolver::PrintInternalInfo(ostream &xo) const
{  return xo; }


ostream &operator<<(ostream &xo, const ClFDSolver &clfds)
{  return clfds.PrintOn(xo); }


//// protected member functions

/* Create node for v in G, if necessary,
   otherwise return the node we already created. */
node 
ClFDSolver::GetVarNode(ClVariable v)
{
  ClMap<ClVariable,node>::iterator it = _mapVarToNode.find(v);
  if (it == _mapVarToNode.end()) {
    node n = G.new_node();
    _mapVarToNode[v] = n;
    nodeToVar[n] = v;
    return n;
  } else {
    return (*it).second;
  }
}


void 
ListPushOnto(list<FDNumber> *pl, ...)
{
  va_list ap;
  va_start(ap, pl);
  FDNumber n;
  while ( (n = va_arg(ap, FDNumber)) != FDN_EOL) {
    pl->push_back(n);
  }
  va_end(ap);
}
