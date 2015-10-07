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

#include <AVFoundation/AVExport.h>

#ifndef _AVAUDIOPLAYER_H_
#define _AVAUDIOPLAYER_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>

@class NSURL;
@class NSError;

@protocol AVAudioPlayerDelegate <NSObject>
@end

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioPlayer : NSObject

@property (readonly, getter=isPlaying) BOOL playing;
@property NSTimeInterval currentTime;
@property float volume;
@property (assign) id delegate;
@property NSInteger numberOfLoops;
@property (readonly) NSTimeInterval duration;
@property (readonly) NSURL *url;
@property float pan;

- (void)pause;
- (void)stop;
- (BOOL)play;
- (id)initWithContentsOfURL:(NSURL *)url error:(NSError **)outError;
- (BOOL)prepareToPlay;
- (id)initWithData:(NSData *)data error:(NSError **)outError;

@end

#endif /* _AVAUDIOPLAYER_H_ */
