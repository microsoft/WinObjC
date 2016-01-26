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

#pragma once

#import <CoreMedia/CoreMediaExport.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>
#import <CoreFoundation/CFString.h>

typedef CFTypeRef CMBufferRef;
typedef CMTime (*CMBufferGetTimeCallback)(CMBufferRef buf, void* refcon);
typedef Boolean (*CMBufferGetBooleanCallback)(CMBufferRef buf, void* refcon);
typedef CFComparisonResult (*CMBufferCompareCallback)(CMBufferRef buf1, CMBufferRef buf2, void* refcon);
typedef struct opaqueCMBufferQueue* CMBufferQueueRef;
typedef struct {
    uint32_t version;
    void* refcon;
    CMBufferGetTimeCallback getDecodeTimeStamp;
    CMBufferGetTimeCallback getPresentationTimeStamp;
    CMBufferGetTimeCallback getDuration;
    CMBufferGetBooleanCallback isDataReady;
    CMBufferCompareCallback compare;
    CFStringRef dataBecameReadyNotification;
} CMBufferCallbacks;
typedef struct opaqueCMBufferQueueTriggerToken* CMBufferQueueTriggerToken;
typedef int32_t CMBufferQueueTriggerCondition;
typedef OSStatus (*CMBufferValidationCallback)(CMBufferQueueRef queue, CMBufferRef buf, void* validationRefCon);
typedef void (*CMBufferQueueTriggerCallback)(void* triggerRefcon, CMBufferQueueTriggerToken triggerToken);

COREMEDIA_EXPORT OSStatus CMBufferQueueCreate(CFAllocatorRef allocator,
                                              CMItemCount capacity,
                                              const CMBufferCallbacks* callbacks,
                                              CMBufferQueueRef _Nullable* queueOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueCallForEachBuffer(CMBufferQueueRef queue,
                                                         OSStatus (*callback)(CMBufferRef, void*),
                                                         void* refcon) STUB_METHOD;
COREMEDIA_EXPORT CMBufferRef CMBufferQueueDequeueAndRetain(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMBufferRef CMBufferQueueDequeueIfDataReadyAndRetain(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueEnqueue(CMBufferQueueRef queue, CMBufferRef buf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueInstallTrigger(CMBufferQueueRef queue,
                                                      CMBufferQueueTriggerCallback triggerCallback,
                                                      void* triggerRefcon,
                                                      CMBufferQueueTriggerCondition triggerCondition,
                                                      CMTime triggerTime,
                                                      CMBufferQueueTriggerToken _Nullable* triggerTokenOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueInstallTriggerWithIntegerThreshold(CMBufferQueueRef queue,
                                                                          CMBufferQueueTriggerCallback triggerCallback,
                                                                          void* triggerRefcon,
                                                                          CMBufferQueueTriggerCondition triggerCondition,
                                                                          CMItemCount triggerThreshold,
                                                                          CMBufferQueueTriggerToken _Nullable* triggerTokenOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueMarkEndOfData(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueRemoveTrigger(CMBufferQueueRef queue, CMBufferQueueTriggerToken triggerToken) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueReset(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueResetWithCallback(CMBufferQueueRef queue,
                                                         void (*callback)(CMBufferRef, void*),
                                                         void* refcon) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBufferQueueSetValidationCallback(CMBufferQueueRef queue,
                                                             CMBufferValidationCallback validationCallback,
                                                             void* validationRefCon) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBufferQueueContainsEndOfData(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBufferQueueIsAtEndOfData(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBufferQueueIsEmpty(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBufferQueueTestTrigger(CMBufferQueueRef queue, CMBufferQueueTriggerToken triggerToken) STUB_METHOD;
COREMEDIA_EXPORT CMItemCount CMBufferQueueGetBufferCount(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetMaxPresentationTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT const CMBufferCallbacks* CMBufferQueueGetCallbacksForUnsortedSampleBuffers() STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetDuration(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetEndPresentationTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetFirstDecodeTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetMinDecodeTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetFirstPresentationTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMBufferRef CMBufferQueueGetHead(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMBufferQueueGetMinPresentationTimeStamp(CMBufferQueueRef queue) STUB_METHOD;
COREMEDIA_EXPORT CFTypeID CMBufferQueueGetTypeID() STUB_METHOD;

enum {
    kCMBufferQueueTrigger_WhenDurationBecomesLessThan = 1,
    kCMBufferQueueTrigger_WhenDurationBecomesLessThanOrEqualTo = 2,
    kCMBufferQueueTrigger_WhenDurationBecomesGreaterThan = 3,
    kCMBufferQueueTrigger_WhenDurationBecomesGreaterThanOrEqualTo = 4,
    kCMBufferQueueTrigger_WhenMinPresentationTimeStampChanges = 5,
    kCMBufferQueueTrigger_WhenMaxPresentationTimeStampChanges = 6,
    kCMBufferQueueTrigger_WhenDataBecomesReady = 7,
    kCMBufferQueueTrigger_WhenEndOfDataReached = 8,
    kCMBufferQueueTrigger_WhenReset = 9,
    kCMBufferQueueTrigger_WhenBufferCountBecomesLessThan = 10,
    kCMBufferQueueTrigger_WhenBufferCountBecomesGreaterThan = 11,
};
