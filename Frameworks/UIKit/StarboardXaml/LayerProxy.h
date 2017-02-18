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
#pragma once

#include "CACompositor.h"

#include <memory>
#include <set>

struct LayerColor {
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;
    float a = 0.0;
};

// A LayerProxy is CALayer's proxy to its backing Xaml FrameworkElement.
// LayerProxy is used to update the Xaml FrameworkElement's visual state (positioning, animations, etc.) based upon CALayer API calls,
// and it's also responsible for the CALayer's sublayer management (*if* that backing Xaml FrameworkElement supports sublayers).
// When constructed, the LayerProxy inspects the passed-in Xaml FrameworkElement, and lights up all CALayer functionality that's
// supported by the given FrameworkElement.
class LayerProxy : public ILayerProxy, public std::enable_shared_from_this<LayerProxy> {
public:
    explicit LayerProxy(IInspectable* xamlElement);

    // ILayerProxy
    Microsoft::WRL::ComPtr<IInspectable> GetXamlElement() override;
    Microsoft::WRL::ComPtr<IInspectable> GetSublayerXamlElement() override;
    void* GetPropertyValue(const char* propertyName) override;
    void SetShouldRasterize(bool shouldRasterize) override;
    void SetTopMost() override; // TODO: Can we remove this altogether at some point?

    // General property management
    void SetTexture(const std::shared_ptr<IDisplayTexture>& texture, float width, float height, float scale);
    void UpdateProperty(const char* name, void* value);

    // Sublayer management
    void AddToRoot();
    void AddSubLayer(const std::shared_ptr<LayerProxy>& subLayer,
                     const std::shared_ptr<LayerProxy>& before,
                     const std::shared_ptr<LayerProxy>& after);
    void MoveLayer(const std::shared_ptr<LayerProxy>& before, const std::shared_ptr<LayerProxy>& after);
    void RemoveFromSuperLayer();

private:
    // Display properties
    void _SetProperty(const char* name, float value);
    void _SetPropertyInt(const char* name, int value);
    void _SetHidden(bool hidden);
    void _SetMasksToBounds(bool masksToBounds);
    void _SetBackgroundColor(const LayerColor& color);
    void _SetBorderColor(const LayerColor& color);
    LayerColor _GetBorderColor();
    void _SetBorderWidth(float width);
    float _GetBorderWidth();
    void _SetContents(const Microsoft::WRL::ComPtr<IInspectable>& bitmap, float width, float height, float scale);
    void _SetContentsCenter(float x, float y, float width, float height);

    // TODO: We should remove this and just do it on UIWindow's backing element since that's the only place it's used
    void _SetZIndex(int zIndex);

    // Property management
    float _GetPresentationPropertyValue(const char* name);

    bool _isRoot;
    std::weak_ptr<LayerProxy> _parent;
    std::set<std::shared_ptr<LayerProxy>> _subLayers;
    std::shared_ptr<IDisplayTexture> _currentTexture;
    bool _topMost;

private:
    // The Xaml element that backs this LayerProxy
    Microsoft::WRL::ComPtr<IInspectable> _xamlElement;
};