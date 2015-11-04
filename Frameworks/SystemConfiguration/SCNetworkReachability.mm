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
#include "SystemConfiguration/SystemConfiguration.h"
#include "SystemConfiguration/SCNetworkReachability.h"

#include "NSRunLoopSource.h"

#include "UWP/WindowsNetworkingSockets.h"
#include "UWP/WindowsNetworking.h"

static __declspec(thread) int SCLastError = 0;

static SCNetworkReachabilityFlags _globalReachableFlags = 0;
static NSMutableArray* _allReachabilityOperations;
static NSLock* _allReachabilityOperationsLock;

@class SCNetworkReachability;

//  Stores a weak reference to the SCNetworkReachability object
//  so that a global list of all objects can be coherently maintained
@interface SCNetworkReachabilityWeakRef : NSObject {
    SCNetworkReachability* _weakObj;
}
@end

@implementation SCNetworkReachabilityWeakRef
- (instancetype)initWithObject:(SCNetworkReachability*)obj {
    objc_storeWeak(&_weakObj, obj);
    [_allReachabilityOperationsLock lock];
    [_allReachabilityOperations addObject:self];
    [_allReachabilityOperationsLock unlock];

    return self;
}

- (SCNetworkReachability*)getRef {
    return objc_loadWeak(&_weakObj);
}

- (void)dealloc {
    [_allReachabilityOperationsLock lock];
    [_allReachabilityOperations removeObject:self];
    [_allReachabilityOperationsLock unlock];

    [super dealloc];
}

+ (void)initialize {
    _allReachabilityOperations = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    _allReachabilityOperationsLock = [NSLock new];
}
@end

//  Base class for network reachability object
//
//  _performReachabilityTest is called on every SCNetworkReachability object
//  when a network reachability condition is found
@interface SCNetworkReachability : NSObject {
@public
    NSRunLoopSource* _availabilityChangedSource;
    NSMutableDictionary* _runLoopsScheduled;

    dispatch_queue_t _callbackQueue;
    BOOL _isPerformingCallback;

    BOOL _hasContext;
    SCNetworkReachabilityCallBack _callBack;
    SCNetworkReachabilityContext _context;
    SCNetworkReachabilityFlags _reachabilityFlags;

    NSConditionLock* _reachabilityFlagsValid;

    SCNetworkReachabilityWeakRef* _weakRef;
}

- (void)_performReachabilityTest;
@end

@implementation SCNetworkReachability
+ (void)initialize {
    if (self == [SCNetworkReachability class]) {
        [WNCNetworkInformation addNetworkStatusChangedEvent:^void(RTObject* sender) {
            [self _networkStatusChanged];
        }];
        [self _checkGlobalReachability];
    }
}

- (void)_performReachabilityTest {
    [NSException raiseWithLogging:@"SCNetworkReachabilityInternal"
                           format:@"_performReachabilityTest not implemented on SCNetworkReachability base class"];
}

+ (void)_testAllReachabilityObjects {
    @autoreleasepool {
        //  Go through every SCNetworkReachability object and instruct it to
        //  check it's reachability status
        [_allReachabilityOperationsLock lock];
        for (SCNetworkReachabilityWeakRef* cur in _allReachabilityOperations) {
            SCNetworkReachability* obj = [cur getRef];
            if (obj != nil) {
                [obj _performReachabilityTest];
            }
        }
        [_allReachabilityOperationsLock unlock];
    }
}

+ (void)_checkGlobalReachability {
    WNCConnectionProfile* internetConnectionProfile = [WNCNetworkInformation getInternetConnectionProfile];
    if ([internetConnectionProfile internalObject] != nil &&
        [internetConnectionProfile getNetworkConnectivityLevel] == WNCNetworkConnectivityLevelInternetAccess) {
        SCNetworkReachabilityFlags newFlags = kSCNetworkReachabilityFlagsReachable;

        if (internetConnectionProfile.isWwanConnectionProfile) {
            newFlags |= kSCNetworkReachabilityFlagsIsWWAN;
        }
        _globalReachableFlags = newFlags;
    } else {
        _globalReachableFlags = 0;
    }
}

