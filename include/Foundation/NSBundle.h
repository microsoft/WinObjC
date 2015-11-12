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

struct BundleFile;

FOUNDATION_EXPORT_CLASS
@interface NSBundle : NSObject

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

- (NSString*)bundlePath;
- (NSString*)resourcePath;
- (NSURL*)bundleURL;
- (NSString*)builtInPlugInsPath;
- (NSDictionary*)infoDictionary;
- (NSDictionary*)localizedInfoDictionary;
- objectForInfoDictionaryKey:(NSString*)key;
- (NSString*)bundleIdentifier;
- (NSString*)developmentLocalization;
- (NSArray*)executableArchitectures;
- (NSString*)executablePath;
- (NSArray*)localizations;
- (NSArray*)preferredLocalizations;
- (NSString*)privateFrameworksPath;
- (NSString*)sharedFrameworksPath;
- (NSString*)sharedSupportPath;
- (NSURL*)appStoreReceiptURL;

- (NSString*)pathForAuxiliaryExecutable:(NSString*)executable;

- (Class)principalClass;
- (Class)classNamed:(NSString*)className;

- (BOOL)isLoaded;
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
- (NSArray*)URLsForResourcesWithExtension:(NSString*)extension subdirectory:(NSString*)subpath;

@end

#define NSLocalizedString(k, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:nil]
#define NSLocalizedStringFromTable(k, t, c) [[NSBundle mainBundle] localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringFromTableInBundle(k, t, b, c) [b localizedStringForKey:k value:@"" table:t]
#define NSLocalizedStringWithDefaultValue(k, t, b, v, c) [b localizedStringForKey:k value:v table:t]

#endif /* _NSBUNDLE_H_ */
