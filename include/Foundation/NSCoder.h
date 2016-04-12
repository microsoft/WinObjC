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
// HACKHACK: these should be class extensions in other libraries
// #import <CoreGraphics/CGGeometry.h>
// #import <CoreGraphics/CGAffineTransform.h>
// #import <CoreMedia/CMTime.h>
// #import <CoreMedia/CMTimeRange.h>
@class NSString;
@class NSData;
@class NSSet;

FOUNDATION_EXPORT_CLASS
@interface NSCoder : NSObject
@property (readonly) BOOL allowsKeyedCoding;
- (BOOL)containsValueForKey:(NSString*)key;
- (void)encodeArrayOfObjCType:(const char*)type count:(NSUInteger)count at:(const void*)array;
- (void)encodeBool:(BOOL)boolv forKey:(NSString*)key;
- (void)encodeBycopyObject:(id)anObject;
- (void)encodeByrefObject:(id)anObject;
- (void)encodeBytes:(const void*)byteaddr length:(NSUInteger)length;
- (void)encodeBytes:(const uint8_t*)bytesp length:(NSUInteger)lenv forKey:(NSString*)key;
- (void)encodeConditionalObject:(id)object;
- (void)encodeConditionalObject:(id)objv forKey:(NSString*)key;
- (void)encodeDataObject:(NSData*)data;
- (void)encodeDouble:(double)realv forKey:(NSString*)key;
- (void)encodeFloat:(float)realv forKey:(NSString*)key;
- (void)encodeInt:(int)intv forKey:(NSString*)key;
- (void)encodeInteger:(NSInteger)intv forKey:(NSString*)key;
- (void)encodeInt32:(int32_t)intv forKey:(NSString*)key;
- (void)encodeInt64:(int64_t)intv forKey:(NSString*)key;
- (void)encodeObject:(id)object;
- (void)encodeObject:(id)objv forKey:(NSString*)key;
- (void)encodeRootObject:(id)rootObject;
- (void)encodeValueOfObjCType:(const char*)type at:(const void*)addr;
- (void)encodeValuesOfObjCTypes:(const char*)types, ...;
//  HACKHACK: these should be class extensions in other libraries
// - (void)encodeCMTime:(CMTime)time forKey:(NSString*)key;
// - (void)encodeCMTimeRange:(CMTimeRange)timeRange forKey:(NSString*)key;
// - (void)encodeCMTimeMapping:(CMTimeMapping)timeMapping forKey:(NSString*)key;
- (void)decodeArrayOfObjCType:(const char*)itemType count:(NSUInteger)count at:(void*)array;
- (BOOL)decodeBoolForKey:(NSString*)key;
- (const uint8_t*)decodeBytesForKey:(NSString*)key returnedLength:(NSUInteger*)lengthp;
- (void*)decodeBytesWithReturnedLength:(NSUInteger*)lengthp;
- (NSData*)decodeDataObject;
- (double)decodeDoubleForKey:(NSString*)key;
- (float)decodeFloatForKey:(NSString*)key;
- (int)decodeIntForKey:(NSString*)key;
- (NSInteger)decodeIntegerForKey:(NSString*)key;
- (int32_t)decodeInt32ForKey:(NSString*)key;
- (int64_t)decodeInt64ForKey:(NSString*)key;
- (id)decodeObject;
- (id)decodeObjectForKey:(NSString*)key;
- (void)decodeValueOfObjCType:(const char*)type at:(void*)data;
- (void)decodeValuesOfObjCTypes:(const char*)types, ...;
- (id)decodeObjectOfClass:(Class)aClass forKey:(NSString*)key;
- (id)decodeObjectOfClasses:(NSSet*)classes forKey:(NSString*)key;
- (id)decodePropertyListForKey:(NSString*)key STUB_METHOD;
// HACKHACK: these should be class extensions in other libraries
// - (CMTime)decodeCMTimeForKey:(NSString*)key;
// - (CMTimeRange)decodeCMTimeRangeForKey:(NSString*)key;
// - (CMTimeMapping)decodeCMTimeMappingForKey:(NSString*)key;

// Value indicating whether this coder requires secure coding.
@property (readonly) BOOL requiresSecureCoding;

// The set of classes allowable for secure coding. Every class in this set must conform to the NSSecureCoding protocol
@property (readonly, copy) NSSet* allowedClasses;

@property (readonly) unsigned int systemVersion;

- (NSInteger)versionForClassName:(NSString*)className;
- (NSZone*)objectZone;
- (void)setObjectZone:(NSZone*)zone;
@end
