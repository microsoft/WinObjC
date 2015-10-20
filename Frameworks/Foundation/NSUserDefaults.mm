/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

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

#include "Starboard.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSProcessInfo.h"
#include "Foundation/NSNotificationCenter.h"
#include "Foundation/NSData.h"
#include "Foundation/NSUserDefaults.h"
#include "Foundation/NSThread.h"
#include "NSPersistentDomain.h"

NSString* const NSGlobalDomain = @"NSGlobalDomain";
NSString* const NSArgumentDomain = @"NSArgumentDomain";
NSString* const NSRegistrationDomain = @"NSRegistrationDomain";

NSString* const NSMonthNameArray = @"NSMonthNameArray";
NSString* const NSWeekDayNameArray = @"NSWeekDayNameArray";
NSString* const NSTimeFormatString = @"NSTimeFormatString";
NSString* const NSDateFormatString = @"NSDateFormatString";
NSString* const NSAMPMDesignation = @"NSAMPMDesignation";
NSString* const NSTimeDateFormatString = @"NSTimeDateFormatString";

NSString* const NSShortWeekDayNameArray = @"NSShortWeekDayNameArray";
NSString* const NSShortMonthNameArray = @"NSShortMonthNameArray";

NSString* const NSUserDefaultsDidChangeNotification = @"NSUserDefaultsDidChangeNotification";

@implementation NSUserDefaults {
    NSMutableDictionary* _domains;
    NSMutableArray* _searchList;
    NSDictionary* _dictionaryRep;

    BOOL _willSave;
}
- (instancetype)init {
    _domains = [NSMutableDictionary new];
    _searchList = [[NSMutableArray allocWithZone:nil] initWithCapacity:64];

    [_searchList addObject:NSArgumentDomain];
    [_searchList addObject:[[NSProcessInfo processInfo] processName]];
    [_searchList addObject:NSGlobalDomain];
    [_searchList addObject:NSRegistrationDomain];
    [_searchList addObject:@"Foundation"];

    [[NSProcessInfo processInfo] environment];

    //[self registerFoundationDefaults];
    //[self registerArgumentDefaults];
    //[self registerProcessNameDefaults];

    [_domains setObject:[NSMutableDictionary dictionary] forKey:NSRegistrationDomain];

    id domain = [NSPersistentDomain persistantDomainWithName:@"UserDefaults"];

    [_domains setObject:domain forKey:[[NSProcessInfo processInfo] processName]];

    [self setObject:[NSArray arrayWithObject:@"en"] forKey:@"AppleLanguages"];
    [self setObject:@"en_US" forKey:@"AppleLocale"];

    return self;
}

+ (NSUserDefaults*)standardUserDefaults {
    static NSUserDefaults* standard;

    if (standard == nil) {
        standard = [self new];
    }

    return standard;
}

- (NSMutableDictionary*)_buildDictionaryRep {
    NSMutableDictionary* result = [NSMutableDictionary dictionary];
    NSInteger i, count = [_searchList count];

    for (i = 0; i < count; i++) {
        NSPersistentDomain* domain = [_domains objectForKey:[_searchList objectAtIndex:i]];
        NSEnumerator* state = [domain keyEnumerator];
        id key;

        while ((key = [state nextObject]) != nil) {
            id value = [domain objectForKey:key];

            if (value != nil)
                [result setObject:value forKey:key];
        }
    }

    return result;
}

- (id)dictionaryRepresentation {
    if (_dictionaryRep == nil)
        _dictionaryRep = [[self _buildDictionaryRep] retain];

    return _dictionaryRep;
}

- (void)registerDefaults:(id)values {
    [[_domains objectForKey:NSRegistrationDomain] addEntriesFromDictionary:values];
}

- (NSMutableDictionary*)persistentDomainForName:(id)name {
    NSMutableDictionary* result = [NSMutableDictionary dictionary];
    NSPersistentDomain* domain = [NSPersistentDomain persistantDomainWithName:name];
    NSArray* allKeys = [domain allKeys];
    NSInteger i, count = [allKeys count];

    for (i = 0; i < count; i++) {
        NSString* key = [allKeys objectAtIndex:i];

        [result setObject:[domain objectForKey:key] forKey:key];
    }

    return result;
}

