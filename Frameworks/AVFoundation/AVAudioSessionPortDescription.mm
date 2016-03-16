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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const AVAudioSessionPortBluetoothHFP = @"AVAudioSessionPortBluetoothHFP";
NSString* const AVAudioSessionPortUSBAudio = @"AVAudioSessionPortUSBAudio";
NSString* const AVAudioSessionPortLineIn = @"AVAudioSessionPortLineIn";
NSString* const AVAudioSessionPortBuiltInMic = @"AVAudioSessionPortBuiltInMic";
NSString* const AVAudioSessionPortHeadsetMic = @"AVAudioSessionPortHeadsetMic";
NSString* const AVAudioSessionPortLineOut = @"AVAudioSessionPortLineOut";
NSString* const AVAudioSessionPortHeadphones = @"AVAudioSessionPortHeadphones";
NSString* const AVAudioSessionPortBluetoothA2DP = @"AVAudioSessionPortBluetoothA2DP";
NSString* const AVAudioSessionPortBuiltInReceiver = @"AVAudioSessionPortBuiltInReceiver";
NSString* const AVAudioSessionPortBuiltInSpeaker = @"AVAudioSessionPortBuiltInSpeaker";
NSString* const AVAudioSessionPortHDMI = @"AVAudioSessionPortHDMI";
NSString* const AVAudioSessionPortAirPlay = @"AVAudioSessionPortAirPlay";
NSString* const AVAudioSessionPortCarAudio = @"AVAudioSessionPortCarAudio";
NSString* const AVAudioSessionPortBluetoothLE = @"AVAudioSessionPortBluetoothLE";

@implementation AVAudioSessionPortDescription
/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
