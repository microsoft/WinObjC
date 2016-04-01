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
// clang-format does not play well with C++/CX
// clang-format off

#pragma once

#ifdef __OBJC__
#include <COMIncludes.h>
#endif

#ifdef __cplusplus_winrt
#include <wrl.h>
#include <agile.h>
#endif

#include <wrl/client.h>

#ifdef __OBJC__
#include <COMIncludes_End.h>
#endif

namespace winobjc {

class Id {
public:
    Microsoft::WRL::ComPtr<IUnknown> _comPtr;

    Id() {
    }

    Id(IUnknown* ptr) : _comPtr(ptr) {
    }

    Id(Id&& copy) : _comPtr(copy._comPtr) {
    }

    Id(const decltype(_comPtr)& other) : _comPtr(other) {
    }

    Id& operator=(const decltype(_comPtr)& other) {
        _comPtr = other;
        return *this;
    }

    Id& operator=(const Id& val) {
        _comPtr = val._comPtr;
        return *this;
    }

    Id& operator=(IUnknown* ptr) {
        _comPtr = ptr;
        return *this;
    }

    Id& operator=(nullptr_t) {
        _comPtr = nullptr;
        return *this;
    }

#ifdef __OBJC__
    Id& operator=(id) = delete;
    Id(id) = delete;
#endif

#ifdef __cplusplus_winrt
    typedef Platform::Object^ ObjPtr;

    inline Id(Platform::Object^ obj) : _comPtr(reinterpret_cast<IUnknown*>(obj)) {
    }

    inline Id& operator=(Platform::Object^ obj) {
        _comPtr = reinterpret_cast<IUnknown*>(obj);
        return *this;
    }

    inline operator Platform::Object^() { return reinterpret_cast<Platform::Object^>(_comPtr.Get()); }
#endif

    inline operator IUnknown*() {
        return _comPtr.Get();
    }
};
}

// clang-format on
