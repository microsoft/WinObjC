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
#include "UIKit/UILabel.h"
#include "UIKit/UITableViewHeaderFooterView.h"

@implementation UITableViewHeaderFooterView {
@public
    idretaintype(UIView) _backgroundView, _contentView;
    idretaintype(UILabel) _textLabel;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithReuseIdentifier:(NSString*)identifier {
    CGRect pos;

    pos.origin.x = 0.0f;
    pos.origin.y = 0.0f;
    pos.size.width = 0;
    pos.size.height = 0;
    return [self initWithFrame:pos];
}

/**
 @Status Interoperable
*/
- (UIView*)backgroundView {
    return _backgroundView;
}

/**
 @Status Interoperable
*/
- (void)setBackgroundView:(UIView*)backgroundView {
    if (_backgroundView != backgroundView) {
        [_backgroundView removeFromSuperview];
        _backgroundView = backgroundView;

        if (_backgroundView != nil) {
            [self addSubview:_backgroundView];
            [self sendSubviewToBack:_backgroundView];
            CGRect bounds;
            bounds = [self bounds];
            [_backgroundView setFrame:bounds];
            [_backgroundView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
        }
    }
}

/**
 @Status Stub
*/
- (UIView*)contentView {
    UNIMPLEMENTED();
    return _contentView;
}

- (void)setContentView:(UIView*)contentView {
    _contentView = contentView;
}

/**
 @Status Interoperable
*/
- (UILabel*)textLabel {
    if (_textLabel == nil) {
        CGRect bounds;
        bounds = [self bounds];
        bounds.origin.x = 10;
        bounds.origin.y = 0;

        _textLabel.attach([[UILabel alloc] initWithFrame:bounds]);
        [_textLabel setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
        [self addSubview:(id)_textLabel];
    }
    return _textLabel;
}

- (void)dealloc {
    _textLabel = nil;
    _backgroundView = nil;
    _contentView = nil;
    [super dealloc];
}

@end
