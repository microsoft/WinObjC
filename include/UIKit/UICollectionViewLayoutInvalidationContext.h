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

@class NSArray;
@class NSString;
@class NSDictionary;

UIKIT_EXPORT_CLASS
@interface UICollectionViewLayoutInvalidationContext : NSObject
@property (readonly, nonatomic) BOOL invalidateEverything STUB_PROPERTY;
@property (readonly, nonatomic) BOOL invalidateDataSourceCounts STUB_PROPERTY;
@property (nonatomic) CGPoint contentOffsetAdjustment STUB_PROPERTY;
@property (nonatomic) CGSize contentSizeAdjustment STUB_PROPERTY;
- (void)invalidateItemsAtIndexPaths:(NSArray*)indexPaths STUB_METHOD;
- (void)invalidateSupplementaryElementsOfKind:(NSString*)elementKind atIndexPaths:(NSArray*)indexPaths STUB_METHOD;
- (void)invalidateDecorationElementsOfKind:(NSString*)elementKind atIndexPaths:(NSArray*)indexPaths STUB_METHOD;
@property (readonly, nonatomic) NSArray* invalidatedItemIndexPaths STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* invalidatedSupplementaryIndexPaths STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* invalidatedDecorationIndexPaths STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* previousIndexPathsForInteractivelyMovingItems STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* targetIndexPathsForInteractivelyMovingItems STUB_PROPERTY;
@property (readonly, nonatomic) CGPoint interactiveMovementTarget STUB_PROPERTY;
@end
