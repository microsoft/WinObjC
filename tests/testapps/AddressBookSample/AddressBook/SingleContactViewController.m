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

#import "SingleContactViewController.h"
#import "ViewController.h"
#import <AddressBook/ABMutableMultiValue.h>
#import <AddressBook/ABPerson.h>

@interface SingleContactViewController ()

/**
 * Sets all of the text fields to have an 'enabled' state as given by
 * enabled.
 */
- (void)_setTextFieldEnabledState:(BOOL)enabled;

/**
 * Populates all of the text fields (name, phone number, etc) with
 * the information obtained from self.contact.
 */
- (void)_populateTextFields;

/**
 * Populates the first name text field with the first name of the
 * contact in self.contact.
 */
- (void)_populateFirstName;

/**
 * Populates the last name text field with the last name of the
 * contact in self.contact.
 */
- (void)_populateLastName;

/**
 * Populates the phone number text field with the first phone number
 * listed in the phone numbers of the contact in self.contact.
 */
- (void)_populatePhoneNumber;

/**
 * Populates the email text field with the first email address
 * listed in the emails of the contact in self.contact.
 */
- (void)_populateEmail;

/**
 * Populates the address text field with the street of the first address
 * listed in the addresses of the contact in self.contact.
 */
- (void)_populateAddress;

/**
 * Populates the contact photo to use the contact image (if present) of
 * the contact in self.contact.
 */
- (void)_populateContactPhoto;

/**
 * Updates the contact in self.contact to now reflect the values in the
 * text fields. If a text field is blank, that property is removed from the
 * contact. The user can only modify values that previously had a value --
 * they cannot add additional ones (they can remove existing values, though).
 */
- (void)_modifyContact;

/**
 * Creates a new contact using the values in the text fields, and then adds
 * said contact to the AddressBook. The phone number is assigned with the label of
 * Main Phone, and the email is assigned with a label of Work. The address creates
 * an address with the given value as the street, with a label of Home.
 */
- (void)_createContact;

/**
 * Returns the value in the text field of the given UITextField*, or
 * NULL if the text field has no text in it.
 */
- (CFTypeRef)_copyContactInfoFrom:(UITextField*)textField;

@end

@implementation SingleContactViewController

