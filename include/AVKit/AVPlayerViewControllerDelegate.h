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

@class AVPlayerViewController;

@protocol AVPlayerViewControllerDelegate <NSObject>
@optional
- (BOOL)playerViewControllerShouldAutomaticallyDismissAtPictureInPictureStart:(AVPlayerViewController*)playerViewController;
- (void)playerViewController:(AVPlayerViewController*)playerViewController
    restoreUserInterfaceForPictureInPictureStopWithCompletionHandler:(void (^)(BOOL restored))completionHandler;
- (void)playerViewControllerDidStartPictureInPicture:(AVPlayerViewController*)playerViewController;
- (void)playerViewControllerDidStopPictureInPicture:(AVPlayerViewController*)playerViewController;
- (void)playerViewControllerWillStartPictureInPicture:(AVPlayerViewController*)playerViewController;
- (void)playerViewControllerWillStopPictureInPicture:(AVPlayerViewController*)playerViewController;
@end
