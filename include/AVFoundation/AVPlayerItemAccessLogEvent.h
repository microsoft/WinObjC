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

@class NSString;
@class NSDate;

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayerItemAccessLogEvent : NSObject <NSCopying>
@property (readonly, nonatomic) NSString* URI STUB_PROPERTY;
@property (readonly, nonatomic) NSString* serverAddress STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfServerAddressChanges STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger mediaRequestsWWAN STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval transferDuration STUB_PROPERTY;
@property (readonly, nonatomic) long long numberOfBytesTransferred STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfMediaRequests STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* playbackStartDate STUB_PROPERTY;
@property (readonly, nonatomic) NSString* playbackSessionID STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval playbackStartOffset STUB_PROPERTY;
@property (readonly, nonatomic) NSString* playbackType STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval startupTime STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval durationWatched STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfDroppedVideoFrames STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfStalls STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfSegmentsDownloaded STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval segmentsDownloadedDuration STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger downloadOverdue STUB_PROPERTY;
@property (readonly, nonatomic) double observedBitrateStandardDeviation STUB_PROPERTY;
@property (readonly, nonatomic) double observedMaxBitrate STUB_PROPERTY;
@property (readonly, nonatomic) double observedMinBitrate STUB_PROPERTY;
@property (readonly, nonatomic) double switchBitrate STUB_PROPERTY;
@property (readonly, nonatomic) double indicatedBitrate STUB_PROPERTY;
@property (readonly, nonatomic) double observedBitrate STUB_PROPERTY;
@end
