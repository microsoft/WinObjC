/*
*******************************************************************************
* Copyright (C) 2011, International Business Machines Corporation and         *
* others. All Rights Reserved.                                                *
*******************************************************************************
*/
#ifndef __TZNAMES_H
#define __TZNAMES_H

/**
 * \file 
 * \brief C API: Time zone names class
 */
#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "unicode/uloc.h"
#include "unicode/unistr.h"

U_CDECL_BEGIN

typedef enum UTimeZoneNameType {
    UTZNM_UNKNOWN           = 0x00,
    UTZNM_LONG_GENERIC      = 0x01,
    UTZNM_LONG_STANDARD     = 0x02,
    UTZNM_LONG_DAYLIGHT     = 0x04,
    UTZNM_SHORT_GENERIC     = 0x08,
    UTZNM_SHORT_STANDARD    = 0x10,
    UTZNM_SHORT_DAYLIGHT    = 0x20,
    UTZNM_SHORT_STANDARD_COMMONLY_USED  = 0x40,
    UTZNM_SHORT_DAYLIGHT_COMMONLY_USED  = 0x80
} UTimeZoneNameType;

U_CDECL_END

U_NAMESPACE_BEGIN

class U_I18N_API TimeZoneNameMatchInfo : public UMemory {
public:
    virtual ~TimeZoneNameMatchInfo();

    virtual int32_t size() const = 0;
    virtual UTimeZoneNameType getNameType(int32_t index) const = 0;
    virtual int32_t getMatchLength(int32_t index) const = 0;
    virtual UnicodeString& getTimeZoneID(int32_t index, UnicodeString& tzID) const = 0;
    virtual UnicodeString& getMetaZoneID(int32_t index, UnicodeString& mzID) const = 0;
};

inline
TimeZoneNameMatchInfo::~TimeZoneNameMatchInfo() {
}

class U_I18N_API TimeZoneNames : public UMemory {
public:
    virtual ~TimeZoneNames();

    static TimeZoneNames* U_EXPORT2 createInstance(const Locale& locale, UErrorCode& status);

    virtual StringEnumeration* getAvailableMetaZoneIDs(UErrorCode& status) const = 0;
    virtual StringEnumeration* getAvailableMetaZoneIDs(const UnicodeString& tzID, UErrorCode& status) const = 0;

    virtual UnicodeString& getMetaZoneID(const UnicodeString& tzID, UDate date, UnicodeString& mzID) const = 0;
    virtual UnicodeString& getReferenceZoneID(const UnicodeString& mzID, const char* region, UnicodeString& tzID) const = 0;

    virtual UnicodeString& getMetaZoneDisplayName(const UnicodeString& mzID, UTimeZoneNameType type, UnicodeString& name) const = 0;
    virtual UnicodeString& getTimeZoneDisplayName(const UnicodeString& tzID, UTimeZoneNameType type, UnicodeString& name) const = 0;

    virtual UnicodeString& getExemplarLocationName(const UnicodeString& tzID, UnicodeString& name) const;
    virtual UnicodeString& getDisplayName(const UnicodeString& tzID, UTimeZoneNameType type, UDate date, UnicodeString& name) const;

    virtual TimeZoneNameMatchInfo* find(const UnicodeString& text, int32_t start, uint32_t types, UErrorCode& status) const = 0;
};

inline
TimeZoneNames::~TimeZoneNames() {
}

U_NAMESPACE_END
#endif
#endif
