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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSAttributedString;
@class NSDictionary;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSExtensionItemAttributedTitleKey;
FOUNDATION_EXPORT NSString* const NSExtensionItemAttributedContentTextKey;
FOUNDATION_EXPORT NSString* const NSExtensionItemAttachmentsKey;

FOUNDATION_EXPORT_CLASS
@interface NSExtensionItem : NSObject <NSCopying, NSSecureCoding>
@property (copy, nonatomic) NSAttributedString* attributedTitle STUB_PROPERTY;
@property (copy, nonatomic) NSDictionary* userInfo STUB_PROPERTY;
@property (copy, nonatomic) NSArray* attachments STUB_PROPERTY;
@property (copy, nonatomic) NSAttributedString* attributedContentText STUB_PROPERTY;
@end
