// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Data.Json.3.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Json::IJsonArray> : produce_base<D, Windows::Data::Json::IJsonArray>
{
    HRESULT __stdcall abi_GetObjectAt(uint32_t index, impl::abi_arg_out<Windows::Data::Json::IJsonObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetObjectAt(index));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetArrayAt(uint32_t index, impl::abi_arg_out<Windows::Data::Json::IJsonArray> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetArrayAt(index));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStringAt(uint32_t index, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetStringAt(index));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNumberAt(uint32_t index, double * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNumberAt(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBooleanAt(uint32_t index, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBooleanAt(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonArrayStatics> : produce_base<D, Windows::Data::Json::IJsonArrayStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonArray> jsonArray) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonArray = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *jsonArray = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonArray> result, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *result));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonErrorStatics2> : produce_base<D, Windows::Data::Json::IJsonErrorStatics2>
{
    HRESULT __stdcall abi_GetJsonStatus(int32_t hresult, Windows::Data::Json::JsonErrorStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetJsonStatus(hresult));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonObject> : produce_base<D, Windows::Data::Json::IJsonObject>
{
    HRESULT __stdcall abi_GetNamedValue(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Json::IJsonValue> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedValue(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNamedValue(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Data::Json::IJsonValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNamedValue(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Data::Json::IJsonValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedObject(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Json::IJsonObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedObject(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedArray(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Json::IJsonArray> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedArray(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedString(impl::abi_arg_in<hstring> name, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedString(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedNumber(impl::abi_arg_in<hstring> name, double * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedNumber(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedBoolean(impl::abi_arg_in<hstring> name, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedBoolean(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonObjectStatics> : produce_base<D, Windows::Data::Json::IJsonObjectStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonObject> jsonObject) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonObject = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *jsonObject = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonObject> result, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *result));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonObjectWithDefaultValues> : produce_base<D, Windows::Data::Json::IJsonObjectWithDefaultValues>
{
    HRESULT __stdcall abi_GetNamedValueOrDefault(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Data::Json::IJsonValue> defaultValue, impl::abi_arg_out<Windows::Data::Json::IJsonValue> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedValue(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Data::Json::JsonValue *>(&defaultValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedObjectOrDefault(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Data::Json::IJsonObject> defaultValue, impl::abi_arg_out<Windows::Data::Json::IJsonObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedObject(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Data::Json::JsonObject *>(&defaultValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedStringOrDefault(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> defaultValue, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedString(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&defaultValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedArrayOrDefault(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Data::Json::IJsonArray> defaultValue, impl::abi_arg_out<Windows::Data::Json::IJsonArray> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedArray(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Data::Json::JsonArray *>(&defaultValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedNumberOrDefault(impl::abi_arg_in<hstring> name, double defaultValue, double * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedNumber(*reinterpret_cast<const hstring *>(&name), defaultValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedBooleanOrDefault(impl::abi_arg_in<hstring> name, bool defaultValue, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNamedBoolean(*reinterpret_cast<const hstring *>(&name), defaultValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonValue> : produce_base<D, Windows::Data::Json::IJsonValue>
{
    HRESULT __stdcall get_ValueType(Windows::Data::Json::JsonValueType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValueType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stringify(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Stringify());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetString(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetString());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNumber(double * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoolean(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBoolean());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetArray(impl::abi_arg_out<Windows::Data::Json::IJsonArray> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetArray());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetObject(impl::abi_arg_out<Windows::Data::Json::IJsonObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetObject());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonValueStatics> : produce_base<D, Windows::Data::Json::IJsonValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonValue> jsonValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *jsonValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonValue> result, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *result));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBooleanValue(bool input, impl::abi_arg_out<Windows::Data::Json::IJsonValue> jsonValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonValue = detach_abi(this->shim().CreateBooleanValue(input));
            return S_OK;
        }
        catch (...)
        {
            *jsonValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateNumberValue(double input, impl::abi_arg_out<Windows::Data::Json::IJsonValue> jsonValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonValue = detach_abi(this->shim().CreateNumberValue(input));
            return S_OK;
        }
        catch (...)
        {
            *jsonValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStringValue(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Data::Json::IJsonValue> jsonValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonValue = detach_abi(this->shim().CreateStringValue(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *jsonValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Json::IJsonValueStatics2> : produce_base<D, Windows::Data::Json::IJsonValueStatics2>
{
    HRESULT __stdcall abi_CreateNullValue(impl::abi_arg_out<Windows::Data::Json::IJsonValue> jsonValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *jsonValue = detach_abi(this->shim().CreateNullValue());
            return S_OK;
        }
        catch (...)
        {
            *jsonValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Json {

template <typename D> Windows::Data::Json::JsonValueType impl_IJsonValue<D>::ValueType() const
{
    Windows::Data::Json::JsonValueType value {};
    check_hresult(WINRT_SHIM(IJsonValue)->get_ValueType(&value));
    return value;
}

template <typename D> hstring impl_IJsonValue<D>::Stringify() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IJsonValue)->abi_Stringify(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IJsonValue<D>::GetString() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IJsonValue)->abi_GetString(put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_IJsonValue<D>::GetNumber() const
{
    double returnValue {};
    check_hresult(WINRT_SHIM(IJsonValue)->abi_GetNumber(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IJsonValue<D>::GetBoolean() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IJsonValue)->abi_GetBoolean(&returnValue));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonArray impl_IJsonValue<D>::GetArray() const
{
    Windows::Data::Json::JsonArray returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValue)->abi_GetArray(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonObject impl_IJsonValue<D>::GetObject() const
{
    Windows::Data::Json::JsonObject returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValue)->abi_GetObject(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Data::Json::JsonValue jsonValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValueStatics)->abi_Parse(get_abi(input), put_abi(jsonValue)));
    return jsonValue;
}

template <typename D> bool impl_IJsonValueStatics<D>::TryParse(hstring_view input, Windows::Data::Json::JsonValue & result) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IJsonValueStatics)->abi_TryParse(get_abi(input), put_abi(result), &succeeded));
    return succeeded;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonValueStatics<D>::CreateBooleanValue(bool input) const
{
    Windows::Data::Json::JsonValue jsonValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValueStatics)->abi_CreateBooleanValue(input, put_abi(jsonValue)));
    return jsonValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonValueStatics<D>::CreateNumberValue(double input) const
{
    Windows::Data::Json::JsonValue jsonValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValueStatics)->abi_CreateNumberValue(input, put_abi(jsonValue)));
    return jsonValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonValueStatics<D>::CreateStringValue(hstring_view input) const
{
    Windows::Data::Json::JsonValue jsonValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValueStatics)->abi_CreateStringValue(get_abi(input), put_abi(jsonValue)));
    return jsonValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonValueStatics2<D>::CreateNullValue() const
{
    Windows::Data::Json::JsonValue jsonValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonValueStatics2)->abi_CreateNullValue(put_abi(jsonValue)));
    return jsonValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonObject<D>::GetNamedValue(hstring_view name) const
{
    Windows::Data::Json::JsonValue returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedValue(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IJsonObject<D>::SetNamedValue(hstring_view name, const Windows::Data::Json::IJsonValue & value) const
{
    check_hresult(WINRT_SHIM(IJsonObject)->abi_SetNamedValue(get_abi(name), get_abi(value)));
}

template <typename D> Windows::Data::Json::JsonObject impl_IJsonObject<D>::GetNamedObject(hstring_view name) const
{
    Windows::Data::Json::JsonObject returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedObject(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonArray impl_IJsonObject<D>::GetNamedArray(hstring_view name) const
{
    Windows::Data::Json::JsonArray returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedArray(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IJsonObject<D>::GetNamedString(hstring_view name) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedString(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_IJsonObject<D>::GetNamedNumber(hstring_view name) const
{
    double returnValue {};
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedNumber(get_abi(name), &returnValue));
    return returnValue;
}

template <typename D> bool impl_IJsonObject<D>::GetNamedBoolean(hstring_view name) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IJsonObject)->abi_GetNamedBoolean(get_abi(name), &returnValue));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonValue impl_IJsonObjectWithDefaultValues<D>::GetNamedValue(hstring_view name, const Windows::Data::Json::JsonValue & defaultValue) const
{
    Windows::Data::Json::JsonValue returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedValueOrDefault(get_abi(name), get_abi(defaultValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonObject impl_IJsonObjectWithDefaultValues<D>::GetNamedObject(hstring_view name, const Windows::Data::Json::JsonObject & defaultValue) const
{
    Windows::Data::Json::JsonObject returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedObjectOrDefault(get_abi(name), get_abi(defaultValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IJsonObjectWithDefaultValues<D>::GetNamedString(hstring_view name, hstring_view defaultValue) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedStringOrDefault(get_abi(name), get_abi(defaultValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonArray impl_IJsonObjectWithDefaultValues<D>::GetNamedArray(hstring_view name, const Windows::Data::Json::JsonArray & defaultValue) const
{
    Windows::Data::Json::JsonArray returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedArrayOrDefault(get_abi(name), get_abi(defaultValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_IJsonObjectWithDefaultValues<D>::GetNamedNumber(hstring_view name, double defaultValue) const
{
    double returnValue {};
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedNumberOrDefault(get_abi(name), defaultValue, &returnValue));
    return returnValue;
}

template <typename D> bool impl_IJsonObjectWithDefaultValues<D>::GetNamedBoolean(hstring_view name, bool defaultValue) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IJsonObjectWithDefaultValues)->abi_GetNamedBooleanOrDefault(get_abi(name), defaultValue, &returnValue));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonObject impl_IJsonObjectStatics<D>::Parse(hstring_view input) const
{
    Windows::Data::Json::JsonObject jsonObject { nullptr };
    check_hresult(WINRT_SHIM(IJsonObjectStatics)->abi_Parse(get_abi(input), put_abi(jsonObject)));
    return jsonObject;
}

template <typename D> bool impl_IJsonObjectStatics<D>::TryParse(hstring_view input, Windows::Data::Json::JsonObject & result) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IJsonObjectStatics)->abi_TryParse(get_abi(input), put_abi(result), &succeeded));
    return succeeded;
}

template <typename D> Windows::Data::Json::JsonObject impl_IJsonArray<D>::GetObjectAt(uint32_t index) const
{
    Windows::Data::Json::JsonObject returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonArray)->abi_GetObjectAt(index, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonArray impl_IJsonArray<D>::GetArrayAt(uint32_t index) const
{
    Windows::Data::Json::JsonArray returnValue { nullptr };
    check_hresult(WINRT_SHIM(IJsonArray)->abi_GetArrayAt(index, put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IJsonArray<D>::GetStringAt(uint32_t index) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IJsonArray)->abi_GetStringAt(index, put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_IJsonArray<D>::GetNumberAt(uint32_t index) const
{
    double returnValue {};
    check_hresult(WINRT_SHIM(IJsonArray)->abi_GetNumberAt(index, &returnValue));
    return returnValue;
}

template <typename D> bool impl_IJsonArray<D>::GetBooleanAt(uint32_t index) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IJsonArray)->abi_GetBooleanAt(index, &returnValue));
    return returnValue;
}

template <typename D> Windows::Data::Json::JsonArray impl_IJsonArrayStatics<D>::Parse(hstring_view input) const
{
    Windows::Data::Json::JsonArray jsonArray { nullptr };
    check_hresult(WINRT_SHIM(IJsonArrayStatics)->abi_Parse(get_abi(input), put_abi(jsonArray)));
    return jsonArray;
}

template <typename D> bool impl_IJsonArrayStatics<D>::TryParse(hstring_view input, Windows::Data::Json::JsonArray & result) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IJsonArrayStatics)->abi_TryParse(get_abi(input), put_abi(result), &succeeded));
    return succeeded;
}

template <typename D> Windows::Data::Json::JsonErrorStatus impl_IJsonErrorStatics2<D>::GetJsonStatus(int32_t hresult) const
{
    Windows::Data::Json::JsonErrorStatus status {};
    check_hresult(WINRT_SHIM(IJsonErrorStatics2)->abi_GetJsonStatus(hresult, &status));
    return status;
}

inline JsonArray::JsonArray() :
    JsonArray(activate_instance<JsonArray>())
{}

inline Windows::Data::Json::JsonArray JsonArray::Parse(hstring_view input)
{
    return get_activation_factory<JsonArray, IJsonArrayStatics>().Parse(input);
}

inline bool JsonArray::TryParse(hstring_view input, Windows::Data::Json::JsonArray & result)
{
    return get_activation_factory<JsonArray, IJsonArrayStatics>().TryParse(input, result);
}

inline Windows::Data::Json::JsonErrorStatus JsonError::GetJsonStatus(int32_t hresult)
{
    return get_activation_factory<JsonError, IJsonErrorStatics2>().GetJsonStatus(hresult);
}

inline JsonObject::JsonObject() :
    JsonObject(activate_instance<JsonObject>())
{}

inline Windows::Data::Json::JsonObject JsonObject::Parse(hstring_view input)
{
    return get_activation_factory<JsonObject, IJsonObjectStatics>().Parse(input);
}

inline bool JsonObject::TryParse(hstring_view input, Windows::Data::Json::JsonObject & result)
{
    return get_activation_factory<JsonObject, IJsonObjectStatics>().TryParse(input, result);
}

inline Windows::Data::Json::JsonValue JsonValue::Parse(hstring_view input)
{
    return get_activation_factory<JsonValue, IJsonValueStatics>().Parse(input);
}

inline bool JsonValue::TryParse(hstring_view input, Windows::Data::Json::JsonValue & result)
{
    return get_activation_factory<JsonValue, IJsonValueStatics>().TryParse(input, result);
}

inline Windows::Data::Json::JsonValue JsonValue::CreateBooleanValue(bool input)
{
    return get_activation_factory<JsonValue, IJsonValueStatics>().CreateBooleanValue(input);
}

inline Windows::Data::Json::JsonValue JsonValue::CreateNumberValue(double input)
{
    return get_activation_factory<JsonValue, IJsonValueStatics>().CreateNumberValue(input);
}

inline Windows::Data::Json::JsonValue JsonValue::CreateStringValue(hstring_view input)
{
    return get_activation_factory<JsonValue, IJsonValueStatics>().CreateStringValue(input);
}

inline Windows::Data::Json::JsonValue JsonValue::CreateNullValue()
{
    return get_activation_factory<JsonValue, IJsonValueStatics2>().CreateNullValue();
}

}

}
#pragma warning(pop)
