//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "Starboard.h"
#import <StubReturn.h>
#import <UIKit/UIKit.h>
#import <UIViewInternal.h>
#import <UIFontInternal.h>
#import <Foundation/NSMutableDictionary.h>
#import "CoreGraphics/CGContext.h"
#import "CoreTextInternal.h"
#import <assert.h>
#import "LoggingNative.h"
#include "StringHelpers.h"
#import <UIKit/NSValue+UIKitAdditions.h>

static const wchar_t* TAG = L"NSString+UIKitAdditions";

void NSStringForceinclude() {
    [NSString class];
}

// Contingent upon VSO 5795281: All of these names need to be compatible with the reference platform.
NSString* const UITextAttributeFont = NSFontAttributeName;
NSString* const UITextAttributeTextColor = NSForegroundColorAttributeName;
NSString* const UITextAttributeTextShadowColor = @"UITextAttributeTextShadowColor";
NSString* const UITextAttributeTextShadowOffset = @"UITextAttributeTextShadowOffset";

@implementation NSString (UIKitAdditions)

// The values of CTTextAlignment and UITextAlignment do not correspond so they can't be simply cast
static CTTextAlignment __UITextAlignmentToCTTextAlignment(UITextAlignment alignment) {
    switch (alignment) {
        case UITextAlignmentLeft:
            return kCTLeftTextAlignment;
        case UITextAlignmentRight:
            return kCTRightTextAlignment;
        case UITextAlignmentCenter:
        default:
            return kCTCenterTextAlignment;
    }
}

static void drawString(UIFont* font,
                       CGContextRef context,
                       NSString* string,
                       CGRect rect,
                       UILineBreakMode lineBreakMode,
                       UITextAlignment alignment,
                       CGSize* sizeOut) {
    if (font == nil) {
        TraceVerbose(TAG, L"drawString: font = nil!");
        return;
    }

    if (rect.size.width == 0) {
        rect.size.width = FLT_MAX;
    }

    if (rect.size.height == 0) {
        rect.size.height = FLT_MAX;
    }

    CTParagraphStyleSetting styles[2];
    CTTextAlignment align = __UITextAlignmentToCTTextAlignment(alignment);
    styles[0] = { kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &align };

    CTLineBreakMode breakMode = static_cast<CTLineBreakMode>(lineBreakMode);
    styles[1] = { kCTParagraphStyleSpecifierLineBreakMode, sizeof(CTLineBreakMode), &breakMode };

    NSAttributedString* attr =
        [[[NSAttributedString alloc] initWithString:string
                                         attributes:@{
                                             (NSString*)kCTForegroundColorFromContextAttributeName : (id)kCFBooleanTrue,
                                             (NSString*)kCTParagraphStyleAttributeName : (id)CTParagraphStyleCreate(styles, 2),
                                             (NSString*)kCTFontAttributeName : font
                                         }] autorelease];

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(static_cast<CFAttributedStringRef>(attr));

    CGPathRef path = CGPathCreateWithRect(rect, nullptr);
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, {}, path, nullptr);

    // Invert text matrix so glyphs are drawn with correct orientation
    CGContextSetTextMatrix(context, CGAffineTransformMakeScale(1.0f, -1.0f));

    // Can't draw the entire frame because it assumes our space has been flipped and translated
    NSArray* lines = static_cast<NSArray*>(CTFrameGetLines(frame));
    std::vector<CGPoint> origins([lines count]);
    CTFrameGetLineOrigins(frame, {}, origins.data());
    for (size_t i = 0; i < origins.size(); ++i) {
        // Need to set text position so each line will be drawn in the correct position relative to each other
        // Y positions will be negative because we are drawing with the coordinate system flipped to what CoreText is expecting
        CGContextSetTextPosition(context, rect.origin.x + origins[i].x, -(rect.origin.y + origins[i].y));
        CTLineDraw(static_cast<CTLineRef>(lines[i]), context);
    }

    if (sizeOut) {
        *sizeOut = _CTFrameGetSize(frame);
    }

    CGPathRelease(path);
    CFRelease(framesetter);
    CFRelease(frame);
}

