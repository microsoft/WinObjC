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
#import "CGContextInternal.h"
#import "NSParagraphStyleInternal.h"
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
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font {
    return [self drawInRect:rect withFont:font lineBreakMode:UILineBreakModeWordWrap];
}

/**
 @Status Caveat
 @Notes Clipping line break modes unsupported
*/
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode {
    return [self drawInRect:rect withFont:font lineBreakMode:lineBreakMode alignment:UITextAlignmentLeft];
}

/**
 @Status Caveat
 @Notes Clipping line break modes unsupported
*/
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode alignment:(UITextAlignment)alignment {
    // 0 Width or Height treated as unlimited bounds
    if (rect.size.width == 0) {
        rect.size.width = std::numeric_limits<CGFloat>::max();
    }

    if (rect.size.height == 0) {
        rect.size.height = std::numeric_limits<CGFloat>::max();
    }

    CTParagraphStyleSetting styles[2];
    CTTextAlignment align = NSTextAlignmentToCTTextAlignment(alignment);
    styles[0] = { kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &align };

    CTLineBreakMode breakMode = static_cast<CTLineBreakMode>(lineBreakMode);
    styles[1] = { kCTParagraphStyleSpecifierLineBreakMode, sizeof(CTLineBreakMode), &breakMode };

    NSAttributedString* attr = [[[NSAttributedString alloc]
        initWithString:self
            attributes:@{
                (NSString*)kCTForegroundColorFromContextAttributeName : (id)kCFBooleanTrue,
                (NSString*)kCTParagraphStyleAttributeName : (id)CTParagraphStyleCreate(styles, std::extent<decltype(styles)>::value),
                (NSString*)kCTFontAttributeName : (font ? font : [UIFont defaultFont])
            }] autorelease];

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(static_cast<CFAttributedStringRef>(attr)) };
    if (framesetter == nil) {
        return CGSizeZero;
    }

    woc::unique_cf<CGPathRef> path{ CGPathCreateWithRect(rect, nullptr) };
    if (path == nil) {
        return CGSizeZero;
    }

    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), {}, path.get(), nullptr) };
    if (frame == nil) {
        return CGSizeZero;
    }

    CGContextRef context = UIGraphicsGetCurrentContext();
    _CGContextPushBeginDraw(context);
    auto popEnd = wil::ScopeExit([context]() { _CGContextPopEndDraw(context); });

    // Invert text matrix so glyphs are drawn with correct orientation
    CGContextSetTextMatrix(context, CGAffineTransformMakeScale(1.0f, -1.0f));

    // Can't draw the entire frame because it assumes our space has been flipped and translated
    NSArray* lines = static_cast<NSArray*>(CTFrameGetLines(frame.get()));
    if ([lines count] != 0) {
        std::vector<CGPoint> origins([lines count]);
        CTFrameGetLineOrigins(frame.get(), {}, origins.data());
        for (size_t i = 0; i < origins.size(); ++i) {
            // Need to set text position so each line will be drawn in the correct position relative to each other
            CGContextSetTextPosition(context, rect.origin.x + origins[i].x, rect.origin.y + origins[i].y);
            CTLineDraw(static_cast<CTLineRef>(lines[i]), context);
        }
    }

    return _CTFrameGetSize(frame.get());
}

/**
 @Status Interoperable
*/
- (CGSize)drawAtPoint:(CGPoint)point withFont:(UIFont*)font {
    return [self drawAtPoint:point forWidth:0 withFont:font];
}

/**
 @Status Caveat
 @Notes Currently UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset will be ignored.
*/
- (void)drawAtPoint:(CGPoint)point withAttributes:(NSDictionary*)attrs {
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
        [self drawAtPoint:point withFont:uiFont];
    }
}

- (CGSize)drawAtPoint:(CGPoint)point forWidth:(float)width withFont:(UIFont*)font {
    return [self drawInRect:{ point, CGSizeMake(width, 0) } withFont:font lineBreakMode:UILineBreakModeClip];
}

/**
 @Status Caveat
 @Notes parameter baselineAdjustment and minFontSize are ignored as text is drawn at given text size
*/
- (CGSize)drawAtPoint:(CGPoint)point
              forWidth:(float)width
              withFont:(UIFont*)font
           minFontSize:(float)minFontSize
        actualFontSize:(float*)actualFontSize
         lineBreakMode:(UILineBreakMode)lineBreak
    baselineAdjustment:(UIBaselineAdjustment)baseline {
    if (actualFontSize) {
        *actualFontSize = 10.0f;
    }
    return [self drawInRect:{ point, CGSizeMake(width, 0) } withFont:font lineBreakMode:lineBreak];
}

/**
 @Status Caveat
 @Notes parameter baselineAdjustment is ignored
*/
- (CGSize)drawAtPoint:(CGPoint)point
              forWidth:(float)width
              withFont:(UIFont*)font
              fontSize:(float)fontSize
         lineBreakMode:(UILineBreakMode)lineBreak
    baselineAdjustment:(UIBaselineAdjustment)baseline {
    font = [font fontWithSize:fontSize];
    return [self drawInRect:{ point, CGSizeMake(width, 0) } withFont:font lineBreakMode:lineBreak];
}

// Private helper for sizeWith... functions
// Returns the bounding box size this string would occupy when drawn as specified
// All sizeWith... functions in this file funnel to this
- (CGSize)_sizeWithAttributes:(NSDictionary<NSString*, id>*)attributes constrainedToSize:(CGSize)size {
    UIFont* font = attributes[NSFontAttributeName];
    if (font == nil) {
        return CGSizeZero;
    }

    if ([attributes objectForKey:NSParagraphStyleAttributeName]) {
        NSMutableDictionary* copied = [NSMutableDictionary dictionaryWithDictionary:attributes];
        woc::unique_cf<CTParagraphStyleRef>
            paragraphStyle{[[attributes objectForKey:NSParagraphStyleAttributeName] _createCTParagraphStyle] };
        [copied setObject:(id)paragraphStyle.get() forKey:static_cast<NSString*>(kCTParagraphStyleAttributeName)];
        attributes = copied;
    }

    NSAttributedString* attributedSelf = [[[NSAttributedString alloc] initWithString:self attributes:attributes] autorelease];
    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef)attributedSelf) };

    if (size.width == 0.0) {
        size.width = std::numeric_limits<CGFloat>::max();
    }

    if (size.height == 0.0) {
        size.height = std::numeric_limits<CGFloat>::max();
    }

    CGSize ret = CTFramesetterSuggestFrameSizeWithConstraints(framesetter.get(), CFRangeMake(0, self.length), nullptr, size, nullptr);

    // If the constrained height is less than a line height sizeWithFont will increase the returned size to fit at least one line
    CGFloat lineHeight = [font ascender] - [font descender];
    ret.height = std::max(ret.height, lineHeight);

    return ret;
}

// Private helper that converts a UILineBreakMode -> NSParagraphStyle
static inline NSParagraphStyle* _paragraphStyleWithLineBreakMode(UILineBreakMode lineBreakMode) {
    NSMutableParagraphStyle* ret = [[[NSMutableParagraphStyle alloc] init] autorelease];
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
