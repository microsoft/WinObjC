// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Copyright (c) Microsoft. All rights reserved.
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*  CFTimeZone.c
    Copyright (c) 1998 - 2015 Apple Inc. and the Swift project authors
    Responsibility: Christopher Kane
*/

// WINOBJC:
// WinObjC has opted to base its CFTimeZone implementation off of ICU instead of tzinfo files,
// causing this file to diverge significantly from Apple's open-source implementation.
// Because of the scope of the changes, 
// individual divergences within this file may not be denoted with a WINOBJC comment,
// nor document the original state of the code.

#include <CoreFoundation/CFTimeZone.h>
#include <CoreFoundation/CFPropertyList.h>
#include <CoreFoundation/CFDateFormatter.h>
#include "CFPriv.h"
#include "CFLocaleInternal.h"
#include "CFInternal.h"
#include <math.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unicode/ucal.h>
#include <unicode/udat.h>
#include <unicode/basictz.h>
#include <unicode/timezone.h>
#include <unicode/tztrans.h>
#include <CoreFoundation/CFDateFormatter.h>
#if DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED || DEPLOYMENT_TARGET_LINUX || DEPLOYMENT_TARGET_FREEBSD
#include <dirent.h>
#include <unistd.h>
#include <sys/fcntl.h>
#endif
#if DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED
#include <tzfile.h>
#elif DEPLOYMENT_TARGET_LINUX || DEPLOYMENT_TARGET_FREEBSD
#ifndef TZDIR
#define TZDIR   "/usr/share/zoneinfo" /* Time zone object file directory */
#endif /* !defined TZDIR */

#ifndef TZDEFAULT
#define TZDEFAULT   "/etc/localtime"
#endif /* !defined TZDEFAULT */

#endif

#include <Foundation/NSTimeZone.h>
#include <Foundation/NSDate.h>

#include <time.h>

#if DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED || DEPLOYMENT_TARGET_LINUX || DEPLOYMENT_TARGET_FREEBSD
#define TZZONELINK  TZDEFAULT
#define TZZONEINFO  TZDIR "/"
#elif DEPLOYMENT_TARGET_WINDOWS
#else
#error Unknown or unspecified DEPLOYMENT_TARGET
#endif

CONST_STRING_DECL(kCFTimeZoneSystemTimeZoneDidChangeNotification, "kCFTimeZoneSystemTimeZoneDidChangeNotification")

static CFTimeZoneRef __CFTimeZoneSystem = NULL;
static CFTimeZoneRef __CFTimeZoneDefault = NULL;
static CFDictionaryRef __CFTimeZoneAbbreviationDict = NULL;
static CFLock_t __CFTimeZoneAbbreviationLock = CFLockInit;
static CFMutableDictionaryRef __CFTimeZoneCompatibilityMappingDict = NULL;
static CFLock_t __CFTimeZoneCompatibilityMappingLock = CFLockInit;
static CFArrayRef __CFKnownTimeZoneList = NULL;
static CFMutableDictionaryRef __CFTimeZoneCache = NULL;
static CFLock_t __CFTimeZoneGlobalLock = CFLockInit;

#if DEPLOYMENT_TARGET_WINDOWS
static CFDictionaryRef __CFTimeZoneWinToOlsonDict = NULL;
static CFLock_t __CFTimeZoneWinToOlsonLock = CFLockInit;
#endif

CF_INLINE void __CFTimeZoneLockGlobal(void) {
    __CFLock(&__CFTimeZoneGlobalLock);
}

CF_INLINE void __CFTimeZoneUnlockGlobal(void) {
    __CFUnlock(&__CFTimeZoneGlobalLock);
}

CF_INLINE void __CFTimeZoneLockAbbreviations(void) {
    __CFLock(&__CFTimeZoneAbbreviationLock);
}

CF_INLINE void __CFTimeZoneUnlockAbbreviations(void) {
    __CFUnlock(&__CFTimeZoneAbbreviationLock);
}

CF_INLINE void __CFTimeZoneLockCompatibilityMapping(void) {
    __CFLock(&__CFTimeZoneCompatibilityMappingLock);
}

CF_INLINE void __CFTimeZoneUnlockCompatibilityMapping(void) {
    __CFUnlock(&__CFTimeZoneCompatibilityMappingLock);
}

#if DEPLOYMENT_TARGET_WINDOWS
/* This function should be used for WIN32 instead of
 * __CFCopyRecursiveDirectoryList function.
 * It takes TimeZone names from the registry
 * (Aleksey Dukhnyakov)
 */
static CFMutableArrayRef __CFCopyWindowsTimeZoneList() {
    // WINOBJC: can't access registry in an appcontainer. Use list of dynamic time zones instead.
    CFMutableArrayRef result = CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks);
    DWORD dwIndex;
    DYNAMIC_TIME_ZONE_INFORMATION info;
    
    for (dwIndex=0; EnumDynamicTimeZoneInformation(dwIndex, &info) == ERROR_SUCCESS ; dwIndex++) {
        CFStringRef string = CFStringCreateWithCharacters(
            kCFAllocatorSystemDefault, reinterpret_cast<const UniChar*>(info.StandardName), wcsnlen_s(info.StandardName, 32));
        CFArrayAppendValue(result, string);
        CFRelease(string);
    }

    return result;
}
#elif DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED || DEPLOYMENT_TARGET_WINDOWS || DEPLOYMENT_TARGET_LINUX || DEPLOYMENT_TARGET_FREEBSD
static CFMutableArrayRef __CFCopyRecursiveDirectoryList() {
    CFMutableArrayRef result = CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks);
#if DEPLOYMENT_TARGET_WINDOWS
    if (!__tzDir) __InitTZStrings();
    if (!__tzDir) return result;
    int fd = open(__tzDir, O_RDONLY);
#else
    int fd = open(TZDIR "/zone.tab", O_RDONLY);
#endif

    for (; 0 <= fd;) {
        uint8_t buffer[4096];
        ssize_t len = read(fd, buffer, sizeof(buffer));
        if (len <= 0) break;
    if (len < sizeof(buffer)) {
        // assumes that partial read only occurs at the end of the file
        buffer[len] = '\n';
        len++;
    }
        const uint8_t *bytes = buffer;
        for (;;) {
        const uint8_t *nextl = memchr(bytes, '\n', len);
        if (!nextl) break;
        nextl++;
        if ('#' == *bytes) {
        len -= (nextl - bytes);
        bytes = nextl;
        continue;
        }
        const uint8_t *tab1 = memchr(bytes, '\t', (nextl - bytes));
        if (!tab1) {
        len -= (nextl - bytes);
        bytes = nextl;
        continue;
        }
        tab1++;
        len -= (tab1 - bytes);
        bytes = tab1; 
        const uint8_t *tab2 = memchr(bytes, '\t', (nextl - bytes));
        if (!tab2) {
        len -= (nextl - bytes);
        bytes = nextl;
        continue;
        }
        tab2++;
        len -= (tab2 - bytes);
        bytes = tab2; 
        const uint8_t *tab3 = memchr(bytes, '\t', (nextl - bytes));
        int nmlen = tab3 ? (tab3 - bytes) : (nextl - 1 - bytes);
        CFStringRef string = CFStringCreateWithBytes(kCFAllocatorSystemDefault, bytes, nmlen, kCFStringEncodingUTF8, false);
        CFArrayAppendValue(result, string);
        CFRelease(string);
        len -= (nextl - bytes);
        bytes = nextl;
        }
        lseek(fd, -len, SEEK_CUR);
    }
    close(fd);
    return result;
}
#else
#error Unknown or unspecified DEPLOYMENT_TARGET
#endif

#define BUFFER_SIZE 768

static UnicodeString __CFStringRefToUnicodeString(CFStringRef str) {
    UniChar buffer[BUFFER_SIZE];
    CFStringGetCharacters(str, CFRangeMake(0, CFStringGetLength(str)), buffer);
    return UnicodeString(reinterpret_cast<UChar*>(buffer), CFStringGetLength(str));
}

static CFStringRef __UnicodeStringToCFStringRef(UnicodeString str) {
    return (str.length() > 0) ? 
        CFStringCreateWithCharacters(kCFAllocatorDefault, reinterpret_cast<const UniChar*>(str.getBuffer()), str.length()) :
        CFSTR("");
}

struct __CFTimeZone {
    CFRuntimeBase _base;
    icu::LocalPointer<icu::BasicTimeZone> _timeZone;
    CFStringRef _name; /* immutable */
    CFDataRef _data;   /* immutable */
};

