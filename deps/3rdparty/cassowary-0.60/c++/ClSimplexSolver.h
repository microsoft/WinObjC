// $Id: ClSimplexSolver.h,v 1.77 2000/02/13 04:34:36 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSimplexSolver.h

#ifndef ClSimplexSolver_H
#define ClSimplexSolver_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <stack>
#include "Cassowary.h"
#include "ClSolver.h"
#include "ClTableau.h"
#include "ClLinearInequality.h"
#include "ClStrength.h"
#include "ClStayConstraint.h"
#include "ClEditConstraint.h"
#include "ClSlackVariable.h"
#include "ClObjectiveVariable.h"
#include "ClErrors.h"
#include "ClTypedefs.h"

class ClVariable;
class ClPoint;
class ExCLRequiredFailureWithExplanation;


// ClSimplexSolver encapsulates the solving behaviour
// of the cassowary algorithm
class ClSimplexSolver : public ClSolver, public ClTableau {
 protected: typedef ClTableau super;
  class ClEditInfo;
  typedef list<ClEditInfo *> ClEditInfoList;

  ClEditInfo *PEditInfoFromClv(ClVariable clv) {
    ClEditInfoList::iterator it = _editInfoList.begin();
    for (; it != _editInfoList.end(); ++it) {
      ClEditInfo *pei = (*it);
      if (pei->_clv == clv)
        return pei;
    }
    return NULL;
  }

 public:

  // Constructor
  ClSimplexSolver() :
    ClSolver(),
    _objective(ClVariable(new ClObjectiveVariable("Z"))),
    _slackCounter(0),
    _artificialCounter(0),
#ifdef CL_FIND_LEAK
    _cArtificialVarsDeleted(0),
#endif
    _dummyCounter(0),
    _epsilon(1e-8),
    _fResetStayConstantsAutomatically(true),
    _fNeedsSolving(false),
    _fExplainFailure(false),
    _pfnResolveCallback(NULL),
    _pfnCnSatCallback(NULL)
    { 
    _rows[_objective] = new ClLinearExpression(); 
    // start out with no edit variables
    _stkCedcns.push(0);
#ifdef CL_TRACE
    cerr << "objective row new@ " << _rows[_objective] << endl;
#endif
    }

  virtual ~ClSimplexSolver();
  
  // Add constraints so that lower<=var<=upper.  (nil means no  bound.)
  ClSimplexSolver &AddLowerBound(ClVariable v, Number lower)
    { 
    ClLinearInequality *pcn = new ClLinearInequality(ClLinearExpression(v) - lower);
    return AddConstraint(pcn);
    }
  ClSimplexSolver &AddUpperBound(ClVariable v, Number upper)
    {
    ClLinearInequality *pcn = new ClLinearInequality(ClLinearExpression(upper) - v);
    return AddConstraint(pcn);
    }
  ClSimplexSolver &AddBounds(ClVariable v, Number lower, Number upper)
    { AddLowerBound(v,lower); AddUpperBound(v,upper); return *this; }

  // Add the constraint cn to the tableau
  ClSimplexSolver &AddConstraint(ClConstraint *const pcn);

#ifndef CL_NO_DEPRECATED
  // Deprecated! --02/19/99 gjb
  ClSimplexSolver &AddConstraint(ClConstraint &cn) 
    { return AddConstraint(&cn); }
#endif

  // Add an edit constraint for "v" with given strength
  ClSimplexSolver &AddEditVar(const ClVariable v, const ClStrength &strength = ClsStrong(),
                              double weight = 1.0 )
    { 
      ClEditConstraint *pedit = new ClEditConstraint(v, strength, weight);
      return AddConstraint(pedit);
    }

  ClSimplexSolver &RemoveEditVar(ClVariable v)
    {
      ClEditInfo *pcei = PEditInfoFromClv(v);
      if (!pcei) {
        throw ExCLEditMisuse("Removing edit variable that was not found");
      }
      ClConstraint *pcnEdit = pcei->_pconstraint;
      RemoveConstraint(pcnEdit);
      delete pcnEdit;
      return *this;
    }

