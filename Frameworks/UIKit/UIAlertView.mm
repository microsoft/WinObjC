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
#include "UIKit/UIView.h"
#include "UIKit/UIControl.h"
#include "UIKit/UIAlertView.h"
#include "UIKit/UIApplication.h"
#include "UIKit/UIColor.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "CoreGraphics/CGAffineTransform.h"
#include "CoreFoundation/CFType.h"
#include "UIKit/UIImage.h"

typedef struct {
    idretain _buttonText;
    idretain _buttonView;
} ActionButton;

struct UIAlertViewPriv {
    UIAlertViewPriv() {
        memset(this, 0, sizeof(UIAlertViewPriv));
    }

    id _delegate;
    idretaintype(NSString) _title;
    idretaintype(UILabel) _titleLabel;
    idretaintype(NSString) _message;
    idretaintype(UILabel) _messageLabel;
    idretain _cancelText;
    idretaintype(UIButton) _cancelView;
    id _darkView;

    int _hideIndex;

    ActionButton _buttons[16];
    int _numButtons;

    int _numberOfRows;

    float _totalHeight;
    int _otherButtonIndex, _cancelButtonIndex;
    bool _isVisible;

    UIAlertViewStyle _style;

    BOOL _delegateSupportsDidDismiss, _delegateSupportsModalDismiss, _delegateSupportsModalCancel;
};

@implementation UIAlertView {
    struct UIAlertViewPriv* alertPriv;
}
+ (id)allocWithZone:(NSZone*)zone {
    UIAlertView* ret = [super allocWithZone:zone];
    ret->alertPriv = new UIAlertViewPriv();

    return ret;
}

static int addButton(UIAlertViewPriv* alertPriv, id text) {
    alertPriv->_buttons[alertPriv->_numButtons]._buttonText.attach([text copy]);

    return alertPriv->_numButtons++;
}

- (id)initWithTitle:(NSString*)title
            message:(NSString*)message
           delegate:(id)delegate
  cancelButtonTitle:(NSString*)cancelButtonTitle
  otherButtonTitles:(NSString*)otherButtonTitles, ... {
    va_list pReader;
    va_start(pReader, otherButtonTitles);
    [self setDelegate:delegate];
    if (title != nil)
        alertPriv->_title.attach([title copy]);
    if (message != nil)
        alertPriv->_message.attach([message copy]);

    alertPriv->_cancelButtonIndex = -1;
    if (cancelButtonTitle != nil) {
        alertPriv->_cancelText.attach([cancelButtonTitle copy]);
        alertPriv->_cancelButtonIndex = 0;
    }

    alertPriv->_otherButtonIndex = -1;

    id otherButtonTitle = otherButtonTitles; // va_arg(pReader, id);
    while (otherButtonTitle != nil) {
        int idx = addButton(alertPriv, otherButtonTitle);
        if (alertPriv->_otherButtonIndex == -1) {
            if (cancelButtonTitle != nil) {
                alertPriv->_otherButtonIndex = 1;
            } else {
                alertPriv->_otherButtonIndex = 0;
            }
        }

        otherButtonTitle = va_arg(pReader, id);
    }
    va_end(pReader);

    return self;
}

- (id)initWithTitle:(id)title
            message:(id)message
           delegate:(id)delegate
      defaultButton:(id)defaultButton
       cancelButton:(id)cancelButton
       otherButtons:(id)otherButtons {
    [self setDelegate:delegate];
    if (title != nil)
        alertPriv->_title.attach([title copy]);
    if (message != nil)
        alertPriv->_message.attach([message copy]);

    alertPriv->_cancelButtonIndex = -1;
    if (cancelButton != nil) {
        alertPriv->_cancelText.attach([cancelButton copy]);
        alertPriv->_cancelButtonIndex = 0;
    }

    alertPriv->_otherButtonIndex = -1;

    if (defaultButton != nil) {
        int idx = addButton(alertPriv, defaultButton);
        if (alertPriv->_otherButtonIndex == -1) {
            alertPriv->_otherButtonIndex = idx;
        }
    }

    otherButtons = [otherButtons componentsSeparatedByString:@";"];
    int count = [otherButtons count];

    for (int i = 0; i < count; i++) {
        id otherButton = [otherButtons objectAtIndex:i];
        int idx = addButton(alertPriv, otherButton);
        if (alertPriv->_otherButtonIndex == -1) {
            alertPriv->_otherButtonIndex = idx;
        }
    }

    return self;
}

