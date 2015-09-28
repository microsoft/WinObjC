/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSDICTIONARY_H_
#define _NSDICTIONARY_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSEnumerator.h>
#import <CoreFoundation/CFDictionary.h>

@class NSArray;
@class NSURL;
@class NSSet;

#define __CFDICTIONARY_SIZE_BYTES   (0x54)

FOUNDATION_EXPORT_CLASS
@interface NSDictionary : NSObject <NSCoding, NSCopying, NSMutableCopying, NSFastEnumeration>
{
@public
    CFMutableDictionaryRef dict;
    uint32_t _dictSpace[((__CFDICTIONARY_SIZE_BYTES + 3) & ~3) / 4];
}

- initWithObjects:(id *)objects forKeys:(id *)keys count:(NSUInteger)count;
- initWithObjects:(NSArray *)objects forKeys:(NSArray *)keys;
- initWithDictionary:(NSDictionary *)dictionary;
- initWithDictionary:(NSDictionary *)dictionary copyItems:(BOOL)copyItems;
- initWithObjectsAndKeys:object,...;
- initWithContentsOfFile:(NSString *)path;
- initWithContentsOfURL:(NSURL *)url;

+ dictionary;
+ dictionaryWithObjects:(id *)objects forKeys:(id *)keys count:(NSUInteger)count;
+ dictionaryWithObjects:(NSArray *)objects forKeys:(NSArray *)keys;
+ dictionaryWithDictionary:(NSDictionary *)other;
+ dictionaryWithObjectsAndKeys:first,...;
+ dictionaryWithObject:object forKey:key;
+ dictionaryWithContentsOfFile:(NSString *)path;
+ dictionaryWithContentsOfURL:(NSURL *)url;

- (NSUInteger)count;
- (NSEnumerator *)keyEnumerator;
- (NSEnumerator *)objectEnumerator;

- (void)getObjects:(id *)objects andKeys:(id *)keys;

- (BOOL)isEqualToDictionary:(NSDictionary *)dictionary;

- (NSArray *)allKeys;
- (NSArray *)allKeysForObject:object;    
- (NSArray *)keysSortedByValueUsingSelector:(SEL)selector;

- (NSArray *)allValues;
- (NSArray *)objectsForKeys:(NSArray *)keys notFoundMarker:marker;

- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;

- (NSString *)description;
- (NSString *)descriptionInStringsFileFormat;
- (NSString *)descriptionWithLocale:locale;
- (NSString *)descriptionWithLocale:locale indent:(NSUInteger)indent;

- (id)objectForKey:(id)aKey;
- (id)objectForKeyedSubscript:(id)key;

- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(id key, id obj, BOOL *stop))block;
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id key, id obj, BOOL *stop))block;
- (NSSet *)keysOfEntriesPassingTest:(BOOL (^)(id key, id obj, BOOL *stop))predicate;
- (NSSet *)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id key, id obj, BOOL *stop))predicate;
- (NSArray *)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (NSArray *)keysSortedByValueUsingComparator:(NSComparator)cmptr;

@end

FOUNDATION_EXPORT NSDictionary* _NSDictionaryOfVariableBindings(NSString *keys, ...);

#import <Foundation/NSMutableDictionary.h>

#endif /* _NSDICTIONARY_H_ */