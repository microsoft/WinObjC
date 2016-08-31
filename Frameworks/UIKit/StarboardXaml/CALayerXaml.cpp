//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "ppltasks.h"
#include "LoggingNative.h"
#include "CALayerXaml.h"
#include <StringHelpers.h>
#include <LoggingNative.h>
#include <algorithm>
#include <collection.h>

using namespace concurrency;
using namespace Platform;
using namespace Strings::Private;
using namespace Windows::System::Threading;
using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::UI::Composition;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Automation::Peers;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Hosting;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Animation;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::Graphics::Display;

static const wchar_t* TAG = L"CALayerXaml";

namespace XamlCompositor {
namespace Controls {
//
// ObjectCache
//
ICacheableObject^ ObjectCache::GetCachableObject() {
    if (m_objects.size() == 0) {
        return nullptr;
    }

    ICacheableObject^ object = m_objects.front();
    m_objects.pop();
    return object;
};

void ObjectCache::PushCacheableObject(ICacheableObject^ obj) {
    obj->Reset();
    if (m_objects.size() >= m_maxSize) {
        return;
    }
    m_objects.push(obj);
};

//
// LayerContent
//
LayerContent::LayerContent() {
    Name = L"LayerContent"; // Set a name so we can be seen in the live tree viewer
    IsHitTestVisible = true; // Always be hit testable by default.
    m_gravity = ContentGravity::Resize;
    m_scaleFactor = 1.0f;
}

void LayerContent::Reset() {
    Children->Clear();
    m_image = nullptr;
    m_content = nullptr;
    m_imageSize = Size(0, 0);
    m_contentSize = Size(0, 0);
    m_contentsCenter = Rect(0, 0, 1.0, 1.0);
    m_gravity = ContentGravity::Resize;
    m_scaleFactor = 1.0f;
    m_origin = Point();
}

LayerContent^ LayerContent::CreateLayerContent() {
    ICacheableObject^ ret = _LayerContentCache->GetCachableObject();
    if (ret != nullptr) {
        return (LayerContent^)ret;
    }

    return ref new LayerContent();
}

void LayerContent::DestroyLayerContent(LayerContent^ content) {
    _LayerContentCache->PushCacheableObject(content);
}

int LayerContent::_IfNegativeMakeZero(int value) {
    return (value < 0) ? 0 : value;
}

void LayerContent::_ApplyContentsCenter() {
    if (m_image == nullptr) {
        return;
    }
    if (m_image->Source == nullptr) {
        return;
    }

    if (m_contentsCenter.X == 0.0 &&
        m_contentsCenter.Y == 0.0 &&
        m_contentsCenter.Width == 1.0 &&
        m_contentsCenter.Height == 1.0) {
        m_image->NineGrid = Thickness(0, 0, 0, 0);
    } else {
        int left = (int)(m_contentsCenter.X * m_imageSize.Width);
        int top = (int)(m_contentsCenter.Y * m_imageSize.Height);
        int right = ((int)m_imageSize.Width) - (left + ((int)(m_contentsCenter.Width * m_imageSize.Width)));
        int bottom = ((int)m_imageSize.Height) - (top + ((int)(m_contentsCenter.Height * m_imageSize.Height)));

        // Remove edge cases that contentsCenter supports but NineGrid does not. 1/3 for top 1/3 for bottom 1/3 for
        // the center etc..

        left = _IfNegativeMakeZero(left);
        top = _IfNegativeMakeZero(top);
        right = _IfNegativeMakeZero(right);
        bottom = _IfNegativeMakeZero(bottom);

        int maxWidth = (int)m_imageSize.Width / 3;

        if (left >= maxWidth) {
            left = maxWidth;
        }

        if (right >= maxWidth) {
            right = maxWidth;
        }

        int maxHeight = (int)m_imageSize.Height / 3;

        if (top >= maxHeight) {
            top = maxHeight;
        }

        if (bottom >= maxHeight) {
            bottom = maxHeight;
        }

        m_image->NineGrid = Thickness(left, top, right, bottom);
    }
}

Rect LayerContent::_GetContentGravityRect(Size size) {
    float left = 0;
    float top = 0;
    float width = 0;
    float height = 0;

    double widthAspect = size.Width / m_contentSize.Width;
    double heightAspect = size.Height / m_contentSize.Height;
    double minAspect = std::min<double>(widthAspect, heightAspect);
    double maxAspect = std::max<double>(widthAspect, heightAspect);

    //  Top/bottom switched due to geometric origin
    switch (m_gravity) {
        case ContentGravity::Center:
            left = (size.Width / 2) - (m_contentSize.Width / 2);
            top = (size.Height / 2) - (m_contentSize.Height / 2);
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::Top:
            left = (size.Width / 2) - (m_contentSize.Width / 2);
            top = size.Height - m_contentSize.Height;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::Bottom:
            left = (size.Width / 2) - (m_contentSize.Width / 2);
            top = 0;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::Left:
            left = 0;
            top = (size.Height / 2) - (m_contentSize.Height / 2);
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::Right:
            left = size.Width - m_contentSize.Width;
            top = (size.Height / 2) - (m_contentSize.Height / 2);
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::TopLeft:
            left = 0;
            top = size.Height - m_contentSize.Height;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::TopRight:
            left = size.Width - m_contentSize.Width;
            top = size.Height - m_contentSize.Height;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::BottomLeft:
            left = 0;
            top = 0;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::BottomRight:
            left = size.Width - m_contentSize.Width;
            top = 0;
            width = m_contentSize.Width;
            height = m_contentSize.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::Resize:
            // UIViewContentModeScaleToFil;
            left = 0;
            top = 0;
            width = size.Width;
            height = size.Height;
            if (m_image != nullptr)
            {
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::ResizeAspect:
            // UIViewContentModeScaleAspectFit

            // Scale the image with the smaller aspect.
            width = m_contentSize.Width * (float)minAspect;
            height = m_contentSize.Height * (float)minAspect;

            left = (size.Width / 2) - (width / 2);
            top = (size.Height / 2) - (height / 2);
            if (m_image != nullptr) {
                // Using Fill since we calculate the aspect ourselves because image translates when modifying its scale with Stretch::Uniform.
                m_image->Stretch = Stretch::Fill;
            }
            break;

        case ContentGravity::ResizeAspectFill:
            // UIViewContentModeScaleAspectFill

            // Scale the image with the larger aspect.
            width = m_contentSize.Width * (float)maxAspect;
            height = m_contentSize.Height * (float)maxAspect;

            left = (size.Width / 2) - (width / 2);
            top = (size.Height / 2) - (height / 2);
            if (m_image != nullptr)
            {
                // Using Fill since we calculate the aspect ourselves because XAML clips when setting UniformToFill.
                m_image->Stretch = Stretch::Fill;
            }
            break;
    }

    return Rect(left, top, width, height);
}

Image^ LayerContent::_GetImage() {
    if (m_image == nullptr) {
        m_image = ref new Image();
        m_image->Stretch = Stretch::Fill;
        m_scaleFactor = 1.0f;
    }

    SetElementContent(m_image);
    return m_image;
}

void LayerContent::SetContentsCenter(Rect rect) {
    m_contentsCenter = rect;
    _ApplyContentsCenter();
}

void LayerContent::SetGravity(ContentGravity imgGravity) {
    m_gravity = imgGravity;
    InvalidateArrange();
}

void LayerContent::SetImageContent(ImageSource^ source, float width, float height) {
    if (source == nullptr) {
        SetElementContent(nullptr);
        return;
    }

    Image^ imgContents = _GetImage();
    imgContents->IsHitTestVisible = false; // Our content should never be HitTestVisible as they are always leaf nodes.

    if (Util::isInstanceOf<BitmapSource^>(source)) {
        m_imageSize = Size(width, height);
    } else {
        m_imageSize = Size(0, 0);
    }
    imgContents->Source = source;

    _ApplyContentsCenter();
}

void LayerContent::_AdjustContentOriginX(Storyboard^ storyboard, DoubleAnimation^ properties, Object^ fromValue, Object^ toValue) {
    if (toValue != nullptr) {
        double value = -((double)toValue);
        m_origin.X = (float)value;
    }
    if (m_image != nullptr || m_content == nullptr) {
        return;
    }
    InvalidateArrange();
}

void LayerContent::_AdjustContentOriginY(Storyboard^ storyboard, DoubleAnimation^ properties, Object^ fromValue, Object^ toValue) {
    if (toValue != nullptr) {
        double value = -((double)toValue);
        m_origin.Y = (float)value;
    }
    if (m_image != nullptr || m_content == nullptr) {
        return;
    }
    InvalidateArrange();
}

void LayerContent::SetElementContent(FrameworkElement^ source) {
    if (m_content == source) {
        return;
    }

    if (m_content != nullptr) {
        unsigned int index;
        if (Children->IndexOf(m_content, &index)) {
            Children->RemoveAt(index);
        }
        m_content = nullptr;
        m_image = nullptr;
    }

    if (source != nullptr) {
        m_content = source;
        Children->Append(m_content);
        InvalidateArrange();

        m_imageSize = Size(0, 0);
    }
}

void LayerContent::SetContentParams(float width, float height, float scale) {
    Size oldSize = m_contentSize;
    float oldScale = scale;

    m_contentSize = Size(width / scale, height / scale);

    if (m_scaleFactor <= 0.0f) {
        m_scaleFactor = 1.0f;
    }

    if (m_scaleFactor != scale) {
        m_scaleFactor = scale;

        if (m_image != nullptr) {
            if (m_scaleFactor != 1.0f) {
                ScaleTransform^ trans = ref new ScaleTransform();
                trans->ScaleX = 1.0 / m_scaleFactor;
                trans->ScaleY = 1.0 / m_scaleFactor;
                m_image->RenderTransform = trans;
            } else {
                m_image->RenderTransform = nullptr;
            }
        }
    }

    if (oldScale != m_scaleFactor || oldSize != m_contentSize) {
        InvalidateArrange();
    }
}

Size LayerContent::ArrangeOverride(Size finalSize) {
    if (m_content != nullptr) {
        Rect newSize = _GetContentGravityRect(finalSize);

        if (m_image != nullptr) {
            m_content->Width = newSize.Width * m_scaleFactor;
            m_content->Height = newSize.Height * m_scaleFactor;
        } else {
            double contentWidth = newSize.Width - m_origin.X;
            double contentHeight = newSize.Height - m_origin.Y;
            if (contentWidth < 0.0) {
                contentWidth = 0.0;
            }
            if (contentHeight < 0.0) {
                contentHeight = 0.0;
            }

            m_content->Width = contentWidth;
            m_content->Height = contentHeight;
        }

        m_content->Arrange(
            Rect(newSize.Left + m_origin.X, newSize.Top + m_origin.Y, (float)m_content->Width, (float)m_content->Height));
    }

    return finalSize;
}

Size LayerContent::MeasureOverride(Size availableSize) {
    return availableSize;
}

//
// CALayerXaml
//
double CALayerXaml::s_screenScale = 1.0;
DependencyProperty^ CALayerXaml::s_visualWidthProperty = nullptr;
DependencyProperty^ CALayerXaml::s_visualHeightProperty = nullptr;
std::map<String^, CALayerXaml::AnimatableProperty^> CALayerXaml::s_animatableProperties = {
    { "position.x",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[3].(TranslateTransform.X)",
                                             (UIElement^)target,
                                             storyboard,
                                             properties,
                                             from,
                                             to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              double positionX = (double)toValue;
              target->m_position.X = (float)positionX;
              if (target->m_createdTransforms) {
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(3))->X = (double)toValue;
              } else {
                  target->_CalcTransforms();
              }
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                            return (double)target->m_position.X;
                                                    }
                                                    return CALayerXaml::_GetAnimatedTransformIndex(
                                                        target, 3, TranslateTransform::XProperty);
                                               })) },
    { "position.y",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[3].(TranslateTransform.Y)",
                                             target,
                                             storyboard,
                                             properties,
                                             from,
                                             to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              double positionY = (double)toValue;
              target->m_position.Y = (float)positionY;
              if (target->m_createdTransforms) {
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(3))->Y = (double)toValue;
              } else {
                  target->_CalcTransforms();
              }
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                          return (double)target->m_position.Y;
                                                    }
                                                    return CALayerXaml::_GetAnimatedTransformIndex(
                                                        target, 3, TranslateTransform::YProperty);
                                                })) },
    { "position",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  s_animatableProperties["position.x"]->Animate(target,
                                                                storyboard,
                                                                properties,
                                                                from != nullptr ? (Object^)((Point)from).X : nullptr,
                                                                (double)((Point)to).X);
                  s_animatableProperties["position.y"]->Animate(target,
                                                                storyboard,
                                                                properties,
                                                                from != nullptr ? (Object^)((Point)from).Y : nullptr,
                                                                (double)((Point)to).Y);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              s_animatableProperties["position.x"]->Set(target, (double)((Point)toValue).X);
              s_animatableProperties["position.y"]->Set(target, (double)((Point)toValue).Y);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    // Unbox x and y values as doubles, before casting them to floats
                                                    return Point((float)(double)target->Get("position.x"),
                                                                 (float)(double)target->Get("position.y"));
                                               })) },
    { "origin.x",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  target->SetupBackground();
                  double targetFrom = from != nullptr ? (double)from : 0.0;
                  double targetTo = to != nullptr ? (double)to : 0.0;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[1].(TranslateTransform.X)",
                                             target,
                                             storyboard,
                                             properties,
                                             (from != nullptr) ? (Object^)(-targetFrom) : nullptr,
                                             -targetTo);
                  if (target->m_masksToBounds) {
                      CALayerXaml::_AddAnimation("(UIElement.Clip).(Transform).(TranslateTransform.X)",
                                                 target,
                                                 storyboard,
                                                 properties,
                                                 (from != nullptr) ? (Object^)(targetFrom) : nullptr,
                                                 targetTo);
                  }
                  target->_AdjustContentOriginX(storyboard, properties, targetFrom, targetTo);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {

              target->SetupBackground();
              double targetValue = (double)toValue;

              target->m_origin.X = (float)targetValue;

              if (target->m_createdTransforms) {
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(1))->X = -targetValue;
              } else {
                  target->_CalcTransforms();
              }
              if (target->Clip != nullptr) {
                  ((TranslateTransform^)target->Clip->Transform)->X = targetValue;
              }
              target->_AdjustContentOriginX(nullptr, nullptr, nullptr, targetValue);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)target->m_origin.X;
                                                    }
                                                    return -((double)CALayerXaml::_GetAnimatedTransformIndex(
                                                        target, 1, TranslateTransform::XProperty));
                                               })) },

    { "origin.y",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  target->SetupBackground();
                  double targetFrom = (from != nullptr) ? (double)from : 0.0;
                  double targetTo = (to != nullptr) ? (double)to : 0.0;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[1].(TranslateTransform.Y)",
                                             target,
                                             storyboard,
                                             properties,
                                             from != nullptr ? (Object^)(-targetFrom) : nullptr,
                                             -targetTo);
                  if (target->m_masksToBounds) {
                      CALayerXaml::_AddAnimation("(UIElement.Clip).(Transform).(TranslateTransform.Y)",
                                                 target,
                                                 storyboard,
                                                 properties,
                                                 (from != nullptr) ? (Object^)(targetFrom) : nullptr,
                                                 targetTo);
                  }
                  target->_AdjustContentOriginY(storyboard, properties, targetFrom, targetTo);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->SetupBackground();
              double targetValue = (double)toValue;

              target->m_origin.Y = (float)targetValue;

              if (target->m_createdTransforms) {
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(1))->Y = -targetValue;
              } else {
                  target->_CalcTransforms();
              }
              if (target->Clip != nullptr) {
                  ((TranslateTransform^)target->Clip->Transform)->Y = targetValue;
              }
              target->_AdjustContentOriginY(nullptr, nullptr, nullptr, targetValue);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)target->m_origin.Y;
                                                    }
                                                    return -((double)CALayerXaml::_GetAnimatedTransformIndex(
                                                        target, 1, TranslateTransform::YProperty));
                                               })) },
    { "origin",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  s_animatableProperties["origin.x"]->Animate(target,
                                                              storyboard,
                                                              properties,
                                                              (from != nullptr) ? (Object^)((Point)from).X : nullptr,
                                                              (double)((Point)to).X);
                  s_animatableProperties["origin.y"]->Animate(target,
                                                              storyboard,
                                                              properties,
                                                              (from != nullptr) ? (Object^)((Point)from).Y : nullptr,
                                                              (double)((Point)to).Y);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              s_animatableProperties["origin.x"]->Set(target, (double)((Point)toValue).X);
              s_animatableProperties["origin.y"]->Set(target, (double)((Point)toValue).Y);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    // Unbox x and y values as doubles, before casting them to floats
                                                    return Point((float)(double)target->Get("origin.x"),
                                                                 (float)(double)target->Get("origin.y"));
                                               })) },
    { "anchorPoint.x",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  Object^ fromVal = (from != nullptr) ? (Object^)(-target->m_size.Width * (double)from) : nullptr;
                  double destVal = -target->m_size.Width * (double)to;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.X)",
                                             target,
                                             storyboard,
                                             properties,
                                             fromVal,
                                             destVal);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              double anchorPointX = (double)toValue;
              target->m_anchorPoint.X = (float)anchorPointX;
              if (target->m_createdTransforms) {
                  double destX = -target->m_size.Width * ((double)toValue);
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(0))->X = destX;
              } else {
                  target->_CalcTransforms();
              }
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^ { return (double)target->m_anchorPoint.X; })) },
    { "anchorPoint.y",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  Object^ fromVal = (from != nullptr) ? (Object^)(-target->m_size.Height * (double)from) : nullptr;
                  double destVal = -target->m_size.Height * (double)to;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.Y)",
                                             target,
                                             storyboard,
                                             properties,
                                             fromVal,
                                             destVal);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              double anchorPointY = (double)toValue;
              target->m_anchorPoint.Y = (float)anchorPointY;
              if (target->m_createdTransforms) {
                  double destY = -target->m_size.Height * ((double)toValue);
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(0))->Y = destY;
              } else {
                  target->_CalcTransforms();
              }
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^ { return (double)target->m_anchorPoint.Y; })) },
    { "anchorPoint",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  s_animatableProperties["anchorPoint.x"]->Animate(target,
                                                                   storyboard,
                                                                   properties,
                                                                   (from != nullptr) ? (Object^)((Point)from).X : nullptr,
                                                                   (double)((Point)to).X);
                  s_animatableProperties["anchorPoint.y"]->Animate(target,
                                                                   storyboard,
                                                                   properties,
                                                                   (from != nullptr) ? (Object^)((Point)from).Y : nullptr,
                                                                   (double)((Point)to).Y);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              s_animatableProperties["anchorPoint.x"]->Set(target, (double)((Point)toValue).X);
              s_animatableProperties["anchorPoint.y"]->Set(target, (double)((Point)toValue).Y);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    // Unbox x and y values as doubles, before casting them to floats
                                                    return Point((float)(double)target->Get("anchorPoint.x"),
                                                                 (float)(double)target->Get("anchorPoint.y"));
                                               })) },
    { "size.width",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  if (from != nullptr) {
                      if ((double)from < 0.0) {
                          from = (double)0.0;
                      }
                  }
                  if (to != nullptr) {
                      if ((double)to < 0.0) {
                          to = (double)0.0;
                      }
                  }

                  Object^ fromVal = (from != nullptr) ? (Object^)((-((double)from)) * target->m_anchorPoint.X) : nullptr;
                  double dest = -((double)to) * target->m_anchorPoint.X;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.X)",
                                             target,
                                             storyboard,
                                             properties,
                                             fromVal,
                                             dest);
                  CALayerXaml::_AddAnimation("VisualWidth", target, storyboard, properties, from, to, true);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              if (toValue != nullptr) {
                  if ((double)toValue < 0.0) {
                      toValue = (double)0.0;
                  }
              }
              if (target->m_size.Width == (double)toValue) {
                  return;
              }

              double width = (double)toValue;
              target->m_size.Width = (float)width;
              target->Width = width;

              if (target->m_createdTransforms) {
                  double destX = -((double)toValue) * target->m_anchorPoint.X;
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(0))->X = destX;
                  target->VisualWidth = (double)toValue;
              } else {
                  target->_CalcTransforms();
              }
              target->InvalidateArrange();
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)target->m_size.Width;
                                                    }
                                                    return target->GetValue(CALayerXaml::VisualWidthProperty);
                                               })) },
    { "size.height",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  if (from != nullptr) {
                      if ((double)from < 0.0) {
                          from = (double)0.0;
                      }
                  }
                  if (to != nullptr) {
                      if ((double)to < 0.0) {
                          to = (double)0.0;
                      }
                  }
                  Object^ fromVal = (from != nullptr) ? (Object^)((-((double)from)) * target->m_anchorPoint.Y) : nullptr;
                  double dest = -((double)to) * target->m_anchorPoint.Y;

                  CALayerXaml::_AddAnimation("(UIElement.RenderTransform).(TransformGroup.Children)[0].(TranslateTransform.Y)",
                                             target,
                                             storyboard,
                                             properties,
                                             fromVal,
                                             dest);
                  CALayerXaml::_AddAnimation("VisualHeight", target, storyboard, properties, from, to, true);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              if (toValue != nullptr) {
                  if ((double)toValue < 0.0) {
                      toValue = (double)0.0;
                  }
              }
              if (target->m_size.Height == (double)toValue) {
                  return;
              }

              double height = (double)toValue;
              target->m_size.Height = (float)height;
              target->Height = height;

              if (target->m_createdTransforms) {
                  double destY = -((double)toValue) * target->m_anchorPoint.Y;
                  ((TranslateTransform^)((TransformGroup^)target->RenderTransform)->Children->GetAt(0))->Y = destY;
                  target->VisualHeight = (double)toValue;
              } else {
                  target->_CalcTransforms();
              }
              target->InvalidateArrange();
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)target->m_size.Height;
                                                    }
                                                    return target->GetValue(CALayerXaml::VisualHeightProperty);
                                               })) },
    { "size",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  s_animatableProperties["size.width"]->Animate(target,
                                                                storyboard,
                                                                properties,
                                                                (from != nullptr) ? (Object^)((Size)from).Width : nullptr,
                                                                (double)((Size)to).Width);
                  s_animatableProperties["size.height"]->Animate(target,
                                                                 storyboard,
                                                                 properties,
                                                                 (from != nullptr) ? (Object^)((Size)from).Height : nullptr,
                                                                 (double)((Size)to).Height);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              s_animatableProperties["size.width"]->Set(target, (double)((Size)toValue).Width);
              s_animatableProperties["size.height"]->Set(target, (double)((Size)toValue).Height);
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    // Unbox width and height values as doubles, before casting them to floats
                                                    return Size((float)(double)target->Get("size.width"),
                                                                (float)(double)target->Get("size.height"));
                                               })) },
    { "transform.rotation",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation(
                      "(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[0].(RotateTransform.Angle)",
                      target,
                      storyboard,
                      properties,
                      from,
                      to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->_CreateTransforms();
              ((RotateTransform^)((TransformGroup^)((TransformGroup^)target->RenderTransform)->Children->GetAt(2))
                   ->Children->GetAt(0))
                  ->Angle = (double)toValue;
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                                  {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)0.0;
                                                    }
                                                    return CALayerXaml::_GetGeneralTransformIndex(
                                                        target, 0, RotateTransform::AngleProperty);
                                                  })) },
    { "transform.scale.x",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation(
                      "(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[1].(ScaleTransform.ScaleX)",
                      target,
                      storyboard,
                      properties,
                      from,
                      to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->_CreateTransforms();
              ((ScaleTransform^)((TransformGroup^)((TransformGroup^)target->RenderTransform)->Children->GetAt(2))->Children->GetAt(1))
                  ->ScaleX = (double)toValue;
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)0.0;
                                                    }
                                                    return CALayerXaml::_GetGeneralTransformIndex(
                                                        target, 1, ScaleTransform::ScaleXProperty);
                                                })) },
    { "transform.scale.y",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation(
                      "(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[1].(ScaleTransform.ScaleY)",
                      target,
                      storyboard,
                      properties,
                      from,
                      to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->_CreateTransforms();
              ((ScaleTransform^)((TransformGroup^)((TransformGroup^)target->RenderTransform)->Children->GetAt(2))->Children->GetAt(1))
                  ->ScaleY = (double)toValue;
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)0.0;
                                                    }
                                                    return CALayerXaml::_GetGeneralTransformIndex(
                                                        target, 1, ScaleTransform::ScaleYProperty);
                                               })) },
    { "transform.translation.x",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation(
                      "(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[2].(TranslateTransform.X)",
                      target,
                      storyboard,
                      properties,
                      from,
                      to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->_CreateTransforms();
              ((TranslateTransform^)((TransformGroup^)((TransformGroup^)target->RenderTransform)->Children->GetAt(2))
                   ->Children->GetAt(2))
                  ->X = (double)toValue;
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)0.0;
                                                    }
                                                    return CALayerXaml::_GetGeneralTransformIndex(
                                                        target, 2, TranslateTransform::XProperty);
                                               })) },
    { "transform.translation.y",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  target->_CreateTransforms();
                  CALayerXaml::_AddAnimation(
                      "(UIElement.RenderTransform).(TransformGroup.Children)[2].(TransformGroup.Children)[2].(TranslateTransform.Y)",
                      target,
                      storyboard,
                      properties,
                      from,
                      to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->_CreateTransforms();
              ((TranslateTransform^)((TransformGroup^)((TransformGroup^)target->RenderTransform)->Children->GetAt(2))
                   ->Children->GetAt(2))
                  ->Y = (double)toValue;
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^
                                               {
                                                    if (!target->m_createdTransforms) {
                                                        return (double)0.0;
                                                    }
                                                    return CALayerXaml::_GetGeneralTransformIndex(
                                                        target, 2, TranslateTransform::YProperty);
                                               })) },
    { "opacity",
      ref new CALayerXaml::AnimatableProperty(
          ref new CALayerXaml::ApplyAnimationFunction(
              [](CALayerXaml^ target, Storyboard^ storyboard, DoubleAnimation^ properties, Object^ from, Object^ to) {
                  CALayerXaml::_AddAnimation("(UIElement.Opacity)", target, storyboard, properties, from, to);
              }),
          ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
              target->m_opacity = (double)toValue;
              target->SetOpacity();
          }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^ { return target->m_opacity; })) },
    { "gravity",
      ref new CALayerXaml::AnimatableProperty(
          nullptr,
          ref new CALayerXaml::ApplyTransformFunction(
              [](CALayerXaml^ target, Object^ toValue) { target->SetContentGravity((ContentGravity)(int)toValue); }),
          ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target) -> Object^ { return (int)target->m_contentGravity; })) },
    { "masksToBounds",
      ref new CALayerXaml::AnimatableProperty(nullptr,
                                              ref new CALayerXaml::ApplyTransformFunction([](CALayerXaml^ target, Object^ toValue) {
                                                  target->m_masksToBounds = (bool)toValue;
                                                  target->Clip = target->m_masksToBounds ? target->m_clipGeometry : nullptr;
                                              }),
                                              ref new CALayerXaml::GetCurrentValue([](CALayerXaml^ target)
                                                                                       -> Object^ { return target->m_masksToBounds; })) },
};

