// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFSystemDirectories.c
	Copyright (c) 1997 - 2015 Apple Inc. and the Swift project authors
	Responsibility: Kevin Perry
*/

/*
        This file defines CFCopySearchPathForDirectoriesInDomains().
        On MacOS 8, this function returns empty array.
        On Mach, it calls the System.framework enumeration functions.
        On Windows, it calls the enumeration functions defined here.
*/

#include <CoreFoundation/CFPriv.h>
#include "CFInternal.h"

#if DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED

/* We use the System framework implementation on Mach.
*/
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <NSSystemDirectories.h>

CFSearchPathEnumerationState __CFStartSearchPathEnumeration(CFSearchPathDirectory dir, CFSearchPathDomainMask domainMask) {
    return NSStartSearchPathEnumeration(dir, domainMask);
}

CFSearchPathEnumerationState __CFGetNextSearchPathEnumeration(CFSearchPathEnumerationState state, uint8_t *path, CFIndex pathSize) {
    CFSearchPathEnumerationState result;
    // NSGetNextSearchPathEnumeration requires a MAX_PATH size
    if (pathSize < PATH_MAX) {
        uint8_t tempPath[PATH_MAX];
        result = NSGetNextSearchPathEnumeration(state, (char *)tempPath);
        strlcpy((char *)path, (char *)tempPath, pathSize);
    } else {
        result = NSGetNextSearchPathEnumeration(state, (char *)path);
    }
    return result;
}

#endif


#if DEPLOYMENT_TARGET_MACOSX || DEPLOYMENT_TARGET_EMBEDDED || DEPLOYMENT_TARGET_WINDOWS

CFArrayRef CFCopySearchPathForDirectoriesInDomains(CFSearchPathDirectory directory, CFSearchPathDomainMask domainMask, Boolean expandTilde) {
    CFMutableArrayRef array;
    CFSearchPathEnumerationState state;
    CFIndex homeLen = -1;
    char cPath[CFMaxPathSize], home[CFMaxPathSize];

    array = CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks);
    state = __CFStartSearchPathEnumeration(directory, domainMask);
    while ((state = __CFGetNextSearchPathEnumeration(state, (uint8_t *)cPath, sizeof(cPath)))) {
	CFURLRef url = NULL;
	if (expandTilde && (cPath[0] == '~')) {
	    if (homeLen < 0) {
		CFURLRef homeURL = CFCopyHomeDirectoryURLForUser(NULL);
		if (homeURL) {
		    CFURLGetFileSystemRepresentation(homeURL, true, (uint8_t *)home, CFMaxPathSize);
		    homeLen = strlen(home);
		    CFRelease(homeURL);
		}
	    }
            if (homeLen + strlen(cPath) < CFMaxPathSize) {
		home[homeLen] = '\0';
		strlcat(home, &cPath[1], sizeof(home));
		url = CFURLCreateFromFileSystemRepresentation(kCFAllocatorSystemDefault, (uint8_t *)home, strlen(home), true);
	    }
	} else {
	    url = CFURLCreateFromFileSystemRepresentation(kCFAllocatorSystemDefault, (uint8_t *)cPath, strlen(cPath), true);
	}
	if (url) {
	    CFArrayAppendValue(array, url);
	    CFRelease(url);
	}
    }
    return array;
}

#endif


#undef numDirs
#undef numApplicationDirs
#undef numLibraryDirs
#undef numDomains
#undef invalidDomains
#undef invalidDomains

