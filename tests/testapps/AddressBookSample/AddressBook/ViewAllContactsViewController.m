//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "ViewAllContactsViewController.h"
#import "SingleContactViewController.h"
#import "ViewController.h"
#import <AddressBook/ABAddressBook.h>
#import <AddressBook/ABPerson.h>

@interface ViewAllContactsViewController ()

@end

@implementation ViewAllContactsViewController {
    ABAddressBookRef _addressBook;
}

- (void)dealloc {
    CFRelease(_addressBook);
}

- (void)viewDidLoad {
    [super viewDidLoad];

    _addressBook = ABAddressBookCreate();
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

// Since Windows Contacts are read-only for those not created by the user's app,
// the cases for modifying and deleting make use of the new method, ABAddressBookCopyArrayOfAllUserAppPeople,
// which returns the contacts that can be modified or deleted. In iOS, all contacts have read-write permission,
// so ABAddressBookCopyArrayOfAllPeople is sufficient.
#ifdef WINOBJC
    if (self.contactOperation == kAddressBookViewContact) {
        self.contacts = (__bridge_transfer NSArray*)ABAddressBookCopyArrayOfAllPeople(_addressBook);
    } else {
        self.contacts = (__bridge_transfer NSArray*)ABAddressBookCopyArrayOfAllUserAppPeople(_addressBook);
    }
#else
    self.contacts = (__bridge_transfer NSArray*)ABAddressBookCopyArrayOfAllPeople(_addressBook);
#endif
    [self.tableView reloadData];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    if (self.contactOperation == kAddressBookRemoveContact) {
#ifdef WINOBJC
        self.contacts = (__bridge_transfer NSArray*)ABAddressBookCopyArrayOfAllUserAppPeople(_addressBook);
#else
        self.contacts = (__bridge_transfer NSArray*)ABAddressBookCopyArrayOfAllPeople(_addressBook);
#endif
        [self.tableView reloadData];
    }
}

/**
 * UITableViewDataSource methods.
 */

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.contacts count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(nonnull NSIndexPath*)indexPath {
    NSString* identifier = nil;
    switch (self.contactOperation) {
        case kAddressBookViewContact:
            identifier = @"ShowContact";
            break;
        case kAddressBookModifyContact:
            identifier = @"ModifyContact";
            break;
        case kAddressBookRemoveContact:
            identifier = @"RemoveContact";
            break;
        default:
            // This case should never happen, since view/modify/remove are the only operations that
            // transition into a list of the user's contacts (create doesn't need to show the user's contacts).
            NSLog(@"Error -- invalid contactOperation of: %d", self.contactOperation);
            break;
    }

    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:identifier];

    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }

    cell.textLabel.text = (__bridge_transfer NSString*)ABRecordCopyCompositeName((__bridge ABRecordRef)(self.contacts[indexPath.row]));
    return cell;
}

/**
 * Method to transition from main menu into other View Controllers.
 */

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    SingleContactViewController* destination = [[self storyboard] instantiateViewControllerWithIdentifier:@"SingleContactViewController"];
    destination.contactOperation = self.contactOperation;
    destination.contact = (__bridge ABRecordRef)(self.contacts[indexPath.row]);
    destination.addressBook = _addressBook;
    [[self navigationController] pushViewController:destination animated:YES];
}

@end
