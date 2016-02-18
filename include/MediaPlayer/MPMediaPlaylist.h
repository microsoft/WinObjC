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
#import <MediaPlayer/MPMediaItemCollection.h>

@class NSString;

typedef NS_OPTIONS(NSUInteger, MPMediaPlaylistAttribute) {
    MPMediaPlaylistAttributeNone = 0,
    MPMediaPlaylistAttributeOnTheGo = (1 << 0),
    MPMediaPlaylistAttributeSmart = (1 << 1),
    MPMediaPlaylistAttributeGenius = (1 << 2)
};

MEDIAPLAYER_EXPORT NSString* const MPMediaPlaylistPropertyPersistentID;
MEDIAPLAYER_EXPORT NSString* const MPMediaPlaylistPropertyName;
MEDIAPLAYER_EXPORT NSString* const MPMediaPlaylistPropertyPlaylistAttributes;
MEDIAPLAYER_EXPORT NSString* const MPMediaPlaylistPropertySeedItems;

MEDIAPLAYER_EXPORT_CLASS

@interface MPMediaPlaylist : MPMediaItemCollection 

@end
