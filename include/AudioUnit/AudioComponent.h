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

#import <AudioUnit/AudioUnitExport.h>
#import <CoreFoundation/CFString.h>

typedef struct OpaqueAudioComponent* AudioComponent;
typedef struct OpaqueAudioComponentInstance* AudioComponentInstance;

typedef struct AudioComponentDescription {
    OSType componentType;
    OSType componentSubType;
    OSType componentManufacturer;
    UInt32 componentFlags;
    UInt32 componentFlagsMask;
} AudioComponentDescription;

AUDIOUNIT_EXPORT OSStatus AudioComponentCopyName(AudioComponent inComponent, CFStringRef _Nullable* outName) STUB_METHOD;
AUDIOUNIT_EXPORT UInt32 AudioComponentCount(const AudioComponentDescription* inDesc) STUB_METHOD;
AUDIOUNIT_EXPORT AudioComponent AudioComponentFindNext(AudioComponent inComponent, const AudioComponentDescription* inDesc) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioComponentGetDescription(AudioComponent inComponent, AudioComponentDescription* outDesc) STUB_METHOD;
AUDIOUNIT_EXPORT Boolean AudioComponentInstanceCanDo(AudioComponentInstance inInstance, SInt16 inSelectorID) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioComponentGetVersion(AudioComponent inComponent, UInt32* outVersion) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioComponentInstanceDispose(AudioComponentInstance inInstance) STUB_METHOD;
AUDIOUNIT_EXPORT AudioComponent AudioComponentInstanceGetComponent(AudioComponentInstance inInstance) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioComponentInstanceNew(AudioComponent inComponent, AudioComponentInstance _Nullable* outInstance) STUB_METHOD;
