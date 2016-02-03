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

typedef NS_OPTIONS(NSUInteger, AVAssetReferenceRestrictions) {
    AVAssetReferenceRestrictionForbidNone = 0UL,
    AVAssetReferenceRestrictionForbidRemoteReferenceToLocal = (1UL << 0),
    AVAssetReferenceRestrictionForbidLocalReferenceToRemote = (1UL << 1),
    AVAssetReferenceRestrictionForbidCrossSiteReference = (1UL << 2),
    AVAssetReferenceRestrictionForbidLocalReferenceToLocal = (1UL << 3),
    AVAssetReferenceRestrictionForbidAll = 0xFFFFUL,
};

@class NSURL;
@class NSArray;
@class NSString;
@class NSLocale;
@class AVAssetTrack;
@class AVMediaSelectionGroup;
@class AVMetadataItem;

AVFOUNDATION_EXPORT_CLASS
@interface AVAsset : NSObject <AVAsynchronousKeyValueLoading, NSCopying>
+ (instancetype)assetWithURL:(NSURL*)URL STUB_METHOD;
- (void)cancelLoading STUB_METHOD;
@property (readonly, nonatomic) NSArray* commonMetadata STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableMetadataFormats STUB_PROPERTY;
- (NSArray*)metadataForFormat:(NSString*)format STUB_METHOD;
@property (readonly, nonatomic) NSString* lyrics STUB_PROPERTY;
@property (readonly) NSArray* availableChapterLocales STUB_PROPERTY;
- (NSArray*)chapterMetadataGroupsWithTitleLocale:(NSLocale*)locale containingItemsWithCommonKeys:(NSArray*)commonKeys STUB_METHOD;
- (NSArray*)chapterMetadataGroupsBestMatchingPreferredLanguages:(NSArray*)preferredLanguages STUB_METHOD;
@property (readonly, nonatomic) NSArray* tracks STUB_PROPERTY;
- (AVAssetTrack*)trackWithTrackID:(CMPersistentTrackID)trackID STUB_METHOD;
- (NSArray*)tracksWithMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
- (NSArray*)tracksWithMediaType:(NSString*)mediaType STUB_METHOD;
@property (readonly, nonatomic) NSArray* trackGroups STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasProtectedContent STUB_PROPERTY;
@property (readonly, getter=isPlayable, nonatomic) BOOL playable STUB_PROPERTY;
@property (readonly, getter=isExportable, nonatomic) BOOL exportable STUB_PROPERTY;
@property (readonly, getter=isReadable, nonatomic) BOOL readable STUB_PROPERTY;
@property (readonly, getter=isComposable, nonatomic) BOOL composable STUB_PROPERTY;
- (CMPersistentTrackID)unusedTrackID STUB_METHOD;
@property (readonly, nonatomic) NSArray* metadata STUB_PROPERTY;
@property (readonly, nonatomic) CMTime duration STUB_PROPERTY;
@property (readonly, nonatomic) BOOL providesPreciseDurationAndTiming STUB_PROPERTY;
@property (readonly, nonatomic) CGSize naturalSize STUB_PROPERTY;
@property (readonly, nonatomic) float preferredRate STUB_PROPERTY;
@property (readonly, nonatomic) CGAffineTransform preferredTransform STUB_PROPERTY;
@property (readonly, nonatomic) float preferredVolume STUB_PROPERTY;
@property (readonly, nonatomic) AVAssetReferenceRestrictions referenceRestrictions STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* availableMediaCharacteristicsWithMediaSelectionOptions STUB_PROPERTY;
- (AVMediaSelectionGroup*)mediaSelectionGroupForMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
@property (readonly, getter=isCompatibleWithSavedPhotosAlbum, nonatomic) BOOL compatibleWithSavedPhotosAlbum STUB_PROPERTY;
@property (readonly, nonatomic) AVMetadataItem* creationDate STUB_PROPERTY;
@end