- (id) /* use typed version */ init {
    alertPriv->_otherButtonIndex = -1;
    alertPriv->_cancelButtonIndex = -1;

    return self;
}

- (void)setDelegate:(id)delegate {
    objc_storeWeak(&alertPriv->_delegate, delegate);
    alertPriv->_delegateSupportsDidDismiss =
        [alertPriv->_delegate respondsToSelector:@selector(alertView:didDismissWithButtonIndex:)];
    alertPriv->_delegateSupportsModalDismiss =
        [alertPriv->_delegate respondsToSelector:@selector(modalView:didDismissWithButtonIndex:)];
    alertPriv->_delegateSupportsModalCancel = [alertPriv->_delegate respondsToSelector:@selector(modalViewCancel:)];
}

- (id)delegate {
    id ret;

    ret = objc_loadWeak(&alertPriv->_delegate);
    return ret;
}

- (void)setTitle:(id)title {
    alertPriv->_title.attach([title copy]);
}

- (id) /* use typed version */ title {
    return alertPriv->_title;
}

- (void)setAlertViewStyle:(UIAlertViewStyle)style {
    alertPriv->_style = style;
}

- (UIAlertViewStyle)alertViewStyle {
    return alertPriv->_style;
}

- (void)setMessage:(id)message {
    alertPriv->_message.attach([message copy]);
}

- (int)addButtonWithTitle:(id)title {
    if (alertPriv->_otherButtonIndex == -1) {
        if (alertPriv->_cancelText != nil) {
            alertPriv->_otherButtonIndex = 1;
        } else {
            alertPriv->_otherButtonIndex = 0;
        }
    }
    int idx = addButton(alertPriv, title);

    return alertPriv->_otherButtonIndex + idx;
}

- (id)setNumberOfRows:(DWORD)numRows {
    alertPriv->_numberOfRows = numRows;

    return self;
}

- (int)cancelButtonIndex {
    return alertPriv->_cancelButtonIndex;
}

- (int)firstOtherButtonIndex {
    return alertPriv->_otherButtonIndex;
}

- (void)setCancelButtonIndex:(int)index {
    alertPriv->_cancelButtonIndex = index;
}

static id createButton(UIAlertView* self, int index, id text, float x, float y, float width) {
    CGRect frame;

    frame.origin.x = x;
    frame.origin.y = y;
    frame.size.width = width;
    frame.size.height = 30.0f;

    id buttonBackground =
        [[UIImage imageNamed:@"/img/blackbutton-pressed@2x.png"] stretchableImageWithLeftCapWidth:9 topCapHeight:0];
    id buttonPressed =
        [[UIImage imageNamed:@"/img/blackbutton-normal@2x.png"] stretchableImageWithLeftCapWidth:9 topCapHeight:0];

    id ret = [[UIButton alloc] initWithFrame:frame];
    [ret setTitle:text forState:0];
    [ret setTitleColor:[UIColor whiteColor] forState:0];
    [ret setBackgroundImage:buttonBackground forState:0];
    [ret setBackgroundImage:buttonPressed forState:1];
    [ret setTag:index];
    [ret addTarget:self action:@selector(buttonClicked:) forControlEvents:UIControlEventTouchUpInside];
    [ret setAlpha:0.9f];

    return ret;
}

