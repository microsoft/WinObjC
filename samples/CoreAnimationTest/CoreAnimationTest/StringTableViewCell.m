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

#import "StringTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface StringTableViewCell ()

@property UILabel* secondLabel;

@end

@implementation StringTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.secondLabel = [UILabel new];
        self.secondLabel.backgroundColor = [UIColor clearColor];
        self.secondLabel.translatesAutoresizingMaskIntoConstraints = NO;
        self.secondLabel.textColor = [UIColor lightGrayColor];
        self.secondLabel.font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
        [self addSubview:self.secondLabel];

        NSDictionary* views = @{ @"titleLabel" : self.titleLabel, @"secondLabel" : self.secondLabel };
        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-pad-[secondLabel]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[secondLabel]|" options:0 metrics:metrics views:views]];
    }

    return self;
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.secondLabel.textColor = (disabled) ? [UIColor lightGrayColor] : [UIColor darkTextColor];
}

@end
