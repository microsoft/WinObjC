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
#import <UIKit/UIKitTypes.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIPrintFormatter.h>

@class NSAttributedString;
@class NSString;
@class UIFont;
@class UIColor;

UIKIT_EXPORT_CLASS
@interface UISimpleTextPrintFormatter : UIPrintFormatter <NSCopying>
- (instancetype)initWithAttributedText:(NSAttributedString*)attributedText STUB_METHOD;
- (instancetype)initWithText:(NSString*)text STUB_METHOD;
@property (copy, nonatomic) NSAttributedString* attributedText STUB_PROPERTY;
@property (copy, nonatomic) NSString* text STUB_PROPERTY;
@property (nonatomic, strong) UIFont* font STUB_PROPERTY;
@property (nonatomic, strong) UIColor* color STUB_PROPERTY;
@property (nonatomic) NSTextAlignment textAlignment STUB_PROPERTY;
@end
