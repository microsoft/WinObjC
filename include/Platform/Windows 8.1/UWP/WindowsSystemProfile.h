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

// WindowsSystemProfile.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPHardwareToken, WSPHardwareIdentification;
@protocol WSPIHardwareToken
, WSPIHardwareIdentificationStatics;

#include "WindowsStorageStreams.h"

// Windows.System.Profile.HardwareToken
#ifndef __WSPHardwareToken_DEFINED__
#define __WSPHardwareToken_DEFINED__

WINRT_EXPORT
@interface WSPHardwareToken : RTObject
@property (readonly) RTObject<WSSIBuffer>* certificate;
@property (readonly) RTObject<WSSIBuffer>* id;
@property (readonly) RTObject<WSSIBuffer>* signature;
@end

#endif // __WSPHardwareToken_DEFINED__

// Windows.System.Profile.HardwareIdentification
#ifndef __WSPHardwareIdentification_DEFINED__
#define __WSPHardwareIdentification_DEFINED__

WINRT_EXPORT
@interface WSPHardwareIdentification : RTObject
+ (WSPHardwareToken*)getPackageSpecificToken:(RTObject<WSSIBuffer>*)nonce;
@end

#endif // __WSPHardwareIdentification_DEFINED__
