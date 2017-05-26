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

// WindowsUIXamlMarkup.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Markup.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlMarkup.h"
#include "WindowsUIXamlMarkup_priv.h"

@implementation WUXMIComponentConnector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IComponentConnector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)connect:(int)connectionId target:(RTObject*)target {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IComponentConnector>(self);
    THROW_NS_IF_FAILED(_comInst->Connect(connectionId, [target comObj].Get()));
}

@end

@implementation WUXMIComponentConnector2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IComponentConnector2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXMIComponentConnector>*)getBindingConnector:(int)connectionId target:(RTObject*)target {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IComponentConnector> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IComponentConnector2>(self);
    THROW_NS_IF_FAILED(_comInst->GetBindingConnector(connectionId, [target comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIComponentConnector>(unmarshalledReturn.Get());
}

@end

@implementation WUXMIXamlMember

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMember> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isAttachable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAttachable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDependencyProperty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDependencyProperty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WUXMIXamlType>*)targetType {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlType>*)type {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject*)getValue:(RTObject*)instance {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->GetValue([instance comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject*)instance value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMember>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue([instance comObj].Get(), [value comObj].Get()));
}

@end

@implementation WUXMIXamlType

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXMIXamlType>*)baseType {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlMember>*)contentProperty {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMember> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlMember>(unmarshalledReturn.Get());
}

- (NSString*)fullName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isArray {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsArray(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCollection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCollection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isConstructible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConstructible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDictionary {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDictionary(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMarkupExtension {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMarkupExtension(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBindable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBindable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WUXMIXamlType>*)itemType {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlType>*)keyType {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (WUXITypeName*)underlyingType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnderlyingType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (RTObject*)activateInstance {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->ActivateInstance(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)createFromString:(NSString*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFromString(nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlMember>*)getMember:(NSString*)name {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMember> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->GetMember(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlMember>(unmarshalledReturn.Get());
}

- (void)addToVector:(RTObject*)instance value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->AddToVector([instance comObj].Get(), [value comObj].Get()));
}

- (void)addToMap:(RTObject*)instance key:(RTObject*)key value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->AddToMap([instance comObj].Get(), [key comObj].Get(), [value comObj].Get()));
}

- (void)runInitializer {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlType>(self);
    THROW_NS_IF_FAILED(_comInst->RunInitializer());
}

@end

@implementation WUXMIXamlMetadataProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXMIXamlType>*)getXamlType:(WUXITypeName*)type {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXamlType(*[type internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlType>*)getXamlTypeByFullName:(NSString*)fullName {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXamlTypeByFullName(nsStrToHstr(fullName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (NSArray* /* WUXMXmlnsDefinition* */)getXmlnsDefinitions {
    ABI::Windows::UI::Xaml::Markup::XmlnsDefinition* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXmlnsDefinitions(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXMXmlnsDefinition_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXMIDataTemplateComponent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)recycle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent>(self);
    THROW_NS_IF_FAILED(_comInst->Recycle());
}

- (void)processBindings:(RTObject*)item itemIndex:(int)itemIndex phase:(int)phase nextPhase:(int*)nextPhase {
    int nextPhaseOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessBindings([item comObj].Get(), itemIndex, phase, &nextPhaseOutUnmarshaled));
    *nextPhase = nextPhaseOutUnmarshaled;
}

@end

@implementation WUXMXamlBinaryWriter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics> WUXMIXamlBinaryWriterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Markup.XamlBinaryWriter").Get(), &inst));
    return inst;
}

+ (WUXMXamlBinaryWriterErrorInformation*)write:(NSMutableArray* /* RTObject<WSSIRandomAccessStream>* */)inputStreams
                                 outputStreams:(NSMutableArray* /* RTObject<WSSIRandomAccessStream>* */)outputStreams
                          xamlMetadataProvider:(RTObject<WUXMIXamlMetadataProvider>*)xamlMetadataProvider {
    ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation unmarshalledReturn;
    auto _comInst = WUXMIXamlBinaryWriterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Write(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                              ABI::Windows::Storage::Streams::IRandomAccessStream*>>::type>*>(
            ConvertToVector<RTObject<WSSIRandomAccessStream>,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                                              ABI::Windows::Storage::Streams::IRandomAccessStream*>>(
                inputStreams)
                .Get()),
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                              ABI::Windows::Storage::Streams::IRandomAccessStream*>>::type>*>(
            ConvertToVector<RTObject<WSSIRandomAccessStream>,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                                              ABI::Windows::Storage::Streams::IRandomAccessStream*>>(
                outputStreams)
                .Get()),
        _getRtInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(xamlMetadataProvider).Get(),
        &unmarshalledReturn));
    return WUXMXamlBinaryWriterErrorInformation_create(unmarshalledReturn);
}

@end

@implementation WUXMXamlReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlReaderStatics> WUXMIXamlReaderStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlReaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Markup.XamlReader").Get(), &inst));
    return inst;
}

+ (RTObject*)Load:(NSString*)xaml {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WUXMIXamlReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Load(nsStrToHstr(xaml).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)loadWithInitialTemplateValidation:(NSString*)xaml {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WUXMIXamlReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadWithInitialTemplateValidation(nsStrToHstr(xaml).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXMXamlBindingHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBindingHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBindingHelperStatics> WUXMIXamlBindingHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBindingHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Markup.XamlBindingHelper").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)dataTemplateComponentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataTemplateComponentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (RTObject<WUXMIDataTemplateComponent>*)getDataTemplateComponent:(WXDependencyObject*)element {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent> unmarshalledReturn;
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDataTemplateComponent(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIDataTemplateComponent>(unmarshalledReturn.Get());
}

+ (void)setDataTemplateComponent:(WXDependencyObject*)element value:(RTObject<WUXMIDataTemplateComponent>*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetDataTemplateComponent(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                           _getRtInterface<ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent>(value).Get()));
}

+ (void)suspendRendering:(WXUIElement*)target {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SuspendRendering(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(target).Get()));
}

+ (void)resumeRendering:(WXUIElement*)target {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ResumeRendering(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(target).Get()));
}

+ (RTObject*)convertValue:(WUXITypeName*)type value:(RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertValue(*[type internalStruct], [value comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (void)setPropertyFromString:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(NSString*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromString([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       nsStrToHstr(value).Get()));
}

+ (void)setPropertyFromBoolean:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(BOOL)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromBoolean([dependencyObject comObj].Get(),
                                                        _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                        (boolean)value));
}

+ (void)setPropertyFromChar16:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(wchar_t)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromChar16([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       value));
}

+ (void)setPropertyFromDateTime:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFDateTime*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromDateTime([dependencyObject comObj].Get(),
                                                         _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                         *[value internalStruct]));
}

+ (void)setPropertyFromDouble:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(double)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromDouble([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       value));
}

+ (void)setPropertyFromInt32:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(int)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromInt32([dependencyObject comObj].Get(),
                                                      _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                      value));
}

+ (void)setPropertyFromUInt32:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(unsigned int)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromUInt32([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       value));
}

