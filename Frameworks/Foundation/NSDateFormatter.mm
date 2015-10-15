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

#include "Starboard.h"

#import <Foundation/Foundation.h>
#import <NSLocaleInternal.h>
#import <NSCalendarInternal.h>
#import <NSTimeZoneInternal.h>
#include <unicode/datefmt.h>
#include <unicode/dtfmtsym.h>
#include <unicode/smpdtfmt.h>
#include <unicode/dtptngen.h>

#include <functional>
#include <map>

static icu::DateFormat::EStyle convertFormatterStyle(NSDateFormatterStyle fmt) {
    switch (fmt) {
        case NSDateFormatterShortStyle:
            return icu::DateFormat::kShort;
        case NSDateFormatterMediumStyle:
            return icu::DateFormat::kMedium;
        case NSDateFormatterLongStyle:
            return icu::DateFormat::kLong;
        case NSDateFormatterFullStyle:
            return icu::DateFormat::kFull;

        default:
            EbrDebugLog("Unrecognized formatter style, defaulting to UDAT_NONE.\n");
        case NSDateFormatterNoStyle:
            return icu::DateFormat::kNone;
    }
}

class ICUPropertyValue {
public:
    bool _boolValue;
    idretaintype(NSObject) _objValue;

    ICUPropertyValue() {
        _boolValue = false;
    }

    ICUPropertyValue(bool boolValue) {
        _boolValue = boolValue;
    }

    ICUPropertyValue(NSObject* obj) {
        _objValue = obj;
    }

    ICUPropertyValue(const ICUPropertyValue& copy) {
        _boolValue = copy._boolValue;
        _objValue = copy._objValue;
    }
};

class ICUPropertyMapper {
public:
    enum PropertyTypes {
        lenient,
        amSymbol,
        pmSymbol,
        shortStandaloneWeekdaySymbols,
        weekdaySymbols,
        shortWeekdaySymbols,
        standaloneWeekdaySymbols,
        standaloneMonthSymbols,
        monthSymbols
    };

private:
    typedef std::function<void(icu::DateFormat*, ICUPropertyValue&, UErrorCode&)> PropertyFunctor;

public:
    PropertyFunctor _setProperty;
    PropertyFunctor _getProperty;
    PropertyTypes _type;

    ICUPropertyMapper() {
    }

    ICUPropertyMapper(const PropertyTypes type, const PropertyFunctor& setter, const PropertyFunctor& getter)
        : _type(type), _setProperty(setter), _getProperty(getter) {
    }

    ICUPropertyMapper(const ICUPropertyMapper& copy) {
        _type = copy._type;
        _getProperty = copy._getProperty;
        _setProperty = copy._setProperty;
    }
};

static NSString* NSStringFromSymbol(icu::DateFormat* formatter, UDateFormatSymbolType symbol, int index, UErrorCode& error) {
    uint32_t len = udat_getSymbols((UDateFormat*)formatter, (UDateFormatSymbolType)symbol, index, NULL, 0, &error);
    UChar* strValue = (UChar*)calloc(len + 1, sizeof(UChar));
    error = U_ZERO_ERROR;
    len = udat_getSymbols((UDateFormat*)formatter, (UDateFormatSymbolType)symbol, index, strValue, len + 1, &error);
    NSString* ret = [NSString stringWithCharacters:(unichar*)strValue length:len];
    free(strValue);

    return ret;
}

static NSArray* NSArrayFromSymbols(icu::DateFormat* formatter, UDateFormatSymbolType symbol, int startIdx, UErrorCode& error) {
    uint32_t count = udat_countSymbols((UDateFormat*)formatter, symbol);

    NSMutableArray* symbolList = [NSMutableArray array];
    for (int i = 0; i < count - startIdx; i++) {
        NSString* string = NSStringFromSymbol(formatter, symbol, i + startIdx, error);
        if (string == nil || error != U_ZERO_ERROR) {
            EbrDebugLog("Error retrieving symbol 0x%x index %d\n", symbol, i);
            return nil;
        }
        [symbolList addObject:string];
    }

    NSArray* ret = [symbolList copy];
    [symbolList release];
    return ret;
}

static void SetSymbolFromNSString(icu::DateFormat* formatter, NSString* value, UDateFormatSymbolType symbol, int index, UErrorCode& error) {
    udat_setSymbols((UDateFormat*)formatter, (UDateFormatSymbolType)symbol, index, (UChar*)[value rawCharacters], [value length], &error);
}

