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

// WindowsUIXamlAutomationPeers_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlAutomationProvider_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsUIXamlControls_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXamlAutomation_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> WUXAPIAutomationPeerStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics> WUXAPIAutomationPeerStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> WUXAPIAutomationPeerAnnotationFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> WUXAPIAutomationPeerAnnotationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics>
WUXAPIFrameworkElementAutomationPeerStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory>
WUXAPIAutoSuggestBoxAutomationPeerFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> WUXAPIPivotItemAutomationPeerFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory>
WUXAPIPivotItemDataAutomationPeerFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> WUXAPIPivotAutomationPeerFactory_inst();
@interface WUXAPRawElementProviderRuntimeId (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId*)internalStruct;
@end
inline WUXAPRawElementProviderRuntimeId* WUXAPRawElementProviderRuntimeId_create(
    ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId val) {
    return [WUXAPRawElementProviderRuntimeId createWith:val];
}

id RTProxiedIterableNSArray_WUXAPAutomationPeer_create(IInspectable* val);
id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
id RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(UINT32 size,
                                                            ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WUXAPAutomationPeer_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXAPAutomationPeer_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXAPAutomationPeerAnnotation_create(IInspectable* val);

@class RTProxiedIterableNSArray_WUXAPAutomationPeer, RTProxiedNSArray_C_NSString, RTProxiedNSArray_C_WUXAPIRawElementProviderSimple;
@class RTProxiedNSArray_NSString, RTProxiedNSArray_WUXAPAutomationPeer, RTProxiedNSMutableArray_WUXAPAutomationPeer,
    RTProxiedNSMutableArray_WUXAPAutomationPeerAnnotation;

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

class WUXAPIItemsControlAutomationPeerOverrides2_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, ComposableBase<>> {
    InspectableClass(L"WUXAPIItemsControlAutomationPeerOverrides2_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIItemsControlAutomationPeerOverrides2>* _inner;
    HRESULT STDMETHODCALLTYPE OnCreateItemAutomationPeer(IInspectable* item_in,
                                                         ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer** ret) override {
        auto unmarshaledRet = [_inner onCreateItemAutomationPeer:_createBareRTObj(item_in)];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer>(unmarshaledRet).Detach();
        return 0;
    }
};

class WUXAPIAutomationPeerOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, ComposableBase<>> {
    InspectableClass(L"WUXAPIAutomationPeerOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIAutomationPeerOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE GetPatternCore(ABI::Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface_in,
                                             IInspectable** ret) override {
        auto unmarshaledRet = [_inner getPatternCore:(WUXAPPatternInterface)patternInterface_in];
        *ret = [unmarshaledRet comObj].Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetAcceleratorKeyCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getAcceleratorKeyCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetAccessKeyCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getAccessKeyCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetAutomationControlTypeCore(ABI::Windows::UI::Xaml::Automation::Peers::AutomationControlType* ret) override {
        auto unmarshaledRet = [_inner getAutomationControlTypeCore];
        *ret = (ABI::Windows::UI::Xaml::Automation::Peers::AutomationControlType)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetAutomationIdCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getAutomationIdCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetBoundingRectangleCore(ABI::Windows::Foundation::Rect* ret) override {
        auto unmarshaledRet = [_inner getBoundingRectangleCore];
        *ret = *[unmarshaledRet internalStruct];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetChildrenCore(IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ret) override {
        auto unmarshaledRet = [_inner getChildrenCore];
        *ret = static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>::type>*>(
            ConvertToVector<WUXAPAutomationPeer,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetClassNameCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getClassNameCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetClickablePointCore(ABI::Windows::Foundation::Point* ret) override {
        auto unmarshaledRet = [_inner getClickablePointCore];
        *ret = *[unmarshaledRet internalStruct];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetHelpTextCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getHelpTextCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetItemStatusCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getItemStatusCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetItemTypeCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getItemTypeCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetLabeledByCore(ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ret) override {
        auto unmarshaledRet = [_inner getLabeledByCore];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetLocalizedControlTypeCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getLocalizedControlTypeCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetNameCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getNameCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetOrientationCore(ABI::Windows::UI::Xaml::Automation::Peers::AutomationOrientation* ret) override {
        auto unmarshaledRet = [_inner getOrientationCore];
        *ret = (ABI::Windows::UI::Xaml::Automation::Peers::AutomationOrientation)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE HasKeyboardFocusCore(boolean* ret) override {
        auto unmarshaledRet = [_inner hasKeyboardFocusCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsContentElementCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isContentElementCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsControlElementCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isControlElementCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsEnabledCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isEnabledCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsKeyboardFocusableCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isKeyboardFocusableCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsOffscreenCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isOffscreenCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsPasswordCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isPasswordCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsRequiredForFormCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isRequiredForFormCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE SetFocusCore() override {
        [_inner setFocusCore];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetPeerFromPointCore(ABI::Windows::Foundation::Point point_in,
                                                   ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ret) override {
        auto unmarshaledRet = [_inner getPeerFromPointCore:WFPoint_create(point_in)];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetLiveSettingCore(ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting* ret) override {
        auto unmarshaledRet = [_inner getLiveSettingCore];
        *ret = (ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting)unmarshaledRet;
        return 0;
    }
};

class WUXAPIAutomationPeerOverrides2_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, ComposableBase<>> {
    InspectableClass(L"WUXAPIAutomationPeerOverrides2_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIAutomationPeerOverrides2>* _inner;
    HRESULT STDMETHODCALLTYPE ShowContextMenuCore() override {
        [_inner showContextMenuCore];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    GetControlledPeersCore(IVectorView<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ret) override {
        auto unmarshaledRet = [_inner getControlledPeersCore];
        *ret = static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>::type>*>(
            ConvertToVectorView<
                WUXAPAutomationPeer,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
};

class WUXAPIAutomationPeerOverrides3_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, ComposableBase<>> {
    InspectableClass(L"WUXAPIAutomationPeerOverrides3_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIAutomationPeerOverrides3>* _inner;
    HRESULT STDMETHODCALLTYPE NavigateCore(ABI::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction_in,
                                           IInspectable** ret) override {
        auto unmarshaledRet = [_inner navigateCore:(WUXAPAutomationNavigationDirection)direction_in];
        *ret = [unmarshaledRet comObj].Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetElementFromPointCore(ABI::Windows::Foundation::Point pointInWindowCoordinates_in,
                                                      IInspectable** ret) override {
        auto unmarshaledRet = [_inner getElementFromPointCore:WFPoint_create(pointInWindowCoordinates_in)];
        *ret = [unmarshaledRet comObj].Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetFocusedElementCore(IInspectable** ret) override {
        auto unmarshaledRet = [_inner getFocusedElementCore];
        *ret = [unmarshaledRet comObj].Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    GetAnnotationsCore(IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*>** ret) override {
        auto unmarshaledRet = [_inner getAnnotationsCore];
        *ret = static_cast<
            IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
                ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*,
                ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation*>>::type>*>(
            ConvertToVector<
                WUXAPAutomationPeerAnnotation,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetPositionInSetCore(int* ret) override {
        auto unmarshaledRet = [_inner getPositionInSetCore];
        *ret = unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetSizeOfSetCore(int* ret) override {
        auto unmarshaledRet = [_inner getSizeOfSetCore];
        *ret = unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetLevelCore(int* ret) override {
        auto unmarshaledRet = [_inner getLevelCore];
        *ret = unmarshaledRet;
        return 0;
    }
};

class WUXAPIAutomationPeerOverrides4_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, ComposableBase<>> {
    InspectableClass(L"WUXAPIAutomationPeerOverrides4_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIAutomationPeerOverrides4>* _inner;
    HRESULT STDMETHODCALLTYPE GetLandmarkTypeCore(ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType* ret) override {
        auto unmarshaledRet = [_inner getLandmarkTypeCore];
        *ret = (ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetLocalizedLandmarkTypeCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getLocalizedLandmarkTypeCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
};

class WUXAPIAutomationPeerOverrides5_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, ComposableBase<>> {
    InspectableClass(L"WUXAPIAutomationPeerOverrides5_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXAPIAutomationPeerOverrides5>* _inner;
    HRESULT STDMETHODCALLTYPE IsPeripheralCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isPeripheralCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE IsDataValidForFormCore(boolean* ret) override {
        auto unmarshaledRet = [_inner isDataValidForFormCore];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetFullDescriptionCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getFullDescriptionCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetDescribedByCore(IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ret) override {
        auto unmarshaledRet = [_inner getDescribedByCore];
        *ret = static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>::type>*>(
            ConvertToIterable<
                WUXAPAutomationPeer,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetFlowsToCore(IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ret) override {
        auto unmarshaledRet = [_inner getFlowsToCore];
        *ret = static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>::type>*>(
            ConvertToIterable<
                WUXAPAutomationPeer,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetFlowsFromCore(IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>** ret) override {
        auto unmarshaledRet = [_inner getFlowsFromCore];
        *ret = static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                              ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>::type>*>(
            ConvertToIterable<
                WUXAPAutomationPeer,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*>>(
                unmarshaledRet)
                .Detach());
        return 0;
    }
};
