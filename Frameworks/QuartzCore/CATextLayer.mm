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
#include "UIKit/UIColor.h"
#include "Foundation/NSString.h"
#include "CoreGraphics/CGContext.h"
#include "CGContextInternal.h"
#include "QuartzCore/CATextLayer.h"
#include "CALayerInternal.h"
#include "CACompositor.h"
#include "CATextLayerInternal.h"

NSString* const kCATruncationNone = @"kCATruncationNone";
NSString* const kCATruncationStart = @"kCATruncationStart";
NSString* const kCATruncationEnd = @"kCATruncationEnd";
NSString* const kCATruncationMiddle = @"kCATruncationMiddle";
NSString* const kCAAlignmentNatural = @"kCAAlignmentNatural";
NSString* const kCAAlignmentLeft = @"kCAAlignmentLeft";
NSString* const kCAAlignmentRight = @"kCAAlignmentRight";
NSString* const kCAAlignmentCenter = @"kCAAlignmentCenter";
NSString* const kCAAlignmentJustified = @"kCAAlignmentJustified";

@implementation CATextLayer {
    idretain __font;
    idretain _text;
    idretain _color, _shadowColor;
    CGSize _shadowOffset;
    UITextAlignment _alignment;
    UILineBreakMode _lineBreakMode;
    int _numLines;
    UIEdgeInsets _edgeInsets;
    BOOL _centerVertically;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        __font = nil;
        _centerVertically = true;

        // CATextLayer is the CALayer for UILabel. By default, when text is centered vertical,
        // it will take left alignment as well. Thus we should set contentGravity to left
        self.contentsGravity = kCAGravityLeft;
    }
    return self;
}

- (void)dealloc {
    __font = nil;
    _text = nil;
    _color = nil;
    _shadowColor = nil;

    [super dealloc];
}

- (DisplayTexture*)_getDisplayTexture {
    if ([self _priv]->_shouldRasterize) {
        return (DisplayTexture*)[super _getDisplayTexture];
    }

    [self _priv]->contentsSize.width = ceilf([self _priv]->bounds.size.width) * [self _priv]->contentsScale;
    [self _priv]->contentsSize.height = ceilf([self _priv]->bounds.size.height) * [self _priv]->contentsScale;

    if (__font == nil || _text == nil) {
        return nullptr;
    }

    DisplayTexture* textLayer = _globalCompositor->CreateDisplayTextureForText();
    GetCACompositor()->SetTextDisplayTextureParams(textLayer,
                                                   __font,
                                                   _text,
                                                   _color,
                                                   _alignment,
                                                   _lineBreakMode,
                                                   _shadowColor,
                                                   _shadowOffset,
                                                   _numLines,
                                                   _edgeInsets,
                                                   _centerVertically);

    return textLayer;
}

- (void)_setDisplayParams:(UIFont*)font
                     text:(NSString*)text
                    color:(UIColor*)color
                alignment:(UITextAlignment)alignment
                lineBreak:(UILineBreakMode)lineBreak
              shadowColor:(UIColor*)shadowColor
             shadowOffset:(CGSize)shadowOffset
                 numLines:(int)numLines {
    __font = font;
    _text = text;
    _alignment = alignment;
    _color = color;
    _shadowColor = shadowColor;
    _shadowOffset = shadowOffset;
    _lineBreakMode = lineBreak;
    _numLines = numLines;
}

@end
