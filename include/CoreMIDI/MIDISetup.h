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
#pragma once

#import <CoreMIDI/CoreMIDIExport.h>
#import <CoreMIDI/MIDIServices.h>
#import <CoreFoundation/CFString.h>

COREMIDI_EXPORT OSStatus MIDIDeviceAddEntity(MIDIDeviceRef device,
                                             CFStringRef name,
                                             Boolean embedded,
                                             ItemCount numSourceEndpoints,
                                             ItemCount numDestinationEndpoints,
                                             MIDIEntityRef* newEntity) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIDeviceRemoveEntity(MIDIDeviceRef device, MIDIEntityRef entity) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIEntityAddOrRemoveEndpoints(MIDIEntityRef entity,
                                                        ItemCount numSourceEndpoints,
                                                        ItemCount numDestinationEndpoints) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIExternalDeviceCreate(CFStringRef name, CFStringRef manufacturer, CFStringRef model, MIDIDeviceRef* outDevice)
    STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISetupAddDevice(MIDIDeviceRef device) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISetupAddExternalDevice(MIDIDeviceRef device) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISetupRemoveDevice(MIDIDeviceRef device) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISetupRemoveExternalDevice(MIDIDeviceRef device) STUB_METHOD;

#if __LP64__
typedef MIDIObjectRef MIDISetupRef;
#else
typedef struct OpaqueMIDISetup* MIDISetupRef;
#endif;
