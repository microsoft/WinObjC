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

#import <CoreAudio/CoreAudioTypes.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFString.h>
#import <CoreMedia/CMBlockBuffer.h>
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CoreMediaExport.h>
#import <CoreMedia/CMTypes.h>
#import <CoreVideo/CVImageBuffer.h>

typedef struct opaqueCMSampleBuffer* CMSampleBufferRef;
typedef struct {
    CMTime duration;
    CMTime presentationTimeStamp;
    CMTime decodeTimeStamp;
} CMSampleTimingInfo;

typedef OSStatus (*CMSampleBufferMakeDataReadyCallback)(CMSampleBufferRef, void*);
typedef OSStatus (*CMSampleBufferInvalidateCallback)(CMSampleBufferRef, uint64_t);

COREMEDIA_EXPORT OSStatus CMAudioSampleBufferCreateWithPacketDescriptions(CFAllocatorRef allocator,
                                                                          CMBlockBufferRef dataBuffer,
                                                                          Boolean dataReady,
                                                                          CMSampleBufferMakeDataReadyCallback makeDataReadyCallback,
                                                                          void* makeDataReadyRefcon,
                                                                          CMFormatDescriptionRef formatDescription,
                                                                          CMItemCount numSamples,
                                                                          CMTime sbufPTS,
                                                                          const AudioStreamPacketDescription* packetDescriptions,
                                                                          CMSampleBufferRef _Nullable* sBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCallForEachSample(CMSampleBufferRef sbuf,
                                                          OSStatus (*callback)(CMSampleBufferRef, CMItemCount, void*),
                                                          void* refcon) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCopySampleBufferForRange(CFAllocatorRef allocator,
                                                                 CMSampleBufferRef sbuf,
                                                                 CFRange sampleRange,
                                                                 CMSampleBufferRef _Nullable* sBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCreate(CFAllocatorRef allocator,
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
                                               CMSampleBufferRef _Nullable* sBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCreateCopy(CFAllocatorRef allocator,
                                                   CMSampleBufferRef sbuf,
                                                   CMSampleBufferRef _Nullable* sbufCopyOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCreateCopyWithNewTiming(CFAllocatorRef allocator,
                                                                CMSampleBufferRef originalSBuf,
                                                                CMItemCount numSampleTimingEntries,
                                                                const CMSampleTimingInfo* sampleTimingArray,
                                                                CMSampleBufferRef _Nullable* sBufCopyOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferCreateForImageBuffer(CFAllocatorRef allocator,
                                                             CVImageBufferRef imageBuffer,
                                                             Boolean dataReady,
                                                             CMSampleBufferMakeDataReadyCallback makeDataReadyCallback,
                                                             void* makeDataReadyRefcon,
                                                             CMVideoFormatDescriptionRef formatDescription,
                                                             const CMSampleTimingInfo* sampleTiming,
                                                             CMSampleBufferRef _Nullable* sBufOut) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMSampleBufferDataIsReady(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetAudioBufferListWithRetainedBlockBuffer(CMSampleBufferRef sbuf,
                                                                                  size_t* bufferListSizeNeededOut,
                                                                                  AudioBufferList* bufferListOut,
                                                                                  size_t bufferListSize,
                                                                                  CFAllocatorRef bbufStructAllocator,
                                                                                  CFAllocatorRef bbufMemoryAllocator,
                                                                                  uint32_t flags,
                                                                                  CMBlockBufferRef _Nullable* blockBufferOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetAudioStreamPacketDescriptions(CMSampleBufferRef sbuf,
                                                                         size_t packetDescriptionsSize,
                                                                         AudioStreamPacketDescription* packetDescriptionsOut,
                                                                         size_t* packetDescriptionsSizeNeededOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus
CMSampleBufferGetAudioStreamPacketDescriptionsPtr(CMSampleBufferRef sbuf,
                                                  const AudioStreamPacketDescription* _Nullable* packetDescriptionsPtrOut,
                                                  size_t* packetDescriptionsSizeOut) STUB_METHOD;
COREMEDIA_EXPORT CMBlockBufferRef CMSampleBufferGetDataBuffer(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetDecodeTimeStamp(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetDuration(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMFormatDescriptionRef CMSampleBufferGetFormatDescription(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CVImageBufferRef CMSampleBufferGetImageBuffer(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMItemCount CMSampleBufferGetNumSamples(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetOutputDecodeTimeStamp(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetOutputDuration(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetOutputPresentationTimeStamp(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetOutputSampleTimingInfoArray(CMSampleBufferRef sbuf,
                                                                       CMItemCount timingArrayEntries,
                                                                       CMSampleTimingInfo* timingArrayOut,
                                                                       CMItemCount* timingArrayEntriesNeededOut) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMSampleBufferGetPresentationTimeStamp(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CFArrayRef CMSampleBufferGetSampleAttachmentsArray(CMSampleBufferRef sbuf, Boolean createIfNecessary) STUB_METHOD;
COREMEDIA_EXPORT size_t CMSampleBufferGetSampleSize(CMSampleBufferRef sbuf, CMItemIndex sampleIndex) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetSampleSizeArray(CMSampleBufferRef sbuf,
                                                           CMItemCount sizeArrayEntries,
                                                           size_t* sizeArrayOut,
                                                           CMItemCount* sizeArrayEntriesNeededOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetSampleTimingInfo(CMSampleBufferRef sbuf,
                                                            CMItemIndex sampleIndex,
                                                            CMSampleTimingInfo* timingInfoOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferGetSampleTimingInfoArray(CMSampleBufferRef sbuf,
                                                                 CMItemCount timingArrayEntries,
                                                                 CMSampleTimingInfo* timingArrayOut,
                                                                 CMItemCount* timingArrayEntriesNeededOut) STUB_METHOD;
COREMEDIA_EXPORT size_t CMSampleBufferGetTotalSampleSize(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT CFTypeID CMSampleBufferGetTypeID() STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferInvalidate(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMSampleBufferIsValid(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferMakeDataReady(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferSetDataBuffer(CMSampleBufferRef sbuf, CMBlockBufferRef dataBuffer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferSetDataBufferFromAudioBufferList(CMSampleBufferRef sbuf,
                                                                         CFAllocatorRef bbufStructAllocator,
                                                                         CFAllocatorRef bbufMemoryAllocator,
                                                                         uint32_t flags,
                                                                         const AudioBufferList* bufferList) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferSetDataReady(CMSampleBufferRef sbuf) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferSetInvalidateCallback(CMSampleBufferRef sbuf,
                                                              CMSampleBufferInvalidateCallback invalidateCallback,
                                                              uint64_t invalidateRefCon) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferSetOutputPresentationTimeStamp(CMSampleBufferRef sbuf,
                                                                       CMTime outputPresentationTimeStamp) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMSampleBufferTrackDataReadiness(CMSampleBufferRef sbuf, CMSampleBufferRef sbufToTrack) STUB_METHOD;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferNotification_DataBecameReady;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotification_InhibitOutputUntil;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotification_ResetOutput;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotification_UpcomingOutputPTSRangeChanged;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConsumerNotification_BufferConsumed;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotificationParameter_ResumeTag;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotificationParameter_UpcomingOutputPTSRangeMayOverlapQueuedOutputPTSRange;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotificationParameter_MinUpcomingOutputPTS;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferConduitNotificationParameter_MaxUpcomingOutputPTS;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_NotSync;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_PartialSync;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_HasRedundantCoding;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_IsDependedOnByOthers;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_DependsOnOthers;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_EarlierDisplayTimesAllowed;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_DisplayImmediately;
COREMEDIA_EXPORT const CFStringRef kCMSampleAttachmentKey_DoNotDisplay;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_ResetDecoderBeforeDecoding;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_DrainAfterDecoding;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_PostNotificationWhenConsumed;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_ResumeOutput;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_TransitionID;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_TrimDurationAtStart;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_TrimDurationAtEnd;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_SpeedMultiplier;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_Reverse;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_FillDiscontinuitiesWithSilence;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_EmptyMedia;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_PermanentEmptyMedia;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_DisplayEmptyMediaImmediately;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_EndsPreviousSampleDuration;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_SampleReferenceURL;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_SampleReferenceByteOffset;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_GradualDecoderRefresh;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_DroppedFrameReason;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferAttachmentKey_DroppedFrameReasonInfo;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferDroppedFrameReason_FrameWasLate;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferDroppedFrameReason_OutOfBuffers;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferDroppedFrameReason_Discontinuity;
COREMEDIA_EXPORT const CFStringRef kCMSampleBufferDroppedFrameReasonInfo_CameraModeSwitch;
