/*
**********************************************************************
* Copyright (C) 2011-2011, International Business Machines Corporation 
* and others.  All Rights Reserved.
**********************************************************************
************************************************************************
*   Date          Name        Description
*   05/14/2011    grhoten     Creation.
************************************************************************/

#include "unicode/utypes.h"

#if !UCONFIG_NO_BREAK_ITERATION

#include "dicttest.h"
#include "textfile.h"
#include "uvector.h"
#include "unicode/rbbi.h"

void DictionaryWordTest::TestThaiBreaks() {
    UErrorCode status=U_ZERO_ERROR;
    BreakIterator* b;
    Locale locale = Locale("th");
    int32_t p, index;
    UChar c[]= { 
            0x0E01, 0x0E39, 0x0020, 0x0E01, 0x0E34, 0x0E19, 0x0E01, 0x0E38, 0x0E49, 0x0E07, 0x0020, 0x0E1B, 
            0x0E34, 0x0E49, 0x0E48, 0x0E07, 0x0E2D, 0x0E22, 0x0E39, 0x0E48, 0x0E43, 0x0E19, 
            0x0E16, 0x0E49, 0x0E33, 0x0000
    };
    int32_t expectedWordResult[] = {
            2, 3, 6, 10, 11, 15, 17, 20, 22
    };
    int32_t expectedLineResult[] = {
            3, 6, 11, 15, 17, 20, 22
    };

    int32_t size = u_strlen(c);
    UnicodeString text=UnicodeString(c);
    
    b = BreakIterator::createWordInstance(locale, status);
    if (U_FAILURE(status)) {
        errcheckln(status, "Unable to create thai word break iterator. - %s", u_errorName(status));
        return;
    }
    b->setText(text);
    p = index = 0;
    while ((p=b->next())!=BreakIterator::DONE && p < size) {
        if (p != expectedWordResult[index++]) {
            errln("Incorrect break given by thai word break iterator. Expected: %d  Got: %d", expectedWordResult[index-1], p);
        }
    }
    delete b;
    
    b = BreakIterator::createLineInstance(locale, status);
    if (U_FAILURE(status)) {
        errln("Unable to create thai line break iterator.");
        return;
    }
    b->setText(text);
    p = index = 0;
    while ((p=b->next())!=BreakIterator::DONE && p < size) {
        if (p != expectedLineResult[index++]) {
            errln("Incorrect break given by thai line break iterator. Expected: %d  Got: %d", expectedLineResult[index-1], p);
        }
    }

    delete b;
}

#define DICTIONARY_TEST_FILE "wordsegments.txt"

void DictionaryWordTest::TestWordBoundaries() {
    UErrorCode      status  = U_ZERO_ERROR;

    TextFile phrases(DICTIONARY_TEST_FILE, "UTF8", status);
    if (U_FAILURE(status)) {
        dataerrln("Can't open "DICTIONARY_TEST_FILE": %s; skipping test",
              u_errorName(status));
        return;
    }

    // Due to how the word break iterator works,
    // scripts for languages that use no spaces should use the correct dictionary by default.
    BreakIterator *wb = BreakIterator::createWordInstance("en", status);
    if (U_FAILURE(status)) {
        dataerrln("Word break iterator can not be opened: %s; skipping test",
              u_errorName(status));
        return;
    }

    int32_t pos, pIdx;
    int32_t testLines = 0;
    UnicodeString phrase;
    while (phrases.readLineSkippingComments(phrase, status, FALSE) && U_SUCCESS(status)) {
        UVector breaks(status);

        for (pIdx = 0; pIdx < phrase.length(); pIdx++) {
            if (phrase.charAt(pIdx) == 0x007C /* | */) {
                breaks.addElement(pIdx, status);
                phrase.remove(pIdx, 1);
            }
        }
        breaks.addElement(pIdx, status);

        wb->setText(phrase);
        int32_t brkArrPos = 0;
        while ((pos=wb->next())!=BreakIterator::DONE) {
            int32_t expectedPos = breaks.elementAti(brkArrPos);
            if (expectedPos != pos) {
                errln("Incorrect forward word break on line %d. Expected: %d  Got: %d",
                    phrases.getLineNumber(), breaks.elementAt(brkArrPos), pos);
            }
            brkArrPos++;
        }
        brkArrPos = breaks.size() - 1;
        while ((pos=wb->previous())!=BreakIterator::DONE) {
            brkArrPos--;
            int32_t expectedPos = breaks.elementAti(brkArrPos);
            if (expectedPos != pos) {
                errln("Incorrect backward word break on line %d. Expected: %d  Got: %d",
                    phrases.getLineNumber(), breaks.elementAt(brkArrPos), pos);
            }
        }
        testLines++;
    }
    delete wb;
    logln("%d tests were run.", testLines);
}

void DictionaryWordTest::runIndexedTest( int32_t index, UBool exec, const char* &name, char* /*par */)
{
    if (exec) logln("TestSuite DictionaryWordTest: ");
    TESTCASE_AUTO_BEGIN;
    TESTCASE_AUTO(TestThaiBreaks);
    TESTCASE_AUTO(TestWordBoundaries);
    TESTCASE_AUTO_END;
}


#endif
