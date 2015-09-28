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


@implementation AutoLayoutViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    id topGuide = self.topLayoutGuide;
    id bottomGuide = self.bottomLayoutGuide;
    self.view.backgroundColor = [UIColor whiteColor];
    
    CenteredAutoLayoutLabel* topLabel = [[CenteredAutoLayoutLabel alloc] initWithFrame:CGRectMake(0, 0, 50, 20)];
    topLabel.text = @"AutoLayout Top Guide";
    topLabel.textColor = [UIColor lightGrayColor];
    
    [self.view addSubview:topLabel];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[topLabel]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[topGuide]-[topLabel(20)]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel, topGuide)]];

    CenteredAutoLayoutLabel* bottomLabel = [[CenteredAutoLayoutLabel alloc] initWithFrame:CGRectMake(0, 0, 50, 20)];
    bottomLabel.text = @"AutoLayout Bottom Guide";
    bottomLabel.textColor = [UIColor lightGrayColor];
    
    [self.view addSubview:bottomLabel];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[bottomLabel]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(bottomLabel)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[bottomLabel(20)]-[bottomGuide]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(bottomLabel, bottomGuide)]];
    
    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    [button setTitle:@"Button For Baseline" forState:UIControlStateNormal];
    [button invalidateIntrinsicContentSize];
    [button setContentHuggingPriority:251 forAxis:UILayoutConstraintAxisVertical];
    button.translatesAutoresizingMaskIntoConstraints = NO;
    button.layer.cornerRadius = 5.0f;
    button.backgroundColor = [UIColor lightGrayColor];
    [self.view addSubview:button];
    
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:bottomLabel attribute:NSLayoutAttributeTop multiplier:1.0 constant:-8.0f]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:button.superview attribute:NSLayoutAttributeLeft multiplier:1.0 constant:20.0f]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:button.intrinsicContentSize.width + 20]];
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:button attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1.0 constant:button.intrinsicContentSize.height + 20]];
    
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
    label2.backgroundColor = [UIColor colorWithRed:0.8 green:1.0 blue:0.8 alpha:1.0];
    label3.backgroundColor = [UIColor colorWithRed:0.8 green:0.8 blue:1.0 alpha:1.0];
    label4.backgroundColor = [UIColor colorWithRed:1.0 green:1.0 blue:0.8 alpha:1.0];
    
    [self.view addSubview:label1];
    [self.view addSubview:label2];
    [self.view addSubview:label3];
    [self.view addSubview:label4];

    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"|-[label1]-[label2(label1)]-[label3(label1)]-[label4(label1)]-|" options:NO metrics:nil views:NSDictionaryOfVariableBindings(label1, label2, label3, label4)]];
    [self.view addConstraints: [NSLayoutConstraint constraintsWithVisualFormat:@"V:[topLabel]-[label1]-[label2(label1)]-[label3(label1)]-[label4(label1)]-[button]" options:NO metrics:nil views:NSDictionaryOfVariableBindings(topLabel, button, label1, label2, label3, label4)]];
}

@end