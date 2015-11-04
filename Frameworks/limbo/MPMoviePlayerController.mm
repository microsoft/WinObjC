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

#include "Starboard.h"

#include "MediaPlayer/MPMoviePlayerController.h"

NSString* const MPMoviePlayerThumbnailImageKey = (NSString * const) @"MPMoviePlayerThumbnailImageKey";
NSString* const MPMoviePlayerThumbnailTimeKey = (NSString * const) @"MPMoviePlayerThumbnailTimeKey";
NSString* const MPMoviePlayerThumbnailErrorKey = (NSString * const) @"MPMoviePlayerThumbnailErrorKey";
NSString* const MPMoviePlayerFullscreenAnimationDurationUserInfoKey =
    (NSString * const) @"MPMoviePlayerFullscreenAnimationDurationUserInfoKey";
NSString* const MPMoviePlayerFullscreenAnimationCurveUserInfoKey = (NSString * const) @"MPMoviePlayerFullscreenAnimationCurveUserInfoKey";
NSString* const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey = (NSString * const) @"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey";

NSString* const MPMoviePlayerWillExitFullscreenNotification = (NSString * const) @"MPMoviePlayerWillExitFullscreenNotification";
NSString* const MPMoviePlayerDidExitFullscreenNotification = (NSString * const) @"MPMoviePlayerDidExitFullscreenNotification";
NSString* const MPMoviePlayerWillEnterFullscreenNotification = (NSString * const) @"MPMoviePlayerWillEnterFullscreenNotification";
NSString* const MPMoviePlayerDidEnterFullscreenNotification = (NSString * const) @"MPMoviePlayerDidEnterFullscreenNotification";
NSString* const MPMoviePlayerPlaybackDidFinishNotification = (NSString * const) @"MPMoviePlayerPlaybackDidFinishNotification";
NSString* const MPMoviePlayerLoadStateDidChangeNotification = (NSString * const) @"MPMoviePlayerLoadStateDidChangeNotification";

@implementation MPMoviePlayerController

@end
