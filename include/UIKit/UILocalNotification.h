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

#pragma once

#import "UIKitExport.h"
#import <Foundation/NSObject.h>
#import <Foundation/NSCalendar.h>

UIKIT_EXPORT extern NSString* const UILocalNotificationDefaultSoundName;

@class NSDictionary;

UIKIT_EXPORT_CLASS
@interface UILocalNotification : NSObject

@property (nonatomic, copy) NSDate* fireDate STUB_PROPERTY;
@property (nonatomic, copy) NSString* alertBody;
@property (nonatomic, copy) NSTimeZone* timeZone STUB_PROPERTY;
@property (nonatomic, copy) NSString* soundName STUB_PROPERTY;
@property (nonatomic) NSInteger applicationIconBadgeNumber STUB_PROPERTY;
@property (nonatomic, copy) NSString* alertAction;
@property (nonatomic) NSCalendarUnit repeatInterval STUB_PROPERTY;
@property (nonatomic, copy) NSDictionary* userInfo STUB_PROPERTY;
@property (nonatomic, copy) NSString* category STUB_PROPERTY;

@end
