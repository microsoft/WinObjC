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

#import <Foundation/NSAttributedString.h>
#import <CoreFoundation/CFAttributedString.h>

#import "Starboard.h"

NSString* const NSFontAttributeName = (NSString * const) @"NSFontAttributeName";
NSString* const NSParagraphStyleAttributeName = (NSString * const) @"NSParagraphStyleAttributeName";
NSString* const NSForegroundColorAttributeName = (NSString * const) @"NSForegroundColorAttributeName";
NSString* const NSBackgroundColorAttributeName = (NSString * const) @"NSBackgroundColorAttributeName";
NSString* const NSLigatureAttributeName = (NSString * const) @"NSLigatureAttributeName";
NSString* const NSKernAttributeName = (NSString * const) @"NSKernAttributeName";
NSString* const NSStrikethroughStyleAttributeName = (NSString * const) @"NSStrikethroughStyleAttributeName";
NSString* const NSUnderlineStyleAttributeName = (NSString * const) @"NSUnderlineStyleAttributeName";
NSString* const NSStrokeColorAttributeName = (NSString * const) @"NSStrokeColorAttributeName";
NSString* const NSStrokeWidthAttributeName = (NSString * const) @"NSStrokeWidthAttributeName";
NSString* const NSShadowAttributeName = (NSString * const) @"NSShadowAttributeName";
NSString* const NSTextEffectAttributeName = (NSString * const) @"NSTextEffectAttributeName";
NSString* const NSAttachmentAttributeName = (NSString * const) @"NSAttachmentAttributeName";
NSString* const NSLinkAttributeName = (NSString * const) @"NSLinkAttributeName";
NSString* const NSBaselineOffsetAttributeName = (NSString * const) @"NSBaselineOffsetAttributeName";
NSString* const NSUnderlineColorAttributeName = (NSString * const) @"NSUnderlineColorAttributeName";
NSString* const NSStrikethroughColorAttributeName = (NSString * const) @"NSStrikethroughColorAttributeName";
NSString* const NSObliquenessAttributeName = (NSString * const) @"NSObliquenessAttributeName";
NSString* const NSExpansionAttributeName = (NSString * const) @"NSExpansionAttributeName";
NSString* const NSWritingDirectionAttributeName = (NSString * const) @"NSWritingDirectionAttributeName";
NSString* const NSVerticalGlyphFormAttributeName = (NSString * const) @"NSVerticalGlyphFormAttributeName";

NSString* const NSDocumentTypeDocumentAttribute = (NSString * const) @"NSDocumentTypeDocumentAttribute";
NSString* const NSHTMLTextDocumentType = (NSString * const) @"NSHTMLTextDocumentType";
NSString* const NSCharacterEncodingDocumentAttribute = (NSString * const) @"NSCharacterEncodingDocumentAttribute";

@implementation NSAttributedString

+ (instancetype)allocWithZone:(NSZone*)zone {
    return (__bridge NSAttributedString*)_CFAttributedStringCreateEmpty();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string {
    [reinterpret_cast<NSMutableAttributedString*>(self) replaceCharactersInRange:NSMakeRange(0, 0) withString:string];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithAttributedString:(NSAttributedString*)string {
    [reinterpret_cast<NSMutableAttributedString*>(self) setAttributedString:string];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    [reinterpret_cast<NSMutableAttributedString*>(self) replaceCharactersInRange:NSMakeRange(0, 0) withString:string];
    [reinterpret_cast<NSMutableAttributedString*>(self) setAttributes:attributes range:NSMakeRange(0, [self length])];
    return self;
}

/**
 @Status Stub
 @Notes  Bit more difficult than the rest of the constructors, separating this out.
         TODO: 5505126
 */
- (NSAttributedString*)attributedSubstringFromRange:(NSRange)range {
    return (__bridge NSAttributedString*)CFAttributedStringCreateWithSubstring(nullptr,
                                                                               reinterpret_cast<CFAttributedStringRef>(self),
                                                                               CFRangeMake(range.location, range.length));
}

/**
 @Status Interoperable
*/
- (NSString*)string {
    return (__bridge NSString*)CFAttributedStringGetString(reinterpret_cast<CFAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    return CFAttributedStringGetLength(reinterpret_cast<CFAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    CFRange outRange;
    NSDictionary* returnValue = (__bridge NSDictionary*)CFAttributedStringGetAttributes(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                        location,
                                                                                        (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    CFRange outRange;
    NSDictionary* returnValue =
        (__bridge NSDictionary*)CFAttributedStringGetAttributesAndLongestEffectiveRange(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                        location,
                                                                                        CFRangeMake(inRange.location, inRange.length),
                                                                                        (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    CFRange outRange;

    id returnValue = (__bridge id)CFAttributedStringGetAttribute(reinterpret_cast<CFAttributedStringRef>(self),
                                                                 location,
                                                                 (__bridge CFStringRef)name,
                                                                 (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    CFRange outRange;
    id returnValue = (__bridge id)CFAttributedStringGetAttributeAndLongestEffectiveRange(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                         location,
                                                                                         (__bridge CFStringRef)name,
                                                                                         CFRangeMake(inRange.location, inRange.length),
                                                                                         (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Stub
 */
- (BOOL)isEqualToAttributedString:(NSAttributedString*)string {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 */
- (void)enumerateAttribute:(NSString*)attrName
                   inRange:(NSRange)enumerationRange
                   options:(NSAttributedStringEnumerationOptions)opts
                usingBlock:(void (^)(id value, NSRange range, BOOL* stop))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 */
- (void)enumerateAttributesInRange:(NSRange)enumerationRange
                           options:(NSAttributedStringEnumerationOptions)opts
                        usingBlock:(void (^)(NSDictionary* attrs, NSRange range, BOOL* stop))block {
    UNIMPLEMENTED();
}

@end
