// $Id: ClSimplexSolver.cc,v 1.115 2000/02/13 04:34:35 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSimplexSolver.cc

#include "debug.h"
#include "ClSimplexSolver.h"
#include "ClErrors.h"
#include "ClVariable.h"
#include "ClPoint.h"
#include "ClSlackVariable.h"
#include "ClObjectiveVariable.h"
#include "ClDummyVariable.h"
#include "cl_auto_ptr.h"
#include <algorithm>
#include <float.h>
#include <strstream>
#include <queue>

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

const char *szCassowaryVersion = VERSION;

// Need to delete all expressions
// and all slack and dummy variables
// See NewExpression -- all allocation is done in there
ClSimplexSolver::~ClSimplexSolver()
{
#ifdef CL_SOLVER_STATS
  cerr << "_slackCounter == " << _slackCounter
       << "\n_artificialCounter == " << _artificialCounter
       << "\n_dummyCounter == " << _dummyCounter << endl;
  cerr << "stayMinusErrorVars " << _stayMinusErrorVars.size() << ", "
       << "stayPlusErrorVars " << _stayPlusErrorVars.size() << ", "
       << "errorVars " << _errorVars.size() << ", "
       << "markerVars " << _markerVars.size() << endl;
#endif
  // Cannot print *this here, since local ClVariable-s may have been
  // destructed already
}

// Add the constraint cn to the tableau
ClSimplexSolver &
ClSimplexSolver::AddConstraint(ClConstraint *const pcn)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << *pcn << ")" << endl;
#endif
  
  if (!pcn->FIsOkayForSimplexSolver()) {
    throw ExCLTooDifficultSpecial("SimplexSolver cannot handle this constraint object");
  }

  if (pcn->IsStrictInequality()) {
    // cannot handle strict inequalities
    throw ExCLStrictInequalityNotAllowed();
  }

  if (pcn->ReadOnlyVars().size() > 0) {
    // cannot handle read-only vars
    throw ExCLReadOnlyNotAllowed();
  }

  if (pcn->IsEditConstraint())
    {
    ClEditConstraint *pcnEdit = dynamic_cast<ClEditConstraint *>(pcn);
    const ClVariable &v = pcnEdit->variable();
    if (!v.IsExternal() ||
        (!FIsBasicVar(v) && !ColumnsHasKey(v)))
      {
      // we could try to make this case work,
      // but it'd be unnecessarily inefficient --
      // and probably easier for the client application
      // to deal with
      throw ExCLEditMisuse("(ExCLEditMisuse) Edit constraint on variable not in tableau.");
      }
    ClEditInfo *pcei = PEditInfoFromClv(v);
    if (pcei)
      {
      // we need to only add a partial _editInfoList entry for this
      // edit constraint since the variable is already being edited.
      // otherwise a more complete entry is added later in this function
      _editInfoList.push_back(new ClEditInfo(v, NULL, clvNil, clvNil, 0));
      return *this;
      }
    }

  ClVariable clvEplus, clvEminus;
  Number prevEConstant;
  ClLinearExpression *pexpr = NewExpression(pcn, /* output to: */
                                            clvEplus,clvEminus,
                                            prevEConstant);
  bool fAddedOkDirectly = false;

  try 
    {
    // If possible Add expr directly to the appropriate tableau by
    // choosing a subject for expr (a variable to become basic) from
    // among the current variables in expr.  If this doesn't work use an
    // artificial variable.  After adding expr re-Optimize.
    fAddedOkDirectly = TryAddingDirectly(*pexpr);
    }
  catch (ExCLRequiredFailure &error)
    {
#ifdef CL_TRACE
    cerr << "could not Add directly -- caught ExCLRequiredFailure error" << endl;
#endif
    RemoveConstraintInternal(pcn);
    throw;
    }

  if (!fAddedOkDirectly)
    { // could not Add directly
    ExCLRequiredFailureWithExplanation e;
    if (!AddWithArtificialVariable(*pexpr, e))
      {
#ifdef CL_DEBUG_FAILURES
      cerr << "Failed solve! Could not Add constraint.\n"
           << *this << endl;
#endif
      RemoveConstraintInternal(pcn);
      if (FIsExplaining())
        throw e;
      else
        throw ExCLRequiredFailure();
      }
    }

  _fNeedsSolving = true;

  if (pcn->IsEditConstraint())
    {
    ClEditConstraint *pcnEdit = dynamic_cast<ClEditConstraint *>(pcn);
    ClVariable clv = pcnEdit->variable();
    _editInfoList.push_back(new ClEditInfo(clv, pcnEdit, clvEplus, clvEminus,
                                       prevEConstant));
    }

  if (_fAutosolve)
    {
    Optimize(_objective);
    SetExternalVariables();
    }

  pcn->addedTo(*this);
  return *this;
}

// Add weak stays to the x and y parts of each point. These have
// increasing weights so that the solver will try to satisfy the x
// and y stays on the same point, rather than the x stay on one and
// the y stay on another.
ClSimplexSolver &
ClSimplexSolver::AddPointStays(const vector<const ClPoint *> &listOfPoints,
                               const ClStrength &strength)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
#endif

  vector<const ClPoint *>::const_iterator it = listOfPoints.begin();
  double weight = 1.0;
  static const double multiplier = 2.0;
  for ( ; it != listOfPoints.end(); ++it )
    {
    AddPointStay((*it)->X(),(*it)->Y(),strength,weight);
    weight *= multiplier;
    }
  return *this;
}

ClSimplexSolver &
ClSimplexSolver::AddPointStay(const ClPoint &clp, const ClStrength &strength, double weight)
{ 
  AddPointStay(clp.X(),clp.Y(),strength,weight);
  return *this;
}


