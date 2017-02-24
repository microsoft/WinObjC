// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Pickers.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileOpenPicker> : produce_base<D, Windows::Storage::Pickers::IFileOpenPicker>
{
    HRESULT __stdcall get_ViewMode(Windows::Storage::Pickers::PickerViewMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ViewMode(Windows::Storage::Pickers::PickerViewMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SettingsIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SettingsIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SettingsIdentifier(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedStartLocation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommitButtonText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommitButtonText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommitButtonText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileTypeFilter(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypeFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleFileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> pickSingleFileOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSingleFileOperation = detach_abi(this->shim().PickSingleFileAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickSingleFileOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickMultipleFilesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>>> pickMultipleFilesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickMultipleFilesOperation = detach_abi(this->shim().PickMultipleFilesAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickMultipleFilesOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileOpenPicker2> : produce_base<D, Windows::Storage::Pickers::IFileOpenPicker2>
{
    HRESULT __stdcall get_ContinuationData(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContinuationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleFileAndContinue() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickSingleFileAndContinue();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickMultipleFilesAndContinue() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickMultipleFilesAndContinue();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileOpenPickerStatics> : produce_base<D, Windows::Storage::Pickers::IFileOpenPickerStatics>
{
    HRESULT __stdcall abi_ResumePickSingleFileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> pickSingleFileOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSingleFileOperation = detach_abi(this->shim().ResumePickSingleFileAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickSingleFileOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileOpenPickerWithOperationId> : produce_base<D, Windows::Storage::Pickers::IFileOpenPickerWithOperationId>
{
    HRESULT __stdcall abi_PickSingleFileAsync(impl::abi_arg_in<hstring> pickerOperationId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> pickSingleFileOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSingleFileOperation = detach_abi(this->shim().PickSingleFileAsync(*reinterpret_cast<const hstring *>(&pickerOperationId)));
            return S_OK;
        }
        catch (...)
        {
            *pickSingleFileOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileSavePicker> : produce_base<D, Windows::Storage::Pickers::IFileSavePicker>
{
    HRESULT __stdcall get_SettingsIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SettingsIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SettingsIdentifier(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedStartLocation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommitButtonText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommitButtonText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommitButtonText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileTypeChoices(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypeChoices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultFileExtension(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultFileExtension());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultFileExtension(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultFileExtension(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedSaveFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedSaveFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedSaveFile(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedSaveFile(*reinterpret_cast<const Windows::Storage::StorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedFileName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedFileName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedFileName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedFileName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSaveFileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> pickSaveFileOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSaveFileOperation = detach_abi(this->shim().PickSaveFileAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickSaveFileOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileSavePicker2> : produce_base<D, Windows::Storage::Pickers::IFileSavePicker2>
{
    HRESULT __stdcall get_ContinuationData(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContinuationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSaveFileAndContinue() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickSaveFileAndContinue();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFileSavePicker3> : produce_base<D, Windows::Storage::Pickers::IFileSavePicker3>
{
    HRESULT __stdcall get_EnterpriseId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnterpriseId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnterpriseId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnterpriseId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFolderPicker> : produce_base<D, Windows::Storage::Pickers::IFolderPicker>
{
    HRESULT __stdcall get_ViewMode(Windows::Storage::Pickers::PickerViewMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ViewMode(Windows::Storage::Pickers::PickerViewMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SettingsIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SettingsIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SettingsIdentifier(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SettingsIdentifier(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedStartLocation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedStartLocation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommitButtonText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommitButtonText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommitButtonText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitButtonText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileTypeFilter(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileTypeFilter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleFolderAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> pickSingleFolderOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSingleFolderOperation = detach_abi(this->shim().PickSingleFolderAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickSingleFolderOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Pickers::IFolderPicker2> : produce_base<D, Windows::Storage::Pickers::IFolderPicker2>
{
    HRESULT __stdcall get_ContinuationData(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContinuationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickFolderAndContinue() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PickFolderAndContinue();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::Pickers {

template <typename D> Windows::Storage::Pickers::PickerViewMode impl_IFileOpenPicker<D>::ViewMode() const
{
    Windows::Storage::Pickers::PickerViewMode value {};
    check_hresult(WINRT_SHIM(IFileOpenPicker)->get_ViewMode(&value));
    return value;
}

template <typename D> void impl_IFileOpenPicker<D>::ViewMode(Windows::Storage::Pickers::PickerViewMode value) const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker)->put_ViewMode(value));
}

template <typename D> hstring impl_IFileOpenPicker<D>::SettingsIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileOpenPicker)->get_SettingsIdentifier(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileOpenPicker<D>::SettingsIdentifier(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker)->put_SettingsIdentifier(get_abi(value)));
}

template <typename D> Windows::Storage::Pickers::PickerLocationId impl_IFileOpenPicker<D>::SuggestedStartLocation() const
{
    Windows::Storage::Pickers::PickerLocationId value {};
    check_hresult(WINRT_SHIM(IFileOpenPicker)->get_SuggestedStartLocation(&value));
    return value;
}

template <typename D> void impl_IFileOpenPicker<D>::SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker)->put_SuggestedStartLocation(value));
}

template <typename D> hstring impl_IFileOpenPicker<D>::CommitButtonText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileOpenPicker)->get_CommitButtonText(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileOpenPicker<D>::CommitButtonText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker)->put_CommitButtonText(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IFileOpenPicker<D>::FileTypeFilter() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IFileOpenPicker)->get_FileTypeFilter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IFileOpenPicker<D>::PickSingleFileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> pickSingleFileOperation;
    check_hresult(WINRT_SHIM(IFileOpenPicker)->abi_PickSingleFileAsync(put_abi(pickSingleFileOperation)));
    return pickSingleFileOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> impl_IFileOpenPicker<D>::PickMultipleFilesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> pickMultipleFilesOperation;
    check_hresult(WINRT_SHIM(IFileOpenPicker)->abi_PickMultipleFilesAsync(put_abi(pickMultipleFilesOperation)));
    return pickMultipleFilesOperation;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IFileOpenPicker2<D>::ContinuationData() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IFileOpenPicker2)->get_ContinuationData(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileOpenPicker2<D>::PickSingleFileAndContinue() const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker2)->abi_PickSingleFileAndContinue());
}

template <typename D> void impl_IFileOpenPicker2<D>::PickMultipleFilesAndContinue() const
{
    check_hresult(WINRT_SHIM(IFileOpenPicker2)->abi_PickMultipleFilesAndContinue());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IFileOpenPickerWithOperationId<D>::PickSingleFileAsync(hstring_view pickerOperationId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> pickSingleFileOperation;
    check_hresult(WINRT_SHIM(IFileOpenPickerWithOperationId)->abi_PickSingleFileAsync(get_abi(pickerOperationId), put_abi(pickSingleFileOperation)));
    return pickSingleFileOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IFileOpenPickerStatics<D>::ResumePickSingleFileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> pickSingleFileOperation;
    check_hresult(WINRT_SHIM(IFileOpenPickerStatics)->abi_ResumePickSingleFileAsync(put_abi(pickSingleFileOperation)));
    return pickSingleFileOperation;
}

template <typename D> hstring impl_IFileSavePicker<D>::SettingsIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_SettingsIdentifier(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::SettingsIdentifier(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_SettingsIdentifier(get_abi(value)));
}

template <typename D> Windows::Storage::Pickers::PickerLocationId impl_IFileSavePicker<D>::SuggestedStartLocation() const
{
    Windows::Storage::Pickers::PickerLocationId value {};
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_SuggestedStartLocation(&value));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_SuggestedStartLocation(value));
}

template <typename D> hstring impl_IFileSavePicker<D>::CommitButtonText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_CommitButtonText(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::CommitButtonText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_CommitButtonText(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> impl_IFileSavePicker<D>::FileTypeChoices() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> value;
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_FileTypeChoices(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileSavePicker<D>::DefaultFileExtension() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_DefaultFileExtension(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::DefaultFileExtension(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_DefaultFileExtension(get_abi(value)));
}

template <typename D> Windows::Storage::StorageFile impl_IFileSavePicker<D>::SuggestedSaveFile() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_SuggestedSaveFile(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::SuggestedSaveFile(const Windows::Storage::StorageFile & value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_SuggestedSaveFile(get_abi(value)));
}

template <typename D> hstring impl_IFileSavePicker<D>::SuggestedFileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePicker)->get_SuggestedFileName(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker<D>::SuggestedFileName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker)->put_SuggestedFileName(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IFileSavePicker<D>::PickSaveFileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> pickSaveFileOperation;
    check_hresult(WINRT_SHIM(IFileSavePicker)->abi_PickSaveFileAsync(put_abi(pickSaveFileOperation)));
    return pickSaveFileOperation;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IFileSavePicker2<D>::ContinuationData() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IFileSavePicker2)->get_ContinuationData(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker2<D>::PickSaveFileAndContinue() const
{
    check_hresult(WINRT_SHIM(IFileSavePicker2)->abi_PickSaveFileAndContinue());
}

template <typename D> hstring impl_IFileSavePicker3<D>::EnterpriseId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePicker3)->get_EnterpriseId(put_abi(value)));
    return value;
}

template <typename D> void impl_IFileSavePicker3<D>::EnterpriseId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFileSavePicker3)->put_EnterpriseId(get_abi(value)));
}

template <typename D> Windows::Storage::Pickers::PickerViewMode impl_IFolderPicker<D>::ViewMode() const
{
    Windows::Storage::Pickers::PickerViewMode value {};
    check_hresult(WINRT_SHIM(IFolderPicker)->get_ViewMode(&value));
    return value;
}

template <typename D> void impl_IFolderPicker<D>::ViewMode(Windows::Storage::Pickers::PickerViewMode value) const
{
    check_hresult(WINRT_SHIM(IFolderPicker)->put_ViewMode(value));
}

template <typename D> hstring impl_IFolderPicker<D>::SettingsIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFolderPicker)->get_SettingsIdentifier(put_abi(value)));
    return value;
}

template <typename D> void impl_IFolderPicker<D>::SettingsIdentifier(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFolderPicker)->put_SettingsIdentifier(get_abi(value)));
}

template <typename D> Windows::Storage::Pickers::PickerLocationId impl_IFolderPicker<D>::SuggestedStartLocation() const
{
    Windows::Storage::Pickers::PickerLocationId value {};
    check_hresult(WINRT_SHIM(IFolderPicker)->get_SuggestedStartLocation(&value));
    return value;
}

template <typename D> void impl_IFolderPicker<D>::SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId value) const
{
    check_hresult(WINRT_SHIM(IFolderPicker)->put_SuggestedStartLocation(value));
}

template <typename D> hstring impl_IFolderPicker<D>::CommitButtonText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFolderPicker)->get_CommitButtonText(put_abi(value)));
    return value;
}

template <typename D> void impl_IFolderPicker<D>::CommitButtonText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFolderPicker)->put_CommitButtonText(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IFolderPicker<D>::FileTypeFilter() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IFolderPicker)->get_FileTypeFilter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IFolderPicker<D>::PickSingleFolderAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> pickSingleFolderOperation;
    check_hresult(WINRT_SHIM(IFolderPicker)->abi_PickSingleFolderAsync(put_abi(pickSingleFolderOperation)));
    return pickSingleFolderOperation;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IFolderPicker2<D>::ContinuationData() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IFolderPicker2)->get_ContinuationData(put_abi(value)));
    return value;
}

template <typename D> void impl_IFolderPicker2<D>::PickFolderAndContinue() const
{
    check_hresult(WINRT_SHIM(IFolderPicker2)->abi_PickFolderAndContinue());
}

inline FileOpenPicker::FileOpenPicker() :
    FileOpenPicker(activate_instance<FileOpenPicker>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> FileOpenPicker::ResumePickSingleFileAsync()
{
    return get_activation_factory<FileOpenPicker, IFileOpenPickerStatics>().ResumePickSingleFileAsync();
}

inline FileSavePicker::FileSavePicker() :
    FileSavePicker(activate_instance<FileSavePicker>())
{}

inline FolderPicker::FolderPicker() :
    FolderPicker(activate_instance<FolderPicker>())
{}

}

}
#pragma warning(pop)
