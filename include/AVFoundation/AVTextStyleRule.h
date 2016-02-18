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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSDictionary;
@class NSString;

AVFOUNDATION_EXPORT_CLASS
@interface AVTextStyleRule : NSObject <NSCopying>
+ (NSArray*)textStyleRulesFromPropertyList:(id)plist STUB_METHOD;
+ (AVTextStyleRule*)textStyleRuleWithTextMarkupAttributes:(NSDictionary*)textMarkupAttributes STUB_METHOD;
+ (AVTextStyleRule*)textStyleRuleWithTextMarkupAttributes:(NSDictionary*)textMarkupAttributes
                                             textSelector:(NSString*)textSelector STUB_METHOD;
- (instancetype)initWithTextMarkupAttributes:(NSDictionary*)textMarkupAttributes STUB_METHOD;
- (instancetype)initWithTextMarkupAttributes:(NSDictionary*)textMarkupAttributes textSelector:(NSString*)textSelector STUB_METHOD;
@property (readonly, nonatomic) NSDictionary* textMarkupAttributes STUB_PROPERTY;
@property (readonly, nonatomic) NSString* textSelector STUB_PROPERTY;
+ (id)propertyListForTextStyleRules:(NSArray*)textStyleRules STUB_METHOD;
@end
