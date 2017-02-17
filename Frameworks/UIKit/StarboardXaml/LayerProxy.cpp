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

#include "LayerProxy.h"
#include "LayerCoordinator.h"

#include <assert.h>
#include <ErrorHandling.h>

using namespace Microsoft::WRL;
using namespace UIKit::Xaml::Private::CoreAnimation;
using namespace Windows::Foundation;
using namespace Windows::Storage::Streams;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

static const wchar_t* TAG = L"LayerProxy";

static const bool DEBUG_ALL = false;
static const bool DEBUG_HIERARCHY = DEBUG_ALL | false;

// TODO: We should formally expose this off of XamlCompositor for our use here.
extern Canvas^ s_windowCollection;

__inline FrameworkElement^ _FrameworkElementFromInspectable(const ComPtr<IInspectable>& element) {
    return dynamic_cast<FrameworkElement^>(reinterpret_cast<Platform::Object^>(element.Get()));
};

__inline Panel^ _SubLayerPanelFromInspectable(const ComPtr<IInspectable>& element) {
    FrameworkElement^ xamlElement = _FrameworkElementFromInspectable(element);

    // First check if the element implements ILayer
    ILayer^ layerElement = dynamic_cast<ILayer^>(xamlElement);
    if (layerElement) {
        if (DEBUG_HIERARCHY) {
            TraceVerbose(
                TAG,
                L"_SubLayerPanelFromInspectable for [%ws] returning layerElement->SublayerCanvas [%ws].",
                layerElement->GetType()->FullName->Data(),
                layerElement->SublayerCanvas->GetType()->FullName->Data());
        }

        return layerElement->SublayerCanvas;
    }

    // Not an ILayer, so default to grabbing the xamlElement's SublayerCanvasProperty (if it exists)
    Platform::Object^ value = xamlElement->GetValue(Layer::SublayerCanvasProperty);
    if (DEBUG_HIERARCHY) {
        TraceVerbose(
            TAG,
            L"GetValue(Layer::SublayerCanvasProperty) for [%ws] returned layerElement->SublayerCanvas [%ws].",
            xamlElement->GetType()->FullName->Data(),
            (value ? value->GetType()->FullName->Data() : L"nullptr"));
    }

    return dynamic_cast<Canvas^>(value);
};

__inline LayerProperty^ _GetBorderBrushProperty(FrameworkElement^ xamlLayer) {
    // Look for a pre-canned BorderBrush dependency property on the types that we know support it
    if (ILayer^ layer = dynamic_cast<ILayer^>(xamlLayer)) {
        return layer->GetBorderBrushProperty();
    } else if (Grid^ grid = dynamic_cast<Grid^>(xamlLayer)) {
        return ref new LayerProperty(grid, grid->BorderBrushProperty);
    } else if (Control^ control = dynamic_cast<Control^>(xamlLayer)) {
        return ref new LayerProperty(control, control->BorderBrushProperty);
    } else {
        UNIMPLEMENTED_WITH_MSG(
            "BorderBrush not supported on this Xaml element: [%ws].",
            xamlLayer->GetType()->FullName->Data());
    }

    return nullptr;
}

__inline LayerProperty^ _GetBorderThicknessProperty(FrameworkElement^ xamlLayer) {
    // Look for a pre-canned BorderThicknessProperty dependency property on the types that we know support it
    if (ILayer^ layer = dynamic_cast<ILayer^>(xamlLayer)) {
        return layer->GetBorderThicknessProperty();
    } else if (Grid^ grid = dynamic_cast<Grid^>(xamlLayer)) {
        return ref new LayerProperty(grid, grid->BorderThicknessProperty);
    } else if (Control^ control = dynamic_cast<Control^>(xamlLayer)) {
        return ref new LayerProperty(control, control->BorderThicknessProperty);
    } else {
        UNIMPLEMENTED_WITH_MSG(
            "BorderWidth not supported on this Xaml element: [%ws].",
            xamlLayer->GetType()->FullName->Data());
    }

    return nullptr;
}

LayerProxy::LayerProxy(IInspectable* xamlElement) :
    _xamlElement(nullptr),
    _isRoot(false),
    _currentTexture(nullptr),
    _topMost(false) {

    // If we weren't passed a xaml element, default to our Xaml CALayer representation
    if (!xamlElement) {
        _xamlElement = reinterpret_cast<IInspectable*>(ref new Layer());
    } else {
        _xamlElement = xamlElement;
    }

    // Initialize the UIElement with CoreAnimation
    CoreAnimation::LayerCoordinator::InitializeFrameworkElement(_FrameworkElementFromInspectable(_xamlElement));
}

