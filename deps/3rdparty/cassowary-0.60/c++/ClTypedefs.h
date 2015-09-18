// $Id: ClTypedefs.h,v 1.10 1999/04/27 01:14:03 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClTypedefs.h

#ifndef CL_TYPEDEFS_H__
#define CL_TYPEDEFS_H__

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "ClMap.h"
#include "ClSet.h"
#include "ClLinearExpression_fwd.h"
#include <set> // Since ClTableauVarSet is always a set (never a hash_set)
#include <vector>

class ClVariable;
class ClConstraint;
class ClEditInfo;

// For Tableau
// ClTableauVarSet is not a ClSet, for performance reasons 
// (Steve Wolfman discovered this, and seems to be true --02/17/99 gjb)
// I have not observed any big performance gains from using the hashtable based containers 
typedef ClSet<ClVariable> ClVarSet;  
typedef ClMap<ClVariable, ClVarSet > ClTableauColumnsMap;
typedef ClMap<ClVariable, ClLinearExpression *> ClTableauRowsMap;

// For Solver
typedef ClMap<const ClConstraint *, ClVarSet> ClConstraintToVarSetMap;
typedef ClMap<const ClConstraint *, ClVariable> ClConstraintToVarMap;
typedef ClMap<ClVariable, const ClConstraint *> ClVarToConstraintMap;
typedef vector<ClVariable> ClVarVector;

typedef ClSet<const ClConstraint *> ClConstraintSet;

// For FDSolver
typedef ClMap<ClVariable, ClConstraintSet> ClVarToConstraintSetMap;

#endif
