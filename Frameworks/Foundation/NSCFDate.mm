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
#include "BridgeHelpers.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSCFDate.h"
#include <CoreFoundation/CFDate.h>

#pragma region Factory Class
@implementation NSDatePrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (instancetype)initWithString:(NSString*)string {
    StrongId<NSDateFormatter> formatter;
    formatter.attach([NSDateFormatter new]);
    [formatter setLocale:[NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"]];
    [formatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZZZ"];
    [formatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    return static_cast<NSDatePrototype*>([formatter dateFromString:string]);
}

- (instancetype)initWithTimeIntervalSinceReferenceDate:(double)ref {
    return reinterpret_cast<NSDatePrototype*>(static_cast<NSDate*>(CFDateCreate(nullptr, ref)));
}

- (instancetype)init {
    return [self initWithTimeIntervalSinceReferenceDate:[NSDate timeIntervalSinceReferenceDate]];
}

@end
#pragma endregion

#pragma region NSCF Bridged Class
@interface NSCFDate : NSDate
@end

@implementation NSCFDate

BRIDGED_CLASS_REQUIRED_IMPLS(CFDateRef, CFDateGetTypeID, NSDate, NSCFDate)

- (double)timeIntervalSinceReferenceDate {
    return CFDateGetAbsoluteTime(static_cast<CFDateRef>(self));
}

@end
#pragma endregion
