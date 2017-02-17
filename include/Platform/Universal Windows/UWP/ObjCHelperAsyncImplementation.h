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

#include "RTHelpers.h"
#import <Foundation/Foundation.h>

namespace ObjCAsync {
inline std::wstring getWString(const char* str) {
    int len = strlen(str);
    return std::wstring(&str[0], &str[len - 1]);
}

template<typename resultType, typename resultInterfaceType, bool = _is_COM_Object(resultInterfaceType)>
class AsyncOperationImpl :
    public RuntimeClass<
    RuntimeClassFlags<WinRtClassicComMix>,
    IAsyncOperation<resultType>,
    AsyncBase<IAsyncOperationCompletedHandler<resultType>>> {

    typedef RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
        IAsyncOperation<resultType>,
        AsyncBase<IAsyncOperationCompletedHandler<resultType>>> RuntimeClassT;

    // This will fail for double pointer (and higher level pointers), but we do not care so much about them.
    InspectableClass((std::wstring(L"Windows.Foundation.IAsyncOperation") + getWString(typeid(std::remove_pointer<resultType>).name())).c_str(), BaseTrust);
    
    resultInterfaceType _result;
public:
    AsyncOperationImpl()
    {
        Start();
    }
    IFACEMETHODIMP put_Completed(IAsyncOperationCompletedHandler<resultType> *pCompleteHandler) override
    {
        return AsyncBase::PutOnComplete(pCompleteHandler);
    }
    IFACEMETHODIMP get_Completed(IAsyncOperationCompletedHandler<resultType> **ppCompleteHandler) override
    {
        return AsyncBase::GetOnComplete(ppCompleteHandler);
    }
    void setResult(resultInterfaceType result)
    {
        _result = result;
        FireCompletion();
    }
    IFACEMETHODIMP GetResults(resultInterfaceType* results) override
    {
        *results = 0;
        HRESULT hr = AsyncBase::CheckValidStateForResultsCall();
        if (SUCCEEDED(hr))
        {
            *results = _result;
        }
        return hr;
    }
    HRESULT OnStart() override
    {
        return S_OK;
    }
    void OnClose() override {}
    void OnCancel() override {}
};

template<typename resultType, typename resultInterfaceType>
class AsyncOperationImpl<resultType, resultInterfaceType, true> :
    public RuntimeClass<
    RuntimeClassFlags<WinRtClassicComMix>,
    IAsyncOperation<resultType>,
    AsyncBase<IAsyncOperationCompletedHandler<resultType>>> {

    typedef RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
        IAsyncOperation<resultType>,
        AsyncBase<IAsyncOperationCompletedHandler<resultType>>> RuntimeClassT;

    // This will fail for double pointer (and higher level pointers), but we do not care so much about them.
    InspectableClass((std::wstring(L"Windows.Foundation.IAsyncOperation") + getWString(typeid(std::remove_pointer<resultType>).name())).c_str(), BaseTrust);

    ComPtr<typename std::remove_pointer<resultInterfaceType>::type> _result;
public:
    AsyncOperationImpl()
    {
        Start();
    }
    IFACEMETHODIMP put_Completed(IAsyncOperationCompletedHandler<resultType> *pCompleteHandler) override
    {
        return AsyncBase::PutOnComplete(pCompleteHandler);
    }
    IFACEMETHODIMP get_Completed(IAsyncOperationCompletedHandler<resultType> **ppCompleteHandler) override
    {
        return AsyncBase::GetOnComplete(ppCompleteHandler);
    }
    void setResult(resultInterfaceType result)
    {
        _result.Attach(result);
        FireCompletion();
    }
    IFACEMETHODIMP GetResults(resultInterfaceType* results) override
    {
        *results = 0;
        HRESULT hr = AsyncBase::CheckValidStateForResultsCall();
        if (SUCCEEDED(hr))
        {
            // Implicit AddRef
            ComPtr<typename std::remove_pointer<resultInterfaceType>::type> ptr = _result;
            *results = ptr.Detach();
        }
        return hr;
    }
    HRESULT OnStart() override
    {
        return S_OK;
    }
    void OnClose() override {}
    void OnCancel() override {}
};
}