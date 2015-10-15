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

@interface UISegment : UIView {
@public
    id _delegate;
    idretain _title;
    idretain _image;
    idretain _selectedBackground, _highlightedBackground;
    idretain _dividerImage;
    idretain _segmentFont;
    idretain _textColor[2];
    id _tintColor;
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
/* annotate with type */ -(id)initWithCoder : (id)coder;
/* annotate with type */ -(id)initWithTitle : (id)title;
/* annotate with type */ -(id)initWithImage : (id)image;
/* annotate with type */ -(id)setDelegate : (id)delegate;
/* annotate with type */ -(id)setTitle : (id)title;
/* annotate with type */ -(id)setImage : (id)image;
/* annotate with type */ -(id)image;
/* annotate with type */ -(id)title;
/* annotate with type */ -(id)buttonClicked : (id)button;
/* annotate with type */ -(id)_setType : (DWORD)type;
/* annotate with type */ -(id)_setSelected : (DWORD)selected;
/* annotate with type */ -(id)setEnabled : (DWORD)enabled;
/* annotate with type */ -(id)drawRect : (CGRect)inRect;
/* annotate with type */ -(id)_setWidth : (float)width;
/* annotate with type */ -(id)touchesBegan : (id)touchSet withEvent : (id)event;
/* annotate with type */ -(id)touchesEnded : (id)touchSet withEvent : (id)event;
/* annotate with type */ -(id)touchesCancelled : (id)touchSet withEvent : (id)event;
/* annotate with type */ -(id)_setBackgroundImage : (id)image forState : (DWORD)state;
/* annotate with type */ -(id)_setAttributes : (id)attributes forState : (DWORD)state;
/* annotate with type */ -(id)_setDividerImage : (id)image;
/* annotate with type */ -(id)_setNoDefaultImages : (BOOL)noDefault;
/* annotate with type */ -(id)_setTintColor : (id)color;
/* annotate with type */ +(id)initialize;
@end
