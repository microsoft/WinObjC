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
#include "XamlCompositor.h"

#include <deque>
#include <map>
#include <memory>

#import "QuartzCore\CAAnimation.h"
#import "QuartzCore\CALayer.h"

class QueuedProperty;
class QueuedMovement;
class QueuedAnimation;

using ICompositorTransaction = XamlCompositor::Internal::ICompositorTransaction;
using ICompositorAnimationTransaction = XamlCompositor::Internal::ICompositorAnimationTransaction;

class LayerTransaction : public ILayerTransaction, public ICompositorTransaction {
public:
    // ILayerTransaction sublayer management
    void AddLayer(const std::shared_ptr<ILayerProxy>& layer,
                  const std::shared_ptr<ILayerProxy>& superLayer,
                  const std::shared_ptr<ILayerProxy>& beforeLayer,
                  const std::shared_ptr<ILayerProxy>& afterLayer) override;
    void MoveLayer(const std::shared_ptr<ILayerProxy>& layer,
                   const std::shared_ptr<ILayerProxy>& beforeLayer,
                   const std::shared_ptr<ILayerProxy>& afterLayer) override;
    void RemoveLayer(const std::shared_ptr<ILayerProxy>& layer) override;

    // ILayerTransaction property management
    void SetLayerProperty(const std::shared_ptr<ILayerProxy>& layer, const char* propertyName, NSObject* newValue) override;

    // ILayerTransaction display management
    void SetLayerTexture(const std::shared_ptr<ILayerProxy>& layer,
                         const std::shared_ptr<IDisplayTexture>& newTexture,
                         CGSize contentsSize,
                         float contentsScale) override;

    // ILayerTransaction animation management
    void AddAnimation(CALayer* layer, CAAnimation* animation, NSString* forKey) override;
    void RemoveAnimation(const std::shared_ptr<ILayerAnimation>& animation) override;

    // LayerTransaction subtransaction management
    void QueueTransaction(const std::shared_ptr<ILayerTransaction>& transaction);

    // ICompositorTransaction
    void Process() override;

private:
    void _QueueProperty(const std::shared_ptr<QueuedProperty> property);
    void _QueueMovement(const std::shared_ptr<QueuedMovement>& movement);
    void _QueueAnimation(const std::shared_ptr<QueuedAnimation>& animation);

    std::deque<std::shared_ptr<ICompositorTransaction>> _queuedTransactions;
    std::deque<std::shared_ptr<ICompositorAnimationTransaction>> _queuedAnimations;
    std::map<std::shared_ptr<ILayerProxy>, std::map<std::string, std::shared_ptr<ICompositorTransaction>>> _queuedProperties;
    std::deque<std::shared_ptr<ICompositorTransaction>> _queuedMovements;
};