static CFTimeZoneRef __CFTimeZoneInitWithICU(CFTimeZoneRef ret, CFStringRef name, CFDataRef data) {
    icu::BasicTimeZone* timeZone = static_cast<icu::BasicTimeZone*>(
        icu::BasicTimeZone::createTimeZone(__CFStringRefToUnicodeString(name)));

    ((struct __CFTimeZone *)ret)->_timeZone.adoptInstead(timeZone);
    ((struct __CFTimeZone *)ret)->_name = CFStringCreateCopy(CFGetAllocator(ret), name);
    ((struct __CFTimeZone *)ret)->_data = data;

    return ret;
}

CF_INLINE UDate __CFAbsoluteTimeToUDate(CFAbsoluteTime time) {
    // UDate measures milliseconds since Jan 01, 1970
    // CFAbsoluteTime measures seconds since Jan 01, 2001
    return (time + kCFAbsoluteTimeIntervalSince1970) * 1000;
}

CF_INLINE CFAbsoluteTime __UDateToCFAbsoluteTime(UDate time) {
    // UDate measures milliseconds since Jan 01, 1970
    // CFAbsoluteTime measures seconds since Jan 01, 2001
    return time/1000 - kCFAbsoluteTimeIntervalSince1970;
}

static Boolean __CFTimeZoneEqual(CFTypeRef cf1, CFTypeRef cf2) {
    CFTimeZoneRef tz1 = (CFTimeZoneRef)cf1;
    CFTimeZoneRef tz2 = (CFTimeZoneRef)cf2;
    if (!CFEqual(CFTimeZoneGetName(tz1), CFTimeZoneGetName(tz2))) return false;
    if (!CFEqual(CFTimeZoneGetData(tz1), CFTimeZoneGetData(tz2))) return false;
    return true;
}

static CFHashCode __CFTimeZoneHash(CFTypeRef cf) {
    CFTimeZoneRef tz = (CFTimeZoneRef)cf;
    return CFHash(CFTimeZoneGetName(tz));
}

static CFStringRef __CFTimeZoneCopyDescription(CFTypeRef cf) {
    CFTimeZoneRef tz = (CFTimeZoneRef)cf;
    CFStringRef result, abbrev;
    CFAbsoluteTime at;
    at = CFAbsoluteTimeGetCurrent();
    abbrev = CFTimeZoneCopyAbbreviation(tz, at);
    result = CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CFTimeZone %p [%p]>{name = %@; abbreviation = %@; GMT offset = %g; is DST = %s}"), cf, CFGetAllocator(tz), tz->_name, abbrev, CFTimeZoneGetSecondsFromGMT(tz, at), CFTimeZoneIsDaylightSavingTime(tz, at) ? "true" : "false");
    CFRelease(abbrev);
    return result;
}

static void __CFTimeZoneDeallocate(CFTypeRef cf) {
    CFTimeZoneRef tz = (CFTimeZoneRef)cf;
    CFAllocatorRef allocator = CFGetAllocator(tz);
    CFIndex idx;
    if (tz->_name) CFRelease(tz->_name);
    if (tz->_data) CFRelease(tz->_data);
}

static CFTypeID __kCFTimeZoneTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CFTimeZoneClass = {
    0,
    "CFTimeZone",
    NULL,   // init
    NULL,   // copy
    __CFTimeZoneDeallocate,
    __CFTimeZoneEqual,
    __CFTimeZoneHash,
    NULL,   //
    __CFTimeZoneCopyDescription
};

CFTypeID CFTimeZoneGetTypeID(void) {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce, ^{ __kCFTimeZoneTypeID = _CFRuntimeRegisterClass(&__CFTimeZoneClass); });
    return __kCFTimeZoneTypeID;
}