ClSimplexSolver &
ClSimplexSolver::RemoveEditVarsTo(int n)
{
  queue<ClVariable> qclv;
  ClVarSet sclvStillEditing; // Set of edit variables that we need to *not* remove
#ifdef DEBUG_NESTED_EDITS
  cerr << __FUNCTION__ << " " << n << endl;
#endif
  int i = 0;
  for ( ClEditInfoList::const_iterator it = _editInfoList.begin();
        (it != _editInfoList.end() && _editInfoList.size() != static_cast<unsigned int>(n));
        ++it, ++i ) 
    {
    const ClEditInfo *pcei = (*it);
    assert(pcei);
#ifdef DEBUG_NESTED_EDITS
    cerr << __FUNCTION__ << "Checking " << pcei->_clv
         << ", index = " << i << endl;
#endif
    if (i >= n)
      qclv.push(pcei->_clv);
    else
      sclvStillEditing.insert(pcei->_clv);
    }
  while (!qclv.empty()) 
    {
    ClVariable clv = qclv.front();
    // only remove the variable if it's not in the set of variable
    // from a previous nested outer edit
    // e.g., if I do:
    // Edit x,y
    // Edit w,h,x,y
    // EndEdit
    // The end edit needs to only get rid of the edits on w,h
    // not the ones on x,y
    if (sclvStillEditing.find(clv) == sclvStillEditing.end())
      {
#ifdef DEBUG_NESTED_EDITS
      cerr << __FUNCTION__ << ": Removing " << clv << endl;
#endif
      RemoveEditVar(clv);
      }
#ifdef DEBUG_NESTED_EDITS
    else
      {
      cerr << __FUNCTION__ << ": Not removing " << clv << endl;
      }
#endif
    qclv.pop();
    }
  while (_editInfoList.size() > n) {
    _editInfoList.pop_back();
  }
  
  return *this;
}


/* A predicate used for remove_if */
class VarInVarSet : public unary_function<ClVariable,bool> {
public:
  VarInVarSet(const ClVarSet &clvset) : 
      _set(clvset),
      _setEnd(clvset.end()) 
    { }

  bool operator ()(ClVariable clv) const {
    return (_set.find(clv) != _setEnd);
  }
  
private:
  const ClVarSet &_set;
  const ClVarSet::iterator _setEnd;
};



// Remove the constraint cn from the tableau
// Also remove any error variable associated with cn
ClSimplexSolver &
ClSimplexSolver::RemoveConstraintInternal(const ClConstraint *const pcn)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << *pcn << ")" << endl;
#endif

  // We are about to remove a constraint.  There may be some stay
  // constraints that were unsatisfied previously -- if we just
  // removed the constraint these could come into play.  Instead,
  // Reset all of the stays so that things should stay where they are
  // at the moment.
  _fNeedsSolving = true;

  ResetStayConstants();

  // remove any error variables from the objective function
  ClLinearExpression *pzRow = RowExpression(_objective);

#ifdef CL_TRACE
  cerr << _errorVars << endl << endl;
#endif

  ClConstraintToVarSetMap::iterator 
    it_eVars = _errorVars.find(pcn);
  bool fFoundErrorVar = (it_eVars != _errorVars.end());

  if (fFoundErrorVar)
    {
    ClVarSet &eVars = (*it_eVars).second;
    ClVarSet::iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      const ClLinearExpression *pexpr = RowExpression(*it);
      if (pexpr == NULL )
	{
	pzRow->AddVariable(*it,-pcn->weight() * pcn->strength().symbolicWeight().AsDouble(),
			   _objective,*this);
	}
      else
	{ // the error variable was in the basis
	pzRow->AddExpression(*pexpr,-pcn->weight() * pcn->strength().symbolicWeight().AsDouble(),
			     _objective,*this);
	}
      }
    }

  ClConstraintToVarMap::iterator 
    it_marker = _markerVars.find(pcn);
  if (it_marker == _markerVars.end())
    { // could not find the constraint
    throw ExCLConstraintNotFound();
    }
  // try to make the marker variable basic if it isn't already
  const ClVariable marker = (*it_marker).second;
  _markerVars.erase(it_marker);
  _constraintsMarked.erase(marker);
#ifdef CL_TRACE
  cerr << "Looking to remove var " << marker << endl;
