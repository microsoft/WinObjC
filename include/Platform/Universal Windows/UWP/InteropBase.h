//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#pragma once

#if defined(__cplusplus)
#include <COMIncludes.h>
#include <wrl/client.h>
#include <COMIncludes_End.h>
#endif /*__cpluplus*/

#include <Foundation/Foundation.h>
#include <inttypes.h>
#include <wchar.h>

#ifndef WINRT_EXPORT
#define WINRT_EXPORT __declspec(dllimport)
#endif

#define ACTIVATOR __attribute((ns_returns_retained))

#ifdef __cplusplus
#define WINRT_EXPORT_FN extern "C" WINRT_EXPORT
#else
#define WINRT_EXPORT_FN WINRT_EXPORT
#endif

WINRT_EXPORT
@interface RTObject : NSObject

// Even with the #ifdefs we will not violate ODR, because of dynamic ivars provided by ObjectiveC modern runtime.
#if defined(__cplusplus)
@property (nonatomic) Microsoft::WRL::ComPtr<IInspectable> comObj;

// For composable objects, this is the original interface.
@property (nonatomic) Microsoft::WRL::ComPtr<IInspectable> innerInterface;
#endif /*__cplusplus*/

@end

// Does a safe cast of rtObject into a derived projected class type. Throws if it is an invalid cast.
WINRT_EXPORT_FN
id rt_dynamic_cast(Class classType, RTObject* rtObject);

#ifdef __cplusplus
template <typename ClassType>
ClassType* rt_dynamic_cast(RTObject* rtObject) {
    return rt_dynamic_cast([ClassType class], rtObject);
}
#endif

#ifndef GUID_DEFINED
#define GUID_DEFINED
#if defined(__midl)
typedef struct {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    byte Data4[8];
} GUID;
#else
typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;
#endif
#endif

WINRT_EXPORT
@interface WFGUID : NSObject
@property unsigned long Data1;
@property unsigned short Data2;
@property unsigned short Data3;
@property (readonly) unsigned char* Data4;
@property (readonly) GUID guidValue;
+ (WFGUID*)guidWithGUID:(const GUID)guid;
- initWithGUID:(const GUID)guid;
@end

WINRT_EXPORT
@interface RTKeyValuePair : RTObject
@property (readonly) id Key;
@property (readonly) id Value;
@end

#ifndef __eventtoken_h__
#define __eventtoken_h__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EventRegistrationToken { __int64 value; } EventRegistrationToken;

#ifdef __cplusplus
}
#endif

#endif

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
#ifdef __midl
typedef LONG HRESULT;
#else
typedef _Return_type_success_(return >= 0) long HRESULT;
#endif // __midl
#endif // !_HRESULT_DEFINED

enum _WFAsyncStatus {
    WFAsyncStatusStarted = 0,
    WFAsyncStatusCompleted,
    WFAsyncStatusCanceled,
    WFAsyncStatusError,
};
typedef unsigned WFAsyncStatus;

enum _RTCollectionOperation { COItemChanged, COItemInserted, COItemRemoved, COReset };
typedef unsigned RTCollectionOperation;

typedef void (^RTCollectionListener)(NSObject* srcCollection, RTCollectionOperation op, id loc);

@protocol RTObservableCollection
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
@end