#if DEPLOYMENT_TARGET_WINDOWS
static const char *__CFTimeZoneWinToOlsonDefaults =
/* Mappings to time zones in Windows Registry are best-guess */
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
" <!DOCTYPE plist SYSTEM \"file://localhost/System/Library/DTDs/PropertyList.dtd\">"
" <plist version=\"1.0\">"
" <dict>"
"    <key>Afghanistan</key>                 <string>Asia/Kabul</string>"
"    <key>Afghanistan Standard Time</key>   <string>Asia/Kabul</string>"
"    <key>Alaskan</key>                     <string>America/Anchorage</string>"
"    <key>Alaskan Standard Time</key>       <string>America/Anchorage</string>"
"    <key>Arab</key>                        <string>Asia/Riyadh</string>"
"    <key>Arab Standard Time</key>          <string>Asia/Riyadh</string>"
"    <key>Arabian</key>                     <string>Asia/Muscat</string>"
"    <key>Arabian Standard Time</key>       <string>Asia/Muscat</string>"
"    <key>Arabic Standard Time</key>        <string>Asia/Baghdad</string>"
"    <key>Atlantic</key>                    <string>America/Halifax</string>"
"    <key>Atlantic Standard Time</key>      <string>America/Halifax</string>"
"    <key>AUS Central</key>                 <string>Australia/Darwin</string>"
"    <key>AUS Central Standard Time</key>   <string>Australia/Darwin</string>"
"    <key>AUS Eastern</key>                 <string>Australia/Sydney</string>"
"    <key>AUS Eastern Standard Time</key>   <string>Australia/Sydney</string>"
"    <key>Azerbaijan Standard Time</key>    <string>Asia/Baku</string>"
"    <key>Azores</key>                      <string>Atlantic/Azores</string>"
"    <key>Azores Standard Time</key>        <string>Atlantic/Azores</string>"
"    <key>Bangkok</key>                     <string>Asia/Bangkok</string>"
"    <key>Bangkok Standard Time</key>       <string>Asia/Bangkok</string>"
"    <key>Beijing</key>                     <string>Asia/Shanghai</string>"
"    <key>Canada Central</key>              <string>America/Regina</string>"
"    <key>Canada Central Standard Time</key> <string>America/Regina</string>"
"    <key>Cape Verde Standard Time</key>    <string>Atlantic/Cape_Verde</string>"
"    <key>Caucasus</key>                    <string>Asia/Yerevan</string>"
"    <key>Caucasus Standard Time</key>      <string>Asia/Yerevan</string>"
"    <key>Cen. Australia</key>              <string>Australia/Adelaide</string>"
"    <key>Cen. Australia Standard Time</key> <string>Australia/Adelaide</string>"
"    <key>Central</key>                     <string>America/Chicago</string>"
"    <key>Central America Standard Time</key> <string>America/Regina</string>"
"    <key>Central Asia</key>                <string>Asia/Dhaka</string>"
"    <key>Central Asia Standard Time</key>  <string>Asia/Dhaka</string>"
"    <key>Central Brazilian Standard Time</key> <string>America/Manaus</string>"
"    <key>Central Europe</key>              <string>Europe/Prague</string>"
"    <key>Central Europe Standard Time</key> <string>Europe/Prague</string>"
"    <key>Central European</key>            <string>Europe/Belgrade</string>"
"    <key>Central European Standard Time</key>  <string>Europe/Belgrade</string>"
"    <key>Central Pacific</key>             <string>Pacific/Guadalcanal</string>"
"    <key>Central Pacific Standard Time</key>   <string>Pacific/Guadalcanal</string>"
"    <key>Central Standard Time</key>       <string>America/Chicago</string>"
"    <key>Central Standard Time (Mexico)</key> <string>America/Mexico_City</string>"
"    <key>China</key>                       <string>Asia/Shanghai</string>"
"    <key>China Standard Time</key>         <string>Asia/Shanghai</string>"
"    <key>Dateline</key>                    <string>GMT-1200</string>"
"    <key>Dateline Standard Time</key>      <string>GMT-1200</string>"
"    <key>E. Africa</key>                   <string>Africa/Nairobi</string>"
"    <key>E. Africa Standard Time</key>     <string>Africa/Nairobi</string>"
"    <key>E. Australia</key>                <string>Australia/Brisbane</string>"
"    <key>E. Australia Standard Time</key>  <string>Australia/Brisbane</string>"
"    <key>E. Europe</key>                   <string>Europe/Minsk</string>"
"    <key>E. Europe Standard Time</key>     <string>Europe/Minsk</string>"
"    <key>E. South America</key>            <string>America/Sao_Paulo</string>"
"    <key>E. South America Standard Time</key>  <string>America/Sao_Paulo</string>"
"    <key>Eastern</key>                     <string>America/New_York</string>"
"    <key>Eastern Standard Time</key>       <string>America/New_York</string>"
"    <key>Egypt</key>       <string>Africa/Cairo</string>"
"    <key>Egypt Standard Time</key> <string>Africa/Cairo</string>"
"    <key>Ekaterinburg</key>                <string>Asia/Yekaterinburg</string>"
"    <key>Ekaterinburg Standard Time</key>  <string>Asia/Yekaterinburg</string>"
"    <key>Fiji</key>    <string>Pacific/Fiji</string>"
"    <key>Fiji Standard Time</key>  <string>Pacific/Fiji</string>"
"    <key>FLE</key> <string>Europe/Helsinki</string>"
"    <key>FLE Standard Time</key>   <string>Europe/Helsinki</string>"
"    <key>Georgian Standard Time</key>  <string>Asia/Tbilisi</string>"
"    <key>GFT</key> <string>Europe/Athens</string>"
"    <key>GFT Standard Time</key>   <string>Europe/Athens</string>"
"    <key>GMT</key> <string>Europe/London</string>"
"    <key>GMT Standard Time</key>   <string>Europe/London</string>"
"    <key>Greenland Standard Time</key> <string>America/Godthab</string>"
"    <key>Greenwich</key>   <string>GMT</string>"
"    <key>Greenwich Standard Time</key> <string>GMT</string>"
"    <key>GTB</key> <string>Europe/Athens</string>"
"    <key>GTB Standard Time</key>   <string>Europe/Athens</string>"
"    <key>Hawaiian</key>    <string>Pacific/Honolulu</string>"
"    <key>Hawaiian Standard Time</key>  <string>Pacific/Honolulu</string>"
"    <key>India</key>   <string>Asia/Calcutta</string>"
"    <key>India Standard Time</key> <string>Asia/Calcutta</string>"
"    <key>Iran</key>    <string>Asia/Tehran</string>"
"    <key>Iran Standard Time</key>  <string>Asia/Tehran</string>"
"    <key>Israel</key>  <string>Asia/Jerusalem</string>"
"    <key>Israel Standard Time</key>    <string>Asia/Jerusalem</string>"
"    <key>Jordan Standard Time</key>    <string>Asia/Amman</string>"
"    <key>Korea</key>   <string>Asia/Seoul</string>"
"    <key>Korea Standard Time</key> <string>Asia/Seoul</string>"
"    <key>Mexico</key>  <string>America/Mexico_City</string>"
"    <key>Mexico Standard Time</key>    <string>America/Mexico_City</string>"
"    <key>Mexico Standard Time 2</key>  <string>America/Chihuahua</string>"
"    <key>Mid-Atlantic</key>    <string>Atlantic/South_Georgia</string>"
"    <key>Mid-Atlantic Standard Time</key>  <string>Atlantic/South_Georgia</string>"
"    <key>Middle East Standard Time</key>   <string>Asia/Beirut</string>"
"    <key>Mountain</key>    <string>America/Denver</string>"
"    <key>Mountain Standard Time</key>  <string>America/Denver</string>"
"    <key>Mountain Standard Time (Mexico)</key> <string>America/Chihuahua</string>"
"    <key>Myanmar Standard Time</key>   <string>Asia/Rangoon</string>"
"    <key>N. Central Asia Standard Time</key>   <string>Asia/Novosibirsk</string>"
"    <key>Namibia Standard Time</key>   <string>Africa/Windhoek</string>"
"    <key>Nepal Standard Time</key> <string>Asia/Katmandu</string>"
"    <key>New Zealand</key> <string>Pacific/Auckland</string>"
"    <key>New Zealand Standard Time</key>   <string>Pacific/Auckland</string>"
"    <key>Newfoundland</key>    <string>America/St_Johns</string>"
"    <key>Newfoundland Standard Time</key>  <string>America/St_Johns</string>"
"    <key>North Asia East Standard Time</key>   <string>Asia/Ulaanbaatar</string>"
"    <key>North Asia Standard Time</key>    <string>Asia/Krasnoyarsk</string>"
"    <key>Pacific</key> <string>America/Los_Angeles</string>"
"    <key>Pacific SA</key>  <string>America/Santiago</string>"
"    <key>Pacific SA Standard Time</key>    <string>America/Santiago</string>"
"    <key>Pacific Standard Time</key>   <string>America/Los_Angeles</string>"
"    <key>Pacific Standard Time (Mexico)</key>  <string>America/Tijuana</string>"
"    <key>Prague Bratislava</key>   <string>Europe/Prague</string>"
"    <key>Romance</key> <string>Europe/Paris</string>"
"    <key>Romance Standard Time</key>   <string>Europe/Paris</string>"
"    <key>Russian</key> <string>Europe/Moscow</string>"
"    <key>Russian Standard Time</key>   <string>Europe/Moscow</string>"
"    <key>SA Eastern</key>  <string>America/Buenos_Aires</string>"
"    <key>SA Eastern Standard Time</key>    <string>America/Buenos_Aires</string>"
"    <key>SA Pacific</key>  <string>America/Bogota</string>"
"    <key>SA Pacific Standard Time</key>    <string>America/Bogota</string>"
"    <key>SA Western</key>  <string>America/Caracas</string>"
"    <key>SA Western Standard Time</key>    <string>America/Caracas</string>"
"    <key>Samoa</key>   <string>Pacific/Apia</string>"
"    <key>Samoa Standard Time</key> <string>Pacific/Apia</string>"
"    <key>Saudi Arabia</key>    <string>Asia/Riyadh</string>"
"    <key>Saudi Arabia Standard Time</key>  <string>Asia/Riyadh</string>"
"    <key>SE Asia Standard Time</key>   <string>Asia/Bangkok</string>"
"    <key>Singapore</key>   <string>Asia/Singapore</string>"
"    <key>Singapore Standard Time</key> <string>Asia/Singapore</string>"
"    <key>South Africa</key>    <string>Africa/Harare</string>"
"    <key>South Africa Standard Time</key>  <string>Africa/Harare</string>"
"    <key>Sri Lanka</key>   <string>Asia/Colombo</string>"
"    <key>Sri Lanka Standard Time</key> <string>Asia/Colombo</string>"
"    <key>Sydney Standard Time</key>    <string>Australia/Sydney</string>"
"    <key>Taipei</key>  <string>Asia/Taipei</string>"
"    <key>Taipei Standard Time</key>    <string>Asia/Taipei</string>"
"    <key>Tasmania</key>    <string>Australia/Hobart</string>"
"    <key>Tasmania Standard Time</key>  <string>Australia/Hobart</string>"
"    <key>Tasmania Standard Time</key>  <string>Australia/Hobart</string>"
"    <key>Tokyo</key>   <string>Asia/Tokyo</string>"
"    <key>Tokyo Standard Time</key> <string>Asia/Tokyo</string>"
"    <key>Tonga Standard Time</key> <string>Pacific/Tongatapu</string>"
"    <key>US Eastern</key>  <string>America/Indianapolis</string>"
"    <key>US Eastern Standard Time</key>    <string>America/Indianapolis</string>"
"    <key>US Mountain</key> <string>America/Phoenix</string>"
"    <key>US Mountain Standard Time</key>   <string>America/Phoenix</string>"
"    <key>Vladivostok</key> <string>Asia/Vladivostok</string>"
"    <key>Vladivostok Standard Time</key>   <string>Asia/Vladivostok</string>"
"    <key>W. Australia</key>    <string>Australia/Perth</string>"
"    <key>W. Australia Standard Time</key>  <string>Australia/Perth</string>"
"    <key>W. Central Africa Standard Time</key> <string>Africa/Luanda</string>"
"    <key>W. Europe</key>   <string>Europe/Berlin</string>"
"    <key>W. Europe Standard Time</key> <string>Europe/Berlin</string>"
"    <key>Warsaw</key>  <string>Europe/Warsaw</string>"
"    <key>West Asia</key>   <string>Asia/Karachi</string>"
"    <key>West Asia Standard Time</key> <string>Asia/Karachi</string>"
"    <key>West Pacific</key>    <string>Pacific/Guam</string>"
"    <key>West Pacific Standard Time</key>  <string>Pacific/Guam</string>"
"    <key>Western Brazilian Standard Time</key> <string>America/Rio_Branco</string>"
"    <key>Yakutsk</key> <string>Asia/Yakutsk</string>"
" </dict>"
" </plist>";

CF_INLINE void __CFTimeZoneLockWinToOlson(void) {
    __CFLock(&__CFTimeZoneWinToOlsonLock);
}

CF_INLINE void __CFTimeZoneUnlockWinToOlson(void) {
    __CFUnlock(&__CFTimeZoneWinToOlsonLock);
}

