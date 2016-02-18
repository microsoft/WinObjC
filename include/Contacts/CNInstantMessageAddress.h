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

CONTACTS_EXPORT NSString* const CNInstantMessageAddressUsernameKey;
CONTACTS_EXPORT NSString* const CNInstantMessageAddressServiceKey;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceAIM;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceFacebook;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceGaduGadu;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceGoogleTalk;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceICQ;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceJabber;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceMSN;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceQQ;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceSkype;
CONTACTS_EXPORT NSString* const CNInstantMessageServiceYahoo;

CONTACTS_EXPORT_CLASS
@interface CNInstantMessageAddress : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithUsername:(NSString*)username service:(NSString*)service STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* service STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* username STUB_PROPERTY;
+ (NSString*)localizedStringForKey:(NSString*)key STUB_METHOD;
+ (NSString*)localizedStringForService:(NSString*)service STUB_METHOD;
@end
