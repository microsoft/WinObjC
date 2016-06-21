//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "StubReturn.h"
#import "Starboard.h"
#import "NSStringInternal.h"
#import <Foundation/NSBundle.h>
#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSFileManager.h>
#import <Foundation/NSException.h>
#import <CoreFoundation/CFBundle.h>

#import "CFFoundationInternal.h"
#import "NSPathUtilitiesInternal.h"

#import <sys/stat.h>

#import <algorithm>
#import <functional>
#import <list>

NSString* const NSLoadedClasses = @"NSLoadedClasses";

extern "C" BOOL isOSTarget(NSString* versionStr) {
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString* minOSVersion = [infoDict objectForKey:@"MinimumOSVersion"];
    if (minOSVersion != nil) {
        if (((int)[minOSVersion _versionStringCompare:versionStr]) >= 0) {
            return true;
        }
    }

    NSString* platformVersion = [infoDict objectForKey:@"DTPlatformVersion"];
    if (platformVersion != nil) {
        if (((int)[platformVersion _versionStringCompare:versionStr]) >= 0) {
            return true;
        }
    }

    char* pSDKVersion = (char*)[[infoDict objectForKey:@"DTSDKName"] UTF8String];
    if (pSDKVersion) {
        char* sdkEnd = pSDKVersion + strlen(pSDKVersion) - 1;
        while (sdkEnd > pSDKVersion) {
            if (!isdigit(*sdkEnd) && *sdkEnd != '.') {
                if (*sdkEnd != 0)
                    sdkEnd++;
                break;
            }
            sdkEnd--;
        }

        char* versionUTF = (char*)[versionStr UTF8String];
        if (strcmp(sdkEnd, versionUTF) >= 0) {
            return true;
        }
    }

    return false;
}

@implementation NSBundle {
@private
    // NSBundle and CFBundle are not actually toll-free bridged
    // As such, just wrap a CFBundle to leverage it
    woc::unique_cf<CFBundleRef> _cf;
}

// Helper for constructing a new array from an existing one by applying a function to each element of the existing array
// Example usage would be to translate a CFArray of CFBundleRefs to an NSArray of NSBundle*s,
// by applying a wrapping function to each of them
template <typename BeforeType, typename AfterType>
static NSMutableArray<AfterType>* _mutableArrayByApplyingFunction(NSArray* beforeArray, AfterType (*func)(BeforeType)) {
    NSMutableArray<AfterType>* ret = [NSMutableArray arrayWithCapacity:[beforeArray count]];
    for (id beforeObject in beforeArray) {
        [ret addObject:func(static_cast<BeforeType>(beforeObject))];
    }
    return ret;
}

// Helper for creating an NSBundle wrapped around a CFBundle, used in _mutableArrayByApplyingFunction
static NSBundle* _NSBundleFromCFBundle(CFBundleRef cfBundle) {
    return [[[NSBundle alloc] _initWithCFBundle:cfBundle] autorelease];
}

// Helper for getting the path string from an NSURL, used in _mutableArrayByApplyingFunction
static NSString* _pathFromNSURL(NSURL* url) {
    return [url path];
}

