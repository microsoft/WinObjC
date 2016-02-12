//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#ifdef __OBJC__
#include "Starboard.h"

#import <Foundation/NSString.h>
#include <COMIncludes.h>

#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
#include <Windows.Foundation.Collections.h>
#include "WRLHelpers.h"
#include "StringHelpers.h"

#include <COMIncludes_End.h>

namespace Collections {
namespace Private {
template <typename T>
struct CollectionType {};

template <typename K, typename V>
struct CollectionType<ABI::Windows::Foundation::Collections::IMap<K, V>> {
    using NSEquivalentType = NSDictionary;
    using NSMutableEquivalentType = NSMutableDictionary;
};

template <typename T>
struct CollectionType<ABI::Windows::Foundation::Collections::IVector<T>> {
    using NSEquivalentType = NSArray;
    using NSMutableEquivalentType = NSMutableArray;
};
}

template <typename T>
static HRESULT WRLToNSCollection(T* collection, typename Private::CollectionType<T>::NSEquivalentType* __autoreleasing* pNSCollection) {
    static_assert(false, "cannot convert arbitrary collection");
}

template <>
HRESULT WRLToNSCollection<ABI::Windows::Foundation::Collections::IMap<HSTRING, HSTRING>>(
    ABI::Windows::Foundation::Collections::IMap<HSTRING, HSTRING>* map, NSDictionary* __autoreleasing* pDictionary) {
    using NSType = Private::CollectionType<ABI::Windows::Foundation::Collections::IMap<HSTRING, HSTRING>>::NSMutableEquivalentType;
    NSType* collection = [[NSType alloc] init];
    HRESULT hr = WRLHelpers::ForEach(
        map,
        [&collection](const Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING, HSTRING>>& pair,
                      boolean* stop) {
            Microsoft::WRL::Wrappers::HString key, value;
            RETURN_IF_FAILED(pair->get_Key(key.GetAddressOf()));
            RETURN_IF_FAILED(pair->get_Value(value.GetAddressOf()));

            [collection setObject:Strings::WideToNSString(value.Get()) forKey:Strings::WideToNSString(key.Get())];
            return S_OK;
        });
    RETURN_IF_FAILED(hr);

    *pDictionary = collection;
    return S_OK;
}

template <typename T>
HRESULT WRLToNSCollection(const Microsoft::WRL::ComPtr<T>& collection,
                          typename Private::CollectionType<T>::NSEquivalentType* __autoreleasing* pNSCollection) {
    return WRLToNSCollection(collection.Get(), pNSCollection);
}
#endif
}
