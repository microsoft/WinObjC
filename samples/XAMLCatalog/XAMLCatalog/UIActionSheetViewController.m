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

#import <UIKit/UIActionSheet.h>

#import "UIActionSheetViewController.h"

@implementation UIActionSheetViewController {
    NSArray* _menuItems;
}

- (id)init {
    if (self = [super init]) {
        [self setTitle:@"Alerts & Actions"];
        _menuItems = @[
            @"Show Basic Action",
            @"Show OK-Cancelable Action",
            @"Show Dynamic Action",
            @"Show Custom Buttons With Cancelable Action",
            @"Show Multiple Buttons on Action Sheet",
            @"Show Action on Button"
        ];
    }

    return self;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_menuItems count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    // Show UIActionSheet on button press
    if (indexPath.row == 5) {
        // We have a button on this cell so we don't need the whole cell to be selectable
        cell.selectionStyle = UITableViewCellSelectionStyleNone;

        // Create our own label which precedes the button
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(10, 0, 200, 40)];
        label.text = [_menuItems objectAtIndex:indexPath.row];

        // Create a button when pressed will display the UIActionSheet
        UIButton* button = [[UIButton alloc] initWithFrame:CGRectMake(200, 2, 150, 40)];
        button.backgroundColor = [UIColor grayColor];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setTitle:@"Button" forState:UIControlStateNormal];
        [button addTarget:self action:@selector(_buttonClick:) forControlEvents:UIControlEventTouchUpInside];

        [cell addSubview:label];
        [cell addSubview:button];
    } else {
        cell.textLabel.text = [_menuItems objectAtIndex:indexPath.row];
    }

    return cell;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    [tableView deselectRowAtIndexPath:[tableView indexPathForSelectedRow] animated:YES];

    if (indexPath.row == 0) {
        [self showBasicAction];
    } else if (indexPath.row == 1) {
        [self showOkAction];
    } else if (indexPath.row == 2) {
        [self showDynamicAction];
    } else if (indexPath.row == 3) {
        [self showCustomActionWithCancelButton];
    } else if (indexPath.row == 4) {
        [self showMultipleButtonsAddedPostInitializationAction];
    }
}

- (void)showBasicAction {
    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet Basic"
                                                             delegate:self
                                                    cancelButtonTitle:nil
                                               destructiveButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;

    NSLog(@"Total number of buttons: %ld", [actionSheet numberOfButtons]);
    NSLog(@"Title of button at index 0: %@", [actionSheet buttonTitleAtIndex:0]);

    NSLog(@"UIActionSheet visible: %@", [actionSheet isVisible] ? @"YES" : @"NO");
    [actionSheet showInView:self.view];
    NSLog(@"UIActionSheet visible: %@", [actionSheet isVisible] ? @"YES" : @"NO");
}

- (void)showOkAction {
    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet OK"
                                                             delegate:self
                                                    cancelButtonTitle:@"Cancel"
                                               destructiveButtonTitle:@"OK"
                                                    otherButtonTitles:nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;

    NSLog(@"Total number of buttons: %ld", [actionSheet numberOfButtons]);
    NSLog(@"Title of button at index 0: %@", [actionSheet buttonTitleAtIndex:0]);

    [actionSheet showInView:self.view];
}

- (void)showDynamicAction {
    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet Dynamic"
                                                              delegate:self
                                                     cancelButtonTitle:nil
                                                destructiveButtonTitle:nil
                                                     otherButtonTitles:@"Button 1", @"Cancel", @"Button 2", nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    actionSheet.destructiveButtonIndex = 0;

    NSLog(@"First other button index (before): %ld", [actionSheet firstOtherButtonIndex]);

    // Mark this button as the cancel button in the initial list
    actionSheet.cancelButtonIndex = 1;

    // Add another button and ensure that the cancel button is still in the same place
    [actionSheet addButtonWithTitle:@"Button 3"];

    NSLog(@"First other button index (after): %ld", [actionSheet firstOtherButtonIndex]);

    NSLog(@"Total number of buttons: %ld", [actionSheet numberOfButtons]);
    NSLog(@"Title of button at index 0: %@", [actionSheet buttonTitleAtIndex:0]);
    NSLog(@"Title of button at index 1: %@", [actionSheet buttonTitleAtIndex:1]);
    NSLog(@"Title of button at index 2: %@", [actionSheet buttonTitleAtIndex:2]);
    NSLog(@"Title of button at index 3: %@", [actionSheet buttonTitleAtIndex:3]);

    [actionSheet showInView:self.view];
}

