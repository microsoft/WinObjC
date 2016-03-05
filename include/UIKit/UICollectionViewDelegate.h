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
#import <UIKit/UIScrollViewDelegate.h>

@class UICollectionView;
@class NSIndexPath;
@class UICollectionViewCell;
@class UICollectionReusableView;
@class NSString;
@class UICollectionViewTransitionLayout;
@class UICollectionViewLayout;
@class UICollectionViewFocusUpdateContext;
@class UIFocusAnimationCoordinator;

@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional
- (BOOL)collectionView:(UICollectionView*)collectionView shouldSelectItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView didSelectItemAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView didDeselectItemAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView didHighlightItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView didUnhighlightItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView
       willDisplayCell:(UICollectionViewCell*)cell
    forItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView
    willDisplaySupplementaryView:(UICollectionReusableView*)view
                  forElementKind:(NSString*)elementKind
                     atIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView
  didEndDisplayingCell:(UICollectionViewCell*)cell
    forItemAtIndexPath:(NSIndexPath*)indexPath;
- (void)collectionView:(UICollectionView*)collectionView
    didEndDisplayingSupplementaryView:(UICollectionReusableView*)view
                     forElementOfKind:(NSString*)elementKind
                          atIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewTransitionLayout*)collectionView:(UICollectionView*)collectionView
                       transitionLayoutForOldLayout:(UICollectionViewLayout*)fromLayout
                                          newLayout:(UICollectionViewLayout*)toLayout;
- (CGPoint)collectionView:(UICollectionView*)collectionView targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset;
- (NSIndexPath*)collectionView:(UICollectionView*)collectionView
    targetIndexPathForMoveFromItemAtIndexPath:(NSIndexPath*)originalIndexPath
                          toProposedIndexPath:(NSIndexPath*)proposedIndexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView
      canPerformAction:(SEL)action
    forItemAtIndexPath:(NSIndexPath*)indexPath
            withSender:(id)sender;
- (void)collectionView:(UICollectionView*)collectionView
         performAction:(SEL)action
    forItemAtIndexPath:(NSIndexPath*)indexPath
            withSender:(id)sender;
- (BOOL)collectionView:(UICollectionView*)collectionView canFocusItemAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)collectionView:(UICollectionView*)collectionView shouldUpdateFocusInContext:(UICollectionViewFocusUpdateContext*)context;
- (void)collectionView:(UICollectionView*)collectionView
     didUpdateFocusInContext:(UICollectionViewFocusUpdateContext*)context
    withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator;
- (NSIndexPath*)indexPathForPreferredFocusedViewInCollectionView:(UICollectionView*)collectionView;
@end
