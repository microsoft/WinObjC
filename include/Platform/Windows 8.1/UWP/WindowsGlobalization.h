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

// WindowsGlobalization.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGJapanesePhoneme, WGJapanesePhoneticAnalyzer, WGCalendarIdentifiers, WGClockIdentifiers, WGNumeralSystemIdentifiers,
    WGCurrencyIdentifiers, WGGeographicRegion, WGLanguage, WGCalendar, WGApplicationLanguages;
@protocol WGIJapanesePhoneticAnalyzerStatics
, WGIJapanesePhoneme, WGICalendarIdentifiersStatics, WGIClockIdentifiersStatics, WGINumeralSystemIdentifiersStatics,
    WGICurrencyIdentifiersStatics, WGIGeographicRegion, WGIGeographicRegionFactory, WGIGeographicRegionStatics, WGILanguage,
    WGILanguageExtensionSubtags, WGILanguageFactory, WGILanguageStatics, WGICalendar, WGICalendarFactory2, WGITimeZoneOnCalendar,
    WGICalendarFactory, WGIApplicationLanguagesStatics;

// Windows.Globalization.DayOfWeek
enum _WGDayOfWeek {
    WGDayOfWeekSunday = 0,
    WGDayOfWeekMonday = 1,
    WGDayOfWeekTuesday = 2,
    WGDayOfWeekWednesday = 3,
    WGDayOfWeekThursday = 4,
    WGDayOfWeekFriday = 5,
    WGDayOfWeekSaturday = 6,
};
typedef unsigned WGDayOfWeek;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

// Windows.Globalization.JapanesePhoneme
#ifndef __WGJapanesePhoneme_DEFINED__
#define __WGJapanesePhoneme_DEFINED__

WINRT_EXPORT
@interface WGJapanesePhoneme : RTObject
@property (readonly) NSString* displayText;
@property (readonly) BOOL isPhraseStart;
@property (readonly) NSString* yomiText;
@end

#endif // __WGJapanesePhoneme_DEFINED__

// Windows.Globalization.JapanesePhoneticAnalyzer
#ifndef __WGJapanesePhoneticAnalyzer_DEFINED__
#define __WGJapanesePhoneticAnalyzer_DEFINED__

WINRT_EXPORT
@interface WGJapanesePhoneticAnalyzer : RTObject
+ (id<NSFastEnumeration> /*WGJapanesePhoneme*/)getWords:(NSString*)input;
+ (id<NSFastEnumeration> /*WGJapanesePhoneme*/)getWordsWithMonoRubyOption:(NSString*)input monoRuby:(BOOL)monoRuby;
@end

#endif // __WGJapanesePhoneticAnalyzer_DEFINED__

// Windows.Globalization.CalendarIdentifiers
#ifndef __WGCalendarIdentifiers_DEFINED__
#define __WGCalendarIdentifiers_DEFINED__

WINRT_EXPORT
@interface WGCalendarIdentifiers : RTObject
+ (NSString*)gregorian;
+ (NSString*)hebrew;
+ (NSString*)hijri;
+ (NSString*)japanese;
+ (NSString*)julian;
+ (NSString*)korean;
+ (NSString*)taiwan;
+ (NSString*)thai;
+ (NSString*)umAlQura;
@end

#endif // __WGCalendarIdentifiers_DEFINED__

// Windows.Globalization.ClockIdentifiers
#ifndef __WGClockIdentifiers_DEFINED__
#define __WGClockIdentifiers_DEFINED__

WINRT_EXPORT
@interface WGClockIdentifiers : RTObject
+ (NSString*)twelveHour;
+ (NSString*)twentyFourHour;
@end

#endif // __WGClockIdentifiers_DEFINED__

// Windows.Globalization.NumeralSystemIdentifiers
#ifndef __WGNumeralSystemIdentifiers_DEFINED__
#define __WGNumeralSystemIdentifiers_DEFINED__

