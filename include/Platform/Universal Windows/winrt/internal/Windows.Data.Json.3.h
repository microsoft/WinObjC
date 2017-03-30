// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Json.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Json {

struct WINRT_EBO JsonArray :
    Windows::Data::Json::IJsonArray,
    impl::require<JsonArray, Windows::Foundation::IStringable, Windows::Foundation::Collections::IVector<Windows::Data::Json::IJsonValue>, Windows::Foundation::Collections::IIterable<Windows::Data::Json::IJsonValue>>
{
    JsonArray(std::nullptr_t) noexcept {}
    JsonArray();
    static Windows::Data::Json::JsonArray Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Data::Json::JsonArray & result);
};

struct JsonError
{
    JsonError() = delete;
    static Windows::Data::Json::JsonErrorStatus GetJsonStatus(int32_t hresult);
};

struct WINRT_EBO JsonObject :
    Windows::Data::Json::IJsonObject,
    impl::require<JsonObject, Windows::Foundation::IStringable, Windows::Data::Json::IJsonObjectWithDefaultValues, Windows::Foundation::Collections::IMap<hstring, Windows::Data::Json::IJsonValue>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Data::Json::IJsonValue>>>
{
    JsonObject(std::nullptr_t) noexcept {}
    JsonObject();
    using impl_IJsonObject::GetNamedArray;
    using impl_IJsonObject::GetNamedBoolean;
    using impl_IJsonObject::GetNamedNumber;
    using impl_IJsonObject::GetNamedObject;
    using impl_IJsonObject::GetNamedString;
    using impl_IJsonObject::GetNamedValue;
    using impl_IJsonObjectWithDefaultValues::GetNamedArray;
    using impl_IJsonObjectWithDefaultValues::GetNamedBoolean;
    using impl_IJsonObjectWithDefaultValues::GetNamedNumber;
    using impl_IJsonObjectWithDefaultValues::GetNamedObject;
    using impl_IJsonObjectWithDefaultValues::GetNamedString;
    using impl_IJsonObjectWithDefaultValues::GetNamedValue;
    static Windows::Data::Json::JsonObject Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Data::Json::JsonObject & result);
};

struct WINRT_EBO JsonValue :
    Windows::Data::Json::IJsonValue,
    impl::require<JsonValue, Windows::Foundation::IStringable>
{
    JsonValue(std::nullptr_t) noexcept {}
    static Windows::Data::Json::JsonValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Data::Json::JsonValue & result);
    static Windows::Data::Json::JsonValue CreateBooleanValue(bool input);
    static Windows::Data::Json::JsonValue CreateNumberValue(double input);
    static Windows::Data::Json::JsonValue CreateStringValue(hstring_view input);
    static Windows::Data::Json::JsonValue CreateNullValue();
};

}

}
