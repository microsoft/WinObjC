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
#import <UIKit/UIGeometry.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIDynamicBehavior.h>

@protocol UIDynamicItem;
@class NSArray;

typedef enum {
    UIAttachmentBehaviorTypeItems,
    UIAttachmentBehaviorTypeAnchor,
} UIAttachmentBehaviorType;

UIKIT_EXPORT const UIFloatRange UIFloatRangeZero;
UIKIT_EXPORT const UIFloatRange UIFloatRangeInfinite;

UIKIT_EXPORT_CLASS
@interface UIAttachmentBehavior : UIDynamicBehavior
+ (instancetype)slidingAttachmentWithItem:(id<UIDynamicItem>)item
                         attachmentAnchor:(CGPoint)point
                        axisOfTranslation:(CGVector)axis STUB_METHOD;
+ (instancetype)slidingAttachmentWithItem:(id<UIDynamicItem>)item1
                           attachedToItem:(id<UIDynamicItem>)item2
                         attachmentAnchor:(CGPoint)point
                        axisOfTranslation:(CGVector)axis STUB_METHOD;
+ (instancetype)fixedAttachmentWithItem:(id<UIDynamicItem>)item1
                         attachedToItem:(id<UIDynamicItem>)item2
                       attachmentAnchor:(CGPoint)point STUB_METHOD;
+ (instancetype)limitAttachmentWithItem:(id<UIDynamicItem>)item1
                       offsetFromCenter:(UIOffset)offset1
                         attachedToItem:(id<UIDynamicItem>)item2
                       offsetFromCenter:(UIOffset)offset2 STUB_METHOD;
+ (instancetype)pinAttachmentWithItem:(id<UIDynamicItem>)item1
                       attachedToItem:(id<UIDynamicItem>)item2
                     attachmentAnchor:(CGPoint)point STUB_METHOD;
- (instancetype)initWithItem:(id<UIDynamicItem>)item attachedToAnchor:(CGPoint)point STUB_METHOD;
- (instancetype)initWithItem:(id<UIDynamicItem>)item1 attachedToItem:(id<UIDynamicItem>)item2 STUB_METHOD;
- (instancetype)initWithItem:(id<UIDynamicItem>)item offsetFromCenter:(UIOffset)p1 attachedToAnchor:(CGPoint)point STUB_METHOD;
- (instancetype)initWithItem:(id<UIDynamicItem>)item1
            offsetFromCenter:(UIOffset)p1
              attachedToItem:(id<UIDynamicItem>)item2
            offsetFromCenter:(UIOffset)p2 STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* items STUB_PROPERTY;
@property (readwrite, nonatomic) CGPoint anchorPoint STUB_PROPERTY;
@property (readonly, nonatomic) UIAttachmentBehaviorType attachedBehaviorType STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat damping STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat frequency STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat length STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat frictionTorque STUB_PROPERTY;
@property (readwrite, nonatomic) UIFloatRange attachmentRange STUB_PROPERTY;

@end
