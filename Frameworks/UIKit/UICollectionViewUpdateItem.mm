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

#include "Starboard.h"
#include "Foundation/NSMutableDictionary.h"
#include "UICollectionViewUpdateItem.h"

@implementation UICollectionViewUpdateItem : NSObject
- (id)initWithAction:(UICollectionUpdateAction)updateAction forIndexPath:(id)indexPath {
    if (updateAction == UICollectionUpdateActionInsert)
        return [self initWithInitialIndexPath:nil finalIndexPath:indexPath updateAction:updateAction];
    else if (updateAction == UICollectionUpdateActionDelete)
        return [self initWithInitialIndexPath:indexPath finalIndexPath:nil updateAction:updateAction];
    else if (updateAction == UICollectionUpdateActionReload)
        return [self initWithInitialIndexPath:indexPath finalIndexPath:indexPath updateAction:updateAction];

    return nil;
}

- (id)initWithInitialIndexPath:(id)initialIndexPath
                finalIndexPath:(id)finalIndexPath
                  updateAction:(UICollectionUpdateAction)updateAction {
    _initialIndexPath = initialIndexPath;
    _finalIndexPath = finalIndexPath;
    _updateAction = updateAction;
    return self;
}

- (id)indexPathBeforeUpdate {
    return _initialIndexPath;
}

- (id)setIndexPathBeforeUpdate:(id)indexPath {
    _initialIndexPath = indexPath;
    return self;
}

- (id)indexPathAfterUpdate {
    return _finalIndexPath;
}

- (UICollectionUpdateAction)updateAction {
    return _updateAction;
}

- (BOOL)isSectionOperation {
    return ([_initialIndexPath item] == NSNotFound || [_finalIndexPath item] == NSNotFound);
}

@end
