// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.DirectX.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.Graphics.Effects.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "Windows.UI.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Graphics.Effects.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Composition::IAmbientLight> : produce_base<D, Windows::UI::Composition::IAmbientLight>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IColorKeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IColorKeyFrameAnimation>
{
    HRESULT __stdcall get_InterpolationColorSpace(Windows::UI::Composition::CompositionColorSpace * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterpolationColorSpace());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InterpolationColorSpace(Windows::UI::Composition::CompositionColorSpace value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InterpolationColorSpace(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<Windows::UI::Color> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::UI::Color *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionAnimation> : produce_base<D, Windows::UI::Composition::ICompositionAnimation>
{
    HRESULT __stdcall abi_ClearAllParameters() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAllParameters();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearParameter(impl::abi_arg_in<hstring> key) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearParameter(*reinterpret_cast<const hstring *>(&key));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetColorParameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorParameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetMatrix3x2Parameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrix3x2Parameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetMatrix4x4Parameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrix4x4Parameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::float4x4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetQuaternionParameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetQuaternionParameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetReferenceParameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::UI::Composition::ICompositionObject> compositionObject) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetReferenceParameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::UI::Composition::CompositionObject *>(&compositionObject));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetScalarParameter(impl::abi_arg_in<hstring> key, float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetScalarParameter(*reinterpret_cast<const hstring *>(&key), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVector2Parameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector2Parameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVector3Parameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector3Parameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVector4Parameter(impl::abi_arg_in<hstring> key, impl::abi_arg_in<Windows::Foundation::Numerics::float4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector4Parameter(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const Windows::Foundation::Numerics::float4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionAnimation2> : produce_base<D, Windows::UI::Composition::ICompositionAnimation2>
{
    HRESULT __stdcall abi_SetBooleanParameter(impl::abi_arg_in<hstring> key, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBooleanParameter(*reinterpret_cast<const hstring *>(&key), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Target(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Target());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Target(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Target(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionAnimationBase> : produce_base<D, Windows::UI::Composition::ICompositionAnimationBase>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionAnimationFactory> : produce_base<D, Windows::UI::Composition::ICompositionAnimationFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionAnimationGroup> : produce_base<D, Windows::UI::Composition::ICompositionAnimationGroup>
{
    HRESULT __stdcall get_Count(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Count());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::UI::Composition::CompositionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::UI::Composition::CompositionAnimation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionBackdropBrush> : produce_base<D, Windows::UI::Composition::ICompositionBackdropBrush>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionBatchCompletedEventArgs> : produce_base<D, Windows::UI::Composition::ICompositionBatchCompletedEventArgs>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionBrush> : produce_base<D, Windows::UI::Composition::ICompositionBrush>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionBrushFactory> : produce_base<D, Windows::UI::Composition::ICompositionBrushFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionClip> : produce_base<D, Windows::UI::Composition::ICompositionClip>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionClip2> : produce_base<D, Windows::UI::Composition::ICompositionClip2>
{
    HRESULT __stdcall get_AnchorPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnchorPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AnchorPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngleInDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngleInDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngleInDegrees(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scale(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Scale(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformMatrix(impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransformMatrix(impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionClipFactory> : produce_base<D, Windows::UI::Composition::ICompositionClipFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionColorBrush> : produce_base<D, Windows::UI::Composition::ICompositionColorBrush>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionCommitBatch> : produce_base<D, Windows::UI::Composition::ICompositionCommitBatch>
{
    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnded(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnded());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionDrawingSurface> : produce_base<D, Windows::UI::Composition::ICompositionDrawingSurface>
{
    HRESULT __stdcall get_AlphaMode(Windows::Graphics::DirectX::DirectXAlphaMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlphaMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelFormat(Windows::Graphics::DirectX::DirectXPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEasingFunction> : produce_base<D, Windows::UI::Composition::ICompositionEasingFunction>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEasingFunctionFactory> : produce_base<D, Windows::UI::Composition::ICompositionEasingFunctionFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEffectBrush> : produce_base<D, Windows::UI::Composition::ICompositionEffectBrush>
{
    HRESULT __stdcall abi_GetSourceParameter(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSourceParameter(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSourceParameter(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSourceParameter(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEffectFactory> : produce_base<D, Windows::UI::Composition::ICompositionEffectFactory>
{
    HRESULT __stdcall abi_CreateBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionEffectBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LoadStatus(Windows::UI::Composition::CompositionEffectFactoryLoadStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LoadStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEffectSourceParameter> : produce_base<D, Windows::UI::Composition::ICompositionEffectSourceParameter>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionEffectSourceParameterFactory> : produce_base<D, Windows::UI::Composition::ICompositionEffectSourceParameterFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::UI::Composition::ICompositionEffectSourceParameter> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionGraphicsDevice> : produce_base<D, Windows::UI::Composition::ICompositionGraphicsDevice>
{
    HRESULT __stdcall abi_CreateDrawingSurface(impl::abi_arg_in<Windows::Foundation::Size> sizePixels, Windows::Graphics::DirectX::DirectXPixelFormat pixelFormat, Windows::Graphics::DirectX::DirectXAlphaMode alphaMode, impl::abi_arg_out<Windows::UI::Composition::ICompositionDrawingSurface> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDrawingSurface(*reinterpret_cast<const Windows::Foundation::Size *>(&sizePixels), pixelFormat, alphaMode));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RenderingDeviceReplaced(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Composition::CompositionGraphicsDevice, Windows::UI::Composition::RenderingDeviceReplacedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RenderingDeviceReplaced(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Composition::CompositionGraphicsDevice, Windows::UI::Composition::RenderingDeviceReplacedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RenderingDeviceReplaced(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RenderingDeviceReplaced(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionLight> : produce_base<D, Windows::UI::Composition::ICompositionLight>
{
    HRESULT __stdcall get_Targets(impl::abi_arg_out<Windows::UI::Composition::IVisualUnorderedCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Targets());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionLightFactory> : produce_base<D, Windows::UI::Composition::ICompositionLightFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionMaskBrush> : produce_base<D, Windows::UI::Composition::ICompositionMaskBrush>
{
    HRESULT __stdcall get_Mask(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mask());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mask(impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mask(*reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionNineGridBrush> : produce_base<D, Windows::UI::Composition::ICompositionNineGridBrush>
{
    HRESULT __stdcall get_BottomInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BottomInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BottomInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BottomInsetScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BottomInsetScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BottomInsetScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInsetScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCenterHollow(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCenterHollow());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCenterHollow(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCenterHollow(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LeftInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LeftInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LeftInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LeftInsetScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LeftInsetScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LeftInsetScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInsetScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RightInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RightInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RightInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RightInsetScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RightInsetScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RightInsetScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInsetScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TopInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TopInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TopInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TopInsetScale(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TopInsetScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TopInsetScale(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInsetScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetInsets(float inset) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsets(inset);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetInsetsWithValues(float left, float top, float right, float bottom) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsets(left, top, right, bottom);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetInsetScales(float scale) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsetScales(scale);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetInsetScalesWithValues(float left, float top, float right, float bottom) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsetScales(left, top, right, bottom);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionObject> : produce_base<D, Windows::UI::Composition::ICompositionObject>
{
    HRESULT __stdcall get_Compositor(impl::abi_arg_out<Windows::UI::Composition::ICompositor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Compositor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Dispatcher(impl::abi_arg_out<Windows::UI::Core::ICoreDispatcher> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Dispatcher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::UI::Composition::ICompositionPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAnimation(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimation> animation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimation(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::UI::Composition::CompositionAnimation *>(&animation));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAnimation(impl::abi_arg_in<hstring> propertyName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAnimation(*reinterpret_cast<const hstring *>(&propertyName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionObject2> : produce_base<D, Windows::UI::Composition::ICompositionObject2>
{
    HRESULT __stdcall get_Comment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Comment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Comment(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Comment(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImplicitAnimations(impl::abi_arg_out<Windows::UI::Composition::IImplicitAnimationCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImplicitAnimations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ImplicitAnimations(impl::abi_arg_in<Windows::UI::Composition::IImplicitAnimationCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImplicitAnimations(*reinterpret_cast<const Windows::UI::Composition::ImplicitAnimationCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAnimationGroup(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimationBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimationGroup(*reinterpret_cast<const Windows::UI::Composition::ICompositionAnimationBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAnimationGroup(impl::abi_arg_in<Windows::UI::Composition::ICompositionAnimationBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAnimationGroup(*reinterpret_cast<const Windows::UI::Composition::ICompositionAnimationBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionObjectFactory> : produce_base<D, Windows::UI::Composition::ICompositionObjectFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionPropertySet> : produce_base<D, Windows::UI::Composition::ICompositionPropertySet>
{
    HRESULT __stdcall abi_InsertColor(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertColor(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertMatrix3x2(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMatrix3x2(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertMatrix4x4(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMatrix4x4(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::float4x4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertQuaternion(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertQuaternion(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertScalar(impl::abi_arg_in<hstring> propertyName, float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertScalar(*reinterpret_cast<const hstring *>(&propertyName), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertVector2(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector2(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertVector3(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector3(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertVector4(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<Windows::Foundation::Numerics::float4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector4(*reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const Windows::Foundation::Numerics::float4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetColor(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::UI::Color> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetColor(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetMatrix3x2(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetMatrix3x2(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetMatrix4x4(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetMatrix4x4(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetQuaternion(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetQuaternion(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetScalar(impl::abi_arg_in<hstring> propertyName, float * value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetScalar(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetVector2(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::float2> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetVector2(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetVector3(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::float3> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetVector3(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetVector4(impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Numerics::float4> value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetVector4(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionPropertySet2> : produce_base<D, Windows::UI::Composition::ICompositionPropertySet2>
{
    HRESULT __stdcall abi_InsertBoolean(impl::abi_arg_in<hstring> propertyName, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertBoolean(*reinterpret_cast<const hstring *>(&propertyName), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetBoolean(impl::abi_arg_in<hstring> propertyName, bool * value, Windows::UI::Composition::CompositionGetValueStatus * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetBoolean(*reinterpret_cast<const hstring *>(&propertyName), *value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionScopedBatch> : produce_base<D, Windows::UI::Composition::ICompositionScopedBatch>
{
    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnded(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnded());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_End() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().End();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Suspend() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Suspend();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionShadow> : produce_base<D, Windows::UI::Composition::ICompositionShadow>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionShadowFactory> : produce_base<D, Windows::UI::Composition::ICompositionShadowFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionSurface> : produce_base<D, Windows::UI::Composition::ICompositionSurface>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionSurfaceBrush> : produce_base<D, Windows::UI::Composition::ICompositionSurfaceBrush>
{
    HRESULT __stdcall get_BitmapInterpolationMode(Windows::UI::Composition::CompositionBitmapInterpolationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapInterpolationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BitmapInterpolationMode(Windows::UI::Composition::CompositionBitmapInterpolationMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapInterpolationMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalAlignmentRatio(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalAlignmentRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HorizontalAlignmentRatio(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalAlignmentRatio(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Stretch(Windows::UI::Composition::CompositionStretch * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stretch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Stretch(Windows::UI::Composition::CompositionStretch value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stretch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Surface(impl::abi_arg_out<Windows::UI::Composition::ICompositionSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Surface());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Surface(impl::abi_arg_in<Windows::UI::Composition::ICompositionSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Surface(*reinterpret_cast<const Windows::UI::Composition::ICompositionSurface *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalAlignmentRatio(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalAlignmentRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VerticalAlignmentRatio(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VerticalAlignmentRatio(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionSurfaceBrush2> : produce_base<D, Windows::UI::Composition::ICompositionSurfaceBrush2>
{
    HRESULT __stdcall get_AnchorPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnchorPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AnchorPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngleInDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngleInDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngleInDegrees(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scale(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Scale(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformMatrix(impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransformMatrix(impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositionTarget> : produce_base<D, Windows::UI::Composition::ICompositionTarget>
{
    HRESULT __stdcall get_Root(impl::abi_arg_out<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Root());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Root(impl::abi_arg_in<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Root(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ICompositor> : produce_base<D, Windows::UI::Composition::ICompositor>
{
    HRESULT __stdcall abi_CreateColorKeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IColorKeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateColorKeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateColorBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionColorBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateColorBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateColorBrushWithColor(impl::abi_arg_in<Windows::UI::Color> color, impl::abi_arg_out<Windows::UI::Composition::ICompositionColorBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateColorBrush(*reinterpret_cast<const Windows::UI::Color *>(&color)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateContainerVisual(impl::abi_arg_out<Windows::UI::Composition::IContainerVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateContainerVisual());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCubicBezierEasingFunction(impl::abi_arg_in<Windows::Foundation::Numerics::float2> controlPoint1, impl::abi_arg_in<Windows::Foundation::Numerics::float2> controlPoint2, impl::abi_arg_out<Windows::UI::Composition::ICubicBezierEasingFunction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCubicBezierEasingFunction(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&controlPoint1), *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&controlPoint2)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateEffectFactory(impl::abi_arg_in<Windows::Graphics::Effects::IGraphicsEffect> graphicsEffect, impl::abi_arg_out<Windows::UI::Composition::ICompositionEffectFactory> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateEffectFactory(*reinterpret_cast<const Windows::Graphics::Effects::IGraphicsEffect *>(&graphicsEffect)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateEffectFactoryWithProperties(impl::abi_arg_in<Windows::Graphics::Effects::IGraphicsEffect> graphicsEffect, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> animatableProperties, impl::abi_arg_out<Windows::UI::Composition::ICompositionEffectFactory> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateEffectFactory(*reinterpret_cast<const Windows::Graphics::Effects::IGraphicsEffect *>(&graphicsEffect), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&animatableProperties)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateExpressionAnimation(impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateExpressionAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateExpressionAnimationWithExpression(impl::abi_arg_in<hstring> expression, impl::abi_arg_out<Windows::UI::Composition::IExpressionAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateExpressionAnimation(*reinterpret_cast<const hstring *>(&expression)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInsetClip(impl::abi_arg_out<Windows::UI::Composition::IInsetClip> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateInsetClip());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInsetClipWithInsets(float leftInset, float topInset, float rightInset, float bottomInset, impl::abi_arg_out<Windows::UI::Composition::IInsetClip> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateInsetClip(leftInset, topInset, rightInset, bottomInset));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateLinearEasingFunction(impl::abi_arg_out<Windows::UI::Composition::ILinearEasingFunction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateLinearEasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePropertySet(impl::abi_arg_out<Windows::UI::Composition::ICompositionPropertySet> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreatePropertySet());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateQuaternionKeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IQuaternionKeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateQuaternionKeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateScalarKeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IScalarKeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateScalarKeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateScopedBatch(Windows::UI::Composition::CompositionBatchTypes batchType, impl::abi_arg_out<Windows::UI::Composition::ICompositionScopedBatch> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateScopedBatch(batchType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSpriteVisual(impl::abi_arg_out<Windows::UI::Composition::ISpriteVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateSpriteVisual());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSurfaceBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionSurfaceBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateSurfaceBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSurfaceBrushWithSurface(impl::abi_arg_in<Windows::UI::Composition::ICompositionSurface> surface, impl::abi_arg_out<Windows::UI::Composition::ICompositionSurfaceBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateSurfaceBrush(*reinterpret_cast<const Windows::UI::Composition::ICompositionSurface *>(&surface)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTargetForCurrentView(impl::abi_arg_out<Windows::UI::Composition::ICompositionTarget> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateTargetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateVector2KeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IVector2KeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateVector2KeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateVector3KeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IVector3KeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateVector3KeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateVector4KeyFrameAnimation(impl::abi_arg_out<Windows::UI::Composition::IVector4KeyFrameAnimation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateVector4KeyFrameAnimation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCommitBatch(Windows::UI::Composition::CompositionBatchTypes batchType, impl::abi_arg_out<Windows::UI::Composition::ICompositionCommitBatch> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCommitBatch(batchType));
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
struct produce<D, Windows::UI::Composition::ICompositor2> : produce_base<D, Windows::UI::Composition::ICompositor2>
{
    HRESULT __stdcall abi_CreateAmbientLight(impl::abi_arg_out<Windows::UI::Composition::IAmbientLight> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateAmbientLight());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAnimationGroup(impl::abi_arg_out<Windows::UI::Composition::ICompositionAnimationGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateAnimationGroup());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBackdropBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionBackdropBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateBackdropBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDistantLight(impl::abi_arg_out<Windows::UI::Composition::IDistantLight> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDistantLight());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDropShadow(impl::abi_arg_out<Windows::UI::Composition::IDropShadow> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDropShadow());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateImplicitAnimationCollection(impl::abi_arg_out<Windows::UI::Composition::IImplicitAnimationCollection> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateImplicitAnimationCollection());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateLayerVisual(impl::abi_arg_out<Windows::UI::Composition::ILayerVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateLayerVisual());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateMaskBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionMaskBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateMaskBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateNineGridBrush(impl::abi_arg_out<Windows::UI::Composition::ICompositionNineGridBrush> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateNineGridBrush());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePointLight(impl::abi_arg_out<Windows::UI::Composition::IPointLight> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreatePointLight());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSpotLight(impl::abi_arg_out<Windows::UI::Composition::ISpotLight> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateSpotLight());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStepEasingFunction(impl::abi_arg_out<Windows::UI::Composition::IStepEasingFunction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateStepEasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStepEasingFunctionWithStepCount(int32_t stepCount, impl::abi_arg_out<Windows::UI::Composition::IStepEasingFunction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateStepEasingFunction(stepCount));
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
struct produce<D, Windows::UI::Composition::IContainerVisual> : produce_base<D, Windows::UI::Composition::IContainerVisual>
{
    HRESULT __stdcall get_Children(impl::abi_arg_out<Windows::UI::Composition::IVisualCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Children());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IContainerVisualFactory> : produce_base<D, Windows::UI::Composition::IContainerVisualFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ICubicBezierEasingFunction> : produce_base<D, Windows::UI::Composition::ICubicBezierEasingFunction>
{
    HRESULT __stdcall get_ControlPoint1(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlPoint1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ControlPoint2(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlPoint2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IDistantLight> : produce_base<D, Windows::UI::Composition::IDistantLight>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CoordinateSpace(impl::abi_arg_out<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSpace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CoordinateSpace(impl::abi_arg_in<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direction(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IDropShadow> : produce_base<D, Windows::UI::Composition::IDropShadow>
{
    HRESULT __stdcall get_BlurRadius(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BlurRadius());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BlurRadius(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlurRadius(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mask(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mask());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mask(impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mask(*reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opacity(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IExpressionAnimation> : produce_base<D, Windows::UI::Composition::IExpressionAnimation>
{
    HRESULT __stdcall get_Expression(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Expression());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Expression(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Expression(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IImplicitAnimationCollection> : produce_base<D, Windows::UI::Composition::IImplicitAnimationCollection>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::IInsetClip> : produce_base<D, Windows::UI::Composition::IInsetClip>
{
    HRESULT __stdcall get_BottomInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BottomInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BottomInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LeftInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LeftInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LeftInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RightInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RightInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RightInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TopInset(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TopInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TopInset(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IKeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IKeyFrameAnimation>
{
    HRESULT __stdcall get_DelayTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DelayTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DelayTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DelayTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IterationBehavior(Windows::UI::Composition::AnimationIterationBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IterationBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IterationBehavior(Windows::UI::Composition::AnimationIterationBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IterationBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IterationCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IterationCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IterationCount(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IterationCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyFrameCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrameCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StopBehavior(Windows::UI::Composition::AnimationStopBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StopBehavior());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StopBehavior(Windows::UI::Composition::AnimationStopBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopBehavior(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertExpressionKeyFrame(float normalizedProgressKey, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertExpressionKeyFrame(normalizedProgressKey, *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertExpressionKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<hstring> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertExpressionKeyFrame(normalizedProgressKey, *reinterpret_cast<const hstring *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IKeyFrameAnimation2> : produce_base<D, Windows::UI::Composition::IKeyFrameAnimation2>
{
    HRESULT __stdcall get_Direction(Windows::UI::Composition::AnimationDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(Windows::UI::Composition::AnimationDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IKeyFrameAnimationFactory> : produce_base<D, Windows::UI::Composition::IKeyFrameAnimationFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::ILayerVisual> : produce_base<D, Windows::UI::Composition::ILayerVisual>
{
    HRESULT __stdcall get_Effect(impl::abi_arg_out<Windows::UI::Composition::ICompositionEffectBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Effect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Effect(impl::abi_arg_in<Windows::UI::Composition::ICompositionEffectBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Effect(*reinterpret_cast<const Windows::UI::Composition::CompositionEffectBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ILinearEasingFunction> : produce_base<D, Windows::UI::Composition::ILinearEasingFunction>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::IPointLight> : produce_base<D, Windows::UI::Composition::IPointLight>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConstantAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConstantAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConstantAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConstantAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CoordinateSpace(impl::abi_arg_out<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSpace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CoordinateSpace(impl::abi_arg_in<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LinearAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinearAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LinearAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LinearAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QuadraticAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QuadraticAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_QuadraticAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuadraticAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IQuaternionKeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IQuaternionKeyFrameAnimation>
{
    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IRenderingDeviceReplacedEventArgs> : produce_base<D, Windows::UI::Composition::IRenderingDeviceReplacedEventArgs>
{
    HRESULT __stdcall get_GraphicsDevice(impl::abi_arg_out<Windows::UI::Composition::ICompositionGraphicsDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GraphicsDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IScalarKeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IScalarKeyFrameAnimation>
{
    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, float value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, value, *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ISpotLight> : produce_base<D, Windows::UI::Composition::ISpotLight>
{
    HRESULT __stdcall get_ConstantAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConstantAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConstantAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConstantAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CoordinateSpace(impl::abi_arg_out<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSpace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CoordinateSpace(impl::abi_arg_in<Windows::UI::Composition::IVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direction(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InnerConeAngle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InnerConeAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InnerConeAngle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InnerConeAngleInDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InnerConeAngleInDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InnerConeAngleInDegrees(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeAngleInDegrees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InnerConeColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InnerConeColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InnerConeColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LinearAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinearAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LinearAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LinearAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OuterConeAngle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OuterConeAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OuterConeAngle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OuterConeAngleInDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OuterConeAngleInDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OuterConeAngleInDegrees(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeAngleInDegrees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OuterConeColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OuterConeColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OuterConeColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QuadraticAttenuation(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QuadraticAttenuation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_QuadraticAttenuation(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuadraticAttenuation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ISpriteVisual> : produce_base<D, Windows::UI::Composition::ISpriteVisual>
{
    HRESULT __stdcall get_Brush(impl::abi_arg_out<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Brush());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Brush(impl::abi_arg_in<Windows::UI::Composition::ICompositionBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brush(*reinterpret_cast<const Windows::UI::Composition::CompositionBrush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::ISpriteVisual2> : produce_base<D, Windows::UI::Composition::ISpriteVisual2>
{
    HRESULT __stdcall get_Shadow(impl::abi_arg_out<Windows::UI::Composition::ICompositionShadow> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Shadow());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Shadow(impl::abi_arg_in<Windows::UI::Composition::ICompositionShadow> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shadow(*reinterpret_cast<const Windows::UI::Composition::CompositionShadow *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IStepEasingFunction> : produce_base<D, Windows::UI::Composition::IStepEasingFunction>
{
    HRESULT __stdcall get_FinalStep(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FinalStep());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FinalStep(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FinalStep(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InitialStep(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialStep());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InitialStep(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialStep(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFinalStepSingleFrame(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFinalStepSingleFrame());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsFinalStepSingleFrame(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFinalStepSingleFrame(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInitialStepSingleFrame(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInitialStepSingleFrame());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInitialStepSingleFrame(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInitialStepSingleFrame(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StepCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StepCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StepCount(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVector2KeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IVector2KeyFrameAnimation>
{
    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float2> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVector3KeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IVector3KeyFrameAnimation>
{
    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float3> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVector4KeyFrameAnimation> : produce_base<D, Windows::UI::Composition::IVector4KeyFrameAnimation>
{
    HRESULT __stdcall abi_InsertKeyFrame(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertKeyFrameWithEasingFunction(float normalizedProgressKey, impl::abi_arg_in<Windows::Foundation::Numerics::float4> value, impl::abi_arg_in<Windows::UI::Composition::ICompositionEasingFunction> easingFunction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<const Windows::Foundation::Numerics::float4 *>(&value), *reinterpret_cast<const Windows::UI::Composition::CompositionEasingFunction *>(&easingFunction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVisual> : produce_base<D, Windows::UI::Composition::IVisual>
{
    HRESULT __stdcall get_AnchorPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnchorPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AnchorPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackfaceVisibility(Windows::UI::Composition::CompositionBackfaceVisibility * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackfaceVisibility());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackfaceVisibility(Windows::UI::Composition::CompositionBackfaceVisibility value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackfaceVisibility(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BorderMode(Windows::UI::Composition::CompositionBorderMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BorderMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BorderMode(Windows::UI::Composition::CompositionBorderMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BorderMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CenterPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CenterPoint(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clip(impl::abi_arg_out<Windows::UI::Composition::ICompositionClip> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clip());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Clip(impl::abi_arg_in<Windows::UI::Composition::ICompositionClip> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clip(*reinterpret_cast<const Windows::UI::Composition::CompositionClip *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompositeMode(Windows::UI::Composition::CompositionCompositeMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositeMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompositeMode(Windows::UI::Composition::CompositionCompositeMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositeMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Offset(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opacity(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Orientation(impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Orientation(*reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parent(impl::abi_arg_out<Windows::UI::Composition::IContainerVisual> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAngleInDegrees(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngleInDegrees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAngleInDegrees(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationAxis(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAxis());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationAxis(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAxis(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scale(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Scale(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Size(impl::abi_arg_in<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformMatrix(impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransformMatrix(impl::abi_arg_in<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<const Windows::Foundation::Numerics::float4x4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVisualCollection> : produce_base<D, Windows::UI::Composition::IVisualCollection>
{
    HRESULT __stdcall get_Count(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Count());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertAbove(impl::abi_arg_in<Windows::UI::Composition::IVisual> newChild, impl::abi_arg_in<Windows::UI::Composition::IVisual> sibling) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAbove(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&newChild), *reinterpret_cast<const Windows::UI::Composition::Visual *>(&sibling));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertAtBottom(impl::abi_arg_in<Windows::UI::Composition::IVisual> newChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtBottom(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&newChild));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertAtTop(impl::abi_arg_in<Windows::UI::Composition::IVisual> newChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtTop(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&newChild));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertBelow(impl::abi_arg_in<Windows::UI::Composition::IVisual> newChild, impl::abi_arg_in<Windows::UI::Composition::IVisual> sibling) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertBelow(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&newChild), *reinterpret_cast<const Windows::UI::Composition::Visual *>(&sibling));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::UI::Composition::IVisual> child) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&child));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Composition::IVisualFactory> : produce_base<D, Windows::UI::Composition::IVisualFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Composition::IVisualUnorderedCollection> : produce_base<D, Windows::UI::Composition::IVisualUnorderedCollection>
{
    HRESULT __stdcall get_Count(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Count());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::UI::Composition::IVisual> newVisual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&newVisual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::UI::Composition::IVisual> visual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::UI::Composition::Visual *>(&visual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Composition {

template <typename D> Windows::UI::Color impl_IAmbientLight<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IAmbientLight)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IAmbientLight<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IAmbientLight)->put_Color(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionColorSpace impl_IColorKeyFrameAnimation<D>::InterpolationColorSpace() const
{
    Windows::UI::Composition::CompositionColorSpace value {};
    check_hresult(WINRT_SHIM(IColorKeyFrameAnimation)->get_InterpolationColorSpace(&value));
    return value;
}

template <typename D> void impl_IColorKeyFrameAnimation<D>::InterpolationColorSpace(Windows::UI::Composition::CompositionColorSpace value) const
{
    check_hresult(WINRT_SHIM(IColorKeyFrameAnimation)->put_InterpolationColorSpace(value));
}

template <typename D> void impl_IColorKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IColorKeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IColorKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::UI::Color & value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IColorKeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> void impl_ICompositionAnimation<D>::ClearAllParameters() const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_ClearAllParameters());
}

template <typename D> void impl_ICompositionAnimation<D>::ClearParameter(hstring_view key) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_ClearParameter(get_abi(key)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetColorParameter(hstring_view key, const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetColorParameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetMatrix3x2Parameter(hstring_view key, const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetMatrix3x2Parameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetMatrix4x4Parameter(hstring_view key, const Windows::Foundation::Numerics::float4x4 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetMatrix4x4Parameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetQuaternionParameter(hstring_view key, const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetQuaternionParameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetReferenceParameter(hstring_view key, const Windows::UI::Composition::CompositionObject & compositionObject) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetReferenceParameter(get_abi(key), get_abi(compositionObject)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetScalarParameter(hstring_view key, float value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetScalarParameter(get_abi(key), value));
}

template <typename D> void impl_ICompositionAnimation<D>::SetVector2Parameter(hstring_view key, const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetVector2Parameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetVector3Parameter(hstring_view key, const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetVector3Parameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation<D>::SetVector4Parameter(hstring_view key, const Windows::Foundation::Numerics::float4 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation)->abi_SetVector4Parameter(get_abi(key), get_abi(value)));
}

template <typename D> void impl_ICompositionAnimation2<D>::SetBooleanParameter(hstring_view key, bool value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation2)->abi_SetBooleanParameter(get_abi(key), value));
}

template <typename D> hstring impl_ICompositionAnimation2<D>::Target() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICompositionAnimation2)->get_Target(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionAnimation2<D>::Target(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimation2)->put_Target(get_abi(value)));
}

template <typename D> int32_t impl_ICompositionAnimationGroup<D>::Count() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICompositionAnimationGroup)->get_Count(&value));
    return value;
}

template <typename D> void impl_ICompositionAnimationGroup<D>::Add(const Windows::UI::Composition::CompositionAnimation & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimationGroup)->abi_Add(get_abi(value)));
}

template <typename D> void impl_ICompositionAnimationGroup<D>::Remove(const Windows::UI::Composition::CompositionAnimation & value) const
{
    check_hresult(WINRT_SHIM(ICompositionAnimationGroup)->abi_Remove(get_abi(value)));
}

template <typename D> void impl_ICompositionAnimationGroup<D>::RemoveAll() const
{
    check_hresult(WINRT_SHIM(ICompositionAnimationGroup)->abi_RemoveAll());
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionClip2<D>::AnchorPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_AnchorPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::AnchorPoint(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_AnchorPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionClip2<D>::CenterPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_CenterPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::CenterPoint(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_CenterPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionClip2<D>::Offset() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::Offset(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_Offset(get_abi(value)));
}

template <typename D> float impl_ICompositionClip2<D>::RotationAngle() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_RotationAngle(&value));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::RotationAngle(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_RotationAngle(value));
}

template <typename D> float impl_ICompositionClip2<D>::RotationAngleInDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_RotationAngleInDegrees(&value));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::RotationAngleInDegrees(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_RotationAngleInDegrees(value));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionClip2<D>::Scale() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_Scale(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::Scale(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_Scale(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3x2 impl_ICompositionClip2<D>::TransformMatrix() const
{
    Windows::Foundation::Numerics::float3x2 value {};
    check_hresult(WINRT_SHIM(ICompositionClip2)->get_TransformMatrix(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionClip2<D>::TransformMatrix(const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionClip2)->put_TransformMatrix(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_ICompositionColorBrush<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ICompositionColorBrush)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionColorBrush<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ICompositionColorBrush)->put_Color(get_abi(value)));
}

template <typename D> bool impl_ICompositionCommitBatch<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICompositionCommitBatch)->get_IsActive(&value));
    return value;
}

template <typename D> bool impl_ICompositionCommitBatch<D>::IsEnded() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICompositionCommitBatch)->get_IsEnded(&value));
    return value;
}

template <typename D> event_token impl_ICompositionCommitBatch<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompositionCommitBatch)->add_Completed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICompositionCommitBatch> impl_ICompositionCommitBatch<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICompositionCommitBatch>(this, &ABI::Windows::UI::Composition::ICompositionCommitBatch::remove_Completed, Completed(handler));
}

template <typename D> void impl_ICompositionCommitBatch<D>::Completed(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompositionCommitBatch)->remove_Completed(token));
}

template <typename D> Windows::Graphics::DirectX::DirectXAlphaMode impl_ICompositionDrawingSurface<D>::AlphaMode() const
{
    Windows::Graphics::DirectX::DirectXAlphaMode value {};
    check_hresult(WINRT_SHIM(ICompositionDrawingSurface)->get_AlphaMode(&value));
    return value;
}

template <typename D> Windows::Graphics::DirectX::DirectXPixelFormat impl_ICompositionDrawingSurface<D>::PixelFormat() const
{
    Windows::Graphics::DirectX::DirectXPixelFormat value {};
    check_hresult(WINRT_SHIM(ICompositionDrawingSurface)->get_PixelFormat(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ICompositionDrawingSurface<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICompositionDrawingSurface)->get_Size(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_ICompositionEffectBrush<D>::GetSourceParameter(hstring_view name) const
{
    Windows::UI::Composition::CompositionBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositionEffectBrush)->abi_GetSourceParameter(get_abi(name), put_abi(result)));
    return result;
}

template <typename D> void impl_ICompositionEffectBrush<D>::SetSourceParameter(hstring_view name, const Windows::UI::Composition::CompositionBrush & source) const
{
    check_hresult(WINRT_SHIM(ICompositionEffectBrush)->abi_SetSourceParameter(get_abi(name), get_abi(source)));
}

template <typename D> Windows::UI::Composition::CompositionEffectBrush impl_ICompositionEffectFactory<D>::CreateBrush() const
{
    Windows::UI::Composition::CompositionEffectBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositionEffectFactory)->abi_CreateBrush(put_abi(result)));
    return result;
}

template <typename D> HRESULT impl_ICompositionEffectFactory<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(ICompositionEffectFactory)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::UI::Composition::CompositionEffectFactoryLoadStatus impl_ICompositionEffectFactory<D>::LoadStatus() const
{
    Windows::UI::Composition::CompositionEffectFactoryLoadStatus value {};
    check_hresult(WINRT_SHIM(ICompositionEffectFactory)->get_LoadStatus(&value));
    return value;
}

template <typename D> hstring impl_ICompositionEffectSourceParameter<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICompositionEffectSourceParameter)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Composition::CompositionEffectSourceParameter impl_ICompositionEffectSourceParameterFactory<D>::Create(hstring_view name) const
{
    Windows::UI::Composition::CompositionEffectSourceParameter instance { nullptr };
    check_hresult(WINRT_SHIM(ICompositionEffectSourceParameterFactory)->abi_Create(get_abi(name), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Composition::CompositionDrawingSurface impl_ICompositionGraphicsDevice<D>::CreateDrawingSurface(const Windows::Foundation::Size & sizePixels, Windows::Graphics::DirectX::DirectXPixelFormat pixelFormat, Windows::Graphics::DirectX::DirectXAlphaMode alphaMode) const
{
    Windows::UI::Composition::CompositionDrawingSurface result { nullptr };
    check_hresult(WINRT_SHIM(ICompositionGraphicsDevice)->abi_CreateDrawingSurface(get_abi(sizePixels), pixelFormat, alphaMode, put_abi(result)));
    return result;
}

template <typename D> event_token impl_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(const Windows::Foundation::TypedEventHandler<Windows::UI::Composition::CompositionGraphicsDevice, Windows::UI::Composition::RenderingDeviceReplacedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompositionGraphicsDevice)->add_RenderingDeviceReplaced(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICompositionGraphicsDevice> impl_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Composition::CompositionGraphicsDevice, Windows::UI::Composition::RenderingDeviceReplacedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICompositionGraphicsDevice>(this, &ABI::Windows::UI::Composition::ICompositionGraphicsDevice::remove_RenderingDeviceReplaced, RenderingDeviceReplaced(handler));
}

template <typename D> void impl_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompositionGraphicsDevice)->remove_RenderingDeviceReplaced(token));
}

template <typename D> Windows::UI::Composition::VisualUnorderedCollection impl_ICompositionLight<D>::Targets() const
{
    Windows::UI::Composition::VisualUnorderedCollection value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionLight)->get_Targets(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_ICompositionMaskBrush<D>::Mask() const
{
    Windows::UI::Composition::CompositionBrush value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionMaskBrush)->get_Mask(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionMaskBrush<D>::Mask(const Windows::UI::Composition::CompositionBrush & value) const
{
    check_hresult(WINRT_SHIM(ICompositionMaskBrush)->put_Mask(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_ICompositionMaskBrush<D>::Source() const
{
    Windows::UI::Composition::CompositionBrush value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionMaskBrush)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionMaskBrush<D>::Source(const Windows::UI::Composition::CompositionBrush & value) const
{
    check_hresult(WINRT_SHIM(ICompositionMaskBrush)->put_Source(get_abi(value)));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::BottomInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_BottomInset(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::BottomInset(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_BottomInset(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::BottomInsetScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_BottomInsetScale(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::BottomInsetScale(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_BottomInsetScale(value));
}

template <typename D> bool impl_ICompositionNineGridBrush<D>::IsCenterHollow() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_IsCenterHollow(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::IsCenterHollow(bool value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_IsCenterHollow(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::LeftInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_LeftInset(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::LeftInset(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_LeftInset(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::LeftInsetScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_LeftInsetScale(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::LeftInsetScale(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_LeftInsetScale(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::RightInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_RightInset(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::RightInset(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_RightInset(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::RightInsetScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_RightInsetScale(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::RightInsetScale(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_RightInsetScale(value));
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_ICompositionNineGridBrush<D>::Source() const
{
    Windows::UI::Composition::CompositionBrush value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::Source(const Windows::UI::Composition::CompositionBrush & value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_Source(get_abi(value)));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::TopInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_TopInset(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::TopInset(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_TopInset(value));
}

template <typename D> float impl_ICompositionNineGridBrush<D>::TopInsetScale() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->get_TopInsetScale(&value));
    return value;
}

template <typename D> void impl_ICompositionNineGridBrush<D>::TopInsetScale(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->put_TopInsetScale(value));
}

template <typename D> void impl_ICompositionNineGridBrush<D>::SetInsets(float inset) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->abi_SetInsets(inset));
}

template <typename D> void impl_ICompositionNineGridBrush<D>::SetInsets(float left, float top, float right, float bottom) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->abi_SetInsetsWithValues(left, top, right, bottom));
}

template <typename D> void impl_ICompositionNineGridBrush<D>::SetInsetScales(float scale) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->abi_SetInsetScales(scale));
}

template <typename D> void impl_ICompositionNineGridBrush<D>::SetInsetScales(float left, float top, float right, float bottom) const
{
    check_hresult(WINRT_SHIM(ICompositionNineGridBrush)->abi_SetInsetScalesWithValues(left, top, right, bottom));
}

template <typename D> Windows::UI::Composition::Compositor impl_ICompositionObject<D>::Compositor() const
{
    Windows::UI::Composition::Compositor value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionObject)->get_Compositor(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_ICompositionObject<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionObject)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Composition::CompositionPropertySet impl_ICompositionObject<D>::Properties() const
{
    Windows::UI::Composition::CompositionPropertySet value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionObject)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionObject<D>::StartAnimation(hstring_view propertyName, const Windows::UI::Composition::CompositionAnimation & animation) const
{
    check_hresult(WINRT_SHIM(ICompositionObject)->abi_StartAnimation(get_abi(propertyName), get_abi(animation)));
}

template <typename D> void impl_ICompositionObject<D>::StopAnimation(hstring_view propertyName) const
{
    check_hresult(WINRT_SHIM(ICompositionObject)->abi_StopAnimation(get_abi(propertyName)));
}

template <typename D> hstring impl_ICompositionObject2<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICompositionObject2)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionObject2<D>::Comment(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICompositionObject2)->put_Comment(get_abi(value)));
}

template <typename D> Windows::UI::Composition::ImplicitAnimationCollection impl_ICompositionObject2<D>::ImplicitAnimations() const
{
    Windows::UI::Composition::ImplicitAnimationCollection value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionObject2)->get_ImplicitAnimations(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionObject2<D>::ImplicitAnimations(const Windows::UI::Composition::ImplicitAnimationCollection & value) const
{
    check_hresult(WINRT_SHIM(ICompositionObject2)->put_ImplicitAnimations(get_abi(value)));
}

template <typename D> void impl_ICompositionObject2<D>::StartAnimationGroup(const Windows::UI::Composition::ICompositionAnimationBase & value) const
{
    check_hresult(WINRT_SHIM(ICompositionObject2)->abi_StartAnimationGroup(get_abi(value)));
}

template <typename D> void impl_ICompositionObject2<D>::StopAnimationGroup(const Windows::UI::Composition::ICompositionAnimationBase & value) const
{
    check_hresult(WINRT_SHIM(ICompositionObject2)->abi_StopAnimationGroup(get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertColor(hstring_view propertyName, const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertColor(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertMatrix3x2(hstring_view propertyName, const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertMatrix3x2(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertMatrix4x4(hstring_view propertyName, const Windows::Foundation::Numerics::float4x4 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertMatrix4x4(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertQuaternion(hstring_view propertyName, const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertQuaternion(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertScalar(hstring_view propertyName, float value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertScalar(get_abi(propertyName), value));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertVector2(hstring_view propertyName, const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertVector2(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertVector3(hstring_view propertyName, const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertVector3(get_abi(propertyName), get_abi(value)));
}

template <typename D> void impl_ICompositionPropertySet<D>::InsertVector4(hstring_view propertyName, const Windows::Foundation::Numerics::float4 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_InsertVector4(get_abi(propertyName), get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetColor(hstring_view propertyName, Windows::UI::Color & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetColor(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetMatrix3x2(hstring_view propertyName, Windows::Foundation::Numerics::float3x2 & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetMatrix3x2(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetMatrix4x4(hstring_view propertyName, Windows::Foundation::Numerics::float4x4 & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetMatrix4x4(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetQuaternion(hstring_view propertyName, Windows::Foundation::Numerics::quaternion & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetQuaternion(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetScalar(hstring_view propertyName, float & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetScalar(get_abi(propertyName), &value, &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetVector2(hstring_view propertyName, Windows::Foundation::Numerics::float2 & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetVector2(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetVector3(hstring_view propertyName, Windows::Foundation::Numerics::float3 & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetVector3(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet<D>::TryGetVector4(hstring_view propertyName, Windows::Foundation::Numerics::float4 & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet)->abi_TryGetVector4(get_abi(propertyName), put_abi(value), &result));
    return result;
}

template <typename D> void impl_ICompositionPropertySet2<D>::InsertBoolean(hstring_view propertyName, bool value) const
{
    check_hresult(WINRT_SHIM(ICompositionPropertySet2)->abi_InsertBoolean(get_abi(propertyName), value));
}

template <typename D> Windows::UI::Composition::CompositionGetValueStatus impl_ICompositionPropertySet2<D>::TryGetBoolean(hstring_view propertyName, bool & value) const
{
    Windows::UI::Composition::CompositionGetValueStatus result {};
    check_hresult(WINRT_SHIM(ICompositionPropertySet2)->abi_TryGetBoolean(get_abi(propertyName), &value, &result));
    return result;
}

template <typename D> bool impl_ICompositionScopedBatch<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->get_IsActive(&value));
    return value;
}

template <typename D> bool impl_ICompositionScopedBatch<D>::IsEnded() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->get_IsEnded(&value));
    return value;
}

template <typename D> void impl_ICompositionScopedBatch<D>::End() const
{
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->abi_End());
}

template <typename D> void impl_ICompositionScopedBatch<D>::Resume() const
{
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->abi_Resume());
}

template <typename D> void impl_ICompositionScopedBatch<D>::Suspend() const
{
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->abi_Suspend());
}

template <typename D> event_token impl_ICompositionScopedBatch<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->add_Completed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICompositionScopedBatch> impl_ICompositionScopedBatch<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Composition::CompositionBatchCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICompositionScopedBatch>(this, &ABI::Windows::UI::Composition::ICompositionScopedBatch::remove_Completed, Completed(handler));
}

template <typename D> void impl_ICompositionScopedBatch<D>::Completed(event_token token) const
{
    check_hresult(WINRT_SHIM(ICompositionScopedBatch)->remove_Completed(token));
}

template <typename D> Windows::UI::Composition::CompositionBitmapInterpolationMode impl_ICompositionSurfaceBrush<D>::BitmapInterpolationMode() const
{
    Windows::UI::Composition::CompositionBitmapInterpolationMode value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->get_BitmapInterpolationMode(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush<D>::BitmapInterpolationMode(Windows::UI::Composition::CompositionBitmapInterpolationMode value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->put_BitmapInterpolationMode(value));
}

template <typename D> float impl_ICompositionSurfaceBrush<D>::HorizontalAlignmentRatio() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->get_HorizontalAlignmentRatio(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush<D>::HorizontalAlignmentRatio(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->put_HorizontalAlignmentRatio(value));
}

template <typename D> Windows::UI::Composition::CompositionStretch impl_ICompositionSurfaceBrush<D>::Stretch() const
{
    Windows::UI::Composition::CompositionStretch value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->get_Stretch(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush<D>::Stretch(Windows::UI::Composition::CompositionStretch value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->put_Stretch(value));
}

template <typename D> Windows::UI::Composition::ICompositionSurface impl_ICompositionSurfaceBrush<D>::Surface() const
{
    Windows::UI::Composition::ICompositionSurface value;
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->get_Surface(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush<D>::Surface(const Windows::UI::Composition::ICompositionSurface & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->put_Surface(get_abi(value)));
}

template <typename D> float impl_ICompositionSurfaceBrush<D>::VerticalAlignmentRatio() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->get_VerticalAlignmentRatio(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush<D>::VerticalAlignmentRatio(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush)->put_VerticalAlignmentRatio(value));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionSurfaceBrush2<D>::AnchorPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_AnchorPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::AnchorPoint(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_AnchorPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionSurfaceBrush2<D>::CenterPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_CenterPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::CenterPoint(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_CenterPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionSurfaceBrush2<D>::Offset() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::Offset(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_Offset(get_abi(value)));
}

template <typename D> float impl_ICompositionSurfaceBrush2<D>::RotationAngle() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_RotationAngle(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::RotationAngle(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_RotationAngle(value));
}

template <typename D> float impl_ICompositionSurfaceBrush2<D>::RotationAngleInDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_RotationAngleInDegrees(&value));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::RotationAngleInDegrees(float value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_RotationAngleInDegrees(value));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICompositionSurfaceBrush2<D>::Scale() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_Scale(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::Scale(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_Scale(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3x2 impl_ICompositionSurfaceBrush2<D>::TransformMatrix() const
{
    Windows::Foundation::Numerics::float3x2 value {};
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->get_TransformMatrix(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionSurfaceBrush2<D>::TransformMatrix(const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(ICompositionSurfaceBrush2)->put_TransformMatrix(get_abi(value)));
}

template <typename D> Windows::UI::Composition::Visual impl_ICompositionTarget<D>::Root() const
{
    Windows::UI::Composition::Visual value { nullptr };
    check_hresult(WINRT_SHIM(ICompositionTarget)->get_Root(put_abi(value)));
    return value;
}

template <typename D> void impl_ICompositionTarget<D>::Root(const Windows::UI::Composition::Visual & value) const
{
    check_hresult(WINRT_SHIM(ICompositionTarget)->put_Root(get_abi(value)));
}

template <typename D> Windows::UI::Composition::ColorKeyFrameAnimation impl_ICompositor<D>::CreateColorKeyFrameAnimation() const
{
    Windows::UI::Composition::ColorKeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateColorKeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionColorBrush impl_ICompositor<D>::CreateColorBrush() const
{
    Windows::UI::Composition::CompositionColorBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateColorBrush(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionColorBrush impl_ICompositor<D>::CreateColorBrush(const Windows::UI::Color & color) const
{
    Windows::UI::Composition::CompositionColorBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateColorBrushWithColor(get_abi(color), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ContainerVisual impl_ICompositor<D>::CreateContainerVisual() const
{
    Windows::UI::Composition::ContainerVisual result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateContainerVisual(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CubicBezierEasingFunction impl_ICompositor<D>::CreateCubicBezierEasingFunction(const Windows::Foundation::Numerics::float2 & controlPoint1, const Windows::Foundation::Numerics::float2 & controlPoint2) const
{
    Windows::UI::Composition::CubicBezierEasingFunction result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateCubicBezierEasingFunction(get_abi(controlPoint1), get_abi(controlPoint2), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionEffectFactory impl_ICompositor<D>::CreateEffectFactory(const Windows::Graphics::Effects::IGraphicsEffect & graphicsEffect) const
{
    Windows::UI::Composition::CompositionEffectFactory result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateEffectFactory(get_abi(graphicsEffect), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionEffectFactory impl_ICompositor<D>::CreateEffectFactory(const Windows::Graphics::Effects::IGraphicsEffect & graphicsEffect, iterable<hstring> animatableProperties) const
{
    Windows::UI::Composition::CompositionEffectFactory result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateEffectFactoryWithProperties(get_abi(graphicsEffect), get_abi(animatableProperties), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_ICompositor<D>::CreateExpressionAnimation() const
{
    Windows::UI::Composition::ExpressionAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateExpressionAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ExpressionAnimation impl_ICompositor<D>::CreateExpressionAnimation(hstring_view expression) const
{
    Windows::UI::Composition::ExpressionAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateExpressionAnimationWithExpression(get_abi(expression), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::InsetClip impl_ICompositor<D>::CreateInsetClip() const
{
    Windows::UI::Composition::InsetClip result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateInsetClip(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::InsetClip impl_ICompositor<D>::CreateInsetClip(float leftInset, float topInset, float rightInset, float bottomInset) const
{
    Windows::UI::Composition::InsetClip result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateInsetClipWithInsets(leftInset, topInset, rightInset, bottomInset, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::LinearEasingFunction impl_ICompositor<D>::CreateLinearEasingFunction() const
{
    Windows::UI::Composition::LinearEasingFunction result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateLinearEasingFunction(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionPropertySet impl_ICompositor<D>::CreatePropertySet() const
{
    Windows::UI::Composition::CompositionPropertySet result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreatePropertySet(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::QuaternionKeyFrameAnimation impl_ICompositor<D>::CreateQuaternionKeyFrameAnimation() const
{
    Windows::UI::Composition::QuaternionKeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateQuaternionKeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ScalarKeyFrameAnimation impl_ICompositor<D>::CreateScalarKeyFrameAnimation() const
{
    Windows::UI::Composition::ScalarKeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateScalarKeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionScopedBatch impl_ICompositor<D>::CreateScopedBatch(Windows::UI::Composition::CompositionBatchTypes batchType) const
{
    Windows::UI::Composition::CompositionScopedBatch result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateScopedBatch(batchType, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::SpriteVisual impl_ICompositor<D>::CreateSpriteVisual() const
{
    Windows::UI::Composition::SpriteVisual result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateSpriteVisual(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionSurfaceBrush impl_ICompositor<D>::CreateSurfaceBrush() const
{
    Windows::UI::Composition::CompositionSurfaceBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateSurfaceBrush(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionSurfaceBrush impl_ICompositor<D>::CreateSurfaceBrush(const Windows::UI::Composition::ICompositionSurface & surface) const
{
    Windows::UI::Composition::CompositionSurfaceBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateSurfaceBrushWithSurface(get_abi(surface), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionTarget impl_ICompositor<D>::CreateTargetForCurrentView() const
{
    Windows::UI::Composition::CompositionTarget result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateTargetForCurrentView(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Vector2KeyFrameAnimation impl_ICompositor<D>::CreateVector2KeyFrameAnimation() const
{
    Windows::UI::Composition::Vector2KeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateVector2KeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Vector3KeyFrameAnimation impl_ICompositor<D>::CreateVector3KeyFrameAnimation() const
{
    Windows::UI::Composition::Vector3KeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateVector3KeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Vector4KeyFrameAnimation impl_ICompositor<D>::CreateVector4KeyFrameAnimation() const
{
    Windows::UI::Composition::Vector4KeyFrameAnimation result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_CreateVector4KeyFrameAnimation(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionCommitBatch impl_ICompositor<D>::GetCommitBatch(Windows::UI::Composition::CompositionBatchTypes batchType) const
{
    Windows::UI::Composition::CompositionCommitBatch result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor)->abi_GetCommitBatch(batchType, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::AmbientLight impl_ICompositor2<D>::CreateAmbientLight() const
{
    Windows::UI::Composition::AmbientLight result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateAmbientLight(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionAnimationGroup impl_ICompositor2<D>::CreateAnimationGroup() const
{
    Windows::UI::Composition::CompositionAnimationGroup result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateAnimationGroup(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionBackdropBrush impl_ICompositor2<D>::CreateBackdropBrush() const
{
    Windows::UI::Composition::CompositionBackdropBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateBackdropBrush(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::DistantLight impl_ICompositor2<D>::CreateDistantLight() const
{
    Windows::UI::Composition::DistantLight result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateDistantLight(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::DropShadow impl_ICompositor2<D>::CreateDropShadow() const
{
    Windows::UI::Composition::DropShadow result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateDropShadow(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::ImplicitAnimationCollection impl_ICompositor2<D>::CreateImplicitAnimationCollection() const
{
    Windows::UI::Composition::ImplicitAnimationCollection result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateImplicitAnimationCollection(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::LayerVisual impl_ICompositor2<D>::CreateLayerVisual() const
{
    Windows::UI::Composition::LayerVisual result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateLayerVisual(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionMaskBrush impl_ICompositor2<D>::CreateMaskBrush() const
{
    Windows::UI::Composition::CompositionMaskBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateMaskBrush(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::CompositionNineGridBrush impl_ICompositor2<D>::CreateNineGridBrush() const
{
    Windows::UI::Composition::CompositionNineGridBrush result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateNineGridBrush(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::PointLight impl_ICompositor2<D>::CreatePointLight() const
{
    Windows::UI::Composition::PointLight result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreatePointLight(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::SpotLight impl_ICompositor2<D>::CreateSpotLight() const
{
    Windows::UI::Composition::SpotLight result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateSpotLight(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::StepEasingFunction impl_ICompositor2<D>::CreateStepEasingFunction() const
{
    Windows::UI::Composition::StepEasingFunction result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateStepEasingFunction(put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::StepEasingFunction impl_ICompositor2<D>::CreateStepEasingFunction(int32_t stepCount) const
{
    Windows::UI::Composition::StepEasingFunction result { nullptr };
    check_hresult(WINRT_SHIM(ICompositor2)->abi_CreateStepEasingFunctionWithStepCount(stepCount, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::VisualCollection impl_IContainerVisual<D>::Children() const
{
    Windows::UI::Composition::VisualCollection value { nullptr };
    check_hresult(WINRT_SHIM(IContainerVisual)->get_Children(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICubicBezierEasingFunction<D>::ControlPoint1() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICubicBezierEasingFunction)->get_ControlPoint1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICubicBezierEasingFunction<D>::ControlPoint2() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICubicBezierEasingFunction)->get_ControlPoint2(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IDistantLight<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDistantLight)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IDistantLight<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDistantLight)->put_Color(get_abi(value)));
}

template <typename D> Windows::UI::Composition::Visual impl_IDistantLight<D>::CoordinateSpace() const
{
    Windows::UI::Composition::Visual value { nullptr };
    check_hresult(WINRT_SHIM(IDistantLight)->get_CoordinateSpace(put_abi(value)));
    return value;
}

template <typename D> void impl_IDistantLight<D>::CoordinateSpace(const Windows::UI::Composition::Visual & value) const
{
    check_hresult(WINRT_SHIM(IDistantLight)->put_CoordinateSpace(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IDistantLight<D>::Direction() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IDistantLight)->get_Direction(put_abi(value)));
    return value;
}

template <typename D> void impl_IDistantLight<D>::Direction(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IDistantLight)->put_Direction(get_abi(value)));
}

template <typename D> float impl_IDropShadow<D>::BlurRadius() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDropShadow)->get_BlurRadius(&value));
    return value;
}

template <typename D> void impl_IDropShadow<D>::BlurRadius(float value) const
{
    check_hresult(WINRT_SHIM(IDropShadow)->put_BlurRadius(value));
}

template <typename D> Windows::UI::Color impl_IDropShadow<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDropShadow)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IDropShadow<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDropShadow)->put_Color(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_IDropShadow<D>::Mask() const
{
    Windows::UI::Composition::CompositionBrush value { nullptr };
    check_hresult(WINRT_SHIM(IDropShadow)->get_Mask(put_abi(value)));
    return value;
}

template <typename D> void impl_IDropShadow<D>::Mask(const Windows::UI::Composition::CompositionBrush & value) const
{
    check_hresult(WINRT_SHIM(IDropShadow)->put_Mask(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IDropShadow<D>::Offset() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IDropShadow)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_IDropShadow<D>::Offset(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IDropShadow)->put_Offset(get_abi(value)));
}

template <typename D> float impl_IDropShadow<D>::Opacity() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDropShadow)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IDropShadow<D>::Opacity(float value) const
{
    check_hresult(WINRT_SHIM(IDropShadow)->put_Opacity(value));
}

template <typename D> hstring impl_IExpressionAnimation<D>::Expression() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IExpressionAnimation)->get_Expression(put_abi(value)));
    return value;
}

template <typename D> void impl_IExpressionAnimation<D>::Expression(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IExpressionAnimation)->put_Expression(get_abi(value)));
}

template <typename D> float impl_IInsetClip<D>::BottomInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInsetClip)->get_BottomInset(&value));
    return value;
}

template <typename D> void impl_IInsetClip<D>::BottomInset(float value) const
{
    check_hresult(WINRT_SHIM(IInsetClip)->put_BottomInset(value));
}

template <typename D> float impl_IInsetClip<D>::LeftInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInsetClip)->get_LeftInset(&value));
    return value;
}

template <typename D> void impl_IInsetClip<D>::LeftInset(float value) const
{
    check_hresult(WINRT_SHIM(IInsetClip)->put_LeftInset(value));
}

template <typename D> float impl_IInsetClip<D>::RightInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInsetClip)->get_RightInset(&value));
    return value;
}

template <typename D> void impl_IInsetClip<D>::RightInset(float value) const
{
    check_hresult(WINRT_SHIM(IInsetClip)->put_RightInset(value));
}

template <typename D> float impl_IInsetClip<D>::TopInset() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInsetClip)->get_TopInset(&value));
    return value;
}

template <typename D> void impl_IInsetClip<D>::TopInset(float value) const
{
    check_hresult(WINRT_SHIM(IInsetClip)->put_TopInset(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IKeyFrameAnimation<D>::DelayTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_DelayTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation<D>::DelayTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->put_DelayTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IKeyFrameAnimation<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->put_Duration(get_abi(value)));
}

template <typename D> Windows::UI::Composition::AnimationIterationBehavior impl_IKeyFrameAnimation<D>::IterationBehavior() const
{
    Windows::UI::Composition::AnimationIterationBehavior value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_IterationBehavior(&value));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation<D>::IterationBehavior(Windows::UI::Composition::AnimationIterationBehavior value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->put_IterationBehavior(value));
}

template <typename D> int32_t impl_IKeyFrameAnimation<D>::IterationCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_IterationCount(&value));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation<D>::IterationCount(int32_t value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->put_IterationCount(value));
}

template <typename D> int32_t impl_IKeyFrameAnimation<D>::KeyFrameCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_KeyFrameCount(&value));
    return value;
}

template <typename D> Windows::UI::Composition::AnimationStopBehavior impl_IKeyFrameAnimation<D>::StopBehavior() const
{
    Windows::UI::Composition::AnimationStopBehavior value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->get_StopBehavior(&value));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation<D>::StopBehavior(Windows::UI::Composition::AnimationStopBehavior value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->put_StopBehavior(value));
}

template <typename D> void impl_IKeyFrameAnimation<D>::InsertExpressionKeyFrame(float normalizedProgressKey, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->abi_InsertExpressionKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IKeyFrameAnimation<D>::InsertExpressionKeyFrame(float normalizedProgressKey, hstring_view value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation)->abi_InsertExpressionKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> Windows::UI::Composition::AnimationDirection impl_IKeyFrameAnimation2<D>::Direction() const
{
    Windows::UI::Composition::AnimationDirection value {};
    check_hresult(WINRT_SHIM(IKeyFrameAnimation2)->get_Direction(&value));
    return value;
}

template <typename D> void impl_IKeyFrameAnimation2<D>::Direction(Windows::UI::Composition::AnimationDirection value) const
{
    check_hresult(WINRT_SHIM(IKeyFrameAnimation2)->put_Direction(value));
}

template <typename D> Windows::UI::Composition::CompositionEffectBrush impl_ILayerVisual<D>::Effect() const
{
    Windows::UI::Composition::CompositionEffectBrush value { nullptr };
    check_hresult(WINRT_SHIM(ILayerVisual)->get_Effect(put_abi(value)));
    return value;
}

template <typename D> void impl_ILayerVisual<D>::Effect(const Windows::UI::Composition::CompositionEffectBrush & value) const
{
    check_hresult(WINRT_SHIM(ILayerVisual)->put_Effect(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IPointLight<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IPointLight)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointLight<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_Color(get_abi(value)));
}

template <typename D> float impl_IPointLight<D>::ConstantAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(IPointLight)->get_ConstantAttenuation(&value));
    return value;
}

template <typename D> void impl_IPointLight<D>::ConstantAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_ConstantAttenuation(value));
}

template <typename D> Windows::UI::Composition::Visual impl_IPointLight<D>::CoordinateSpace() const
{
    Windows::UI::Composition::Visual value { nullptr };
    check_hresult(WINRT_SHIM(IPointLight)->get_CoordinateSpace(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointLight<D>::CoordinateSpace(const Windows::UI::Composition::Visual & value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_CoordinateSpace(get_abi(value)));
}

template <typename D> float impl_IPointLight<D>::LinearAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(IPointLight)->get_LinearAttenuation(&value));
    return value;
}

template <typename D> void impl_IPointLight<D>::LinearAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_LinearAttenuation(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IPointLight<D>::Offset() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IPointLight)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_IPointLight<D>::Offset(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_Offset(get_abi(value)));
}

template <typename D> float impl_IPointLight<D>::QuadraticAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(IPointLight)->get_QuadraticAttenuation(&value));
    return value;
}

template <typename D> void impl_IPointLight<D>::QuadraticAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(IPointLight)->put_QuadraticAttenuation(value));
}

template <typename D> void impl_IQuaternionKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(IQuaternionKeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IQuaternionKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::quaternion & value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IQuaternionKeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> Windows::UI::Composition::CompositionGraphicsDevice impl_IRenderingDeviceReplacedEventArgs<D>::GraphicsDevice() const
{
    Windows::UI::Composition::CompositionGraphicsDevice value { nullptr };
    check_hresult(WINRT_SHIM(IRenderingDeviceReplacedEventArgs)->get_GraphicsDevice(put_abi(value)));
    return value;
}

template <typename D> void impl_IScalarKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, float value) const
{
    check_hresult(WINRT_SHIM(IScalarKeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, value));
}

template <typename D> void impl_IScalarKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, float value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IScalarKeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, value, get_abi(easingFunction)));
}

template <typename D> float impl_ISpotLight<D>::ConstantAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_ConstantAttenuation(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::ConstantAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_ConstantAttenuation(value));
}

template <typename D> Windows::UI::Composition::Visual impl_ISpotLight<D>::CoordinateSpace() const
{
    Windows::UI::Composition::Visual value { nullptr };
    check_hresult(WINRT_SHIM(ISpotLight)->get_CoordinateSpace(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpotLight<D>::CoordinateSpace(const Windows::UI::Composition::Visual & value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_CoordinateSpace(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpotLight<D>::Direction() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_Direction(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpotLight<D>::Direction(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_Direction(get_abi(value)));
}

template <typename D> float impl_ISpotLight<D>::InnerConeAngle() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_InnerConeAngle(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::InnerConeAngle(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_InnerConeAngle(value));
}

template <typename D> float impl_ISpotLight<D>::InnerConeAngleInDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_InnerConeAngleInDegrees(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::InnerConeAngleInDegrees(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_InnerConeAngleInDegrees(value));
}

template <typename D> Windows::UI::Color impl_ISpotLight<D>::InnerConeColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_InnerConeColor(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpotLight<D>::InnerConeColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_InnerConeColor(get_abi(value)));
}

template <typename D> float impl_ISpotLight<D>::LinearAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_LinearAttenuation(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::LinearAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_LinearAttenuation(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpotLight<D>::Offset() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpotLight<D>::Offset(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_Offset(get_abi(value)));
}

template <typename D> float impl_ISpotLight<D>::OuterConeAngle() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_OuterConeAngle(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::OuterConeAngle(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_OuterConeAngle(value));
}

template <typename D> float impl_ISpotLight<D>::OuterConeAngleInDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_OuterConeAngleInDegrees(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::OuterConeAngleInDegrees(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_OuterConeAngleInDegrees(value));
}

template <typename D> Windows::UI::Color impl_ISpotLight<D>::OuterConeColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_OuterConeColor(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpotLight<D>::OuterConeColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_OuterConeColor(get_abi(value)));
}

template <typename D> float impl_ISpotLight<D>::QuadraticAttenuation() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISpotLight)->get_QuadraticAttenuation(&value));
    return value;
}

template <typename D> void impl_ISpotLight<D>::QuadraticAttenuation(float value) const
{
    check_hresult(WINRT_SHIM(ISpotLight)->put_QuadraticAttenuation(value));
}

template <typename D> Windows::UI::Composition::CompositionBrush impl_ISpriteVisual<D>::Brush() const
{
    Windows::UI::Composition::CompositionBrush value { nullptr };
    check_hresult(WINRT_SHIM(ISpriteVisual)->get_Brush(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpriteVisual<D>::Brush(const Windows::UI::Composition::CompositionBrush & value) const
{
    check_hresult(WINRT_SHIM(ISpriteVisual)->put_Brush(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionShadow impl_ISpriteVisual2<D>::Shadow() const
{
    Windows::UI::Composition::CompositionShadow value { nullptr };
    check_hresult(WINRT_SHIM(ISpriteVisual2)->get_Shadow(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpriteVisual2<D>::Shadow(const Windows::UI::Composition::CompositionShadow & value) const
{
    check_hresult(WINRT_SHIM(ISpriteVisual2)->put_Shadow(get_abi(value)));
}

template <typename D> int32_t impl_IStepEasingFunction<D>::FinalStep() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IStepEasingFunction)->get_FinalStep(&value));
    return value;
}

template <typename D> void impl_IStepEasingFunction<D>::FinalStep(int32_t value) const
{
    check_hresult(WINRT_SHIM(IStepEasingFunction)->put_FinalStep(value));
}

template <typename D> int32_t impl_IStepEasingFunction<D>::InitialStep() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IStepEasingFunction)->get_InitialStep(&value));
    return value;
}

template <typename D> void impl_IStepEasingFunction<D>::InitialStep(int32_t value) const
{
    check_hresult(WINRT_SHIM(IStepEasingFunction)->put_InitialStep(value));
}

template <typename D> bool impl_IStepEasingFunction<D>::IsFinalStepSingleFrame() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStepEasingFunction)->get_IsFinalStepSingleFrame(&value));
    return value;
}

template <typename D> void impl_IStepEasingFunction<D>::IsFinalStepSingleFrame(bool value) const
{
    check_hresult(WINRT_SHIM(IStepEasingFunction)->put_IsFinalStepSingleFrame(value));
}

template <typename D> bool impl_IStepEasingFunction<D>::IsInitialStepSingleFrame() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStepEasingFunction)->get_IsInitialStepSingleFrame(&value));
    return value;
}

template <typename D> void impl_IStepEasingFunction<D>::IsInitialStepSingleFrame(bool value) const
{
    check_hresult(WINRT_SHIM(IStepEasingFunction)->put_IsInitialStepSingleFrame(value));
}

template <typename D> int32_t impl_IStepEasingFunction<D>::StepCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IStepEasingFunction)->get_StepCount(&value));
    return value;
}

template <typename D> void impl_IStepEasingFunction<D>::StepCount(int32_t value) const
{
    check_hresult(WINRT_SHIM(IStepEasingFunction)->put_StepCount(value));
}

template <typename D> void impl_IVector2KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(IVector2KeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IVector2KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float2 & value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IVector2KeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> void impl_IVector3KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IVector3KeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IVector3KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float3 & value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IVector3KeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> void impl_IVector4KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float4 & value) const
{
    check_hresult(WINRT_SHIM(IVector4KeyFrameAnimation)->abi_InsertKeyFrame(normalizedProgressKey, get_abi(value)));
}

template <typename D> void impl_IVector4KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, const Windows::Foundation::Numerics::float4 & value, const Windows::UI::Composition::CompositionEasingFunction & easingFunction) const
{
    check_hresult(WINRT_SHIM(IVector4KeyFrameAnimation)->abi_InsertKeyFrameWithEasingFunction(normalizedProgressKey, get_abi(value), get_abi(easingFunction)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_IVisual<D>::AnchorPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_AnchorPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::AnchorPoint(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_AnchorPoint(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionBackfaceVisibility impl_IVisual<D>::BackfaceVisibility() const
{
    Windows::UI::Composition::CompositionBackfaceVisibility value {};
    check_hresult(WINRT_SHIM(IVisual)->get_BackfaceVisibility(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::BackfaceVisibility(Windows::UI::Composition::CompositionBackfaceVisibility value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_BackfaceVisibility(value));
}

template <typename D> Windows::UI::Composition::CompositionBorderMode impl_IVisual<D>::BorderMode() const
{
    Windows::UI::Composition::CompositionBorderMode value {};
    check_hresult(WINRT_SHIM(IVisual)->get_BorderMode(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::BorderMode(Windows::UI::Composition::CompositionBorderMode value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_BorderMode(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IVisual<D>::CenterPoint() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_CenterPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::CenterPoint(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_CenterPoint(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionClip impl_IVisual<D>::Clip() const
{
    Windows::UI::Composition::CompositionClip value { nullptr };
    check_hresult(WINRT_SHIM(IVisual)->get_Clip(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::Clip(const Windows::UI::Composition::CompositionClip & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Clip(get_abi(value)));
}

template <typename D> Windows::UI::Composition::CompositionCompositeMode impl_IVisual<D>::CompositeMode() const
{
    Windows::UI::Composition::CompositionCompositeMode value {};
    check_hresult(WINRT_SHIM(IVisual)->get_CompositeMode(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::CompositeMode(Windows::UI::Composition::CompositionCompositeMode value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_CompositeMode(value));
}

template <typename D> bool impl_IVisual<D>::IsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVisual)->get_IsVisible(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::IsVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_IsVisible(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IVisual<D>::Offset() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_Offset(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::Offset(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Offset(get_abi(value)));
}

template <typename D> float impl_IVisual<D>::Opacity() const
{
    float value {};
    check_hresult(WINRT_SHIM(IVisual)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::Opacity(float value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Opacity(value));
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_IVisual<D>::Orientation() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(IVisual)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::Orientation(const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Orientation(get_abi(value)));
}

template <typename D> Windows::UI::Composition::ContainerVisual impl_IVisual<D>::Parent() const
{
    Windows::UI::Composition::ContainerVisual value { nullptr };
    check_hresult(WINRT_SHIM(IVisual)->get_Parent(put_abi(value)));
    return value;
}

template <typename D> float impl_IVisual<D>::RotationAngle() const
{
    float value {};
    check_hresult(WINRT_SHIM(IVisual)->get_RotationAngle(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::RotationAngle(float value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_RotationAngle(value));
}

template <typename D> float impl_IVisual<D>::RotationAngleInDegrees() const
{
    float value {};
    check_hresult(WINRT_SHIM(IVisual)->get_RotationAngleInDegrees(&value));
    return value;
}

template <typename D> void impl_IVisual<D>::RotationAngleInDegrees(float value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_RotationAngleInDegrees(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IVisual<D>::RotationAxis() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_RotationAxis(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::RotationAxis(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_RotationAxis(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IVisual<D>::Scale() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_Scale(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::Scale(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Scale(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float2 impl_IVisual<D>::Size() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_Size(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::Size(const Windows::Foundation::Numerics::float2 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_Size(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float4x4 impl_IVisual<D>::TransformMatrix() const
{
    Windows::Foundation::Numerics::float4x4 value {};
    check_hresult(WINRT_SHIM(IVisual)->get_TransformMatrix(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisual<D>::TransformMatrix(const Windows::Foundation::Numerics::float4x4 & value) const
{
    check_hresult(WINRT_SHIM(IVisual)->put_TransformMatrix(get_abi(value)));
}

template <typename D> int32_t impl_IVisualCollection<D>::Count() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IVisualCollection)->get_Count(&value));
    return value;
}

template <typename D> void impl_IVisualCollection<D>::InsertAbove(const Windows::UI::Composition::Visual & newChild, const Windows::UI::Composition::Visual & sibling) const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_InsertAbove(get_abi(newChild), get_abi(sibling)));
}

template <typename D> void impl_IVisualCollection<D>::InsertAtBottom(const Windows::UI::Composition::Visual & newChild) const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_InsertAtBottom(get_abi(newChild)));
}

template <typename D> void impl_IVisualCollection<D>::InsertAtTop(const Windows::UI::Composition::Visual & newChild) const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_InsertAtTop(get_abi(newChild)));
}

template <typename D> void impl_IVisualCollection<D>::InsertBelow(const Windows::UI::Composition::Visual & newChild, const Windows::UI::Composition::Visual & sibling) const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_InsertBelow(get_abi(newChild), get_abi(sibling)));
}

template <typename D> void impl_IVisualCollection<D>::Remove(const Windows::UI::Composition::Visual & child) const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_Remove(get_abi(child)));
}

template <typename D> void impl_IVisualCollection<D>::RemoveAll() const
{
    check_hresult(WINRT_SHIM(IVisualCollection)->abi_RemoveAll());
}

template <typename D> int32_t impl_IVisualUnorderedCollection<D>::Count() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IVisualUnorderedCollection)->get_Count(&value));
    return value;
}

template <typename D> void impl_IVisualUnorderedCollection<D>::Add(const Windows::UI::Composition::Visual & newVisual) const
{
    check_hresult(WINRT_SHIM(IVisualUnorderedCollection)->abi_Add(get_abi(newVisual)));
}

template <typename D> void impl_IVisualUnorderedCollection<D>::Remove(const Windows::UI::Composition::Visual & visual) const
{
    check_hresult(WINRT_SHIM(IVisualUnorderedCollection)->abi_Remove(get_abi(visual)));
}

template <typename D> void impl_IVisualUnorderedCollection<D>::RemoveAll() const
{
    check_hresult(WINRT_SHIM(IVisualUnorderedCollection)->abi_RemoveAll());
}

inline CompositionEffectSourceParameter::CompositionEffectSourceParameter(hstring_view name) :
    CompositionEffectSourceParameter(get_activation_factory<CompositionEffectSourceParameter, ICompositionEffectSourceParameterFactory>().Create(name))
{}

inline Compositor::Compositor() :
    Compositor(activate_instance<Compositor>())
{}

}

}
#pragma warning(pop)
