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

// WindowsUIXamlAutomation_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXaml_priv.h"
#include "WindowsUIXamlAutomationPeers_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiersStatics> WUXAIAnnotationPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics4> WUXAIAutomationElementIdentifiersStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics> WUXAIAutomationElementIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics3> WUXAIAutomationElementIdentifiersStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics5> WUXAIAutomationElementIdentifiersStatics5_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics2> WUXAIAutomationElementIdentifiersStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics2> WUXAIAutomationPropertiesStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics4> WUXAIAutomationPropertiesStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics> WUXAIAutomationPropertiesStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics5> WUXAIAutomationPropertiesStatics5_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics3> WUXAIAutomationPropertiesStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiersStatics> WUXAIDockPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiersStatics> WUXAIDragPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiersStatics> WUXAIDropTargetPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiersStatics> WUXAIExpandCollapsePatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiersStatics> WUXAIGridItemPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiersStatics> WUXAIGridPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiersStatics> WUXAIMultipleViewPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiersStatics> WUXAIRangeValuePatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiersStatics> WUXAIScrollPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiersStatics> WUXAISelectionItemPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiersStatics> WUXAISelectionPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiersStatics> WUXAISpreadsheetItemPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiersStatics> WUXAIStylesPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiersStatics> WUXAITableItemPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiersStatics> WUXAITablePatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiersStatics> WUXAITogglePatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPattern2IdentifiersStatics> WUXAITransformPattern2IdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiersStatics> WUXAITransformPatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiersStatics> WUXAIValuePatternIdentifiersStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiersStatics> WUXAIWindowPatternIdentifiersStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationFactory> WUXAIAutomationAnnotationFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationStatics> WUXAIAutomationAnnotationStatics_inst();

id RTProxiedNSMutableArray_WUXAAutomationAnnotation_create(IInspectable* val);
id RTProxiedNSMutableArray_WXDependencyObject_create(IInspectable* val);
id RTProxiedNSMutableArray_WXUIElement_create(IInspectable* val);

@class RTProxiedNSMutableArray_WUXAAutomationAnnotation, RTProxiedNSMutableArray_WXDependencyObject, RTProxiedNSMutableArray_WXUIElement;

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
