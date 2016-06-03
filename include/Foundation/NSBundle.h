//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

@class NSString;
@class NSURL;
@class NSArray<ObjectType>;
@class NSDictionary;
@class NSError;
@class NSSet;

typedef NS_ENUM(NSUInteger, NSBundleExecutableArchitecture) {
    NSBundleExecutableArchitectureI386 = 0x00000007,
    NSBundleExecutableArchitecturePPC = 0x00000012,
    NSBundleExecutableArchitectureX86_64 = 0x01000007,
    NSBundleExecutableArchitecturePPC64 = 0x01000012
};

FOUNDATION_EXPORT NSString* const NSLoadedClasses;
FOUNDATION_EXPORT NSString* const NSBundleDidLoadNotification;

FOUNDATION_EXPORT_CLASS
@interface NSBundle : NSObject

+ (NSBundle*)mainBundle;
+ (NSArray<NSBundle*>*)allFrameworks STUB_METHOD;
+ (NSArray<NSBundle*>*)allBundles;

+ (instancetype)bundleWithURL:(NSURL*)url;
+ (instancetype)bundleWithPath:(NSString*)fullPath;
+ (NSBundle*)bundleForClass:(Class)aClass;
+ (NSBundle*)bundleWithIdentifier:(NSString*)identifier;
- (instancetype)initWithURL:(NSURL*)url;
- (instancetype)initWithPath:(NSString*)fullPath;

- (NSArray*)loadNibNamed:(NSString*)name owner:(id)owner options:(NSDictionary*)options STUB_METHOD;

+ (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)bundlePath;
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension;
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)extension inDirectory:(NSString*)subpath;
- (NSString*)pathForResource:(NSString*)name
                      ofType:(NSString*)extension
                 inDirectory:(NSString*)subpath
             forLocalization:(NSString*)localizationName;

+ (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
         inBundleWithURL:(NSURL*)bundleURL;
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension;
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension subdirectory:(NSString*)subpath;
- (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
            localization:(NSString*)localizationName;

+ (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath inBundleWithURL:(NSURL*)bundleURL;
- (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension
                                     subdirectory:(NSString*)subpath
                                     localization:(NSString*)localizationName;
- (NSArray<NSURL*>*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath;

+ (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)extension inDirectory:(NSString*)bundlePath;
- (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)extension inDirectory:(NSString*)subpath;
- (NSArray<NSString*>*)pathsForResourcesOfType:(NSString*)extension
                                   inDirectory:(NSString*)subpath
                               forLocalization:(NSString*)localizationName;

@property (readonly, copy) NSString* resourcePath;
@property (readonly, copy) NSURL* appStoreReceiptURL;
@property (readonly, copy) NSURL* bundleURL;
@property (readonly, copy) NSString* bundlePath;
@property (readonly, copy) NSString* bundleIdentifier;
@property (readonly, copy) NSDictionary* infoDictionary;

- (id)objectForInfoDictionaryKey:(NSString*)key;

@property (readonly, copy) NSURL* builtInPlugInsURL;
@property (readonly, copy) NSString* builtInPlugInsPath;
@property (readonly, copy) NSURL* executableURL;
@property (readonly, copy) NSString* executablePath;

- (NSURL*)URLForAuxiliaryExecutable:(NSString*)executableName;
- (NSString*)pathForAuxiliaryExecutable:(NSString*)executableName;

@property (readonly, copy) NSURL* privateFrameworksURL;
@property (readonly, copy) NSString* privateFrameworksPath;
@property (readonly, copy) NSURL* sharedFrameworksURL;
@property (readonly, copy) NSString* sharedFrameworksPath;
@property (readonly, copy) NSURL* sharedSupportURL;
@property (readonly, copy) NSString* sharedSupportPath;
@property (readonly, copy) NSURL* resourceURL;

- (NSString*)localizedStringForKey:(NSString*)key value:(NSString*)value table:(NSString*)tableName;

@property (readonly, copy) NSArray<NSNumber*>* executableArchitectures;

- (BOOL)preflightAndReturnError:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)load;
- (BOOL)loadAndReturnError:(NSError* _Nullable*)error STUB_METHOD;

@property (readonly, getter=isLoaded) BOOL loaded;

- (BOOL)unload STUB_METHOD;

+ (NSArray<NSString*>*)preferredLocalizationsFromArray:(NSArray<NSString*>*)localizationsArray;
+ (NSArray<NSString*>*)preferredLocalizationsFromArray:(NSArray<NSString*>*)localizationsArray
                                        forPreferences:(NSArray<NSString*>*)preferencesArray;

@property (readonly, copy) NSArray<NSString*>* preferredLocalizations;
@property (readonly, copy) NSString* developmentLocalization;
@property (readonly, copy) NSArray<NSString*>* localizations;
@property (readonly, copy) NSDictionary* localizedInfoDictionary;

- (void)setPreservationPriority:(double)priority forTags:(NSSet*)tags STUB_METHOD;
- (double)preservationPriorityForTag:(NSString*)tag STUB_METHOD;

- (Class)classNamed:(NSString*)className;
@property (readonly) Class principalClass STUB_PROPERTY;

@end

#define NSLocalizedString(k, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:nil]
#define NSLocalizedStringFromTable(k, t, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringFromTableInBundle(k, t, b, c) [b localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringWithDefaultValue(k, t, b, v, c) [b localizedStringForKey:k value:v table:t]