Microsoft::WRL::ComPtr<IInspectable> LayerProxy::GetXamlElement() {
    return _xamlElement;
}

Microsoft::WRL::ComPtr<IInspectable> LayerProxy::GetSublayerXamlElement() {
    // If we have a sublayer panel return it, else return _xamlElement
    Panel^ sublayerPanel = _SubLayerPanelFromInspectable(_xamlElement);
    return sublayerPanel ? reinterpret_cast<IInspectable*>(sublayerPanel) : _xamlElement;
}

///////////////////////////////////////////////////////////////////////////////////////
// TODO: We should remove this and just do it on UIWindow's backing element since that's the only place it's used
void LayerProxy::_SetZIndex(int zIndex) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    xamlLayer->SetValue(Canvas::ZIndexProperty, zIndex);
}
///////////////////////////////////////////////////////////////////////////////////////

void LayerProxy::_SetProperty(const char* name, float value) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    CoreAnimation::LayerCoordinator::SetValue(xamlLayer, name, (double)value);
}

void LayerProxy::_SetPropertyInt(const char* name, int value) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    CoreAnimation::LayerCoordinator::SetValue(xamlLayer, name, value);
}

void LayerProxy::_SetHidden(bool hidden) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    xamlLayer->Visibility = (hidden ? Visibility::Collapsed : Visibility::Visible);
}

void LayerProxy::_SetMasksToBounds(bool masksToBounds) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    CoreAnimation::LayerCoordinator::SetValue(xamlLayer, "masksToBounds", masksToBounds);
}

float LayerProxy::_GetPresentationPropertyValue(const char* name) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    return (float)(double)CoreAnimation::LayerCoordinator::GetValue(xamlLayer, name);
}

void LayerProxy::_SetContentsCenter(float x, float y, float width, float height) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    CoreAnimation::LayerCoordinator::SetContentCenter(xamlLayer, Rect(x, y, width, height));
}

// TODO: Find a way to remove this
void LayerProxy::SetTopMost() {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    _topMost = true;

    // If the element is a Panel, set its background to nullptr so it can't
    // accept pointer input.  
    // Note: we should probably find a cleaner way to handle our top-level UIWindows' layers.
    if (dynamic_cast<Panel^>(xamlLayer)) {
        dynamic_cast<Panel^>(xamlLayer)->Background = nullptr;
    }
}

SolidColorBrush^ _SolidColorBrushFromLayerColor(const LayerColor& color) {
    Windows::UI::Color windowsColor;
    windowsColor.R = static_cast<unsigned char>(color.r * 255.0);
    windowsColor.G = static_cast<unsigned char>(color.g * 255.0);
    windowsColor.B = static_cast<unsigned char>(color.b * 255.0);
    windowsColor.A = static_cast<unsigned char>(color.a * 255.0);
    return ref new SolidColorBrush(windowsColor);
}

LayerColor _LayerColorFromSolidColorBrush(SolidColorBrush^ brush) {
    LayerColor color;
    if (brush) {
        Windows::UI::Color windowsColor = brush->Color;
        color.r = static_cast<float>(windowsColor.R / 255.0);
        color.g = static_cast<float>(windowsColor.G / 255.0);
        color.b = static_cast<float>(windowsColor.B / 255.0);
        color.a = static_cast<float>(windowsColor.A / 255.0);
    }

    return color;
}

void LayerProxy::_SetBackgroundColor(const LayerColor& color) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);

    // A null brush is transparent and not hit-testable; we only want this for 'root' or 'topmost' layers/views.
    // For everything else, we simply map through the background color that was set on the layer/view.
    // Note that UIView hit-testability is handled in UIView via its 'userInteractionEnabled', 'isHidden', and 'alpha' property values.
    SolidColorBrush^ backgroundBrush = nullptr; 
    if (!_isRoot && !_topMost) {
        backgroundBrush = _SolidColorBrushFromLayerColor(color);
    }

    // Panel and Control each have a Background property that we can set
    if (Panel^ panel = dynamic_cast<Panel^>(xamlLayer)) {
        panel->Background = backgroundBrush;
    } else if (Control^ control = dynamic_cast<Control^>(xamlLayer)) {
        control->Background = backgroundBrush;
    } else {
        UNIMPLEMENTED_WITH_MSG(
            "SetBackgroundColor not supported on this Xaml element: [%ws].",
            xamlLayer->GetType()->FullName->Data());
    }
}

