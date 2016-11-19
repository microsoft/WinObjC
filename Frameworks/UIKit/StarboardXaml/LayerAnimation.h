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

#include <deque>
#include <map>
#include <memory>
#include <ppltasks.h>

class LayerAnimation : public ILayerAnimation, public std::enable_shared_from_this<LayerAnimation> {
public:
#if defined(__OBJC__)
    static std::shared_ptr<ILayerAnimation> CreateBasicAnimation(CAAnimation* animation,
                                                                 NSString* propertyName,
                                                                 NSObject* fromValue,
                                                                 NSObject* toValue,
                                                                 NSObject* byValue,
                                                                 CAMediaTimingProperties* timingProperties);

    static std::shared_ptr<ILayerAnimation> CreateTransitionAnimation(CAAnimation* animation, NSString* type, NSString* subType);
#endif

    void Stop();
    virtual concurrency::task<void> AddToLayer(ILayerProxy& layer) = 0;

protected:
    LayerAnimation();
    virtual ~LayerAnimation(){};

    void _CreateXamlAnimation();
    void _Start();
    virtual void _Completed() = 0;

    concurrency::task<void> _AddAnimation(ILayerProxy& layer, const char* propertyName, bool fromValid, float from, bool toValid, float to);
    concurrency::task<void> _AddTransitionAnimation(ILayerProxy& layer, const char* type, const char* subtype);

    Microsoft::WRL::ComPtr<IInspectable> _storyboardManager;
    enum Easing { EaseInEaseOut, EaseIn, EaseOut, Linear, Default };

    double beginTime;
    double duration;
    bool autoReverse;
    float repeatCount;
    float repeatDuration;
    float speed;
    double timeOffset;
    Easing easingFunction;
};