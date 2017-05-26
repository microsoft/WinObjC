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

// WindowsMediaCaptureCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Capture.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaCaptureCore.h"
#include "WindowsMediaCaptureCore_priv.h"

@implementation WMCCVariablePhotoSequenceCapture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)startAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)finishAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPhotoCapturedEvent:(void (^)(WMCCVariablePhotoSequenceCapture*, WMCCVariablePhotoCapturedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->add_PhotoCaptured(
        Make<
            ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePhotoCapturedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PhotoCaptured(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WMCCVariablePhotoSequenceCapture*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Stopped(Make<ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

- (RTObject<WFIAsyncAction>*)updateSettingsAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture2>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateSettingsAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMCCVariablePhotoCapturedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrame*)frame {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrame>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)captureTimeOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaptureTimeOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (id /* unsigned int */)usedFrameControllerIndex {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsedFrameControllerIndex(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (WMCCapturedFrameControlValues*)capturedFrameControlValues {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrameControlValues> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CapturedFrameControlValues(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrameControlValues>(unmarshalledReturn.Get());
}

@end