static void SetSymbolsFromNSArray(
    icu::DateFormat* formatter, NSArray* values, UDateFormatSymbolType symbol, int startIdx, UErrorCode& error) {
    for (int i = 0; i < [values count]; i++) {
        NSString* symbolStr = [values objectAtIndex:i];

        udat_setSymbols((UDateFormat*)formatter,
                        (UDateFormatSymbolType)symbol,
                        i + startIdx,
                        (UChar*)[symbolStr rawCharacters],
                        [symbolStr length],
                        &error);
    }
}

static std::map<ICUPropertyMapper::PropertyTypes, ICUPropertyMapper> _icuProperties = {
    { ICUPropertyMapper::lenient,
      ICUPropertyMapper(ICUPropertyMapper::lenient,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            udat_setLenient((UDateFormat*)formatter, value._boolValue);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._boolValue = udat_isLenient((UDateFormat*)formatter);
                        }) },

    { ICUPropertyMapper::amSymbol,
      ICUPropertyMapper(ICUPropertyMapper::amSymbol,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolFromNSString(formatter, (NSString*)value._objValue, (UDateFormatSymbolType)UDAT_AM_PMS, 0, error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSStringFromSymbol(formatter, (UDateFormatSymbolType)UDAT_AM_PMS, 0, error);
                        }) },

    { ICUPropertyMapper::pmSymbol,
      ICUPropertyMapper(ICUPropertyMapper::pmSymbol,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolFromNSString(formatter, (NSString*)value._objValue, (UDateFormatSymbolType)UDAT_AM_PMS, 1, error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSStringFromSymbol(formatter, (UDateFormatSymbolType)UDAT_AM_PMS, 1, error);
                        }) },

    { ICUPropertyMapper::shortStandaloneWeekdaySymbols,
      ICUPropertyMapper(ICUPropertyMapper::shortStandaloneWeekdaySymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter,
                                                  (NSArray*)value._objValue,
                                                  (UDateFormatSymbolType)UDAT_STANDALONE_SHORT_WEEKDAYS,
                                                  1,
                                                  error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue =
                                NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_STANDALONE_SHORT_WEEKDAYS, 1, error);
                        }) },

    { ICUPropertyMapper::weekdaySymbols,
      ICUPropertyMapper(ICUPropertyMapper::weekdaySymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter, (NSArray*)value._objValue, (UDateFormatSymbolType)UDAT_WEEKDAYS, 1, error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_WEEKDAYS, 1, error);
                        }) },

    { ICUPropertyMapper::shortWeekdaySymbols,
      ICUPropertyMapper(ICUPropertyMapper::shortWeekdaySymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter,
                                                  (NSArray*)value._objValue,
                                                  (UDateFormatSymbolType)UDAT_SHORT_WEEKDAYS,
                                                  1,
                                                  error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_SHORT_WEEKDAYS, 1, error);
                        }) },

    { ICUPropertyMapper::standaloneWeekdaySymbols,
      ICUPropertyMapper(ICUPropertyMapper::standaloneWeekdaySymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter,
                                                  (NSArray*)value._objValue,
                                                  (UDateFormatSymbolType)UDAT_STANDALONE_WEEKDAYS,
                                                  1,
                                                  error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_STANDALONE_WEEKDAYS, 1, error);
                        }) },

    { ICUPropertyMapper::standaloneMonthSymbols,
      ICUPropertyMapper(ICUPropertyMapper::standaloneMonthSymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter,
                                                  (NSArray*)value._objValue,
                                                  (UDateFormatSymbolType)UDAT_STANDALONE_MONTHS,
                                                  0,
                                                  error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_STANDALONE_MONTHS, 0, error);
                        }) },

    { ICUPropertyMapper::monthSymbols,
      ICUPropertyMapper(ICUPropertyMapper::monthSymbols,
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            SetSymbolsFromNSArray(formatter, (NSArray*)value._objValue, (UDateFormatSymbolType)UDAT_MONTHS, 0, error);
                        },
                        [](icu::DateFormat* formatter, ICUPropertyValue& value, UErrorCode& error) {
                            value._objValue = NSArrayFromSymbols(formatter, (UDateFormatSymbolType)UDAT_MONTHS, 0, error);
                        }) },
};