void CALayerXaml::Reset() {
    __super::Children->Clear();
    InvalidateArrange();
    m_content = nullptr;
    m_contentsCenter = Rect(0, 0, 1, 1);
    m_contentGravity = ContentGravity::Resize;
    Clip = nullptr;
    m_invOriginTransform = ref new TranslateTransform();
    m_clipGeometry = ref new RectangleGeometry();
    m_clipGeometry->Transform = m_invOriginTransform;
    RenderTransform = ref new TranslateTransform();
    m_position = Point(0, 0);
    m_origin = Point(0, 0);
    m_size = Size(0, 0);
    m_hidden = false;
    m_originSet = false;
    m_createdTransforms = false;
    LayerOpacity = 1.0;

    IsHitTestVisible = true; // Always hit-testable by default

    Set("anchorPoint", Point(0.5, 0.5));
    m_masksToBounds = false;

    __super::Background = _TransparentBrush;

    // Due to the nature of how we lay out our CALayerXamls as 1x1 panels, we need an actual backing element
    // that we can use for hit testing purposes.  Without this backing rectangle, we are unable accept pointer
    // input at the appropriate location in many instances.  For example, we wouldn't be able to click on a UIView
    // that hasn't set a background or any content, which is incorrect behavior.  This will be revisited when
    // we move the code closer to UI.Composition Visual usage.
    SetBackgroundColor(0, 0, 0, 0);
}

