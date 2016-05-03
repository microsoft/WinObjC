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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/NSParagraphStyle.h>

@class NSTextTab;
@class NSArray;

UIKIT_EXPORT_CLASS
@interface NSMutableParagraphStyle : NSParagraphStyle <NSCopying, NSMutableCopying, NSSecureCoding>
- (void)setParagraphStyle:(NSParagraphStyle*)obj STUB_METHOD;
@property (nonatomic) NSTextAlignment alignment STUB_PROPERTY;
@property (nonatomic) CGFloat firstLineHeadIndent STUB_PROPERTY;
@property (nonatomic) CGFloat headIndent STUB_PROPERTY;
@property (nonatomic) CGFloat tailIndent STUB_PROPERTY;
@property (nonatomic) NSLineBreakMode lineBreakMode;
@property (nonatomic) CGFloat maximumLineHeight STUB_PROPERTY;
@property (nonatomic) CGFloat minimumLineHeight STUB_PROPERTY;
@property (nonatomic) CGFloat lineSpacing STUB_PROPERTY;
@property (nonatomic) CGFloat paragraphSpacing STUB_PROPERTY;
@property (nonatomic) CGFloat paragraphSpacingBefore STUB_PROPERTY;
@property (nonatomic) NSWritingDirection baseWritingDirection STUB_PROPERTY;
@property (nonatomic) CGFloat lineHeightMultiple STUB_PROPERTY;
- (void)addTabStop:(NSTextTab*)anObject STUB_METHOD;
- (void)removeTabStop:(NSTextTab*)anObject STUB_METHOD;
@property (copy, nonatomic) NSArray* tabStops STUB_PROPERTY;
@property (nonatomic) CGFloat defaultTabInterval STUB_PROPERTY;
@property (nonatomic) float hyphenationFactor STUB_PROPERTY;

@end
