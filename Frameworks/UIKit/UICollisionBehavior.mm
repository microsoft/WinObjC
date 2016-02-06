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

#import <UIKit/UIKit.h>
#import <StubReturn.h>

@implementation UICollisionBehavior
/**
 @Status Stub
 @Notes
*/
- (void)addItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItems:(NSArray*)items {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addBoundaryWithIdentifier:(id<NSCopying>)identifier forPath:(UIBezierPath*)bezierPath {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addBoundaryWithIdentifier:(id<NSCopying>)identifier fromPoint:(CGPoint)p1 toPoint:(CGPoint)p2 {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIBezierPath*)boundaryWithIdentifier:(id<NSCopying>)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllBoundaries {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeBoundaryWithIdentifier:(id<NSCopying>)identifier {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setTranslatesReferenceBoundsIntoBoundaryWithInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
}

@end
