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
#import <UIKit/UIBarPositioningDelegate.h>
#import <Foundation/Foundation.h>

@class UISearchBar;

@protocol UISearchBarDelegate <UIBarPositioningDelegate>
@optional
- (void)searchBar:(UISearchBar*)searchBar textDidChange:(NSString*)searchText;
- (BOOL)searchBar:(UISearchBar*)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString*)text;
- (BOOL)searchBarShouldBeginEditing:(UISearchBar*)searchBar;
- (void)searchBarTextDidBeginEditing:(UISearchBar*)searchBar;
- (BOOL)searchBarShouldEndEditing:(UISearchBar*)searchBar;
- (void)searchBarTextDidEndEditing:(UISearchBar*)searchBar;
- (void)searchBarBookmarkButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarCancelButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarSearchButtonClicked:(UISearchBar*)searchBar;
- (void)searchBarResultsListButtonClicked:(UISearchBar*)searchBar;
- (void)searchBar:(UISearchBar*)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope;
@end
