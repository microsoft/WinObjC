//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsMediaMediaProperties_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesStatics> WMMIAudioEncodingPropertiesStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingSubtypesStatics> WMMIMediaEncodingSubtypesStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IH264ProfileIdsStatics> WMMIH264ProfileIdsStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IMpeg2ProfileIdsStatics> WMMIMpeg2ProfileIdsStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingPropertiesStatics> WMMIVideoEncodingPropertiesStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics2> WMMIImageEncodingPropertiesStatics2_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics> WMMIImageEncodingPropertiesStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics> WMMIMediaEncodingProfileStatics_inst();
ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics2> WMMIMediaEncodingProfileStatics2_inst();

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);

@class RTProxiedNSArray_C_UInt8;