CFDictionaryRef CFTimeZoneCopyWinToOlsonDictionary(void) {
    CFDictionaryRef dict;
    __CFTimeZoneLockWinToOlson();
    if (NULL == __CFTimeZoneWinToOlsonDict) {
        CFDataRef data = CFDataCreate(kCFAllocatorSystemDefault, (uint8_t *)__CFTimeZoneWinToOlsonDefaults, strlen(__CFTimeZoneWinToOlsonDefaults));
        __CFTimeZoneWinToOlsonDict = (CFDictionaryRef)CFPropertyListCreateFromXMLData(kCFAllocatorSystemDefault, data, kCFPropertyListImmutable, NULL);
        CFRelease(data);
    }
    if (NULL == __CFTimeZoneWinToOlsonDict) {
        __CFTimeZoneWinToOlsonDict = CFDictionaryCreate(kCFAllocatorSystemDefault, NULL, NULL, 0, NULL, NULL);
    }
    dict = __CFTimeZoneWinToOlsonDict ? (CFDictionaryRef)CFRetain(__CFTimeZoneWinToOlsonDict) : NULL;
    __CFTimeZoneUnlockWinToOlson();
    return dict;
}

void CFTimeZoneSetWinToOlsonDictionary(CFDictionaryRef dict) {
    __CFGenericValidateType(dict, CFDictionaryGetTypeID());
    __CFTimeZoneLockWinToOlson();
    if (dict != __CFTimeZoneWinToOlsonDict) {
        if (dict) CFRetain(dict);
        if (__CFTimeZoneWinToOlsonDict) CFRelease(__CFTimeZoneWinToOlsonDict);
        __CFTimeZoneWinToOlsonDict = dict;
    }
    __CFTimeZoneUnlockWinToOlson();
}

CFTimeZoneRef CFTimeZoneCreateWithWindowsName(CFAllocatorRef allocator, CFStringRef winName) {
    if (!winName) return NULL;
    
    CFDictionaryRef winToOlson = CFTimeZoneCopyWinToOlsonDictionary();
    if (!winToOlson) return NULL;
    
    CFStringRef olsonName = static_cast<CFStringRef>(CFDictionaryGetValue(winToOlson, winName));
    CFTimeZoneRef retval = NULL;
    if (olsonName) {
         retval = CFTimeZoneCreateWithName(allocator, olsonName, false);
    }
    CFRelease(winToOlson);
    return retval;
}

// WINOBJC: This is supposed to return the path to the time zone info files. For WinObjC that is the executable dir.
// extern CFStringRef _CFGetWindowsAppleSystemLibraryDirectory(void);
CFStringRef _CFGetWindowsAppleSystemLibraryDirectory(void) {
    static const wchar_t* dllPath = _CFDLLPath();
    static const CFStringRef toReturn = CFStringCreateWithCharacters(nullptr, reinterpret_cast<const UniChar*>(dllPath), wcsnlen_s(dllPath, MAX_PATH));
    return toReturn;
}

#endif

static CFTimeZoneRef __CFTimeZoneCreateSystem(void) {
    CFTimeZoneRef result = NULL;
    
    CFStringRef name = NULL;
    
#if DEPLOYMENT_TARGET_WINDOWS
    TIME_ZONE_INFORMATION tzi = { 0 };
    DWORD rval = GetTimeZoneInformation(&tzi);
    if (rval != TIME_ZONE_ID_INVALID) {
        LPWSTR standardName = (LPWSTR)&tzi.StandardName;
        CFStringRef cfStandardName = CFStringCreateWithBytes(kCFAllocatorSystemDefault, (UInt8 *)standardName, wcslen(standardName)*sizeof(WCHAR), kCFStringEncodingUTF16LE, false);
        if (cfStandardName) {
            CFDictionaryRef winToOlson = CFTimeZoneCopyWinToOlsonDictionary();
            if (winToOlson) {
                name = static_cast<CFStringRef>(CFDictionaryGetValue(winToOlson, cfStandardName));
                if (name) CFRetain(name);
                CFRelease(winToOlson);
            }
            CFRelease(cfStandardName);
        }
    } else {
        CFLog(kCFLogLevelError, CFSTR("Couldn't get time zone information error %d"), GetLastError());
    }
#else
    const char *tzenv;
    int ret;
    char linkbuf[CFMaxPathSize];
    
    tzenv = __CFgetenv("TZFILE");
    if (NULL != tzenv) {
        CFStringRef name = CFStringCreateWithBytes(kCFAllocatorSystemDefault, (uint8_t *)tzenv, strlen(tzenv), kCFStringEncodingUTF8, false);
        result = CFTimeZoneCreateWithName(kCFAllocatorSystemDefault, name, false);
        CFRelease(name);
        if (result) return result;
    }
    tzenv = __CFgetenv("TZ");
    if (NULL != tzenv) {
        CFStringRef name = CFStringCreateWithBytes(kCFAllocatorSystemDefault, (uint8_t *)tzenv, strlen(tzenv), kCFStringEncodingUTF8, false);
        result = CFTimeZoneCreateWithName(kCFAllocatorSystemDefault, name, true);
        CFRelease(name);
        if (result) return result;
    }
    ret = readlink(TZZONELINK, linkbuf, sizeof(linkbuf));
    if (0 < ret) {
        linkbuf[ret] = '\0';
        if (strncmp(linkbuf, TZZONEINFO, sizeof(TZZONEINFO) - 1) == 0) {
            name = CFStringCreateWithBytes(kCFAllocatorSystemDefault, (uint8_t *)linkbuf + sizeof(TZZONEINFO) - 1, strlen(linkbuf) - sizeof(TZZONEINFO) + 1, kCFStringEncodingUTF8, false);
        } else {
            name = CFStringCreateWithBytes(kCFAllocatorSystemDefault, (uint8_t *)linkbuf, strlen(linkbuf), kCFStringEncodingUTF8, false);
        }
    } else {
        // TODO: This can still fail on Linux if the time zone is not recognized by ICU later
        // Try localtime
        tzset();
        time_t t = time(NULL);
        struct tm lt = {0};
        localtime_r(&t, &lt);
        
        name = CFStringCreateWithCString(kCFAllocatorSystemDefault, lt.tm_zone, kCFStringEncodingUTF8);
    }
#endif
    if (name) {
        result = CFTimeZoneCreateWithName(kCFAllocatorSystemDefault, name, false);
        CFRelease(name);
        if (result) return result;
    }
    return CFTimeZoneCreateWithTimeIntervalFromGMT(kCFAllocatorSystemDefault, 0.0);
}

CFTimeZoneRef CFTimeZoneCopySystem(void) {
    CFTimeZoneRef tz;
    __CFTimeZoneLockGlobal();
    if (NULL == __CFTimeZoneSystem) {
    __CFTimeZoneUnlockGlobal();
    tz = __CFTimeZoneCreateSystem();
    __CFTimeZoneLockGlobal();
    if (NULL == __CFTimeZoneSystem) {
        __CFTimeZoneSystem = tz;
    } else {
        if (tz) CFRelease(tz);
    }
    }
    tz = __CFTimeZoneSystem ? (CFTimeZoneRef)CFRetain(__CFTimeZoneSystem) : NULL;
    __CFTimeZoneUnlockGlobal();
    return tz;
}

static CFIndex __noteCount = 0;

void CFTimeZoneResetSystem(void) {
    __CFTimeZoneLockGlobal();
    if (__CFTimeZoneDefault == __CFTimeZoneSystem) {
    if (__CFTimeZoneDefault) CFRelease(__CFTimeZoneDefault);
    __CFTimeZoneDefault = NULL;
    }
    CFTimeZoneRef tz = __CFTimeZoneSystem;
    __CFTimeZoneSystem = NULL;
    __CFTimeZoneUnlockGlobal();
    if (tz) CFRelease(tz);
}

CFIndex _CFTimeZoneGetNoteCount(void) {
    return __noteCount;
}

CFTimeZoneRef CFTimeZoneCopyDefault(void) {
    CFTimeZoneRef tz;
    __CFTimeZoneLockGlobal();
    if (NULL == __CFTimeZoneDefault) {
    __CFTimeZoneUnlockGlobal();
    tz = CFTimeZoneCopySystem();
    __CFTimeZoneLockGlobal();
    if (NULL == __CFTimeZoneDefault) {
        __CFTimeZoneDefault = tz;
    } else {
        if (tz) CFRelease(tz);
    }
    }
    tz = __CFTimeZoneDefault ? (CFTimeZoneRef)CFRetain(__CFTimeZoneDefault) : NULL;
    __CFTimeZoneUnlockGlobal();
    return tz;
}

void CFTimeZoneSetDefault(CFTimeZoneRef tz) {
    if (tz) __CFGenericValidateType(tz, CFTimeZoneGetTypeID());
    __CFTimeZoneLockGlobal();
    if (tz != __CFTimeZoneDefault) {
    if (tz) CFRetain(tz);
    if (__CFTimeZoneDefault) CFRelease(__CFTimeZoneDefault);
    __CFTimeZoneDefault = tz;
    }
    __CFTimeZoneUnlockGlobal();
}

static CFDictionaryRef __CFTimeZoneCopyCompatibilityDictionary(void);

