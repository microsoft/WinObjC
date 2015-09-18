// $Id: ClTableau.cc,v 1.44 1999/04/20 00:25:21 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClTableau.cc

#include "ClTableau.h"
#include "debug.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif


// delete the linear expressions
// let ClSimplexSolver worry about deleting the variables
ClTableau::~ClTableau()
{
  ClTableauRowsMap::iterator it = _rows.begin();
  for (; it != _rows.end(); ++it)
    {
    // free the ClLinearExpression that we new-ed 
#ifdef CL_TRACE
    cerr << "Deleting row  delete@ " << ((*it).second) << endl;
#endif
    delete (*it).second;
    }
}

#ifndef CL_NO_IO
// Some extra debugging info
ostream &
ClTableau::PrintInternalInfo(ostream &xo) const
{
  xo << "ncns:" << _rows.size() -1
     << "; cols:" << _columns.size()
     << "; infrows:" << _infeasibleRows.size() 
     << "; ebvars:" << _externalRows.size()
     << "; epvars:" << _externalParametricVars.size();
  return xo;
}


ostream &
ClTableau::printExternalVariablesTo(ostream &xo) const
{
  xo << "Parametric: ";
  ClVarSet::iterator itParVars = _externalParametricVars.begin();
  for ( ; itParVars != _externalParametricVars.end(); ++itParVars ) {
    ClVariable v = *itParVars;
    xo << v << " ";
  }
  xo << "\nBasic: ";
  ClVarSet::iterator itRowVars = _externalRows.begin();
  for ( ; itRowVars != _externalRows.end() ; ++itRowVars ) {
    ClVariable v = *itRowVars;
    xo << v << " ";
  }
  return xo << endl;
}

#endif


// Add v, update column cross indices
// v becomes a basic variable
// expr is now owned by ClTableau class, 
// and ClTableauis responsible for deleting it
// (also, expr better be allocated on the heap!)
void 
ClTableau::addRow(ClVariable var, const ClLinearExpression &expr)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << var << ", " << expr << ")" << endl;
#endif
  _rows[var] = const_cast<ClLinearExpression *>(&expr);
  ClVarToNumberMap::const_iterator it = expr.Terms().begin();
  // for each variable in expr, Add var to the set of rows which have that variable
  // in their Expression
  for (; it != expr.Terms().end(); ++it)
    {
    ClVariable v = (*it).first;
    _columns[v].insert(var);
    if (v.IsExternal() && !FIsBasicVar(v))
      {
      _externalParametricVars.insert(v);
      }
    }
  if (var.IsExternal())
    {
    _externalRows.insert(var);
    }
#ifdef CL_TRACE
  cerr << *this << endl;
#endif
}

// Remove var from the tableau -- remove the column cross indices for var
// and remove var from every Expression in rows in which v occurs
// Remove the parametric variable var, updating the appropriate column and row entries.
// (Renamed from Smalltalk implementation's `removeParametricVar')
ClVariable
ClTableau::RemoveColumn(ClVariable var)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << var << ")" << endl;
#endif
  ClTableauColumnsMap::iterator it_var = _columns.find(var);
  if (it_var == _columns.end())
    return var;  // nothing to do

  ClVarSet &varset = (*it_var).second;
  // remove the rows with the variables in varset
  ClVarSet::iterator it = varset.begin();
  for (; it != varset.end(); ++it)
    {
    ClVariable v = (*it);
    ClVarToNumberMap &Terms = _rows[v]->Terms();
    Terms.erase(Terms.find(var));
    }
  if (var.IsExternal())
    {
    _externalRows.erase(var);
    _externalParametricVars.erase(var);
    }
  _columns.erase(it_var);
  return var;
}