void LayerProxy::_SetBorderColor(const LayerColor& color) {
    // Set the BorderBrush property if this layer supports it
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    LayerProperty^ borderBrushProperty = _GetBorderBrushProperty(xamlLayer);
    if (borderBrushProperty) {
        SolidColorBrush^ borderBrush = _SolidColorBrushFromLayerColor(color);
        borderBrushProperty->SetValue(borderBrush);
    }
}

LayerColor LayerProxy::_GetBorderColor() {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    SolidColorBrush^ borderBrush = nullptr;

    // Get the BorderBrush property if this layer supports it
    LayerProperty^ borderBrushProperty = _GetBorderBrushProperty(xamlLayer);
    if (borderBrushProperty) {
        borderBrush = safe_cast<SolidColorBrush^>(borderBrushProperty->GetValue());
    }

    return _LayerColorFromSolidColorBrush(borderBrush);
}

void LayerProxy::_SetBorderWidth(float width) {
    // Set the BorderThickness property if this layer supports it
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    LayerProperty^ borderThicknessProperty = _GetBorderThicknessProperty(xamlLayer);
    if (borderThicknessProperty) {
        Thickness thickness(width);
        borderThicknessProperty->SetValue(thickness);
    }
}

float LayerProxy::_GetBorderWidth() {
    // Get the BorderThickness property if this layer supports it
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    LayerProperty^ borderThicknessProperty = _GetBorderThicknessProperty(xamlLayer);
    if (borderThicknessProperty) {
        Thickness thickness = static_cast<Thickness>(borderThicknessProperty->GetValue());

        assert(thickness.Left == thickness.Right && thickness.Left == thickness.Top && thickness.Left == thickness.Bottom);

        // Return an arbitrary field of the thickness as our width, since they should all be equal
        return static_cast<float>(thickness.Left);
    }

    return 0.0;
}

void LayerProxy::SetShouldRasterize(bool rasterize) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    if (rasterize) {
        xamlLayer->CacheMode = ref new Media::BitmapCache();
    } else if (xamlLayer->CacheMode) {
        xamlLayer->CacheMode = nullptr;
    }
}

void LayerProxy::_SetContents(const Microsoft::WRL::ComPtr<IInspectable>& bitmap, float width, float height, float scale) {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    if (bitmap) {
        auto content = dynamic_cast<Media::ImageSource^>(reinterpret_cast<Platform::Object^>(bitmap.Get()));
        CoreAnimation::LayerCoordinator::SetContent(xamlLayer, content, width, height, scale);
    } else {
        CoreAnimation::LayerCoordinator::SetContent(xamlLayer, nullptr, width, height, scale);
    }
}

void LayerProxy::AddToRoot() {
    FrameworkElement^ xamlLayer = _FrameworkElementFromInspectable(_xamlElement);
    s_windowCollection->Children->Append(xamlLayer);
    _SetMasksToBounds(true);
    _isRoot = true;
}

void LayerProxy::AddSubLayer(const std::shared_ptr<LayerProxy>& subLayer, const std::shared_ptr<LayerProxy>& before, const std::shared_ptr<LayerProxy>& after) {
    // Make sure the sublayer isn't already parented
    {
        auto strongParent = subLayer->_parent.lock();
        assert(!strongParent);
    }

    // Set ourselves as the sublayer's parent
    subLayer->_parent = shared_from_this();
    _subLayers.insert(subLayer);

    FrameworkElement^ xamlElementForSubLayer = _FrameworkElementFromInspectable(subLayer->_xamlElement);
    Panel^ subLayerPanelForThisLayer = _SubLayerPanelFromInspectable(_xamlElement);
    if (!subLayerPanelForThisLayer) {
        UNIMPLEMENTED_WITH_MSG(
            "AddSubLayer not supported on this Xaml element: [%ws].", 
            _FrameworkElementFromInspectable(_xamlElement)->GetType()->FullName->Data());
        return;
    }

    if (before == NULL && after == NULL) {
        subLayerPanelForThisLayer->Children->Append(xamlElementForSubLayer);
    } else if (before != NULL) {
        FrameworkElement^ xamlBeforeLayer = _FrameworkElementFromInspectable(before->_xamlElement);
        unsigned int idx = 0;
        if (subLayerPanelForThisLayer->Children->IndexOf(xamlBeforeLayer, &idx) == true) {
            subLayerPanelForThisLayer->Children->InsertAt(idx, xamlElementForSubLayer);
        } else {
            FAIL_FAST();
        }
    } else if (after != NULL) {
        FrameworkElement^ xamlAfterLayer = _FrameworkElementFromInspectable(after->_xamlElement);
        unsigned int idx = 0;
        if (subLayerPanelForThisLayer->Children->IndexOf(xamlAfterLayer, &idx) == true) {
            subLayerPanelForThisLayer->Children->InsertAt(idx + 1, xamlElementForSubLayer);
        } else {
            FAIL_FAST();
        }
    }

    subLayerPanelForThisLayer->InvalidateArrange();
}

