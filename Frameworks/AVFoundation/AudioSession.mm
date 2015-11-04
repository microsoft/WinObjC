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
#import <AVFoundation/AVFoundation.h>

/**
 @Status Stub
*/
void AudioServicesPlaySystemSound(SystemSoundID soundID) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
OSStatus AudioSessionGetProperty(AudioSessionPropertyID id, UInt32* dataSize, void* outData) {
    UNIMPLEMENTED();
    return 100;
}

/**
 @Status Stub
*/
OSStatus AudioSessionSetActive(Boolean active) {
    UNIMPLEMENTED();
    return 100;
}

/**
 @Status Stub
*/
OSStatus AudioSessionInitialize(CFRunLoopRef inRunLoop,
                                CFStringRef inRunLoopMode,
                                AudioSessionInterruptionListener inInterruptionListener,
                                void* inClientData) {
    UNIMPLEMENTED();
    return 100;
}

/**
 @Status Stub
*/
OSStatus AudioSessionSetProperty(AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData) {
    UNIMPLEMENTED();
    return 100;
}
