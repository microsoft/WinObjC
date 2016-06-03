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
// clang-format does not seem to like C++/CX
// clang-format off
#pragma once

#include <list>
#include <map>
#include <queue>

namespace XamlCompositor {
namespace Controls {
/// <summary>
///
/// </summary>
public
enum class ContentGravity {
    Resize = 0,
    Center,
    Top,
    ResizeAspect,
    TopLeft,
    BottomLeft,
    Left,
    ResizeAspectFill,
    Bottom,
    TopRight,
    Right,
    BottomRight
};

private
class Util {
public:
    template <class T, class U>
    static bool isInstanceOf(U u) {
        return (dynamic_cast<T>(u) != nullptr);
    };
};

/// <summary>
///
/// </summary>
public
interface class ICacheableObject {
    virtual void Reset() = 0;
};

/// <summary>
///
/// </summary>
private
ref class ObjectCache sealed {
public:
    ObjectCache(size_t maxSize = 32) : m_maxSize(maxSize){};
    ICacheableObject^ GetCachableObject();
    void PushCacheableObject(ICacheableObject^ obj);

private:
    std::queue<ICacheableObject^> m_objects;
    size_t m_maxSize;
};

/// <summary>
///
/// </summary>
[Windows::Foundation::Metadata::WebHostHidden]
public
ref class LayerContent sealed : Windows::UI::Xaml::Controls::Panel, ICacheableObject {
public:
    LayerContent();
    virtual void Reset();
    static LayerContent^ CreateLayerContent();
    static void DestroyLayerContent(LayerContent^ content);
    void SetContentsCenter(Windows::Foundation::Rect rect);
    void SetGravity(ContentGravity imgGravity);
    void SetImageContent(Windows::UI::Xaml::Media::ImageSource^ source, float width, float height);
    void SetContentParams(float width, float height, float scale);
    void SetElementContent(Windows::UI::Xaml::FrameworkElement^ source);

protected:
    Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size finalSize) override;
    Windows::Foundation::Size MeasureOverride(Windows::Foundation::Size availableSize) override;

internal:
    void _AdjustContentOriginX(Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                                         Windows::UI::Xaml::Media::Animation::DoubleAnimation^ properties,
                                         Platform::Object^ fromValue,
                                         Platform::Object^ toValue);
    void _AdjustContentOriginY(Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                              Windows::UI::Xaml::Media::Animation::DoubleAnimation^ properties,
                              Platform::Object^ fromValue,
                              Platform::Object^ toValue);

private:
    static property ObjectCache^
        _LayerContentCache {
            ObjectCache^ get() {
                static ObjectCache^ instance = ref new ObjectCache();
                return instance;
            }
        }

    Windows::UI::Xaml::Controls::Image^ m_image;
    Windows::UI::Xaml::FrameworkElement^ m_content;
    Windows::Foundation::Size m_imageSize;
    Windows::Foundation::Size m_contentSize = Windows::Foundation::Size(0, 0);
    Windows::Foundation::Rect m_contentsCenter = Windows::Foundation::Rect(0, 0, 1.0, 1.0);
    ContentGravity m_gravity;
    float m_scaleFactor = 1.0f;
    Windows::Foundation::Point m_origin = Windows::Foundation::Point();

