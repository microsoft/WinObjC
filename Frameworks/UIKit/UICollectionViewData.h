//******************************************************************************
//
// UICollectionViewData.h
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
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

#pragma once

#import <UIKit/UICollectionViewCommon.h>

@class UICollectionView, UICollectionViewLayout, UICollectionViewLayoutAttributes;

@interface UICollectionViewData : NSObject

// Designated initializer.
- (id)initWithCollectionView:(UICollectionView*)collectionView layout:(UICollectionViewLayout*)layout;

// Ensure data is valid. may fetches items from dataSource and layout.
- (void)validateLayoutInRect:(CGRect)rect;

- (CGRect)rectForItemAtIndexPath:(NSIndexPath*)indexPath;

/*
 - (CGRect)rectForSupplementaryElementOfKind:(id)arg1 atIndexPath:(id)arg2;
 - (CGRect)rectForDecorationElementOfKind:(id)arg1 atIndexPath:(id)arg2;
 - (CGRect)rectForGlobalItemIndex:(int)arg1;
*/

// No idea (yet)
- (NSUInteger)globalIndexForItemAtIndexPath:(NSIndexPath*)indexPath;

- (NSIndexPath*)indexPathForItemAtGlobalIndex:(NSInteger)index;

// Fetch layout attributes
- (NSArray*)layoutAttributesForElementsInRect:(CGRect)rect;

/*
- (UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath;
- (UICollectionViewLayoutAttributes *)layoutAttributesForElementsInSection:(NSInteger)section;
- (UICollectionViewLayoutAttributes *)layoutAttributesForGlobalItemIndex:(NSInteger)index;
- (UICollectionViewLayoutAttributes *)layoutAttributesForDecorationViewOfKind:(id)arg1 atIndexPath:(NSIndexPath *)indexPath;
- (UICollectionViewLayoutAttributes *)layoutAttributesForSupplementaryElementOfKind:(id)arg1 atIndexPath:(NSIndexPath *)indexPath;
 - (id)existingSupplementaryLayoutAttributesInSection:(int)arg1;
*/

// Make data to re-evaluate dataSources.
- (void)invalidate;

// Access cached item data
- (NSInteger)numberOfItemsBeforeSection:(NSInteger)section;

- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (NSInteger)numberOfItems;

- (NSInteger)numberOfSections;

// Total size of the content.
- (CGRect)collectionViewContentRect;

@property (readonly) BOOL layoutIsPrepared;

/*
 - (void)_setLayoutAttributes:(id)arg1 atGlobalItemIndex:(int)arg2;
 - (void)_setupMutableIndexPath:(id*)arg1 forGlobalItemIndex:(int)arg2;
 - (id)_screenPageForPoint:(struct CGPoint { float x1; float x2; })arg1;
 - (void)_validateContentSize;
 - (void)_validateItemCounts;
 - (void)_updateItemCounts;
 - (void)_loadEverything;
 - (void)_prepareToLoadData;
 - (void)invalidate:(BOOL)arg1;
 */

@end