- (void)dealloc {
    // Viewing, modifying, and deleting a contact uses the parent's ABAddressBookRef.
    // Create, however, has its own, and so it must clean up when finished.
    if (self.contactOperation == kAddressBookCreateContact) {
        CFRelease(self.addressBook);
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // Set delegates for the text fields so that the keyboard can be hidden
    // when return is pressed, or if the user taps outside of the text field.
    self.firstName.delegate = self;
    self.lastName.delegate = self;
    self.phoneNumber.delegate = self;
    self.email.delegate = self;
    self.address.delegate = self;

    // Set up the text fields and button depending on operation type.
    switch (self.contactOperation) {
        case kAddressBookViewContact:
            [self _setTextFieldEnabledState:NO];
            [self.button setTitle:@"Done" forState:UIControlStateNormal];
            [self _populateTextFields];
            break;
        case kAddressBookRemoveContact:
            [self _setTextFieldEnabledState:NO];
            [self.button setTitle:@"Remove" forState:UIControlStateNormal];
            [self _populateTextFields];
            break;
        case kAddressBookModifyContact:
            [self _setTextFieldEnabledState:YES];
            [self.button setTitle:@"Save" forState:UIControlStateNormal];
            [self _populateTextFields];
            break;
        case kAddressBookCreateContact:
            [self _setTextFieldEnabledState:YES];
            [self.button setTitle:@"Create" forState:UIControlStateNormal];
            break;
    }
}

- (void)_setTextFieldEnabledState:(BOOL)enabled {
    [self.firstName setEnabled:enabled];
    [self.lastName setEnabled:enabled];
    [self.phoneNumber setEnabled:enabled];
    [self.email setEnabled:enabled];
    [self.address setEnabled:enabled];
}

- (void)_populateTextFields {
    [self _populateFirstName];
    [self _populateLastName];
    [self _populatePhoneNumber];
    [self _populateEmail];
    [self _populateAddress];
    [self _populateContactPhoto];
}

- (void)_populateFirstName {
    NSString* firstName = (__bridge_transfer NSString*)ABRecordCopyValue(self.contact, kABPersonFirstNameProperty);
    if (firstName) {
        [self.firstName setText:firstName];
    } else if (self.contactOperation == kAddressBookModifyContact) {
        [self.firstName setEnabled:NO];
    }
}

- (void)_populateLastName {
    NSString* lastName = (__bridge_transfer NSString*)ABRecordCopyValue(self.contact, kABPersonLastNameProperty);
    if (lastName) {
        [self.lastName setText:lastName];
    } else if (self.contactOperation == kAddressBookModifyContact) {
        [self.lastName setEnabled:NO];
    }
}

- (void)_populatePhoneNumber {
    ABMultiValueRef phoneNumbers = ABRecordCopyValue(self.contact, kABPersonPhoneProperty);
    NSString* phoneNumber = nil;
    if (ABMultiValueGetCount(phoneNumbers) > 0) {
        phoneNumber = (__bridge_transfer NSString*)ABMultiValueCopyValueAtIndex(phoneNumbers, 0);
    }

    if (phoneNumber) {
        [self.phoneNumber setText:phoneNumber];
    } else if (self.contactOperation == kAddressBookModifyContact) {
        [self.phoneNumber setEnabled:NO];
    }

    if (phoneNumbers) {
        CFRelease(phoneNumbers);
    }
}

- (void)_populateEmail {
    ABMultiValueRef emails = ABRecordCopyValue(self.contact, kABPersonEmailProperty);
    NSString* email = nil;
    if (ABMultiValueGetCount(emails) > 0) {
        email = (__bridge_transfer NSString*)ABMultiValueCopyValueAtIndex(emails, 0);
    }

    if (email) {
        [self.email setText:email];
    } else if (self.contactOperation == kAddressBookModifyContact) {
        [self.email setEnabled:NO];
    }

    if (emails) {
        CFRelease(emails);
    }
}

- (void)_populateAddress {
    // Don't allow a user to modify their address, since only the street is displayed
    // (and so they don't have a way of updating other aspects like city).
    if (self.contactOperation == kAddressBookModifyContact) {
        [self.address setEnabled:NO];
    }

    ABMultiValueRef addresses = ABRecordCopyValue(self.contact, kABPersonAddressProperty);
    if (ABMultiValueGetCount(addresses) > 0) {
        NSDictionary* address = (__bridge_transfer NSDictionary*)ABMultiValueCopyValueAtIndex(addresses, 0);
        NSString* street = address[(NSString*)kABPersonAddressStreetKey];
        if (street) {
            [self.address setText:street];
        }
    }

    if (addresses) {
        CFRelease(addresses);
    }
}

- (void)_populateContactPhoto {
    ABRecordID contactID = ABRecordGetRecordID(self.contact);
    ABRecordRef originalContact = ABAddressBookGetPersonWithRecordID(self.addressBook, contactID);
    if (ABPersonHasImageData(originalContact)) {
        NSData* contactPhoto =
            (__bridge_transfer NSData*)ABPersonCopyImageDataWithFormat(originalContact, kABPersonImageFormatOriginalSize);
        UIImage* image = [UIImage imageWithData:contactPhoto];
        [self.contactPhoto setImage:image];
    }
}

- (CFTypeRef)_copyContactInfoFrom:(UITextField*)textField {
    if ([textField.text length] > 0) {
        return (__bridge_retained CFTypeRef)textField.text;
    } else {
        return NULL;
    }
}

- (IBAction)buttonPressed:(id)sender {
    CFErrorRef error = NULL;
    bool succeeded = true;
    switch (self.contactOperation) {
        case kAddressBookViewContact:
            // Viewing a contact doesn't need to make any changes.
            break;
        case kAddressBookRemoveContact:
            // Remove the contact from the AddressBook.
            succeeded = succeeded && ABAddressBookRemoveRecord(_addressBook, self.contact, &error);
            succeeded = succeeded && ABAddressBookSave(_addressBook, &error);
            if (!succeeded) {
                NSLog(@"There was an error removing the contact: %@", (__bridge_transfer NSString*)CFErrorCopyDescription(error));
            }
            break;
        case kAddressBookModifyContact:
            // Modify the AddressBook record for the current contact to reflect
            // any changes made by the user.
            [self _modifyContact];
            break;
        case kAddressBookCreateContact:
            // Create a new record in the AddressBook for the information
            // entered by the user.
            [self _createContact];
            break;
        default:
            // This case should never be reached, since a ContactOperation can only
            // have the previously-handled values.
            NSLog(@"Error -- invalid ContactOperation of: %d", self.contactOperation);
            break;
    }

    // Dismiss this view after the button is pressed.
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)_modifyContact {
    CFErrorRef error = NULL;
    CFTypeRef firstName = [self _copyContactInfoFrom:self.firstName];
    CFTypeRef lastName = [self _copyContactInfoFrom:self.lastName];
    CFTypeRef phoneNumber = [self _copyContactInfoFrom:self.phoneNumber];
    CFTypeRef email = [self _copyContactInfoFrom:self.email];
    bool succeeded = true;

    succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonFirstNameProperty, firstName, &error);
    if (firstName) {
        CFRelease(firstName);
    }

    succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonLastNameProperty, lastName, &error);
    if (lastName) {
        CFRelease(lastName);
    }

    if (self.phoneNumber.isEnabled) {
        ABMultiValueRef existingPhone = ABRecordCopyValue(self.contact, kABPersonPhoneProperty);
        ABMutableMultiValueRef phoneNumbers = ABMultiValueCreateMutableCopy(existingPhone);
        CFRelease(existingPhone);

        // Either update the value of the first phone number (since that's the one we displayed), or
        // remove it entirely if the user cleared the text field.
        if (phoneNumber) {
            succeeded = succeeded && ABMultiValueReplaceValueAtIndex(phoneNumbers, phoneNumber, 0);
        } else {
            succeeded = succeeded && ABMultiValueRemoveValueAndLabelAtIndex(phoneNumbers, 0);
        }

        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonPhoneProperty, phoneNumbers, &error);
        CFRelease(phoneNumbers);
    }

    if (phoneNumber) {
        CFRelease(phoneNumber);
    }

    if (self.email.isEnabled) {
        ABMultiValueRef existingEmail = ABRecordCopyValue(self.contact, kABPersonEmailProperty);
        ABMutableMultiValueRef emails = ABMultiValueCreateMutableCopy(existingEmail);
        CFRelease(existingEmail);

        // Either update the value of the first email address (since that's the one we displayed), or
        // remove it entirely if the user cleared the text field.
        if (email) {
            succeeded = succeeded && ABMultiValueReplaceValueAtIndex(emails, email, 0);
        } else {
            succeeded = succeeded && ABMultiValueRemoveValueAndLabelAtIndex(emails, 0);
        }

        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonEmailProperty, emails, &error);
        CFRelease(emails);
    }

    if (email) {
        CFRelease(email);
    }

    succeeded = succeeded && ABAddressBookSave(self.addressBook, &error);
    if (!succeeded) {
        NSLog(@"There was an error modifying the contact: %@", (__bridge_transfer NSString*)CFErrorCopyDescription(error));
    }
}

