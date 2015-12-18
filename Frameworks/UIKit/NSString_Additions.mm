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

#include "Starboard.h"
#include <UIKit/UIKit.h>
#include "CGFontInternal.h"
#include "CoreGraphics/CGContext.h"
#include "Foundation/NSMutableDictionary.h"
#include <assert.h>

void NSStringForceinclude() {
    [NSString class];
}

NSString* const UITextAttributeFont = @"UITextAttributeFont";
NSString* const UITextAttributeTextColor = @"UITextAttributeTextColor";
NSString* const UITextAttributeTextShadowColor = @"UITextAttributeTextShadowColor";
NSString* const UITextAttributeTextShadowOffset = @"UITextAttributeTextShadowOffset";

@implementation NSString (UIKitAdditions)
static void drawCharsAtPoint(UIFont* font,
                             CGContextRef context,
                             WORD* str,
                             DWORD strLength,
                             CGRect rct,
                             float x,
                             float y,
                             UITextAlignment alignment,
                             CGSize* sizeOut) {
    float size = [font pointSize];
    CGFontFitChars(font, size, str, strLength, 0, sizeOut);
    // CGFontMeasureGlyphs(font, size, str, strLength, sizeOut);

    //  Calculate output position
    float outX, outY = y;

    switch (alignment) {
        case UITextAlignmentLeft:
            outX = rct.origin.x;
            break;

        case UITextAlignmentCenter:
            outX = rct.origin.x + (rct.size.width / 2.0f) - (sizeOut->width / 2.0f);
            break;

        case UITextAlignmentRight:
            outX = rct.origin.x + rct.size.width - sizeOut->width;
            break;

        default:
            assert(0);
            break;
    }

    if (context) {
        CGAffineTransform t;

        CGContextSetFont(context, font);

        WORD* glyphs = (WORD*)EbrMalloc(strLength * sizeof(WORD));
        DWORD numGlyphs = CGFontGetGlyphs(font, str, strLength, glyphs);

        t = CGAffineTransformMakeScale(1.0, -1.0);
        CGContextSetTextMatrix(context, t);
        CGContextSetFontSize(context, size);
        CGContextTranslateCTM(context, 0, [font ascender]);
        CGContextShowGlyphsAtPoint(context, outX, outY, glyphs, numGlyphs);
        CGContextTranslateCTM(context, 0, -[font ascender]);

        EbrFree(glyphs);
    }
}