-(void)showCustomActionWithCancelButton {
    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet Custom"
                                                            delegate:self
                                                   cancelButtonTitle:@"Cancel"
                                              destructiveButtonTitle:nil
                                                   otherButtonTitles:@"Button 1", @"Button 2", nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    actionSheet.destructiveButtonIndex = 1;

    NSLog(@"Total number of buttons: %ld", [actionSheet numberOfButtons]);
    NSLog(@"Title of button at index 0: %@", [actionSheet buttonTitleAtIndex:0]);
    NSLog(@"Title of button at index 1: %@", [actionSheet buttonTitleAtIndex:1]);

    [actionSheet showInView : self.view];
}

- (void)showMultipleButtonsAddedPostInitializationAction {
    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet Post Initialization"
                                                             delegate:self
                                                    cancelButtonTitle:nil
                                               destructiveButtonTitle:nil
                                                    otherButtonTitles:nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    actionSheet.destructiveButtonIndex = 1;

    NSLog(@"Title: %@", [actionSheet title]);
    NSLog(@"Total of buttons (before): %ld", [actionSheet numberOfButtons]);

    // Add buttons after the action sheet has been initialized
    NSArray* buttonTitles = @[
        @"Button 1",
        @"Button 2",
        @"Button 3",
        @"Button 4",
        @"Button 5",
        @"Button 6",
        @"Button 7",
        @"Button 8",
        @"Button 9",
        @"Button 10",
        @"Button 11",
        @"Button 12",
        @"Button 13",
        @"Button 14",
        @"Button 15",
        @"Button 16"
    ];

    for (NSString* title in buttonTitles) {
        [actionSheet addButtonWithTitle:title];
    }

    NSLog(@"Total number of buttons (after): %ld", [actionSheet numberOfButtons]);

    [actionSheet showInView:self.view];
}

// Button action
- (void)_buttonClick:(UIButton*)button {
    NSLog(@"Triggered button click");

    UIActionSheet* actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet on Button"
                                                             delegate:self
                                                    cancelButtonTitle:@"Cancel"
                                               destructiveButtonTitle:@"Dismiss"
                                                    otherButtonTitles:nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    actionSheet.destructiveButtonIndex = 1;
    [actionSheet showInView:button];
}

// ActionSheet delegate

-(void)willPresentActionSheet:(UIActionSheet*)actionSheet {
    NSLog(@"Triggered delegate willPresentActionSheet");
}

-(void)didPresentActionSheet:(UIActionSheet*)actionSheet {
    NSLog(@"Triggered delegate didPresentActionSheet");
}

-(void)actionSheetCancel:(UIActionSheet*)actionSheet {
    NSLog(@"Triggered delegate actionSheetCancel");
}

-(void)actionSheet:(UIActionSheet*)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    NSLog(@"Triggered delegate clickedButtonAtIndex - button index: %ld", buttonIndex);

    NSLog(@"Title of button at index %ld: %@", buttonIndex, [actionSheet buttonTitleAtIndex:buttonIndex]);
    NSLog(@"IsCancelButtonIndex: %@", buttonIndex == [actionSheet cancelButtonIndex] ? @"YES" : @"NO");
    NSLog(@"IsDestructiveButtonIndex: %@", buttonIndex == [actionSheet destructiveButtonIndex] ? @"YES" : @"NO");
    NSLog(@"First other button index: %ld", [actionSheet firstOtherButtonIndex]);

    NSLog(@"UIActionSheet visible: %@", [actionSheet isVisible] ? @"YES" : @"NO");
}

-(void)actionSheet:(UIActionSheet*)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex {
    NSLog(@"Triggered delegate willDismissWithButtonIndex - button index: %ld", buttonIndex);
}

-(void)actionSheet:(UIActionSheet*)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex {
    NSLog(@"Triggered delegate didDismissWithButtonIndex - button index: %ld", buttonIndex);
}

@end
