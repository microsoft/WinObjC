//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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
// clang-format does not like C++/CX
// clang-format off

#include "LayerAnimation.h"

#include "DisplayProperties.h"
#include "LayerProxy.h"
#include "LayerCoordinator.h"
#include "StoryboardManager.h"

#include <ErrorHandling.h>

using namespace CoreAnimation;
using namespace Microsoft::WRL;
using namespace UIKit::Xaml::Private::CoreAnimation;
using namespace Windows::Foundation;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;

static const wchar_t* TAG = L"LayerAnimation";

__inline CoreAnimation::StoryboardManager^ _GetStoryboardManager(const Microsoft::WRL::ComPtr<IInspectable>& storyboardManager) {
    return dynamic_cast<CoreAnimation::StoryboardManager^>(reinterpret_cast<Platform::Object^>(storyboardManager.Get()));
}

__inline FrameworkElement^ _GetXamlElement(ILayerProxy& layer) {
    return dynamic_cast<FrameworkElement^>(reinterpret_cast<Platform::Object^>(reinterpret_cast<LayerProxy*>(&layer)->GetXamlElement().Get()));
};

LayerAnimation::LayerAnimation() {
    easingFunction = EaseInEaseOut;
}

void LayerAnimation::_CreateXamlAnimation() {
    auto storyboardManager = ref new CoreAnimation::StoryboardManager(
        beginTime, duration, autoReverse, repeatCount, repeatDuration, speed, timeOffset);

    switch (easingFunction) {
        case Easing::EaseInEaseOut: {
            auto easing = ref new Media::Animation::QuadraticEase();
            easing->EasingMode = Media::Animation::EasingMode::EaseInOut;
            storyboardManager->AnimationEase = easing;
        } break;

        case Easing::EaseIn: {
            auto easing = ref new Media::Animation::QuadraticEase();
            easing->EasingMode = Media::Animation::EasingMode::EaseIn;
            storyboardManager->AnimationEase = easing;
        } break;

        case Easing::EaseOut: {
            auto easing = ref new Media::Animation::QuadraticEase();
            easing->EasingMode = Media::Animation::EasingMode::EaseOut;
            storyboardManager->AnimationEase = easing;
        } break;

        case Easing::Default: {
            auto easing = ref new Media::Animation::QuadraticEase();
            easing->EasingMode = Media::Animation::EasingMode::EaseInOut;
            storyboardManager->AnimationEase = easing;
        } break;

        case Easing::Linear: {
            storyboardManager->AnimationEase = nullptr;
        } break;
    }

    _storyboardManager = reinterpret_cast<IInspectable*>(storyboardManager);
}

void LayerAnimation::_Start() {
    CoreAnimation::StoryboardManager^ storyboardManager = _GetStoryboardManager(_storyboardManager);

    std::weak_ptr<LayerAnimation> weakThis = shared_from_this();
    storyboardManager->Completed = ref new CoreAnimation::AnimationMethod([weakThis](Platform::Object^ sender) {
        std::shared_ptr<LayerAnimation> strongThis = weakThis.lock();
        if (strongThis) {
            strongThis->_Completed();
            CoreAnimation::StoryboardManager^ storyboardManager = _GetStoryboardManager(strongThis->_storyboardManager);
            storyboardManager->Completed = nullptr;
        }
    });

    storyboardManager->Start();
}

void LayerAnimation::Stop() {
    CoreAnimation::StoryboardManager^ storyboardManager = _GetStoryboardManager(_storyboardManager);
    if (storyboardManager) {
        storyboardManager->Stop();
        storyboardManager->Completed = nullptr;
        _storyboardManager = nullptr;
    }
}

concurrency::task<void> LayerAnimation::_AddAnimation(ILayerProxy& layer, const char* propertyName, bool fromValid, float from, bool toValid, float to) {
    auto xamlLayer = _GetXamlElement(layer);
    auto storyboardManager = _GetStoryboardManager(_storyboardManager);

    storyboardManager->Animate(xamlLayer,
        propertyName,
        fromValid ? (Platform::Object^)(double)from : nullptr,
        toValid ? (Platform::Object^)(double)to : nullptr);

    return concurrency::task_from_result();
}

