/*
*******************************************************************************
* Copyright (C) 2011, International Business Machines Corporation and         *
* others. All Rights Reserved.                                                *
*******************************************************************************
*/
#ifndef __TZFMT_H
#define __TZFMT_H

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "unicode/uobject.h"
#include "unicode/uloc.h"
#include "unicode/unistr.h"
#include "unicode/format.h"
#include "unicode/timezone.h"
#include "tznames.h"

U_CDECL_BEGIN

typedef enum UTimeZoneFormatStyle {
    UTZFMT_STYLE_LOCATION,
    UTZFMT_STYLE_GENERIC_LONG,
    UTZFMT_STYLE_GENERIC_SHORT,
    UTZFMT_STYLE_SPECIFIC_LONG,
    UTZFMT_STYLE_SPECIFIC_SHORT,
    UTZFMT_STYLE_SPECIFIC_SHORT_COMMONLY_USED
} UTimeZoneFormatStyle;

typedef enum UTimeZoneTimeType {
    UTZFMT_TIME_TYPE_UNKNOWN,
    UTZFMT_TIME_TYPE_STANDARD,
    UTZFMT_TIME_TYPE_DAYLIGHT
} UTimeZoneTimeType;

U_CDECL_END

U_NAMESPACE_BEGIN

class TimeZoneNames;

class U_I18N_API TimeZoneFormat : public UMemory {
public:
    virtual ~TimeZoneFormat();

    static TimeZoneFormat* U_EXPORT2 createInstance(const Locale& locale, UErrorCode& status);

    virtual const TimeZoneNames* getTimeZoneNames() const = 0;

    virtual UnicodeString& format(UTimeZoneFormatStyle style, const TimeZone& tz, UDate date,
        UnicodeString& name, UTimeZoneTimeType* timeType = NULL) const = 0;

    virtual UnicodeString& parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UnicodeString& tzID, UTimeZoneTimeType* timeType = NULL) const = 0;

    TimeZone* parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UTimeZoneTimeType* timeType = NULL) const;
};

U_NAMESPACE_END

#endif
#endif
