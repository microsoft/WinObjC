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
#import <CoreFoundation/CoreFoundation.h>

static IWLazyClassLookup _LazyNSRunLoop("NSRunLoop"), _LazyNSDate("NSDate");

SInt32 CFRunLoopRunInMode(CFStringRef mode, CFTimeInterval time, Boolean returnAfterSource) {
    id stopDate = [_LazyNSDate dateWithTimeIntervalSinceNow:time];
    id runLoop = [_LazyNSRunLoop currentRunLoop];

    while ([runLoop runMode:(NSString*)mode beforeDate:stopDate]) {
        if ([stopDate timeIntervalSinceNow] <= 0) {
            break;
        }
    }

    return kCFRunLoopRunTimedOut;
}

CFRunLoopRef CFRunLoopGetCurrent() {
    return (CFRunLoopRef)[_LazyNSRunLoop currentRunLoop];
}

CFRunLoopRef CFRunLoopGetMain() {
    return (CFRunLoopRef)[_LazyNSRunLoop mainRunLoop];
}
