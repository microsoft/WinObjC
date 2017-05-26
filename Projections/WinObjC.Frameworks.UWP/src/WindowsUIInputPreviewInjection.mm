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

// WindowsUIInputPreviewInjection.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Input.Preview.Injection.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIInputPreviewInjection.h"
#include "WindowsUIInputPreviewInjection_priv.h"

@implementation WUIPIInjectedInputKeyboardInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Preview.Injection.InjectedInputKeyboardInfo").Get(),
                                              &out));
    return [_createRtProxy<WUIPIInjectedInputKeyboardInfo>(out.Get()) retain];
}

- (WUIPIInjectedInputKeyOptions)keyOptions {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyOptions(&unmarshalledReturn));
    return (WUIPIInjectedInputKeyOptions)unmarshalledReturn;
}

- (void)setKeyOptions:(WUIPIInjectedInputKeyOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyOptions((ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions)value));
}

- (unsigned short)scanCode {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScanCode:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScanCode(value));
}

- (unsigned short)virtualKey {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_VirtualKey(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVirtualKey:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_VirtualKey(value));
}

@end

@implementation WUIPIInjectedInputMouseInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Preview.Injection.InjectedInputMouseInfo").Get(),
                                              &out));
    return [_createRtProxy<WUIPIInjectedInputMouseInfo>(out.Get()) retain];
}

- (WUIPIInjectedInputMouseOptions)mouseOptions {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseOptions(&unmarshalledReturn));
    return (WUIPIInjectedInputMouseOptions)unmarshalledReturn;
}

- (void)setMouseOptions:(WUIPIInjectedInputMouseOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_MouseOptions((ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions)value));
}

- (unsigned int)mouseData {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseData(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMouseData:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_MouseData(value));
}

- (int)deltaY {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeltaY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDeltaY:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeltaY(value));
}

- (int)deltaX {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeltaX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDeltaX:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeltaX(value));
}

- (unsigned int)timeOffsetInMilliseconds {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeOffsetInMilliseconds(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTimeOffsetInMilliseconds:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimeOffsetInMilliseconds(value));
}

@end

@implementation WUIPIInjectedInputTouchInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Preview.Injection.InjectedInputTouchInfo").Get(),
                                              &out));
    return [_createRtProxy<WUIPIInjectedInputTouchInfo>(out.Get()) retain];
}

- (WUIPIInjectedInputRectangle*)contact {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(&unmarshalledReturn));
    return WUIPIInjectedInputRectangle_create(unmarshalledReturn);
}

- (void)setContact:(WUIPIInjectedInputRectangle*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Contact(*[value internalStruct]));
}

- (int)orientation {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOrientation:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation(value));
}

- (WUIPIInjectedInputPointerInfo*)pointerInfo {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerInfo(&unmarshalledReturn));
    return WUIPIInjectedInputPointerInfo_create(unmarshalledReturn);
}

- (void)setPointerInfo:(WUIPIInjectedInputPointerInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerInfo(*[value internalStruct]));
}

- (double)pressure {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPressure:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Pressure(value));
}

- (WUIPIInjectedInputTouchParameters)touchParameters {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TouchParameters(&unmarshalledReturn));
    return (WUIPIInjectedInputTouchParameters)unmarshalledReturn;
}

- (void)setTouchParameters:(WUIPIInjectedInputTouchParameters)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TouchParameters((ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters)value));
}

@end

@implementation WUIPIInjectedInputPenInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.Preview.Injection.InjectedInputPenInfo").Get(),
                                              &out));
    return [_createRtProxy<WUIPIInjectedInputPenInfo>(out.Get()) retain];
}

- (WUIPIInjectedInputPointerInfo*)pointerInfo {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerInfo(&unmarshalledReturn));
    return WUIPIInjectedInputPointerInfo_create(unmarshalledReturn);
}

- (void)setPointerInfo:(WUIPIInjectedInputPointerInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerInfo(*[value internalStruct]));
}

- (WUIPIInjectedInputPenButtons)penButtons {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPenButtons unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PenButtons(&unmarshalledReturn));
    return (WUIPIInjectedInputPenButtons)unmarshalledReturn;
}

- (void)setPenButtons:(WUIPIInjectedInputPenButtons)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_PenButtons((ABI::Windows::UI::Input::Preview::Injection::InjectedInputPenButtons)value));
}

- (WUIPIInjectedInputPenParameters)penParameters {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPenParameters unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PenParameters(&unmarshalledReturn));
    return (WUIPIInjectedInputPenParameters)unmarshalledReturn;
}

- (void)setPenParameters:(WUIPIInjectedInputPenParameters)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_PenParameters((ABI::Windows::UI::Input::Preview::Injection::InjectedInputPenParameters)value));
}

- (double)pressure {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPressure:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Pressure(value));
}

- (double)rotation {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rotation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotation:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rotation(value));
}

- (int)tiltX {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TiltX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTiltX:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TiltX(value));
}

- (int)tiltY {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TiltY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTiltY:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TiltY(value));
}

@end

@implementation WUIPIInputInjector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInputInjector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInputInjectorStatics> WUIPIIInputInjectorStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInputInjectorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Preview.Injection.InputInjector").Get(),
                                                       &inst));
    return inst;
}

