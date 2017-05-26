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

// WindowsUIXamlAutomationPeers.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Automation.Peers.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsUIXamlAutomationPeers_priv.h"

@implementation WUXAPAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> WUXAPIAutomationPeerStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutomationPeer").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAPRawElementProviderRuntimeId*)generateRawElementProviderRuntimeId {
    ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GenerateRawElementProviderRuntimeId(&unmarshalledReturn));
    return WUXAPRawElementProviderRuntimeId_create(unmarshalledReturn);
}

ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics> WUXAPIAutomationPeerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutomationPeer").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)listenerExists:(WUXAPAutomationEvents)eventId {
    boolean unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ListenerExists((ABI::Windows::UI::Xaml::Automation::Peers::AutomationEvents)eventId, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPAutomationPeer*)eventsSource {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventsSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (void)setEventsSource:(WUXAPAutomationPeer*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EventsSource(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(value).Get()));
}

- (RTObject*)getPattern:(WUXAPPatternInterface)patternInterface {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetPattern((ABI::Windows::UI::Xaml::Automation::Peers::PatternInterface)patternInterface,
                                            unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)raiseAutomationEvent:(WUXAPAutomationEvents)eventId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->RaiseAutomationEvent((ABI::Windows::UI::Xaml::Automation::Peers::AutomationEvents)eventId));
}

- (void)raisePropertyChangedEvent:(WUXAAutomationProperty*)automationProperty oldValue:(RTObject*)oldValue newValue:(RTObject*)newValue {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->RaisePropertyChangedEvent(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::IAutomationProperty>(automationProperty).Get(),
        [oldValue comObj].Get(),
        [newValue comObj].Get()));
}

