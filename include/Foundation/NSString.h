/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSSTRING_H_
#define _NSSTRING_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSObjCRuntime.h>

@class NSArray, NSData, NSDictionary, NSCharacterSet, NSError, NSLocale, NSURL;

typedef uint16_t unichar;

enum {
    NSStringEncodingConversionAllowLossy = 1,
    NSStringEncodingConversionExternalRepresentation = 2
};
typedef uint32_t NSStringEncodingConversionOptions;

typedef NSUInteger NSStringEnumerationOptions;

enum {
    NSStringEnumerationByLines = 0,
    NSStringEnumerationByParagraphs = 1,
    NSStringEnumerationByComposedCharacterSequences = 2,
    NSStringEnumerationByWords = 3,
    NSStringEnumerationBySentences = 4,
    NSStringEnumerationReverse = 1UL << 8,
    NSStringEnumerationSubstringNotRequired = 1UL << 9,
    NSStringEnumerationLocalized = 1UL << 10
};

enum : uint32_t {
   NSASCIIStringEncoding=1,
   NSNEXTSTEPStringEncoding=2,
   NSJapaneseEUCStringEncoding=3,
   NSUTF8StringEncoding=4,
   NSISOLatin1StringEncoding=5,
   NSSymbolStringEncoding=6,
   NSNonLossyASCIIStringEncoding=7,
   NSShiftJISStringEncoding=8,
   NSISOLatin2StringEncoding=9,
   NSUnicodeStringEncoding=10,
   NSWindowsCP1251StringEncoding=11,
   NSWindowsCP1252StringEncoding=12,
   NSWindowsCP1253StringEncoding=13,
   NSWindowsCP1254StringEncoding=14,
   NSWindowsCP1250StringEncoding=15,
   NSISO2022JPStringEncoding=21,
   NSMacOSRomanStringEncoding=30,
   NSProprietaryStringEncoding=0x00010000,
   NSUTF16BigEndianStringEncoding=0x90000100,
   NSUTF16LittleEndianStringEncoding=0x94000100,
   NSUTF32StringEncoding=0x8c000100,
   NSUTF32BigEndianStringEncoding=0x98000100,
   NSUTF32LittleEndianStringEncoding=0x9c000100,
   NSUTF16StringEncoding = NSUnicodeStringEncoding
};
typedef uint32_t NSStringEncoding;

enum {
    NSCaseInsensitiveSearch = 1,
    NSLiteralSearch = 2,
    NSBackwardsSearch = 4,
    NSAnchoredSearch = 8,
    NSNumericSearch = 64,
    NSDiacriticInsensitiveSearch = 128,
    NSWidthInsensitiveSearch = 256,
    NSForcedOrderingSearch = 512,
    NSRegularExpressionSearch = 1024
};
typedef NSUInteger NSStringCompareOptions;
typedef NSUInteger NSStringEncodingConversionOptions;

SB_EXPORT const NSUInteger NSMaximumStringLength;

struct _ConstructedStringData;
struct _ConstructedStringType {
    uint8_t        _hashIsCached;
    uint8_t        _placementAllocated;
    uint8_t         align;
    struct _ConstructedStringData *constructedStr;
    uint32_t           _hashCache;
};
struct _NoOwnStringType {
    uint8_t _freeWhenDone;
    uint8_t align[2];
    void *_address;
    uint32_t _length;
    uint32_t _encoding;
};

FOUNDATION_EXPORT_CLASS
@interface NSString : NSObject <NSCopying,NSMutableCopying,NSCoding> {
@public
    union stringData {
        struct _ConstructedStringType ConstructedString;
        struct _NoOwnStringType    NoOwnString;
    } *u;
    uint32_t                   strType;
}

+(const NSStringEncoding *)availableStringEncodings;
+(NSString *)localizedNameOfStringEncoding:(NSStringEncoding)encoding;

+stringWithCharacters:(const unichar *)unicode length:(NSUInteger)length;
+string;
+stringWithCString:(const char *)cString length:(NSUInteger)length;
+stringWithCString:(const char *)cString;
+stringWithString:(NSString *)string;
+stringWithFormat:(NSString *)format,...;
+stringWithContentsOfFile:(NSString *)path;
+stringWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)encoding error:(NSError **)error;
+stringWithContentsOfFile:(NSString *)path usedEncoding:(NSStringEncoding *)encoding error:(NSError **)error;
+stringWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)encoding error:(NSError **)error;
+stringWithContentsOfURL:(NSURL *)url usedEncoding:(NSStringEncoding *)encoding error:(NSError **)error;
+stringWithCString:(const char *)cString encoding:(NSStringEncoding)encoding;
+stringWithUTF8String:(const char *)utf8;

