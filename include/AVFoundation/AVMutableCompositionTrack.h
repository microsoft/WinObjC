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
#import <CoreGraphics/CGAffineTransform.h>
#import <AVFoundation/AVCompositionTrack.h>
#import <CoreMedia/CMTime.h>

@class AVAssetTrack;
@class NSError;
@class NSArray;
@class NSString;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableCompositionTrack : AVCompositionTrack <AVAsynchronousKeyValueLoading, NSCopying>
- (void)insertEmptyTimeRange:(CMTimeRange)timeRange STUB_METHOD;
- (BOOL)insertTimeRange:(CMTimeRange)timeRange
                ofTrack:(AVAssetTrack*)track
                 atTime:(CMTime)startTime
                  error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)insertTimeRanges:(NSArray*)timeRanges
                ofTracks:(NSArray*)tracks
                  atTime:(CMTime)startTime
                   error:(NSError* _Nullable*)error STUB_METHOD;
- (void)removeTimeRange:(CMTimeRange)timeRange STUB_METHOD;
- (void)scaleTimeRange:(CMTimeRange)timeRange toDuration:(CMTime)duration STUB_METHOD;
@property (copy, nonatomic) NSArray* segments STUB_PROPERTY;
- (BOOL)validateTrackSegments:(NSArray*)trackSegments error:(NSError* _Nullable*)error STUB_METHOD;
@property (copy, nonatomic) NSString* languageCode STUB_PROPERTY;
@property (copy, nonatomic) NSString* extendedLanguageTag STUB_PROPERTY;
@property (nonatomic) CMTimeScale naturalTimeScale STUB_PROPERTY;
@property (nonatomic) CGAffineTransform preferredTransform STUB_PROPERTY;
@property (nonatomic) float preferredVolume STUB_PROPERTY;
@end