// Remove the basic variable v from the tableau row v=expr
// Then update column cross indices
ClLinearExpression *
ClTableau::RemoveRow(ClVariable var)
{
#ifdef CL_TRACE
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << var << ")" << endl;
#endif
  ClTableauRowsMap::iterator it = _rows.find(var);
  assert(it != _rows.end());
  ClLinearExpression *pexpr = (*it).second;
  ClVarToNumberMap &Terms = pexpr->Terms();
  ClVarToNumberMap::iterator it_term = Terms.begin();
  for (; it_term != Terms.end(); ++it_term)
    {
    ClVariable v = (*it_term).first;
    _columns[v].erase(var);
    if (_columns[v].size() == 0)
      {
      _columns.erase(v);
      _externalParametricVars.erase(v);
      }
    }

  _infeasibleRows.erase(var);

  if (var.IsExternal())
    {
    _externalRows.erase(var);
    _externalParametricVars.erase(var);
    }

  _rows.erase(it);
#ifdef CL_TRACE
  cerr << "- returning " << *pexpr << endl;
#endif
  return pexpr;
}

// Replace all occurrences of oldVar with expr, and update column cross indices
// oldVar should now be a basic variable
// Uses the Columns data structure and calls SubstituteOut on each
// row that has oldVar in it
// oldVar is leaving the basis, and becoming parametric
void 
ClTableau::SubstituteOut(ClVariable oldVar, const ClLinearExpression &expr)
{
#ifdef CL_TRACE
  cerr << "* ClTableau::";
  Tracer TRACER(__FUNCTION__);
  cerr << "(" << oldVar << ", " << expr << ")" << endl;
  cerr << (*this) << endl;
#endif

  ClTableauColumnsMap::iterator it_oldVar = _columns.find(oldVar);
  if (it_oldVar == _columns.end())
    return;

  ClVarSet &varset = (*it_oldVar).second;
  ClVarSet::iterator it = varset.begin();
  for (; it != varset.end(); ++it)
    {
    ClVariable v = (*it);
    ClLinearExpression *prow = _rows[v];
    prow->SubstituteOut(oldVar,expr,v,*this);
    if (v.IsRestricted() && prow->Constant() < 0.0)
      {
      _infeasibleRows.insert(v);
      }
    }
  _columns.erase(it_oldVar);
  if (oldVar.IsExternal())
    {
    if (_columns[oldVar].size() > 0) 
      {
      _externalRows.insert(oldVar);
      }
    _externalParametricVars.erase(oldVar);
    }
}


#ifndef CL_NO_IO

ostream &
PrintTo(ostream &xo, const ClVarSet & varset)
{
  ClVarSet::const_iterator it = varset.begin();
  xo << "{ ";
  if (it != varset.end())
    {
    xo << *it;
    ++it;
    }
  for (; it != varset.end(); ++it) 
    {
    xo << ", " << *it;
    }
  xo << " }";
  return xo;
}  

ostream &operator<<(ostream &xo, const ClVarSet & varset)
{ return PrintTo(xo,varset); }

ostream &
PrintTo(ostream &xo, const ClTableauColumnsMap & varmap)
{
  ClTableauColumnsMap::const_iterator it = varmap.begin();
  for (; it != varmap.end(); ++it) 
    {
    xo << (*it).first << " -> " << (*it).second << endl;
    }
  return xo;
}

ostream &operator<<(ostream &xo, const ClTableauColumnsMap & varmap)
{ return PrintTo(xo,varmap); }

ostream &
PrintTo(ostream &xo, const ClTableauRowsMap & rows)
{
  ClTableauRowsMap::const_iterator it = rows.begin();
  for (; it != rows.end(); ++it) 
    {
    ClVariable v = it->first;
    const ClLinearExpression *pe = it->second;
    xo << v << " <-=-> ";
    if (pe) xo << *pe; else xo << "NilExpr";
    xo << endl;
    }
  return xo;
}

ostream &operator<<(ostream &xo, const ClTableauRowsMap & rows)
{ return PrintTo(xo,rows); }

ostream &
ClTableau::PrintOn(ostream &xo) const
{
  xo << "Tableau:\n" 
     << _rows << endl;
  xo << "Columns:\n" 
     << _columns << endl;
  xo << "Infeasible rows: " 
     << _infeasibleRows << endl;
  xo << "External basic variables: "
     << _externalRows << endl;
  xo << "External parametric variables: "
     << _externalParametricVars << endl;
  return xo;
}

ostream &operator<<(ostream &xo, const ClTableau &clt)
{ return clt.PrintOn(xo); }

#endif
