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

// Windows-only:
//      g_etl...TestHook

#undef _WINOBJC_DO_NOT_USE_NSLOG
#include <TestFramework.h>
#import <Foundation/Foundation.h>
#include "Starboard.h"
#include "NSLogging.h"
#include "LoggingNative.h"
#include "LoggingTesting.h"
#include "winmeta.h"
#include "NSLogInternal.h"

#define EXPECTED L"/TAG: FORMAT\n"

void setup() {
    g_debugTestHook = L"";
    g_etlLevelTestHook = -1;
    g_etlTagTestHook = L"";
    g_etlBufferTestHook = L"";
}

void validateDebugOutputDebugMode(const wchar_t* expectedDebug) {
#ifdef _DEBUG
    ASSERT_STREQ(expectedDebug, g_debugTestHook.c_str());
#else
    ASSERT_STREQ(L"", g_debugTestHook.c_str());
#endif
}

void validateDebugOutputDebugReleaseMode(const wchar_t* expectedDebug) {
    ASSERT_STREQ(expectedDebug, g_debugTestHook.c_str());
}

void validateWideEtl(const wchar_t* tag, const wchar_t* expectedBody, int expectedLevel) {
    ASSERT_EQ(expectedLevel, g_etlLevelTestHook);
    ASSERT_STREQ(tag, g_etlTagTestHook.c_str());
    ASSERT_STREQ(expectedBody, g_etlBufferTestHook.c_str());
}

TEST(NSLogging, NSLoggingWideBasicTests) {
    g_isTestHookEnabled = true;
    auto reset = wil::ScopeExit([]() { g_isTestHookEnabled = false; });

    // Basic test. Use macros so can use literal concatenation.
    const wchar_t* tag = L"TAG";
    const wchar_t* format = L"FORMAT";

    setup();
    TraceVerbose(tag, format);
    validateDebugOutputDebugMode(L"V" EXPECTED);
    validateWideEtl(tag, format, WINEVENT_LEVEL_VERBOSE);

    setup();
    TraceInfo(tag, format);
    validateDebugOutputDebugMode(L"I" EXPECTED);
    validateWideEtl(tag, format, WINEVENT_LEVEL_INFO);

    setup();
    TraceWarning(tag, format);
    validateDebugOutputDebugMode(L"W" EXPECTED);
    validateWideEtl(tag, format, WINEVENT_LEVEL_WARNING);

    setup();
    TraceError(tag, format);
    validateDebugOutputDebugMode(L"E" EXPECTED);
    validateWideEtl(tag, format, WINEVENT_LEVEL_ERROR);

    setup();
    TraceCritical(tag, format);
    validateDebugOutputDebugMode(L"C" EXPECTED);
    validateWideEtl(tag, format, WINEVENT_LEVEL_CRITICAL);
}

TEST(NSLogging, NSLoggingNSStringBasicTests) {
    g_isTestHookEnabled = true;
    auto reset = wil::ScopeExit([]() { g_isTestHookEnabled = false; });

    // Basic test. Use macros so can use literal concatenation.
    const wchar_t* tag = L"TAG";
    StrongId<NSString> format = @"FORMAT";
    const wchar_t* expectedBody = L"FORMAT";

    setup();
    NSTraceVerbose(tag, format);
    validateDebugOutputDebugMode(L"V" EXPECTED);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_VERBOSE);

    setup();
    NSTraceInfo(tag, format);
    validateDebugOutputDebugMode(L"I" EXPECTED);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_INFO);

    setup();
    NSTraceWarning(tag, format);
    validateDebugOutputDebugMode(L"W" EXPECTED);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_WARNING);

    setup();
    NSTraceError(tag, format);
    validateDebugOutputDebugMode(L"E" EXPECTED);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_ERROR);

    setup();
    NSTraceCritical(tag, format);
    validateDebugOutputDebugMode(L"C" EXPECTED);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_CRITICAL);
}

