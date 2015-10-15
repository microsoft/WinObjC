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
#include "UIBarItemInternal.h"

@implementation UIBarButtonItem {
    idretaintype(NSString) _title;
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
}
static void initInternal(UIBarButtonItem* self) {
    if (isOSTarget(@"7.0")) {
        self->_font = [UIFont boldSystemFontOfSize:17];
    } else {
        self->_font = [UIFont boldSystemFontOfSize:14];
    }
    self->_systemItem = (UIBarButtonSystemItem)-1;
}

static void initControls(UIBarButtonItem* self) {
    if (self->_systemItem != UIBarButtonSystemItemFlexibleSpace && self->_systemItem != UIBarButtonSystemItemFixedSpace &&
        self->_customView == nil) {
        CGRect frame = { 0, 0, 0, 0 };

        self->_buttonView.attach([[UIButton alloc] initWithFrame:frame]);

        bool noBorder = false;

        id infoDict = [[NSBundle mainBundle] infoDictionary];
        if (isOSTarget(@"7.0")) {
            noBorder = true;
        }
        if (self->_style != UIBarButtonItemStylePlain && noBorder == false) {
            id image = [[UIImage imageNamed:@"/img/blackbutton-normal@2x.png"] stretchableImageWithLeftCapWidth:9 topCapHeight:0];
            id pressedImage = [[UIImage imageNamed:@"/img/blackbutton-pressed@2x.png"] stretchableImageWithLeftCapWidth:9 topCapHeight:0];

            [self->_buttonView setBackgroundImage:(id)image forState:0];
            [self->_buttonView setBackgroundImage:(id)pressedImage forState:1];
        }

        [self->_buttonView setTitle:(id)self->_title forState:0];
        [self->_buttonView setImage:(id)self->_image forState:0];
        [self->_buttonView setFont:(id)self->_font];
        [self->_buttonView addTarget:self action:@selector(_sendAction:) forControlEvents:UIControlEventTouchUpInside];
        [[self->_buttonView titleLabel] setLineBreakMode:UILineBreakModeMiddleTruncation];
    }
}

- (NSObject*)initWithCoder:(NSCoder*)coder {
    id customView = [coder decodeObjectForKey:@"UICustomView"];
    if (customView != nil) {
        [self initWithCustomView:customView];
    } else {
        BOOL isSystem = [coder decodeBoolForKey:@"UIIsSystemItem"];
        if (isSystem) {
            UIBarButtonSystemItem systemID = (UIBarButtonSystemItem)[coder decodeIntForKey:@"UISystemItem"];

            [self initWithBarButtonSystemItem:systemID target:nil action:NULL];
        } else {
            _image = [coder decodeObjectForKey:@"UIImage"];
            id title = [coder decodeObjectForKey:@"UITitle"];
            UIBarButtonItemStyle style = (UIBarButtonItemStyle)[coder decodeIntForKey:@"UIStyle"];
            [self initWithTitle:title style:style target:nil action:NULL];
        }

        if ([coder containsValueForKey:@"UIWidth"]) {
            _width = [coder decodeFloatForKey:@"UIWidth"];
        }
    }
    initControls(self);

    return self;
}

- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)sysItem target:(id)target action:(SEL)targetSel {
    _width = 35.0f;

    initInternal(self);

    _systemItem = sysItem;
    _style = UIBarButtonItemStyleBordered;

    switch (sysItem) {
        case UIBarButtonSystemItemDone:
            _title = @"Done";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemCancel:
            _title = @"Cancel";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemFlexibleSpace:
            _title = nil;
            _width = 0.0f;
            break;

        case UIBarButtonSystemItemFixedSpace:
            _title = nil;
            _width = 32.0f;
            break;

        case UIBarButtonSystemItemAdd:
            _title = @"Add";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemSave:
            _title = @"Save";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemReply:
            _title = @"Reply";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemRewind:
            _title = @"<";
            _width = 35.0f;
            break;

        case UIBarButtonSystemItemPlay:
            _title = @"|>";
            _width = 35.0f;
            break;

        case UIBarButtonSystemItemSearch:
            _title = @"Search";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemCamera:
            _title = @"Camera";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemAction:
            _title = @"Action";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemCompose:
            _width = 32.0f;
            _title = nil;
            _image = [UIImage imageNamed:@"/img/barbutton-compose.png"];
            break;

        case UIBarButtonSystemItemFastForward:
            _title = @">";
            _width = 35.0f;
            break;

        case UIBarButtonSystemItemRefresh: {
            _width = 32.0f;
            _title = nil;
            _image = [UIImage imageNamed:@"/img/refresh.png"];
        } break;

        case UIBarButtonSystemItemTrash:
            _title = @"Trash";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemPause:
            _title = @"||";
            _width = 35.0f;
            break;

        case UIBarButtonSystemItemOrganize:
            _title = @"Organize";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemStop:
            _title = @"X";
            _width = 35.0f;
            break;

        case UIBarButtonSystemItemEdit:
            _title = @"Edit";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemBookmarks:
            _title = @"Book";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case 0x15:
            _title = @"Undo";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case 0x16:
            _title = @"Redo";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case 0x17:
            _title = @"Curl";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        default:
            assert(0);
            break;
    }
    _target = target;
    _targetSel = targetSel;
    initControls(self);

    return self;
}

