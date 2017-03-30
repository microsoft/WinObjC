// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.DataTransfer.DragDrop.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

struct WINRT_EBO CoreDragDropManager :
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager
{
    CoreDragDropManager(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager GetForCurrentView();
};

struct WINRT_EBO CoreDragInfo :
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo,
    impl::require<CoreDragInfo, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2>
{
    CoreDragInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreDragOperation :
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation,
    impl::require<CoreDragOperation, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2>
{
    CoreDragOperation(std::nullptr_t) noexcept {}
    CoreDragOperation();
};

struct WINRT_EBO CoreDragUIOverride :
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride
{
    CoreDragUIOverride(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreDropOperationTargetRequestedEventArgs :
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs
{
    CoreDropOperationTargetRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
