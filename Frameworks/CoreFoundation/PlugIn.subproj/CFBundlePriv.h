// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFBundlePriv.h
	Copyright (c) 1999-2015, Apple Inc.  All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFBUNDLEPRIV__)
#define __COREFOUNDATION_CFBUNDLEPRIV__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFBundle.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFURL.h>

CF_EXTERN_C_BEGIN

/* Finder stuff */
CF_EXPORT
const CFStringRef _kCFBundlePackageTypeKey;
CF_EXPORT
const CFStringRef _kCFBundleSignatureKey;
CF_EXPORT
const CFStringRef _kCFBundleIconFileKey;
CF_EXPORT
const CFStringRef _kCFBundleDocumentTypesKey;
CF_EXPORT
const CFStringRef _kCFBundleURLTypesKey;

/* Localizable Finder stuff */
CF_EXPORT
const CFStringRef _kCFBundleDisplayNameKey;
CF_EXPORT
const CFStringRef _kCFBundleShortVersionStringKey;
CF_EXPORT
const CFStringRef _kCFBundleGetInfoStringKey;
CF_EXPORT
const CFStringRef _kCFBundleGetInfoHTMLKey;

/* Sub-keys for CFBundleDocumentTypes dictionaries */
CF_EXPORT
const CFStringRef _kCFBundleTypeNameKey;
CF_EXPORT
const CFStringRef _kCFBundleTypeRoleKey;
CF_EXPORT
const CFStringRef _kCFBundleTypeIconFileKey;
CF_EXPORT
const CFStringRef _kCFBundleTypeOSTypesKey;
CF_EXPORT
const CFStringRef _kCFBundleTypeExtensionsKey;
CF_EXPORT
const CFStringRef _kCFBundleTypeMIMETypesKey;

/* Sub-keys for CFBundleURLTypes dictionaries */
CF_EXPORT
const CFStringRef _kCFBundleURLNameKey;
CF_EXPORT
const CFStringRef _kCFBundleURLIconFileKey;
CF_EXPORT
const CFStringRef _kCFBundleURLSchemesKey;

/* Compatibility key names */
CF_EXPORT
const CFStringRef _kCFBundleOldExecutableKey;
CF_EXPORT
const CFStringRef _kCFBundleOldInfoDictionaryVersionKey;
CF_EXPORT
const CFStringRef _kCFBundleOldNameKey;
CF_EXPORT
const CFStringRef _kCFBundleOldIconFileKey;
CF_EXPORT
const CFStringRef _kCFBundleOldDocumentTypesKey;
CF_EXPORT
const CFStringRef _kCFBundleOldShortVersionStringKey;

/* Compatibility CFBundleDocumentTypes key names */
CF_EXPORT
const CFStringRef _kCFBundleOldTypeNameKey;
CF_EXPORT
const CFStringRef _kCFBundleOldTypeRoleKey;
CF_EXPORT
const CFStringRef _kCFBundleOldTypeIconFileKey;
CF_EXPORT
const CFStringRef _kCFBundleOldTypeExtensions1Key;
CF_EXPORT
const CFStringRef _kCFBundleOldTypeExtensions2Key;
CF_EXPORT
const CFStringRef _kCFBundleOldTypeOSTypesKey;

/* For platform specification */
CF_EXPORT
const CFStringRef _kCFBundleSupportedPlatformsKey;

/* For Code Signing */
CF_EXPORT
const CFStringRef _kCFBundleResourceSpecificationKey;


/* Functions for examining directories that may "look like" bundles */

CF_EXPORT
CFURLRef _CFBundleCopyBundleURLForExecutableURL(CFURLRef url);

CF_EXPORT
Boolean _CFBundleURLLooksLikeBundle(CFURLRef url);

/* Note: As of OS X 10.11 and iOS 9.0, this function uses _CFBundleCreateUnique and will return a bundle that does not populate the usual CFBundle caches. This means it will not be included in the result of CFBundleGetAllBundles(). */
CF_EXPORT
CFBundleRef _CFBundleCreateIfLooksLikeBundle(CFAllocatorRef allocator, CFURLRef url);

CF_EXPORT
CFBundleRef _CFBundleGetMainBundleIfLooksLikeBundle(void);

CF_EXPORT
Boolean _CFBundleMainBundleInfoDictionaryComesFromResourceFork(void);

