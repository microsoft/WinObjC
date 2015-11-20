//******************************************************************************
//
// UICollectionViewCommon.h
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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Mostly a debug feature, makes classes from UICollection* compatible with UICollection*
// (e.g. adding the "real" UICollectionViewFlowLayout to UICollectionView.
//#define kPSUIInteroperabilityEnabled

@class UICollectionView, UICollectionViewCell, UICollectionReusableView;

@protocol UICollectionViewDataSource <NSObject>
@required

- (NSInteger)collectionView:(UICollectionView*)collectionView numberOfItemsInSection:(NSInteger)section;

// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
- (UICollectionViewCell*)collectionView:(UICollectionView*)collectionView cellForItemAtIndexPath:(NSIndexPath*)indexPath;

@optional

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView*)collectionView;

// The view that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
- (UICollectionReusableView*)collectionView:(UICollectionView*)collectionView
          viewForSupplementaryElementOfKind:(NSString*)kind
                                atIndexPath:(NSIndexPath*)indexPath;

@end

@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional

// Methods for notification of selection/deselection and highlight/unhighlight events.
// The sequence of calls leading to selection from a user touch is:
//
// (when the touch begins)
// 1. -collectionView:shouldHighlightItemAtIndexPath:
// 2. -collectionView:didHighlightItemAtIndexPath:
//
// (when the touch lifts)
// 3. -collectionView:shouldSelectItemAtIndexPath: or -collectionView:shouldDeselectItemAtIndexPath:
// 4. -collectionView:didSelectItemAtIndexPath: or -collectionView:didDeselectItemAtIndexPath:
// 5. -collectionView:didUnhighlightItemAtIndexPath:
- (BOOL)collectionView:(UICollectionView*)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath*)indexPath;

- (void)collectionView:(UICollectionView*)collectionView didHighlightItemAtIndexPath:(NSIndexPath*)indexPath;

- (void)collectionView:(UICollectionView*)collectionView didUnhighlightItemAtIndexPath:(NSIndexPath*)indexPath;

- (BOOL)collectionView:(UICollectionView*)collectionView shouldSelectItemAtIndexPath:(NSIndexPath*)indexPath;

- (BOOL)collectionView:(UICollectionView*)collectionView
    shouldDeselectItemAtIndexPath:(NSIndexPath*)indexPath; // called when the user taps on an already-selected item in multi-select mode
- (void)collectionView:(UICollectionView*)collectionView didSelectItemAtIndexPath:(NSIndexPath*)indexPath;

- (void)collectionView:(UICollectionView*)collectionView didDeselectItemAtIndexPath:(NSIndexPath*)indexPath;

- (void)collectionView:(UICollectionView*)collectionView
  didEndDisplayingCell:(UICollectionViewCell*)cell
    forItemAtIndexPath:(NSIndexPath*)indexPath;

- (void)collectionView:(UICollectionView*)collectionView
    didEndDisplayingSupplementaryView:(UICollectionReusableView*)view
                     forElementOfKind:(NSString*)elementKind
                          atIndexPath:(NSIndexPath*)indexPath;

// These methods provide support for copy/paste actions on cells.
// All three should be implemented if any are.
- (BOOL)collectionView:(UICollectionView*)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath*)indexPath;

- (BOOL)collectionView:(UICollectionView*)collectionView
      canPerformAction:(SEL)action
    forItemAtIndexPath:(NSIndexPath*)indexPath
            withSender:(id)sender;

- (void)collectionView:(UICollectionView*)collectionView
         performAction:(SEL)action
    forItemAtIndexPath:(NSIndexPath*)indexPath
            withSender:(id)sender;

@end
