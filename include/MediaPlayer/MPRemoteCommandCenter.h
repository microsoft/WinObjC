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

@class MPRemoteCommand;
@class MPChangePlaybackRateCommand;
@class MPSkipIntervalCommand;
@class MPRatingCommand;
@class MPFeedbackCommand;

MEDIAPLAYER_EXPORT_CLASS
@interface MPRemoteCommandCenter : NSObject

+ (MPRemoteCommandCenter*)sharedCommandCenter STUB_METHOD;

@property (readonly, nonatomic) MPRemoteCommand* pauseCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* playCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* stopCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* togglePlayPauseCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* nextTrackCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* previousTrackCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPChangePlaybackRateCommand* changePlaybackRateCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* seekBackwardCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRemoteCommand* seekForwardCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPSkipIntervalCommand* skipBackwardCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPSkipIntervalCommand* skipForwardCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPRatingCommand* ratingCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPFeedbackCommand* likeCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPFeedbackCommand* dislikeCommand STUB_PROPERTY;
@property (readonly, nonatomic) MPFeedbackCommand* bookmarkCommand STUB_PROPERTY;

@end
