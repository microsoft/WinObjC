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

#import "ViewController.h"
#import "SingleContactViewController.h"
#import "ViewAllContactsViewController.h"
#import <AddressBook/ABAddressBook.h>

@interface ViewController () <UITableViewDelegate>

/**
 * Displays an alert telling the user they must give the app permissions to use
 * their AddressBook. Clears the menu so the user does not try to use other parts
 * of the application.
 */
- (void)_accessDenied;

@end

@implementation ViewController {
    NSArray* _menuOptions;
}

- (void)_accessDenied {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Cannot Use AddressBook"
                                                                   message:@"You must give the app permission to use the AddressBook."
                                                            preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction* action){
                                                          }];
    [alert addAction:defaultAction];
    [self presentViewController:alert animated:YES completion:nil];

    // Clear the menu to effectively disable the rest of the application
    // (which is useless without AddressBook permissions).
    _menuOptions = @[];
    [self.tableView reloadData];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.tableView setHidden:YES];
    _menuOptions = @[ @"View All Contacts", @"Create Contact", @"Modify Contact", @"Remove Contact" ];
    ABAuthorizationStatus status = ABAddressBookGetAuthorizationStatus();
    ABAddressBookRef addressBook;

    switch (status) {
        case kABAuthorizationStatusDenied:
        case kABAuthorizationStatusRestricted:
            // User previously denied permission for AddressBook, or has parental restrictions on.
            [self _accessDenied];
            break;
        case kABAuthorizationStatusAuthorized:
            // User has already previously given this application permission for the AddressBook.
            [self.tableView setHidden:NO];
            break;
        case kABAuthorizationStatusNotDetermined:
            // User hasn't given nor denied permission, so we must ask for it.
            addressBook = ABAddressBookCreate();

            // Make a weak reference for use in the callback.
            ViewController* __weak weakSelf = self;
            ABAddressBookRequestAccessWithCompletion(addressBook, ^(bool granted, CFErrorRef error) {
                if (!granted) {
                    // Access was not granted; dispatch on main queue because we
                    // reload the table view in _accessDenied
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [weakSelf _accessDenied];
                    });
                } else {
                    [weakSelf.tableView setHidden:NO];
                }
            });
            CFRelease(addressBook);
            break;
    }
}

/**
 * UITableViewDataSource methods.
 */

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_menuOptions count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(nonnull NSIndexPath*)indexPath {
    NSArray* cellIdentifiers = @[ @"ViewAllContactsCell", @"CreateContactCell", @"ModifyContactCell", @"RemoveContactCell" ];
    NSString* identifier = cellIdentifiers[indexPath.row];
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:identifier];

    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }

    cell.textLabel.text = _menuOptions[indexPath.row];
    return cell;
}

/**
 * Method to transition from main menu into other View Controllers.
 */

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    enum ContactOperation contactOperation = (enum ContactOperation)indexPath.row;

    if (contactOperation == kAddressBookCreateContact) {
        SingleContactViewController* destination =
            [[self storyboard] instantiateViewControllerWithIdentifier:@"SingleContactViewController"];
        destination.contactOperation = contactOperation;
        destination.addressBook = ABAddressBookCreateWithOptions(NULL, NULL);
        [[self navigationController] pushViewController:destination animated:YES];
    } else {
        ViewAllContactsViewController* destination =
            [[self storyboard] instantiateViewControllerWithIdentifier:@"ViewAllContactsViewController"];
        destination.contactOperation = contactOperation;
        [[self navigationController] pushViewController:destination animated:YES];
    }
}

@end