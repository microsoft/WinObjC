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

#pragma once

#import <UIKit/UIKitExport.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIView.h>
#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    UIStackViewDistributionFill = 0,
    UIStackViewDistributionFillEqually,
    UIStackViewDistributionFillProportionally,
    UIStackViewDistributionEqualSpacing,
    UIStackViewDistributionEqualCentering,
} UIStackViewDistribution;

typedef enum : NSInteger {
    UIStackViewAlignmentFill,
    UIStackViewAlignmentLeading,
    UIStackViewAlignmentTop = UIStackViewAlignmentLeading,
    UIStackViewAlignmentFirstBaseline, // Valid for horizontal axis only
    UIStackViewAlignmentCenter,
    UIStackViewAlignmentTrailing,
    UIStackViewAlignmentBottom = UIStackViewAlignmentTrailing,
    UIStackViewAlignmentLastBaseline, // Valid for horizontal axis only
} UIStackViewAlignment;
UIKIT_EXPORT_CLASS

@interface UIStackView : UIView <NSCoding,
                                 NSObject,
                                 UIAppearance,
                                 UIAppearanceContainer,
                                 UICoordinateSpace,
                                 UIDynamicItem,
                                 UIFocusEnvironment,
                                 UITraitEnvironment>
- (instancetype)initWithArrangedSubviews:(NSArray*)views STUB_METHOD;
- (void)addArrangedSubview:(UIView*)view STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* arrangedSubviews STUB_PROPERTY;
- (void)insertArrangedSubview:(UIView*)view atIndex:(NSUInteger)stackIndex STUB_METHOD;
- (void)removeArrangedSubview:(UIView*)view STUB_METHOD;
@property (nonatomic) UIStackViewAlignment alignment STUB_PROPERTY;
@property (nonatomic) UILayoutConstraintAxis axis STUB_PROPERTY;
@property (getter=isBaselineRelativeArrangement, nonatomic) BOOL baselineRelativeArrangement STUB_PROPERTY;
@property (nonatomic) UIStackViewDistribution distribution STUB_PROPERTY;
@property (getter=isLayoutMarginsRelativeArrangement, nonatomic) BOOL layoutMarginsRelativeArrangement STUB_PROPERTY;
@property (nonatomic) CGFloat spacing STUB_PROPERTY;
@end