  // BeginEdit() should be called before sending
  // Resolve() messages, after adding the appropriate edit variables
  ClSimplexSolver &BeginEdit()
    {
      if (_editInfoList.size() == 0) {
        throw ExCLEditMisuse("BeginEdit called, but no edit variable");
      }
      // may later want to do more in here
      _infeasibleRows.clear();
      ResetStayConstants();
      _stkCedcns.push(_editInfoList.size());
      return *this;
    }

  // EndEdit should be called after editing has finished
  // for now, it just removes edit variables added from before the last BeginEdit
  ClSimplexSolver &EndEdit()
    {
      if (_editInfoList.size() == 0)
        throw ExCLEditMisuse("EndEdit called but no edit variables");
      Resolve();
      _stkCedcns.pop();
      RemoveEditVarsTo(_stkCedcns.top());
      // may later want to do more in here
      return *this;
    }

  // RemoveAllEditVars() just eliminates all the edit constraints
  // that were added
  ClSimplexSolver &RemoveAllEditVars() { RemoveEditVarsTo(0); return *this; }

  // remove the last added edit vars to leave only n edit vars left
  ClSimplexSolver &RemoveEditVarsTo(int n);

  int numEditVars() const
  { return _editInfoList.size(); }

  // Add weak stays to the x and y parts of each point. These have
  // increasing weights so that the solver will try to satisfy the x
  // and y stays on the same point, rather than the x stay on one and
  // the y stay on another.
  ClSimplexSolver &AddPointStays(const vector<const ClPoint *> &listOfPoints,
                                 const ClStrength &strength = ClsWeak());

  ClSimplexSolver &AddPointStay(const ClVariable vx, const ClVariable vy, 
                                const ClStrength &strength = ClsWeak(),
                                double weight = 1.0)
    { AddStay(vx,strength,weight); AddStay(vy,strength,weight); return *this; }

  ClSimplexSolver &AddPointStay(const ClPoint &clp,
                                const ClStrength &strength = ClsWeak(),
                                double weight = 1.0);


  // Add a stay of the given strength (default to weak) of v to the tableau
  ClSimplexSolver &AddStay(const ClVariable v,
			   const ClStrength &strength = ClsWeak(), double weight = 1.0 )
    {
    ClStayConstraint *pcn = new ClStayConstraint(v,strength,weight); 
    return AddConstraint(pcn); 
    }

  // Remove the constraint cn from the tableau
  // Also remove any error variable associated with cn
  ClSimplexSolver &RemoveConstraint(ClConstraint *const pcn)
    { RemoveConstraintInternal(pcn); pcn->removedFrom(*this); return *this; }

#ifndef CL_NO_DEPRECATED
  // Deprecated! --02/19/99 gjb
  ClSimplexSolver &RemoveConstraint(ClConstraint &cn) 
    { return RemoveConstraint(&cn); }
#endif


  // Re-initialize this solver from the original constraints, thus
  // getting rid of any accumulated numerical problems.  (Actually, we
  // haven't definitely observed any such problems yet)
  void Reset();

  // Re-solve the current collection of constraints, given the new
  // values for the edit variables that have already been
  // suggested (see SuggestValue() method)
  // This is not guaranteed to work if you remove an edit constraint
  // from the middle of the edit constraints you added
  // (e.g., edit A, edit B, edit C, remove B -> this will fail!)
  // DEPRECATED
  void Resolve();

  // Re-solve the current collection of constraints for new values for
  // the constants of the edit variables.
  // This is implemented in terms of SuggestValue-s, and is
  // less efficient than that more natural interface
  void Resolve(const vector<Number> &newEditConstants);

  // Convenience function for Resolve-s of two variables
  void Resolve(Number x, Number y)
    {
    vector<Number> vals;
    vals.push_back(x);
    vals.push_back(y);
    Resolve(vals);
    }

  // Suggest a new value for an edit variable
  // the variable needs to be added as an edit variable
  // and BeginEdit() needs to be called before this is called.
  // The tableau will not be solved completely until
  // after Resolve() has been called
  ClSimplexSolver &SuggestValue(ClVariable v, Number x);

  // Set and check whether or not the solver will attempt to compile
  // an explanation of failure when a required constraint conflicts
  // with another required constraint
  ClSimplexSolver &SetExplaining(bool f)
    { _fExplainFailure = f; return *this; }

