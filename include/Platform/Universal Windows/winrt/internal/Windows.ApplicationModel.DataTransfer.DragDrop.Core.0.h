// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core {

struct ICoreDragDropManager;
struct ICoreDragDropManagerStatics;
struct ICoreDragInfo;
struct ICoreDragInfo2;
struct ICoreDragOperation;
struct ICoreDragOperation2;
struct ICoreDragUIOverride;
struct ICoreDropOperationTarget;
struct ICoreDropOperationTargetRequestedEventArgs;
struct CoreDragDropManager;
struct CoreDragInfo;
struct CoreDragOperation;
struct CoreDragUIOverride;
struct CoreDropOperationTargetRequestedEventArgs;

}

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

struct ICoreDragDropManager;
struct ICoreDragDropManagerStatics;
struct ICoreDragInfo;
struct ICoreDragInfo2;
struct ICoreDragOperation;
struct ICoreDragOperation2;
struct ICoreDragUIOverride;
struct ICoreDropOperationTarget;
struct ICoreDropOperationTargetRequestedEventArgs;
struct CoreDragDropManager;
struct CoreDragInfo;
struct CoreDragOperation;
struct CoreDragUIOverride;
struct CoreDropOperationTargetRequestedEventArgs;

}

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

template <typename T> struct impl_ICoreDragDropManager;
template <typename T> struct impl_ICoreDragDropManagerStatics;
template <typename T> struct impl_ICoreDragInfo;
template <typename T> struct impl_ICoreDragInfo2;
template <typename T> struct impl_ICoreDragOperation;
template <typename T> struct impl_ICoreDragOperation2;
template <typename T> struct impl_ICoreDragUIOverride;
template <typename T> struct impl_ICoreDropOperationTarget;
template <typename T> struct impl_ICoreDropOperationTargetRequestedEventArgs;

}

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

enum class CoreDragUIContentMode : unsigned
{
    Auto = 0x0,
    Deferred = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(CoreDragUIContentMode)

}

}
