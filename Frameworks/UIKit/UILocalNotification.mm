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

#include "Starboard.h"
#include "Foundation/NSCalendar.h"
#include "Foundation/NSCoder.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSString.h"
#include "Foundation/NSTimeZone.h"

@implementation UILocalNotification : NSObject
    idretain _receiver;
    idretain _fireDate;
    idretain _action;
    idretain _body;
    idretain _alertLaunchImage;
    idretain _userInfo;
    idretain _timeZone;

    void formatFireDate()
    {
#if 0
        id locale = [NSLocale currentLocale];
        id formatter = [NSDateFormatter new];
        id dateFormat = [NSDateFormatter dateFormatFromTemplate:@"E MMM d yyyy" options:0 locale:locale];
        [formatter setDateFormat:dateFormat];
        [formatter setLocale:locale];

        id dateStr = [formatter stringFromDate:(id)_fireDate];
        char *s = (char *)E2H([dateStr UTF8String]);
        EbrDebugLog("fireDate is %s.\n", s);

        [formatter release];
        [dateStr release];
#endif
    }

    // --------------------------------------------------------------------------------
    // Instance methods

    -(id) init {
        return self;
    }
    
    -(void) dealloc {
        return [super dealloc];
    }
    
    -(void) _receiveAlarm:(id)unused {
    }
    
    -(void) _setReceiver:(id)receiver {
        if (_fireDate == nil) return;
        _receiver = receiver;

        //[self _scheduleNotification];
    }

    -(void) cancelAlarm {
        //[self _cancelNotification];
    }
    
    -(id) fireDate {
        return _fireDate;
    }

    -(void) setFireDate:(id)val {
        _fireDate = val;

        formatFireDate();
    }

    /* annotate with type */ -(id) timeZone {
        return _timeZone;
    }

    /* annotate with type */ -(id) setTimeZone:(id)val {
        _timeZone = val;
        return self;
    }

    /* annotate with type */ -(id) repeatInterval {
        EbrDebugLog("!!!! repeatInterval called!\n");
        return nil;
    }

    /* annotate with type */ -(id) setRepeatInterval:(NSCalendarUnit)val {
        EbrDebugLog("!!!! setRepeatInterval called!\n");
        return nil;
    }

    /* annotate with type */ -(id) repeatCalendar {
        EbrDebugLog("!!!! repeatCalendar called!\n");
        return nil;
    }

    /* annotate with type */ -(id) setRepeatCalendar:(id)val {
        EbrDebugLog("!!!! setRepeatCalendar called!\n");
        return nil;
    }

    /* annotate with type */ -(id) alertBody {
        return _body;
    }

    /* annotate with type */ -(id) setAlertBody:(id)val {
        _body = val;
        return self;
    }

    /* annotate with type */ -(id) hasAction {
        EbrDebugLog("!!!! hasAction called!\n");
        return nil;
    }

    /* annotate with type */ -(id) setHasAction:(BOOL)val {
        EbrDebugLog("!!!! setHasAction called!\n");
        return nil;
    }

    /* annotate with type */ -(id) alertAction {
        return _action;
    }

    /* annotate with type */ -(id) setAlertAction:(id)val {
        _action = val;
        return self;
    }

    /* annotate with type */ -(id) alertLaunchImage {
        return _alertLaunchImage;
    }

    /* annotate with type */ -(id) setAlertLaunchImage:(id)val {
        _alertLaunchImage = val;
        return self;
    }

    /* annotate with type */ -(id) soundName {
        EbrDebugLog("!!!! soundName called!\n");
        return nil;
    }

    /* annotate with type */ -(id) setSoundName:(id)val {
        EbrDebugLog("!!!! setSoundName called!\n");
        return nil;
    }

    /* annotate with type */ -(id) applicationIconBadgeNumber {
        EbrDebugLog("!!!! applicationIconBadgeNumber called!\n");
        return nil;
    }

    /* annotate with type */ -(id) setApplicationIconBadgeNumber:(NSInteger)val {
        EbrDebugLog("!!!! setApplicationIconBadgeNumber called!\n");
        return nil;
    }

    /* annotate with type */ -(id) userInfo {
        return _userInfo;
    }

    /* annotate with type */ -(id) setUserInfo:(id)val {
        _userInfo = val;
        return self;
    }

    // --------------------------------------------------------------------------------

    
@end

