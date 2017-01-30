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

#import "HeaderTableViewCell.h"
#import "CALayerMultipleViewController.h"

@implementation HeaderTableViewCell {
    UILabel* _titleLabel;
    UIView* _layerView;
    UILabel* _countLabel;
    CALayer* _separator;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.backgroundColor = [UIColor clearColor];

        _titleLabel = [UILabel new];
        _titleLabel.backgroundColor = [UIColor clearColor];
        _titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
        _titleLabel.textColor = [UIColor darkTextColor];
        _titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont smallSystemFontSize]];
        [self addSubview:_titleLabel];

        _countLabel = [UILabel new];
        _countLabel.backgroundColor = [UIColor clearColor];
        _countLabel.translatesAutoresizingMaskIntoConstraints = NO;
        _countLabel.textColor = [UIColor lightGrayColor];
        _countLabel.font = [UIFont systemFontOfSize:[UIFont smallSystemFontSize]];
        [self addSubview:_countLabel];

        NSDictionary* views = NSDictionaryOfVariableBindings(_titleLabel, _countLabel);
        NSDictionary* metrics = @{ @"pad" : @(kPadding), @"height" : @(_titleLabel.font.lineHeight) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[_titleLabel]-(>=0)-[_countLabel]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(>=pad)-[_titleLabel(height)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-(>=pad)-[_countLabel(height)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];

        // Separator
        _separator = [CALayer layer];
        _separator.backgroundColor = [UIColor darkGrayColor].CGColor;
        _separator.frame = CGRectMake(0, CGRectGetHeight(self.frame) - 0.5f, CGRectGetWidth(self.frame), 0.5f);
        [self.layer addSublayer:_separator];
    }

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    _separator.frame = CGRectMake(0, CGRectGetHeight(self.frame) - 0.5f, CGRectGetWidth(self.frame), 0.5f);
}

- (void)setUpWithView:(UIView*)view andTitle:(NSString*)title {
    _titleLabel.text = title;
    _countLabel.text = [NSString stringWithFormat:@"%lu layers", view.layer.sublayers.count + 1];
    _countLabel.hidden = NO;
    _layerView = view;
}

- (void)setUpWithTitle:(NSString*)title {
    _titleLabel.text = title;
    _countLabel.hidden = YES;
    _layerView = nil;
}

@end
