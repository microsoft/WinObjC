/*
*******************************************************************************
* Copyright (C) 2011, International Business Machines Corporation and         *
* others. All Rights Reserved.                                                *
*******************************************************************************
*/

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "tzfmt.h"
#include "tzgnames.h"
#include "cmemory.h"
#include "cstring.h"
#include "putilimp.h"
#include "uassert.h"
#include "ucln_in.h"
#include "uhash.h"
#include "umutex.h"
#include "zonemeta.h"

U_NAMESPACE_BEGIN

// ---------------------------------------------------
// TimeZoneFormatImpl - the TimeZoneFormat implementation
// ---------------------------------------------------
class TimeZoneFormatImpl : public TimeZoneFormat {
public:
    TimeZoneFormatImpl(const Locale& locale, UErrorCode& status);
    virtual ~TimeZoneFormatImpl();

    const TimeZoneNames* getTimeZoneNames() const;

    UnicodeString& format(UTimeZoneFormatStyle style, const TimeZone& tz, UDate date,
        UnicodeString& name, UTimeZoneTimeType* timeType = NULL) const;

    UnicodeString& parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UnicodeString& tzID, UTimeZoneTimeType* timeType = NULL) const;

private:
    UMTX fLock;
    Locale fLocale;
    char fTargetRegion[ULOC_COUNTRY_CAPACITY];
    TimeZoneNames* fTimeZoneNames;
    TimeZoneGenericNames* fTimeZoneGenericNames;

    UnicodeString& formatGeneric(const TimeZone& tz, UTimeZoneGenericNameType genType, UDate date, UnicodeString& name) const;

    UnicodeString& formatSpecific(const TimeZone& tz, UTimeZoneNameType stdType, UTimeZoneNameType dstType,
        UDate date, UnicodeString& name, UTimeZoneTimeType *timeType) const;

    const TimeZoneGenericNames* getTimeZoneGenericNames(UErrorCode& status) const;
};

TimeZoneFormatImpl::TimeZoneFormatImpl(const Locale& locale, UErrorCode& status)
: fLock(NULL),fLocale(locale), fTimeZoneNames(NULL), fTimeZoneGenericNames(NULL) {

    const char* region = fLocale.getCountry();
    int32_t regionLen = uprv_strlen(region);
    if (regionLen == 0) {
        char loc[ULOC_FULLNAME_CAPACITY];
        uloc_addLikelySubtags(fLocale.getName(), loc, sizeof(loc), &status);

        regionLen = uloc_getCountry(loc, fTargetRegion, sizeof(fTargetRegion), &status);
        if (U_SUCCESS(status)) {
            fTargetRegion[regionLen] = 0;
        } else {
            return;
        }
    } else if (regionLen < (int32_t)sizeof(fTargetRegion)) {
        uprv_strcpy(fTargetRegion, region);
    } else {
        fTargetRegion[0] = 0;
    }

    fTimeZoneNames = TimeZoneNames::createInstance(locale, status);
    // fTimeZoneGenericNames is lazily instantiated
}

TimeZoneFormatImpl::~TimeZoneFormatImpl() {
    if (fTimeZoneNames != NULL) {
        delete fTimeZoneNames;
    }
    if (fTimeZoneGenericNames != NULL) {
        delete fTimeZoneGenericNames;
    }
    umtx_destroy(&fLock);
}

const TimeZoneNames*
TimeZoneFormatImpl::getTimeZoneNames() const {
    return fTimeZoneNames;
}

const TimeZoneGenericNames*
TimeZoneFormatImpl::getTimeZoneGenericNames(UErrorCode& status) const {
    if (U_FAILURE(status)) {
        return NULL;
    }

    UBool create;
    UMTX_CHECK(&gZoneMetaLock, (fTimeZoneGenericNames == NULL), create);
    if (create) {
        TimeZoneFormatImpl *nonConstThis = const_cast<TimeZoneFormatImpl *>(this);
        umtx_lock(&nonConstThis->fLock);
        {
            if (fTimeZoneGenericNames == NULL) {
                nonConstThis->fTimeZoneGenericNames = new TimeZoneGenericNames(fLocale, status);
                if (U_SUCCESS(status) && fTimeZoneGenericNames == NULL) {
                    status = U_MEMORY_ALLOCATION_ERROR;
                }
            }
        }
        umtx_unlock(&nonConstThis->fLock);
    }

    return fTimeZoneGenericNames;
}

