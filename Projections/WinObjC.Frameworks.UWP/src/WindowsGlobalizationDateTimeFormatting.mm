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

// WindowsGlobalizationDateTimeFormatting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.DateTimeFormatting.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalizationDateTimeFormatting.h"
#include "WindowsGlobalizationDateTimeFormatting_priv.h"

@implementation WGDDateTimeFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> WGDIDateTimeFormatterFactory_inst() {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.DateTimeFormatting.DateTimeFormatter").Get(), &inst));
    return inst;
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatter:(NSString*)formatTemplate {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatter(nsStrToHstr(formatTemplate).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterLanguages:(NSString*)formatTemplate
                                              languages:(id<NSFastEnumeration> /* NSString * */)languages {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatterLanguages(
        nsStrToHstr(formatTemplate).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterContext:(NSString*)formatTemplate
                                            languages:(id<NSFastEnumeration> /* NSString * */)languages
                                     geographicRegion:(NSString*)geographicRegion
                                             calendar:(NSString*)calendar
                                                clock:(NSString*)clock {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatterContext(
        nsStrToHstr(formatTemplate).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        nsStrToHstr(calendar).Get(),
        nsStrToHstr(clock).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterDate:(WGDYearFormat)yearFormat
                                       monthFormat:(WGDMonthFormat)monthFormat
                                         dayFormat:(WGDDayFormat)dayFormat
                                   dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateDateTimeFormatterDate((ABI::Windows::Globalization::DateTimeFormatting::YearFormat)yearFormat,
                                              (ABI::Windows::Globalization::DateTimeFormatting::MonthFormat)monthFormat,
                                              (ABI::Windows::Globalization::DateTimeFormatting::DayFormat)dayFormat,
                                              (ABI::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat)dayOfWeekFormat,
                                              unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterTime:(WGDHourFormat)hourFormat
                                      minuteFormat:(WGDMinuteFormat)minuteFormat
                                      secondFormat:(WGDSecondFormat)secondFormat {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatterTime((ABI::Windows::Globalization::DateTimeFormatting::HourFormat)hourFormat,
                                                             (ABI::Windows::Globalization::DateTimeFormatting::MinuteFormat)minuteFormat,
                                                             (ABI::Windows::Globalization::DateTimeFormatting::SecondFormat)secondFormat,
                                                             unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterDateTimeLanguages:(WGDYearFormat)yearFormat
                                                    monthFormat:(WGDMonthFormat)monthFormat
                                                      dayFormat:(WGDDayFormat)dayFormat
                                                dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat
                                                     hourFormat:(WGDHourFormat)hourFormat
                                                   minuteFormat:(WGDMinuteFormat)minuteFormat
                                                   secondFormat:(WGDSecondFormat)secondFormat
                                                      languages:(id<NSFastEnumeration> /* NSString * */)languages {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatterDateTimeLanguages(
        (ABI::Windows::Globalization::DateTimeFormatting::YearFormat)yearFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::MonthFormat)monthFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::DayFormat)dayFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat)dayOfWeekFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::HourFormat)hourFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::MinuteFormat)minuteFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::SecondFormat)secondFormat,
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGDDateTimeFormatter*)makeDateTimeFormatterDateTimeContext:(WGDYearFormat)yearFormat
                                                  monthFormat:(WGDMonthFormat)monthFormat
                                                    dayFormat:(WGDDayFormat)dayFormat
                                              dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat
                                                   hourFormat:(WGDHourFormat)hourFormat
                                                 minuteFormat:(WGDMinuteFormat)minuteFormat
                                                 secondFormat:(WGDSecondFormat)secondFormat
                                                    languages:(id<NSFastEnumeration> /* NSString * */)languages
                                             geographicRegion:(NSString*)geographicRegion
                                                     calendar:(NSString*)calendar
                                                        clock:(NSString*)clock {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeFormatterDateTimeContext(
        (ABI::Windows::Globalization::DateTimeFormatting::YearFormat)yearFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::MonthFormat)monthFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::DayFormat)dayFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat)dayOfWeekFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::HourFormat)hourFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::MinuteFormat)minuteFormat,
        (ABI::Windows::Globalization::DateTimeFormatting::SecondFormat)secondFormat,
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        nsStrToHstr(calendar).Get(),
        nsStrToHstr(clock).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> WGDIDateTimeFormatterStatics_inst() {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.DateTimeFormatting.DateTimeFormatter").Get(), &inst));
    return inst;
}

+ (WGDDateTimeFormatter*)longDate {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LongDate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get());
}

+ (WGDDateTimeFormatter*)longTime {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LongTime(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get());
}

+ (WGDDateTimeFormatter*)shortDate {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShortDate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get());
}

+ (WGDDateTimeFormatter*)shortTime {
    ComPtr<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> unmarshalledReturn;
    auto _comInst = WGDIDateTimeFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShortTime(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDateTimeFormatter>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)calendar {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Calendar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)clock {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Clock(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSArray* /* NSString * */)patterns {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Patterns(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)Template {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Template(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)format:(WFDateTime*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->Format(*[value internalStruct], &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGDYearFormat)includeYear {
    ABI::Windows::Globalization::DateTimeFormatting::YearFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeYear(&unmarshalledReturn));
    return (WGDYearFormat)unmarshalledReturn;
}

- (WGDMonthFormat)includeMonth {
    ABI::Windows::Globalization::DateTimeFormatting::MonthFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeMonth(&unmarshalledReturn));
    return (WGDMonthFormat)unmarshalledReturn;
}

- (WGDDayOfWeekFormat)includeDayOfWeek {
    ABI::Windows::Globalization::DateTimeFormatting::DayOfWeekFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeDayOfWeek(&unmarshalledReturn));
    return (WGDDayOfWeekFormat)unmarshalledReturn;
}

- (WGDDayFormat)includeDay {
    ABI::Windows::Globalization::DateTimeFormatting::DayFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeDay(&unmarshalledReturn));
    return (WGDDayFormat)unmarshalledReturn;
}

- (WGDHourFormat)includeHour {
    ABI::Windows::Globalization::DateTimeFormatting::HourFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeHour(&unmarshalledReturn));
    return (WGDHourFormat)unmarshalledReturn;
}

- (WGDMinuteFormat)includeMinute {
    ABI::Windows::Globalization::DateTimeFormatting::MinuteFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeMinute(&unmarshalledReturn));
    return (WGDMinuteFormat)unmarshalledReturn;
}

- (WGDSecondFormat)includeSecond {
    ABI::Windows::Globalization::DateTimeFormatting::SecondFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeSecond(&unmarshalledReturn));
    return (WGDSecondFormat)unmarshalledReturn;
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUsingTimeZone:(WFDateTime*)datetime timeZoneId:(NSString*)timeZoneId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUsingTimeZone(*[datetime internalStruct], nsStrToHstr(timeZoneId).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
