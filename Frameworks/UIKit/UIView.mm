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
#include "UIAnimationNotification.h"
#include "QuartzCore/CABasicAnimation.h"
#include "UIViewInternal.h"
#include "UIAppearanceSetter.h"

@class UIAppearanceSetter;

#if defined( USE_CASSOWARY )
#include <ClSimplexSolver.h>
#include <ClLinearEquation.h>
#endif

#include <math.h>

const CGFloat UIViewNoIntrinsicMetric = -1.0f;

BOOL g_alwaysSendViewEvents = TRUE;
int g_animationsDisabled = 0, g_nestedAnimationsDisabled = 0;
BOOL g_presentingAnimated = FALSE;

typedef void (^animationBlockFunc)(void);
typedef void (^completionBlockFunc)(BOOL);
#define CALLBLOCK(b) b()
#define CALLCOMPLETIONBLOCK(b, finished) b(finished)
#define COPYBLOCK(b) Block_copy(b)

typedef struct {
    int    _numAnimations;
    double _animationDuration;
    double _animationDelay;
    id     _animationDelegate;
    idretain _animationCurve;
    id     _animationID;
    void  *_context;
    SEL _animationWillStartSelector;
    SEL _animationDidStopSelector;
    BOOL   _autoReverses;
    BOOL   _beginsFromCurrentState;
    float  _repeatCount;
    UIAnimationNotification*  _animationNotifier;
    completionBlockFunc _completionBlock;
} AnimationProperties;

class AutoLayoutProperties;
#if defined( USE_CASSOWARY )
class AutoLayoutProperties
{
public:
    AutoLayoutProperties(id view)  
    {
        memset(_contentHuggingConstraint, 0, sizeof(_contentHuggingConstraint));
        memset(_contentCompressionResistanceConstraint, 0, sizeof(_contentCompressionResistanceConstraint));
        _constrained = false;
        _staysAdded = false;
        _inSolution = false;
        _vars[Right] = new ClVariable(0.0);
        _vars[Bottom] = new ClVariable(0.0);
        _vars[Left] = new ClVariable(0.0);
        _vars[Top] = new ClVariable(0.0);
        _contentHuggingPriority.height = 250.0f;
        _contentHuggingPriority.width = 250.0f;
        _contentCompressionResistancePriority.height = 750.0f;
        _contentCompressionResistancePriority.width = 750.0f;
    }

    ~AutoLayoutProperties()
    {
        delete _vars[0];
        delete _vars[1];
        delete _vars[2];
        delete _vars[3];
    }

    void AddStays()
    {
        if(!_staysAdded) {
            for(int i = 0; i < 4; i++) {
                solver.AddStay(*_vars[i], ClsWeak(), 1000.0);
            }
            _staysAdded = true;
        }
    }

    enum {
        Left,
        Right,
        Top,
        Bottom
    };

    ClVariable* _vars[4];
    bool _constrained;
    bool _staysAdded;
    bool _inSolution;
    CGSize _contentHuggingPriority;
    CGSize _contentCompressionResistancePriority;
    ClConstraint* _contentHuggingConstraint[2];
    ClConstraint* _contentCompressionResistanceConstraint[2];
};

void dumpConstraints(id constraints) {
    int count = [constraints count];
    if(count) {
        for(int i = 0; i < count; i++) {
            NSLayoutConstraint* constraint = [(id)constraints objectAtIndex:i];
            if(constraint->_items[0] != nil) {
                EbrDebugLog("Constraint from (%s) Type: ", E2H([[constraint->_items[0] description] UTF8String]));
            } else {
                EbrDebugLog("Constraint from (NONE) Type: ");
            }
            switch(constraint->_attributes[0]) {
            case NSLayoutAttributeLeft:
                EbrDebugLog("NSLayoutAttributeLeft\n");
                break;
            case NSLayoutAttributeRight:
                EbrDebugLog("NSLayoutAttributeRight\n");
                break;
            case NSLayoutAttributeTop:
                EbrDebugLog("NSLayoutAttributeTop\n");
                break;
            case NSLayoutAttributeBottom:
                EbrDebugLog("NSLayoutAttributeBottom\n");
                break;
            case NSLayoutAttributeLeading:
                EbrDebugLog("NSLayoutAttributeLeading\n");
                break;
            case NSLayoutAttributeTrailing:
                EbrDebugLog("NSLayoutAttributeRight\n");
                break;
            case NSLayoutAttributeWidth:
                EbrDebugLog("NSLayoutAttributeWidth\n");
                break;
            case NSLayoutAttributeHeight:
                EbrDebugLog("NSLayoutAttributeHeight\n");
                break;
            case NSLayoutAttributeCenterX:
                EbrDebugLog("NSLayoutAttributeCenterX\n");
                break;
            case NSLayoutAttributeCenterY:
                EbrDebugLog("NSLayoutAttributeCenterY\n");
                break;
            case NSLayoutAttributeBaseline:
                EbrDebugLog("NSLayoutAttributeBaseline\n");
                break;
            default:
                EbrDebugLog("None\n");
                break;
            }
            if(constraint->_items[1] != nil) {
                EbrDebugLog("Constraint to   (%s) Type: ", E2H([[constraint->_items[1] description] UTF8String]));
            } else {
                EbrDebugLog("Constraint to   (NONE) Type: ");
            }
            switch(constraint->_attributes[1]) {
            case NSLayoutAttributeLeft:
                EbrDebugLog("NSLayoutAttributeLeft\n");
                break;
            case NSLayoutAttributeRight:
                EbrDebugLog("NSLayoutAttributeRight\n");
                break;
            case NSLayoutAttributeTop:
                EbrDebugLog("NSLayoutAttributeTop\n");
                break;
            case NSLayoutAttributeBottom:
                EbrDebugLog("NSLayoutAttributeBottom\n");
                break;
            case NSLayoutAttributeLeading:
                EbrDebugLog("NSLayoutAttributeLeading\n");
                break;
            case NSLayoutAttributeTrailing:
                EbrDebugLog("NSLayoutAttributeRight\n");
                break;
            case NSLayoutAttributeWidth:
                EbrDebugLog("NSLayoutAttributeWidth\n");
                break;
            case NSLayoutAttributeHeight:
                EbrDebugLog("NSLayoutAttributeHeight\n");
                break;
            case NSLayoutAttributeCenterX:
                EbrDebugLog("NSLayoutAttributeCenterX\n");
                break;
            case NSLayoutAttributeCenterY:
                EbrDebugLog("NSLayoutAttributeCenterY\n");
                break;
            case NSLayoutAttributeBaseline:
                EbrDebugLog("NSLayoutAttributeBaseline\n");
                break;
            default:
                EbrDebugLog("None\n");
                break;
            }
            EbrDebugLog("Deets: mult(%f) const(%f), priority(%d)\n", constraint->_multiplier, constraint->_constant, constraint->_priority);
            if(constraint->_constant < 0) {
                CGRect itmBounds;
                itmBounds = [constraint->_items[0] frame];
                EbrDebugLog("Item 1 (%f)(%f), (%f)(%f)\n", itmBounds.origin.x, itmBounds.origin.y, itmBounds.size.width, itmBounds.size.height);
                itmBounds = [constraint->_items[1] frame];
                EbrDebugLog("Item 2 (%f)(%f), (%f)(%f)\n", itmBounds.origin.x, itmBounds.origin.y, itmBounds.size.width, itmBounds.size.height);
            }
        }
    }
}
#endif

static AnimationProperties _animationProperties[32];
static int stackLevel = 0;

int viewCount = 0;

@implementation UIView {
    idretaintype(CALayer) layer;
    bool _deallocating;
}
    static void initPriv(UIView* self)
    {
        if ( self->priv ) return;

        viewCount ++;
        self->priv = new UIViewPrivateState();
        self->priv->setSelf(self);
        self->priv->autoresizesSubviews = TRUE;
        self->priv->autoresizingMask = UIViewAutoresizingNone;
        self->priv->userInteractionEnabled = 1;
        self->priv->multipleTouchEnabled = 0;
        self->priv->superview = 0;
        self->priv->backgroundColor = nil;
        self->priv->currentTouches = [[NSMutableArray alloc] initWithCapacity:16];
        self->priv->contentMode = UIViewContentModeScaleToFill;
        self->priv->gestures = [NSMutableArray new];
        self->priv->constraints = [NSMutableArray new];
#if defined( USE_CASSOWARY )
        self->priv->layoutProperties = new AutoLayoutProperties(self);
#endif

        self->layer.attach([[[self class] layerClass] new]);
        [self->layer setDelegate:self];

        //EbrDebugLog("%d: Allocing %s (%x)\n", viewCount, object_getClassName(self), (id) self);
    }


    +(instancetype) allocWithZone:(NSZone*)zone {
        UIView* ret = [super allocWithZone:zone];

        initPriv(ret);
        return ret;
    }

    static UIView* initInternal(UIView* self, CGRect pos)
    {
        EbrDebugLog("[%f,%f] @ %fx%f\n", (float) pos.origin.x, (float) pos.origin.y, (float) pos.size.width, (float) pos.size.height);

        initPriv(self);
        [self setOpaque:TRUE];
        [self setFrame:pos];
        [self setNeedsDisplay];

#if defined( USE_CASSOWARY )
        priv->layoutProperties->_vars[AutoLayoutProperties::Right]->SetValue(pos.origin.x + pos.size.width);
        priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]->SetValue(pos.origin.y + pos.size.height);
        priv->layoutProperties->_vars[AutoLayoutProperties::Left]->SetValue((Number)pos.origin.x);
        priv->layoutProperties->_vars[AutoLayoutProperties::Top]->SetValue((Number)pos.origin.y);
#endif

        return self;
    }


    -(instancetype) initWithFrame:(CGRect)pos {
        return initInternal(self, pos);
    }


    -(instancetype) init {
        CGRect pos;

        pos.origin.x = 0;
        pos.origin.y = 0;
        pos.size.width = 0;
        pos.size.height = 0;

        return [self initWithFrame:pos];
    }

