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

#import "LayerTableViewCell.h"
#import "CALayerMultipleViewController.h"

@implementation LayerTableViewCell {
    UILabel* _titleLabel;
    CALayer* _layer;
    UIButton* _moveUpButton;
    UIButton* _moveDownButton;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        _titleLabel = [UILabel new];
        _titleLabel.backgroundColor = [UIColor clearColor];
        _titleLabel.translatesAutoresizingMaskIntoConstraints = NO;
        _titleLabel.textColor = [UIColor darkTextColor];
        _titleLabel.font = [UIFont systemFontOfSize:[UIFont labelFontSize]];

        [self addSubview:_titleLabel];

        _moveUpButton = [UIButton new];
        _moveUpButton.translatesAutoresizingMaskIntoConstraints = NO;
        _moveUpButton.titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont smallSystemFontSize]];
        [_moveUpButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
        [_moveUpButton setTitle:@"\u2191" forState:UIControlStateNormal];
        [_moveUpButton addTarget:self action:@selector(moveUp) forControlEvents:UIControlEventTouchUpInside];
        [_moveUpButton sizeToFit];

        [self addSubview:_moveUpButton];

        _moveDownButton = [UIButton new];
        _moveDownButton.translatesAutoresizingMaskIntoConstraints = NO;
        _moveDownButton.titleLabel.font = [UIFont boldSystemFontOfSize:[UIFont smallSystemFontSize]];
        [_moveDownButton setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
        [_moveDownButton setTitle:@"\u2193" forState:UIControlStateNormal];
        [_moveDownButton addTarget:self action:@selector(moveDown) forControlEvents:UIControlEventTouchUpInside];
        [_moveDownButton sizeToFit];

        [self addSubview:_moveDownButton];

        NSDictionary* views = NSDictionaryOfVariableBindings(_titleLabel, _moveUpButton, _moveDownButton);
        NSDictionary* metrics = @{ @"pad" : @(kPadding), @"pad3x" : @(kPadding * 3.0f) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad3x-[_titleLabel]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[_titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=0)-[_moveUpButton(20)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=0)-[_moveDownButton(20)]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];

        [_moveUpButton.topAnchor constraintEqualToAnchor:self.topAnchor constant:kPadding / 2.0f].active = YES;
        [_moveDownButton.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-kPadding / 2.0f].active = YES;
    }

    return self;
}

- (void)drawRect:(CGRect)rect {
    [super layoutSubviews];

    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat originY = (CGRectGetHeight(rect) / 2.0) - kPadding / 2.0;
    CGRect rectangle = CGRectMake(kPadding, originY, kPadding, kPadding);
    CGContextSetFillColorWithColor(context, _layer.backgroundColor);
    CGContextFillRect(context, rectangle);
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self setNeedsDisplay];
}

- (void)setUpWithLayer:(CALayer*)layer
                andTitle:(NSString*)title
      shouldShowUpButton:(BOOL)showUpButton
    shouldShowDownButton:(BOOL)showDownButton {
    _titleLabel.text = title;
    _layer = layer;
    _moveUpButton.hidden = !showUpButton;
    _moveDownButton.hidden = !showDownButton;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    self.backgroundColor = selected ? [UIColor colorWithWhite:0.8 alpha:1.0] : [UIColor clearColor];
}

#pragma mark - Button handlers

- (void)moveUp {
    if ([self.delegate respondsToSelector:@selector(cellWithLayer:shouldMove:)]) {
        [self.delegate cellWithLayer:_layer shouldMove:MoveUp];
    }
}

- (void)moveDown {
    if ([self.delegate respondsToSelector:@selector(cellWithLayer:shouldMove:)]) {
        [self.delegate cellWithLayer:_layer shouldMove:MoveDown];
    }
}

@end
