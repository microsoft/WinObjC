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

// WindowsDevicesInput.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Input.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesInput.h"
#include "WindowsDevicesInput_priv.h"

@implementation WDIPointerDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::IPointerDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Input::IPointerDeviceStatics> WDIIPointerDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Input::IPointerDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Input.PointerDevice").Get(), &inst));
    return inst;
}

+ (WDIPointerDevice*)getPointerDevice:(unsigned int)pointerId {
    ComPtr<ABI::Windows::Devices::Input::IPointerDevice> unmarshalledReturn;
    auto _comInst = WDIIPointerDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetPointerDevice(pointerId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIPointerDevice>(unmarshalledReturn.Get());
}

+ (NSArray* /* WDIPointerDevice* */)getPointerDevices {
    ComPtr<IVectorView<ABI::Windows::Devices::Input::PointerDevice*>> unmarshalledReturn;
    auto _comInst = WDIIPointerDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetPointerDevices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDIPointerDevice_create(unmarshalledReturn.Get());
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (BOOL)isIntegrated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIntegrated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)maxContacts {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxContacts(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFRect*)physicalDeviceRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhysicalDeviceRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)screenRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScreenRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (NSArray* /* WDIPointerDeviceUsage* */)supportedUsages {
    ComPtr<IVectorView<ABI::Windows::Devices::Input::PointerDeviceUsage>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedUsages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDIPointerDeviceUsage_create(unmarshalledReturn.Get());
}

- (unsigned int)maxPointersWithZDistance {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IPointerDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPointersWithZDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDIMouseDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::IMouseDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Input::IMouseDeviceStatics> WDIIMouseDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Input::IMouseDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Input.MouseDevice").Get(), &inst));
    return inst;
}

+ (WDIMouseDevice*)getForCurrentView {
    ComPtr<ABI::Windows::Devices::Input::IMouseDevice> unmarshalledReturn;
    auto _comInst = WDIIMouseDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIMouseDevice>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addMouseMovedEvent:(void (^)(WDIMouseDevice*, WDIMouseEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_MouseMoved(
        Make<ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMouseMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MouseMoved(cookie));
}

@end

@implementation WDIMouseEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::IMouseEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIMouseDelta*)mouseDelta {
    ABI::Windows::Devices::Input::MouseDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseDelta(&unmarshalledReturn));
    return WDIMouseDelta_create(unmarshalledReturn);
}

@end

@implementation WDIMouseCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::IMouseCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Input.MouseCapabilities").Get(), &out));
    return [_createRtProxy<WDIMouseCapabilities>(out.Get()) retain];
}

- (int)mousePresent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_MousePresent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)verticalWheelPresent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalWheelPresent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)horizontalWheelPresent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalWheelPresent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)swapButtons {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SwapButtons(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)numberOfButtons {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IMouseCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfButtons(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDIKeyboardCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::IKeyboardCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Input.KeyboardCapabilities").Get(), &out));
    return [_createRtProxy<WDIKeyboardCapabilities>(out.Get()) retain];
}

- (int)keyboardPresent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::IKeyboardCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyboardPresent(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDITouchCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Input::ITouchCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Input.TouchCapabilities").Get(), &out));
    return [_createRtProxy<WDITouchCapabilities>(out.Get()) retain];
}

- (int)touchPresent {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::ITouchCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_TouchPresent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)contacts {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Input::ITouchCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contacts(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDIPointerDeviceUsage {
    ABI::Windows::Devices::Input::PointerDeviceUsage structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::Input::PointerDeviceUsage)s {
    WDIPointerDeviceUsage* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::Input::PointerDeviceUsage*)internalStruct {
    return &structVal;
}
- (unsigned int)usagePage {
    return structVal.UsagePage;
}
- (void)setUsagePage:(unsigned int)val {
    structVal.UsagePage = val;
}
- (unsigned int)usage {
    return structVal.Usage;
}
- (void)setUsage:(unsigned int)val {
    structVal.Usage = val;
}
- (int)minLogical {
    return structVal.MinLogical;
}
- (void)setMinLogical:(int)val {
    structVal.MinLogical = val;
}
- (int)maxLogical {
    return structVal.MaxLogical;
}
- (void)setMaxLogical:(int)val {
    structVal.MaxLogical = val;
}
- (int)minPhysical {
    return structVal.MinPhysical;
}
- (void)setMinPhysical:(int)val {
    structVal.MinPhysical = val;
}
- (int)maxPhysical {
    return structVal.MaxPhysical;
}
- (void)setMaxPhysical:(int)val {
    structVal.MaxPhysical = val;
}
- (unsigned int)unit {
    return structVal.Unit;
}
- (void)setUnit:(unsigned int)val {
    structVal.Unit = val;
}
- (float)physicalMultiplier {
    return structVal.PhysicalMultiplier;
}
- (void)setPhysicalMultiplier:(float)val {
    structVal.PhysicalMultiplier = val;
}
@end
@implementation WDIMouseDelta {
    ABI::Windows::Devices::Input::MouseDelta structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::Input::MouseDelta)s {
    WDIMouseDelta* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::Input::MouseDelta*)internalStruct {
    return &structVal;
}
- (int)x {
    return structVal.X;
}
- (void)setX:(int)val {
    structVal.X = val;
}
- (int)y {
    return structVal.Y;
}
- (void)setY:(int)val {
    structVal.Y = val;
}
@end
id RTProxiedNSArray_WDIPointerDevice_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Input::PointerDevice*>,
                                         RTArrayObj<ABI::Windows::Devices::Input::IPointerDevice*,
                                                    IVectorView<ABI::Windows::Devices::Input::PointerDevice*>,
                                                    WDIPointerDevice,
                                                    ABI::Windows::Devices::Input::PointerDevice*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDIPointerDeviceUsage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Input::PointerDeviceUsage>,
                                         RTArrayObj<ABI::Windows::Devices::Input::PointerDeviceUsage,
                                                    IVectorView<ABI::Windows::Devices::Input::PointerDeviceUsage>,
                                                    WDIPointerDeviceUsage,
                                                    ABI::Windows::Devices::Input::PointerDeviceUsage,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
