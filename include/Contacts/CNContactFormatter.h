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
#import <Foundation/NSFormatter.h>

@class NSAttributedString;
@class CNContact;
@class NSDictionary;
@class NSString;
@class NSFormatter;

typedef NS_ENUM(NSInteger, CNContactFormatterStyle) { CNContactFormatterStyleFullName, CNContactFormatterStylePhoneticFullName };

typedef NS_ENUM(NSInteger, CNContactDisplayNameOrder) {
    CNContactDisplayNameOrderUserDefault,
    CNContactDisplayNameOrderGivenNameFirst,
    CNContactDisplayNameOrderFamilyNameFirst
};

CONTACTS_EXPORT_CLASS
@interface CNContactFormatter : NSFormatter <NSCoding, NSCopying>
+ (NSAttributedString*)attributedStringFromContact:(CNContact*)contact
                                             style:(CNContactFormatterStyle)style
                                 defaultAttributes:(NSDictionary*)attributes STUB_METHOD;
+ (NSString*)stringFromContact:(CNContact*)contact style:(CNContactFormatterStyle)style STUB_METHOD;
- (NSString*)stringFromContact:(CNContact*)contact STUB_METHOD;
- (NSAttributedString*)attributedStringFromContact:(CNContact*)contact defaultAttributes:(NSDictionary*)attributes STUB_METHOD;
+ (NSString*)delimiterForContact:(CNContact*)contact STUB_METHOD;
+ (CNContactDisplayNameOrder)nameOrderForContact:(CNContact*)contact STUB_METHOD;
@property (nonatomic) CNContactFormatterStyle style STUB_PROPERTY;
@end
