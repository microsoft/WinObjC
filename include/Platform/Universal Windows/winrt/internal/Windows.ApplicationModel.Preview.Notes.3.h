// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Preview.Notes.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Preview::Notes {

struct WINRT_EBO NotePlacementChangedPreviewEventArgs :
    Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs
{
    NotePlacementChangedPreviewEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NoteVisibilityChangedPreviewEventArgs :
    Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs
{
    NoteVisibilityChangedPreviewEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NotesWindowManagerPreview :
    Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview
{
    NotesWindowManagerPreview(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::Preview::Notes::NotesWindowManagerPreview GetForCurrentApp();
};

}

}
