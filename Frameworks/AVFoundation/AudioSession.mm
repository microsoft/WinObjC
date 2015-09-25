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

void AudioServicesPlaySystemSound(SystemSoundID soundID) {
}

OSStatus AudioSessionGetProperty(AudioSessionPropertyID id, UInt32* dataSize, void* outData) {
    return 100;
}

OSStatus AudioSessionSetActive(Boolean active) {
    return 100;
}

OSStatus AudioSessionInitialize(CFRunLoopRef inRunLoop,
                                CFStringRef inRunLoopMode,
                                AudioSessionInterruptionListener inInterruptionListener,
                                void* inClientData) {
    return 100;
}

OSStatus AudioSessionSetProperty(AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData) {
    return 100;
}
