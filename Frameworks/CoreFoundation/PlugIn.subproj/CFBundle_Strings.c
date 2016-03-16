// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*      CFBundle_Strings.c
        Copyright (c) 1999-2015, Apple Inc.  All rights reserved.
        Responsibility: Tony Parker
*/

#include "CFBundle_Internal.h"
#if DEPLOYMENT_TARGET_MACOSX

#endif

#include <CoreFoundation/CFPreferences.h>
#include <CoreFoundation/CFURLAccess.h>

#pragma mark -
#pragma mark Localized Strings

typedef struct {
    CFDictionaryRef localizedFormatStringsTable;
    CFMutableDictionaryRef result;
} VariableWidthStringContext;


CF_EXPORT CFStringRef CFBundleCopyLocalizedString(CFBundleRef bundle, CFStringRef key, CFStringRef value, CFStringRef tableName) {
    return CFBundleCopyLocalizedStringForLocalization(bundle, key, value, tableName, NULL);
}

static CFStringRef _copyStringFromTable(CFBundleRef bundle, CFStringRef tableName, CFStringRef key, CFStringRef localizationName) {
    // Check the cache first. If it's not there, populate the cache and check again.
    
    __CFLock(&bundle->_lock);
    // Only consult the cache when a specific localization has not been requested. We only cache results for the preferred language as determined by normal bundle lookup rules.
    if (!localizationName && bundle->_stringTable) {
        CFDictionaryRef stringTable = (CFDictionaryRef)CFDictionaryGetValue(bundle->_stringTable, tableName);
        if (stringTable) {
            CFStringRef result = CFDictionaryGetValue(stringTable, key);
            if (result) {
                CFRetain(result);
            }
            __CFUnlock(&bundle->_lock);
            return result;
        }
    }

    // Not in the local cache, so load the table. Unlock so we don't hold the lock across file system access.
    __CFUnlock(&bundle->_lock);

    CFDictionaryRef stringsTable = NULL;
    CFURLRef stringsTableURL = NULL;
    CFURLRef stringsDictTableURL = NULL;
    
    // Find the resource URL.
    if (localizationName) {
        stringsTableURL = CFBundleCopyResourceURLForLocalization(bundle, tableName, _CFBundleStringTableType, NULL, localizationName);
        stringsDictTableURL = CFBundleCopyResourceURLForLocalization(bundle, tableName, _CFBundleStringDictTableType, NULL, localizationName);
    } else {
        stringsTableURL = CFBundleCopyResourceURL(bundle, tableName, _CFBundleStringTableType, NULL);
        stringsDictTableURL = CFBundleCopyResourceURL(bundle, tableName, _CFBundleStringDictTableType, NULL);
    }
    
    
    // Next, look on disk for the regular strings file.
    if (!stringsTable && stringsTableURL) {
        CFDataRef tableData = _CFDataCreateFromURL(stringsTableURL, NULL);
        if (tableData) {
            CFErrorRef error = NULL;
            stringsTable = (CFDictionaryRef)CFPropertyListCreateWithData(CFGetAllocator(bundle), tableData, kCFPropertyListImmutable, NULL, &error);
            CFRelease(tableData);
            
            if (stringsTable && CFDictionaryGetTypeID() != CFGetTypeID(stringsTable)) {
                CFLog(kCFLogLevelError, CFSTR("Unable to load .strings file: %@ / %@: Top-level object was not a dictionary"), bundle, tableName);
                CFRelease(stringsTable);
                stringsTable = NULL;
            } else if (!stringsTable && error) {
                CFLog(kCFLogLevelError, CFSTR("Unable to load .strings file: %@ / %@: %@"), bundle, tableName, error);
                CFRelease(error);
                error = NULL;
            }
        }
        
    }
    
    // Check for a .stringsdict file.
    if (stringsDictTableURL) {
        CFDataRef tableData = _CFDataCreateFromURL(stringsDictTableURL, NULL);
        if (tableData) {
            CFErrorRef error = NULL;
            CFDictionaryRef stringsDictTable = (CFDictionaryRef)CFPropertyListCreateWithData(CFGetAllocator(bundle), tableData, kCFPropertyListImmutable, NULL, &error);
            CFRelease(tableData);
            
            if (stringsDictTable && CFDictionaryGetTypeID() != CFGetTypeID(stringsDictTable)) {
                CFLog(kCFLogLevelError, CFSTR("Unable to load .stringsdict file: %@ / %@: Top-level object was not a dictionary"), bundle, tableName);
                CFRelease(stringsDictTable);
                stringsDictTable = NULL;
            } else if (!stringsDictTable && error) {
                CFLog(kCFLogLevelError, CFSTR("Unable to load .stringsdict file: %@ / %@: %@"), bundle, tableName, error);
                CFRelease(error);
                error = NULL;
            }
            
            // Post-process the strings table
            if (stringsDictTable) {
                CFMutableDictionaryRef mutableStringsDictTable;
                if (stringsTable) {
                    // Use the strings table as base content for the stringsdict
                    mutableStringsDictTable = CFDictionaryCreateMutableCopy(NULL, 0, stringsTable);
                } else {
                    // Start from scratch with the stringsdict
                    mutableStringsDictTable = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
                }
                CFRelease(stringsDictTable);
                if (stringsTable) CFRelease(stringsTable);
                stringsTable = mutableStringsDictTable;
            }
        }
    }
    
    if (stringsTableURL) CFRelease(stringsTableURL);
    if (stringsDictTableURL) CFRelease(stringsDictTableURL);
    
    // Last resort: create an empty table
    if (!stringsTable) {
        stringsTable = CFDictionaryCreate(CFGetAllocator(bundle), NULL, NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    }
    
    // Insert the result into our local cache
    if ((!CFStringHasSuffix(tableName, CFSTR(".nocache")) || !_CFExecutableLinkedOnOrAfter(CFSystemVersionLeopard)) && localizationName == NULL) {
        // Take lock again, because this we will unlock after getting the value out of the table.
        __CFLock(&bundle->_lock);
        if (!bundle->_stringTable) bundle->_stringTable = CFDictionaryCreateMutable(CFGetAllocator(bundle), 0, &kCFCopyStringDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        
        // If another thread beat us to setting this tableName, then we'll just replace it here.
        CFDictionarySetValue(bundle->_stringTable, tableName, stringsTable);
    } else {
        // Take lock again, because this we will unlock after getting the value out of the table.
        __CFLock(&bundle->_lock);
    }
    
    // Finally, fetch the result from the table
    CFStringRef result = CFDictionaryGetValue(stringsTable, key);
    if (result) {
        CFRetain(result);
    }
    __CFUnlock(&bundle->_lock);

    CFRelease(stringsTable);
    
    return result;
}

CF_EXPORT CFStringRef CFBundleCopyLocalizedStringForLocalization(CFBundleRef bundle, CFStringRef key, CFStringRef value, CFStringRef tableName, CFStringRef localizationName) {
    if (!key) return (value ? (CFStringRef)CFRetain(value) : (CFStringRef)CFRetain(CFSTR("")));
    
    // Make sure to check the mixed localizations key early -- if the main bundle has not yet been cached, then we need to create the cache of the Info.plist before we start asking for resources (11172381)
    (void)CFBundleAllowMixedLocalizations();
    
    if (!tableName || CFEqual(tableName, CFSTR(""))) tableName = _CFBundleDefaultStringTableName;
    
    CFStringRef result = _copyStringFromTable(bundle, tableName, key, localizationName);
    
    if (!result) {
        if (!value) {
            result = (CFStringRef)CFRetain(key);
        } else if (CFEqual(value, CFSTR(""))) {
            result = (CFStringRef)CFRetain(key);
        } else {
            result = (CFStringRef)CFRetain(value);
        }
        static Boolean capitalize = false;
        if (capitalize) {
            CFMutableStringRef capitalizedResult = CFStringCreateMutableCopy(kCFAllocatorSystemDefault, 0, result);
            CFLog(__kCFLogBundle, CFSTR("Localizable string \"%@\" not found in strings table \"%@\" of bundle %@."), key, tableName, bundle);
            CFStringUppercase(capitalizedResult, NULL);
            CFRelease(result);
            result = capitalizedResult;
        }
    }
    
    return result;
}

