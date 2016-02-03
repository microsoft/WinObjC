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

#import <AVKit/AVKitExport.h>
#import <Foundation/NSObject.h>

@class AVPlayerLayer;
@protocol AVPictureInPictureControllerDelegate;

AVKIT_EXPORT_CLASS
@interface AVPictureInPictureController : NSObject
- (instancetype)initWithPlayerLayer:(AVPlayerLayer*)playerLayer STUB_METHOD;
@property (nonatomic, weak) id<AVPictureInPictureControllerDelegate> delegate STUB_PROPERTY;
@property (readonly, nonatomic) AVPlayerLayer* playerLayer STUB_PROPERTY;
+ (BOOL)isPictureInPictureSupported STUB_METHOD;
@property (readonly, getter=isPictureInPicturePossible, nonatomic) BOOL pictureInPicturePossible STUB_PROPERTY;
@property (readonly, getter=isPictureInPictureActive, nonatomic) BOOL pictureInPictureActive STUB_PROPERTY;
@property (readonly, getter=isPictureInPictureSuspended, nonatomic) BOOL pictureInPictureSuspended STUB_PROPERTY;
- (void)startPictureInPicture STUB_METHOD;
- (void)stopPictureInPicture STUB_METHOD;
@end