  bool FIsExplaining() const
    { return _fExplainFailure; }

  // If autosolving has been turned off, client code needs
  // to explicitly call solve() before accessing variables
  // values
  ClSimplexSolver &Solve()
    {
#ifdef CL_SOLVER_CHECK_INTEGRITY
    AssertValid();
#endif
    if (_fNeedsSolving) 
      {
      Optimize(_objective);
      SetExternalVariables();
#ifdef CL_TRACE_VERBOSE
      cerr << "Manual solve actually solving." << endl;
#endif
      }
    return *this;
    }

  ClSimplexSolver &SetEditedValue(ClVariable v, double n)
    {
    if (!FContainsVariable(v))
      {
      ChangeClv(v,n);
      return *this;
      }

    if (!ClApprox(n, v.Value())) 
      {
      AddEditVar(v);
      BeginEdit();
      SuggestValue(v,n);
      EndEdit();
      }
    return *this;
    }

  // Solver contains the variable if it's in either the columns
  // list or the rows list
  bool FContainsVariable(const ClVariable v)
    { return ColumnsHasKey(v) || RowExpression(v); }

  ClSimplexSolver &AddVar(const ClVariable v)
    { if (!FContainsVariable(v)) 
        {
        AddStay(v); 
#ifdef CL_TRACE
        cerr << "added initial stay on " << v << endl;
#endif
        }
      return *this; }

  typedef void (*PfnResolveCallback)(ClSimplexSolver *psolver);

  void SetResolveCallback(PfnResolveCallback pfn)
    { _pfnResolveCallback = pfn; }

  typedef void (*PfnCnSatCallback)(ClSimplexSolver *psolver, 
                                   ClConstraint *pcn, bool fSatisfied);

  void SetCnSatCallback(PfnCnSatCallback pfn)
    { _pfnCnSatCallback = pfn; }

#ifndef CL_NO_IO
  friend ostream &operator<<(ostream &xo, const ClSimplexSolver &tableau);

  ostream &PrintOn(ostream &xo) const;
  
  ostream &PrintInternalInfo(ostream &xo) const;

  ostream &PrintOnVerbose(ostream &xo) const 
    { PrintOn(xo); PrintInternalInfo(xo); xo << endl; return xo; }

#endif

  const ClConstraintToVarMap &ConstraintMap() const
    { return _markerVars; }

  const ClVarToConstraintMap &MarkerMap() const
    { return _constraintsMarked; }

  bool FIsConstraintSatisfied(const ClConstraint *const pcn) const;

  // DEPRECATED
  bool FIsConstraintSatisfied(const ClConstraint &pcn) const
    { return FIsConstraintSatisfied(&pcn); }

  // re-set all the external variables to their current values
  // most importantly, this re-calls all the ChangeClv callbacks
  // (which might be used to copy the ClVariable's value to another
  // variable)
  void UpdateExternalVariables() 
    { SetExternalVariables(); }

  // A. Beurive' Tue Jul  6 17:05:39 CEST 1999
  void ChangeStrengthAndWeight(ClConstraint *pcn, const ClStrength &strength, double weight);
  void ChangeStrength(ClConstraint *pcn, const ClStrength &strength);
  void ChangeWeight(ClConstraint *pcn, double weight);
  // void DisplayObjective();

  // Each of the non-required stays will be represented by an equation
  // of the form
  //     v = c + eplus - eminus
  // where v is the variable with the stay, c is the previous value of
  // v, and eplus and eminus are slack variables that hold the error
  // in satisfying the stay constraint.  We are about to change
  // something, and we want to fix the constants in the equations
  // representing the stays.  If both eplus and eminus are nonbasic
  // they have value 0 in the current solution, meaning the previous
  // stay was exactly satisfied.  In this case nothing needs to be
  // changed.  Otherwise one of them is basic, and the other must
  // occur only in the Expression for that basic error variable.
  // Reset the Constant in this Expression to 0.
  void ResetStayConstants();

  ClSimplexSolver &SetAutoResetStayConstants(bool f)
    { _fResetStayConstantsAutomatically = f; if (f) ResetStayConstants(); return *this; }

  bool FIsAutoResetStayConstants() const
    { return _fResetStayConstantsAutomatically; }

