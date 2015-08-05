//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"

#include "NativeUI/NativeUI.h"
#include "Quaternion.h"
#include "Etc.h"

#include "CACompositor.h"

#define LOG_REFS(...)

ActiveAnimations _activeAnimations;
int g_numActiveAnimations, g_totalDisplayAnimations, g_totalCAAnimations;

float applyMediaTimingFunction(id function, float t);

ActiveAnimations::ActiveAnimations()
{
    _allAnimations = new DisplayAnimationRef();
    _numEventLists = 0;
    _maxEventLists = 64;
    _eventLists = (AnimationEvent **) malloc(_maxEventLists * sizeof(AnimationEvent *));
    EbrLockInit(&_listLock);
}

void ActiveAnimations::AddActiveAnimation(DisplayAnimation *anim)
{
    anim->AddRef();

    DisplayAnimationRef *animRef = new DisplayAnimationRef();
    animRef->_animation = anim;
    animRef->_appliedToNode = NULL;

    _allAnimations->addChildAfter(animRef, NULL);
    g_numActiveAnimations ++;
}

void ActiveAnimations::ApplyAnimations(double curTime)
{
    AnimationEvent *eventList = NULL;

    LLTREE_FOREACH(curanimationref, _allAnimations)
    {
        DisplayAnimation   *pAnim = curanimationref->_animation;
        DWORD               events = animationEventNone;
        
        if ( pAnim->_remove ) {
            _allAnimations->removeChild(curanimationref);
            delete curanimationref;
            pAnim->Release();
            g_numActiveAnimations --;
            continue;
        }

        if ( pAnim->_ownerNode ) {
            DisplayNode *animNode = pAnim->_ownerNode->_appliedToNode;
            animNode->AddRef();

            bool remove = true;
            if ( !pAnim->_abort ) {
                remove = pAnim->ApplyAnimation(animNode, curTime, &animNode->presentationProperties);
            } else {
                pAnim->_fireActivate = TRUE;
                pAnim->_fireStarted = TRUE;
                pAnim->_fireFinished = TRUE;
                pAnim->_remove = TRUE;
                remove = true;
            }

            if ( remove ) {
                DisplayTransaction::removeAnimationRaw(animNode, pAnim);
            }

            animNode->Release();
        } else {
            pAnim->_fireFinished = TRUE;
            pAnim->_remove = TRUE;
        }

        if ( pAnim->_fireActivate && !pAnim->_didFireActivate ) {
            events |= animationEventActivated;
            pAnim->_didFireActivate = TRUE;
        }
        if ( pAnim->_fireStarted && !pAnim->_didFireStarted ) {
            pAnim->_didFireStarted = TRUE;
            events |= animationEventStarted;
        }
        if ( pAnim->_fireFinished && !pAnim->_didFireFinished ) {
            pAnim->_didFireFinished = TRUE;
            events |= animationEventFinished;
        }

        if ( events != animationEventNone )
        {
            if ( eventList == NULL ) {
                eventList = new AnimationEvent();
            }
            AnimationEvent *newEvent = new AnimationEvent();
            newEvent->_events = events;
            newEvent->_animation = pAnim;
            pAnim->AddRef();

            eventList->addChildAfter(newEvent, NULL);
        }
    }

    if ( eventList != NULL ) {
        EbrLockEnter(_listLock);
        if ( _numEventLists + 1 >= _maxEventLists ) {
            _maxEventLists += 32;
            _eventLists = (AnimationEvent **) realloc(_eventLists, _maxEventLists * sizeof(AnimationEvent *));
        }
        _eventLists[_numEventLists ++] = eventList;
        EbrLockLeave(_listLock);
        GetCACompositor()->DisplayTreeChanged();
    }
}

void ActiveAnimations::ProcessAnimationEvents()
{
    for ( ;; ) {
        AnimationEvent *curList = NULL;
        EbrLockEnter(_listLock);
        if ( _numEventLists > 0 ) {
            curList = _eventLists[0];
            memcpy(&_eventLists[0], &_eventLists[1], sizeof(AnimationEvent *) * _numEventLists - 1);
            _numEventLists --;
        }
        EbrLockLeave(_listLock);

        if ( curList ) {
            LLTREE_FOREACH(curevent, curList)
            {
                id animObject = curevent->_animation->_animationObject;

                //  Fire events
                if ( curevent->_events & animationEventActivated ) {
                    [animObject animationDidStart];
                }
                if ( curevent->_events & animationEventStarted ) {
                    [animObject animationHasStarted];
                }

                if ( curevent->_events & animationEventFinished ) {
                    switch ( curevent->_animation->timingProperties._fillMode ) {
                        case fillModeForwards:
                        case fillModeBackwards:
                        case fillModeBoth:
                            curevent->_animation->PerformFill();
                            break;
                    }

                    [animObject animationDidStop:TRUE];

                    if ( curevent->_animation->timingProperties._removedOnCompletion && !curevent->_animation->_abort ) {
                        [animObject _removeAnimationsFromLayer];
                    }

                    curevent->_animation->_animationObject = nil;
                    [animObject release];
                }
                curevent->_animation->Release();
                delete curevent;
            }
            delete curList;
        } else break;
    }
}