UnicodeString&
TimeZoneFormatImpl::format(UTimeZoneFormatStyle style, const TimeZone& tz, UDate date,
        UnicodeString& name, UTimeZoneTimeType* timeType /* = NULL */) const {
    if (timeType) {
        *timeType = UTZFMT_TIME_TYPE_UNKNOWN;
    }
    switch (style) {
    case UTZFMT_STYLE_LOCATION:
        formatGeneric(tz, UTZGNM_LOCATION, date, name);
        break;
    case UTZFMT_STYLE_GENERIC_LONG:
        formatGeneric(tz, UTZGNM_LONG, date, name);
        break;
    case UTZFMT_STYLE_GENERIC_SHORT:
        formatGeneric(tz, UTZGNM_SHORT, date, name);
        break;
    case UTZFMT_STYLE_SPECIFIC_LONG:
        formatSpecific(tz, UTZNM_LONG_STANDARD, UTZNM_LONG_DAYLIGHT, date, name, timeType);
        break;
    case UTZFMT_STYLE_SPECIFIC_SHORT:
        formatSpecific(tz, UTZNM_SHORT_STANDARD, UTZNM_SHORT_DAYLIGHT, date, name, timeType);
        break;
    case UTZFMT_STYLE_SPECIFIC_SHORT_COMMONLY_USED:
        formatSpecific(tz, UTZNM_SHORT_STANDARD_COMMONLY_USED, UTZNM_SHORT_DAYLIGHT_COMMONLY_USED, date, name, timeType);
        break;
    }
    return name;
}

UnicodeString&
TimeZoneFormatImpl::parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UnicodeString& tzID, UTimeZoneTimeType* timeType /* = NULL */) const {
    if (timeType) {
        *timeType = UTZFMT_TIME_TYPE_UNKNOWN;
    }
    tzID.setToBogus();

    int32_t startIdx = pos.getIndex();

    UBool isGeneric = FALSE;
    uint32_t types = 0;

    switch (style) {
    case UTZFMT_STYLE_LOCATION:
        isGeneric = TRUE;
        types = UTZGNM_LOCATION;
        break;
    case UTZFMT_STYLE_GENERIC_LONG:
        isGeneric = TRUE;
        types = UTZGNM_LOCATION | UTZGNM_LONG;
        break;
    case UTZFMT_STYLE_GENERIC_SHORT:
        isGeneric = TRUE;
        types = UTZGNM_LOCATION | UTZGNM_SHORT;
        break;
    case UTZFMT_STYLE_SPECIFIC_LONG:
        types = UTZNM_LONG_STANDARD | UTZNM_LONG_DAYLIGHT;
        break;
    case UTZFMT_STYLE_SPECIFIC_SHORT:
        types = UTZNM_SHORT_STANDARD | UTZNM_SHORT_DAYLIGHT;
        break;
    case UTZFMT_STYLE_SPECIFIC_SHORT_COMMONLY_USED:
        types = UTZNM_SHORT_STANDARD_COMMONLY_USED | UTZNM_SHORT_DAYLIGHT_COMMONLY_USED;
        break;
    }

    UTimeZoneTimeType parsedTimeType = UTZFMT_TIME_TYPE_UNKNOWN;
    UnicodeString parsedTzID;
    UErrorCode status = U_ZERO_ERROR;

    if (isGeneric) {
        int32_t len = 0;
        const TimeZoneGenericNames *gnames = getTimeZoneGenericNames(status);
        if (U_SUCCESS(status)) {
            len = gnames->findBestMatch(text, startIdx, types, parsedTzID, parsedTimeType, status);
        }
        if (U_FAILURE(status) || len == 0) {
            pos.setErrorIndex(startIdx);
            return tzID;
        }
        pos.setIndex(startIdx + len);
    } else {
        TimeZoneNameMatchInfo *matchInfo = fTimeZoneNames->find(text, startIdx, types, status);
        if (U_FAILURE(status) || matchInfo == NULL) {
            pos.setErrorIndex(startIdx);
            return tzID;
        }
        int32_t bestLen = 0;
        int32_t bestIdx = -1;
        for (int32_t i = 0; i < matchInfo->size(); i++) {
            int32_t matchLen = matchInfo->getMatchLength(i);
            if (matchLen > bestLen) {
                bestLen = matchLen;
                bestIdx = i;
            }
        }
        if (bestIdx >= 0) {
            matchInfo->getTimeZoneID(bestIdx, parsedTzID);
            if (parsedTzID.isEmpty()) {
                UnicodeString mzID;
                matchInfo->getMetaZoneID(bestIdx, mzID);
                U_ASSERT(mzID.length() > 0);
                fTimeZoneNames->getReferenceZoneID(mzID, fTargetRegion, parsedTzID);
            }
            UTimeZoneNameType nameType = matchInfo->getNameType(bestIdx);
            switch (nameType) {
            case UTZNM_LONG_STANDARD:
            case UTZNM_SHORT_STANDARD:
            case UTZNM_SHORT_STANDARD_COMMONLY_USED:
                parsedTimeType = UTZFMT_TIME_TYPE_STANDARD;
                break;
            case UTZNM_LONG_DAYLIGHT:
            case UTZNM_SHORT_DAYLIGHT:
            case UTZNM_SHORT_DAYLIGHT_COMMONLY_USED:
                parsedTimeType = UTZFMT_TIME_TYPE_DAYLIGHT;
                break;
            default:
                parsedTimeType = UTZFMT_TIME_TYPE_UNKNOWN;
                break;
            }
            pos.setIndex(startIdx + bestLen);
        }
        delete matchInfo;
    }
    if (timeType) {
        *timeType = parsedTimeType;
    }
    tzID.setTo(parsedTzID);
    return tzID;
}

