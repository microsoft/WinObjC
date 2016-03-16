// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFLogUtilities.h
	Copyright (c) 2004 - 2015 Apple Inc. and the Swift project authors
*/

/*
        APPLE SPI:  NOT TO BE USED OUTSIDE APPLE!
*/

#if !defined(__COREFOUNDATION_CFLOGUTILITIES__)
#define __COREFOUNDATION_CFLOGUTILITIES__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFString.h>

CF_EXTERN_C_BEGIN


typedef CF_ENUM(int32_t, CFLogLevel) {	// Legal level values for CFLog()
    kCFLogLevelEmergency = 0,
    kCFLogLevelAlert = 1,
    kCFLogLevelCritical = 2,
    kCFLogLevelError = 3,
    kCFLogLevelWarning = 4,
    kCFLogLevelNotice = 5,
    kCFLogLevelInfo = 6,
    kCFLogLevelDebug = 7,
};

CF_EXPORT void CFLog(CFLogLevel level, CFStringRef format, ...);
/*	Passing in a level value which is outside the range of 0-7 will cause the the call to do nothing.
	CFLog() logs the message using the asl.h API, and uses the level parameter as the log level.
	Note that the asl subsystem ignores some log levels by default.
	CFLog() is not fast, and is not going to be guaranteed to be fast.
	Even "no-op" CFLogs are not necessarily fast.
	If you care about performance, you shouldn't be logging.
*/

#if DEPLOYMENT_RUNTIME_SWIFT
CF_EXPORT void CFLog1(CFLogLevel lev, CFStringRef message);
#endif

CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFLOGUTILITIES__ */