DisplayAnimation::DisplayAnimation(id animationObject)
{
    LOG_REFS("DisplayAnimation created\n");
    refCount = 0;
    _hasStarted = FALSE;
    _hasStopped = FALSE;
    _didFireActivate = _didFireStarted = _didFireFinished = FALSE;
    _fireActivate = _fireStarted = _fireFinished = _remove = FALSE;
    _ownerNode = NULL;
    _animationObject = [animationObject retain];
    _abort = FALSE;

    EbrIncrement((volatile int *) &g_totalDisplayAnimations);
}

DisplayAnimation::~DisplayAnimation()
{
    [_animationObject release];
    _animationObject = nil;
    assert(_ownerNode == NULL);
    LOG_REFS("DisplayAnimation destroyed\n");
    EbrDecrement((volatile int *) &g_totalDisplayAnimations);
}

void DisplayAnimation::Release()
{
    if ( EbrDecrement((int *) &refCount) == 0 ) {
        delete this;
    }
}

void DisplayAnimation::AddRef()
{
    EbrIncrement((int *) &refCount);
}

void DisplayAnimation::PerformFill()
{
}

bool DisplayAnimation::ApplyAnimation(DisplayNode *pLayer, double curTime, CADisplayProperties *presentationProperties)
{
    if ( _hasStopped ) {
        ApplyLocalAnimation(pLayer, 1.0f, presentationProperties);
        return false;
    }

    if ( timingProperties._speed == 0.0f ) {
        assert(0);
    }

    if ( timingProperties._beginTime == 0.0f ) {
        timingProperties._beginTime = curTime;
    }

    curTime -= timingProperties._beginTime;
    curTime *= timingProperties._speed;
    curTime -= timingProperties._timeOffset;
    if ( curTime < 0.0f ) {
        return false;
    }

    if ( !_hasActivated ) {
        _hasActivated = TRUE;
        _fireActivate = TRUE;
        Activated(pLayer);
    }

    curTime -= timingProperties._delay;
    if ( curTime >= 0.0f ) {
        if ( !_hasStarted ) {
            _hasStarted = TRUE;
            _fireStarted = TRUE;
            Started(pLayer);
        }
    } else {
        curTime = 0.0f;
    }

    double keyFrameDuration = timingProperties._duration * (timingProperties._autoReverses ? 2.0f : 1.0f);
    double curFrame = curTime / keyFrameDuration;
    BOOL stop = FALSE;

    if ( timingProperties._repeatCount != 0.0f ) {
        if ( curFrame >= timingProperties._repeatCount ) {
            stop = TRUE;
        }
    } else {
        if ( curFrame >= 1.0 ) {
            stop = TRUE;
        }
    }
    if ( timingProperties._duration == 0.0f ) {
        stop = TRUE;
    }

    if ( stop ) {
        if ( timingProperties._autoReverses ) {
            ApplyLocalAnimation(pLayer, 0.0f, presentationProperties);
        } else {
            ApplyLocalAnimation(pLayer, 1.0f, presentationProperties);
        }

        if ( !_hasStopped ) {
            _hasStopped = TRUE;
            Stopped(pLayer);
            _fireFinished = TRUE;

            return false;
        }

        return false;
    }

    double curFrameNumber = floor(curFrame);

    curTime -= curFrameNumber * keyFrameDuration;

    //  Invert if it autoreverses
    if ( timingProperties._autoReverses && curTime > timingProperties._duration ) {
        curTime -= timingProperties._duration;
        curTime = timingProperties._duration - curTime;
    }

    ApplyLocalAnimation(pLayer, applyMediaTimingFunction(timingProperties._timingFunction, (float)(curTime / timingProperties._duration)), presentationProperties);

    if ( timingProperties._repeatCount < 500.0f ) {
        GetCACompositor()->RequestRedraw();
    } else {
        pLayer->refreshOnDraw = true;
    }

    return false;
}

BasicAnimation::BasicAnimation(id self) : DisplayAnimation(self)
{
    strcpy(_propName, "");
}