void LayerProxy::MoveLayer(const std::shared_ptr<LayerProxy>& before, const std::shared_ptr<LayerProxy>& after) {
    // Grab a strong reference to our parent
    auto strongParent = _parent.lock();
    assert(strongParent);

    FrameworkElement^ xamlElementForThisLayer = _FrameworkElementFromInspectable(_xamlElement);
    Panel^ subLayerPanelForParentLayer = _SubLayerPanelFromInspectable(strongParent->_xamlElement);
    if (!subLayerPanelForParentLayer) {
        FrameworkElement^ xamlElementForParentLayer = _FrameworkElementFromInspectable(strongParent->_xamlElement);
        UNIMPLEMENTED_WITH_MSG(
            "MoveLayer for [%ws] not supported on parent [%ws].",
            xamlElementForThisLayer->GetType()->FullName->Data(),
            xamlElementForParentLayer->GetType()->FullName->Data());
        return;
    }

    if (before) {
        FrameworkElement^ xamlBeforeLayer = _FrameworkElementFromInspectable(before->_xamlElement);

        unsigned int srcIdx = 0;
        if (subLayerPanelForParentLayer->Children->IndexOf(xamlElementForThisLayer, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (subLayerPanelForParentLayer->Children->IndexOf(xamlBeforeLayer, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                subLayerPanelForParentLayer->Children->RemoveAt(srcIdx);
                subLayerPanelForParentLayer->Children->InsertAt(destIdx, xamlElementForThisLayer);
            } else {
                FAIL_FAST();
            }
        } else {
            FAIL_FAST();
        }
    } else {
        assert(after);

        FrameworkElement^ xamlAfterLayer = _FrameworkElementFromInspectable(after->_xamlElement);
        unsigned int srcIdx = 0;
        if (subLayerPanelForParentLayer->Children->IndexOf(xamlElementForThisLayer, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (subLayerPanelForParentLayer->Children->IndexOf(xamlAfterLayer, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                subLayerPanelForParentLayer->Children->RemoveAt(srcIdx);
                subLayerPanelForParentLayer->Children->InsertAt(destIdx + 1, xamlElementForThisLayer);
            } else {
                FAIL_FAST();
            }
        } else {
            FAIL_FAST();
        }
    }
}

void LayerProxy::RemoveFromSuperLayer() {
    // Grab a strong reference to our parent (if one exists)
    auto strongParent = _parent.lock();

    FrameworkElement^ xamlElementForThisLayer = _FrameworkElementFromInspectable(_xamlElement);
    Panel^ subLayerPanelForParentLayer;
    if (_isRoot) {
        subLayerPanelForParentLayer = s_windowCollection;
    } else {
        if (!strongParent) {
            if (DEBUG_HIERARCHY) {
                TraceVerbose(
                    TAG, 
                    L"RemoveFromSuperLayer for [%ws] doesn't have a parent; nothing left to do.", 
                    xamlElementForThisLayer->GetType()->FullName->Data());
            }

            return;
        }

        subLayerPanelForParentLayer = _SubLayerPanelFromInspectable(strongParent->_xamlElement);
        strongParent->_subLayers.erase(shared_from_this());
    }

    if (DEBUG_HIERARCHY) {
        TraceVerbose(
            TAG,
            L"RemoveFromSuperLayer xamlElementForThisLayer = [%ws]; subLayerPanelForParentLayer = [%ws].",
            xamlElementForThisLayer->GetType()->FullName->Data(),
            subLayerPanelForParentLayer->GetType()->FullName->Data());
    }

    if (!subLayerPanelForParentLayer) {
        FrameworkElement^ xamlElementForParentLayer = _FrameworkElementFromInspectable(strongParent->_xamlElement);
        UNIMPLEMENTED_WITH_MSG(
            "RemoveFromSuperLayer for [%ws] not supported on parent [%ws].",
            xamlElementForThisLayer->GetType()->FullName->Data(),
            xamlElementForParentLayer->GetType()->FullName->Data());

        return;
    }

    unsigned int idx = 0;
    if (subLayerPanelForParentLayer->Children->IndexOf(xamlElementForThisLayer, &idx) == true) {
        subLayerPanelForParentLayer->Children->RemoveAt(idx);
    } else {
        FAIL_FAST();
    }

    _parent.reset();
}
