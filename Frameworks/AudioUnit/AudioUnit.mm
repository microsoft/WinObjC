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
#import <AudioUnit/AudioUnit.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitInitialize(AudioUnit inUnit) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitUninitialize(AudioUnit inUnit) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitAddRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* inProcUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitRemoveRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* inProcUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitRender(AudioUnit inUnit,
                         AudioUnitRenderActionFlags* ioActionFlags,
                         const AudioTimeStamp* inTimeStamp,
                         UInt32 inOutputBusNumber,
                         UInt32 inNumberFrames,
                         AudioBufferList* ioData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitReset(AudioUnit inUnit, AudioUnitScope inScope, AudioUnitElement inElement) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitAddPropertyListener(AudioUnit inUnit,
                                      AudioUnitPropertyID inID,
                                      AudioUnitPropertyListenerProc inProc,
                                      void* inProcUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitRemovePropertyListenerWithUserData(AudioUnit inUnit,
                                                     AudioUnitPropertyID inID,
                                                     AudioUnitPropertyListenerProc inProc,
                                                     void* inProcUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitGetProperty(
    AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, void* outData, UInt32* ioDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitGetPropertyInfo(AudioUnit inUnit,
                                  AudioUnitPropertyID inID,
                                  AudioUnitScope inScope,
                                  AudioUnitElement inElement,
                                  UInt32* outDataSize,
                                  Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitSetProperty(
    AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, const void* inData, UInt32 inDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitGetParameter(
    AudioUnit inUnit, AudioUnitParameterID inID, AudioUnitScope inScope, AudioUnitElement inElement, AudioUnitParameterValue* outValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitSetParameter(AudioUnit inUnit,
                               AudioUnitParameterID inID,
                               AudioUnitScope inScope,
                               AudioUnitElement inElement,
                               AudioUnitParameterValue inValue,
                               UInt32 inBufferOffsetInFrames) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioUnitScheduleParameters(AudioUnit inUnit, const AudioUnitParameterEvent* inParameterEvent, UInt32 inNumParamEvents) {
    UNIMPLEMENTED();
    return StubReturn();
}
