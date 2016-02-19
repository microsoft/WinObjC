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
#import <UIKit/UIDynamicBehavior.h>

@protocol UIDynamicItem;
@class NSArray;

UIKIT_EXPORT_CLASS
@interface UIDynamicItemBehavior : UIDynamicBehavior
- (void)addItem:(id<UIDynamicItem>)item STUB_METHOD;
- (instancetype)initWithItems:(NSArray*)items STUB_METHOD;
- (void)removeItem:(id<UIDynamicItem>)item STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* items STUB_PROPERTY;
- (void)addAngularVelocity:(CGFloat)velocity forItem:(id<UIDynamicItem>)item STUB_METHOD;
- (void)addLinearVelocity:(CGPoint)velocity forItem:(id<UIDynamicItem>)item STUB_METHOD;
@property (readwrite, nonatomic) BOOL allowsRotation STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat angularResistance STUB_PROPERTY;
- (CGFloat)angularVelocityForItem:(id<UIDynamicItem>)item STUB_METHOD;
- (CGPoint)linearVelocityForItem:(id<UIDynamicItem>)item STUB_METHOD;
@property (readwrite, nonatomic) CGFloat density STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat elasticity STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat friction STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat resistance STUB_PROPERTY;
@property (readwrite, nonatomic) CGFloat charge STUB_PROPERTY;
@property (getter=isAnchored, nonatomic) BOOL anchored STUB_PROPERTY;
@end