+ (void)setPropertyFromInt64:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(int64_t)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromInt64([dependencyObject comObj].Get(),
                                                      _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                      value));
}

+ (void)setPropertyFromUInt64:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(uint64_t)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromUInt64([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       value));
}

+ (void)setPropertyFromSingle:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(float)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromSingle([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       value));
}

+ (void)setPropertyFromPoint:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFPoint*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromPoint([dependencyObject comObj].Get(),
                                                      _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                      *[value internalStruct]));
}

+ (void)setPropertyFromRect:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFRect*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromRect([dependencyObject comObj].Get(),
                                                     _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                     *[value internalStruct]));
}

+ (void)setPropertyFromSize:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFSize*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromSize([dependencyObject comObj].Get(),
                                                     _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                     *[value internalStruct]));
}

+ (void)setPropertyFromTimeSpan:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFTimeSpan*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromTimeSpan([dependencyObject comObj].Get(),
                                                         _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                         *[value internalStruct]));
}

+ (void)setPropertyFromByte:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(uint8_t)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromByte([dependencyObject comObj].Get(),
                                                     _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                     value));
}

+ (void)setPropertyFromUri:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(WFUri*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromUri([dependencyObject comObj].Get(),
                                                    _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

+ (void)setPropertyFromObject:(RTObject*)dependencyObject propertyToSet:(WXDependencyProperty*)propertyToSet value:(RTObject*)value {
    auto _comInst = WUXMIXamlBindingHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetPropertyFromObject([dependencyObject comObj].Get(),
                                                       _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(propertyToSet).Get(),
                                                       [value comObj].Get()));
}

@end

@implementation WUXMXamlBinaryWriterErrorInformation {
    ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation)s {
    WUXMXamlBinaryWriterErrorInformation* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation*)internalStruct {
    return &structVal;
}
- (unsigned int)inputStreamIndex {
    return structVal.InputStreamIndex;
}
- (void)setInputStreamIndex:(unsigned int)val {
    structVal.InputStreamIndex = val;
}
- (unsigned int)lineNumber {
    return structVal.LineNumber;
}
- (void)setLineNumber:(unsigned int)val {
    structVal.LineNumber = val;
}
- (unsigned int)linePosition {
    return structVal.LinePosition;
}
- (void)setLinePosition:(unsigned int)val {
    structVal.LinePosition = val;
}
@end
@implementation WUXMXmlnsDefinition {
    ABI::Windows::UI::Xaml::Markup::XmlnsDefinition structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Markup::XmlnsDefinition)s {
    WUXMXmlnsDefinition* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Markup::XmlnsDefinition*)internalStruct {
    return &structVal;
}
- (NSString*)xmlNamespace {
    return hstrToNSStr(structVal.XmlNamespace);
}
- (void)setXmlNamespace:(NSString*)val {
    structVal.XmlNamespace = nsStrToHstr(val).Detach();
}
- (NSString*)Namespace {
    return hstrToNSStr(structVal.Namespace);
}
- (void)setNamespace:(NSString*)val {
    structVal.Namespace = nsStrToHstr(val).Detach();
}
@end
id RTProxiedNSArray_C_WUXMXmlnsDefinition_create(UINT32 size, ABI::Windows::UI::Xaml::Markup::XmlnsDefinition* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::UI::Xaml::Markup::XmlnsDefinition,
                         RTCArrayObj<ABI::Windows::UI::Xaml::Markup::XmlnsDefinition, WUXMXmlnsDefinition, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WSSIRandomAccessStream_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
                                                RTMutableArrayObj<ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                                  IVector<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
                                                                  RTObject<WSSIRandomAccessStream>,
                                                                  ABI::Windows::Storage::Streams::IRandomAccessStream*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
