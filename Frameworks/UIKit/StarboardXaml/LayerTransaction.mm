//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import "Starboard.h"
#import "LayerTransaction.h"

#import "LayerAnimation.h"
#import "LayerProxy.h"

#import "CAAnimationInternal.h"
#import "CALayerInternal.h"

#import <UIKit/UIApplication.h>

#include <string>

static const wchar_t* TAG = L"LayerTransaction";

using namespace XamlCompositor::Internal;

class QueuedAnimation : public ICompositorAnimationTransaction {
public:
    CALayer* _layer = nil;
    CAAnimation* _animation = nil;
    NSString* _key = nil;
    std::shared_ptr<ILayerAnimation> _abortAnimation;

    QueuedAnimation(CALayer* layer, CAAnimation* anim, NSString* key) {
        _layer = [layer retain];
        _animation = [anim retain];
        _key = [key retain];
    }

    QueuedAnimation(const std::shared_ptr<ILayerAnimation>& animToAbort) {
        _abortAnimation = animToAbort;
    }

    ~QueuedAnimation() {
        [_layer release];
        [_animation release];
        [_key release];
    }

    concurrency::task<void> Process() override {
        if (_abortAnimation) {
            std::dynamic_pointer_cast<LayerAnimation>(_abortAnimation)->Stop();
        } else {
            // If the animation is still valid, create and start it.
            if (![_animation wasRemoved]) {
                std::shared_ptr<ILayerAnimation> newAnimation = [_animation _createAnimation:_layer forKey:_key];

                /////////////////////////////////////////////////////
                // TODO: Call in _createAnimation impls on success?
                [_animation animationDidStart];
                [_animation animationHasStarted];

                if (newAnimation) {
                    std::shared_ptr<ILayerProxy> layer = [_layer _layerProxy];
                    return std::dynamic_pointer_cast<LayerAnimation>(newAnimation)->AddToLayer(*layer);
                } else {
                    /////////////////////////////////////////////////////
                    // TODO: Call in _createAnimation impls on failure?
                    [_animation animationDidStop:FALSE];
                }
            }
        }

        return concurrency::task_from_result();
    }
};

class QueuedProperty : public ICompositorTransaction {
public:
    std::shared_ptr<LayerProxy> _layer;
    std::string _propertyName;
    NSObject* _propertyValue;
    std::shared_ptr<IDisplayTexture> _newTexture;
    CGSize _contentsSize;
    float _contentsScale;
    bool _applyingTexture;

    QueuedProperty(const std::shared_ptr<ILayerProxy>& layer,
                   const std::shared_ptr<IDisplayTexture>& newTexture,
                   CGSize contentsSize,
                   float contentsScale) {
        _layer = std::dynamic_pointer_cast<LayerProxy>(layer);
        _propertyName.assign("contents");
        _propertyValue = NULL;
        _newTexture = newTexture;
        _contentsScale = contentsScale;
        _contentsSize = contentsSize;
        _applyingTexture = true;
    }

    QueuedProperty(const std::shared_ptr<ILayerProxy>& layer, const char* propertyName, NSObject* propertyValue) {
        _layer = std::dynamic_pointer_cast<LayerProxy>(layer);
        _propertyName.assign(propertyName);
        _propertyValue = [propertyValue retain];
        _newTexture = NULL;
        _applyingTexture = false;
    }

    ~QueuedProperty() {
        [_propertyValue release];
        _propertyValue = nullptr;
    }

    void Process() override {
        if (_applyingTexture) {
            _layer->SetTexture(_newTexture, _contentsSize.width, _contentsSize.height, _contentsScale);
        } else {
            _layer->UpdateProperty(_propertyName.data(), _propertyValue);
        }
    }
};

class QueuedMovement : public ICompositorTransaction {
public:
    std::shared_ptr<LayerProxy> _layer;
    std::shared_ptr<LayerProxy> _before;
    std::shared_ptr<LayerProxy> _after;
    std::shared_ptr<LayerProxy> _superLayer;

    enum MovementType { Add, Move, Remove };

    MovementType _type;

    QueuedMovement(MovementType type,
                   const std::shared_ptr<ILayerProxy>& layer,
                   const std::shared_ptr<ILayerProxy>& before,
                   const std::shared_ptr<ILayerProxy>& after,
                   const std::shared_ptr<ILayerProxy>& superLayer) {
        _type = type;
        _layer = std::dynamic_pointer_cast<LayerProxy>(layer);
        _before = std::dynamic_pointer_cast<LayerProxy>(before);
        _after = std::dynamic_pointer_cast<LayerProxy>(after);
        _superLayer = std::dynamic_pointer_cast<LayerProxy>(superLayer);
    }