    int _IfNegativeMakeZero(int value);
    void _ApplyContentsCenter();
    Windows::Foundation::Rect _GetContentGravityRect(Windows::Foundation::Size size);
    Windows::UI::Xaml::Controls::Image^ _GetImage();
};

/// <summary>
///
/// </summary>
[Windows::Foundation::Metadata::WebHostHidden]
public ref class CALayerXaml sealed : Windows::UI::Xaml::Controls::Panel, ICacheableObject {
    delegate void ApplyAnimationFunction(CALayerXaml^ target,
                                         Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                                         Windows::UI::Xaml::Media::Animation::DoubleAnimation^ properties,
                                         Platform::Object^ fromValue,
                                         Platform::Object^ toValue);
    delegate void ApplyTransformFunction(CALayerXaml^ target, Platform::Object^ toValue);
    delegate Platform::Object^ GetCurrentValue(CALayerXaml^ target);

    /// <summary>
    ///
    /// </summary>
    ref class AnimatableProperty sealed {
    public:
        property ApplyAnimationFunction^ Animate;
        property ApplyTransformFunction^ Set;
        property GetCurrentValue^ GetValue;

        AnimatableProperty(ApplyAnimationFunction^ animFunction, ApplyTransformFunction^ setFunction, GetCurrentValue^ getValue) {
            Animate = animFunction;
            Set = setFunction;
            GetValue = getValue;
        };
    };

public:
    property float CurrentWidth {
        float get() {
            if (m_createdTransforms) {
                return (float)VisualWidth;
            } else {
                return m_size.Width;
            }
        }
    };

    property float CurrentHeight {
        float get() {
            if (m_createdTransforms) {
                return (float)VisualHeight;
            } else {
                return m_size.Height;
            }
        }
    };

    property double LayerOpacity {
        double get() {
            return m_opacity;
        }
        void set(double value) {
            m_opacity = value;
            SetOpacity();
        }
    };


    static property Windows::UI::Xaml::DependencyProperty^ VisualWidthProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_visualWidthProperty;
        }
    };

    static property Windows::UI::Xaml::DependencyProperty^ VisualHeightProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_visualHeightProperty;
        }
    };

    property double VisualWidth {
        double get() {
            return (double)GetValue(VisualWidthProperty);
        }
        void set(double value) {
            SetValue(VisualWidthProperty, value);
        }
    };

    property double VisualHeight {
        double get() {
            return (double)GetValue(VisualHeightProperty);
        }
        void set(double value) {
            SetValue(VisualHeightProperty, value);
        }
    };

    property bool Hidden {
        bool get() {
            return m_hidden;
        }
        void set(bool value) {
            m_hidden = value;
            SetOpacity();
        }
    };

    CALayerXaml();
    virtual void Reset();
    void Set(Platform::String^ propertyName, Platform::Object^ value);
    Platform::Object^ Get(Platform::String^ propertyName);
    void SetOpacity();
    void SetZIndex(int zIndex);
    static CALayerXaml^ CreateLayer();
    static void DestroyLayer(CALayerXaml^ layer);
    static void ApplyMagnificationFactor(Windows::UI::Xaml::Controls::Canvas^ windowContainer, float scale, float rotation);
    static void SizeChangedCallback(Windows::UI::Xaml::DependencyObject^ d, Windows::UI::Xaml::DependencyPropertyChangedEventArgs^ e);
    void SetContentGravity(ContentGravity gravity);
    void SetContentsCenter(Windows::Foundation::Rect rect);
    void SetupBackground();
    void SetBackgroundColor(float r, float g, float b, float a);
    void SetTopMost();
    void SetContentImage(Windows::UI::Xaml::Media::ImageSource^ source, float width, float height, float scale);
    void SetContentElement(Windows::UI::Xaml::FrameworkElement^ elem, float width, float height, float scale);

protected:
    // Windows::UI::Xaml::Automation::Peers::AutomationPeer^ OnCreateAutomationPeer() override;
    Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size finalSize) override;
    Windows::Foundation::Size MeasureOverride(Windows::Foundation::Size availableSize) override;

