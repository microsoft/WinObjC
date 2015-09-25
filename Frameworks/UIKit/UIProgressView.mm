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
#include "UIKit/UIKit.h"
#include "CoreGraphics/CoreGraphics.h"
#include "UIKit/UIColor.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIImageView.h"

@implementation UIProgressView {
    float _value;
    UIImageView *_progressBackground, *_progressForeground;
    idretaintype(UIImage) _trackImage;
}

static void sizeViews(UIProgressView* self, bool animated) {
    CGRect bounds;
    bounds = [self bounds];

    if (animated) {
        [UIView beginAnimations:@"MoveView" context:nil];
        [UIView setAnimationDuration:0.25f];
        [UIView setAnimationDelegate:nil];
    }

    CGRect newFrame;
    newFrame.origin.x = 0;
    newFrame.origin.y = 0;
    newFrame.size.width = bounds.size.width;
    newFrame.size.height = 8;
    [self->_progressBackground setFrame:newFrame];

    newFrame.size.width = bounds.size.width * self->_value;
    if (newFrame.size.width > bounds.size.width) {
        newFrame.size.width = bounds.size.width;
    }
    if (newFrame.size.width < 8) {
        newFrame.size.width = 8;
    }

    [self->_progressForeground setFrame:newFrame];

    if (animated) {
        [UIView commitAnimations];
    }
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    CGRect frame;
    frame = [self frame];

    UIImage* background =
        [[UIImage imageNamed:@"/img/progress-background@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];
    UIImage* foreground =
        [[UIImage imageNamed:@"/img/progress-foreground@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];

    CGRect progressFrame;

    progressFrame.origin.x = 0;
    progressFrame.origin.y = 0;
    progressFrame.size.width = frame.size.width;
    progressFrame.size.height = 8;

    _progressBackground = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [_progressBackground setImage:background];

    progressFrame.size.width = 8;
    _progressForeground = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [_progressForeground setImage:foreground];

    [self addSubview:_progressBackground];
    [self addSubview:_progressForeground];

    sizeViews(self, false);

    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    [self setOpaque:FALSE];
    [self setUserInteractionEnabled:FALSE];

    UIImage* background =
        [[UIImage imageNamed:@"/img/progress-background@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];
    UIImage* foreground =
        [[UIImage imageNamed:@"/img/progress-foreground@2x.png"] stretchableImageWithLeftCapWidth:5 topCapHeight:0];

    CGRect progressFrame;

    progressFrame.origin.x = 0;
    progressFrame.origin.y = 0;
    progressFrame.size.width = frame.size.width;
    progressFrame.size.height = 8;

    _progressBackground = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [_progressBackground setImage:background];

    progressFrame.size.width = 8;
    _progressForeground = [[[UIImageView alloc] initWithFrame:progressFrame] autorelease];
    [_progressForeground setImage:foreground];

    [self addSubview:_progressBackground];
    [self addSubview:_progressForeground];

    sizeViews(self, false);

    return self;
}

- (instancetype)initWithProgressViewStyle:(UIProgressViewStyle)style {
    [self init];

    return self;
}

- (void)setProgressViewStyle:(UIProgressViewStyle)style {
}

- (void)setProgress:(float)progress {
    _value = progress;
    sizeViews(self, false);
}

- (void)setProgress:(float)progress animated:(BOOL)animated {
    _value = progress;
    sizeViews(self, animated);
}

- (void)setProgressImage:(UIImage*)image {
}

- (void)setProgressTintColor:(UIColor*)color {
}

- (void)setTrackTintColor:(UIColor*)color {
}

- (void)setTrackImage:(UIImage*)image {
    _trackImage = image;
}

- (UIImage*)trackImage {
    return _trackImage;
}

- (float)progress {
    return _value;
}

- (void)layoutSubviews {
    sizeViews(self, false);
}

- (void)dealloc {
    _trackImage = nil;

    [super dealloc];
}
@end
