//******************************************************************************
//
// Copyright (c) 2017 Intel Corporation. All rights reserved.
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.
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

// This is needed for getting mfapi.h to build in unit tests. 
#ifndef OUT
#define OUT
#endif

#include <COMIncludes.h>
#import <wrl\client.h>
#import <wrl\wrappers\corewrappers.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mferror.h>
#include <wmcodecdsp.h>
#include <COMIncludes_End.h>

#import <Foundation/NSObject.h>
#import <CoreAudio/CoreAudioTypes.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

#define RETURN_AUDIOERR_IF_FAILED_WITH_MSG(hr, msg)           \
    if (FAILED(hr)) {                                         \
        NSTraceInfo(TAG, @"%@: %lx", msg, (unsigned long)hr); \
        return kAudioConverterErr_UnspecifiedError;           \
    }

#define RETURN_NIL_IF_FAILED(hr)       \
    if (FAILED(hr)) {                  \
        self = nil;                    \
        return nil;                    \
    }


@interface AudioConverter : NSObject
@property (atomic) ComPtr<IMFTransform> transform;
@property (atomic) float sizeChangeMultiplier;
- (instancetype)initWithSourceFormat:(const AudioStreamBasicDescription*)srcFormat
                   destinationFormat:(const AudioStreamBasicDescription*)destFormat;
- (ComPtr<IMFTransform>)getTransform;
- (float)getSizeChangeMultiplier;
@end

OSStatus _setMFProperties(const AudioStreamBasicDescription* format, IMFMediaType** mediaType);