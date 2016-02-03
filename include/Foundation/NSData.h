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
#import <Foundation/NSRange.h>

@class NSString;
@class NSError;
@class NSURL;

typedef NSUInteger NSDataReadingOptions;
typedef NSUInteger NSDataBase64EncodingOptions;
typedef NSUInteger NSDataBase64DecodingOptions;
typedef NSUInteger NSDataWritingOptions;
typedef NSUInteger NSDataSearchOptions;
enum {
    NSDataReadingMappedIfSafe = 1UL << 0,
    NSDataReadingUncached = 1UL << 1,
    NSDataReadingMappedAlways = 1UL << 3,
};

enum {
    NSDataBase64Encoding64CharacterLineLength = 1UL << 0,
    NSDataBase64Encoding76CharacterLineLength = 1UL << 1,
    NSDataBase64EncodingEndLineWithCarriageReturn = 1UL << 4,
    NSDataBase64EncodingEndLineWithLineFeed = 1UL << 5,
};

enum { NSDataBase64DecodingIgnoreUnknownCharacters = 1UL << 0 };
enum { NSDataReadingMapped = NSDataReadingMappedIfSafe, NSMappedRead = NSDataReadingMapped, NSUncachedRead = NSDataReadingUncached };
enum {
    NSDataWritingAtomic = 1UL << 0,
    NSDataWritingWithoutOverwriting = 1UL << 1,
    NSDataWritingFileProtectionNone = 0x10000000,
    NSDataWritingFileProtectionComplete = 0x20000000,
    NSDataWritingFileProtectionCompleteUnlessOpen = 0x30000000,
    NSDataWritingFileProtectionCompleteUntilFirstUserAuthentication = 0x40000000,
    NSDataWritingFileProtectionMask = 0xf0000000,
};

enum { NSAtomicWrite = NSDataWritingAtomic };
enum { NSDataSearchBackwards = 1UL << 0, NSDataSearchAnchored = 1UL << 1 };

FOUNDATION_EXPORT_CLASS
@interface NSData : NSObject <NSCopying, NSMutableCopying, NSSecureCoding> {
    uint8_t* _bytes;
    size_t _length;
    BOOL _freeWhenDone;
}

+ (instancetype)data;
+ (instancetype)dataWithBytes:(const void*)bytes length:(NSUInteger)length;
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
+ (instancetype)dataWithContentsOfFile:(NSString*)path;
+ (instancetype)dataWithContentsOfFile:(NSString*)path options:(NSDataReadingOptions)mask error:(NSError* _Nullable*)errorPtr;
+ (id)dataWithContentsOfMappedFile:(NSString*)path;
+ (instancetype)dataWithContentsOfURL:(NSURL*)aURL;
+ (instancetype)dataWithContentsOfURL:(NSURL*)aURL options:(NSDataReadingOptions)mask error:(NSError* _Nullable*)errorPtr;
+ (instancetype)dataWithData:(NSData*)aData;
- (instancetype)initWithBase64EncodedData:(NSData*)base64Data options:(NSDataBase64DecodingOptions)options;
- (instancetype)initWithBase64EncodedString:(NSString*)base64String options:(NSDataBase64DecodingOptions)options;
- (id)initWithBase64Encoding:(NSString*)base64String;
- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length deallocator:(void (^)(void*, NSUInteger))deallocator;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)flag;
- (instancetype)initWithContentsOfFile:(NSString*)path;
- (instancetype)initWithContentsOfFile:(NSString*)path options:(NSDataReadingOptions)mask error:(NSError* _Nullable*)errorPtr;
- (id)initWithContentsOfMappedFile:(NSString*)path;
- (instancetype)initWithContentsOfURL:(NSURL*)aURL;
- (instancetype)initWithContentsOfURL:(NSURL*)aURL options:(NSDataReadingOptions)mask error:(NSError* _Nullable*)errorPtr;
- (instancetype)initWithData:(NSData*)data;
@property (readonly) const void* bytes;
@property (readonly, copy) NSString* description;
- (void)enumerateByteRangesUsingBlock:(void (^)(const void*, NSRange, BOOL*))block;
- (void)getBytes:(void*)buffer;
- (void)getBytes:(void*)buffer length:(NSUInteger)length;
- (void)getBytes:(void*)buffer range:(NSRange)range;
- (NSData*)subdataWithRange:(NSRange)range;
- (NSRange)rangeOfData:(NSData*)dataToFind options:(NSDataSearchOptions)mask range:(NSRange)searchRange;
- (NSData*)base64EncodedDataWithOptions:(NSDataBase64EncodingOptions)options;
- (NSString*)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options;
- (NSString*)base64Encoding;
- (BOOL)isEqualToData:(NSData*)otherData;
@property (readonly) NSUInteger length;
- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)atomically;
- (BOOL)writeToFile:(NSString*)path options:(NSDataWritingOptions)mask error:(NSError* _Nullable*)errorPtr;
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL*)aURL options:(NSDataWritingOptions)mask error:(NSError* _Nullable*)errorPtr;
@end
