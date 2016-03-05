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

@protocol CNKeyDescriptor;
@class NSData;
@class NSArray;
@class NSError;

CONTACTS_EXPORT_CLASS
@interface CNContactVCardSerialization : NSObject
+ (NSData*)dataWithContacts:(NSArray*)contacts error:(NSError* _Nullable*)error STUB_METHOD;
+ (NSArray*)contactsWithData:(NSData*)data error:(NSError* _Nullable*)error STUB_METHOD;
+ (id<CNKeyDescriptor>)descriptorForRequiredKeys STUB_METHOD;
@end