UnicodeString&
TimeZoneFormatImpl::formatGeneric(const TimeZone& tz, UTimeZoneGenericNameType genType, UDate date, UnicodeString& name) const {
    UErrorCode status = U_ZERO_ERROR;
    const TimeZoneGenericNames* gnames = getTimeZoneGenericNames(status);
    if (U_FAILURE(status)) {
        name.setToBogus();
        return name;
    }

    if (genType == UTZGNM_LOCATION) {
        const UChar* canonicalID = ZoneMeta::getCanonicalCLDRID(tz);
        if (canonicalID == NULL) {
            name.setToBogus();
            return name;
        }
        return gnames->getGenericLocationName(UnicodeString(canonicalID), name);
    }
    return gnames->getDisplayName(tz, genType, date, name);
}

UnicodeString&
TimeZoneFormatImpl::formatSpecific(const TimeZone& tz, UTimeZoneNameType stdType, UTimeZoneNameType dstType,
        UDate date, UnicodeString& name, UTimeZoneTimeType *timeType) const {
    if (fTimeZoneNames == NULL) {
        name.setToBogus();
        return name;
    }

    UErrorCode status = U_ZERO_ERROR;
    UBool isDaylight = tz.inDaylightTime(date, status);
    const UChar* canonicalID = ZoneMeta::getCanonicalCLDRID(tz);

    if (U_FAILURE(status) || canonicalID == NULL) {
        name.setToBogus();
        return name;
    }

    if (isDaylight) {
        fTimeZoneNames->getDisplayName(UnicodeString(canonicalID), dstType, date, name);
    } else {
        fTimeZoneNames->getDisplayName(UnicodeString(canonicalID), stdType, date, name);
    }

    if (timeType && !name.isEmpty()) {
        *timeType = isDaylight ? UTZFMT_TIME_TYPE_DAYLIGHT : UTZFMT_TIME_TYPE_STANDARD;
    }
    return name;
}


// TimeZoneFormat object cache handling
static UMTX gTimeZoneFormatLock = NULL;
static UHashtable *gTimeZoneFormatCache = NULL;
static UBool gTimeZoneFormatCacheInitialized = FALSE;

// Access count - incremented every time up to SWEEP_INTERVAL,
// then reset to 0
static int32_t gAccessCount = 0;

// Interval for calling the cache sweep function - every 100 times
#define SWEEP_INTERVAL 100

