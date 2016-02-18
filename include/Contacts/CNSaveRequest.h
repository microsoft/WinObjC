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

@class CNMutableContact;
@class NSString;
@class CNMutableGroup;
@class CNContact;
@class CNGroup;

CONTACTS_EXPORT_CLASS
@interface CNSaveRequest : NSObject
- (void)addContact:(CNMutableContact*)contact toContainerWithIdentifier:(NSString*)identifier STUB_METHOD;
- (void)updateContact:(CNMutableContact*)contact STUB_METHOD;
- (void)deleteContact:(CNMutableContact*)contact STUB_METHOD;
- (void)addGroup:(CNMutableGroup*)group toContainerWithIdentifier:(NSString*)identifier STUB_METHOD;
- (void)updateGroup:(CNMutableGroup*)group STUB_METHOD;
- (void)deleteGroup:(CNMutableGroup*)group STUB_METHOD;
- (void)addMember:(CNContact*)contact toGroup:(CNGroup*)group STUB_METHOD;
- (void)removeMember:(CNContact*)contact fromGroup:(CNGroup*)group STUB_METHOD;
@end
