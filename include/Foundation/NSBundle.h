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
#ifndef _NSBUNDLE_H_
#define _NSBUNDLE_H_

#import <Foundation/NSObject.h>
#import <StarboardExport.h>

@class NSArray;
@class NSDictionary;
@class NSString;
@class NSError;
@class NSMutableDictionary;
@class NSURL;

SB_EXPORT NSString* const NSBundleDidLoadNotification;
SB_EXPORT NSString* const NSLoadedClasses;

typedef NS_ENUM(NSUInteger, NSBundleExecutableArchitecture) {
    NSBundleExecutableArchitectureI386 = 0x00000007,
    NSBundleExecutableArchitecturePPC = 0x00000012,
    NSBundleExecutableArchitectureX86_64 = 0x01000007,
    NSBundleExecutableArchitecturePPC64 = 0x01000012
};

struct BundleFile;

FOUNDATION_EXPORT_CLASS
@interface NSBundle : NSObject

@property (readonly, copy) NSURL* bundleURL;
@property (readonly, copy) NSString* bundlePath;
@property (readonly, copy) NSString* resourcePath;

@property (readonly, copy) NSURL* appStoreReceiptURL;

@property (readonly, copy) NSString* bundleIdentifier;
@property (readonly, copy) NSDictionary* infoDictionary;
@property (readonly, copy) NSURL* builtInPlugInsURL;
@property (readonly, copy) NSString* builtInPlugInsPath;
@property (readonly, copy) NSURL* executableURL;
@property (readonly, copy) NSString* executablePath;
@property (readonly, copy) NSURL* privateFrameworksURL;
@property (readonly, copy) NSString* privateFrameworksPath;
@property (readonly, copy) NSURL* sharedFrameworksURL;
@property (readonly, copy) NSString* sharedFrameworksPath;
@property (readonly, copy) NSURL* sharedSupportURL;
@property (readonly, copy) NSString* sharedSupportPath;
@property (readonly, copy) NSURL* resourceURL;

@property (readonly, getter=isLoaded) BOOL loaded;

@property (readonly, copy) NSArray* preferredLocalizations;
@property (readonly, copy) NSString* developmentLocalization;
@property (readonly, copy) NSArray* localizations;
@property (readonly, copy) NSDictionary* localizedInfoDictionary;

@property (readonly, copy) NSArray* executableArchitectures;

@property (readonly) Class principalClass;

+ (NSArray*)allBundles;
+ (NSArray*)allFrameworks;

+ (NSBundle*)mainBundle;

+ (NSBundle*)bundleForClass:(Class)aClass;
+ (NSBundle*)bundleWithIdentifier:(NSString*)identifier;
+ (NSBundle*)bundleWithPath:(NSString*)path;
+ (NSBundle*)bundleWithURL:(NSURL*)url;

+ (NSString*)pathForResource:(NSString*)name ofType:(NSString*)type inDirectory:(NSString*)path;
+ (NSArray*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)path;
+ (NSArray*)preferredLocalizationsFromArray:(NSArray*)localizations;
+ (NSArray*)preferredLocalizationsFromArray:(NSArray*)localizations forPreferences:(NSArray*)preferences;

- initWithPath:(NSString*)path;
- initWithUrl:(NSURL*)url;

- objectForInfoDictionaryKey:(NSString*)key;
- (NSURL*)URLForAuxiliaryExecutable:(NSString*)executableName;

- (NSArray*)localizations;

- (NSString*)pathForAuxiliaryExecutable:(NSString*)executable;

- (Class)classNamed:(NSString*)className;

- (BOOL)preflightAndReturnError:(NSError**)error;
- (BOOL)loadAndReturnError:(NSError**)error;

- (BOOL)load;
- (BOOL)unload;

- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)type;
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)type inDirectory:(NSString*)path;
- (NSString*)pathForResource:(NSString*)name ofType:(NSString*)type inDirectory:(NSString*)path forLocalization:(NSString*)localization;

- (NSArray*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)path;
- (NSArray*)pathsForResourcesOfType:(NSString*)type inDirectory:(NSString*)path forLocalization:(NSString*)localization;

- (NSString*)localizedStringForKey:(NSString*)key value:(NSString*)value table:(NSString*)table;

- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension;
- (NSURL*)URLForResource:(NSString*)name withExtension:(NSString*)extension subdirectory:(NSString*)subpath;
- (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
            localization:(NSString*)localizationName;
+ (NSURL*)URLForResource:(NSString*)name
           withExtension:(NSString*)extension
            subdirectory:(NSString*)subpath
         inBundleWithURL:(NSURL*)bundleURL;
+ (NSArray*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath inBundleWithURL:(NSURL*)bundleURL;
- (NSArray*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath;
- (NSArray*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath localization:(NSString*)localizationName;

- (void)setPreservationPriority:(double)priority forTags:(NSSet*)tags;
- (double)preservationPriorityForTag:(NSString*)tag;

@end

#define NSLocalizedString(k, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:nil]
#define NSLocalizedStringFromTable(k, t, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringFromTableInBundle(k, t, b, c) [b localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringWithDefaultValue(k, t, b, v, c) [b localizedStringForKey:k value:v table:t]

#endif /* _NSBUNDLE_H_ */