#endif
  if (!FIsBasicVar(marker))
    { // not in the basis, so need to do some work
    // first choose which variable to move out of the basis
    // only consider restricted basic variables
    ClVarSet &col = _columns[marker];
    ClVarSet::iterator it_col = col.begin();
#ifdef CL_TRACE
    cerr << "Must Pivot -- columns are " << col << endl;
#endif

    ClVariable exitVar = clvNil;
    bool fExitVarSet = false;
    double minRatio = 0.0;
    for ( ; it_col != col.end(); ++it_col) 
      {
      const ClVariable &v = *it_col;
      if (v.IsRestricted() )
	{
	const ClLinearExpression *pexpr = RowExpression(v);
	assert(pexpr != NULL );
	Number coeff = pexpr->CoefficientFor(marker);
#ifdef CL_TRACE
	cerr << "Marker " << marker << "'s coefficient in " << *pexpr << " is "
	     << coeff << endl;
#endif
	// only consider negative coefficients
	if (coeff < 0.0) 
	  {
	  Number r = - pexpr->Constant() / coeff;
	  if (!fExitVarSet || r < minRatio)
	    {
	    minRatio = r;
	    exitVar = v;
            fExitVarSet = true;
	    }
	  }
	}
      }
    // if we didn't set exitvar above, then either the marker
    // variable has a positive coefficient in all equations, or it
    // only occurs in equations for unrestricted variables.  If it
    // does occur in an equation for a restricted variable, pick the
    // equation that gives the smallest ratio.  (The row with the
    // marker variable will become infeasible, but all the other rows
    // will still be feasible; and we will be dropping the row with
    // the marker variable.  In effect we are removing the
    // non-negativity restriction on the marker variable.)
    if (!fExitVarSet)
      {
#ifdef CL_TRACE
      cerr << "exitVar did not get set" << endl;
#endif
      it_col = col.begin();
      for ( ; it_col != col.end(); ++it_col) 
	{
	ClVariable v = *it_col;
	if (v.IsRestricted() )
	  {
	  const ClLinearExpression *pexpr = RowExpression(v);
	  assert(pexpr != NULL);
	  Number coeff = pexpr->CoefficientFor(marker);
	  Number r = pexpr->Constant() / coeff;
	  if (!fExitVarSet || r < minRatio)
	    {
	    minRatio = r;
	    exitVar = v;
            fExitVarSet = true;
	    }
	  }
	}
      }

    if (!fExitVarSet)
      { // exitVar is still nil
      // If col is empty, then exitVar doesn't occur in any equations,
      // so just remove it.  Otherwise pick an exit var from among the
      // unrestricted variables whose equation involves the marker var
      if (col.size() == 0)
	{
	RemoveColumn(marker);
	}
      else
	{
	  // A. Beurive' Tue Sep 14 18:26:05 CEST 1999
	  // Don't pick the objective, or it will be removed!
	  it_col = col.begin();
	  for ( ; it_col != col.end(); ++it_col)
	    {
	      ClVariable v = *it_col;
	      if (v != _objective)
		{
		  exitVar = v;
		  fExitVarSet = true;
		  break;
		}
	    }
	  assert(fExitVarSet == true);
	}
      }
    
    if (fExitVarSet)
      {
      Pivot(marker,exitVar);
      }
    }
  
  if (FIsBasicVar(marker))
    {
    ClLinearExpression *pexpr = RemoveRow(marker);
#ifdef CL_TRACE
    cerr << "delete@ " << pexpr << endl;
#endif
    delete pexpr;
    }

  // Delete any error variables.  If cn is an inequality, it also
  // contains a slack variable; but we use that as the marker variable
  // and so it has been deleted when we removed its row.
  if (fFoundErrorVar)
    {
    ClVarSet &eVars = (*it_eVars).second;
    ClVarSet::iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      ClVariable v = (*it);
      if (v != marker)
	{
	RemoveColumn(v);
	}
      }
    }

  if (pcn->isStayConstraint())
    {
    // iterate over the stay{Plus,Minus}ErrorVars and remove those
    // variables v in those vectors that are also in set eVars
    if (fFoundErrorVar)
      {
      ClVarSet &eVars = (*it_eVars).second;
      _stayPlusErrorVars
        .erase(remove_if(_stayPlusErrorVars.begin(),_stayPlusErrorVars.end(),
                         VarInVarSet(eVars)),
               _stayPlusErrorVars.end());
      _stayMinusErrorVars
        .erase(remove_if(_stayMinusErrorVars.begin(),_stayMinusErrorVars.end(),
                         VarInVarSet(eVars)),
               _stayMinusErrorVars.end());
      }
    }
  else if (pcn->IsEditConstraint())
    {
    const ClEditConstraint *pcnEdit = dynamic_cast<const ClEditConstraint *>(pcn);
    const ClVariable clv = pcnEdit->variable();
    ClEditInfo *pcei = PEditInfoFromClv(clv);
    assert(pcei);
    ClVariable clvEditMinus = pcei->_clvEditMinus;
    RemoveColumn(clvEditMinus);  // clvEditPlus is a marker var and gets removed later
    delete pcei;
    _editInfoList.remove(pcei);
    }

  if (fFoundErrorVar)
    {
    // This code is not needed since the variables are deleted
    // when they are removed from the row --
    // leaving it in results in double deletions
    // delete the constraint's error variables
    //    ClVarSet &evars_set = (*it_eVars).second;
    //    ClVarSet::const_iterator it_set = evars_set.begin();
    //    for ( ; it_set != evars_set.end(); ++it_set)
    //      {
    //      delete *it_set;
    //      }
    _errorVars.erase((*it_eVars).first);
    }

  if (_fAutosolve)
    {
    Optimize(_objective);
    SetExternalVariables();
    }

  return *this;
}


// Re-initialize this solver from the original constraints, thus
// getting rid of any accumulated numerical problems.  (Actually,
// Alan hasn't observed any such problems yet, but here's the method
// anyway.)
void 
ClSimplexSolver::Reset()
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "()" << endl;
#endif
  // FIXGJB  -- can postpone writing this for a while
  // gotta be careful, though, as it's a likely place for
  // a memory leak to sneak in
  assert(false);
}


// Re-solve the cuurent collection of constraints, given the new
// values for the edit variables that have already been
// suggested (see SuggestValue() method)
void 
ClSimplexSolver::Resolve()
{ // CODE DUPLICATED ABOVE
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
#endif
  DualOptimize();
  SetExternalVariables();
  _infeasibleRows.clear();
  if (_fResetStayConstantsAutomatically)
    ResetStayConstants();
}

ClSimplexSolver &
ClSimplexSolver::SuggestValue(ClVariable v, Number x)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
#endif
  ClEditInfo *pcei = PEditInfoFromClv(v);
  if (NULL == pcei)
    {
#ifndef CL_NO_IO
    strstream ss;
    ss << "SuggestValue for variable " << v << ", but var is not an edit variable" << ends;
    throw ExCLEditMisuse(ss.str());
#else
    throw ExCLEditMisuse(v.Name().c_str());
#endif
    }
  ClVariable clvEditPlus = pcei->_clvEditPlus;
  ClVariable clvEditMinus = pcei->_clvEditMinus;
  Number delta = x - pcei->_prevEditConstant;
  pcei->_prevEditConstant = x;
  DeltaEditConstant(delta,clvEditPlus,clvEditMinus);
  return *this;
}

// Re-solve the cuurent collection of constraints, given the new
// values for the edit variables that have already been
// suggested (see SuggestValue() method)
// This is not guaranteed to work if you remove an edit constraint
// from the middle of the edit constraints you added
// (e.g., edit A, edit B, edit C, remove B -> this will fail!)
// DEPRECATED
void 
ClSimplexSolver::Resolve(const vector<Number> &newEditConstants)
{
  ClEditInfoList::iterator it = _editInfoList.begin();
  int i = 0;
  for (; i < newEditConstants.size() && it != _editInfoList.end(); ++it, ++i)
    {
    ClEditInfo *pcei = (*it);
    SuggestValue(pcei->_clv,newEditConstants[i]);
    }
  Resolve();
}


//// protected

// Add the constraint expr=0 to the inequality tableau using an
// artificial variable.  To do this, create an artificial variable
// av and Add av=expr to the inequality tableau, then make av be 0.
// (Raise an exception if we can't attain av=0 -- and prepare explanation)
bool
ClSimplexSolver::AddWithArtificialVariable(ClLinearExpression &expr,
                                           ExCLRequiredFailureWithExplanation &e)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << expr << ")" << endl;
#endif
  
  // Allocate the objects on the heap because the objects
  // will remain in the tableau if we throw an exception,
  // and that will result in the destructor cleaning up
  // after us
  ClSlackVariable *pav = new ClSlackVariable(++_artificialCounter,"a");
  ClObjectiveVariable *paz = new ClObjectiveVariable("az");
  ClLinearExpression *pazRow = new ClLinearExpression(expr);
  // the artificial objective is av, which we know is equal to expr
  // (which contains only parametric variables)

#ifdef CL_FIND_LEAK
  cerr << "aC = " << _artificialCounter
       << "\nDeletes = " << _cArtificialVarsDeleted << endl;
