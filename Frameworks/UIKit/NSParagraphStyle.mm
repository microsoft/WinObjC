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

#include "UIKit/NSParagraphStyle.h"

@implementation NSParagraphStyle {
@protected

    float _hyphenationFactor;
    NSTextAlignment _alignment;
    NSLineBreakMode _lineBreakMode;
}
@synthesize hyphenationFactor = _hyphenationFactor;
@synthesize alignment = _alignment;

@end

@implementation NSMutableParagraphStyle
- (void)setHyphenationFactor:(float)factor {
    _hyphenationFactor = factor;
}

- (void)setAlignment:(NSTextAlignment)alignment {
    _alignment = alignment;
}

- (void)setLineBreakMode:(NSLineBreakMode)mode {
    _lineBreakMode = mode;
}
@end