#define PAUSE_ANIMATIONS()  g_nestedAnimationsDisabled ++;
#define CONTINUE_ANIMATIONS()   g_nestedAnimationsDisabled --;  if ( g_nestedAnimationsDisabled < 0 ) g_nestedAnimationsDisabled = 0;


    -(id) initWithCoder:(NSCoder*)coder {
        CGRect bounds;

        NSString* boundsObj = [coder decodeObjectForKey:@"UIBounds"];
        if ( boundsObj != nil ) {
            if ( [boundsObj isKindOfClass:[NSString class]] ) {
                const char *boundsStr = (const char *) [boundsObj UTF8String];
                sscanf(boundsStr, "{{%f, %f}, {%f, %f}}", &bounds.origin.x, &bounds.origin.y, &bounds.size.width, &bounds.size.height);
            } else {
                CGRect *pRect = (CGRect *) ((char *) [boundsObj bytes] + 1);
                memcpy(&bounds, pRect, sizeof(CGRect));
            }
        } else {
            bounds.origin.x = 0;
            bounds.origin.y = 0;
            bounds.size.width = 0;
            bounds.size.height = 0;
        }

        CGPoint center;

        NSObject* centerObj = [coder decodeObjectForKey:@"UICenter"];
        if ( centerObj ) {
            if ( [centerObj isKindOfClass:[NSString class]] ) {
                const char *centerStr = (const char *) [centerObj UTF8String];
                sscanf(centerStr, "{%f, %f}", &center.x, &center.y);
            } else {
                CGPoint *pPoint = (CGPoint *) ((char *) [centerObj bytes] + 1);
                memcpy(&center, pPoint, sizeof(CGPoint));
            }
        } else {
            center.x = 0;
            center.y = 0;
        }

        PAUSE_ANIMATIONS();
        [self setBounds:bounds];
        [self setCenter:center];
        [self setNeedsDisplay];
        if ( [coder containsValueForKey:@"UIAlpha"] ) {
            float val = [coder decodeFloatForKey:@"UIAlpha"];
            [self setAlpha:val];
        }
        if ( [coder containsValueForKey:@"UIContentStretch"] ) {

            CGRect rect;

            NSObject* obj = [coder decodeObjectForKey:@"UIContentStretch"];
            if ( [obj isKindOfClass:[NSString class]] ) {
                const char *stretchStr = (const char *) [obj UTF8String];
                sscanf(stretchStr, "{{%f, %f}, {%f, %f}}", &rect.origin.x, &rect.origin.y, &rect.size.width, &rect.size.height);
            } else {
                memcpy(&rect, (char *) [obj bytes] + 1, sizeof(CGRect));
            }

            [self setContentStretch:rect];
        }

        CONTINUE_ANIMATIONS();

        if ( [coder decodeInt32ForKey:@"UIUserInteractionDisabled"] ) {
            priv->userInteractionEnabled = FALSE;
        }

        UIViewContentMode contentMode = (UIViewContentMode) [coder decodeInt32ForKey:@"UIContentMode"];
        [self setContentMode:contentMode];

        id uidelegate = [coder decodeObjectForKey:@"UIDelegate"];
        if ( uidelegate != nil ) {
            [self setDelegate:uidelegate];
        }

        NSArray* subviewsObj = [coder decodeObjectForKey:@"UISubviews"];
        if ( subviewsObj != nil ) {
            int count = [subviewsObj count];

            for ( int i = 0; i < count; i ++ ) {
                UIView* subView = [subviewsObj objectAtIndex:i];
                [self addSubview:subView];
            }
        }

#if defined( USE_CASSOWARY )
        if([coder containsValueForKey:@"UIViewContentCompressionResistancePriority"]) {
            id sizeObj = [coder decodeObjectForKey:@"UIViewContentCompressionResistancePriority"];
            if ( [sizeObj isKindOfClass:[NSString class]] ) {
                const char *stretchStr = (const char *) E2H([sizeObj UTF8String]);
                sscanf(stretchStr, "{%f, %f}", &priv->layoutProperties->_contentCompressionResistancePriority.width, &priv->layoutProperties->_contentCompressionResistancePriority.height);
            } else {
                CGSize *size = (CGSize *) E2H([sizeObj bytes] + 1);
                memcpy(&priv->layoutProperties->_contentCompressionResistancePriority, size, sizeof(CGRect));
            }
        }

        if([coder containsValueForKey:@"UIViewContentHuggingPriority"]) {
            id sizeObj = [coder decodeObjectForKey:@"UIViewContentHuggingPriority"];
            if ( [sizeObj isKindOfClass:[NSString class]] ) {
                const char *stretchStr = (const char *) E2H([sizeObj UTF8String]);
                sscanf(stretchStr, "{%f, %f}", &priv->layoutProperties->_contentHuggingPriority.width, &priv->layoutProperties->_contentHuggingPriority.height);
            } else {
                CGSize *size = (CGSize *) E2H([sizeObj bytes] + 1);
                memcpy(&priv->layoutProperties->_contentHuggingPriority, size, sizeof(CGRect));
            }
        }

        priv->layoutProperties->_vars[AutoLayoutProperties::Right]->SetValue(bounds.origin.x + bounds.size.width);
        priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]->SetValue(bounds.origin.y + bounds.size.height);
        priv->layoutProperties->_vars[AutoLayoutProperties::Left]->SetValue((Number)bounds.origin.x);
        priv->layoutProperties->_vars[AutoLayoutProperties::Top]->SetValue((Number)bounds.origin.y);
