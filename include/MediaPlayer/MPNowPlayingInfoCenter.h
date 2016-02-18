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

@class NSString;
@class NSDictionary;

MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyElapsedPlaybackTime;
MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyPlaybackRate;
MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyPlaybackQueueIndex;
MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyPlaybackQueueCount;
MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyChapterNumber;
MEDIAPLAYER_EXPORT NSString* const MPNowPlayingInfoPropertyChapterCount;

MEDIAPLAYER_EXPORT_CLASS
@interface MPNowPlayingInfoCenter : NSObject <NSObject>

+ (MPNowPlayingInfoCenter*)defaultCenter STUB_METHOD;

@property (copy) NSDictionary* nowPlayingInfo STUB_PROPERTY;

@end
