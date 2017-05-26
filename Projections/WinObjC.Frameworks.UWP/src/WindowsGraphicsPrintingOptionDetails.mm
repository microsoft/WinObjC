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

// WindowsGraphicsPrintingOptionDetails.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Printing.OptionDetails.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsPrintingOptionDetails.h"
#include "WindowsGraphicsPrintingOptionDetails_priv.h"

@implementation WGPOIPrintOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPOIPrintNumberOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)minValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPOIPrintTextOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxCharacters {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCharacters(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPOIPrintItemListOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPOIPrintCustomOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPOPrintCopiesOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)minValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxValue {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPOPrintMediaSizeOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintMediaTypeOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintOrientationOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintQualityOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintColorModeOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintDuplexOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintCollationOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintStapleOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintHolePunchOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintBindingOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintBorderingOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintCustomTextOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMaxCharacters:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxCharacters(value));
}

- (unsigned int)maxCharacters {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCharacters(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPOPrintCustomItemDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)itemId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setItemDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemDisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)itemDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGPOPrintCustomItemListOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)optionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPOPrintOptionType)optionType {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionType(&unmarshalledReturn));
    return (WGPOPrintOptionType)unmarshalledReturn;
}

- (void)setErrorText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_ErrorText(nsStrToHstr(value).Get()));
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setState:(WGPOPrintOptionStates)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates)value));
}

- (WGPOPrintOptionStates)state {
    ABI::Windows::Graphics::Printing::OptionDetails::PrintOptionStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGPOPrintOptionStates)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)trySetValue:(RTObject*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue([value comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* RTObject* */)items {
    ComPtr<IVectorView<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_create(unmarshalledReturn.Get());
}

- (void)addItem:(NSString*)itemId displayName:(NSString*)displayName {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->AddItem(nsStrToHstr(itemId).Get(), nsStrToHstr(displayName).Get()));
}

@end

@implementation WGPOPrintTaskOptionChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)optionId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OptionId(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WGPOPrintTaskOptionDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic> WGPOIPrintTaskOptionDetailsStatic_inst() {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing.OptionDetails.PrintTaskOptionDetails").Get(), &inst));
    return inst;
}

+ (WGPOPrintTaskOptionDetails*)getFromPrintTaskOptions:(WGPPrintTaskOptions*)printTaskOptions {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> unmarshalledReturn;
    auto _comInst = WGPOIPrintTaskOptionDetailsStatic_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFromPrintTaskOptions(_getRtInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore>(printTaskOptions).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPOPrintTaskOptionDetails>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject<WGPOIPrintOptionDetails>* */)options {
    ComPtr<IMapView<HSTRING, ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_WGPOIPrintOptionDetails_create(unmarshalledReturn.Get());
}

- (WGPOPrintCustomItemListOptionDetails*)createItemListOption:(NSString*)optionId displayName:(NSString*)displayName {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateItemListOption(nsStrToHstr(optionId).Get(), nsStrToHstr(displayName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPOPrintCustomItemListOptionDetails>(unmarshalledReturn.Get());
}

- (WGPOPrintCustomTextOptionDetails*)createTextOption:(NSString*)optionId displayName:(NSString*)displayName {
    ComPtr<ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateTextOption(nsStrToHstr(optionId).Get(), nsStrToHstr(displayName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPOPrintCustomTextOptionDetails>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addOptionChangedEvent:(void (^)(WGPOPrintTaskOptionDetails*, WGPOPrintTaskOptionChangedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionChanged(
        Make<
            ITypedEventHandler_Windows_Graphics_Printing_OptionDetails_PrintTaskOptionDetails_Windows_Graphics_Printing_OptionDetails_PrintTaskOptionChangedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionChanged(eventCookie));
}

- (EventRegistrationToken)addBeginValidationEvent:(void (^)(WGPOPrintTaskOptionDetails*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->add_BeginValidation(
        Make<ITypedEventHandler_Windows_Graphics_Printing_OptionDetails_PrintTaskOptionDetails_System_Object>(eventHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBeginValidationEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BeginValidation(eventCookie));
}

- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber {
    ABI::Windows::Graphics::Printing::PrintPageDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore>(self);
    THROW_NS_IF_FAILED(_comInst->GetPageDescription(jobPageNumber, &unmarshalledReturn));
    return WGPPrintPageDescription_create(unmarshalledReturn);
}

- (NSMutableArray* /* NSString * */)displayedOptions {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayedOptions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<IInspectable*>,
                        RTArrayObj<IInspectable*, IVectorView<IInspectable*>, RTObject, IInspectable*, dummyObjCCreator, dummyWRLCreator>>>(
        val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTObject_WGPOIPrintOptionDetails_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*,
                     ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*,
                     NSString,
                     RTObject<WGPOIPrintOptionDetails>,
                     IMapView<HSTRING, ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
