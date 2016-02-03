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
#import <Contacts/CNContact.h>

@class NSArray;
@class NSDateComponents;
@class NSString;
@class NSData;

CONTACTS_EXPORT_CLASS
@interface CNMutableContact : CNContact <NSCopying, NSMutableCopying, NSSecureCoding>
@property (nonatomic) CNContactType contactType STUB_PROPERTY;
@property (copy, nonatomic) NSArray* dates STUB_PROPERTY;
@property (copy, nonatomic) NSDateComponents* nonGregorianBirthday STUB_PROPERTY;
@property (copy, nonatomic) NSDateComponents* birthday STUB_PROPERTY;
@property (copy, nonatomic) NSString* namePrefix STUB_PROPERTY;
@property (copy, nonatomic) NSString* givenName STUB_PROPERTY;
@property (copy, nonatomic) NSString* middleName STUB_PROPERTY;
@property (copy, nonatomic) NSString* familyName STUB_PROPERTY;
@property (copy, nonatomic) NSString* previousFamilyName STUB_PROPERTY;
@property (copy, nonatomic) NSString* nameSuffix STUB_PROPERTY;
@property (copy, nonatomic) NSString* nickname STUB_PROPERTY;
@property (copy, nonatomic) NSString* phoneticGivenName STUB_PROPERTY;
@property (copy, nonatomic) NSString* phoneticMiddleName STUB_PROPERTY;
@property (copy, nonatomic) NSString* phoneticFamilyName STUB_PROPERTY;
@property (copy, nonatomic) NSString* organizationName STUB_PROPERTY;
@property (copy, nonatomic) NSString* departmentName STUB_PROPERTY;
@property (copy, nonatomic) NSString* jobTitle STUB_PROPERTY;
@property (copy, nonatomic) NSArray* socialProfiles STUB_PROPERTY;
@property (copy, nonatomic) NSArray* phoneNumbers STUB_PROPERTY;
@property (copy, nonatomic) NSArray* emailAddresses STUB_PROPERTY;
@property (copy, nonatomic) NSArray* urlAddresses STUB_PROPERTY;
@property (copy, nonatomic) NSArray* postalAddresses STUB_PROPERTY;
@property (copy, nonatomic) NSString* note STUB_PROPERTY;
@property (copy, nonatomic) NSData* imageData STUB_PROPERTY;
@property (copy, nonatomic) NSArray* contactRelations STUB_PROPERTY;
@property (copy, nonatomic) NSArray* instantMessageAddresses STUB_PROPERTY;
@end
