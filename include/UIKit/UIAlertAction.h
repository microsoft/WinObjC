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
#import <Foundation/Foundation.h>

@class NSString;

typedef enum UIAlertActionStyle : NSInteger {
    UIAlertActionStyleDefault = 0,
    UIAlertActionStyleCancel,
    UIAlertActionStyleDestructive,
} UIAlertActionStyle;

UIKIT_EXPORT_CLASS
@interface UIAlertAction : NSObject <NSCopying>
+ (instancetype)actionWithTitle:(NSString*)title style:(UIAlertActionStyle)style handler:(void (^)(UIAlertAction*))handler STUB_METHOD;
@property (readonly, nonatomic) NSString* title STUB_PROPERTY;
@property (readonly, nonatomic) UIAlertActionStyle style STUB_PROPERTY;
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@end