- (NSString*)getAcceleratorKey {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetAcceleratorKey(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getAccessKey {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetAccessKey(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationControlType)getAutomationControlType {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationControlType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetAutomationControlType(&unmarshalledReturn));
    return (WUXAPAutomationControlType)unmarshalledReturn;
}

- (NSString*)getAutomationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetAutomationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFRect*)getBoundingRectangle {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoundingRectangle(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (NSMutableArray* /* WUXAPAutomationPeer* */)getChildren {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetChildren(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (NSString*)getClassName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetClassName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFPoint*)getClickablePoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetClickablePoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (NSString*)getHelpText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetHelpText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getItemStatus {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemStatus(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getItemType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationPeer*)getLabeledBy {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetLabeledBy(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (NSString*)getLocalizedControlType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalizedControlType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationOrientation)getOrientation {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetOrientation(&unmarshalledReturn));
    return (WUXAPAutomationOrientation)unmarshalledReturn;
}

- (BOOL)hasKeyboardFocus {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->HasKeyboardFocus(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isContentElement {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsContentElement(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isControlElement {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsControlElement(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isKeyboardFocusable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsKeyboardFocusable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isOffscreen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsOffscreen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPassword {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsPassword(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRequiredForForm {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->IsRequiredForForm(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setFocus {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->SetFocus());
}

- (WUXAPAutomationPeer*)getParent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetParent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (void)invalidatePeer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->InvalidatePeer());
}

- (WUXAPAutomationPeer*)getPeerFromPoint:(WFPoint*)point {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetPeerFromPoint(*[point internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (WUXAPAutomationLiveSetting)getLiveSetting {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->GetLiveSetting(&unmarshalledReturn));
    return (WUXAPAutomationLiveSetting)unmarshalledReturn;
}

- (RTObject*)getPatternCore:(WUXAPPatternInterface)patternInterface {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetPatternCore((ABI::Windows::UI::Xaml::Automation::Peers::PatternInterface)patternInterface,
                                                unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (NSString*)getAcceleratorKeyCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetAcceleratorKeyCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getAccessKeyCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetAccessKeyCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationControlType)getAutomationControlTypeCore {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationControlType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetAutomationControlTypeCore(&unmarshalledReturn));
    return (WUXAPAutomationControlType)unmarshalledReturn;
}

- (NSString*)getAutomationIdCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetAutomationIdCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFRect*)getBoundingRectangleCore {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoundingRectangleCore(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (NSMutableArray* /* WUXAPAutomationPeer* */)getChildrenCore {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetChildrenCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (NSString*)getClassNameCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetClassNameCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFPoint*)getClickablePointCore {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetClickablePointCore(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (NSString*)getHelpTextCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetHelpTextCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getItemStatusCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemStatusCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getItemTypeCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemTypeCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationPeer*)getLabeledByCore {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetLabeledByCore(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (NSString*)getLocalizedControlTypeCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalizedControlTypeCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getNameCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetNameCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationOrientation)getOrientationCore {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetOrientationCore(&unmarshalledReturn));
    return (WUXAPAutomationOrientation)unmarshalledReturn;
}

- (BOOL)hasKeyboardFocusCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->HasKeyboardFocusCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isContentElementCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsContentElementCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isControlElementCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsControlElementCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabledCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isKeyboardFocusableCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsKeyboardFocusableCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isOffscreenCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsOffscreenCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPasswordCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsPasswordCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRequiredForFormCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->IsRequiredForFormCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setFocusCore {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->SetFocusCore());
}

- (WUXAPAutomationPeer*)getPeerFromPointCore:(WFPoint*)point {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetPeerFromPointCore(*[point internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (WUXAPAutomationLiveSetting)getLiveSettingCore {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetLiveSettingCore(&unmarshalledReturn));
    return (WUXAPAutomationLiveSetting)unmarshalledReturn;
}

- (WUXAPAutomationPeer*)peerFromProvider:(WUXAPIRawElementProviderSimple*)provider {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected>(self);
    THROW_NS_IF_FAILED(_comInst->PeerFromProvider(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(provider).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (WUXAPIRawElementProviderSimple*)providerFromPeer:(WUXAPAutomationPeer*)peer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected>(self);
    THROW_NS_IF_FAILED(_comInst->ProviderFromPeer(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(peer).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)showContextMenuCore {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>(self);
    THROW_NS_IF_FAILED(_comInst->ShowContextMenuCore());
}

- (NSArray* /* WUXAPAutomationPeer* */)getControlledPeersCore {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>(self);
    THROW_NS_IF_FAILED(_comInst->GetControlledPeersCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (RTObject*)navigate:(WUXAPAutomationNavigationDirection)direction {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->Navigate((ABI::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection)direction,
                                          unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getElementFromPoint:(WFPoint*)pointInWindowCoordinates {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetElementFromPoint(*[pointInWindowCoordinates internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getFocusedElement {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetFocusedElement(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)showContextMenu {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->ShowContextMenu());
}

- (NSArray* /* WUXAPAutomationPeer* */)getControlledPeers {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetControlledPeers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUXAPAutomationPeerAnnotation* */)getAnnotations {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXAPAutomationPeerAnnotation_create(unmarshalledReturn.Get());
}

- (void)setParent:(WUXAPAutomationPeer*)peer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->SetParent(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(peer).Get()));
}

- (void)raiseTextEditTextChangedEvent:(WUXAAutomationTextEditChangeType)automationTextEditChangeType
                          changedData:(NSArray* /* NSString * */)changedData {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->RaiseTextEditTextChangedEvent(
        (ABI::Windows::UI::Xaml::Automation::AutomationTextEditChangeType)automationTextEditChangeType,
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(changedData).Get())));
}

- (int)getPositionInSet {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetPositionInSet(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)getSizeOfSet {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetSizeOfSet(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)getLevel {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)raiseStructureChangedEvent:(WUXAPAutomationStructureChangeType)structureChangeType child:(WUXAPAutomationPeer*)child {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>(self);
    THROW_NS_IF_FAILED(
        _comInst->RaiseStructureChangedEvent((ABI::Windows::UI::Xaml::Automation::Peers::AutomationStructureChangeType)structureChangeType,
                                             _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(child).Get()));
}

- (RTObject*)navigateCore:(WUXAPAutomationNavigationDirection)direction {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->NavigateCore((ABI::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection)direction,
                                              unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getElementFromPointCore:(WFPoint*)pointInWindowCoordinates {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetElementFromPointCore(*[pointInWindowCoordinates internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getFocusedElementCore {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetFocusedElementCore(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUXAPAutomationPeerAnnotation* */)getAnnotationsCore {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotationsCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXAPAutomationPeerAnnotation_create(unmarshalledReturn.Get());
}

- (int)getPositionInSetCore {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetPositionInSetCore(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)getSizeOfSetCore {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetSizeOfSetCore(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)getLevelCore {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>(self);
    THROW_NS_IF_FAILED(_comInst->GetLevelCore(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXAPAutomationLandmarkType)getLandmarkType {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer4>(self);
    THROW_NS_IF_FAILED(_comInst->GetLandmarkType(&unmarshalledReturn));
    return (WUXAPAutomationLandmarkType)unmarshalledReturn;
}

- (NSString*)getLocalizedLandmarkType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer4>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalizedLandmarkType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPAutomationLandmarkType)getLandmarkTypeCore {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>(self);
    THROW_NS_IF_FAILED(_comInst->GetLandmarkTypeCore(&unmarshalledReturn));
    return (WUXAPAutomationLandmarkType)unmarshalledReturn;
}

- (NSString*)getLocalizedLandmarkTypeCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocalizedLandmarkTypeCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPeripheral {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>(self);
    THROW_NS_IF_FAILED(_comInst->IsPeripheral(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDataValidForForm {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>(self);
    THROW_NS_IF_FAILED(_comInst->IsDataValidForForm(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)getFullDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>(self);
    THROW_NS_IF_FAILED(_comInst->GetFullDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPeripheralCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->IsPeripheralCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDataValidForFormCore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->IsDataValidForFormCore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)getFullDescriptionCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->GetFullDescriptionCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id<NSFastEnumeration> /* WUXAPAutomationPeer* */)getDescribedByCore {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->GetDescribedByCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WUXAPAutomationPeer* */)getFlowsToCore {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->GetFlowsToCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WUXAPAutomationPeer* */)getFlowsFromCore {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>(self);
    THROW_NS_IF_FAILED(_comInst->GetFlowsFromCore(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WUXAPAutomationPeer_create(unmarshalledReturn.Get());
}

@end

@implementation WUXAPAutomationPeerAnnotation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutomationPeerAnnotation").Get(),
                                              &out));
    return [_createRtProxy<WUXAPAutomationPeerAnnotation>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> WUXAPIAutomationPeerAnnotationFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutomationPeerAnnotation").Get(), &inst));
    return inst;
}

+ (WUXAPAutomationPeerAnnotation*)makeInstance:(WUXAAnnotationType)type {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerAnnotationFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance((ABI::Windows::UI::Xaml::Automation::AnnotationType)type, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPAutomationPeerAnnotation>(unmarshalledReturn.Get()) retain];
}

+ (WUXAPAutomationPeerAnnotation*)makeWithPeerParameter:(WUXAAnnotationType)type peer:(WUXAPAutomationPeer*)peer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerAnnotationFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithPeerParameter((ABI::Windows::UI::Xaml::Automation::AnnotationType)type,
                                          _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(peer).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPAutomationPeerAnnotation>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> WUXAPIAutomationPeerAnnotationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutomationPeerAnnotation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)typeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerAnnotationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)peerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAPIAutomationPeerAnnotationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PeerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXAAnnotationType)type {
    ABI::Windows::UI::Xaml::Automation::AnnotationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUXAAnnotationType)unmarshalledReturn;
}

- (void)setType:(WUXAAnnotationType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::UI::Xaml::Automation::AnnotationType)value));
}

- (WUXAPAutomationPeer*)peer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Peer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (void)setPeer:(WUXAPAutomationPeer*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Peer(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(value).Get()));
}

@end

@implementation WUXAPFrameworkElementAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPFrameworkElementAutomationPeer*)makeInstanceWithOwner:(WXFrameworkElement*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FrameworkElementAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPFrameworkElementAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics>
WUXAPIFrameworkElementAutomationPeerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FrameworkElementAutomationPeer").Get(), &inst));
    return inst;
}

+ (WUXAPAutomationPeer*)fromElement:(WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIFrameworkElementAutomationPeerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

+ (WUXAPAutomationPeer*)createPeerForElement:(WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIFrameworkElementAutomationPeerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePeerForElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (WXUIElement*)owner {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Owner(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPButtonBaseAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPCaptureElementAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPCaptureElementAutomationPeer*)makeInstanceWithOwner:(WXCCaptureElement*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.CaptureElementAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ICaptureElement>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPCaptureElementAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPComboBoxItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPComboBoxItemAutomationPeer*)makeInstanceWithOwner:(WXCComboBoxItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ComboBoxItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IComboBoxItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPComboBoxItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPFlipViewItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPFlipViewItemAutomationPeer*)makeInstanceWithOwner:(WXCFlipViewItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FlipViewItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IFlipViewItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPFlipViewItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPGroupItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPGroupItemAutomationPeer*)makeInstanceWithOwner:(WXCGroupItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.GroupItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IGroupItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPGroupItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPImageAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPImageAutomationPeer*)makeInstanceWithOwner:(WXCImage*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ImageAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IImage>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPImageAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListBoxItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListBoxItemAutomationPeer*)makeInstanceWithOwner:(WXCListBoxItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListBoxItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListBoxItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListBoxItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPMediaTransportControlsAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPMediaTransportControlsAutomationPeer*)makeInstanceWithOwner:(WXCMediaTransportControls*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.MediaTransportControlsAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IMediaTransportControls>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPMediaTransportControlsAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPPasswordBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPPasswordBoxAutomationPeer*)makeInstanceWithOwner:(WXCPasswordBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.PasswordBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IPasswordBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPPasswordBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPProgressRingAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPProgressRingAutomationPeer*)makeInstanceWithOwner:(WXCProgressRing*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ProgressRingAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IProgressRing>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPProgressRingAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPRichEditBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRichEditBoxAutomationPeer*)makeInstanceWithOwner:(WXCRichEditBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RichEditBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IRichEditBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPRichEditBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPRichTextBlockAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRichTextBlockAutomationPeer*)makeInstanceWithOwner:(WXCRichTextBlock*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RichTextBlockAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IRichTextBlock>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPRichTextBlockAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPRichTextBlockOverflowAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRichTextBlockOverflowAutomationPeer*)makeInstanceWithOwner:(WXCRichTextBlockOverflow*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RichTextBlockOverflowAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflow>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPRichTextBlockOverflowAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPSettingsFlyoutAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSettingsFlyoutAutomationPeer*)makeInstanceWithOwner:(WXCSettingsFlyout*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SettingsFlyoutAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ISettingsFlyout>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPSettingsFlyoutAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPTextBlockAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPTextBlockAutomationPeer*)makeInstanceWithOwner:(WXCTextBlock*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.TextBlockAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ITextBlock>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPTextBlockAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPTextBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPTextBoxAutomationPeer*)makeInstanceWithOwner:(WXCTextBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.TextBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ITextBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPTextBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPThumbAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPThumbAutomationPeer*)makeInstanceWithOwner:(WUXCPThumb*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ThumbAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPThumbAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPAutoSuggestBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory>
WUXAPIAutoSuggestBoxAutomationPeerFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AutoSuggestBoxAutomationPeer").Get(), &inst));
    return inst;
}

+ (WUXAPAutoSuggestBoxAutomationPeer*)makeInstanceWithOwner:(WXCAutoSuggestBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIAutoSuggestBoxAutomationPeerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox>(owner).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPAutoSuggestBoxAutomationPeer>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WUXAPDatePickerAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPDatePickerAutomationPeer*)makeInstanceWithOwner:(WXCDatePicker*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.DatePickerAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IDatePicker>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPDatePickerAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPFlyoutPresenterAutomationPeer*)makeInstanceWithOwner:(WXCFlyoutPresenter*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FlyoutPresenterAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IFlyoutPresenter>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPFlyoutPresenterAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPGridViewItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPGridViewItemAutomationPeer*)makeInstanceWithOwner:(WXCGridViewItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.GridViewItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IGridViewItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPGridViewItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPHubAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPHubAutomationPeer*)makeInstanceWithOwner:(WXCHub*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.HubAutomationPeer").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IHub>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPHubAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListViewBaseHeaderItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPListViewItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListViewItemAutomationPeer*)makeInstanceWithOwner:(WXCListViewItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListViewItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListViewItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListViewItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPMediaElementAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPMediaElementAutomationPeer*)makeInstanceWithOwner:(WXCMediaElement*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.MediaElementAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IMediaElement>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPMediaElementAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPMediaPlayerElementAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPMediaPlayerElementAutomationPeer*)makeInstanceWithOwner:(WXCMediaPlayerElement*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.MediaPlayerElementAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IMediaPlayerElement>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPMediaPlayerElementAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPSearchBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSearchBoxAutomationPeer*)makeInstanceWithOwner:(WXCSearchBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SearchBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ISearchBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPSearchBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPTimePickerAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPTimePickerAutomationPeer*)makeInstanceWithOwner:(WXCTimePicker*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.TimePickerAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ITimePicker>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPTimePickerAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPGridViewHeaderItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPGridViewHeaderItemAutomationPeer*)makeInstanceWithOwner:(WXCGridViewHeaderItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.GridViewHeaderItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IGridViewHeaderItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPGridViewHeaderItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListViewHeaderItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListViewHeaderItemAutomationPeer*)makeInstanceWithOwner:(WXCListViewHeaderItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListViewHeaderItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListViewHeaderItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListViewHeaderItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPButtonAutomationPeer*)makeInstanceWithOwner:(WXCButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IButton>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)invoke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Invoke());
}

@end

@implementation WUXAPHyperlinkButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPHyperlinkButtonAutomationPeer*)makeInstanceWithOwner:(WXCHyperlinkButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.HyperlinkButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IHyperlinkButton>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPHyperlinkButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)invoke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Invoke());
}

@end

@implementation WUXAPRepeatButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRepeatButtonAutomationPeer*)makeInstanceWithOwner:(WUXCPRepeatButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RepeatButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPRepeatButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)invoke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Invoke());
}

@end

@implementation WUXAPMenuFlyoutItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPMenuFlyoutItemAutomationPeer*)makeInstanceWithOwner:(WXCMenuFlyoutItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.MenuFlyoutItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItem>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPMenuFlyoutItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)invoke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Invoke());
}

@end

@implementation WUXAPAppBarButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPAppBarButtonAutomationPeer*)makeInstanceWithOwner:(WXCAppBarButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AppBarButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IAppBarButton>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPAppBarButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPItemsControlAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPItemsControlAutomationPeer*)makeInstanceWithOwner:(WXCItemsControl*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ItemsControlAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IItemsControl>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPItemsControlAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAPIRawElementProviderSimple*)findItemByProperty:(WUXAPIRawElementProviderSimple*)startAfter
                                   automationProperty:(WUXAAutomationProperty*)automationProperty
                                                value:(RTObject*)value {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->FindItemByProperty(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(startAfter).Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::IAutomationProperty>(automationProperty).Get(),
        [value comObj].Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (WUXAPItemAutomationPeer*)createItemAutomationPeer:(RTObject*)item {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateItemAutomationPeer([item comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPItemAutomationPeer>(unmarshalledReturn.Get());
}

- (WUXAPItemAutomationPeer*)onCreateItemAutomationPeer:(RTObject*)item {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>(self);
    THROW_NS_IF_FAILED(_comInst->OnCreateItemAutomationPeer([item comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPItemAutomationPeer>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPMenuFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPMenuFlyoutPresenterAutomationPeer*)makeInstanceWithOwner:(WXCMenuFlyoutPresenter*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.MenuFlyoutPresenterAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IMenuFlyoutPresenter>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPMenuFlyoutPresenterAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPRangeBaseAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRangeBaseAutomationPeer*)makeInstanceWithOwner:(WUXCPRangeBase*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RangeBaseAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPRangeBaseAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)largeChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maximum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minimum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)smallChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue(value));
}

@end

@implementation WUXAPProgressBarAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPProgressBarAutomationPeer*)makeInstanceWithOwner:(WXCProgressBar*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ProgressBarAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IProgressBar>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPProgressBarAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPScrollBarAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPScrollBarAutomationPeer*)makeInstanceWithOwner:(WUXCPScrollBar*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ScrollBarAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPScrollBarAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPSliderAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSliderAutomationPeer*)makeInstanceWithOwner:(WXCSlider*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SliderAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ISlider>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPSliderAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPHubSectionAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPHubSectionAutomationPeer*)makeInstanceWithOwner:(WXCHubSection*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.HubSectionAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IHubSection>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPHubSectionAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPScrollViewerAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPScrollViewerAutomationPeer*)makeInstanceWithOwner:(WXCScrollViewer*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ScrollViewerAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IScrollViewer>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPScrollViewerAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)horizontallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)horizontalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)verticallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)verticalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)scroll:(WUXAScrollAmount)horizontalAmount verticalAmount:(WUXAScrollAmount)verticalAmount {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Scroll((ABI::Windows::UI::Xaml::Automation::ScrollAmount)horizontalAmount,
                                        (ABI::Windows::UI::Xaml::Automation::ScrollAmount)verticalAmount));
}

- (void)setScrollPercent:(double)horizontalPercent verticalPercent:(double)verticalPercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetScrollPercent(horizontalPercent, verticalPercent));
}

@end

@implementation WUXAPSelectorAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSelectorAutomationPeer*)makeInstanceWithOwner:(WUXCPSelector*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SelectorAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPSelectorAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)canSelectMultiple {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSelectMultiple(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSelectionRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPFlipViewAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPFlipViewAutomationPeer*)makeInstanceWithOwner:(WXCFlipView*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FlipViewAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IFlipView>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPFlipViewAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListBoxAutomationPeer*)makeInstanceWithOwner:(WXCListBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListViewBaseAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListViewBaseAutomationPeer*)makeInstanceWithOwner:(WXCListViewBase*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListViewBaseAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListViewBase>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListViewBaseAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (NSString*)dropEffect {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffect(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)dropEffects {
    HSTRING* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffects(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_NSString_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPGridViewAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPGridViewAutomationPeer*)makeInstanceWithOwner:(WXCGridView*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.GridViewAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IGridView>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPGridViewAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPListViewAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListViewAutomationPeer*)makeInstanceWithOwner:(WXCListView*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListViewAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListView>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPListViewAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPSemanticZoomAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSemanticZoomAutomationPeer*)makeInstanceWithOwner:(WXCSemanticZoom*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SemanticZoomAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ISemanticZoom>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPSemanticZoomAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

@end

@implementation WUXAPToggleSwitchAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPToggleSwitchAutomationPeer*)makeInstanceWithOwner:(WXCToggleSwitch*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ToggleSwitchAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IToggleSwitch>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPToggleSwitchAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

@end

@implementation WUXAPToggleButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPToggleButtonAutomationPeer*)makeInstanceWithOwner:(WUXCPToggleButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ToggleButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPToggleButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

@end

@implementation WUXAPCheckBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPCheckBoxAutomationPeer*)makeInstanceWithOwner:(WXCCheckBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.CheckBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::ICheckBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPCheckBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPRadioButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPRadioButtonAutomationPeer*)makeInstanceWithOwner:(WXCRadioButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.RadioButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IRadioButton>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPRadioButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)selectionContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

@end

@implementation WUXAPToggleMenuFlyoutItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPToggleMenuFlyoutItemAutomationPeer*)makeInstanceWithOwner:(WXCToggleMenuFlyoutItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ToggleMenuFlyoutItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem>(owner).Get(),
                                         outer.Get(),
                                         &inner,
                                         &instance));
    WUXAPToggleMenuFlyoutItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

@end

@implementation WUXAPAppBarToggleButtonAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPAppBarToggleButtonAutomationPeer*)makeInstanceWithOwner:(WXCAppBarToggleButton*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AppBarToggleButtonAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IAppBarToggleButton>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPAppBarToggleButtonAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXAPItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPItemAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPItemsControlAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ItemAutomationPeer").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (RTObject*)item {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Item(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUXAPItemsControlAutomationPeer*)itemsControlAutomationPeer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemsControlAutomationPeer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPItemsControlAutomationPeer>(unmarshalledReturn.Get());
}

- (void)realize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Realize());
}

@end

@implementation WUXAPSelectorItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPSelectorItemAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPSelectorAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.SelectorItemAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPSelectorItemAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)selectionContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

@end

@implementation WUXAPComboBoxItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPComboBoxItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPComboBoxAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ComboBoxItemDataAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPComboBoxItemDataAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPFlipViewItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPFlipViewItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPFlipViewAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.FlipViewItemDataAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPFlipViewItemDataAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPListBoxItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListBoxItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPListBoxAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListBoxItemDataAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPListBoxItemDataAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPGridViewItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPGridViewItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPGridViewAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.GridViewItemDataAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPGridViewItemDataAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPListViewItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPListViewItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPListViewBaseAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ListViewItemDataAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer>(parent).Get(),
        outer.Get(),
        &inner,
        &instance));
    WUXAPListViewItemDataAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPComboBoxAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPComboBoxAutomationPeer*)makeInstanceWithOwner:(WXCComboBox*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.ComboBoxAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIItemsControlAutomationPeerOverrides2)]) {
        typedOuter = Make<WUXAPIItemsControlAutomationPeerOverrides2_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IComboBox>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPComboBoxAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAExpandCollapseState)expandCollapseState {
    ABI::Windows::UI::Xaml::Automation::ExpandCollapseState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpandCollapseState(&unmarshalledReturn));
    return (WUXAExpandCollapseState)unmarshalledReturn;
}

- (void)collapse {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse());
}

- (void)expand {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Expand());
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue(nsStrToHstr(value).Get()));
}

- (BOOL)isModal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsModal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTopmost {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTopmost(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)maximizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)minimizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAWindowInteractionState)interactionState {
    ABI::Windows::UI::Xaml::Automation::WindowInteractionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionState(&unmarshalledReturn));
    return (WUXAWindowInteractionState)unmarshalledReturn;
}

- (WUXAWindowVisualState)visualState {
    ABI::Windows::UI::Xaml::Automation::WindowVisualState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualState(&unmarshalledReturn));
    return (WUXAWindowVisualState)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)setVisualState:(WUXAWindowVisualState)state {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetVisualState((ABI::Windows::UI::Xaml::Automation::WindowVisualState)state));
}

- (BOOL)waitForInputIdle:(int)milliseconds {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WaitForInputIdle(milliseconds, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXAPAppBarAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXAPAppBarAutomationPeer*)makeInstanceWithOwner:(WXCAppBar*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.AppBarAutomationPeer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXAPIAutomationPeerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXAPIAutomationPeerOverrides)]) {
        typedOuter = Make<WUXAPIAutomationPeerOverrides_RtProxy>();
        outer = typedOuter;
    }
    THROW_NS_IF_FAILED(factory->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IAppBar>(owner).Get(),
                                                        outer.Get(),
                                                        &inner,
                                                        &instance));
    WUXAPAppBarAutomationPeer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

- (WUXAExpandCollapseState)expandCollapseState {
    ABI::Windows::UI::Xaml::Automation::ExpandCollapseState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpandCollapseState(&unmarshalledReturn));
    return (WUXAExpandCollapseState)unmarshalledReturn;
}

- (void)collapse {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse());
}