- (void)_createContact {
    CFErrorRef error = NULL;
    self.contact = ABPersonCreate();
    bool succeeded = true;

    CFTypeRef firstName = [self _copyContactInfoFrom:self.firstName];
    if (firstName) {
        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonFirstNameProperty, firstName, &error);
        CFRelease(firstName);
    }

    CFTypeRef lastName = [self _copyContactInfoFrom:self.lastName];
    if (lastName) {
        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonLastNameProperty, lastName, &error);
        CFRelease(lastName);
    }

    CFTypeRef phoneNumber = [self _copyContactInfoFrom:self.phoneNumber];
    if (phoneNumber) {
        ABMutableMultiValueRef phoneNumbers = ABMultiValueCreateMutable(kABStringPropertyType);
        succeeded = succeeded && ABMultiValueAddValueAndLabel(phoneNumbers, phoneNumber, kABPersonPhoneMainLabel, NULL);
        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonPhoneProperty, phoneNumbers, &error);
        CFRelease(phoneNumbers);
        CFRelease(phoneNumber);
    }

    CFTypeRef email = [self _copyContactInfoFrom:self.email];
    if (email) {
        ABMutableMultiValueRef emails = ABMultiValueCreateMutable(kABStringPropertyType);
        succeeded = succeeded && ABMultiValueAddValueAndLabel(emails, email, kABWorkLabel, NULL);
        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonEmailProperty, emails, &error);
        CFRelease(emails);
        CFRelease(email);
    }

    CFTypeRef address = [self _copyContactInfoFrom:self.address];
    if (address) {
        ABMutableMultiValueRef addresses = ABMultiValueCreateMutable(kABDictionaryPropertyType);
        NSDictionary* homeAddress = @{ (NSString*) kABPersonAddressStreetKey : (__bridge NSString*)address };
        succeeded = succeeded && ABMultiValueAddValueAndLabel(addresses, (__bridge CFTypeRef)homeAddress, kABHomeLabel, NULL);
        succeeded = succeeded && ABRecordSetValue(self.contact, kABPersonAddressProperty, addresses, &error);
        CFRelease(addresses);
        CFRelease(address);
    }

    succeeded = succeeded && ABAddressBookAddRecord(self.addressBook, self.contact, &error);
    succeeded = succeeded && ABAddressBookSave(self.addressBook, &error);
    if (!succeeded) {
        NSLog(@"There was an error creating the contact: %@", (__bridge_transfer NSString*)CFErrorCopyDescription(error));
    }

    CFRelease(self.contact);
}

/**
 * UITextFieldDelegate/UIResponder methods to handle hiding the keyboard when necessary.
 */

- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)touchesBegan:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event {
    [self.view endEditing:YES];
    [super touchesBegan:touches withEvent:event];
}

@end