+ (void)_networkStatusChanged {
    SCNetworkReachabilityFlags oldState = _globalReachableFlags;
    [self _checkGlobalReachability];

    if (_globalReachableFlags != oldState) {
        [self _testAllReachabilityObjects];
    }
}

- (instancetype)init {
    _runLoopsScheduled = [NSMutableDictionary new];
    _reachabilityFlagsValid = [NSConditionLock new];
    _weakRef = [[SCNetworkReachabilityWeakRef alloc] initWithObject:self];

    return self;
}

- (void)_setReachabilityFlags:(SCNetworkReachabilityFlags)flags {
    [_reachabilityFlagsValid lock];
    _reachabilityFlags = flags;

    //  Flags are now valid
    [_reachabilityFlagsValid unlockWithCondition:TRUE];

    [self _availabilityChanged];
}

- (bool)hasReachabilityFlags {
    bool ret = false;
    [_reachabilityFlagsValid lock];
    if (_reachabilityFlagsValid.condition == TRUE) {
        ret = true;
    }
    [_reachabilityFlagsValid unlock];

    return ret;
}

- (SCNetworkReachabilityFlags)getReachabilityFlags {
    SCNetworkReachabilityFlags ret;

    //  Wait
    [_reachabilityFlagsValid lockWhenCondition:TRUE];
    ret = _reachabilityFlags;
    [_reachabilityFlagsValid unlock];

    return ret;
}

- (void)_performCallback {
    if (_callBack != NULL) {
        _callBack((SCNetworkReachabilityRef)self, [self getReachabilityFlags], _hasContext ? _context.info : 0);
    }
}

- (void)_availabilityChanged {
    [_reachabilityFlagsValid lock];

    [_availabilityChangedSource _trigger];

    if (_callbackQueue != NULL && _isPerformingCallback == FALSE) {
        _isPerformingCallback = TRUE;
        [self retain];
        dispatch_async(_callbackQueue,
                       ^void() {
                           [self _performCallback];
                           [self release];
                           _isPerformingCallback = FALSE;
                       });
    }

    [_reachabilityFlagsValid unlock];
}

- (void)setCallback:(SCNetworkReachabilityCallBack)callback withContext:(SCNetworkReachabilityContext*)context {
    //  Retain the passed in callback
    if (context->retain != 0) {
        context->retain(_context.info);
    }

    //  Release the current callback
    if (_hasContext) {
        if (_context.release != 0) {
            _context.release(_context.info);
        }
    }

    _callBack = callback;

    if (context) {
        memcpy(&_context, context, sizeof(*context));
        _hasContext = TRUE;
    } else {
        _hasContext = FALSE;
    }
}

- (void)setCallbackQueue:(dispatch_queue_t)queue {
    [_reachabilityFlagsValid lock];

    if (queue != NULL)
        dispatch_retain(queue);
    if (_callbackQueue != NULL)
        dispatch_release(_callbackQueue);
    _callbackQueue = queue;

    if (_callbackQueue != NULL) {
        //  If we have a valid reachability status, signal it to all listeners
        if ([_reachabilityFlagsValid condition] == TRUE) {
            [self _availabilityChanged];
        }
    }
    [_reachabilityFlagsValid unlock];
}

