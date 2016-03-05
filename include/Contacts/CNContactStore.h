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
#import <Foundation/NSError.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSPredicate.h>

@class NSString;
@class CNContact;
@class NSArray;
@class NSError;
@class NSPredicate;
@class CNContactFetchRequest;
@class CNSaveRequest;

typedef NS_ENUM(NSInteger, CNEntityType) { CNEntityTypeContacts };

typedef NS_ENUM(NSInteger, CNAuthorizationStatus) {
    CNAuthorizationStatusNotDetermined,
    CNAuthorizationStatusRestricted,
    CNAuthorizationStatusDenied,
    CNAuthorizationStatusAuthorized
};

CONTACTS_EXPORT NSString* const CNContactStoreDidChangeNotification;

CONTACTS_EXPORT_CLASS
@interface CNContactStore : NSObject
- (CNContact*)unifiedContactWithIdentifier:(NSString*)identifier keysToFetch:(NSArray*)keys error:(NSError* _Nullable*)error STUB_METHOD;
- (NSArray*)unifiedContactsMatchingPredicate:(NSPredicate*)predicate
                                 keysToFetch:(NSArray*)keys
                                       error:(NSError* _Nullable*)error STUB_METHOD;
+ (CNAuthorizationStatus)authorizationStatusForEntityType:(CNEntityType)entityType STUB_METHOD;
- (void)requestAccessForEntityType:(CNEntityType)entityType completionHandler:(void (^)(BOOL, NSError*))completionHandler STUB_METHOD;
- (NSArray*)groupsMatchingPredicate:(NSPredicate*)predicate error:(NSError* _Nullable*)error STUB_METHOD;
- (NSArray*)containersMatchingPredicate:(NSPredicate*)predicate error:(NSError* _Nullable*)error STUB_METHOD;
- (NSString*)defaultContainerIdentifier STUB_METHOD;
- (BOOL)enumerateContactsWithFetchRequest:(CNContactFetchRequest*)fetchRequest
                                    error:(NSError* _Nullable*)error
                               usingBlock:(void (^)(CNContact*, BOOL*))block STUB_METHOD;
- (BOOL)executeSaveRequest:(CNSaveRequest*)saveRequest error:(NSError* _Nullable*)error STUB_METHOD;
@end
