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

// WindowsFoundation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Foundation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsFoundation.h"
#include "WindowsFoundation_priv.h"

@implementation WFIClosable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IClosable> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFIPropertyValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IPropertyValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPropertyType)type {
    ABI::Windows::Foundation::PropertyType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WFPropertyType)unmarshalledReturn;
}

- (BOOL)isNumericScalar {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNumericScalar(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (uint8_t)getUInt8 {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt8(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int16_t)getInt16 {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)getUInt16 {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)getInt32 {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)getUInt32 {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)getInt64 {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)getUInt64 {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)getSingle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetSingle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)getDouble {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetDouble(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (wchar_t)getChar16 {
    wchar_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetChar16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)getBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)getString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)getGuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetGuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFDateTime*)getDateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetDateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)getTimeSpan {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetTimeSpan(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)getPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFSize*)getSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)getRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)getUInt8Array:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt8Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

- (void)getInt16Array:(NSArray* /* int16_t */*)value {
    UINT32 __value_ArrayLen = 0;
    int16_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt16Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Int16_create(__value_ArrayLen, __value_Array);
}

- (void)getUInt16Array:(NSArray* /* unsigned short */*)value {
    UINT32 __value_ArrayLen = 0;
    unsigned short* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt16Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt16_create(__value_ArrayLen, __value_Array);
}

- (void)getInt32Array:(NSArray* /* int */*)value {
    UINT32 __value_ArrayLen = 0;
    int* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt32Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Int32_create(__value_ArrayLen, __value_Array);
}

- (void)getUInt32Array:(NSArray* /* unsigned int */*)value {
    UINT32 __value_ArrayLen = 0;
    unsigned int* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt32Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt32_create(__value_ArrayLen, __value_Array);
}

- (void)getInt64Array:(NSArray* /* int64_t */*)value {
    UINT32 __value_ArrayLen = 0;
    int64_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInt64Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Int64_create(__value_ArrayLen, __value_Array);
}

- (void)getUInt64Array:(NSArray* /* uint64_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint64_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetUInt64Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt64_create(__value_ArrayLen, __value_Array);
}

- (void)getSingleArray:(NSArray* /* float */*)value {
    UINT32 __value_ArrayLen = 0;
    float* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetSingleArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Single_create(__value_ArrayLen, __value_Array);
}

- (void)getDoubleArray:(NSArray* /* double */*)value {
    UINT32 __value_ArrayLen = 0;
    double* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetDoubleArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Double_create(__value_ArrayLen, __value_Array);
}

