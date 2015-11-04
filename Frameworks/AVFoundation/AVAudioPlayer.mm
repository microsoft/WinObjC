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

#import "Starboard.h"
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@implementation AVAudioPlayer : NSObject
@synthesize delegate;
@synthesize numberOfLoops;
@synthesize volume;

/**
 @Status Stub
*/
- (id)initWithContentsOfURL:(NSURL*)url error:(NSError**)outError {
    UNIMPLEMENTED();
    if (outError) {
        *outError = [NSError errorWithDomain:@"AVAudioPlayer" code:100 userInfo:nil];
    }
    return nil;
}

/**
 @Status Stub
*/
- (id)initWithData:(NSData*)data error:(NSError**)outError {
    UNIMPLEMENTED();
    if (outError) {
        *outError = [NSError errorWithDomain:@"AVAudioPlayer" code:100 userInfo:nil];
    }
    return nil;
}
@end

@implementation AVAudioSession

/**
 @Status Stub
*/
+ (AVAudioSession*)sharedInstance {
    UNIMPLEMENTED();
    return nil;
}
@end
