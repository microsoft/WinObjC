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
#import <UIKit/UIPreviewActionItem.h>

@class NSString;
@class UIViewController;

UIKIT_EXPORT_CLASS
@interface UIPreviewAction : NSObject <NSCopying, NSObject, UIPreviewActionItem>
+ (instancetype)actionWithTitle:(NSString*)title
                          style:(UIPreviewActionStyle)style
                        handler:(void (^)(UIPreviewAction*, UIViewController*))handler STUB_METHOD;
@property (readonly, copy, nonatomic, nonnull) void (^handler)(id<UIPreviewActionItem>, UIViewController*) STUB_PROPERTY;
@end