internal:
    static double s_screenScale;
    bool m_originSet = false;
    Windows::UI::Color m_backgroundColor;
    Windows::UI::Xaml::Media::SolidColorBrush^ m_backgroundBrush = _TransparentBrush;
    Windows::Foundation::Point m_position;
    bool m_createdTransforms = false;
    bool m_masksToBounds;
    Windows::Foundation::Point m_origin;
    Windows::Foundation::Size m_size;
    Windows::Foundation::Point m_anchorPoint;
    double m_opacity;
    ContentGravity m_contentGravity = ContentGravity::Resize;
    static std::map<Platform::String^, AnimatableProperty^> s_animatableProperties;
    Windows::UI::Xaml::Media::RectangleGeometry^ m_clipGeometry;

    static void _AddAnimation(Platform::String^ propertyName,
                             Windows::UI::Xaml::UIElement^ target,
                             Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                             Windows::UI::Xaml::Media::Animation::DoubleAnimation^ copyProperties,
                             Platform::Object^ fromValue,
                             Platform::Object^ toValue,
                             bool dependent = false);
    static Platform::Object^
        _GetAnimatedTransformIndex(Windows::UI::Xaml::UIElement^ element, int idx, Windows::UI::Xaml::DependencyProperty^ property);
    static Platform::Object^
        _GetGeneralTransformIndex(Windows::UI::Xaml::UIElement^ element, int idx, Windows::UI::Xaml::DependencyProperty^ property);
    void _AdjustContentOriginX(Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                               Windows::UI::Xaml::Media::Animation::DoubleAnimation^ properties,
                               Platform::Object^ fromValue,
                               Platform::Object^ toValue);
    void _AdjustContentOriginY(Windows::UI::Xaml::Media::Animation::Storyboard^ storyboard,
                               Windows::UI::Xaml::Media::Animation::DoubleAnimation^ properties,
                               Platform::Object^ fromValue,
                               Platform::Object^ toValue);
    void _CreateTransforms();
    void _CalcTransforms();
    void _CopyPropertiesFrom(CALayerXaml^ fromLayer);
    void _DiscardContent();

