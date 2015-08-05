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

// This should probably eventually be moved to a SystemConfiguration project but there's little else
// interesting in the SC group of stuff so... eh. This is in the Foundation to have easier access
// to NSRunLoopSource.

#include <winsock2.h>
#include <Ws2tcpip.h>

#include "Starboard.h"
#include "Foundation/NSOperation.h"
#include "SystemConfiguration/SCNetworkReachability.h"

#include "NSRunLoopSource.h"

#define REACHABILITY_STATE      (kSCNetworkReachabilityFlagsReachable)
#define OFFLINE_REACHABILITY_STATE 0

@interface SCNetworkReachability : NSOperation {
@public
    sockaddr_in address;
    char *hostname;
    NSRunLoopSource* networkAvailableSource;
    BOOL hasContext;
    SCNetworkReachabilityCallBack callBack;
    SCNetworkReachabilityContext context;
}
@end


@implementation SCNetworkReachability : NSOperation

    -(void) _networkAvailable {
        if ( callBack != 0 ) {
            SCNetworkReachabilityFlags flags = 0;
            SCNetworkReachabilityGetFlags((SCNetworkReachabilityRef) self, &flags);

            EbrCall(callBack, "ddd", self, flags, hasContext ? context.info : 0);
        }
    }


    -(void) dealloc {
        if ( context.release != 0 ) {
            EbrCall(context.release, "d", context.info);
        }
        [super dealloc];
    }


    -(void) _availabilityChanged {
        [networkAvailableSource _trigger];
    }









    
@end




SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator, const sockaddr *addrOpaque)
{
    auto address = (const sockaddr_in*)addrOpaque;

    SCNetworkReachability* ret = [SCNetworkReachability new];
    ret->address = *address;

    //  Need to suport ipv6 ...
    char *hostname = inet_ntoa(*((in_addr *) &address->sin_addr));
    NSString* hostStr = [[NSString alloc] initWithUTF8String:hostname];
    [ret _setHost:hostStr withPort:address->sin_port];
    [hostStr release];

    return (SCNetworkReachabilityRef) ret;
}


SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef allocator, const char *hostname)
{
    SCNetworkReachability* ret = [SCNetworkReachability new];
    ret->hostname = _strdup(hostname);
    NSString* hostStr = [[NSString alloc] initWithUTF8String:hostname];
    //[ret _setHost:hostStr withPort:0];
    [hostStr release];

    return (SCNetworkReachabilityRef) ret;
}


Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags *retFlags)
{
    SCNetworkReachabilityFlags flags = 0;

    /*
    if ( [target _isConnected] ) {
        flags |= kSCNetworkReachabilityFlagsReachable;
        if ( ![target _isWifiConnected] ) {
            flags |= kSCNetworkReachabilityFlagsIsWWAN;
        }
    }
    */

    *retFlags = flags;

    return TRUE;
}


Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef target, SCNetworkReachabilityCallBack  callout, SCNetworkReachabilityContext *context)
{
    SCNetworkReachability* scNetwork = (SCNetworkReachability*) target;
    scNetwork->callBack = callout;

    if ( context ) {
        memcpy(&scNetwork->context, context, sizeof(*context));
        scNetwork->hasContext = TRUE;
    }

    if ( scNetwork->context.retain != 0 ) {
        EbrCall(scNetwork->context.retain, "d", scNetwork->context.info);
    }

    return TRUE;
}


Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runloop, CFStringRef mode)
{
    SCNetworkReachability* scNetwork = (SCNetworkReachability*) target;

    if ( scNetwork->networkAvailableSource != nil ) {
        EbrDebugLog("Already scheduled for run loop\n");
        return TRUE;
    }

    scNetwork->networkAvailableSource = [NSRunLoopSource new];
    [scNetwork->networkAvailableSource setSourceDelegate:scNetwork selector:@selector(_networkAvailable)];
    [runloop addInputSource:scNetwork->networkAvailableSource forMode:(NSString*) mode];
    [target retain];
    [target _scheduleLookup];

    return TRUE;
}


Boolean SCNetworkReachabilitySetDispatchQueue(SCNetworkReachabilityRef  target, id queue)
{
    //[queue addOperation:target];
    return TRUE;
}


Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runloop, CFStringRef mode)
{
    SCNetworkReachability* scNetwork = (SCNetworkReachability*) target;

    [target _unscheduleLookup];
    if ( scNetwork->networkAvailableSource != nil ) {
        [runloop removeInputSource:scNetwork->networkAvailableSource forMode:(NSString*) mode]; 
        scNetwork->networkAvailableSource = nil;
        [target release];
    }

    return TRUE;
}