#endif

        if ( [coder containsValueForKey:@"UIViewAutolayoutConstraints"] ) {
            NSArray* constraints = [coder decodeObjectForKey:@"UIViewAutolayoutConstraints"];
            int count = [constraints count];
            for(int i = 0; i < count; i++) {
                NSLayoutConstraint* constraint = [constraints objectAtIndex:i];
                if([(id)constraint isKindOfClass:[NSLayoutConstraint class]]) {
                    [self addConstraint:(id)constraint];
                } else {
                    EbrDebugLog("Skipping unsupported constraint type: %s\n", [[constraint description] UTF8String]);
                }
            }
        }

        [self setHidden:[coder decodeInt32ForKey:@"UIHidden"]];

        priv->autoresizesSubviews = [coder decodeInt32ForKey:@"UIAutoresizeSubviews"];
        priv->autoresizingMask = (UIViewAutoresizing) [coder decodeInt32ForKey:@"UIAutoresizingMask"];
        priv->tag = [coder decodeInt32ForKey:@"UITag"];
        priv->multipleTouchEnabled = [coder decodeInt32ForKey:@"UIMultipleTouchEnabled"];

        [self setOpaque:[coder decodeInt32ForKey:@"UIOpaque"]];
        [self setClipsToBounds:[coder decodeInt32ForKey:@"UIClipsToBounds"]];

        UIColor* backgroundColor = [coder decodeObjectForKey:@"UIBackgroundColor"];
        if ( backgroundColor != nil ) [self setBackgroundColor:backgroundColor];

        NSArray* gestures = [coder decodeObjectForKey:@"gestureRecognizers"];
        if ( gestures != nil ) {
            EbrDebugLog("UIView initWithCoder adding gesture recognizers\n");
            [self setGestureRecognizers:gestures];
        }

        return self;
    }


    -(CGRect) bounds {
        CGRect ret;
        ret = [layer bounds];
        return ret;
    }


    -(CGPoint) center {
        CGPoint ret;
        ret = [layer position];
        return ret;
    }


    -(CGAffineTransform) transform {
        CGAffineTransform transform;
        transform = [layer affineTransform];
        return transform;
    }


    -(CGRect) frame {
        CGRect ret;
        ret = [layer frame];
        ret = CGRectStandardize(ret);
        return ret;
    }


    -(void) setCenter:(CGPoint)center {
        [layer setPosition:center];
    }


    -(void) layoutSublayersOfLayer:(CALayer*)forLayer {
        if ( forLayer == layer ) {
            UIViewController* controller = [UIViewController controllerForView:self];
            if ( controller != nil ) {
                [controller viewWillLayoutSubviews];
                [controller updateViewConstraints];
            }

            [self layoutSubviews];
            [self __didLayout];

            if ( controller != nil ) {
                [controller viewDidLayoutSubviews];
            }
        }
    }


    -(void) layoutSubviews {
        if ( priv->autoresizesSubviews ) {
#if defined( USE_CASSOWARY )
            // Apply new bounds.
            for(int i = 0; i < priv->childCount; i++) {
                UIView* child = priv->childAtIndex(i)->self;
                [(id)child layoutSubviews];

                if(priv->layoutProperties->_inSolution && child->priv->layoutProperties->_constrained) {
                    CGRect newFrame;
                    CGPoint newPoint;
                    CGPoint oldPoint;
                    UIViewPrivateState* topView = priv;

                    oldPoint.x = (float)child->priv->layoutProperties->_vars[AutoLayoutProperties::Left]->Value();
                    oldPoint.y = (float)child->priv->layoutProperties->_vars[AutoLayoutProperties::Top]->Value();
                        
                    while(topView->parent) {
                        if(topView->layoutProperties->_constrained) {
                            topView = topView->parent;
                        } else {
                            break;
                        }
                    }

                    newPoint = [self convertPoint:oldPoint fromView:topView->self];

                    newFrame.size.width = (float)(child->priv->layoutProperties->_vars[AutoLayoutProperties::Right]->Value() -
                            child->priv->layoutProperties->_vars[AutoLayoutProperties::Left]->Value());
                    newFrame.size.height = (float)(child->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]->Value() -
                                child->priv->layoutProperties->_vars[AutoLayoutProperties::Top]->Value());
                    newFrame.origin.x = newPoint.x;
                    newFrame.origin.y = newPoint.y;

                    [(id)child setFrame:newFrame];
                }
            }
#endif
        }
    }


    -(void) layoutIfNeeded {
        [layer layoutIfNeeded];
    }


    -(void) __didLayout {
        UIViewController* controller = [UIViewController controllerForView:self];

        if ( controller != nil ) {
            [controller viewDidLayoutSubviews];
        }
    }


    -(void) setNeedsLayout {
        [layer setNeedsLayout];
    }


    -(void) _setShouldLayout {
        [layer _setShouldLayout];
    }


    -(CGRect) origin {
        CGRect curFrame;

        curFrame = [layer frame];

        return curFrame;
    }

    static void doResize(unsigned mask, float &pos, float &size, float parentSize, float delta)
    {
        switch ( mask ) {
            case 0:
                break;

            case UIViewAutoresizingFlexibleLeftMargin:
                pos += delta;
                break;

            case UIViewAutoresizingFlexibleWidth:
                size += delta;
                break;

            case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth): {
                float totalSize = 0.0f;
                float newSize;

                totalSize += pos;
                totalSize += size;
                newSize = totalSize + delta;

                if ( totalSize == 0.0f ) {
                    pos += size;
                } else {
                    float newPos = pos * newSize / totalSize;
                    size = ((pos + size) * newSize / totalSize) - newPos;
                    pos = newPos;
                }
            }
                break;

            case UIViewAutoresizingFlexibleRightMargin:
                break;

            case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin): {
                float totalSize = 0.0f;
                float newSize;

                totalSize += pos;
                totalSize += parentSize - (pos + size);
                newSize = totalSize + delta;

                if ( totalSize == 0.0f ) {
                    pos = newSize / 2.0f;
                } else {
                    pos = pos * newSize / totalSize;
                }
                break;
            }

            case (UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth): {
                float totalSize = 0.0f;
                float lastSize = parentSize - (pos + size);
                float newSize;

                totalSize += size;
                totalSize += lastSize;
                newSize = totalSize + delta;

                if ( lastSize <= 0.0f || size == 0.0f ) {
                    size = parentSize + delta - pos;
                } else {
                    float newPos = pos * newSize / totalSize;
                    size = ((pos + size) * newSize / totalSize) - newPos;
                }
            }
                break;

            case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth): {
                float totalSize = 0.0f;
                float lastSize = parentSize - (pos + size);
                float newSize;

                totalSize += pos;
                totalSize += size;
                totalSize += lastSize;
                newSize = totalSize + delta;

                if ( totalSize == 0.0f ) {
                    pos = (parentSize + delta) / 3.0f;
                    size = (parentSize + delta) / 3.0f;
                } else {
                    float newPos = pos * newSize / totalSize;
                    size = ((pos + size) * newSize / totalSize) - newPos;
                    pos = newPos;
                }
            }
                break;

            default:
                assert(0);
                break;
        }
    }

    static void adjustSubviews(UIView* self, CGSize parentSize, CGSize delta)
    {
        if ( !self->priv ) return;

        if ( self->priv->autoresizesSubviews ) {
            //  Go through each subview and resize it
            LLTREE_FOREACH(curSubview, self->priv) {
                UIView* subview = curSubview->self;

                UIViewAutoresizing mask = subview->priv->autoresizingMask;

                if ( mask == UIViewAutoresizingNone ) continue;
#if defined( USE_CASSOWARY )                    
                if ( subview->priv->layoutProperties->_constrained ) continue;
#endif
                
                CGRect curFrame, origFrame;
                curFrame = [subview frame];
                origFrame = curFrame;

                curFrame.origin.x += subview->priv->_resizeRoundingError.origin.x;
                curFrame.origin.y += subview->priv->_resizeRoundingError.origin.y;
                curFrame.size.width += subview->priv->_resizeRoundingError.size.width;
                curFrame.size.height += subview->priv->_resizeRoundingError.size.height;

                doResize(mask & 7, curFrame.origin.x, curFrame.size.width, parentSize.width, delta.width);
                doResize((mask >> 3) & 7, curFrame.origin.y, curFrame.size.height, parentSize.height, delta.height);

                if ( curFrame.size.width < 0.0f ) curFrame.size.width = 0.0f;
                if ( curFrame.size.height < 0.0f ) curFrame.size.height = 0.0f;

                CGRect beforeRound = curFrame;
                curFrame.origin.x = floorf(curFrame.origin.x);
                curFrame.origin.y = floorf(curFrame.origin.y);
                curFrame.size.width = floorf(curFrame.size.width);
                curFrame.size.height = floorf(curFrame.size.height);

                if ( memcmp(&curFrame, &origFrame, sizeof(CGRect)) != 0 ) {
                    subview->priv->_resizeRoundingError.origin.x = beforeRound.origin.x - curFrame.origin.x;
                    subview->priv->_resizeRoundingError.origin.y = beforeRound.origin.y - curFrame.origin.y;
                    subview->priv->_resizeRoundingError.size.width = beforeRound.size.width - curFrame.size.width;
                    subview->priv->_resizeRoundingError.size.height = beforeRound.size.height - curFrame.size.height;

                    /*
                    EbrDebugLog("Resizing %s (%f, %f, %f, %f) -> (%f, %f, %f, %f)\n", object_getClassName(subview),
                        origFrame.origin.x, origFrame.origin.y, origFrame.size.width, origFrame.size.height, 
                        curFrame.origin.x, curFrame.origin.y, curFrame.size.width, curFrame.size.height);
                        */
                    [subview setFrame:curFrame];
                } else {
                    subview->priv->_resizeRoundingError.origin.x = beforeRound.origin.x - origFrame.origin.x;
                    subview->priv->_resizeRoundingError.origin.y = beforeRound.origin.y - origFrame.origin.y;
                    subview->priv->_resizeRoundingError.size.width = beforeRound.size.width - origFrame.size.width;
                    subview->priv->_resizeRoundingError.size.height = beforeRound.size.height - origFrame.size.height;
                }
            }
        }

        return;
    }

    static float doRound(float f)
    {
        return (float) (floor((f * 2) + 0.5) / 2.0f);
    }


    -(void) setFrame:(CGRect)frame {
        if ( memcmp(&frame, &CGRectNull, sizeof(CGRect)) == 0 ) {
            EbrDebugLog("setFrame: CGRectNull!\n");
            return;
        }

        frame.origin.x = doRound(frame.origin.x);
        frame.origin.y = doRound(frame.origin.y);
        frame.size.width = doRound(frame.size.width);
        frame.size.height = doRound(frame.size.height);

        EbrDebugLog("SetFrame(%s): %f, %f, %f, %f\n", object_getClassName(self), frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);

        //  Get our existing frame
        CGRect startFrame = frame;
        CGRect curFrame;
        curFrame = [self frame];

        if ( frame.origin.x == doRound(curFrame.origin.x) &&
             frame.origin.y == doRound(curFrame.origin.y) &&
             frame.size.width == doRound(curFrame.size.width) &&
             frame.size.height == doRound(curFrame.size.height) ) {
            return;
        }
        
        //  Get transformed bounding box
        CGAffineTransform curTransform, translate, invTranslate;
        curTransform = [layer affineTransform];

        CGPoint anchorPoint;
        CGPoint position;

        anchorPoint = [layer anchorPoint];
        
        position.x = frame.origin.x + frame.size.width * anchorPoint.x;
        position.y = frame.origin.y + frame.size.height * anchorPoint.y;

        //  Get transformed bounding box
        translate = CGAffineTransformMakeTranslation(-position.x, -position.y);
        translate = CGAffineTransformConcat(translate, curTransform);
        invTranslate = CGAffineTransformMakeTranslation(position.x, position.y);
        translate = CGAffineTransformConcat(translate, invTranslate);

        translate = CGAffineTransformInvert(translate);
        frame = CGRectApplyAffineTransform(frame, translate);

        CGSize outSize;
        outSize.width = frame.size.width;
        outSize.height = frame.size.height;

        position.x = frame.origin.x + frame.size.width * anchorPoint.x;
        position.y = frame.origin.y + frame.size.height * anchorPoint.y;

        CGRect curBounds;
        curBounds = [layer bounds];

        CGSize delta;
        delta.width = outSize.width - curBounds.size.width;
        delta.height = outSize.height - curBounds.size.height;
        if ( delta.width != 0.0f || delta.height != 0.0f ) {
            adjustSubviews(self, curBounds.size, delta);
        }

        [layer setPosition:position];

        curBounds.size = outSize;

        [layer setBounds:curBounds];
    }


    -(void) setBounds:(CGRect)bounds {
        //  Get our existing bounds
        CGRect curBounds;
        curBounds = [self bounds];
        
        //EbrDebugLog("Resizing %s (%f, %f, %f, %f)\n", object_getClassName(self), curBounds.origin.x, curBounds.origin.y, curBounds.size.width, curBounds.size.height);

        CGSize delta;
        delta.width = bounds.size.width - curBounds.size.width;
        delta.height = bounds.size.height - curBounds.size.height;
        if ( delta.width != 0.0f || delta.height != 0.0f ) {
            adjustSubviews(self, curBounds.size, delta);
        }

        [layer setBounds:bounds];
    }


    -(void) setOrigin:(CGPoint)origin {
        CGRect curFrame;

        curFrame = [layer frame];
        curFrame.origin = origin;
    
        [layer setFrame:curFrame];
  }


    -(void) setBoundsOrigin:(CGPoint)origin {
        [layer setOrigin:origin];
    }


    -(NSArray*) subviews {
        return priv->subnodesArray();
    }


    -(void) _notifyWillMoveToWindow:(UIWindow*)window superview:(UIView*)superview {
        UIViewController* controller = [UIViewController controllerForView:self];

        if ( controller != nil && window != nil ) {
            UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
            if ( rootController == nil ) {
                [[[[UIApplication sharedApplication] windows] objectAtIndex:0] _setRootViewController:controller];
                rootController = controller;
            }

            UIViewController* parentController = [UIViewController controllerForView:superview];
            if ( rootController == controller || g_alwaysSendViewEvents ) [controller notifyViewWillAppear:g_presentingAnimated]; /*** should we do this? ****/
        }
        if ( controller != nil && window == nil ) {
            UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController]; 
            UIViewController* parentController = [UIViewController controllerForView:superview];
            if ( rootController == controller || g_alwaysSendViewEvents ) [controller notifyViewWillDisappear:g_presentingAnimated]; /*** should we do this? ****/
        }

        if ( window == nil ) {
            for (UIGestureRecognizer* curgesture in priv->gestures) {
                if ( [curgesture respondsToSelector:@selector(cancelIfActive)] ) {
                    [curgesture cancelIfActive];
                }
            }
        }

        [self willMoveToWindow:window];

        LLTREE_FOREACH(curView, priv) {
            [curView->self _notifyWillMoveToWindow:window superview:superview];
        }
    }


    -(void) willMoveToSuperview:(UIView*)view {
    }


    -(void) _notifyDidMoveToWindow:(UIWindow*)window superview:(UIView*)superview {
        LLTREE_FOREACH(curView, priv) {
            [curView->self _notifyDidMoveToWindow:window superview:superview];
        }

        UIViewController* controller = [UIViewController controllerForView:self];

        if ( controller != nil && window != nil ) {
            UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
            UIViewController* parentController = [UIViewController controllerForView:superview];
            if ( rootController == controller || 
                [controller parentViewController] != nil || 
                [controller isKindOfClass:[UINavigationController class]] ||
                [parentController isKindOfClass:[UINavigationController class]] || 
                g_alwaysSendViewEvents ) {
                    if ( stackLevel == 0 ) {
                        [controller notifyViewWillAppear:FALSE];
                        [controller notifyViewDidAppear:FALSE];
                    }
                }
        }
        if ( controller != nil && window == nil ) {
            UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
            if ( rootController == controller ) {
                [[[[UIApplication sharedApplication] windows] objectAtIndex:0] _setRootViewController:nil];
            }

            UIViewController* parentController = [UIViewController controllerForView:superview];
            if ( rootController == controller || 
                [controller parentViewController] != nil || 
                [controller isKindOfClass:[UINavigationController class]] ||
                [parentController isKindOfClass:[UINavigationController class]] || 
                g_alwaysSendViewEvents ) [controller notifyViewDidDisappear:FALSE];
        }

        if ( window == nil ) {
            /* Optimization: release contents when not part of the view heirarchy */
            [layer _releaseContents:FALSE];
        }
        [self didMoveToWindow];
    }


    -(void) removeFromSuperview {
        if ( priv->_isChangingParent ) {
            assert(0);
        }
        if ( priv->superview != nil ) {
            [self retain];
            priv->_isChangingParent = true;

            UIWindow* curWindow = [self _getWindowInternal];
            UIView* curSuperview = priv->superview;

            //  Notify our superview that we will be removed
            if ( [priv->superview respondsToSelector:@selector(willRemoveSubview:)] ) {
                [priv->superview willRemoveSubview:self];
            }
            if ( [self respondsToSelector:@selector(willMoveToSuperview:)] ) {
                [self willMoveToSuperview:nil];
            }
            [self _notifyWillMoveToWindow:nil superview:curSuperview];

            UIView* superview = priv->superview;
            UIView* pSuper = curSuperview;
            if ( superview != curSuperview ) {
                EbrDebugLog("Warning: superview changed!\n");
            }

            pSuper->priv->removeChild(priv);
            priv->superview = nil;
            [self release];
            [layer removeFromSuperlayer];

            priv->_isChangingParent = false;
            [self didMoveToSuperview];

            [self _notifyDidMoveToWindow:nil superview:curSuperview];

            [self autorelease];
        }
    }


    -(void) _removeFromSuperviewNoNotify {
        if ( priv->superview != nil ) {
            [self retain];

            UIWindow* curWindow = [self _getWindowInternal];
            UIView* curSuperview = priv->superview;

            UIView* superview = priv->superview;
            UIView* pSuper = superview;

            pSuper->priv->removeChild(priv);
            priv->superview = nil;
            [self release];
            [layer removeFromSuperlayer];

            [self autorelease];
        }
    }


    -(void) addSubview:(UIView*)subview {
        if ( subview == nil ) {
            EbrDebugLog("subview = nil!\n");
            return;
        }
        if ( subview == self ) {
            EbrDebugLog("subview = self?!\n");
            return;
        }
        if ( ((UIView*) subview)->priv->_isChangingParent ) {
            assert(0);
        }

        //EbrDebugLog("Adding subview %s to %s\n", subview.object_getClassName(), self.object_getClassName());

        UIWindow* subviewWindow = [subview _getWindowInternal];
        UIWindow* curWindow = [self _getWindowInternal];

        if ( [subview superview] != self ) {
            //  Notify the subview it's about to be moved
            if ( subviewWindow != curWindow ) {
                [subview _notifyWillMoveToWindow:curWindow superview:self];
            }
            if ( [subview respondsToSelector:@selector(willMoveToSuperview:)] ) {
                [subview willMoveToSuperview:self];
            }

            //  Remove the view from its superview
            [subview _removeFromSuperviewNoNotify];

            //  Add it to our views
            priv->addChildAfter(subview, nil);
            [subview retain];
            ((UIView *) subview)->priv->superview = self;

            //  Add its layer to our layers
            CALayer* subviewLayer = [subview layer];
            [layer addSublayer:subviewLayer];

            //  Notify the subview it's about to be moved
            if ( subviewWindow != curWindow ) {
                [subview _notifyDidMoveToWindow:curWindow superview:self];
            }
            [subview didMoveToSuperview];
            [UIAppearanceSetter _applyAppearance:subview];

            //  Notify our view it was added
            if ( [self respondsToSelector:@selector(didAddSubview:)] ) {
                [self didAddSubview:subview];
            }

            [subview setNeedsDisplay];
        } else {
            //  Just bring it to the front
            [self bringSubviewToFront:subview];
        }
    }


    -(void) insertSubview:(UIView*)subview atIndex:(int)index {
        if ( !priv->containsChild(subview) ) {
            UIWindow* subviewWindow = [subview _getWindowInternal];
            UIWindow* curWindow = [self _getWindowInternal];

            [subview retain];

            //  Notify the subview it's about to be moved
            if ( [subview respondsToSelector:@selector(willMoveToSuperview:)] ) {
                [subview willMoveToSuperview:self];
            }
            if ( subviewWindow != curWindow ) {
                [subview _notifyWillMoveToWindow:curWindow superview:self];
            }

            //  Remove the view from its superview
            [subview _removeFromSuperviewNoNotify];

            //  Add it to our views
            if ( priv->childCount < index ) {
                index = priv->childCount;
                EbrDebugLog("Warning: Tried to insert subview at bad index\n");
            }
            priv->insertChildAtIndex(subview, index);
            [subview retain];
            ((UIView *) subview)->priv->superview = self;

            //  Add its layer to our layers
            CALayer* subviewLayer = [subview layer];
            [layer insertSublayer:subviewLayer atIndex:index];

            //  Notify the subview it's about to be moved
            [subview didMoveToSuperview];
            [UIAppearanceSetter _applyAppearance:subview];

            if ( subviewWindow != curWindow ) {
                [subview _notifyDidMoveToWindow:curWindow superview:self];
            }

            //  Notify our view it was added
            if ( [self respondsToSelector:@selector(didAddSubview:)] ) {
                [self didAddSubview:subview];
            }

            [subview setNeedsDisplay];
            [subview release];
        }
    }


    -(void) insertSubview:(UIView*)subview belowSubview:(UIView*)belowSubview {
        if ( subview == nil ) {
            EbrDebugLog("Subview = nil!\n");
            return;
        }

        int index = priv->indexOfChild(belowSubview);
        if ( index == 0x7fffffff ) {
            index = 0;

            EbrDebugLog("Sketchy ...\n");
            //assert(0);
        }

        if ( !priv->containsChild(subview) ) {
            UIWindow* subviewWindow = [subview _getWindowInternal];
            UIWindow* curWindow = [self _getWindowInternal];

            [subview retain];

            //  Notify the subview it's about to be moved
            if ( [subview respondsToSelector:@selector(willMoveToSuperview:)] ) {
                [subview willMoveToSuperview:self];
            }
            if ( subviewWindow != curWindow ) {
                [subview _notifyWillMoveToWindow:curWindow superview:self];
            }

            //  Remove the view from its superview
            [subview _removeFromSuperviewNoNotify];

            //  Add it to our views
            priv->insertChildAtIndex(subview, index);
            [subview retain];
            ((UIView *) subview)->priv->superview = self;

            //  Add its layet to our layers
            CALayer* subviewLayer = [subview layer];
            [layer insertSublayer:subviewLayer atIndex:index];

            //  Notify the subview it's about to be moved
            [subview didMoveToSuperview];
            [UIAppearanceSetter _applyAppearance:subview];

            if ( subviewWindow != curWindow ) {
                [subview _notifyDidMoveToWindow:curWindow superview:self];
            }

            //  Notify our view it was added
            if ( [self respondsToSelector:@selector(didAddSubview:)] ) {
                [self didAddSubview:subview];
            }

            [subview setNeedsDisplay];
            [subview release];
        }
    }


    -(void) exchangeSubviewAtIndex:(int)index1 withSubviewAtIndex:(int)index2 {
        UIView* view1 = nil;
        UIView* view2 = nil;

        if ( index1 >= 0 && index1 < priv->childCount ) {
            view1 = priv->childAtIndex(index1)->self;
        }
        if ( index2 >= 0 && index2 < priv->childCount ) {
            view2 = priv->childAtIndex(index2)->self;
        }
        if ( view1 == nil || view2 == nil ) {
            EbrDebugLog("Cannot exchange subviews %d and %d count=%d on view %s (view1=%s view2=%s)\n",
                index1, index2, priv->childCount, object_getClassName(self), view1 ? object_getClassName(view1) : "nil", view2 ? object_getClassName(view2) : "nil");
            return;
        }

        assert(view1 != nil && view2 != nil);
        priv->exchangeChild(view1, view2);

        CALayer* layer1 = [view1 layer];
        CALayer* layer2 = [view2 layer];

        [layer exchangeSublayer:layer1 withLayer:layer2];
    }


    -(void) insertSubview:(UIView*)subview aboveSubview:(UIView*)aboveSubview {
        if ( subview == nil ) {
            EbrDebugLog("insertSubview: subview = nil!\n");
            return;
        }

        UIWindow* subviewWindow = [subview _getWindowInternal];
        UIWindow* curWindow = [self _getWindowInternal];

        int index = priv->indexOfChild(aboveSubview);
        if ( index == 0x7fffffff ) {
            index = -1;

            EbrDebugLog("Sketchy ...\n");
            //assert(0);
        }

        if ( !priv->containsChild(subview) ) {
            UIWindow* subviewWindow = [subview _getWindowInternal];
            UIWindow* curWindow = [self _getWindowInternal];

            [subview retain];

            //  Notify the subview it's about to be moved
            if ( [subview respondsToSelector:@selector(willMoveToSuperview:)] ) {
                [subview willMoveToSuperview:self];
            }
            if ( subviewWindow != curWindow ) {
                [subview _notifyWillMoveToWindow:curWindow superview:self];
            }

            //  Remove the view from its superview
            [subview _removeFromSuperviewNoNotify];

            //  Add it to our views
            priv->insertChildAtIndex(subview, index + 1);
            [subview retain];
            ((UIView *) subview)->priv->superview = self;

            //  Add its layet to our layers
            CALayer* subviewLayer = [subview layer];
            [layer insertSublayer:subviewLayer atIndex:index + 1];

            //  Notify the subview it's about to be moved
            [subview didMoveToSuperview];
            [UIAppearanceSetter _applyAppearance:subview];

            if ( subviewWindow != curWindow ) {
                [subview _notifyDidMoveToWindow:curWindow superview:self];
            }

            //  Notify our view it was added
            if ( [self respondsToSelector:@selector(didAddSubview:)] ) {
                [self didAddSubview:subview];
            }

            [subview setNeedsDisplay];
            [subview release];
        }
    }


    -(void) bringSubviewToFront:(UIView*)subview {
        if ( !priv->containsChild(subview) ) return;

        priv->removeChild(subview);
        priv->addChildAfter(subview, nil);

        [layer bringSublayerToFront:[subview layer]];
    }


    -(void) sendSubviewToBack:(UIView*)subview {
        if ( !priv->containsChild(subview) ) return;

        priv->removeChild(subview);
        priv->addChildBefore(subview, nil);

        [layer sendSublayerToBack:[subview layer]];
    }


    -(void) setContentView:(UIView*)view {
        [self addSubview:view];
    }


    -(void) setContentScaleFactor:(float)factor {
        [layer setContentsScale:factor];
    }


    -(float) contentScaleFactor {
        return [layer contentsScale];
    }


    -(void) orderFront:(UIView*)view {
    }


    -(void) makeKey:(UIView*)view {
        EbrDebugLog("UIVIew::makeKey\n");
    }


    -(void) setHidden:(BOOL)hide {
        [layer setHidden:hide];
    }


    -(BOOL) isHidden {
        return [layer isHidden];
    }


    -(UIView*) superview {
        return priv->superview;
    }


    -(BOOL) pointInside:(CGPoint)point withEvent:(UIEvent*)event {
        CGRect bounds;

        bounds = [layer bounds];

        //  CGPoint is in our coordinate system
        if ( point.x >= bounds.origin.x && point.x < bounds.origin.x + bounds.size.width &&
            point.y >= bounds.origin.y && point.y < bounds.origin.y + bounds.size.height ) {
            return TRUE;
        } else {
            return FALSE;
        }
    }


    -(UIView*) hitTest:(CGPoint)point withEvent:(UIEvent*)event {
        UIWindow* window = [self _getWindowInternal];

        if ( [self isHidden] ) return nil;
        if ( ![self isUserInteractionEnabled] ) return nil;
        if ( [self respondsToSelector:@selector(ignoresMouseEvents)] ) {
            if ( [self ignoresMouseEvents] ) return nil;
        }
        if ( [self alpha] <= 0.01f ) { 
            return nil;
        }

        if ( ![self pointInside:point withEvent:event] ) return nil;

        //EbrDebugLog("HitTest inside %s (0x%08x)\n", object_getClassName(self), self);

        //  Go through subviews backwards until we find the furthest descendant
        int subviewCount = 0;
        UIView* *subviewsCopy = (UIView* *) alloca(sizeof(UIView*) * priv->childCount);
        LLTREE_FOREACH(curSubview, priv) {
            subviewsCopy[subviewCount ++] = curSubview->self;
        }

        int i;
        for ( i = subviewCount - 1; i >= 0; i -- ) {
            UIView* view = subviewsCopy[i];

            if ( [view isHidden] ) continue;
            if ( ![view isUserInteractionEnabled] ) continue;
            if ( [view alpha] <= 0.01f ) {
                float ret = [view alpha];
                continue;
            }

            CGPoint newPoint;

            newPoint = [window convertPoint:point fromView:self toView:view];
            //EbrDebugLog("Point inside %s %d, %d?\n", object_getClassName(view), (int) newPoint.x, (int) newPoint.y);
            if ( [view pointInside:newPoint withEvent:event] ) {
                UIView* ret = [view hitTest:newPoint withEvent:event];
                if ( ret != nil ) return ret;
            }
        }

        return self;
    }


    -(CGRect) convertRect:(CGRect)pos toView:(UIView*)toView {
        CGRect ret;

        UIWindow* ourWindow = [self _getWindowInternal];

        if ( ourWindow == nil ) {
            ret.origin.x = pos.origin.x;
            ret.origin.y = pos.origin.y;
            ret.size = pos.size;
            return ret;
        }

        if ( toView == nil ) toView = ourWindow;

        CGPoint pt1 = pos.origin;
        CGPoint pt2;

        pt2 = pos.origin;
        pt2.x += pos.size.width;
        pt2.y += pos.size.height;

        pt1 = [ourWindow convertPoint:pt1 fromView:self toView:toView];
        pt2 = [ourWindow convertPoint:pt2 fromView:self toView:toView];

        ret.origin.x = pt1.x < pt2.x ? pt1.x : pt2.x;
        ret.origin.y = pt1.y < pt2.y ? pt1.y : pt2.y;
        ret.size.width = fabsf(pt1.x - pt2.x);
        ret.size.height = fabsf(pt1.y - pt2.y);

        return ret;
    }


    -(CGRect) convertRect:(CGRect)pos fromView:(UIView*)fromView {
        CGRect ret;

        UIWindow* ourWindow = [self _getWindowInternal];

        if ( ourWindow == nil ) {
            ret.origin.x = pos.origin.x;
            ret.origin.y = pos.origin.y;
            ret.size = pos.size;
            return ret;
        }

        if ( fromView == nil ) fromView = ourWindow;

        CGPoint pt1 = pos.origin;
        CGPoint pt2;

        pt2 = pos.origin;
        pt2.x += pos.size.width;
        pt2.y += pos.size.height;

        pt1 = [ourWindow convertPoint:pt1 fromView:fromView toView:self];
        pt2 = [ourWindow convertPoint:pt2 fromView:fromView toView:self];

        ret.origin.x = pt1.x < pt2.x ? pt1.x : pt2.x;
        ret.origin.y = pt1.y < pt2.y ? pt1.y : pt2.y;
        ret.size.width = fabsf(pt1.x - pt2.x);
        ret.size.height = fabsf(pt1.y - pt2.y);

        return ret;
    }


    -(CGPoint) convertPoint:(CGPoint)pos toView:(UIView*)toView {
        CGPoint ret;

        UIWindow* ourWindow = [self _getWindowInternal];
        if ( ourWindow == nil ) {
            return pos;
        }

        if ( toView == nil ) toView = ourWindow;

        ret = [ourWindow convertPoint:pos fromView:self toView:toView];

        return ret;
    }


    -(CGPoint) convertPoint:(CGPoint)pos fromView:(UIView*)fromView {
        CGPoint ret;

        UIWindow* ourWindow = [self _getWindowInternal];
        if ( ourWindow == nil ) {
            return pos;
        }

        if ( fromView == nil ) fromView = ourWindow;

        ret = [ourWindow convertPoint:pos fromView:fromView toView:self];

        return ret;
    }


    -(void) drawLayer:(CALayer*)layer inContext:(CGContextRef)context {
        UIGraphicsPushContext(context);

        CGRect bounds;
        //bounds = [layer bounds];
        bounds = CGContextGetClipBoundingBox(context);
        [self drawRect:bounds];

        UIGraphicsPopContext();
    }


    -(void) setTapDelegate:(id)delegateAddr {
    }


    -(void) setGestureDelegate:(id)delegateAddr {
    }


    -(CALayer*) layer {
        return layer;
    }


    -(void) setNeedsDisplay {
        [layer setNeedsDisplay];
    }


    -(void) setNeedsDisplayInRect:(CGRect)rc {
        [layer setNeedsDisplay];
    }


    -(UIWindow*) window {
        return [self _getWindowInternal];
    }


    -(UIWindow*) _getWindowInternal {
        if ( !priv ) {
            EbrDebugLog("priv = NULL!\n");
            return nil;
        }

        if ( priv->superview == 0 ) return nil;

        return [priv->superview _getWindowInternal];
    }


    -(void) setMultipleTouchEnabled:(BOOL)enabled {
        if ( !priv ) {
            EbrDebugLog("Priv is null, should alloc priv in alloc\n");
            return;
        }

        priv->multipleTouchEnabled = enabled;
    }


    +(id) layerClass {
        return [CALayer class];
    }


    -(void) setAlpha:(float)alpha {
        [layer setOpacity:alpha];
    }


    -(float) alpha {
        return [layer opacity];
    }


    -(void) setTransform:(CGAffineTransform)transform {
        [layer setAffineTransform:transform];
    }


    -(void) setRotationBy:(float)degrees {
        assert(0);
    }


    -(void) setClearsContextBeforeDrawing:(BOOL)clear {
    }


    -(void) setBackgroundColor:(UIColor*)color {
        if ( color != nil ) {
            priv->backgroundColor = color;
        } else {
            priv->backgroundColor = nil;
        }
        [layer setBackgroundColor:[(UIColor*) priv->backgroundColor CGColor]];
    }


    -(UIColor*) backgroundColor {
        return priv->backgroundColor;
    }


    -(void) setUserInteractionEnabled:(BOOL)enabled {
        priv->userInteractionEnabled = enabled;
    }


    -(void) setTag:(int)newTag {
        priv->tag = newTag;
    }


    -(int) tag {
        return priv->tag;
    }


    -(BOOL) isUserInteractionEnabled {
        return priv->userInteractionEnabled;
    }


    -(BOOL) isMultipleTouchEnabled {
        return priv->multipleTouchEnabled;
    }


    -(UIViewContentMode) contentMode {
        return priv->contentMode;
    }


    -(void) setContentMode:(UIViewContentMode)mode {
        priv->contentMode = mode;

        //  Top/bottom switched due to geometric origin of CALayer

        switch ( mode ) {
            case UIViewContentModeScaleToFill:
                [layer setContentsGravity: kCAGravityResize];
                break;

            case UIViewContentModeCenter:
                [layer setContentsGravity: kCAGravityCenter];
                break;

            case UIViewContentModeTop:
                [layer setContentsGravity: kCAGravityBottom];
                break;

            case UIViewContentModeScaleAspectFit:
                [layer setContentsGravity: kCAGravityResizeAspect];
                break;

            case UIViewContentModeTopLeft:
                [layer setContentsGravity: kCAGravityBottomLeft];
                break;

            case UIViewContentModeTopRight:
                [layer setContentsGravity: kCAGravityBottomRight];
                break;

            case UIViewContentModeBottomLeft:
                [layer setContentsGravity: kCAGravityTopLeft];
                break;

            case UIViewContentModeLeft:
                [layer setContentsGravity: kCAGravityLeft];
                break;

            case UIViewContentModeScaleAspectFill:
                [layer setContentsGravity: kCAGravityResizeAspectFill];
                break;

            case UIViewContentModeBottom:
                [layer setContentsGravity: kCAGravityTop];
                break;

            case UIViewContentModeBottomRight:
                [layer setContentsGravity: kCAGravityTopRight];
                break;

            case UIViewContentModeRight:
                [layer setContentsGravity: kCAGravityRight];
                break;

            case UIViewContentModeRedraw:
                [layer setNeedsDisplayOnBoundsChange:TRUE];
                break;

            default:
                assert(0);
        }
    }


    /* annotate with type */ -(void) setContentStretch:(CGRect)stretch {
        [layer setContentsCenter:stretch];
    }


    /* annotate with type */ -(void) setOpaque:(BOOL)opaque {
        [layer setOpaque:opaque];
    }


    -(BOOL) isOpaque {
        BOOL ret = [layer isOpaque];

        return ret;
    }


    -(void) setAutoresizingMask:(UIViewAutoresizing)mask {
        priv->autoresizingMask = mask;
    }


    -(UIViewAutoresizing) autoresizingMask {
        return priv->autoresizingMask;
    }


    -(void) setAutoresizesSubviews:(BOOL)autoresize {
        priv->autoresizesSubviews = autoresize;
    }


    -(void) setTranslatesAutoresizingMaskIntoConstraints:(BOOL)translate {
        EbrDebugLog("setTranslatesAutoresizingMaskIntoConstraints(%d) not supported\n", (int)translate);
    }


    -(NSArray*) constraints {
        return priv->constraints;
    }


    -(void) addConstraint:(id)constraint {
        if([priv->constraints containsObject:constraint]) {
            return;
        }

        [priv->constraints addObject:constraint];
        NSLayoutConstraint* layoutConstraint = constraint;

#if defined( USE_CASSOWARY )
        assert(layoutConstraint->_items[0]);
        assert([layoutConstraint->_items[0] isKindOfClass:[UIView class]]);
        if(layoutConstraint->_items[1]) assert([layoutConstraint->_items[1] isKindOfClass:[UIView class]]);

        if(!layoutConstraint->priv->_constraint) {
            // TODO: Care about reading direction.
            ClLinearExpression *lex[2];
            memset(lex, 0, sizeof(lex));
            for(int n = 0; n < 2; n++) {
                UIView* item = layoutConstraint->_items[n];
                int attribute = layoutConstraint->_attributes[n];

                if(layoutConstraint->_items[n] == nil) {
                    lex[n] = new ClLinearExpression(0.0);
                    continue;
                }

                item->priv->layoutProperties->_inSolution = true;

                switch(attribute) {
                case NSLayoutAttributeWidth:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Right]-*item->priv->layoutProperties->_vars[AutoLayoutProperties::Left]);
                    break;
                case NSLayoutAttributeHeight:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]-*item->priv->layoutProperties->_vars[AutoLayoutProperties::Top]);
                    break;
                case NSLayoutAttributeCenterX:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Right]*0.5+*item->priv->layoutProperties->_vars[AutoLayoutProperties::Left]*0.5);
                    break;
                case NSLayoutAttributeCenterY:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]*0.5+*item->priv->layoutProperties->_vars[AutoLayoutProperties::Top]*0.5);
                    break;
                case NSLayoutAttributeLeading:
                case NSLayoutAttributeLeft:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Left]);
                    break;
                case NSLayoutAttributeTrailing:
                case NSLayoutAttributeRight:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Right]);
                    break;
                case NSLayoutAttributeTop:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Top]);
                    break;
                case NSLayoutAttributeBaseline:
                    {
                        UIView* baseline = [item viewForBaselineLayout];
                        if(baseline->priv->layoutProperties->_constrained || (id)item == (id)baseline) {
                            lex[n] = new ClLinearExpression(*baseline->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]);
                        } else {
                            CGRect baselineFrame;
                            CGRect itemFrame;
                            baselineFrame = [baseline frame];
                            itemFrame = [item frame];
                            baselineFrame.origin.y += baselineFrame.size.height;
                            lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom] - 6); // TODO: This is fudged.
                        }
                    }
                    break;
                case NSLayoutAttributeBottom:
                    lex[n] = new ClLinearExpression(*item->priv->layoutProperties->_vars[AutoLayoutProperties::Bottom]);
                    break;
                default:
                    assert(0);
                    break;
                }
            }

            ClStrength strength(layoutConstraint->_priority >= NSLayoutPriorityRequired ? ClsRequired() : ClsWeak());
            float constant = layoutConstraint->_constant;
            UIView* item1 = layoutConstraint->_items[0];
            UIView* item2 = layoutConstraint->_items[1];

            if((id)item2 != nil) {
                if(item1->priv->superview == item2->priv->superview) {
                    // Siblings shouldn't set stays.
                    item1->priv->layoutProperties->_constrained = true;
                } else if(item2->priv->superview == item1) {
                    item2->priv->layoutProperties->_constrained = true;
                } else if(item1->priv->superview == item2) {
                    item1->priv->layoutProperties->_constrained = true;
                } else {
                    EbrDebugLog("Constraint set between items that don't share a direct relationship. This might be an error.\n");
                }
            }

            if(layoutConstraint->_autoSpacing && item2 != nil &&
              (layoutConstraint->_attributes[0] >= NSLayoutAttributeLeft && layoutConstraint->_attributes[0] <= NSLayoutAttributeTrailing)) {
                if(item1->priv->superview == item2->priv->superview) {
                    if(layoutConstraint->_attributes[0] != layoutConstraint->_attributes[1]) {
                        constant = 8.0f;
                    }
                } else {
                    constant = 20.0f;
                }
            }

            if(!lex[1]) {
                lex[1] = new ClLinearExpression(constant);
            } else {
                *lex[1] = lex[1]->MultiplyMe(layoutConstraint->_multiplier).Plus(constant);
            }

            switch(layoutConstraint->_relation) {
            case NSLayoutRelationEqual:
                layoutConstraint->priv->_constraint = new ClLinearEquation(*lex[0], *lex[1], strength, layoutConstraint->_priority);
                break;
            case NSLayoutRelationGreaterThanOrEqual:
                layoutConstraint->priv->_constraint = new ClLinearInequality(*lex[0], cnGEQ, *lex[1], strength, layoutConstraint->_priority);
                break;
            case NSLayoutRelationLessThanOrEqual:
                layoutConstraint->priv->_constraint = new ClLinearInequality(*lex[0], cnLEQ, *lex[1], strength, layoutConstraint->_priority);
                break;
            default:
                assert(0);
            }

            solver.AddConstraint(layoutConstraint->priv->_constraint);

            delete lex[0];
            delete lex[1];
        }
