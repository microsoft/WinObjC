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

#import "SearchBarViewController.h"

@implementation SearchBarViewController

static const int TAG_SUBVIEW_UISEARCHBAR = 1;

- (void)viewDidLoad {
    [super viewDidLoad];

    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 5;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 100;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    } else {
        // before reuse, check if cell contains any tagged subview, if so, remove them first
        UIView* subView = (UIView*)[cell viewWithTag:TAG_SUBVIEW_UISEARCHBAR];
        [subView removeFromSuperview];
    }

    [super viewDidLoad];

    self.title = @"UISearchBar";
    self.view.backgroundColor = [UIColor groupTableViewBackgroundColor];

    if (indexPath.row == 0) {
        UISearchBar* searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, cell.bounds.size.width, 100)];
        [searchBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth];
        searchBar.tag = TAG_SUBVIEW_UISEARCHBAR;
        [cell addSubview:searchBar];
    } else if (indexPath.row == 1) {
        UISearchBar* searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, cell.bounds.size.width, 100)];
        [searchBar setPrompt:@"UISearchBar prompt"];
        [searchBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth];
        searchBar.tag = TAG_SUBVIEW_UISEARCHBAR;
        [cell addSubview:searchBar];
    } else if (indexPath.row == 2) {
        UISearchBar* searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, cell.bounds.size.width, 100)];
        [searchBar setPrompt:@"UISearchBar with bg image"];
        [searchBar setSearchFieldBackgroundImage:[UIImage imageNamed:@"tf_bgimage.jpg"] forState:UIControlStateNormal];
        [searchBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth];
        searchBar.tag = TAG_SUBVIEW_UISEARCHBAR;
        [cell addSubview:searchBar];
    } else if (indexPath.row == 3) {
        UISearchBar* searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, cell.bounds.size.width, 100)];
        [searchBar setPrompt:@"UISearchBar with cancel button"];
        searchBar.showsCancelButton = true;
        [searchBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth];
        searchBar.tag = TAG_SUBVIEW_UISEARCHBAR;
        [cell addSubview:searchBar];
    } else if (indexPath.row == 4) {
        // searchbar with empty prompt, we should not show prompt label
        UISearchBar* searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, cell.bounds.size.width, 100)];
        [searchBar setPrompt:@""];
        searchBar.showsCancelButton = true;
        [searchBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth];
        [cell addSubview:searchBar];
        searchBar.delegate = self;
    }

    return cell;
}

- (void)searchBarCancelButtonClicked:(UISearchBar*)searchBar {
    searchBar.text = @"";
}

@end