DisplayAnimation *BasicAnimation::Clone()
{
    BasicAnimation *pCopy = new BasicAnimation(nil);

    *pCopy = *this;
    pCopy->_ownerNode = NULL;
    pCopy->_animationObject = nil;
    pCopy->refCount = 0;

    return pCopy;
}

const char *BasicAnimation::Description()
{
    return _propName;
}

void BasicAnimation::ApplyLocalAnimation(DisplayNode *pLayer, double normalizedTimeIn, CADisplayProperties *presentationProperties)
{
    // Every other parameter of this is a float and we don't need the extra resolution of double in this circumstance
    // so use floating point for the time here. This may break for very long animations.
    float normalizedTime = float(normalizedTimeIn);

    if ( strcmp(_propName, "") == 0 ) return;

    if ( strcmp(_propName, "opacity") == 0 ) {
        float delta = _floatTo - _floatFrom;

        presentationProperties->opacity = _floatFrom + delta * normalizedTime;
    } else if ( strcmp(_propName, "position") == 0 ) {
        CGPoint delta;
        CGPoint from = _pointFrom;

        delta.x = _pointTo.x - from.x;
        delta.y = _pointTo.y - from.y;

        presentationProperties->position.x = from.x + delta.x * normalizedTime;
        presentationProperties->position.y = from.y + delta.y * normalizedTime;
    } else if ( strcmp(_propName, "bounds") == 0 ) {
        CGRect delta;
        CGRect from = _rectFrom;

        delta.origin.x = _rectTo.origin.x - from.origin.x;
        delta.origin.y = _rectTo.origin.y - from.origin.y;
        delta.size.width = _rectTo.size.width - from.size.width;
        delta.size.height = _rectTo.size.height - from.size.height;

        presentationProperties->bounds.origin.x = from.origin.x + delta.origin.x * normalizedTime;
        presentationProperties->bounds.origin.y = from.origin.y + delta.origin.y * normalizedTime;
        presentationProperties->bounds.size.width = from.size.width + delta.size.width * normalizedTime;
        presentationProperties->bounds.size.height = from.size.height + delta.size.height * normalizedTime;
    } else if ( strcmp(_propName, "bounds.origin") == 0 ) {
        CGPoint delta;
        delta.x = _pointTo.x - _pointFrom.x;
        delta.y = _pointTo.y - _pointFrom.y;

        presentationProperties->bounds.origin.x = _pointFrom.x + delta.x * normalizedTime;
        presentationProperties->bounds.origin.y = _pointFrom.y + delta.y * normalizedTime;
    } else if ( strcmp(_propName, "bounds.size") == 0 ) {
        CGSize delta;
        delta.width = _sizeTo.width - _sizeFrom.width;
        delta.height = _sizeTo.height - _sizeFrom.height;

        presentationProperties->bounds.size.width = _sizeFrom.width + delta.width * normalizedTime;
        presentationProperties->bounds.size.height = _sizeFrom.height + delta.height * normalizedTime;
    } else if ( strcmp(_propName, "position.x") == 0 ) {
        float delta = _floatTo - _floatFrom;

        presentationProperties->position.x = _floatFrom + delta * normalizedTime;
    } else if ( strcmp(_propName, "position.y") == 0 ) {
        float delta = _floatTo - _floatFrom;

        presentationProperties->position.y = _floatFrom + delta * normalizedTime;
    } else if ( strcmp(_propName, "transform") == 0 ) {
        CATransform3D from = _transformFrom;

        Quaternion qFrom, qTo;
        qFrom.CreateFromMatrix((float *) &from);
        qTo.CreateFromMatrix((float *) &_transformTo);

        Quaternion result = Quaternion::Slerp(qFrom, qTo, normalizedTime);

        CATransform3D rotationTransform;
        result.CreateMatrix((float *) &rotationTransform);

        presentationProperties->transform = CATransform3DMakeTranslation(0, 0, 0);

        float fromScale[3], toScale[3];
        float fromPosition[3], toPosition[3];
        CATransform3DGetScale(_transformFrom, fromScale);
        CATransform3DGetPosition(_transformFrom, fromPosition);
        CATransform3DGetScale(_transformTo, toScale);
        CATransform3DGetPosition(_transformTo, toPosition);

        CATransform3D scaleTransform;
        scaleTransform = CATransform3DMakeScale(fromScale[0] + (toScale[0] - fromScale[0]) * normalizedTime,
            fromScale[1] + (toScale[1] - fromScale[1]) * normalizedTime,
            fromScale[2] + (toScale[2] - fromScale[2]) * normalizedTime);
        CATransform3D translateTransform;
        translateTransform = CATransform3DMakeTranslation(fromPosition[0] + (toPosition[0] - fromPosition[0]) * normalizedTime,
            fromPosition[1] + (toPosition[1] - fromPosition[1]) * normalizedTime,
            fromPosition[2] + (toPosition[2] - fromPosition[2]) * normalizedTime);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, rotationTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, scaleTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, translateTransform);
    } else if ( strcmp(_propName, "transform.rotation") == 0 || strcmp(_propName, "transform.rotation.z") == 0 ) {
        float delta = _floatTo - _floatFrom;

        CATransform3D rotationTransform;
        rotationTransform = CATransform3DMakeRotation(_floatFrom + (_floatTo - _floatFrom) * normalizedTime, 0, 0, 1.0f);

        float curScale[3];
        float curPosition[3];
        CATransform3DGetScale(presentationProperties->transform, curScale);
        CATransform3DGetPosition(presentationProperties->transform, curPosition);

        presentationProperties->transform = CATransform3DMakeTranslation(0, 0, 0);

        CATransform3D scaleTransform, translateTransform;
        scaleTransform = CATransform3DMakeScale(curScale[0], curScale[1], curScale[2]);
        translateTransform = CATransform3DMakeTranslation(curPosition[0], curPosition[1], curPosition[2]);

        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, rotationTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, scaleTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, translateTransform);
    } else if ( strcmp(_propName, "transform.rotation.y") == 0 ) {
        float delta = _floatTo - _floatFrom;

        CATransform3D rotationTransform;
        rotationTransform = CATransform3DMakeRotation(_floatFrom + (_floatTo - _floatFrom) * normalizedTime, 0, 1.0f, 0.0f);

        float curScale[3];
        float curPosition[3];
        CATransform3DGetScale(presentationProperties->transform, curScale);
        CATransform3DGetPosition(presentationProperties->transform, curPosition);

        presentationProperties->transform = CATransform3DMakeTranslation(0, 0, 0);

        CATransform3D scaleTransform, translateTransform;
        scaleTransform = CATransform3DMakeScale(curScale[0], curScale[1], curScale[2]);
        translateTransform = CATransform3DMakeTranslation(curPosition[0], curPosition[1], curPosition[2]);

        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, rotationTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, scaleTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, translateTransform);
    } else if ( strcmp(_propName, "transform.rotation.x") == 0 ) {
        float delta = _floatTo - _floatFrom;

        CATransform3D rotationTransform;
        rotationTransform = CATransform3DMakeRotation(_floatFrom + (_floatTo - _floatFrom) * normalizedTime, 1.0, 0.0f, 0.0f);

        float curScale[3];
        float curPosition[3];
        CATransform3DGetScale(presentationProperties->transform, curScale);
        CATransform3DGetPosition(presentationProperties->transform, curPosition);

        presentationProperties->transform = CATransform3DMakeTranslation(0, 0, 0);

        CATransform3D scaleTransform, translateTransform;
        scaleTransform = CATransform3DMakeScale(curScale[0], curScale[1], curScale[2]);
        translateTransform = CATransform3DMakeTranslation(curPosition[0], curPosition[1], curPosition[2]);

        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, rotationTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, scaleTransform);
        presentationProperties->transform = CATransform3DConcat(presentationProperties->transform, translateTransform);
    } else if ( strcmp(_propName, "transform.scale") == 0 ) {
        float delta = _floatTo - _floatFrom;

        float curVal = _floatFrom + (_floatTo - _floatFrom ) * normalizedTime;

        presentationProperties->transform.m11 = curVal;
        presentationProperties->transform.m22 = curVal;
        presentationProperties->transform.m33 = curVal;
        presentationProperties->transform.m44 = 1.0f;
    } else {
        EbrDebugLog("Unsupported transform: %s\n", _propName);
    }
}

