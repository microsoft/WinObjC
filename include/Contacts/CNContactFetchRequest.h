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
#import <Contacts/CNContact.h>

@class NSArray;
@class NSPredicate;

CONTACTS_EXPORT_CLASS
@interface CNContactFetchRequest : NSObject
@property (nonatomic) BOOL mutableObjects STUB_PROPERTY;
@property (nonatomic) BOOL unifyResults STUB_PROPERTY;
@property (nonatomic) CNContactSortOrder sortOrder STUB_PROPERTY;
- (instancetype)initWithKeysToFetch:(NSArray*)keysToFetch STUB_METHOD;
@property (copy, nonatomic) NSArray* keysToFetch STUB_PROPERTY;
@property (copy, nonatomic) NSPredicate* predicate STUB_PROPERTY;
@end
