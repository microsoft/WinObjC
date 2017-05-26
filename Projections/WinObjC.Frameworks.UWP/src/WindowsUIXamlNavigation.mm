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

// WindowsUIXamlNavigation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Navigation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlNavigation.h"
#include "WindowsUIXamlNavigation_priv.h"

@implementation WUXNNavigationEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)content {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)parameter {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameter(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUXITypeName*)sourcePageType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePageType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (WUXNNavigationMode)navigationMode {
    ABI::Windows::UI::Xaml::Navigation::NavigationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigationMode(&unmarshalledReturn));
    return (WUXNNavigationMode)unmarshalledReturn;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WUXMANavigationTransitionInfo*)navigationTransitionInfo {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigationTransitionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMANavigationTransitionInfo>(unmarshalledReturn.Get());
}

@end

@implementation WUXNNavigatingCancelEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)cancel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cancel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCancel:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Cancel((boolean)value));
}

- (WUXNNavigationMode)navigationMode {
    ABI::Windows::UI::Xaml::Navigation::NavigationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigationMode(&unmarshalledReturn));
    return (WUXNNavigationMode)unmarshalledReturn;
}

- (WUXITypeName*)sourcePageType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePageType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (RTObject*)parameter {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameter(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUXMANavigationTransitionInfo*)navigationTransitionInfo {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigationTransitionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMANavigationTransitionInfo>(unmarshalledReturn.Get());
}

@end

@implementation WUXNNavigationFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)exception {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exception(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WUXITypeName*)sourcePageType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePageType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

@end

@implementation WUXNPageStackEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntryFactory> WUXNIPageStackEntryFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntryFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Navigation.PageStackEntry").Get(), &inst));
    return inst;
}

+ (WUXNPageStackEntry*)makeInstance:(WUXITypeName*)sourcePageType
                          parameter:(RTObject*)parameter
           navigationTransitionInfo:(WUXMANavigationTransitionInfo*)navigationTransitionInfo {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntry> unmarshalledReturn;
    auto _comInst = WUXNIPageStackEntryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(
        *[sourcePageType internalStruct],
        [parameter comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>(navigationTransitionInfo).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXNPageStackEntry>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntryStatics> WUXNIPageStackEntryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Navigation::IPageStackEntryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Navigation.PageStackEntry").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)sourcePageTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXNIPageStackEntryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SourcePageTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXITypeName*)sourcePageType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::IPageStackEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePageType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (RTObject*)parameter {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::IPageStackEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameter(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUXMANavigationTransitionInfo*)navigationTransitionInfo {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Navigation::IPageStackEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigationTransitionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMANavigationTransitionInfo>(unmarshalledReturn.Get());
}

@end
