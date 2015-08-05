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

#include "QuartzCore/CAAnimation.h"
#include "QuartzCore/CALayer.h"

class DisplayNode;
class DisplayAnimationRef;

class DisplayAnimation
{
public:
    uint32_t refCount;
    CAMediaTimingProperties timingProperties;
    BOOL _hasStarted, _hasStopped, _hasActivated;
    BOOL _fireActivate, _fireStarted, _fireFinished, _remove;
    BOOL _didFireActivate, _didFireStarted, _didFireFinished;    
    BOOL  _abort;
    id _animationObject;

    DisplayAnimationRef *_ownerNode;

public:
    DisplayAnimation(id animationObject);
    virtual ~DisplayAnimation();

    void Release();
    void AddRef();

    virtual bool ApplyAnimation(DisplayNode *pLayer, double curTime, CADisplayProperties *presentationProperties);
    virtual void ApplyLocalAnimation(DisplayNode *pLayer, double normalizedTime, CADisplayProperties *presentationProperties) = 0;
    virtual void Activated(DisplayNode *pLayer) = 0;
    virtual void Started(DisplayNode *pLayer) = 0;
    virtual void Stopped(DisplayNode *pLayer) = 0;
    virtual void PerformFill();
    virtual DisplayAnimation *Clone() = 0;
    virtual const char *Description()
    {
        return "None";
    }
};

class DisplayAnimationRef : public LLTreeNodeNoObj<DisplayAnimationRef>
{
public:
    DisplayAnimation *_animation;
    DisplayNode      *_appliedToNode;
};

#define MAX_CLIP_REGION     32

class ClippingRegion
{
private:
    DisplayNode  *clippingLayers[MAX_CLIP_REGION];
    float         clippingMatricies[MAX_CLIP_REGION][16];
    int            numClippingLayers;

public:
    ClippingRegion();

    void Clear();
    void RenderStencil();
    void ApplyScreen();
    void PushClippingLayer(DisplayNode *layer);
    void PopClippingLayer();
};

#define animationEventNone      0x00
#define animationEventActivated 0x01
#define animationEventStarted   0x02
#define animationEventFinished  0x04

class AnimationEvent : public LLTreeNodeNoObj<AnimationEvent>
{
public:
    DWORD              _events;
    DisplayAnimation  *_animation;
};

class ActiveAnimations
{
    EbrLock              _listLock;
    DisplayAnimationRef  *_allAnimations;
    AnimationEvent       **_eventLists;
    int                    _numEventLists, _maxEventLists;

public:
    ActiveAnimations();
    void AddActiveAnimation(DisplayAnimation *anim);
    void ProcessAnimationEvents();
    void ApplyAnimations(double curTime);
};

class BasicAnimation : public DisplayAnimation
{
public:
    float _floatFrom, _floatTo;
    CGPoint _pointFrom, _pointTo;
    CGRect _rectFrom, _rectTo;
    CGSize _sizeFrom, _sizeTo;
    CATransform3D _transformFrom, _transformTo;
    char _propName[128];

    BasicAnimation(id self);
    DisplayAnimation *Clone();
    virtual const char *Description();
    void ApplyLocalAnimation(DisplayNode *pLayer, double normalizedTimeIn, CADisplayProperties *presentationProperties);
    void Activated(DisplayNode *pLayer);
    void Started(DisplayNode *pLayer);
    void Stopped(DisplayNode *pLayer);
    void PerformFill();
};

class MoveAnimation : public DisplayAnimation
{
public:
    typedef enum {
        fade,
        moveIn,
        push,
        reveal,
        squeeze,
    } MoveType;

    typedef enum {
        fromRight,
        fromLeft,
        fromTop,
        fromBottom
    } MoveSubType;

    MoveType     moveType;
    MoveSubType  moveSubType;
    bool         inverted;

    MoveAnimation(id self);
    DisplayAnimation *Clone();
    void AdjustPos(CADisplayProperties *presentationProperties, CGPoint *pos, bool invert);
    void ApplyLocalAnimation(DisplayNode *pLayer, double normalizedTime, CADisplayProperties *presentationProperties);
    void Activated(DisplayNode *pLayer);
    void Started(DisplayNode *pLayer);
    void Stopped(DisplayNode *pLayer);
};

extern ActiveAnimations _activeAnimations;
extern int g_numActiveAnimations, g_totalDisplayAnimations, g_totalCAAnimations;