CALayerXaml^ CALayerXaml::CreateLayer() {
    ICacheableObject^ ret = _LayerContentCache->GetCachableObject();
    if (ret != nullptr) {
        return (CALayerXaml^)ret;
    }

    CALayerXaml^ newLayer = ref new CALayerXaml();

    auto layerVisual = ElementCompositionPreview::GetElementVisual(newLayer);
    layerVisual->BorderMode = CompositionBorderMode::Hard;

    return newLayer;
}

void CALayerXaml::DestroyLayer(CALayerXaml^ layer) {
    layer->_DiscardContent();
    _LayerContentCache->PushCacheableObject(layer);
}

void CALayerXaml::ApplyMagnificationFactor(Canvas^ windowContainer, float scale, float rotation) {
    TransformGroup^ globalTransform = ref new TransformGroup();
    ScaleTransform^ windowScale = ref new ScaleTransform();
    RotateTransform^ orientation = ref new RotateTransform();

    windowScale->ScaleX = scale;
    windowScale->ScaleY = scale;
    windowScale->CenterX = windowContainer->Width / 2.0;
    windowScale->CenterY = windowContainer->Height / 2.0;

    globalTransform->Children->Append(windowScale);
    if (rotation != 0.0) {
        orientation->Angle = rotation;
        orientation->CenterX = windowContainer->Width / 2.0;
        orientation->CenterY = windowContainer->Height / 2.0;

        globalTransform->Children->Append(orientation);
    }

    windowContainer->RenderTransform = globalTransform;
    CALayerXaml::s_screenScale = (double)scale;
}

