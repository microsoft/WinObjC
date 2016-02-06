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
#import <UIKit/UIUserNotificationAction.h>

@class NSString;
@class NSDictionary;

UIKIT_EXPORT_CLASS
@interface UIMutableUserNotificationAction : UIUserNotificationAction <NSCopying, NSMutableCopying, NSObject, NSSecureCoding>
@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (copy, nonatomic) NSString* title STUB_PROPERTY;
@property (assign, nonatomic) UIUserNotificationActivationMode activationMode STUB_PROPERTY;
@property (getter=isAuthenticationRequired, assign, nonatomic) BOOL authenticationRequired STUB_PROPERTY;
@property (getter=isDestructive, assign, nonatomic) BOOL destructive STUB_PROPERTY;
@property (assign, nonatomic) UIUserNotificationActionBehavior behavior STUB_PROPERTY;
@property (copy, nonatomic) NSDictionary* parameters STUB_PROPERTY;
@end
