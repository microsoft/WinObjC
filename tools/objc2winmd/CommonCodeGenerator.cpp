//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#include <sstream>
#include "CommonCodeGenerator.h"
#include "ClangHelpers.h"
#include "ClangObjectModel.h"
#include "Helpers.h"

extern "C" const std::string g_commonConvertors;
extern "C" const std::string g_notificationCenter;
extern "C" const std::string g_copyrightNotice;
extern ClangObjectModel::GlobalData g_globalData;
extern ClangHelpers::SDKParameters g_sdkParameters;
extern "C" const std::string g_winrtClassPrefix;
extern std::string generateABIBoundaryStart();
extern std::string generateABIBoundaryEnd();

using namespace std;

namespace CommonCodeGenerator {
string generateNSNotificationCenterIDL() {
    stringstream ss, ssEvents;
    string rtStaticClassName = "I" + g_notificationCenter + "Statics";
    ss << "import \"inspectable.idl\";" << endl;
    ss << "import \"windows.foundation.idl\";" << endl;
    ss << endl;
    ss << "namespace " << ClangHelpers::generateNamespaceString("", "") << " {" << endl;
    for (auto handler : g_globalData.notifications) {
        ss << Helpers::annotate("uuid", Helpers::newUuid());
        ss << Helpers::annotate("version", "1.0");
        string delegateName = g_notificationCenter + "_" + handler;
        ss << "delegate HRESULT " << delegateName << "();" << endl;

        ssEvents << "    [eventadd] HRESULT " << handler << "([in] " << delegateName
                 << "* handler, [out] [retval] EventRegistrationToken* token);" << endl;
        ssEvents << "    [eventremove] HRESULT " << handler << "([in] EventRegistrationToken token);" << endl;
    }
    ss << endl;
    ss << Helpers::annotate("uuid", Helpers::newUuid());
    ss << Helpers::annotate("version", "1.0");
    ss << "interface " << rtStaticClassName << " : IInspectable {" << endl;
    ss << ssEvents.str();
    ss << "}" << endl;
    ss << endl;
    ss << Helpers::annotate("marshaling_behavior", "agile");
    ss << Helpers::annotate("static", rtStaticClassName + ", 1.0");
    ss << Helpers::annotate("version", "1.0");
    ss << "runtimeclass " << g_notificationCenter << " {" << endl;
    ss << "}" << endl;
    ss << endl;
    ss << "}" << endl;
    return ss.str();
}

string generateNSNotificationCenterDeclarations() {
    stringstream ss;
    string rootNamespace = ClangHelpers::generateNamespaceString("", "");
    string rtClassName = g_winrtClassPrefix + g_notificationCenter;
    ss << "class " << rtClassName << " : public RuntimeClass<IInspectable> {" << endl;
    ss << "    InspectableClass(RuntimeClass_" << rootNamespace << "_" << g_notificationCenter << ", BaseTrust)" << endl;
    ss << "public:" << endl;
    ss << "};" << endl;
    ss << endl;

    for (auto notification : g_globalData.notifications) {
        ss << "MIDL_INTERFACE(\"" << Helpers::newUuid() << "\")" << endl;
        ss << "I" << notification << " : public IInspectable {" << endl;
        ss << "public:" << endl;
        ss << "    virtual HRESULT STDMETHODCALLTYPE AddEvent(" << endl;
        string delegateName = g_notificationCenter + "_" + notification;
        string resolvedDelegateName = "ABI::" + rootNamespace + "::I" + delegateName;
        ss << "        " << resolvedDelegateName << "* handler," << endl;
        ss << "        EventRegistrationToken* token) = 0;" << endl;
        ss << "    virtual HRESULT STDMETHODCALLTYPE RemoveEvent(" << endl;
        ss << "        EventRegistrationToken token) = 0;" << endl;
        ss << "    virtual HRESULT STDMETHODCALLTYPE Invoke(void) = 0;" << endl;
        ss << "};" << endl;
        ss << endl;
        ss << "extern const __declspec(selectany) IID & IID_I" << notification << " = __uuidof(I" << notification << ");" << endl;
        ss << endl;
        ss << "class " << g_winrtClassPrefix << notification << " : public RuntimeClass<" << rootNamespace << "::I" << notification
           << ">, public GetInnerObject {" << endl;
        ss << "    Microsoft::WRL::EventSource<" << resolvedDelegateName << "> _eventSource;" << endl;
        ss << "    StrongId<id> _obj;" << endl;
        ss << "    CriticalSection _lock;" << endl;
        ss << "    InspectableClass(L\"RuntimeClass_" << rootNamespace << "_" << notification << "\", BaseTrust)" << endl;
        ss << "public:" << endl;
        ss << "    " << g_winrtClassPrefix << notification << "();" << endl;
        ss << "    ~" << g_winrtClassPrefix << notification << "();" << endl;
        ss << "    STDMETHODIMP AddEvent(" << resolvedDelegateName << "* handler, EventRegistrationToken* token) override;" << endl;
        ss << "    STDMETHODIMP RemoveEvent(EventRegistrationToken token) override;" << endl;
        ss << "    STDMETHODIMP Invoke() override;" << endl;
        ss << "    id getInnerObject() override;" << endl;
        ss << "};" << endl;
        ss << endl;
    }
    return ss.str();
}

string generateNSNotificationCenterDefinitions() {
    stringstream ss, ssPrefix;
    string rootNamespace = ClangHelpers::generateNamespaceString("", "");
    ssPrefix << g_copyrightNotice;
    ssPrefix << endl;
    ssPrefix << "#include <ComIncludes.h>" << endl;
    ssPrefix << "#include <windows.foundation.h>" << endl;
    ssPrefix << "#include <wrl.h>" << endl;
    ssPrefix << "#include <wrl/implements.h>" << endl;
    ssPrefix << "#include <wrl/async.h>" << endl;
    ssPrefix << "#include <wrl/module.h>" << endl;
    ssPrefix << "#include <ComIncludes_End.h>" << endl;
    ssPrefix << "#import <UWP/ObjCHelpers.h>" << endl;
    ssPrefix << "#import \"" << rootNamespace << ".h\"" << endl;
    ssPrefix << endl;
    string rtStaticClassName = g_winrtClassPrefix + g_notificationCenter + "Statics";
    string staticInterfaceName = "I" + g_notificationCenter + "Statics";
    for (auto notification : g_globalData.notifications) {
        ssPrefix << "extern \"C\" __attribute__((visibility(\"default\"))) NSString *const " << notification << ";" << endl;
        string rtClassName = g_winrtClassPrefix + notification;
        string delegateName = g_notificationCenter + "_" + notification;
        string resolvedDelegateName = "ABI::" + rootNamespace + "::I" + delegateName;
        string resolvedInternalInterface = rootNamespace + "::I" + notification;
        string resolvedInternalRTClass = rootNamespace + "::" + g_winrtClassPrefix + notification;
        ss << rtClassName << "::" << rtClassName << "() {" << endl;
        ss << "    _obj = nil;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << rtClassName << "::~" << rtClassName << "() {" << endl;
        ss << "    if (nil != _obj) {" << endl;
        ss << "        StrongId<NSAutoreleasePool> p;" << endl;
        ss << "        p.attach([NSAutoreleasePool new]);" << endl;
        ss << "        [[NSNotificationCenter defaultCenter] removeObserver:_obj];" << endl;
        ss << "        _obj = nil;" << endl;
        ss << "    }" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "id " << rtClassName << "::getInnerObject() {" << endl;
        ss << "    return _obj.get();" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "STDMETHODIMP " << rtClassName << "::AddEvent(" << endl;
        ss << "    " << resolvedDelegateName << "* handler," << endl;
        ss << "    "
           << "EventRegistrationToken* token) {" << endl;
        ss << generateABIBoundaryStart();
        ss << "    auto lock = _lock.Lock();" << endl;
        ss << "    _eventSource.Add(handler, token);" << endl;
        ss << "    if (nil == _obj) {" << endl;
        ss << "        StrongId<NSAutoreleasePool> p;" << endl;
        ss << "        p.attach([NSAutoreleasePool new]);" << endl;
        ss << "        _obj = [[NSNotificationCenter defaultCenter] addObserverForName:" << notification << endl;
        ss << "                                                     object:nil" << endl;
        ss << "                                                     queue:nil" << endl;
        ss << "                                                     usingBlock:^(NSNotification* notification) {" << endl;
        ss << "                                                         Invoke();" << endl;
        ss << "                                                     }];" << endl;
        ss << "    }" << endl;
        ss << "    return S_OK;" << endl;
        ss << generateABIBoundaryEnd();
        ss << "}" << endl;
        ss << endl;
        ss << "STDMETHODIMP " << rtClassName << "::RemoveEvent(EventRegistrationToken token) {" << endl;
        ss << generateABIBoundaryStart();
        ss << "    auto lock = _lock.Lock();" << endl;
        ss << "    _eventSource.Remove(token);" << endl;
        ss << "    size_t count = _eventSource.GetSize();" << endl;
        ss << "    if (0 == count) {" << endl;
        ss << "        StrongId<NSAutoreleasePool> p;" << endl;
        ss << "        p.attach([NSAutoreleasePool new]);" << endl;
        ss << "        [[NSNotificationCenter defaultCenter] removeObserver:_obj];" << endl;
        ss << "        _obj = nil;" << endl;
        ss << "    }" << endl;
        ss << "    return S_OK;" << endl;
        ss << generateABIBoundaryEnd();
        ss << "}" << endl;
        ss << endl;
        ss << "STDMETHODIMP " << rtClassName << "::Invoke() {" << endl;
        ss << generateABIBoundaryStart();
        ss << "    _eventSource.InvokeAll();" << endl;
        ss << "    return S_OK;" << endl;
        ss << generateABIBoundaryEnd();
        ss << "}" << endl;
        ss << endl;
        ss << "class " << rtStaticClassName << " : public ActivationFactory<ABI::" << rootNamespace << "::" << staticInterfaceName << "> {"
           << endl;
        ss << "        static CriticalSection s_accessPropertiesOnCoreApplication;" << endl;
        ss << "        // Runtime.h defines Nil as ((Class)_OBJC_NULL_PTR), which results in an error for InspectableClassStatic" << endl;
        ss << "        // which expects Nil as a CPP class. If Nil is undefined, the push and pop below are NOP." << endl;
        ss << "#pragma push_macro(\"Nil\")" << endl;
        ss << "#undef Nil" << endl;
        ss << "        InspectableClassStatic(RuntimeClass_" << rootNamespace << "_" << g_notificationCenter << ", BaseTrust)" << endl;
        ss << "#pragma pop_macro(\"Nil\")" << endl;
        ss << "private:" << endl;
        ss << "    ComPtr<IMap<HSTRING, IInspectable*>> _getPropertySetAsMap() {" << endl;
        ss << "        ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication> coreApp;" << endl;
        ss << "        THROW_IF_FAILED(GetActivationFactory(" << endl;
        ss << "            HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(), &coreApp));" << endl;
        ss << "        ComPtr<IPropertySet> properties;" << endl;
        ss << "        THROW_IF_FAILED(coreApp->get_Properties(&properties));" << endl;
        ss << "        ComPtr<IMap<HSTRING, IInspectable*>> map;" << endl;
        ss << "        THROW_IF_FAILED(properties.As(&map));" << endl;
        ss << "        return map;" << endl;
        ss << "    }" << endl;
        ss << "public:" << endl;
        ss << "    " << rtStaticClassName << "() {" << endl;
        ss << "    }" << endl;
        ss << "    STDMETHODIMP add_" << notification << "(" << resolvedDelegateName << "* handler, " << endl;
        ss << "         EventRegistrationToken* token) override {" << endl;
        ss << generateABIBoundaryStart();
        ss << ClangHelpers::generateCallToIslandWoodInit();
        ss << "        ComPtr<IMap<HSTRING, IInspectable*>> propertySetMap = _getPropertySetAsMap();" << endl;
        ss << "        auto lock = s_accessPropertiesOnCoreApplication.Lock();" << endl;
        ss << "        ComPtr<IInspectable> inspectablePropertyValue;" << endl;
        ss << "        ComPtr<" << resolvedInternalInterface << "> valObj;" << endl;
        ss << "        if (SUCCEEDED(propertySetMap->Lookup(nsStrToHstr(" << notification << ").Get(), &inspectablePropertyValue))) {"
           << endl;
        ss << "            RETURN_IF_FAILED(inspectablePropertyValue.As(&valObj));" << endl;
        ss << "            RETURN_IF_FAILED(valObj->AddEvent(handler, token));" << endl;
        ss << "        } else {" << endl;
        ss << "            // First event registration" << endl;
        ss << "            valObj = Make<" << resolvedInternalRTClass << ">();" << endl;
        ss << "            RETURN_IF_FAILED(valObj->AddEvent(handler, token));" << endl;
        ss << "            RETURN_IF_FAILED(valObj.As(&inspectablePropertyValue));" << endl;
        ss << "            boolean replaced;" << endl;
        ss << "            RETURN_IF_FAILED(propertySetMap->Insert(nsStrToHstr(" << notification
           << ").Get(), inspectablePropertyValue.Get(), &replaced));" << endl;
        ss << "        }" << endl;
        ss << "        return S_OK;" << endl;
        ss << generateABIBoundaryEnd();
        ss << "    }" << endl;
        ss << endl;
        ss << "    STDMETHODIMP remove_" << notification << "(EventRegistrationToken token) override {" << endl;
        ss << generateABIBoundaryStart();
        ss << ClangHelpers::generateCallToIslandWoodInit();
        ss << "        ComPtr<IMap<HSTRING, IInspectable*>> propertySetMap = _getPropertySetAsMap();" << endl;
        ss << "        auto lock = s_accessPropertiesOnCoreApplication.Lock();" << endl;
        ss << "        ComPtr<IInspectable> inspectablePropertyValue;" << endl;
        ss << "        ComPtr<" << resolvedInternalInterface << "> valObj;" << endl;
        ss << "        if (SUCCEEDED(propertySetMap->Lookup(nsStrToHstr(" << notification << ").Get(), &inspectablePropertyValue))) {"
           << endl;
        ss << "            RETURN_IF_FAILED(inspectablePropertyValue.As(&valObj));" << endl;
        ss << "            RETURN_IF_FAILED(valObj->RemoveEvent(token));" << endl;
        ss << "        }" << endl;
        ss << "        return S_OK;" << endl;
        ss << generateABIBoundaryEnd();
        ss << "    }" << endl;
        ss << endl;
    }

    ss << "};" << endl;
    ss << "CriticalSection " << rtStaticClassName << "::s_accessPropertiesOnCoreApplication;" << endl;
    ss << "ActivatableStaticOnlyFactory(" << rtStaticClassName << ");" << endl;

    ssPrefix << endl;
    ssPrefix << "namespace " << rootNamespace << " {" << endl;
    return ssPrefix.str() + ss.str() + "\n}\n";
}

string generateIslandWoodInitImport() {
    std::stringstream ss;
    ss << "__declspec(selectany) extern \"C\" std::once_flag g_IslandwoodIsInitialized;" << std::endl;
    return ss.str();
}

// Generate a common header file to house things used by all clases.
string generateCommonHeader() {
    stringstream ss;
    ss << g_copyrightNotice;
    ss << "#pragma once" << std::endl << std::endl;
    ss << "#include <ComIncludes.h>" << endl;
    ss << "#ifdef __OBJC__" << endl;
    ss << "#pragma push_macro(\"Nil\")" << endl;
    ss << "#undef Nil" << endl;
    ss << "#endif" << endl;
    if (g_globalData.requiresNSNotificationMarshalling) {
        ss << "#include \"" << ClangHelpers::generateNamespaceString("", "") << "._" << g_notificationCenter << ".h\"" << endl;
    }
    ss << "#include <windows.foundation.h>" << endl;
    ss << "#include <wrl.h>" << endl;
    ss << "#include <wrl/implements.h>" << endl;
    ss << "#include <wrl/async.h>" << endl;
    ss << "#include <wrl/module.h>" << endl;
    ss << "#ifdef __OBJC__" << endl;
    ss << "#pragma pop_macro(\"Nil\")" << endl;
    ss << "#endif" << endl;
    ss << "#include <ComIncludes_End.h>" << endl;
    ss << "#import <UWP/ObjCHelpers.h>" << endl;
    ss << "#include <mutex>" << std::endl;
    ss << "#import <Foundation/Foundation.h>" << endl;
    ss << "#import <UIKit/UIApplication.h>" << endl;
    ss << endl;

    // Generate code for an objective-c class that holds the WRL class as a WeakRef
    // This is needed because associated objects (objc_setAssociatedObject) can only be objective-c objects.
    ss << "@interface WeakRefWrapper : NSObject" << endl;
    ss << "    @property (nonatomic)WeakRef weakRefComObj;" << endl;
    ss << "@end" << endl;

    ss << "template<typename Functor>" << endl;
    ss << "HRESULT ExceptionBoundary(Functor&& functor) {" << endl;
    ss << "    StrongId<NSAutoreleasePool> p;" << endl;
    ss << "    p.attach([NSAutoreleasePool new]);" << endl;
    ss << "    ComPtr<IRestrictedErrorInfo> clearExistingErrorInfo = nullptr;" << endl;
    ss << "    GetRestrictedErrorInfo(&clearExistingErrorInfo);" << endl;
    ss << "    clearExistingErrorInfo.Reset();" << endl;
    ss << "    try {" << endl;
    ss << "        try {" << endl;
    ss << "            HRESULT hr = functor();" << endl;
    ss << "            if (hr == S_OK) {" << endl;
    ss << "                GetRestrictedErrorInfo(&clearExistingErrorInfo);" << endl;
    ss << "            }" << endl;
    ss << "            return hr;" << endl;
    ss << "        } catch(...) {" << endl;
    ss << "            wil::details::RethrowNormalizedCaughtException(__R_INFO_ONLY(nullptr));" << endl;
    ss << "        }" << endl;
    ss << "    } catch (NSException* nse) {" << endl;
    ss << "        return [nse _hresult];" << endl;
    ss << "    }" << endl;
    ss << "    return E_UNEXPECTED;" << endl;
    ss << "}" << endl;

    ss << "namespace " << g_sdkParameters.rootNameSpace << " {" << std::endl;

    ss << generateIslandWoodInitImport() << std::endl;

    ss << "class __declspec(novtable) GetInnerObject {" << std::endl;
    ss << "public:" << std::endl;
    ss << "    virtual id getInnerObject() = 0;" << std::endl;
    ss << "};" << std::endl;

    if (g_globalData.requiresNSNotificationMarshalling) {
        ss << CommonCodeGenerator::generateNSNotificationCenterDeclarations();
    }

    ss << "}" << std::endl;
    return ss.str();
}

string generateCommonImplementation() {
    stringstream ss;
    ss << g_copyrightNotice;

    ss << "#include \"" << g_sdkParameters.rootNameSpace << ".h\"" << std::endl;

    ss << "@implementation WeakRefWrapper" << endl;
    ss << "@end" << endl;

    return ss.str();
}
}