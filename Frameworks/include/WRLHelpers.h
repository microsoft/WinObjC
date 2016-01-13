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

#include "Starboard.h"
#include <utility>

#include <COMIncludes.h>
#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.foundation.h>
#include <windows.foundation.collections.h>
#include <COMIncludes_End.h>

namespace WRLHelpers {

namespace Private {

// Dispatcher class template declaration for generically working with WRL types
// Main issue is that ABI types will either be IFoo* or HSTRING or a few other
// value types. IFoo* and HSTRING have similar lifetime concerns but don't have a
// common type to work with them generically. This solves that by using a type that has a
// .Get() and .GetAddressOf() to get and assign to them.
template <typename T>
struct TypeTraits;

template <class Q>
struct TypeTraits<Q*> {
    using type = Microsoft::WRL::ComPtr<Q>;
};

template <>
struct TypeTraits<HSTRING> {
    using type = Microsoft::WRL::Wrappers::HString;
};
}

// Helps with iterating an iterable container (like a vector, map, etc.)  Calls a functor on each
// element in the iterable range with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IIterable<T>* iterable, Q&& functor) {
    boolean more;
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterator<T>> iter;

    RETURN_IF_FAILED(iterable->First(&iter));
    RETURN_IF_FAILED(iter->get_HasCurrent(&more));

    while (more) {
        boolean stop = false;
        typename Private::TypeTraits<T>::type current;

        RETURN_IF_FAILED(iter->get_Current(current.GetAddressOf()));

        RETURN_IF_FAILED(functor(current.Get(), &stop));

        if (stop) {
            break;
        }

        RETURN_IF_FAILED(iter->MoveNext(&more));
    }

    return S_OK;
}

// Helps with iterating an IVector<T>. Calls a functor on each element with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IVector<T>* vector, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<T>> iter;

    RETURN_IF_FAILED(vector->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IVectorView<T>. Calls a functor on each element with the value it found.
template <typename T, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IVectorView<T>* vector, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<T>> iter;

    RETURN_IF_FAILED(vector->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating collections.  Calls a functor on each element with the value it found.
// Required because the other overloads take M*, but ComPtr<M> has no implicit conversion to M*.
template <typename T, typename Q>
HRESULT ForEach(const Microsoft::WRL::ComPtr<T>& source, Q&& functor) {
    return ForEach(source.Get(), functor);
}

// Helps with iterating an IPropertySet. Calls a functor on each element with the value it found.
template <typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IPropertySet* propertySet, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<
        ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING, IInspectable*>*>> iter;

    RETURN_IF_FAILED(propertySet->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IMapView. Calls a functor on each element with the value it found.
template <typename K, typename V, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IMapView<K, V>* mapView, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<K, V>*>>
        iter;

    RETURN_IF_FAILED(mapView->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}

// Helps with iterating an IMap. Calls a functor on each element with the value it found.
template <typename K, typename V, typename Q>
HRESULT ForEach(ABI::Windows::Foundation::Collections::IMap<K, V>* map, Q&& functor) {
    Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IIterable<ABI::Windows::Foundation::Collections::IKeyValuePair<K, V>*>>
        iter;

    RETURN_IF_FAILED(map->QueryInterface(IID_PPV_ARGS(&iter)));

    return ForEach(iter.Get(), std::forward<Q>(functor));
}
}