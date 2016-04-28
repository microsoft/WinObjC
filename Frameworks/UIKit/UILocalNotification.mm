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

#import <StubReturn.h>
#import "Starboard.h"
#import "Foundation/NSCalendar.h"
#import "Foundation/NSCoder.h"
#import "Foundation/NSDate.h"
#import "Foundation/NSDictionary.h"
#import "Foundation/NSString.h"
#import "Foundation/NSTimeZone.h"
#import "LoggingNative.h"

static const wchar_t* TAG = L"UILocalNotification";

NSString* const UILocalNotificationDefaultSoundName = @"UILocalNotificationDefaultSoundName";

@implementation UILocalNotification {
    StrongId<NSDate*> _fireDate;
    StrongId<NSString*> _alertBody;
    StrongId<NSTimeZone*> _timeZone;
    StrongId<NSString*> _soundName;
    StrongId<NSString*> _alertAction;
    StrongId<NSDictionary*> _userInfo;
    StrongId<NSString*> _category;

    NSCalendarUnit _repeatInterval;
    NSInteger _applicationIconBadgeNumber;
}

- (void)_setReceiver:(id)receiver {
}

- (void)_cancelAlarm {
}

/**
   @Status Stub
*/
- (void)setFireDate:(NSDate*)fireDate {
    UNIMPLEMENTED();
    _fireDate.attach([fireDate copy]);
}

/**
   @Status Interoperable
*/
- (void)setAlertBody:(NSString*)alertBody {
    _alertBody.attach([alertBody copy]);
}

/**
   @Status Stub
*/
- (void)setTimeZone:(NSTimeZone*)timeZone {
    UNIMPLEMENTED();
    _timeZone.attach([timeZone copy]);
}

/**
   @Status Stub
*/
- (void)setSoundName:(NSString*)soundName {
    UNIMPLEMENTED();
    _soundName.attach([soundName copy]);
}

/**
   @Status Stub
*/
- (void)setApplicationIconBadgeNumber:(NSInteger)badgeNumber {
    UNIMPLEMENTED();
    _applicationIconBadgeNumber = badgeNumber;
}

/**
   @Status Interoperable
*/
- (void)setAlertAction:(NSString*)alertAction {
    _alertAction.attach([alertAction copy]);
}

/**
   @Status Stub
*/
- (void)setRepeatInterval:(NSCalendarUnit)repeatInterval {
    UNIMPLEMENTED();
    _repeatInterval = repeatInterval;
}

/**
   @Status Stub
*/
- (void)setUserInfo:(NSDictionary*)userInfo {
    UNIMPLEMENTED();
    _userInfo.attach([userInfo copy]);
}

/**
   @Status Stub
*/
- (void)setCategory:(NSString*)category {
    UNIMPLEMENTED();
    _category.attach([category copy]);
}

/**
   @Status Stub
*/
- (NSDate*)fireDate {
    UNIMPLEMENTED();
    return [[_fireDate copy] autorelease];
}

/**
   @Status Interoperable
*/
- (NSString*)alertBody {
    return [[_alertBody copy] autorelease];
}

/**
   @Status Stub
*/
- (NSTimeZone*)timeZone {
    UNIMPLEMENTED();
    return [[_timeZone copy] autorelease];
}

/**
   @Status Stub
*/
- (NSString*)soundName {
    UNIMPLEMENTED();
    return [[_soundName copy] autorelease];
}

/**
   @Status Stub
*/
- (NSInteger) applicationIconBadgeNumber {
    UNIMPLEMENTED();
    return _applicationIconBadgeNumber;
}

/**
   @Status Interoperable
*/
- (NSString*)alertAction {
    return [[_alertAction copy] autorelease];
}

/**
   @Status Stub
*/
- (NSCalendarUnit) repeatInterval {
    UNIMPLEMENTED();
    return _repeatInterval;
}

/**
   @Status Stub
*/
- (NSDictionary*)userInfo {
    UNIMPLEMENTED();
    return [[_userInfo copy] autorelease];
}

/**
   @Status Stub
*/
- (NSString*)category {
    UNIMPLEMENTED();
    return [[_category copy] autorelease];
}

@end
