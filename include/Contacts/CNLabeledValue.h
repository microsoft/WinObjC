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

CONTACTS_EXPORT NSString* const CNLabelHome;
CONTACTS_EXPORT NSString* const CNLabelWork;
CONTACTS_EXPORT NSString* const CNLabelOther;
CONTACTS_EXPORT NSString* const CNLabelEmailiCloud;
CONTACTS_EXPORT NSString* const CNLabelURLAddressHomePage;
CONTACTS_EXPORT NSString* const CNLabelDateAnniversary;

CONTACTS_EXPORT_CLASS
@interface CNLabeledValue : NSObject <NSCopying, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
- (instancetype)initWithLabel:(NSString*)label value:(id<NSCopying>)value STUB_METHOD;
+ (instancetype)labeledValueWithLabel:(NSString*)label value:(id<NSCopying>)value STUB_METHOD;
- (instancetype)labeledValueBySettingLabel:(NSString*)label STUB_METHOD;
- (instancetype)labeledValueBySettingLabel:(NSString*)label value:(id<NSCopying>)value STUB_METHOD;
- (instancetype)labeledValueBySettingValue:(id<NSCopying>)value STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* label STUB_PROPERTY;
@property (readonly, copy, nonatomic) id<NSCopying> value STUB_PROPERTY;
+ (NSString*)localizedStringForLabel:(NSString*)label STUB_METHOD;
@end