/* Note: As of OS X 10.11 and iOS 9.0, this function uses _CFBundleCreateUnique and will return a bundle that does not populate the usual CFBundle caches. This means it will not be included in the result of CFBundleGetAllBundles(). */
CF_EXPORT
CFBundleRef _CFBundleCreateWithExecutableURLIfLooksLikeBundle(CFAllocatorRef allocator, CFURLRef url);

CF_EXPORT
CFURLRef _CFBundleCopyMainBundleExecutableURL(Boolean *looksLikeBundle);

CF_EXPORT
CFBundleRef _CFBundleGetExistingBundleWithBundleURL(CFURLRef bundleURL);

// This function is obsolete.
CF_EXPORT
CFArrayRef _CFBundleGetSupportedPlatforms(CFBundleRef bundle);

CF_EXPORT
CFStringRef _CFBundleGetCurrentPlatform(void);

/* This function will return a bundle object that is not from the existing caches, and will never be part of the result of any method that checks the caches (e.g., get all bundles). The bundle object itself may keep a cache, but you can just use this function to create another instance if you want to get a fresh cache. Note that any NSBundle-level API has yet another cache, which is not considered here. */
CF_EXPORT
CFBundleRef _CFBundleCreateUnique(CFAllocatorRef allocator, CFURLRef bundleURL) CF_AVAILABLE(10_11, 9_0);

/* For Code Signing */

// This function is obsolete. Use CFBundleCreate instead.
CF_EXPORT
CFBundleRef _CFBundleCreateIfMightBeBundle(CFAllocatorRef allocator, CFURLRef url) CF_DEPRECATED(10_6, 10_10, 2_0, 8_0);

// This function is for code signing only. Do not use this function.
CF_EXPORT
CFBundleRef _CFBundleCreateWithExecutableURLIfMightBeBundle(CFAllocatorRef allocator, CFURLRef url);


/* Functions for examining the structure of a bundle */

CF_EXPORT
CFURLRef _CFBundleCopyResourceForkURL(CFBundleRef bundle) CF_AVAILABLE_MAC(10_0);

CF_EXPORT
CFURLRef _CFBundleCopyInfoPlistURL(CFBundleRef bundle);


/* Functions for working without a bundle instance */

CF_EXPORT
CFURLRef _CFBundleCopyExecutableURLInDirectory(CFURLRef url);

CF_EXPORT
CFURLRef _CFBundleCopyOtherExecutableURLInDirectory(CFURLRef url);


/* Functions for dealing with localizations */

CF_EXPORT
void _CFBundleGetLanguageAndRegionCodes(SInt32 *languageCode, SInt32 *regionCode);
// may return -1 for either one if no code can be found

CF_EXPORT
Boolean CFBundleGetLocalizationInfoForLocalization(CFStringRef localizationName, SInt32 *languageCode, SInt32 *regionCode, SInt32 *scriptCode, CFStringEncoding *stringEncoding);
    /* Gets the appropriate language and region codes, and the default */
    /* script code and encoding, for the localization specified. */
    /* Pass NULL for the localizationName to get these values for the */
    /* single most preferred localization in the current context. */
    /* May give -1 if there is no language or region code for a particular */
    /* localization. Returns false if CFBundle has no information about */
    /* the given localization. */

CF_EXPORT
CFStringRef CFBundleCopyLocalizationForLocalizationInfo(SInt32 languageCode, SInt32 regionCode, SInt32 scriptCode, CFStringEncoding stringEncoding);
    /* Returns the default localization for the combination of codes */
    /* specified.  Pass in -1 for language, region code, or script code, or */
    /* 0xFFFF for stringEncoding, if you do not wish to specify one of these. */ 

// Get a localized string for a specific localization (including processing as strings dict file). This skips the usual cache for localized strings.
CF_EXPORT CFStringRef CFBundleCopyLocalizedStringForLocalization(CFBundleRef bundle, CFStringRef key, CFStringRef value, CFStringRef tableName, CFStringRef localizationName) CF_AVAILABLE(10_10, 8_0);

CF_EXPORT
void _CFBundleSetDefaultLocalization(CFStringRef localizationName);


/* Functions for dealing specifically with CFM executables */

CF_EXPORT
void *_CFBundleGetCFMFunctionPointerForName(CFBundleRef bundle, CFStringRef funcName);

