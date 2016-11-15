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
#include "StoryboardManager.h"

#include "DisplayProperties.h"
#include "LayerCoordinator.h"

#include <ErrorHandling.h>

#include <algorithm>
#include <collection.h>

using namespace Platform;
using namespace UIKit::Xaml::Private::CoreAnimation;
using namespace Windows::Foundation;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Animation;
using namespace Windows::UI::Xaml::Media::Imaging;

static const wchar_t* TAG = L"StoryboardManager";

static const bool DEBUG_ALL = false;
static const bool DEBUG_TRANSITIONS = DEBUG_ALL || false;

namespace CoreAnimation {

static const double c_hundredNanoSeconds = 10000000.0;

StoryboardManager::StoryboardManager(
    double beginTime, double duration, bool autoReverse, float repeatCount, float repeatDuration, float speed, double timeOffset) {
    TimeSpan beginTimeSpan = TimeSpan();
    beginTimeSpan.Duration = (long long)(beginTime * c_hundredNanoSeconds);
    m_container->BeginTime = beginTimeSpan;
    TimeSpan timeSpan = TimeSpan();
    timeSpan.Duration = (long long)(duration * c_hundredNanoSeconds);
    m_container->Duration = Duration(timeSpan);
    if (repeatCount != 0) {
        m_container->RepeatBehavior = RepeatBehavior(repeatCount);
    }
    if (repeatDuration != 0) {
        TimeSpan timeSpan = TimeSpan();
        timeSpan.Duration = (long long)(repeatDuration * c_hundredNanoSeconds);
        m_container->RepeatBehavior = RepeatBehavior(timeSpan);
    }
    m_container->SpeedRatio = speed;
    m_container->AutoReverse = autoReverse;
    m_container->FillBehavior = FillBehavior::HoldEnd;
    m_container->Completed += ref new EventHandler<Object^>([this](Object^ sender, Object^ args) {
        if (Completed) {
            Completed(this);
        }
        m_container->Stop();
    });
}

void StoryboardManager::Start() {
    m_container->Begin();
}

void StoryboardManager::Stop() {
    m_container->Stop();

    // Enumerate any pending snapshots and make sure they're all removed from their respective scenes
    for (auto snapshotLayer : _animatingSnapshots) {
        if (DEBUG_TRANSITIONS) {
            TraceVerbose(TAG, L"StoryboardManager::Stop clearing out pending transition animation snapshot.");
        }

        _RemoveSnapshotLayer(snapshotLayer);
    }

    _animatingSnapshots.clear();
}

void StoryboardManager::_CreateFlip(Layer^ layer, bool flipRight, bool invert, bool removeFromParent) {
    if (layer->Projection == nullptr) {
        layer->Projection = ref new PlaneProjection();
    }

    DoubleAnimation^ rotateAnim = ref new DoubleAnimation();
    rotateAnim->Duration = m_container->Duration;

    if (!invert) {
        rotateAnim->From = 0.01;
        if (!flipRight) {
            rotateAnim->To = (double)180;
        } else {
            rotateAnim->To = (double)-180;
        }
    } else {
        if (!flipRight) {
            rotateAnim->From = (double)180;
            rotateAnim->To = (double)360;
        } else {
            rotateAnim->From = (double)-180;
            rotateAnim->To = (double)-360;
        }
    }

    Storyboard::SetTargetProperty(rotateAnim, "(UIElement.Projection).(PlaneProjection.RotationY)");
    Storyboard::SetTarget(rotateAnim, layer);
    m_container->Children->Append(rotateAnim);

    DoubleAnimation^ moveAnim = ref new DoubleAnimation();
    moveAnim->Duration = m_container->Duration;
    moveAnim->From = 0.01;
    moveAnim->To = (double)-160;
    moveAnim->SpeedRatio = 2.0;
    moveAnim->AutoReverse = true;

    Storyboard::SetTarget(moveAnim, layer);
    Storyboard::SetTargetProperty(moveAnim, "(UIElement.Projection).(PlaneProjection.GlobalOffsetZ)");
    m_container->Children->Append(moveAnim);

    DoubleAnimation^ fade1 = ref new DoubleAnimation();
    Storyboard::SetTarget(fade1, layer);
    Storyboard::SetTargetProperty(fade1, "(UIElement.Opacity)");

    Platform::WeakReference weakLayer(layer);
    if (!invert) {
        TimeSpan fade1TimeSpan = TimeSpan();
        fade1TimeSpan.Duration = m_container->Duration.TimeSpan.Duration / 2;
        fade1->Duration = Duration(fade1TimeSpan);
        fade1->From = 1.0;
        fade1->To = 0.5;
        fade1->FillBehavior = FillBehavior::HoldEnd;
    } else {
        TimeSpan fade1TimeSpan = TimeSpan();
        fade1TimeSpan.Duration = m_container->Duration.TimeSpan.Duration / 2;
        fade1->Duration = Duration(fade1TimeSpan);
        TimeSpan fade1BeginTimeSpan = TimeSpan();
        fade1BeginTimeSpan.Duration = m_container->Duration.TimeSpan.Duration / 2;
        fade1->BeginTime = fade1BeginTimeSpan;
        fade1->From = 0.5;
        fade1->To = 1.0;
        fade1->FillBehavior = FillBehavior::HoldEnd;

        fade1->Completed += ref new EventHandler<Object^>([weakLayer](Object^ sender, Object^ args) {
            Layer^ strongLayer = weakLayer.Resolve<Layer>();
            if (strongLayer) {
                strongLayer->Opacity = 1.0;
            } else if (DEBUG_TRANSITIONS) {
                TraceVerbose(TAG, L"fade1->Completed (for original layer) wasn't able to resolve its weak reference.");
            }
        });
    }

    if (removeFromParent) {
        Platform::WeakReference weakThis(this);
        fade1->Completed += ref new EventHandler<Object^>([weakThis, weakLayer](Object^ sender, Object^ args) {
            auto strongThis = weakThis.Resolve<StoryboardManager>();
            if (strongThis) {
                auto strongLayer = weakLayer.Resolve<Layer>();
                if (strongLayer) {
                    // Remove the snapshot layer from the scene and from our tracking vector
                    strongThis->_RemoveSnapshotLayer(strongLayer);
                    strongThis->_animatingSnapshots.erase(
                        std::remove_if(
                            std::begin(strongThis->_animatingSnapshots), 
                            std::end(strongThis->_animatingSnapshots), 
                            [strongLayer](Layer^ snapshotLayer) {
                                return snapshotLayer == strongLayer;
                            }));
                } else if (DEBUG_TRANSITIONS) {
                    TraceVerbose(TAG, L"fade1->Completed (for snapshot layer) wasn't able to resolve its weakLayer reference.");
                }
            } else if (DEBUG_TRANSITIONS) {
                TraceVerbose(TAG, L"fade1->Completed (for snapshot layer) wasn't able to resolve its weakThis reference.");
            }
        });
    } else {
        rotateAnim->Completed += ref new EventHandler<Object^>([weakLayer](Object^ sender, Object^ args) {
            Layer^ strongLayer = weakLayer.Resolve<Layer>();
            if (strongLayer) {
                // Using Projection transforms (even Identity) causes less-than-pixel-perfect rendering.
                strongLayer->Projection = nullptr;
            } else if (DEBUG_TRANSITIONS) {
                TraceVerbose(TAG, L"rotateAnim->Completed (for original layer) wasn't able to resolve its weak reference.");
            }
        });
    }

    m_container->Children->Append(fade1);
}

void StoryboardManager::_CreateWoosh(Layer^ layer, bool fromRight, bool invert, bool removeFromParent) {
    if (layer->Projection == nullptr) {
        layer->Projection = ref new PlaneProjection();
    }

    DoubleAnimation^ wooshAnim = ref new DoubleAnimation();
    wooshAnim->Duration = m_container->Duration;
    wooshAnim->EasingFunction = ref new PowerEase();
    wooshAnim->EasingFunction->EasingMode = EasingMode::EaseOut;

    if (!invert) {
        if (fromRight) {
            wooshAnim->From = (double)LayerCoordinator::GetVisualWidth(layer);
            wooshAnim->To = 0.01;
        } else {
            wooshAnim->From = 0.01;
            wooshAnim->To = (double)LayerCoordinator::GetVisualWidth(layer);
        }
    } else {
        if (fromRight) {
            wooshAnim->From = 0.01;
            wooshAnim->To = (double)(-LayerCoordinator::GetVisualWidth(layer) / 4);
        } else {
            wooshAnim->From = (double)(-LayerCoordinator::GetVisualWidth(layer) / 4);
            wooshAnim->To = 0.01;
        }
    }

    Storyboard::SetTargetProperty(wooshAnim, "(UIElement.Projection).(PlaneProjection.LocalOffsetX)");
    Storyboard::SetTarget(wooshAnim, layer);

    Platform::WeakReference weakLayer(layer);
    if (removeFromParent) {
        Platform::WeakReference weakThis(this);
        wooshAnim->Completed += ref new EventHandler<Object^>([weakThis, weakLayer](Object^ sender, Object^ args) {
            auto strongThis = weakThis.Resolve<StoryboardManager>();
            if (strongThis) {
                auto strongLayer = weakLayer.Resolve<Layer>();
                if (strongLayer) {
                    // Remove the snapshot layer from the scene and from our tracking vector
                    strongThis->_RemoveSnapshotLayer(strongLayer);
                    strongThis->_animatingSnapshots.erase(
                        std::remove_if(
                            std::begin(strongThis->_animatingSnapshots), 
                            std::end(strongThis->_animatingSnapshots), 
                            [strongLayer](Layer^ snapshotLayer) {
                                return snapshotLayer == strongLayer;
                            }));
                } else if (DEBUG_TRANSITIONS) {
                    TraceVerbose(TAG, L"wooshAnim->Completed (for snapshot layer) wasn't able to resolve its weakLayer reference.");
                }
            } else if (DEBUG_TRANSITIONS) {
                TraceVerbose(TAG, L"wooshAnim->Completed (for snapshot layer) wasn't able to resolve its weakThis reference.");
            }
        });
    } else {
        wooshAnim->Completed += ref new EventHandler<Object^>([weakLayer](Object^ sender, Object^ args) {
            Layer^ strongLayer = weakLayer.Resolve<Layer>();
            if (strongLayer) {
                // Using Projection transforms (even Identity) causes less-than-pixel-perfect rendering.
                strongLayer->Projection = nullptr;
            } else if (DEBUG_TRANSITIONS) {
                TraceVerbose(TAG, L"wooshAnim->Completed (for original layer) wasn't able to resolve its weak reference.");
            }
        });
    }

    m_container->Children->Append(wooshAnim);
}

void StoryboardManager::_RemoveSnapshotLayer(Layer^ snapshotLayer) {
    // Remove the snapshot layer from the parent panel
    auto parentPanel = safe_cast<Panel^>(snapshotLayer->Parent);
    if (parentPanel) {
        unsigned int index = 0;
        parentPanel->Children->IndexOf(snapshotLayer, &index);
        parentPanel->Children->RemoveAt(index);
    } else {
        // TODO: Determine why the internal news test app occasionally hits this path.
        TraceWarning(TAG, L"Failed to remove snapshot layer from scene; didn't have a parent to remove from!");
        snapshotLayer->Visibility = Visibility::Collapsed;
        LayerCoordinator::SetContent(
            snapshotLayer,
            nullptr,
            static_cast<float>(0),
            static_cast<float>(0),
            static_cast<float>(0));
    }
}

void StoryboardManager::AddTransition(Layer^ realLayer, Layer^ snapshotLayer, String^ type, String^ subtype) {
    if (type == "kCATransitionFlip") {
        TimeSpan timeSpan = TimeSpan();
        timeSpan.Duration = (long long)(0.75 * c_hundredNanoSeconds);
        m_container->Duration = Duration(timeSpan);

        Panel^ parent = safe_cast<Panel^>(VisualTreeHelper::GetParent(realLayer));

        bool flipToLeft = true;
        if (subtype != "kCATransitionFromLeft") {
            flipToLeft = false;
        }

        // We don't need to animate a snapshot if it doesn't exist
        if (snapshotLayer) {

            // Store the snapshot so we can clean up adequately in the event that animations are aborted early
            _animatingSnapshots.push_back(snapshotLayer);

            unsigned int idx;
            parent->Children->IndexOf(realLayer, &idx);
            parent->Children->InsertAt(idx + 1, snapshotLayer);
            parent->InvalidateArrange();
            realLayer->Opacity = 0;
            _CreateFlip(snapshotLayer, flipToLeft, false, true);
        }

        _CreateFlip(realLayer, flipToLeft, true, false);
    } else {
        TimeSpan timeSpan = TimeSpan();
        timeSpan.Duration = (long long)(0.5 * c_hundredNanoSeconds);
        m_container->Duration = Duration(timeSpan);
        Panel^ parent = (Panel^)VisualTreeHelper::GetParent(realLayer);

        bool fromRight = true;
        if (subtype == "kCATransitionFromLeft") {
            fromRight = false;
        }

        if (fromRight) {
            // We don't need to animate a snapshot if it doesn't exist
            if (snapshotLayer) {
                // Store the snapshot so we can clean up adequately in the event that animations are aborted early
                _animatingSnapshots.push_back(snapshotLayer);

                unsigned int idx;
                parent->Children->IndexOf(realLayer, &idx);
                parent->Children->InsertAt(idx, snapshotLayer);
                parent->InvalidateArrange();
                _CreateWoosh(snapshotLayer, fromRight, true, true);
            }

            _CreateWoosh(realLayer, fromRight, false, false);
        } else {
            // We don't need to animate a snapshot if it doesn't exist
            if (snapshotLayer) {
                // Store the snapshot so we can clean up adequately in the event that animations are aborted early
                _animatingSnapshots.push_back(snapshotLayer);

                unsigned int idx;
                parent->Children->IndexOf(realLayer, &idx);
                parent->Children->InsertAt(idx + 1, snapshotLayer);
                parent->InvalidateArrange();
                _CreateWoosh(snapshotLayer, fromRight, false, true);
            }

            _CreateWoosh(realLayer, fromRight, true, false);
        }
    }
}

void StoryboardManager::Animate(FrameworkElement^ layer, const char* propertyName, Object^ from, Object^ to) {
    DoubleAnimation^ timeline = ref new DoubleAnimation();
    timeline->Duration = m_container->Duration;
    timeline->EasingFunction = m_animationEase;
    LayerCoordinator::AnimateValue(layer, m_container, timeline, propertyName, from, to);
}

} /* namespace CoreAnimation */

// clang-format on