- (id)_didHideAlert {
    [alertPriv->_darkView removeFromSuperview];
    alertPriv->_darkView = nil;
    [self removeFromSuperview];
    alertPriv->_isVisible = false;

    id weakDelegate = objc_loadWeak(&alertPriv->_delegate);
    if (alertPriv->_delegateSupportsDidDismiss) {
        [weakDelegate alertView:self didDismissWithButtonIndex:alertPriv->_hideIndex];
    }
    if (alertPriv->_delegateSupportsModalDismiss) {
        if (alertPriv->_hideIndex != alertPriv->_cancelButtonIndex) {
            [weakDelegate modalView:self didDismissWithButtonIndex:alertPriv->_hideIndex];
        }
    }
    if (alertPriv->_delegateSupportsModalCancel) {
        if (alertPriv->_hideIndex == alertPriv->_cancelButtonIndex) {
            [weakDelegate modalViewCancel:self];
        }
    }
    return self;
}

static void hideAlert(UIAlertView* self, int index, BOOL animated) {
    if (animated) {
        self->alertPriv->_hideIndex = index;
        [UIView beginAnimations:@"HideAlert" context:nil];
        [UIView setAnimationDuration:0.25f];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(_didHideAlert)];
        [self->alertPriv->_darkView setAlpha:0.0f];
        [self setAlpha:0.0f];
        [UIView commitAnimations];
    } else {
        [self->alertPriv->_darkView removeFromSuperview];
        self->alertPriv->_darkView = nil;
        [self removeFromSuperview];
        self->alertPriv->_isVisible = false;

        id weakDelegate = objc_loadWeak(&self->alertPriv->_delegate);
        if ([weakDelegate respondsToSelector:@selector(alertView:didDismissWithButtonIndex:)]) {
            [weakDelegate alertView:self didDismissWithButtonIndex:index];
        }
        if (self->alertPriv->_delegateSupportsModalDismiss) {
            if (index != self->alertPriv->_cancelButtonIndex) {
                [weakDelegate modalView:self didDismissWithButtonIndex:index];
            }
        }
        if (self->alertPriv->_delegateSupportsModalCancel) {
            if (index == self->alertPriv->_cancelButtonIndex) {
                [weakDelegate modalViewCancel:self];
            }
        }
    }
}

- (void)dismissWithClickedButtonIndex:(int)index animated:(BOOL)animated {
    [self retain];
    [self autorelease];

    id weakDelegate = objc_loadWeak(&alertPriv->_delegate);

    if ([weakDelegate respondsToSelector:@selector(alertView:willDismissWithButtonIndex:)]) {
        [weakDelegate alertView:self willDismissWithButtonIndex:index];
    }

    hideAlert(self, index, animated);
}

- (void)buttonClicked:(id)button {
    int index = [button tag];

    [self retain];
    [self autorelease];

    id weakDelegate = objc_loadWeak(&alertPriv->_delegate);

    if ([weakDelegate respondsToSelector:@selector(alertView:clickedButtonAtIndex:)]) {
        [weakDelegate alertView:self clickedButtonAtIndex:index];
    }

    if ([weakDelegate respondsToSelector:@selector(alertView:willDismissWithButtonIndex:)]) {
        [weakDelegate alertView:self willDismissWithButtonIndex:index];
    }

    hideAlert(self, index, TRUE);
}

- (BOOL)isVisible {
    return alertPriv->_isVisible;
}

