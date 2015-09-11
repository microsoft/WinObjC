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
#include "_TableCellAnimationHelper.h"

#include "UIKit/UITableView.h"
#include "UIKit/UITableViewCell.h"
#include "UIKit/UIColor.h"
#include "UIKit/UIFont.h"

#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSRunLoop.h"

#include "LinkedList.h"

#include <unordered_map>
#include <vector>
#include <algorithm>

typedef id idweak;
#define EbrFree free
#define EbrMalloc malloc
#define EbrCalloc calloc
#import <Foundation/NSNib.h>

// narsty hack
extern id _curFirstResponder;

extern "C" bool doLog;

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

class VisibleComponent : public LLTreeNode<VisibleComponent, VisibleComponent>
{
public:
    TableViewNode *_node;

    VisibleComponent(TableViewNode *node)
    {
        _node = node;
    }
    ~VisibleComponent();
};

class VisibleComponents
{
public:
    VisibleComponent _allComponents;
    UITableView* _parent;

    VisibleComponents(id parent) : _allComponents(NULL)
    {
        _parent = parent;
    }

    ~VisibleComponents()
    {
        ClearVisibleNodes();
    }

    void ClearVisibleNodes()
    {
        LLTREE_FOREACH(curComponent, (&_allComponents)) {
            _allComponents.removeChild(curComponent);
            delete curComponent;
        }
    }
    void AddVisibleNode(TableViewNode *node);
    void RemoveVisibleNode(TableViewNode *node);
    void MarkReusable(CGRect &rect, BOOL animated);
};

enum TableViewNodeType
{
    tableViewNodeRow,
    tableViewNodeExtra,
    tableViewNodeUnknown
};
class TableViewNode : public LLTreeNode<TableViewNode, TableViewNode>
{
public:
    bool  _yValid;
    float _yPos, _oldYPos;
    float _height, _oldHeight;
    idretaintype(UIView) _view;
    UITableView* _parent;
    bool  _addedToView;
    VisibleComponent *_visibleComponent;
    UITableViewRowAnimation _animation;

    virtual TableViewNodeType getNodeType()
    {
        return tableViewNodeUnknown;
    }

    TableViewNode(id parent)
    {
        _parent = parent;
        _yPos = _height = 0.0f;
        _oldYPos = _oldHeight = -1.0f;
        _view = nil;
        _yValid = false;
        _addedToView = false;
        _visibleComponent = NULL;
        _animation = UITableViewRowAnimationNone;
    }
    ~TableViewNode()
    {
        [(UIView *)(_view) removeFromSuperview];
        _view = nil;
        if ( _visibleComponent ) {
            _parent->tablePriv->_visibleComponents->RemoveVisibleNode(this);
        }
    }
    bool isInVisibleRange(CGRect &rect, BOOL animated)
    {
        if ( !animated ) {
            if ( _height == 0.0f ) return false;
            if ( _yPos + _height < rect.origin.y || 
                 _yPos > rect.origin.y + rect.size.height ) {
                return false;
            } else {
                return true;
            }
        } else {
            bool ret = false;
            if ( _yPos + _height >= rect.origin.y &&
                    _yPos <= rect.origin.y + rect.size.height ) {
                ret = true;
            } 
            if ( _addedToView ) {
                if ( _oldYPos + _oldHeight >= rect.origin.y &&
                     _oldYPos <= rect.origin.y + rect.size.height ) {
                    ret = true;
                } 
            } else {
                if ( _height == 0.0f ) return false;
            }

            return ret;
        }
    }

    virtual void nodeVisible()
    {
    }

    virtual void nodeInvisible()
    {
        removeFromView();
    }

    void addIfVisible(CGRect &rect, BOOL animated = FALSE)
    {
        if ( !isInVisibleRange(rect, animated) ) {
            return;
        }
        nodeVisible();

        CGRect frame;

        frame.origin.x = 0;
        frame.origin.y = _yPos;
        frame.size.width = rect.size.width;
        frame.size.height = _height;

        if ( _view == nil ) {
            _view = getView(frame);
        }

        if ( _view == nil ) return;

        if ( !animated ) {
            [UIView _setNestedAnimationsEnabled:FALSE];
            if ( [_view superview] != _parent ) {
                [_parent addSubview:_view];
            }
            if ( [_view isHidden] ) {
                [_view setHidden:0];
            }
            [_view setFrame:frame];
            [UIView _setNestedAnimationsEnabled:TRUE];
        } else {
            [UIView _setNestedAnimationsEnabled:FALSE];
            if ( [_view superview] != _parent ) {
                [_parent addSubview:_view];
            }
            if ( _animation != UITableViewRowAnimationNone ) {
                [_view setAlpha:0.0f];
            }
            frame.origin.y = _oldYPos;
            frame.size.height = _height;
            [_view setFrame:frame];
            [UIView _setNestedAnimationsEnabled:TRUE];
            frame.origin.y = _yPos;
            frame.size.height = _height;
            [_view setFrame:frame];
            if ( _animation != UITableViewRowAnimationNone ) {
                [_view setAlpha:1.0f];
            }
            if ( [_view isHidden] ) {
                [_view setHidden:0];
            }
        }
        _animation = UITableViewRowAnimationNone;

        if ( !_addedToView ) {
            _parent->tablePriv->_visibleComponents->AddVisibleNode(this);
            _addedToView = true;
        }
    }

    void detachView()
    {
        _view = nil;
        _parent->tablePriv->_visibleComponents->RemoveVisibleNode(this);
        _addedToView = false;
    }

    void removeFromView()
    {
        [_view removeFromSuperview];
        detachView();
    }

    virtual id getView(CGRect frame)
    {
        return nil;
    }
};

class ReusableCell
{
public:
    ReusableCell()
    {
        sourceRow = NULL;
    }
    ~ReusableCell()
    {
        _cell = nil;
        _reuseIdentifier = nil;
    }

    TableViewRow *sourceRow;
    idretain      _cell;
    idretain      _reuseIdentifier;
};

void VisibleComponents::AddVisibleNode(TableViewNode *node)
{
    VisibleComponent *newComponent = new VisibleComponent(node);
    _allComponents.addChildAfter(newComponent, NULL);
    assert(node->_visibleComponent == NULL);
    node->_visibleComponent = newComponent;
}

void VisibleComponents::RemoveVisibleNode(TableViewNode *node)
{
    VisibleComponent *component = node->_visibleComponent;
    assert(component != NULL);
    _allComponents.removeChild(component);
    node->_visibleComponent = NULL;
    delete component;
}

void VisibleComponents::MarkReusable(CGRect &rect, BOOL animated)
{
    LLTREE_FOREACH(curComponent, (&_allComponents)) {
        TableViewNode *curNode = curComponent->_node;

        if ( !curNode->isInVisibleRange(rect, animated) ) {
            curNode->nodeInvisible();
        }
    }
}

VisibleComponent::~VisibleComponent()
{
    if ( _node ) {
        _node->_visibleComponent = NULL;
    }
}
class TableViewHeaderFooter;

class TableViewSection : public TableViewNode
{
public:
    float    _yPos;
    float    _sectionHeight;
    int      _sectionIndex;

    TableViewHeaderFooter *_header;
    TableViewHeaderFooter *_footer;

    TableViewSection(id parent, int sectionIndex) : TableViewNode(parent)
    {
        _yPos = 0;
        _sectionHeight = 0;
        _sectionIndex = sectionIndex;
        _header = NULL;
        _footer = NULL;
    }
    ~TableViewSection();

    bool isSectionVisible(CGRect &rect)
    {
        if ( _yPos + _sectionHeight < rect.origin.y || 
             _yPos > rect.origin.y + rect.size.height ) {
            return false;
        } else {
            return true;
        }
    }

    int rowCount()
    {
        return childCount;
    }
    void calcRowHeights();

    TableViewRow *rowAtIndex(int idx)
    {
        return (TableViewRow *) childAtIndex(idx);
    }
};

class TableViewRow : public TableViewNode
{
public:
    ReusableCell *_reusable;
    int           _rowIndex;

    TableViewRow(id parent, int index) : TableViewNode(parent)
    {
        _rowIndex = index;
        _reusable = NULL;
    }
    ~TableViewRow();

    virtual TableViewNodeType getNodeType()
    {
        return tableViewNodeRow;
    }

    int getSectionIndex()
    {
        if ( this->parent == NULL ) return 0;
        return ((TableViewSection *) parent)->_sectionIndex;
    }
    int getSectionCount()
    {
        if ( this->parent == NULL ) return 0;
        return ((TableViewSection *) parent)->childCount;
    }

