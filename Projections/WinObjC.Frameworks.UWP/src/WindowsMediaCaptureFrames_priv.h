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

// WindowsMediaCaptureFrames_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMediaCapture_priv.h"
#include "WindowsMediaDevicesCore_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsMediaDevices_priv.h"
#include "WindowsPerceptionSpatial_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
#include "WindowsMedia_priv.h"
ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics> WMCFIMediaFrameSourceGroupStatics_inst();

id RTProxiedNSArray_WMCFMediaFrameFormat_create(IInspectable* val);
id RTProxiedNSArray_WMCFMediaFrameSourceGroup_create(IInspectable* val);
id RTProxiedNSArray_WMCFMediaFrameSourceInfo_create(IInspectable* val);
id RTProxiedNSDictionary_WFGUID_RTObject_create(IInspectable* val);

@class Nullable_WFTimeSpan, RTProxiedNSArray_WMCFMediaFrameFormat, RTProxiedNSArray_WMCFMediaFrameSourceGroup,
    RTProxiedNSArray_WMCFMediaFrameSourceInfo;
@class RTProxiedNSDictionary_WFGUID_RTObject;

#ifndef __ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::Frames::MediaFrameReader*,
                                                                       ABI::Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs*>> {
    void (^_delegate)(WMCFMediaFrameReader*, WMCFMediaFrameArrivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs(
        void (^del)(WMCFMediaFrameReader*, WMCFMediaFrameArrivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::Frames::IMediaFrameReader* arg0,
                                             ABI::Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCFMediaFrameReader>(arg0), _createRtProxy<WMCFMediaFrameArrivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::Frames::MediaFrameSource*, IInspectable*>> {
    void (^_delegate)(WMCFMediaFrameSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object(void (^del)(WMCFMediaFrameSource*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::Frames::IMediaFrameSource* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCFMediaFrameSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
