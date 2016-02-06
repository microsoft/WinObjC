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

@class NSString;
@class UIApplicationShortcutIcon;
@class NSDictionary;

UIKIT_EXPORT_CLASS
@interface UIApplicationShortcutItem : NSObject <NSCopying, NSMutableCopying>
- (instancetype)initWithType:(NSString*)type localizedTitle:(NSString*)localizedTitle STUB_METHOD;
- (instancetype)initWithType:(NSString*)type
              localizedTitle:(NSString*)localizedTitle
           localizedSubtitle:(NSString*)localizedSubtitle
                        icon:(UIApplicationShortcutIcon*)icon
                    userInfo:(NSDictionary*)userInfo STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* localizedTitle STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* localizedSubtitle STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* type STUB_PROPERTY;
@property (readonly, copy, nonatomic) UIApplicationShortcutIcon* icon STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDictionary* userInfo STUB_PROPERTY;
@end