+localizedStringWithFormat:(NSString *)format,...;

-initWithCharactersNoCopy:(unichar *)unicode length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
-initWithCharacters:(const unichar *)unicode length:(NSUInteger)length;
-init;

-initWithCStringNoCopy:(char *)cString length:(NSUInteger)length
          freeWhenDone:(BOOL)freeWhenDone;
-initWithCString:(const char *)cString length:(NSUInteger)length;
-initWithCString:(const char *)cString;
-initWithCString:(const char *)cString encoding:(NSStringEncoding)encoding;

-initWithString:(NSString *)string;

-initWithFormat:(NSString *)format locale:(id)locale arguments:(va_list)arguments;
-initWithFormat:(NSString *)format locale:(id)locale,...;
-initWithFormat:(NSString *)format arguments:(va_list)arguments;
-initWithFormat:(NSString *)format,...;

-initWithData:(NSData *)data encoding:(NSStringEncoding)encoding;
-initWithUTF8String:(const char *)utf8;
-initWithBytes:(const void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding;
-initWithBytesNoCopy:(void *)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding freeWhenDone:(BOOL)freeWhenDone;
-initWithContentsOfFile:(NSString *)path usedEncoding:(NSStringEncoding *)encoding error:(NSError **)error;

-initWithContentsOfFile:(NSString *)path;
-initWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)encoding error:(NSError **)error;
-initWithContentsOfFile:(NSString *)path usedEncoding:(NSStringEncoding *)encoding error:(NSError **)error;
-initWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)encoding error:(NSError **)error;
-initWithContentsOfURL:(NSURL *)url usedEncoding:(NSStringEncoding *)encoding error:(NSError **)error;

-(unichar)characterAtIndex:(NSUInteger)location;
-(NSUInteger)length;

-(void)getCharacters:(unichar *)buffer range:(NSRange)range;
-(void)getCharacters:(unichar *)buffer;
-(const unichar *)rawCharacters;

-(NSComparisonResult)compare:(NSString *)other options:(NSStringCompareOptions)options range:(NSRange)range locale:(NSLocale *)locale;
-(NSComparisonResult)compare:(NSString *)other options:(NSStringCompareOptions)options range:(NSRange)range;
-(NSComparisonResult)compare:(NSString *)other options:(NSStringCompareOptions)options;
-(NSComparisonResult)compare:(NSString *)other;
-(NSComparisonResult)caseInsensitiveCompare:(NSString *)other;
-(NSComparisonResult)localizedCompare:(NSString *)other;
-(NSComparisonResult)localizedCaseInsensitiveCompare:(NSString *)other;

-(BOOL)isEqualToString:(NSString *)string;

-(BOOL)hasPrefix:(NSString *)string;
-(BOOL)hasSuffix:(NSString *)string;
-(NSRange)rangeOfString:(NSString *)string options:(NSStringCompareOptions)options range:(NSRange)range locale:(NSLocale *)locale;
-(NSRange)rangeOfString:(NSString *)string options:(NSStringCompareOptions)options range:(NSRange)range;
-(NSRange)rangeOfString:(NSString *)string options:(NSStringCompareOptions)options;
-(NSRange)rangeOfString:(NSString *)string;

-(NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)set options:(NSStringCompareOptions)options range:(NSRange)range;
-(NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)set options:(NSStringCompareOptions)options;
-(NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)set;

-(void)getLineStart:(NSUInteger *)startp end:(NSUInteger *)endp contentsEnd:(NSUInteger *)contentsEndp forRange:(NSRange)range;
-(NSRange)lineRangeForRange:(NSRange)range;

-(void)getParagraphStart:(NSUInteger *)startp end:(NSUInteger *)endp contentsEnd:(NSUInteger *)contentsEndp forRange:(NSRange)range;
-(NSRange)paragraphRangeForRange:(NSRange)range;

-(NSString *)substringWithRange:(NSRange)range;
-(NSString *)substringFromIndex:(NSUInteger)location;
-(NSString *)substringToIndex:(NSUInteger)location;

-(BOOL)boolValue;
-(int)intValue;
-(NSInteger)integerValue;
-(long long)longLongValue;
-(float)floatValue;
-(double)doubleValue;

-(NSString *)lowercaseString;
-(NSString *)uppercaseString;
-(NSString *)capitalizedString;

-(NSString *)stringByAppendingFormat:(NSString *)format,...;
-(NSString *)stringByAppendingString:(NSString *)string;

-(NSArray *)componentsSeparatedByString:(NSString *)separator;
-(NSArray *)componentsSeparatedByCharactersInSet:(NSCharacterSet *)set;

