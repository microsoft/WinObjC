//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSDictionary;
@class NSString;

typedef struct {
    NSInteger majorVersion;
    NSInteger minorVersion;
    NSInteger patchVersion;
} NSOperatingSystemVersion;

typedef enum : uint64_t {
    NSActivityIdleDisplaySleepDisabled = (1ULL << 40),
    NSActivityIdleSystemSleepDisabled = (1ULL << 20),
    NSActivitySuddenTerminationDisabled = (1ULL << 14),
    NSActivityAutomaticTerminationDisabled = (1ULL << 15),
    NSActivityUserInitiated = (0x00FFFFFFULL | NSActivityIdleSystemSleepDisabled),
    NSActivityUserInitiatedAllowingIdleSystemSleep = (NSActivityUserInitiated & ~NSActivityIdleSystemSleepDisabled),
    NSActivityBackground = 0x000000FFULL,
    NSActivityLatencyCritical = 0xFF00000000ULL,
} NSActivityOptions;

enum {
    NSWindowsNTOperatingSystem = 1,
    NSWindows95OperatingSystem,
    NSSolarisOperatingSystem,
    NSHPUXOperatingSystem,
    NSMACHOperatingSystem,
    NSSunOSOperatingSystem,
    NSOSF1OperatingSystem
};

FOUNDATION_EXPORT_CLASS
@interface NSProcessInfo : NSObject
+ (NSProcessInfo*)processInfo;
@property (readonly, copy) NSArray* arguments;
@property (readonly, copy) NSDictionary* environment;
@property (readonly, copy) NSString* globallyUniqueString;
@property (readonly) int processIdentifier;
@property (copy) NSString* processName;
@property (readonly, copy) NSString* hostName;
- (NSUInteger)operatingSystem;
- (NSString*)operatingSystemName;
@property (readonly, copy) NSString* operatingSystemVersionString;
@property (readonly) NSOperatingSystemVersion operatingSystemVersion;
- (BOOL)isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion)version;
@property (readonly) NSUInteger processorCount;
@property (readonly) NSUInteger activeProcessorCount;
@property (readonly) unsigned long long physicalMemory STUB_PROPERTY;
@property (readonly) NSTimeInterval systemUptime;

- (id<NSObject>)beginActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason STUB_METHOD;
- (void)endActivity:(id<NSObject>)activity STUB_METHOD;
- (void)performActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason usingBlock:(void (^)(void))block STUB_METHOD;
- (void)performExpiringActivityWithReason:(NSString*)reason usingBlock:(void (^)(BOOL))block STUB_METHOD;
@end

FOUNDATION_EXPORT void NSInitializeProcess(int argc, const char* argv[]);
