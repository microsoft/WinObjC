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

#import <AudioToolbox/SystemSound.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesCreateSystemSoundID(CFURLRef inFileURL, SystemSoundID* outSystemSoundID) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesDisposeSystemSoundID(SystemSoundID inSystemSoundID) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void AudioServicesPlayAlertSound(SystemSoundID inSystemSoundID) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void AudioServicesPlaySystemSound(SystemSoundID inSystemSoundID) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesAddSystemSoundCompletion(SystemSoundID inSystemSoundID,
                                               CFRunLoopRef inRunLoop,
                                               CFStringRef inRunLoopMode,
                                               AudioServicesSystemSoundCompletionProc inCompletionRoutine,
                                               void* inClientData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void AudioServicesRemoveSystemSoundCompletion(SystemSoundID inSystemSoundID) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesGetPropertyInfo(AudioServicesPropertyID inPropertyID,
                                      UInt32 inSpecifierSize,
                                      const void* inSpecifier,
                                      UInt32* outPropertyDataSize,
                                      Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesGetProperty(AudioServicesPropertyID inPropertyID,
                                  UInt32 inSpecifierSize,
                                  const void* inSpecifier,
                                  UInt32* ioPropertyDataSize,
                                  void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesSetProperty(AudioServicesPropertyID inPropertyID,
                                  UInt32 inSpecifierSize,
                                  const void* inSpecifier,
                                  UInt32 inPropertyDataSize,
                                  const void* inPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}