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

#import <Contacts/ContactsExport.h>
#import <Foundation/NSObject.h>

@class NSString;

CONTACTS_EXPORT NSString* const CNLabelPhoneNumberiPhone;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberMobile;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberMain;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberHomeFax;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberWorkFax;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberOtherFax;
CONTACTS_EXPORT NSString* const CNLabelPhoneNumberPager;

CONTACTS_EXPORT_CLASS
@interface CNPhoneNumber : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithStringValue:(NSString*)string STUB_METHOD;
+ (instancetype)phoneNumberWithStringValue:(NSString*)stringValue STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* stringValue STUB_PROPERTY;
@end