-(NSString *)commonPrefixWithString:(NSString *)other options:(NSStringCompareOptions)options;
-(NSString *)stringByPaddingToLength:(NSUInteger)length withString:(NSString *)padding startingAtIndex:(NSUInteger)index;
-(NSString *)stringByReplacingCharactersInRange:(NSRange)range withString:(NSString *)substitute;
-(NSString *)stringByReplacingOccurrencesOfString:(NSString *)original withString:(NSString *)substitute;
-(NSString *)stringByReplacingOccurrencesOfString:(NSString *)original withString:(NSString *)substitute options:(NSStringCompareOptions)options range:(NSRange)range;

-(NSString *)stringByFoldingWithOptions:(NSStringCompareOptions)options locale:(NSLocale *)locale;

-(NSRange)rangeOfComposedCharacterSequenceAtIndex:(NSUInteger)index;
-(NSRange)rangeOfComposedCharacterSequencesForRange:(NSRange)range;

-(NSString *)precomposedStringWithCanonicalMapping;
-(NSString *)decomposedStringWithCanonicalMapping;
-(NSString *)precomposedStringWithCompatibilityMapping;
-(NSString *)decomposedStringWithCompatibilityMapping;

-propertyList;
-(NSDictionary *)propertyListFromStringsFileFormat;

-(BOOL)writeToFile:(NSString *)path atomically:(BOOL)atomically;
-(BOOL)writeToFile:(NSString *)path atomically:(BOOL)atomically encoding:(NSStringEncoding)encoding error:(NSError **)error;
-(BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically encoding:(NSStringEncoding)encoding error:(NSError **)error;

-(NSStringEncoding)fastestEncoding;
-(NSStringEncoding)smallestEncoding;

-(BOOL)canBeConvertedToEncoding:(NSStringEncoding)encoding;
-(NSUInteger)lengthOfBytesUsingEncoding:(NSStringEncoding)encoding;
-(NSUInteger)maximumLengthOfBytesUsingEncoding:(NSStringEncoding)encoding;

-(NSData *)dataUsingEncoding:(NSStringEncoding)encoding allowLossyConversion:(BOOL)lossy;
-(NSData *)dataUsingEncoding:(NSStringEncoding)encoding;

-(BOOL)getBytes:(void *)bytes maxLength:(NSUInteger)maxLength usedLength:(NSUInteger *)usedLength encoding:(NSStringEncoding)encoding options:(NSStringEncodingConversionOptions)options range:(NSRange)range remainingRange:(NSRange *)remainingRange;

-(__strong const char *)UTF8String NS_RETURNS_INNER_POINTER;

-(NSString *)stringByReplacingPercentEscapesUsingEncoding:(NSStringEncoding)encoding;
-(NSString *)stringByAddingPercentEscapesUsingEncoding:(NSStringEncoding)encoding;
-(NSString *)stringByRemovingPercentEncoding;

-(NSString *)stringByTrimmingCharactersInSet:(NSCharacterSet *)set;

-(const char *)cStringUsingEncoding:(NSStringEncoding)encoding;
-(BOOL)getCString:(char *)cString maxLength:(NSUInteger)maxLength encoding:(NSStringEncoding)encoding;

-(NSString *)description;

+(NSStringEncoding)defaultCStringEncoding;

-(void)getCString:(char *)buffer maxLength:(NSUInteger)maxLength
            range:(NSRange)range remainingRange:(NSRange *)remainingRange;
-(void)getCString:(char *)buffer maxLength:(NSUInteger)maxLength;
-(void)getCString:(char *)buffer;

-(NSUInteger)cStringLength;
-(const char *)cString;
-(const char *)lossyCString;

- (void)enumerateSubstringsInRange:(NSRange)range options:(NSStringEnumerationOptions)opts usingBlock:(void (^)(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop))block;

@end

@interface NSConstantString : NSString
@end

#if defined( STARBOARD_PORT ) && defined( __cplusplus )
namespace icu_48 {
    class UnicodeString;
}
class UStringHolder
{
private:
    icu_48::UnicodeString *_str, *_destroyStr;
    icu_48::UnicodeString *_subStr;

    void initWithString(NSString *str, int location, int length);

public:
    UStringHolder(NSString *str, int location = 0, int length = -1);
    UStringHolder(id str, int location = 0, int length = -1);
    ~UStringHolder();

    icu_48::UnicodeString &string();
    inline unichar getChar(int index);
};
NSString *NSStringFromICU(const icu_48::UnicodeString& str);
#endif

#import <Foundation/NSMutableString.h>

#endif /* _NSSTRING_H_ */
