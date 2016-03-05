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
#import <UIKit/UIKitTypes.h>

@class NSString;
@class NSDictionary;
@class NSCharacterSet;
@class NSLocale;

UIKIT_EXPORT NSString* const NSTabColumnTerminatorsAttributeName;

UIKIT_EXPORT_CLASS
@interface NSTextTab : NSObject <NSCoding, NSCopying>
- (instancetype)initWithTextAlignment:(NSTextAlignment)alignment location:(CGFloat)loc options:(NSDictionary*)options STUB_METHOD;
+ (NSCharacterSet*)columnTerminatorsForLocale:(NSLocale*)aLocale STUB_METHOD;
@property (readonly, nonatomic) NSDictionary* options STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat location STUB_PROPERTY;
@property (readonly, nonatomic) NSTextAlignment alignment STUB_PROPERTY;
@end