#endif
#ifdef CL_TRACE
  cerr << __FUNCTION__ << " before addRow-s:\n"
       << (*this) << endl;
#endif

  // the artificial objective is av, which we know is equal to expr
  // (which contains only parametric variables)
  
  // objective is treated as a row in the tableau,
  // so do the substitution for its value (we are minimizing
  // the artificial variable)
  // this row will be removed from the tableau after optimizing
  addRow(*paz,*pazRow);
  
  // now Add the normal row to the tableau -- when artifical
  // variable is minimized to 0 (if possible)
  // this row remains in the tableau to maintain the constraint
  // we are trying to Add
  addRow(*pav,expr);

#ifdef CL_TRACE
  cerr << __FUNCTION__ << " after addRow-s:\n"
       << (*this) << endl;
#endif

  // try to Optimize az to 0
  // note we are *not* optimizing the real objective, but optimizing
  // the artificial objective to see if the error in the constraint
  // we are adding can be set to 0
  Optimize(*paz);

  // Careful, we want to get the Expression that is in
  // the tableau, not the one we initialized it with!
  ClLinearExpression *pazTableauRow = RowExpression(*paz);
#ifdef CL_TRACE
  cerr << "pazTableauRow->Constant() == " << pazTableauRow->Constant() << endl;
#endif

  // Check that we were able to make the objective value 0
  // If not, the original constraint was not satisfiable
  if (!ClApprox(pazTableauRow->Constant(),0.0))
    {
    BuildExplanation(e, paz, pazTableauRow);
    // remove the artificial objective row that we just
    // added temporarily
    delete RemoveRow(*paz);
    // and delete the artificial objective variable that we also added above
    delete paz;
    return false;
    }

  // see if av is a basic variable
  const ClLinearExpression *pe = RowExpression(*pav);
  if (pe != NULL)
    {
    // FIXGJB: do we ever even get here?
    // Find another variable in this row and Pivot, so that av becomes parametric
    // If there isn't another variable in the row then 
    // the tableau contains the equation av = 0  -- just delete av's row
    if (pe->IsConstant())
      {
      // FIXGJB: do we ever get here?
      assert(ClApprox(pe->Constant(),0.0));
      delete RemoveRow(*pav);
      // remove the temporary objective function
      // FIXGJB may need this too: delete RemoveRow(*paz);
      delete pav;
#ifdef CL_FIND_LEAK
      ++_cArtificialVarsDeleted;
#endif
      return true;
      }
    ClVariable entryVar = pe->AnyPivotableVariable();
    if (entryVar.IsNil())
      {
      BuildExplanation(e, *pav, pe);
      return false; /* required failure */
      }
    Pivot(entryVar, *pav);
    }
  // now av should be parametric
  assert(RowExpression(*pav) == NULL);
  RemoveColumn(*pav);
  delete pav;
#ifdef CL_FIND_LEAK
  ++_cArtificialVarsDeleted;
#endif
  // remove the temporary objective function
  delete RemoveRow(*paz);
  delete paz;
  return true;
}


// Using the given equation (av = cle) build an explanation which
// implicates all constraints used to construct the equation. That
// is, everything for which the variables in the equation are markers.
void ClSimplexSolver::BuildExplanation(ExCLRequiredFailureWithExplanation &e,
                                       ClVariable av,
                                       const ClLinearExpression *pcle)
{
  ClVarToConstraintMap::iterator it_cn;
  it_cn = _constraintsMarked.find(av);
  if (it_cn != _constraintsMarked.end()) 
    {
      e.AddConstraint((*it_cn).second);
    }
  
  assert(pcle != NULL);
  
  const ClVarToNumberMap & terms = pcle->Terms();
  ClVarToNumberMap::const_iterator it_term;
  for (it_term = terms.begin(); it_term != terms.end(); it_term++)
    {
    it_cn = _constraintsMarked.find((*it_term).first);
    if (it_cn != _constraintsMarked.end()) 
      {
      e.AddConstraint((*it_cn).second);
      }
    }
}



// We are trying to Add the constraint expr=0 to the appropriate
// tableau.  Try to Add expr directly to the tableaus without
// creating an artificial variable.  Return true if successful and
// false if not.
bool 
ClSimplexSolver::TryAddingDirectly(ClLinearExpression &expr) 
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << expr << ")" << endl;
#endif
  ClVariable subject = ChooseSubject(expr);
  if (subject.get_pclv() == NULL )
    {
#ifdef CL_TRACE
    cerr << "- returning false" << endl;
#endif
    return false;
    }
  expr.NewSubject(subject);
  if (ColumnsHasKey(subject))
    {
    SubstituteOut(subject,expr);
    }
  addRow(subject,expr);
#ifdef CL_TRACE
  cerr << "- returning true" << endl;
