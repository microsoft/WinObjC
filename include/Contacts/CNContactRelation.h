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

CONTACTS_EXPORT NSString* const CNLabelContactRelationFather;
CONTACTS_EXPORT NSString* const CNLabelContactRelationMother;
CONTACTS_EXPORT NSString* const CNLabelContactRelationParent;
CONTACTS_EXPORT NSString* const CNLabelContactRelationBrother;
CONTACTS_EXPORT NSString* const CNLabelContactRelationSister;
CONTACTS_EXPORT NSString* const CNLabelContactRelationChild;
CONTACTS_EXPORT NSString* const CNLabelContactRelationFriend;
CONTACTS_EXPORT NSString* const CNLabelContactRelationSpouse;
CONTACTS_EXPORT NSString* const CNLabelContactRelationPartner;
CONTACTS_EXPORT NSString* const CNLabelContactRelationAssistant;
CONTACTS_EXPORT NSString* const CNLabelContactRelationManager;

CONTACTS_EXPORT_CLASS
@interface CNContactRelation : NSObject <NSCopying, NSSecureCoding>
+ (instancetype)contactRelationWithName:(NSString*)name STUB_METHOD;
- (instancetype)initWithName:(NSString*)name STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
@end
