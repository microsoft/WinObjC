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

#import <MediaPlayer/MediaPlayerExport.h>
#import <Foundation/NSObject.h>

@class NSDate;
@class NSString;

MEDIAPLAYER_EXPORT_CLASS
@interface MPMovieAccessLogEvent : NSObject <NSCopying>

@property (readonly, nonatomic) NSUInteger numberOfSegmentsDownloaded STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* playbackStartDate STUB_PROPERTY;
@property (readonly, nonatomic) NSString* URI STUB_PROPERTY;
@property (readonly, nonatomic) NSString* serverAddress STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger numberOfServerAddressChanges STUB_PROPERTY;
@property (readonly, nonatomic) NSString* playbackSessionID STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval playbackStartOffset STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval segmentsDownloadedDuration STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval durationWatched STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfStalls STUB_PROPERTY;
@property (readonly, nonatomic) int64_t numberOfBytesTransferred STUB_PROPERTY;
@property (readonly, nonatomic) double observedBitrate STUB_PROPERTY;
@property (readonly, nonatomic) double indicatedBitrate STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger numberOfDroppedVideoFrames STUB_PROPERTY;

@end
