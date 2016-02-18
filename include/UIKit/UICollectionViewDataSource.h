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
#import <Foundation/Foundation.h>

@class UICollectionView;
@class UICollectionViewCell;
@class NSIndexPath;
@class UICollectionReusableView;
@class NSString;

@protocol UICollectionViewDataSource <NSObject>
- (NSInteger)collectionView:(UICollectionView*)collectionView numberOfItemsInSection:(NSInteger)section;
- (UICollectionViewCell*)collectionView:(UICollectionView*)collectionView cellForItemAtIndexPath:(NSIndexPath*)indexPath;

@optional
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView*)collectionView;
- (UICollectionReusableView*)collectionView:(UICollectionView*)collectionView
          viewForSupplementaryElementOfKind:(NSString*)kind
                                atIndexPath:(NSIndexPath*)indexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView canMoveItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView
   moveItemAtIndexPath:(NSIndexPath*)sourceIndexPath
           toIndexPath:(NSIndexPath*)destinationIndexPath;
@end
