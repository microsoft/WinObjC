//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <CFNetwork/CFHost.h>

const SInt32 kCFStreamErrorDomainNetDB = StubConstant();
const SInt32 kCFStreamErrorDomainSystemConfiguration = StubConstant();

/**
 @Status Stub
 @Notes
*/
CFHostRef CFHostCreateCopy(CFAllocatorRef alloc, CFHostRef host) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFHostRef CFHostCreateWithAddress(CFAllocatorRef allocator, CFDataRef addr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFHostRef CFHostCreateWithName(CFAllocatorRef allocator, CFStringRef hostname) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFHostCancelInfoResolution(CFHostRef theHost, CFHostInfoType info) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFHostGetAddressing(CFHostRef theHost, Boolean* hasBeenResolved) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFHostGetNames(CFHostRef theHost, Boolean* hasBeenResolved) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CFHostGetReachability(CFHostRef theHost, Boolean* hasBeenResolved) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHostStartInfoResolution(CFHostRef theHost, CFHostInfoType info, CFStreamError* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CFHostSetClient(CFHostRef theHost, CFHostClientCallBack clientCB, CFHostClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFHostScheduleWithRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CFHostUnscheduleFromRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CFHostGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