@implementation NSDateFormatter {
    NSDateFormatterStyle _dateStyle;
    NSDateFormatterStyle _timeStyle;
    idretaintype(NSString) _dateFormat;
    BOOL _lenient, _lenientSet;
    idretaintype(NSLocale) _locale;
    idretaintype(NSTimeZone) _timeZone;
    idretaintype(NSCalendar) _calendar;

    icu::DateFormat* _formatter;
    BOOL _formatterNeedsRebuilding;

    std::map<ICUPropertyMapper::PropertyTypes, ICUPropertyValue> _valueOverrides;
}
+ (NSString*)dateFormatFromTemplate:(NSString*)dateTemplate options:(NSUInteger)options locale:(NSLocale*)locale {
    UErrorCode error = U_ZERO_ERROR;
    icu::Locale* icuLocale = [locale _createICULocale];
    DateTimePatternGenerator* pg = DateTimePatternGenerator::createInstance(*icuLocale, error);
    delete icuLocale;
    UStringHolder strTemplate(dateTemplate);

    UnicodeString strSkeleton = pg->getSkeleton(strTemplate.string(), error);
    if (U_FAILURE(error)) {
        delete pg;
        return nil;
    }

    UnicodeString pattern = pg->getBestPattern(strSkeleton, error);
    if (U_FAILURE(error)) {
        delete pg;
        return nil;
    }

    NSString* ret = NSStringFromICU(pattern);

    delete pg;

    return ret;
}

- (ICUPropertyValue)_getFormatterProperty:(ICUPropertyMapper::PropertyTypes)type {
    auto pos = _valueOverrides.find(type);
    if (pos != _valueOverrides.end()) {
        return pos->second;
    } else {
        ICUPropertyValue ret;

        UErrorCode status = U_ZERO_ERROR;
        _icuProperties[type]._getProperty([self _getFormatter], ret, status);

        return ret;
    }
}

- (void)_setFormatterProperty:(ICUPropertyMapper::PropertyTypes)type withValue:(ICUPropertyValue)value {
    _valueOverrides[type] = value;
    _formatterNeedsRebuilding = TRUE;
}

- (icu::DateFormat*)_getFormatter {
    if (!_formatter || _formatterNeedsRebuilding) {
        _formatterNeedsRebuilding = FALSE;

        if (_formatter)
            delete _formatter;

        UErrorCode status = U_ZERO_ERROR;
        icu::Locale* icuLocale = [_locale _createICULocale];

        if ([_dateFormat length] > 0) {
            UStringHolder fmtString(_dateFormat);

            _formatter = new SimpleDateFormat(fmtString.string(), *icuLocale, status);
        } else {
            _formatter =
                icu::DateFormat::createDateTimeInstance(convertFormatterStyle(_dateStyle), convertFormatterStyle(_timeStyle), *icuLocale);
        }

        delete icuLocale;

        //  Set calendar
        icu::Calendar* calendar = [_calendar _createICUCalendar];
        _formatter->setCalendar(*calendar);
        delete calendar;

        //  Set all overridden properties
        for (auto& curProperty : _valueOverrides) {
            _icuProperties[curProperty.first]._setProperty(_formatter, curProperty.second, status);
        }

        //  Set timezone
        icu::TimeZone* icuTimezone = [_timeZone _createICUTimeZone];
        _formatter->setTimeZone(*icuTimezone);
        delete icuTimezone;
    }

    return _formatter;
}

- (instancetype)init {
    return [self initWithDateFormat:@"" allowNaturalLanguage:NO];
}

- (instancetype)copyWithZone:(NSZone*)zone {
    NSDateFormatter* copy = [super copyWithZone:zone];

    copy->_dateStyle = _dateStyle;
    copy->_timeStyle = _timeStyle;
    copy->_dateFormat = _dateFormat;
    copy->_locale = _locale;
    copy->_timeZone = _timeZone;
    copy->_valueOverrides = _valueOverrides;

    return copy;
}

- (instancetype)initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag {
    return [self initWithDateFormat:format allowNaturalLanguage:flag locale:[NSLocale currentLocale]];
}

- (instancetype)initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag locale:(NSLocale*)locale {
    if (flag == YES) {
        [NSException raiseWithLogging:@"NSDateFormatterException" format:@"allowNatrualLanguage = YES not supported"];
    }

    [super init];
    _formatter = 0;
    _dateFormat.attach([format copy]);
    _locale = locale;

    _timeZone = [NSTimeZone defaultTimeZone];
    _calendar = [NSCalendar currentCalendar];

    return self;
}

- (void)dealloc {
    _dateFormat = nil;
    _locale = nil;
    _timeZone = nil;

    if (_formatter)
        delete _formatter;

    return [super dealloc];
}

- (void)setCalendar:(NSCalendar*)cal {
    if (_calendar == cal)
        return;

    _calendar = cal;
    _formatterNeedsRebuilding = TRUE;
}

