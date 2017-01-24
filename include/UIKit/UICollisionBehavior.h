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

#import <CoreGraphics/CGGeometry.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIDynamicBehavior.h>
#import <UIKit/UIKitExport.h>
#import <UIKit/UIGeometry.h>

@protocol UIDynamicItem;
@class NSArray;
@protocol NSCopying;
@class UIBezierPath;
@protocol UICollisionBehaviorDelegate;

typedef NS_OPTIONS(NSUInteger, UICollisionBehaviorMode) {
    UICollisionBehaviorModeItems = 1 << 0,
    UICollisionBehaviorModeBoundaries = 1 << 1,
    UICollisionBehaviorModeEverything = NSUIntegerMax,
};

UIKIT_EXPORT_CLASS
@interface UICollisionBehavior : UIDynamicBehavior
- (void)addItem:(id<UIDynamicItem>)item STUB_METHOD;
- (instancetype)initWithItems:(NSArray*)items STUB_METHOD;
- (void)removeItem:(id<UIDynamicItem>)item STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* items STUB_PROPERTY;
- (void)addBoundaryWithIdentifier:(id<NSCopying>)identifier forPath:(UIBezierPath*)bezierPath STUB_METHOD;
- (void)addBoundaryWithIdentifier:(id<NSCopying>)identifier fromPoint:(CGPoint)p1 toPoint:(CGPoint)p2 STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* boundaryIdentifiers STUB_PROPERTY;
- (UIBezierPath*)boundaryWithIdentifier:(id<NSCopying>)identifier STUB_METHOD;

// The docs say this is a weak reference, but we can't enable that until we have ARC on in UIKit
@property (readwrite, nonatomic) id<UICollisionBehaviorDelegate> collisionDelegate STUB_PROPERTY;

@property (readwrite, nonatomic) UICollisionBehaviorMode collisionMode STUB_PROPERTY;
- (void)removeAllBoundaries STUB_METHOD;
- (void)removeBoundaryWithIdentifier:(id<NSCopying>)identifier STUB_METHOD;
- (void)setTranslatesReferenceBoundsIntoBoundaryWithInsets:(UIEdgeInsets)insets STUB_METHOD;
@property (readwrite, nonatomic) BOOL translatesReferenceBoundsIntoBoundary STUB_PROPERTY;
@end
