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
#import <UWP/InteropBase.h>
#include <COMIncludes.h>

#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
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

template <>
struct CollectionType<ABI::Windows::Foundation::Collections::IPropertySet> {
    using NSEquivalentType = NSDictionary;
    using NSMutableEquivalentType = NSMutableDictionary;
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

// Specified for converting IPropertyValue of String to NSString for Toast Action conversion
// TODO 8218419: Cannot currently consume values in Objective C projection without first converting to IPropertyValue
template <>
HRESULT WRLToNSCollection<ABI::Windows::Foundation::Collections::IPropertySet>(ABI::Windows::Foundation::Collections::IPropertySet* map,
                                                                               NSDictionary* __autoreleasing* pDictionary) {
    using NSType = Private::CollectionType<ABI::Windows::Foundation::Collections::IPropertySet>::NSMutableEquivalentType;
    NSType* collection = [[NSType alloc] init];
    RETURN_IF_FAILED(WRLHelpers::ForEach(
        map,
        [&collection](const Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING, IInspectable*>>& pair,
                      boolean* stop) {
            Microsoft::WRL::Wrappers::HString key;
            RETURN_IF_FAILED(pair->get_Key(key.GetAddressOf()));

            Microsoft::WRL::ComPtr<IInspectable> inspectableValue;
            RETURN_IF_FAILED(pair->get_Value(inspectableValue.GetAddressOf()));

            Microsoft::WRL::ComPtr<ABI::Windows::Foundation::IPropertyValue> propertyValue;
            RETURN_IF_FAILED(inspectableValue.As(&propertyValue));

            Microsoft::WRL::Wrappers::HString value;
            RETURN_IF_FAILED(propertyValue->GetString(value.GetAddressOf()));

            [collection setObject:Strings::WideToNSString(value.Get()) forKey:Strings::WideToNSString(key.Get())];
            return S_OK;
        }));

    *pDictionary = [collection autorelease];
    return S_OK;
}

template <typename T>
HRESULT WRLToNSCollection(const Microsoft::WRL::ComPtr<T>& collection,
                          typename Private::CollectionType<T>::NSEquivalentType* __autoreleasing* pNSCollection) {
    return WRLToNSCollection(collection.Get(), pNSCollection);
}

#endif
}