- (NSCalendar*)calendar {
    return _calendar;
}

- (void)setTimeZone:(NSTimeZone*)zone {
    if (_timeZone == zone)
        return;

    _timeZone = zone;
    _formatterNeedsRebuilding = TRUE;
}

- (NSTimeZone*)timeZone {
    return _timeZone;
}

- (void)setLocale:(NSLocale*)locale {
    if (_locale == locale)
        return;

    _locale = locale;
    _formatterNeedsRebuilding = TRUE;
}

- (NSLocale*)locale {
    return _locale;
}

- (void)setLenient:(BOOL)lenient {
    [self _setFormatterProperty:ICUPropertyMapper::lenient withValue:ICUPropertyValue(lenient)];
}

- (BOOL)lenient {
    return [self _getFormatterProperty:ICUPropertyMapper::lenient]._boolValue;
}

- (void)setDateFormat:(NSString*)format {
    if (_dateFormat == format)
        return;

    _dateFormat = format;
    _formatterNeedsRebuilding = TRUE;
}

- (NSString*)dateFormat {
    return _dateFormat;
}

- (void)setDateStyle:(NSDateFormatterStyle)style {
    if (_dateStyle == style)
        return;
    _dateStyle = style;
    _formatterNeedsRebuilding = TRUE;
}

- (NSDateFormatterStyle)dateStyle {
    return _dateStyle;
}

- (void)setTimeStyle:(NSDateFormatterStyle)style {
    if (_timeStyle == style)
        return;
    _timeStyle = style;
    _formatterNeedsRebuilding = TRUE;
}

- (NSDateFormatterStyle)timeStyle {
    return _timeStyle;
}

- (NSString*)stringFromDate:(NSDate*)date {
    if (date == nil)
        return nil;

    UnicodeString str;

    [self _getFormatter]->format([date timeIntervalSince1970] * 1000.0, str);

    return NSStringFromICU(str);
}

- (NSDate*)dateFromString:(NSString*)str {
    UStringHolder uStr(str);
    UErrorCode status = U_ZERO_ERROR;
    UDate date = [self _getFormatter]->parse(uStr.string(), status);

    if (!U_SUCCESS(status))
        return nil;
    return [NSDate dateWithTimeIntervalSince1970:date / 1000.0];
}

- (BOOL)getObjectValue:(id*)outObj forString:(id)str errorDescription:(NSString**)err {
    if (err)
        *err = nil;

    *outObj = [self dateFromString:str];
    return TRUE;
}

- (NSString*)stringForObjectValue:(NSObject*)object {
    if ([object isKindOfClass:[NSDate class]]) {
        return [self stringFromDate:(NSDate*)object];
    } else {
        return nil;
    }
}

- (void)setAMSymbol:(NSString*)symbol {
    [self _setFormatterProperty:ICUPropertyMapper::amSymbol withValue:ICUPropertyValue(symbol)];
}

- (NSString*)AMSymbol {
    return (NSString*)[self _getFormatterProperty:ICUPropertyMapper::amSymbol]._objValue;
}

- (void)setPMSymbol:(NSString*)symbol {
    [self _setFormatterProperty:ICUPropertyMapper::pmSymbol withValue:ICUPropertyValue(symbol)];
}

- (NSString*)PMSymbol {
    return (NSString*)[self _getFormatterProperty:ICUPropertyMapper::pmSymbol]._objValue;
}

- (void)setShortStandaloneWeekdaySymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::shortStandaloneWeekdaySymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)shortStandaloneWeekdaySymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::shortStandaloneWeekdaySymbols]._objValue;
}

- (void)setWeekdaySymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::weekdaySymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)weekdaySymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::weekdaySymbols]._objValue;
}

- (void)setShortWeekdaySymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::shortWeekdaySymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)shortWeekdaySymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::shortWeekdaySymbols]._objValue;
}

- (void)setStandaloneWeekdaySymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::standaloneWeekdaySymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)standaloneWeekdaySymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::standaloneWeekdaySymbols]._objValue;
}

- (void)setStandaloneMonthSymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::standaloneMonthSymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)standaloneMonthSymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::standaloneMonthSymbols]._objValue;
}

- (void)setMonthSymbols:(NSArray*)symbols {
    [self _setFormatterProperty:ICUPropertyMapper::monthSymbols withValue:ICUPropertyValue(symbols)];
}

- (NSArray*)monthSymbols {
    return (NSArray*)[self _getFormatterProperty:ICUPropertyMapper::monthSymbols]._objValue;
}
@end
