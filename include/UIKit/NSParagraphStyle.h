//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _NSPARAGRAPHSTYLE_H_
#define _NSPARAGRAPHSTYLE_H_

#import <Foundation/NSObject.h>
#import <UIKit/UIKitExport.h>
#import <UIKit/NSText.h>

// NSString *const NSTabColumnTerminatorsAttributeName  = @"NSTabColumnTerminatorsAttributeName";

UIKIT_EXPORT_CLASS
@interface NSTextTab : NSObject
- (instancetype)initWithTextAlignment:(NSTextAlignment)alignment location:(CGFloat)loc options:(NSDictionary*)options;
+ (NSCharacterSet*)columnTerminatorsForLocale:(NSLocale*)aLocale;
@property (readonly, nonatomic) NSDictionary* options;
@property (readonly, nonatomic) CGFloat location;
@property (readonly, nonatomic) NSTextAlignment alignment;
@end

UIKIT_EXPORT_CLASS
@interface NSParagraphStyle : NSObject

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

UIKIT_EXPORT_CLASS
@interface NSMutableParagraphStyle : NSParagraphStyle

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

- (void)addTabStop:(NSTextTab*)anObject;
- (void)removeTabStop:(NSTextTab*)anObject;
@property (copy, nonatomic) NSArray* tabStops;
@property (nonatomic) CGFloat defaultTabInterval;

@property (nonatomic) float hyphenationFactor;

@end

#endif /* _NSPARAGRAPHSTYLE_H_ */
