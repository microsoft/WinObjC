/* $Id: ClC.cc,v 1.22 1999/08/27 00:06:27 gjb Exp $
 * Cassowary Incremental Constraint Solver
 * Original Smalltalk Implementation by Alan Borning
 * This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
 * http://www.cs.washington.edu/homes/gjb
 * (C) 1998, 1999 Greg J. Badros and Alan Borning
 * See ../LICENSE for legal details regarding this software
 *
 * ClC.c
 * C wrapper for most important Cassowary functionality
 * (Originally developed for the Amaya CCSS extensions)
 */

#define CLC_IMPL
#include "ClC.h"

#include "Cl.h"
#include <strstream.h>
#include <stdio.h>
#include <limits.h>

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#define FDN_EOL LONG_MIN

#define boolean int

extern "C" {

typedef StringToVarMap *CL_VarMap;

CL_VarMap varmap = NULL;

/* Functions unique to the C interface */
void
CL_Init()
{
}

void
CL_Shutdown()
{
  /* empty */
}

CL_VarMap CL_VarMapNew()
{
  return new StringToVarMap();
}


CL_VarMap CL_SetVarMap(CL_VarMap varmap_)
{
  if (varmap_ == NULL)
    varmap_ = CL_VarMapNew();
  varmap = varmap_;
  ClVariable::SetVarMap(varmap);
  return varmap;
}

CL_VarMap CL_GetVarMap()
{
  return varmap;
}

/* return true iff the variable did exist
   in the current global varmap, else return false */
boolean
CL_VarMapDelete(const char *sz)
{
  const string s(sz);
  StringToVarMap::iterator it = varmap->find(s);
  if (it != varmap->end()) {
    varmap->erase(it);
    return true;
  }
  return false;
}


/* Return a new ClVariable with name and initial Value */
CLV CL_ClvNew(const char *szName, double Value, CL_SimplexSolver solver)
{
  ClVariable *pclv = new ClVariable(szName,Value);
  if (solver)
    solver->AddStay(*pclv);
#if 0
  fprintf(stderr,"Created var %s @ %p\n",szName,pclv->get_pclv());
#endif
  return pclv;
}



void CL_VariableSetPv(CLV var, void *pv)
{ var->SetPv(pv); }

void *CL_VariablePv(CLV var)
{ return var->Pv(); }

const char *
CL_VariableName(CLV var)
{ return var->Name().c_str(); }

/* Return a new ClSimplexSolver object */
CL_SimplexSolver CL_SimplexSolverNew()
{
  ClSimplexSolver *psolver = new ClSimplexSolver();
  return psolver;
}


/* Print the ClVariable out to the given FILE * */
void 
CL_ClvPrint(CLV var, FILE *out)
{
  strstream xo;
  xo << *var << ends;
  fprintf(out,"%s",xo.str());
}

/* Print the ClSolver object out to the given FILE * */
void 
CL_SolverPrint(CL_Solver solver, FILE *out)
{
  strstream xo;
  xo << *solver << ends;
  fprintf(out,"%s",xo.str());
}

/* Print the constraint object out to the given FILE * */
void 
CL_ConstraintPrint(CL_Constraint pcn, FILE *out)
{
  strstream xo;
  xo << *pcn << ends;
  fprintf(out,"%s",xo.str());
}


void 
CL_TableauPrintExternalVariables(CL_Tableau tableau, FILE *out)
{
  strstream xo;
  tableau->printExternalVariablesTo(xo);
  xo << ends;
  fprintf(out,"%s",xo.str());
}


void 
CL_SolverSetChangeClvCallback(CL_Solver solver, PfnChangeClvCallback pfn)
{
  solver->SetChangeClvCallback(pfn);
}

void 
CL_SimplexSolverAddStrongStay(CL_SimplexSolver solver, CLV var, double weight)
{
  solver->AddStay(*var,ClsMedium(),weight);
}

void 
CL_SimplexSolverAddStay(CL_SimplexSolver solver, CLV var, double weight)
{
  solver->AddStay(*var,ClsWeak(),weight);
}

/* Return a clvariable with the given name, or NULL if not found;
   be forgiving about leading/trailing whitespace in szNameConst,
   and also stopping once a non-id character is seen.*/
CLV CL_ClvLookupTrim(const char *szNameConst)
{
  char *szName = const_cast<char *>(szNameConst);
  // skip leading ws
  while (szName && *szName && *szName == ' ' || *szName == '\t')
    ++szName;
  char *pchEnd = szName + strcspn(szName," \t\n;:<>,./?~!@#$%^&*()+=|\\{}[]\"`'");
  char ch = '\0';
  if (pchEnd) {
    ch = *pchEnd;        // save the character
    *pchEnd = '\0';      // and terminate the string
  }
  CLV answer = CL_ClvLookup(szName);
  if (pchEnd) *pchEnd = ch; // restore the character
  return answer;
}

/* Return a clvariable with the given name, or NULL if not found */
CLV CL_ClvLookup(const char *szName)
{
  if (!varmap)
    return NULL;
  StringToVarMap::iterator it = varmap->find(szName);
  if (it == varmap->end())
    return NULL;
  ClVariable *pclv = new ClVariable(it->second);
  return pclv;
}

/* Return the Value of clv */
double CL_ClvValue(const CLV var)
{
  return var->Value();
}

boolean
CL_ClvIsNil(const CLV var)
{
  return var->IsNil();
}



/* Return a new constraint (or NULL) from parsing the strings */
CL_Constraint CL_ParseConstraint(const char *szConstraintRule, const char *szConstraintStrength)
{
  try {
    istrstream xiLine(szConstraintRule);
    ClConstraint *pcn = PcnParseConstraint(xiLine,ClVarLookupInMap(varmap,false),
                                           ClsFromSz(szConstraintStrength));
    return pcn;
  } catch (ExCLError &e) {
    fprintf(stderr,"%s\n",e.description().c_str());
    return NULL;
  }
}

boolean CL_FIsSatisfied(ClConstraint *pcn)
{
  return pcn->FIsSatisfied();
}


/* Add a constraint to the solver; return 1 on success, 0 on failure */
boolean CL_AddConstraint(CL_Solver solver, CL_Constraint cn)
{
  try {
    return (solver->AddConstraintNoException(cn)?1:0);
  } catch (...) {
    return 0;
  }
}

/* Add a constraint to the solver; return 1 on success, 0 on failure */
boolean CL_RemoveConstraint(CL_Solver solver, CL_Constraint cn)
{
  try {
    return (solver->RemoveConstraintNoException(cn)?1:0);
  } catch (...) {
    return 0;
  }
}

void CL_Solve(CL_Solver solver)
{
  solver->Solve();
}

void CL_Resolve(CL_Solver solver)
{
  solver->Resolve();
}


void CL_SimplexSolverSetEditedValue(CL_SimplexSolver solver, CLV var, double n)
{
  solver->SetEditedValue(*var,n);
}

#if defined(CL_HAVE_GTL) && defined(CL_BUILD_FD_SOLVER)

#include <stdarg.h>

/* Return a new ClVariable containing an FD variable with name and 
   varargs domain_values as its initial domain, terminated with FDN_EOL */
CLV CL_CldvNew(const char *szName, ...)
{
  va_list ap;
  va_start(ap, szName);
  list<FDNumber> l;
  FDNumber n;
  while ( (n = va_arg(ap, FDNumber)) != FDN_EOL) {
    l.push_back(n);
  }
  va_end(ap);

  ClVariable *pclv = new ClVariable(new ClFDVariable(szName,0.0,l));
#if 0
  fprintf(stderr,"Created fd var %s @ %p\n",szName,pclv->get_pclv());
#endif
  return pclv;
}


CL_FDSolver CL_FDSolverNew()
{
  ClFDSolver *psolver = new ClFDSolver();
  return psolver;
}

boolean CL_ClvIsFD(const CLV var)
{
  return var->IsFDVariable();
}

boolean CL_FDCanConvertCn(CL_Constraint cn)
{
  return ClFDBinaryOneWayConstraint::FCanConvertCn(*cn);
}

CL_Constraint CL_FDCnFromCn(CL_Constraint cn)
{
  try {
    return new ClFDBinaryOneWayConstraint(*cn);
  } catch (...) {
    return NULL;
  }
}

boolean CL_FCnOkayForSimplexSolver(CL_Constraint cn)
{
  return cn->FIsOkayForSimplexSolver();
}

#endif

} /* extern "C" */
