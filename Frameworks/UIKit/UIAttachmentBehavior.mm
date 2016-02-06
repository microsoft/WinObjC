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

#import <UIKit/UIAttachmentBehavior.h>
#import <StubReturn.h>

/** @Status Stub */
const UIFloatRange UIFloatRangeZero = StubConstant();
/** @Status Stub */
const UIFloatRange UIFloatRangeInfinite = StubConstant();

@implementation UIAttachmentBehavior
/**
 @Status Stub
 @Notes
*/
+ (instancetype)slidingAttachmentWithItem:(id<UIDynamicItem>)item attachmentAnchor:(CGPoint)point axisOfTranslation:(CGVector)axis {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)slidingAttachmentWithItem:(id<UIDynamicItem>)item1
                           attachedToItem:(id<UIDynamicItem>)item2
                         attachmentAnchor:(CGPoint)point
                        axisOfTranslation:(CGVector)axis {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fixedAttachmentWithItem:(id<UIDynamicItem>)item1 attachedToItem:(id<UIDynamicItem>)item2 attachmentAnchor:(CGPoint)point {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)limitAttachmentWithItem:(id<UIDynamicItem>)item1
                       offsetFromCenter:(UIOffset)offset1
                         attachedToItem:(id<UIDynamicItem>)item2
                       offsetFromCenter:(UIOffset)offset2 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)pinAttachmentWithItem:(id<UIDynamicItem>)item1 attachedToItem:(id<UIDynamicItem>)item2 attachmentAnchor:(CGPoint)point {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItem:(id<UIDynamicItem>)item attachedToAnchor:(CGPoint)point {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItem:(id<UIDynamicItem>)item1 attachedToItem:(id<UIDynamicItem>)item2 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItem:(id<UIDynamicItem>)item offsetFromCenter:(UIOffset)p1 attachedToAnchor:(CGPoint)point {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItem:(id<UIDynamicItem>)item1
            offsetFromCenter:(UIOffset)p1
              attachedToItem:(id<UIDynamicItem>)item2
            offsetFromCenter:(UIOffset)p2 {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
