//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsGlobalizationPhoneNumberFormatting.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGLOBALIZATIONPHONENUMBERFORMATTINGEXPORT
#define OBJCUWPWINDOWSGLOBALIZATIONPHONENUMBERFORMATTINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGlobalizationPhoneNumberFormatting.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPPhoneNumberInfo, WGPPhoneNumberFormatter;
@protocol WGPIPhoneNumberInfo, WGPIPhoneNumberFormatter, WGPIPhoneNumberInfoFactory, WGPIPhoneNumberInfoStatics, WGPIPhoneNumberFormatterStatics;

// Windows.Globalization.PhoneNumberFormatting.PhoneNumberFormat
enum _WGPPhoneNumberFormat {
    WGPPhoneNumberFormatE164 = 0,
    WGPPhoneNumberFormatInternational = 1,
    WGPPhoneNumberFormatNational = 2,
    WGPPhoneNumberFormatRfc3966 = 3,
};
typedef unsigned WGPPhoneNumberFormat;

// Windows.Globalization.PhoneNumberFormatting.PredictedPhoneNumberKind
enum _WGPPredictedPhoneNumberKind {
    WGPPredictedPhoneNumberKindFixedLine = 0,
    WGPPredictedPhoneNumberKindMobile = 1,
    WGPPredictedPhoneNumberKindFixedLineOrMobile = 2,
    WGPPredictedPhoneNumberKindTollFree = 3,
    WGPPredictedPhoneNumberKindPremiumRate = 4,
    WGPPredictedPhoneNumberKindSharedCost = 5,
    WGPPredictedPhoneNumberKindVoip = 6,
    WGPPredictedPhoneNumberKindPersonalNumber = 7,
    WGPPredictedPhoneNumberKindPager = 8,
    WGPPredictedPhoneNumberKindUniversalAccountNumber = 9,
    WGPPredictedPhoneNumberKindVoicemail = 10,
    WGPPredictedPhoneNumberKindUnknown = 11,
};
typedef unsigned WGPPredictedPhoneNumberKind;

// Windows.Globalization.PhoneNumberFormatting.PhoneNumberParseResult
enum _WGPPhoneNumberParseResult {
    WGPPhoneNumberParseResultValid = 0,
    WGPPhoneNumberParseResultNotANumber = 1,
    WGPPhoneNumberParseResultInvalidCountryCode = 2,
    WGPPhoneNumberParseResultTooShort = 3,
    WGPPhoneNumberParseResultTooLong = 4,
};
typedef unsigned WGPPhoneNumberParseResult;

// Windows.Globalization.PhoneNumberFormatting.PhoneNumberMatchResult
enum _WGPPhoneNumberMatchResult {
    WGPPhoneNumberMatchResultNoMatch = 0,
    WGPPhoneNumberMatchResultShortNationalSignificantNumberMatch = 1,
    WGPPhoneNumberMatchResultNationalSignificantNumberMatch = 2,
    WGPPhoneNumberMatchResultExactMatch = 3,
};
typedef unsigned WGPPhoneNumberMatchResult;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString *)toString;
@end

OBJCUWPWINDOWSGLOBALIZATIONPHONENUMBERFORMATTINGEXPORT
@interface WFIStringable : RTObject <WFIStringable>
@end

#endif // __WFIStringable_DEFINED__

// Windows.Globalization.PhoneNumberFormatting.PhoneNumberInfo
#ifndef __WGPPhoneNumberInfo_DEFINED__
#define __WGPPhoneNumberInfo_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONPHONENUMBERFORMATTINGEXPORT
@interface WGPPhoneNumberInfo : RTObject <WFIStringable>
+ (WGPPhoneNumberParseResult)tryParse:(NSString *)input phoneNumber:(WGPPhoneNumberInfo**)phoneNumber;
+ (WGPPhoneNumberParseResult)tryParseWithRegion:(NSString *)input regionCode:(NSString *)regionCode phoneNumber:(WGPPhoneNumberInfo**)phoneNumber;
+ (WGPPhoneNumberInfo*)make:(NSString *)number ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int countryCode;
@property (readonly) NSString * phoneNumber;
- (int)getLengthOfGeographicalAreaCode;
- (NSString *)getNationalSignificantNumber;
- (int)getLengthOfNationalDestinationCode;
- (WGPPredictedPhoneNumberKind)predictNumberKind;
- (NSString *)getGeographicRegionCode;
- (WGPPhoneNumberMatchResult)checkNumberMatch:(WGPPhoneNumberInfo*)otherNumber;
- (NSString *)toString;
@end

#endif // __WGPPhoneNumberInfo_DEFINED__

// Windows.Globalization.PhoneNumberFormatting.PhoneNumberFormatter
#ifndef __WGPPhoneNumberFormatter_DEFINED__
#define __WGPPhoneNumberFormatter_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONPHONENUMBERFORMATTINGEXPORT
@interface WGPPhoneNumberFormatter : RTObject
+ (void)tryCreate:(NSString *)regionCode phoneNumber:(WGPPhoneNumberFormatter**)phoneNumber;
+ (int)getCountryCodeForRegion:(NSString *)regionCode;
+ (NSString *)getNationalDirectDialingPrefixForRegion:(NSString *)regionCode stripNonDigit:(BOOL)stripNonDigit;
+ (NSString *)wrapWithLeftToRightMarkers:(NSString *)number;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSString *)format:(WGPPhoneNumberInfo*)number;
- (NSString *)formatWithOutputFormat:(WGPPhoneNumberInfo*)number numberFormat:(WGPPhoneNumberFormat)numberFormat;
- (NSString *)formatPartialString:(NSString *)number;
- (NSString *)formatString:(NSString *)number;
- (NSString *)formatStringWithLeftToRightMarkers:(NSString *)number;
@end

#endif // __WGPPhoneNumberFormatter_DEFINED__

