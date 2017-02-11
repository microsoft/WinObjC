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

#import "FooterTableViewCell.h"
#import "CALayerMultipleViewController.h"

@implementation FooterTableViewCell {
    UIButton* _addLayerButton;
    CALayer* _separator;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.backgroundColor = [UIColor clearColor];

        _addLayerButton = [UIButton new];
        [_addLayerButton setTitle:@"+ Add layer" forState:UIControlStateNormal];
        [_addLayerButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateNormal];
        _addLayerButton.titleLabel.font = [UIFont systemFontOfSize:[UIFont labelFontSize]];
        _addLayerButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
        _addLayerButton.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:_addLayerButton];

        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        NSDictionary* views = NSDictionaryOfVariableBindings(_addLayerButton);
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[_addLayerButton]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-pad-[_addLayerButton]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];

        // Separator
        _separator = [CALayer layer];
        _separator.backgroundColor = [UIColor colorWithWhite:0.8 alpha:1.0].CGColor;
        _separator.frame = CGRectMake(0, 0, CGRectGetWidth(self.frame), 0.5f);
        [self.layer addSublayer:_separator];
    }

    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    _separator.frame = CGRectMake(0, 0, CGRectGetWidth(self.frame), 0.5f);
}

- (void)setUpWithSection:(NSInteger)section withTarget:(id)target andAction:(SEL)action {
    _addLayerButton.tag = section;
    [_addLayerButton addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
}

@end
