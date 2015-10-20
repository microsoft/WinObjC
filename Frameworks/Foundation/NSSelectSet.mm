/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifdef WIN32
#include <WinSock.h>
#elif defined(WINPHONE) || defined(__OBJC__)
#include <winsock2.h>
#undef WIN32
#else
#include <sys/socket.h>
#include <sys/select.h>
#endif

#include <errno.h>

#include "Starboard.h"
#include "NSSelectSet.h"
#include "Foundation/NSMutableSet.h"
#include "NSSocket.h"

@implementation NSSelectSet : NSObject
typedef struct {
    int max;
    fd_set* fdset;
} native_set;

static native_set* native_set_new(int max) {
    native_set* result = (native_set*)EbrCalloc(1, sizeof(native_set));

    result->max = FD_SETSIZE;
    result->fdset = (fd_set*)EbrCalloc(1, sizeof(fd_set));

    return result;
}

static void native_set_EbrFree(native_set* set) {
    EbrFree(set->fdset);
    EbrFree(set);
}

static void native_set_clear(native_set* set, int descriptor) {
    FD_CLR(descriptor, set->fdset);
}

static void native_set_set(native_set* set, int descriptor) {
    FD_SET(descriptor, set->fdset);
}

static BOOL native_set_is_set(native_set* native, int descriptor) {
    // if(descriptor>native->max)
    // return NO;

    return FD_ISSET(descriptor, native->fdset);
}

static int maxDescriptorInSet(id set) {
    int result = -1;
    id state = [set objectEnumerator];
    id socket;

    while ((socket = [state nextObject]) != nil) {
        int check = [socket descriptor];

        if (check > result)
            result = check;
    }

    return result;
}

static int maxDescriptorInThreeSets(id set1, id set2, id set3) {
    int check, result = maxDescriptorInSet(set1);

    check = maxDescriptorInSet(set2);
    if (check > result)
        result = check;

    check = maxDescriptorInSet(set3);
    if (check > result)
        result = check;

    return result;
}

static void transferSetToNative(id set, native_set* native) {
    id state = [set objectEnumerator];
    id socket;

    while ((socket = [state nextObject]) != nil)
        native_set_set(native, [socket descriptor]);
}

static void transferNativeToSetWithOriginals(native_set* sset, id set, id original, id cheater) {
    unsigned int i;

#if defined(WIN32) || defined(WINPHONE)
    for (i = 0; i < sset->fdset->fd_count; i++) {
        if (native_set_is_set(sset, sset->fdset->fd_array[i])) {
            [cheater setDescriptor:sset->fdset->fd_array[i]];
            [set addObject:[original member:cheater]];
        }
    }
#else
    for (i = 0; i < sset->max; i++) {
        if (native_set_is_set(sset, i)) {
            [cheater setDescriptor:i];
            [set addObject:[original member:cheater]];
        }
    }
#endif
}

- (id)init {
    _readSet = [NSMutableSet new];
    _writeSet = [NSMutableSet new];
    _exceptionSet = [NSMutableSet new];
    return self;
}

- (void)dealloc {
    [_readSet release];
    [_writeSet release];
    [_exceptionSet release];
    [super dealloc];
}

- (id)addObjectForRead:(id)object {
    [_readSet addObject:object];

    return self;
}

- (id)addObjectForWrite:(id)object {
    [_writeSet addObject:object];

    return self;
}

- (id)addObjectForException:(id)object {
    [_exceptionSet addObject:object];

    return self;
}

- (BOOL)isEmpty {
    return ([_readSet count] == 0) && ([_writeSet count] == 0) && ([_exceptionSet count] == 0);
}

- (id)waitForSelectWithOutputSet:(id*)outputSetX beforeDate:(id)beforeDate {
    id result = nil;
    id cheater = [NSSocket socketWithDescriptor:-1];
    int maxDescriptor = maxDescriptorInThreeSets(_readSet, _writeSet, _exceptionSet);
    native_set* activeRead = native_set_new(maxDescriptor);
    native_set* activeWrite = native_set_new(maxDescriptor);
    native_set* activeExcept = native_set_new(maxDescriptor);
    struct __ws2_timeval timeval;
    NSTimeInterval interval = 1.0;

    int numFds = 0;
    while (result == nil && numFds == 0 && interval > 0.0) {
        EbrBlockIfBackground();
        transferSetToNative(_readSet, activeRead);
        transferSetToNative(_writeSet, activeWrite);
        transferSetToNative(_exceptionSet, activeExcept);

        interval = [beforeDate timeIntervalSinceNow];

        if (interval > 1000000)
            interval = 1000000;
#ifdef ANDRID
        if (interval < 10000)
            interval = 0;
#else
        if (interval < 0)
            interval = 0;
#endif

        timeval.tv_sec = (long)interval;
        interval -= timeval.tv_sec;
        timeval.tv_usec = (long)(interval * 1000000);

        if ((numFds = select(maxDescriptor + 1, activeRead->fdset, activeWrite->fdset, activeExcept->fdset, &timeval)) < 0) {
#if defined(WIN32) || defined(WINPHONE)
            DWORD err = WSAGetLastError();
            EbrDebugLog("Select error %d\n", err);
#else
            EbrDebugLog("Select error %d\n", errno);
#endif
            if (errno == EINTR) {
                EbrDebugLog("Interrupted, restarting\n");
                fflush(stdout);
                numFds = 0;
                continue;
            }
            /*
            if(errno!=EINTR) {
            //result=[NSError errorWithDomain:NSPOSIXErrorDomain code:errno userInfo:nil];
            assert(0);
            }
            */
            assert(0);
        }

        double nextInterval = [beforeDate timeIntervalSinceNow];
    }

    if (result == nil) {
        NSSelectSet* outputSet = [[[NSSelectSet alloc] init] autorelease];
        if (numFds) {
            /*
            for(int i=0;i<activeRead->max;i++){
            if(native_set_is_set(activeRead,i)){
            EbrDebugLog("%d is readable\n", i);
            }
            }
            */
            transferNativeToSetWithOriginals(activeRead, outputSet->_readSet, _readSet, cheater);
            transferNativeToSetWithOriginals(activeWrite, outputSet->_writeSet, _writeSet, cheater);
            transferNativeToSetWithOriginals(activeExcept, outputSet->_exceptionSet, _exceptionSet, cheater);
        }
        *outputSetX = outputSet;
    }

    native_set_EbrFree(activeRead);
    native_set_EbrFree(activeWrite);
    native_set_EbrFree(activeExcept);

    return result;
}

- (BOOL)containsObjectForRead:(id)object {
    return [_readSet containsObject:object];
}

- (BOOL)containsObjectForWrite:(id)object {
    return [_writeSet containsObject:object];
}

- (BOOL)containsObjectForException:(id)object {
    return [_exceptionSet containsObject:object];
}

/*
-(void)removeObjectForRead:object {
[_readSet removeObject:object];
}

-(void)removeObjectForWrite:object {
[_writeSet removeObject:object];
}

-(void)removeObjectForException:object {
[_exceptionSet removeObject:object];
}

-(void)removeAllObjects {
[_readSet removeAllObjects];
[_writeSet removeAllObjects];
[_exceptionSet removeAllObjects];
}

-(void)waitInBackgroundInMode:(NSString *)mode {
NSInvalidAbstractInvocation();
}

*/

@end