- (void)removePersistentDomainForName:(id)name {
}

- (void)setPersistentDomain:(id)domain forName:(NSString*)name {
    EbrDebugLog("Setting domain for %s\n", [name UTF8String]);
    [_domains setObject:domain forKey:name];
}

- (BOOL)synchronize {
    /*
    if ( ![NSThread isMainThread] ) {
    return FALSE;
    }
    */

    _willSave = FALSE;
    [[self persistantDomain] synchronize];
    return TRUE;
}

- (NSDictionary*)persistantDomain {
    return [_domains objectForKey:[[NSProcessInfo processInfo] processName]];
}

- (id)objectForKey:(NSString*)defaultName {
    NSInteger i, count = [_searchList count];

    for (i = 0; i < count; i++) {
        id domain = [_domains objectForKey:[_searchList objectAtIndex:i]];
        id object = [domain objectForKey:defaultName];

        if (object != nil) {
            return object;
        }
    }

    return nil;
}

- (id)dataForKey:(NSString*)defaultName {
    id data = [self objectForKey:defaultName];

    return [data isKindOfClass:[NSData class]] ? data : nil;
}

- (id)stringForKey:(NSString*)defaultName {
    id string = [self objectForKey:defaultName];

    return [string isKindOfClass:[NSString class]] ? string : nil;
}

- (id)arrayForKey:(NSString*)defaultName {
    id array = [self objectForKey:defaultName];

    return [array isKindOfClass:[NSArray class]] ? array : nil;
}

- (id)dictionaryForKey:(NSString*)defaultName {
    id dictionary = [self objectForKey:defaultName];

    return [dictionary isKindOfClass:[NSDictionary class]] ? dictionary : nil;
}

- (BOOL)boolForKey:(NSString*)defaultName {
    id object = [self objectForKey:defaultName];

    if ([object isKindOfClass:[NSNumber class]])
        return [(NSNumber*)object boolValue];

    if ([object isKindOfClass:[NSString class]])
        return [(NSString*)object boolValue];

    return NO;
}

- (int)integerForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number intValue] : ([number isKindOfClass:[NSNumber class]] ? [number intValue] : 0);
}

- (__int64)longLongForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    __int64 ret = 0;
    if ([number isKindOfClass:[NSString class]]) {
        [number longLongValuePtr:&ret];
    } else {
        if ([number isKindOfClass:[NSNumber class]]) {
            [number _copyInt64Value:&ret];
        }
    }

    return ret;
}

- (float)floatForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number floatValue] :
                                                     ([number isKindOfClass:[NSNumber class]] ? [number floatValue] : 0.0f);
}

- (double)doubleForKey:(NSString*)defaultName {
    id number = [self objectForKey:defaultName];

    return [number isKindOfClass:[NSString class]] ? [number doubleValue] :
                                                     ([number isKindOfClass:[NSNumber class]] ? [number doubleValue] : 0.0);
}

static id deepCopyValue(id obj) {
    if ([obj isKindOfClass:[NSArray class]]) {
        int count = [obj count];
        int i = 0;
        id* objs = (id*)EbrMalloc(count * sizeof(id));
        for (id curObj in obj) {
            objs[i] = deepCopyValue(curObj);
            i++;
        }

        id ret;

        if ([obj isKindOfClass:[NSMutableArray class]]) {
            ret = [[NSMutableArray alloc] initWithObjects:objs count:count];
        } else {
            ret = [[NSArray alloc] initWithObjects:objs count:count];
        }

        for (i = 0; i < count; i++) {
            [objs[i] release];
        }

        EbrFree(objs);

        return ret;
    } else if ([obj isKindOfClass:[NSDictionary class]]) {
        int count = [obj count];
        int i = 0;
        id* objs = (id*)EbrMalloc(count * sizeof(id));
        id* keys = (id*)EbrMalloc(count * sizeof(id));

        for (id curObj in obj) {
            keys[i] = curObj;
            objs[i] = deepCopyValue([obj objectForKey:curObj]);
            i++;
        }

        id ret;
        if ([obj isKindOfClass:[NSMutableDictionary class]]) {
            ret = [[NSMutableDictionary alloc] initWithObjects:objs forKeys:keys count:count];
        } else {
            ret = [[NSDictionary alloc] initWithObjects:objs forKeys:keys count:count];
        }

        for (i = 0; i < count; i++) {
            [objs[i] release];
        }

        EbrFree(objs);
        EbrFree(keys);

        return ret;
    }

    return [obj copy];
}

