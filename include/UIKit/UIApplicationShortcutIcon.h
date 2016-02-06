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
@class CNContact;

typedef enum UIApplicationShortcutIconType : NSInteger {
    UIApplicationShortcutIconTypeCompose,
    UIApplicationShortcutIconTypePlay,
    UIApplicationShortcutIconTypePause,
    UIApplicationShortcutIconTypeAdd,
    UIApplicationShortcutIconTypeLocation,
    UIApplicationShortcutIconTypeSearch,
    UIApplicationShortcutIconTypeShare,
    UIApplicationShortcutIconTypeProhibit,
    UIApplicationShortcutIconTypeContact,
    UIApplicationShortcutIconTypeHome,
    UIApplicationShortcutIconTypeMarkLocation,
    UIApplicationShortcutIconTypeFavorite,
    UIApplicationShortcutIconTypeLove,
    UIApplicationShortcutIconTypeCloud,
    UIApplicationShortcutIconTypeInvitation,
    UIApplicationShortcutIconTypeConfirmation,
    UIApplicationShortcutIconTypeMail,
    UIApplicationShortcutIconTypeMessage,
    UIApplicationShortcutIconTypeDate,
    UIApplicationShortcutIconTypeTime,
    UIApplicationShortcutIconTypeCapturePhoto,
    UIApplicationShortcutIconTypeCaptureVideo,
    UIApplicationShortcutIconTypeTask,
    UIApplicationShortcutIconTypeTaskCompleted,
    UIApplicationShortcutIconTypeAlarm,
    UIApplicationShortcutIconTypeBookmark,
    UIApplicationShortcutIconTypeShuffle,
    UIApplicationShortcutIconTypeAudio,
    UIApplicationShortcutIconTypeUpdate
} UIApplicationShortcutIconType;

UIKIT_EXPORT_CLASS
@interface UIApplicationShortcutIcon : NSObject <NSCopying>
+ (instancetype)iconWithType:(UIApplicationShortcutIconType)type STUB_METHOD;
+ (instancetype)iconWithTemplateImageName:(NSString*)templateImageName STUB_METHOD;
+ (instancetype)iconWithContact:(CNContact*)contact STUB_METHOD;
@end