void BasicAnimation::Activated(DisplayNode *pLayer)
{
}

void BasicAnimation::Started(DisplayNode *pLayer)
{
}

void BasicAnimation::Stopped(DisplayNode *pLayer)
{
}

void BasicAnimation::PerformFill()
{
    /*
    switch ( timingProperties._fillMode ) {
        case fillModeBoth:
        case fillModeForwards: {
            CABasicAnimation* self = timingProperties._self;

            char *pName = (char *) E2H([self->_keyPath UTF8String]);
            EbrDebugLog("Performing fill on %s\n", pName);
            [_targetLayer setValue:self->_to forKey:self->_keyPath];
        }
            break;

        default:
            assert(0);
            break;
    }
    */
}

MoveAnimation::MoveAnimation(id self) : DisplayAnimation(self)
{
}

DisplayAnimation *MoveAnimation::Clone()
{
    MoveAnimation *pCopy = new MoveAnimation(nil);

    *pCopy = *this;
    pCopy->_ownerNode = NULL;
    pCopy->_animationObject = nil;
    pCopy->refCount = 0;

    return pCopy;
}

void MoveAnimation::AdjustPos(CADisplayProperties *presentationProperties, CGPoint *pos, bool invert)
{
    switch ( moveSubType ) {
        case fromLeft:
            pos->x -= invert ? -presentationProperties->bounds.size.width : presentationProperties->bounds.size.width;
            break;

        case fromRight:
            pos->x += invert ? -presentationProperties->bounds.size.width : presentationProperties->bounds.size.width;
            break;

        case fromTop:
            pos->y += invert ? -presentationProperties->bounds.size.height : presentationProperties->bounds.size.height;
            break;

        case fromBottom:
            pos->y -= invert ? -presentationProperties->bounds.size.height : presentationProperties->bounds.size.height;
            break;
    }
}