void CALayerXaml::_AddAnimation(String^ propertyName,
                               UIElement^ target,
                               Storyboard^ storyboard,
                               DoubleAnimation^ copyProperties,
                               Object^ fromValue,
                               Object^ toValue,
                               bool dependent) {
    DoubleAnimation^ posxAnim = ref new DoubleAnimation();
    if (toValue != nullptr) {
        posxAnim->To = (double)toValue;
    }
    if (fromValue != nullptr) {
        posxAnim->From = (double)fromValue;
    }
    posxAnim->Duration = copyProperties->Duration;
    posxAnim->RepeatBehavior = copyProperties->RepeatBehavior;
    posxAnim->AutoReverse = copyProperties->AutoReverse;
    posxAnim->EasingFunction = copyProperties->EasingFunction;
    posxAnim->EnableDependentAnimation = dependent;
    posxAnim->FillBehavior = copyProperties->FillBehavior;
    posxAnim->BeginTime = copyProperties->BeginTime;
    storyboard->Children->Append(posxAnim);

    Storyboard::SetTarget(posxAnim, target);
    Storyboard::SetTargetProperty(posxAnim, propertyName);
}

Object^ CALayerXaml::_GetAnimatedTransformIndex(UIElement^ element, int idx, DependencyProperty^ property) {
    TransformGroup^ grp = (TransformGroup^)element->GetValue(UIElement::RenderTransformProperty);
    TransformCollection^ children = (TransformCollection^)grp->GetValue(TransformGroup::ChildrenProperty);
    DependencyObject^ transform = (DependencyObject^)children->GetAt(idx);

    return transform->GetValue(property);
}

