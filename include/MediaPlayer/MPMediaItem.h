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
#import <MediaPlayer/MPMediaQuery.h>
#import <MediaPlayer/MPMediaEntity.h>

typedef NS_OPTIONS(NSUInteger, MPMediaType) {
    // audio media types
    MPMediaTypeMusic = 1 << 0,
    MPMediaTypePodcast = 1 << 1,
    MPMediaTypeAudioBook = 1 << 2,
    MPMediaTypeAudioITunesU = 1 << 3, // available in iOS 5.0
    MPMediaTypeAnyAudio = 0x00ff,

    // video media types
    MPMediaTypeMovie = 1 << 8,
    MPMediaTypeTVShow = 1 << 9,
    MPMediaTypeVideoPodcast = 1 << 10,
    MPMediaTypeMusicVideo = 1 << 11,
    MPMediaTypeVideoITunesU = 1 << 12,
    MPMediaTypeAnyVideo = 0xff00, // generic media type
    MPMediaTypeAny = ~0
};

MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyArtistPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumArtistPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyGenrePersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyComposerPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyPodcastPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyMediaType;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyTitle;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumTitle;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyArtist;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumArtist;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyGenre;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyComposer;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyPlaybackDuration;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumTrackNumber;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAlbumTrackCount;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyDiscNumber;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyDiscCount;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyArtwork;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyLyrics;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyIsCompilation;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyReleaseDate;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyBeatsPerMinute;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyComments;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyAssetURL;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyIsCloudItem;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyPodcastTitle;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyPlayCount;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertySkipCount;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyRating;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyLastPlayedDate;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyUserGrouping;
MEDIAPLAYER_EXPORT NSString* const MPMediaItemPropertyBookmarkTime;

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaItem : MPMediaEntity

+ (NSString*)persistentIDPropertyForGroupingType:(MPMediaGrouping)groupingType STUB_METHOD;
+ (NSString*)titlePropertyForGroupingType:(MPMediaGrouping)groupingType STUB_METHOD;

@end
