/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSString.h"
#import "Foundation/NSMutableDictionary.h"
#import "Foundation/NSNumber.h"
#import "Foundation/NSNotificationCenter.h"
#import "Foundation/NSData.h"
#import "Foundation/NSUserDefaults.h"
#import "Foundation/NSThread.h"
#import "NSStringInternal.h"
#import "LoggingNative.h"
#import "ForFoundationOnly.h"
#import <CoreFoundation/CFPreferences.h>

static const wchar_t* TAG = L"NSUserDefaults";

FOUNDATION_EXPORT NSString* const NSGlobalDomain = @"NSGlobalDomain";
FOUNDATION_EXPORT NSString* const NSArgumentDomain = @"NSArgumentDomain";
FOUNDATION_EXPORT NSString* const NSRegistrationDomain = @"NSRegistrationDomain";

FOUNDATION_EXPORT NSString* const NSMonthNameArray = @"NSMonthNameArray";
FOUNDATION_EXPORT NSString* const NSWeekDayNameArray = @"NSWeekDayNameArray";
FOUNDATION_EXPORT NSString* const NSTimeFormatString = @"NSTimeFormatString";
FOUNDATION_EXPORT NSString* const NSDateFormatString = @"NSDateFormatString";
FOUNDATION_EXPORT NSString* const NSAMPMDesignation = @"NSAMPMDesignation";
FOUNDATION_EXPORT NSString* const NSTimeDateFormatString = @"NSTimeDateFormatString";
FOUNDATION_EXPORT NSString* const NSShortWeekDayNameArray = @"NSShortWeekDayNameArray";
FOUNDATION_EXPORT NSString* const NSShortMonthNameArray = @"NSShortMonthNameArray";

FOUNDATION_EXPORT NSString* const NSUserDefaultsDidChangeNotification = @"NSUserDefaultsDidChangeNotification";

@implementation NSUserDefaults {
    StrongId<NSMutableDictionary> _registrationDict;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    [super init];

    _registrationDict = [NSMutableDictionary dictionary];

    [self setObject:[NSArray arrayWithObject:@"en"] forKey:@"AppleLanguages"];
    [self setObject:@"en_US" forKey:@"AppleLocale"];

    return self;
}

/**
 @Status Interoperable
*/
+ (NSUserDefaults*)standardUserDefaults {
    static NSUserDefaults* standard;

    if (standard == nil) {
        standard = [self new];
    }

    return standard;
}

/**
 @Status Interoperable
*/
- (id)dictionaryRepresentation {
    _CFApplicationPreferences* preferences = _CFStandardApplicationPreferences(kCFPreferencesCurrentApplication);
    CFDictionaryRef dict = _CFApplicationPreferencesCopyRepresentation(preferences);
    return [(NSDictionary*)dict autorelease];
}

/**
 @Status Interoperable
*/
- (void)registerDefaults:(NSDictionary*)dictionary {
    [_registrationDict addEntriesFromDictionary:dictionary];
}

/**
 @Status Stub
*/
- (NSMutableDictionary*)persistentDomainForName:(id)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)removePersistentDomainForName:(id)name {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setPersistentDomain:(id)domain forName:(NSString*)name {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)synchronize {
    return CFPreferencesAppSynchronize(kCFPreferencesCurrentApplication);
}

/**
 @Status Interoperable
*/
- (id)objectForKey:(NSString*)defaultName {
    id obj = [(id)CFPreferencesCopyAppValue(static_cast<CFStringRef>(defaultName), kCFPreferencesCurrentApplication) autorelease];

    if (!obj) {
        obj = [_registrationDict objectForKey:defaultName];
    }

    return obj;
}

/**
 @Status Interoperable
*/
- (id)dataForKey:(NSString*)defaultName {
    id data = [self objectForKey:defaultName];

    return [data isKindOfClass:[NSData class]] ? data : nil;
}

/**
 @Status Interoperable
*/
- (id)stringForKey:(NSString*)defaultName {
    id string = [self objectForKey:defaultName];

    return [string isKindOfClass:[NSString class]] ? string : nil;
}

/**
 @Status Interoperable
*/
- (id)arrayForKey:(NSString*)defaultName {
    id array = [self objectForKey:defaultName];

    return [array isKindOfClass:[NSArray class]] ? array : nil;
}

/**
 @Status Interoperable
*/
- (id)dictionaryForKey:(NSString*)defaultName {
    id dictionary = [self objectForKey:defaultName];

    return [dictionary isKindOfClass:[NSDictionary class]] ? dictionary : nil;
}

/**
 @Status Interoperable
*/
- (BOOL)boolForKey:(NSString*)defaultName {
    id object = [self objectForKey:defaultName];

    if ([object isKindOfClass:[NSNumber class]]) {
        return [(NSNumber*)object boolValue];
    }

    if ([object isKindOfClass:[NSString class]]) {
        return [(NSString*)object boolValue];
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (int)integerForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number intValue] : ([number isKindOfClass:[NSNumber class]] ? [number intValue] : 0);
}

- (__int64)longLongForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    __int64 ret = 0;
    if ([number isKindOfClass:[NSString class]]) {
        ret = [static_cast<NSString*>(number) longLongValue];
    } else {
        if ([number isKindOfClass:[NSNumber class]]) {
            ret = [number longLongValue];
        }
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (float)floatForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number floatValue] :
                                                     ([number isKindOfClass:[NSNumber class]] ? [number floatValue] : 0.0f);
}