private:
    static property Windows::UI::Xaml::Media::SolidColorBrush^ _TransparentBrush {
        Windows::UI::Xaml::Media::SolidColorBrush^ get() {
            static Windows::UI::Xaml::Media::SolidColorBrush^ instance =
                ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Transparent);
            return instance;
        }
    };
    static property ObjectCache^ _LayerContentCache {
        ObjectCache^ get() {
            static ObjectCache^ instance = ref new ObjectCache();
            return instance;
        }
    };

    static Windows::UI::Xaml::DependencyProperty^ s_visualWidthProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_visualHeightProperty;
    Windows::UI::Xaml::FrameworkElement^ m_content;
    Windows::Foundation::Rect m_contentsCenter = Windows::Foundation::Rect(0, 0, 1, 1);
    Windows::UI::Xaml::Media::TranslateTransform^ m_invOriginTransform;
    bool m_hidden = false;

    void _CALayerXaml_PointerPressed(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _CALayerXaml_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _CALayerXaml_PointerCanceled(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _CALayerXaml_PointerMoved(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _SetContent(Windows::UI::Xaml::FrameworkElement^ element);
    LayerContent^ _GetLayerContent(bool create = false);
};

/// <summary>
///
/// </summary>
[Windows::Foundation::Metadata::WebHostHidden]
public
ref class CALayerXamlAutomationPeer sealed : Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer {
public:
    CALayerXamlAutomationPeer(CALayerXaml^ owner) : FrameworkElementAutomationPeer(owner){};

protected:
    virtual Platform::String^ GetClassNameCore() override {
        return ref new Platform::String(L"FakeClassName");
    };

    virtual Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore() override {
        return Windows::UI::Xaml::Automation::Peers::AutomationControlType::ScrollBar;
    };
};

/// <summary>
///
/// </summary>
public
delegate void AnimationMethod(Platform::Object^ sender);

[Windows::Foundation::Metadata::WebHostHidden]
public
ref class EventedStoryboard sealed {
    ref class Animation {
    internal:
        Platform::String^ propertyName = nullptr;
        Platform::Object^ toValue = nullptr;
    };

    enum class EasingFunction { EastInEaseIn, Linear };

public:
    property AnimationMethod^ Completed {
        AnimationMethod^ get() {
            return m_completed;
        }
        void set(AnimationMethod^ value) {
            m_completed = value;
        }
    };

    property AnimationMethod^ Started {
        AnimationMethod^ get() {
            return m_started;
        }
        void set(AnimationMethod^ value) {
            m_started = value;
        }
    };

    property Windows::UI::Xaml::Media::Animation::EasingFunctionBase^ AnimationEase {
        Windows::UI::Xaml::Media::Animation::EasingFunctionBase^ get() {
            return m_animationEase;
        }
        void set(Windows::UI::Xaml::Media::Animation::EasingFunctionBase^ value) {
            m_animationEase = value;
        }
    };

    EventedStoryboard();
    EventedStoryboard(
        double beginTime, double duration, bool autoReverse, float repeatCount, float repeatDuration, float speed, double timeOffset);
    void Start();
    void Abort();
    void Animate(CALayerXaml^ layer, Platform::String^ propertyName, Platform::Object^ from, Platform::Object^ to);
    Platform::Object^ GetStoryboard();

internal:
    AnimationMethod^ m_completed;
    AnimationMethod^ m_started;

    concurrency::task<CALayerXaml^> SnapshotLayer(CALayerXaml^ layer);
    void AddTransition(CALayerXaml^ realLayer, CALayerXaml^ snapshotLayer, Platform::String^ type, Platform::String^ subtype);
    void _CreateFlip(CALayerXaml^ layer, bool flipRight, bool invert, bool removeFromParent);
    void _CreateWoosh(CALayerXaml^ layer, bool fromRight, bool invert, bool removeFromParent);

private:
    Windows::UI::Xaml::Media::Animation::Storyboard^ m_container = ref new Windows::UI::Xaml::Media::Animation::Storyboard();
    std::list<Animation^> m_animations;
    CALayerXaml^ m_animatedLayer = nullptr;
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase^ m_animationEase;
};

/// <summary>
///
/// </summary>
public
interface class ICALayerXamlInputEvents {
    virtual void PointerDown(float x, float y, unsigned int id, unsigned long long timestamp) = 0;
    virtual void PointerUp(float x, float y, unsigned int id, unsigned long long timestamp) = 0;
    virtual void PointerMoved(float x, float y, unsigned int id, unsigned long long timestamp) = 0;
    virtual void KeyDown(unsigned int key) = 0;
};

/// <summary>
///
/// </summary>
public
ref class CALayerInputHandler sealed {
public:
    static property CALayerInputHandler^ Instance {
        CALayerInputHandler^ get() {
            static CALayerInputHandler^ instance = ref new CALayerInputHandler();
            return instance;
        }
    };
    void SetInputHandler(ICALayerXamlInputEvents^ handler);

internal:
    void _HandleDownInput(CALayerXaml^ layer, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _HandleUpInput(CALayerXaml^ layer, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
    void _HandleMoveInput(CALayerXaml^ layer, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);

private:
    ICALayerXamlInputEvents^ m_inputEventHandler;
    Windows::UI::Xaml::Controls::Control^ m_dummyFocus;

    CALayerInputHandler() {};
    void _CoreWindow_CharacterReceived(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::CharacterReceivedEventArgs^ args);
};

/// <summary>
///
/// </summary>
[Windows::Foundation::Metadata::WebHostHidden]
public
ref class CATextLayerXaml sealed : ICacheableObject {
public:
    property Windows::UI::Xaml::Controls::TextBlock^ TextBlock {
        Windows::UI::Xaml::Controls::TextBlock^ get() {
            return m_textBlock;
        }
    };

    virtual void Reset();
    static CATextLayerXaml^ CreateTextLayer();
    static void DestroyTextLayer(CATextLayerXaml^ content);

private:
    static property ObjectCache^ _TextLayerCache {
        ObjectCache^ get() {
            static ObjectCache^ instance = ref new ObjectCache();
            return instance;
        }
    };

    Windows::UI::Xaml::Controls::TextBlock^ m_textBlock = ref new Windows::UI::Xaml::Controls::TextBlock();
};

} // Controls
} // XamlCompositor

// clang-format on
