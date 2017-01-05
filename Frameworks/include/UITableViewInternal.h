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

#include <UIKit/UICollectionViewDelegate.h>
#include <UIKit/UIStoryboardSegueTemplate.h>
#include <UIKit/UITableView.h>
#include <UIKit/UITableViewDataSource.h>
#include <UIKit/UITableViewDelegate.h>

#include <unordered_map>
#include <vector>

class TableViewNode;
class TableViewSection;
class TableViewRow;
class ReusableCell;
class VisibleComponents;

@class UIButton;
@class UICollectionViewData;

struct UITableViewPriv {
    id<UITableViewDelegate> _delegate; // this should be idweak
    id<UITableViewDataSource> _dataSource;
    idretain _footerView;
    idretain _externalObjects;
    float _footerYPos;
    StrongId<UIView> _headerView;
    StrongId<UIView> _backgroundView;
    std::unordered_map<std::string, std::vector<ReusableCell*>> _reusableCells;
    StrongId<NSMutableDictionary> _reusableCellNibs;
    StrongId<NSMutableDictionary> _reusableHeaderClasses;
    StrongId<NSMutableDictionary> _reusableCellClasses;

    float _defaultRowHeight;
    float _defaultSectionHeaderHeight;

    TableViewNode* _rootNode;
    BOOL _needsReload;
    DWORD _isEnumerating;

    VisibleComponents* _visibleComponents;

    UITableViewStyle _style;
    unsigned _separatorStyle;
    BOOL _isEditing;

    DWORD _allowsSelection;
    bool _allowsMultipleSelection, _allowsMultipleSelectionDuringEditing;

    NSInteger sectionCount();
    TableViewSection* sectionAtIndex(int idx);

    CGSize _lastSize;

    void removeReusableCell(ReusableCell* cell);
    void addReusableCell(id cell);
    void addReusableCell(TableViewRow* row);
};

@interface UITableView () <UITableViewDelegate> {
@public
    id _dataSource;
    id<UICollectionViewDelegate> _collectionViewDelegate;
    idretain _supplementaryViewReuseQueues, _cellReuseQueues, _decorationViewReuseQueues;
    idretain _nibLayout, _nibCellsExternalObjects, _supplementaryViewsExternalObjects;
    idretain _cellNibDict, _supplementaryViewNibDict, _supplementaryViewClassDict, _cellClassDict;
    UICollectionViewData* _collectionViewData;
    idretain _layout, _allVisibleViewsDict;
    idretain _backgroundView;
    idretain _updateCompletionHandler;

    idretain _insertItems;
    idretain _deleteItems;
    idretain _reloadItems;
    idretain _moveItems;
    idretain _update;

    struct UITableViewPriv* tablePriv;
    idretain _indexPathsForSelectedItems, _indexPathsForHighlightedItems;
    idretain _currentIndexPath, _touchingIndexPath;

    idretain _originalInsertItems, _originalDeleteItems;

    int _reloadingSuspendedCount, _updateCount;

    struct {
        unsigned int delegateShouldHighlightItemAtIndexPath : 1;
        unsigned int delegateDidHighlightItemAtIndexPath : 1;
        unsigned int delegateDidUnhighlightItemAtIndexPath : 1;
        unsigned int delegateShouldSelectItemAtIndexPath : 1;
        unsigned int delegateShouldDeselectItemAtIndexPath : 1;
        unsigned int delegateDidSelectItemAtIndexPath : 1;
        unsigned int delegateDidDeselectItemAtIndexPath : 1;
        unsigned int delegateSupportsMenus : 1;
        unsigned int delegateDidEndDisplayingCell : 1;
        unsigned int delegateDidEndDisplayingSupplementaryView : 1;
        unsigned int dataSourceNumberOfSections : 1;
        unsigned int dataSourceViewForSupplementaryElement : 1;
        unsigned int reloadSkippedDuringSuspension : 1;
        unsigned int scheduledUpdateVisibleCells : 1;
        unsigned int scheduledUpdateVisibleCellLayoutAttributes : 1;
        unsigned int allowsSelection : 1;
        unsigned int allowsMultipleSelection : 1;
        unsigned int updating : 1;
        unsigned int fadeCellsForBoundsChange : 1;
        unsigned int updatingLayout : 1;
        unsigned int needsReload : 1;
        unsigned int reloading : 1;
        unsigned int skipLayoutDuringSnapshotting : 1;
        unsigned int layoutInvalidatedSinceLastCellUpdate : 1;
        unsigned int doneFirstLayout : 1;
    } _collectionViewFlags;
}

- (void)_forwardCellRemoval:(UITableViewCell*)cell;
- (void)_cellSelectedUp:(UITableViewCell*)cell;
- (void)_cellSelectedDown:(UITableViewCell*)cell;
- (void)_cellSelectedCancelled:(UITableViewCell*)cell;
- (void)_cellAccessoryTapped:(UITableViewCell*)cell;
- (BOOL)_canEditCell:(UITableViewCell*)cell;

@end

@class _UIGroupEdgeView;

@interface UITableViewCell () {
@public
    StrongId<UIView> _contentView;
    StrongId<UIView> _curAccessoryView;
    StrongId<UIStoryboardSegueTemplate> _selectionSegueTemplate;
    StrongId<UIView> _multipleSelectionBackgroundView;

    BOOL _isSelected, _isHighlighted, _currentlyHighlighted;
    BOOL _isEditing;
    UITableViewCellAccessoryType _accessoryType;
    float _indentationWidth;
    UITableViewCellStyle _style;
    UITableViewCellSelectionStyle _selectionStyle;
    BOOL _showsReorderControl;
    StrongId<UILabel> _textLabel;
    StrongId<UILabel> _secondaryLabel;
    StrongId<UIImageView> _imageView;
    StrongId<UIView> _backgroundView, _selectedbackgroundView;
    StrongId<NSIndexPath> _deferredIndexPath, _indexPath;
    UIView *_accessoryView, *_editingAccessoryView;
    StrongId<UIImageView> _internalAccessoryView;
    StrongId<UIButton> _internalAccessoryButton;
    int _internalAccessoryType;
    idretain _reuseIdentifier;
    idretain _borderView;
    int _indentationLevel;

    int _groupEdgeStyle;
    StrongId<_UIGroupEdgeView> _groupEdgeView;
    idretain _cellBackgroundColor;
    idretain _cellOldBackgroundColor;
    BOOL _cellBackgroundColorSet;

    idretain _swipeGestureRecognizer;
    StrongId<UIButton> _removeButton;

    StrongId<UIImageView> _editSelectedView;
    BOOL _editSelectedViewVisible;
}

- (void)_setEditingMode:(BOOL)editingMode animated:(BOOL)animated;

// TODO: these ought to be _names, but it's too difficult to locate all usages of indexPath currently
- (void)setIndexPath:(NSIndexPath*)path;
- (NSIndexPath*)indexPath;

@end