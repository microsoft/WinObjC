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

#import <AddressBookUI/AddressBookUIExport.h>
#import <Foundation/NSObject.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABAddressBook.h>
#import <AddressBook/ABMultiValue.h>
#import <UIKit/UIViewController.h>

@class NSArray;

@protocol UIAppearanceContainer;
@protocol UIContentContainer;
@protocol UIFocusEnvironment;
@protocol UITraitEnvironment;
@protocol UIViewControllerRestoration;
@protocol ABPersonViewControllerDelegate;

ADDRESSBOOKUI_EXPORT_CLASS
@interface ABPersonViewController : UIViewController <NSCoding,
                                                      NSObject,
                                                      UIAppearanceContainer,
                                                      UIContentContainer,
                                                      UIFocusEnvironment,
                                                      UITraitEnvironment,
                                                      UIViewControllerRestoration>
@property (readwrite, nonatomic) ABRecordRef displayedPerson STUB_PROPERTY;
@property (copy, nonatomic) NSArray* displayedProperties STUB_PROPERTY;
@property (nonatomic) BOOL shouldShowLinkedPeople STUB_PROPERTY;
@property (readwrite, nonatomic) ABAddressBookRef addressBook STUB_PROPERTY;
@property (nonatomic) BOOL allowsActions STUB_PROPERTY;
@property (nonatomic) BOOL allowsEditing STUB_PROPERTY;
- (void)setHighlightedItemForProperty:(ABPropertyID)property withIdentifier:(ABMultiValueIdentifier)identifier STUB_METHOD;
@property (assign, nonatomic) id<ABPersonViewControllerDelegate> personViewDelegate STUB_PROPERTY;

@end