// Cache expiration in millisecond. When a cached entry is no
// longer referenced and exceeding this threshold since last
// access time, then the cache entry will be deleted by the sweep
// function. For now, 3 minutes.
#define CACHE_EXPIRATION 180000.0

typedef struct TimeZoneFormatCacheEntry {
    TimeZoneFormat* tzfmt;
    int32_t         refCount;
    double          lastAccess;
} TimeZoneNameFormatCacheEntry;

U_CDECL_BEGIN
/**
 * Cleanup callback func
 */
static UBool U_CALLCONV timeZoneFormat_cleanup(void)
{
    umtx_destroy(&gTimeZoneFormatLock);

    if (gTimeZoneFormatCache != NULL) {
        uhash_close(gTimeZoneFormatCache);
        gTimeZoneFormatCache = NULL;
    }
    gTimeZoneFormatCacheInitialized = FALSE;
    return TRUE;
}

/**
 * Deleter for TimeZoneNamesCacheEntry
 */
static void U_CALLCONV
deleteTimeZoneFormatCacheEntry(void *obj) {
    TimeZoneNameFormatCacheEntry *entry = (TimeZoneNameFormatCacheEntry *)obj;
    delete (TimeZoneFormat *) entry->tzfmt;
    uprv_free((void *)entry);
}
U_CDECL_END

/**
 * Function used for removing unreferrenced cache entries exceeding
 * the expiration time. This function must be called with in the mutex
 * block.
 */
static void sweepCache() {
    int32_t pos = -1;
    const UHashElement* elem;
    double now = (double)uprv_getUTCtime();

    while ((elem = uhash_nextElement(gTimeZoneFormatCache, &pos))) {
        TimeZoneFormatCacheEntry *entry = (TimeZoneFormatCacheEntry *)elem->value.pointer;
        if (entry->refCount <= 0 && (now - entry->lastAccess) > CACHE_EXPIRATION) {
            // delete this entry
            uhash_removeElement(gTimeZoneFormatCache, elem);
        }
    }
}

// ---------------------------------------------------
// TimeZoneFormatDelegate
// This class wraps a TimeZoneFormatImpl singleton
// per locale and maintain the reference count.
// ---------------------------------------------------
class TimeZoneFormatDelegate : public TimeZoneFormat {
public:
    TimeZoneFormatDelegate(const Locale& locale, UErrorCode& status);
    virtual ~TimeZoneFormatDelegate();

    const TimeZoneNames* getTimeZoneNames() const;

    UnicodeString& format(UTimeZoneFormatStyle style, const TimeZone& tz, UDate date,
        UnicodeString& name, UTimeZoneTimeType* timeType = NULL) const;

    UnicodeString& parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UnicodeString& tzID, UTimeZoneTimeType* timeType = NULL) const;

private:
    TimeZoneFormatCacheEntry* fTZfmtCacheEntry;
};

