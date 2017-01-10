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
#import "LayerAnimation.h"

#import <UIKit/NSValue+UIKitAdditions.h>
#import <UIKit/UIApplication.h>

#import <QuartzCore/CoreAnimationFunctions.h>

#import "CAAnimationInternal.h"
#import "Quaternion.h"

static const wchar_t* TAG = L"LayerAnimation";

namespace {

class TransitionAnimation : public LayerAnimation {
public:
    id _animHandler;
    NSString *_type, *_subType;

    TransitionAnimation(id animHandler, NSString* type, NSString* subType) {
        _animHandler = [animHandler retain];

        _type = [type retain];
        _subType = [subType retain];
        beginTime = 0;
        duration = 1.0f;
        autoReverse = false;
        repeatCount = 0;
        repeatDuration = 0;
        speed = 1.5;
        timeOffset = 0;
    }

    ~TransitionAnimation() {
        [_animHandler release];
        [_type release];
        [_subType release];
    }

    concurrency::task<void> AddToLayer(ILayerProxy& layer) {
        // We don't currently support transition animations when in synchronous transaction mode,
        // so call the completion handler and return immediately.
        if (!UIApplication.displayMode.useLegacyBatchedCATransactions) {
            _Completed();
            return concurrency::task_from_result();
        }

        _CreateXamlAnimation();
        return _AddTransitionAnimation(layer, [_type UTF8String], [_subType UTF8String]);
    }

    void _Completed() {
        id animHandler = _animHandler; // Save in a local for the block to retain.
        dispatch_async(dispatch_get_main_queue(), ^{
            [animHandler animationDidStop:TRUE];
            [animHandler _removeAnimationsFromLayer];
        });
    }
};

class BasicAnimation : public LayerAnimation {
private:
    void _AdjustFloatValuesForKeyPath(NSString* curKeyPath) {
        if (_fromValue != nil) {
            if (_toValue != nil) {
                // Interpolate between _fromValue and _toValue.
                return;
            } else if (_byValue != nil) {
                // Interpolate between _fromValue and (_fromValue + _byValue)
                float fromValue = [static_cast<NSNumber*>(_fromValue) floatValue];
                float byValue = [static_cast<NSNumber*>(_byValue) floatValue];
                _toValue = [[NSNumber numberWithFloat:(fromValue + byValue)] retain];
            } else {
                FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
            }
        } else if (_toValue != nil) {
            if (_byValue != nil) {
                // Interpolate between (_toValue - _byValue) and _toValue
                float toValue = [static_cast<NSNumber*>(_toValue) floatValue];
                float byValue = [static_cast<NSNumber*>(_byValue) floatValue];
                _fromValue = [[NSNumber numberWithFloat:(toValue - byValue)] retain];
            } else {
                FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
            }
        } else if (_byValue != nil) {
            FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
        } else {
            UNIMPLEMENTED_WITH_MSG("Unsupported when all CABasicAnimation properties are nil");
        }
    }

    void _AdjustCGSizeValuesForKeyPath(NSString* curKeyPath) {
        if (_fromValue != nil && _toValue != nil) {
            return;
        }

        bool fromValid = _fromValue != nil;
        bool toValid = _toValue != nil;
        bool byValid = _byValue != nil;

        CGSize fromSize;
        CGSize toSize;
        CGSize bySize;

        if (fromValid) {
            [static_cast<NSValue*>(_fromValue) getValue:&fromSize];
            [_fromValue release];
            _fromValue = [[NSNumber numberWithFloat:fromSize.width] retain];
        }

        if (toValid) {
            [static_cast<NSValue*>(_toValue) getValue:&toSize];
            [_toValue release];
            _toValue = [[NSNumber numberWithFloat:toSize.width] retain];
        }

        if (byValid) {
            [static_cast<NSValue*>(_byValue) getValue:&bySize];
            [_byValue release];
            _byValue = [NSNumber numberWithFloat:bySize.width];
        }

        NSString* newKeyPath = [curKeyPath stringByAppendingString:@".width"];
        _AdjustFloatValuesForKeyPath(newKeyPath);
        fromSize.width = [static_cast<NSNumber*>(_fromValue) floatValue];
        toSize.width = [static_cast<NSNumber*>(_toValue) floatValue];
        [_fromValue release];
        [_toValue release];

        if (fromValid) {
            _fromValue = [[NSNumber numberWithFloat:fromSize.height] retain];
        } else {
            _fromValue = nil;
        }

        if (toValid) {
            _toValue = [[NSNumber numberWithFloat:toSize.height] retain];
        } else {
            _toValue = nil;
        }

        if (byValid) {
            _byValue = [NSNumber numberWithFloat:bySize.height];
        } else {
            _byValue = nil;
        }

        newKeyPath = [curKeyPath stringByAppendingString:@".height"];
        _AdjustFloatValuesForKeyPath(newKeyPath);
        fromSize.height = [static_cast<NSNumber*>(_fromValue) floatValue];
        toSize.height = [static_cast<NSNumber*>(_toValue) floatValue];
        [_fromValue release];
        [_toValue release];

        _fromValue = [[NSValue valueWithCGSize:fromSize] retain];
        _toValue = [[NSValue valueWithCGSize:toSize] retain];
        _byValue = nil;
    }

