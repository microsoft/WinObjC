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

#import <CoreMedia/CMSampleBuffer.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef kCMSampleBufferNotification_DataBecameReady = static_cast<CFStringRef>(@"FigSampleBufferDataBecameReady");
const CFStringRef kCMSampleBufferConduitNotification_InhibitOutputUntil = static_cast<CFStringRef>(@"InhibitOutputUntil");
const CFStringRef kCMSampleBufferConduitNotification_ResetOutput = static_cast<CFStringRef>(@"ResetOutput");
const CFStringRef kCMSampleBufferConduitNotification_UpcomingOutputPTSRangeChanged =
    static_cast<CFStringRef>(@"UpcomingOutputPTSRangeChanged");
const CFStringRef kCMSampleBufferConsumerNotification_BufferConsumed = static_cast<CFStringRef>(@"BufferConsumed");
const CFStringRef kCMSampleBufferConduitNotificationParameter_ResumeTag = static_cast<CFStringRef>(@"ResumeTag");
const CFStringRef kCMSampleBufferConduitNotificationParameter_UpcomingOutputPTSRangeMayOverlapQueuedOutputPTSRange =
    static_cast<CFStringRef>(@"UpcomingOutputPTSRangeMayOverlapQueuedOutputPTSRange");
const CFStringRef kCMSampleBufferConduitNotificationParameter_MinUpcomingOutputPTS = static_cast<CFStringRef>(@"MinUpcomingOutputPTS");
const CFStringRef kCMSampleBufferConduitNotificationParameter_MaxUpcomingOutputPTS = static_cast<CFStringRef>(@"MaxUpcomingOutputPTS");
const CFStringRef kCMSampleAttachmentKey_NotSync = static_cast<CFStringRef>(@"NotSync");
const CFStringRef kCMSampleAttachmentKey_PartialSync = static_cast<CFStringRef>(@"PartialSync");
const CFStringRef kCMSampleAttachmentKey_HasRedundantCoding = static_cast<CFStringRef>(@"HasRedundantCoding");
const CFStringRef kCMSampleAttachmentKey_IsDependedOnByOthers = static_cast<CFStringRef>(@"IsDependedOnByOthers");
const CFStringRef kCMSampleAttachmentKey_DependsOnOthers = static_cast<CFStringRef>(@"DependsOnOthers");
const CFStringRef kCMSampleAttachmentKey_EarlierDisplayTimesAllowed = static_cast<CFStringRef>(@"EarlierDisplayTimesAllowed");
const CFStringRef kCMSampleAttachmentKey_DisplayImmediately = static_cast<CFStringRef>(@"DisplayImmediately");
const CFStringRef kCMSampleAttachmentKey_DoNotDisplay = static_cast<CFStringRef>(@"DoNotDisplay");
const CFStringRef kCMSampleBufferAttachmentKey_ResetDecoderBeforeDecoding = static_cast<CFStringRef>(@"ResetDecoderBeforeDecoding");
const CFStringRef kCMSampleBufferAttachmentKey_DrainAfterDecoding = static_cast<CFStringRef>(@"DrainAfterDecoding");
const CFStringRef kCMSampleBufferAttachmentKey_PostNotificationWhenConsumed = static_cast<CFStringRef>(@"PostNotificationWhenConsumed");
const CFStringRef kCMSampleBufferAttachmentKey_ResumeOutput = static_cast<CFStringRef>(@"ResumeOutput");
const CFStringRef kCMSampleBufferAttachmentKey_TransitionID = static_cast<CFStringRef>(@"TransitionID");
const CFStringRef kCMSampleBufferAttachmentKey_TrimDurationAtStart = static_cast<CFStringRef>(@"TrimDurationAtStart");
const CFStringRef kCMSampleBufferAttachmentKey_TrimDurationAtEnd = static_cast<CFStringRef>(@"TrimDurationAtEnd");
const CFStringRef kCMSampleBufferAttachmentKey_SpeedMultiplier = static_cast<CFStringRef>(@"SpeedMultiplier");
const CFStringRef kCMSampleBufferAttachmentKey_Reverse = static_cast<CFStringRef>(@"Reverse");
const CFStringRef kCMSampleBufferAttachmentKey_FillDiscontinuitiesWithSilence = static_cast<CFStringRef>(@"FillDiscontinuitiesWithSilence");
const CFStringRef kCMSampleBufferAttachmentKey_EmptyMedia = static_cast<CFStringRef>(@"EmptyMedia");
const CFStringRef kCMSampleBufferAttachmentKey_PermanentEmptyMedia = static_cast<CFStringRef>(@"PermanentEmptyMedia");
const CFStringRef kCMSampleBufferAttachmentKey_DisplayEmptyMediaImmediately = static_cast<CFStringRef>(@"DisplayEmptyMediaImmediately");
const CFStringRef kCMSampleBufferAttachmentKey_EndsPreviousSampleDuration = static_cast<CFStringRef>(@"EndsPreviousSampleDuration");
const CFStringRef kCMSampleBufferAttachmentKey_SampleReferenceURL = static_cast<CFStringRef>(@"SampleReferenceURL");
const CFStringRef kCMSampleBufferAttachmentKey_SampleReferenceByteOffset = static_cast<CFStringRef>(@"SampleReferenceByteOffset");
const CFStringRef kCMSampleBufferAttachmentKey_GradualDecoderRefresh = static_cast<CFStringRef>(@"GradualDecoderRefresh");
const CFStringRef kCMSampleBufferAttachmentKey_DroppedFrameReason = static_cast<CFStringRef>(@"DroppedFrameReason");
const CFStringRef kCMSampleBufferAttachmentKey_DroppedFrameReasonInfo = static_cast<CFStringRef>(@"DroppedFrameReasonInfo");
const CFStringRef kCMSampleBufferDroppedFrameReason_FrameWasLate = static_cast<CFStringRef>(@"FrameWasLate");
const CFStringRef kCMSampleBufferDroppedFrameReason_OutOfBuffers = static_cast<CFStringRef>(@"OutOfBuffers");
const CFStringRef kCMSampleBufferDroppedFrameReason_Discontinuity = static_cast<CFStringRef>(@"Discontinuity");
const CFStringRef kCMSampleBufferDroppedFrameReasonInfo_CameraModeSwitch = static_cast<CFStringRef>(@"CameraModeSwitch");

