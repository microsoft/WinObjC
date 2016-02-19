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

#import <UIKit/UIDynamicAnimator.h>
#import <StubReturn.h>

@implementation UIDynamicAnimator
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithReferenceView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout*)layout {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)itemsInRect:(CGRect)rect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addBehavior:(UIDynamicBehavior*)behavior {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeBehavior:(UIDynamicBehavior*)behavior {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllBehaviors {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSTimeInterval)elapsedTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateItemUsingCurrentState:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForCellAtIndexPath:(NSIndexPath*)indexPath {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)decorationViewKind
                                                                 atIndexPath:(NSIndexPath*)indexPath {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString*)kind atIndexPath:(NSIndexPath*)indexPath {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
