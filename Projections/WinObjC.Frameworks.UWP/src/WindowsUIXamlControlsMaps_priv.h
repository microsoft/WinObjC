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

// WindowsUIXamlControlsMaps_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUICore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXamlMediaMedia3D_priv.h"
#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsServicesMapsLocalSearch_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsUIXamlData_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsServicesMaps_priv.h"
#include "WindowsUIXamlMediaAnimation_priv.h"
#include "WindowsUIXamlControls_priv.h"
#include "WindowsApplicationModelDataTransfer_priv.h"
#include "WindowsUIXamlMedia_priv.h"
#include "WindowsUIText_priv.h"
#include "WindowsUIXamlInput_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsUIXamlAutomationPeers_priv.h"
static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCameraFactory> WUXCMIMapCameraFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics2> WUXCMIMapElementStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics> WUXCMIMapElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics> WUXCMIMapItemsControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapSceneStatics> WUXCMIMapSceneStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics> WUXCMIMapTileSourceStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics> WUXCMIStreetsidePanoramaStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics2> WUXCMIMapIconStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics> WUXCMIMapIconStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics> WUXCMIMapPolygonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics> WUXCMIMapPolylineStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory> WUXCMIStreetsideExperienceFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics4> WUXCMIMapControlStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics2> WUXCMIMapControlStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics> WUXCMIMapControlStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory> WUXCMIMapControlDataHelperFactory_inst();
@interface WUXCMMapZoomLevelRange (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange*)internalStruct;
@end
inline WUXCMMapZoomLevelRange* WUXCMMapZoomLevelRange_create(ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange val) {
    return [WUXCMMapZoomLevelRange createWith:val];
}

id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WDGGeopoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedNSArray_WSMLLocalLocation_create(IInspectable* val);
id RTProxiedNSArray_WUXCMMapElement_create(IInspectable* val);
id RTProxiedNSArray_WUXIPointer_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_WDGGeopath_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXCMMapElement_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXCMMapRouteView_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXCMMapTileSource_create(IInspectable* val);
id RTProxiedNSMutableArray_WXDependencyObject_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class Nullable_Double, Nullable_WXThickness, RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint,
    RTProxiedIterableNSArray_WDGGeopoint;
@class RTProxiedIterableNSArray_WFPoint, RTProxiedNSArray_WSMLLocalLocation, RTProxiedNSArray_WUXCMMapElement, RTProxiedNSArray_WUXIPointer;
@class RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSMutableArray_WDGGeopath, RTProxiedNSMutableArray_WUXCMMapElement,
    RTProxiedNSMutableArray_WUXCMMapRouteView;