#endif
  return true; // successfully added directly
}


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
ClVariable
ClSimplexSolver::ChooseSubject(ClLinearExpression &expr)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << expr << ")" << endl;
#endif
  ClVariable subject(clvNil); // the current best subject, if any

  // true iff we have found a subject that is an unrestricted variable
  bool foundUnrestricted = false; 

  // true iff we have found a restricted variable that is new to the
  // solver (except for being in the obj. function) and that has a
  // negative coefficient
  bool foundNewRestricted = false;

  const ClVarToNumberMap &terms = expr.Terms();
  ClVarToNumberMap::const_iterator it = terms.begin();
  for ( ; it != terms.end(); ++it )
    {
    ClVariable v = (*it).first;
    Number c = (*it).second;

    if (foundUnrestricted)
      {
      // We have already found an unrestricted variable.  The only
      // time we will want to use v instead of the current choice
      // 'subject' is if v is unrestricted and new to the solver and
      // 'subject' isn't new.  If this is the case just pick v
      // immediately and return.
      if (!v.IsRestricted())
	{
	if (!ColumnsHasKey(v))
	  return v;
	}
      }
    else
      { // we haven't found an restricted variable yet
      if (v.IsRestricted())
	{
	// v is restricted.  If we have already found a suitable
	// restricted variable just stick with that.  Otherwise, if v
	// is new to the solver and has a negative coefficient pick
	// it.  Regarding being new to the solver -- if the variable
	// occurs only in the objective function we regard it as being
	// new to the solver, since error variables are added to the
	// objective function when we make the Expression.  We also
	// never pick a dummy variable here.
	if (!foundNewRestricted && !v.IsDummy() && c < 0.0)
	  {
	  const ClTableauColumnsMap &col = Columns();
	  ClTableauColumnsMap::const_iterator it_col = col.find(v);
	  if (it_col == col.end() || 
	      ( col.size() == 1 && ColumnsHasKey(_objective) ) )
	    {
	    subject = v;
	    foundNewRestricted = true;
	    }
	  }
	}
      else
	{
	// v is unrestricted.  
	// If v is also new to the solver just pick it now
	subject = v;
	foundUnrestricted = true;
	}
      }
    }
  if (!subject.IsNil())
    return subject;

  // subject is nil. 
  // Make one last check -- if all of the variables in expr are dummy
  // variables, then we can pick a dummy variable as the subject
  Number coeff = 0;
  it = terms.begin();
  for ( ; it != terms.end(); ++it )
    {
    ClVariable v = (*it).first;
    Number c = (*it).second;
    if (!v.IsDummy())
      return clvNil; // nope, no luck
    // if v is new to the solver, tentatively make it the subject
    if (!ColumnsHasKey(v))
      {
      subject = v;
      coeff = c;
      }
    }

  // If we get this far, all of the variables in the Expression should
  // be dummy variables.  If the Constant is nonzero we are trying to
  // Add an unsatisfiable required constraint.  (Remember that dummy
  // variables must take on a value of 0.)  Otherwise, if the Constant
  // is Zero, multiply by -1 if necessary to make the coefficient for
  // the subject negative."
  if (!ClApprox(expr.Constant(),0.0))
    {
#ifdef CL_DEBUG_FAILURES
    cerr << "required failure in choose subject:\n"
         << *this << endl;
#endif
    if (FIsExplaining()) 
      {
      ExCLRequiredFailureWithExplanation e;
      BuildExplanation(e, clvNil, &expr);
      throw e;
      }
    else
      throw ExCLRequiredFailure();
    }
  if (coeff > 0.0)
    {
    expr.MultiplyMe(-1);
    }
  return subject;
}
  
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
void 
ClSimplexSolver::DeltaEditConstant(Number delta,
				   ClVariable plusErrorVar,
				   ClVariable minusErrorVar)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << delta << ", " << plusErrorVar << ", " << minusErrorVar << ")" << endl;
#endif
  // first check if the plusErrorVar is basic
  ClLinearExpression *pexprPlus = RowExpression(plusErrorVar);
  if (pexprPlus != NULL )
    {
    pexprPlus->IncrementConstant(delta);
    // error variables are always restricted
    // so the row is infeasible if the Constant is negative
    if (pexprPlus->Constant() < 0.0)
      {
      _infeasibleRows.insert(plusErrorVar);
      }
    return;
    }
  // check if minusErrorVar is basic
  ClLinearExpression *pexprMinus = RowExpression(minusErrorVar);
  if (pexprMinus != NULL)
    {
    pexprMinus->IncrementConstant(-delta);
    if (pexprMinus->Constant() < 0.0)
      {
      _infeasibleRows.insert(minusErrorVar);
      }
    return;
    }
  // Neither is basic.  So they must both be nonbasic, and will both
  // occur in exactly the same expressions.  Find all the expressions
  // in which they occur by finding the column for the minusErrorVar
  // (it doesn't matter whether we look for that one or for
  // plusErrorVar).  Fix the constants in these expressions.
  ClVarSet &columnVars = _columns[minusErrorVar];
  ClVarSet::iterator it = columnVars.begin();
  for (; it != columnVars.end(); ++it)
    {
    ClVariable basicVar = *it;
    ClLinearExpression *pexpr = RowExpression(basicVar);
    assert(pexpr != NULL );
    double c = pexpr->CoefficientFor(minusErrorVar);
    pexpr->IncrementConstant(c*delta);
    if (basicVar.IsRestricted() && pexpr->Constant() < 0.0)
      {
      _infeasibleRows.insert(basicVar);
      }
    }
}
  
// We have set new values for the constants in the edit constraints.
// Re-Optimize using the dual simplex algorithm.
void 
ClSimplexSolver::DualOptimize()
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "()" << endl;
#endif
  const ClLinearExpression *pzRow = RowExpression(_objective);
  // need to handle infeasible rows
  while (!_infeasibleRows.empty())
    {
    ClVarSet::iterator it_exitVar = _infeasibleRows.begin();
    ClVariable exitVar = *it_exitVar;
    _infeasibleRows.erase(it_exitVar);
    ClVariable entryVar;
    // exitVar might have become basic after some other pivoting
    // so allow for the case of its not being there any longer
    ClLinearExpression *pexpr = RowExpression(exitVar);
    if (pexpr != NULL )
      {
      // make sure the row is still not feasible
      if (pexpr->Constant() < 0.0)
	{
	double ratio = DBL_MAX;
	double r;
	ClVarToNumberMap &terms = pexpr->Terms();
	ClVarToNumberMap::iterator it = terms.begin();
	for ( ; it != terms.end(); ++it )
	  {
	  ClVariable v = (*it).first;
	  Number c = (*it).second;
	  if (c > 0.0 && v.IsPivotable())
	    {
	    Number zc = pzRow->CoefficientFor(v);
	    r = zc/c; // FIXGJB r:= zc/c or Zero, as ClSymbolicWeight-s
	    if (r < ratio)
	      {
	      entryVar = v;
	      ratio = r;
	      }
	    }
	  }
	if (ratio == DBL_MAX)
	  {
          strstream ss;
	  ss << "ratio == nil (DBL_MAX)" << ends;
	  throw ExCLInternalError(ss.str());
	  }
	Pivot(entryVar,exitVar);
	}
      }
    }
}

// Make a new linear Expression representing the constraint cn,
// replacing any basic variables with their defining expressions.
// Normalize if necessary so that the Constant is non-negative.  If
// the constraint is non-required give its error variables an
// appropriate weight in the objective function.
ClLinearExpression *
ClSimplexSolver::NewExpression(const ClConstraint *pcn,
                               /* output to */
                               ClVariable &clvEplus,
                               ClVariable &clvEminus,
                               Number &prevEConstant)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << *pcn << ")" << endl;
  cerr << "cn.IsInequality() == " << pcn->IsInequality() << endl;
  cerr << "cn.IsRequired() == " << pcn->IsRequired() << endl;
