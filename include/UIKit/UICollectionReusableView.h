//******************************************************************************
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

#include <UIKit/UIView.h>

@class UICollectionViewLayout;
@class UICollectionView;
@class UICollectionViewLayoutAttributes;

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
