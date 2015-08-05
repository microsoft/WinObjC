/*
*******************************************************************************
* Copyright (C) 2011, International Business Machines Corporation and         *
* others. All Rights Reserved.                                                *
*******************************************************************************
*/
#ifndef __TZGNAMES_H
#define __TZGNAMES_H

/**
 * \file 
 * \brief C API: Time zone generic names classe
 */

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "unicode/locid.h"
#include "unicode/timezone.h"
#include "unicode/unistr.h"
#include "tznames.h"
#include "tznames_impl.h"
#include "tzfmt.h"
#include "uhash.h"
#include "umutex.h"

U_CDECL_BEGIN

typedef enum UTimeZoneGenericNameType {
    UTZGNM_UNKNOWN      = 0x00,
    UTZGNM_LOCATION     = 0x01,
    UTZGNM_LONG         = 0x02,
    UTZGNM_SHORT        = 0x04
} UTimeZoneGenericNameType;

U_CDECL_END

U_NAMESPACE_BEGIN

class LocaleDisplayNames;
class MessageFormat;
class TimeZone;

class TimeZoneGenericNameMatchInfo : public UMemory {
public:
    TimeZoneGenericNameMatchInfo(UVector* matches);
    ~TimeZoneGenericNameMatchInfo();

    int32_t size() const;
    UTimeZoneGenericNameType getGenericNameType(int32_t index) const;
    int32_t getMatchLength(int32_t index) const;
    UnicodeString& getTimeZoneID(int32_t index, UnicodeString& tzID) const;

private:
    UVector* fMatches;  // vector of MatchEntry
};

class U_I18N_API TimeZoneGenericNames : public UMemory {
public:
    TimeZoneGenericNames(const Locale& locale, UErrorCode& status);
    virtual ~TimeZoneGenericNames();

    UnicodeString& getDisplayName(const TimeZone& tz, UTimeZoneGenericNameType type,
                        UDate date, UnicodeString& name) const;

    UnicodeString& getGenericLocationName(const UnicodeString& tzCanonicalID, UnicodeString& name) const;

    int32_t findBestMatch(const UnicodeString& text, int32_t start, uint32_t types,
        UnicodeString& tzID, UTimeZoneTimeType& timeType, UErrorCode& status) const;

private:
    Locale fLocale;
    UMTX fLock;
    const TimeZoneNames* fTimeZoneNames;
    UHashtable* fLocationNamesMap;
    UHashtable* fPartialLocationNamesMap;

    MessageFormat* fRegionFormat;
    MessageFormat* fFallbackRegionFormat;
    MessageFormat* fFallbackFormat;

    LocaleDisplayNames* fLocaleDisplayNames;
    ZNStringPool fStringPool;

    TextTrieMap fGNamesTrie;
    UBool fGNamesTrieFullyLoaded;

    char fTargetRegion[ULOC_COUNTRY_CAPACITY];

    void initialize(const Locale& locale, UErrorCode& status);
    void cleanup();

    void loadStrings(const UnicodeString& tzCanonicalID);

    const UChar* getGenericLocationName(const UnicodeString& tzCanonicalID);

    UnicodeString& formatGenericNonLocationName(const TimeZone& tz, UTimeZoneGenericNameType type,
                        UDate date, UnicodeString& name) const;

    UnicodeString& getPartialLocationName(const UnicodeString& tzCanonicalID,
                        const UnicodeString& mzID, UBool isLong, const UnicodeString& mzDisplayName,
                        UnicodeString& name) const;

    const UChar* getPartialLocationName(const UnicodeString& tzCanonicalID,
                        const UnicodeString& mzID, UBool isLong, const UnicodeString& mzDisplayName);

    TimeZoneGenericNameMatchInfo* findLocal(const UnicodeString& text, int32_t start, uint32_t types, UErrorCode& status) const;

    TimeZoneNameMatchInfo* findTimeZoneNames(const UnicodeString& text, int32_t start, uint32_t types, UErrorCode& status) const;
};

U_NAMESPACE_END
#endif
#endif