@class RTProxiedNSMutableArray_WUXCMMapTileSource, RTProxiedNSMutableArray_WXDependencyObject,
    RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Control*,
                                                                       ABI::Windows::UI::Xaml::Controls::FocusDisengagedEventArgs*>> {
    void (^_delegate)(WXCControl*, WXCFocusDisengagedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs(
        void (^del)(WXCControl*, WXCFocusDisengagedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCControl>(arg0), _createRtProxy<WXCFocusDisengagedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Control*,
                                                                       ABI::Windows::UI::Xaml::Controls::FocusEngagedEventArgs*>> {
    void (^_delegate)(WXCControl*, WXCFocusEngagedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs(
        void (^del)(WXCControl*, WXCFocusEngagedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IFocusEngagedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCControl>(arg0), _createRtProxy<WXCFocusEngagedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs*>> {
    void (^_delegate)(WUXCMCustomMapTileDataSource*, WUXCMMapTileBitmapRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs(
        void (^del)(WUXCMCustomMapTileDataSource*, WUXCMMapTileBitmapRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMCustomMapTileDataSource>(arg0), _createRtProxy<WUXCMMapTileBitmapRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs*>> {
    void (^_delegate)(WUXCMHttpMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs(
        void (^del)(WUXCMHttpMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMHttpMapTileDataSource>(arg0), _createRtProxy<WUXCMMapTileUriRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs*>> {
    void (^_delegate)(WUXCMLocalMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs(
        void (^del)(WUXCMLocalMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMLocalMapTileDataSource>(arg0), _createRtProxy<WUXCMMapTileUriRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*, IInspectable*>> {
    void (^_delegate)(WUXCMMapControl*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object(void (^del)(WUXCMMapControl*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapActualCameraChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapActualCameraChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapActualCameraChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapActualCameraChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapActualCameraChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapActualCameraChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkClickEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkClickEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlBusinessLandmarkClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerExitedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerExitedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlBusinessLandmarkPointerExitedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkRightTappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkRightTappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlBusinessLandmarkRightTappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlTransitFeatureClickEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlTransitFeatureClickEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlTransitFeatureClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerEnteredEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerEnteredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlTransitFeaturePointerEnteredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerExitedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerExitedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlTransitFeaturePointerExitedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                              ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapControlTransitFeatureRightTappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapControlTransitFeatureRightTappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
           ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapControlTransitFeatureRightTappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapCustomExperienceChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapCustomExperienceChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapCustomExperienceChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapElementClickEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapElementClickEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapElementClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapElementPointerEnteredEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapElementPointerEnteredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapElementPointerEnteredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapElementPointerExitedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapElementPointerExitedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapElementPointerExitedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapInputEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapInputEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapInputEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapInputEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapRightTappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapRightTappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapRightTappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapControl*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs*>> {
    void (^_delegate)(WUXCMMapControl*, WUXCMMapTargetCameraChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs(
        void (^del)(WUXCMMapControl*, WUXCMMapTargetCameraChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapControl>(arg0), _createRtProxy<WUXCMMapTargetCameraChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Maps::MapScene*,
                                                       ABI::Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs*>> {
    void (^_delegate)(WUXCMMapScene*, WUXCMMapTargetCameraChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs(
        void (^del)(WUXCMMapScene*, WUXCMMapTargetCameraChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Maps::IMapScene* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCMMapScene>(arg0), _createRtProxy<WUXCMMapTargetCameraChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*, IInspectable*>> {
    void (^_delegate)(WXFrameworkElement*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object(void (^del)(WXFrameworkElement*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*,
                                                                       ABI::Windows::UI::Xaml::DataContextChangedEventArgs*>> {
    void (^_delegate)(WXFrameworkElement*, WXDataContextChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs(
        void (^del)(WXFrameworkElement*, WXDataContextChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0,
                                             ABI::Windows::UI::Xaml::IDataContextChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createRtProxy<WXDataContextChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DragStartingEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDragStartingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs(void (^del)(WXUIElement*, WXDragStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDragStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDragStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DropCompletedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDropCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs(void (^del)(WXUIElement*,
                                                                                                    WXDropCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDropCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDropCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayDismissedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyInvokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::ContextRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIContextRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIContextRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIContextRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*, ABI::Windows::UI::Xaml::RoutedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXRoutedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs(void (^del)(WXUIElement*, WXRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIDoubleTappedEventHandler_shim__DEFINED
#define __WUXIDoubleTappedEventHandler_shim__DEFINED
class WUXIDoubleTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IDoubleTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIDoubleTappedRoutedEventArgs*);

public:
    WUXIDoubleTappedEventHandler_shim(void (^del)(RTObject*, WUXIDoubleTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIDoubleTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIDoubleTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIHoldingEventHandler_shim__DEFINED
#define __WUXIHoldingEventHandler_shim__DEFINED
class WUXIHoldingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IHoldingEventHandler> {
    void (^_delegate)(RTObject*, WUXIHoldingRoutedEventArgs*);

public:
    WUXIHoldingEventHandler_shim(void (^del)(RTObject*, WUXIHoldingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIHoldingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIHoldingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIKeyEventHandler_shim__DEFINED
#define __WUXIKeyEventHandler_shim__DEFINED
class WUXIKeyEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IKeyEventHandler> {
    void (^_delegate)(RTObject*, WUXIKeyRoutedEventArgs*);

public:
    WUXIKeyEventHandler_shim(void (^del)(RTObject*, WUXIKeyRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIKeyEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIKeyRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationCompletedEventHandler_shim__DEFINED
#define __WUXIManipulationCompletedEventHandler_shim__DEFINED
class WUXIManipulationCompletedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationCompletedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*);

public:
    WUXIManipulationCompletedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationCompletedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationCompletedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationDeltaEventHandler_shim__DEFINED
#define __WUXIManipulationDeltaEventHandler_shim__DEFINED
class WUXIManipulationDeltaEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationDeltaEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*);

public:
    WUXIManipulationDeltaEventHandler_shim(void (^del)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationDeltaEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationDeltaRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
class WUXIManipulationInertiaStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*);

public:
    WUXIManipulationInertiaStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~WUXIManipulationInertiaStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationInertiaStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartedEventHandler_shim__DEFINED
#define __WUXIManipulationStartedEventHandler_shim__DEFINED
class WUXIManipulationStartedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartedRoutedEventArgs*);

public:
    WUXIManipulationStartedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartingEventHandler_shim__DEFINED
#define __WUXIManipulationStartingEventHandler_shim__DEFINED
class WUXIManipulationStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartingRoutedEventArgs*);

public:
    WUXIManipulationStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIPointerEventHandler_shim__DEFINED
#define __WUXIPointerEventHandler_shim__DEFINED
class WUXIPointerEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IPointerEventHandler> {
    void (^_delegate)(RTObject*, WUXIPointerRoutedEventArgs*);

public:
    WUXIPointerEventHandler_shim(void (^del)(RTObject*, WUXIPointerRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIPointerEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIPointerRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIRightTappedEventHandler_shim__DEFINED
#define __WUXIRightTappedEventHandler_shim__DEFINED
class WUXIRightTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IRightTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIRightTappedRoutedEventArgs*);

public:
    WUXIRightTappedEventHandler_shim(void (^del)(RTObject*, WUXIRightTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIRightTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIRightTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXITappedEventHandler_shim__DEFINED
#define __WUXITappedEventHandler_shim__DEFINED
class WUXITappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::ITappedEventHandler> {
    void (^_delegate)(RTObject*, WUXITappedRoutedEventArgs*);

public:
    WUXITappedEventHandler_shim(void (^del)(RTObject*, WUXITappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXITappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXITappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedCallback_shim__DEFINED
#define __WXDependencyPropertyChangedCallback_shim__DEFINED
class WXDependencyPropertyChangedCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedCallback> {
    void (^_delegate)(WXDependencyObject*, WXDependencyProperty*);

public:
    WXDependencyPropertyChangedCallback_shim(void (^del)(WXDependencyObject*, WXDependencyProperty*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IDependencyObject* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyProperty* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXDependencyObject>(arg0), _createRtProxy<WXDependencyProperty>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedEventHandler_shim__DEFINED
#define __WXDependencyPropertyChangedEventHandler_shim__DEFINED
class WXDependencyPropertyChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventHandler> {
    void (^_delegate)(RTObject*, WXDependencyPropertyChangedEventArgs*);

public:
    WXDependencyPropertyChangedEventHandler_shim(void (^del)(RTObject*, WXDependencyPropertyChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXDependencyPropertyChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDragEventHandler_shim__DEFINED
#define __WXDragEventHandler_shim__DEFINED
class WXDragEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDragEventHandler> {
    void (^_delegate)(RTObject*, WXDragEventArgs*);

public:
    WXDragEventHandler_shim(void (^del)(RTObject*, WXDragEventArgs*)) : _delegate([del copy]) {
    }
    ~WXDragEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IDragEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXDragEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXRoutedEventHandler_shim__DEFINED
#define __WXRoutedEventHandler_shim__DEFINED
class WXRoutedEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXRoutedEventArgs*);

public:
    WXRoutedEventHandler_shim(void (^del)(RTObject*, WXRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXSizeChangedEventHandler_shim__DEFINED
#define __WXSizeChangedEventHandler_shim__DEFINED
class WXSizeChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ISizeChangedEventHandler> {
    void (^_delegate)(RTObject*, WXSizeChangedEventArgs*);

public:
    WXSizeChangedEventHandler_shim(void (^del)(RTObject*, WXSizeChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXSizeChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::ISizeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXSizeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
