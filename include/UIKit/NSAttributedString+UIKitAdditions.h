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

#pragma once

#import <Foundation/Foundation.h>
#import <UIKit/UIKitExport.h>

typedef NS_ENUM(NSInteger, NSUnderlineStyle) {
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

UIKIT_EXPORT NSString* const NSFontAttributeName;
UIKIT_EXPORT NSString* const NSParagraphStyleAttributeName;
UIKIT_EXPORT NSString* const NSForegroundColorAttributeName;
UIKIT_EXPORT NSString* const NSBackgroundColorAttributeName;
UIKIT_EXPORT NSString* const NSLigatureAttributeName;
UIKIT_EXPORT NSString* const NSKernAttributeName;
UIKIT_EXPORT NSString* const NSStrikethroughStyleAttributeName;
UIKIT_EXPORT NSString* const NSUnderlineStyleAttributeName;
UIKIT_EXPORT NSString* const NSStrokeColorAttributeName;
UIKIT_EXPORT NSString* const NSStrokeWidthAttributeName;
UIKIT_EXPORT NSString* const NSShadowAttributeName;
UIKIT_EXPORT NSString* const NSTextEffectAttributeName;
UIKIT_EXPORT NSString* const NSAttachmentAttributeName;
UIKIT_EXPORT NSString* const NSLinkAttributeName;
UIKIT_EXPORT NSString* const NSBaselineOffsetAttributeName;
UIKIT_EXPORT NSString* const NSUnderlineColorAttributeName;
UIKIT_EXPORT NSString* const NSStrikethroughColorAttributeName;
UIKIT_EXPORT NSString* const NSObliquenessAttributeName;
UIKIT_EXPORT NSString* const NSExpansionAttributeName;
UIKIT_EXPORT NSString* const NSWritingDirectionAttributeName;
UIKIT_EXPORT NSString* const NSVerticalGlyphFormAttributeName;

typedef enum : NSInteger { NSTextWritingDirectionEmbedding = (0 << 1), NSTextWritingDirectionOverride = (1 << 1) } NSTextWritingDirection;

UIKIT_EXPORT NSString* const NSPlainTextDocumentType;
UIKIT_EXPORT NSString* const NSRTFTextDocumentType;
UIKIT_EXPORT NSString* const NSRTFDTextDocumentType;
UIKIT_EXPORT NSString* const NSHTMLTextDocumentType;

UIKIT_EXPORT NSString* const NSDocumentTypeDocumentAttribute;
UIKIT_EXPORT NSString* const NSCharacterEncodingDocumentAttribute;
UIKIT_EXPORT NSString* const NSDefaultAttributesDocumentAttribute;
UIKIT_EXPORT NSString* const NSPaperSizeDocumentAttribute;
UIKIT_EXPORT NSString* const NSPaperMarginDocumentAttribute;
UIKIT_EXPORT NSString* const NSViewSizeDocumentAttribute;
UIKIT_EXPORT NSString* const NSViewZoomDocumentAttribute;
UIKIT_EXPORT NSString* const NSViewModeDocumentAttribute;
UIKIT_EXPORT NSString* const NSReadOnlyDocumentAttribute;
UIKIT_EXPORT NSString* const NSBackgroundColorDocumentAttribute;
UIKIT_EXPORT NSString* const NSHyphenationFactorDocumentAttribute;
UIKIT_EXPORT NSString* const NSDefaultTabIntervalDocumentAttribute;
UIKIT_EXPORT NSString* const NSTextLayoutSectionsAttribute;

UIKIT_EXPORT NSString* const NSTextLayoutSectionOrientation;
UIKIT_EXPORT NSString* const NSTextLayoutSectionRange;

UIKIT_EXPORT NSString* const NSTextEffectLetterpressStyle;

@interface NSAttributedString (NSAttributedStringUIKitAdditions)

- (NSAttributedString*)initWithData:(NSData*)data
                            options:(NSDictionary*)options
                 documentAttributes:(NSDictionary*)docAttrs
                              error:(NSError**)error;

// TODO 5827705, 5244811:
// + (NSAttributedString*)attributedStringWithAttachment:(NSTextAttachment*)attachment;
// - (NSFileWrapper*)fileWrapperFromRange:(NSRange)range
//                     documentAttributes:(NSDictionary*)dict
//                                  error:(NSError**)error;

- (NSData*)dataFromRange:(NSRange)range documentAttributes:(NSDictionary*)dict error:(NSError**)error;

@end