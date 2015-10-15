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

#ifndef __NSDICTIONARY_H
#define __NSDICTIONARY_H

class __CFDictionary;
#define __CFDICTIONARY_SIZE_BYTES (0x54)
@interface NSDictionary : NSObject {
@public
    __CFDictionary* dict;
    DWORD _dictSpace[((__CFDICTIONARY_SIZE_BYTES + 3) & ~3) / 4];
}
- (__int64)fileSize;
- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count;
- (instancetype)initWithObjectsTakeOwnership:(id*)vals forKeys:(id*)keys count:(unsigned)count;
- (instancetype)initWithObjectsAndKeys:(id)firstObj, ...;
- (instancetype)initWithObjects:(id)vals forKeys:(id)keys;
- (instancetype)initWithObject:(id)val forKey:(id)key;
- (id)initWithCoder:(id)coder;
- (id)objectForKey:(id)key;
- (id)objectForKeyedSubscript:(id)key;
- (id)valueForKey:(id)key;
- (instancetype)initWithDictionary:(NSDictionary*)dict;
- (NSDictionary*)initWithDictionary:(NSDictionary*)dict copyItems:(BOOL)copyItems;
- (NSDictionary*)initWithContentsOfFile:(NSString*)filename;
- (NSDictionary*)initWithContentsOfURL:(id)url;
- (NSDictionary*)init;
- (NSArray*)allValues;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (unsigned)count;
- (unsigned)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(unsigned)maxCount;
- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically;
- (NSEnumerator*)objectEnumerator;
- (NSEnumerator*)keyEnumerator;
- (NSString*)fileType;
- (NSDate*)fileModificationDate;
- (NSDate*)fileCreationDate;
- (id)classForArchiver;
- (void)encodeWithCoder:(NSCoder*)coder;
- (void)dealloc;
- (NSMutableDictionary*)mutableCopyWithZone:(id)zone;
- (instancetype)copyWithZone:(id)zone;
- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToDictionary:(NSDictionary*)dictionary;
- (NSArray*)keysSortedByValueUsingSelector:(SEL)selector;
- (NSArray*)keysSortedByValueUsingComparator:(id)comparator;
- (NSString*)description;
- (NSString*)stringFromQueryComponents;
- (void)getObjects:(id*)objects andKeys:(id*)keys;
- (void)enumerateKeysAndObjectsUsingBlock:(id)block;
- (NSArray*)objectsForKeys:(NSArray*)keys notFoundMarker:(id)notFoundMarker;
+ (instancetype)dictionaryWithObjectsAndKeys:(id)firstObj, ...;
+ (instancetype)dictionaryWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count;
+ (instancetype)dictionaryWithObject:(id)val forKey:(id)key;
+ (instancetype)dictionaryWithDictionary:(NSDictionary*)dictionary;
+ (instancetype)dictionaryWithObjects:(NSArray*)vals forKeys:(NSArray*)keys;
+ (NSDictionary*)dictionaryWithContentsOfFile:(NSString*)filename;
+ (NSDictionary*)dictionaryWithContentsOfURL:(NSURL*)url;
+ (NSDictionary*)dictionary;
@end

#endif
