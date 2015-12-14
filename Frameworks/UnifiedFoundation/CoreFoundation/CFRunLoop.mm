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

/**
 @Status Caveat
 @Notes returnAfterSource parameter is not supported
*/
SInt32 CFRunLoopRunInMode(CFStringRef mode, CFTimeInterval time, Boolean returnAfterSource) {
    id stopDate = [NSDate dateWithTimeIntervalSinceNow:time];
    id runLoop = [NSRunLoop currentRunLoop];

    while ([runLoop runMode:(NSString*)mode beforeDate:stopDate]) {
        if ([stopDate timeIntervalSinceNow] <= 0) {
            break;
        }
    }

    return kCFRunLoopRunTimedOut;
}

/**
 @Status Interoperable
*/
CFRunLoopRef CFRunLoopGetCurrent() {
    return (CFRunLoopRef)[NSRunLoop currentRunLoop];
}

/**
 @Status Interoperable
*/
CFRunLoopRef CFRunLoopGetMain() {
    return (CFRunLoopRef)[NSRunLoop mainRunLoop];
}
