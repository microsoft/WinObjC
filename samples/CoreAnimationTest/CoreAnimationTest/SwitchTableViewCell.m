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

#import "SwitchTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface SwitchTableViewCell ()

@property UISwitch* switchControl;

@end

@implementation SwitchTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.switchControl = [UISwitch new];
        self.switchControl.tintColor = [UIColor lightGrayColor];
        self.switchControl.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:self.switchControl];

        NSDictionary* views = @{ @"titleLabel" : self.titleLabel, @"switchControl" : self.switchControl };
        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-pad-[switchControl]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self.switchControl.centerYAnchor constraintEqualToAnchor:self.centerYAnchor].active = YES;
    }

    return self;
}

- (void)setUpWithText:(NSString*)title value:(BOOL)value target:(id)target action:(SEL)action {
    self.titleLabel.text = title;
    self.switchControl.on = value;
    [self.switchControl addTarget:target action:action forControlEvents:UIControlEventValueChanged];
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.switchControl.enabled = !disabled;
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self.switchControl removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
}

@end
