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
#import <AudioUnit/AudioComponent.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioComponentCopyName(AudioComponent inComponent, CFStringRef _Nullable* outName) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
UInt32 AudioComponentCount(const AudioComponentDescription* inDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
AudioComponent AudioComponentFindNext(AudioComponent inComponent, const AudioComponentDescription* inDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioComponentGetDescription(AudioComponent inComponent, AudioComponentDescription* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean AudioComponentInstanceCanDo(AudioComponentInstance inInstance, SInt16 inSelectorID) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioComponentGetVersion(AudioComponent inComponent, UInt32* outVersion) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioComponentInstanceDispose(AudioComponentInstance inInstance) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
AudioComponent AudioComponentInstanceGetComponent(AudioComponentInstance inInstance) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioComponentInstanceNew(AudioComponent inComponent, AudioComponentInstance _Nullable* outInstance) {
    UNIMPLEMENTED();
    return StubReturn();
}
