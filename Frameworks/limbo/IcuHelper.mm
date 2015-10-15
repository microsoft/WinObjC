//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#define U_STATIC_IMPLEMENTATION 1

#include "Starboard.h"
#include <pthread.h>

#include <unicode/coll.h>
#include <unicode/ucnv.h>
#include <unicode/brkiter.h>
#include <unicode/uclean.h>
#include <unicode/udata.h>

#include "IcuHelper.h"

static pthread_key_t _icuUTF8Cnv, _icuUTF32BECnv, _icuASCIICnv, _icuDefaultCollator, _icuLettersSet, _icuWordIterator, _icuRegexPatterns,
    _icuSearch;

int _icuTotal = 0;

void* icuMalloc(const void* context, size_t size) {
    _icuTotal += size;
    return malloc(size);
}

void icuFree(const void* context, void* mem) {
    uint32_t ret = 0;

    //  Use EbrBlockSize!
    // if ( mem ) memcpy(&ret, ((DWORD *) mem) - 3, 4);
    _icuTotal -= ret;
    free(mem);
}

void* icuRealloc(const void* context, void* mem, size_t size) {
    uint32_t ret = 0;

    //  Use EbrBlockSize!
    // if ( mem ) memcpy(&ret, ((DWORD *) mem) - 3, 4);
    _icuTotal -= ret;
    _icuTotal += size;
    return realloc(mem, size);
}

static void destroyConverter(void* ptr) {
    UConverter* cnv = (UConverter*)ptr;
    ucnv_close(cnv);
}

static void destroyCollator(void* ptr) {
    UCollator* col = (UCollator*)ptr;
    ucol_close(col);
}

static void destroySet(void* ptr) {
    UnicodeSet* set = (UnicodeSet*)ptr;
    delete set;
}

static void destroyIterator(void* ptr) {
    BreakIterator* iterator = (BreakIterator*)ptr;
    delete iterator;
}

static void destroySearch(void* ptr) {
    UStringSearch* search = (UStringSearch*)ptr;
    usearch_close(search);
}

static void destroyRegexPatterns(void* ptr) {
    id dict = (id)ptr;
    //_m(dict, "release");
}

extern "C" {
extern const char _static_icuData[];
};

__attribute__((constructor)) void InitICU() {
    //  Setup ICU allocator
    UErrorCode error = U_ZERO_ERROR;
    // u_setMemoryFunctions(NULL, icuMalloc, icuRealloc, icuFree, &error);

    pthread_key_create(&_icuUTF8Cnv, destroyConverter);
    pthread_key_create(&_icuUTF32BECnv, destroyConverter);
    pthread_key_create(&_icuASCIICnv, destroyConverter);
    pthread_key_create(&_icuDefaultCollator, destroyCollator);
    pthread_key_create(&_icuLettersSet, destroySet);
    pthread_key_create(&_icuWordIterator, destroyIterator);
    pthread_key_create(&_icuRegexPatterns, destroyRegexPatterns);
    pthread_key_create(&_icuSearch, destroySearch);

    EbrFile* fpICU = EbrFopen("icudt48l.dat", "rb");

    // For now we fall back on the packaged data since it may be useful to have later:
    if (fpICU) {
        EbrFseek(fpICU, 0, SEEK_END);
        int len = EbrFtell(fpICU);
        EbrFseek(fpICU, 0, SEEK_SET);

        char* icuData = new char[len];
        EbrFread(icuData, 1, len, fpICU);

        UErrorCode status = U_ZERO_ERROR;
        udata_setCommonData(icuData, &status);
        assert(status == U_ZERO_ERROR);
    } else {
        UErrorCode status = U_ZERO_ERROR;
        udata_setCommonData(_static_icuData, &status);
        assert(status == U_ZERO_ERROR);
    }
}

UConverter* getUTF8Converter() {
    UConverter* cnv = (UConverter*)pthread_getspecific(_icuUTF8Cnv);
    if (!cnv) {
        UErrorCode status = U_ZERO_ERROR;

        cnv = ucnv_open("UTF-8", &status);
        pthread_setspecific(_icuUTF8Cnv, cnv);
    }

    return cnv;
}

UConverter* getUTF32BEConverter() {
    UConverter* cnv = (UConverter*)pthread_getspecific(_icuUTF32BECnv);
    if (!cnv) {
        UErrorCode status = U_ZERO_ERROR;

        cnv = ucnv_open("UTF-32BE", &status);
        pthread_setspecific(_icuUTF32BECnv, cnv);
    }

    return cnv;
}

UConverter* getASCIIConverter() {
    UConverter* cnv = (UConverter*)pthread_getspecific(_icuASCIICnv);
    if (!cnv) {
        UErrorCode status = U_ZERO_ERROR;

        cnv = ucnv_open("ASCII", &status);
        pthread_setspecific(_icuASCIICnv, cnv);
    }

    return cnv;
}

UCollator* getDefaultLocaleCollator() {
    UCollator* col = (UCollator*)pthread_getspecific(_icuDefaultCollator);
    UErrorCode status = U_ZERO_ERROR;

    if (!col) {
        col = ucol_open("en_US", &status);
        pthread_setspecific(_icuDefaultCollator, col);
    }

    ucol_setAttribute(col, UCOL_CASE_LEVEL, UCOL_DEFAULT, &status);
    ucol_setAttribute(col, UCOL_NUMERIC_COLLATION, UCOL_DEFAULT, &status);
    ucol_setStrength(col, UCOL_DEFAULT);

    return col;
}

UStringSearch* getSearchForOptions(uint32_t options) {
    UErrorCode error = U_ZERO_ERROR;
    UStringSearch* search = (UStringSearch*)pthread_getspecific(_icuSearch);

    if (!search) {
        UCollator* collator = getDefaultLocaleCollator();
        search = usearch_openFromCollator((UChar*)"    ", 1, (UChar*)"    ", 1, collator, NULL, &error);
        pthread_setspecific(_icuSearch, search);
    }

    UCollator* collator = usearch_getCollator(search);
    if ((options & NSCaseInsensitiveSearch) && (options & NSDiacriticInsensitiveSearch)) {
        ucol_setStrength(collator, UCOL_PRIMARY);
    } else if (options & NSCaseInsensitiveSearch) {
        ucol_setStrength(collator, UCOL_SECONDARY);
    } else if (options & NSDiacriticInsensitiveSearch) {
        ucol_setStrength(collator, UCOL_PRIMARY);
        ucol_setAttribute(collator, UCOL_CASE_LEVEL, UCOL_ON, &error);
    }

    if (options & NSNumericSearch)
        ucol_setAttribute(collator, UCOL_NUMERIC_COLLATION, UCOL_ON, &error);

    return search;
}

BreakIterator* getWordIterator() {
    BreakIterator* ret = (BreakIterator*)pthread_getspecific(_icuWordIterator);
    if (!ret) {
        UErrorCode status = U_ZERO_ERROR;
        ret = BreakIterator::createWordInstance(Locale(), status);
        pthread_setspecific(_icuWordIterator, ret);
    }

    return ret;
}

UnicodeSet* lettersSet() {
    UnicodeSet* ret = (UnicodeSet*)pthread_getspecific(_icuLettersSet);
    if (!ret) {
        UErrorCode status = U_ZERO_ERROR;
        ret = new UnicodeSet(UnicodeString("[:letter:]"), status);
        pthread_setspecific(_icuLettersSet, ret);
    }

    return ret;
}
