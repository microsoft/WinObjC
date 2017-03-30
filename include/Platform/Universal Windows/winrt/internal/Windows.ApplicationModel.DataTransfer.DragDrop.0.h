// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::DataTransfer {


}

namespace Windows::ApplicationModel::DataTransfer::DragDrop {

enum class DragDropModifiers : unsigned
{
    None = 0x0,
    Shift = 0x1,
    Control = 0x2,
    Alt = 0x4,
    LeftButton = 0x8,
    MiddleButton = 0x10,
    RightButton = 0x20,
};

DEFINE_ENUM_FLAG_OPERATORS(DragDropModifiers)

}

}
