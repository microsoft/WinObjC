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
#include "UIKit/UITableViewController.h"
#include "UIKit/UITableView.h"
#include "UITableViewDataSource.h"
#include "UIViewControllerInternal.h"

@implementation UITableViewController {
    UITableViewStyle _style;
    idretaintype(UITableViewDataSource) _staticSource;
    idretain _keyboardCropper;
    idretaintype(UIRefreshControl) _refreshControl;
}
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    UITableView* tableView = [coder decodeObjectForKey:@"UITableView"];
    if (tableView) {
        [self setTableView:tableView];
    }

    return self;
}

- (instancetype)initWithStyle:(UITableViewStyle)style {
    [super init];

    _style = style;

    return self;
}

- (instancetype)init {
    return [super init];
}

- (UITableView*)tableView {
    UIView* ret = [self view];
    if ([ret isKindOfClass:[UITableView class]]) {
        return (UITableView*)ret;
    } else {
        return nil;
    }
}

- (void)loadView {
    if ([self nibName] != nil) {
        [super loadView];
        if ([priv->view isKindOfClass:[UITableView class]]) {
            [priv->view setDelegate:self];
            [priv->view setDataSource:self];
        }
        return;
    }

    CGRect rct = [[UIScreen mainScreen] applicationFrame];

    UITableView* tableView = [[[UITableView alloc] initWithFrame:rct style:_style] autorelease];
    [tableView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [self setTableView:tableView];
}

- (void)setTableView:(UITableView*)tableView {
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [self setView:tableView];
}

- (void)setView:(UIView*)view {
    _keyboardCropper = nil;
    [super setView:view];

    if ([view isKindOfClass:[UITableView class]]) {
#if KEYBOARD
        _keyboardCropper = [UIKeyboardCropper keyboardCropperForView:view];
#endif
    }
}

- (void)setStaticDataSource:(id<UITableViewDataSource>)dataSource {
    _staticSource = dataSource;
}

- (void)setClearsSelectionOnViewWillAppear:(BOOL)clear {
}

- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    if (_staticSource != nil) {
        return [_staticSource numberOfSections];
    } else {
        return 1;
    }
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)index {
    if (_staticSource != nil) {
        return [[_staticSource sectionForIndex:index] numberOfRows];
    } else {
        assert(0);
        return 0;
    }
}

- (NSString*)tableView:(UITableView*)tableView titleForHeaderInSection:(NSInteger)index {
    if (_staticSource != nil) {
        id section = [_staticSource sectionForIndex:index];
        return [section title];
    } else {
        return nil;
    }
}

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)index {
    if (_staticSource != nil) {
        UITableViewSection* section = [_staticSource sectionForIndex:[index section]];
        UITableViewRow* row = [section rowForIndex:[index row]];
        return [row rowHeight];
    } else {
        return [tableView rowHeight];
    }
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)index {
    if (_staticSource != nil) {
        UITableViewSection* section = [_staticSource sectionForIndex:[index section]];
        UITableViewRow* row = [section rowForIndex:[index row]];
        return [row cell];
    } else {
        assert(0);
        return nil;
    }
}

- (void)setRefreshControl:(UIRefreshControl*)refreshControl {
    _refreshControl = refreshControl;
}

- (UIRefreshControl*)refreshControl {
    return _refreshControl;
}

- (void)setEditing:(BOOL)editing animated:(BOOL)animated {
    [super setEditing:editing animated:animated];
    id view = [self view];

    if ([view respondsToSelector:@selector(setEditing:animated:)]) {
        [view setEditing:editing animated:animated];
    }
}

- (void)dealloc {
    [priv->view setDelegate:nil];
    [priv->view setDataSource:nil];
    [priv->view removeFromSuperview];
    _staticSource = nil;
    _keyboardCropper = nil;
    [super dealloc];
}

@end
