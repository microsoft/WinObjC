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

#ifndef _UIDYNAMICANIMATOR_H_
#define _UIDYNAMICANIMATOR_H_

#import <Foundation/NSObject.h>

@class UIDynamicBehavior;
@class UICollectionViewLayout;
@class UICollectionViewLayoutAttributes;
@class NSArray;
@class NSIndexPath;

@protocol UIDynamicItem <NSObject>
@end

@interface UIDynamicAnimator : NSObject

@property (nonatomic, readonly, copy) NSArray* behaviors;

- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout*)layout;
- (void)addBehavior:(UIDynamicBehavior*)behavior;
- (void)removeBehavior:(UIDynamicBehavior*)behavior;
- (NSArray*)itemsInRect:(CGRect)rect;
- (UICollectionViewLayoutAttributes*)layoutAttributesForCellAtIndexPath:(NSIndexPath*)indexPath;
- (void)updateItemUsingCurrentState:(id<UIDynamicItem>)item;

@end

#endif /* _UIDYNAMICANIMATOR_H_ */