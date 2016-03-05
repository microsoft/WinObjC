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
#include "CGFontInternal.h"
#include "CGContextInternal.h"
#include "QuartzCore/CATextLayer.h"
#include "CALayerInternal.h"
#include "CACompositor.h"

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
    if (priv->_shouldRasterize) {
        return (DisplayTexture*)[super _getDisplayTexture];
    }

    priv->contentsSize.width = ceilf(priv->bounds.size.width) * priv->contentsScale;
    priv->contentsSize.height = ceilf(priv->bounds.size.height) * priv->contentsScale;

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
                         :(NSString*)text
                         :(UIColor*)color
                         :(UITextAlignment)alignment
                         :(UILineBreakMode)lineBreak
                         :(UIColor*)shadowColor
                         :(CGSize)shadowOffset
                         :(int)numLines {
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
