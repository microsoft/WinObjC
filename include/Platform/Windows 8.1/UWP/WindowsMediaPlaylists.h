//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsMediaPlaylists.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMPPlaylist;
@protocol WMPIPlaylist
, WMPIPlaylistStatics;

// Windows.Media.Playlists.PlaylistFormat
enum _WMPPlaylistFormat {
    WMPPlaylistFormatWindowsMedia = 0,
    WMPPlaylistFormatZune = 1,
    WMPPlaylistFormatM3u = 2,
};
typedef unsigned WMPPlaylistFormat;

#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.Media.Playlists.Playlist
#ifndef __WMPPlaylist_DEFINED__
#define __WMPPlaylist_DEFINED__

WINRT_EXPORT
@interface WMPPlaylist : RTObject
+ (void)loadAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WMPPlaylist*))success failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WSStorageFile*/ files;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (void)saveAsAsync:(RTObject<WSIStorageFolder>*)saveLocation
        desiredName:(NSString*)desiredName
             option:(WSNameCollisionOption)option
            success:(void (^)(WSStorageFile*))success
            failure:(void (^)(NSError*))failure;
- (void)saveAsWithFormatAsync:(RTObject<WSIStorageFolder>*)saveLocation
                  desiredName:(NSString*)desiredName
                       option:(WSNameCollisionOption)option
               playlistFormat:(WMPPlaylistFormat)playlistFormat
                      success:(void (^)(WSStorageFile*))success
                      failure:(void (^)(NSError*))failure;
@end

#endif // __WMPPlaylist_DEFINED__
