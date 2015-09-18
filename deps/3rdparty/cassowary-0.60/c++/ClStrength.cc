// $Id: ClStrength.cc,v 1.18 1999/04/20 00:25:16 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This C++ Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClStrength.cc

#include "ClStrength.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

// Use the singleton pattern for the strength objects
const ClStrength &ClsRequired()
{
  // required is distinct by equality to this static object,
  // but I still use an especially high symbolic weight, just in case
  // FIXGJB: hack?
  static ClStrength required_strength("<Required>", 1000, 1000, 1000);
  return required_strength;
}

const ClStrength &ClsStrong()
{
  static ClStrength strong_strength("strong", 1.0, 0.0, 0.0);
  return strong_strength;
}

const ClStrength &ClsMedium()
{
  static ClStrength medium_strength("medium", 0.0, 1.0, 0.0);
  return medium_strength;
}


const ClStrength &ClsWeak()
{
  static ClStrength weak_strength("weak", 0.0, 0.0, 1.0);
  return weak_strength;
}

// special case for when nLevels = 3, should assert nLevels() == 3
ClStrength::ClStrength(const string &Name, double w1, double w2, double w3) :
  _name(Name), _symbolicWeight(w1, w2, w3)
{ 
}
