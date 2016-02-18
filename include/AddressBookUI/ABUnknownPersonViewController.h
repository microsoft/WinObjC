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
#import <UIKit/UIViewController.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABAddressBook.h>

@class NSString;

@protocol UIAppearanceContainer;
@protocol UIContentContainer;
@protocol UIFocusEnvironment;
@protocol UITraitEnvironment;
@protocol ABUnknownPersonViewControllerDelegate;

ADDRESSBOOKUI_EXPORT_CLASS
@interface ABUnknownPersonViewController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

@property (copy, nonatomic) NSString* alternateName STUB_PROPERTY;
@property (copy, nonatomic) NSString* message STUB_PROPERTY;
@property (readwrite, nonatomic) ABRecordRef displayedPerson STUB_PROPERTY;
@property (readwrite, nonatomic) ABAddressBookRef addressBook STUB_PROPERTY;
@property (nonatomic) BOOL allowsActions STUB_PROPERTY;
@property (nonatomic) BOOL allowsAddingToAddressBook STUB_PROPERTY;
@property (assign, nonatomic) id<ABUnknownPersonViewControllerDelegate> unknownPersonViewDelegate STUB_PROPERTY;

@end
