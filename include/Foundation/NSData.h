/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSDATA_H_
#define _NSDATA_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

typedef NS_OPTIONS(NSUInteger, NSDataReadingOptions) {
    NSDataReadingMappedIfSafe = 1UL << 0,
    NSDataReadingUncached = 1UL << 1,
    NSDataReadingMappedAlways = 1UL << 3,

    // deprecated enum values
    NSDataReadingMapped = NSDataReadingMappedIfSafe,
    NSMappedRead = NSDataReadingMapped,
    NSUncachedRead = NSDataReadingUncached
};

typedef NS_OPTIONS(NSUInteger, NSDataWritingOptions) {
    NSDataWritingAtomic = 1UL << 0,
    NSDataWritingWithoutOverwriting = 1UL << 1,
    NSDataWritingFileProtectionNone = 0x10000000,
    NSDataWritingFileProtectionComplete = 0x20000000,
    NSDataWritingFileProtectionCompleteUnlessOpen = 0x30000000,
    NSDataWritingFileProtectionCompleteUntilFirstUserAuthentication = 0x40000000,
    NSDataWritingFileProtectionMask = 0xf0000000,

    // deprecated values
    NSAtomicWrite = NSDataWritingAtomic
};

typedef NS_OPTIONS(NSUInteger, NSDataSearchOptions) { NSDataSearchBackwards = 1UL << 0, NSDataSearchAnchored = 1UL << 1 };

typedef NS_OPTIONS(NSUInteger, NSDataBase64EncodingOptions) {
    NSDataBase64Encoding64CharacterLineLength = 1UL << 0,
    NSDataBase64Encoding76CharacterLineLength = 1UL << 1,
    NSDataBase64EncodingEndLineWithCarriageReturn = 1UL << 4,
    NSDataBase64EncodingEndLineWithLineFeed = 1UL << 5,
};

typedef NS_OPTIONS(NSUInteger, NSDataBase64DecodingOptions) { NSDataBase64DecodingIgnoreUnknownCharacters = 1UL << 0 };

@class NSURL, NSError;

FOUNDATION_EXPORT_CLASS
@interface NSData : NSObject <NSCopying, NSMutableCopying, NSCoding> {
    uint8_t* _bytes;
    size_t _length;
    BOOL _freeWhenDone;
}

// Creating Data Objects
+ (instancetype)data;
+ (instancetype)dataWithBytes:(const void*)bytes length:(NSUInteger)length;
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
+ (instancetype)dataWithContentsOfFile:(NSString*)path;
+ (instancetype)dataWithData:(NSData*)data;
+ (instancetype)dataWithContentsOfFile:(NSString*)path options:(NSDataReadingOptions)options error:(NSError**)errorp;
+ (instancetype)dataWithContentsOfMappedFile:(NSString*)path;
+ (instancetype)dataWithContentsOfURL:(NSURL*)url;
+ (instancetype)dataWithContentsOfURL:(NSURL*)url options:(NSDataReadingOptions)options error:(NSError**)errorp;

- (instancetype)initWithBase64EncodedData:(NSData*)base64Data options:(NSDataBase64DecodingOptions)options;
- (instancetype)initWithBase64EncodedString:(NSString*)base64String options:(NSDataBase64DecodingOptions)options;
- (instancetype)initWithBase64Encoding:(NSString*)base64String;
- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                        deallocator:(void (^)(void* bytes, NSUInteger length))deallocator;
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
- (instancetype)initWithContentsOfFile:(NSString*)path;
- (instancetype)initWithContentsOfFile:(NSString*)path options:(NSDataReadingOptions)mask error:(NSError**)errorPtr;
- (instancetype)initWithContentsOfMappedFile:(NSString*)path;
- (instancetype)initWithContentsOfURL:(NSURL*)url;
- (instancetype)initWithContentsOfURL:(NSURL*)aURL options:(NSDataReadingOptions)mask error:(NSError**)errorPtr;
- (instancetype)initWithData:(NSData*)data;

// Accessing Data
@property (readonly) const void* bytes;
@property (readonly, copy) NSString* description;
- (void)enumerateByteRangesUsingBlock:(void (^)(const void* bytes, NSRange byteRange, BOOL* stop))block;
- (void)getBytes:(void*)buffer;
- (void)getBytes:(void*)buffer length:(NSUInteger)length;
- (void)getBytes:(void*)buffer range:(NSRange)range;
- (NSData*)subdataWithRange:(NSRange)range;
- (NSRange)rangeOfData:(NSData*)dataToFind options:(NSDataSearchOptions)mask range:(NSRange)searchRange;

// Base-64 Encoding
- (NSData*)base64EncodedDataWithOptions:(NSDataBase64EncodingOptions)options;
- (NSString*)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options;
- (NSString*)base64Encoding;

// Testing Data
- (BOOL)isEqualToData:(NSData*)data;
@property (readonly) NSUInteger length;
- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)atomically;
- (BOOL)writeToFile:(NSString*)path options:(NSDataWritingOptions)mask error:(NSError**)errorPtr;
- (BOOL)writeToURL:(NSURL*)url atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL*)aURL options:(NSDataWritingOptions)mask error:(NSError**)errorPtr;

@end

#import <Foundation/NSMutableData.h>

#endif /* _NSDATA_H_ */
