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
#import <UIKit/UITableViewCell.h>
#import <UIKit/UIScrollViewDelegate.h>

@class UITableView;
@class NSIndexPath;
@class UITableViewCell;
@class NSArray;
@class UIView;
@class NSString;
@class UITableViewFocusUpdateContext;
@class UIFocusAnimationCoordinator;

@protocol UITableViewDelegate <UIScrollViewDelegate>
@optional
- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath;
- (CGFloat)tableView:(UITableView*)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSInteger)tableView:(UITableView*)tableView indentationLevelForRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView willDisplayCell:(UITableViewCell*)cell forRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSArray*)tableView:(UITableView*)tableView editActionsForRowAtIndexPath:(NSIndexPath*)indexPath;
- (UITableViewCellAccessoryType)tableView:(UITableView*)tableView accessoryTypeForRowWithIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath*)indexPath;
- (NSIndexPath*)tableView:(UITableView*)tableView willSelectRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSIndexPath*)tableView:(UITableView*)tableView willDeselectRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didDeselectRowAtIndexPath:(NSIndexPath*)indexPath;
- (UIView*)tableView:(UITableView*)tableView viewForHeaderInSection:(NSInteger)section;
- (UIView*)tableView:(UITableView*)tableView viewForFooterInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView*)tableView heightForHeaderInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView*)tableView estimatedHeightForHeaderInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView*)tableView heightForFooterInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView*)tableView estimatedHeightForFooterInSection:(NSInteger)section;
- (void)tableView:(UITableView*)tableView willDisplayHeaderView:(UIView*)view forSection:(NSInteger)section;
- (void)tableView:(UITableView*)tableView willDisplayFooterView:(UIView*)view forSection:(NSInteger)section;
- (void)tableView:(UITableView*)tableView willBeginEditingRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didEndEditingRowAtIndexPath:(NSIndexPath*)indexPath;
- (UITableViewCellEditingStyle)tableView:(UITableView*)tableView editingStyleForRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSString*)tableView:(UITableView*)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)tableView:(UITableView*)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSIndexPath*)tableView:(UITableView*)tableView
    targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath*)sourceIndexPath
                         toProposedIndexPath:(NSIndexPath*)proposedDestinationIndexPath;
- (void)tableView:(UITableView*)tableView didEndDisplayingCell:(UITableViewCell*)cell forRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didEndDisplayingHeaderView:(UIView*)view forSection:(NSInteger)section;
- (void)tableView:(UITableView*)tableView didEndDisplayingFooterView:(UIView*)view forSection:(NSInteger)section;
- (BOOL)tableView:(UITableView*)tableView shouldShowMenuForRowAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)tableView:(UITableView*)tableView canPerformAction:(SEL)action forRowAtIndexPath:(NSIndexPath*)indexPath withSender:(id)sender;
- (void)tableView:(UITableView*)tableView performAction:(SEL)action forRowAtIndexPath:(NSIndexPath*)indexPath withSender:(id)sender;
- (BOOL)tableView:(UITableView*)tableView shouldHighlightRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didHighlightRowAtIndexPath:(NSIndexPath*)indexPath;
- (void)tableView:(UITableView*)tableView didUnhighlightRowAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)tableView:(UITableView*)tableView canFocusRowAtIndexPath:(NSIndexPath*)indexPath;
- (BOOL)tableView:(UITableView*)tableView shouldUpdateFocusInContext:(UITableViewFocusUpdateContext*)context;
- (void)tableView:(UITableView*)tableView
     didUpdateFocusInContext:(UITableViewFocusUpdateContext*)context
    withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator;
- (NSIndexPath*)indexPathForPreferredFocusedViewInTableView:(UITableView*)tableView;
@end
