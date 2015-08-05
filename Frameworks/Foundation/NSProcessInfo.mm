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
#include <math.h>

#include "Foundation/NSString.h"
#include "Foundation/NSProcessInfo.h"

static id _processInfo;

static IWLazyClassLookup _LazyUIDevice("UIDevice");

@implementation NSProcessInfo : NSObject
    +(NSProcessInfo*) processInfo {
        return _processInfo;
    }

    +(void) initialize {
        _processInfo = [self new];
    }

    -(instancetype) init {
        _environment = [NSMutableDictionary new];

        [_environment setObject:[[NSBundle mainBundle] bundlePath] forKey:@"HOME"];
        [_environment setObject:@"/tmp" forKey:@"TMPDIR"];

        return self;
    }

    -(NSString*) globallyUniqueString {
        CFUUIDRef uuid = CFUUIDCreate(nil);
        NSString* ret = (NSString*) CFUUIDCreateString(nil, uuid);

        CFRelease(uuid);

        return [ret autorelease];
    }

    -(NSString*) operatingSystemVersionString {
        return @"iOS 3.2";
    }

    -(NSString*) processName {
        return @"MainProcess";
    }

    -(int) processIdentifier {
        return 12345;
    }

    -(double) systemUptime {
        return 60.0 * 5.0;
    }

    -(NSDictionary*) environment {
        return _environment;
    }

    -(unsigned) processorCount {
        return 2;
    }

    -(uint64_t) physicalMemory {
        return [_LazyUIDevice _deviceTotalMemory];
    }

    
@end

