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
@class NSArray;

typedef enum UIUserNotificationActionContext : NSUInteger {
    UIUserNotificationActionContextDefault,
    UIUserNotificationActionContextMinimal,
} UIUserNotificationActionContext;

UIKIT_EXPORT_CLASS
@interface UIUserNotificationCategory : NSObject <NSCopying, NSMutableCopying, NSObject, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
- (NSArray*)actionsForContext:(UIUserNotificationActionContext)context STUB_METHOD;
@end
