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

#include "UIKitExport.h"

#ifndef _UIUSERNOTIFICATIONSETTINGS_H_
#define _UIUSERNOTIFICATIONSETTINGS_H_

typedef enum UIUserNotificationType : NSUInteger {
    UIUserNotificationTypeNone = 0,
    UIUserNotificationTypeBadge = 1 << 0,
    UIUserNotificationTypeSound = 1 << 1,
    UIUserNotificationTypeAlert = 1 << 2,
} UIUserNotificationType;

UIKIT_EXPORT_CLASS
@interface UIUserNotificationSettings : NSObject <NSObject>

@property (nonatomic, readonly) UIUserNotificationType types;
@property (nonatomic, copy, readonly) NSSet* categories;

+ (instancetype)settingsForTypes:(UIUserNotificationType)allowedUserNotificationTypes categories:(NSSet*)actionSettings;

@end

#endif /* _UIUSERNOTIFICATIONSETTINGS_H_ */