Object^ CALayerXaml::_GetGeneralTransformIndex(UIElement^ element, int idx, DependencyProperty^ property) {
    TransformGroup^ grp = (TransformGroup^)element->GetValue(UIElement::RenderTransformProperty);
    TransformCollection^ children = (TransformCollection^)grp->GetValue(TransformGroup::ChildrenProperty);
    TransformGroup^ transform = (TransformGroup^)children->GetAt(2);
    TransformCollection^ generalTransformChildren = (TransformCollection^)transform->GetValue(TransformGroup::ChildrenProperty);
    DependencyObject^ innerTransform = (DependencyObject^)generalTransformChildren->GetAt(idx);

    return innerTransform->GetValue(property);
}

void CALayerXaml::_AdjustContentOriginX(Storyboard^ storyboard, DoubleAnimation^ properties, Object^ fromValue, Object^ toValue) {
    if (m_content == nullptr) {
        return;
    }
    if (storyboard != nullptr) {
        _AddAnimation("(UIElement.RenderTransform).(TranslateTransform.X)",
                      m_content,
                      storyboard,
                      properties,
                      fromValue != nullptr ? (Object^)fromValue : nullptr,
                      toValue);
    } else {
        ((TranslateTransform^)m_content->RenderTransform)->X = (double)toValue;
    }

    if (Util::isInstanceOf<LayerContent^>(m_content)) {
        static_cast<LayerContent^>(m_content)->_AdjustContentOriginX(storyboard, properties, fromValue, toValue);
    }
}