    virtual void nodeVisible()
    {
        if ( _reusable ) {
            _parent->tablePriv->removeReusableCell(_reusable);
            _reusable = NULL;
        }
    }

    virtual void nodeInvisible()
    {
        if ( !_reusable ) {
            if ( _view != nil ) {
                if ( ![_curFirstResponder respondsToSelector:@selector(isDescendantOfView:)] || ![_curFirstResponder isDescendantOfView:_view] ) {
                    _parent->tablePriv->addReusableCell(this);
                }
            }
        }
    }

    id getView(CGRect frame)
    {
        NSIndexPath* index = [NSIndexPath indexPathForRow:_rowIndex inSection:getSectionIndex()];

        [UIView _setNestedAnimationsEnabled:FALSE];
        UITableViewCell* view = [_parent->tablePriv->_dataSource tableView:_parent cellForRowAtIndexPath:index];

        if ( view == nil) {
            EbrDebugLog("Didn't return a cell!\n");
            //assert(0);
        } else {
            ((UITableViewCell*) view)->_deferredIndexPath = index;
        }

        if ( _parent->tablePriv->_style == UITableViewStyleGrouped ) {
            int groupEdgeStyle = 0x01;
            if ( _rowIndex == 0 ) {
                groupEdgeStyle |= 0x02;    //  Rounded top;
            } 
            if ( _rowIndex == getSectionCount() - 1 ) {
                groupEdgeStyle |= 0x04;
            } 
            [view _setGroupEdgeStyle:groupEdgeStyle];
        } else {
            if ( _parent->tablePriv->_separatorStyle == 1 ) {
                [view addBottomBorder:_parent];
            }
            [view _setGroupEdgeStyle:0];
        }

        if ( [_parent->tablePriv->_delegate respondsToSelector:@selector(tableView:accessoryTypeForRowWithIndexPath:)] ) {
            UITableViewCellAccessoryType accessoryType = (UITableViewCellAccessoryType) [_parent->tablePriv->_delegate tableView:_parent accessoryTypeForRowWithIndexPath:index];
            [view setAccessoryType:accessoryType];
        }

        if ( [_parent->tablePriv->_delegate respondsToSelector:@selector(tableView:willDisplayCell:forRowAtIndexPath:)] ) {
            [_parent->tablePriv->_delegate tableView:_parent willDisplayCell:view forRowAtIndexPath:index];
        }

        [view setSelected:FALSE animated:FALSE];
        [view setHighlighted:FALSE animated:FALSE];
        if ( [_parent->_indexPathsForSelectedItems containsObject:index] ) {
            [view setSelected:TRUE animated:FALSE];
        }
        if ( [_parent->_indexPathsForHighlightedItems containsObject:index] ) {
            [view setHighlighted:TRUE animated:FALSE];
        }
        [view _setEditingMode:_parent->tablePriv->_isEditing animated:FALSE];
        [UIView _setNestedAnimationsEnabled:TRUE];
        [view setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleBottomMargin];

        return view;
    }
};

class TableViewHeaderFooter : public TableViewNode
{
public:
    idretain _string;
    TableViewSection *_parentSection;
    bool     _isHeader;

    TableViewHeaderFooter(id parent, TableViewSection *parentSection, id string, float height, bool isHeader) : TableViewNode(parent)
    {
        _string = string;
        _height = height;
        _parentSection = parentSection;
        _isHeader = isHeader;
    }
    id getView(CGRect frame)
    {
        id view = nil;
        if ( _isHeader ) {
            if ( [_parent->tablePriv->_dataSource respondsToSelector:@selector(tableView:viewForHeaderInSection:)] ) {
                view = [_parent->tablePriv->_dataSource tableView:_parent viewForHeaderInSection:_parentSection->_sectionIndex];
            } 
        } else {
            if ( [_parent->tablePriv->_dataSource respondsToSelector:@selector(tableView:viewForFooterInSection:)] ) {
                view = [_parent->tablePriv->_dataSource tableView:_parent viewForFooterInSection:_parentSection->_sectionIndex];
            } 
        }

        if ( view == nil ) {
            id string = _string;

            if ( string == nil ) {
                if ( _isHeader ) {
                    if ( [_parent->tablePriv->_dataSource respondsToSelector:@selector(tableView:titleForHeaderInSection:)] ) {
                        string = [_parent->tablePriv->_dataSource tableView:_parent titleForHeaderInSection:_parentSection->_sectionIndex];
                    }
                } else {
                    if ( [_parent->tablePriv->_dataSource respondsToSelector:@selector(tableView:titleForFooterInSection:)] ) {
                        string = [_parent->tablePriv->_dataSource tableView:_parent titleForFooterInSection:_parentSection->_sectionIndex];
                    }
                }
            }

            if ( string != nil ) {
                view = [[[UITableViewCell alloc] initWithFrame:frame] autorelease];
                [view setText:string];
                if ( GetCACompositor()->isTablet() ) {
                    [view setFont:[UIFont boldSystemFontOfSize:17.0f]];
                } else {
                    [view setFont:[UIFont boldSystemFontOfSize:12.0f]];
                }
                [view setUserInteractionEnabled:FALSE];

                //  Setup table cell background gradient
                if ( _parent->tablePriv->_style == UITableViewStyleGrouped ) {
                    [view setTextColor:[UIColor darkGrayColor]];
                    [view _setGroupEdgeStyle:0x800];
                } else {
                    id backgroundGradient = [[UIImage imageNamed:@"/img/navgradient.png"] stretchableImageWithLeftCapWidth:1 topCapHeight:0];
                    id imageView = [[[UIImageView alloc] initWithImage:backgroundGradient] autorelease];
                    [view setBackgroundView:imageView];
                    [view setTextColor:[UIColor whiteColor]];

                    id label = [view textLabel];
                    [label setShadowColor:[UIColor blackColor]];
                    CGSize shadowOffset = { 1.0f, 1.0f };
                    [label setShadowOffset:shadowOffset];
                }
            }
        }

        [view setAutoresizingMask:UIViewAutoresizingFlexibleWidth];

        return view;
    }
};

TableViewSection::~TableViewSection()
{
    if ( _header ) {
        delete _header;
    }
    if ( _footer ) {
        delete _footer;
    }
}

TableViewRow::~TableViewRow()
{
    if ( _reusable ) {
        _reusable->sourceRow = NULL;
    }
}

void TableViewSection::calcRowHeights()
{
    int curRowIdx = 0;

    LLTREE_FOREACH(curNode, (TableViewNode *) this) {
        TableViewRow *curRow = (TableViewRow *) curNode;
        id index = [NSIndexPath indexPathForRow:curRowIdx inSection:_sectionIndex];
        float cellHeight = _parent->tablePriv->_defaultRowHeight;

        if ( [_parent->tablePriv->_delegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)] ) {
            cellHeight = [_parent->tablePriv->_delegate tableView:_parent heightForRowAtIndexPath:index];
        }

        curRow->_oldHeight = curRow->_height;
        curRow->_height = cellHeight;
        curRow->_rowIndex = curRowIdx;

        curRowIdx ++;
    }
}
int UITableViewPriv::sectionCount()
{
    return _rootNode->childCount;
}

TableViewSection *UITableViewPriv::sectionAtIndex(int idx)
{
    return (TableViewSection *) _rootNode->childAtIndex(idx);
}

void UITableViewPriv::addReusableCell(TableViewRow *row)
{
    NSString* reuse = [row->_view reuseIdentifier];
    assert(reuse != nil);

    auto& arr = _reusableCells[[reuse UTF8String]];

    if ( arr.size() <= 5 ) {
        ReusableCell *newReusableCell = new ReusableCell();

        newReusableCell->sourceRow = row;
        newReusableCell->_cell = row->_view;
        [newReusableCell->_cell setHidden:TRUE];
        newReusableCell->_reuseIdentifier = reuse;
        row->_reusable = newReusableCell;
        arr.push_back(newReusableCell);
    } else {
        row->removeFromView();
    }
}

void UITableViewPriv::addReusableCell(id cell)
{
    NSString* reuse = [cell reuseIdentifier];
    assert(reuse != nil);

    auto& arr = _reusableCells[[reuse UTF8String]];

    if ( arr.size() <= 5 ) {
        ReusableCell *newReusableCell = new ReusableCell();

        newReusableCell->sourceRow = NULL;
        newReusableCell->_cell = cell;
        [newReusableCell->_cell setHidden:TRUE];
        newReusableCell->_reuseIdentifier = reuse;
        arr.push_back(newReusableCell);
    } else {
        [cell removeFromSuperview];
    }
}