TimeZoneFormatDelegate::TimeZoneFormatDelegate(const Locale& locale, UErrorCode& status) {
    UBool initialized;
    UMTX_CHECK(&gTimeZoneFormatLock, gTimeZoneFormatCacheInitialized, initialized);
    if (!initialized) {
        // Create empty hashtable
        umtx_lock(&gTimeZoneFormatLock);
        {
            if (!gTimeZoneFormatCacheInitialized) {
                gTimeZoneFormatCache = uhash_open(uhash_hashChars, uhash_compareChars, NULL, &status);
                if (U_SUCCESS(status)) {
                    uhash_setKeyDeleter(gTimeZoneFormatCache, uhash_freeBlock);
                    uhash_setValueDeleter(gTimeZoneFormatCache, deleteTimeZoneFormatCacheEntry);
                    gTimeZoneFormatCacheInitialized = TRUE;
                    ucln_i18n_registerCleanup(UCLN_I18N_TIMEZONEFORMAT, timeZoneFormat_cleanup);
                }
            }
        }
        umtx_unlock(&gTimeZoneFormatLock);
    }

    // Check the cache, if not available, create new one and cache
    TimeZoneFormatCacheEntry *cacheEntry = NULL;
    umtx_lock(&gTimeZoneFormatLock);
    {
        const char *key = locale.getName();
        cacheEntry = (TimeZoneFormatCacheEntry *)uhash_get(gTimeZoneFormatCache, key);
        if (cacheEntry == NULL) {
            TimeZoneFormat *tzfmt = NULL;
            char *newKey = NULL;

            tzfmt = new TimeZoneFormatImpl(locale, status);
            if (tzfmt == NULL) {
                status = U_MEMORY_ALLOCATION_ERROR;
            }
            if (U_SUCCESS(status)) {
                newKey = (char *)uprv_malloc(uprv_strlen(key) + 1);
                if (newKey == NULL) {
                    status = U_MEMORY_ALLOCATION_ERROR;
                } else {
                    uprv_strcpy(newKey, key);
                }
            }
            if (U_SUCCESS(status)) {
                cacheEntry = (TimeZoneFormatCacheEntry *)uprv_malloc(sizeof(TimeZoneFormatCacheEntry));
                if (cacheEntry == NULL) {
                    status = U_MEMORY_ALLOCATION_ERROR;
                } else {
                    cacheEntry->tzfmt = tzfmt;
                    cacheEntry->refCount = 1;
                    cacheEntry->lastAccess = (double)uprv_getUTCtime();

                    uhash_put(gTimeZoneFormatCache, newKey, cacheEntry, &status);
                }
            }
            if (U_FAILURE(status)) {
                if (tzfmt != NULL) {
                    delete tzfmt;
                }
                if (newKey != NULL) {
                    uprv_free(newKey);
                }
                if (cacheEntry != NULL) {
                    uprv_free(cacheEntry);
                }
                return;
            }
        } else {
            // Update the reference count
            cacheEntry->refCount++;
            cacheEntry->lastAccess = (double)uprv_getUTCtime();
        }
        gAccessCount++;
        if (gAccessCount >= SWEEP_INTERVAL) {
            // sweep
            sweepCache();
            gAccessCount = 0;
        }
    }
    umtx_unlock(&gTimeZoneFormatLock);

    fTZfmtCacheEntry = cacheEntry;
}

TimeZoneFormatDelegate::~TimeZoneFormatDelegate() {
    umtx_lock(&gTimeZoneFormatLock);
    {
        U_ASSERT(fTZfmtCacheEntry->refCount > 0);
        // Just decrement the reference count
        fTZfmtCacheEntry->refCount--;
    }
    umtx_unlock(&gTimeZoneFormatLock);
}

const TimeZoneNames*
TimeZoneFormatDelegate::getTimeZoneNames() const {
    return fTZfmtCacheEntry->tzfmt->getTimeZoneNames();
}

UnicodeString&
TimeZoneFormatDelegate::format(UTimeZoneFormatStyle style, const TimeZone& tz, UDate date,
        UnicodeString& name, UTimeZoneTimeType* timeType /* = NULL */) const {
    return fTZfmtCacheEntry->tzfmt->format(style, tz, date, name, timeType);
}

UnicodeString&
TimeZoneFormatDelegate::parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UnicodeString& tzID, UTimeZoneTimeType* timeType /* = NULL */) const {
    return fTZfmtCacheEntry->tzfmt->parse(style, text, pos, tzID, timeType);
}


// ---------------------------------------------------
// TimeZoneFormat base class
// ---------------------------------------------------
TimeZoneFormat::~TimeZoneFormat() {
}

TimeZone*
TimeZoneFormat::parse(UTimeZoneFormatStyle style, const UnicodeString& text, ParsePosition& pos,
        UTimeZoneTimeType* timeType /*= NULL*/) const {
    UnicodeString tzID;
    parse(style, text, pos, tzID, timeType);
    if (pos.getErrorIndex() < 0) {
        return TimeZone::createTimeZone(tzID);
    }
    return NULL;
}

TimeZoneFormat* U_EXPORT2
TimeZoneFormat::createInstance(const Locale& locale, UErrorCode& status) {
    TimeZoneFormat* tzfmt = new TimeZoneFormatDelegate(locale, status);
    if (U_SUCCESS(status) && tzfmt == NULL) {
        status = U_MEMORY_ALLOCATION_ERROR;
    }
    return tzfmt;
}


U_NAMESPACE_END

#endif
