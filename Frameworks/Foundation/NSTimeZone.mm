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

@implementation NSTimeZone {
    icu_48::TimeZone* _icuTZ;
}
    +(instancetype) systemTimeZone {
        NSTimeZone* ret = [self alloc];
        ret->_icuTZ = icu_48::TimeZone::createDefault();
        return [ret autorelease];
    }

    +(instancetype) defaultTimeZone {
        return [self systemTimeZone];
    }

    +(NSArray*) knownTimeZoneNames {
		//  TODO
        return [NSArray arrayWithObject:@"America/Los_Angeles"];
    }

    -(void) _getICUTimezone:(icu_48::TimeZone**)tz {
        *tz = _icuTZ;
    }

    +(instancetype) timeZoneForSecondsFromGMT:(NSInteger)seconds {
        NSTimeZone* ret = [self alloc];
        ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString("GMT"));
		ret->_icuTZ->setRawOffset(seconds * 1000);
        return [ret autorelease];
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

	-(BOOL) isDaylightSavingTimeForDate: (NSDate *) date
	{
		UErrorCode status = U_ZERO_ERROR;

        return _icuTZ->inDaylightTime([date timeIntervalSince1970] * 1000.0, status);
	}

    -(BOOL) isDaylightSavingTime {
		return [self isDaylightSavingTimeForDate: [NSDate date]];
    }

    -(void) dealloc {
        delete _icuTZ;
        [super dealloc];
    }

        
        
        
    
@end