- (void)expand {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Expand());
}

- (BOOL)isModal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsModal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTopmost {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTopmost(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)maximizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)minimizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAWindowInteractionState)interactionState {
    ABI::Windows::UI::Xaml::Automation::WindowInteractionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionState(&unmarshalledReturn));
    return (WUXAWindowInteractionState)unmarshalledReturn;
}

- (WUXAWindowVisualState)visualState {
    ABI::Windows::UI::Xaml::Automation::WindowVisualState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualState(&unmarshalledReturn));
    return (WUXAWindowVisualState)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)setVisualState:(WUXAWindowVisualState)state {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetVisualState((ABI::Windows::UI::Xaml::Automation::WindowVisualState)state));
}

- (BOOL)waitForInputIdle:(int)milliseconds {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WaitForInputIdle(milliseconds, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXAPInkToolbarAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPMapControlAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)horizontallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)horizontalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)verticallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)verticalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)scroll:(WUXAScrollAmount)horizontalAmount verticalAmount:(WUXAScrollAmount)verticalAmount {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Scroll((ABI::Windows::UI::Xaml::Automation::ScrollAmount)horizontalAmount,
                                        (ABI::Windows::UI::Xaml::Automation::ScrollAmount)verticalAmount));
}

- (void)setScrollPercent:(double)horizontalPercent verticalPercent:(double)verticalPercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetScrollPercent(horizontalPercent, verticalPercent));
}