    void Process() override {
        switch (_type) {
            case Add:
                if (!_superLayer) {
                    _layer->AddToRoot();
                } else {
                    _superLayer->AddSubLayer(_layer, _before, _after);
                }
                break;

            case Move:
                _layer->MoveLayer(_before, _after);
                break;

            case Remove:
                _layer->RemoveFromSuperLayer();
                break;
        }
    }
};

void LayerTransaction::AddLayer(const std::shared_ptr<ILayerProxy>& layer,
                                const std::shared_ptr<ILayerProxy>& superLayer,
                                const std::shared_ptr<ILayerProxy>& beforeLayer,
                                const std::shared_ptr<ILayerProxy>& afterLayer) {
    _QueueMovement(std::make_shared<QueuedMovement>(QueuedMovement::Add, layer, beforeLayer, afterLayer, superLayer));
}

void LayerTransaction::MoveLayer(const std::shared_ptr<ILayerProxy>& layer,
                                 const std::shared_ptr<ILayerProxy>& beforeLayer,
                                 const std::shared_ptr<ILayerProxy>& afterLayer) {
    _QueueMovement(std::make_shared<QueuedMovement>(QueuedMovement::Move, layer, beforeLayer, afterLayer, nullptr));
}

void LayerTransaction::RemoveLayer(const std::shared_ptr<ILayerProxy>& layer) {
    _QueueMovement(std::make_shared<QueuedMovement>(QueuedMovement::Remove, layer, nullptr, nullptr, nullptr));
}

void LayerTransaction::SetLayerProperty(const std::shared_ptr<ILayerProxy>& layer, const char* propertyName, NSObject* newValue) {
    _QueueProperty(std::make_shared<QueuedProperty>(layer, propertyName, newValue));
}

void LayerTransaction::SetLayerTexture(const std::shared_ptr<ILayerProxy>& layer,
                                       const std::shared_ptr<IDisplayTexture>& newTexture,
                                       CGSize contentsSize,
                                       float contentsScale) {
    _QueueProperty(std::make_shared<QueuedProperty>(layer, newTexture, contentsSize, contentsScale));
}

void LayerTransaction::AddAnimation(CALayer* layer, CAAnimation* animation, NSString* forKey) {
    _QueueAnimation(std::make_shared<QueuedAnimation>(layer, animation, forKey));
}

void LayerTransaction::RemoveAnimation(const std::shared_ptr<ILayerAnimation>& animation) {
    _QueueAnimation(std::make_shared<QueuedAnimation>(animation));
}

void LayerTransaction::Process() {
    DispatchCompositorTransactions(std::move(_queuedTransactions),
                                   std::move(_queuedAnimations),
                                   std::move(_queuedProperties),
                                   std::move(_queuedMovements));
}

void LayerTransaction::_QueueProperty(const std::shared_ptr<QueuedProperty> property) {
    // If we're in synchronous mode, set the property immediately
    if (!UIApplication.displayMode.useLegacyBatchedCATransactions) {
        property->Process();
        return;
    }

    auto& currentUpdates = _queuedProperties[property->_layer];
    currentUpdates[property->_propertyName] = property;
}

void LayerTransaction::_QueueMovement(const std::shared_ptr<QueuedMovement>& layerMovement) {
    // If we're in synchronous mode, move the node immediately
    if (!UIApplication.displayMode.useLegacyBatchedCATransactions) {
        layerMovement->Process();
        return;
    }

    _queuedMovements.push_back(layerMovement);
}

void LayerTransaction::_QueueAnimation(const std::shared_ptr<QueuedAnimation>& animation) {
    // If we're in synchronous mode, kick off the animation immediately
    if (!UIApplication.displayMode.useLegacyBatchedCATransactions) {
        animation->Process();
        return;
    }

    _queuedAnimations.push_back(animation);
}

void LayerTransaction::QueueTransaction(const std::shared_ptr<ILayerTransaction>& transaction) {
    //  Move all of our existing queues into a new transaction
    if (!_queuedAnimations.empty() || !_queuedProperties.empty() || !_queuedMovements.empty()) {
        auto currentChanges = std::make_shared<LayerTransaction>();
        currentChanges->_queuedAnimations = std::move(_queuedAnimations);
        currentChanges->_queuedProperties = std::move(_queuedProperties);
        currentChanges->_queuedMovements = std::move(_queuedMovements);

        _queuedTransactions.push_back(std::dynamic_pointer_cast<ICompositorTransaction>(currentChanges));
    }

    _queuedTransactions.push_back(std::dynamic_pointer_cast<ICompositorTransaction>(transaction));
}