void CALayerXaml::_AdjustContentOriginY(Storyboard^ storyboard, DoubleAnimation^ properties, Object^ fromValue, Object^ toValue) {
    if (m_content == nullptr) {
        return;
    }
    if (storyboard != nullptr) {
        _AddAnimation("(UIElement.RenderTransform).(TranslateTransform.Y)",
                      m_content,
                      storyboard,
                      properties,
                      fromValue != nullptr ? (Object^)fromValue : nullptr,
                      toValue);
    } else {
        ((TranslateTransform^)m_content->RenderTransform)->Y = (double)toValue;
    }

    if (Util::isInstanceOf<LayerContent^>(m_content)) {
        static_cast<LayerContent^>(m_content)->_AdjustContentOriginY(storyboard, properties, fromValue, toValue);
    }
}

void CALayerXaml::_CalcTransforms() {
    if (!m_createdTransforms) {
        Point destTranslation;

        destTranslation.X = -m_size.Width * m_anchorPoint.X;
        destTranslation.Y = -m_size.Height * m_anchorPoint.Y;
        destTranslation.X -= m_origin.X;
        destTranslation.Y -= m_origin.Y;
        destTranslation.X += m_position.X;
        destTranslation.Y += m_position.Y;

        ((TranslateTransform^)RenderTransform)->X = destTranslation.X;
        ((TranslateTransform^)RenderTransform)->Y = destTranslation.Y;
    }
}

void CALayerXaml::_CreateTransforms() {
    if (!m_createdTransforms) {
        TranslateTransform^ SizeAnchorTransform = ref new TranslateTransform();
        SizeAnchorTransform->X = -m_size.Width * m_anchorPoint.X;
        SizeAnchorTransform->Y = -m_size.Height * m_anchorPoint.Y;

        TranslateTransform^ OriginTransform = ref new TranslateTransform();
        OriginTransform->X = -m_origin.X;
        OriginTransform->Y = -m_origin.Y;

        TransformGroup^ ContentTransform = ref new TransformGroup();
        ContentTransform->Children->Append(ref new RotateTransform());
        ContentTransform->Children->Append(ref new ScaleTransform());
        ContentTransform->Children->Append(ref new TranslateTransform());

        TranslateTransform^ PositionTransform = ref new TranslateTransform();
        PositionTransform->X = m_position.X;
        PositionTransform->Y = m_position.Y;

        TransformGroup^ LayerTransforms = ref new TransformGroup();
        LayerTransforms->Children->Append(SizeAnchorTransform);
        LayerTransforms->Children->Append(OriginTransform);
        LayerTransforms->Children->Append(ContentTransform);
        LayerTransforms->Children->Append(PositionTransform);
        RenderTransform = LayerTransforms;

        VisualWidth = m_size.Width;
        VisualHeight = m_size.Height;
        m_createdTransforms = true;
    }
}

void CALayerXaml::Set(String^ propertyName, Object^ value) {
    CALayerXaml::s_animatableProperties[propertyName]->Set(this, value);
}

Object^ CALayerXaml::Get(String^ propertyName) {
    return CALayerXaml::s_animatableProperties[propertyName]->GetValue(this);
}

void CALayerXaml::SetOpacity() {
    if (m_hidden) {
        __super::Opacity = 0.0;
    } else {
        __super::Opacity = m_opacity;
    }
};

void CALayerXaml::SetZIndex(int zIndex) {
    __super::SetValue(Canvas::ZIndexProperty, zIndex);
}

/* Disable for now
AutomationPeer^ CALayerXaml::OnCreateAutomationPeer()
{
    return ref new CALayerXamlAutomationPeer(this);
}
*/

void CALayerXaml::SizeChangedCallback(DependencyObject^ d, DependencyPropertyChangedEventArgs^ e) {
    ((CALayerXaml^)d)->InvalidateArrange();
}

CALayerXaml::CALayerXaml() {
    Name = L"LayoutElement";
    m_invOriginTransform = ref new TranslateTransform();
    m_clipGeometry = ref new RectangleGeometry();
    m_clipGeometry->Transform = m_invOriginTransform;
    RenderTransform = ref new TranslateTransform();

    Set("anchorPoint", Point(0.5, 0.5));
    LayerOpacity = 1.0;

    Background = _TransparentBrush;

    // note-nithishm-03252016 - DependencyProperty are registered with Panel class instead of CALayerXaml class, as we found that
    // while property look up, the code starts with the base class and not the current class. This might be a bug but for now as a
    // workaround register with the base class.
    if (s_visualWidthProperty == nullptr) {
        s_visualWidthProperty = DependencyProperty::Register("VisualWidth",
                                                             double::typeid,
                                                             Panel::typeid,
                                                             ref new PropertyMetadata((Platform::Object^ )0.0,
                                                                ref new PropertyChangedCallback(&CALayerXaml::SizeChangedCallback)));
    }
    if (s_visualHeightProperty == nullptr) {
        s_visualHeightProperty = DependencyProperty::Register("VisualHeight",
                                                              double::typeid,
                                                              Panel::typeid,
                                                              ref new PropertyMetadata((Platform::Object^ )0.0,
                                                              ref new PropertyChangedCallback(&CALayerXaml::SizeChangedCallback)));
    }

    // Always start off with a clean slate.
    Reset();
}

void CALayerXaml::_CopyPropertiesFrom(CALayerXaml^ fromLayer) {
    Set("opacity", fromLayer->Get("opacity"));
    Set("position", fromLayer->Get("position"));
    Set("size", fromLayer->Get("size"));
    Set("anchorPoint", fromLayer->Get("anchorPoint"));
}

void CALayerXaml::_DiscardContent() {
    if (m_content != nullptr) {
        unsigned int index;
        if (Children->IndexOf(m_content, &index)) {
            Children->RemoveAt(index);
        }
        InvalidateArrange();

        if (Util::isInstanceOf<LayerContent^>(m_content)) {
            LayerContent::DestroyLayerContent((LayerContent^)m_content);
        }
        m_content = nullptr;
    }
}

void CALayerXaml::_SetContent(FrameworkElement^ element) {
    if (m_content == element) {
        return;
    }

    _DiscardContent();

    m_content = element;
    if (element != nullptr) {
        m_content->RenderTransform = m_invOriginTransform;
        this->Children->InsertAt(0, m_content);
        InvalidateArrange();
    }
}

LayerContent^ CALayerXaml::_GetLayerContent(bool create) {
    if (!Util::isInstanceOf<LayerContent^>(m_content)) {
        if (!create) {
            return nullptr;
        }

        LayerContent^ imageContent = LayerContent::CreateLayerContent();
        imageContent->SetGravity(m_contentGravity);
        imageContent->SetContentsCenter(m_contentsCenter);
        imageContent->Background = m_backgroundBrush;
        imageContent->_AdjustContentOriginX(nullptr, nullptr, nullptr, (double)m_origin.X);
        imageContent->_AdjustContentOriginY(nullptr, nullptr, nullptr, (double)m_origin.Y);
        __super::Background = _TransparentBrush;

        _SetContent(imageContent);
    }

    return (LayerContent^)m_content;
}

