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
#import <UIKit/UIKitTypes.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/NSParagraphStyle.h>
#import <Foundation/Foundation.h>
#import <UIKit/NSAttributedString+UIKitAdditions.h>

@class NSDictionary;
@class NSString;
@class NSStringDrawingContext;
@class UIFont;

UIKIT_EXPORT NSString* const UITextAttributeFont;
UIKIT_EXPORT NSString* const UITextAttributeTextColor;
UIKIT_EXPORT NSString* const UITextAttributeTextShadowColor;
UIKIT_EXPORT NSString* const UITextAttributeTextShadowOffset;

@interface NSString (UIKitAdditions)
- (CGSize)sizeWithFont:(UIFont*)font;
- (CGSize)sizeWithFont:(UIFont*)font forWidth:(CGFloat)width lineBreakMode:(NSLineBreakMode)lineBreakMode;
- (CGSize)sizeWithFont:(UIFont*)font
           minFontSize:(CGFloat)minFontSize
        actualFontSize:(CGFloat*)actualFontSize
              forWidth:(CGFloat)width
         lineBreakMode:(NSLineBreakMode)lineBreakMode;
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size;
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size lineBreakMode:(NSLineBreakMode)lineBreakMode;
- (CGSize)drawAtPoint:(CGPoint)point withFont:(UIFont*)font;
- (CGSize)drawAtPoint:(CGPoint)point forWidth:(CGFloat)width withFont:(UIFont*)font lineBreakMode:(NSLineBreakMode)lineBreakMode;
- (CGSize)drawAtPoint:(CGPoint)point
             forWidth:(CGFloat)width
             withFont:(UIFont*)font
             fontSize:(CGFloat)fontSize
        lineBreakMode:(NSLineBreakMode)lineBreakMode
   baselineAdjustment:(UIBaselineAdjustment)baselineAdjustment;
- (CGSize)drawAtPoint:(CGPoint)point
             forWidth:(CGFloat)width
             withFont:(UIFont*)font
          minFontSize:(CGFloat)minFontSize
       actualFontSize:(CGFloat*)actualFontSize
        lineBreakMode:(NSLineBreakMode)lineBreakMode
   baselineAdjustment:(UIBaselineAdjustment)baselineAdjustment;
- (void)drawAtPoint:(CGPoint)point withAttributes:(NSDictionary*)attrs;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font lineBreakMode:(NSLineBreakMode)lineBreakMode;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font lineBreakMode:(NSLineBreakMode)lineBreakMode alignment:(NSTextAlignment)alignment;
- (CGRect)boundingRectWithSize:(CGSize)size
                       options:(NSStringDrawingOptions)options
                    attributes:(NSDictionary*)attributes
                       context:(NSStringDrawingContext*)context;
- (void)drawInRect:(CGRect)rect withAttributes:(NSDictionary*)attrs;
- (void)drawWithRect:(CGRect)rect
             options:(NSStringDrawingOptions)options
          attributes:(NSDictionary*)attributes
             context:(NSStringDrawingContext*)context;
- (CGSize)sizeWithAttributes:(NSDictionary<NSString*, id>*)attrs;
@end