void MoveAnimation::ApplyLocalAnimation(DisplayNode *pLayer, double normalizedTime, CADisplayProperties *presentationProperties)
{
    if ( moveType == squeeze ) {
        if ( !inverted ) {
            normalizedTime *= 2.0;

            if ( normalizedTime >= 1.0 ) {
                presentationProperties->transform = CATransform3DMakeScale(float(normalizedTime - 1.0), 1.f, 1.f);
            } else {
                presentationProperties->transform = CATransform3DMakeScale(0, 1.f, 1.f);
            }
        } else {
            normalizedTime *= 2.0;
            if ( normalizedTime <= 1.0 ) {
                presentationProperties->transform = CATransform3DMakeScale(float(1.0 - normalizedTime), 1.0, 1.0);
            } else {
                presentationProperties->transform = CATransform3DMakeScale(0, 1.f, 1.f);
            }
        }
        return;
    }

    CGPoint fromPos;
    CGPoint toPos;
    float fromAlpha;
    float toAlpha;
    float alphaTime = (float)normalizedTime;

    fromAlpha = presentationProperties->opacity;
    toAlpha = presentationProperties->opacity;

    memcpy(&fromPos, &presentationProperties->position, sizeof(CGPoint));
    memcpy(&toPos, &presentationProperties->position, sizeof(CGPoint));

    switch ( moveType ) {
        case fade:
            if ( !inverted ) {
                fromAlpha = 0.0f;
            } else {
                toAlpha = 0.0f;
            }
            break;

        case moveIn:
            if ( !inverted ) {
                AdjustPos(presentationProperties, &fromPos, false);
                fromAlpha = 0.0f;

                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            } else {
                toAlpha = 0.0f;

                alphaTime -= 0.5f;
                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            }
            break;

        case push:
            if ( !inverted ) {
                AdjustPos(presentationProperties, &fromPos, false);
                fromAlpha = 0.0f;

                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            } else {
                AdjustPos(presentationProperties, &toPos, true);
                toAlpha = 0.0f;

                alphaTime -= 0.5f;
                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            }
            break;

        case reveal:
            if ( !inverted ) {
                fromAlpha = 0.0f;

                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            } else {
                AdjustPos(presentationProperties, &toPos, true);
                toAlpha = 0.0f;

                alphaTime -= 0.5f;
                alphaTime *= 2.0f;
                if ( alphaTime < 0.0f ) alphaTime = 0.0f;
                if ( alphaTime > 1.0f ) alphaTime = 1.0f;
            }
            break;

            /*
        default:
            break;
            */
    }

    CGPoint deltaPos;
    deltaPos.x = toPos.x - fromPos.x;
    deltaPos.y = toPos.y - fromPos.y;

    float deltaAlpha = toAlpha - fromAlpha;

    presentationProperties->position.x = fromPos.x + float(deltaPos.x * normalizedTime);
    presentationProperties->position.y = fromPos.y + float(deltaPos.y * normalizedTime);
    presentationProperties->opacity = fromAlpha + deltaAlpha * alphaTime;
//  EbrDebugLog("Animation @ %x running\n", this);
}

void MoveAnimation::Activated(DisplayNode *pLayer)
{
}

void MoveAnimation::Started(DisplayNode *pLayer)
{
}

void MoveAnimation::Stopped(DisplayNode *pLayer)
{
    if ( inverted ) {
        DisplayTransaction::removeNode(pLayer);
        pLayer->presentationProperties.hidden = TRUE;
        pLayer->originalPresentationProperties.hidden = TRUE;
        GetCACompositor()->DisplayTreeChanged();
    }
}

