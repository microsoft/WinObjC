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
#import <MediaPlayer/MPNowPlayingInfoCenter.h>

NSString* const MPNowPlayingInfoPropertyElapsedPlaybackTime = @"MPNowPlayingInfoPropertyElapsedPlaybackTime";
NSString* const MPNowPlayingInfoPropertyPlaybackRate = @"MPNowPlayingInfoPropertyPlaybackRate";
NSString* const MPNowPlayingInfoPropertyPlaybackQueueIndex = @"MPNowPlayingInfoPropertyPlaybackQueueIndex";
NSString* const MPNowPlayingInfoPropertyPlaybackQueueCount = @"MPNowPlayingInfoPropertyPlaybackQueueCount";
NSString* const MPNowPlayingInfoPropertyChapterNumber = @"MPNowPlayingInfoPropertyChapterNumber";
NSString* const MPNowPlayingInfoPropertyChapterCount = @"MPNowPlayingInfoPropertyChapterCount";

@implementation MPNowPlayingInfoCenter
/**
 @Status Stub
 @Notes
*/
+ (MPNowPlayingInfoCenter*)defaultCenter {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
