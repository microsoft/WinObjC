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

SB_EXPORT NSString* const NSFontAttributeName;
SB_EXPORT NSString* const NSParagraphStyleAttributeName;
SB_EXPORT NSString* const NSForegroundColorAttributeName;
SB_EXPORT NSString* const NSBackgroundColorAttributeName;
SB_EXPORT NSString* const NSLigatureAttributeName;
SB_EXPORT NSString* const NSKernAttributeName;
SB_EXPORT NSString* const NSStrikethroughStyleAttributeName;
SB_EXPORT NSString* const NSUnderlineStyleAttributeName;
SB_EXPORT NSString* const NSStrokeColorAttributeName;
SB_EXPORT NSString* const NSStrokeWidthAttributeName;
SB_EXPORT NSString* const NSShadowAttributeName;
SB_EXPORT NSString* const NSTextEffectAttributeName;
SB_EXPORT NSString* const NSAttachmentAttributeName;
SB_EXPORT NSString* const NSLinkAttributeName;
SB_EXPORT NSString* const NSBaselineOffsetAttributeName;
SB_EXPORT NSString* const NSUnderlineColorAttributeName;
SB_EXPORT NSString* const NSStrikethroughColorAttributeName;
SB_EXPORT NSString* const NSObliquenessAttributeName;
SB_EXPORT NSString* const NSExpansionAttributeName;
SB_EXPORT NSString* const NSWritingDirectionAttributeName;
SB_EXPORT NSString* const NSVerticalGlyphFormAttributeName;

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
    NSAttributedStringEnumerationLongestEffectiveRangeNotRequired = (1UL << 20),
};
typedef uint32_t NSAttributedStringEnumerationOptions;

@class NSDictionary;
@class NSError;

@interface NSAttributedString : NSObject <NSCopying, NSCoding, NSMutableCopying>

- initWithString:(NSString*)string;
- initWithString:(NSString*)string attributes:(NSDictionary*)attributes;
- initWithAttributedString:(NSAttributedString*)other;
- initWithData:(NSData*)data options:(NSDictionary*)options documentAttributes:(NSDictionary*)docAttrs error:(NSError**)error;

- (BOOL)isEqualToAttributedString:(NSAttributedString*)other;

- (NSUInteger)length;
- (NSString*)string;

- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange;

- attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange;

- (NSAttributedString*)attributedSubstringFromRange:(NSRange)range;
- (void)enumerateAttribute:(NSString*)attrName
                   inRange:(NSRange)enumerationRange
                   options:(NSAttributedStringEnumerationOptions)opts
                usingBlock:(void (^)(id value, NSRange range, BOOL* stop))block;

- fixAttributesInRange:(NSRange)range;

@end

#endif /* _NSATTRIBUTEDSTRING_H_ */