@end

@implementation WUXAPLoopingSelectorItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)realize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Realize());
}

@end

@implementation WUXAPDatePickerFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPListPickerFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPLoopingSelectorAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAExpandCollapseState)expandCollapseState {
    ABI::Windows::UI::Xaml::Automation::ExpandCollapseState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpandCollapseState(&unmarshalledReturn));
    return (WUXAExpandCollapseState)unmarshalledReturn;
}

- (void)collapse {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse());
}

- (void)expand {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Expand());
}

- (WUXAPIRawElementProviderSimple*)findItemByProperty:(WUXAPIRawElementProviderSimple*)startAfter
                                   automationProperty:(WUXAAutomationProperty*)automationProperty
                                                value:(RTObject*)value {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->FindItemByProperty(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(startAfter).Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::IAutomationProperty>(automationProperty).Get(),
        [value comObj].Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (BOOL)horizontallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)horizontalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)verticallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)verticalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)scroll:(WUXAScrollAmount)horizontalAmount verticalAmount:(WUXAScrollAmount)verticalAmount {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Scroll((ABI::Windows::UI::Xaml::Automation::ScrollAmount)horizontalAmount,
                                        (ABI::Windows::UI::Xaml::Automation::ScrollAmount)verticalAmount));
}

- (void)setScrollPercent:(double)horizontalPercent verticalPercent:(double)verticalPercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetScrollPercent(horizontalPercent, verticalPercent));
}

