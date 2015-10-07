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

#ifndef _UILOCALNOTIFICATION_H_
#define _UILOCALNOTIFICATION_H_

#import "UIKitExport.h"
#import <Foundation/NSObject.h>
#import <Foundation/NSCalendar.h>

UIKIT_EXPORT_CLASS
@interface UILocalNotification : NSObject {
}

@property(nonatomic, copy) NSDate *fireDate;
@property(nonatomic, copy) NSString *alertBody;
@property(nonatomic, copy) NSTimeZone *timeZone;
@property(nonatomic, copy) NSString *soundName;
@property(nonatomic) NSInteger applicationIconBadgeNumber;
@property(nonatomic, copy) NSString *alertAction;
@property(nonatomic) NSCalendarUnit repeatInterval;
@property(nonatomic, copy) NSDictionary *userInfo;

@end

extern NSString *UILocalNotificationDefaultSoundName;

#endif /* _UILOCALNOTIFICATION_H_ */
