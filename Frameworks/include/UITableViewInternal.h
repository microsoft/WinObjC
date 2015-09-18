#pragma once

#include <unordered_map>
#include <vector>

class TableViewNode;
class TableViewSection;
class TableViewRow;
class ReusableCell;
class VisibleComponents;

struct UITableViewPriv
{
    id<UITableViewDelegate> _delegate; // this should be idweak
    id<UITableViewDataSource> _dataSource;
    idretain _footerView;
    idretain _externalObjects;
    float    _footerYPos;
    idretain _headerView;
    idretaintype(UIView)  _backgroundView;
    std::unordered_map<std::string, std::vector<ReusableCell*>> _reusableCells;
    idretaintype(NSMutableDictionary)  _reusableCellNibs;
    idretaintype(NSMutableDictionary)  _reusableHeaderClasses;
    idretaintype(NSMutableDictionary)  _reusableCellClasses;

    float   _defaultRowHeight;
    float   _defaultSectionHeaderHeight;    

    TableViewNode *_rootNode;
    BOOL         _needsReload;
    DWORD        _isEnumerating;

    VisibleComponents *_visibleComponents;

    UITableViewStyle    _style;
    unsigned   _separatorStyle;
    BOOL    _isEditing;

    DWORD   _allowsSelection;
    bool    _allowsMultipleSelection, _allowsMultipleSelectionDuringEditing;

    NSInteger sectionCount();
    TableViewSection *sectionAtIndex(int idx);

    CGSize _lastSize;

    void removeReusableCell(ReusableCell *cell);
    void addReusableCell(id cell);
    void addReusableCell(TableViewRow *row);
};

@interface UITableView () {
@public
    id _dataSource;
    id<UICollectionViewDelegate> _collectionViewDelegate;
    idretain _supplementaryViewReuseQueues, _cellReuseQueues, _decorationViewReuseQueues;
    idretain _nibLayout, _nibCellsExternalObjects, _supplementaryViewsExternalObjects;
    idretain _cellNibDict, _supplementaryViewNibDict, _supplementaryViewClassDict, _cellClassDict;
    UICollectionViewData *_collectionViewData;
    idretain _layout, _allVisibleViewsDict;
    idretain _backgroundView;
    idretain _updateCompletionHandler;

    idretain _insertItems;
    idretain _deleteItems;
    idretain _reloadItems;
    idretain _moveItems;
    idretain _update;

    struct UITableViewPriv *tablePriv;
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
    }_collectionViewFlags;
}
@end

@interface UITableViewCell () {
@public
    idretaint<UIView> _contentView;
    idretaint<UIView> _curAccessoryView;
    idretaint<UIStoryboardSegueTemplate> _selectionSegueTemplate;

    BOOL _isSelected, _isHighlighted, _currentlyHighlighted;
    BOOL  _isEditing;
    unsigned _accessoryType;
    float _indentationWidth;
    UITableViewCellStyle _style;
    UITableViewCellSelectionStyle _selectionStyle;
    BOOL _showsReorderControl;
    idretaintype(UIView) _textLabel;
    idretaintype(UIView) _secondaryLabel;
    idretaintype(UIImageView) _imageView;
    idretaintype(UIView) _backgroundView, _selectedbackgroundView;
    idretain _deferredIndexPath, _indexPath;
    UIView* _accessoryView, *_editingAccessoryView;
    idretain _internalAccessoryView, _internalAccessoryButton;
    int      _internalAccessoryType;
    idretain _reuseIdentifier;
    idretain _borderView;
    int      _indentationLevel;

    int      _groupEdgeStyle;
    idretaintype(UIView) _groupEdgeView;
    idretain _cellBackgroundColor;
    idretain _cellOldBackgroundColor;
    BOOL     _cellBackgroundColorSet;

    idretain _swipeGestureRecognizer;
    idretaintype(UIView) _removeButton;

    idretaintype(UIView) _editSelectedView;
    BOOL     _editSelectedViewVisible;
}
@end