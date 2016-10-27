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

#import <Foundation/Foundation.h>
#import "CGDrawOptions.h"

@implementation CGDrawOptions

- (id)initWithLineWidth:(CGFloat)lineWidth
              lineColor:(CGColorRef)lineColor
              fillColor:(CGColorRef)fillColor
        lineDashPattern:(CGFloat*)dashPattern
              linePhase:(CGFloat)linePhase
              dashCount:(size_t)dashCount {
    if (self = [super init]) {
        _lineWidth = lineWidth;
        _lineColor = lineColor;
        CGColorRetain(_lineColor);
        _fillColor = fillColor;
        CGColorRetain(_fillColor);
        _lineDashPattern = dashPattern;
        _linePhase = linePhase;
        _lineDashCount = dashCount;
    }
    return self;
}

- (void)dealloc {
    CGColorRelease(_lineColor);
    CGColorRelease(_fillColor);
}

@end
