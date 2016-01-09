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

#ifdef __cplusplus_winrt
#include <wrl.h>
#include <wrl/client.h>
#include <agile.h>
#endif

#ifndef IWEXPORT
#ifndef OBJCRT_EXPORT
#define IWEXPORT __declspec(dllimport)
#else
#define IWEXPORT OBJCRT_EXPORT
#endif
#endif

#ifdef __cplusplus_winrt
IWEXPORT extern "C" void IWRunApplicationMain(Platform::String ^ principalClassName,
                                              Platform::String ^ delegateClassName,
                                              float windowWidth,
                                              float windowHeight);
IWEXPORT extern "C" void IWSetXamlRoot(Windows::UI::Xaml::Controls::Grid ^ grid);
IWEXPORT extern "C" Windows::UI::Xaml::Controls::SwapChainPanel ^ IWSetSwapChainTarget(Windows::UI::Xaml::Controls::SwapChainPanel ^ panel);
#endif
namespace winobjc {
#ifdef __cplusplus_winrt
MIDL_INTERFACE("E7A2DBED-6156-463E-ADDC-017D4DD43726")
IIWSendMsg : public IInspectable {
public:
    virtual HRESULT STDMETHODCALLTYPE MsgSend(const char* str, ...) = 0;
};
#endif

class Id {
public:
    void* _idPtr;

    IWEXPORT void Set(void* idPtr);
    IWEXPORT Id();
    IWEXPORT Id(void* idPtr);
    IWEXPORT Id(Id&& copy);
    IWEXPORT ~Id();
    IWEXPORT Id& operator=(const Id& val);

#ifdef __OBJC__
    inline operator id() {
        return (id)_idPtr;
    }
#endif
#ifdef __cplusplus_winrt
    typedef Platform::Object ^ ObjPtr;
    inline Id(Platform::Object ^ obj) {
        _idPtr = NULL;
        Set((void*)obj);
    }
    inline Id& operator=(Platform::Object ^ val) {
        Set((void*)val);
        return *this;
    }
    inline operator Platform::Object ^() { return *((ObjPtr*)&_idPtr); } inline operator IIWSendMsg*() {
        return (IIWSendMsg*)*((ObjPtr*)&_idPtr);
    }
    inline IIWSendMsg* operator->() {
        return (IIWSendMsg*)*((ObjPtr*)&_idPtr);
    }
#endif
};

#if 0
    //  [TODO: Make public WinRT interfaces]
    public interface class IIWRecvMsgArgs
    {
        Platform::Object ^PullObject();
        IIWSendMsg ^PullId();
        uint32 PullUInt32();
    };
    public interface class IIWRecvMsg
    {
        Platform::Object ^MsgReceive(Platform::String ^selName, IIWRecvMsgArgs ^args);
    };
#endif
}
