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

CONTACTS_EXPORT NSString* const CNSocialProfileURLStringKey;
CONTACTS_EXPORT NSString* const CNSocialProfileUsernameKey;
CONTACTS_EXPORT NSString* const CNSocialProfileUserIdentifierKey;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceKey;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceFacebook;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceFlickr;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceLinkedIn;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceSinaWeibo;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceTencentWeibo;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceTwitter;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceYelp;
CONTACTS_EXPORT NSString* const CNSocialProfileServiceGameCenter;

CONTACTS_EXPORT_CLASS
@interface CNSocialProfile : NSObject <NSCopying, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* service STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* urlString STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* userIdentifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* username STUB_PROPERTY;
+ (NSString*)localizedStringForKey:(NSString*)key STUB_METHOD;
+ (NSString*)localizedStringForService:(NSString*)service STUB_METHOD;
@end
