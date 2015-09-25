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

// Original - Christopher Lloyd <cjwl@objc.net>

#include "Starboard.h"
#include <math.h>
#include "NSPersistentDomain.h"
#include "Foundation/NSString.h"
#include "Foundation/NSFileManager.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSData.h"

void printContents(int level, id obj) {
    char szLevel[100];

    memset(szLevel, ' ', level * 2);
    szLevel[level * 2] = 0;

    if ([obj isKindOfClass:[NSString class]]) {
        EbrDebugLog("%s%s \"%s\"\n", szLevel, object_getClassName(obj), [obj UTF8String]);
    } else if ([obj isKindOfClass:[NSData class]]) {
        EbrDebugLog("%s%s ", szLevel, object_getClassName(obj));

        int len = [obj length];
        char* bytes = (char*)[obj bytes];

        while (len--) {
            EbrDebugLog("%02X", *bytes);
            bytes++;
        }

        EbrDebugLog("\n");
    } else {
        EbrDebugLog("%s%s\n", szLevel, object_getClassName(obj));
    }

    if ([obj isKindOfClass:[NSDictionary class]]) {
        id keyEnum = [obj keyEnumerator];
        id objEnum = [obj objectEnumerator];

        id curKey, curVal;
        curKey = [keyEnum nextObject];
        curVal = [objEnum nextObject];

        level++;
        memset(szLevel, ' ', level * 2);
        szLevel[level * 2] = 0;

        while (curKey != nil) {
            EbrDebugLog("%sKey=\"%s\"\n", szLevel, [curKey UTF8String]);
            printContents(level + 1, curVal);

            curKey = [keyEnum nextObject];
            curVal = [objEnum nextObject];
        }
    }

    if ([obj isKindOfClass:[NSArray class]]) {
        id objEnum = [obj objectEnumerator];

        id curVal;
        curVal = [objEnum nextObject];

        level++;

        while (curVal != nil) {
            printContents(level, curVal);

            curVal = [objEnum nextObject];
        }
    }
}

@implementation NSPersistentDomain : NSObject
- (instancetype)initWithName:(NSString*)name {
    NSKeyedArchiver* serializedDictionary = nil;

    _path = [@"/Documents" stringByAppendingPathComponent:@"Library"];
    _path = [_path stringByAppendingPathComponent:name];
    _path = [[_path stringByAppendingPathExtension:@"plist"] retain];

    serializedDictionary = [NSKeyedUnarchiver unarchiveObjectWithFile:_path];
    if (serializedDictionary != nil) {
        // printContents(0, serializedDictionary);
        _mutableDomain = [serializedDictionary mutableCopy];
    } else {
        _mutableDomain = [[NSMutableDictionary alloc] init];
    }

    return self;
}

- (void)dealloc {
    [_mutableDomain release];
    [_path release];

    [super dealloc];
}

+ (NSPersistentDomain*)persistantDomainWithName:(NSString*)name {
    return [[[self allocWithZone:nil] initWithName:name] autorelease];
}

- (NSArray*)allKeys {
    return [_mutableDomain allKeys];
}

- (NSEnumerator*)keyEnumerator {
    return [[self allKeys] objectEnumerator];
}

- (id)objectForKey:(NSString*)key {
    return [_mutableDomain objectForKey:key];
}

- (void)setObject:(id)object forKey:(NSString*)key {
    [_mutableDomain setObject:object forKey:key];
    _isDirty = TRUE;
}

- (void)removeObjectForKey:(NSString*)key {
    [_mutableDomain removeObjectForKey:key];
    _isDirty = TRUE;
}

- (void)createUserDefaultsDirectoryIfNeeded {
    BOOL isDirectory;
    id components = [_path pathComponents];
    NSInteger i, count = [components count];
    id check = @"";

    for (i = 0; i < count; i++) {
        // leave the error checking up to -synchronize
        check = [check stringByAppendingPathComponent:[components objectAtIndex:i]];
        if (i > 0 && ![[NSFileManager defaultManager] fileExistsAtPath:check isDirectory:&isDirectory]) {
            [[NSFileManager defaultManager] createDirectoryAtPath:check attributes:nil];
        }
    }
}

- (void)synchronize {
    //[self createUserDefaultsDirectoryIfNeeded];

    if (_isDirty) {
        // printContents(0, _mutableDomain);
        if ([NSKeyedArchiver archiveRootObject:_mutableDomain toFile:_path] == NO) {
            EbrDebugLog("***** Couldn't write user defaults to %s *****\n", [_path UTF8String]);
            // assert(0);
        }
        _isDirty = FALSE;
    }

    //[NSException raise:NSInternalInconsistencyException
    // format:@"Cannot synchronize NSUserDefaults to %@", _path];
}

@end