+ (WUIPIInputInjector*)tryCreate {
    ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInputInjector> unmarshalledReturn;
    auto _comInst = WUIPIIInputInjectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPIInputInjector>(unmarshalledReturn.Get());
}

- (void)injectKeyboardInput:(id<NSFastEnumeration> /* WUIPIInjectedInputKeyboardInfo* */)input {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->InjectKeyboardInput(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo*,
            ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo*>>::type>*>(
            ConvertToIterable<WUIPIInjectedInputKeyboardInfo,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo*,
                                  ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo*>>(input)
                .Get())));
}

- (void)injectMouseInput:(id<NSFastEnumeration> /* WUIPIInjectedInputMouseInfo* */)input {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->InjectMouseInput(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo*,
            ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo*>>::type>*>(
            ConvertToIterable<
                WUIPIInjectedInputMouseInfo,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo*,
                                                                  ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo*>>(
                input)
                .Get())));
}

- (void)initializeTouchInjection:(WUIPIInjectedInputVisualizationMode)visualMode {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(
        _comInst->InitializeTouchInjection((ABI::Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode)visualMode));
}

- (void)injectTouchInput:(id<NSFastEnumeration> /* WUIPIInjectedInputTouchInfo* */)input {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->InjectTouchInput(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo*,
            ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo*>>::type>*>(
            ConvertToIterable<
                WUIPIInjectedInputTouchInfo,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo*,
                                                                  ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo*>>(
                input)
                .Get())));
}

- (void)uninitializeTouchInjection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->UninitializeTouchInjection());
}

- (void)initializePenInjection:(WUIPIInjectedInputVisualizationMode)visualMode {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(
        _comInst->InitializePenInjection((ABI::Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode)visualMode));
}

- (void)injectPenInput:(WUIPIInjectedInputPenInfo*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(
        _comInst->InjectPenInput(_getRtInterface<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>(input).Get()));
}

- (void)uninitializePenInjection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->UninitializePenInjection());
}

- (void)injectShortcut:(WUIPIInjectedInputShortcut)shortcut {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Preview::Injection::IInputInjector>(self);
    THROW_NS_IF_FAILED(_comInst->InjectShortcut((ABI::Windows::UI::Input::Preview::Injection::InjectedInputShortcut)shortcut));
}

@end

@implementation WUIPIInjectedInputRectangle {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle)s {
    WUIPIInjectedInputRectangle* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle*)internalStruct {
    return &structVal;
}
- (int)left {
    return structVal.Left;
}
- (void)setLeft:(int)val {
    structVal.Left = val;
}
- (int)top {
    return structVal.Top;
}
- (void)setTop:(int)val {
    structVal.Top = val;
}
- (int)bottom {
    return structVal.Bottom;
}
- (void)setBottom:(int)val {
    structVal.Bottom = val;
}
- (int)right {
    return structVal.Right;
}
- (void)setRight:(int)val {
    structVal.Right = val;
}
@end
@implementation WUIPIInjectedInputPoint {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint)s {
    WUIPIInjectedInputPoint* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint*)internalStruct {
    return &structVal;
}
- (int)positionX {
    return structVal.PositionX;
}
- (void)setPositionX:(int)val {
    structVal.PositionX = val;
}
- (int)positionY {
    return structVal.PositionY;
}
- (void)setPositionY:(int)val {
    structVal.PositionY = val;
}
@end
@implementation WUIPIInjectedInputPointerInfo {
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo)s {
    WUIPIInjectedInputPointerInfo* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo*)internalStruct {
    return &structVal;
}
- (unsigned int)pointerId {
    return structVal.PointerId;
}
- (void)setPointerId:(unsigned int)val {
    structVal.PointerId = val;
}
- (WUIPIInjectedInputPointerOptions)pointerOptions {
    return (WUIPIInjectedInputPointerOptions)structVal.PointerOptions;
}
- (void)setPointerOptions:(WUIPIInjectedInputPointerOptions)val {
    structVal.PointerOptions = (ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerOptions)val;
}
- (WUIPIInjectedInputPoint*)pixelLocation {
    return WUIPIInjectedInputPoint_create(structVal.PixelLocation);
}
- (void)setPixelLocation:(WUIPIInjectedInputPoint*)val {
    structVal.PixelLocation = *[val internalStruct];
}
- (unsigned int)timeOffsetInMilliseconds {
    return structVal.TimeOffsetInMilliseconds;
}
- (void)setTimeOffsetInMilliseconds:(unsigned int)val {
    structVal.TimeOffsetInMilliseconds = val;
}
- (uint64_t)performanceCount {
    return structVal.PerformanceCount;
}
- (void)setPerformanceCount:(uint64_t)val {
    structVal.PerformanceCount = val;
}
@end
id RTProxiedIterableNSArray_WUIPIInjectedInputKeyboardInfo_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo*>,
                                RTIterableObj<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo*,
                                              IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo*>,
                                              WUIPIInjectedInputKeyboardInfo,
                                              ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WUIPIInjectedInputMouseInfo_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo*>,
                                RTIterableObj<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo*,
                                              IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo*>,
                                              WUIPIInjectedInputMouseInfo,
                                              ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WUIPIInjectedInputTouchInfo_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo*>,
                                RTIterableObj<ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo*,
                                              IIterable<ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo*>,
                                              WUIPIInjectedInputTouchInfo,
                                              ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
