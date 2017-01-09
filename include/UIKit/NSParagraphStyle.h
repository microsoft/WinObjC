//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <UIKit/NSString+UIKitAdditions.h>
#import <Foundation/NSObject.h>

@class NSDictionary;
@class NSCharacterSet;
@class NSLocale;
@class NSArray;
@class NSTextTab;

UIKIT_EXPORT_CLASS
@interface NSParagraphStyle : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

+ (NSParagraphStyle*)defaultParagraphStyle;
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString*)languageName;

@property (readonly, nonatomic) NSTextAlignment alignment;
@property (readonly, nonatomic) CGFloat firstLineHeadIndent;
@property (readonly, nonatomic) CGFloat headIndent;
@property (readonly, nonatomic) CGFloat tailIndent;
@property (readonly, nonatomic) CGFloat lineHeightMultiple;
@property (readonly, nonatomic) CGFloat maximumLineHeight;
@property (readonly, nonatomic) CGFloat minimumLineHeight;
@property (readonly, nonatomic) CGFloat lineSpacing;
@property (readonly, nonatomic) CGFloat paragraphSpacing;
@property (readonly, nonatomic) CGFloat paragraphSpacingBefore;
@property (readonly, copy, nonatomic) NSArray* tabStops;
@property (readonly, nonatomic) CGFloat defaultTabInterval;
@property (readonly, nonatomic) NSLineBreakMode lineBreakMode;
@property (readonly, nonatomic) float hyphenationFactor;
@property (readonly, nonatomic) NSWritingDirection baseWritingDirection;

@end
