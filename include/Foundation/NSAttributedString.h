/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSATTRIBUTEDSTRING_H_
#define _NSATTRIBUTEDSTRING_H_

#import <Foundation/NSRange.h>
#import <Foundation/NSData.h>
#import <Foundation/FoundationExport.h>

FOUNDATION_EXPORT NSString* const NSFontAttributeName;
FOUNDATION_EXPORT NSString* const NSParagraphStyleAttributeName;
FOUNDATION_EXPORT NSString* const NSForegroundColorAttributeName;
FOUNDATION_EXPORT NSString* const NSBackgroundColorAttributeName;
FOUNDATION_EXPORT NSString* const NSLigatureAttributeName;
FOUNDATION_EXPORT NSString* const NSKernAttributeName;
FOUNDATION_EXPORT NSString* const NSStrikethroughStyleAttributeName;
FOUNDATION_EXPORT NSString* const NSUnderlineStyleAttributeName;
FOUNDATION_EXPORT NSString* const NSStrokeColorAttributeName;
FOUNDATION_EXPORT NSString* const NSStrokeWidthAttributeName;
FOUNDATION_EXPORT NSString* const NSShadowAttributeName;
FOUNDATION_EXPORT NSString* const NSTextEffectAttributeName;
FOUNDATION_EXPORT NSString* const NSAttachmentAttributeName;
FOUNDATION_EXPORT NSString* const NSLinkAttributeName;
FOUNDATION_EXPORT NSString* const NSBaselineOffsetAttributeName;
FOUNDATION_EXPORT NSString* const NSUnderlineColorAttributeName;
FOUNDATION_EXPORT NSString* const NSStrikethroughColorAttributeName;
FOUNDATION_EXPORT NSString* const NSObliquenessAttributeName;
FOUNDATION_EXPORT NSString* const NSExpansionAttributeName;
FOUNDATION_EXPORT NSString* const NSWritingDirectionAttributeName;
FOUNDATION_EXPORT NSString* const NSVerticalGlyphFormAttributeName;

FOUNDATION_EXPORT NSString* const NSDocumentTypeDocumentAttribute;
FOUNDATION_EXPORT NSString* const NSHTMLTextDocumentType;
FOUNDATION_EXPORT NSString* const NSCharacterEncodingDocumentAttribute;

enum {
    NSUnderlineStyleNone = 0x00,
    NSUnderlineStyleSingle = 0x01,
    NSUnderlineStyleThick = 0x02,
    NSUnderlineStyleDouble = 0x09,
    NSUnderlinePatternSolid = 0x0000,
    NSUnderlinePatternDot = 0x0100,
    NSUnderlinePatternDash = 0x0200,
    NSUnderlinePatternDashDot = 0x0300,
    NSUnderlinePatternDashDotDot = 0x0400,
    NSUnderlineByWord = 0x8000
};
typedef int32_t NSUnderlineStyle;

enum { 
    NSAttributedStringEnumerationReverse = (1UL << 1), 
    NSAttributedStringEnumerationLongestEffectiveRangeNotRequired = (1UL << 20) 
};
typedef uint32_t NSAttributedStringEnumerationOptions;

@class NSDictionary;
@class NSError;

FOUNDATION_EXPORT_CLASS
@interface NSAttributedString : NSObject <NSCopying, NSCoding, NSMutableCopying>

- (instancetype)initWithString:(NSString *)string;
- (instancetype)initWithAttributedString:(NSAttributedString *)attributedString;
- (instancetype)initWithString:(NSString *)string attributes : (NSDictionary *)attributes;
- (instancetype)initWithData:(NSData*)data options : (NSDictionary*)options documentAttributes : (NSDictionary*)docAttrs error : (NSError**)error;

- (BOOL)isEqualToAttributedString:(NSAttributedString*)other;

@property(readonly, copy) NSString *string;
@property(readonly) NSUInteger length;

- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange;

- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange;
- (BOOL)isEqualToAttributedString:(NSAttributedString *)string;

- (NSAttributedString*)attributedSubstringFromRange:(NSRange)range;

- (void)enumerateAttribute:(NSString*)attrName
                   inRange:(NSRange)enumerationRange
                   options:(NSAttributedStringEnumerationOptions)opts
                usingBlock:(void (^)(id value, NSRange range, BOOL* stop))block;

- fixAttributesInRange:(NSRange)range;

- (void)enumerateAttributesInRange:(NSRange)enumerationRange
                           options:(NSAttributedStringEnumerationOptions)opts
                        usingBlock:(void (^)(NSDictionary *attrs, NSRange range, BOOL *stop))block;
@end

#endif /* _NSATTRIBUTEDSTRING_H_ */