- (BOOL)canSelectMultiple {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSelectMultiple(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSelectionRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPLoopingSelectorItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)selectionContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

@end

@implementation WUXAPPickerFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPPivotItemAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> WUXAPIPivotItemAutomationPeerFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.PivotItemAutomationPeer").Get(), &inst));
    return inst;
}

+ (WUXAPPivotItemAutomationPeer*)makeInstanceWithOwner:(WXCPivotItem*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIPivotItemAutomationPeerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IPivotItem>(owner).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPPivotItemAutomationPeer>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WUXAPPivotItemDataAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory>
WUXAPIPivotItemDataAutomationPeerFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.PivotItemDataAutomationPeer").Get(), &inst));
    return inst;
}

+ (WUXAPPivotItemDataAutomationPeer*)makeInstanceWithParentAndItem:(RTObject*)item parent:(WUXAPPivotAutomationPeer*)parent {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIPivotItemDataAutomationPeerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithParentAndItem(
        [item comObj].Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer>(parent).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPPivotItemDataAutomationPeer>(unmarshalledReturn.Get()) retain];
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)selectionContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

- (void)realize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Realize());
}

@end

@implementation WUXAPTimePickerFlyoutPresenterAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAPPivotAutomationPeer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> WUXAPIPivotAutomationPeerFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.Peers.PivotAutomationPeer").Get(), &inst));
    return inst;
}