CFArrayRef CFTimeZoneCopyKnownNames(void) {
    CFArrayRef tzs;
    __CFTimeZoneLockGlobal();
    if (NULL == __CFKnownTimeZoneList) {
    CFMutableArrayRef list;
/* TimeZone information locate in the registry for Win32
 * (Aleksey Dukhnyakov)
 */
 #if DEPLOYMENT_TARGET_WINDOWS
        list = __CFCopyWindowsTimeZoneList();
#else
        list = __CFCopyRecursiveDirectoryList();
#endif
    // Remove undesirable ancient cruft
    CFDictionaryRef dict = __CFTimeZoneCopyCompatibilityDictionary();
    CFIndex idx;
    for (idx = CFArrayGetCount(list); idx--; ) {
        CFStringRef item = (CFStringRef)CFArrayGetValueAtIndex(list, idx);
        if (CFDictionaryContainsKey(dict, item)) {
        CFArrayRemoveValueAtIndex(list, idx);
        }
    }
    __CFKnownTimeZoneList = CFArrayCreateCopy(kCFAllocatorSystemDefault, list);
    CFRelease(list);
    }
    tzs = __CFKnownTimeZoneList ? (CFArrayRef)CFRetain(__CFKnownTimeZoneList) : NULL;
    __CFTimeZoneUnlockGlobal();
    return tzs;
}

/* The criteria here are sort of: coverage for the U.S. and Europe,
 * large cities, abbreviation uniqueness, and perhaps a few others.
 * But do not make the list too large with obscure information.
 */
static const char *__CFTimeZoneAbbreviationDefaults =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
" <!DOCTYPE plist SYSTEM \"file://localhost/System/Library/DTDs/PropertyList.dtd\">"
" <plist version=\"1.0\">"
" <dict>"
"    <key>ADT</key>  <string>America/Halifax</string>"
"    <key>AKDT</key> <string>America/Juneau</string>"
"    <key>AKST</key> <string>America/Juneau</string>"
"    <key>ART</key>  <string>America/Argentina/Buenos_Aires</string>"
"    <key>AST</key>  <string>America/Halifax</string>"
"    <key>BDT</key>  <string>Asia/Dhaka</string>"
"    <key>BRST</key> <string>America/Sao_Paulo</string>"
"    <key>BRT</key>  <string>America/Sao_Paulo</string>"
"    <key>BST</key>  <string>Europe/London</string>"
"    <key>CAT</key>  <string>Africa/Harare</string>"
"    <key>CDT</key>  <string>America/Chicago</string>"
"    <key>CEST</key> <string>Europe/Paris</string>"
"    <key>CET</key>  <string>Europe/Paris</string>"
"    <key>CLST</key> <string>America/Santiago</string>"
"    <key>CLT</key>  <string>America/Santiago</string>"
"    <key>COT</key>  <string>America/Bogota</string>"
"    <key>CST</key>  <string>America/Chicago</string>"
"    <key>EAT</key>  <string>Africa/Addis_Ababa</string>"
"    <key>EDT</key>  <string>America/New_York</string>"
"    <key>EEST</key> <string>Europe/Istanbul</string>"
"    <key>EET</key>  <string>Europe/Istanbul</string>"
"    <key>EST</key>  <string>America/New_York</string>"
"    <key>GMT</key>  <string>GMT</string>"
"    <key>GST</key>  <string>Asia/Dubai</string>"
"    <key>HKT</key>  <string>Asia/Hong_Kong</string>"
"    <key>HST</key>  <string>Pacific/Honolulu</string>"
"    <key>ICT</key>  <string>Asia/Bangkok</string>"
"    <key>IRST</key> <string>Asia/Tehran</string>"
"    <key>IST</key>  <string>Asia/Calcutta</string>"
"    <key>JST</key>  <string>Asia/Tokyo</string>"
"    <key>KST</key>  <string>Asia/Seoul</string>"
"    <key>MDT</key>  <string>America/Denver</string>"
"    <key>MSD</key>  <string>Europe/Moscow</string>"
"    <key>MSK</key>  <string>Europe/Moscow</string>"
"    <key>MST</key>  <string>America/Denver</string>"
"    <key>NZDT</key> <string>Pacific/Auckland</string>"
"    <key>NZST</key> <string>Pacific/Auckland</string>"
"    <key>PDT</key>  <string>America/Los_Angeles</string>"
"    <key>PET</key>  <string>America/Lima</string>"
"    <key>PHT</key>  <string>Asia/Manila</string>"
"    <key>PKT</key>  <string>Asia/Karachi</string>"
"    <key>PST</key>  <string>America/Los_Angeles</string>"
"    <key>SGT</key>  <string>Asia/Singapore</string>"
"    <key>UTC</key>  <string>UTC</string>"
"    <key>WAT</key>  <string>Africa/Lagos</string>"
"    <key>WEST</key> <string>Europe/Lisbon</string>"
"    <key>WET</key>  <string>Europe/Lisbon</string>"
"    <key>WIT</key>  <string>Asia/Jakarta</string>"
" </dict>"
" </plist>";

CFDictionaryRef CFTimeZoneCopyAbbreviationDictionary(void) {
    CFDictionaryRef dict;
    __CFTimeZoneLockAbbreviations();
    if (NULL == __CFTimeZoneAbbreviationDict) {
    CFDataRef data = CFDataCreate(kCFAllocatorSystemDefault, (uint8_t *)__CFTimeZoneAbbreviationDefaults, strlen(__CFTimeZoneAbbreviationDefaults));
    __CFTimeZoneAbbreviationDict = (CFDictionaryRef)CFPropertyListCreateFromXMLData(kCFAllocatorSystemDefault, data, kCFPropertyListImmutable, NULL);
    CFRelease(data);
    }
    if (NULL == __CFTimeZoneAbbreviationDict) {
    __CFTimeZoneAbbreviationDict = CFDictionaryCreate(kCFAllocatorSystemDefault, NULL, NULL, 0, NULL, NULL);
    }
    dict = __CFTimeZoneAbbreviationDict ? (CFDictionaryRef)CFRetain(__CFTimeZoneAbbreviationDict) : NULL;
    __CFTimeZoneUnlockAbbreviations();
    return dict;
}

void _removeFromCache(const void *key, const void *value, void *context) {
    CFDictionaryRemoveValue(__CFTimeZoneCache, (CFStringRef)key);
}

void CFTimeZoneSetAbbreviationDictionary(CFDictionaryRef dict) {
    __CFGenericValidateType(dict, CFDictionaryGetTypeID());
    __CFTimeZoneLockGlobal();
    if (dict != __CFTimeZoneAbbreviationDict) {
    if (dict) CFRetain(dict);
    if (__CFTimeZoneAbbreviationDict) {
        CFDictionaryApplyFunction(__CFTimeZoneAbbreviationDict, _removeFromCache, NULL);
        CFRelease(__CFTimeZoneAbbreviationDict);
    }
    __CFTimeZoneAbbreviationDict = dict;
    }
    __CFTimeZoneUnlockGlobal();
}
    
CF_INLINE const UChar *STRING_to_UTF16(CFStringRef S) { // UTF16String
    CFIndex length = CFStringGetLength((CFStringRef)S);
    UChar *buffer = (UChar *)malloc((length + 1) * sizeof(UChar));
    CFStringGetBytes((CFStringRef)(S), CFRangeMake(0, CFStringGetLength((CFStringRef)S)), kCFStringEncodingUTF16, 0, false, (UInt8 *)buffer, length * sizeof(UChar), NULL);
    buffer[length] = 0;
    return buffer;
}

CF_INLINE void FREE_STRING_to_UTF16(const UChar *buf) {
    free((void *)buf);
}

