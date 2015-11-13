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

#include <Foundation/Foundation.h>
#include <inttypes.h>

#ifndef WINRT_EXPORT
#define WINRT_EXPORT __declspec(dllimport)
#endif

#define ACTIVATOR __attribute((ns_returns_retained))

#ifndef __cplusplus
#ifndef WCHAR
#define WCHAR wchar_t
#endif
#endif

WINRT_EXPORT
@interface RTObject : NSObject {
#ifdef _WRL_CLIENT_H_
@public
    Microsoft::WRL::ComPtr<IInspectable> comObj;

    // For composable objects, this is the original interface.
    Microsoft::WRL::ComPtr<IInspectable> innerInterface;
#endif
}
- (id)internalObject;
#ifdef _WRL_CLIENT_H_
- (void)setComObj:(Microsoft::WRL::ComPtr<IInspectable>)obj;
#endif
@end

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

@interface WFGUID : RTObject
@property unsigned long Data1;
@property unsigned short Data2;
@property unsigned short Data3;
@property (readonly) unsigned char* Data4;
@property (readonly) GUID guidValue;
+ (WFGUID*)guidWithGUID:(const GUID)guid;
- initWithGUID:(const GUID)guid;
@end

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

enum _RTCollectionOperation {
    COItemChanged,
    COItemInserted,
    COItemRemoved,
    COReset,
};
typedef unsigned RTCollectionOperation;

typedef void (^RTCollectionListener)(NSObject* srcCollection, RTCollectionOperation op, id loc);

@protocol RTObservableCollection
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
@end
