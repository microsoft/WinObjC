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

// WindowsGraphicsPrinting3D_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsUI_priv.h"
ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DManagerStatics> WGPIPrint3DManagerStatics_inst();
static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> WGPIPrinting3DBaseMaterialGroupFactory_inst();
ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> WGPIPrinting3DBaseMaterialStatics_inst();
static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> WGPIPrinting3DColorMaterialGroupFactory_inst();
static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory>
WGPIPrinting3DTexture2CoordMaterialGroupFactory_inst();
static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory>
WGPIPrinting3DCompositeMaterialGroupFactory_inst();
static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory>
WGPIPrinting3DMultiplePropertyMaterialGroupFactory_inst();
ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackageStatics> WGPIPrinting3D3MFPackageStatics_inst();
@interface WGPPrinting3DBufferDescription (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription*)internalStruct;
@end
inline WGPPrinting3DBufferDescription* WGPPrinting3DBufferDescription_create(
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription val) {
    return [WGPPrinting3DBufferDescription createWith:val];
}

id RTProxiedNSArray_UInt32_create(IInspectable* val);
id RTProxiedNSMutableArray_Double_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_UInt32_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DBaseMaterial_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DBaseMaterialGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DColorMaterial_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DColorMaterialGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DComponent_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DComponentWithMatrix_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterial_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterialGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DMesh_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DModelTexture_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterial_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterialGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterial_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterialGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WGPPrinting3DTextureResource_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedNSArray_UInt32, RTProxiedNSMutableArray_Double, RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_UInt32,
    RTProxiedNSMutableArray_WGPPrinting3DBaseMaterial;
@class RTProxiedNSMutableArray_WGPPrinting3DBaseMaterialGroup, RTProxiedNSMutableArray_WGPPrinting3DColorMaterial,
    RTProxiedNSMutableArray_WGPPrinting3DColorMaterialGroup;
@class RTProxiedNSMutableArray_WGPPrinting3DComponent, RTProxiedNSMutableArray_WGPPrinting3DComponentWithMatrix,
    RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterial;
@class RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterialGroup, RTProxiedNSMutableArray_WGPPrinting3DMesh,
    RTProxiedNSMutableArray_WGPPrinting3DModelTexture;
@class RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterial, RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterialGroup;
@class RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterial, RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterialGroup;
@class RTProxiedNSMutableArray_WGPPrinting3DTextureResource, RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing3D::Print3DManager*,
                                                       ABI::Windows::Graphics::Printing3D::Print3DTaskRequestedEventArgs*>> {
    void (^_delegate)(WGPPrint3DManager*, WGPPrint3DTaskRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs(
        void (^del)(WGPPrint3DManager*, WGPPrint3DTaskRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing3D::IPrint3DManager* arg0,
                                             ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrint3DManager>(arg0), _createRtProxy<WGPPrint3DTaskRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing3D::Print3DTask*, IInspectable*>> {
    void (^_delegate)(WGPPrint3DTask*, RTObject*);

public:
    ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object(void (^del)(WGPPrint3DTask*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing3D::IPrint3DTask* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrint3DTask>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing3D::Print3DTask*,
                                                       ABI::Windows::Graphics::Printing3D::Print3DTaskCompletedEventArgs*>> {
    void (^_delegate)(WGPPrint3DTask*, WGPPrint3DTaskCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs(
        void (^del)(WGPPrint3DTask*, WGPPrint3DTaskCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing3D::IPrint3DTask* arg0,
                                             ABI::Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrint3DTask>(arg0), _createRtProxy<WGPPrint3DTaskCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing3D::Print3DTask*,
                                                       ABI::Windows::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs*>> {
    void (^_delegate)(WGPPrint3DTask*, WGPPrint3DTaskSourceChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs(
        void (^del)(WGPPrint3DTask*, WGPPrint3DTaskSourceChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing3D::IPrint3DTask* arg0,
                                             ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrint3DTask>(arg0), _createRtProxy<WGPPrint3DTaskSourceChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WGPPrint3DTaskSourceRequestedHandler_shim__DEFINED
#define __WGPPrint3DTaskSourceRequestedHandler_shim__DEFINED
class WGPPrint3DTaskSourceRequestedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedHandler> {
    void (^_delegate)(WGPPrint3DTaskSourceRequestedArgs*);

public:
    WGPPrint3DTaskSourceRequestedHandler_shim(void (^del)(WGPPrint3DTaskSourceRequestedArgs*)) : _delegate([del copy]) {
    }
    ~WGPPrint3DTaskSourceRequestedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrint3DTaskSourceRequestedArgs>(arg0));
            return 0;
        };
    }
};
#endif