static int32_t __tryParseGMTName(CFStringRef name) {
    CFIndex len = CFStringGetLength(name);
    if (len < 3 || 9 < len) return -1;
    UniChar ustr[10];
    CFStringGetCharacters(name, CFRangeMake(0, len), ustr);
    ustr[len] = 0;
    
    // GMT, GMT{+|-}HH, GMT{+|-}HHMM, GMT{+|-}{H|HH}{:|.}MM
    // UTC, UTC{+|-}HH, UTC{+|-}HHMM, UTC{+|-}{H|HH}{:|.}MM
    //   where "00" <= HH <= "18", "00" <= MM <= "59", and if HH==18, then MM must == 00
    
    Boolean isGMT = ('G' == ustr[0] && 'M' == ustr[1] && 'T' == ustr[2]);
    Boolean isUTC = ('U' == ustr[0] && 'T' == ustr[1] && 'C' == ustr[2]);
    if (!isGMT && !isUTC) return -1;
    if (3 == len) return 0;
    
    if (len < 6) return -1;
    if (!('+' == ustr[3] || '-' == ustr[3])) return -1;
    if (!('0' <= ustr[4] && ustr[4] <= '9')) return -1;
    Boolean twoHourDigits = ('0' <= ustr[5] && ustr[5] <= '9');
    Boolean fiveIsPunct = (':' == ustr[5] || '.' == ustr[5]);
    if (!(twoHourDigits || fiveIsPunct)) return -1;
    
    int32_t hours = twoHourDigits ? (10 * (ustr[4] - '0') + (ustr[5] - '0')) : (ustr[4] - '0');
    if (18 < hours) return -1;
    if (twoHourDigits && 6 == len) return (('-' == ustr[3]) ? -1 : 1) * hours * 3600; // GMT{+|-}HH
    
    if (len < 8) return -1;
    Boolean sixIsDigit = ('0' <= ustr[6] && ustr[6] <= '5');
    Boolean sixIsPunct = (':' == ustr[6] || '.' == ustr[6]);
    if (!(sixIsDigit && 8 == len) && !(sixIsPunct && 9 == len)) return -1;
    
    CFIndex minIdx = len - 2;
    UniChar minDig1 = ustr[minIdx], minDig2 = ustr[minIdx + 1];
    if (!('0' <= minDig1 && minDig1 <= '5' && '0' <= minDig2 && minDig2 <= '9')) return -1;
    int32_t minutes = 10 * (minDig1 - '0') + (minDig2 - '0');
    if (18 == hours && 0 != minutes) return -1;
    
    return (('-' == ustr[3]) ? -1 : 1) * (hours * 3600 + minutes * 60);
}
    
static Boolean __nameStringOK(CFStringRef name) {
    int32_t offset = __tryParseGMTName(name);
    if (-1 != offset) return true;
    const UChar *ustr = STRING_to_UTF16(name);
    int32_t len = u_strlen(ustr);
    UErrorCode status = U_ZERO_ERROR;
    // In Leopard and beyond, we do not show obsolete zone names in the known
    // zones list, but if you name a zone explicitly, we have always allowed
    // you to create a time zone with that name if we have data for it.
    UBool isSystemID = false;
    UChar ubuffer[1024];
    int32_t res = ucal_getCanonicalTimeZoneID(ustr, len, ubuffer, 1024, &isSystemID, &status);
    FREE_STRING_to_UTF16(ustr);
    if (!U_SUCCESS(status) || !isSystemID || 1000 < res) {
        return false;
    }
    return true;
}

#if DEPLOYMENT_RUNTIME_SWIFT
    
static CFTimeZoneRef __CFTimeZoneInitFixed(CFTimeZoneRef result, int32_t seconds, CFStringRef name, int isDST) {
    CFDataRef data;
    int32_t nameLen = CFStringGetLength(name);
    unsigned char dataBytes[52 + nameLen + 1];
    memset(dataBytes, 0, sizeof(dataBytes));
    
    // Put in correct magic bytes for timezone structures
    dataBytes[0] = 'T';
    dataBytes[1] = 'Z';
    dataBytes[2] = 'i';
    dataBytes[3] = 'f';
    
    __CFEntzcode(1, dataBytes + 20);
    __CFEntzcode(1, dataBytes + 24);
    __CFEntzcode(1, dataBytes + 36);
    __CFEntzcode(nameLen + 1, dataBytes + 40);
    __CFEntzcode(seconds, dataBytes + 44);
    dataBytes[48] = isDST ? 1 : 0;
    CFStringGetCString(name, (char *)dataBytes + 50, nameLen + 1, kCFStringEncodingASCII);
    data = CFDataCreate(kCFAllocatorSystemDefault, dataBytes, 52 + nameLen + 1);
    result = _CFTimeZoneInit(result, name, data);
    CFRelease(data);
    return result;
}
    
Boolean _CFTimeZoneInitWithTimeIntervalFromGMT(CFTimeZoneRef result, CFTimeInterval ti) {

    CFStringRef name;
    int32_t seconds, minute, hour;
    if (ti < -18.0 * 3600 || 18.0 * 3600 < ti) return false;
    ti = (ti < 0.0) ? ceil((ti / 60.0) - 0.5) * 60.0 : floor((ti / 60.0) + 0.5) * 60.0;
    seconds = (int32_t)ti;
    hour = (ti < 0) ? (-seconds / 3600) : (seconds / 3600);
    seconds -= ((ti < 0) ? -hour : hour) * 3600;
    minute = (ti < 0) ? (-seconds / 60) : (seconds / 60);
    if (fabs(ti) < 1.0) {
        name = (CFStringRef)CFRetain(CFSTR("GMT"));
    } else {
        name = CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("GMT%c%02d%02d"), (ti < 0.0 ? '-' : '+'), hour, minute);
    }
    result = __CFTimeZoneInitFixed(result, (int32_t)ti, name, 0);
    CFRelease(name);
    return true;
}
    
