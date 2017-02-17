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

#import "CGRectTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface CGRectTableViewCell ()

@property UITextField* textFieldX;
@property UITextField* textFieldY;

@property UITextField* textFieldWidth;
@property UITextField* textFieldHeight;

@property UILabel* labelX;
@property UILabel* labelY;
@property UILabel* labelWidth;
@property UILabel* labelHeight;

@end

@implementation CGRectTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.textFieldX = [UITextField new];
        self.textFieldX.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldX.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelX = [UILabel new];
        self.labelX.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelX.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelX.textColor = [UIColor lightGrayColor];
        self.labelX.text = @"X:";

        self.textFieldY = [UITextField new];
        self.textFieldY.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldY.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelY = [UILabel new];
        self.labelY.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelY.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelY.textColor = [UIColor lightGrayColor];
        self.labelY.text = @"Y:";

        self.textFieldWidth = [UITextField new];
        self.textFieldWidth.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldWidth.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelWidth = [UILabel new];
        self.labelWidth.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelWidth.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelWidth.textColor = [UIColor lightGrayColor];
        self.labelWidth.text = @"W:";

        self.textFieldHeight = [UITextField new];
        self.textFieldHeight.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldHeight.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.labelHeight = [UILabel new];
        self.labelHeight.translatesAutoresizingMaskIntoConstraints = NO;
        self.labelHeight.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        self.labelHeight.textColor = [UIColor lightGrayColor];
        self.labelHeight.text = @"H:";

        [self addSubview:self.textFieldX];
        [self addSubview:self.textFieldY];
        [self addSubview:self.textFieldWidth];
        [self addSubview:self.textFieldHeight];

        [self addSubview:self.labelX];
        [self addSubview:self.labelY];
        [self addSubview:self.labelWidth];
        [self addSubview:self.labelHeight];

#ifdef WINOBJC
        // Override the use of autolayout using its visual language for this cell
        [self.titleLabel setFrame:CGRectMake(20.0f, 30.0f, 100.0f, 16.0f)];
        [self.labelX setFrame:CGRectMake(150.0f, 16.0f, 20.0f, 16.0f)];
        [self.labelY setFrame:CGRectMake(150.0f, 48.0f, 20.0f, 16.0f)];
        [self.textFieldX setFrame:CGRectMake(170.0f, 16.0f, 70.0f, 20.0f)];
        [self.textFieldY setFrame:CGRectMake(170.0f, 48.0f, 70.0f, 20.0f)];
        [self.labelWidth setFrame:CGRectMake(255.0f, 16.0f, 20.0f, 16.0f)];
        [self.labelHeight setFrame:CGRectMake(255.0f, 48.0f, 20.0f, 16.0f)];
        [self.textFieldWidth setFrame:CGRectMake(275.0f, 16.0f, 70.0f, 20.0f)];
        [self.textFieldHeight setFrame:CGRectMake(275.0f, 48.0f, 70.0f, 20.0f)];
#else
        NSDictionary* views = @{
            @"titleLabel" : self.titleLabel,
            @"textFieldX" : self.textFieldX,
            @"textFieldY" : self.textFieldY,
            @"textFieldWidth" : self.textFieldWidth,
            @"textFieldHeight" : self.textFieldHeight,
            @"labelX" : self.labelX,
            @"labelY" : self.labelY,
            @"labelWidth" : self.labelWidth,
            @"labelHeight" : self.labelHeight
        };
        NSDictionary* metrics = @{ @"pad" : @(kPadding), @"w" : @(kPadding * 3.0) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-(>=pad)-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint
                                 constraintsWithVisualFormat:@"H:|-(>=pad)-[labelX]-[textFieldX(w)]-[labelWidth]-[textFieldWidth(w)]-pad-|"
                                                     options:0
                                                     metrics:metrics
                                                       views:views]];
        [self
            addConstraints:[NSLayoutConstraint
                               constraintsWithVisualFormat:@"H:|-(>=pad)-[labelY]-[textFieldY(w)]-[labelHeight]-[textFieldHeight(w)]-pad-|"
                                                   options:0
                                                   metrics:metrics
                                                     views:views]];

        [self.textFieldX.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;
        [self.textFieldWidth.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;
        [self.labelX.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;
        [self.labelWidth.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding].active = YES;

        [self.textFieldY.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
        [self.textFieldHeight.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
        [self.labelY.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
        [self.labelHeight.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding].active = YES;
#endif
    }

    return self;
}

- (void)setUpWithText:(NSString*)title
         currentValue:(CGRect)value
               target:(id)target
              actionX:(SEL)actionX
              actionY:(SEL)actionY
          actionWidth:(SEL)actionWidth
         actionHeight:(SEL)actionHeight {
    self.titleLabel.text = title;

    self.textFieldX.text = [NSString stringWithFormat:@"%.3f", value.origin.x];
    self.textFieldY.text = [NSString stringWithFormat:@"%.3f", value.origin.y];

    self.textFieldWidth.text = [NSString stringWithFormat:@"%.3f", value.size.width];
    self.textFieldHeight.text = [NSString stringWithFormat:@"%.3f", value.size.height];

    [self.textFieldX addTarget:target action:actionX forControlEvents:UIControlEventEditingChanged];
    [self.textFieldY addTarget:target action:actionY forControlEvents:UIControlEventEditingChanged];
    [self.textFieldWidth addTarget:target action:actionWidth forControlEvents:UIControlEventEditingChanged];
    [self.textFieldHeight addTarget:target action:actionHeight forControlEvents:UIControlEventEditingChanged];
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.textFieldX.enabled = !disabled;
    self.textFieldY.enabled = !disabled;
    self.textFieldWidth.enabled = !disabled;
    self.textFieldHeight.enabled = !disabled;
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self.textFieldX removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [self.textFieldY removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [self.textFieldWidth removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
    [self.textFieldHeight removeTarget:nil action:NULL forControlEvents:UIControlEventAllEvents];
}

@end
