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

#import <Foundation/Foundation.h>

#import "AutoLayoutViewController.h"

@interface CenteredAutoLayoutLabel : UILabel
- (instancetype)initWithFrame:(CGRect)frame;
@end

@implementation CenteredAutoLayoutLabel
- (instancetype)initWithFrame:(CGRect)frame {
    CenteredAutoLayoutLabel* ret = [super initWithFrame:frame];
    ret.translatesAutoresizingMaskIntoConstraints = NO;
    ret.textAlignment = NSTextAlignmentCenter;
    return ret;
}
- (instancetype)init {
    CenteredAutoLayoutLabel* ret = [super init];
    ret.translatesAutoresizingMaskIntoConstraints = NO;
    ret.textAlignment = NSTextAlignmentCenter;
    return ret;
}
@end


@implementation AutoLayoutViewController {
    CenteredAutoLayoutLabel* _addRemoveLabel;
};

- (void)viewDidLoad {
    [super viewDidLoad];

    id topGuide = self.topLayoutGuide;
    id bottomGuide = self.bottomLayoutGuide;
    self.view.backgroundColor = [UIColor whiteColor];
    
    CenteredAutoLayoutLabel* topLabel = [[CenteredAutoLayoutLabel alloc] initWithFrame:CGRectMake(0, 0, 50, 30)];
    topLabel.text = @"AutoLayout Top Guide - Test By Resizing and Rotating Window";
    topLabel.textColor = [UIColor lightGrayColor];
    
    [self.view addSubview:topLabel];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[topLabel]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[topGuide]-[topLabel(30)]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel, topGuide)]];

    CenteredAutoLayoutLabel* bottomLabel = [[CenteredAutoLayoutLabel alloc] initWithFrame:CGRectMake(0, 0, 50, 30)];
    bottomLabel.text = @"AutoLayout Bottom Guide";
    bottomLabel.textColor = [UIColor lightGrayColor];
    
    [self.view addSubview:bottomLabel];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[bottomLabel]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(bottomLabel)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[bottomLabel(30)]-[bottomGuide]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(bottomLabel, bottomGuide)]];
    
    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];

    [button setTitle:@"Button For Baseline" forState:UIControlStateNormal];
    [button setTitle:@"Highlighted State Changes Intrinsic Content Size" forState:UIControlStateHighlighted];
    [button setContentHuggingPriority:251 forAxis:UILayoutConstraintAxisVertical];
    button.contentEdgeInsets = UIEdgeInsetsMake(10, 10, 10, 10);
    button.translatesAutoresizingMaskIntoConstraints = NO;
    button.layer.cornerRadius = 5.0f;
    button.backgroundColor = [UIColor lightGrayColor];
    [self.view addSubview:button];

    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:bottomLabel attribute:NSLayoutAttributeTop multiplier:1.0 constant:-8.0f]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:button.superview attribute:NSLayoutAttributeLeft multiplier:1.0 constant:20.0f]];
    
    CenteredAutoLayoutLabel* buttonLabel = [CenteredAutoLayoutLabel new];
    
    buttonLabel.text = @"Baseline Label";
    [self.view addSubview:buttonLabel];
    
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:buttonLabel attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:button attribute:NSLayoutAttributeRight multiplier:1.0 constant:8.0f]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:buttonLabel attribute:NSLayoutAttributeBaseline relatedBy:NSLayoutRelationEqual toItem:button attribute:NSLayoutAttributeBaseline multiplier:1.0 constant:0]];
    
    UILabel* label1 = [CenteredAutoLayoutLabel new];
    UILabel* label2 = [CenteredAutoLayoutLabel new];
    UILabel* label3 = [CenteredAutoLayoutLabel new];
    UILabel* label4 = [CenteredAutoLayoutLabel new];
    
    label1.text = @"All";
    label2.text = @"the";
    label3.text = @"same";
    label4.text = @"size.";
    
    label1.backgroundColor = [UIColor colorWithRed:1.0 green:0.8 blue:0.8 alpha:1.0];
    label1.layer.borderColor = [UIColor blueColor].CGColor;
    label1.layer.borderWidth = 1.0f;

    label2.backgroundColor = [UIColor colorWithRed:0.8 green:1.0 blue:0.8 alpha:1.0];
    label2.layer.borderColor = [UIColor purpleColor].CGColor;
    label2.layer.borderWidth = 3.0f;

    label3.backgroundColor = [UIColor colorWithRed:0.8 green:0.8 blue:1.0 alpha:1.0];
    label3.layer.borderColor = [UIColor redColor].CGColor;
    label3.layer.borderWidth = 5.0f;

    label4.backgroundColor = [UIColor colorWithRed:1.0 green:1.0 blue:0.8 alpha:1.0];
    label4.layer.borderColor = [UIColor greenColor].CGColor;
    label4.layer.borderWidth = 7.0f;

    [self.view addSubview:label1];
    [self.view addSubview:label2];
    [self.view addSubview:label3];
    [self.view addSubview:label4];

    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[label1]-[label2(label1)]-[label3(label1)]-[label4(label1)]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(label1, label2, label3, label4)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[topLabel]-[label1]-[label2(label1)]-[label3(label1)]-[label4(label1)]-[button]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel, button, label1, label2, label3, label4)]];

    UIButton* button2 = [UIButton buttonWithType : UIButtonTypeRoundedRect];
    [button2 setTitle:@"Add a new label" forState:UIControlStateNormal];

    [button2 setTitle:@"Delete the new label" forState:UIControlStateSelected];
    [button2 setTitle:@"Delete the new label" forState:UIControlStateSelected | UIControlStateHighlighted];

    [button2 setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted];
    [button2 setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted | UIControlStateSelected];

    [button2 setContentHuggingPriority:251 forAxis:UILayoutConstraintAxisVertical];
    button2.contentEdgeInsets = UIEdgeInsetsMake(10, 10, 10, 10);
    button2.translatesAutoresizingMaskIntoConstraints = NO;
    button2.layer.cornerRadius = 5.0f;
    button2.backgroundColor = [UIColor lightGrayColor];
    [button2 addTarget:self action:@selector(_button2TouchUp:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];

    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button2 attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:buttonLabel attribute:NSLayoutAttributeRight multiplier:1.0 constant:8.0f]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button2 attribute:NSLayoutAttributeBaseline relatedBy:NSLayoutRelationEqual toItem:buttonLabel attribute:NSLayoutAttributeBaseline multiplier:1.0 constant:0]];
}

- (void)_button2TouchUp:(UIButton*)button {
    BOOL wasSelected = button.isSelected;
    [button setSelected:!wasSelected];

    if (wasSelected) {
        // Delete the label
        [_addRemoveLabel removeFromSuperview];
        _addRemoveLabel = nil;
    } else {
        // Add the new label
        _addRemoveLabel = [CenteredAutoLayoutLabel new];
        _addRemoveLabel.text = @"Temporary";
        _addRemoveLabel.backgroundColor = [UIColor purpleColor];
        [_addRemoveLabel sizeToFit];
        [self.view addSubview:_addRemoveLabel];
    }
}

@end