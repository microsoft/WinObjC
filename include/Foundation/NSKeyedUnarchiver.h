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

#import <Foundation/NSCoder.h>

@class NSString;
@class NSData;
@protocol NSKeyedUnarchiverDelegate;

FOUNDATION_EXPORT NSString* const NSInvalidUnarchiveOperationException;

FOUNDATION_EXPORT_CLASS
@interface NSKeyedUnarchiver : NSCoder
- (instancetype)initForReadingWithData:(NSData*)data;
+ (id)unarchiveObjectWithData:(NSData*)data;
+ (id)unarchiveObjectWithFile:(NSString*)path;
- (BOOL)containsValueForKey:(NSString*)key;
- (BOOL)decodeBoolForKey:(NSString*)key;
- (const uint8_t*)decodeBytesForKey:(NSString*)key returnedLength:(NSUInteger*)lengthp;
- (double)decodeDoubleForKey:(NSString*)key;
- (float)decodeFloatForKey:(NSString*)key;
- (int)decodeIntForKey:(NSString*)key;
- (int32_t)decodeInt32ForKey:(NSString*)key;
- (int64_t)decodeInt64ForKey:(NSString*)key;
- (id)decodeObjectForKey:(NSString*)key;
- (void)finishDecoding;

+ (void)setClass:(Class)cls forClassName:(NSString*)codedName;
+ (Class)classForClassName:(NSString*)codedName;
- (void)setClass:(Class)cls forClassName:(NSString*)codedName;
- (Class)classForClassName:(NSString*)codedName;

// Value indicating whether this coder requires secure coding. Once set to YES,
// attempts to set it to NO will result in an exception. This is to avoid classes
// selectively turning off secure coding.
@property (readwrite) BOOL requiresSecureCoding;

// TODO: implement delegate
@property (assign) id<NSKeyedUnarchiverDelegate> delegate;
@end

@protocol NSKeyedUnarchiverDelegate <NSObject>
@optional
- (Class)unarchiver:(NSKeyedUnarchiver*)unarchiver cannotDecodeObjectOfClassName:(NSString*)name originalClasses:(NSArray*)classNames;
- (id)unarchiver:(NSKeyedUnarchiver*)unarchiver didDecodeObject:(id)object;
- (void)unarchiver:(NSKeyedUnarchiver*)unarchiver willReplaceObject:(id)object withObject:(id)newObject;
- (void)unarchiverDidFinish:(NSKeyedUnarchiver*)unarchiver;
- (void)unarchiverWillFinish:(NSKeyedUnarchiver*)unarchiver;
@end