 protected:
  
  // ClEditInfo is a privately-used class
  // that just wraps a constraint, its positive and negative
  // error variables, and its prior edit Constant.
  // It is used as values in _editInfoList, and replaces
  // the parallel vectors of error variables and previous edit
  // constants from the smalltalk version of the code.
  class ClEditInfo {
    friend ClSimplexSolver;
  public:
    
    // These instances own none of the pointers;
    // the tableau row (the Expression) owns the peplus, peminus,
    // and AddEditVar/RemoveEditVar pair or the client code owns
    // the constraint object
    ClEditInfo(ClVariable clv,
               ClEditConstraint *pconstraint, 
               ClVariable eplus, ClVariable eminus,
               Number prevEditConstant)
        :_clv(clv),
         _pconstraint(pconstraint),
         _clvEditPlus(eplus), _clvEditMinus(eminus),
         _prevEditConstant(prevEditConstant)
      { }
    
    ~ClEditInfo() 
     { }

    ostream &PrintOn(ostream &xo) const
      { //xo << _clv << " -> [" << _clvEditPlus << ", " << _clvEditMinus << "](" 
        //   << _prevEditConstant << ")@" << " -- " 
        //   << *_pconstraint; 
      return xo; }
    
    friend ostream &operator<<(ostream &xo, const ClEditInfo &cei)
      { return cei.PrintOn(xo); }

  private:
    ClVariable _clv;
    ClConstraint *_pconstraint;
    ClVariable _clvEditPlus;
    ClVariable _clvEditMinus;
    Number _prevEditConstant;
  };
  
  // Add the constraint expr=0 to the inequality tableau using an
  // artificial variable.  To do this, create an artificial variable
  // av and Add av=expr to the inequality tableau, then make av be 0.
  // (Raise an exception if we can't attain av=0.)
  // (Raise an exception if we can't attain av=0.) If the Add fails,
  // prepare an explanation in e that describes why it failed (note
  // that an empty explanation is considered to mean the explanation
  // encompasses all active constraints.
  bool AddWithArtificialVariable(ClLinearExpression &pexpr, 
                                 ExCLRequiredFailureWithExplanation &e);
  
  // Using the given equation (av = cle) build an explanation which
  // implicates all constraints used to construct the equation. That
  // is, everything for which the variables in the equation are markers.
  // Thanks to Steve Wolfman for the implementation of the explanation feature
  void BuildExplanation(ExCLRequiredFailureWithExplanation & e, 
                        ClVariable av,
                        const ClLinearExpression * pcle);

  // We are trying to Add the constraint expr=0 to the appropriate
  // tableau.  Try to Add expr directly to the tableax without
  // creating an artificial variable.  Return true if successful and
  // false if not.
  bool TryAddingDirectly(ClLinearExpression &pexpr);

  // We are trying to Add the constraint expr=0 to the tableaux.  Try
  // to choose a subject (a variable to become basic) from among the
  // current variables in expr.  If expr contains any unrestricted
  // variables, then we must choose an unrestricted variable as the
  // subject.  Also, if the subject is new to the solver we won't have
  // to do any substitutions, so we prefer new variables to ones that
  // are currently noted as parametric.  If expr contains only
  // restricted variables, if there is a restricted variable with a
  // negative coefficient that is new to the solver we can make that
  // the subject.  Otherwise we can't find a subject, so return nil.
  // (In this last case we have to Add an artificial variable and use
  // that variable as the subject -- this is done outside this method
  // though.)
  // 
  // Note: in checking for variables that are new to the solver, we
  // ignore whether a variable occurs in the objective function, since
  // new slack variables are added to the objective function by
  // 'NewExpression:', which is called before this method.
  ClVariable ChooseSubject(ClLinearExpression &pexpr);
  
