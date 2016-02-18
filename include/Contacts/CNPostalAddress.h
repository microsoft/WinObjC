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

CONTACTS_EXPORT NSString* const CNPostalAddressStreetKey;
CONTACTS_EXPORT NSString* const CNPostalAddressCityKey;
CONTACTS_EXPORT NSString* const CNPostalAddressStateKey;
CONTACTS_EXPORT NSString* const CNPostalAddressPostalCodeKey;
CONTACTS_EXPORT NSString* const CNPostalAddressCountryKey;
CONTACTS_EXPORT NSString* const CNPostalAddressISOCountryCodeKey;

CONTACTS_EXPORT_CLASS
@interface CNPostalAddress : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* street STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* city STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* state STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* postalCode STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* country STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* ISOCountryCode STUB_PROPERTY;
+ (NSString*)localizedStringForKey:(NSString*)key STUB_METHOD;
@end