static void drawString(UIFont* font,
                       CGContextRef context,
                       WORD* str,
                       DWORD strLength,
                       CGRect rct,
                       UILineBreakMode lineBreakMode,
                       UITextAlignment alignment,
                       CGSize* sizeOut,
                       CGPoint* lastCharPos = NULL) {
    if (font == nil) {
        EbrDebugLog("drawString: font = nil!\n");
        return;
    }

    float size = [font pointSize];

    switch (lineBreakMode) {
        case UILineBreakModeWordWrap: {
            CGFontWrapState state;

            memset(&state, 0, sizeof(state));

            state.chars = str;
            state.count = strLength;
            state.curIndex = 0;
            float y = rct.origin.y;

            sizeOut->width = 0;
            sizeOut->height = 0;

            CGSize fitSize;

            //  Keep drawing lines of text until we're out of characters
            while (CGFontWrap(font, size, &state, rct.size.width, &fitSize)) {
                if (y + fitSize.height - rct.origin.y > rct.size.height && rct.size.height != 0.0f && sizeOut->height > 0.0f) {
                    break;
                }

                CGSize extent;

                //  Draw the string
                drawCharsAtPoint(font, context, state.lineStart, state.lineLen, rct, rct.origin.x, y, alignment, &extent);
                extent.height = ceilf(extent.height);
                extent.width = ceilf(extent.width);

                if (lastCharPos) {
                    lastCharPos->x = rct.origin.x + fitSize.width;
                    lastCharPos->y = y;
                }

                if (extent.width > sizeOut->width) {
                    sizeOut->width = extent.width;
                }
                if (y + extent.height - rct.origin.y > sizeOut->height) {
                    sizeOut->height = y + extent.height - rct.origin.y;
                }

                y += extent.height;
            }
            break;
        }

        case UILineBreakModeCharacterWrap: {
            WORD* curChar = str;
            DWORD charsLeft = strLength;
            float y = rct.origin.y;

            sizeOut->width = 0;
            sizeOut->height = 0;

            //  [BUG: self is doing word wrap]
            while (charsLeft > 0) {
                //  Measure how many chars can fit in self line
                DWORD num = CGFontFitChars(font, size, curChar, charsLeft, rct.size.width, NULL);
                DWORD numToDraw = num;

                CGSize extent;

                //  Draw the string
                drawCharsAtPoint(font, context, curChar, numToDraw, rct, rct.origin.x, y, alignment, &extent);
                extent.height = ceilf(extent.height);
                extent.width = ceilf(extent.width);

                if (extent.width > sizeOut->width) {
                    sizeOut->width = extent.width;
                }
                if (y + extent.height - rct.origin.y > sizeOut->height) {
                    sizeOut->height = y + extent.height - rct.origin.y;
                }

                y += extent.height;
                curChar += num;
                charsLeft -= num;

                //  Skip any trailing whitespace
                while (charsLeft > 0 && *curChar == ' ') {
                    charsLeft--;
                    curChar++;
                }
            }

            break;
        }

        case UILineBreakModeTailTruncation: {
            CGFontWrapState state;

            memset(&state, 0, sizeof(state));

            state.chars = str;
            state.count = strLength;
            state.curIndex = 0;
            float y = rct.origin.y;

            sizeOut->width = 0;
            sizeOut->height = 0;

            CGSize fitSize;

            //  Keep drawing lines of text until we're out of characters
            while (CGFontWrap(font, size, &state, rct.size.width, &fitSize)) {
                if (y + (fitSize.height * 2) - rct.origin.y > rct.size.height) {
                    //  Last line, do "..." truncation
                    CGSize totalSize;
                    str = state.lineStart;
                    strLength = (state.chars + strLength) - state.lineStart;
                    DWORD numTotal = CGFontFitChars(font, size, str, strLength, rct.size.width, &totalSize);

                    if (totalSize.width <= rct.size.width && numTotal == strLength) {
                        CGSize extent;
                        drawCharsAtPoint(font, context, str, strLength, rct, rct.origin.x, y, alignment, &extent);
                        extent.height = ceilf(extent.height);
                        extent.width = ceilf(extent.width);

                        if (extent.width > sizeOut->width) {
                            sizeOut->width = extent.width;
                        }
                        if (y + extent.height - rct.origin.y > sizeOut->height) {
                            sizeOut->height = y + extent.height - rct.origin.y;
                        }
                    } else {
                        // Measure how much the '...' will take between:
                        CGSize ellipseSize;
                        WORD ellipseText[] = { '.', '.', '.', '\0' };

                        // If we can't even fit the ellipse in the middle, not much chance of us fitting
                        if (CGFontFitChars(font, size, ellipseText, 3, rct.size.width, &ellipseSize) < 3) {
                            break;
                        }

                        // Allocate enough room for the entire string, a null terminator and the ...s
                        WORD* tempStr = (WORD*)EbrMalloc(sizeof(WORD) * (strLength + 4));

                        size_t lastGood = 0;
                        for (size_t i = 1; i <= strLength; ++i) {
                            size_t leftCount = i;
                            memcpy(tempStr, str, leftCount * sizeof(WORD));
                            memcpy(tempStr + leftCount, ellipseText, 3 * sizeof(WORD));

                            size_t len = i + 3;
                            if (CGFontFitChars(font, size, tempStr, len, rct.size.width, &totalSize) < len ||
                                totalSize.width >= rct.size.width || totalSize.width == 0.f) {
                                break;
                            }
                            lastGood = i;
                        }

                        // Produce and render the good string:
                        size_t leftCount = lastGood;
                        memcpy(tempStr, str, leftCount * sizeof(WORD));
                        memcpy(tempStr + leftCount, ellipseText, 3 * sizeof(WORD));

                        CGSize extent;
                        drawCharsAtPoint(font, context, tempStr, lastGood + 3, rct, rct.origin.x, y, alignment, &extent);
                        extent.height = ceilf(extent.height);
                        extent.width = ceilf(extent.width);

                        if (extent.width > sizeOut->width) {
                            sizeOut->width = extent.width;
                        }
                        if (y + extent.height - rct.origin.y > sizeOut->height) {
                            sizeOut->height = y + extent.height - rct.origin.y;
                        }

                        EbrFree(tempStr);
                    }
                    break;
                } else {
                    CGSize extent;

                    //  Draw the string
                    drawCharsAtPoint(font, context, state.lineStart, state.lineLen, rct, rct.origin.x, y, alignment, &extent);
                    extent.height = ceilf(extent.height);
                    extent.width = ceilf(extent.width);

                    if (extent.width > sizeOut->width) {
                        sizeOut->width = extent.width;
                    }
                    if (y + extent.height - rct.origin.y > sizeOut->height) {
                        sizeOut->height = y + extent.height - rct.origin.y;
                    }

                    y += extent.height;
                }
            }
            break;
        }

        case UILineBreakModeMiddleTruncation: {
            CGSize totalSize;
            DWORD numTotal = CGFontFitChars(font, size, str, strLength, rct.size.width, &totalSize);

            if (totalSize.width <= rct.size.width && totalSize.width != 0.f && numTotal == strLength) {
                CGSize extent;
                drawCharsAtPoint(font, context, str, strLength, rct, rct.origin.x, rct.origin.y, alignment, &extent);
                extent.height = ceilf(extent.height);
                extent.width = ceilf(extent.width);
                *sizeOut = extent;
            } else {
                // Measure how much the '...' will take between:
                CGSize ellipseSize;
                WORD ellipseText[] = { '.', '.', '.', '\0' };

                // If we can't even fit the ellipse in the middle, not much chance of us fitting
                if (CGFontFitChars(font, size, ellipseText, 3, rct.size.width, &ellipseSize) < 3) {
                    break;
                }

                // Allocate enough room for the entire string, a null terminator and the ...s
                WORD* tempStr = (WORD*)EbrMalloc(sizeof(WORD) * (strLength + 4));

                size_t lastGood = 0;
                for (size_t i = 1; i <= strLength; ++i) {
                    size_t leftCount = (i + 1) / 2, rightCount = i / 2;
                    memcpy(tempStr, str, leftCount * sizeof(WORD));
                    memcpy(tempStr + leftCount, ellipseText, 3 * sizeof(WORD));
                    memcpy(tempStr + leftCount + 3, str + strLength - rightCount, rightCount * sizeof(WORD));

                    size_t len = i + 3;
                    if (CGFontFitChars(font, size, tempStr, len, rct.size.width, &totalSize) < len || totalSize.width >= rct.size.width ||
                        totalSize.width == 0.f) {
                        break;
                    }
                    lastGood = i;
                }

                // Produce and render the good string:
                size_t leftCount = (lastGood + 1) / 2, rightCount = lastGood / 2;
                memcpy(tempStr, str, leftCount * sizeof(WORD));
                memcpy(tempStr + leftCount, ellipseText, 3 * sizeof(WORD));
                memcpy(tempStr + leftCount + 3, str + strLength - rightCount, rightCount * sizeof(WORD));

                CGSize extent;
                drawCharsAtPoint(font, context, tempStr, lastGood + 3, rct, rct.origin.x, rct.origin.y, alignment, &extent);
                extent.height = ceilf(extent.height);
                extent.width = ceilf(extent.width);
                *sizeOut = extent;

                EbrFree(tempStr);
            }
            break;
        }

        case UILineBreakModeClip: {
            CGSize extent;

            //  Draw the string
            drawCharsAtPoint(font, context, str, strLength, rct, rct.origin.x, rct.origin.y, alignment, &extent);
            extent.height = ceilf(extent.height);
            extent.width = ceilf(extent.width);
            *sizeOut = extent;
            break;
        }

        default:
            assert(0);
    }
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, UILineBreakModeWordWrap, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode alignment:(UITextAlignment)alignment {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, lineBreakMode, alignment, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawInRect:(CGRect)rct withFont:(UIFont*)font lineBreakMode:(UILineBreakMode)lineBreakMode {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, lineBreakMode, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)drawAtPoint:(CGPoint)pt withFont:(UIFont*)font {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = 0;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Caveat
 @Notes Currently UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset will be ignored.
*/
- (void)drawAtPoint:(CGPoint)pt withAttributes:(NSDictionary*)attrs {
    if (attrs == nil) {
        return;
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
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

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
        lineBreakMode:(DWORD)lineBreak
   baselineAdjustment:(DWORD)baseline {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);
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
        lineBreakMode:(DWORD)lineBreak
   baselineAdjustment:(DWORD)baseline {
    CGSize fontExtent;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;

    rct.origin.x = pt.x;
    rct.origin.y = pt.y;
    rct.size.width = forWidth;
    rct.size.height = 0;

    font = [font fontWithSize:fontSize];

    drawString(font, UIGraphicsGetCurrentContext(), str, [self length], rct, UILineBreakModeClip, UITextAlignmentLeft, &fontExtent);

    return fontExtent;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size lineBreakMode:(UILineBreakMode)lineBreakMode {
    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;
    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size = size;

    drawString(font, NULL, str, [self length], rct, lineBreakMode, UITextAlignmentLeft, &ret);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font constrainedToSize:(CGSize)size {
    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;
    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size = size;

    drawString(font, NULL, str, [self length], rct, UILineBreakModeWordWrap, UITextAlignmentLeft, &ret);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font forWidth:(float)width lineBreakMode:(UILineBreakMode)lineBreakMode {
    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct = { 0 };
    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size.width = width;

    drawString(font, NULL, str, [self length], rct, lineBreakMode, UITextAlignmentLeft, &ret);

    return ret;
}

- (CGSize)sizeWithFont:(UIFont*)font forWidth:(float)width lineBreakMode:(UILineBreakMode)lineBreakMode lastCharPos:(CGPoint*)lastCharPos {
    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct = { 0 };
    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size.width = width;

    drawString(font, NULL, str, [self length], rct, lineBreakMode, UITextAlignmentLeft, &ret, lastCharPos);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font
           minFontSize:(float)minFontSize
        actualFontSize:(float*)actualFontSize
              forWidth:(float)forWidth
         lineBreakMode:(UILineBreakMode)lineBreak {
    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;

    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size.width = forWidth;
    rct.size.height = 0;

    drawString(font, NULL, str, [self length], rct, lineBreak, UITextAlignmentLeft, &ret);
    if (actualFontSize) {
        *actualFontSize = 10.0f;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeWithFont:(UIFont*)font {
    if (font == nil) {
        font = [objc_getClass("UIFont") defaultFont];
    }

    CGSize ret;
    WORD* str = (WORD*)[self rawCharacters];

    CGRect rct;
    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size.width = 0;
    rct.size.height = 0;

    drawString(font, NULL, str, [self length], rct, UILineBreakModeClip, UITextAlignmentLeft, &ret);

    return ret;
}

/**
 @Status Caveat
 @Notes Currently UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset will be ignored.
*/
- (CGSize)sizeWithAttributes:(NSDictionary*)attrs {
    if (attrs == nil) {
        return {0, 0};
    }

    UIColor* uiShadowColor = [attrs valueForKey:UITextAttributeTextShadowColor];
    NSValue* textShadowOffset = [attrs valueForKey:UITextAttributeTextShadowOffset];

    // TODO enable UITextAttributeTextShadowColor and UITextAttributeTextShadowOffset
    if (uiShadowColor != nil && textShadowOffset != nil) {
        CGSize offset = textShadowOffset.sizeValue;
        CGContextSetShadowWithColor(UIGraphicsGetCurrentContext(), offset, 0, [uiShadowColor CGColor]);
    } else if (textShadowOffset != nil) {
        CGSize offset = textShadowOffset.sizeValue;
        CGContextSetShadow(UIGraphicsGetCurrentContext(), offset, 0);
    }

    UIColor* uiTextColor = [attrs valueForKey:UITextAttributeTextColor];
    if (uiTextColor != nil) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [uiTextColor CGColor]);
    }

    UIFont* uiFont = [attrs valueForKey:UITextAttributeFont];
    if (uiFont != nil) {
        return [self sizeWithFont:uiFont];
    }
    
    // No font was found
    return {0, 0};
}

/**
 @Status Stub
*/
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options attributes:(NSDictionary*)attributes context:(NSStringDrawingContext*)context {
    UNIMPLEMENTED();
    return {{0, 0}, 20, 20};
}

@end
