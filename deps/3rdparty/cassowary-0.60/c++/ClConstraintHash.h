// $Id: ClConstraintHash.h,v 1.5 1999/04/20 00:24:51 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClHash.h

#ifndef CL_HASH_H__
#define CL_HASH_H__

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#ifdef CL_USE_HASH_MAP_AND_SET

#include <hash_map>

class ClConstraint;

struct hash<const ClConstraint *> {
  size_t operator()(const ClConstraint * const p) const 
    { return size_t((unsigned long)p/CL_PTR_HASH_DIVISOR); }
};

struct hash<ClConstraint *> {
  size_t operator()(ClConstraint * const p) const 
    { return size_t((unsigned long)p/CL_PTR_HASH_DIVISOR); }
};

#endif // CL_USE_HASH_MAP_AND_SET


#endif
