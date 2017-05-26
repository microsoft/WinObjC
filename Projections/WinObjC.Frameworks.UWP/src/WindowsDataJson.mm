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

// WindowsDataJson.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Json.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataJson.h"
#include "WindowsDataJson_priv.h"

@implementation WDJIJsonValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDJJsonValueType)valueType {
    ABI::Windows::Data::Json::JsonValueType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueType(&unmarshalledReturn));
    return (WDJJsonValueType)unmarshalledReturn;
}

- (NSString*)stringify {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->Stringify(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNumber {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonArray*)getArray {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetArray(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (WDJJsonObject*)getObject {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetObject(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

@end

@implementation WDJJsonArray {
    RTMutableArrayObj<ABI::Windows::Data::Json::IJsonValue*,
                      IVector<ABI::Windows::Data::Json::IJsonValue*>,
                      RTObject<WDJIJsonValue>,
                      ABI::Windows::Data::Json::IJsonValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, RTObject<WDJIJsonValue>, ABI::Windows::Data::Json::IJsonValue*, ABI::Windows::Data::Json::IJsonValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Data.Json.JsonArray").Get(), &out));
    return [_createRtProxy<WDJJsonArray>(out.Get()) retain];
}

ComPtr<ABI::Windows::Data::Json::IJsonArrayStatics> WDJIJsonArrayStatics_inst() {
    ComPtr<ABI::Windows::Data::Json::IJsonArrayStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Json.JsonArray").Get(), &inst));
    return inst;
}

+ (WDJJsonArray*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = WDJIJsonArrayStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input result:(WDJJsonArray**)result {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDJIJsonArrayStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(), resultOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *result = _createRtProxy<WDJJsonArray>(resultOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonObject*)getObjectAt:(unsigned int)index {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonArray>(self);
    THROW_NS_IF_FAILED(_comInst->GetObjectAt(index, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (WDJJsonArray*)getArrayAt:(unsigned int)index {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonArray>(self);
    THROW_NS_IF_FAILED(_comInst->GetArrayAt(index, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (NSString*)getStringAt:(unsigned int)index {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonArray>(self);
    THROW_NS_IF_FAILED(_comInst->GetStringAt(index, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNumberAt:(unsigned int)index {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonArray>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumberAt(index, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBooleanAt:(unsigned int)index {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonArray>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanAt(index, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonValueType)valueType {
    ABI::Windows::Data::Json::JsonValueType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueType(&unmarshalledReturn));
    return (WDJJsonValueType)unmarshalledReturn;
}

- (NSString*)stringify {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->Stringify(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNumber {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonArray*)getArray {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetArray(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (WDJJsonObject*)getObject {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetObject(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDJJsonObject {
    RTMapObj<HSTRING,
             HSTRING,
             ABI::Windows::Data::Json::IJsonValue*,
             ABI::Windows::Data::Json::IJsonValue*,
             NSString,
             RTObject<WDJIJsonValue>,
             IMap<HSTRING, ABI::Windows::Data::Json::IJsonValue*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj,
                 RTProxiedNSMutableDictionary_NSString_RTObject_WDJIJsonValue,
                 HSTRING,
                 HSTRING,
                 ABI::Windows::Data::Json::IJsonValue*,
                 ABI::Windows::Data::Json::IJsonValue*,
                 NSString,
                 RTObject<WDJIJsonValue>)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Data.Json.JsonObject").Get(), &out));
    return [_createRtProxy<WDJJsonObject>(out.Get()) retain];
}

ComPtr<ABI::Windows::Data::Json::IJsonObjectStatics> WDJIJsonObjectStatics_inst() {
    ComPtr<ABI::Windows::Data::Json::IJsonObjectStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Json.JsonObject").Get(), &inst));
    return inst;
}

+ (WDJJsonObject*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = WDJIJsonObjectStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input result:(WDJJsonObject**)result {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDJIJsonObjectStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(), resultOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *result = _createRtProxy<WDJJsonObject>(resultOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonValue*)getNamedValue:(NSString*)name {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedValue(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

- (void)setNamedValue:(NSString*)name value:(RTObject<WDJIJsonValue>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetNamedValue(nsStrToHstr(name).Get(), _getRtInterface<ABI::Windows::Data::Json::IJsonValue>(value).Get()));
}

- (WDJJsonObject*)getNamedObject:(NSString*)name {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedObject(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (WDJJsonArray*)getNamedArray:(NSString*)name {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedArray(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (NSString*)getNamedString:(NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedString(nsStrToHstr(name).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNamedNumber:(NSString*)name {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedNumber(nsStrToHstr(name).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getNamedBoolean:(NSString*)name {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedBoolean(nsStrToHstr(name).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonValueType)valueType {
    ABI::Windows::Data::Json::JsonValueType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueType(&unmarshalledReturn));
    return (WDJJsonValueType)unmarshalledReturn;
}

- (NSString*)stringify {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->Stringify(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNumber {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonArray*)getArray {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetArray(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (WDJJsonObject*)getObject {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetObject(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (WDJJsonValue*)getNamedValueOrDefault:(NSString*)name defaultValue:(WDJJsonValue*)defaultValue {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedValueOrDefault(nsStrToHstr(name).Get(),
                                                        _getRtInterface<ABI::Windows::Data::Json::IJsonValue>(defaultValue).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

- (WDJJsonObject*)getNamedObjectOrDefault:(NSString*)name defaultValue:(WDJJsonObject*)defaultValue {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedObjectOrDefault(nsStrToHstr(name).Get(),
                                                         _getRtInterface<ABI::Windows::Data::Json::IJsonObject>(defaultValue).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (NSString*)getNamedStringOrDefault:(NSString*)name defaultValue:(NSString*)defaultValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedStringOrDefault(nsStrToHstr(name).Get(), nsStrToHstr(defaultValue).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDJJsonArray*)getNamedArrayOrDefault:(NSString*)name defaultValue:(WDJJsonArray*)defaultValue {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedArrayOrDefault(nsStrToHstr(name).Get(),
                                                        _getRtInterface<ABI::Windows::Data::Json::IJsonArray>(defaultValue).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (double)getNamedNumberOrDefault:(NSString*)name defaultValue:(double)defaultValue {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedNumberOrDefault(nsStrToHstr(name).Get(), defaultValue, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getNamedBooleanOrDefault:(NSString*)name defaultValue:(BOOL)defaultValue {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonObjectWithDefaultValues>(self);
    THROW_NS_IF_FAILED(_comInst->GetNamedBooleanOrDefault(nsStrToHstr(name).Get(), (boolean)defaultValue, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDJJsonValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Data::Json::IJsonValueStatics2> WDJIJsonValueStatics2_inst() {
    ComPtr<ABI::Windows::Data::Json::IJsonValueStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Json.JsonValue").Get(), &inst));
    return inst;
}

+ (WDJJsonValue*)createNullValue {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateNullValue(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Data::Json::IJsonValueStatics> WDJIJsonValueStatics_inst() {
    ComPtr<ABI::Windows::Data::Json::IJsonValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Json.JsonValue").Get(), &inst));
    return inst;
}

+ (WDJJsonValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input result:(WDJJsonValue**)result {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> resultOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(), resultOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *result = _createRtProxy<WDJJsonValue>(resultOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

+ (WDJJsonValue*)createBooleanValue:(BOOL)input {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBooleanValue((boolean)input, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

+ (WDJJsonValue*)createNumberValue:(double)input {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateNumberValue(input, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

+ (WDJJsonValue*)createStringValue:(NSString*)input {
    ComPtr<ABI::Windows::Data::Json::IJsonValue> unmarshalledReturn;
    auto _comInst = WDJIJsonValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateStringValue(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonValue>(unmarshalledReturn.Get());
}

- (WDJJsonValueType)valueType {
    ABI::Windows::Data::Json::JsonValueType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ValueType(&unmarshalledReturn));
    return (WDJJsonValueType)unmarshalledReturn;
}

- (NSString*)stringify {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->Stringify(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)getNumber {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDJJsonArray*)getArray {
    ComPtr<ABI::Windows::Data::Json::IJsonArray> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetArray(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonArray>(unmarshalledReturn.Get());
}

- (WDJJsonObject*)getObject {
    ComPtr<ABI::Windows::Data::Json::IJsonObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Json::IJsonValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetObject(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDJJsonObject>(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDJJsonError

ComPtr<ABI::Windows::Data::Json::IJsonErrorStatics2> WDJIJsonErrorStatics2_inst() {
    ComPtr<ABI::Windows::Data::Json::IJsonErrorStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Json.JsonError").Get(), &inst));
    return inst;
}

+ (WDJJsonErrorStatus)getJsonStatus:(int)hresult {
    ABI::Windows::Data::Json::JsonErrorStatus unmarshalledReturn;
    auto _comInst = WDJIJsonErrorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetJsonStatus(hresult, &unmarshalledReturn));
    return (WDJJsonErrorStatus)unmarshalledReturn;
}

@end