- (instancetype)initWithCustomView:(UIView*)view {
    initInternal(self);

    _customView = view;
    initControls(self);

    return self;
}

- (instancetype)initWithTitle:(NSString*)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)targetSel {
    _style = style;
    initInternal(self);
    _title.attach([title copy]);
    _target = target;
    _targetSel = targetSel;
    initControls(self);

    return self;
}

- (instancetype)initWithImage:(UIImage*)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)targetSel {
    initInternal(self);

    _target = target;
    _targetSel = targetSel;
    _image = image;
    _style = style;
    initControls(self);

    return self;
}

- (id)init {
    initInternal(self);
    initControls(self);

    return self;
}

- (void)addEventConnection:(UIRuntimeEventConnection*)connection {
    _target = [connection obj];
    _targetSel = (SEL)[connection sel];
}

- (void)setStyle:(UIBarButtonItemStyle)style {
    _style = style;
}

- (UIBarButtonItemStyle)style {
    return _style;
}

- (void)setWidth:(float)width {
    _width = width;
}

- (float)width {
    return _width;
}

- (float)_margin {
    if (_systemItem == UIBarButtonSystemItemFlexibleSpace || _systemItem == UIBarButtonSystemItemFixedSpace) {
        return 0.0f;
    }

    if (_customView == nil) {
        return 4.0f;
    } else {
        if ([_customView isKindOfClass:[UISegmentedControl class]]) {
            return 5.0f;
        } else if ([_customView isKindOfClass:[UIButton class]]) {
            return 0.0f;
        } else {
            return 12.0f;
        }
    }
}

- (void)_idealSize:(CGSize*)sizeOut {
    sizeOut->height = 34.0f;
    if (_width > 0.0f) {
        sizeOut->width = _width;
        return;
    } else {
        if (_customView == nil) {
            CGSize size = { 0, 0 };
            if (_title != nil) {
                size = [_title sizeWithFont:(id)_font];
                sizeOut->width = size.width + 16.0f;
                return;
            } else if (_image != nil) {
                float padding = _style == UIBarButtonItemStylePlain ? 0.0f : 15.0f;
                size = [_image size];

                sizeOut->width = size.width + padding;

                if (_style == UIBarButtonItemStylePlain) {
                    sizeOut->height = size.height;
                }

                return;
            } else {
                sizeOut->width = 0.0f;
                return;
            }
        } else {
            CGRect bounds;

            bounds = [_customView bounds];
            *sizeOut = bounds.size;
            return;
        }
    }
}

- (void)setTitle:(NSString*)title {
    _title.attach([title copy]);
    [_buttonView setTitle:(id)_title forState:0];
}

- (NSString*)title {
    return _title;
}

- (SEL)action {
    return _targetSel;
}

- (UIView*)customView {
    return _customView;
}

- (void)setCustomView:(UIView*)view {
    _customView = view;
}

- (void)setTarget:(id)target {
    _target = target;
}

- (id)target {
    return _target;
}

- (void)setAction:(SEL)pSel {
    _targetSel = pSel;
}

- (void)setImage:(UIImage*)image {
    _image = image;
    [_buttonView setImage:(id)_image forState:0];
}

- (UIImage*)image {
    return _image;
}

- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state barMetrics:(UIBarMetrics)metrics {
    EbrDebugLog("UIBarButtonItem setBackgroundImage not fully supported\n");
    [_buttonView setBackgroundImage:image forState:state];
}

- (void)setTitlePositionAdjustment:(CGPoint)position forBarMetrics:(UIBarMetrics)metrics {
    EbrDebugLog("UIBarButtonItem setTitlePositionAdjustmentForBarMetrics not supported\n");
}

