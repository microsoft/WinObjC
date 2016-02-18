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

#import <Foundation/NSObject.h>
#import <MediaPlayer/MediaPlayerExport.h>
#import <MediaPlayer/MPMediaItem.h>
#import <MediaPlayer/MPMediaPlayback.h>

@class MPMediaItem;
@class MPMediaQuery;
@class MPMediaItemCollection;

typedef NS_ENUM(NSUInteger, MPMusicPlaybackState) {
    MPMusicPlaybackStateStopped,
    MPMusicPlaybackStatePlaying,
    MPMusicPlaybackStatePaused,
    MPMusicPlaybackStateInterrupted,
    MPMusicPlaybackStateSeekingForward,
    MPMusicPlaybackStateSeekingBackward
};

typedef NS_ENUM(NSUInteger, MPMusicRepeatMode) {
    MPMusicRepeatModeDefault,
    MPMusicRepeatModeNone,
    MPMusicRepeatModeOne,
    MPMusicRepeatModeAll 
};

typedef NS_ENUM(NSUInteger, MPMusicShuffleMode) {
    MPMusicShuffleModeDefault,
    MPMusicShuffleModeOff,
    MPMusicShuffleModeSongs,
    MPMusicShuffleModeAlbums 
};

MEDIAPLAYER_EXPORT_CLASS
@interface MPMusicPlayerController : NSObject <MPMediaPlayback, NSObject>

+ (MPMusicPlayerController*)applicationMusicPlayer STUB_METHOD;
+ (MPMusicPlayerController*)systemMusicPlayer STUB_METHOD;
+ (MPMusicPlayerController*)iPodMusicPlayer STUB_METHOD;

@property (copy, nonatomic) MPMediaItem* nowPlayingItem STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger indexOfNowPlayingItem STUB_PROPERTY;
@property (readonly, nonatomic) MPMusicPlaybackState playbackState STUB_PROPERTY;
@property (nonatomic) MPMusicRepeatMode repeatMode STUB_PROPERTY;
@property (nonatomic) MPMusicShuffleMode shuffleMode STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;

@property (nonatomic, readonly) BOOL isPreparedToPlay STUB_PROPERTY;
@property (nonatomic) float currentPlaybackRate STUB_PROPERTY;
@property (nonatomic) NSTimeInterval currentPlaybackTime STUB_PROPERTY;

- (void)setQueueWithQuery:(MPMediaQuery*)query STUB_METHOD;
- (void)setQueueWithItemCollection:(MPMediaItemCollection*)itemCollection STUB_METHOD;
- (void)skipToNextItem STUB_METHOD;
- (void)skipToBeginning STUB_METHOD;
- (void)skipToPreviousItem STUB_METHOD;
- (void)beginGeneratingPlaybackNotifications STUB_METHOD;
- (void)endGeneratingPlaybackNotifications STUB_METHOD;

@end