+ (WUXAPPivotAutomationPeer*)makeInstanceWithOwner:(WXCPivot*)owner {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer> unmarshalledReturn;
    auto _comInst = WUXAPIPivotAutomationPeerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithOwner(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IPivot>(owner).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAPPivotAutomationPeer>(unmarshalledReturn.Get()) retain];
}

- (BOOL)horizontallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)horizontalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)verticallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)verticalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)scroll:(WUXAScrollAmount)horizontalAmount verticalAmount:(WUXAScrollAmount)verticalAmount {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Scroll((ABI::Windows::UI::Xaml::Automation::ScrollAmount)horizontalAmount,
                                        (ABI::Windows::UI::Xaml::Automation::ScrollAmount)verticalAmount));
}

- (void)setScrollPercent:(double)horizontalPercent verticalPercent:(double)verticalPercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetScrollPercent(horizontalPercent, verticalPercent));
}

- (BOOL)canSelectMultiple {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSelectMultiple(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSelectionRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPRawElementProviderRuntimeId {
    ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId)s {
    WUXAPRawElementProviderRuntimeId* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId*)internalStruct {
    return &structVal;
}
- (unsigned int)part1 {
    return structVal.Part1;
}
- (void)setPart1:(unsigned int)val {
    structVal.Part1 = val;
}
- (unsigned int)part2 {
    return structVal.Part2;
}
- (void)setPart2:(unsigned int)val {
    structVal.Part2 = val;
}
@end
id RTProxiedIterableNSArray_WUXAPAutomationPeer_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                                 RTIterableObj<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*,
                                                               IIterable<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                                               WUXAPAutomationPeer,
                                                               ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<HSTRING, RTCArrayObj<HSTRING, NSString, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(
    UINT32 size, ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple*,
                                          RTCArrayObj<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple*,
                                                      WUXAPIRawElementProviderSimple,
                                                      dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXAPAutomationPeer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                                    WUXAPAutomationPeer,
                                                    ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUXAPAutomationPeer_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer*,
                                                                  IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*>,
                                                                  WUXAPAutomationPeer,
                                                                  ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeer*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUXAPAutomationPeerAnnotation_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*>,
                               RTMutableArrayObj<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation*,
                                                 IVector<ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*>,
                                                 WUXAPAutomationPeerAnnotation,
                                                 ABI::Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
