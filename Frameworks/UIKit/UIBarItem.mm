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

#import "Starboard.h"
#import "UIKit/UIBarItem.h"
#import "UIKit/UIView.h"
#import "UIBarItemInternal.h"
#import <StubReturn.h>

@implementation UIBarItem {
    idretaintype(NSString) __title;
    idretaintype(UIFont) _font;
    idretaintype(UIImage) _backImage;
    idretaintype(UIView) _customView;
    idretaintype(UIButton) _buttonView;

    id _target;
    SEL _targetSel;
    float _width;
    UIBarButtonSystemItem _systemItem;
    bool _pressed;
    UIBarButtonItemStyle _style;

    idretaintype(UIColor) _tintColor;
}

- (void)awakeFromNib {
}

- (void)setTintColor:(UIColor*)color {
    _tintColor = color;
}

- (UIColor*)tintColor {
    return _tintColor;
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image {
    _image = image;
}

/**
 @Status Interoperable
*/
- (UIImage*)image {
    return _image;
}

- (void)dealloc {
    _tintColor = nil;
    [super dealloc];
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

@end
