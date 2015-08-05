/*
**********************************************************************
* Copyright (C) 2011-2011, International Business Machines Corporation 
* and others.  All Rights Reserved.
**********************************************************************
************************************************************************
*   Date          Name        Description
*   05/14/2011    grhoten     Creation.
************************************************************************/

#ifndef DICTTEST_H
#define DICTTEST_H

#include "unicode/utypes.h"

#if !UCONFIG_NO_BREAK_ITERATION

#include "intltest.h"


class DictionaryWordTest: public IntlTest {
public:
    void runIndexedTest( int32_t index, UBool exec, const char* &name, char* par = NULL );
    void TestWordBoundaries();
    void TestThaiBreaks();
};

#endif /* #if !UCONFIG_NO_BREAK_ITERATION */

#endif

