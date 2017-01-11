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

@interface UISegment : UIView {
@public
    id _delegate;
    idretain _title;
    StrongId<UIImage> _image;
    StrongId<UIImage> _selectedBackground;
    StrongId<UIImage> _highlightedBackground;
    StrongId<UIImage> _dividerImage;
    idretain _segmentFont;
    idretain _textColor[2];
    StrongId<UIColor> _tintColor;
    unsigned _position;
    unsigned _type, _selected;
    unsigned _disabled;
    float _overrideWidth;
    BOOL _noDefaultImages;
}
- (float)_contentWidth;
- (float)_desiredWidth;
- (unsigned)position;
- (BOOL)isEnabled;
- (void)dealloc;
- (instancetype)initWithCoder:(id)coder;
- (instancetype)initWithTitle:(id)title;
- (instancetype)initWithImage:(id)image;
- (id)setDelegate:(id)delegate;
- (id)setTitle:(id)title;
- (id)setImage:(id)image;
- (id)image;
- (id)title;
- (id)_setType:(DWORD)type;
- (id)_setSelected:(DWORD)selected;
- (id)setEnabled:(DWORD)enabled;
- (id)drawRect:(CGRect)inRect;
- (id)_setWidth:(float)width;
- (id)touchesBegan:(id)touchSet withEvent:(id)event;
- (id)touchesEnded:(id)touchSet withEvent:(id)event;
- (id)touchesCancelled:(id)touchSet withEvent:(id)event;
- (id)_setBackgroundImage:(id)image forState:(DWORD)state;
- (id)_setAttributes:(id)attributes forState:(DWORD)state;
- (id)_setDividerImage:(id)image;
- (id)_setNoDefaultImages:(BOOL)noDefault;
- (id)_setTintColor:(UIColor*)color;
+ (instancetype)initialize;
@end