concurrency::task<Layer^> _SnapshotLayer(Layer^ layer) {
    if (((layer->Height == 0) && (layer->Width == 0)) || (layer->Opacity == 0)) {
        return concurrency::task_from_result<Layer^>(nullptr);
    }
    else {
        RenderTargetBitmap^ snapshot = ref new RenderTargetBitmap();
        return concurrency::create_task(
                snapshot->RenderAsync(layer))
            .then([snapshot, layer](concurrency::task<void> result) noexcept {
            try {
                result.get();
            } catch (Platform::InvalidArgumentException^ ex) {
                // Handle exceptions related to invalid layer attribute passed to RenderAsync
                TraceWarning(TAG,
                             L"RenderAsync threw InvalidArgumentException exception - [%ld]%s",
                             ex->HResult,
                             ex->Message);
                return static_cast<Layer^>(nullptr);
            }

            // Return a new 'copy' layer with the rendered content
            Layer^ newLayer = ref new Layer();
            newLayer->Name = "_Temporary_CoreAnimation_SnapshotLayer";
            LayerCoordinator::InitializeFrameworkElement(newLayer);

            // Copy display properties from the old layer to the new layer
            LayerCoordinator::SetValue(newLayer, "opacity", LayerCoordinator::GetValue(layer, "opacity"));
            LayerCoordinator::SetValue(newLayer, "position", LayerCoordinator::GetValue(layer, "position"));
            LayerCoordinator::SetValue(newLayer, "size", LayerCoordinator::GetValue(layer, "size"));
            LayerCoordinator::SetValue(newLayer, "anchorPoint", LayerCoordinator::GetValue(layer, "anchorPoint"));

            auto dispInfo = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            // Set the snapshot as the content of the new layer
            LayerCoordinator::SetContent(
                newLayer, 
                snapshot,
                static_cast<float>(layer->Width),
                static_cast<float>(layer->Height),
                static_cast<float>(DisplayProperties::RawScreenScale() * dispInfo->RawPixelsPerViewPixel));

            // There seems to be a bug in Xaml where Render'd layers get sized to their visible content... sort of.
            // If the UIViewController being transitioned away from has transparent content, the height returned is less the
            // navigation bar, as though Xaml sizes the buffer to the largest child Visual, and only expands where needed.
            // Top/bottom switched due to geometric origin of CALayer so read this as UIViewContentModeTopLeft
            LayerCoordinator::SetContentGravity(newLayer, ContentGravity::BottomLeft);

            return newLayer;
        }, concurrency::task_continuation_context::use_current());
    }
}

concurrency::task<void> LayerAnimation::_AddTransitionAnimation(ILayerProxy& layer, const char* type, const char* subtype) {
    auto xamlLayer = _GetXamlElement(layer);
    auto storyboardManager = _GetStoryboardManager(_storyboardManager);

    std::string stype(type);
    std::wstring wtype(stype.begin(), stype.end());
    std::string ssubtype(subtype);
    std::wstring wsubtype(ssubtype.begin(), ssubtype.end());

    // We currently only support layer snapshots/transitions on our default Layer implementation
    auto coreAnimationLayer = dynamic_cast<Layer^>(xamlLayer);
    if (!coreAnimationLayer) {
        UNIMPLEMENTED_WITH_MSG(
            "Layer transition animations not supported on this Xaml element: [%ws].",
            xamlLayer->GetType()->FullName->Data());
        return concurrency::task_from_result();
    }

    // Render a layer snapshot, then kick off the animation
    return _SnapshotLayer(coreAnimationLayer)
        .then([this, storyboardManager, coreAnimationLayer, wtype, wsubtype](Layer^ snapshotLayer) noexcept {

        storyboardManager->AddTransition(
            coreAnimationLayer,
            snapshotLayer,
            ref new Platform::String(wtype.data()),
            ref new Platform::String(wsubtype.data()));

        _Start();
    }, concurrency::task_continuation_context::use_current());
}