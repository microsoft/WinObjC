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

// WindowsPerceptionSpatialSurfaces_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsPerceptionSpatial_priv.h"
#include "WindowsGraphicsDirectX_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> WPSSISpatialSurfaceMeshOptionsStatics_inst();
ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> WPSSISpatialSurfaceObserverStatics_inst();

id RTProxiedIterableNSArray_WPSSpatialBoundingVolume_create(IInspectable* val);
id RTProxiedNSArray_WGDDirectXPixelFormat_create(IInspectable* val);
id RTProxiedNSDictionary_WFGUID_WPSSSpatialSurfaceInfo_create(IInspectable* val);

@class Nullable_WPSSpatialBoundingOrientedBox, RTProxiedIterableNSArray_WPSSpatialBoundingVolume, RTProxiedNSArray_WGDDirectXPixelFormat;
@class RTProxiedNSDictionary_WFGUID_WPSSSpatialSurfaceInfo;

#ifndef __ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object__DEFINED
class ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver*,
                                                                       IInspectable*>> {
    void (^_delegate)(WPSSSpatialSurfaceObserver*, RTObject*);

public:
    ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object(void (^del)(WPSSSpatialSurfaceObserver*,
                                                                                                            RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WPSSSpatialSurfaceObserver>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