- (void)setBackButtonTitlePositionAdjustment:(UIOffset)position forBarMetrics:(UIBarMetrics)metrics {
    EbrDebugLog("setBackButtonTitlePositionAdjustment not supported\n");
}

- (void)setBackButtonBackgroundImage:(UIImage*)image forState:(UIControlState)state barMetrics:(UIBarMetrics)metrics {
    EbrDebugLog("UIBarButtonItem setBackButtonBackgroundImage not supported\n");
    _backImage = image;
}

- (UIImage*)backButtonBackgroundImage {
    return _backImage;
}

- (void)setTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state {
    id font = [attributes objectForKey:@"kCTFontAttributeName"];
    id textColor = [attributes objectForKey:@"UITextAttributeTextColor"];

    if (font != nil) {
        [_buttonView setFont:font];
        if ([_customView respondsToSelector:@selector(setFont:)]) {
            [_customView setFont:font];
        }
    }
    if (textColor != nil) {
        [_buttonView setTitleColor:textColor forState:state];
        if ([_customView respondsToSelector:@selector(setTitleColor:forState:)]) {
            [_customView setTitleColor:textColor forState:state];
        }
    }
    if ([_customView respondsToSelector:@selector(setTitleTextAttributes:forState:)]) {
        [_customView setTitleTextAttributes:attributes forState:state];
    }
}

- (void)setTintColor:(UIColor*)tintColor {
    [super setTintColor:tintColor];

    [_buttonView setTintColor:tintColor];
    if ([_customView respondsToSelector:@selector(setTintColor:)]) {
        [_customView setTintColor:tintColor];
    }
}

- (UIColor*)tintColor {
    return [super tintColor];
}

- (void)setEnabled:(BOOL)enabled {
    bool update = false;

    if (!enabled) {
        if (!_isDisabled) {
            _isDisabled = true;
            update = true;
        }
    } else {
        if (_isDisabled) {
            _isDisabled = false;
            update = true;
        }
    }

    if (update) {
        id view = [self _getView];
        [[view superview] setNeedsLayout];
        if ([view respondsToSelector:@selector(setEnabled:)]) {
            [view setEnabled:_isDisabled == false];
        }
    }
}

- (BOOL)isEnabled {
    if (_isDisabled) {
        return FALSE;
    } else {
        return TRUE;
    }
}

- (void)_sendAction:(id)event {
    if (_isDisabled) {
        EbrDebugLog("Bar item is disabled\n");
        return;
    }
    if (_targetSel == NULL) {
        EbrDebugLog("No selector on Bar item\n");
        return;
    }

    EbrDebugLog("sending message %s to %x\n", _targetSel ? _targetSel : "(null)", _target);
    if (_target != nil && _targetSel != NULL) {
        [_target performSelector:_targetSel withObject:self withObject:event];
    } else {
        id nextResponder = [self nextResponder];

        while (nextResponder != nil) {
            if ([nextResponder respondsToSelector:_targetSel]) {
                _m(nextResponder, _targetSel, self, event);
                break;
            }

            EbrDebugLog("Next responder is %s\n", object_getClassName(nextResponder));
            nextResponder = [nextResponder nextResponder];
        }
    }
}

- (void)setImageInsets:(UIEdgeInsets)insets {
}

- (void)setAccessibilityLabel:(NSString*)label {
}

- (UIView*)_getView {
    if (_customView != nil) {
        return _customView;
    } else {
        return _buttonView;
    }
}

- (void)setTag:(NSInteger)tag {
    _tag = tag;
}

- (NSInteger)tag {
    return _tag;
}

- (void)dealloc {
    _title = nil;
    _font = nil;
    _image = nil;
    _customView = nil;
    _buttonView = nil;

    [super dealloc];
}

- (BOOL)isFlexibleWidth {
    if (_systemItem == UIBarButtonSystemItemFlexibleSpace) {
        return TRUE;
    } else {
        return FALSE;
    }
}

+ (id)appearance {
    return [UIAppearanceSetter appearanceWhenContainedIn:nil forUIClass:self];
}

+ (id)appearanceWhenContainedIn:(id)containedClass, ... {
    id curClass = [self class];

    va_list pReader;
    va_start(pReader, containedClass);

    id curVal = va_arg(pReader, id);

    while (curVal != nil) {
        assert(0);
        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return [UIAppearanceSetter appearanceWhenContainedIn:containedClass forUIClass:self];
}

@end
