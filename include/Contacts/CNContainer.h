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
@class NSPredicate;
@class NSArray;

typedef NS_ENUM(NSInteger, CNContainerType) { CNContainerTypeLocal, CNContainerTypeExchange, CNContainerTypeCardDAV };

CONTACTS_EXPORT NSString* const CNContainerIdentifierKey;
CONTACTS_EXPORT NSString* const CNContainerNameKey;
CONTACTS_EXPORT NSString* const CNContainerTypeKey;

CONTACTS_EXPORT_CLASS
@interface CNContainer : NSObject <NSCopying, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) CNContainerType type STUB_PROPERTY;
+ (NSPredicate*)predicateForContainerOfContactWithIdentifier:(NSString*)contactIdentifier STUB_METHOD;
+ (NSPredicate*)predicateForContainersWithIdentifiers:(NSArray*)identifiers STUB_METHOD;
+ (NSPredicate*)predicateForContainerOfGroupWithIdentifier:(NSString*)groupIdentifier STUB_METHOD;
@end
