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

#import <UIKit/UIKitExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/NSAttributedString.h>
#import <Foundation/Foundation.h>

@class NSTextAttachment;
@class NSData;
@class NSDictionary;
@class NSError;
@class NSURL;
@class NSStringDrawingContext;
@class NSFileWrapper;
@class NSString;

typedef NSInteger NSStringDrawingOptions;

@interface NSAttributedString (UIKitAdditions)
+ (NSAttributedString*)attributedStringWithAttachment:(NSTextAttachment*)attachment;
- (instancetype)initWithData:(NSData*)data
                     options:(NSDictionary*)options
          documentAttributes:(NSDictionary* _Nullable*)dict
                       error:(NSError* _Nullable*)error;
- (instancetype)initWithFileURL:(NSURL*)url
                        options:(NSDictionary*)options
             documentAttributes:(NSDictionary* _Nullable*)dict
                          error:(NSError* _Nullable*)error;
- (void)drawAtPoint:(CGPoint)point;
- (void)drawInRect:(CGRect)rect;
- (void)drawWithRect:(CGRect)rect options:(NSStringDrawingOptions)options context:(NSStringDrawingContext*)context;
- (CGSize)size;
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options context:(NSStringDrawingContext*)context;
- (NSData*)dataFromRange:(NSRange)range documentAttributes:(NSDictionary*)dict error:(NSError* _Nullable*)error;
- (NSFileWrapper*)fileWrapperFromRange:(NSRange)range documentAttributes:(NSDictionary*)dict error:(NSError* _Nullable*)error;
@end

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