WINRT_EXPORT
@interface WGNumeralSystemIdentifiers : RTObject
+ (NSString*)arab;
+ (NSString*)arabExt;
+ (NSString*)bali;
+ (NSString*)beng;
+ (NSString*)cham;
+ (NSString*)deva;
+ (NSString*)fullWide;
+ (NSString*)gujr;
+ (NSString*)guru;
+ (NSString*)haniDec;
+ (NSString*)java;
+ (NSString*)kali;
+ (NSString*)khmr;
+ (NSString*)knda;
+ (NSString*)lana;
+ (NSString*)lanaTham;
+ (NSString*)laoo;
+ (NSString*)latn;
+ (NSString*)lepc;
+ (NSString*)limb;
+ (NSString*)mlym;
+ (NSString*)mong;
+ (NSString*)mtei;
+ (NSString*)mymr;
+ (NSString*)mymrShan;
+ (NSString*)nkoo;
+ (NSString*)olck;
+ (NSString*)orya;
+ (NSString*)saur;
+ (NSString*)sund;
+ (NSString*)talu;
+ (NSString*)tamlDec;
+ (NSString*)telu;
+ (NSString*)thai;
+ (NSString*)tibt;
+ (NSString*)vaii;
@end

#endif // __WGNumeralSystemIdentifiers_DEFINED__

// Windows.Globalization.CurrencyIdentifiers
#ifndef __WGCurrencyIdentifiers_DEFINED__
#define __WGCurrencyIdentifiers_DEFINED__

WINRT_EXPORT
@interface WGCurrencyIdentifiers : RTObject
+ (NSString*)aED;
+ (NSString*)aFN;
+ (NSString*)aLL;
+ (NSString*)aMD;
+ (NSString*)aNG;
+ (NSString*)aOA;
+ (NSString*)aRS;
+ (NSString*)aUD;
+ (NSString*)aWG;
+ (NSString*)aZN;
+ (NSString*)bAM;
+ (NSString*)bBD;
+ (NSString*)bDT;
+ (NSString*)bGN;
+ (NSString*)bHD;
+ (NSString*)bIF;
+ (NSString*)bMD;
+ (NSString*)bND;
+ (NSString*)bOB;
+ (NSString*)bRL;
+ (NSString*)bSD;
+ (NSString*)bTN;
+ (NSString*)bWP;
+ (NSString*)bYR;
+ (NSString*)bZD;
+ (NSString*)cAD;
+ (NSString*)cDF;
+ (NSString*)cHF;
+ (NSString*)cLP;
+ (NSString*)cNY;
+ (NSString*)cOP;
+ (NSString*)cRC;
+ (NSString*)cUP;
+ (NSString*)cVE;
+ (NSString*)cZK;
+ (NSString*)dJF;
+ (NSString*)dKK;
+ (NSString*)dOP;
+ (NSString*)dZD;
+ (NSString*)eGP;
+ (NSString*)eRN;
+ (NSString*)eTB;
+ (NSString*)eUR;
+ (NSString*)fJD;
+ (NSString*)fKP;
+ (NSString*)gBP;
+ (NSString*)gEL;
+ (NSString*)gHS;
+ (NSString*)gIP;
+ (NSString*)gMD;
+ (NSString*)gNF;
+ (NSString*)gTQ;
+ (NSString*)gYD;
+ (NSString*)hKD;
+ (NSString*)hNL;
+ (NSString*)hRK;
+ (NSString*)hTG;
+ (NSString*)hUF;
+ (NSString*)iDR;
+ (NSString*)iLS;
+ (NSString*)iNR;
+ (NSString*)iQD;
+ (NSString*)iRR;
+ (NSString*)iSK;
+ (NSString*)jMD;
+ (NSString*)jOD;
+ (NSString*)jPY;
+ (NSString*)kES;
+ (NSString*)kGS;
+ (NSString*)kHR;
+ (NSString*)kMF;
+ (NSString*)kPW;
+ (NSString*)kRW;
+ (NSString*)kWD;
+ (NSString*)kYD;
+ (NSString*)kZT;
+ (NSString*)lAK;
+ (NSString*)lBP;
+ (NSString*)lKR;
+ (NSString*)lRD;
+ (NSString*)lSL;
+ (NSString*)lTL;
+ (NSString*)lVL;
+ (NSString*)lYD;
+ (NSString*)mAD;
+ (NSString*)mDL;
+ (NSString*)mGA;
+ (NSString*)mKD;
+ (NSString*)mMK;
+ (NSString*)mNT;
+ (NSString*)mOP;
+ (NSString*)mRO;
+ (NSString*)mUR;
+ (NSString*)mVR;
+ (NSString*)mWK;
+ (NSString*)mXN;
+ (NSString*)mYR;
+ (NSString*)mZN;
+ (NSString*)nAD;
+ (NSString*)nGN;
+ (NSString*)nIO;
+ (NSString*)nOK;
+ (NSString*)nPR;
+ (NSString*)nZD;
+ (NSString*)oMR;
+ (NSString*)pAB;
+ (NSString*)pEN;
+ (NSString*)pGK;
+ (NSString*)pHP;
+ (NSString*)pKR;
+ (NSString*)pLN;
+ (NSString*)pYG;
+ (NSString*)qAR;
+ (NSString*)rON;
+ (NSString*)rSD;
+ (NSString*)rUB;
+ (NSString*)rWF;
+ (NSString*)sAR;
+ (NSString*)sBD;
+ (NSString*)sCR;
+ (NSString*)sDG;
+ (NSString*)sEK;
+ (NSString*)sGD;
+ (NSString*)sHP;
+ (NSString*)sLL;
+ (NSString*)sOS;
+ (NSString*)sRD;
+ (NSString*)sTD;
+ (NSString*)sYP;
+ (NSString*)sZL;
+ (NSString*)tHB;
+ (NSString*)tJS;
+ (NSString*)tMT;
+ (NSString*)tND;
+ (NSString*)tOP;
+ (NSString*)tRY;
+ (NSString*)tTD;
+ (NSString*)tWD;
+ (NSString*)tZS;
+ (NSString*)uAH;
+ (NSString*)uGX;
+ (NSString*)uSD;
+ (NSString*)uYU;
+ (NSString*)uZS;
+ (NSString*)vEF;
+ (NSString*)vND;
+ (NSString*)vUV;
+ (NSString*)wST;
+ (NSString*)xAF;
+ (NSString*)xCD;
+ (NSString*)xOF;
+ (NSString*)xPF;
+ (NSString*)xXX;
+ (NSString*)yER;
+ (NSString*)zAR;
+ (NSString*)zMW;
+ (NSString*)zWL;
@end

