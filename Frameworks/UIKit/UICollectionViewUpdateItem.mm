//******************************************************************************
//
// UICollectionViewUpdateItem.m
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

#import <UIKit/UIKit.h>
#import "UICollectionViewUpdateItem.h"

@interface UICollectionViewUpdateItem () {
    NSIndexPath* _initialIndexPath;
    NSIndexPath* _finalIndexPath;
    UICollectionUpdateAction _updateAction;
    id _gap;
}
@end

@implementation UICollectionViewUpdateItem

@synthesize updateAction = _updateAction;
@synthesize indexPathBeforeUpdate = _initialIndexPath;
@synthesize indexPathAfterUpdate = _finalIndexPath;

- (id)initWithInitialIndexPath:(NSIndexPath*)initialIndexPath
                finalIndexPath:(NSIndexPath*)finalIndexPath
                  updateAction:(UICollectionUpdateAction)updateAction {
    if ((self = [super init])) {
        _initialIndexPath = initialIndexPath;
        _finalIndexPath = finalIndexPath;
        _updateAction = updateAction;
    }
    return self;
}

- (id)initWithAction:(UICollectionUpdateAction)updateAction forIndexPath:(NSIndexPath*)indexPath {
    if (updateAction == UICollectionUpdateActionInsert)
        return [self initWithInitialIndexPath:nil finalIndexPath:indexPath updateAction:updateAction];
    else if (updateAction == UICollectionUpdateActionDelete)
        return [self initWithInitialIndexPath:indexPath finalIndexPath:nil updateAction:updateAction];
    else if (updateAction == UICollectionUpdateActionReload)
        return [self initWithInitialIndexPath:indexPath finalIndexPath:indexPath updateAction:updateAction];

    return nil;
}

- (id)initWithOldIndexPath:(NSIndexPath*)oldIndexPath newIndexPath:(NSIndexPath*)newIndexPath {
    return [self initWithInitialIndexPath:oldIndexPath finalIndexPath:newIndexPath updateAction:UICollectionUpdateActionMove];
}

- (NSString*)description {
    NSString* action = nil;
    switch (_updateAction) {
        case UICollectionUpdateActionInsert:
            action = @"insert";
            break;
        case UICollectionUpdateActionDelete:
            action = @"delete";
            break;
        case UICollectionUpdateActionMove:
            action = @"move";
            break;
        case UICollectionUpdateActionReload:
            action = @"reload";
            break;
        default:
            break;
    }

    return [NSString stringWithFormat:@"Index path before update (%@) index path after update (%@) action (%@).",
                                      _initialIndexPath,
                                      _finalIndexPath,
                                      action];
}

- (void)setNewIndexPath:(NSIndexPath*)indexPath {
    _finalIndexPath = indexPath;
}

- (void)setGap:(id)gap {
    _gap = gap;
}

- (BOOL)isSectionOperation {
    return (_initialIndexPath.item == NSNotFound || _finalIndexPath.item == NSNotFound);
}

- (NSIndexPath*)newIndexPath {
    return _finalIndexPath;
}

- (id)gap {
    return _gap;
}

- (UICollectionUpdateAction)action {
    return _updateAction;
}

- (id)indexPath {
    // TODO: check this
    return _initialIndexPath;
}

- (NSComparisonResult)compareIndexPaths:(UICollectionViewUpdateItem*)otherItem {
    NSComparisonResult result = NSOrderedSame;
    NSIndexPath* selfIndexPath = nil;
    NSIndexPath* otherIndexPath = nil;

    switch (_updateAction) {
        case UICollectionUpdateActionInsert:
            selfIndexPath = _finalIndexPath;
            otherIndexPath = [otherItem newIndexPath];
            break;
        case UICollectionUpdateActionDelete:
            selfIndexPath = _initialIndexPath;
            otherIndexPath = [otherItem indexPath];
        default:
            break;
    }

    if (self.isSectionOperation)
        result = [@(selfIndexPath.section) compare:@(otherIndexPath.section)];
    else
        result = [selfIndexPath compare:otherIndexPath];
    return result;
}

- (NSComparisonResult)inverseCompareIndexPaths:(UICollectionViewUpdateItem*)otherItem {
    return (NSComparisonResult)([self compareIndexPaths:otherItem] * -1);
}

@end