  // Each of the non-required edits will be represented by an equation
  // of the form
  //    v = c + eplus - eminus 
  // where v is the variable with the edit, c is the previous edit
  // value, and eplus and eminus are slack variables that hold the
  // error in satisfying the edit constraint.  We are about to change
  // something, and we want to fix the constants in the equations
  // representing the edit constraints.  If one of eplus and eminus is
  // basic, the other must occur only in the Expression for that basic
  // error variable.  (They can't both be basic.)  Fix the Constant in
  // this Expression.  Otherwise they are both nonbasic.  Find all of
  // the expressions in which they occur, and fix the constants in
  // those.  See the UIST paper for details.  
  // (This comment was for resetEditConstants(), but that is now
  // gone since it was part of the screwey vector-based interface
  // to resolveing. --02/15/99 gjb)
  void DeltaEditConstant(Number delta, ClVariable pv1, ClVariable pv2);
  
  // We have set new values for the constants in the edit constraints.
  // Re-Optimize using the dual simplex algorithm.
  void DualOptimize();

  // Make a new linear Expression representing the constraint cn,
  // replacing any basic variables with their defining expressions.
  // Normalize if necessary so that the Constant is non-negative.  If
  // the constraint is non-required give its error variables an
  // appropriate weight in the objective function.
  ClLinearExpression *NewExpression(const ClConstraint *pcn,
                                    /* output to */
                                    ClVariable &clvEplus,
                                    ClVariable &clvEminus,
                                    Number &prevEConstant);

  // Minimize the value of the objective.  (The tableau should already
  // be feasible.)
  void Optimize(ClVariable zVar);

  // Do a Pivot.  Move entryVar into the basis (i.e. make it a basic variable),
  // and move exitVar out of the basis (i.e., make it a parametric variable)
  void Pivot(ClVariable entryVar, ClVariable exitVar);

  // Set the external variables known to this solver to their appropriate values.
  // Set each external basic variable to its value, and set each
  // external parametric variable to 0.  (It isn't clear that we will
  // ever have external parametric variables -- every external
  // variable should either have a stay on it, or have an equation
  // that defines it in terms of other external variables that do have
  // stays.  For the moment I'll put this in though.)  Variables that
  // are internal to the solver don't actually store values -- their
  // values are just implicit in the tableu -- so we don't need to set
  // them.
  void SetExternalVariables();

  // this gets called by RemoveConstraint and by AddConstraint when the
  // contraint we're trying to Add is inconsistent
  ClSimplexSolver &RemoveConstraintInternal(const ClConstraint *const pcn);

  void ChangeClv(ClVariable clv, Number n) {
    clv.ChangeValue(n); 
    if (_pfnChangeClvCallback) 
      _pfnChangeClvCallback(&clv,this);
  }

  /// instance variables

  // the arrays of positive and negative error vars for the stay constraints
  // (need both positive and negative since they have only non-negative values)
  ClVarVector _stayMinusErrorVars;
  ClVarVector _stayPlusErrorVars;

  // give error variables for a non required constraint,
  // maps to ClSlackVariable-s
  ClConstraintToVarSetMap _errorVars;

  // Return a lookup table giving the marker variable for each
  // constraint (used when deleting a constraint).
  ClConstraintToVarMap _markerVars;

  // Reverse of the above-- a lookup table giving the constraint
  // for each marker variable (used when building failure explanations)
  ClVarToConstraintMap _constraintsMarked;

  ClVariable _objective;

  // Map edit variables to their constraints, errors, and prior
  // values
  ClEditInfoList _editInfoList;

  int _slackCounter;
  int _artificialCounter;
#ifdef CL_FIND_LEAK
  int _cArtificialVarsDeleted;
#endif
  int _dummyCounter;
  const double _epsilon;

  bool _fResetStayConstantsAutomatically;
  bool _fNeedsSolving;
  bool _fExplainFailure;

  PfnResolveCallback _pfnResolveCallback;
  PfnCnSatCallback _pfnCnSatCallback;

  // C-style extension mechanism so I
  // don't have to wrap ScwmClSolver separately
  void *_pv;

  // a stack of the number of edit constraints
  // that existed at the prior BeginEdit.
  // an EndEdit needs to pop off the top value,
  // then remove constraints to get down
  // to the # of constraints as in _stkCedcns.top()
  stack<int> _stkCedcns;

};

#ifndef CL_NO_IO

ostream &PrintTo(ostream &xo, const ClSimplexSolver::ClEditInfoList &listPEditInfo);
ostream &operator<<(ostream &xo, const ClSimplexSolver::ClEditInfoList &listPEditInfo);

#endif


#endif