#endif // __WGCurrencyIdentifiers_DEFINED__

// Windows.Globalization.GeographicRegion
#ifndef __WGGeographicRegion_DEFINED__
#define __WGGeographicRegion_DEFINED__

WINRT_EXPORT
@interface WGGeographicRegion : RTObject
+ (BOOL)isSupported:(NSString*)geographicRegionCode;
+ (WGGeographicRegion*)createGeographicRegion:(NSString*)geographicRegionCode ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) NSString* code;
@property (readonly) NSString* codeThreeDigit;
@property (readonly) NSString* codeThreeLetter;
@property (readonly) NSString* codeTwoLetter;
@property (readonly) id<NSFastEnumeration> /*String*/ currenciesInUse;
@property (readonly) NSString* displayName;
@property (readonly) NSString* nativeName;
@end

#endif // __WGGeographicRegion_DEFINED__

// Windows.Globalization.Language
#ifndef __WGLanguage_DEFINED__
#define __WGLanguage_DEFINED__

WINRT_EXPORT
@interface WGLanguage : RTObject
+ (BOOL)isWellFormed:(NSString*)languageTag;
+ (WGLanguage*)createLanguage:(NSString*)languageTag ACTIVATOR;
@property (readonly) NSString* displayName;
@property (readonly) NSString* languageTag;
@property (readonly) NSString* nativeName;
@property (readonly) NSString* script;
+ (NSString*)currentInputMethodLanguageTag;
- (id<NSFastEnumeration> /*String*/)getExtensionSubtags:(NSString*)singleton;
@end

#endif // __WGLanguage_DEFINED__

// Windows.Globalization.Calendar
#ifndef __WGCalendar_DEFINED__
#define __WGCalendar_DEFINED__

WINRT_EXPORT
@interface WGCalendar : RTObject
+ (WGCalendar*)createCalendarDefaultCalendarAndClock:(id<NSFastEnumeration> /*String*/)languages ACTIVATOR;
+ (WGCalendar*)createCalendar:(id<NSFastEnumeration> /*String*/)languages calendar:(NSString*)calendar clock:(NSString*)clock ACTIVATOR;
+ (WGCalendar*)createCalendarWithTimeZone:(id<NSFastEnumeration> /*String*/)languages
                                 calendar:(NSString*)calendar
                                    clock:(NSString*)clock
                               timeZoneId:(NSString*)timeZoneId ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property int second;
