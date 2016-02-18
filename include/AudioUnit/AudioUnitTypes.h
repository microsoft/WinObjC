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

#import <AudioUnit/AudioComponent.h>
#import <CoreFoundation/CFBase.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioUnit/AudioUnitExport.h>

typedef uint32_t AUAudioChannelCount;
typedef uint64_t AUParameterAddress;
typedef float AUValue;
typedef int64_t AUEventSampleTime;
typedef uint32_t AUAudioFrameCount;
typedef void* AUParameterObserverToken;
typedef int32_t AUAudioUnitStatus;
typedef uint32_t AudioComponentInstantiationOptions;
typedef uint32_t AudioUnitParameterOptions;

typedef CF_ENUM(uint8_t, AURenderEventType) {
    AURenderEventParameter = 1,
    AURenderEventParameterRamp = 2,
    AURenderEventMIDI = 8,
    AURenderEventMIDISysEx = 9
};

typedef struct AURecordedParameterEvent {
    uint64_t hostTime;
    AUParameterAddress address;
    AUValue value;
} AURecordedParameterEvent;

typedef struct AURenderEventHeader {
    union AURenderEvent* next;
    AUEventSampleTime eventSampleTime;
    AURenderEventType eventType;
    uint8_t reserved;
} AURenderEventHeader;

typedef struct AUParameterEvent {
    union AURenderEvent* next;
    AUEventSampleTime eventSampleTime;
    AURenderEventType eventType;
    uint8_t reserved[3];
    AUAudioFrameCount rampDurationSampleFrames;
    AUParameterAddress parameterAddress;
    AUValue value;
} AUParameterEvent;

typedef struct AUMIDIEvent {
    union AURenderEvent* next;
    AUEventSampleTime eventSampleTime;
    AURenderEventType eventType;
    uint8_t reserved;
    uint16_t length;
    uint8_t cable;
    uint8_t data[3];
} AUMIDIEvent;

typedef union AURenderEvent {
    AURenderEventHeader head;
    AUParameterEvent parameter;
    AUMIDIEvent MIDI;
} AURenderEvent;
