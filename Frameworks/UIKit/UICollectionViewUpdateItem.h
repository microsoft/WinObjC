//******************************************************************************
//
// UICollectionViewUpdateItem.h
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
// Contributed by Sergey Gavrilyuk.
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

enum _UICollectionUpdateAction {
    UICollectionUpdateActionInsert,
    UICollectionUpdateActionDelete,
    UICollectionUpdateActionReload,
    UICollectionUpdateActionMove,
    UICollectionUpdateActionNone
};
typedef NSInteger UICollectionUpdateAction;

@interface UICollectionViewUpdateItem : NSObject

@property (nonatomic, readonly, strong) NSIndexPath* indexPathBeforeUpdate; // nil for UICollectionUpdateActionInsert
@property (nonatomic, readonly, strong) NSIndexPath* indexPathAfterUpdate; // nil for UICollectionUpdateActionDelete
@property (nonatomic, readonly, assign) UICollectionUpdateAction updateAction;

- (id)initWithInitialIndexPath:(NSIndexPath*)arg1 finalIndexPath:(NSIndexPath*)arg2 updateAction:(UICollectionUpdateAction)arg3;

- (id)initWithAction:(UICollectionUpdateAction)arg1 forIndexPath:(NSIndexPath*)indexPath;

- (id)initWithOldIndexPath:(NSIndexPath*)arg1 newIndexPath:(NSIndexPath*)arg2;

- (UICollectionUpdateAction)updateAction;

- (NSComparisonResult)compareIndexPaths:(UICollectionViewUpdateItem*)otherItem;

- (NSComparisonResult)inverseCompareIndexPaths:(UICollectionViewUpdateItem*)otherItem;

@end
