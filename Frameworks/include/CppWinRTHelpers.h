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

#pragma once

#import <Foundation/Foundation.h>
#import "StringHelpers.h"
#import <utility>
#import <type_traits>

// Required for the propagation of exceptions across language boundaries
@interface NSException (WinRTInternal)
- (HRESULT)_hresult;
@end

// TODO: Make RTHelpers.h includable from Objective-C++ without these gymnastics
#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#endif
#include <UWP/RTHelpers.h>
#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#endif

#include "COMIncludes.h"
#import <winrt/Windows.Foundation.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <wrl/client.h>
#include "COMIncludes_End.h"

// C++/WinRT types have a default constructor that instantiates the underlying object,
// and another constructor that takes nullptr_t and doesn't instantiate the underlying
// object. This is problematic when C++/WinRT objects are fields in an Objective-C
// class, because Objective-C class fields can only be constructed using the default
// constructor, which is often not what you want. Therefore, this type exists to wrap
// a C++/WinRT type and forward the default constructor to the (nullptr_t) constructor.
template <typename T>
class TrivialDefaultConstructor : public T {
public:
    TrivialDefaultConstructor() : T(nullptr) { }

    auto operator=(const T& other) {
        return T::operator=(other);
    }

    auto operator=(T&& other) {
        return T::operator=(std::forward<T>(other));
    }
};

namespace objcwinrt {

//
// Convert to and from IInspectable
//

// Returns an object's underlying IInspectable*.
// Return value is not AddRef'ed.
template <typename T>
IInspectable* to_insp(const T& t) {
    return reinterpret_cast<IInspectable*>(
        static_cast<winrt::ABI::Windows::Foundation::IInspectable*>(
            winrt::get_abi(t)));
}

template <typename T>
IInspectable* to_insp(const TrivialDefaultConstructor<T>& t) {
    return to_insp(static_cast<const T&>(t));
}

template <typename T>
T from_insp(IInspectable* insp) {
    T retval = nullptr;
    winrt::ABI::default_interface<winrt::abi<T>>* retvalAbi;

    if (SUCCEEDED(insp->QueryInterface(IID_PPV_ARGS(&retvalAbi)))) {
        winrt::attach_abi(retval, retvalAbi);
    }

    return retval;
}

template <typename T>
T from_insp(const Microsoft::WRL::ComPtr<IInspectable>& insp) {
    return from_insp<T>(insp.Get());
}

//
// Convert to and from RTObject
//

template <typename T>
RTObject* to_rtobj(const T& t) {
    return _createBareRTObj(to_insp(t));
}

template <typename T>
T from_rtobj(RTObject* obj) {
    return from_insp<T>([obj comObj]);
}


//
// Convert strings back and forth
//

inline
winrt::hstring string(NSString* str) {
    auto hstr1 = Strings::NarrowToWide<HSTRING>(str);

    winrt::hstring hstr2;
    winrt::attach_abi(hstr2, hstr1.Detach());

    return hstr2;
}

inline
NSString* string(winrt::hstring_view str) {
    return [NSString _stringWithHSTRING:winrt::get_abi(str)];
}


//
// Generate IReference<T> instances
//

template <typename T>
winrt::Windows::Foundation::IReference<T> optional(T t) {
    static_assert(false, "objcwinrt::optional<T> not specialized");
}

template <>
inline
winrt::Windows::Foundation::IReference<double> optional<double>(double d) {
    auto ref = winrt::Windows::Foundation::PropertyValue::CreateDouble(d);
    return ref.as<winrt::Windows::Foundation::IReference<double>>();
}

template <>
inline
winrt::Windows::Foundation::IReference<float> optional<float>(float f) {
    auto ref = winrt::Windows::Foundation::PropertyValue::CreateSingle(f);
    return ref.as<winrt::Windows::Foundation::IReference<float>>();
}

template <>
inline
winrt::Windows::Foundation::IReference<int> optional<int>(int i) {
    auto ref = winrt::Windows::Foundation::PropertyValue::CreateInt32(i);
    return ref.as<winrt::Windows::Foundation::IReference<int>>();
}

template <>
inline
winrt::Windows::Foundation::IReference<unsigned int> optional<unsigned int>(unsigned int u) {
    auto ref = winrt::Windows::Foundation::PropertyValue::CreateUInt32(u);
    return ref.as<winrt::Windows::Foundation::IReference<unsigned int>>();
}

//
// Convert async status to NSError
//
template <typename TAsync>
NSError* to_nserror(const TAsync& async, winrt::Windows::Foundation::AsyncStatus status) {
    // Results are roughly compatible with what ObjCUWP projections do
    NSError* error = nil;

    switch (status) {
        case winrt::Windows::Foundation::AsyncStatus::Completed:
            // No error
            break;

        case winrt::Windows::Foundation::AsyncStatus::Error: {
            HRESULT hr = async.ErrorCode();

            // None of this "error: the operation succeeded" nonsense
            if (hr == S_OK) {
                hr = E_UNEXPECTED;
            }

            error = [NSError errorWithDomain:@"HRESULT" code:static_cast<NSInteger>(hr) userInfo:nil];
            break;
        }

        case winrt::Windows::Foundation::AsyncStatus::Canceled:
        default:
            error = [NSError errorWithDomain:@"Async" code:static_cast<NSInteger>(status) userInfo:nil];
            break;
    }

    return error;
}

//
// Callback wrapper
//
namespace impl {
    template <typename TCallable>
    class callback {
    public:
        callback(const TCallable& c) : _callback(c) { }
        callback(TCallable&& c) : _callback(std::forward<TCallable>(c)) { }
        callback(callback&& other) : _callback(std::move(other._callback)) { }

        // Make sure all callback operations are wrapped in an autorelease pool
        template <typename... TArgs>
        auto operator()(TArgs&& ...args) {
            @autoreleasepool {
#ifndef _M_ARM // !_M_ARM; TODO GH#352 ARM exception handling is currently broken
                @try {
                    return _callback(std::forward<TArgs>(args)...);
                } @catch(NSException* ex) {
                    // NSException has set the COM error info for us by virtue of it calling RoOriginateLanguageException.
                    throw winrt::hresult_error([ex _hresult], winrt::hresult_error::from_abi);
                }
#else // _M_ARM
                return _callback(std::forward<TArgs>(args)...);
#endif // _M_ARM
            }
        }

    private:
        TCallable _callback;
    };
}

template <typename TCallable>
impl::callback<std::remove_reference_t<TCallable>> callback(TCallable&& c) {
    return impl::callback<std::remove_reference_t<TCallable>>(std::forward<TCallable>(c));
}

}
