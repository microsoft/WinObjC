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

#import <Foundation/NSPropertyListSerialization.h>
#import <Foundation/NSCoder.h>

@class NSString;
@class NSMutableData;
@class NSData;
@protocol NSKeyedArchiverDelegate;

FOUNDATION_EXPORT NSString* const NSInvalidArchiveOperationException;
FOUNDATION_EXPORT NSString* const NSKeyedArchiveRootObjectKey;

FOUNDATION_EXPORT_CLASS
@interface NSKeyedArchiver : NSCoder
- (instancetype)initForWritingWithMutableData:(NSMutableData*)data;
+ (NSData*)archivedDataWithRootObject:(id)rootObject;
+ (BOOL)archiveRootObject:(id)rootObject toFile:(NSString*)path;
- (void)finishEncoding;
@property NSPropertyListFormat outputFormat;
@property (readwrite) BOOL requiresSecureCoding;
- (void)encodeBool:(BOOL)boolv forKey:(NSString*)key;
- (void)encodeBytes:(const uint8_t*)bytesp length:(NSUInteger)lenv forKey:(NSString*)key;
- (void)encodeConditionalObject:(id)objv forKey:(NSString*)key;
- (void)encodeDouble:(double)realv forKey:(NSString*)key;
- (void)encodeFloat:(float)realv forKey:(NSString*)key;
- (void)encodeInt:(int)intv forKey:(NSString*)key;
- (void)encodeInt32:(int32_t)intv forKey:(NSString*)key;
- (void)encodeInt64:(int64_t)intv forKey:(NSString*)key;
- (void)encodeObject:(id)objv forKey:(NSString*)key;
@property (assign) id<NSKeyedArchiverDelegate> delegate;
+ (void)setClassName:(NSString*)codedName forClass:(Class)cls;
+ (NSString*)classNameForClass:(Class)cls;
- (void)setClassName:(NSString*)codedName forClass:(Class)cls;
- (NSString*)classNameForClass:(Class)cls;
@end

@protocol NSKeyedArchiverDelegate <NSObject>
@optional
- (void)archiver:(NSKeyedArchiver*)archiver didEncodeObject:(id)object;
- (void)archiverDidFinish:(NSKeyedArchiver*)archiver;
- (id)archiver:(NSKeyedArchiver*)archiver willEncodeObject:(id)object;
- (void)archiverWillFinish:(NSKeyedArchiver*)archiver;
- (void)archiver:(NSKeyedArchiver*)archiver willReplaceObject:(id)object withObject:(id)newObject;
@end