#endif
  const ClLinearExpression &cnExpr = pcn->Expression();
  cl_auto_ptr<ClLinearExpression> pexpr ( new ClLinearExpression(cnExpr.Constant()) );
  cl_auto_ptr<ClSlackVariable> pslackVar;
  cl_auto_ptr<ClDummyVariable> pdummyVar;
  cl_auto_ptr<ClSlackVariable> peminus(0);
  cl_auto_ptr<ClSlackVariable> peplus(0);
  const ClVarToNumberMap &cnTerms = cnExpr.Terms();
  ClVarToNumberMap::const_iterator it = cnTerms.begin();
  for ( ; it != cnTerms.end(); ++it)
    {
    ClVariable v = (*it).first;
    Number c = (*it).second;
    const ClLinearExpression *pe = RowExpression(v);
    if (pe == NULL)
      {
      pexpr->AddVariable(v,c);
      }
    else
      {
      pexpr->AddExpression(*pe,c);
      }
    }

  // Add slack and error variables as needed
  if (pcn->IsInequality())
    {
    // cn is an inequality, so Add a slack variable.  The original
    // constraint is expr>=0, so that the resulting equality is
    // expr-slackVar=0.  If cn is also non-required Add a negative
    // error variable, giving
    //    expr-slackVar = -errorVar, in other words
    //    expr-slackVar+errorVar=0.
    // Since both of these variables are newly created we can just Add
    // them to the Expression (they can't be basic).
    ++_slackCounter;
    ReinitializeAutoPtr(pslackVar,new ClSlackVariable (_slackCounter, "s"));
    pexpr->setVariable(*pslackVar,-1);
    // index the constraint under its slack variable and vice-versa
    _markerVars[pcn] = pslackVar.get();
    _constraintsMarked[pslackVar.get()] = pcn;
    
    if (!pcn->IsRequired())
      {
      ++_slackCounter;
      ReinitializeAutoPtr(peminus,new ClSlackVariable (_slackCounter, "em"));
      pexpr->setVariable(*peminus,1.0);
      // Add emnius to the objective function with the appropriate weight
      ClLinearExpression *pzRow = RowExpression(_objective);
      // FIXGJB: pzRow->AddVariable(eminus,pcn->strength().symbolicWeight() * pcn->weight());
      ClSymbolicWeight sw = pcn->strength().symbolicWeight().Times(pcn->weight());
      pzRow->setVariable(*peminus,sw.AsDouble());
      _errorVars[pcn].insert(peminus.get());
      NoteAddedVariable(*peminus,_objective);
      }
    }
  else
    { // cn is an equality
    if (pcn->IsRequired())
      {
      // Add a dummy variable to the Expression to serve as a marker
      // for this constraint.  The dummy variable is never allowed to
      // enter the basis when pivoting.
      ++_dummyCounter;
      ReinitializeAutoPtr(pdummyVar,new ClDummyVariable (_dummyCounter, "d"));
      pexpr->setVariable(*pdummyVar,1.0);
      _markerVars[pcn] = pdummyVar.get();
      _constraintsMarked[pdummyVar.get()] = pcn;
#ifdef CL_TRACE
      cerr << "Adding dummyVar == d" << _dummyCounter << endl;
#endif
      }
    else
      {
      // cn is a non-required equality.  Add a positive and a negative
      // error variable, making the resulting constraint 
      //       expr = eplus - eminus, 
      // in other words:  expr-eplus+eminus=0
      ++_slackCounter;
      ReinitializeAutoPtr(peplus,new ClSlackVariable (_slackCounter, "ep"));
      ReinitializeAutoPtr(peminus,new ClSlackVariable (_slackCounter, "em"));

      pexpr->setVariable(*peplus,-1.0);
      pexpr->setVariable(*peminus,1.0);
      // index the constraint under one of the error variables
      _markerVars[pcn] = peplus.get();
      _constraintsMarked[peplus.get()] = pcn;

      ClLinearExpression *pzRow = RowExpression(_objective);
      // FIXGJB: pzRow->AddVariable(eplus,pcn->strength().symbolicWeight() * pcn->weight());
      ClSymbolicWeight sw = pcn->strength().symbolicWeight().Times(pcn->weight());
      double swCoeff = sw.AsDouble();
#ifdef CL_TRACE
      if (swCoeff == 0) 
	{
	cerr << "sw == " << sw << endl
	     << "cn == " << *pcn << endl;
	cerr << "adding " << *peplus << " and " << *peminus 
	     << " with swCoeff == " << swCoeff << endl;
	}
#endif      
      pzRow->setVariable(*peplus,swCoeff);
      NoteAddedVariable(*peplus,_objective);
      // FIXGJB: pzRow->AddVariable(eminus,pcn->strength().symbolicWeight() * pcn->weight());
      pzRow->setVariable(*peminus,swCoeff);
      NoteAddedVariable(*peminus,_objective);
      _errorVars[pcn].insert(peminus.get());
      _errorVars[pcn].insert(peplus.get());
      if (pcn->isStayConstraint()) 
	{
	_stayPlusErrorVars.push_back(peplus.get());
	_stayMinusErrorVars.push_back(peminus.get());
	}
      else if (pcn->IsEditConstraint())
	{
        clvEplus = peplus.get();
        clvEminus = peminus.get();
        prevEConstant = cnExpr.Constant();
	}
      }
    }

  // the Constant in the Expression should be non-negative.
  // If necessary normalize the Expression by multiplying by -1
  if (pexpr->Constant() < 0)
    {
#ifdef CL_TRACE
    cerr << "NewExpression's Constant is " << pexpr->Constant() << ", < 0, so flipping" << endl;
#endif
    pexpr->MultiplyMe(-1);
    }
#ifdef CL_TRACE
  cerr << "- returning " << *pexpr << endl;
#endif
  // Terrible Name -- release() does *not* delete the object,
  // only makes sure that the destructor won't delete the object
  // (it releases the cl_auto_ptr from the responsibility of deleting the object)
  pslackVar.release();
  pdummyVar.release();
  peminus.release();
  peplus.release();
  return pexpr.release();
}

// Minimize the value of the objective.  (The tableau should already
// be feasible.)
void 
ClSimplexSolver::Optimize(ClVariable zVar)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << zVar << ")\n"
       << *this << endl;
