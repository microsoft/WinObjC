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

@class NSString;
@class NSDictionary;
@class NSArray;
@class NSData;
@class NSURL;

FOUNDATION_EXPORT NSString* const NSGlobalDomain;
FOUNDATION_EXPORT NSString* const NSArgumentDomain;
FOUNDATION_EXPORT NSString* const NSRegistrationDomain;
FOUNDATION_EXPORT NSString* const NSUserDefaultsDidChangeNotification;

FOUNDATION_EXPORT NSString* const NSMonthNameArray;
FOUNDATION_EXPORT NSString* const NSWeekDayNameArray;
FOUNDATION_EXPORT NSString* const NSTimeFormatString;
FOUNDATION_EXPORT NSString* const NSDateFormatString;
FOUNDATION_EXPORT NSString* const NSAMPMDesignation;
FOUNDATION_EXPORT NSString* const NSTimeDateFormatString;
FOUNDATION_EXPORT NSString* const NSShortWeekDayNameArray;
FOUNDATION_EXPORT NSString* const NSShortMonthNameArray;

FOUNDATION_EXPORT_CLASS
@interface NSUserDefaults : NSObject
+ (NSUserDefaults*)standardUserDefaults;
+ (void)resetStandardUserDefaults;
- (instancetype)init;
- (id)initWithUser:(NSString*)username STUB_METHOD;
- (instancetype)initWithSuiteName:(NSString*)suitename;
- (void)registerDefaults:(NSDictionary*)dictionary;
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
- (void)setBool:(BOOL)value forKey:(NSString*)defaultName;
- (void)setFloat:(float)value forKey:(NSString*)defaultName;
- (void)setInteger:(NSInteger)value forKey:(NSString*)defaultName;
- (void)setObject:(id)value forKey:(NSString*)defaultName;
- (void)setDouble:(double)value forKey:(NSString*)defaultName;
- (void)setURL:(NSURL*)url forKey:(NSString*)defaultName;
- (void)removeObjectForKey:(NSString*)defaultName;
- (BOOL)synchronize;
- (NSDictionary*)persistentDomainForName:(NSString*)domainName STUB_METHOD;
- (NSArray*)persistentDomainNames STUB_METHOD;
- (void)removePersistentDomainForName:(NSString*)domainName STUB_METHOD;
- (void)setPersistentDomain:(NSDictionary*)domain forName:(NSString*)domainName STUB_METHOD;
- (BOOL)objectIsForcedForKey:(NSString*)key STUB_METHOD;
- (BOOL)objectIsForcedForKey:(NSString*)key inDomain:(NSString*)domain STUB_METHOD;
- (NSDictionary*)dictionaryRepresentation;
- (void)removeVolatileDomainForName:(NSString*)domainName STUB_METHOD;
- (void)setVolatileDomain:(NSDictionary*)domain forName:(NSString*)domainName STUB_METHOD;
- (NSDictionary*)volatileDomainForName:(NSString*)domainName STUB_METHOD;
@property (readonly, copy) NSArray* volatileDomainNames;
- (void)addSuiteNamed:(NSString*)suiteName STUB_METHOD;
- (void)removeSuiteNamed:(NSString*)suiteName STUB_METHOD;
@end
