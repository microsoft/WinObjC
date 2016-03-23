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

#pragma once

#import <StubIncludes.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVFoundationExport.h>
#import <AVFoundation/AVFoundationTypes.h>
#import <AVFoundation/AVFoundationConstants.h>
#import <AVFoundation/AVAsset.h>
#import <AVFoundation/AVAssetExportSession.h>
#import <AVFoundation/AVAssetImageGenerator.h>
#import <AVFoundation/AVAssetReader.h>
#import <AVFoundation/AVAssetReaderAudioMixOutput.h>
#import <AVFoundation/AVAssetReaderOutput.h>
#import <AVFoundation/AVAssetReaderOutputMetadataAdaptor.h>
#import <AVFoundation/AVAssetReaderSampleReferenceOutput.h>
#import <AVFoundation/AVAssetReaderTrackOutput.h>
#import <AVFoundation/AVAssetReaderVideoCompositionOutput.h>
#import <AVFoundation/AVAssetResourceLoader.h>
#import <AVFoundation/AVAssetResourceLoaderDelegate.h>
#import <AVFoundation/AVAssetResourceLoadingContentInformationRequest.h>
#import <AVFoundation/AVAssetResourceLoadingDataRequest.h>
#import <AVFoundation/AVAssetResourceLoadingRequest.h>
#import <AVFoundation/AVAssetResourceRenewalRequest.h>
#import <AVFoundation/AVAssetTrack.h>
#import <AVFoundation/AVAssetTrackGroup.h>
#import <AVFoundation/AVAssetTrackSegment.h>
#import <AVFoundation/AVAssetWriter.h>
#import <AVFoundation/AVAssetWriterInput.h>
#import <AVFoundation/AVAssetWriterInputGroup.h>
#import <AVFoundation/AVAssetWriterInputMetadataAdaptor.h>
#import <AVFoundation/AVAssetWriterInputPassDescription.h>
#import <AVFoundation/AVAssetWriterInputPixelBufferAdaptor.h>
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>
#import <AVFoundation/AVAsynchronousVideoCompositionRequest.h>
#import <AVFoundation/AVAudio3DMixing.h>
#import <AVFoundation/AVAudioBuffer.h>
#import <AVFoundation/AVAudioChannelLayout.h>
#import <AVFoundation/AVAudioEngine.h>
#import <AVFoundation/AVAudioEnvironmentDistanceAttenuationParameters.h>
#import <AVFoundation/AVAudioEnvironmentNode.h>
#import <AVFoundation/AVAudioEnvironmentReverbParameters.h>
#import <AVFoundation/AVAudioFile.h>
#import <AVFoundation/AVAudioFormat.h>
#import <AVFoundation/AVAudioInputNode.h>
#import <AVFoundation/AVAudioIONode.h>
#import <AVFoundation/AVAudioMix.h>
#import <AVFoundation/AVAudioMixerNode.h>
#import <AVFoundation/AVAudioMixing.h>
#import <AVFoundation/AVAudioMixInputParameters.h>
#import <AVFoundation/AVAudioNode.h>
#import <AVFoundation/AVAudioOutputNode.h>
#import <AVFoundation/AVAudioPCMBuffer.h>
#import <AVFoundation/AVAudioPlayer.h>
#import <AVFoundation/AVAudioPlayerDelegate.h>
#import <AVFoundation/AVAudioPlayerNode.h>
#import <AVFoundation/AVAudioRecorder.h>
#import <AVFoundation/AVAudioRecorderDelegate.h>
#import <AVFoundation/AVAudioSession.h>
#import <AVFoundation/AVAudioSessionChannelDescription.h>
#import <AVFoundation/AVAudioSessionDataSourceDescription.h>
#import <AVFoundation/AVAudioSessionDelegate.h>
#import <AVFoundation/AVAudioSessionPortDescription.h>
#import <AVFoundation/AVAudioSessionRouteDescription.h>
#import <AVFoundation/AVAudioStereoMixing.h>
#import <AVFoundation/AVAudioTime.h>
#import <AVFoundation/AVAudioUnit.h>
#import <AVFoundation/AVAudioUnitDelay.h>
#import <AVFoundation/AVAudioUnitDistortion.h>
#import <AVFoundation/AVAudioUnitEffect.h>
#import <AVFoundation/AVAudioUnitEQ.h>
#import <AVFoundation/AVAudioUnitEQFilterParameters.h>
#import <AVFoundation/AVAudioUnitGenerator.h>
#import <AVFoundation/AVAudioUnitMIDIInstrument.h>
#import <AVFoundation/AVAudioUnitReverb.h>
#import <AVFoundation/AVAudioUnitSampler.h>
#import <AVFoundation/AVAudioUnitTimeEffect.h>
#import <AVFoundation/AVAudioUnitTimePitch.h>
#import <AVFoundation/AVAudioUnitVarispeed.h>
#import <AVFoundation/AVCaptureAudioChannel.h>
#import <AVFoundation/AVCaptureAudioDataOutput.h>
#import <AVFoundation/AVCaptureAudioDataOutputSampleBufferDelegate.h>
#import <AVFoundation/AVCaptureAutoExposureBracketedStillImageSettings.h>
#import <AVFoundation/AVCaptureBracketedStillImageSettings.h>
#import <AVFoundation/AVCaptureConnection.h>
#import <AVFoundation/AVCaptureDevice.h>
#import <AVFoundation/AVCaptureDeviceFormat.h>
#import <AVFoundation/AVCaptureDeviceInput.h>
#import <AVFoundation/AVCaptureFileOutput.h>
#import <AVFoundation/AVCaptureFileOutputRecordingDelegate.h>
#import <AVFoundation/AVCaptureInput.h>
#import <AVFoundation/AVCaptureInputPort.h>
#import <AVFoundation/AVCaptureManualExposureBracketedStillImageSettings.h>
#import <AVFoundation/AVCaptureMetadataOutput.h>
#import <AVFoundation/AVCaptureMetadataOutputObjectsDelegate.h>
#import <AVFoundation/AVCaptureMovieFileOutput.h>
#import <AVFoundation/AVCaptureOutput.h>
#import <AVFoundation/AVCaptureSession.h>
#import <AVFoundation/AVCaptureStillImageOutput.h>
#import <AVFoundation/AVCaptureVideoDataOutput.h>
#import <AVFoundation/AVCaptureVideoDataOutputSampleBufferDelegate.h>
#import <AVFoundation/AVCaptureVideoPreviewLayer.h>
#import <AVFoundation/AVComposition.h>
#import <AVFoundation/AVCompositionTrack.h>
#import <AVFoundation/AVCompositionTrackSegment.h>
#import <AVFoundation/AVFoundationTypes.h>
#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVFrameRateRange.h>
#import <AVFoundation/AVMediaSelectionGroup.h>
#import <AVFoundation/AVMediaSelectionOption.h>
#import <AVFoundation/AVMetadataFaceObject.h>
#import <AVFoundation/AVMetadataGroup.h>
#import <AVFoundation/AVMetadataItem.h>
#import <AVFoundation/AVMetadataItemFilter.h>
#import <AVFoundation/AVMetadataMachineReadableCodeObject.h>
#import <AVFoundation/AVMetadataObject.h>
#import <AVFoundation/AVMIDIPlayer.h>
#import <AVFoundation/AVOutputSettingsAssistant.h>
#import <AVFoundation/AVPlayer.h>
#import <AVFoundation/AVPlayerItem.h>
#import <AVFoundation/AVPlayerItemAccessLog.h>
#import <AVFoundation/AVPlayerItemAccessLogEvent.h>
#import <AVFoundation/AVPlayerItemErrorLog.h>
#import <AVFoundation/AVPlayerItemErrorLogEvent.h>
#import <AVFoundation/AVPlayerItemLegibleOutput.h>
#import <AVFoundation/AVPlayerItemLegibleOutputPushDelegate.h>
#import <AVFoundation/AVPlayerItemMetadataOutput.h>
#import <AVFoundation/AVPlayerItemMetadataOutputPushDelegate.h>
#import <AVFoundation/AVPlayerItemOutput.h>
#import <AVFoundation/AVPlayerItemOutputPullDelegate.h>
#import <AVFoundation/AVPlayerItemOutputPushDelegate.h>
#import <AVFoundation/AVPlayerItemTrack.h>
#import <AVFoundation/AVPlayerItemVideoOutput.h>
#import <AVFoundation/AVPlayerLayer.h>
#import <AVFoundation/AVPlayerMediaSelectionCriteria.h>
#import <AVFoundation/AVQueuePlayer.h>
#import <AVFoundation/AVSampleBufferDisplayLayer.h>
#import <AVFoundation/AVSpeechSynthesisVoice.h>
#import <AVFoundation/AVSpeechSynthesizer.h>
#import <AVFoundation/AVSpeechSynthesizerDelegate.h>
#import <AVFoundation/AVSpeechUtterance.h>
#import <AVFoundation/AVSynchronizedLayer.h>
#import <AVFoundation/AVTextStyleRule.h>
#import <AVFoundation/AVTimedMetadataGroup.h>
#import <AVFoundation/AVURLAsset.h>
#import <AVFoundation/AVVideoCompositing.h>
#import <AVFoundation/AVVideoComposition.h>
#import <AVFoundation/AVVideoCompositionCoreAnimationTool.h>
#import <AVFoundation/AVVideoCompositionInstruction.h>
#import <AVFoundation/AVVideoCompositionLayerInstruction.h>
#import <AVFoundation/AVVideoCompositionRenderContext.h>
#import <AVFoundation/AVVideoCompositionValidationHandling.h>
#import <AVFoundation/AVMutableAudioMix.h>
#import <AVFoundation/AVMutableAudioMixInputParameters.h>
#import <AVFoundation/AVMutableComposition.h>
#import <AVFoundation/AVMutableCompositionTrack.h>
#import <AVFoundation/AVMutableMetadataItem.h>
#import <AVFoundation/AVMutableTimedMetadataGroup.h>
#import <AVFoundation/AVMutableVideoComposition.h>
#import <AVFoundation/AVMutableVideoCompositionInstruction.h>
#import <AVFoundation/AVMutableVideoCompositionLayerInstruction.h>
