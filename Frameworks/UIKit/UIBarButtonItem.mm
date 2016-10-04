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
#import "UIBarItemInternal.h"
#import "UIBarButtonItem+Internals.h"
#import "UIAppearanceSetter.h"
#import "LoggingNative.h"
#import "StubReturn.h"

static const wchar_t* TAG = L"UIBarButtonItem";

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
    self->_font = [UIFont systemFontOfSize:15];
    self->_systemItem = (UIBarButtonSystemItem)-1;
}

static void initControls(UIBarButtonItem* self) {
    if (self->_systemItem != UIBarButtonSystemItemFlexibleSpace && self->_systemItem != UIBarButtonSystemItemFixedSpace &&
        self->_customView == nil) {
        CGRect frame = { 0, 0, 0, 0 };

        self->_buttonView.attach([[UIButton alloc] initWithFrame:frame]);
        [self->_buttonView setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];

        [self->_buttonView setTitle:(id)self->_title forState:UIControlStateNormal];
        [self->_buttonView setImage:(id)self->_image forState:UIControlStateNormal];
        [self->_buttonView setFont:(id)self->_font];
        [self->_buttonView addTarget:self action:@selector(_sendAction:) forControlEvents:UIControlEventTouchUpInside];
        [[self->_buttonView titleLabel] setLineBreakMode:UILineBreakModeMiddleTruncation];
    }
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
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

/**
 @Status Stub
*/
- (UIImage*)backgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Limited system item support
*/
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

        case UIBarButtonSystemItemUndo:
            _title = @"Undo";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemRedo:
            _title = @"Redo";
            {
                CGSize size;
                size = [_title sizeWithFont:(id)_font];
                _width = size.width + 15.0f;
            }
            break;

        case UIBarButtonSystemItemPageCurl:
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

/**
 @Status Interoperable
*/
- (instancetype)initWithCustomView:(UIView*)view {
    initInternal(self);

    _customView = view;
    initControls(self);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTitle:(NSString*)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)targetSel {
    _style = style;
    initInternal(self);
    _title.attach([title copy]);
    _target = target;
    _targetSel = targetSel;
    initControls(self);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithImage:(UIImage*)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)targetSel {
    initInternal(self);

    _target = target;
    _targetSel = targetSel;
    _image = image;
    _style = style;
    initControls(self);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    initInternal(self);
    initControls(self);

    return self;
}

/**
 @Status Interoperable
*/
- (void)setStyle:(UIBarButtonItemStyle)style {
    _style = style;
}

/**
 @Status Interoperable
*/
- (UIBarButtonItemStyle)style {
    return _style;
}

/**
 @Status Interoperable
*/
- (void)setWidth:(float)width {
    _width = width;
}

/**
 @Status Interoperable
*/
- (float)width {
    return _width;
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)title {
    _title.attach([title copy]);
    [_buttonView setTitle:(id)_title forState:UIControlStateNormal];
}

/**
 @Status Interoperable
*/
- (NSString*)title {
    return _title;
}

/**
 @Status Interoperable
*/
- (SEL)action {
    return _targetSel;
}

/**
 @Status Interoperable
*/
- (UIView*)customView {
    return _customView;
}

/**
 @Status Interoperable
*/
- (void)setCustomView:(UIView*)view {
    _customView = view;
}

/**
 @Status Interoperable
*/
- (void)setTarget:(id)target {
    _target = target;
}

/**
 @Status Interoperable
*/
- (id)target {
    return _target;
}

/**
 @Status Interoperable
*/
- (void)setAction:(SEL)pSel {
    _targetSel = pSel;
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)image {
    _image = image;
    [_buttonView setImage:(id)_image forState:UIControlStateNormal];
}

/**
 @Status Interoperable
*/
- (UIImage*)image {
    return _image;
}

/**
 @Status Caveat
 @Notes barMetrics parameter not supported
*/
- (void)setBackgroundImage:(UIImage*)image forState:(UIControlState)state barMetrics:(UIBarMetrics)metrics {
    TraceVerbose(TAG, L"UIBarButtonItem setBackgroundImage not fully supported");
    [_buttonView setBackgroundImage:image forState:state];
}

/**
 @Status Stub
*/
- (void)setTitlePositionAdjustment:(CGPoint)position forBarMetrics:(UIBarMetrics)metrics {
    UNIMPLEMENTED_WITH_MSG("UIBarButtonItem setTitlePositionAdjustmentForBarMetrics not supported\n");
}

/**
 @Status Stub
*/
- (void)setBackButtonTitlePositionAdjustment:(UIOffset)position forBarMetrics:(UIBarMetrics)metrics {
    UNIMPLEMENTED();
    TraceVerbose(TAG, L"setBackButtonTitlePositionAdjustment not supported");
}

/**
 @Status Caveat
 @Notes barMetrics parameter not supported
*/
- (void)setBackButtonBackgroundImage:(UIImage*)image forState:(UIControlState)state barMetrics:(UIBarMetrics)metrics {
    TraceVerbose(TAG, L"UIBarButtonItem setBackButtonBackgroundImage not supported");
    _backImage = image;
}

/**
 @Status Interoperable
*/
- (void)setTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state {
    id font = [attributes objectForKey:@"kCTFontAttributeName"];
    id textColor = [attributes objectForKey:@"UITextAttributeTextColor"];

    if (font != nil) {
        [_buttonView setFont:font];
        if ([_customView respondsToSelector:@selector(setFont:)]) {
            [_customView performSelector:@selector(setFont) withObject:font];
        }
    }
    if (textColor != nil) {
        [_buttonView setTitleColor:textColor forState:state];
        if ([_customView respondsToSelector:@selector(setTitleColor:forState:)]) {
            [static_cast<UIButton*>(_customView) setTitleColor:textColor forState:state];
        }
    }
    if ([_customView respondsToSelector:@selector(setTitleTextAttributes:forState:)]) {
        [static_cast<UISegmentedControl*>(_customView) setTitleTextAttributes:attributes forState:state];
    }
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (void)setTintColor:(UIColor*)tintColor {
    [_buttonView setTintColor:tintColor];
    [_customView setTintColor:tintColor];
}

/**
 @Status Interoperable
*/
- (UIColor*)tintColor {
    return [[self _view] tintColor];
}

/**
 @Status Interoperable
*/
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
        id view = [self _view];
        [[view superview] setNeedsLayout];
        if ([view respondsToSelector:@selector(setEnabled:)]) {
            [view setEnabled:_isDisabled == false];
        }
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    if (_isDisabled) {
        return FALSE;
    } else {
        return TRUE;
    }
}

- (void)_sendAction:(id)event {
    if (_isDisabled) {
        TraceVerbose(TAG, L"Bar item is disabled");
        return;
    }
    if (_targetSel == NULL) {
        TraceVerbose(TAG, L"No selector on Bar item");
        return;
    }

    TraceVerbose(TAG, L"sending message %hs to %x", _targetSel ? sel_getName(_targetSel) : "(null)", _target);
    if (_target != nil && _targetSel != NULL) {
        [_target performSelector:_targetSel withObject:self withObject:event];
    } else {
        id nextResponder = [[self _view] nextResponder];

        while (nextResponder != nil) {
            if ([nextResponder respondsToSelector:_targetSel]) {
                [nextResponder performSelector:_targetSel withObject:self withObject:event];
                break;
            }

            TraceVerbose(TAG, L"Next responder is %hs", object_getClassName(nextResponder));
            nextResponder = [nextResponder nextResponder];
        }
    }
}

/**
 @Status Stub
*/
- (void)setImageInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setAccessibilityLabel:(NSString*)label {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setTag:(NSInteger)tag {
    _tag = tag;
}

/**
 @Status Interoperable
*/
- (NSInteger)tag {
    return _tag;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _title = nil;
    _font = nil;
    _image = nil;
    _customView = nil;
    _buttonView = nil;

    [super dealloc];
}

/**
 @Status Interoperable
*/
+ (instancetype)appearance {
    return [UIAppearanceSetter _appearanceWhenContainedIn:nil forUIClass:self];
}

/**
 @Status Interoperable
*/
+ (instancetype)appearanceWhenContainedIn:(Class<UIAppearanceContainer>)containedClass, ... {
    id curClass = [self class];

    va_list pReader;
    va_start(pReader, containedClass);

    id curVal = va_arg(pReader, id);

    while (curVal != nil) {
        assert(0);
        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return [UIAppearanceSetter _appearanceWhenContainedIn:containedClass forUIClass:self];
}

@end

@implementation UIBarButtonItem (Internals)

- (void)_addEventConnection:(UIRuntimeEventConnection*)connection {
    _target = [connection obj];
    _targetSel = (SEL)[connection sel];
}

// we need this shim because app are doing hack like following to get the view from UIBarButtonItem
// [barButtonItem valueForKey:@"view"];
- (UIView*)view {
    return [self _view];
}

- (UIView*)_view {
    if (_customView != nil) {
        return _customView;
    } else {
        return _buttonView;
    }
}

- (BOOL)_isFlexibleWidth {
    if (_systemItem == UIBarButtonSystemItemFlexibleSpace) {
        return TRUE;
    } else {
        return FALSE;
    }
}

- (float)margin {
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

- (CGSize)idealSize {
    CGSize sizeOut{ 0.0f, 34.0f };
    if (_width > 0.0f) {
        sizeOut.width = _width;
    } else {
        if (_customView == nil) {
            CGSize size = { 0, 0 };
            if (_title != nil) {
                size = [_title sizeWithFont:(id)_font];
                sizeOut.width = size.width + 16.0f;
            } else if (_image != nil) {
                float padding = _style == UIBarButtonItemStylePlain ? 0.0f : 15.0f;

                size = [_image size];
                sizeOut.width = size.width + padding;

                if (_style == UIBarButtonItemStylePlain) {
                    sizeOut.height = size.height;
                }
            } else {
                sizeOut.width = 0.0f;
            }
        } else {
            sizeOut = [_customView bounds].size;
        }
    }
    return sizeOut;
}

- (UIImage*)backButtonBackgroundImage {
    return _backImage;
}

@end
