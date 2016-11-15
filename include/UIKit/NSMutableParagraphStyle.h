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
#import <Foundation/NSObject.h>
#import <UIKit/NSParagraphStyle.h>

@class NSTextTab;
@class NSArray;

UIKIT_EXPORT_CLASS
@interface NSMutableParagraphStyle : NSParagraphStyle <NSCopying, NSMutableCopying, NSSecureCoding>
- (void)setParagraphStyle:(NSParagraphStyle*)obj;
@property (nonatomic) NSTextAlignment alignment;
@property (nonatomic) CGFloat firstLineHeadIndent;
@property (nonatomic) CGFloat headIndent;
@property (nonatomic) CGFloat tailIndent;
@property (nonatomic) NSLineBreakMode lineBreakMode;
@property (nonatomic) CGFloat maximumLineHeight;
@property (nonatomic) CGFloat minimumLineHeight;
@property (nonatomic) CGFloat lineSpacing;
@property (nonatomic) CGFloat paragraphSpacing;
@property (nonatomic) CGFloat paragraphSpacingBefore;
@property (nonatomic) NSWritingDirection baseWritingDirection;
@property (nonatomic) CGFloat lineHeightMultiple;
- (void)addTabStop:(NSTextTab*)anObject STUB_METHOD;
- (void)removeTabStop:(NSTextTab*)anObject STUB_METHOD;
@property (copy, nonatomic) NSArray* tabStops;
@property (nonatomic) CGFloat defaultTabInterval;
@property (nonatomic) float hyphenationFactor;

@end