#endif
    }


    -(void) removeConstraint:(id)constraint {
#if defined( USE_CASSOWARY )
        NSLayoutConstraint* layoutConstraint = constraint;
        if(layoutConstraint->priv->_constraint) {
            solver.RemoveConstraint(layoutConstraint->priv->_constraint);
            delete layoutConstraint->priv->_constraint;
            layoutConstraint->priv->_constraint = NULL;
        }
#endif
        [priv->constraints removeObject:constraint];
    }


    -(void) addConstraints:(id)constraints {
        EbrDebugLog("addConstraints not supported\n");
    }


    -(void) removeConstraints:(id)constraints {
        EbrDebugLog("removeConstraints not supported\n");
    }


    -(void) updateConstraints {
        for(int i = 0; i < priv->childCount; i++) {
            [priv->childAtIndex(i)->self updateConstraints];
        }

#if defined( USE_CASSOWARY )
        if(priv->layoutProperties->_inSolution) {
            CGRect bounds;
            CGSize contentSize;
            bounds = [self bounds];
            contentSize = [self intrinsicContentSize];
            if(contentSize.width == UIViewNoIntrinsicMetric) {
                if(priv->layoutProperties->_contentHuggingConstraint[0]) {
                    solver.RemoveConstraint(priv->layoutProperties->_contentHuggingConstraint[0]);
                    delete priv->layoutProperties->_contentHuggingConstraint[0];
                    priv->layoutProperties->_contentHuggingConstraint[0] = NULL;
                    solver.RemoveConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[0]);
                    delete priv->layoutProperties->_contentCompressionResistanceConstraint[0];
                    priv->layoutProperties->_contentCompressionResistanceConstraint[0] = NULL;
                }
            } else {
                if(priv->layoutProperties->_contentHuggingConstraint[0] && contentSize.width != priv->layoutProperties->_contentHuggingConstraint[0]->Expression().Constant()) {
                    solver.RemoveConstraint(priv->layoutProperties->_contentHuggingConstraint[0]);
                    delete priv->layoutProperties->_contentHuggingConstraint[0];
                    priv->layoutProperties->_contentHuggingConstraint[0] = NULL;
                    solver.RemoveConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[0]);
                    delete priv->layoutProperties->_contentCompressionResistanceConstraint[0];
                    priv->layoutProperties->_contentCompressionResistanceConstraint[0] = NULL;
                }
                if(!priv->layoutProperties->_contentHuggingConstraint[0]) {
                    priv->layoutProperties->_contentHuggingConstraint[0] = 
                        new ClLinearInequality(*priv->layoutProperties->_vars[AutoLayoutProperties::Right] - *priv->layoutProperties->_vars[AutoLayoutProperties::Left],
                            cnLEQ, contentSize.width, ClsWeak(), priv->layoutProperties->_contentHuggingPriority.width);
                    priv->layoutProperties->_contentCompressionResistanceConstraint[0] = 
                        new ClLinearInequality(*priv->layoutProperties->_vars[AutoLayoutProperties::Right] - *priv->layoutProperties->_vars[AutoLayoutProperties::Left],
                            cnGEQ, contentSize.width, ClsWeak(), priv->layoutProperties->_contentCompressionResistancePriority.width);
                    solver.AddConstraint(priv->layoutProperties->_contentHuggingConstraint[0]);
                    solver.AddConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[0]);
                }
            }
            if(contentSize.height == UIViewNoIntrinsicMetric) {
                if(priv->layoutProperties->_contentHuggingConstraint[1]) {
                    solver.RemoveConstraint(priv->layoutProperties->_contentHuggingConstraint[1]);
                    delete priv->layoutProperties->_contentHuggingConstraint[1];
                    priv->layoutProperties->_contentHuggingConstraint[1] = NULL;
                    solver.RemoveConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[1]);
                    delete priv->layoutProperties->_contentCompressionResistanceConstraint[1];
                    priv->layoutProperties->_contentCompressionResistanceConstraint[1] = NULL;
                }
            } else {
                if(priv->layoutProperties->_contentHuggingConstraint[1] && contentSize.height != priv->layoutProperties->_contentHuggingConstraint[1]->Expression().Constant()) {
                    solver.RemoveConstraint(priv->layoutProperties->_contentHuggingConstraint[1]);
                    delete priv->layoutProperties->_contentHuggingConstraint[1];
                    priv->layoutProperties->_contentHuggingConstraint[1] = NULL;
                    solver.RemoveConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[1]);
                    delete priv->layoutProperties->_contentCompressionResistanceConstraint[1];
                    priv->layoutProperties->_contentCompressionResistanceConstraint[1] = NULL;
                }
                if(!priv->layoutProperties->_contentHuggingConstraint[1]) {
                    priv->layoutProperties->_contentHuggingConstraint[1] = 
                        new ClLinearInequality(*priv->layoutProperties->_vars[AutoLayoutProperties::Bottom] - *priv->layoutProperties->_vars[AutoLayoutProperties::Top],
                            cnLEQ, contentSize.height, ClsWeak(), priv->layoutProperties->_contentHuggingPriority.height);
                    priv->layoutProperties->_contentCompressionResistanceConstraint[1] = 
                        new ClLinearInequality(*priv->layoutProperties->_vars[AutoLayoutProperties::Bottom] - *priv->layoutProperties->_vars[AutoLayoutProperties::Top],
                            cnGEQ, contentSize.height, ClsWeak(), priv->layoutProperties->_contentCompressionResistancePriority.height);
                    solver.AddConstraint(priv->layoutProperties->_contentHuggingConstraint[1]);
                    solver.AddConstraint(priv->layoutProperties->_contentCompressionResistanceConstraint[1]);
                }
            }

            if(!priv->layoutProperties->_constrained) {
                priv->layoutProperties->AddStays();

                for(int i = 0; i < 4; i++) {
                    solver.AddEditVar(*priv->layoutProperties->_vars[i]);
                }

                solver.BeginEdit();
                solver.SuggestValue(*priv->layoutProperties->_vars[AutoLayoutProperties::Right], bounds.size.width);
                solver.SuggestValue(*priv->layoutProperties->_vars[AutoLayoutProperties::Bottom], bounds.size.height);
                solver.SuggestValue(*priv->layoutProperties->_vars[AutoLayoutProperties::Left], 0);
                solver.SuggestValue(*priv->layoutProperties->_vars[AutoLayoutProperties::Top], 0);
                solver.Resolve();
                solver.EndEdit(); // Removes edit variables btw.
            }
        }
