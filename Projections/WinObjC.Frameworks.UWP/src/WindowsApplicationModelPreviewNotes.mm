//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsApplicationModelPreviewNotes.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Preview.Notes.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelPreviewNotes.h"
#include "WindowsApplicationModelPreviewNotes_priv.h"

@implementation WAPNNotePlacementChangedPreviewEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)viewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotePlacementChangedPreviewEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WAPNNoteVisibilityChangedPreviewEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)viewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INoteVisibilityChangedPreviewEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WAPNNotesWindowManagerPreview

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics> WAPNINotesWindowManagerPreviewStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreviewStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Preview.Notes.NotesWindowManagerPreview").Get(), &inst));
    return inst;
}

+ (WAPNNotesWindowManagerPreview*)getForCurrentApp {
    ComPtr<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview> unmarshalledReturn;
    auto _comInst = WAPNINotesWindowManagerPreviewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentApp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPNNotesWindowManagerPreview>(unmarshalledReturn.Get());
}

- (BOOL)isScreenLocked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsScreenLocked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)showNote:(int)noteViewId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->ShowNote(noteViewId));
}

- (void)showNoteRelativeTo:(int)noteViewId anchorNoteViewId:(int)anchorNoteViewId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->ShowNoteRelativeTo(noteViewId, anchorNoteViewId));
}

- (void)showNoteWithPlacement:(int)noteViewId data:(RTObject<WSSIBuffer>*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->ShowNoteWithPlacement(noteViewId, _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get()));
}

- (void)hideNote:(int)noteViewId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->HideNote(noteViewId));
}

- (RTObject<WSSIBuffer>*)getNotePlacement:(int)noteViewId {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->GetNotePlacement(noteViewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (BOOL)trySetNoteSize:(int)noteViewId size:(WFSize*)size {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetNoteSize(noteViewId, *[size internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setFocusToNextView {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->SetFocusToNextView());
}

- (RTObject<WFIAsyncAction>*)setNotesThumbnailAsync:(RTObject<WSSIBuffer>*)thumbnail {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->SetNotesThumbnailAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(thumbnail).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addSystemLockStateChangedEvent:(void (^)(WAPNNotesWindowManagerPreview*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->add_SystemLockStateChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Preview_Notes_NotesWindowManagerPreview_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSystemLockStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SystemLockStateChanged(token));
}

- (EventRegistrationToken)addNotePlacementChangedEvent:(void (^)(WAPNNotesWindowManagerPreview*,
                                                                 WAPNNotePlacementChangedPreviewEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->add_NotePlacementChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Preview_Notes_NotesWindowManagerPreview_Windows_ApplicationModel_Preview_Notes_NotePlacementChangedPreviewEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNotePlacementChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NotePlacementChanged(token));
}

- (EventRegistrationToken)addNoteVisibilityChangedEvent:(void (^)(WAPNNotesWindowManagerPreview*,
                                                                  WAPNNoteVisibilityChangedPreviewEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->add_NoteVisibilityChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Preview_Notes_NotesWindowManagerPreview_Windows_ApplicationModel_Preview_Notes_NoteVisibilityChangedPreviewEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNoteVisibilityChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Preview::Notes::INotesWindowManagerPreview>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NoteVisibilityChanged(token));
}

@end
