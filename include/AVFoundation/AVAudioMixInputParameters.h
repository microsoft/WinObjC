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
#import <Foundation/NSObject.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

@class NSString;

typedef id MTAudioProcessingTapRef;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioMixInputParameters : NSObject <NSCopying, NSMutableCopying>
@property (readonly, nonatomic) CMPersistentTrackID trackID STUB_PROPERTY;
- (BOOL)getVolumeRampForTime:(CMTime)time
                 startVolume:(float*)startVolume
                   endVolume:(float*)endVolume
                   timeRange:(CMTimeRange*)timeRange STUB_METHOD;
@property (readonly, retain, nonatomic) MTAudioProcessingTapRef audioTapProcessor STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* audioTimePitchAlgorithm STUB_PROPERTY;
@end