- (void) /* use typed version */ show {
    float boxWidth = 300.0f;
    id titleFont = [UIFont titleFont];
    id messageFont = [UIFont messageFont];
    id whiteColor = [UIColor whiteColor];

    if (GetCACompositor()->isTablet()) {
        CGRect screenRect;
        screenRect = [[UIScreen mainScreen] bounds];
        boxWidth = screenRect.size.width * 0.9f;
    }

    float itemWidth = boxWidth - 20.0f;
    float curHeight = 10.0f;

    //  Measure the title and message sizes
    CGSize titleSize = { 0.0f, 0.0f }, messageSize = { 0.0f, 0.0f };
    if (alertPriv->_title != nil) {
        titleSize = [alertPriv->_title sizeWithFont:titleFont
                                  constrainedToSize:CGSizeMake(itemWidth, 480.0f)
                                      lineBreakMode:UILineBreakModeWordWrap];

        CGRect frame;

        frame.origin.x = 10.0f;
        frame.origin.y = curHeight;
        frame.size.width = itemWidth;
        frame.size.height = titleSize.height;

        alertPriv->_titleLabel.attach([[UILabel alloc] initWithFrame:frame]);
        [alertPriv->_titleLabel setText:(id)alertPriv->_title];
        [alertPriv->_titleLabel setFont:titleFont];
        [alertPriv->_titleLabel setTextAlignment:UITextAlignmentCenter];
        [alertPriv->_titleLabel setTextColor:whiteColor];
        [alertPriv->_titleLabel setBackgroundColor:nil];
        [alertPriv->_titleLabel setNumberOfLines:0];

        curHeight += titleSize.height;
        curHeight += 10.0f;
    }

    id popupWindow = [[UIApplication sharedApplication] _popupLayer];
    [[popupWindow superview] bringSubviewToFront:popupWindow];

    CGRect fullScreen;
    fullScreen = [popupWindow bounds];

    if (alertPriv->_message != nil) {
        float maxHeight = fullScreen.size.height - curHeight - 30.0f;
        if (alertPriv->_cancelText != nil && alertPriv->_numButtons == 1 && alertPriv->_numberOfRows < 2) {
            maxHeight -= 40.0f;
        } else {
            maxHeight -= alertPriv->_numButtons * 40.0f;

            if (alertPriv->_cancelText != nil) {
                maxHeight -= 10.0f;
                maxHeight -= 40.0f;
            }
        }

        for (;;) {
            messageSize = [alertPriv->_message sizeWithFont:messageFont
                                          constrainedToSize:CGSizeMake(itemWidth, 480.0f)
                                              lineBreakMode:UILineBreakModeWordWrap];
            if (messageSize.height < maxHeight)
                break;

            float curSize = [messageFont pointSize];
            curSize -= 0.5f;
            messageFont = [messageFont fontWithSize:curSize];
            if (curSize <= 1.0f)
                break;
        }

        if (messageSize.height > maxHeight)
            messageSize.height = maxHeight;

        CGRect frame;

        frame.origin.x = 10.0f;
        frame.origin.y = curHeight;
        frame.size.width = itemWidth;
        frame.size.height = messageSize.height;

        alertPriv->_messageLabel.attach([[UILabel alloc] initWithFrame:frame]);
        [alertPriv->_messageLabel setText:(id)alertPriv->_message];
        [alertPriv->_messageLabel setFont:messageFont];
        [alertPriv->_messageLabel setTextAlignment:UITextAlignmentCenter];
        [alertPriv->_messageLabel setLineBreakMode:UILineBreakModeWordWrap];
        [alertPriv->_messageLabel setNumberOfLines:0];
        [alertPriv->_messageLabel setTextColor:whiteColor];
        [alertPriv->_messageLabel setBackgroundColor:nil];

        curHeight += messageSize.height;
        curHeight += 10.0f;
    }

    if (alertPriv->_cancelText != nil && alertPriv->_numButtons == 1 && alertPriv->_numberOfRows < 2) {
        float buttonsWidth = 270.0f;
        //  Make side by side buttons
        alertPriv->_cancelView = (createButton(self,
                                               alertPriv->_cancelButtonIndex,
                                               alertPriv->_cancelText,
                                               boxWidth / 2.0f - buttonsWidth / 2.0f,
                                               curHeight,
                                               130.0f));
        [alertPriv->_cancelView sendControlEventsOnBack:UIControlEventTouchUpInside];

        for (int i = 0; i < alertPriv->_numButtons; i++) {
            alertPriv->_buttons[i]._buttonView.attach(createButton(self,
                                                                   i + alertPriv->_otherButtonIndex,
                                                                   alertPriv->_buttons[i]._buttonText,
                                                                   boxWidth / 2.0f - buttonsWidth / 2.0f + 140.0f,
                                                                   curHeight,
                                                                   130.0f));
        }

        curHeight += 40.0f;
    } else {
        //  Make top-down buttons
        for (int i = 0; i < alertPriv->_numButtons; i++) {
            alertPriv->_buttons[i]._buttonView.attach(createButton(self,
                                                                   i + alertPriv->_otherButtonIndex,
                                                                   alertPriv->_buttons[i]._buttonText,
                                                                   boxWidth / 2.0f - 280.0f / 2.0f,
                                                                   curHeight,
                                                                   280.0f));
            curHeight += 40.0f;
        }

        if (alertPriv->_cancelText != nil) {
            curHeight += 10.0f;
            alertPriv->_cancelView = (createButton(self,
                                                   alertPriv->_cancelButtonIndex,
                                                   alertPriv->_cancelText,
                                                   boxWidth / 2.0f - 280.0f / 2.0f,
                                                   curHeight,
                                                   280.0f));
            [alertPriv->_cancelView sendControlEventsOnBack:UIControlEventTouchUpInside];

            curHeight += 40.0f;
        } else if (alertPriv->_numButtons == 1) {
            [alertPriv->_buttons[0]._buttonView sendControlEventsOnBack:UIControlEventTouchUpInside];
        }
    }

    curHeight += 5.0f;

    CGRect frame;
    frame.origin.x = fullScreen.size.width / 2.0f - boxWidth / 2.0f;
    frame.origin.y = fullScreen.size.height / 2.0f - curHeight / 2.0f + fullScreen.origin.x;
    frame.size.width = boxWidth;
    frame.size.height = curHeight;
    [self initWithFrame:frame];

    id image;
    image = [[UIImage imageNamed:@"/img/alert-background@2x.png"] stretchableImageWithLeftCapWidth:25 topCapHeight:30];
    UIImageSetLayerContents([self layer], image);

    if (alertPriv->_messageLabel)
        [self addSubview:(id)alertPriv->_messageLabel];
    if (alertPriv->_titleLabel)
        [self addSubview:(id)alertPriv->_titleLabel];

    if (alertPriv->_cancelView)
        [self addSubview:(id)alertPriv->_cancelView];
    for (int i = 0; i < alertPriv->_numButtons; i++) {
        [self addSubview:(id)alertPriv->_buttons[i]._buttonView];
    }

    if ([alertPriv->_delegate respondsToSelector:@selector(willPresentAlertView:)]) {
        [alertPriv->_delegate willPresentAlertView:self];
    }

    alertPriv->_darkView = [[UIView alloc] initWithFrame:fullScreen];
    [self setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    [alertPriv->_darkView setBackgroundColor:[UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.5f]];
    [alertPriv->_darkView setAlpha:0.0f];
    [alertPriv->_darkView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [self setAutoresizingMask:UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin |
                              UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleTopMargin];
    [self setAlpha:0.0f];
    [popupWindow addSubview:alertPriv->_darkView];
    [popupWindow addSubview:self];

    [UIView beginAnimations:@"ShowAlert" context:nil];
    [UIView setAnimationDuration:0.25f];
    [alertPriv->_darkView setAlpha:1.0f];
    [self setAlpha:1.0f];
    [UIView commitAnimations];
    alertPriv->_isVisible = true;

    if ([alertPriv->_delegate respondsToSelector:@selector(didPresentAlertView:)]) {
        [alertPriv->_delegate didPresentAlertView:self];
    }
}

- (void)dealloc {
    for (int i = 0; i < alertPriv->_numButtons; i++) {
        alertPriv->_buttons[i]._buttonView = nil;
        alertPriv->_buttons[i]._buttonText = nil;
    }
    alertPriv->_title = nil;
    alertPriv->_titleLabel = nil;
    alertPriv->_message = nil;
    alertPriv->_messageLabel = nil;
    alertPriv->_cancelText = nil;
    alertPriv->_cancelView = nil;

    delete alertPriv;

    [super dealloc];
}

- (id)buttonTitleAtIndex:(int)index {
    if (index == alertPriv->_cancelButtonIndex)
        return alertPriv->_cancelText;

    int idx = index - alertPriv->_otherButtonIndex;
    assert(idx >= 0 && idx < alertPriv->_numButtons);

    return [alertPriv->_buttons[idx]._buttonView currentTitle];
}

- (id)textFieldAtIndex:(int)index {
    // TODO: should return a UITextField.
    return nil;
}

@end