TEST(NSLogging, NSLoggingWideFormatTests) {
    g_isTestHookEnabled = true;
    auto reset = wil::ScopeExit([]() { g_isTestHookEnabled = false; });

    int intSample = 12345;
    float floatSample = 123.45;
    const char* narrowSample = "abcdefg";
    const wchar_t* wideSample = L"文字化け";
    const wchar_t* tag = L"TAG/タグ";
    const wchar_t* format = L"Int: %d Float: %.2f Narrow: %hs Wide: %ws Narrow2: %S Wide2: %s";
    const wchar_t* expectedBody = L"Int: 12345 Float: 123.45 Narrow: abcdefg Wide: 文字化け Narrow2: abcdefg Wide2: 文字化け";
    const wchar_t* expectedDebug =
        L"V/TAG/タグ: Int: 12345 Float: 123.45 Narrow: abcdefg Wide: 文字化け Narrow2: abcdefg Wide2: 文字化け\n";

    setup();
    TraceVerbose(tag, format, intSample, floatSample, narrowSample, wideSample, narrowSample, wideSample);
    validateDebugOutputDebugMode(expectedDebug);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_VERBOSE);
}

TEST(NSLogging, NSLoggingNSStringFormatTests) {
    g_isTestHookEnabled = true;
    auto reset = wil::ScopeExit([]() { g_isTestHookEnabled = false; });

    int intSample = 12345;
    float floatSample = 123.45;
    const char* narrowSample = "abcdefg";
    StrongId<NSString> narrowNSStringSample = @"abcdefg";
    StrongId<NSString> wideNSStringSample = @"文字化け";
    const wchar_t* tag = L"TAG/タグ";
    StrongId<NSString> format = @"Int: %d Float: %.2f Narrow: %s WideNSString: %@ NarrowNSString: %@";
    const wchar_t* expectedBody = L"Int: 12345 Float: 123.45 Narrow: abcdefg WideNSString: 文字化け NarrowNSString: abcdefg";
    const wchar_t* expectedDebug = L"V/TAG/タグ: Int: 12345 Float: 123.45 Narrow: abcdefg WideNSString: 文字化け NarrowNSString: abcdefg\n";

    setup();
    NSTraceVerbose(tag, format, intSample, floatSample, narrowSample, (NSString*)wideNSStringSample, (NSString*)narrowNSStringSample);
    validateDebugOutputDebugMode(expectedDebug);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_VERBOSE);
}

TEST(NSLogging, NSLogTests) {
    g_isTestHookEnabled = true;
    g_isNSLogTestHookEnabled = true;
    auto reset = wil::ScopeExit([]() {
        g_isTestHookEnabled = false;
        g_isNSLogTestHookEnabled = false;
    });

    int intSample = 12345;
    float floatSample = 123.45;
    const char* narrowSample = "abcdefg";
    StrongId<NSString> narrowNSStringSample = @"abcdefg";
    StrongId<NSString> wideNSStringSample = @"文字化け";
    const wchar_t* tag = L"NSLog";
    StrongId<NSString> format = @"Int: %d Float: %.2f Narrow: %s WideNSString: %@ NarrowNSString: %@";
    const wchar_t* expectedBody = L"Int: 12345 Float: 123.45 Narrow: abcdefg WideNSString: 文字化け NarrowNSString: abcdefg";
    const wchar_t* expectedDebug = L"V/NSLog: Int: 12345 Float: 123.45 Narrow: abcdefg WideNSString: 文字化け NarrowNSString: abcdefg\n";

    setup();
    NSLog(format, intSample, floatSample, narrowSample, (NSString*)wideNSStringSample, (NSString*)narrowNSStringSample);
    // NSLog is printed also to debug output and stderr in release mode manually, without a test hook.
    validateDebugOutputDebugMode(expectedDebug);
    validateWideEtl(tag, expectedBody, WINEVENT_LEVEL_VERBOSE);
}