Boolean _CFTimeZoneInit(CFTimeZoneRef timeZone, CFStringRef name, CFDataRef data) {
    if (name && __nameStringOK(name)) {
        if (data) {
            CFTZPeriod *tzp = NULL;
            CFIndex cnt = 0;
            __CFTimeZoneLockGlobal();
            if (__CFParseTimeZoneData(kCFAllocatorSystemDefault, data, &tzp, &cnt)) {
                __CFTimeZoneUnlockGlobal();
                
            } else {
                __CFTimeZoneUnlockGlobal();
                return false;
            }
            ((struct __CFTimeZone *)timeZone)->_name = (CFStringRef)CFStringCreateCopy(kCFAllocatorSystemDefault, name);
            ((struct __CFTimeZone *)timeZone)->_data = CFDataCreateCopy(kCFAllocatorSystemDefault, data);
            ((struct __CFTimeZone *)timeZone)->_periods = tzp;
            ((struct __CFTimeZone *)timeZone)->_periodCnt = cnt;
            return true;
        } else {
            CFStringRef tzName = NULL;
            CFDataRef data = NULL;
            
            CFIndex len = CFStringGetLength(name);
            if (6 == len || 8 == len) {
                UniChar buffer[8];
                CFStringGetCharacters(name, CFRangeMake(0, len), buffer);
                if ('G' == buffer[0] && 'M' == buffer[1] && 'T' == buffer[2] && ('+' == buffer[3] || '-' == buffer[3])) {
                    if (('0' <= buffer[4] && buffer[4] <= '9') && ('0' <= buffer[5] && buffer[5] <= '9')) {
                        int32_t hours = (buffer[4] - '0') * 10 + (buffer[5] - '0');
                        if (-14 <= hours && hours <= 14) {
                            CFTimeInterval ti = hours * 3600.0;
                            if (6 == len) {
                                return _CFTimeZoneInitWithTimeIntervalFromGMT(timeZone, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                            } else {
                                if (('0' <= buffer[6] && buffer[6] <= '9') && ('0' <= buffer[7] && buffer[7] <= '9')) {
                                    int32_t minutes = (buffer[6] - '0') * 10 + (buffer[7] - '0');
                                    if ((-14 == hours && 0 == minutes) || (14 == hours && 0 == minutes) || (0 <= minutes && minutes <= 59)) {
                                        ti = ti + minutes * 60.0;
                                        return _CFTimeZoneInitWithTimeIntervalFromGMT(timeZone, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Boolean tryAbbrev = true;
            CFURLRef baseURL, tempURL;
            void *bytes;
            CFIndex length;
            Boolean result = false;
            
#if DEPLOYMENT_TARGET_WINDOWS
            if (!__tzZoneInfo) __InitTZStrings();
            if (!__tzZoneInfo) return NULL;
            baseURL = CFURLCreateWithFileSystemPath(kCFAllocatorSystemDefault, __tzZoneInfo, kCFURLWindowsPathStyle, true);
#else
            baseURL = CFURLCreateWithFileSystemPath(kCFAllocatorSystemDefault, CFSTR(TZZONEINFO), kCFURLPOSIXPathStyle, true);
#endif
            if (tryAbbrev) {
                CFDictionaryRef abbrevs = CFTimeZoneCopyAbbreviationDictionary();
                tzName = CFDictionaryGetValue(abbrevs, name);
                if (NULL != tzName) {
                    tempURL = CFURLCreateCopyAppendingPathComponent(kCFAllocatorSystemDefault, baseURL, tzName, false);
                    if (NULL != tempURL) {
                        if (_CFReadBytesFromFile(kCFAllocatorSystemDefault, tempURL, &bytes, &length, 0, 0)) {
                            data = CFDataCreateWithBytesNoCopy(kCFAllocatorSystemDefault, bytes, length, kCFAllocatorSystemDefault);
                        }
                        CFRelease(tempURL);
                    }
                }
                CFRelease(abbrevs);
            }
            if (NULL == data) {
                CFDictionaryRef dict = __CFTimeZoneCopyCompatibilityDictionary();
                CFStringRef mapping = CFDictionaryGetValue(dict, name);
                if (mapping) {
                    name = mapping;
#if DEPLOYMENT_TARGET_WINDOWS
                } else if (CFStringHasPrefix(name, __tzZoneInfo)) {
                    CFMutableStringRef unprefixed = CFStringCreateMutableCopy(kCFAllocatorSystemDefault, CFStringGetLength(name), name);
                    CFStringDelete(unprefixed, CFRangeMake(0, CFStringGetLength(__tzZoneInfo)));
#else
                } else if (CFStringHasPrefix(name, CFSTR(TZZONEINFO))) {
                    CFMutableStringRef unprefixed = CFStringCreateMutableCopy(kCFAllocatorSystemDefault, CFStringGetLength(name), name);
                    CFStringDelete(unprefixed, CFRangeMake(0, sizeof(TZZONEINFO)));
#endif
                    mapping = CFDictionaryGetValue(dict, unprefixed);
                    if (mapping) {
                        name = mapping;
                    }
                    CFRelease(unprefixed);
                }
                CFRelease(dict);
                if (CFEqual(CFSTR(""), name)) {
                    return false;
                }
            }
            if (NULL == data) {
                tzName = name;
                tempURL = CFURLCreateCopyAppendingPathComponent(kCFAllocatorSystemDefault, baseURL, tzName, false);
                if (NULL != tempURL) {
                    if (_CFReadBytesFromFile(kCFAllocatorSystemDefault, tempURL, &bytes, &length, 0, 0)) {
                        data = CFDataCreateWithBytesNoCopy(kCFAllocatorSystemDefault, bytes, length, kCFAllocatorSystemDefault);
                    }
                    CFRelease(tempURL);
                }
            }
            CFRelease(baseURL);
            if (NULL != data) {
                result = _CFTimeZoneInit(timeZone, tzName, data);
                CFRelease(data);
            }
            return result;
        }
    }
    return false;
}
#endif
    
CFTimeZoneRef CFTimeZoneCreate(CFAllocatorRef allocator, CFStringRef name, CFDataRef data) {
// assert:    (NULL != name && NULL != data);
    CFTimeZoneRef memory;
    uint32_t size;
    CFIndex idx, cnt = 0;

    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    __CFGenericValidateType(name, CFStringGetTypeID());
    __CFGenericValidateType(data, CFDataGetTypeID());

    if (!name || !__nameStringOK(name)) {
        return NULL;
    }

    __CFTimeZoneLockGlobal();
    if (NULL != __CFTimeZoneCache && CFDictionaryGetValueIfPresent(__CFTimeZoneCache, name, (const void **)&memory)) {
        __CFTimeZoneUnlockGlobal();
        return (CFTimeZoneRef)CFRetain(memory);
    }
    size = sizeof(struct __CFTimeZone) - sizeof(CFRuntimeBase);
    memory = (CFTimeZoneRef)_CFRuntimeCreateInstance(allocator, CFTimeZoneGetTypeID(), size, NULL);
    if (NULL == memory) {
        __CFTimeZoneUnlockGlobal();
        return NULL;
    }
    __CFTimeZoneInitWithICU(((struct __CFTimeZone *)memory), name, data);
    if (NULL == __CFTimeZoneCache) {
        __CFTimeZoneCache = CFDictionaryCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    }
    CFDictionaryAddValue(__CFTimeZoneCache, ((struct __CFTimeZone *)memory)->_name, memory);
    __CFTimeZoneUnlockGlobal();
    return memory;
}

// rounds offset to nearest minute
CFTimeZoneRef CFTimeZoneCreateWithTimeIntervalFromGMT(CFAllocatorRef allocator, CFTimeInterval ti) {
    CFTimeZoneRef result;
    CFStringRef name;
    int32_t seconds, minute, hour;
    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    if (ti < -18.0 * 3600 || 18.0 * 3600 < ti) return NULL;
    ti = (ti < 0.0) ? ceil((ti / 60.0) - 0.5) * 60.0 : floor((ti / 60.0) + 0.5) * 60.0;
    seconds = (int32_t)ti;
    hour = (ti < 0) ? (-seconds / 3600) : (seconds / 3600);
    seconds -= ((ti < 0) ? -hour : hour) * 3600;
    minute = (ti < 0) ? (-seconds / 60) : (seconds / 60);
    if (fabs(ti) < 1.0) {
    name = (CFStringRef)CFRetain(CFSTR("GMT"));
    } else {
    name = CFStringCreateWithFormat(allocator, NULL, CFSTR("GMT%c%02d%02d"), (ti < 0.0 ? '-' : '+'), hour, minute);
    }
    result = CFTimeZoneCreate(allocator, name, nullptr);
    CFRelease(name);
    return result;
}

CFTimeZoneRef CFTimeZoneCreateWithName(CFAllocatorRef allocator, CFStringRef name, Boolean tryAbbrev) {
    CFTimeZoneRef result = NULL;
    CFStringRef tzName = NULL;
    CFDataRef data = NULL;

    if (allocator == NULL) allocator = __CFGetDefaultAllocator();
    __CFGenericValidateType(allocator, CFAllocatorGetTypeID());
    __CFGenericValidateType(name, CFStringGetTypeID());
    if (CFEqual(CFSTR(""), name)) {
    // empty string is not a time zone name, just abort now,
    // following stuff will fail anyway
    return NULL;
    }
    __CFTimeZoneLockGlobal();
    if (!tryAbbrev && (NULL != __CFTimeZoneCache) && (CFDictionaryGetValueIfPresent(__CFTimeZoneCache, name, (const void **)&result))) {
    __CFTimeZoneUnlockGlobal();
    return (CFTimeZoneRef)CFRetain(result);
    }
    __CFTimeZoneUnlockGlobal();
    CFIndex len = CFStringGetLength(name);
    // Check for GMT timezone names
    // GMT timezone names must follow a specific format
    if (6 == len || 8 == len || 9 == len) {
        UniChar buffer[9];
        CFStringGetCharacters(name, CFRangeMake(0, len), buffer);
        if ('G' == buffer[0] && 'M' == buffer[1] && 'T' == buffer[2] && ('+' == buffer[3] || '-' == buffer[3])) {
            // GMT+... or GMT-...
            if ('0' <= buffer[4] && buffer[4] <= '9') {
                if ('0' <= buffer[5] && buffer[5] <= '9') {
                    // GMT+##... or GMT-##...
                    int32_t hours = (buffer[4] - '0') * 10 + (buffer[5] - '0');
                    if (-14 <= hours && hours <= 14) {
                        CFTimeInterval ti = hours * 3600.0;
                        if (6 == len) {
                            // GMT+## or GMT-##
                            return CFTimeZoneCreateWithTimeIntervalFromGMT(allocator, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                        } else if ((8 == len) && ('0' <= buffer[6] && buffer[6] <= '9') && ('0' <= buffer[7] && buffer[7] <= '9')) {
                            // GMT+#### or GMT-####
                            int32_t minutes = (buffer[6] - '0') * 10 + (buffer[7] - '0');
                            if ((-14 == hours && 0 == minutes) || (14 == hours && 0 == minutes) || (0 <= minutes && minutes <= 59)) {
                                ti = ti + minutes * 60.0;
                                return CFTimeZoneCreateWithTimeIntervalFromGMT(allocator, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                            }
                        } else if ((9 == len) && (buffer[6] == ':') && ('0' <= buffer[7] && buffer[7] <= '9') && ('0' <= buffer[8] && buffer[8] <= '9')) {
                            // GMT+##:## or GMT-##:##
                            int32_t minutes = (buffer[7] - '0') * 10 + (buffer[8] - '0');
                            if ((-14 == hours && 0 == minutes) || (14 == hours && 0 == minutes) || (0 <= minutes && minutes <= 59)) {
                                ti = ti + minutes * 60.0;
                                return CFTimeZoneCreateWithTimeIntervalFromGMT(allocator, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                            }
                        }
                    }
                } else if (buffer[5] == ':') {
                    // GMT+#:... or GMT-#:...
                    int32_t hours = (buffer[4] - '0');
                    if (-14 <= hours && hours <= 14) {
                        CFTimeInterval ti = hours * 3600.0;
                        if (8 == len) {
                            if (('0' <= buffer[6] && buffer[6] <= '9') && ('0' <= buffer[7] && buffer[7] <= '9')) {
                                // GMT+#:## or GMT-#:##
                                int32_t minutes = (buffer[6] - '0') * 10 + (buffer[7] - '0');
                                if ((-14 == hours && 0 == minutes) || (14 == hours && 0 == minutes) || (0 <= minutes && minutes <= 59)) {
                                    ti = ti + minutes * 60.0;
                                    return CFTimeZoneCreateWithTimeIntervalFromGMT(allocator, ('-' == buffer[3] ? -1.0 : 1.0) * ti);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void *bytes;
    CFIndex length;

    if (tryAbbrev) {
        CFDictionaryRef abbrevs = CFTimeZoneCopyAbbreviationDictionary();
        tzName = static_cast<CFStringRef>(CFDictionaryGetValue(abbrevs, name));
        CFRelease(abbrevs);
    }
    if (NULL == data) {
        CFDictionaryRef dict = __CFTimeZoneCopyCompatibilityDictionary();
        CFStringRef mapping = static_cast<CFStringRef>(CFDictionaryGetValue(dict, name));
        if (mapping) {
            name = mapping;
        }
        CFRelease(dict);
        if (CFEqual(CFSTR(""), name)) {
            return NULL;
        }
    }
    if (NULL == tzName) {
        tzName = name;
    }
    result = CFTimeZoneCreate(allocator, tzName, data);
    if ((NULL != result) && (name != tzName) && (!tryAbbrev)) {
        CFStringRef nameCopy = (CFStringRef)CFStringCreateCopy(allocator, name);
        __CFTimeZoneLockGlobal();
        CFDictionaryAddValue(__CFTimeZoneCache, nameCopy, result);
        __CFTimeZoneUnlockGlobal();
        CFRelease(nameCopy);
    }
    if (NULL != data) {
        CFRelease(data);
    }
    return result;
}

CFStringRef CFTimeZoneGetName(CFTimeZoneRef tz) {
    CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFStringRef, (NSTimeZone *)tz, name);
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());
    return tz->_name;
}

CFDataRef CFTimeZoneGetData(CFTimeZoneRef tz) {
    CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFDataRef, (NSTimeZone *)tz, data);
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());
    return tz->_data;
}

CFTimeInterval CFTimeZoneGetSecondsFromGMT(CFTimeZoneRef tz, CFAbsoluteTime at) {
    CFIndex idx;
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());

    int32_t rawOffset;
    int32_t dstOffset;
    UErrorCode status = U_ZERO_ERROR;
    tz->_timeZone->getOffset(__CFAbsoluteTimeToUDate(at), false, rawOffset, dstOffset, status);
    if (U_SUCCESS(status)) {
        // rawOffset is in milliseconds, CFTimeInterval is in seconds
        return (rawOffset + dstOffset) / 1000;
    }

    CFLog(kCFLogLevelError, CFSTR("Failed to get icu timezone offset %d"), GetLastError());
    return 0.0;
}

CFStringRef CFTimeZoneCopyAbbreviation(CFTimeZoneRef tz, CFAbsoluteTime at) {
    return CFTimeZoneCopyLocalizedName(
        tz, 
        CFTimeZoneIsDaylightSavingTime(tz, at) ? kCFTimeZoneNameStyleShortDaylightSaving : kCFTimeZoneNameStyleShortStandard, 
        CFLocaleGetSystem());
}

Boolean CFTimeZoneIsDaylightSavingTime(CFTimeZoneRef tz, CFAbsoluteTime at) {
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());

    UErrorCode status = U_ZERO_ERROR;
    UBool daylight = tz->_timeZone->inDaylightTime(__CFAbsoluteTimeToUDate(at), status);

    if (U_SUCCESS(status)) {
        return daylight;
    }

    CFLog(kCFLogLevelError, CFSTR("Failed to get icu timezone dst status %d"), GetLastError());
    return false;
}

CFTimeInterval CFTimeZoneGetDaylightSavingTimeOffset(CFTimeZoneRef tz, CFAbsoluteTime at) {
    // WINOBJC: use publicly available method instead.
    // CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFTimeInterval, (NSTimeZone *)tz, _daylightSavingTimeOffsetForAbsoluteTime:at);
    CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFTimeInterval, (NSTimeZone *)tz, daylightSavingTimeOffsetForDate:(NSDate*)CFDateCreate(nullptr, at));
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());

    int32_t rawOffset;
    int32_t dstOffset;
    UErrorCode status = U_ZERO_ERROR;
    tz->_timeZone->getOffset(__CFAbsoluteTimeToUDate(at), false, rawOffset, dstOffset, status);
    if (U_SUCCESS(status)) {
        // dstOffset is in milliseconds, CFTimeInterval is in seconds
        return dstOffset / 1000;
    }

    CFLog(kCFLogLevelError, CFSTR("Failed to get icu timezone dst offset %d"), GetLastError());
    return 0.0;
}

CFAbsoluteTime CFTimeZoneGetNextDaylightSavingTimeTransition(CFTimeZoneRef tz, CFAbsoluteTime at) {
    // WINOBJC: use public method instead.
    // CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFTimeInterval, (NSTimeZone *)tz, _nextDaylightSavingTimeTransitionAfterAbsoluteTime:at);
    if (CF_IS_OBJC(CFTimeZoneGetTypeID(), tz)) {
        NSDate* nextDate =  CF_OBJC_CALLV((NSTimeZone *)tz, nextDaylightSavingTimeTransitionAfterDate:(NSDate*)CFDateCreate(nullptr, at));
        return [nextDate timeIntervalSinceReferenceDate];
    }
    
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());
    icu::TimeZoneTransition transition;
    tz->_timeZone->getNextTransition(__CFAbsoluteTimeToUDate(at), false, transition);
    return __UDateToCFAbsoluteTime(transition.getTime());
}

extern UCalendar *__CFCalendarCreateUCalendar(CFStringRef calendarID, CFStringRef localeID, CFTimeZoneRef tz);

CFStringRef CFTimeZoneCopyLocalizedName(CFTimeZoneRef tz, CFTimeZoneNameStyle style, CFLocaleRef locale) {
    CF_OBJC_FUNCDISPATCHV(CFTimeZoneGetTypeID(), CFStringRef, (NSTimeZone *)tz, localizedName:(NSTimeZoneNameStyle)style locale:(NSLocale *)locale);
    __CFGenericValidateType(tz, CFTimeZoneGetTypeID());
    __CFGenericValidateType(locale, CFLocaleGetTypeID());

    if (style == kCFTimeZoneNameStyleGeneric || style == kCFTimeZoneNameStyleShortGeneric) {
    CFDateFormatterRef df = CFDateFormatterCreate(kCFAllocatorSystemDefault, locale, kCFDateFormatterNoStyle, kCFDateFormatterNoStyle);
    CFDateFormatterSetProperty(df, kCFDateFormatterTimeZoneKey, tz);
    CFDateFormatterSetFormat(df, (style == kCFTimeZoneNameStyleGeneric) ? CFSTR("vvvv") : CFSTR("v"));
    CFStringRef str = CFDateFormatterCreateStringWithAbsoluteTime(CFGetAllocator(tz), df, 0.0);
    CFRelease(df);
    return str;
    }

    CFStringRef localeID = CFLocaleGetIdentifier(locale);
    UCalendar *cal = __CFCalendarCreateUCalendar(NULL, localeID, tz);
    if (NULL == cal) {
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    const char *cstr = CFStringGetCStringPtr(localeID, kCFStringEncodingASCII);
    if (NULL == cstr) {
        if (CFStringGetCString(localeID, buffer, BUFFER_SIZE, kCFStringEncodingASCII)) cstr = buffer;
    }
    if (NULL == cstr) {
    ucal_close(cal);
        return NULL;
    }

    UChar ubuffer[BUFFER_SIZE];
    UErrorCode status = U_ZERO_ERROR;
    int32_t cnt = ucal_getTimeZoneDisplayName(cal, (UCalendarDisplayNameType)style, cstr, ubuffer, BUFFER_SIZE, &status);
    ucal_close(cal);
    if (U_SUCCESS(status) && cnt <= BUFFER_SIZE) {
        return CFStringCreateWithCharacters(CFGetAllocator(tz), (const UniChar *)ubuffer, cnt);
    }

    return NULL;
}

static CFDictionaryRef __CFTimeZoneCopyCompatibilityDictionary(void) {
    CFDictionaryRef dict;
    __CFTimeZoneLockCompatibilityMapping();
    if (NULL == __CFTimeZoneCompatibilityMappingDict) {
    __CFTimeZoneCompatibilityMappingDict = CFDictionaryCreateMutable(kCFAllocatorSystemDefault, 112, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

    // Empty string means delete/ignore these 
    }
    dict = __CFTimeZoneCompatibilityMappingDict ? (CFDictionaryRef)CFRetain(__CFTimeZoneCompatibilityMappingDict) : NULL;
    __CFTimeZoneUnlockCompatibilityMapping();
    return dict;
}

#undef TZZONEINFO
#undef TZZONELINK

// clang-format on