@property int period;
@property (copy) NSString* numeralSystem;
@property int year;
@property int nanosecond;
@property int minute;
@property int hour;
@property int era;
@property int month;
@property int day;
@property (readonly) int firstPeriodInThisDay;
@property (readonly) int firstSecondInThisMinute;
@property (readonly) int firstYearInThisEra;
@property (readonly) BOOL isDaylightSavingTime;
@property (readonly) id<NSFastEnumeration> /*String*/ languages;
@property (readonly) int lastEra;
@property (readonly) int lastHourInThisPeriod;
@property (readonly) int lastMinuteInThisHour;
@property (readonly) int lastMonthInThisYear;
@property (readonly) int firstEra;
@property (readonly) int lastPeriodInThisDay;
@property (readonly) int lastSecondInThisMinute;
@property (readonly) int lastYearInThisEra;
@property (readonly) WGDayOfWeek dayOfWeek;
@property (readonly) int firstDayInThisMonth;
@property (readonly) int numberOfDaysInThisMonth;
@property (readonly) int numberOfEras;
@property (readonly) int numberOfHoursInThisPeriod;
@property (readonly) int numberOfMonthsInThisYear;
@property (readonly) int numberOfPeriodsInThisDay;
@property (readonly) int numberOfSecondsInThisMinute;
@property (readonly) int numberOfYearsInThisEra;
@property (readonly) int lastDayInThisMonth;
@property (readonly) int firstHourInThisPeriod;
@property (readonly) int firstMinuteInThisHour;
@property (readonly) NSString* resolvedLanguage;
@property (readonly) int firstMonthInThisYear;
@property (readonly) int numberOfMinutesInThisHour;
- (WGCalendar*)clone;
- (void)setToMin;
- (void)setToMax;
- (NSString*)getCalendarSystem;
- (void)changeCalendarSystem:(NSString*)value;
- (NSString*)getClock;
- (void)changeClock:(NSString*)value;
- (WFDateTime*)getDateTime;
- (void)setDateTime:(WFDateTime*)value;
- (void)setToNow;
- (void)addEras:(int)eras;
- (NSString*)eraAsFullString;
- (NSString*)eraAsString:(int)idealLength;
- (void)addYears:(int)years;
- (NSString*)yearAsString;
- (NSString*)yearAsTruncatedString:(int)remainingDigits;
- (NSString*)yearAsPaddedString:(int)minDigits;
- (void)addMonths:(int)months;
- (NSString*)monthAsFullString;
- (NSString*)monthAsString:(int)idealLength;
- (NSString*)monthAsFullSoloString;
- (NSString*)monthAsSoloString:(int)idealLength;
- (NSString*)monthAsNumericString;
- (NSString*)monthAsPaddedNumericString:(int)minDigits;
- (void)addWeeks:(int)weeks;
- (void)addDays:(int)days;
- (NSString*)dayAsString;
- (NSString*)dayAsPaddedString:(int)minDigits;
- (NSString*)dayOfWeekAsFullString;
- (NSString*)dayOfWeekAsString:(int)idealLength;
- (NSString*)dayOfWeekAsFullSoloString;
- (NSString*)dayOfWeekAsSoloString:(int)idealLength;
- (void)addPeriods:(int)periods;
- (NSString*)periodAsFullString;
- (NSString*)periodAsString:(int)idealLength;
- (void)addHours:(int)hours;
- (NSString*)hourAsString;
- (NSString*)hourAsPaddedString:(int)minDigits;
- (void)addMinutes:(int)minutes;
- (NSString*)minuteAsString;
- (NSString*)minuteAsPaddedString:(int)minDigits;
- (void)addSeconds:(int)seconds;
- (NSString*)secondAsString;
- (NSString*)secondAsPaddedString:(int)minDigits;
- (void)addNanoseconds:(int)nanoseconds;
- (NSString*)nanosecondAsString;
- (NSString*)nanosecondAsPaddedString:(int)minDigits;
- (int)compare:(WGCalendar*)other;
- (int)compareDateTime:(WFDateTime*)other;
- (void)copyTo:(WGCalendar*)other;
- (NSString*)getTimeZone;
- (void)changeTimeZone:(NSString*)timeZoneId;
- (NSString*)timeZoneAsFullString;
- (NSString*)timeZoneAsString:(int)idealLength;
@end

#endif // __WGCalendar_DEFINED__

// Windows.Globalization.ApplicationLanguages
#ifndef __WGApplicationLanguages_DEFINED__
#define __WGApplicationLanguages_DEFINED__

WINRT_EXPORT
@interface WGApplicationLanguages : RTObject
+ (NSString*)primaryLanguageOverride;
+ (void)setPrimaryLanguageOverride:(NSString*)value;
+ (id<NSFastEnumeration> /*String*/)languages;
+ (id<NSFastEnumeration> /*String*/)manifestLanguages;
@end

#endif // __WGApplicationLanguages_DEFINED__