    void _AdjustCGPointValuesForKeyPath(NSString* curKeyPath) {
        if (_fromValue != nil && _toValue != nil) {
            return;
        }

        bool fromValid = _fromValue != nil;
        bool toValid = _toValue != nil;
        bool byValid = _byValue != nil;

        CGPoint fromPoint;
        CGPoint toPoint;
        CGPoint byPoint;

        if (fromValid) {
            [static_cast<NSValue*>(_fromValue) getValue:&fromPoint];
            [_fromValue release];
            _fromValue = [[NSNumber numberWithFloat:fromPoint.x] retain];
        }

        if (toValid) {
            [static_cast<NSValue*>(_toValue) getValue:&toPoint];
            [_toValue release];
            _toValue = [[NSNumber numberWithFloat:toPoint.x] retain];
        }

        if (byValid) {
            [static_cast<NSValue*>(_byValue) getValue:&byPoint];
            [_byValue release];
            _byValue = [NSNumber numberWithFloat:byPoint.x];
        }

        NSString* newKeyPath = [curKeyPath stringByAppendingString:@".x"];
        _AdjustFloatValuesForKeyPath(newKeyPath);
        fromPoint.x = [static_cast<NSNumber*>(_fromValue) floatValue];
        toPoint.x = [static_cast<NSNumber*>(_toValue) floatValue];
        [_fromValue release];
        [_toValue release];

        if (fromValid) {
            _fromValue = [[NSNumber numberWithFloat:fromPoint.y] retain];
        } else {
            _fromValue = nil;
        }

        if (toValid) {
            _toValue = [[NSNumber numberWithFloat:toPoint.y] retain];
        } else {
            _toValue = nil;
        }

        if (byValid) {
            _byValue = [NSNumber numberWithFloat:byPoint.y];
        } else {
            _byValue = nil;
        }

        newKeyPath = [curKeyPath stringByAppendingString:@".y"];
        _AdjustFloatValuesForKeyPath(newKeyPath);
        fromPoint.y = [static_cast<NSNumber*>(_fromValue) floatValue];
        toPoint.y = [static_cast<NSNumber*>(_toValue) floatValue];
        [_fromValue release];
        [_toValue release];

        _fromValue = [[NSValue valueWithCGPoint:fromPoint] retain];
        _toValue = [[NSValue valueWithCGPoint:toPoint] retain];
        _byValue = nil;
    }

