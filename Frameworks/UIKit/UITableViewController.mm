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

#import "Starboard.h"

#import <UIKit/UIScreen.h>
#import <UIKit/UITableViewController.h>
#import <UIKit/UITableView.h>

#import "UITableViewDataSource.h"
#import "UIViewControllerInternal.h"

@implementation UITableViewController {
    UITableViewStyle _style;
    idretaintype(UITableViewDataSource) _staticSource;
    idretain _keyboardCropper;
    idretaintype(UIRefreshControl) _refreshControl;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    UITableView* tableView = [coder decodeObjectForKey:@"UITableView"];
    if (tableView) {
        [self setTableView:tableView];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithStyle:(UITableViewStyle)style {
    [super init];

    _style = style;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [super init];
}

/**
 @Status Interoperable
*/
- (UITableView*)tableView {
    UIView* ret = [self view];
    if ([ret isKindOfClass:[UITableView class]]) {
        return (UITableView*)ret;
    } else {
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (void)loadView {
    if ([self nibName] != nil) {
        [super loadView];
        if ([priv->view isKindOfClass:[UITableView class]]) {
            [static_cast<UITableView*>(priv->view) setDelegate:self];
            [static_cast<UITableView*>(priv->view) setDataSource:self];
        }
        return;
    }

    CGRect rct = [[UIScreen mainScreen] applicationFrame];

    UITableView* tableView = [[[UITableView alloc] initWithFrame:rct style:_style] autorelease];
    [tableView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];
    [self setTableView:tableView];
}

/**
 @Status Interoperable
*/
- (void)setTableView:(UITableView*)tableView {
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [self setView:tableView];
}

/**
 @Status Interoperable
*/
- (void)setView:(UIView*)view {
    _keyboardCropper = nil;
    [super setView:view];

    if ([view isKindOfClass:[UITableView class]]) {
#if KEYBOARD
        _keyboardCropper = [UIKeyboardCropper keyboardCropperForView:view];
#endif
    }
}

/**
 @Status Interoperable
*/
- (void)setStaticDataSource:(id<UITableViewDataSource>)dataSource {
    _staticSource = dataSource;
}

/**
 @Status Stub
*/
- (void)setClearsSelectionOnViewWillAppear:(BOOL)clear {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    if (_staticSource != nil) {
        return [_staticSource numberOfSections];
    } else {
        return 1;
    }
}

/**
 @Status Interoperable
*/
- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)index {
    if (_staticSource != nil) {
        return [[_staticSource sectionForIndex:index] numberOfRows];
    } else {
        assert(0);
        return 0;
    }
}

/**
 @Status Interoperable
*/
- (NSString*)tableView:(UITableView*)tableView titleForHeaderInSection:(NSInteger)index {
    if (_staticSource != nil) {
        id section = [_staticSource sectionForIndex:index];
        return [section title];
    } else {
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)index {
    if (_staticSource != nil) {
        UITableViewSection* section = [_staticSource sectionForIndex:[index section]];
        UITableViewRow* row = [section rowForIndex:[index row]];
        return [row rowHeight];
    } else {
        return [tableView rowHeight];
    }
}

/**
 @Status Interoperable
*/
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

/**
 @Status Stub
*/
- (void)setRefreshControl:(UIRefreshControl*)refreshControl {
    UNIMPLEMENTED();
    _refreshControl = refreshControl;
}

/**
 @Status Stub
*/
- (UIRefreshControl*)refreshControl {
    UNIMPLEMENTED();
    return _refreshControl;
}

/**
 @Status Interoperable
*/
- (void)setEditing:(BOOL)editing animated:(BOOL)animated {
    [super setEditing:editing animated:animated];
    id view = [self view];

    if ([view respondsToSelector:@selector(setEditing:animated:)]) {
        [view setEditing:editing animated:animated];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if ([priv->view isKindOfClass:[UITableView class]]) {
        UITableView* view = static_cast<UITableView*>(priv->view);
        [view setDelegate:nil];
        [view setDataSource:nil];
        [view removeFromSuperview];
    }
    _staticSource = nil;
    _keyboardCropper = nil;
    [super dealloc];
}

@end
