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
#import <Contacts/CNPostalAddress.h>

@class NSString;

CONTACTS_EXPORT_CLASS
@interface CNMutablePostalAddress : CNPostalAddress <NSCopying, NSMutableCopying, NSSecureCoding>
@property (copy, nonatomic) NSString* street STUB_PROPERTY;
@property (copy, nonatomic) NSString* city STUB_PROPERTY;
@property (copy, nonatomic) NSString* state STUB_PROPERTY;
@property (copy, nonatomic) NSString* postalCode STUB_PROPERTY;
@property (copy, nonatomic) NSString* country STUB_PROPERTY;
@property (copy, nonatomic) NSString* ISOCountryCode STUB_PROPERTY;
@end
