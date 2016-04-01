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
#import <UIKit/UIKitTypes.h>
#import <UIKit/UITouch.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIDevice.h>

@class NSArray;

UIKIT_EXPORT_CLASS
@interface UITraitCollection : NSObject <NSCopying, NSObject, NSSecureCoding>
+ (UITraitCollection*)traitCollectionWithTraitsFromCollections:(NSArray*)traitCollections STUB_METHOD;
+ (UITraitCollection*)traitCollectionWithDisplayScale:(CGFloat)scale STUB_METHOD;
+ (UITraitCollection*)traitCollectionWithUserInterfaceIdiom:(UIUserInterfaceIdiom)idiom STUB_METHOD;
+ (UITraitCollection*)traitCollectionWithHorizontalSizeClass:(UIUserInterfaceSizeClass)horizontalSizeClass STUB_METHOD;
+ (UITraitCollection*)traitCollectionWithVerticalSizeClass:(UIUserInterfaceSizeClass)verticalSizeClass STUB_METHOD;
+ (UITraitCollection*)traitCollectionWithForceTouchCapability:(UIForceTouchCapability)capability STUB_METHOD;
@property (readonly, nonatomic) CGFloat displayScale STUB_PROPERTY;
@property (readonly, nonatomic) UIUserInterfaceSizeClass horizontalSizeClass STUB_PROPERTY;
@property (readonly, nonatomic) UIUserInterfaceIdiom userInterfaceIdiom STUB_PROPERTY;
@property (readonly, nonatomic) UIUserInterfaceSizeClass verticalSizeClass STUB_PROPERTY;
@property (readonly, nonatomic) UIForceTouchCapability forceTouchCapability STUB_PROPERTY;
- (BOOL)containsTraitsInCollection:(UITraitCollection*)trait STUB_METHOD;
@end