void CALayerXaml::SetContentGravity(ContentGravity gravity) {
    m_contentGravity = gravity;
    auto layoutContent = _GetLayerContent();
    if (layoutContent != nullptr) {
        layoutContent->SetGravity(gravity);
    }
}

void CALayerXaml::SetContentsCenter(Rect rect) {
    m_contentsCenter = rect;
    auto layoutContent = _GetLayerContent();
    if (layoutContent != nullptr) {
        layoutContent->SetContentsCenter(m_contentsCenter);
    }
}

void CALayerXaml::SetupBackground() {
    if (m_content == nullptr) {
        Rectangle^ rect = ref new Rectangle();
        _SetContent(rect);
    }

    if (Util::isInstanceOf<Rectangle^>(m_content)) {
        static_cast<Rectangle^>(m_content)->Fill = m_backgroundBrush;
    } else {
        static_cast<Panel^>(m_content)->Background = m_backgroundBrush;
    }
}

void CALayerXaml::SetBackgroundColor(float r, float g, float b, float a) {
    m_backgroundColor.R = (unsigned char)(r * 255.0);
    m_backgroundColor.G = (unsigned char)(g * 255.0);
    m_backgroundColor.B = (unsigned char)(b * 255.0);
    m_backgroundColor.A = (unsigned char)(a * 255.0);
    if (m_backgroundColor.A == 0) {
        m_backgroundBrush = _TransparentBrush;
    } else {
        m_backgroundBrush = ref new SolidColorBrush(m_backgroundColor);
    }

    SetupBackground();
}

void CALayerXaml::SetTopMost() {
    _SetContent(nullptr);
    __super::Background = nullptr;
}

void CALayerXaml::SetContentImage(ImageSource^ source, float width, float height, float scale) {
    if (source == nullptr) {
        if (Util::isInstanceOf<LayerContent^>(m_content)) {
            _SetContent(nullptr);
            SetupBackground();
        }
    } else {
        LayerContent^ c = _GetLayerContent(true);
        c->SetImageContent(source, width, height);
        c->SetContentParams(width, height, scale);
    }
}

void CALayerXaml::SetContentElement(FrameworkElement^ elem, float width, float height, float scale) {
    if (elem == nullptr) {
        if (Util::isInstanceOf<LayerContent^>(m_content)) {
            _SetContent(nullptr);
            SetupBackground();
        }
    } else {
        LayerContent^ c = _GetLayerContent(true);
        c->SetElementContent(elem);
        c->SetContentParams(width, height, scale);
    }
}

Size CALayerXaml::ArrangeOverride(Size finalSize) {
    float curWidth = CurrentWidth;
    float curHeight = CurrentHeight;
    if (m_clipGeometry->Rect.Width != curWidth || m_clipGeometry->Rect.Height != curHeight) {
        m_clipGeometry->Rect = Rect(0, 0, curWidth, curHeight);
    }

    if (m_content != nullptr) {
        m_content->Width = curWidth;
        m_content->Height = curHeight;
        m_content->Arrange(Rect(0, 0, curWidth, curHeight));
    }

    unsigned int childrenSize = Children->Size;
    for (unsigned int index = 0; index < childrenSize; index++) {
        FrameworkElement^ curChild = static_cast<FrameworkElement^>(Children->GetAt(index));
        if (curChild == m_content) {
            continue;
        }
        CALayerXaml^ subLayer = dynamic_cast<CALayerXaml^>(curChild);
        if (subLayer != nullptr) {
            subLayer->Arrange(Rect(0, 0, 1.0, 1.0));
        }  else {
            curChild->Arrange(Rect(0, 0, curWidth, curHeight));
        }
    }

    Size ret;
    if (Util::isInstanceOf<CALayerXaml^>(Parent)) {
        ret = Size(1, 1);
    } else {
        ret = Size(curWidth, curHeight);
    }

    return ret;
}

Size CALayerXaml::MeasureOverride(Size availableSize) {
    unsigned int childrenSize = Children->Size;
    for (unsigned int index = 0; index < childrenSize; index++) {
        FrameworkElement^ curChild = (FrameworkElement^)Children->GetAt(index);
        if (curChild == m_content) {
            continue;
        }

        if (!Util::isInstanceOf<CALayerXaml^>(curChild)) {
            curChild->Measure(availableSize);
        }
    }

    return m_size;
}

//
// EventedStoryboard
//
static const double c_hundredNanoSeconds = 10000000.0;

EventedStoryboard::EventedStoryboard() {
    // AppxManifest.xml appears to fail to enumerate runtimeclasses with accessors and no default constructor in the Win8.1 SDK.
    throw ref new Platform::FailureException("Do not use the default constructor; this is merely here as a bug fix.");
}

EventedStoryboard::EventedStoryboard(
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
        if (Completed != nullptr) {
            Completed(this);
        }
        m_container->Stop();
    });
    TimeSpan span = m_container->BeginTime->Value;
    ThreadPoolTimer^ beginTimer =
        ThreadPoolTimer::CreateTimer(ref new TimerElapsedHandler([this](ThreadPoolTimer^ timer) {
                                         IAsyncAction^ ret = m_container->Dispatcher->RunAsync(CoreDispatcherPriority::High,
                                                                                               ref new DispatchedHandler([this]() {
                                                                                                   if (Started != nullptr) {
                                                                                                       Started(this);
                                                                                                   }
                                                                                               }));
                                     }),
                                     m_container->BeginTime->Value);
}

void EventedStoryboard::Start() {
    m_container->Begin();
}

void EventedStoryboard::Abort() {
    for (Animation^ curAnim : m_animations) {
        Object^ curValue = CALayerXaml::s_animatableProperties[curAnim->propertyName]->GetValue(m_animatedLayer);
        CALayerXaml::s_animatableProperties[curAnim->propertyName]->Set(m_animatedLayer, curValue);
    }
}

void EventedStoryboard::_CreateFlip(CALayerXaml^ layer, bool flipRight, bool invert, bool removeFromParent) {
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

    ((PlaneProjection^)layer->Projection)->CenterOfRotationX = layer->CurrentWidth / 2;
    ((PlaneProjection^)layer->Projection)->CenterOfRotationY = layer->CurrentHeight / 2;
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

        fade1->Completed += ref new EventHandler<Object^>([layer](Object^ sender, Object^ args) { layer->Opacity = 1.0; });
    }

    if (removeFromParent) {
        fade1->Completed += ref new EventHandler<Object^>([layer](Object^ sender, Object^ args) {
            VisualTreeHelper::DisconnectChildrenRecursive(layer);
        });
    } else {
        rotateAnim->Completed += ref new EventHandler<Object^>([layer](Object^ sender, Object^ args) {
            // Using Projection transforms (even Identity) causes less-than-pixel-perfect rendering.
            layer->Projection = nullptr;
        });
    }

    m_container->Children->Append(fade1);
}