void UITableViewPriv::removeReusableCell(ReusableCell *cell)
{
    id reuse = cell->_reuseIdentifier;
    assert(reuse != nil);

    auto it = _reusableCells.find([reuse UTF8String]);
    if ( it != _reusableCells.end() ) {
        auto& arr = it->second;
        arr.erase(std::remove(arr.begin(), arr.end(), cell), arr.end());
    }

    delete cell;
}

@implementation UITableView {
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

    // EMPTY -----------------------------------------------
    - (CGRect)rectForHeaderInSection:(NSInteger)section { }
    - (CGRect)rectForFooterInSection:(NSInteger)section { }
    - (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated { }
    - (void)moveRowAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath { }
    // -----------------------------------------------------

    static void initInternal(UITableView* self)
    {
        auto& priv = self->tablePriv;

        priv = new UITableViewPriv;
        priv->_rootNode = new TableViewNode(self);
        priv->_visibleComponents = new VisibleComponents(self);
        priv->_needsReload = FALSE;
        priv->_isEnumerating = FALSE;
        priv->_isEditing = FALSE;
        priv->_allowsSelection = TRUE;
        priv->_style = UITableViewStylePlain;
        priv->_lastSize.width = priv->_lastSize.height = 0.f;

        priv->_allowsMultipleSelection = priv->_allowsMultipleSelectionDuringEditing = FALSE;

        priv->_delegate = nil;
        priv->_dataSource = nil;

        priv->_defaultRowHeight = 50.0f;
        priv->_defaultSectionHeaderHeight = 22.0f;
        priv->_footerYPos = 0.f;
        priv->_reusableCellNibs = [NSMutableDictionary new];
        priv->_reusableHeaderClasses = [NSMutableDictionary new];
        priv->_reusableCellClasses = [NSMutableDictionary new];
        self->_indexPathsForSelectedItems = [NSMutableSet new];
        self->_indexPathsForHighlightedItems = [NSMutableSet new];
        priv->_separatorStyle = 1;
    }
    
    -(instancetype) initWithFrame:(CGRect)pos style:(UITableViewStyle)style {
        [super initWithFrame:pos];
        [super setDelegate:self];

        initInternal(self);
        tablePriv->_style = style;

        [self setBackgroundColor:[UIColor whiteColor]];

        return self;
    }

    -(id) initWithCoder:(NSCoder*)coder {
        [super initWithCoder:coder];
        [super setDelegate:self];
        //[self setBackgroundColor:[UIColor whiteColor]];

        initInternal(self);
        tablePriv->_style = (UITableViewStyle) [coder decodeInt32ForKey:@"UIStyle"];
        tablePriv->_separatorStyle = [coder decodeInt32ForKey:@"UISeparatorStyle"];

        if ( [coder containsValueForKey:@"UIAllowsSelection"] ) {
            tablePriv->_allowsSelection = [coder decodeInt32ForKey:@"UIAllowsSelection"];
        }
        if ( [coder containsValueForKey:@"UIAllowsMultipleSelection"] ) {
            tablePriv->_allowsMultipleSelection = [coder decodeInt32ForKey:@"UIAllowsMultipleSelection"] != 0;
        }
        if ( [coder containsValueForKey:@"UIAllowsMultipleSelectionDuringEditing"] ) {
            tablePriv->_allowsMultipleSelectionDuringEditing = [coder decodeInt32ForKey:@"UIAllowsMultipleSelectionDuringEditing"] != 0;
        }
        if ( [coder containsValueForKey:@"UIRowHeight"] ) {
            tablePriv->_defaultRowHeight = [coder decodeFloatForKey:@"UIRowHeight"];
        }
        if ( [coder containsValueForKey:@"UITableViewCellPrototypeNibs"] ) {
            tablePriv->_reusableCellNibs = [coder decodeObjectForKey:@"UITableViewCellPrototypeNibs"];
        }
        if ( [coder containsValueForKey:@"UITableViewCellPrototypeNibExternalObjects"] ) {
            tablePriv->_externalObjects = [coder decodeObjectForKey:@"UITableViewCellPrototypeNibExternalObjects"];
        }
        id headerView = [coder decodeObjectForKey:@"UITableHeaderView"];
        if ( headerView != nil ) {
            [self setTableHeaderView:headerView];
        }
        id footerView = [coder decodeObjectForKey:@"UITableFooterView"];
        if ( footerView != nil ) {
            [self setTableFooterView:footerView];
        }

        return self;
    }

    -(instancetype) initWithFrame:(CGRect)pos {
        [super initWithFrame:pos];
        [super setDelegate:self];

        [self setBackgroundColor:[UIColor whiteColor]];

        initInternal(self);

        return self;
    }

    -(void) setSeparatorStyle:(unsigned)style {
        tablePriv->_separatorStyle = style;
    }

    -(void) setDelegate:(id)delegate {
        tablePriv->_delegate = delegate;
    }

    -(id) delegate {
        return tablePriv->_delegate;
    }

    -(void) setDataSource:(id<UITableViewDataSource>)dataSource {
        tablePriv->_dataSource = dataSource;
        tablePriv->_needsReload = TRUE;

        [self setNeedsLayout];
    }

    -(id<UITableViewDataSource>) dataSource {
        return tablePriv->_dataSource;
    }

    -(void) setTableHeaderView:(UIView*)view {
        if ( tablePriv->_headerView != nil ) [tablePriv->_headerView removeFromSuperview];
        tablePriv->_headerView = view;

        if ( tablePriv->_headerView != nil ) {
            [self addSubview:tablePriv->_headerView];

            CGRect headerBounds;            
            headerBounds = [tablePriv->_headerView bounds];
            headerBounds.origin.x = 0;
            headerBounds.origin.y = 0;
            [tablePriv->_headerView setFrame:headerBounds];
            [tablePriv->_headerView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleBottomMargin];
        }
        [self setNeedsLayout];
    }

    -(UIView*) backgroundView {
        return tablePriv->_backgroundView;
    }

    -(UIView*) tableHeaderView {
        return tablePriv->_headerView;
    }

    -(void) setTableFooterView:(UIView*)view {
        if ( tablePriv->_footerView != nil ) [tablePriv->_footerView removeFromSuperview];
        tablePriv->_footerView = view;

        if ( tablePriv->_footerView != nil ) {
            [self addSubview:tablePriv->_footerView];
        }
        [self setNeedsLayout];
    }

    -(UIView*) tableFooterView {
        return tablePriv->_footerView;
    }

    -(void) setAllowsSelectionDuringEditing:(BOOL)canSelect {
    }
    
    -(void) setAllowsSelection:(BOOL)canSelect {
        tablePriv->_allowsSelection = canSelect;
    }

    -(BOOL) allowsSelection {
        return tablePriv->_allowsSelection;
    }

    -(void) layoutIfNeeded {
        //  Explicitly reload data if layoutIfNeeded is explicitly called
        if ( tablePriv->_needsReload ) {
            [self reloadData];
        }
        [super layoutIfNeeded];
    }

    static void showVisibleCells(UITableView* self, BOOL animated = FALSE)
    {
        auto priv = self->tablePriv;
        priv->_isEnumerating ++;

        CGPoint scrollPoint;
        scrollPoint = [self contentOffset];

        CGRect bounds;
        bounds = [self bounds];

        if ( priv->_backgroundView != nil ) {
            [self sendSubviewToBack:(UIView *)(priv->_backgroundView)];

            CGRect backgroundPos = bounds;
            [(UIView*)(priv->_backgroundView) setFrame:backgroundPos];
        }

        if ( priv->_headerView != nil ) {
            CGRect headerBounds;            
            headerBounds = [(UIView*)(priv->_headerView) bounds];
            headerBounds.origin.x = 0;
            headerBounds.origin.y = 0;
            headerBounds.size.width = bounds.size.width;
            [(UIView*)(priv->_headerView) setFrame:headerBounds];
        }
        int curSectionIndex = 0;

        CGRect visibleRect;
        visibleRect.origin.x = 0.0f;
        visibleRect.origin.y = scrollPoint.y;
        visibleRect.size.width = bounds.size.width;
        visibleRect.size.height = bounds.size.height;

        id delegate = priv->_delegate;
        id dataSource = priv->_dataSource;

        priv->_visibleComponents->MarkReusable(visibleRect, animated);

        LLTREE_FOREACH(curNode, priv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            if ( curSection->isSectionVisible(visibleRect) ) {
                curSection->_header->addIfVisible(visibleRect);

                LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                    TableViewRow *curRow = (TableViewRow *) curRowNode;

                    curRow->addIfVisible(visibleRect, animated);
                }

                curSection->_footer->addIfVisible(visibleRect);
            }
        }

        if ( priv->_footerView != nil ) {
            CGRect footerBounds;            
            footerBounds = [(UIView*)(priv->_footerView) bounds];
            footerBounds.origin.x = 0;
            footerBounds.origin.y = priv->_footerYPos;
            footerBounds.size.width = bounds.size.width;
            [(UIView *)(priv->_footerView) setFrame:footerBounds];
        }
        priv->_isEnumerating --;
    }

    static void calcCellPositions(UITableView* self)
    {
        auto priv = self->tablePriv;
        CGSize contentSize = { 0, 0 };      

        float y = 0.0f;

        if ( priv->_headerView != nil ) {
            CGRect headerBounds;            
            headerBounds = [(UIView *)(priv->_headerView) bounds];
            y = headerBounds.size.height;
        }

        if ( priv->_style == UITableViewStyleGrouped ) y += 10.0f;

        //  Grab section data
        LLTREE_FOREACH(curNode, priv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            curSection->_yPos = y;

            curSection->_header->_yPos = y;
            y += curSection->_header->_height;

            int curIndex = 0;

            //  Grab rows
            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_yValid ) {
                    curRow->_oldYPos = curRow->_yPos;
                } else {
                    curRow->_oldYPos = y;
                }
                curRow->_yPos = y;
                curRow->_yValid = true;

                if ( curRow->_view ) {
                    if ( curRow->_rowIndex != curIndex ) {
                        UITableViewCell* rowView = (UITableViewCell *)(curRow->_view);
                        id index = [NSIndexPath indexPathForRow:curIndex inSection:curSection->_sectionIndex];
                        if ( rowView->_deferredIndexPath != nil ) {
                            rowView->_deferredIndexPath = index;
                        } else {
                            rowView->_indexPath = index;
                        }
                    }
                }
                curRow->_rowIndex = curIndex;

                y += curRow->_height;

                curIndex ++;
            }
            curSection->_footer->_yPos = y;
            y += curSection->_footer->_height;

            curSection->_sectionHeight = y - curSection->_yPos;

            if ( priv->_style == UITableViewStyleGrouped ) y += 10.0f;
        }

        if ( priv->_footerView != nil ) {
            CGRect footerBounds;            
            footerBounds = [(UIView *)(priv->_footerView) bounds];
            priv->_footerYPos = y;
            y += footerBounds.size.height;
        }

        contentSize.width = 0;
        contentSize.height = y;

        [self setContentSize:contentSize];
        [self setNeedsLayout];
    }

    -(NSArray*) visibleCells {
        id ret = [NSMutableArray array];

        CGPoint scrollPoint;
        scrollPoint = [self contentOffset];

        CGRect bounds;
        bounds = [self bounds];

        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_yPos + curRow->_height  < scrollPoint.y || 
                     curRow->_yPos                       > scrollPoint.y + bounds.size.height ) {
                } else {
                    if ( curRow->_view != nil ) {
                        [ret addObject:curRow->_view];
                    }
                }
            }
        }

        return ret;
    }

    -(NSArray*) indexPathsForVisibleRows {
        id ret = [NSMutableArray array];

        CGPoint scrollPoint;
        scrollPoint = [self contentOffset];

        CGRect bounds;
        bounds = [self bounds];

        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_yPos + curRow->_height  < scrollPoint.y || 
                     curRow->_yPos                       > scrollPoint.y + bounds.size.height ) {
                } else {
                    if ( curRow->_view != nil ) {
                        id indexPath = [curRow->_view indexPath];
                        if ( indexPath != nil ) [ret addObject:indexPath];
                    }
                }
            }
        }

        return ret;
    }

    -(NSIndexPath*) indexPathForRowAtPoint:(CGPoint)point {
        int curSectionIndex = 0;
        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            int curRowIndex = 0;
            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_yPos + curRow->_height  > point.y &&
                     curRow->_yPos                       <= point.y ) {
                    id index = [NSIndexPath indexPathForRow:curRowIndex inSection:curSectionIndex];

                    return index;
                }

                curRowIndex ++;
            }

            curSectionIndex ++;
        }

        return nil;
    }

    -(NSIndexPath*) indexPathsForRowsInRect:(CGRect)rect {
        id ret = [NSMutableArray array];
        int curSectionIndex = 0;
        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            int curRowIndex = 0;
            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_yPos + curRow->_height  > rect.origin.y &&
                     curRow->_yPos                       <= rect.origin.y + rect.size.height ) {
                    id index = [NSIndexPath indexPathForRow:curRowIndex inSection:curSectionIndex];
                    [ret addObject:index];
                }

                curRowIndex ++;
            }

            curSectionIndex ++;
        }

        return ret;
    }

    -(NSInteger) numberOfSections {
        return tablePriv->sectionCount();
    }

    -(void) reloadRowsAtIndexPaths:(NSArray*)paths withRowAnimation:(UITableViewRowAnimation)animationType {
        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView beginAnimations:@"CellMoving" context:nil];
            [UIView setAnimationDuration:0.4f];
        }

        unsigned count = [paths count];

        _TableCellAnimationHelper* cleanupHelper = [_TableCellAnimationHelper new];
        cleanupHelper->_numCellsToBeRemoved = 0;
        cleanupHelper->_cellsToBeRemoved = (id *) EbrMalloc(sizeof(id) * count);

        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView setAnimationDidStopSelector:@selector(animationFinished)];
            [UIView setAnimationDelegate:cleanupHelper];
        }

        for ( unsigned i = 0; i < count; i ++ ) {
            NSIndexPath* path = [paths objectAtIndex:i];

            int section = [path section];
            int row = [path row];

            if ( section >= tablePriv->sectionCount() || row >= tablePriv->sectionAtIndex(section)->rowCount()) {
                assert(0);
            }

            //  Reload the row
            TableViewRow *curRow = tablePriv->sectionAtIndex(section)->rowAtIndex(row);

            if ( curRow->_view != nil ) {
                [curRow->_view setAlpha:0.0f];
                cleanupHelper->_cellsToBeRemoved[cleanupHelper->_numCellsToBeRemoved ++ ] = curRow->_view;
                [curRow->_view retain];
                curRow->detachView();
            }
            if ( curRow->_reusable ) {
                tablePriv->removeReusableCell(curRow->_reusable);
                curRow->_reusable = NULL;
            }
            float cellHeight = tablePriv->_defaultRowHeight;

            if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)] ) {
                cellHeight = [tablePriv->_delegate tableView:self heightForRowAtIndexPath:path];
            }

            curRow->_animation = animationType;
            curRow->_oldHeight = curRow->_height;
            curRow->_height = cellHeight;
        }

        calcCellPositions(self);
        showVisibleCells(self, animationType != UITableViewRowAnimationNone);

        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView commitAnimations];
        }
    }

    static void recalcTableSize(UITableView* self, bool changedWidth)
    {
        auto priv = self->tablePriv;

        // Don't recalculate the row heights unless we change the width of the
        // table.
        if ( changedWidth ) {
            LLTREE_FOREACH(curNode, priv->_rootNode) {
                TableViewSection *curSection = (TableViewSection *) curNode;
                curSection->calcRowHeights();
            }
        }

        // This was added for iphoneGeo but it breaks UICatalog and seems wrong.
        // I'm going to leave this in because we'll no doubt need it again but we
        // need to understand the correct way.
        //priv->_needsReload = TRUE;
        calcCellPositions(self);
    }

    -(void) setFrame:(CGRect)frame {
        [super setFrame:frame];

        if ( !tablePriv ) return;

        if ( [self window] == nil ) {
            //  We shouldn't try to re-layout the tableview if it's not part of the view heiarchy
            return;
        }

        if ( frame.size.width != tablePriv->_lastSize.width && frame.size.height != tablePriv->_lastSize.height )
        {
            bool changedWidth = frame.size.width != tablePriv->_lastSize.width;
            tablePriv->_lastSize = frame.size;
            recalcTableSize(self, changedWidth);
        }
    }

    -(void) reloadData {
        if ( tablePriv->_isEnumerating ) {
            tablePriv->_needsReload = TRUE;
            [self _setShouldLayout];
            return;
        }

        NSRunLoop* mainRunLoop = [NSRunLoop mainRunLoop];
        NSRunLoop* currentRunLoop = [NSRunLoop currentRunLoop];
        if ( mainRunLoop != currentRunLoop ) {
            [self performSelectorOnMainThread:@selector(reloadData) withObject:nil waitUntilDone:TRUE];
            return;
        }

        tablePriv->_needsReload = FALSE;
        tablePriv->_isEnumerating ++;
        [_indexPathsForSelectedItems removeAllObjects];
        [_indexPathsForHighlightedItems removeAllObjects];
        tablePriv->_visibleComponents->ClearVisibleNodes();

        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_view != nil ) {
                    if ( curRow->_reusable == NULL ) {
                        tablePriv->addReusableCell(curRow->_view);
                    } else {
                        curRow->_reusable->sourceRow = NULL;
                    }
                    [curRow->_view removeFromSuperview];
                    curRow->_view = nil;
                }
                curSection->removeChild(curRow);
                delete curRow;
            }

            tablePriv->_rootNode->removeChild(curSection);
            delete curSection;
        }

        int numSections = 0;

        id<UITableViewDataSource> dataSource = tablePriv->_dataSource;

        if ( dataSource != nil ) {
            if ( [dataSource respondsToSelector:@selector(numberOfSectionsInTableView:)] ) {
                numSections = [dataSource numberOfSectionsInTableView:self];
            } else {
                numSections = 1;
            }

            NSArray* sectionTitles = nil;
            
            if ( [dataSource respondsToSelector:@selector(sectionIndexTitlesForTableView:)] ) {
                sectionTitles = [dataSource sectionIndexTitlesForTableView:self];
            }

            //  Grab section data
            for ( int i = 0; i < numSections; i ++ ) {
                TableViewSection *curSection = new TableViewSection(self, i);

                tablePriv->_rootNode->addChildAfter(curSection, NULL);

                int numRows = [dataSource tableView:self numberOfRowsInSection:i];
                if ( numRows < 0 ) {
                    EbrDebugLog("numRows < 0!\n");
                    numRows = 0;
                }

                float headerHeight = 0.0f;
                float defaultHeight = 25.0f;

                if ( GetCACompositor()->isTablet() ) {
                    defaultHeight = 44.0f;
                }

                NSString* headerString = nil;
                if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForHeaderInSection:)] ) {
                    headerHeight = [tablePriv->_delegate tableView:self heightForHeaderInSection:i];
                    if ( headerHeight == -1.0f ) {
                        headerHeight = defaultHeight;
                    }
                } 

                if ( [dataSource respondsToSelector:@selector(tableView:titleForHeaderInSection:)] ) {
                    headerString = [dataSource tableView:self titleForHeaderInSection:i];
                    if ( headerString != nil && headerHeight <= 0.0f ) {
                        headerHeight = defaultHeight;
                    }
                } else if ( sectionTitles != nil ) {
                    headerString = [sectionTitles objectAtIndex:i];
                    if ( headerString != nil && headerHeight <= 0.0f ) {
                        headerHeight = defaultHeight;
                    }
                }

                curSection->_header = new TableViewHeaderFooter(self, curSection, headerString, headerHeight, true);

                //  Grab rows
                for ( int j = 0; j < numRows; j ++ ) {
                    TableViewRow *newRow = new TableViewRow(self, j);
                    curSection->addChildAfter(newRow, NULL);
                }

                curSection->calcRowHeights();

                float footerHeight = 0.0f;
                id footerString = nil;

                if ( tablePriv->_style == UITableViewStyleGrouped ) {
                    if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForFooterInSection:)] ) {
                        footerHeight = [tablePriv->_delegate tableView:self heightForFooterInSection:i];
                        if ( footerHeight == -1.0f ) {
                            footerHeight = 25.0f;
                        }
                    } 

                    if ( [dataSource respondsToSelector:@selector(tableView:titleForFooterInSection:)] ) {
                        footerString = [dataSource tableView:self titleForFooterInSection:i];
                        if ( footerString != nil && footerHeight <= 0.0f ) {
                            footerHeight = 25.0f;
                        }
                    }
                }

                curSection->_footer = new TableViewHeaderFooter(self, curSection, footerString, footerHeight, false);
            }
        }

        calcCellPositions(self);        

        CGRect curBounds;
        curBounds = [self bounds];
        tablePriv->_lastSize = curBounds.size;

        [self _clampOffset];

        tablePriv->_isEnumerating --;
    }

    -(int) selectedRow {
        assert(0);
        return -1;
    }

    -(id) dequeueReusableCellWithIdentifier:(NSString*)identifier {
        auto it = tablePriv->_reusableCells.find([identifier UTF8String]);

        if ( it != tablePriv->_reusableCells.end() ) {
            auto& arr = it->second;
            if ( arr.size() > 0 ) {
                ReusableCell *reusable = arr.back();
                TableViewRow *row = reusable->sourceRow;

                arr.pop_back();

                if ( row ) {
                    row->detachView();
                    row->_reusable = NULL;
                }

                id ret = reusable->_cell;
                [ret retain];
                [ret prepareForReuse];

                delete reusable;

                return [ret autorelease];
            }

            if ( arr.size() <= 1 ) {
                tablePriv->_reusableCells.erase([identifier UTF8String]);
            }
        }

        id classId = [tablePriv->_reusableCellClasses objectForKey:identifier];
        if ( classId != nil ) {
            return [[[classId alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier] autorelease];
        }
        id reusableNib = [tablePriv->_reusableCellNibs objectForKey:identifier];
        if ( reusableNib != nil ) {
            id proxies = [tablePriv->_externalObjects objectForKey:identifier];
            id objects = [reusableNib instantiateWithOwner:self options:nil proxies:proxies];
            id ret = [[objects objectAtIndex:0] retain];
            [ret _setReuseIdentifier:identifier];
            return [ret autorelease];
        }

        return nil;
    }

    -(id) dequeueReusableCellWithIdentifier:(NSString*)identifier forIndexPath:(NSIndexPath*)indexPath {
        auto it = tablePriv->_reusableCells.find([identifier UTF8String]);

        if ( it != tablePriv->_reusableCells.end() ) {
            auto& arr = it->second;
            if ( arr.size() > 0 ) {
                ReusableCell *reusable = arr.back();
                TableViewRow *row = reusable->sourceRow;

                arr.pop_back();

                if ( row ) {
                    row->detachView();
                    row->_reusable = NULL;
                }

                id ret = reusable->_cell;
                [ret retain];
                [ret prepareForReuse];

                delete reusable;

                return [ret autorelease];
            }

            if ( arr.size() <= 1 ) {
                tablePriv->_reusableCells.erase([identifier UTF8String]);
            }
        }

        id classId = [tablePriv->_reusableCellClasses objectForKey:identifier];
        if ( classId != nil ) {
            id ret = [[classId alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
            return [ret autorelease];
        }
        id reusableNib = [tablePriv->_reusableCellNibs objectForKey:identifier];
        if ( reusableNib != nil ) {
            id proxies = [tablePriv->_externalObjects objectForKey:identifier];
            id objects = [reusableNib instantiateWithOwner:self options:nil proxies:proxies];
            id ret = [[objects objectAtIndex:0] retain];
            [ret _setReuseIdentifier:identifier];
            return [ret autorelease];
        }

        return [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }

    -(void) setRowHeight:(float)rowHeight {
        tablePriv->_defaultRowHeight = rowHeight;
    }

    -(float) rowHeight {
        return tablePriv->_defaultRowHeight;
    }

    -(void) setSeparatorColor:(UIColor*)color {
    }

    -(void) setSectionHeaderHeight:(float)height {
        tablePriv->_defaultSectionHeaderHeight = height;
    }

    -(float) sectionHeaderHeight {
        return tablePriv->_defaultSectionHeaderHeight;
    }

    -(void) setSectionFooterHeight:(float)height {
    }

    -(void) setSectionIndexMinimumDisplayRowCount:(unsigned)numRows {
    }

    -(BOOL) highlightItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition notifyDelegate:(BOOL)notifyDelegate {
        BOOL shouldHighlight = YES;
        if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:shouldHighlightRowAtIndexPath:)] ) {
            shouldHighlight = [tablePriv->_delegate tableView:self shouldHighlightRowAtIndexPath:indexPath];
        }

        if (shouldHighlight) {
            UITableViewCell* highlightedCell = [self cellForRowAtIndexPath:indexPath];
            [highlightedCell setHighlighted:YES];
            [_indexPathsForHighlightedItems addObject:indexPath];

            if (scrollPosition != UITableViewScrollPositionNone) {
                [self scrollToRowAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
            }

            if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:didHighlightRowAtIndexPath:)] ) {
                [tablePriv->_delegate tableView:self didHighlightRowAtIndexPath:indexPath];
            }
        }
        return shouldHighlight;
    }

    -(BOOL) unhighlightItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
        return [self unhighlightItemAtIndexPath:indexPath animated:animated notifyDelegate:notifyDelegate shouldCheckHighlight:NO];
    }

    -(BOOL) unhighlightItemAtIndexPath:(id)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate shouldCheckHighlight:(BOOL)check {
        if ([_indexPathsForHighlightedItems containsObject:indexPath]) {
            UITableViewCell* highlightedCell = [self cellForRowAtIndexPath:indexPath];
            // iOS6 does not notify any delegate if the cell was never highlighted (setHighlighted overwritten) during touchMoved
            if (check && ![highlightedCell isHighlighted]) {
                return NO;
            }

            // if multiple selection or not unhighlighting a selected item we don't perform any op
            if ([highlightedCell isHighlighted] && [_indexPathsForSelectedItems containsObject:indexPath]) {
                [highlightedCell setHighlighted:YES];
            } else {
                [highlightedCell setHighlighted:NO];
            }

            [_indexPathsForHighlightedItems removeObject:indexPath];

            if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:didUnhighlightRowAtIndexPath:)] ) {
                [tablePriv->_delegate tableView:self didUnhighlightRowAtIndexPath:indexPath];
            }

            return YES;
        }
        return NO;
    }

    -(void) _cellSelectedDown:(UITableViewCell*)cell {
        // reset touching state vars
        _touchingIndexPath = nil;
        _currentIndexPath = nil;

        NSIndexPath* indexPath = [cell indexPath];

        if (indexPath && [self allowsSelection] ) {
            if (![self highlightItemAtIndexPath:indexPath animated:YES scrollPosition:UITableViewScrollPositionNone notifyDelegate:YES])
                return;

            _touchingIndexPath = indexPath;
            _currentIndexPath = indexPath;

            if (![self _currentlyAllowsMultipleSelection] ) {
                // temporally unhighlight background on touchesBegan (keeps selected by _indexPathsForSelectedItems)
                // single-select only mode only though
                id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
                if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:_touchingIndexPath]) {
                    // iOS6 UICollectionView deselects cell without notification
                    id selectedCell = [self cellForRowAtIndexPath:tempDeselectIndexPath];
                    [selectedCell setSelected:NO];
                }
            }
        }
    }

    -(void) cellTouchCancelled {
        // turn on ALL the *should be selected* cells (iOS6 UICollectionView does no state keeping or other fancy optimizations)
        // there should be no notifications as this is a silent "turn everything back on"
        for (NSIndexPath* tempDeselectedIndexPath in [[_indexPathsForSelectedItems copy] autorelease]) {
            UITableViewCell* selectedCell = [self cellForRowAtIndexPath:tempDeselectedIndexPath];
            [selectedCell setSelected:YES];
        }
    }

    -(void) _cellSelectedCancelled:(UITableViewCell*)cell {
        // do not mark touchingIndexPath as nil because whoever cancelled this touch will need to signal a touch up event later
        if (_touchingIndexPath) {
            // first unhighlight the touch operation
            [self unhighlightItemAtIndexPath:_touchingIndexPath animated:YES notifyDelegate:YES];
            [self cellTouchCancelled];
            _touchingIndexPath = nil;
        }
    }

    -(void) _cellSelectedUp:(UITableViewCell*)cell {
        if ( _touchingIndexPath ) {
            // first unhighlight the touch operation
            [self unhighlightItemAtIndexPath:_touchingIndexPath animated:YES notifyDelegate:YES];

            id indexPath = [cell indexPath];
            if ( [indexPath isEqual:_touchingIndexPath]) {
                [self userSelectedItemAtIndexPath:indexPath];
            } else if (![self _currentlyAllowsMultipleSelection]) {
                id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
                if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:_touchingIndexPath]) {
                    [self cellTouchCancelled];
                }
            }

            // for pedantic reasons only - always set to nil on touchesBegan
            _touchingIndexPath = nil;
            _currentIndexPath = nil;
        }
    }

    -(void) userSelectedItemAtIndexPath:(NSIndexPath*)indexPath {
        if ( [self _currentlyAllowsMultipleSelection] && [_indexPathsForSelectedItems containsObject:indexPath]) {
            [self deselectItemAtIndexPath:indexPath animated:YES notifyDelegate:YES];
        } else if ( [self allowsSelection] ) {
            [self selectItemAtIndexPath:indexPath animated:YES scrollPosition:UITableViewScrollPositionNone notifyDelegate:YES];
        }
    }

    /* annotate with type */ -(id) selectItemAtIndexPath:(id)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition notifyDelegate:(BOOL)notifyDelegate {
        if ( [self _currentlyAllowsMultipleSelection] && [_indexPathsForSelectedItems containsObject:indexPath]) {
            if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:willDeselectRowAtIndexPath:)] ) {
                indexPath = [tablePriv->_delegate tableView:self willDeselectRowAtIndexPath:indexPath];
            }

            if (indexPath) {
                [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:notifyDelegate];
            }
        } else {
            // either single selection, or wasn't already selected in multiple selection mode
            if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:willSelectRowAtIndexPath:)] ) {
                indexPath = [tablePriv->_delegate tableView:self willSelectRowAtIndexPath:indexPath];
            }

            if ( ![self _currentlyAllowsMultipleSelection]) {
                // now unselect the previously selected cell for single selection
                id tempDeselectIndexPath = [_indexPathsForSelectedItems anyObject];
                if (tempDeselectIndexPath && ![tempDeselectIndexPath isEqual:indexPath]) {
                    [self deselectItemAtIndexPath:tempDeselectIndexPath animated:YES notifyDelegate:YES];
                }
            }

            if (indexPath) {
                UITableViewCell* selectedCell = [self cellForRowAtIndexPath:indexPath];
                [selectedCell setSelected:YES];

                [_indexPathsForSelectedItems addObject:indexPath];

                [selectedCell performSelectionSegue];

                if (scrollPosition != UITableViewScrollPositionNone) {
                    [self scrollToRowAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
                }

                if (notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:didSelectRowAtIndexPath:)] ) {
                    [tablePriv->_delegate tableView:self didSelectRowAtIndexPath:indexPath];
                }
            }
        }

        return self;
    }

    /* annotate with type */ -(id) deselectItemAtIndexPath:(id)indexPath animated:(BOOL)animated notifyDelegate:(BOOL)notifyDelegate {
        // deselect only relevant during multi mode
        if ( notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:willDeselectRowAtIndexPath:)] ) {
            indexPath = [tablePriv->_delegate tableView:self willDeselectRowAtIndexPath:indexPath];
        }

        if (indexPath && [_indexPathsForSelectedItems containsObject:indexPath]) {
            id selectedCell = [self cellForRowAtIndexPath:indexPath];
            if (selectedCell) {
                if ([selectedCell isSelected]) {
                    [selectedCell setSelected:NO];
                }
            }
            [_indexPathsForSelectedItems removeObject:indexPath];

            if ( notifyDelegate && [tablePriv->_delegate respondsToSelector:@selector(tableView:didDeselectRowAtIndexPath:)] ) {
                [tablePriv->_delegate tableView:self didDeselectRowAtIndexPath:indexPath];
            }
        }
        return self;
    }

    -(void) deselectItemAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated {
        [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:NO];
    }

    -(void) selectRowAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition {
        if ( indexPath && ![_indexPathsForSelectedItems containsObject:indexPath] )
            [self selectItemAtIndexPath:indexPath animated:animated scrollPosition:scrollPosition notifyDelegate:NO];
    }

    -(void) deselectRowAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated {
        if ( indexPath && [_indexPathsForSelectedItems containsObject:indexPath])
            [self deselectItemAtIndexPath:indexPath animated:animated notifyDelegate:NO];
    }

    -(void) _cellAccessoryTapped:(UITableViewCell*)cell {
        NSIndexPath* indexPath = [cell indexPath];

        if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:accessoryButtonTappedForRowWithIndexPath:)] ) {
            [tablePriv->_delegate tableView:self accessoryButtonTappedForRowWithIndexPath:indexPath];
        }
    }

    -(UITableViewCell*) cellForRowAtIndexPath:(NSIndexPath*)path {
        int section = [path section];
        int row = [path row];

        if ( section >= tablePriv->sectionCount() || row >= tablePriv->sectionAtIndex(section)->rowCount()) {
            return nil;
        }

        return tablePriv->sectionAtIndex(section)->rowAtIndex(row)->_view;
    }

    -(CGRect) rectForRowAtIndexPath:(NSIndexPath*)path {
        int section = [path section];
        int row = [path row];

        CGRect ret = { 0, 0, 0, 0 };
        if ( section >= tablePriv->sectionCount() || row >= tablePriv->sectionAtIndex(section)->rowCount()) {
            return ret;
        }

        CGRect bounds;
        bounds = [self bounds];
        ret.origin.x = 0.0f;
        ret.origin.y = tablePriv->sectionAtIndex(section)->rowAtIndex(row)->_yPos;
        ret.size.width = bounds.size.width;
        ret.size.height = tablePriv->sectionAtIndex(section)->rowAtIndex(row)->_height;

        return ret;
    }

    -(CGRect) rectForSection:(int)section {
        if ( tablePriv->_needsReload ) {
            [self reloadData];
        }

        CGRect ret;
        CGSize contentSize = { 0, 0 };      

        float y = 0.0f;

        if ( section >= tablePriv->sectionCount() ) {
            EbrDebugLog("section(%d) > numSections(%d)\n", section, tablePriv->sectionCount());
            assert(0);
        }

        //  Grab section data
        y += tablePriv->sectionAtIndex(section)->_header->_height;

        //  Grab rows
        TableViewSection *curSection = tablePriv->sectionAtIndex(section);
        LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
            TableViewRow *curRow = (TableViewRow *) curRowNode;

            y += curRow->_height;
        }

        y += tablePriv->sectionAtIndex(section)->_footer->_height;

        CGRect bounds;
        bounds = [self bounds];
        ret.origin.x = 0.0f;
        ret.origin.y = tablePriv->sectionAtIndex(section)->_yPos;
        ret.size.width = bounds.size.width;
        ret.size.height = y;

        return ret;
    }
        
    -(void) insertRowsAtIndexPaths:(NSArray*)paths withRowAnimation:(UITableViewRowAnimation)animate {
        if ( tablePriv->_needsReload ) {
            [self reloadData];
        }

        unsigned count = [paths count];

        for ( unsigned i = 0; i < count; i ++ ) {
            NSIndexPath* path = [paths objectAtIndex:i];

            int section = [path section];
            int row = [path row];

            if ( section >= tablePriv->sectionCount() || row > tablePriv->sectionAtIndex(section)->rowCount()) {
                assert(0);
            }

            TableViewSection *curSection = tablePriv->sectionAtIndex(section);
            TableViewNode *insertAfter = NULL;
            if ( row < tablePriv->sectionAtIndex(section)->rowCount() ) {
                insertAfter = curSection->childAtIndex(row);
            }

            float cellHeight = tablePriv->_defaultRowHeight;

            if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)] ) {
                cellHeight = [tablePriv->_delegate tableView:self heightForRowAtIndexPath:path];
            }

            //  Insert the row
            TableViewRow *newRow = new TableViewRow(self, i);
            curSection->addChildAfter(newRow, insertAfter);

            newRow->_height = cellHeight;
            newRow->_view = nil;
            newRow->_yPos = -1;
        }

        calcCellPositions(self);
        showVisibleCells(self, animate != UITableViewRowAnimationNone);
    }

    -(void) insertSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animate {
        EbrDebugLog("insertSections not supported\n");
    }

    -(void) reloadSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animationType {
        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView beginAnimations:@"CellMoving" context:nil];
            [UIView setAnimationDuration:0.4f];
        }

        _TableCellAnimationHelper* cleanupHelper = [_TableCellAnimationHelper new];

        int maxCells = 0;

        LLTREE_FOREACH(curNode, (TableViewNode *) tablePriv->_rootNode) {
            maxCells += curNode->childCount;
        }
        cleanupHelper->_numCellsToBeRemoved = 0;
        cleanupHelper->_cellsToBeRemoved = (id *) EbrMalloc(sizeof(id) * maxCells);

        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView setAnimationDidStopSelector:@selector(animationFinished)];
            [UIView setAnimationDelegate:cleanupHelper];
        }

        NSUInteger idx = [sections firstIndex];
        while(idx != NSNotFound)
        {
            int section = idx;

            if ( section >= tablePriv->sectionCount() ) {
                assert(0);
            }

            TableViewSection *curSection = tablePriv->sectionAtIndex(section);
            int newRowCount = [tablePriv->_dataSource tableView:self numberOfRowsInSection:section];

            int curIdx = 0;

            LLTREE_FOREACH(curNode, (TableViewNode *) curSection) {
                //  Reload the rows
                TableViewRow *curRow = (TableViewRow *) curNode;

                if ( curRow->_view != nil ) {
                    [curRow->_view setAlpha:0.0f];
                    cleanupHelper->_cellsToBeRemoved[cleanupHelper->_numCellsToBeRemoved ++ ] = curRow->_view;
                    [curRow->_view retain];
                    curRow->detachView();
                }
                if ( curRow->_reusable ) {
                    tablePriv->removeReusableCell(curRow->_reusable);
                    curRow->_reusable = NULL;
                }

                if ( curIdx < newRowCount ) {
                    float cellHeight = tablePriv->_defaultRowHeight;

                    if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)] ) {
                        id path = [NSIndexPath indexPathForRow:curIdx inSection:section];
                        cellHeight = [tablePriv->_delegate tableView:self heightForRowAtIndexPath:path];
                    }

                    curRow->_animation = animationType;
                    curRow->_oldHeight = curRow->_height;
                    curRow->_height = cellHeight;
                } else {
                    curSection->removeChild(curRow);
                    delete curRow;
                }
                curIdx ++;
            }

            //  Add any extra new rows needed
            while ( curIdx < newRowCount ) {
                TableViewRow *newRow = new TableViewRow(self, curIdx);
                float cellHeight = tablePriv->_defaultRowHeight;

                if ( [tablePriv->_delegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)] ) {
                    id path = [NSIndexPath indexPathForRow:curIdx inSection:section];
                    cellHeight = [tablePriv->_delegate tableView:self heightForRowAtIndexPath:path];
                }

                newRow->_animation = animationType;
                newRow->_height = cellHeight;
                newRow->_oldHeight = newRow->_height;

                curSection->addChildAfter(newRow, NULL);
                curIdx ++;
            }

            idx = [sections indexGreaterThanIndex:idx];
        }

        calcCellPositions(self);
        showVisibleCells(self, animationType != UITableViewRowAnimationNone);

        if ( animationType != UITableViewRowAnimationNone ) {
            [UIView commitAnimations];
        }
    }

    -(void) deleteRowsAtIndexPaths:(NSArray*)paths withRowAnimation:(UITableViewRowAnimation)animate {
        int count = [paths count];

        TableViewRow **rows = (TableViewRow **) malloc(sizeof(TableViewRow *) * count);
        int numRows = 0;

        for ( int i = 0; i < count; i ++ ) {
            NSIndexPath* path = [paths objectAtIndex:i];

            int section = [path section];
            int row = [path row];

            if ( section >= tablePriv->sectionCount() || row >= tablePriv->sectionAtIndex(section)->rowCount()) {
                //assert(0);
                return;
            }

            //  Delete the row
            TableViewRow *itemRow = tablePriv->sectionAtIndex(section)->rowAtIndex(row);
            rows[numRows ++] = itemRow;
        }

        for ( int i = 0; i < numRows; i ++ ) {
            //  Delete the row
            TableViewRow *curRow = rows[i];

            if ( curRow->_view != nil ) {
                [curRow->_view removeFromSuperview];
                curRow->_view = nil;
            }

            TableViewSection *section = (TableViewSection *) curRow->parent;
            section->removeChild(curRow);
            delete curRow;
        }

        calcCellPositions(self);
        showVisibleCells(self);
    }

    -(void) deleteSections:(NSIndexSet*)sections withRowAnimation:(UITableViewRowAnimation)animate {
        int section = 0;

        for ( int i = 0; i < tablePriv->sectionCount(); i ++ ) {
            if ( ![sections containsIndex:i] ) {
                section ++;
                continue;
            }

            if ( section >= tablePriv->sectionCount() ) {
                assert(0);
            }

            TableViewSection *curSection = tablePriv->sectionAtIndex(section);

            //  Delete the section
            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_view != nil ) {
                    [curRow->_view removeFromSuperview];
                    curRow->_view = nil;
                }
                delete curRow;
            }

            tablePriv->_rootNode->removeChild(curSection);
            delete curSection;
            section --;
        }

        calcCellPositions(self);
        showVisibleCells(self);
    }

    -(NSInteger) numberOfRowsInSection:(NSInteger)section {
        if ( tablePriv->_needsReload ) {
            [self reloadData];
        }

        return tablePriv->sectionAtIndex(section)->rowCount();
    }

    -(NSIndexPath*) indexPathForSelectedRow {
        return [_indexPathsForSelectedItems anyObject];
    }

    -(NSArray*) indexPathsForSelectedRows {
        return [_indexPathsForSelectedItems allObjects];
    }

    -(NSIndexPath*) indexPathForCell:(UITableViewCell*)cell {
        return [cell indexPath];
    }

    -(void) setBackgroundView:(UIView*)view {
        if ( tablePriv->_backgroundView == view ) {
            return;
        }

        if ( tablePriv->_backgroundView != nil ) [tablePriv->_backgroundView removeFromSuperview];
        tablePriv->_backgroundView = view;

        [self addSubview:tablePriv->_backgroundView];

        [tablePriv->_backgroundView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
        [self _setShouldLayout];
    }

    -(void) scrollToRowAtIndexPath:(id)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated {
        //  Get cell rect
        CGRect cellRect = CGRectNull;
        CGRect bounds;

        cellRect = [self rectForRowAtIndexPath:indexPath];
        bounds = [self bounds];

        if ( !CGRectIsNull(cellRect) && cellRect.size.height > 0) {
            switch (scrollPosition) {
                case UITableViewScrollPositionNone:
                    break;
                
                case UITableViewScrollPositionTop:
                    cellRect.size.height = bounds.size.height;
                    break;

                case UITableViewScrollPositionMiddle:
                    cellRect.origin.y -= (bounds.size.height / 2.f) - cellRect.size.height;
                    cellRect.size.height = bounds.size.height;
                    break;

                case UITableViewScrollPositionBottom:
                    cellRect.origin.y -= bounds.size.height - cellRect.size.height;
                    cellRect.size.height = bounds.size.height;
                    break;
            }
        
            [self scrollRectToVisible:cellRect animated:animated];
        }
    }

    -(void) setEditing:(BOOL)editing {
        [self setEditing:editing animated:FALSE];
    }

    -(void) setEditing:(BOOL)editing animated:(BOOL)animated {
        BOOL wasEditing = tablePriv->_isEditing;
        tablePriv->_isEditing = editing;

        if ( editing != wasEditing ) {
            LLTREE_FOREACH(curComponent, (&tablePriv->_visibleComponents->_allComponents)) {
                if ( curComponent->_node->getNodeType() == tableViewNodeRow ) {
                    [(UITableViewCell*)curComponent->_node->_view _setEditingMode:editing animated:animated];
                }
            }
        }
    }

    -(BOOL) isEditing {
        return tablePriv->_isEditing;
    }

    -(void) layoutSubviews {
        [super layoutSubviews];
        if ( [self window] == nil ) return;

        if ( tablePriv->_needsReload ) {
            [self reloadData];
        }
        showVisibleCells(self);
    }

    -(void) dealloc {
        for (const auto& rc : tablePriv->_reusableCells) {
            for (auto& cell : rc.second) {
                [(UITableViewCell *)cell->_cell removeFromSuperview];
                if (cell->sourceRow) {
                    cell->sourceRow->_view = nil;
                    cell->sourceRow->_reusable = NULL;
                }
                delete cell;
            }
        }

        LLTREE_FOREACH(curNode, tablePriv->_rootNode) {
            TableViewSection *curSection = (TableViewSection *) curNode;

            LLTREE_FOREACH(curRowNode, ((TableViewNode *) curSection)) {
                TableViewRow *curRow = (TableViewRow *) curRowNode;

                if ( curRow->_view != nil ) {
                    [(UIView*)curRow->_view removeFromSuperview];
                    curRow->_view = nil;
                }
                delete curRow;
            }

            delete curSection;
        }

        delete tablePriv->_visibleComponents;

        tablePriv->_backgroundView = nil;
        tablePriv->_reusableCellNibs = nil;
        tablePriv->_reusableHeaderClasses = nil;
        tablePriv->_reusableCellClasses = nil;
        tablePriv->_headerView = nil;
        tablePriv->_footerView = nil;
        tablePriv->_backgroundView = nil;
        _indexPathsForSelectedItems = nil;
        _indexPathsForHighlightedItems = nil;
        _currentIndexPath = nil;
        _touchingIndexPath = nil;
        tablePriv->_externalObjects = nil;
        delete tablePriv;
        [super dealloc];
    }

    -(UITableViewStyle) style {
        return tablePriv->_style;
    }

    -(void) beginUpdates {
    }

    -(void) endUpdates {
    }

    -(void) scrollViewDidScroll:(UIScrollView*)scroller {
        showVisibleCells(self);

        id delegate = tablePriv->_delegate;
        if ( delegate != self && [delegate respondsToSelector:@selector(scrollViewDidScroll:)] ) {
            [delegate scrollViewDidScroll:scroller];
        }
    }

    -(void) scrollViewWillBeginDecelerating:(UIScrollView*)scroller {
        if ( tablePriv->_delegate != self && [tablePriv->_delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)] ) {
            [tablePriv->_delegate scrollViewWillBeginDecelerating:scroller];
        }
    }

    -(void) scrollViewDidEndDecelerating:(UIScrollView*)scroller {
        if ( tablePriv->_delegate != self && [tablePriv->_delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)] ) {
            [tablePriv->_delegate scrollViewDidEndDecelerating:scroller];
        }
    }

    -(void) scrollViewWillBeginDragging:(UIScrollView*)scroller {
        if ( tablePriv->_delegate != self && [tablePriv->_delegate respondsToSelector:@selector(scrollViewWillBeginDragging:)] ) {
            [tablePriv->_delegate scrollViewWillBeginDragging:scroller];
        }
    }

    -(void) scrollViewDidEndDragging:(UIScrollView*)scroller willDecelerate:(BOOL)willDecelerate {
        if ( tablePriv->_delegate != self && [tablePriv->_delegate respondsToSelector:@selector(scrollViewDidEndDragging:willDecelerate:)] ) {
            [tablePriv->_delegate scrollViewDidEndDragging:scroller willDecelerate:willDecelerate];
        }
    }

    -(void) scrollViewWillEndDragging:(UIScrollView*)scroller withVelocity:(CGPoint)velocity targetContentOffset:(CGPoint*)contentOffsetPtr {
        if ( tablePriv->_delegate != self && [tablePriv->_delegate respondsToSelector:@selector(scrollViewWillEndDragging:withVelocity:targetContentOffset:)] ) {
            [tablePriv->_delegate scrollViewWillEndDragging:scroller withVelocity:velocity targetContentOffset:contentOffsetPtr];
        }
    }

    -(void) registerNib:(NSNib*)nib forCellReuseIdentifier:(NSString*)identifier {
        [tablePriv->_reusableCellNibs setObject:nib forKey:identifier];
    }

    -(void) registerClass:(id)classId forHeaderFooterViewReuseIdentifier:(id)reuseIdentifier {
        [(NSMutableDictionary*)tablePriv->_reusableHeaderClasses setObject:classId forKey:reuseIdentifier];
    }

    -(void) registerClass:(id)classId forCellReuseIdentifier:(id)reuseIdentifier {
        [(NSMutableDictionary*)tablePriv->_reusableCellClasses setObject:classId forKey:reuseIdentifier];
    }

    -(void) setAllowsMultipleSelection:(BOOL)allow {
        tablePriv->_allowsMultipleSelection = allow;
    }

    -(BOOL) allowsMultipleSelection {
        return tablePriv->_allowsMultipleSelection;
    }

    -(BOOL) _currentlyAllowsMultipleSelection {
        return tablePriv->_isEditing ? tablePriv->_allowsMultipleSelectionDuringEditing : tablePriv->_allowsMultipleSelection;
    }

    -(id) dequeueReusableHeaderFooterViewWithIdentifier:(NSString*)reuseIdentifier {
        id classId = [tablePriv->_reusableHeaderClasses objectForKey:reuseIdentifier];
        if ( classId == nil ) {
            classId = [UITableViewHeaderFooterView class];
        }
        id ret = [[classId alloc] initWithReuseIdentifier:reuseIdentifier];

        return [ret autorelease];
    }

    -(void) willMoveToWindow:(UIWindow*)newWindow {
        if ( newWindow != nil ) {
            [self _setShouldLayout];
        }
        [super willMoveToWindow:newWindow];
    }

    -(void) _forwardCellRemoval:(UITableViewCell*)cell {
        [tablePriv->_dataSource tableView:self commitEditingStyle:UITableViewCellEditingStyleDelete forRowAtIndexPath:[cell indexPath]];
    }

    -(BOOL) _canEditCell:(UITableViewCell*)cell {
        if ( [tablePriv->_dataSource respondsToSelector:@selector(tableView:canEditRowAtIndexPath:)] ) {
            return [tablePriv->_dataSource tableView:self canEditRowAtIndexPath:[cell indexPath]];
        }
        return [tablePriv->_dataSource respondsToSelector:@selector(tableView:commitEditingStyle:forRowAtIndexPath:)];
    }

        
    
    
    
@end

