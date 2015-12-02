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
@class NSData;
@class NSMutableDictionary;
@class NSDictionary;
@class NSMutableArray;
@class NSURL;

FOUNDATION_EXPORT NSString* const NSGlobalDomain;
FOUNDATION_EXPORT NSString* const NSArgumentDomain;
FOUNDATION_EXPORT NSString* const NSRegistrationDomain;

FOUNDATION_EXPORT NSString* const NSMonthNameArray;
FOUNDATION_EXPORT NSString* const NSWeekDayNameArray;
FOUNDATION_EXPORT NSString* const NSTimeFormatString;
FOUNDATION_EXPORT NSString* const NSDateFormatString;
FOUNDATION_EXPORT NSString* const NSAMPMDesignation;

FOUNDATION_EXPORT NSString* const NSTimeDateFormatString;

FOUNDATION_EXPORT NSString* const NSShortWeekDayNameArray;
FOUNDATION_EXPORT NSString* const NSShortMonthNameArray;

FOUNDATION_EXPORT NSString* const NSUserDefaultsDidChangeNotification;

FOUNDATION_EXPORT_CLASS
@interface NSUserDefaults : NSObject

// Getting the Shared NSUserDefaults Instance
+ (NSUserDefaults*)standardUserDefaults;
+ (void)resetStandardUserDefaults;

// Initializing an NSUserDefaults Object
- (instancetype)init;
- (instancetype)initWithUser:(NSString*)user;
- (instancetype)initWithSuiteName:(NSString*)suitename;

// Registering Defaults
- (void)registerDefaults:(NSDictionary*)dictionary;

// Getting Default Values
- (NSArray*)arrayForKey:(NSString*)defaultName;
- (BOOL)boolForKey:(NSString*)defaultName;
- (NSData*)dataForKey:(NSString*)defaultName;
- (NSDictionary*)dictionaryForKey:(NSString*)defaultName;
- (float)floatForKey:(NSString*)defaultName;
- (NSInteger)integerForKey:(NSString*)defaultName;
- (id)objectForKey:(NSString*)defaultName;
- (NSArray*)stringArrayForKey:(NSString*)defaultName;
- (NSString*)stringForKey:(NSString*)defaultName;
- (double)doubleForKey:(NSString*)defaultName;
- (NSURL*)URLForKey:(NSString*)defaultName;

// Setting Default Values
- (void)setBool:(BOOL)value forKey:(NSString*)defaultName;
- (void)setFloat:(float)value forKey:(NSString*)defaultName;
- (void)setInteger:(NSInteger)value forKey:(NSString*)defaultName;
- (void)setObject:(id)value forKey:(NSString*)defaultName;
- (void)setDouble:(double)value forKey:(NSString*)defaultName;
- (void)setURL:(NSURL*)url forKey:(NSString*)defaultName;

// Removing Defaults
- (void)removeObjectForKey:(NSString*)defaultName;

// Maintaining Persistent Domains
- (BOOL)synchronize;
- (NSDictionary*)persistentDomainForName:(NSString*)domainName;
- (NSArray*)persistentDomainNames;
- (void)removePersistentDomainForName:(NSString*)domainName;
- (void)setPersistentDomain:(NSDictionary*)domain forName:(NSString*)domainName;

// Accessing Managed Environment Keys
- (BOOL)objectIsForcedForKey:(NSString*)key;
- (BOOL)objectIsForcedForKey:(NSString*)key inDomain:(NSString*)domain;

// Managing the Search List
- (NSDictionary*)dictionaryRepresentation;
- (void)removeVolatileDomainForName:(NSString*)domainName;
- (void)setVolatileDomain:(NSDictionary*)domain forName:(NSString*)domainName;
- (NSDictionary*)volatileDomainForName:(NSString*)domainName;
@property (readonly, copy) NSArray* volatileDomainNames;

// Maintaining Suites
- (void)addSuiteNamed:(NSString*)suiteName;
- (void)removeSuiteNamed:(NSString*)suiteName;

@end