void EventedStoryboard::_CreateWoosh(CALayerXaml^ layer, bool fromRight, bool invert, bool removeFromParent) {
    if (layer->Projection == nullptr) {
        layer->Projection = ref new PlaneProjection();
    }

    DoubleAnimation^ wooshAnim = ref new DoubleAnimation();
    wooshAnim->Duration = m_container->Duration;
    wooshAnim->EasingFunction = ref new PowerEase();
    wooshAnim->EasingFunction->EasingMode = EasingMode::EaseOut;

    if (!invert) {
        if (fromRight) {
            wooshAnim->From = (double)layer->CurrentWidth;
            wooshAnim->To = 0.01;
        } else {
            wooshAnim->From = 0.01;
            wooshAnim->To = (double)layer->CurrentWidth;
        }
    } else {
        if (fromRight) {
            wooshAnim->From = 0.01;
            wooshAnim->To = (double)(-layer->CurrentWidth / 4);
        } else {
            wooshAnim->From = (double)(-layer->CurrentWidth / 4);
            wooshAnim->To = 0.01;
        }
    }

    Storyboard::SetTargetProperty(wooshAnim, "(UIElement.Projection).(PlaneProjection.LocalOffsetX)");
    Storyboard::SetTarget(wooshAnim, layer);

    if (removeFromParent) {
        wooshAnim->Completed += ref new EventHandler<Object^>([layer](Object^ sender, Object^ args) {
            VisualTreeHelper::DisconnectChildrenRecursive(layer);
        });
    } else {
        wooshAnim->Completed += ref new EventHandler<Object^>([layer](Object^ sender, Object^ args) {
            // Using Projection transforms (even Identity) causes less-than-pixel-perfect rendering.
            layer->Projection = nullptr;
        });
    }

    m_container->Children->Append(wooshAnim);
}

concurrency::task<CALayerXaml^> EventedStoryboard::SnapshotLayer(CALayerXaml^ layer) {
    if (((layer->m_size.Height == 0) && (layer->m_size.Width == 0)) || (layer->Opacity == 0)) {
        return concurrency::task_from_result<CALayerXaml^>(nullptr);
    }
    else {
        RenderTargetBitmap^ snapshot = ref new RenderTargetBitmap();
        return concurrency::create_task(snapshot->RenderAsync(layer, (int)(layer->CurrentWidth * CALayerXaml::s_screenScale), 0))
            .then([snapshot, layer](concurrency::task<void> result) noexcept {
            try {
                result.get();
            } catch (Platform::InvalidArgumentException^ ex) {
                // Handle exceptions related to invalid layer attribute passed to RenderAsync
                TraceWarning(TAG,
                             L"RenderAsync threw InvalidArgumentException exception - [%ld]%s",
                             ex->HResult,
                             ex->Message);
                return (CALayerXaml^)nullptr;
            }

            // Return a new 'copy' layer with the rendered content
            CALayerXaml^ newLayer = CALayerXaml::CreateLayer();
            newLayer->_CopyPropertiesFrom(layer);

            int width = snapshot->PixelWidth;
            int height = snapshot->PixelHeight;
            DisplayInformation^ dispInfo = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            newLayer->SetContentImage(snapshot, (float)width, (float)height, (float)(CALayerXaml::s_screenScale * dispInfo->RawPixelsPerViewPixel));

            // There seems to be a bug in Xaml where Render'd layers get sized to their visible content... sort of.
            // If the UIViewController being transitioned away from has transparent content, the height returned is less the
            // navigation bar, as though Xaml sizes the buffer to the largest child Visual, and only expands where needed.
            // Top/bottom switched due to geometric origin of CALayer so read this as UIViewContentModeTopLeft
            newLayer->SetContentGravity(ContentGravity::BottomLeft);

            return newLayer;
        }, concurrency::task_continuation_context::use_current());
    }
}

void EventedStoryboard::AddTransition(CALayerXaml^ realLayer, CALayerXaml^ snapshotLayer, String^ type, String^ subtype) {
    if (type == "kCATransitionFlip") {
        TimeSpan timeSpan = TimeSpan();
        timeSpan.Duration = (long long)(0.75 * c_hundredNanoSeconds);
        m_container->Duration = Duration(timeSpan);
        Panel^ parent = (Panel^)VisualTreeHelper::GetParent(realLayer);

        bool flipToLeft = true;
        if (subtype != "kCATransitionFromLeft") {
            flipToLeft = false;
        }

        // We don't need to animate a snapshot if it doesn't exist
        if (snapshotLayer) {
            unsigned int idx;
            parent->Children->IndexOf(realLayer, &idx);
            parent->Children->InsertAt(idx + 1, snapshotLayer);
            parent->InvalidateArrange();
            realLayer->Opacity = 0;
            _CreateFlip(snapshotLayer, flipToLeft, false, true);
        }

        _CreateFlip(realLayer, flipToLeft, true, false);
    }
    else {
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
                unsigned int idx;
                parent->Children->IndexOf(realLayer, &idx);
                parent->Children->InsertAt(idx, snapshotLayer);
                parent->InvalidateArrange();
                _CreateWoosh(snapshotLayer, fromRight, true, true);
            }

            _CreateWoosh(realLayer, fromRight, false, false);
        }
        else {
            // We don't need to animate a snapshot if it doesn't exist
            if (snapshotLayer) {
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

void EventedStoryboard::Animate(CALayerXaml^ layer, String^ propertyName, Object^ from, Object^ to) {
    DoubleAnimation^ timeline = ref new DoubleAnimation();
    timeline->Duration = m_container->Duration;
    timeline->EasingFunction = m_animationEase;

    CALayerXaml::s_animatableProperties[propertyName]->Animate(layer, m_container, timeline, from, to);
}

Object^ EventedStoryboard::GetStoryboard() {
    return m_container;
}

//
// CATextLayerXaml
//
void CATextLayerXaml::Reset() {
    TextBlock->Text = "";
    TextBlock->Width = std::nan(NULL);
    TextBlock->Height = std::nan(NULL);
}

CATextLayerXaml^ CATextLayerXaml::CreateTextLayer() {
    ICacheableObject^ ret = _TextLayerCache->GetCachableObject();
    if (ret != nullptr) {
        return (CATextLayerXaml^)ret;
    }

    return ref new CATextLayerXaml();
}

void CATextLayerXaml::DestroyTextLayer(CATextLayerXaml^ content) {
    _TextLayerCache->PushCacheableObject(content);
}

} // Controls
} // XamlCompositor

// clang-format on