#endif
  ClLinearExpression *pzRow = RowExpression(zVar);
  assert(pzRow != NULL);
  ClVariable entryVar = clvNil;
  ClVariable exitVar = clvNil;
  while (true)
    {
    Number objectiveCoeff = 0;
    // Find the most negative coefficient in the objective function
    // (ignoring the non-pivotable dummy variables).  If all
    // coefficients are positive we're done
    ClVarToNumberMap &terms = pzRow->Terms();
    ClVarToNumberMap::iterator it = terms.begin();
    for (; it != terms.end(); ++it)
      {
      ClVariable v = (*it).first;
      Number c = (*it).second;
      if (v.IsPivotable() && c < objectiveCoeff)
	{
	objectiveCoeff = c;
	entryVar = v;
	// A. Beurive' Tue Jul 13 23:03:05 CEST 1999 Why the most
	// negative?  I encountered unending cycles of pivots!
	break;
	}
      }
    // if all coefficients were positive (or if the objective
    // function has no pivotable variables)
    // we are at an optimum
    if (objectiveCoeff >= -_epsilon)
      return;
#ifdef CL_TRACE
    cerr << "entryVar == " << entryVar << ", "
	 << "objectiveCoeff == " << objectiveCoeff
	 << endl;
#endif

    // choose which variable to move out of the basis
    // Only consider pivotable basic variables
    // (i.e. restricted, non-dummy variables)
    double minRatio = DBL_MAX;
    ClVarSet &columnVars = _columns[entryVar];
    ClVarSet::iterator it_rowvars = columnVars.begin();
    Number r = 0.0;
    for (; it_rowvars != columnVars.end(); ++it_rowvars)
      {
      ClVariable v = *it_rowvars;
#ifdef CL_TRACE
      cerr << "Checking " << v << endl;
#endif
      if (v.IsPivotable()) 
	{
	const ClLinearExpression *pexpr = RowExpression(v);
	Number coeff = pexpr->CoefficientFor(entryVar);
	// only consider negative coefficients
	if (coeff < 0.0)
	  {
	  r = - pexpr->Constant() / coeff;
	  if (r < minRatio)
	    {
#ifdef CL_TRACE
	    cerr << "New minRatio == " << r << endl;
#endif
	    minRatio = r;
	    exitVar = v;
	    }
	  }
	}
      }
    // If minRatio is still nil at this point, it means that the
    // objective function is unbounded, i.e. it can become
    // arbitrarily negative.  This should never happen in this
    // application.
    if (minRatio == DBL_MAX)
      {
      strstream ss;
      ss << "objective function is unbounded!" << ends;
      throw ExCLInternalError(ss.str());
      }
    Pivot(entryVar, exitVar);
#ifdef CL_TRACE
    cerr << "After Optimize:\n"
         << *this << endl;
#endif
    }
}

// Do a Pivot.  Move entryVar into the basis (i.e. make it a basic variable),
// and move exitVar out of the basis (i.e., make it a parametric variable)
void 
ClSimplexSolver::Pivot(ClVariable entryVar, ClVariable exitVar)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << entryVar << ", " << exitVar << ")" << endl;
#endif

  // the entryVar might be non-pivotable if we're doing a RemoveConstraint --
  // otherwise it should be a pivotable variable -- enforced at call sites,
  // hopefully
  
  // expr is the Expression for the exit variable (about to leave the basis) -- 
  // so that the old tableau includes the equation:
  //   exitVar = expr
  ClLinearExpression *pexpr = RemoveRow(exitVar);

  // Compute an Expression for the entry variable.  Since expr has
  // been deleted from the tableau we can destructively modify it to
  // build this Expression.
  pexpr->ChangeSubject(exitVar,entryVar);
  SubstituteOut(entryVar,*pexpr);

  if (entryVar.IsExternal())
    {
    // entry var is no longer a parametric variable since we're moving
    // it into the basis
    _externalParametricVars.erase(entryVar);
    }
  addRow(entryVar,*pexpr);
}



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
void 
ClSimplexSolver::ResetStayConstants()
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "()" << endl;
#endif
  ClVarVector::const_iterator 
    itStayPlusErrorVars = _stayPlusErrorVars.begin();
  ClVarVector::const_iterator 
    itStayMinusErrorVars = _stayMinusErrorVars.begin();

  for ( ; itStayPlusErrorVars != _stayPlusErrorVars.end();
	++itStayPlusErrorVars, ++itStayMinusErrorVars )
    {
    ClLinearExpression *pexpr = RowExpression(*itStayPlusErrorVars);
    if (pexpr == NULL )
      {
      pexpr = RowExpression(*itStayMinusErrorVars);
      }
    if (pexpr != NULL)
      {
      pexpr->Set_constant(0.0);
      }
    }
}

// Set the external variables known to this solver to their appropriate values.
// Set each external basic variable to its value, and set each
// external parametric variable to 0.  (It isn't clear that we will
// ever have external parametric variables -- every external
// variable should either have a stay on it, or have an equation
// that defines it in terms of other external variables that do have
// stays.  For the moment I'll put this in though.)  Variables that
// are internal to the solver don't actually store values -- their
// values are just implicit in the tableu -- so we don't need to set
// them."
void 
ClSimplexSolver::SetExternalVariables()
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "()\n"
       << *this << endl;
#endif

  // FIXGJB -- oughta check some invariants here

  // Set external parametric variables first
  // in case I've screwed up
  ClVarSet::iterator itParVars = _externalParametricVars.begin();
  for ( ; itParVars != _externalParametricVars.end(); ++itParVars )
    {
    ClVariable v = *itParVars;
#ifndef NDEBUG
    // defensively skip it if it is basic -- ChangeValue is virtual
    // so don't want to call it twice;  this should never
    // happen
    if (FIsBasicVar(v))
      {
#ifndef CL_NO_IO
      // WARNING
      cerr << __FUNCTION__ << "Error: variable " << v 
           << " in _externalParametricVars is basic" << endl;
      cerr << "Row is: " << *RowExpression(v) << endl;
#endif
      continue;
      }
#endif
    ChangeClv(v,0.0);
    }

  // Only iterate over the rows w/ external variables
  ClVarSet::iterator itRowVars = _externalRows.begin();
  for ( ; itRowVars != _externalRows.end() ; ++itRowVars )
    {
    ClVariable v = *itRowVars;
    ClLinearExpression *pexpr = RowExpression(v);
    ChangeClv(v,pexpr->Constant());
    }

  _fNeedsSolving = false;
  if (_pfnResolveCallback)
    _pfnResolveCallback(this);
}