    void _AdjustCGRectValuesForKeyPath(NSString* curKeyPath) {
        if (_fromValue != nil && _toValue != nil) {
            return;
        }

        bool fromValid = _fromValue != nil;
        bool toValid = _toValue != nil;
        bool byValid = _byValue != nil;

        CGRect fromRect;
        CGRect toRect;
        CGRect byRect;

        if (fromValid) {
            [static_cast<NSValue*>(_fromValue) getValue:&fromRect];
            [_fromValue release];
            _fromValue = [[NSValue valueWithCGPoint:fromRect.origin] retain];
        }

        if (toValid) {
            [static_cast<NSValue*>(_toValue) getValue:&toRect];
            [_toValue release];
            _toValue = [[NSValue valueWithCGPoint:toRect.origin] retain];
        }

        if (byValid) {
            [static_cast<NSValue*>(_byValue) getValue:&byRect];
            [_byValue release];

            // _byValue is will be released by _AdjustCGPointValuesForKeyPath
            _byValue = [[NSValue valueWithCGPoint:byRect.origin] retain];
        }

        NSString* newKeyPath = [curKeyPath stringByAppendingString:@".origin"];
        _AdjustCGPointValuesForKeyPath(newKeyPath);
        [static_cast<NSValue*>(_fromValue) getValue:&(fromRect.origin)];
        [static_cast<NSValue*>(_toValue) getValue:&(toRect.origin)];
        [_fromValue release];
        [_toValue release];

        if (fromValid) {
            _fromValue = [[NSValue valueWithCGSize:fromRect.size] retain];
        } else {
            _fromValue = nil;
        }

        if (toValid) {
            _toValue = [[NSValue valueWithCGSize:toRect.size] retain];
        } else {
            _toValue = nil;
        }

        if (byValid) {
            // _byValue is will be released by _AdjustCGSizeValuesForKeyPath
            _byValue = [[NSValue valueWithCGSize:byRect.size] retain];
        } else {
            _byValue = nil;
        }

        newKeyPath = [curKeyPath stringByAppendingString:@".size"];
        _AdjustCGSizeValuesForKeyPath(newKeyPath);
        [static_cast<NSValue*>(_fromValue) getValue:&(fromRect.size)];
        [static_cast<NSValue*>(_toValue) getValue:&(toRect.size)];
        [_fromValue release];
        [_toValue release];

        _fromValue = [[NSValue valueWithCGRect:fromRect] retain];
        _toValue = [[NSValue valueWithCGRect:toRect] retain];
        _byValue = nil;
    }

    bool _AdjustCATransform3DValues(
        float* translationFrom, float* scaleFrom, float* angleFrom, float* translationTo, float* scaleTo, float* angleTo) {
        const int dimensions = 3;
        float translationBy[dimensions] = { 0 };
        float scaleBy[dimensions] = { 1.0f, 1.0f, 1.0f };
        float angleBy = 0.0f;
        Quaternion qval;
        CATransform3D fromValue = [static_cast<NSValue*>(_fromValue) CATransform3DValue];
        CATransform3D toValue = [static_cast<NSValue*>(_toValue) CATransform3DValue];
        CATransform3D byValue = [static_cast<NSValue*>(_byValue) CATransform3DValue];
        float (^add)(float, float) = ^(float a, float b) {
            return (a + b);
        };
        float (^subtract)(float, float) = ^(float a, float b) {
            return (a - b);
        };
        float (^multiply)(float, float) = ^(float a, float b) {
            return a * b;
        };
        float (^divide)(float, float) = ^(float a, float b) {
            if (b == 0.0f) {
                return 0.0f;
            }
            return a / b;
        };
        void (^performOperation)(float*, float*, float*, int, float (^)(float, float)) =
            ^(float* array1, float* array2, float* resultArray, int size, float (^operation)(float, float)) {
                for (int i = 0; i < size; i++) {
                    resultArray[i] = operation(array1[i], array2[i]);
                }
            };

        bool isValid = true;
        if (_fromValue != nil) {
            qval.CreateFromMatrix(reinterpret_cast<float*>(&fromValue));
            *angleFrom = (float)-qval.roll() * 180.0f / M_PI;
            CATransform3DGetScale(fromValue, scaleFrom);
            CATransform3DGetPosition(fromValue, translationFrom);
            if (_toValue != nil) {
                // Interpolate between _fromValue and _toValue.
                qval.CreateFromMatrix(reinterpret_cast<float*>(&toValue));
                *angleTo = (float)-qval.roll() * 180.0f / M_PI;
                CATransform3DGetScale(toValue, scaleTo);
                CATransform3DGetPosition(toValue, translationTo);
            } else if (_byValue != nil) {
                // Interpolate between _fromValue and (_fromValue + _byValue)
                qval.CreateFromMatrix(reinterpret_cast<float*>(&byValue));
                angleBy = (float)-qval.roll() * 180.0f / M_PI;
                CATransform3DGetScale(byValue, scaleBy);
                CATransform3DGetPosition(byValue, translationBy);
                *angleTo = *angleFrom + angleBy;
                performOperation(scaleFrom, scaleBy, scaleTo, dimensions, multiply);
                performOperation(translationFrom, translationBy, translationTo, dimensions, add);
            } else {
                // Guaranteed to be taken care of by _createAnimation in CABasicAnimation.
                FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
                isValid = false;
            }
        } else if (_toValue != nil) {
            qval.CreateFromMatrix(reinterpret_cast<float*>(&toValue));
            *angleTo = (float)-qval.roll() * 180.0f / M_PI;
            CATransform3DGetScale(toValue, scaleTo);
            CATransform3DGetPosition(toValue, translationTo);
            if (_byValue != nil) {
                // Interpolate between (_toValue - _byValue) and _toValue
                qval.CreateFromMatrix(reinterpret_cast<float*>(&byValue));
                angleBy = (float)-qval.roll() * 180.0f / M_PI;
                CATransform3DGetScale(byValue, scaleBy);
                CATransform3DGetPosition(byValue, translationBy);

                *angleFrom = *angleTo - angleBy;
                performOperation(scaleTo, scaleBy, scaleFrom, dimensions, divide);
                performOperation(translationTo, translationBy, translationFrom, dimensions, subtract);
            } else {
                FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
                isValid = false;
            }
        } else if (_byValue != nil) {
            FAIL_FAST_MSG("Guaranteed to be taken care of by _createAnimation in CABasicAnimation.");
            isValid = false;
        } else {
            UNIMPLEMENTED_WITH_MSG("Unsupported when all interpolation values are nil");
            isValid = false;
        }
        return isValid;
    }

public:
    NSString* _propertyName;
    NSObject* _fromValue;
    NSObject* _toValue;
    NSObject* _byValue;
    id _animHandler;

