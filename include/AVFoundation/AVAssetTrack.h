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

#import <AVFoundation/AVFoundationExport.h>
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

@class NSString;
@class AVAsset;
@class NSArray;
@class AVAssetTrackSegment;

AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeAudioFallback;
AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeChapterList;
AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeForcedSubtitlesOnly;
AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeSelectionFollower;
AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeTimecode;
AVFOUNDATION_EXPORT NSString* const AVTrackAssociationTypeMetadataReferent;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetTrack : NSObject <AVAsynchronousKeyValueLoading, NSCopying>
@property (readonly, nonatomic, weak) AVAsset* asset STUB_PROPERTY;
@property (readonly, nonatomic) CMPersistentTrackID trackID STUB_PROPERTY;
@property (readonly, nonatomic) NSString* mediaType STUB_PROPERTY;
- (BOOL)hasMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
@property (readonly, nonatomic) NSArray* formatDescriptions STUB_PROPERTY;
@property (readonly, getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (readonly, getter=isPlayable, nonatomic) BOOL playable STUB_PROPERTY;
@property (readonly, getter=isSelfContained, nonatomic) BOOL selfContained STUB_PROPERTY;
@property (readonly, nonatomic) long long totalSampleDataLength STUB_PROPERTY;
@property (readonly, nonatomic) CMTimeRange timeRange STUB_PROPERTY;
@property (readonly, nonatomic) CMTimeScale naturalTimeScale STUB_PROPERTY;
@property (readonly, nonatomic) float estimatedDataRate STUB_PROPERTY;
@property (readonly, nonatomic) NSString* languageCode STUB_PROPERTY;
@property (readonly, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (readonly, nonatomic) CGSize naturalSize STUB_PROPERTY;
@property (readonly, nonatomic) CGAffineTransform preferredTransform STUB_PROPERTY;
@property (readonly, nonatomic) float preferredVolume STUB_PROPERTY;
@property (readonly, nonatomic) float nominalFrameRate STUB_PROPERTY;
@property (readonly, nonatomic) CMTime minFrameDuration STUB_PROPERTY;
@property (readonly, nonatomic) BOOL requiresFrameReordering STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* segments STUB_PROPERTY;
- (AVAssetTrackSegment*)segmentForTrackTime:(CMTime)trackTime STUB_METHOD;
- (CMTime)samplePresentationTimeForTrackTime:(CMTime)trackTime STUB_METHOD;
@property (readonly, nonatomic) NSArray* commonMetadata STUB_PROPERTY;
- (NSArray*)metadataForFormat:(NSString*)format STUB_METHOD;
@property (readonly, nonatomic) NSArray* availableMetadataFormats STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* metadata STUB_PROPERTY;
- (NSArray*)associatedTracksOfType:(NSString*)trackAssociationType STUB_METHOD;
@property (readonly, nonatomic) NSArray* availableTrackAssociationTypes STUB_PROPERTY;
@end
