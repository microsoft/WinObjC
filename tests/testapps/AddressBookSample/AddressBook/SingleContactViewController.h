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

#import <AddressBook/ABAddressBook.h>
#import <UIKit/UIKit.h>

@interface SingleContactViewController : UIViewController <UITextFieldDelegate>

- (IBAction)buttonPressed:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField* firstName;
@property (weak, nonatomic) IBOutlet UITextField* lastName;
@property (weak, nonatomic) IBOutlet UITextField* phoneNumber;
@property (weak, nonatomic) IBOutlet UITextField* email;
@property (weak, nonatomic) IBOutlet UITextField* address;
@property (weak, nonatomic) IBOutlet UIImageView* contactPhoto;
@property (weak, nonatomic) IBOutlet UIButton* button;
@property (nonatomic) enum ContactOperation contactOperation;
@property ABRecordRef contact;
@property ABAddressBookRef addressBook;

@end