// Convenience constructor for creating an NSBundle wrapped around a CFBundle
- (NSBundle*)_initWithCFBundle:(CFBundleRef)cfBundle {
    if (self = [super init]) {
        CFRetain(cfBundle);
        _cf.reset(cfBundle);
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (NSBundle*)mainBundle {
    static StrongId<NSBundle> mainBundle = [[[self alloc] _initWithCFBundle:CFBundleGetMainBundle()] autorelease];
    return mainBundle;
}

/**
 @Status Stub
*/
+ (NSArray<NSBundle*>*)allFrameworks {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (NSArray<NSBundle*>*)allBundles {
    return _mutableArrayByApplyingFunction(static_cast<NSArray*>(CFBundleGetAllBundles()), &_NSBundleFromCFBundle);
}

/**
 @Status Interoperable
*/
+ (NSBundle*)bundleWithURL:(NSURL*)url {
    return [[[self alloc] initWithURL:url] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSBundle*)bundleWithPath:(NSString*)path {
    return [[[self alloc] initWithPath:path] autorelease];
}

/**
 @Status Caveat
 @Notes Always returns +[NSBundle mainBundle]
*/
+ (NSBundle*)bundleForClass:(id)_class {
    return [self mainBundle];
}

/**
 @Status Interoperable
*/
+ (NSBundle*)bundleWithIdentifier:(NSString*)identifier {
    return [[[self alloc] _initWithCFBundle:CFBundleGetBundleWithIdentifier(static_cast<CFStringRef>(identifier))] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithURL:(NSURL*)url {
    if (self = [super init]) {
        _cf.reset(CFBundleCreate(kCFAllocatorDefault, static_cast<CFURLRef>(url)));
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPath:(NSString*)path {
    if (path == nil) {
        [self release];
        return nil;
    }

    return [self initWithURL:[NSURL fileURLWithPath:path]];
}

/**
 @Status Stub
*/
- (NSArray*)loadNibNamed:(NSString*)name owner:(id)owner options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension subdirectory:(NSString*)subpath {
    if ([name length] > 0) {
        return [static_cast<NSURL*>(CFBundleCopyResourceURL(_cf.get(),
                                                            static_cast<CFStringRef>(name),
                                                            static_cast<CFStringRef>(extension),
                                                            static_cast<CFStringRef>(subpath))) autorelease];
    }
    return nil;
}

/**
 @Status Interoperable
*/
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)subpath {
    return [[self URLForResource:name withExtension:extension subdirectory:subpath] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension {
    // Pass nil for subdirectory to search standard Bundle locations
    return [self URLForResource:name withExtension:extension subdirectory:nil];
}

/**
 @Status Interoperable
*/
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension {
    // Pass nil for subdirectory to search standard Bundle locations
    return [self pathForResource:name ofType:extension inDirectory:nil];
}

/**
 @Status Interoperable
*/
- (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath {
    return [static_cast<NSArray<NSURL*>*>(
        CFBundleCopyResourceURLsOfType(_cf.get(), static_cast<CFStringRef>(extension), static_cast<CFStringRef>(subpath))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)directory {
    return _mutableArrayByApplyingFunction([self URLsForResourcesWithExtension:type subdirectory:directory], &_pathFromNSURL);
}

/**
 @Status Interoperable
*/
- (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
            localization:(NSString*)localizationName {
    return [static_cast<NSURL*>(CFBundleCopyResourceURLForLocalization(_cf.get(),
                                                                       static_cast<CFStringRef>(name),
                                                                       static_cast<CFStringRef>(extension),
                                                                       static_cast<CFStringRef>(subpath),
                                                                       static_cast<CFStringRef>(localizationName))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)pathForResource:(NSString*)name
                      ofType:(NSString*)extension
                 inDirectory:(NSString*)subpath
             forLocalization:(NSString*)localizationName {
    return [[self URLForResource:name withExtension:extension subdirectory:subpath localization:localizationName] path];
}

/**
 @Status Interoperable
*/
- (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension
                                     subdirectory:(NSString*)subpath
                                     localization:(NSString*)localizationName {
    return [static_cast<NSArray<NSURL*>*>(CFBundleCopyResourceURLsOfTypeForLocalization(_cf.get(),
                                                                                        static_cast<CFStringRef>(extension),
                                                                                        static_cast<CFStringRef>(subpath),
                                                                                        static_cast<CFStringRef>(localizationName)))
        autorelease];
}

/**
 @Status Interoperable
*/
- (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)extension
                                   inDirectory:(NSString*)subpath
                               forLocalization:(NSString*)localizationName {
    return _mutableArrayByApplyingFunction([self URLsForResourcesWithExtension:extension
                                                                  subdirectory:subpath
                                                                  localization:localizationName],
                                           &_pathFromNSURL);
}

/**
 @Status Interoperable
*/
+ (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
         inBundleWithURL:(NSURL*)bundleURL {
    return [static_cast<NSURL*>(CFBundleCopyResourceURLInDirectory(static_cast<CFURLRef>(bundleURL),
                                                                   static_cast<CFStringRef>(name),
                                                                   static_cast<CFStringRef>(extension),
                                                                   static_cast<CFStringRef>(subpath))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)bundlePath {
    // Pass nil for subdirectory to search standard Bundle locations
    return [[self URLForResource:name withExtension:extension subdirectory:nil inBundleWithURL:[NSURL fileURLWithPath:bundlePath]] path];
}

/**
 @Status Interoperable
*/
+ (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath inBundleWithURL:(NSURL*)bundleURL {
    return [static_cast<NSArray<NSURL*>*>(CFBundleCopyResourceURLsOfTypeInDirectory(static_cast<CFURLRef>(bundleURL),
                                                                                    static_cast<CFStringRef>(extension),
                                                                                    static_cast<CFStringRef>(subpath))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)extension inDirectory:(NSString*)bundlePath {
    // Pass nil for subdirectory to search standard Bundle locations
    return _mutableArrayByApplyingFunction([self URLsForResourcesWithExtension:extension
                                                                  subdirectory:nil
                                                               inBundleWithURL:[NSURL fileURLWithPath:bundlePath]],
                                           &_pathFromNSURL);
}

/**
 @Status Interoperable
*/
- (NSString*)localizedStringForKey:(NSString*)key value:(NSString*)value table:(NSString*)tableName {
    return [static_cast<NSString*>(CFBundleCopyLocalizedString(_cf.get(),
                                                               static_cast<CFStringRef>(key),
                                                               static_cast<CFStringRef>(value),
                                                               static_cast<CFStringRef>(tableName))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)resourceURL {
    return [static_cast<NSURL*>(CFBundleCopyResourcesDirectoryURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)resourcePath {
    return [[self resourceURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)executableURL {
    return [static_cast<NSURL*>(CFBundleCopyExecutableURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)executablePath {
    return [[self executableURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)privateFrameworksURL {
    return [static_cast<NSURL*>(CFBundleCopyPrivateFrameworksURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)privateFrameworksPath {
    return [[self privateFrameworksURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)sharedFrameworksURL {
    return [static_cast<NSURL*>(CFBundleCopySharedFrameworksURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)sharedFrameworksPath {
    return [[self sharedFrameworksURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)builtInPlugInsURL {
    return [static_cast<NSURL*>(CFBundleCopyBuiltInPlugInsURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)builtInPlugInsPath {
    return [[self builtInPlugInsURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLForAuxiliaryExecutable:(NSString*)executableName {
    return [static_cast<NSURL*>(CFBundleCopyAuxiliaryExecutableURL(_cf.get(), static_cast<CFStringRef>(executableName))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)pathForAuxiliaryExecutable:(NSString*)executableName {
    return [[self URLForAuxiliaryExecutable:executableName] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)sharedSupportURL {
    return [static_cast<NSURL*>(CFBundleCopySharedSupportURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)sharedSupportPath {
    return [[self sharedSupportURL] path];
}

/**
 @Status Interoperable
*/
- (NSURL*)bundleURL {
    return [static_cast<NSURL*>(CFBundleCopyBundleURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)bundlePath {
    return [[self bundleURL] path];
}

/**
 @Status Interoperable
*/
- (NSString*)bundleIdentifier {
    return static_cast<NSString*>(CFBundleGetIdentifier(_cf.get()));
}

/**
 @Status Interoperable
*/
- (NSDictionary*)infoDictionary {
    return static_cast<NSDictionary*>(CFBundleGetInfoDictionary(_cf.get()));
}

/**
 @Status Interoperable
*/
- (id)objectForInfoDictionaryKey:(NSString*)key {
    return static_cast<id>(CFBundleGetValueForInfoDictionaryKey(_cf.get(), static_cast<CFStringRef>(key)));
}

/**
 @Status Interoperable
*/
- (NSArray<NSString*>*)localizations {
    return [static_cast<NSArray<NSString*>*>(CFBundleCopyBundleLocalizations(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSArray<NSString*>*)preferredLocalizations {
    return [[self class] preferredLocalizationsFromArray:[self localizations]];
}

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)preferredLocalizationsFromArray:(NSArray<NSString*>*)localizationsArray {
    return [static_cast<NSArray<NSString*>*>(CFBundleCopyPreferredLocalizationsFromArray(static_cast<CFArrayRef>(localizationsArray)))
        autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)preferredLocalizationsFromArray:(NSArray<NSString*>*)localizationsArray
                                        forPreferences:(NSArray<NSString*>*)preferencesArray {
    return
        [static_cast<NSArray<NSString*>*>(CFBundleCopyLocalizationsForPreferences(static_cast<CFArrayRef>(localizationsArray),
                                                                                  static_cast<CFArrayRef>(preferencesArray))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)developmentLocalization {
    return static_cast<NSString*>(CFBundleGetDevelopmentRegion(_cf.get()));
}

/**
 @Status Interoperable
*/
- (NSDictionary*)localizedInfoDictionary {
    return static_cast<NSDictionary*>(CFBundleGetLocalInfoDictionary(_cf.get()));
}

/**
 @Status Caveat
 @Notes Returns objc_getClass(name)
*/
- (Class)classNamed:(NSString*)name {
    return NSClassFromString(name);
}

/**
 @Status Stub
*/
- (BOOL)preflightAndReturnError:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (BOOL)loadAndReturnError:(NSError**)error {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Interoperable
 @Notes Always returns YES, NSBundle is loaded @ designated initializer
*/
- (BOOL)load {
    return YES;
}

/**
 @Status Stub
*/
- (BOOL)isLoaded {
    UNIMPLEMENTED();
    return YES;
}

/**
 @Status Stub
*/
- (BOOL)unload {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
*/
- (void)setPreservationPriority:(double)priority forTags:(NSSet*)tags {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (double)preservationPriorityForTag:(NSString*)tag {
    UNIMPLEMENTED();
    return 0.0;
}

@end

@implementation NSBundle (Internal)

// Converts a URL into a ms-appx:// URL
// Intended for URLs returned from [NSBundle URLForResource:]
// URLs not returned from [NSBundle URLForResource:] just return the same URL with the scheme changed
- (NSURL*)_msAppxURLForResourceWithURL:(NSURL*)url {
    NSString* scheme = [url scheme];
    NSString* path = [url path];

    if (scheme == nil || [scheme isEqualToString:NSURLFileScheme]) {
        NSRange range = [path rangeOfString:[self bundlePath]];

        // If a URL was returned from URLForResource, it ought to have [self bundlePath] in it
        if (range.location != NSNotFound) {
            path = [path substringFromIndex:range.location + range.length];
        }

        return [[[NSURL alloc] initWithScheme:@"ms-appx" host:nil path:path] autorelease];
    } else {
        return [[url copy] autorelease];
    }
}

@end