/**
 @Status Interoperable
*/
- (double)doubleForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number doubleValue] :
                                                     ([number isKindOfClass:[NSNumber class]] ? [number doubleValue] : 0.0);
}

/**
 @Status Interoperable
*/
- (void)setObject:(id)value forKey:(NSString*)key {
    if (value == nil) {
        return;
    }

    CFTypeRef valueCopy = CFAutorelease(CFPropertyListCreateDeepCopy(kCFAllocatorDefault, value, kCFPropertyListMutableContainersAndLeaves));

    CFPreferencesSetAppValue(static_cast<CFStringRef>(key), valueCopy, kCFPreferencesCurrentApplication);

    [[NSNotificationCenter defaultCenter] postNotificationName:NSUserDefaultsDidChangeNotification object:self];
}

/**
 @Status Caveat
 @Notes  setURL does not support file Reference URL, and also doesn't support abbreviate the path with
 user's home directory for file path URL, instead, path string is stored for file path URL regardless.
 */
- (void)setURL:(NSURL*)url forKey:(NSString*)defaultName {
    // reference documentation says setURL should do followings
    // 1. for Non-File URL, persisting the NSData generated by NSKeyedArchiver:archivedDataWithRootObject
    //    with the NSURL
    // 2. for file reference URL, will be treated as non-FileURL, and information which makes this URL
    //    compatible with 10.5 needs to be written as part of the archive as well as its minimal bookmark data
    // 3. for file path-based URL, getting the path and determine if the path can be treated as relative path
    //    against to user's home directory, if so, the string is abbreviated by using stringByAbbrevitaingWithTildeInPath.
    if (url == nil) {
        [self removeObjectForKey:defaultName];
    } else if (![url isFileURL]) {
        // non-file URL case, e.g., http://
        NSData* data = [NSKeyedArchiver archivedDataWithRootObject:url];
        [self setObject:data forKey:defaultName];

    } else if ([url isFileReferenceURL]) {
        // file reference URL case. we don't support it.
        UNIMPLEMENTED();
    } else {
        // TODO: for now, just save the whole URL
        [self setObject:[url absoluteString] forKey:defaultName];
    }
}

/**
 @Status Caveat
 @Notes since setURL does not support file reference URL, URLForKey does not support that too. For file path URL, since
 setURL does not support abbreviating file path with home directory,  URLForKey will not expanding the path with
 user home directory too.
 */
- (NSURL*)URLForKey:(NSString*)defaultName {
    id result = nil;

    id obj = [self objectForKey:defaultName];
    if (obj != nil) {
        if ([obj isKindOfClass:[NSData class]]) {
            // non-file URL case
            result = [NSKeyedUnarchiver unarchiveObjectWithData:obj];
        } else if ([obj isKindOfClass:[NSString class]]) {
            // TODO: file path URL, no expansion currently since no abbreviation in SetURL
            result = [NSURL URLWithString:obj];
        } else {
            // we don't support file reference URL
            UNIMPLEMENTED();
        }
    }

    return result;
}

/**
 @Status Interoperable
*/
- (void)setBool:(int)value forKey:(NSString*)defaultName {
    [self setObject:value ? @"YES" : @"NO" forKey:defaultName];
}

/**
 @Status Interoperable
*/
- (void)setInteger:(int)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithInteger:value] forKey:defaultName];
}

- (void)setLongLong:(__int64)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithLongLong:value] forKey:defaultName];
}

/**
 @Status Interoperable
*/
- (void)setFloat:(float)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithFloat:value] forKey:defaultName];
}

/**
 @Status Interoperable
*/
- (void)setDouble:(double)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithDouble:value] forKey:defaultName];
}

/**
 @Status Interoperable
*/
- (void)removeObjectForKey:(NSString*)key {
    CFPreferencesSetAppValue((CFStringRef)key, NULL, kCFPreferencesCurrentApplication);

    [[NSNotificationCenter defaultCenter] postNotificationName:NSUserDefaultsDidChangeNotification object:self];
}

/**
 @Status Interoperable
*/
- (NSArray*)stringArrayForKey:(NSString*)key {
    id array = [self objectForKey:key];
    NSInteger count;

    if (![array isKindOfClass:[NSArray class]]) {
        return nil;
    }

    count = [array count];
    while (--count >= 0) {
        if (![[array objectAtIndex:count] isKindOfClass:[NSString class]]) {
            return nil;
        }
    }

    return array;
}

/**
 @Status Interoperable
*/
- (id)valueForKey:(NSString*)key {
    return [self objectForKey:key];
}

/**
 @Status Interoperable
*/
- (void)setValue:(id)value forKey:(NSString*)key {
    [self setObject:value forKey:key];
}

/**
 @Status Stub
*/
+ (void)resetStandardUserDefaults {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithUser:(NSString*)username {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithSuiteName:(NSString*)suitename {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)persistentDomainNames {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)objectIsForcedForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)objectIsForcedForKey:(NSString*)key inDomain:(NSString*)domain {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeVolatileDomainForName:(NSString*)domainName {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setVolatileDomain:(NSDictionary*)domain forName:(NSString*)domainName {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSDictionary*)volatileDomainForName:(NSString*)domainName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addSuiteNamed:(NSString*)suiteName {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeSuiteNamed:(NSString*)suiteName {
    UNIMPLEMENTED();
}

@end