#ifndef CL_NO_IO
ostream &
PrintTo(ostream &xo, const ClVarVector &varlist)
{
  ClVarVector::const_iterator it = varlist.begin();
  xo << varlist.size() << ":" << "[ ";
  if (it != varlist.end())
    {
    xo << *it;
    ++it;
    }
  for (; it != varlist.end(); ++it) 
    {
    xo << ", " << *it;
    }
  xo << " ]";
  return xo;
}

ostream &operator<<(ostream &xo, const ClVarVector &varlist)
{ return PrintTo(xo,varlist); }


ostream &
PrintTo(ostream &xo, const ClConstraintToVarSetMap &mapCnToVarSet)
{
  ClConstraintToVarSetMap::const_iterator it = mapCnToVarSet.begin();
  for ( ; it != mapCnToVarSet.end(); ++it) {
    const ClConstraint *pcn = (*it).first;
    const ClVarSet &set = (*it).second;
    xo << "CN: " << pcn << *pcn << ":: " << set << endl;
  }
  return xo;
}

ostream &operator <<(ostream &xo, const ClConstraintToVarSetMap &mapCnToVarSet)
{ return PrintTo(xo,mapCnToVarSet); }



ostream &
ClSimplexSolver::PrintOn(ostream &xo) const
{
  super::PrintOn(xo);

  xo << "_stayPlusErrorVars: "
     << _stayPlusErrorVars << endl;
  xo << "_stayMinusErrorVars: "
     << _stayMinusErrorVars << endl;
  xo << "_editInfoList:\n"
     << _editInfoList << endl;
  return xo;
}


ostream &
ClSimplexSolver::PrintInternalInfo(ostream &xo) const
{
  super::PrintInternalInfo(xo);
  xo << "; edvars: " << _editInfoList.size();
  xo << endl;
  printExternalVariablesTo(xo);
  return xo;
}

ostream &operator<<(ostream &xo, const ClSimplexSolver &clss)
{
  return clss.PrintOn(xo);
}

#endif

bool 
ClSimplexSolver::FIsConstraintSatisfied(const ClConstraint *const pcn) const
{
  ClConstraintToVarMap::const_iterator it_marker = _markerVars.find(pcn);
  if (it_marker == _markerVars.end())
    { // could not find the constraint
    throw ExCLConstraintNotFound();
    }

#ifndef CL_NO_IO
  bool fCnsays = pcn->FIsSatisfied();
#endif

  ClConstraintToVarSetMap::const_iterator it_eVars = _errorVars.find(pcn);

  if (it_eVars != _errorVars.end())
    {
    const ClVarSet &eVars = (*it_eVars).second;
    ClVarSet::const_iterator it = eVars.begin();
    for ( ; it != eVars.end(); ++it )
      {
      const ClLinearExpression *pexpr = RowExpression(*it);
      if (pexpr != NULL && !ClApprox(pexpr->Constant(),0.0))
        {
#ifndef CL_NO_IO
        if (fCnsays)
          cerr << __FUNCTION__ << ": constraint says satisfiable, but solver does not" << endl;
#endif
        return false;
        }
      }
    }

#ifndef CL_NO_IO
  if (!fCnsays)
    cerr << __FUNCTION__ << ": solver says satisfiable, but constraint does not" << endl;
#endif
  return true;
}



#ifndef CL_NO_ID

ostream &PrintTo(ostream &xo, const ClSimplexSolver::ClEditInfoList &listPEditInfo)
{
  ClSimplexSolver::ClEditInfoList::const_iterator it = listPEditInfo.begin();
  for ( ; it != listPEditInfo.end(); ++it) {
    const ClSimplexSolver::ClEditInfo *pcei = (*it);
    xo << *pcei << endl;
  }
  return xo;
}
  

ostream &operator<<(ostream &xo, const ClSimplexSolver::ClEditInfoList &listPEditInfo)
{ return PrintTo(xo,listPEditInfo); }

#endif

// A. Beurive' Tue Jul  6 17:03:32 CEST 1999
void
ClSimplexSolver::ChangeStrengthAndWeight(ClConstraint *pcn, const ClStrength &strength, double weight)
{
  ClConstraintToVarSetMap::iterator it_eVars = _errorVars.find(pcn);
  // Only for constraints that already have error variables (i.e. non-required constraints)
  assert(it_eVars != _errorVars.end());

  ClLinearExpression *pzRow = RowExpression(_objective);

  Number old_coeff = pcn->weight() * pcn->strength().symbolicWeight().AsDouble();
  pcn->setStrength(strength);
  pcn->setWeight(weight);
  Number new_coeff = pcn->weight() * pcn->strength().symbolicWeight().AsDouble();

  if (new_coeff != old_coeff)
    {
#ifdef CL_TRACE
      cerr << "Changing strength and/or weight for constraint: " << endl << *pcn << endl;
      cerr << "Updating objective row from:" << endl << *pzRow << endl;
#endif
      ClVarSet &eVars = (*it_eVars).second;
      ClVarSet::iterator it = eVars.begin();
      for ( ; it != eVars.end(); ++it )
	{
	  const ClLinearExpression *pexpr = RowExpression(*it);
	  if (pexpr == NULL )
	    {
	      pzRow->AddVariable(*it,-old_coeff,_objective,*this);
	      pzRow->AddVariable(*it,new_coeff,_objective,*this);
	    }
	  else
	    {
	      pzRow->AddExpression(*pexpr,-old_coeff,_objective,*this);
	      pzRow->AddExpression(*pexpr,new_coeff,_objective,*this);
	    }
	}
#ifdef CL_TRACE
      cerr << "to: " << endl << *pzRow << endl;
#endif

      if (_fAutosolve)
	{
	  Optimize(_objective);
	  SetExternalVariables();
	}
    }
}

// A. Beurive' Tue Jul  6 17:03:42 CEST 1999
void
ClSimplexSolver::ChangeStrength(ClConstraint *pcn, const ClStrength &strength)
{
  ChangeStrengthAndWeight(pcn,strength,pcn->weight());
}

// A. Beurive' Tue Jul  6 17:03:42 CEST 1999
void
ClSimplexSolver::ChangeWeight(ClConstraint *pcn, double weight)
{
  ChangeStrengthAndWeight(pcn,pcn->strength(),weight);
}
