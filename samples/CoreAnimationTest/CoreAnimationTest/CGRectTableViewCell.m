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

@end

@implementation CGRectTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.textFieldX = [UITextField new];
        self.textFieldX.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldX.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.textFieldY = [UITextField new];
        self.textFieldY.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldY.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.textFieldWidth = [UITextField new];
        self.textFieldWidth.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldWidth.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        self.textFieldHeight = [UITextField new];
        self.textFieldHeight.translatesAutoresizingMaskIntoConstraints = NO;
        self.textFieldHeight.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];

        [self addSubview:self.textFieldX];
        [self addSubview:self.textFieldY];
        [self addSubview:self.textFieldWidth];
        [self addSubview:self.textFieldHeight];

        NSDictionary* views = @{
            @"titleLabel" : self.titleLabel,
            @"textFieldX" : self.textFieldX,
            @"textFieldY" : self.textFieldY,
            @"textFieldWidth" : self.textFieldWidth,
            @"textFieldHeight" : self.textFieldHeight
        };
        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-pad-[textFieldX]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[titleLabel]-pad-[textFieldY]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[titleLabel]-pad-[textFieldWidth]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[titleLabel]-pad-[textFieldHeight]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];

        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[textFieldX(25)]-(>=0)-[textFieldY(25)]-(>=0)-"
                                                                             @"[textFieldWidth(25)]-(>=0)-[textFieldHeight(25)]"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
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