/**
 @Status Stub
*/
OSStatus CMAudioSampleBufferCreateWithPacketDescriptions(CFAllocatorRef allocator,
                                                         CMBlockBufferRef dataBuffer,
                                                         Boolean dataReady,
                                                         CMSampleBufferMakeDataReadyCallback makeDataReadyCallback,
                                                         void* makeDataReadyRefcon,
                                                         CMFormatDescriptionRef formatDescription,
                                                         CMItemCount numSamples,
                                                         CMTime sbufPTS,
                                                         const AudioStreamPacketDescription* packetDescriptions,
                                                         CMSampleBufferRef _Nullable* sBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCallForEachSample(CMSampleBufferRef sbuf,
                                         OSStatus (*callback)(CMSampleBufferRef, CMItemCount, void*),
                                         void* refcon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCopySampleBufferForRange(CFAllocatorRef allocator,
                                                CMSampleBufferRef sbuf,
                                                CFRange sampleRange,
                                                CMSampleBufferRef _Nullable* sBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCreate(CFAllocatorRef allocator,
                              CMBlockBufferRef dataBuffer,
                              Boolean dataReady,
                              CMSampleBufferMakeDataReadyCallback makeDataReadyCallback,
                              void* makeDataReadyRefcon,
                              CMFormatDescriptionRef formatDescription,
                              CMItemCount numSamples,
                              CMItemCount numSampleTimingEntries,
                              const CMSampleTimingInfo* sampleTimingArray,
                              CMItemCount numSampleSizeEntries,
                              const size_t* sampleSizeArray,
                              CMSampleBufferRef _Nullable* sBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCreateCopy(CFAllocatorRef allocator, CMSampleBufferRef sbuf, CMSampleBufferRef _Nullable* sbufCopyOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCreateCopyWithNewTiming(CFAllocatorRef allocator,
                                               CMSampleBufferRef originalSBuf,
                                               CMItemCount numSampleTimingEntries,
                                               const CMSampleTimingInfo* sampleTimingArray,
                                               CMSampleBufferRef _Nullable* sBufCopyOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferCreateForImageBuffer(CFAllocatorRef allocator,
                                            CVImageBufferRef imageBuffer,
                                            Boolean dataReady,
                                            CMSampleBufferMakeDataReadyCallback makeDataReadyCallback,
                                            void* makeDataReadyRefcon,
                                            CMVideoFormatDescriptionRef formatDescription,
                                            const CMSampleTimingInfo* sampleTiming,
                                            CMSampleBufferRef _Nullable* sBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMSampleBufferDataIsReady(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetAudioBufferListWithRetainedBlockBuffer(CMSampleBufferRef sbuf,
                                                                 size_t* bufferListSizeNeededOut,
                                                                 AudioBufferList* bufferListOut,
                                                                 size_t bufferListSize,
                                                                 CFAllocatorRef bbufStructAllocator,
                                                                 CFAllocatorRef bbufMemoryAllocator,
                                                                 uint32_t flags,
                                                                 CMBlockBufferRef _Nullable* blockBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetAudioStreamPacketDescriptions(CMSampleBufferRef sbuf,
                                                        size_t packetDescriptionsSize,
                                                        AudioStreamPacketDescription* packetDescriptionsOut,
                                                        size_t* packetDescriptionsSizeNeededOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetAudioStreamPacketDescriptionsPtr(CMSampleBufferRef sbuf,
                                                           const AudioStreamPacketDescription* _Nullable* packetDescriptionsPtrOut,
                                                           size_t* packetDescriptionsSizeOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMBlockBufferRef CMSampleBufferGetDataBuffer(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetDecodeTimeStamp(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetDuration(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMFormatDescriptionRef CMSampleBufferGetFormatDescription(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CVImageBufferRef CMSampleBufferGetImageBuffer(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMItemCount CMSampleBufferGetNumSamples(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetOutputDecodeTimeStamp(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetOutputDuration(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetOutputPresentationTimeStamp(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetOutputSampleTimingInfoArray(CMSampleBufferRef sbuf,
                                                      CMItemCount timingArrayEntries,
                                                      CMSampleTimingInfo* timingArrayOut,
                                                      CMItemCount* timingArrayEntriesNeededOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMSampleBufferGetPresentationTimeStamp(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFArrayRef CMSampleBufferGetSampleAttachmentsArray(CMSampleBufferRef sbuf, Boolean createIfNecessary) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
size_t CMSampleBufferGetSampleSize(CMSampleBufferRef sbuf, CMItemIndex sampleIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetSampleSizeArray(CMSampleBufferRef sbuf,
                                          CMItemCount sizeArrayEntries,
                                          size_t* sizeArrayOut,
                                          CMItemCount* sizeArrayEntriesNeededOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetSampleTimingInfo(CMSampleBufferRef sbuf, CMItemIndex sampleIndex, CMSampleTimingInfo* timingInfoOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferGetSampleTimingInfoArray(CMSampleBufferRef sbuf,
                                                CMItemCount timingArrayEntries,
                                                CMSampleTimingInfo* timingArrayOut,
                                                CMItemCount* timingArrayEntriesNeededOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
size_t CMSampleBufferGetTotalSampleSize(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFTypeID CMSampleBufferGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferInvalidate(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMSampleBufferIsValid(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferMakeDataReady(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferSetDataBuffer(CMSampleBufferRef sbuf, CMBlockBufferRef dataBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferSetDataBufferFromAudioBufferList(CMSampleBufferRef sbuf,
                                                        CFAllocatorRef bbufStructAllocator,
                                                        CFAllocatorRef bbufMemoryAllocator,
                                                        uint32_t flags,
                                                        const AudioBufferList* bufferList) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferSetDataReady(CMSampleBufferRef sbuf) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferSetInvalidateCallback(CMSampleBufferRef sbuf,
                                             CMSampleBufferInvalidateCallback invalidateCallback,
                                             uint64_t invalidateRefCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferSetOutputPresentationTimeStamp(CMSampleBufferRef sbuf, CMTime outputPresentationTimeStamp) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMSampleBufferTrackDataReadiness(CMSampleBufferRef sbuf, CMSampleBufferRef sbufToTrack) {
    UNIMPLEMENTED();
    return StubReturn();
}
