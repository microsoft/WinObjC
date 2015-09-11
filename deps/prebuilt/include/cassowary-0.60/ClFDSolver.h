// $Id: ClFDSolver.h,v 1.5 1999/08/27 00:06:30 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSolver.h

#ifndef ClFDSolver_H
#define ClFDSolver_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "Cassowary.h"
#include "ClSolver.h"
#include "ClVariable.h"
#include "ClErrors.h"
#include "ClTypedefs.h"
#include "ClSymbolicWeight.h"
#include <GTL/graph.h>

class ClVariable;
class ClFDBinaryOneWayConstraint;

// ClFDSolver is a concrete class
// implementing a very restricted (for now --04/23/99 gjb)
// finite-domain constraint solving algorithm
class ClFDSolver: public ClSolver {
 public:
  ClFDSolver()
      : _setCns(), _mapClvToCns(), G(), nodeToVar(G)
    { G.make_directed(); }

  virtual ~ClFDSolver()
    { } 

  virtual ClFDSolver &AddConstraint(ClConstraint *const pcn);

  virtual ClFDSolver &RemoveConstraint(ClConstraint *const pcn);

  virtual ClFDSolver &Solve();

  virtual ClFDSolver &ShowSolve();

  void ChangeClv(ClVariable clv, FDNumber n) {
    clv.ChangeValue(n); 
    if (_pfnChangeClvCallback) {
      _pfnChangeClvCallback(&clv,this);
    }
  }


#ifndef CL_NO_IO
  ostream &PrintOn(ostream &xo) const;
  
  ostream &PrintInternalInfo(ostream &xo) const;

  ostream &PrintOnVerbose(ostream &xo) const 
    { PrintOn(xo); PrintInternalInfo(xo); xo << endl; return xo; }

  friend ostream &operator<<(ostream &xo, const ClFDSolver &solver);

#endif

 protected:

  virtual ClFDSolver &AddConstraintInternal(ClConstraint *const pcn);

  virtual ClFDSolver &RemoveConstraintInternal(ClConstraint *const pcn);

  /* Create node for v in G, if necessary,
     otherwise return the node we already created. */
  node GetVarNode(ClVariable v);

  /* return the best (lowest) incremental error and the value
     at which that error occurs */
  pair<ClSymbolicWeight,FDNumber> ComputeBest(ClFDVariable *pcldv);

  ClSymbolicWeight ErrorForClvAtValSubjectToCn(ClFDVariable *pcldv,
                                               FDNumber value,const ClConstraint &cn);

  /* Turn all FDVariable FIsSet() flags to false */
  void ResetSetFlagsOnVariables();

  /* all the constraints in the solver */
  ClConstraintSet _setCns;

  /* _mapClvToCns maps variable to the constraints in which
     it is rw (it omits where it is ro) */
  ClVarToConstraintSetMap _mapClvToCns;

  /* track what edges correspond to which constraints
     so we can update the constraint graph when
     removing a constraint */
  ClMap<ClConstraint *, edge> _mapCnToEdge;

  /* track what nodes correspond to which variables */
  ClMap<ClVariable, node> _mapVarToNode;

  /* directed graph that mirrors the structure of
     the relations of the added constraints */
  graph G;

  node_map<ClVariable> nodeToVar;
};

#define FDN_EOL LONG_MIN

void ListPushOnto(list<FDNumber> *pl, ...);

#endif
