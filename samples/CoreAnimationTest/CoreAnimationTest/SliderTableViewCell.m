//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "SliderTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface SliderTableViewCell ()

@property UISlider* slideControl;

@end

@implementation SliderTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.slideControl = [UISlider new];
        self.slideControl.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:self.slideControl];

        NSDictionary* views = @{ @"titleLabel" : self.titleLabel, @"slideControl" : self.slideControl };
        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-pad-[slideControl]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[slideControl]|" options:0 metrics:metrics views:views]];
    }

    return self;
}

- (void)setUpWithText:(NSString*)title
             minValue:(CGFloat)minValue
             maxValue:(CGFloat)maxValue
         currentValue:(CGFloat)currentValue
               target:(id)target
               action:(SEL)action {
    self.titleLabel.text = title;
    self.slideControl.minimumValue = minValue;
    self.slideControl.maximumValue = maxValue;
    self.slideControl.value = currentValue;
    [self.slideControl addTarget:target action:action forControlEvents:UIControlEventValueChanged];
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.slideControl.enabled = !disabled;
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self.slideControl removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
}

@end
