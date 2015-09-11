// $Id: Cassowary.h,v 1.28 1999/08/27 00:06:26 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// Cassowary.h

#ifndef Cassowary_H
#define Cassowary_H

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#ifndef CL_PTR_HASH_DIVISOR
#define CL_PTR_HASH_DIVISOR 4
#endif

#include "ClConstraintHash.h"
#include <limits.h>

#ifdef USE_GC
#include "../../gc/gc_cpp.h"
#endif

#include <string>
#include <assert.h>

#ifdef _MSC_VER
#ifndef CL_NO_IO
#include <iostream>
#endif
#pragma warning(disable : 4786)
using namespace std;
#define __FUNCTION__ "WIN"
#else
#ifndef CL_NO_IO
#include <iostream.h>
#endif
#endif

typedef double Number;

typedef long FDNumber;

enum { FDN_NOTSET = LONG_MIN };

#define NEWVAR(x) do { cerr << "line " << __LINE__ << ": new " << x << endl; } while (0)
#define DELVAR(x) do { cerr << "line " << __LINE__ << ": del " << x << endl; } while (0)

#endif
