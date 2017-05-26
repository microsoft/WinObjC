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

// WindowsDevicesPrintersExtensions.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Printers.Extensions.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPrintersExtensions.h"
#include "WindowsDevicesPrintersExtensions_priv.h"

@implementation WDPEPrintTaskConfigurationSaveRequestedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WDPEPrintTaskConfigurationSaveRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)save:(RTObject*)printerExtensionContext {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>(self);
    THROW_NS_IF_FAILED(_comInst->Save([printerExtensionContext comObj].Get()));
}

- (WDPEPrintTaskConfigurationSaveRequestedDeferral*)getDeferral {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPEPrintTaskConfigurationSaveRequestedDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WDPEPrintTaskConfigurationSaveRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPEPrintTaskConfigurationSaveRequest*)request {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPEPrintTaskConfigurationSaveRequest>(unmarshalledReturn.Get());
}

@end

@implementation WDPEPrintTaskConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)printerExtensionContext {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrinterExtensionContext(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addSaveRequestedEvent:(void (^)(WDPEPrintTaskConfiguration*,
                                                          WDPEPrintTaskConfigurationSaveRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->add_SaveRequested(
        Make<
            ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSaveRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SaveRequested(eventCookie));
}

@end

@implementation WDPEPrintNotificationEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)printerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrinterName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)eventData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEventData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_EventData(nsStrToHstr(value).Get()));
}

@end

@implementation WDPEPrintExtensionContext

ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> WDPEIPrintExtensionContextStatic_inst() {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Printers.Extensions.PrintExtensionContext").Get(), &inst));
    return inst;
}

+ (RTObject*)fromDeviceId:(NSString*)deviceId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WDPEIPrintExtensionContextStatic_inst();
    THROW_NS_IF_FAILED(_comInst->FromDeviceId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WDPEPrint3DWorkflowPrintRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPEPrint3DWorkflowStatus)status {
    ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDPEPrint3DWorkflowStatus)unmarshalledReturn;
}

- (void)setExtendedStatus:(WDPEPrint3DWorkflowDetail)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetExtendedStatus((ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowDetail)value));
}

- (void)setSource:(RTObject*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetSource([source comObj].Get()));
}

- (void)setSourceChanged:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetSourceChanged((boolean)value));
}

@end

@implementation WDPEPrint3DWorkflowPrinterChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)newDeviceId __attribute__((ns_returns_not_retained)) {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPEPrint3DWorkflow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceID {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceID(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject*)getPrintModelPackage {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->GetPrintModelPackage(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)isPrintReady {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrintReady(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPrintReady:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPrintReady((boolean)value));
}

- (EventRegistrationToken)addPrintRequestedEvent:(void (^)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrintRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->add_PrintRequested(
        Make<
            ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePrintRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PrintRequested(eventCookie));
}

- (EventRegistrationToken)addPrinterChangedEvent:(void (^)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrinterChangedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>(self);
    THROW_NS_IF_FAILED(_comInst->add_PrinterChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePrinterChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PrinterChanged(eventCookie));
}

@end
