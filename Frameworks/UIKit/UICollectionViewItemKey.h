//******************************************************************************
//
// UICollectionViewItemKey.h
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

UIKIT_EXPORT NSString* const UICollectionElementKindCell;
UIKIT_EXPORT NSString* const UICollectionElementKindDecorationView;
@class UICollectionViewLayoutAttributes;

NSString* UICollectionViewItemTypeToString(UICollectionViewItemType type); // debug helper

// Used in NSDictionaries
@interface UICollectionViewItemKey : NSObject <NSCopying>

+ (id)collectionItemKeyForLayoutAttributes:(UICollectionViewLayoutAttributes*)layoutAttributes;

+ (id)collectionItemKeyForCellWithIndexPath:(NSIndexPath*)indexPath;

@property (nonatomic, assign) UICollectionViewItemType type;
@property (nonatomic, strong) NSIndexPath* indexPath;
@property (nonatomic, strong) NSString* identifier;

@end
