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

#import <CoreMedia/CMBufferQueue.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

/**
 @Status Stub
*/
OSStatus CMBufferQueueCreate(CFAllocatorRef allocator,
                             CMItemCount capacity,
                             const CMBufferCallbacks* callbacks,
                             CMBufferQueueRef _Nullable* queueOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueCallForEachBuffer(CMBufferQueueRef queue, OSStatus (*callback)(CMBufferRef, void*), void* refcon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMBufferRef CMBufferQueueDequeueAndRetain(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMBufferRef CMBufferQueueDequeueIfDataReadyAndRetain(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueEnqueue(CMBufferQueueRef queue, CMBufferRef buf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueInstallTrigger(CMBufferQueueRef queue,
                                     CMBufferQueueTriggerCallback triggerCallback,
                                     void* triggerRefcon,
                                     CMBufferQueueTriggerCondition triggerCondition,
                                     CMTime triggerTime,
                                     CMBufferQueueTriggerToken _Nullable* triggerTokenOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueInstallTriggerWithIntegerThreshold(CMBufferQueueRef queue,
                                                         CMBufferQueueTriggerCallback triggerCallback,
                                                         void* triggerRefcon,
                                                         CMBufferQueueTriggerCondition triggerCondition,
                                                         CMItemCount triggerThreshold,
                                                         CMBufferQueueTriggerToken _Nullable* triggerTokenOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueMarkEndOfData(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueRemoveTrigger(CMBufferQueueRef queue, CMBufferQueueTriggerToken triggerToken) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueReset(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueResetWithCallback(CMBufferQueueRef queue, void (*callback)(CMBufferRef, void*), void* refcon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBufferQueueSetValidationCallback(CMBufferQueueRef queue, CMBufferValidationCallback validationCallback, void* validationRefCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBufferQueueContainsEndOfData(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBufferQueueIsAtEndOfData(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBufferQueueIsEmpty(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBufferQueueTestTrigger(CMBufferQueueRef queue, CMBufferQueueTriggerToken triggerToken) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMItemCount CMBufferQueueGetBufferCount(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetMaxPresentationTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const CMBufferCallbacks* CMBufferQueueGetCallbacksForUnsortedSampleBuffers() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetDuration(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetEndPresentationTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetFirstDecodeTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetMinDecodeTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetFirstPresentationTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMBufferRef CMBufferQueueGetHead(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMBufferQueueGetMinPresentationTimeStamp(CMBufferQueueRef queue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFTypeID CMBufferQueueGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