    void _Completed() {
        id animHandler = _animHandler; // Save in a local for the block to retain.
        dispatch_async(dispatch_get_main_queue(), ^{
            [animHandler animationDidStop:TRUE];
            [animHandler _removeAnimationsFromLayer];
        });
    }

    BasicAnimation(id animHandler,
                   NSString* propertyName,
                   NSObject* fromValue,
                   NSObject* toValue,
                   NSObject* byValue,
                   CAMediaTimingProperties* timingProperties) {
        CAMediaTimingFunction* mediaTiming = timingProperties->_timingFunction;
        float p1[2] = { 0 }, p2[2] = { 0 };
        [mediaTiming getControlPointAtIndex:0 values:p1];
        [mediaTiming getControlPointAtIndex:1 values:p2];

        if (p1[0] == 0.0f && p1[1] == 0.0f && p2[0] == 1.0f && p2[1] == 1.0f) {
            easingFunction = Linear;
        } else if (p1[0] == 0.5f && p1[1] == 0.0f && p2[0] == 1.0f && p2[1] == 1.0f) {
            easingFunction = EaseIn;
        } else if (p1[0] == 0.0f && p1[1] == 0.0f && p2[0] == 0.5f && p2[1] == 1.0f) {
            easingFunction = EaseOut;
        } else if (p1[0] == 0.5f && p1[1] == 0.0f && p2[0] == 0.5f && p2[1] == 1.0f) {
            easingFunction = EaseInEaseOut;
        } else if (p1[0] == 0.5f && p1[1] == 0.0f && p2[0] == 1.0f && p2[1] == 1.0f) {
            easingFunction = Default;
        }

        _animHandler = [animHandler retain];
        _propertyName = [propertyName retain];
        _fromValue = [fromValue retain];
        _toValue = [toValue retain];
        _byValue = [byValue retain];

        beginTime = timingProperties->_beginTime - CACurrentMediaTime();
        duration = timingProperties->_duration;
        autoReverse = (bool)timingProperties->_autoReverses;
        repeatCount = timingProperties->_repeatCount;
        repeatDuration = timingProperties->_repeatDuration;
        speed = timingProperties->_speed;
        timeOffset = timingProperties->_timeOffset;

        if (repeatCount > 0xFFFFFF) {
            repeatCount = 0xFFFFFF;
        }

        if (repeatDuration > 0xFFFFFF) {
            repeatDuration = 0xFFFFFF;
        }
    }

    ~BasicAnimation() {
        [_animHandler release];
        [_propertyName release];
        [_fromValue release];
        [_toValue release];
        [_byValue release];
    }

