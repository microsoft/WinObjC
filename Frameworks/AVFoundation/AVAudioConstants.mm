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

#import <AVFoundation/AVFoundation.h>

extern "C" NSString* const AVAudioSessionCategoryAmbient = @"AVAudioSessionCategoryAmbient";
extern "C" NSString* const AVAudioSessionCategoryPlayback = @"AVAudioSessionCategoryPlayback";
extern "C" NSString* const AVAudioSessionCategoryPlayAndRecord = @"AVAudioSessionCategoryPlayAndRecord";
extern "C" NSString* const AVAudioSessionCategorySoloAmbient = @"AVAudioSessionCategorySoloAmbient";

extern "C" NSString* const AVAudioSessionInterruptionTypeKey = @"AVAudioSessionInterruptionTypeKey";
extern "C" NSString* const AVAudioSessionInterruptionOptionKey = @"AVAudioSessionInterruptionOptionKey";
extern "C" NSString* const AVAudioSessionRouteChangeReasonKey = @"AVAudioSessionRouteChangeReasonKey";
extern "C" NSString* const AVAudioSessionRouteChangePreviousRouteKey = @"AVAudioSessionRouteChangePreviousRouteKey";
extern "C" NSString* const AVAudioSessionSilenceSecondaryAudioHintTypeKey = @"AVAudioSessionSilenceSecondaryAudioHintTypeKey";