- (void)setObject:(id)value forKey:(NSString*)key {
    if (value == nil) {
        return;
    }

    value = deepCopyValue(value);

    [[self persistantDomain] setObject:value forKey:key];
    [value release];
    [_dictionaryRep autorelease];
    _dictionaryRep = nil;

    [[NSNotificationCenter defaultCenter] postNotificationName:NSUserDefaultsDidChangeNotification object:self];

    if (!_willSave) {
        _willSave = TRUE;
        if (![NSThread isMainThread]) {
            EbrDebugLog("Warning: NSUserDefaults accessed from non-main thread\n");
            [self performSelectorOnMainThread:@selector(_scheduleSync) withObject:nil waitUntilDone:FALSE];
        } else {
            [self performSelector:@selector(synchronize) withObject:nil afterDelay:1.0];
        }
    }
}

- (id)_scheduleSync {
    [self performSelector:@selector(synchronize) withObject:nil afterDelay:1.0];
    return self;
}

- (void)setURL:(id)value forKey:(NSString*)key {
    [self setObject:value forKey:key];
}

- (void)setBool:(int)value forKey:(NSString*)defaultName {
    [self setObject:value ? @"YES" : @"NO" forKey:defaultName];
}

- (void)setInteger:(int)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithInteger:value] forKey:defaultName];
}

- (void)setLongLong:(__int64)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithLongLong:value] forKey:defaultName];
}

- (void)setFloat:(float)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithFloat:value] forKey:defaultName];
}

- (void)setDouble:(double)value forKey:(NSString*)defaultName {
    [self setObject:[NSNumber numberWithDouble:value] forKey:defaultName];
}

- (void)removeObjectForKey:(NSString*)key {
    [[self persistantDomain] removeObjectForKey:key];

    [[NSNotificationCenter defaultCenter] postNotificationName:NSUserDefaultsDidChangeNotification object:self];
}

- (NSArray*)stringArrayForKey:(NSString*)key {
    id array = [self objectForKey:key];
    NSInteger count;

    if (![array isKindOfClass:[NSArray class]])
        return nil;

    count = [array count];
    while (--count >= 0)
        if (![[array objectAtIndex:count] isKindOfClass:[NSString class]])
            return nil;

    return array;
}

- (id)valueForKey:(NSString*)key {
    // EbrDebugLog("Warning: calling objectForKey for valueForKey\n");

    return [self objectForKey:key];
}

- (NSMutableArray*)mutableArrayValueForKey:(NSString*)key {
    id obj = [self objectForKey:key];
    if (!obj)
        return nil;

    if (![obj isKindOfClass:[NSArray class]]) {
        assert(0);
        return nil;
    }

    if (![obj isKindOfClass:[NSMutableArray class]]) {
        obj = [obj mutableCopy];
        [self setObject:obj forKey:key];
    }

    return obj;
}

- (void)setValue:(id)value forKey:(NSString*)key {
    EbrDebugLog("Warning: callling setObjectForKey for setValueForKey\n");

    [self setObject:value forKey:key];
}

+ (void)resetStandardUserDefaults {
    EbrDebugLog("Warning: resetStandardUserDefaults not implemented\n");
}

- (void)addObserver:(id)observer forKeyPath:(id)keyPath options:(NSKeyValueObservingOptions)options context:(void*)context {
    EbrDebugLog("NSUserDefaults: abbObserver for \"%s\"\n", [keyPath UTF8String]);
}

@end
