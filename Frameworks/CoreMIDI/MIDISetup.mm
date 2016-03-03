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
#import <CoreMIDI/MIDISetup.h>

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIDeviceAddEntity(MIDIDeviceRef device,
                             CFStringRef name,
                             Boolean embedded,
                             ItemCount numSourceEndpoints,
                             ItemCount numDestinationEndpoints,
                             MIDIEntityRef* newEntity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIDeviceRemoveEntity(MIDIDeviceRef device, MIDIEntityRef entity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIEntityAddOrRemoveEndpoints(MIDIEntityRef entity, ItemCount numSourceEndpoints, ItemCount numDestinationEndpoints) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIExternalDeviceCreate(CFStringRef name, CFStringRef manufacturer, CFStringRef model, MIDIDeviceRef* outDevice) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISetupAddDevice(MIDIDeviceRef device) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISetupAddExternalDevice(MIDIDeviceRef device) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISetupRemoveDevice(MIDIDeviceRef device) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISetupRemoveExternalDevice(MIDIDeviceRef device) {
    UNIMPLEMENTED();
    return StubReturn();
}