- (void)getChar16Array:(NSArray* /* wchar_t */*)value {
    UINT32 __value_ArrayLen = 0;
    wchar_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetChar16Array(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Char16_create(__value_ArrayLen, __value_Array);
}

- (void)getBooleanArray:(NSArray* /* BOOL */*)value {
    UINT32 __value_ArrayLen = 0;
    boolean* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetBooleanArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_Boolean_create(__value_ArrayLen, __value_Array);
}

- (void)getStringArray:(NSArray* /* NSString * */*)value {
    UINT32 __value_ArrayLen = 0;
    HSTRING* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetStringArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_NSString_create(__value_ArrayLen, __value_Array);
}

- (void)getInspectableArray:(NSArray* /* RTObject* */*)value {
    UINT32 __value_ArrayLen = 0;
    IInspectable** __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetInspectableArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_RTObject_create(__value_ArrayLen, __value_Array);
}

- (void)getGuidArray:(NSArray* /* WFGUID* */*)value {
    UINT32 __value_ArrayLen = 0;
    GUID* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetGuidArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFGUID_create(__value_ArrayLen, __value_Array);
}

- (void)getDateTimeArray:(NSArray* /* WFDateTime* */*)value {
    UINT32 __value_ArrayLen = 0;
    ABI::Windows::Foundation::DateTime* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetDateTimeArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFDateTime_create(__value_ArrayLen, __value_Array);
}

- (void)getTimeSpanArray:(NSArray* /* WFTimeSpan* */*)value {
    UINT32 __value_ArrayLen = 0;
    ABI::Windows::Foundation::TimeSpan* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetTimeSpanArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFTimeSpan_create(__value_ArrayLen, __value_Array);
}

- (void)getPointArray:(NSArray* /* WFPoint* */*)value {
    UINT32 __value_ArrayLen = 0;
    ABI::Windows::Foundation::Point* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetPointArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFPoint_create(__value_ArrayLen, __value_Array);
}

- (void)getSizeArray:(NSArray* /* WFSize* */*)value {
    UINT32 __value_ArrayLen = 0;
    ABI::Windows::Foundation::Size* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetSizeArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFSize_create(__value_ArrayLen, __value_Array);
}

- (void)getRectArray:(NSArray* /* WFRect* */*)value {
    UINT32 __value_ArrayLen = 0;
    ABI::Windows::Foundation::Rect* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IPropertyValue>(self);
    THROW_NS_IF_FAILED(_comInst->GetRectArray(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_WFRect_create(__value_ArrayLen, __value_Array);
}

@end

@implementation WFIStringable

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IStringable> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WFIAsyncInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFIAsyncAction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCompleted:(WFAsyncActionCompletedHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Completed(Make<WFAsyncActionCompletedHandler_shim>(handler).Get()));
}

- (WFAsyncActionCompletedHandler)completed {
    ComPtr<ABI::Windows::Foundation::IAsyncActionCompletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completed(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)getResults {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->GetResults());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFIWwwFormUrlDecoderEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WFIGetActivationFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IGetActivationFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)getActivationFactory:(NSString*)activatableClassId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IGetActivationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetActivationFactory(nsStrToHstr(activatableClassId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WFIMemoryBufferReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)capacity {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBufferReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WFIMemoryBufferReference>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBufferReference>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(Make<ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object>(handler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBufferReference>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(cookie));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFIMemoryBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IMemoryBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIMemoryBufferReference>*)createReference {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->CreateReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIMemoryBufferReference>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFPropertyValue

ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> WFIPropertyValueStatics_inst() {
    ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.PropertyValue").Get(), &inst));
    return inst;
}

+ (RTObject*)createEmpty {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateEmpty(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt8:(uint8_t)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt8(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt16:(int16_t)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt16(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt16:(unsigned short)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt16(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt32:(int)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt32(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt32:(unsigned int)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt32(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt64:(int64_t)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt64(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt64:(uint64_t)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt64(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createSingle:(float)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSingle(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createDouble:(double)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDouble(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createChar16:(wchar_t)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateChar16(value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createBoolean:(BOOL)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBoolean((boolean)value, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createString:(NSString*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateString(nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInspectable:(RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInspectable([value comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createGuid:(WFGUID*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateGuid(value.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createDateTime:(WFDateTime*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTime(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createTimeSpan:(WFTimeSpan*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTimeSpan(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createPoint:(WFPoint*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePoint(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createSize:(WFSize*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSize(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createRect:(WFRect*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateRect(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt8Array:(NSArray* /* uint8_t */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt8Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt16Array:(NSArray* /* int16_t */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int16_t* __value_Array = NULL;
    if (!ConvertToCArray<int16_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt16Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt16Array:(NSArray* /* unsigned short */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned short* __value_Array = NULL;
    if (!ConvertToCArray<unsigned short>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt16Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt32Array:(NSArray* /* int */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int* __value_Array = NULL;
    if (!ConvertToCArray<int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt32Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt32Array:(NSArray* /* unsigned int */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned int* __value_Array = NULL;
    if (!ConvertToCArray<unsigned int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt32Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInt64Array:(NSArray* /* int64_t */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int64_t* __value_Array = NULL;
    if (!ConvertToCArray<int64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInt64Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createUInt64Array:(NSArray* /* uint64_t */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint64_t* __value_Array = NULL;
    if (!ConvertToCArray<uint64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUInt64Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createSingleArray:(NSArray* /* float */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    float* __value_Array = NULL;
    if (!ConvertToCArray<float>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSingleArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createDoubleArray:(NSArray* /* double */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    double* __value_Array = NULL;
    if (!ConvertToCArray<double>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDoubleArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createChar16Array:(NSArray* /* wchar_t */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    wchar_t* __value_Array = NULL;
    if (!ConvertToCArray<wchar_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateChar16Array(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createBooleanArray:(NSArray* /* BOOL */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    boolean* __value_Array = NULL;
    if (!ConvertToCArray<boolean>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBooleanArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createStringArray:(NSArray* /* NSString * */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    HSTRING* __value_Array = NULL;
    if (!ConvertToCArray<HSTRING>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateStringArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createInspectableArray:(NSArray* /* RTObject* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    IInspectable** __value_Array = NULL;
    if (!ConvertToCArray<IInspectable*>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInspectableArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createGuidArray:(NSArray* /* WFGUID* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    GUID* __value_Array = NULL;
    if (!ConvertToCArray<GUID>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateGuidArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createDateTimeArray:(NSArray* /* WFDateTime* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::DateTime* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::DateTime>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDateTimeArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createTimeSpanArray:(NSArray* /* WFTimeSpan* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::TimeSpan* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::TimeSpan>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTimeSpanArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createPointArray:(NSArray* /* WFPoint* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Point* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePointArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createSizeArray:(NSArray* /* WFSize* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Size* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Size>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSizeArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (RTObject*)createRectArray:(NSArray* /* WFRect* */)value {
    ComPtr<IInspectable> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Rect* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Rect>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WFIPropertyValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateRectArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WFDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::IDeferralFactory> WFIDeferralFactory_inst() {
    ComPtr<ABI::Windows::Foundation::IDeferralFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Deferral").Get(), &inst));
    return inst;
}

+ (WFDeferral*)make:(WFDeferralCompletedHandler)handler {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = WFIDeferralFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(Make<WFDeferralCompletedHandler_shim>(handler).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDeferral>(unmarshalledReturn.Get()) retain];
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFWwwFormUrlDecoder {
    RTArrayObj<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry*,
               IVectorView<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry*>,
               RTObject<WFIWwwFormUrlDecoderEntry>,
               ABI::Windows::Foundation::IWwwFormUrlDecoderEntry*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             RTObject<WFIWwwFormUrlDecoderEntry>,
                             ABI::Windows::Foundation::IWwwFormUrlDecoderEntry*,
                             ABI::Windows::Foundation::IWwwFormUrlDecoderEntry*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> WFIWwwFormUrlDecoderRuntimeClassFactory_inst() {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.WwwFormUrlDecoder").Get(), &inst));
    return inst;
}

+ (WFWwwFormUrlDecoder*)makeWwwFormUrlDecoder:(NSString*)query {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> unmarshalledReturn;
    auto _comInst = WFIWwwFormUrlDecoderRuntimeClassFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWwwFormUrlDecoder(nsStrToHstr(query).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFWwwFormUrlDecoder>(unmarshalledReturn.Get()) retain];
}

- (NSString*)getFirstValueByName:(NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->GetFirstValueByName(nsStrToHstr(name).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WFUri

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::IUriRuntimeClassFactory> WFIUriRuntimeClassFactory_inst() {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClassFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Uri").Get(), &inst));
    return inst;
}

+ (WFUri*)makeUri:(NSString*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WFIUriRuntimeClassFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUri(nsStrToHstr(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFUri>(unmarshalledReturn.Get()) retain];
}

+ (WFUri*)makeWithRelativeUri:(NSString*)baseUri relativeUri:(NSString*)relativeUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WFIUriRuntimeClassFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithRelativeUri(nsStrToHstr(baseUri).Get(), nsStrToHstr(relativeUri).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFUri>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Foundation::IUriEscapeStatics> WFIUriEscapeStatics_inst() {
    ComPtr<ABI::Windows::Foundation::IUriEscapeStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Uri").Get(), &inst));
    return inst;
}

+ (NSString*)unescapeComponent:(NSString*)toUnescape {
    HSTRING unmarshalledReturn;
    auto _comInst = WFIUriEscapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnescapeComponent(nsStrToHstr(toUnescape).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)escapeComponent:(NSString*)toEscape {
    HSTRING unmarshalledReturn;
    auto _comInst = WFIUriEscapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->EscapeComponent(nsStrToHstr(toEscape).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)absoluteUri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayUri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)domain {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Domain(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)extension {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Extension(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)fragment {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fragment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)host {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Host(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)password {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Password(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)query {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Query(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFWwwFormUrlDecoder*)queryParsed {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryParsed(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFWwwFormUrlDecoder>(unmarshalledReturn.Get());
}

- (NSString*)rawUri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)schemeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_SchemeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)port {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Port(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)suspicious {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->get_Suspicious(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)equals:(WFUri*)pUri {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->Equals(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(pUri).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFUri*)combineUri:(NSString*)relativeUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClass>(self);
    THROW_NS_IF_FAILED(_comInst->CombineUri(nsStrToHstr(relativeUri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)absoluteCanonicalUri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteCanonicalUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayIri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayIri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WFWwwFormUrlDecoderEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IWwwFormUrlDecoderEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WFMemoryBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IMemoryBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::IMemoryBufferFactory> WFIMemoryBufferFactory_inst() {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.MemoryBuffer").Get(), &inst));
    return inst;
}

+ (WFMemoryBuffer*)make:(unsigned int)capacity {
    ComPtr<ABI::Windows::Foundation::IMemoryBuffer> unmarshalledReturn;
    auto _comInst = WFIMemoryBufferFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(capacity, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFMemoryBuffer>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WFIMemoryBufferReference>*)createReference {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->CreateReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIMemoryBufferReference>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFPoint {
    ABI::Windows::Foundation::Point structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Point)s {
    WFPoint* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Point*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
@end
@implementation WFSize {
    ABI::Windows::Foundation::Size structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Size)s {
    WFSize* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Size*)internalStruct {
    return &structVal;
}
- (float)width {
    return structVal.Width;
}
- (void)setWidth:(float)val {
    structVal.Width = val;
}
- (float)height {
    return structVal.Height;
}
- (void)setHeight:(float)val {
    structVal.Height = val;
}
@end
@implementation WFRect {
    ABI::Windows::Foundation::Rect structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Rect)s {
    WFRect* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Rect*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
- (float)width {
    return structVal.Width;
}
- (void)setWidth:(float)val {
    structVal.Width = val;
}
- (float)height {
    return structVal.Height;
}
- (void)setHeight:(float)val {
    structVal.Height = val;
}
@end
@implementation WFDateTime {
    ABI::Windows::Foundation::DateTime structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::DateTime)s {
    WFDateTime* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::DateTime*)internalStruct {
    return &structVal;
}
- (int64_t)universalTime {
    return structVal.UniversalTime;
}
- (void)setUniversalTime:(int64_t)val {
    structVal.UniversalTime = val;
}
@end
@implementation WFTimeSpan {
    ABI::Windows::Foundation::TimeSpan structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::TimeSpan)s {
    WFTimeSpan* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::TimeSpan*)internalStruct {
    return &structVal;
}
- (int64_t)duration {
    return structVal.Duration;
}
- (void)setDuration:(int64_t)val {
    structVal.Duration = val;
}
@end
id RTProxiedNSArray_C_Boolean_create(UINT32 size, boolean* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<boolean, RTCArrayObj<boolean, BOOL, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Char16_create(UINT32 size, wchar_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<wchar_t, RTCArrayObj<wchar_t, wchar_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Double_create(UINT32 size, double* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<double, RTCArrayObj<double, double, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int16_create(UINT32 size, int16_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<int16_t, RTCArrayObj<int16_t, int16_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<CArrayAdapterObj<int, RTCArrayObj<int, int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int64_create(UINT32 size, int64_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<int64_t, RTCArrayObj<int64_t, int64_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<HSTRING, RTCArrayObj<HSTRING, NSString, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_RTObject_create(UINT32 size, IInspectable** val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<IInspectable*, RTCArrayObj<IInspectable*, RTObject, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Single_create(UINT32 size, float* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<float, RTCArrayObj<float, float, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt16_create(UINT32 size, unsigned short* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<unsigned short, RTCArrayObj<unsigned short, unsigned short, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt32_create(UINT32 size, unsigned int* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<unsigned int, RTCArrayObj<unsigned int, unsigned int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt64_create(UINT32 size, uint64_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint64_t, RTCArrayObj<uint64_t, uint64_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFDateTime_create(UINT32 size, ABI::Windows::Foundation::DateTime* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::DateTime,
                                          RTCArrayObj<ABI::Windows::Foundation::DateTime, WFDateTime, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFGUID_create(UINT32 size, GUID* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<GUID, RTCArrayObj<GUID, WFGUID, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Point, RTCArrayObj<ABI::Windows::Foundation::Point, WFPoint, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFRect_create(UINT32 size, ABI::Windows::Foundation::Rect* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Rect, RTCArrayObj<ABI::Windows::Foundation::Rect, WFRect, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFSize_create(UINT32 size, ABI::Windows::Foundation::Size* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Size, RTCArrayObj<ABI::Windows::Foundation::Size, WFSize, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFTimeSpan_create(UINT32 size, ABI::Windows::Foundation::TimeSpan* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::TimeSpan,
                                          RTCArrayObj<ABI::Windows::Foundation::TimeSpan, WFTimeSpan, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
