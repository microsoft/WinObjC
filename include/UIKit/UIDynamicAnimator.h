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
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/Foundation.h>

@protocol UIDynamicItem;
@class UIView;
@class UICollectionViewLayout;
@class NSArray;
@class UIDynamicBehavior;
@protocol UIDynamicAnimatorDelegate;
@class UICollectionViewLayoutAttributes;
@class NSIndexPath;
@class NSString;

UIKIT_EXPORT_CLASS
@interface UIDynamicAnimator : NSObject
- (instancetype)initWithReferenceView:(UIView*)view STUB_METHOD;
- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout*)layout STUB_METHOD;
- (NSArray*)itemsInRect:(CGRect)rect STUB_METHOD;
- (void)addBehavior:(UIDynamicBehavior*)behavior STUB_METHOD;
- (void)removeBehavior:(UIDynamicBehavior*)behavior STUB_METHOD;
- (void)removeAllBehaviors STUB_METHOD;
- (NSTimeInterval)elapsedTime STUB_METHOD;
@property (readonly, getter=isRunning, nonatomic) BOOL running STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* behaviors STUB_PROPERTY;
@property (readonly, nonatomic) UIView* referenceView STUB_PROPERTY;
@property (nonatomic) id<UIDynamicAnimatorDelegate> delegate STUB_PROPERTY;
- (void)updateItemUsingCurrentState:(id<UIDynamicItem>)item STUB_METHOD;
- (UICollectionViewLayoutAttributes*)layoutAttributesForCellAtIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)decorationViewKind
                                                                 atIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString*)kind
                                                                    atIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
@end
