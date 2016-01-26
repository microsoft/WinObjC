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

#import <StubReturn.h>
#import <MediaPlayer/MPMediaItem.h>
#import <MediaPlayer/MPMediaQuery.h>

NSString* const MPMediaItemPropertyPersistentID = @"MPMediaItemPropertyPersistentID";
NSString* const MPMediaItemPropertyAlbumPersistentID = @"MPMediaItemPropertyAlbumPersistentID";
NSString* const MPMediaItemPropertyArtistPersistentID = @"MPMediaItemPropertyArtistPersistentID";
NSString* const MPMediaItemPropertyAlbumArtistPersistentID = @"MPMediaItemPropertyAlbumArtistPersistentID";
NSString* const MPMediaItemPropertyGenrePersistentID = @"MPMediaItemPropertyGenrePersistentID";
NSString* const MPMediaItemPropertyComposerPersistentID = @"MPMediaItemPropertyComposerPersistentID";
NSString* const MPMediaItemPropertyPodcastPersistentID = @"MPMediaItemPropertyPodcastPersistentID";
NSString* const MPMediaItemPropertyMediaType = @"MPMediaItemPropertyMediaType";
NSString* const MPMediaItemPropertyTitle = @"MPMediaItemPropertyTitle";
NSString* const MPMediaItemPropertyAlbumTitle = @"MPMediaItemPropertyAlbumTitle";
NSString* const MPMediaItemPropertyArtist = @"MPMediaItemPropertyArtist";
NSString* const MPMediaItemPropertyAlbumArtist = @"MPMediaItemPropertyAlbumArtist";
NSString* const MPMediaItemPropertyGenre = @"MPMediaItemPropertyGenre";
NSString* const MPMediaItemPropertyComposer = @"MPMediaItemPropertyComposer";
NSString* const MPMediaItemPropertyPlaybackDuration = @"MPMediaItemPropertyPlaybackDuration";
NSString* const MPMediaItemPropertyAlbumTrackNumber = @"MPMediaItemPropertyAlbumTrackNumber";
NSString* const MPMediaItemPropertyAlbumTrackCount = @"MPMediaItemPropertyAlbumTrackCount";
NSString* const MPMediaItemPropertyDiscNumber = @"MPMediaItemPropertyDiscNumber";
NSString* const MPMediaItemPropertyDiscCount = @"MPMediaItemPropertyDiscCount";
NSString* const MPMediaItemPropertyArtwork = @"MPMediaItemPropertyArtwork";
NSString* const MPMediaItemPropertyLyrics = @"MPMediaItemPropertyLyrics";
NSString* const MPMediaItemPropertyIsCompilation = @"MPMediaItemPropertyIsCompilation";
NSString* const MPMediaItemPropertyReleaseDate = @"MPMediaItemPropertyReleaseDate";
NSString* const MPMediaItemPropertyBeatsPerMinute = @"MPMediaItemPropertyBeatsPerMinute";
NSString* const MPMediaItemPropertyComments = @"MPMediaItemPropertyComments";
NSString* const MPMediaItemPropertyAssetURL = @"MPMediaItemPropertyAssetURL";
NSString* const MPMediaItemPropertyIsCloudItem = @"MPMediaItemPropertyIsCloudItem";
NSString* const MPMediaItemPropertyPodcastTitle = @"MPMediaItemPropertyPodcastTitle";
NSString* const MPMediaItemPropertyPlayCount = @"MPMediaItemPropertyPlayCount";
NSString* const MPMediaItemPropertySkipCount = @"MPMediaItemPropertySkipCount";
NSString* const MPMediaItemPropertyRating = @"MPMediaItemPropertyRating";
NSString* const MPMediaItemPropertyLastPlayedDate = @"MPMediaItemPropertyLastPlayedDate";
NSString* const MPMediaItemPropertyUserGrouping = @"MPMediaItemPropertyUserGrouping";
NSString* const MPMediaItemPropertyBookmarkTime = @"MPMediaItemPropertyBookmarkTime";

@implementation MPMediaItem
/**
 @Status Stub
 @Notes
*/
+ (NSString*)persistentIDPropertyForGroupingType:(MPMediaGrouping)groupingType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)titlePropertyForGroupingType:(MPMediaGrouping)groupingType {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