static NSDictionary* _getDefaultUITextAttributes() {
    static NSDictionary* _defaultUITextAttributes;
    if (_defaultUITextAttributes == nil) {
        UIFont* font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        UIColor* color = [UIColor blackColor];
        _defaultUITextAttributes =
            [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    }

    return _defaultUITextAttributes;
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font {
    CGSize fontExtent;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, UILineBreakModeWordWrap, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Caveat
 @Notes Currently UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset will be ignored.
*/
- (void)drawInRect:(CGRect)rect withAttributes:(NSDictionary*)attrs {
    if (attrs == nil) {
        attrs = _getDefaultUITextAttributes();
    }

    // TODO enable UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset
    UIColor* uiShadowColor = [attrs valueForKey:UITextAttributeTextShadowColor];
    NSValue* textShadowOffset = [attrs valueForKey:UITextAttributeTextShadowOffset];
    if (uiShadowColor != nil && textShadowOffset != nil) {
        CGSize offset = [textShadowOffset sizeValue];
        CGContextSetShadowWithColor(UIGraphicsGetCurrentContext(), offset, 0, [uiShadowColor CGColor]);
    } else if (textShadowOffset != nil) {
        CGSize offset = [textShadowOffset sizeValue];
        CGContextSetShadow(UIGraphicsGetCurrentContext(), offset, 0);
    }

    UIColor* uiTextColor = [attrs valueForKey:UITextAttributeTextColor];
    if (uiTextColor != nil) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [uiTextColor CGColor]);
    }

    UIFont* uiFont = [attrs valueForKey:UITextAttributeFont];
    if (uiFont != nil) {
        [self drawInRect:rect withFont:uiFont];
    }
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode alignment:(UITextAlignment)alignment {
    CGSize fontExtent;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, lineBreakMode, alignment, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode {
    CGSize fontExtent;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, lineBreakMode, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawAtPoint:(CGPoint)pt withFont:(UIFont*)font {
    CGSize fontExtent;

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = 0;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Caveat
 @Notes Currently UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset will be ignored.
*/
- (void)drawAtPoint:(CGPoint)pt withAttributes:(NSDictionary*)attrs {
    if (attrs == nil) {
        attrs = _getDefaultUITextAttributes();
    }

    // TODO enable UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset
    UIColor* uiShadowColor = [attrs valueForKey:UITextAttributeTextShadowColor];
    NSValue* textShadowOffset = [attrs valueForKey:UITextAttributeTextShadowOffset];
    if (uiShadowColor != nil && textShadowOffset != nil) {
        CGSize offset = [textShadowOffset sizeValue];
        CGContextSetShadowWithColor(UIGraphicsGetCurrentContext(), offset, 0, [uiShadowColor CGColor]);
    } else if (textShadowOffset != nil) {
        CGSize offset = [textShadowOffset sizeValue];
        CGContextSetShadow(UIGraphicsGetCurrentContext(), offset, 0);
    }

    UIColor* uiTextColor = [attrs valueForKey:UITextAttributeTextColor];
    if (uiTextColor != nil) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [uiTextColor CGColor]);
    }

    UIFont* uiFont = [attrs valueForKey:UITextAttributeFont];
    if (uiFont != nil) {
        [self drawAtPoint:pt withFont:uiFont];
    }
}

- (CGSize)drawAtPoint:(CGPoint)pt forWidth:(float)forWidth withFont:(UIFont*)font {
    CGSize fontExtent;

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawAtPoint:(CGPoint)pt
              forWidth:(float)forWidth
              withFont:(UIFont*)font
           minFontSize:(float)minFontSize
        actualFontSize:(float*)actualFontSize
         lineBreakMode:(UILineBreakMode)lineBreak
    baselineAdjustment:(UIBaselineAdjustment)baseline {
    CGSize fontExtent;
    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);
    if (actualFontSize) {
        *actualFontSize = 10.0f;
    }

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawAtPoint:(CGPoint)pt
              forWidth:(float)forWidth
              withFont:(UIFont*)font
              fontSize:(float)fontSize
         lineBreakMode:(UILineBreakMode)lineBreak
    baselineAdjustment:(UIBaselineAdjustment)baseline {
    CGSize fontExtent;
    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    font = [font fontWithSize:fontSize];

    drawString(font, UIGraphicsGetCurrentContext(), self, rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

// Private helper for sizeWith... functions
// Returns the bounding box size this string would occupy when drawn as specified
// All sizeWith... functions in this file funnel to this
- (CGSize)_sizeWithAttributes:(NSDictionary<NSString*, id>*)attributes constrainedToSize:(CGSize)size {
    NSAttributedString* attributedSelf = [[[NSAttributedString alloc] initWithString:self attributes:attributes] autorelease];

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef)attributedSelf);
    CFAutorelease(framesetter);

    return CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, self.length), nullptr, size, nullptr);
}

// Private helper that converts a UILineBreakMode -> NSParagraphStyle
// TODO #1108: NS/CT ParagraphStyle are not properly bridged, and ParagraphStyle is not currently read anywhere
static inline NSParagraphStyle* _paragraphStyleWithLineBreakMode(UILineBreakMode lineBreakMode) {
    NSMutableParagraphStyle* ret = [NSMutableParagraphStyle new];
    ret.lineBreakMode = lineBreakMode;
    return ret;
}

/**
 @Status Caveat
 @Notes lineBreakMode is currently not fully supported
*/
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size lineBreakMode:(UILineBreakMode)lineBreakMode {
    return [self _sizeWithAttributes:@{
        NSFontAttributeName : font,
        NSParagraphStyleAttributeName : _paragraphStyleWithLineBreakMode(lineBreakMode)
    }
                   constrainedToSize:size];
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size {
    return [self _sizeWithAttributes:@{ NSFontAttributeName : font } constrainedToSize:size];
}

/**
 @Status Caveat
 @Notes lineBreakMode is currently not fully supported
*/
- (CGSize)sizeWithFont:(UIFont*)font forWidth:(float)width lineBreakMode:(UILineBreakMode)lineBreakMode {
    return [self sizeWithFont:font constrainedToSize:{ width, std::numeric_limits<CGFloat>::max() } lineBreakMode:lineBreakMode];
}

/**
 @Status Caveat
 @Notes minFontSize, which is supposed to enable variable font-size scaling, is unsupported
        However, documentation for this function discourages changing the font size anyway, as it leads to an inconsistent user experience
        lineBreakMode is currently not fully supported
*/
- (CGSize)sizeWithFont:(UIFont*)font
           minFontSize:(float)minFontSize
        actualFontSize:(float*)actualFontSize
              forWidth:(float)width
         lineBreakMode:(UILineBreakMode)lineBreakMode {
    if (actualFontSize) {
        *actualFontSize = [font pointSize];
    }

    return [self sizeWithFont:font forWidth:width lineBreakMode:lineBreakMode];
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font {
    return [self sizeWithFont:font constrainedToSize:{ std::numeric_limits<CGFloat>::max(), std::numeric_limits<CGFloat>::max() }];
}

/**
 @Status Caveat
 @Notes not all attributes are currently supported
*/
- (CGSize)sizeWithAttributes:(NSDictionary<NSString*, id>*)attrs {
    return [self _sizeWithAttributes:attrs constrainedToSize:{ std::numeric_limits<CGFloat>::max(), std::numeric_limits<CGFloat>::max() }];
}

/**
 @Status Caveat
 @Notes Currently NSStringDrawingOptions will be ignored.
 Further only NSStringDrawingUsesLineFragmentOrigin is the only fully supported option. NSStringDrawingTruncatesLastVisibleLine maps to
 UILineBreakModeTailTruncation which may not fully map.
*/
- (CGRect)boundingRectWithSize:(CGSize)size
                       options:(NSStringDrawingOptions)options
                    attributes:(NSDictionary*)attributes
                       context:(NSStringDrawingContext*)context {
    if (attributes == nil) {
        return [self boundingRectWithSize:size options:options context:context];
    }

    if (context == nil) {
        context = [[NSStringDrawingContext new] autorelease];
    }

    UIFont* uiFont = [attributes valueForKey:UITextAttributeFont];
    if (uiFont != nil) {
        UILineBreakMode lineBreakMode = UILineBreakModeWordWrap;
        if ((options & NSStringDrawingTruncatesLastVisibleLine) > 0) {
            lineBreakMode = UILineBreakModeTailTruncation;
        }
        CGSize mySize = [self sizeWithFont:uiFont constrainedToSize:size lineBreakMode:lineBreakMode];
        CGRect rect = CGRectMake(0, 0, mySize.width, mySize.height);
        [context _setInternalTotalBounds:rect];
        return rect;
    } else {
        return [self boundingRectWithSize:size options:options context:context];
    }
}

// if provided size < mySize provide larger rect else provide the size rect.
/**
 @Status Caveat
 @Notes Currently NSStringDrawingOptions will be ignored.
 Further only NSStringDrawingUsesLineFragmentOrigin is the only fully supported option. NSStringDrawingTruncatesLastVisibleLine maps to
 UILineBreakModeTailTruncation which may not fully map.
*/
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options context:(NSStringDrawingContext*)context {
    if (context == nil) {
        context = [[NSStringDrawingContext new] autorelease];
    }

    UILineBreakMode lineBreakMode = UILineBreakModeWordWrap;
    if ((options & NSStringDrawingTruncatesLastVisibleLine) > 0) {
        lineBreakMode = UILineBreakModeTailTruncation;
    }

    UIFont* uiFont = [UIFont systemFontOfSize:[UIFont systemFontSize]];
    CGSize mySize = [self sizeWithFont:uiFont constrainedToSize:size lineBreakMode:lineBreakMode];
    CGRect rect = CGRectMake(0, 0, mySize.width, mySize.height);
    [context _setInternalTotalBounds:rect];
    return rect;
}

/**
 @Status Stub
 @Notes
*/
- (CGSize)drawAtPoint:(CGPoint)point forWidth:(CGFloat)width withFont:(UIFont*)font lineBreakMode:(NSLineBreakMode)lineBreakMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawWithRect:(CGRect)rect
             options:(NSStringDrawingOptions)options
          attributes:(NSDictionary*)attributes
             context:(NSStringDrawingContext*)context {
    UNIMPLEMENTED();
}

@end