- (void)scheduleInRunLoop:(CFRunLoopRef)runLoop forMode:(CFStringRef)mode {
    [_reachabilityFlagsValid lock];
    if (_availabilityChangedSource == nil) {
        _availabilityChangedSource = [NSRunLoopSource new];
        [_availabilityChangedSource setSourceDelegate:self selector:@selector(_performCallback)];
    }

    NSMutableArray* runLoops = _runLoopsScheduled[(NSString*)mode];
    if (runLoops == nil) {
        runLoops = [NSMutableArray new];
        _runLoopsScheduled[(NSString*)mode] = runLoops;
        [runLoops release];
    }

    if (![runLoops containsObject:(NSRunLoop*)runLoop]) {
        [runLoops addObject:(NSRunLoop*)runLoop];
        [(NSRunLoop*)runLoop addInputSource:_availabilityChangedSource forMode:(NSString*)mode];
    }

    //  If we have a valid reachability status, signal it to all listeners
    if ([_reachabilityFlagsValid condition] == TRUE) {
        [self _availabilityChanged];
    }
    [_reachabilityFlagsValid unlock];
}

- (BOOL)unscheduleFromRunLoop:(CFRunLoopRef)runLoop forMode:(CFStringRef)mode {
    BOOL ret = FALSE;
    [_reachabilityFlagsValid lock];

    if (_availabilityChangedSource != nil) {
        NSMutableArray* runLoops = _runLoopsScheduled[(NSString*)mode];
        if (runLoops != nil) {
            if ([runLoops containsObject:(NSRunLoop*)runLoop]) {
                [runLoops removeObject:(NSRunLoop*)runLoop];
                [(NSRunLoop*)runLoop removeInputSource:_availabilityChangedSource forMode:(NSString*)mode];

                ret = TRUE;
            }
        }
    }

    [_reachabilityFlagsValid unlock];

    return ret;
}

- (void)dealloc {
    if (_hasContext) {
        if (_context.release != 0) {
            _context.release(_context.info);
        }
    }
    if (_availabilityChangedSource != nil) {
        for (NSString* curMode in _runLoopsScheduled) {
            NSArray* runLoops = [_runLoopsScheduled objectForKey:curMode];
            for (NSRunLoop* curRunLoop in runLoops) {
                [curRunLoop removeInputSource:_availabilityChangedSource forMode:curMode];
            }
        }
    }
    [_runLoopsScheduled release];
    [_reachabilityFlagsValid release];
    [_weakRef release];

    if (_callbackQueue != NULL) {
        dispatch_release(_callbackQueue);
    }
    [super dealloc];
}
@end

@interface SCNetworkReachabilityAddress : SCNetworkReachability {
    struct sockaddr _address;
}
@end

@interface SCNetworkReachabilityHostName : SCNetworkReachability {
    char* _hostname;
}
@end

@implementation SCNetworkReachabilityAddress
- (instancetype)initWithAddress:(const struct sockaddr*)addr {
    [super init];
    memcpy(&_address, addr, sizeof(sockaddr));

    return self;
}

- (void)_performReachabilityTest {
    //  If the address is zero, simply check for internet connectivity
    if (((const struct sockaddr_in*)&_address)->sin_addr.s_addr == 0) {
        if (_globalReachableFlags != 0) {
            [self _setReachabilityFlags:_globalReachableFlags | kSCNetworkReachabilityFlagsReachable];
        } else {
            [self _setReachabilityFlags:0];
        }

        return;
    }
    WCHAR addressStr[64];
    DWORD addressStrLen = sizeof(addressStr);
    INT rc = WSAAddressToStringW((LPSOCKADDR)&_address, sizeof(struct sockaddr), NULL, addressStr, &addressStrLen);

    if (rc == 0 && addressStrLen > 0) {
        //  keep ourself around until the reachability test completes
        [self retain];

        NSString* strAddress = [NSString stringWithCharacters:(const unichar*)addressStr length:addressStrLen - 1];
        WNHostName* wnHostName = [WNHostName createHostName:strAddress];
        [WNSDatagramSocket getEndpointPairsAsync:wnHostName
            remoteServiceName:@"0"
            success:^void(id<NSFastEnumeration> pairs) {
                for (WNEndpointPair* cur in pairs) {
                    [self _setReachabilityFlags:_globalReachableFlags | kSCNetworkReachabilityFlagsReachable];
                    break;
                }
                [self release];
            }
            failure:^void(NSError* error) {
                [self _setReachabilityFlags:0];
                [self release];
            }];
        [wnHostName release];
    } else {
        //  Address error, unreachable
        [self _setReachabilityFlags:0];
    }
}
@end

