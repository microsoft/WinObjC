// $Id: ClDummyVariable.cc,v 1.2 1999/03/18 00:07:03 gjb Exp $

#include "ClDummyVariable.h"

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#define CONFIG_H_INCLUDED
#endif

#ifdef CL_FIND_LEAK
long ClDummyVariable::cDummyVariables = 0;
#endif
