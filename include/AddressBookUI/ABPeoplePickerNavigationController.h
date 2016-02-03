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
#import <UIKit/UINavigationController.h>
#import <AddressBook/ABAddressBook.h>

@class NSString;
@class NSArray;

@protocol UIAppearanceContainer;
@protocol UIContentContainer;
@protocol UIFocusEnvironment;
@protocol UITraitEnvironment;
@protocol ABPeoplePickerNavigationControllerDelegate;

@class NSPredicate;

ADDRESSBOOKUI_EXPORT NSString* const ABPersonNamePrefixProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonGivenNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonMiddleNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonFamilyNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonNameSuffixProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPreviousFamilyNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonNicknameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPhoneticGivenNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPhoneticMiddleNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPhoneticFamilyNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonOrganizationNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonDepartmentNameProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonJobTitleProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonBirthdayProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonNoteProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPhoneNumbersProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonEmailAddressesProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonUrlAddressesProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonDatesProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonInstantMessageAddressesProperty;

ADDRESSBOOKUI_EXPORT NSString* const ABPersonRelatedNamesProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonSocialProfilesProperty;
ADDRESSBOOKUI_EXPORT NSString* const ABPersonPostalAddressesProperty;

ADDRESSBOOKUI_EXPORT_CLASS
@interface ABPeoplePickerNavigationController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

@property (copy, nonatomic) NSArray* displayedProperties STUB_PROPERTY;
@property (readwrite, nonatomic) ABAddressBookRef addressBook STUB_PROPERTY;
@property (assign, nonatomic) id<ABPeoplePickerNavigationControllerDelegate> peoplePickerDelegate STUB_PROPERTY;
@property (copy, nonatomic) NSPredicate* predicateForEnablingPerson STUB_PROPERTY;
@property (copy, nonatomic) NSPredicate* predicateForSelectionOfPerson STUB_PROPERTY;
@property (copy, nonatomic) NSPredicate* predicateForSelectionOfProperty STUB_PROPERTY;

@end
