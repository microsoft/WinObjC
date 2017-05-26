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

// WindowsPerceptionSpatial_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsPerception_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorStatics> WPSISpatialAnchorStatics_inst();
ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorStatics> WPSISpatialLocatorStatics_inst();
ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorManagerStatics> WPSISpatialAnchorManagerStatics_inst();
ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorTransferManagerStatics> WPSISpatialAnchorTransferManagerStatics_inst();
ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolumeStatics> WPSISpatialBoundingVolumeStatics_inst();
@interface WPSSpatialBoundingFrustum (Internal)
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingFrustum)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Perception::Spatial::SpatialBoundingFrustum*)internalStruct;
@end
inline WPSSpatialBoundingFrustum* WPSSpatialBoundingFrustum_create(ABI::Windows::Perception::Spatial::SpatialBoundingFrustum val) {
    return [WPSSpatialBoundingFrustum createWith:val];
}
@interface WPSSpatialBoundingBox (Internal)
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingBox)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Perception::Spatial::SpatialBoundingBox*)internalStruct;
@end
inline WPSSpatialBoundingBox* WPSSpatialBoundingBox_create(ABI::Windows::Perception::Spatial::SpatialBoundingBox val) {
    return [WPSSpatialBoundingBox createWith:val];
}
@interface WPSSpatialBoundingOrientedBox (Internal)
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox*)internalStruct;
@end
inline WPSSpatialBoundingOrientedBox* WPSSpatialBoundingOrientedBox_create(
    ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox val) {
    return [WPSSpatialBoundingOrientedBox createWith:val];
}
@interface WPSSpatialBoundingSphere (Internal)
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingSphere)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Perception::Spatial::SpatialBoundingSphere*)internalStruct;
@end
inline WPSSpatialBoundingSphere* WPSSpatialBoundingSphere_create(ABI::Windows::Perception::Spatial::SpatialBoundingSphere val) {
    return [WPSSpatialBoundingSphere createWith:val];
}

id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WPSSpatialAnchor_create(IInspectable* val);

@class Nullable_Double, Nullable_WFNMatrix4x4, RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WPSSpatialAnchor,
    RTProxiedKeyValuePair_NSString_WPSSpatialAnchor;
@class RTProxiedNSDictionary_NSString_WPSSpatialAnchor;

#ifndef __ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Perception::Spatial::SpatialAnchor*,
                              ABI::Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs*>> {
    void (^_delegate)(WPSSpatialAnchor*, WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs*);

public:
    ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs(
        void (^del)(WPSSpatialAnchor*, WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Perception::Spatial::ISpatialAnchor* arg0,
           ABI::Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WPSSpatialAnchor>(arg0), _createRtProxy<WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object__DEFINED
class ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Perception::Spatial::SpatialLocator*, IInspectable*>> {
    void (^_delegate)(WPSSpatialLocator*, RTObject*);

public:
    ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object(void (^del)(WPSSpatialLocator*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Perception::Spatial::ISpatialLocator* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WPSSpatialLocator>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Perception::Spatial::SpatialLocator*,
                              ABI::Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs*>> {
    void (^_delegate)(WPSSpatialLocator*, WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs*);

public:
    ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs(
        void (^del)(WPSSpatialLocator*, WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Perception::Spatial::ISpatialLocator* arg0,
           ABI::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WPSSpatialLocator>(arg0),
                      _createRtProxy<WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

typedef IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*
    IKeyValuePair_HSTRING_Perception_Spatial_SpatialAnchorPtr_Ptr;
