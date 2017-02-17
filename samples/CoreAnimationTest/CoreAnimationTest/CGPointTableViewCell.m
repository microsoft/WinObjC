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

#import "CGPointTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface CGPointTableViewCell ()

@property UITextField* textFieldX;
@property UITextField* textFieldY;

@property UILabel* labelX;
@property UILabel* labelY;

@end

@implementation CGPointTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.textFieldX = [UITextField new];
        self.textFieldX.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldX.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelX = [UILabel new];
        self.labelX.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelX.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelX.textColor = [UIColor lightGrayColor];
        self.labelX.textAlignment = NSTextAlignmentRight;
        self.labelX.text = @"X:";

        self.textFieldY = [UITextField new];
        self.textFieldY.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldY.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelY = [UILabel new];
        self.labelY.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelY.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelY.textColor = [UIColor lightGrayColor];
        self.labelY.textAlignment = NSTextAlignmentRight;
        self.labelY.text = @"Y:";

        [self addSubview:self.textFieldX];
        [self addSubview:self.textFieldY];
        [self addSubview:self.labelX];
        [self addSubview:self.labelY];

#ifdef WINOBJC
        // Override the use of autolayout using its visual language for this cell
        [self.titleLabel setFrame:CGRectMake(20.0f, 30.0f, 100.0f, 16.0f)];
        [self.labelX setFrame:CGRectMake(150.0f, 16.0f, 50.0f, 16.0f)];
        [self.labelY setFrame:CGRectMake(150.0f, 48.0f, 50.0f, 16.0f)];
        [self.textFieldX setFrame:CGRectMake(210.0f, 16.0f, 100.0f, 20.0f)];
        [self.textFieldY setFrame:CGRectMake(210.0f, 48.0f, 100.0f, 20.0f)];
#else
        NSDictionary* views = @{
            @"titleLabel" : self.titleLabel,
            @"textFieldX" : self.textFieldX,
            @"textFieldY" : self.textFieldY,
            @"labelX" : self.labelX,
            @"labelY" : self.labelY
        };
        NSDictionary* metrics = @{ @"pad" : @(kPadding), @"w" : @(kPadding * 3.0), @"h" : @(kPadding * 1.5) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-(>=pad)-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=pad)-[labelX(48)]-[textFieldX(100)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=pad)-[labelY(48)]-[textFieldY(100)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[labelX(20)]-(>=pad)-[labelY(20)]-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[textFieldX(20)]-(>=pad)-[textFieldY(20)]-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];

        [self.textFieldX.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;
        [self.labelX.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;
        [self.textFieldY.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
        [self.labelY.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
#endif
    }

    return self;
}

- (void)setUpWithText:(NSString*)title currentValue:(CGPoint)value target:(id)target actionX:(SEL)actionX actionY:(SEL)actionY {
    self.titleLabel.text = title;

    self.textFieldX.text = [NSString stringWithFormat:@"%.3f", value.x];
    self.textFieldY.text = [NSString stringWithFormat:@"%.3f", value.y];

    [self.textFieldX addTarget:target action:actionX forControlEvents:UIControlEventEditingChanged];
    [self.textFieldY addTarget:target action:actionY forControlEvents:UIControlEventEditingChanged];
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.textFieldX.enabled = !disabled;
    self.textFieldY.enabled = !disabled;
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self.textFieldX removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [self.textFieldY removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
}

@end
