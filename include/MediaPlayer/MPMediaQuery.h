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

@class NSSet;
@class NSArray;
@class MPMediaPredicate;

typedef NS_ENUM(NSUInteger, MPMediaGrouping) {
    MPMediaGroupingTitle,
    MPMediaGroupingAlbum,
    MPMediaGroupingArtist,
    MPMediaGroupingAlbumArtist,
    MPMediaGroupingComposer,
    MPMediaGroupingGenre,
    MPMediaGroupingPlaylist,
    MPMediaGroupingPodcastTitle,
};

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaQuery : NSObject <NSCopying, NSSecureCoding>

+ (MPMediaQuery*)albumsQuery STUB_METHOD;
+ (MPMediaQuery*)artistsQuery STUB_METHOD;
+ (MPMediaQuery*)songsQuery STUB_METHOD;
+ (MPMediaQuery*)playlistsQuery STUB_METHOD;
+ (MPMediaQuery*)podcastsQuery STUB_METHOD;
+ (MPMediaQuery*)audiobooksQuery STUB_METHOD;
+ (MPMediaQuery*)compilationsQuery STUB_METHOD;
+ (MPMediaQuery*)composersQuery STUB_METHOD;
+ (MPMediaQuery*)genresQuery STUB_METHOD;

@property (nonatomic, strong) NSSet* filterPredicates STUB_PROPERTY;
@property (nonatomic) MPMediaGrouping groupingType STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* itemSections STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* collectionSections STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* items STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* collections STUB_PROPERTY;

-(id)init STUB_METHOD;
-(instancetype)initWithFilterPredicates:(NSSet*)filterPredicates STUB_METHOD;
- (void)addFilterPredicate:(MPMediaPredicate*)predicate STUB_METHOD;
- (void)removeFilterPredicate:(MPMediaPredicate*)predicate STUB_METHOD;

@end
