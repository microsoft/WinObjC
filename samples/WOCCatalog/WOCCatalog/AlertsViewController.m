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

#import "AlertsViewController.h"

@interface AlertsViewController ()

@end

@implementation AlertsViewController

- (id) init {
    self = [super init];
    
    [self setTitle:@"Alerts & Actions"];
    
    menuItems = @[@"Show Basic Action", @"Show Ok-Cancel Action", @"Show Custom Action", @"Show Simple Alert", @"Show Ok-Cancel Alert", @"Show Custom Alert"];
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return [menuItems count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }
    
    cell.textLabel.text = [menuItems objectAtIndex:indexPath.row];
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:[tableView indexPathForSelectedRow] animated:YES];
    
    if (indexPath.row == 0) {
        [self showBasicAction];
        
    } else if (indexPath.row == 1) {
        [self showOkAction];
        
    } else if (indexPath.row == 2) {
        [self showCustomAction];
    }
    else if (indexPath.row == 3) {
        [self showBasicAlert];
    }
    else if (indexPath.row == 4) {
        [self ShowOkAlert];
    }
    else if (indexPath.row == 5) {
        [self showCustomAlert];
    }    
}

- (void)showBasicAction
{
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet" delegate:self cancelButtonTitle:nil destructiveButtonTitle:@"OK" otherButtonTitles:nil];
    
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    [actionSheet showInView:self.view];
}

- (void)showOkAction
{
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:@"OK" otherButtonTitles:nil];
    
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    [actionSheet showInView:self.view];
}

- (void)showCustomAction
{
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:@"UIActionSheet" delegate:self cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:@"Button 1", @"Button 2", nil];
    actionSheet.actionSheetStyle = UIActionSheetStyleDefault;
    actionSheet.destructiveButtonIndex = 1;
    [actionSheet showInView:self.view];
}

- (void)showBasicAlert
{
    // open an alert with just an OK button
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"UIAlertView" message:@"Hello Alert"
                                                   delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
    [alert show];
}

- (void)ShowOkAlert
{
    // open a alert with an OK and cancel button
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"UIAlertView" message:@"Hello Alert"
                                                   delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"OK", nil];
    [alert show];
}

- (void)showCustomAlert
{
    // open an alert with two custom buttons
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"UIAlertView" message:@"Hello Custom"
                                                   delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Button1", @"Button2", nil];
    [alert show];
}

// AlertView delegate

- (void)alertView:(UIAlertView *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    // use "buttonIndex" to decide your action
    //
}

// ActionSheet delegate

- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    // the user clicked one of the OK/Cancel buttons
    if (buttonIndex == 0)
    {
        //NSLog(@"ok");
    }
    else
    {
        //NSLog(@"cancel");
    }
}

@end
