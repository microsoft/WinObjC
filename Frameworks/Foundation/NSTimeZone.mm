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
#include "Foundation/NSData.h"
#include "Foundation/NSString.h"
#include "Foundation/NSArray.h"
#include "Etc.h"
#include "Foundation/NSTimeZone.h"

#define U_STATIC_IMPLEMENTATION 1

#include <unicode/gregocal.h>

@implementation NSTimeZone : NSObject
    +(instancetype) systemTimeZone {
        NSTimeZone* ret = [self alloc];
        ret->_icuTZ = icu_48::TimeZone::createDefault();
        return [ret autorelease];
    }

    +(instancetype) defaultTimeZone {
        return [self systemTimeZone];
    }

    +(NSArray*) knownTimeZoneNames {
        return [NSArray arrayWithObject:@"America/Toronto"];
    }

    -(void) _getICUTimezone:(icu_48::TimeZone**)tz {
        *tz = _icuTZ;
    }

    +(instancetype) timeZoneForSecondsFromGMT:(NSInteger)seconds {
        EbrDebugLog("timeZoneForSecondsFromGMT not supported\n");
        return [self timeZoneWithName:@"America/Toronto"];
    }

    +(instancetype) localTimeZone {
        return [self timeZoneWithName:@"America/Toronto"];
    }

    +(instancetype) _gmtTimeZone {
        NSTimeZone* ret = [self alloc];
        ret->_icuTZ = icu_48::TimeZone::getGMT()->clone();
        return [ret autorelease];
    }

    +(instancetype) timeZoneWithName:(NSString*)name {
        NSTimeZone* ret = [self alloc];
        ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString([name UTF8String]));
        return [ret autorelease];
    }

    +(instancetype) timeZoneWithAbbreviation:(NSString*)name {
        NSTimeZone* ret = [self alloc];
        const char* nameStr = [name UTF8String];
        icu_48::TimeZone* tz = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString(nameStr));
        int foo = tz->getRawOffset();
        ret->_icuTZ = tz;
        return [ret autorelease];
    }

    // TODO: Implement these when needed:

    -(NSString*) name {
        icu_48::UnicodeString n;
        _icuTZ->getDisplayName(n);
        return NSStringFromICU(n);
    }

    -(NSString*) abbreviation {
        icu_48::UnicodeString n;
        _icuTZ->getID(n);
        return NSStringFromICU(n);
    }

    -(NSString*) description {
        icu_48::UnicodeString n;
        _icuTZ->getDisplayName(n);
        return NSStringFromICU(n);
    }

    -(NSString*) localizedName:(NSTimeZoneNameStyle)name locale:(NSLocale*)locale {
        return [self description];
    }

    -(NSInteger) secondsFromGMT {
        return _icuTZ->getRawOffset() / 1000;
    }

    -(NSInteger) secondsFromGMTForDate:(NSDate*)date {
        assert(0);
        return 0;
    }

    -(instancetype) copyWithZone:(NSZone*)zone {
        return [self retain];
    }

    +(void) resetSystemTimeZone {
    }

    +(void) setDefaultTimeZone:(NSTimeZone*)zone {
    }

    -(BOOL) isDaylightSavingTime {
        // [BUG: Blatant lie]
        // something like return _icuTZ->inDaylightTime();
        return NO;
    }

    -(void) dealloc {
        delete _icuTZ;
        [super dealloc];
    }

        
        
        
    
@end

