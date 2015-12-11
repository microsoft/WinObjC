/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>

@class NSArray;
@class NSDictionary;
@class NSLock;
@class NSMutableDictionary;

// deprecated, used for return values of operatingSystem message
enum {
    NSWindowsNTOperatingSystem = 1,
    NSWindows95OperatingSystem,
    NSSolarisOperatingSystem,
    NSHPUXOperatingSystem,
    NSMACHOperatingSystem,
    NSSunOSOperatingSystem,
    NSOSF1OperatingSystem
};

typedef struct {
    NSInteger majorVersion;
    NSInteger minorVersion;
    NSInteger patchVersion;
} NSOperatingSystemVersion;

typedef NS_OPTIONS(uint64_t, NSActivityOptions) {
    NSActivityIdleDisplaySleepDisabled = (1ULL << 40),
    NSActivityIdleSystemSleepDisabled = (1ULL << 20),
    NSActivitySuddenTerminationDisabled = (1ULL << 14),
    NSActivityAutomaticTerminationDisabled = (1ULL << 15),
    NSActivityUserInitiated = (0x00FFFFFFULL | NSActivityIdleSystemSleepDisabled),
    NSActivityUserInitiatedAllowingIdleSystemSleep = (NSActivityUserInitiated & ~NSActivityIdleSystemSleepDisabled),
    NSActivityBackground = 0x000000FFULL,
    NSActivityLatencyCritical = 0xFF00000000ULL,
};

FOUNDATION_EXPORT_CLASS
@interface NSProcessInfo : NSObject {
    NSMutableDictionary* _environment;
    NSString* _processName;
    int _processIdentifier;
    NSUInteger _processorCount;
}

// Getting the Process Information Agent
+ (NSProcessInfo*)processInfo;

// Accessing Process Information
@property (readonly, copy) NSArray* arguments;
@property (readonly, copy) NSDictionary* environment;
@property (readonly, copy) NSString* globallyUniqueString;
@property (readonly) int processIdentifier;
@property (copy) NSString* processName;

// Getting Host Information
@property (readonly, copy) NSString* hostName;
- (NSUInteger)operatingSystem;
- (NSString*)operatingSystemName;
@property (readonly, copy) NSString* operatingSystemVersionString;
@property (readonly) NSOperatingSystemVersion operatingSystemVersion;
- (BOOL)isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion)version;

// Getting Computer Information
@property (readonly) NSUInteger processorCount;
@property (readonly) NSUInteger activeProcessorCount;
@property (readonly) unsigned long long physicalMemory;
@property (readonly) NSTimeInterval systemUptime;

// Managing Activities
- (id<NSObject>)beginActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason;
- (void)endActivity:(id)activity;
- (void)performActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason usingBlock:(void (^)(void))block;
- (void)performExpiringActivityWithReason:(NSString*)reason usingBlock:(void (^)(BOOL expired))block;

@end

FOUNDATION_EXPORT void NSInitializeProcess(int argc, const char* argv[]);
