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

// WindowsUIXamlMedia_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsUIXamlMediaMedia3D_priv.h"
#include "WindowsMediaPlayback_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics2> WUXMIVisualTreeHelperStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics> WUXMIVisualTreeHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixHelperStatics> WUXMIMatrixHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics> WUXMICompositionTargetStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyStatics2> WUXMIFontFamilyStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IBrushStatics> WUXMIBrushStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryStatics> WUXMIGeometryStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarkerStatics> WUXMITimelineMarkerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IMatrix3DProjectionStatics> WUXMIMatrix3DProjectionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPlaneProjectionStatics> WUXMIPlaneProjectionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IRectangleGeometryStatics> WUXMIRectangleGeometryStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushFactory> WUXMISolidColorBrushFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushStatics> WUXMISolidColorBrushStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ICompositeTransformStatics> WUXMICompositeTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixTransformStatics> WUXMIMatrixTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IRotateTransformStatics> WUXMIRotateTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IScaleTransformStatics> WUXMIScaleTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ISkewTransformStatics> WUXMISkewTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ITransformGroupStatics> WUXMITransformGroupStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ITranslateTransformStatics> WUXMITranslateTransformStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IGradientStopStatics> WUXMIGradientStopStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPathFigureStatics> WUXMIPathFigureStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IArcSegmentStatics> WUXMIArcSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IBezierSegmentStatics> WUXMIBezierSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IEllipseGeometryStatics> WUXMIEllipseGeometryStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryGroupStatics> WUXMIGeometryGroupStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IGradientBrushStatics> WUXMIGradientBrushStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ILineGeometryStatics> WUXMILineGeometryStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ILineSegmentStatics> WUXMILineSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPathGeometryStatics> WUXMIPathGeometryStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPolyBezierSegmentStatics> WUXMIPolyBezierSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPolyLineSegmentStatics> WUXMIPolyLineSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics> WUXMIPolyQuadraticBezierSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics> WUXMIQuadraticBezierSegmentStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ITileBrushStatics> WUXMITileBrushStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::IImageBrushStatics> WUXMIImageBrushStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushFactory> WUXMILinearGradientBrushFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushStatics> WUXMILinearGradientBrushStatics_inst();
@interface WUXMMatrix (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Matrix)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Media::Matrix*)internalStruct;
@end
inline WUXMMatrix* WUXMMatrix_create(ABI::Windows::UI::Xaml::Media::Matrix val) {
    return [WUXMMatrix createWith:val];
}

id RTProxiedIterableNSArray_WXUIElement_create(IInspectable* val);
id RTProxiedNSArray_WUXCPPopup_create(IInspectable* val);

@class RTProxiedIterableNSArray_WXUIElement, RTProxiedNSArray_WUXCPPopup;

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

#ifndef __WXExceptionRoutedEventHandler_shim__DEFINED
#define __WXExceptionRoutedEventHandler_shim__DEFINED
class WXExceptionRoutedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IExceptionRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXExceptionRoutedEventArgs*);

public:
    WXExceptionRoutedEventHandler_shim(void (^del)(RTObject*, WXExceptionRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXExceptionRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXExceptionRoutedEventArgs>(arg1));
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

class WUXMIGeneralTransformOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides, ComposableBase<>> {
    InspectableClass(L"WUXMIGeneralTransformOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXMIGeneralTransformOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE get_InverseCore(ABI::Windows::UI::Xaml::Media::IGeneralTransform** ret) override {
        auto unmarshaledRet = [_inner inverseCore];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransform>(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE TryTransformCore(ABI::Windows::Foundation::Point inPoint_in,
                                               ABI::Windows::Foundation::Point* outPoint_in,
                                               boolean* ret) override {
        WFPoint* outPoint_outparm;
        auto unmarshaledRet = [_inner tryTransformCore:WFPoint_create(inPoint_in) outPoint:&outPoint_outparm];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE TransformBoundsCore(ABI::Windows::Foundation::Rect rect_in, ABI::Windows::Foundation::Rect* ret) override {
        auto unmarshaledRet = [_inner transformBoundsCore:WFRect_create(rect_in)];
        *ret = *[unmarshaledRet internalStruct];
        return 0;
    }
};
