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

#include <Windows.ApplicationModel.store.h>
#include <wrl/client.h>
#include <wrl/implements.h>
#include <wrl/module.h>
#include <comutil.h>
#include <functional>
#undef interface

#import <CoreFoundation/CFBase.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::ApplicationModel::Store;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace Microsoft::WRL::Wrappers;

//
// COM Helpers:
//

static std::wstring _stringFromHstring(HSTRING str) {
    if (WindowsIsStringEmpty(str))
        return std::wstring();

    unsigned len;
    auto buff = WindowsGetStringRawBuffer(str, &len);
    auto ret = std::wstring(buff, buff + len);
    WindowsDeleteString(str);
    return ret;
}

static NSString* _nsstringFromHstring(HSTRING str, bool free = false) {
    if (WindowsIsStringEmpty(str))
        return nil;

    unsigned len;
    auto buff = WindowsGetStringRawBuffer(str, &len);
    NSLog(@"ptr: 0x%x len:%d", str, len);
    OutputDebugStringW(buff);
    auto ret = [[NSString alloc] initWithBytes:buff length:len * 2 encoding:NSUnicodeStringEncoding];

    if (free)
        WindowsDeleteString(str);

    return ret;
}

#define GET_STR(obj, getter)              \
    _stringFromHstring([&]() -> HSTRING { \
        HSTRING o;                        \
        obj->getter(&o);                  \
        return o;                         \
    }());
#define GET_NSTR(obj, getter) \
    _nsstringFromHstring(     \
        [&]() -> HSTRING {    \
            HSTRING o;        \
            obj->getter(&o);  \
            return o;         \
        }(),                  \
        true);

static ComPtr<ICurrentAppSimulator> getCurrentApp() {
    HSTRING className;
    WindowsCreateString(RuntimeClass_Windows_ApplicationModel_Store_CurrentAppSimulator,
                        wcslen(RuntimeClass_Windows_ApplicationModel_Store_CurrentAppSimulator),
                        &className);

    ComPtr<ICurrentAppSimulator> spCurrentApp;
    HRESULT hr = Windows::Foundation::GetActivationFactory(className, &spCurrentApp);
    assert(hr == S_OK);

    WindowsDeleteString(className);

    return spCurrentApp;
}

template <typename T>
class CompletionHandler : public IAsyncOperationCompletedHandler<T> {
    ULONG _ulRefs = 1;
    std::function<void(IAsyncOperation<T>*)> _func;

public:
    CompletionHandler(std::function<void(IAsyncOperation<T>*)> func) : _func(func) {
    }

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(_In_ REFIID id, _COM_Outptr_ void** ppv) {
        if (nullptr == ppv)
            return E_INVALIDARG;

        if (id == IID_IUnknown)
            *ppv = this;
        else if (id == __uuidof(IAsyncOperationCompletedHandler<T>))
            *ppv = static_cast<IAsyncOperationCompletedHandler<T>*>(this);
        else {
            *ppv = nullptr;
            return E_NOINTERFACE;
        }

        ((IUnknown*)(*ppv))->AddRef();

        return S_OK;
    }

    virtual ULONG STDMETHODCALLTYPE AddRef() {
        return InterlockedIncrement(&_ulRefs);
    }

    virtual ULONG STDMETHODCALLTYPE Release() {
        unsigned curr = InterlockedDecrement(&_ulRefs);
        if (curr == 0)
            delete this;

        return curr;
    }

    virtual HRESULT STDMETHODCALLTYPE Invoke(IAsyncOperation<T>* asyncInfo, AsyncStatus status) {
        _func(asyncInfo);
        return S_OK;
    }
};