@implementation SCNetworkReachabilityHostName
- (instancetype)initWithHostName:(const char*)hostname {
    [super init];
    _hostname = _strdup(hostname);

    return self;
}

- (void)dealloc {
    free(_hostname);
    [super dealloc];
}

- (void)_performReachabilityTest {
    //  keep ourself around until the reachability test completes
    [self retain];

    NSString* hostStr = [NSString stringWithCString:_hostname];

    //  To extract just the host name in case we're fed an URL
    NSURL* url = [NSURL URLWithString:hostStr];

    WNHostName* wnHostName;
    if (url.host.length > 0) {
        wnHostName = [WNHostName createHostName:url.host];
    } else {
        wnHostName = [WNHostName createHostName:hostStr];
    }
    [WNSDatagramSocket getEndpointPairsAsync:wnHostName
        remoteServiceName:@"0"
        success:^void(id<NSFastEnumeration> pairs) {
            for (WNEndpointPair* cur in pairs) {
                [self _setReachabilityFlags:_globalReachableFlags | kSCNetworkReachabilityFlagsReachable];
                break;
            }
            [self release];
        }
        failure:^void(NSError* error) {
            [self _setReachabilityFlags:0];
            [self release];
        }];
    [wnHostName release];
}
@end

/**
 @Status Interoperable
*/
SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator, const sockaddr* address) {
    SCNetworkReachability* ret = [[SCNetworkReachabilityAddress alloc] initWithAddress:address];

    [ret _performReachabilityTest];

    return (SCNetworkReachabilityRef)ret;
}

/**
 @Status Interoperable
*/
SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef allocator, const char* hostname) {
    SCNetworkReachability* ret = [[SCNetworkReachabilityHostName alloc] initWithHostName:hostname];

    [ret _performReachabilityTest];

    return (SCNetworkReachabilityRef)ret;
}

/**
 @Status Interoperable
*/
Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags* retFlags) {
    SCNetworkReachability* scNetwork = (SCNetworkReachability*)target;

    if (![scNetwork hasReachabilityFlags]) {
        return FALSE;
    }

    *retFlags = [scNetwork getReachabilityFlags];

    return TRUE;
}

/**
 @Status Interoperable
*/
Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef target,
                                         SCNetworkReachabilityCallBack callout,
                                         SCNetworkReachabilityContext* context) {
    SCNetworkReachability* scNetwork = (SCNetworkReachability*)target;
    [scNetwork setCallback:callout withContext:context];

    return TRUE;
}

/**
 @Status Stub
*/
Boolean SCNetworkReachabilitySetDispatchQueue(SCNetworkReachabilityRef target, dispatch_queue_t queue) {
    UNIMPLEMENTED();
    SCNetworkReachability* scNetwork = (SCNetworkReachability*)target;

    [scNetwork setCallbackQueue:queue];

    return TRUE;
}

/**
 @Status Interoperable
*/
Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runloop, CFStringRef mode) {
    SCNetworkReachability* scNetwork = (SCNetworkReachability*)target;

    [scNetwork scheduleInRunLoop:runloop forMode:mode];

    return TRUE;
}

/**
 @Status Interoperable
*/
Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef target, CFRunLoopRef runloop, CFStringRef mode) {
    SCNetworkReachability* scNetwork = (SCNetworkReachability*)target;

    return [scNetwork unscheduleFromRunLoop:runloop forMode:mode];
}

/**
 @Status Stub
*/
int SCError(void) {
    UNIMPLEMENTED();
    return SCLastError;
}

/**
 @Status Stub
*/
const char* SCErrorString(int status) {
    UNIMPLEMENTED();
    return "Not implemented";
}
