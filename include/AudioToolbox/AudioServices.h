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

#ifndef _AUDIOSERVICES_H_
#define _AUDIOSERVICES_H_

#import <AudioToolbox/AudioSession.h>
#import <StarboardExport.h>
#import <AudioToolbox/AudioToolboxExport.h>
#import <stdint.h>

#define kSystemSoundID_Vibrate 0x00000FFF

enum {
    kAudioServicesNoError = 0,
    kAudioServicesUnsupportedPropertyError = 'pty?',
    kAudioServicesBadPropertySizeError = '!siz',
    kAudioServicesBadSpecifierSizeError = '!spc',
    kAudioServicesSystemSoundUnspecifiedError = -1500,
    kAudioServicesSystemSoundClientTimedOutError = -1501
};

typedef uint32_t SystemSoundID;

AUDIOTOOLBOX_EXPORT void AudioServicesPlaySystemSound(SystemSoundID soundID);
// AUDIOTOOLBOX_EXPORT OSStatus AudioServicesCreateSystemSoundID(CFURLRef fileURL, SystemSoundID soundID);
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesDisposeSystemSoundID(SystemSoundID soundID);
AUDIOTOOLBOX_EXPORT void AudioServicesPlayAlertSound(SystemSoundID inSystemSoundID);
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesCreateSystemSoundID(CFURLRef inFileURL, SystemSoundID* outSystemSoundID);

#endif // _AUDIOSERVICES_H_