    concurrency::task<void> AddToLayer(ILayerProxy& layer) {
        _CreateXamlAnimation();

        const char* propName = [_propertyName UTF8String];
        if (strcmp(propName, "transform.scale") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            _AddAnimation(layer, "transform.scale.x", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _AddAnimation(layer, "transform.scale.y", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "transform.rotation.z") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            fromValue = fromValue * 180.0f / M_PI;
            toValue = toValue * 180.0f / M_PI;

            _AddAnimation(layer, "transform.rotation", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "transform.translation.x") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            _AddAnimation(layer, "transform.translation.x", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "transform.translation.y") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            _AddAnimation(layer, "transform.translation.y", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "position") == 0) {
            _AdjustCGPointValuesForKeyPath(_propertyName);
            CGPoint fromValue = [(NSValue*)_fromValue CGPointValue];
            CGPoint toValue = [(NSValue*)_toValue CGPointValue];

            _AddAnimation(layer, "position.x", _fromValue != nil, fromValue.x, _toValue != nil, toValue.x);
            _AddAnimation(layer, "position.y", _fromValue != nil, fromValue.y, _toValue != nil, toValue.y);
            _Start();
        } else if (strcmp(propName, "bounds") == 0) {
            _AdjustCGRectValuesForKeyPath(_propertyName);
            CGRect fromValue = [(NSValue*)_fromValue CGRectValue];
            CGRect toValue = [(NSValue*)_toValue CGRectValue];

            _AddAnimation(layer, "origin.x", _fromValue != nil, fromValue.origin.x, _toValue != nil, toValue.origin.x);
            _AddAnimation(layer, "origin.y", _fromValue != nil, fromValue.origin.y, _toValue != nil, toValue.origin.y);
            _AddAnimation(layer, "size.width", _fromValue != nil, fromValue.size.width, _toValue != nil, toValue.size.width);
            _AddAnimation(layer, "size.height", _fromValue != nil, fromValue.size.height, _toValue != nil, toValue.size.height);
            _Start();
        } else if (strcmp(propName, "opacity") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];
            _AddAnimation(layer, "opacity", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "transform") == 0) {
            CATransform3D fromValue = [(NSValue*)_fromValue CATransform3DValue];
            CATransform3D toValue = [(NSValue*)_toValue CATransform3DValue];

            float translationFrom[3] = { 0 };
            float scaleFrom[3] = { 1.0f, 1.0f, 1.0f };
            float angleFrom = 0.0f;
            float translationTo[3] = { 0 };
            float scaleTo[3] = { 1.0f, 1.0f, 1.0f };
            float angleTo = 0.0f;

            bool isValid = _AdjustCATransform3DValues(translationFrom, scaleFrom, &angleFrom, translationTo, scaleTo, &angleTo);

            if (scaleFrom[0] != 1.0f || scaleFrom[1] != 1.0f || scaleTo[0] != 1.0f || scaleTo[1] != 1.0f) {
                _AddAnimation(layer, "transform.scale.x", isValid, scaleFrom[0], isValid, scaleTo[0]);
                _AddAnimation(layer, "transform.scale.y", isValid, scaleFrom[1], isValid, scaleTo[1]);
            }
            if (translationFrom[0] != 0.0f || translationFrom[1] != 0.0f || translationTo[0] != 0.0f || translationTo[1] != 0.0f) {
                _AddAnimation(layer, "transform.translation.x", isValid, translationFrom[0], isValid, translationTo[0]);
                _AddAnimation(layer, "transform.translation.y", isValid, translationFrom[1], isValid, translationTo[1]);
            }
            if (angleFrom != 0.0f || angleTo != 0.0f) {
                _AddAnimation(layer, "transform.rotation", isValid, angleFrom, isValid, angleTo);
            }
            _Start();
        } else if (strcmp(propName, "transform.translation.y") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            _AddAnimation(layer, "transform.translation.y", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else if (strcmp(propName, "transform.translation.x") == 0) {
            _AdjustFloatValuesForKeyPath(_propertyName);
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            _AddAnimation(layer, "transform.translation.x", _fromValue != nil, fromValue, _toValue != nil, toValue);
            _Start();
        } else {
            UNIMPLEMENTED_WITH_MSG("Stubbed function called! Unsupported property name: %hs", propName);
        }

        // No specialized task needed for basic animations
        return concurrency::task_from_result();
    }
};
}

std::shared_ptr<ILayerAnimation> LayerAnimation::CreateBasicAnimation(CAAnimation* animation,
                                                                      NSString* propertyName,
                                                                      NSObject* fromValue,
                                                                      NSObject* toValue,
                                                                      NSObject* byValue,
                                                                      CAMediaTimingProperties* timingProperties) {
    return std::make_shared<BasicAnimation>(animation, propertyName, fromValue, toValue, byValue, timingProperties);
}

std::shared_ptr<ILayerAnimation> LayerAnimation::CreateTransitionAnimation(CAAnimation* animation, NSString* type, NSString* subType) {
    return std::make_shared<TransitionAnimation>(animation, type, subType);
}