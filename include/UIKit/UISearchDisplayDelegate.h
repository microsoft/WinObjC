//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>

@class UISearchDisplayController;
@class UITableView;

@protocol UISearchDisplayDelegate <NSObject>
@optional
- (void)searchDisplayControllerWillBeginSearch:(UISearchDisplayController*)controller;
- (void)searchDisplayControllerDidBeginSearch:(UISearchDisplayController*)controller;
- (void)searchDisplayControllerWillEndSearch:(UISearchDisplayController*)controller;
- (void)searchDisplayControllerDidEndSearch:(UISearchDisplayController*)controller;
- (void)searchDisplayController:(UISearchDisplayController*)controller didLoadSearchResultsTableView:(UITableView*)tableView;
- (void)searchDisplayController:(UISearchDisplayController*)controller willUnloadSearchResultsTableView:(UITableView*)tableView;
- (void)searchDisplayController:(UISearchDisplayController*)controller willShowSearchResultsTableView:(UITableView*)tableView;
- (void)searchDisplayController:(UISearchDisplayController*)controller didShowSearchResultsTableView:(UITableView*)tableView;
- (void)searchDisplayController:(UISearchDisplayController*)controller willHideSearchResultsTableView:(UITableView*)tableView;
- (void)searchDisplayController:(UISearchDisplayController*)controller didHideSearchResultsTableView:(UITableView*)tableView;
- (BOOL)searchDisplayController:(UISearchDisplayController*)controller shouldReloadTableForSearchString:(NSString*)searchString;
- (BOOL)searchDisplayController:(UISearchDisplayController*)controller shouldReloadTableForSearchScope:(NSInteger)searchOption;
@end
