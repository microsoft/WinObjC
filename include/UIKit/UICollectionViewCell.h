//******************************************************************************
//
// UICollectionViewCell.h
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

#import <UIKit/UIKit.h>
#import <UIKit/UIKitExport.h>

@class UICollectionViewLayout, UICollectionView, UICollectionViewLayoutAttributes;

UIKIT_EXPORT_CLASS
@interface UICollectionReusableView : UIView

@property (nonatomic, readonly, copy) NSString* reuseIdentifier;

// Override in subclasses. Called before instance is returned to the reuse queue.
- (void)prepareForReuse;

// Apply layout attributes on cell.
- (void)applyLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes;
- (void)willTransitionFromLayout:(UICollectionViewLayout*)oldLayout toLayout:(UICollectionViewLayout*)newLayout;
- (void)didTransitionFromLayout:(UICollectionViewLayout*)oldLayout toLayout:(UICollectionViewLayout*)newLayout;

@end

@interface UICollectionReusableView (Internal)
@property (nonatomic, unsafe_unretained) UICollectionView* collectionView;
@property (nonatomic, copy) NSString* reuseIdentifier;
@property (nonatomic, strong, readonly) UICollectionViewLayoutAttributes* layoutAttributes;
@end

UIKIT_EXPORT_CLASS
@interface UICollectionViewCell : UICollectionReusableView

@property (nonatomic, readonly) UIView* contentView; // add custom subviews to the cell's contentView

// Cells become highlighted when the user touches them.
// The selected state is toggled when the user lifts up from a highlighted cell.
// Override these methods to provide custom UI for a selected or highlighted state.
// The collection view may call the setters inside an animation block.
@property (nonatomic, getter=isSelected) BOOL selected;
@property (nonatomic, getter=isHighlighted) BOOL highlighted;

// The background view is a subview behind all other views.
// If selectedBackgroundView is different than backgroundView, it will be placed above the background view and animated in on selection.
@property (nonatomic, strong) UIView* backgroundView;
@property (nonatomic, strong) UIView* selectedBackgroundView;

@end
