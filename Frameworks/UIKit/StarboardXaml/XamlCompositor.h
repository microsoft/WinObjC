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

#include "StarboardXaml.h"

#include "CACompositor.h"

#include <deque>
#include <map>
#include <ppltasks.h>
#include <set>

namespace XamlCompositor {

#if !defined(__OBJC__)
// clang-format does not like C++/CX
// clang-format off

void Initialize(Windows::UI::Xaml::Controls::Grid^ rootGrid, ActivationType activationType);

// clang-format on
#endif // !defined(__OBJC__)

Microsoft::WRL::ComPtr<IInspectable> GetRootElement();

namespace Internal {

typedef enum {
    CompositionModeDefault = 0,
    CompositionModeLibrary = 1,
} CompositionMode;

// XamlCompsitor.mm
void CreateXamlCompositor(CompositionMode compositionMode);
void RootGridSizeChanged(float newWidth, float newHeight);
void SetScreenParameters(float width, float height, float scale, float rotation);

// XamlCompsitor.cpp
// TODO: Move to a displaylink helper API?
void EnableRenderingListener(void (*callback)());
void DisableRenderingListener();

struct ICompositorTransaction {
public:
    virtual ~ICompositorTransaction() {
    }
    virtual void Process() = 0;
};

struct ICompositorAnimationTransaction {
public:
    virtual ~ICompositorAnimationTransaction() {
    }
    virtual concurrency::task<void> Process() = 0;
};

// Dispatches the compositor transactions that have been queued up
void DispatchCompositorTransactions(
    std::deque<std::shared_ptr<ICompositorTransaction>>&& subTransactions,
    std::deque<std::shared_ptr<ICompositorAnimationTransaction>>&& animationTransactions,
    std::map<std::shared_ptr<ILayerProxy>, std::map<std::string, std::shared_ptr<ICompositorTransaction>>>&& propertyTransactions,
    std::deque<std::shared_ptr<ICompositorTransaction>>&& movementTransactions);

} /* namespace Internal*/
} /* namespace XamlCompositor */