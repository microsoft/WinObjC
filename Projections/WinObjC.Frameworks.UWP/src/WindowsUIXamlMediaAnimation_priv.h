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

// WindowsUIXamlMediaAnimation_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlControls_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsUIComposition_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeyTimeHelperStatics> WUXMAIKeyTimeHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelperStatics> WUXMAIRepeatBehaviorHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrameStatics> WUXMAIColorKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameStatics> WUXMAIDoubleKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseStatics> WUXMAIEasingFunctionBaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrameStatics> WUXMAIObjectKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrameStatics> WUXMAIPointKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ITimelineStatics> WUXMAITimelineStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBackEaseStatics> WUXMAIBackEaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboardStatics> WUXMAIBeginStoryboardStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBounceEaseStatics> WUXMAIBounceEaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationStatics> WUXMAIColorAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFramesStatics> WUXMAIColorAnimationUsingKeyFramesStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransitionStatics> WUXMAIContentThemeTransitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationStatics> WUXMAIDoubleAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFramesStatics> WUXMAIDoubleAnimationUsingKeyFramesStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimationStatics> WUXMAIDragItemThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimationStatics> WUXMAIDragOverThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimationStatics> WUXMAIDrillInThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimationStatics> WUXMAIDrillOutThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimationStatics> WUXMAIDropTargetItemThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrameStatics> WUXMAIEasingColorKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrameStatics> WUXMAIEasingDoubleKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrameStatics> WUXMAIEasingPointKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransitionStatics> WUXMAIEdgeUIThemeTransitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IElasticEaseStatics> WUXMAIElasticEaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransitionStatics> WUXMAIEntranceThemeTransitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEaseStatics> WUXMAIExponentialEaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimationStatics> WUXMAIFadeInThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimationStatics> WUXMAIFadeOutThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFramesStatics> WUXMAIObjectAnimationUsingKeyFramesStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransitionStatics> WUXMAIPaneThemeTransitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationStatics> WUXMAIPointAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFramesStatics> WUXMAIPointAnimationUsingKeyFramesStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimationStatics> WUXMAIPointerDownThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimationStatics> WUXMAIPointerUpThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimationStatics> WUXMAIPopInThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimationStatics> WUXMAIPopOutThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransitionStatics> WUXMAIPopupThemeTransitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPowerEaseStatics> WUXMAIPowerEaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimationStatics> WUXMAIRepositionThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransitionStatics2> WUXMAIRepositionThemeTransitionStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrameStatics> WUXMAISplineColorKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrameStatics> WUXMAISplineDoubleKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrameStatics> WUXMAISplinePointKeyFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimationStatics> WUXMAISplitCloseThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimationStatics> WUXMAISplitOpenThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboardStatics> WUXMAIStoryboardStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimationStatics> WUXMAISwipeBackThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimationStatics> WUXMAISwipeHintThemeAnimationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationServiceStatics> WUXMAIConnectedAnimationServiceStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfoStatics> WUXMAICommonNavigationTransitionInfoStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfoStatics>
WUXMAIContinuumNavigationTransitionInfoStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfoStatics>
WUXMAIEntranceNavigationTransitionInfoStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransitionStatics> WUXMAINavigationThemeTransitionStatics_inst();
@interface WUXMAKeyTime (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Animation::KeyTime)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Media::Animation::KeyTime*)internalStruct;
@end
inline WUXMAKeyTime* WUXMAKeyTime_create(ABI::Windows::UI::Xaml::Media::Animation::KeyTime val) {
    return [WUXMAKeyTime createWith:val];
}
@interface WUXMARepeatBehavior (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior*)internalStruct;
@end
inline WUXMARepeatBehavior* WUXMARepeatBehavior_create(ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior val) {
    return [WUXMARepeatBehavior createWith:val];
}

@class Nullable_Double, Nullable_WFPoint, Nullable_WFTimeSpan, Nullable_WUColor;

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

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Media::Animation::ConnectedAnimation*, IInspectable*>> {
    void (^_delegate)(WUXMAConnectedAnimation*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object(void (^del)(WUXMAConnectedAnimation*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXMAConnectedAnimation>(arg0), _createBareRTObj(arg1));
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

class WUXMAINavigationTransitionInfoOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides, ComposableBase<>> {
    InspectableClass(L"WUXMAINavigationTransitionInfoOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXMAINavigationTransitionInfoOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE GetNavigationStateCore(HSTRING* ret) override {
        auto unmarshaledRet = [_inner getNavigationStateCore];
        *ret = nsStrToHstr(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE SetNavigationStateCore(HSTRING navigationState_in) override {
        [_inner setNavigationStateCore:hstrToNSStr(navigationState_in)];
        return 0;
    }
};