CF_EXPORT
void _CFBundleGetCFMFunctionPointersForNames(CFBundleRef bundle, CFArrayRef functionNames, void *ftbl[]);

CF_EXPORT
void _CFBundleSetCFMConnectionID(CFBundleRef bundle, void *connectionID);


/* Miscellaneous functions */

CF_EXPORT
CFStringRef _CFBundleCopyFileTypeForFileURL(CFURLRef url);

CF_EXPORT
CFStringRef _CFBundleCopyFileTypeForFileData(CFDataRef data);

CF_EXPORT
Boolean _CFBundleGetHasChanged(CFBundleRef bundle);

CF_EXPORT
void _CFBundleFlushCaches(void) CF_DEPRECATED(10_0, 10_8, 2_0, 6_0);

CF_EXPORT
void _CFBundleFlushCachesForURL(CFURLRef url) CF_DEPRECATED(10_0, 10_8, 2_0, 6_0);

CF_EXPORT
void _CFBundleFlushBundleCaches(CFBundleRef bundle);    // The previous two functions flush cached resource paths; this one also flushes bundle-specific caches such as the info dictionary and strings files

CF_EXPORT 
CFArrayRef _CFBundleCopyAllBundles(void); // Pending publication, the only known client of this is PowerBox. Email david_smith@apple.com before using this.

CF_EXPORT
void _CFBundleSetStringsFilesShared(CFBundleRef bundle, Boolean flag);

CF_EXPORT
Boolean _CFBundleGetStringsFilesShared(CFBundleRef bundle);

CF_EXPORT
CFURLRef _CFBundleCopyFrameworkURLForExecutablePath(CFStringRef executablePath);

/* Functions deprecated as SPI */

CF_EXPORT
CFDictionaryRef _CFBundleGetLocalInfoDictionary(CFBundleRef bundle);	// deprecated in favor of CFBundleGetLocalInfoDictionary

CF_EXPORT
CFPropertyListRef _CFBundleGetValueForInfoKey(CFBundleRef bundle, CFStringRef key);	// deprecated in favor of CFBundleGetValueForInfoDictionaryKey

CF_EXPORT
Boolean _CFBundleGetPackageInfoInDirectory(CFAllocatorRef alloc, CFURLRef url, UInt32 *packageType, UInt32 *packageCreator);	// deprecated in favor of CFBundleGetPackageInfoInDirectory

CF_EXPORT
CFDictionaryRef _CFBundleCopyInfoDictionaryInResourceFork(CFURLRef url);	// CFBundleCopyInfoDictionaryForURL is usually preferred; for the main bundle, however, no special call is necessary, since the info dictionary will automatically be available whether the app is bundled or not

CF_EXPORT
CFURLRef _CFBundleCopyPrivateFrameworksURL(CFBundleRef bundle);		// deprecated in favor of CFBundleCopyPrivateFrameworksURL

CF_EXPORT
CFURLRef _CFBundleCopySharedFrameworksURL(CFBundleRef bundle);		// deprecated in favor of CFBundleCopySharedFrameworksURL

CF_EXPORT
CFURLRef _CFBundleCopySharedSupportURL(CFBundleRef bundle);		// deprecated in favor of CFBundleCopySharedSupportURL

CF_EXPORT
CFURLRef _CFBundleCopyBuiltInPlugInsURL(CFBundleRef bundle);		// deprecated in favor of CFBundleCopyBuiltInPlugInsURL

CF_EXPORT
CFURLRef _CFBundleCopyResourceURLForLanguage(CFBundleRef bundle, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName, CFStringRef language);	 // deprecated in favor of CFBundleCopyResourceURLForLocalization

CF_EXPORT
CFArrayRef _CFBundleCopyResourceURLsOfTypeForLanguage(CFBundleRef bundle, CFStringRef resourceType, CFStringRef subDirName, CFStringRef language);	// deprecated in favor of CFBundleCopyResourceURLsOfTypeForLocalization

CF_EXPORT
CFBundleRefNum _CFBundleOpenBundleResourceFork(CFBundleRef bundle);	// deprecated in favor of CFBundleOpenBundleResourceMap

CF_EXPORT
void _CFBundleCloseBundleResourceFork(CFBundleRef bundle);	// deprecated in favor of CFBundleCloseBundleResourceMap

CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFBUNDLEPRIV__ */

// clang-format on