#endif
    }


    -(UIView*) viewWithTag:(int)tag {
        if ( priv->tag == tag ) {
            return self;
        }

        LLTREE_FOREACH(curView, priv) {
            id ret = [curView->self viewWithTag:tag];
            if ( ret != nil ) {
                return ret;
            }
        }

        return nil;
    }


    -(UIResponder*) nextResponder {
        UIViewController* controller = [UIViewController controllerForView:self];

        if ( controller ) {
            return controller;
        }

        return priv->superview;
    }


    -(void) touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
        UIResponder* nextResponder = [self nextResponder];

        if ( nextResponder != nil ) {
            [nextResponder touchesBegan:touches withEvent:event];
        }
    }


    -(void) touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
        EbrDebugLog("Clicked: %s\n", object_getClassName(self));
        UIResponder* nextResponder = [self nextResponder];

        if ( nextResponder != nil ) {
            [nextResponder touchesMoved:touches withEvent:event];
        }
    }


    -(void) touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
        UIResponder* nextResponder = [self nextResponder];

        if ( nextResponder != nil ) {
            [nextResponder touchesEnded:touches withEvent:event];
        }
    }


    -(void) touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
        UIResponder* nextResponder = [self nextResponder];

        if ( nextResponder != nil ) {
            [nextResponder touchesCancelled:touches withEvent:event];
        }
    }


    -(void) setClipsToBounds:(BOOL)clip {
        [layer setMasksToBounds:clip];
    }


    -(void) setExclusiveTouch:(BOOL)isExclusive {
        EbrDebugLog("setExclusiveTouch not supported\n");
        //assert(0);
    }


    -(id<CAAction>) actionForLayer:(CALayer*)layer forKey:(NSString*)key {
        if ( stackLevel > 0 && g_animationsDisabled == 0 && g_nestedAnimationsDisabled == 0 ) {
            char *keyName = (char *) [key UTF8String];
            if ( strcmp(keyName, "opacity") == 0 ||
                 strcmp(keyName, "position") == 0 ||
                 strcmp(keyName, "bounds") == 0 ||
                 strcmp(keyName, "bounds.origin") == 0 ||
                 strcmp(keyName, "bounds.size") == 0 ||
                 strcmp(keyName, "transform") == 0 ) {
                CABasicAnimation* ret = [CABasicAnimation animationWithKeyPath:key];

                if ( _animationProperties[stackLevel]._beginsFromCurrentState && strcmp(keyName, "opacity") != 0 ) {
                    NSObject *fromValue = [layer presentationValueForKey:key];
                    [ret setFromValue: fromValue];
                } else {
                    id fromValue = [layer valueForKey:key];
                    [ret setFromValue:fromValue];
                }
                if ( _animationProperties[stackLevel]._animationCurve != nil ) {
                    [ret setTimingFunction:_animationProperties[stackLevel]._animationCurve];
                }
                [ret setDuration:_animationProperties[stackLevel]._animationDuration];
                [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
                [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
                [ret setDelay:_animationProperties[stackLevel]._animationDelay];
                [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];
                _animationProperties[stackLevel]._numAnimations ++;

                return ret;
            }
        }

        return (id<CAAction>) [NSNull null];
    }


    +(void) animateWithDuration:(double)duration animations:(animationBlockFunc)animationBlock {
        [self beginAnimations:nil context:0];
        [self setAnimationDuration:duration];
        [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
        CALLBLOCK(animationBlock);

        [self commitAnimations];
    }


    +(void) transitionFromView:(UIView*)fromView toView:(UIView*)toView duration:(double)duration options:(uint32_t)options completion:(completionBlockFunc)completion {
        [self beginAnimations:nil context:0];
        _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
        [self setAnimationDuration:duration];
        [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
        [self setAnimationTransition:UIViewAnimationTransitionFlipFromLeft forView:toView cache:FALSE];

        id superview = [fromView superview];
        [fromView removeFromSuperview];
        [superview addSubview:toView];
        [self commitAnimations];
    }


    +(void) transitionWithView:(id)view duration:(double)duration options:(unsigned)options animations:(animationBlockFunc)animationBlock completion:(completionBlockFunc)completion {
        [self beginAnimations:nil context:0];
        _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
        [self setAnimationDuration:duration];
        [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
        [self setAnimationTransition:UIViewAnimationTransitionFlipFromLeft forView:view cache:FALSE];
        CALLBLOCK(animationBlock);

        [self commitAnimations];
    }


    +(void) animateWithDuration:(double)duration animations:(animationBlockFunc)animationBlock completion:(completionBlockFunc)completion {
        EbrDebugLog("animationWithDurationCompletion not supported\n");
        [self beginAnimations:nil context:0];
        _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
        [self setAnimationDuration:duration];
        [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
        CALLBLOCK(animationBlock);
        [self commitAnimations];
        //EbrCall(E2H(completion)[3], "dd", completion, TRUE);
    }


    +(void) animateWithDuration:(double)duration delay:(double)delay options:(unsigned)options animations:(animationBlockFunc)animationBlock completion:(completionBlockFunc)completion {
        EbrDebugLog("animateWithDurationDelayCompletion not supported\n");
        [self beginAnimations:nil context:0];
        _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
        [self setAnimationDuration:duration];
        [self setAnimationDelay:delay];
        [self setAnimationCurve:UIViewAnimationCurveEaseInOut];

        if ( options & UIViewAnimationOptionBeginFromCurrentState ) {
            [self setAnimationBeginsFromCurrentState:TRUE];
        }
        if ( options & UIViewAnimationOptionAutoreverse ) {
            [self setAnimationRepeatAutoreverses:TRUE];
        }
        if ( options & UIViewAnimationOptionCurveLinear ) {
            [self setAnimationCurve:UIViewAnimationCurveLinear];
        }

        CALLBLOCK(animationBlock);
        [self commitAnimations];
        //EbrCall(E2H(completion)[3], "dd", completion, TRUE);
    }


    +(void) beginAnimations:(id)animationID context:(void *)context {
        stackLevel ++;
        assert(stackLevel < 32);

        _animationProperties[stackLevel]._numAnimations = 0;
        _animationProperties[stackLevel]._animationDuration = 0.2f;
        _animationProperties[stackLevel]._animationDelay = 0.0f;
        _animationProperties[stackLevel]._animationID = animationID;
        _animationProperties[stackLevel]._context = context;
        _animationProperties[stackLevel]._repeatCount = 0.0f;
        _animationProperties[stackLevel]._autoReverses = FALSE;
        _animationProperties[stackLevel]._beginsFromCurrentState = FALSE;
        _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"];
        _animationProperties[stackLevel]._animationWillStartSelector = NULL;
        _animationProperties[stackLevel]._animationDidStopSelector = NULL;
        _animationProperties[stackLevel]._animationDelegate = nil;
        _animationProperties[stackLevel]._animationNotifier = [UIAnimationNotification alloc];
        [_animationProperties[stackLevel]._animationNotifier autorelease];
        _animationProperties[stackLevel]._completionBlock = nil;
    }


    +(void) setAnimationCurve:(UIViewAnimationCurve)curve {
        switch ( curve ) {
            case UIViewAnimationCurveEaseInOut:
                _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"];
                break;

            case UIViewAnimationCurveEaseIn:
                _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseIn"];
                break;

            case UIViewAnimationCurveEaseOut:
                _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseOut"];
                break;

            case UIViewAnimationCurveLinear:
                _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionLinear"];
                break;

            default:
                assert(0);
                break;
        }       
    }


    +(void) setAnimationRepeatAutoreverses:(BOOL)autoReverses {
        _animationProperties[stackLevel]._autoReverses = autoReverses;
    }


    +(void) setAnimationRepeatCount:(float)count {
        _animationProperties[stackLevel]._repeatCount = count;
    }


    +(void) setAnimationDuration:(double)duration {
        _animationProperties[stackLevel]._animationDuration = duration;
    }


    +(double) _getAnimationDuration {
        if ( stackLevel > 0 ) {
            return _animationProperties[stackLevel]._animationDuration;
        } else {
            return 0.0;
        }
    }


    +(void) setAnimationDelay:(double)delay {
        _animationProperties[stackLevel]._animationDelay = delay;
    }


    +(void) setAnimationDelegate:(id)delegate {
        _animationProperties[stackLevel]._animationDelegate = delegate;
    }


    +(void) setAnimationsEnabled:(BOOL)enable {
        g_animationsDisabled = !enable;
    }


    +(void) _setNestedAnimationsEnabled:(BOOL)enable {
        if ( enable ) {
            CONTINUE_ANIMATIONS();
        } else {
            PAUSE_ANIMATIONS();
        }
    }


    +(BOOL) animationsEnabled {
        return (g_animationsDisabled == 0) && (g_nestedAnimationsDisabled == 0);
    }


    +(BOOL) areAnimationsEnabled {
        return [self areAnimationsEnabled];
    }


    +(void) setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView*)view cache:(BOOL)cache {
        if ( stackLevel > 0 && transition != UIViewAnimationTransitionNone ) {
            _animationProperties[stackLevel]._numAnimations ++;
            CABasicAnimation* ret = [CATransition animation];
            [ret setDuration:_animationProperties[stackLevel]._animationDuration];
            [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
            [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
            [ret setDelay:_animationProperties[stackLevel]._animationDelay];
            [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];

            switch ( transition ) {
                case UIViewAnimationTransitionFlipFromLeft:
                    [ret setType:@"kCATransitionFlip"];
                    [ret setSubtype:@"kCATransitionFromLeft"];
                    break;

                case UIViewAnimationTransitionFlipFromRight:
                    [ret setType:@"kCATransitionFlip"];
                    [ret setSubtype:@"kCATransitionFromRight"];
                    break;

                default:
                    [ret setType:@"kCATransitionPush"];
                    [ret setSubtype:@"kCATransitionFromLeft"];
                    break;
            }

            [[view layer] addAnimation:ret forKey:@"transition"];
        }

    }


    +(void) _setPageTransitionForView:(UIView*)view fromLeft:(BOOL)fromLeft {
        if ( stackLevel > 0 ) {
            _animationProperties[stackLevel]._numAnimations ++;
            id ret = [CATransition animation];
            [ret setDuration:_animationProperties[stackLevel]._animationDuration];
            [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
            [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
            [ret setDelay:_animationProperties[stackLevel]._animationDelay];
            [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];
            [ret setType:@"kCATransitionPush"];

            [ret setSubtype:fromLeft ? @"kCATransitionFromLeft" : @"kCATransitionFromRight"];
            [[view layer] addAnimation:ret forKey:@"transition"];
        }
    }


    +(void) setAnimationBeginsFromCurrentState:(BOOL)curState {
        _animationProperties[stackLevel]._beginsFromCurrentState = curState;
    }


    +(void) setAnimationDidStopSelector:(SEL)selector {
        _animationProperties[stackLevel]._animationDidStopSelector = selector;
    }


    +(void) setAnimationWillStartSelector:(SEL)selector {
        _animationProperties[stackLevel]._animationWillStartSelector = selector;
    }


    +(void) commitAnimations {
        if (stackLevel <= 0) {
            EbrDebugLog("UIView: No animations stacked!\n");
            return;
        }

        if ( _animationProperties[stackLevel]._numAnimations > 0 ) {
            _animationProperties[stackLevel]._animationNotifier->_numAnimations = _animationProperties[stackLevel]._numAnimations;
            _animationProperties[stackLevel]._animationNotifier->_numStarted = 0;
            _animationProperties[stackLevel]._animationNotifier->_numStopped = 0;
            _animationProperties[stackLevel]._animationNotifier->_animationDidStopSelector = _animationProperties[stackLevel]._animationDidStopSelector;
            _animationProperties[stackLevel]._animationNotifier->_animationWillStartSelector = _animationProperties[stackLevel]._animationWillStartSelector;
            _animationProperties[stackLevel]._animationNotifier->_animDelegate = [_animationProperties[stackLevel]._animationDelegate retain];
            _animationProperties[stackLevel]._animationNotifier->_context = _animationProperties[stackLevel]._context;
            _animationProperties[stackLevel]._animationNotifier->_animName = [_animationProperties[stackLevel]._animationID copy];
            _animationProperties[stackLevel]._animationNotifier->_completionBlock = _animationProperties[stackLevel]._completionBlock;
        } else {
            sendDidStop(_animationProperties[stackLevel]._animationDelegate, _animationProperties[stackLevel]._animationDidStopSelector,
                _animationProperties[stackLevel]._animationID, TRUE, _animationProperties[stackLevel]._context);
            if ( _animationProperties[stackLevel]._completionBlock != nil ) {
                //EbrDebugLog("Calling completion block %x\n", E2H(_animationProperties[stackLevel]._completionBlock)[3]);
                CALLCOMPLETIONBLOCK(_animationProperties[stackLevel]._completionBlock, TRUE);
                [_animationProperties[stackLevel]._completionBlock release];
            }
        } 

        stackLevel --;
    }


    -(void) willMoveToWindow:(UIWindow*)window {
    }


    -(BOOL) isDescendantOfView:(UIView*)view {
        id curView = self;
        while ( curView != nil ) {
            if ( curView == view ) {
                return TRUE;
            }
            curView = [curView superview];
        }
        return FALSE;
    }


    -(void) awakeFromNib {
    }


    -(void) didMoveToWindow {
        [super didMoveToWindow];
    }


    -(void) didMoveToSuperview {
    }


    -(CGSize) sizeThatFits:(CGSize)curSize {
        CGRect curBounds;
        curBounds = [self bounds];
        return curBounds.size;
    }


    -(void) sizeToFit {
        CGRect curSize;

        //  Get current size
        curSize = [self frame];

        //  Get preferred size
        curSize.size = [self sizeThatFits:curSize.size];
        [self setFrame:curSize];
    }


    -(void) dealloc {
        if ( _deallocating ) return;
        _deallocating = true;
        viewCount --;
        EbrDebugLog("%d: dealloc %s %x\n", viewCount, object_getClassName(self), self);

        [self removeFromSuperview];
        priv->backgroundColor = nil;
        priv->constraints = nil;
        int subviewCount = 0;
        id *subviewsCopy = (id *) alloca(sizeof(id) * priv->childCount);
        LLTREE_FOREACH(curView, priv) {
            subviewsCopy[subviewCount] = curView->self;
            [subviewsCopy[subviewCount] retain];
            subviewCount ++;
        }

        for ( int i = 0; i < subviewCount; i ++ ) {
            [subviewsCopy[i] removeFromSuperview];
            [subviewsCopy[i] release];
        }

        for (UIGestureRecognizer* curgesture in priv->gestures) {
            if ( [curgesture respondsToSelector:@selector(_setView:)] ) {
                [curgesture _setView:nil];
            }
        }
        [priv->gestures release];
        [priv->currentTouches release];
        layer = nil;

#if defined( USE_CASSOWARY )
        delete priv->layoutProperties;
#endif
        delete priv;

        [super dealloc];
    }


    -(BOOL) endEditing:(BOOL)force {
        for (UIView* child in [self subviews]) {
            if ( [child isKindOfClass:[UITextField class]] ) {
                if ( [child isFirstResponder] ) {
                    [child resignFirstResponder];
                    return TRUE;
                }
            } else {
                if ( [child endEditing:force] ) {
                    return TRUE;
                }
            }
        }
        return FALSE;
    }


    -(void) drawRect:(CGRect)pos {
    }


    -(void) setAccessibilityLabel:(NSString*)label {
    }


    -(void) setAccessibilityHint:(NSString*)hint {
    }


    -(void) setAccessibilityTraits:(UIAccessibilityTraits)traits {
    }       


    -(void) setAccessibilityViewIsModal:(BOOL)modal {
    }       


    -(void) setIsAccessibilityElement:(BOOL)enabled {
    }


    -(void) addGestureRecognizer:(UIGestureRecognizer*)gesture {
        [priv->gestures addObject:gesture];
        [gesture _setView:self];
    }


    -(void) removeGestureRecognizer:(UIGestureRecognizer*)gesture {
        [priv->gestures removeObject:gesture];
        [gesture _setView:nil];
    }


    -(void) setGestureRecognizers:(NSArray*)gestures {
        for (UIGestureRecognizer* curgesture in priv->gestures) {
            if ( [curgesture isKindOfClass:[UIGestureRecognizer class]] ) {
                [curgesture _setView:nil];
            }
        }

        gestures = [gestures copy];
        [priv->gestures release];
        priv->gestures = gestures;

        for (UIGestureRecognizer* curgesture in priv->gestures) {
            if ( [curgesture isKindOfClass:[UIGestureRecognizer class]] ) {
                [curgesture _setView:self];
            } else {
                EbrDebugLog("UIView: object %s is not a gesture!\n", object_getClassName(curgesture));
            }
        }
    }


    -(NSArray*) gestureRecognizers {
        return priv->gestures;
    }


    +(UIAppearanceSetter*) appearance {
        return [UIAppearanceSetter appearanceWhenContainedIn:nil forUIClass:self];
    }

    +(UIAppearanceSetter*) appearanceWhenContainedIn:(id)containedClass , ...{
        id curClass = [self class];
    
        va_list pReader; va_start(pReader, containedClass);

        id curVal = va_arg(pReader, id);

        while ( curVal  != nil ) {
            assert(0);
            curVal = va_arg(pReader, id);
        }

        va_end(pReader);

        return [UIAppearanceSetter appearanceWhenContainedIn:containedClass forUIClass:self];
    }


    -(void) setBackButtonDelegate:(id)delegate action:(SEL)action withParam:(id)param {
        _backButtonDelegate = delegate;
        _backButtonSelector = action;
        _backButtonArg = param;
    }


    -(void) setBackButtonReturnsSuccess:(BOOL)returnsSuccess {
        _backButtonReturnsSuccess = returnsSuccess;
    }


    -(void) setBackButtonPriority:(int)priority {
        _backButtonPriority = priority;
    }


    -(void) setEnabled:(BOOL)enabled {
        [self setUserInteractionEnabled:enabled];
    }


    -(BOOL) isEnabled {
        return [self isUserInteractionEnabled];
    }


    -(void) __setContentsImage:(id)image {
        UIImageSetLayerContents([self layer], image);
    }


    -(UIView*) viewForBaselineLayout {
        return self;
    }

    -(CGSize) intrinsicContentSize {
        CGSize ret;
        ret.width = UIViewNoIntrinsicMetric;
        ret.height = UIViewNoIntrinsicMetric;
        return ret;
    }

    -(void) setNativeElement:(WXFrameworkElement *) nativeElement
    {
        [self layer].contentsElement = nativeElement;
    }
@end


