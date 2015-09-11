// $Id: Cl.h,v 1.23 1999/07/26 16:41:23 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// Cl.h
// This is the top level include file for external clients

#ifndef CL_H
#define CL_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#ifdef CL_NO_IO
#undef CL_TRACE
#undef CL_SOLVER_STATS
#undef CL_DEBUG_FAILURES
#undef CL_TRACE_VERBOSE
#endif

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include "cassowary/ClVariable.h"
#include "cassowary/ClSimplexSolver.h"
#include "cassowary/ClLinearEquation.h"
#include "cassowary/ClLinearInequality.h"
#include "cassowary/ClErrors.h"
#include "cassowary/ClEditConstraint.h"
#include "cassowary/ClStayConstraint.h"
#include "cassowary/ClReader.h"
#include "cassowary/ClConstraint.h"
#if defined(CL_HAVE_GTL) && defined(CL_BUILD_FD_SOLVER)
#include "cassowary/ClFDBinaryOneWayConstraint.h"
#include "cassowary/ClFDSolver.h"
#endif

extern const char *szCassowaryVersion;

#endif
