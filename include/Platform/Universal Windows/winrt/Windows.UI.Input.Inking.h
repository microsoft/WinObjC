// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.Input.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.Input.Inking.3.h"
#include "Windows.UI.Input.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkDrawingAttributes> : produce_base<D, Windows::UI::Input::Inking::IInkDrawingAttributes>
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

    HRESULT __stdcall get_PenTip(Windows::UI::Input::Inking::PenTipShape * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PenTip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PenTip(Windows::UI::Input::Inking::PenTipShape value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PenTip(value);
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

    HRESULT __stdcall put_Size(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IgnorePressure(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IgnorePressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IgnorePressure(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IgnorePressure(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FitToCurve(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FitToCurve());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FitToCurve(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FitToCurve(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkDrawingAttributes2> : produce_base<D, Windows::UI::Input::Inking::IInkDrawingAttributes2>
{
    HRESULT __stdcall get_PenTipTransform(impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PenTipTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PenTipTransform(impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PenTipTransform(*reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DrawAsHighlighter(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DrawAsHighlighter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DrawAsHighlighter(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DrawAsHighlighter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkDrawingAttributes3> : produce_base<D, Windows::UI::Input::Inking::IInkDrawingAttributes3>
{
    HRESULT __stdcall get_Kind(Windows::UI::Input::Inking::InkDrawingAttributesKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PencilProperties(impl::abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PencilProperties());
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
struct produce<D, Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties> : produce_base<D, Windows::UI::Input::Inking::IInkDrawingAttributesPencilProperties>
{
    HRESULT __stdcall get_Opacity(double * value) noexcept override
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

    HRESULT __stdcall put_Opacity(double value) noexcept override
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
struct produce<D, Windows::UI::Input::Inking::IInkDrawingAttributesStatics> : produce_base<D, Windows::UI::Input::Inking::IInkDrawingAttributesStatics>
{
    HRESULT __stdcall abi_CreateForPencil(impl::abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributes> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateForPencil());
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
struct produce<D, Windows::UI::Input::Inking::IInkInputProcessingConfiguration> : produce_base<D, Windows::UI::Input::Inking::IInkInputProcessingConfiguration>
{
    HRESULT __stdcall get_Mode(Windows::UI::Input::Inking::InkInputProcessingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::UI::Input::Inking::InkInputProcessingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RightDragAction(Windows::UI::Input::Inking::InkInputRightDragAction * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RightDragAction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RightDragAction(Windows::UI::Input::Inking::InkInputRightDragAction value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightDragAction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkManager> : produce_base<D, Windows::UI::Input::Inking::IInkManager>
{
    HRESULT __stdcall get_Mode(Windows::UI::Input::Inking::InkManipulationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::UI::Input::Inking::InkManipulationMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessPointerDown(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessPointerDown(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessPointerUpdate(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint, impl::abi_arg_out<Windows::Foundation::IInspectable> updateInformation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updateInformation = detach_abi(this->shim().ProcessPointerUpdate(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint)));
            return S_OK;
        }
        catch (...)
        {
            *updateInformation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessPointerUp(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint, impl::abi_arg_out<Windows::Foundation::Rect> updateRectangle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updateRectangle = detach_abi(this->shim().ProcessPointerUp(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDefaultDrawingAttributes(impl::abi_arg_in<Windows::UI::Input::Inking::IInkDrawingAttributes> drawingAttributes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDefaultDrawingAttributes(*reinterpret_cast<const Windows::UI::Input::Inking::InkDrawingAttributes *>(&drawingAttributes));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RecognizeAsync2(Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>>> recognitionResults) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recognitionResults = detach_abi(this->shim().RecognizeAsync(recognitionTarget));
            return S_OK;
        }
        catch (...)
        {
            *recognitionResults = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkPoint> : produce_base<D, Windows::UI::Input::Inking::IInkPoint>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pressure(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkPointFactory> : produce_base<D, Windows::UI::Input::Inking::IInkPointFactory>
{
    HRESULT __stdcall abi_CreateInkPoint(impl::abi_arg_in<Windows::Foundation::Point> position, float pressure, impl::abi_arg_out<Windows::UI::Input::Inking::IInkPoint> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateInkPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&position), pressure));
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
struct produce<D, Windows::UI::Input::Inking::IInkPresenter> : produce_base<D, Windows::UI::Input::Inking::IInkPresenter>
{
    HRESULT __stdcall get_IsInputEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInputEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInputEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputDeviceTypes(Windows::UI::Core::CoreInputDeviceTypes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputDeviceTypes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InputDeviceTypes(Windows::UI::Core::CoreInputDeviceTypes value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputDeviceTypes(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnprocessedInput(impl::abi_arg_out<Windows::UI::Input::Inking::IInkUnprocessedInput> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnprocessedInput());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeInput(impl::abi_arg_out<Windows::UI::Input::Inking::IInkStrokeInput> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeInput());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputProcessingConfiguration(impl::abi_arg_out<Windows::UI::Input::Inking::IInkInputProcessingConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputProcessingConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeContainer(impl::abi_arg_out<Windows::UI::Input::Inking::IInkStrokeContainer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeContainer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeContainer(impl::abi_arg_in<Windows::UI::Input::Inking::IInkStrokeContainer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeContainer(*reinterpret_cast<const Windows::UI::Input::Inking::InkStrokeContainer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyDefaultDrawingAttributes(impl::abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributes> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CopyDefaultDrawingAttributes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateDefaultDrawingAttributes(impl::abi_arg_in<Windows::UI::Input::Inking::IInkDrawingAttributes> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateDefaultDrawingAttributes(*reinterpret_cast<const Windows::UI::Input::Inking::InkDrawingAttributes *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ActivateCustomDrying(impl::abi_arg_out<Windows::UI::Input::Inking::IInkSynchronizer> inkSynchronizer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inkSynchronizer = detach_abi(this->shim().ActivateCustomDrying());
            return S_OK;
        }
        catch (...)
        {
            *inkSynchronizer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPredefinedConfiguration(Windows::UI::Input::Inking::InkPresenterPredefinedConfiguration value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPredefinedConfiguration(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StrokesCollected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokesCollected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokesCollected(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokesCollected(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StrokesErased(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokesErased(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokesErased(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokesErased(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkPresenterRuler> : produce_base<D, Windows::UI::Input::Inking::IInkPresenterRuler>
{
    HRESULT __stdcall get_Length(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Width(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Width(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkPresenterRulerFactory> : produce_base<D, Windows::UI::Input::Inking::IInkPresenterRulerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Input::Inking::IInkPresenter> inkPresenter, impl::abi_arg_out<Windows::UI::Input::Inking::IInkPresenterRuler> inkPresenterRuler) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inkPresenterRuler = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Input::Inking::InkPresenter *>(&inkPresenter)));
            return S_OK;
        }
        catch (...)
        {
            *inkPresenterRuler = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkPresenterStencil> : produce_base<D, Windows::UI::Input::Inking::IInkPresenterStencil>
{
    HRESULT __stdcall get_Kind(Windows::UI::Input::Inking::InkPresenterStencilKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
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

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Transform(impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Transform(impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transform(*reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkRecognitionResult> : produce_base<D, Windows::UI::Input::Inking::IInkRecognitionResult>
{
    HRESULT __stdcall get_BoundingRect(impl::abi_arg_out<Windows::Foundation::Rect> boundingRect) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *boundingRect = detach_abi(this->shim().BoundingRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTextCandidates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> textCandidates) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textCandidates = detach_abi(this->shim().GetTextCandidates());
            return S_OK;
        }
        catch (...)
        {
            *textCandidates = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStrokes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke>> strokes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *strokes = detach_abi(this->shim().GetStrokes());
            return S_OK;
        }
        catch (...)
        {
            *strokes = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkRecognizer> : produce_base<D, Windows::UI::Input::Inking::IInkRecognizer>
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
struct produce<D, Windows::UI::Input::Inking::IInkRecognizerContainer> : produce_base<D, Windows::UI::Input::Inking::IInkRecognizerContainer>
{
    HRESULT __stdcall abi_SetDefaultRecognizer(impl::abi_arg_in<Windows::UI::Input::Inking::IInkRecognizer> recognizer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDefaultRecognizer(*reinterpret_cast<const Windows::UI::Input::Inking::InkRecognizer *>(&recognizer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RecognizeAsync(impl::abi_arg_in<Windows::UI::Input::Inking::IInkStrokeContainer> strokeCollection, Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>>> recognitionResults) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recognitionResults = detach_abi(this->shim().RecognizeAsync(*reinterpret_cast<const Windows::UI::Input::Inking::InkStrokeContainer *>(&strokeCollection), recognitionTarget));
            return S_OK;
        }
        catch (...)
        {
            *recognitionResults = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecognizers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognizer>> recognizerView) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recognizerView = detach_abi(this->shim().GetRecognizers());
            return S_OK;
        }
        catch (...)
        {
            *recognizerView = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStroke> : produce_base<D, Windows::UI::Input::Inking::IInkStroke>
{
    HRESULT __stdcall get_DrawingAttributes(impl::abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributes> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DrawingAttributes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DrawingAttributes(impl::abi_arg_in<Windows::UI::Input::Inking::IInkDrawingAttributes> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DrawingAttributes(*reinterpret_cast<const Windows::UI::Input::Inking::InkDrawingAttributes *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BoundingRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Selected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Selected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Selected(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Selected(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recognized(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recognized());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRenderingSegments(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStrokeRenderingSegment>> renderingSegments) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *renderingSegments = detach_abi(this->shim().GetRenderingSegments());
            return S_OK;
        }
        catch (...)
        {
            *renderingSegments = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::UI::Input::Inking::IInkStroke> clonedStroke) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *clonedStroke = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *clonedStroke = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStroke2> : produce_base<D, Windows::UI::Input::Inking::IInkStroke2>
{
    HRESULT __stdcall get_PointTransform(impl::abi_arg_out<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PointTransform(impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointTransform(*reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetInkPoints(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkPoint>> inkPoints) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inkPoints = detach_abi(this->shim().GetInkPoints());
            return S_OK;
        }
        catch (...)
        {
            *inkPoints = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStrokeBuilder> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeBuilder>
{
    HRESULT __stdcall abi_BeginStroke(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginStroke(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendToStroke(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint, impl::abi_arg_out<Windows::UI::Input::IPointerPoint> previousPointerPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousPointerPoint = detach_abi(this->shim().AppendToStroke(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint)));
            return S_OK;
        }
        catch (...)
        {
            *previousPointerPoint = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EndStroke(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint, impl::abi_arg_out<Windows::UI::Input::Inking::IInkStroke> stroke) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stroke = detach_abi(this->shim().EndStroke(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint)));
            return S_OK;
        }
        catch (...)
        {
            *stroke = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStroke(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> points, impl::abi_arg_out<Windows::UI::Input::Inking::IInkStroke> stroke) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stroke = detach_abi(this->shim().CreateStroke(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Point> *>(&points)));
            return S_OK;
        }
        catch (...)
        {
            *stroke = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDefaultDrawingAttributes(impl::abi_arg_in<Windows::UI::Input::Inking::IInkDrawingAttributes> drawingAttributes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDefaultDrawingAttributes(*reinterpret_cast<const Windows::UI::Input::Inking::InkDrawingAttributes *>(&drawingAttributes));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStrokeBuilder2> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeBuilder2>
{
    HRESULT __stdcall abi_CreateStrokeFromInkPoints(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkPoint>> inkPoints, impl::abi_arg_in<Windows::Foundation::Numerics::float3x2> transform, impl::abi_arg_out<Windows::UI::Input::Inking::IInkStroke> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateStrokeFromInkPoints(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkPoint> *>(&inkPoints), *reinterpret_cast<const Windows::Foundation::Numerics::float3x2 *>(&transform)));
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
struct produce<D, Windows::UI::Input::Inking::IInkStrokeContainer> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeContainer>
{
    HRESULT __stdcall get_BoundingRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStroke(impl::abi_arg_in<Windows::UI::Input::Inking::IInkStroke> stroke) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStroke(*reinterpret_cast<const Windows::UI::Input::Inking::InkStroke *>(&stroke));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteSelected(impl::abi_arg_out<Windows::Foundation::Rect> invalidatedRect) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *invalidatedRect = detach_abi(this->shim().DeleteSelected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveSelected(impl::abi_arg_in<Windows::Foundation::Point> translation, impl::abi_arg_out<Windows::Foundation::Rect> invalidatedRectangle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *invalidatedRectangle = detach_abi(this->shim().MoveSelected(*reinterpret_cast<const Windows::Foundation::Point *>(&translation)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectWithPolyLine(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> polyline, impl::abi_arg_out<Windows::Foundation::Rect> invalidatedRectangle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *invalidatedRectangle = detach_abi(this->shim().SelectWithPolyLine(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Point> *>(&polyline)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectWithLine(impl::abi_arg_in<Windows::Foundation::Point> from, impl::abi_arg_in<Windows::Foundation::Point> to, impl::abi_arg_out<Windows::Foundation::Rect> invalidatedRectangle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *invalidatedRectangle = detach_abi(this->shim().SelectWithLine(*reinterpret_cast<const Windows::Foundation::Point *>(&from), *reinterpret_cast<const Windows::Foundation::Point *>(&to)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopySelectedToClipboard() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopySelectedToClipboard();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PasteFromClipboard(impl::abi_arg_in<Windows::Foundation::Point> position, impl::abi_arg_out<Windows::Foundation::Rect> invalidatedRectangle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *invalidatedRectangle = detach_abi(this->shim().PasteFromClipboard(*reinterpret_cast<const Windows::Foundation::Point *>(&position)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanPasteFromClipboard(bool * canPaste) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *canPaste = detach_abi(this->shim().CanPasteFromClipboard());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> inputStream, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<uint64_t>> loadAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadAction = detach_abi(this->shim().LoadAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&inputStream)));
            return S_OK;
        }
        catch (...)
        {
            *loadAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> outputStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t>> outputStreamOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outputStreamOperation = detach_abi(this->shim().SaveAsync(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&outputStream)));
            return S_OK;
        }
        catch (...)
        {
            *outputStreamOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateRecognitionResults(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> recognitionResults) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateRecognitionResults(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> *>(&recognitionResults));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStrokes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke>> strokeView) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *strokeView = detach_abi(this->shim().GetStrokes());
            return S_OK;
        }
        catch (...)
        {
            *strokeView = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecognitionResults(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> recognitionResults) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recognitionResults = detach_abi(this->shim().GetRecognitionResults());
            return S_OK;
        }
        catch (...)
        {
            *recognitionResults = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStrokeContainer2> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeContainer2>
{
    HRESULT __stdcall abi_AddStrokes(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkStroke>> strokes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStrokes(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::UI::Input::Inking::InkStroke> *>(&strokes));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStrokeInput> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeInput>
{
    HRESULT __stdcall add_StrokeStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokeStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokeStarted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeStarted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StrokeContinued(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokeContinued(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokeContinued(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeContinued(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StrokeEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokeEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokeEnded(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeEnded(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StrokeCanceled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StrokeCanceled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StrokeCanceled(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeCanceled(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InkPresenter(impl::abi_arg_out<Windows::UI::Input::Inking::IInkPresenter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InkPresenter());
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
struct produce<D, Windows::UI::Input::Inking::IInkStrokeRenderingSegment> : produce_base<D, Windows::UI::Input::Inking::IInkStrokeRenderingSegment>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BezierControlPoint1(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BezierControlPoint1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BezierControlPoint2(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BezierControlPoint2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pressure(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiltX(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiltX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiltY(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiltY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Twist(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Twist());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs> : produce_base<D, Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs>
{
    HRESULT __stdcall get_Strokes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Strokes());
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
struct produce<D, Windows::UI::Input::Inking::IInkStrokesErasedEventArgs> : produce_base<D, Windows::UI::Input::Inking::IInkStrokesErasedEventArgs>
{
    HRESULT __stdcall get_Strokes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Strokes());
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
struct produce<D, Windows::UI::Input::Inking::IInkSynchronizer> : produce_base<D, Windows::UI::Input::Inking::IInkSynchronizer>
{
    HRESULT __stdcall abi_BeginDry(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke>> inkStrokes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inkStrokes = detach_abi(this->shim().BeginDry());
            return S_OK;
        }
        catch (...)
        {
            *inkStrokes = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EndDry() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndDry();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::IInkUnprocessedInput> : produce_base<D, Windows::UI::Input::Inking::IInkUnprocessedInput>
{
    HRESULT __stdcall add_PointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerEntered(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerHovered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerHovered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerHovered(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerHovered(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerExited(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerPressed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerPressed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerMoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerMoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerMoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerReleased(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerReleased(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerReleased(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerLost(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerLost(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InkPresenter(impl::abi_arg_out<Windows::UI::Input::Inking::IInkPresenter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InkPresenter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Input::Inking {

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> impl_IInkStrokesCollectedEventArgs<D>::Strokes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> value;
    check_hresult(WINRT_SHIM(IInkStrokesCollectedEventArgs)->get_Strokes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> impl_IInkStrokesErasedEventArgs<D>::Strokes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> value;
    check_hresult(WINRT_SHIM(IInkStrokesErasedEventArgs)->get_Strokes(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInkPresenter<D>::IsInputEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkPresenter)->get_IsInputEnabled(&value));
    return value;
}

template <typename D> void impl_IInkPresenter<D>::IsInputEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->put_IsInputEnabled(value));
}

template <typename D> Windows::UI::Core::CoreInputDeviceTypes impl_IInkPresenter<D>::InputDeviceTypes() const
{
    Windows::UI::Core::CoreInputDeviceTypes value {};
    check_hresult(WINRT_SHIM(IInkPresenter)->get_InputDeviceTypes(&value));
    return value;
}

template <typename D> void impl_IInkPresenter<D>::InputDeviceTypes(Windows::UI::Core::CoreInputDeviceTypes value) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->put_InputDeviceTypes(value));
}

template <typename D> Windows::UI::Input::Inking::InkUnprocessedInput impl_IInkPresenter<D>::UnprocessedInput() const
{
    Windows::UI::Input::Inking::InkUnprocessedInput value { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->get_UnprocessedInput(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkStrokeInput impl_IInkPresenter<D>::StrokeInput() const
{
    Windows::UI::Input::Inking::InkStrokeInput value { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->get_StrokeInput(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkInputProcessingConfiguration impl_IInkPresenter<D>::InputProcessingConfiguration() const
{
    Windows::UI::Input::Inking::InkInputProcessingConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->get_InputProcessingConfiguration(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkStrokeContainer impl_IInkPresenter<D>::StrokeContainer() const
{
    Windows::UI::Input::Inking::InkStrokeContainer value { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->get_StrokeContainer(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkPresenter<D>::StrokeContainer(const Windows::UI::Input::Inking::InkStrokeContainer & value) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->put_StrokeContainer(get_abi(value)));
}

template <typename D> Windows::UI::Input::Inking::InkDrawingAttributes impl_IInkPresenter<D>::CopyDefaultDrawingAttributes() const
{
    Windows::UI::Input::Inking::InkDrawingAttributes value { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->abi_CopyDefaultDrawingAttributes(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkPresenter<D>::UpdateDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & value) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->abi_UpdateDefaultDrawingAttributes(get_abi(value)));
}

template <typename D> Windows::UI::Input::Inking::InkSynchronizer impl_IInkPresenter<D>::ActivateCustomDrying() const
{
    Windows::UI::Input::Inking::InkSynchronizer inkSynchronizer { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenter)->abi_ActivateCustomDrying(put_abi(inkSynchronizer)));
    return inkSynchronizer;
}

template <typename D> void impl_IInkPresenter<D>::SetPredefinedConfiguration(Windows::UI::Input::Inking::InkPresenterPredefinedConfiguration value) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->abi_SetPredefinedConfiguration(value));
}

template <typename D> event_token impl_IInkPresenter<D>::StrokesCollected(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkPresenter)->add_StrokesCollected(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkPresenter> impl_IInkPresenter<D>::StrokesCollected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesCollectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkPresenter>(this, &ABI::Windows::UI::Input::Inking::IInkPresenter::remove_StrokesCollected, StrokesCollected(handler));
}

template <typename D> void impl_IInkPresenter<D>::StrokesCollected(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->remove_StrokesCollected(cookie));
}

template <typename D> event_token impl_IInkPresenter<D>::StrokesErased(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkPresenter)->add_StrokesErased(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkPresenter> impl_IInkPresenter<D>::StrokesErased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkPresenter, Windows::UI::Input::Inking::InkStrokesErasedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkPresenter>(this, &ABI::Windows::UI::Input::Inking::IInkPresenter::remove_StrokesErased, StrokesErased(handler));
}

template <typename D> void impl_IInkPresenter<D>::StrokesErased(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkPresenter)->remove_StrokesErased(cookie));
}

template <typename D> Windows::UI::Input::Inking::InkInputProcessingMode impl_IInkInputProcessingConfiguration<D>::Mode() const
{
    Windows::UI::Input::Inking::InkInputProcessingMode value {};
    check_hresult(WINRT_SHIM(IInkInputProcessingConfiguration)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IInkInputProcessingConfiguration<D>::Mode(Windows::UI::Input::Inking::InkInputProcessingMode value) const
{
    check_hresult(WINRT_SHIM(IInkInputProcessingConfiguration)->put_Mode(value));
}

template <typename D> Windows::UI::Input::Inking::InkInputRightDragAction impl_IInkInputProcessingConfiguration<D>::RightDragAction() const
{
    Windows::UI::Input::Inking::InkInputRightDragAction value {};
    check_hresult(WINRT_SHIM(IInkInputProcessingConfiguration)->get_RightDragAction(&value));
    return value;
}

template <typename D> void impl_IInkInputProcessingConfiguration<D>::RightDragAction(Windows::UI::Input::Inking::InkInputRightDragAction value) const
{
    check_hresult(WINRT_SHIM(IInkInputProcessingConfiguration)->put_RightDragAction(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> impl_IInkSynchronizer<D>::BeginDry() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> inkStrokes;
    check_hresult(WINRT_SHIM(IInkSynchronizer)->abi_BeginDry(put_abi(inkStrokes)));
    return inkStrokes;
}

template <typename D> void impl_IInkSynchronizer<D>::EndDry() const
{
    check_hresult(WINRT_SHIM(IInkSynchronizer)->abi_EndDry());
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerEntered(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerEntered, PointerEntered(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerEntered(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerEntered(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerHovered(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerHovered(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerHovered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerHovered, PointerHovered(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerHovered(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerHovered(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerExited(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerExited, PointerExited(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerExited(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerExited(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerPressed(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerPressed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerPressed, PointerPressed(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerPressed(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerMoved(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerMoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerMoved, PointerMoved(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerMoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerMoved(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerReleased(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerReleased(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerReleased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerReleased, PointerReleased(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerReleased(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerReleased(cookie));
}

template <typename D> event_token impl_IInkUnprocessedInput<D>::PointerLost(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->add_PointerLost(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkUnprocessedInput> impl_IInkUnprocessedInput<D>::PointerLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkUnprocessedInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkUnprocessedInput>(this, &ABI::Windows::UI::Input::Inking::IInkUnprocessedInput::remove_PointerLost, PointerLost(handler));
}

template <typename D> void impl_IInkUnprocessedInput<D>::PointerLost(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->remove_PointerLost(cookie));
}

template <typename D> Windows::UI::Input::Inking::InkPresenter impl_IInkUnprocessedInput<D>::InkPresenter() const
{
    Windows::UI::Input::Inking::InkPresenter value { nullptr };
    check_hresult(WINRT_SHIM(IInkUnprocessedInput)->get_InkPresenter(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IInkStrokeInput<D>::StrokeStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkStrokeInput)->add_StrokeStarted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkStrokeInput> impl_IInkStrokeInput<D>::StrokeStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkStrokeInput>(this, &ABI::Windows::UI::Input::Inking::IInkStrokeInput::remove_StrokeStarted, StrokeStarted(handler));
}

template <typename D> void impl_IInkStrokeInput<D>::StrokeStarted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkStrokeInput)->remove_StrokeStarted(cookie));
}

template <typename D> event_token impl_IInkStrokeInput<D>::StrokeContinued(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkStrokeInput)->add_StrokeContinued(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkStrokeInput> impl_IInkStrokeInput<D>::StrokeContinued(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkStrokeInput>(this, &ABI::Windows::UI::Input::Inking::IInkStrokeInput::remove_StrokeContinued, StrokeContinued(handler));
}

template <typename D> void impl_IInkStrokeInput<D>::StrokeContinued(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkStrokeInput)->remove_StrokeContinued(cookie));
}

template <typename D> event_token impl_IInkStrokeInput<D>::StrokeEnded(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkStrokeInput)->add_StrokeEnded(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkStrokeInput> impl_IInkStrokeInput<D>::StrokeEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkStrokeInput>(this, &ABI::Windows::UI::Input::Inking::IInkStrokeInput::remove_StrokeEnded, StrokeEnded(handler));
}

template <typename D> void impl_IInkStrokeInput<D>::StrokeEnded(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkStrokeInput)->remove_StrokeEnded(cookie));
}

template <typename D> event_token impl_IInkStrokeInput<D>::StrokeCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IInkStrokeInput)->add_StrokeCanceled(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IInkStrokeInput> impl_IInkStrokeInput<D>::StrokeCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::InkStrokeInput, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInkStrokeInput>(this, &ABI::Windows::UI::Input::Inking::IInkStrokeInput::remove_StrokeCanceled, StrokeCanceled(handler));
}

template <typename D> void impl_IInkStrokeInput<D>::StrokeCanceled(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IInkStrokeInput)->remove_StrokeCanceled(cookie));
}

template <typename D> Windows::UI::Input::Inking::InkPresenter impl_IInkStrokeInput<D>::InkPresenter() const
{
    Windows::UI::Input::Inking::InkPresenter value { nullptr };
    check_hresult(WINRT_SHIM(IInkStrokeInput)->get_InkPresenter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkPresenterStencilKind impl_IInkPresenterStencil<D>::Kind() const
{
    Windows::UI::Input::Inking::InkPresenterStencilKind value {};
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->get_Kind(&value));
    return value;
}

template <typename D> bool impl_IInkPresenterStencil<D>::IsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->get_IsVisible(&value));
    return value;
}

template <typename D> void impl_IInkPresenterStencil<D>::IsVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->put_IsVisible(value));
}

template <typename D> Windows::UI::Color impl_IInkPresenterStencil<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkPresenterStencil<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IInkPresenterStencil<D>::ForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkPresenterStencil<D>::ForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->put_ForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3x2 impl_IInkPresenterStencil<D>::Transform() const
{
    Windows::Foundation::Numerics::float3x2 value {};
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->get_Transform(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkPresenterStencil<D>::Transform(const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterStencil)->put_Transform(get_abi(value)));
}

template <typename D> double impl_IInkPresenterRuler<D>::Length() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInkPresenterRuler)->get_Length(&value));
    return value;
}

template <typename D> void impl_IInkPresenterRuler<D>::Length(double value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterRuler)->put_Length(value));
}

template <typename D> double impl_IInkPresenterRuler<D>::Width() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInkPresenterRuler)->get_Width(&value));
    return value;
}

template <typename D> void impl_IInkPresenterRuler<D>::Width(double value) const
{
    check_hresult(WINRT_SHIM(IInkPresenterRuler)->put_Width(value));
}

template <typename D> Windows::UI::Input::Inking::InkPresenterRuler impl_IInkPresenterRulerFactory<D>::Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const
{
    Windows::UI::Input::Inking::InkPresenterRuler inkPresenterRuler { nullptr };
    check_hresult(WINRT_SHIM(IInkPresenterRulerFactory)->abi_Create(get_abi(inkPresenter), put_abi(inkPresenterRuler)));
    return inkPresenterRuler;
}

template <typename D> Windows::Foundation::Point impl_IInkPoint<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IInkPoint)->get_Position(put_abi(value)));
    return value;
}

template <typename D> float impl_IInkPoint<D>::Pressure() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInkPoint)->get_Pressure(&value));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkPoint impl_IInkPointFactory<D>::CreateInkPoint(const Windows::Foundation::Point & position, float pressure) const
{
    Windows::UI::Input::Inking::InkPoint result { nullptr };
    check_hresult(WINRT_SHIM(IInkPointFactory)->abi_CreateInkPoint(get_abi(position), pressure, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Color impl_IInkDrawingAttributes<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->put_Color(get_abi(value)));
}

template <typename D> Windows::UI::Input::Inking::PenTipShape impl_IInkDrawingAttributes<D>::PenTip() const
{
    Windows::UI::Input::Inking::PenTipShape value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->get_PenTip(&value));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes<D>::PenTip(Windows::UI::Input::Inking::PenTipShape value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->put_PenTip(value));
}

template <typename D> Windows::Foundation::Size impl_IInkDrawingAttributes<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->get_Size(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes<D>::Size(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->put_Size(get_abi(value)));
}

template <typename D> bool impl_IInkDrawingAttributes<D>::IgnorePressure() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->get_IgnorePressure(&value));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes<D>::IgnorePressure(bool value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->put_IgnorePressure(value));
}

template <typename D> bool impl_IInkDrawingAttributes<D>::FitToCurve() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->get_FitToCurve(&value));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes<D>::FitToCurve(bool value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes)->put_FitToCurve(value));
}

template <typename D> Windows::Foundation::Numerics::float3x2 impl_IInkDrawingAttributes2<D>::PenTipTransform() const
{
    Windows::Foundation::Numerics::float3x2 value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes2)->get_PenTipTransform(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes2<D>::PenTipTransform(const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes2)->put_PenTipTransform(get_abi(value)));
}

template <typename D> bool impl_IInkDrawingAttributes2<D>::DrawAsHighlighter() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes2)->get_DrawAsHighlighter(&value));
    return value;
}

template <typename D> void impl_IInkDrawingAttributes2<D>::DrawAsHighlighter(bool value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributes2)->put_DrawAsHighlighter(value));
}

template <typename D> double impl_IInkDrawingAttributesPencilProperties<D>::Opacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributesPencilProperties)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IInkDrawingAttributesPencilProperties<D>::Opacity(double value) const
{
    check_hresult(WINRT_SHIM(IInkDrawingAttributesPencilProperties)->put_Opacity(value));
}

template <typename D> Windows::UI::Input::Inking::InkDrawingAttributesKind impl_IInkDrawingAttributes3<D>::Kind() const
{
    Windows::UI::Input::Inking::InkDrawingAttributesKind value {};
    check_hresult(WINRT_SHIM(IInkDrawingAttributes3)->get_Kind(&value));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties impl_IInkDrawingAttributes3<D>::PencilProperties() const
{
    Windows::UI::Input::Inking::InkDrawingAttributesPencilProperties value { nullptr };
    check_hresult(WINRT_SHIM(IInkDrawingAttributes3)->get_PencilProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkDrawingAttributes impl_IInkDrawingAttributesStatics<D>::CreateForPencil() const
{
    Windows::UI::Input::Inking::InkDrawingAttributes result { nullptr };
    check_hresult(WINRT_SHIM(IInkDrawingAttributesStatics)->abi_CreateForPencil(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Point impl_IInkStrokeRenderingSegment<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IInkStrokeRenderingSegment<D>::BezierControlPoint1() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_BezierControlPoint1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IInkStrokeRenderingSegment<D>::BezierControlPoint2() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_BezierControlPoint2(put_abi(value)));
    return value;
}

template <typename D> float impl_IInkStrokeRenderingSegment<D>::Pressure() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_Pressure(&value));
    return value;
}

template <typename D> float impl_IInkStrokeRenderingSegment<D>::TiltX() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_TiltX(&value));
    return value;
}

template <typename D> float impl_IInkStrokeRenderingSegment<D>::TiltY() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_TiltY(&value));
    return value;
}

template <typename D> float impl_IInkStrokeRenderingSegment<D>::Twist() const
{
    float value {};
    check_hresult(WINRT_SHIM(IInkStrokeRenderingSegment)->get_Twist(&value));
    return value;
}

template <typename D> Windows::UI::Input::Inking::InkDrawingAttributes impl_IInkStroke<D>::DrawingAttributes() const
{
    Windows::UI::Input::Inking::InkDrawingAttributes value { nullptr };
    check_hresult(WINRT_SHIM(IInkStroke)->get_DrawingAttributes(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkStroke<D>::DrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & value) const
{
    check_hresult(WINRT_SHIM(IInkStroke)->put_DrawingAttributes(get_abi(value)));
}

template <typename D> Windows::Foundation::Rect impl_IInkStroke<D>::BoundingRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IInkStroke)->get_BoundingRect(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInkStroke<D>::Selected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkStroke)->get_Selected(&value));
    return value;
}

template <typename D> void impl_IInkStroke<D>::Selected(bool value) const
{
    check_hresult(WINRT_SHIM(IInkStroke)->put_Selected(value));
}

template <typename D> bool impl_IInkStroke<D>::Recognized() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInkStroke)->get_Recognized(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStrokeRenderingSegment> impl_IInkStroke<D>::GetRenderingSegments() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStrokeRenderingSegment> renderingSegments;
    check_hresult(WINRT_SHIM(IInkStroke)->abi_GetRenderingSegments(put_abi(renderingSegments)));
    return renderingSegments;
}

template <typename D> Windows::UI::Input::Inking::InkStroke impl_IInkStroke<D>::Clone() const
{
    Windows::UI::Input::Inking::InkStroke clonedStroke { nullptr };
    check_hresult(WINRT_SHIM(IInkStroke)->abi_Clone(put_abi(clonedStroke)));
    return clonedStroke;
}

template <typename D> Windows::Foundation::Numerics::float3x2 impl_IInkStroke2<D>::PointTransform() const
{
    Windows::Foundation::Numerics::float3x2 value {};
    check_hresult(WINRT_SHIM(IInkStroke2)->get_PointTransform(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkStroke2<D>::PointTransform(const Windows::Foundation::Numerics::float3x2 & value) const
{
    check_hresult(WINRT_SHIM(IInkStroke2)->put_PointTransform(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkPoint> impl_IInkStroke2<D>::GetInkPoints() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkPoint> inkPoints;
    check_hresult(WINRT_SHIM(IInkStroke2)->abi_GetInkPoints(put_abi(inkPoints)));
    return inkPoints;
}

template <typename D> void impl_IInkStrokeBuilder<D>::BeginStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    check_hresult(WINRT_SHIM(IInkStrokeBuilder)->abi_BeginStroke(get_abi(pointerPoint)));
}

template <typename D> Windows::UI::Input::PointerPoint impl_IInkStrokeBuilder<D>::AppendToStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    Windows::UI::Input::PointerPoint previousPointerPoint { nullptr };
    check_hresult(WINRT_SHIM(IInkStrokeBuilder)->abi_AppendToStroke(get_abi(pointerPoint), put_abi(previousPointerPoint)));
    return previousPointerPoint;
}

template <typename D> Windows::UI::Input::Inking::InkStroke impl_IInkStrokeBuilder<D>::EndStroke(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    Windows::UI::Input::Inking::InkStroke stroke { nullptr };
    check_hresult(WINRT_SHIM(IInkStrokeBuilder)->abi_EndStroke(get_abi(pointerPoint), put_abi(stroke)));
    return stroke;
}

template <typename D> Windows::UI::Input::Inking::InkStroke impl_IInkStrokeBuilder<D>::CreateStroke(iterable<Windows::Foundation::Point> points) const
{
    Windows::UI::Input::Inking::InkStroke stroke { nullptr };
    check_hresult(WINRT_SHIM(IInkStrokeBuilder)->abi_CreateStroke(get_abi(points), put_abi(stroke)));
    return stroke;
}

template <typename D> void impl_IInkStrokeBuilder<D>::SetDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & drawingAttributes) const
{
    check_hresult(WINRT_SHIM(IInkStrokeBuilder)->abi_SetDefaultDrawingAttributes(get_abi(drawingAttributes)));
}

template <typename D> Windows::UI::Input::Inking::InkStroke impl_IInkStrokeBuilder2<D>::CreateStrokeFromInkPoints(iterable<Windows::UI::Input::Inking::InkPoint> inkPoints, const Windows::Foundation::Numerics::float3x2 & transform) const
{
    Windows::UI::Input::Inking::InkStroke result { nullptr };
    check_hresult(WINRT_SHIM(IInkStrokeBuilder2)->abi_CreateStrokeFromInkPoints(get_abi(inkPoints), get_abi(transform), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Rect impl_IInkRecognitionResult<D>::BoundingRect() const
{
    Windows::Foundation::Rect boundingRect {};
    check_hresult(WINRT_SHIM(IInkRecognitionResult)->get_BoundingRect(put_abi(boundingRect)));
    return boundingRect;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IInkRecognitionResult<D>::GetTextCandidates() const
{
    Windows::Foundation::Collections::IVectorView<hstring> textCandidates;
    check_hresult(WINRT_SHIM(IInkRecognitionResult)->abi_GetTextCandidates(put_abi(textCandidates)));
    return textCandidates;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> impl_IInkRecognitionResult<D>::GetStrokes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> strokes;
    check_hresult(WINRT_SHIM(IInkRecognitionResult)->abi_GetStrokes(put_abi(strokes)));
    return strokes;
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::BoundingRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->get_BoundingRect(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkStrokeContainer<D>::AddStroke(const Windows::UI::Input::Inking::InkStroke & stroke) const
{
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_AddStroke(get_abi(stroke)));
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::DeleteSelected() const
{
    Windows::Foundation::Rect invalidatedRect {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_DeleteSelected(put_abi(invalidatedRect)));
    return invalidatedRect;
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::MoveSelected(const Windows::Foundation::Point & translation) const
{
    Windows::Foundation::Rect invalidatedRectangle {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_MoveSelected(get_abi(translation), put_abi(invalidatedRectangle)));
    return invalidatedRectangle;
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::SelectWithPolyLine(iterable<Windows::Foundation::Point> polyline) const
{
    Windows::Foundation::Rect invalidatedRectangle {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_SelectWithPolyLine(get_abi(polyline), put_abi(invalidatedRectangle)));
    return invalidatedRectangle;
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::SelectWithLine(const Windows::Foundation::Point & from, const Windows::Foundation::Point & to) const
{
    Windows::Foundation::Rect invalidatedRectangle {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_SelectWithLine(get_abi(from), get_abi(to), put_abi(invalidatedRectangle)));
    return invalidatedRectangle;
}

template <typename D> void impl_IInkStrokeContainer<D>::CopySelectedToClipboard() const
{
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_CopySelectedToClipboard());
}

template <typename D> Windows::Foundation::Rect impl_IInkStrokeContainer<D>::PasteFromClipboard(const Windows::Foundation::Point & position) const
{
    Windows::Foundation::Rect invalidatedRectangle {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_PasteFromClipboard(get_abi(position), put_abi(invalidatedRectangle)));
    return invalidatedRectangle;
}

template <typename D> bool impl_IInkStrokeContainer<D>::CanPasteFromClipboard() const
{
    bool canPaste {};
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_CanPasteFromClipboard(&canPaste));
    return canPaste;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<uint64_t> impl_IInkStrokeContainer<D>::LoadAsync(const Windows::Storage::Streams::IInputStream & inputStream) const
{
    Windows::Foundation::IAsyncActionWithProgress<uint64_t> loadAction;
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_LoadAsync(get_abi(inputStream), put_abi(loadAction)));
    return loadAction;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> impl_IInkStrokeContainer<D>::SaveAsync(const Windows::Storage::Streams::IOutputStream & outputStream) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> outputStreamOperation;
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_SaveAsync(get_abi(outputStream), put_abi(outputStreamOperation)));
    return outputStreamOperation;
}

template <typename D> void impl_IInkStrokeContainer<D>::UpdateRecognitionResults(vector_view<Windows::UI::Input::Inking::InkRecognitionResult> recognitionResults) const
{
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_UpdateRecognitionResults(get_abi(recognitionResults)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> impl_IInkStrokeContainer<D>::GetStrokes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkStroke> strokeView;
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_GetStrokes(put_abi(strokeView)));
    return strokeView;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> impl_IInkStrokeContainer<D>::GetRecognitionResults() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult> recognitionResults;
    check_hresult(WINRT_SHIM(IInkStrokeContainer)->abi_GetRecognitionResults(put_abi(recognitionResults)));
    return recognitionResults;
}

template <typename D> void impl_IInkStrokeContainer2<D>::AddStrokes(iterable<Windows::UI::Input::Inking::InkStroke> strokes) const
{
    check_hresult(WINRT_SHIM(IInkStrokeContainer2)->abi_AddStrokes(get_abi(strokes)));
}

template <typename D> void impl_IInkStrokeContainer2<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IInkStrokeContainer2)->abi_Clear());
}

template <typename D> hstring impl_IInkRecognizer<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IInkRecognizer)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IInkRecognizerContainer<D>::SetDefaultRecognizer(const Windows::UI::Input::Inking::InkRecognizer & recognizer) const
{
    check_hresult(WINRT_SHIM(IInkRecognizerContainer)->abi_SetDefaultRecognizer(get_abi(recognizer)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> impl_IInkRecognizerContainer<D>::RecognizeAsync(const Windows::UI::Input::Inking::InkStrokeContainer & strokeCollection, Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> recognitionResults;
    check_hresult(WINRT_SHIM(IInkRecognizerContainer)->abi_RecognizeAsync(get_abi(strokeCollection), recognitionTarget, put_abi(recognitionResults)));
    return recognitionResults;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognizer> impl_IInkRecognizerContainer<D>::GetRecognizers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognizer> recognizerView;
    check_hresult(WINRT_SHIM(IInkRecognizerContainer)->abi_GetRecognizers(put_abi(recognizerView)));
    return recognizerView;
}

template <typename D> Windows::UI::Input::Inking::InkManipulationMode impl_IInkManager<D>::Mode() const
{
    Windows::UI::Input::Inking::InkManipulationMode value {};
    check_hresult(WINRT_SHIM(IInkManager)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IInkManager<D>::Mode(Windows::UI::Input::Inking::InkManipulationMode value) const
{
    check_hresult(WINRT_SHIM(IInkManager)->put_Mode(value));
}

template <typename D> void impl_IInkManager<D>::ProcessPointerDown(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    check_hresult(WINRT_SHIM(IInkManager)->abi_ProcessPointerDown(get_abi(pointerPoint)));
}

template <typename D> Windows::Foundation::IInspectable impl_IInkManager<D>::ProcessPointerUpdate(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    Windows::Foundation::IInspectable updateInformation;
    check_hresult(WINRT_SHIM(IInkManager)->abi_ProcessPointerUpdate(get_abi(pointerPoint), put_abi(updateInformation)));
    return updateInformation;
}

template <typename D> Windows::Foundation::Rect impl_IInkManager<D>::ProcessPointerUp(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    Windows::Foundation::Rect updateRectangle {};
    check_hresult(WINRT_SHIM(IInkManager)->abi_ProcessPointerUp(get_abi(pointerPoint), put_abi(updateRectangle)));
    return updateRectangle;
}

template <typename D> void impl_IInkManager<D>::SetDefaultDrawingAttributes(const Windows::UI::Input::Inking::InkDrawingAttributes & drawingAttributes) const
{
    check_hresult(WINRT_SHIM(IInkManager)->abi_SetDefaultDrawingAttributes(get_abi(drawingAttributes)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> impl_IInkManager<D>::RecognizeAsync(Windows::UI::Input::Inking::InkRecognitionTarget recognitionTarget) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::UI::Input::Inking::InkRecognitionResult>> recognitionResults;
    check_hresult(WINRT_SHIM(IInkManager)->abi_RecognizeAsync2(recognitionTarget, put_abi(recognitionResults)));
    return recognitionResults;
}

inline InkDrawingAttributes::InkDrawingAttributes() :
    InkDrawingAttributes(activate_instance<InkDrawingAttributes>())
{}

inline Windows::UI::Input::Inking::InkDrawingAttributes InkDrawingAttributes::CreateForPencil()
{
    return get_activation_factory<InkDrawingAttributes, IInkDrawingAttributesStatics>().CreateForPencil();
}

inline InkManager::InkManager() :
    InkManager(activate_instance<InkManager>())
{}

inline InkPoint::InkPoint(const Windows::Foundation::Point & position, float pressure) :
    InkPoint(get_activation_factory<InkPoint, IInkPointFactory>().CreateInkPoint(position, pressure))
{}

inline InkPresenterRuler::InkPresenterRuler(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) :
    InkPresenterRuler(get_activation_factory<InkPresenterRuler, IInkPresenterRulerFactory>().Create(inkPresenter))
{}

inline InkRecognizerContainer::InkRecognizerContainer() :
    InkRecognizerContainer(activate_instance<InkRecognizerContainer>())
{}

inline InkStrokeBuilder::InkStrokeBuilder() :
    InkStrokeBuilder(activate_instance<InkStrokeBuilder>())
{}

inline InkStrokeContainer::InkStrokeContainer() :
    InkStrokeContainer(activate_instance<InkStrokeContainer>())
{}

}

}
#pragma warning(pop)
