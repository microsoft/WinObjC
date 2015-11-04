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

enum {
    NSDataReadingMappedIfSafe = 1,
    NSDataReadingUncached = 2,
    NSDataReadingMappedAlways = 8,
};
typedef uint32_t NSDataReadingOptions;

enum {
    NSDataReadingMapped = 0x01,
    // deprecated
    NSMappedRead = NSDataReadingMapped,
    NSUncachedRead = NSDataReadingUncached,
};

enum : unsigned int {
    NSDataWritingAtomic = 0x1,
    NSDataWritingWithoutOverwriting = 0x2,
    NSDataWritingFileProtectionNone = 0x10000000,
    NSDataWritingFileProtectionComplete = 0x20000000,
    NSDataWritingFileProtectionCompleteUnlessOpen = 0x30000000,
    NSDataWritingFileProtectionCompleteUntilFirstUserAuthentication = 0x40000000,
    NSDataWritingFileProtectionMask = 0xf0000000,
};
typedef uint32_t NSDataWritingOptions;

enum {
    // deprecated
    NSAtomicWrite = NSDataWritingAtomic,
};

enum {
    NSDataSearchBackwards = 0x01,
    NSDataSearchAnchored = 0x02,
};
typedef uint32_t NSDataSearchOptions;

enum {
    NSDataBase64Encoding64CharacterLineLength = 1UL << 0,
    NSDataBase64Encoding76CharacterLineLength = 1UL << 1,
    NSDataBase64EncodingEndLineWithCarriageReturn = 1UL << 4,
    NSDataBase64EncodingEndLineWithLineFeed = 1UL << 5,
};
typedef uint32_t NSDataBase64EncodingOptions;

enum { NSDataBase64DecodingIgnoreUnknownCharacters = 1UL << 0 };
typedef uint32_t NSDataBase64DecodingOptions;

@class NSURL, NSError;

FOUNDATION_EXPORT_CLASS
@interface NSData : NSObject <NSCopying, NSMutableCopying, NSCoding> {
    uint8_t* _bytes;
    size_t _length;
    BOOL _freeWhenDone;
}

- initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
- initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
- initWithBytes:(const void*)bytes length:(NSUInteger)length;
- initWithData:(NSData*)data;
- initWithContentsOfFile:(NSString*)path;
- initWithContentsOfMappedFile:(NSString*)path;
- initWithContentsOfURL:(NSURL*)url;
- initWithContentsOfFile:(NSString*)path options:(NSUInteger)options error:(NSError**)errorp;
- initWithContentsOfURL:(NSURL*)url options:(NSUInteger)options error:(NSError**)errorp;

+ data;
+ dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
+ dataWithBytesNoCopy:(void*)bytes length:(NSUInteger)length;
+ dataWithBytes:(const void*)bytes length:(NSUInteger)length;
+ dataWithData:(NSData*)data;
+ dataWithContentsOfFile:(NSString*)path;
+ dataWithContentsOfMappedFile:(NSString*)path;
+ dataWithContentsOfURL:(NSURL*)url;
+ dataWithContentsOfFile:(NSString*)path options:(NSUInteger)options error:(NSError**)errorp;
+ dataWithContentsOfURL:(NSURL*)url options:(NSUInteger)options error:(NSError**)errorp;

- (const void*)bytes NS_RETURNS_INNER_POINTER;
- (NSUInteger)length;

- (BOOL)isEqualToData:(NSData*)data;

- (void)getBytes:(void*)result range:(NSRange)range;
- (void)getBytes:(void*)result length:(NSUInteger)length;
- (void)getBytes:(void*)result;

- (NSData*)subdataWithRange:(NSRange)range;

- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL*)url atomically:(BOOL)atomically;
- (BOOL)writeToFile:(NSString*)path options:(NSUInteger)options error:(NSError**)errorp;
- (BOOL)writeToURL:(NSURL*)url options:(NSUInteger)options error:(NSError**)errorp;

- (NSString*)description;

- (NSRange)rangeOfData:(NSData*)dataToFind options:(NSDataSearchOptions)mask range:(NSRange)searchRange;

- (instancetype)initWithBase64EncodedString:(NSString*)base64String options:(NSDataBase64DecodingOptions)options;
- (NSString*)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options;

@end

#import <Foundation/NSMutableData.h>

#endif /* _NSDATA_H_ */
