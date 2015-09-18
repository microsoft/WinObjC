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

#if defined( __cplusplus ) && defined( __OBJC__ ) && !defined( __CA_COMPOSITOR_H )
#define __CA_COMPOSITOR_H

class DisplayNode;
class DisplayAnimation;
class DisplayTexture;
class DisplayTransaction;
struct CAMediaTimingProperties;

#define CACompositorRotationNone                0.0f
#define CACompositorRotation90Clockwise         90.0f
#define CACompositorRotation180                 180.0f
#define CACompositorRotation90CounterClockwise  270.0f

class CACompositorInterface
{
public:
    virtual void DisplayTreeChanged() = 0;
    virtual void ProcessTransactions() = 0;
    virtual void RequestRedraw() = 0;
    virtual DisplayNode *CreateDisplayNode() = 0;
    virtual DisplayTransaction *CreateDisplayTransaction() = 0;
    virtual void QueueDisplayTransaction(DisplayTransaction *transaction, DisplayTransaction *onTransaction) = 0;

    virtual void sortWindowLevels() = 0;

    virtual void addNode(DisplayTransaction *transaction, DisplayNode *node, DisplayNode *superNode, DisplayNode *beforeNode, DisplayNode *afterNode) = 0;
    virtual void moveNode(DisplayTransaction *transaction, DisplayNode *node, DisplayNode *beforeNode, DisplayNode *afterNode) = 0;
    virtual void removeNode(DisplayTransaction *transaction, DisplayNode *pNode) = 0;

    virtual void addAnimation(DisplayTransaction *transaction, id layer, id animation, id forKey) = 0;
    virtual void addAnimationRaw(DisplayTransaction *transaction, DisplayNode *pNode, DisplayAnimation *pAnimation) = 0;
    virtual void removeAnimationRaw(DisplayTransaction *transaction, DisplayNode *pNode, DisplayAnimation *pAnimation) = 0;

    virtual void setDisplayProperty(DisplayTransaction *transaction, DisplayNode *node, const char *propertyName, NSObject *newValue) = 0;

    virtual void setNodeTexture(DisplayTransaction *transaction, DisplayNode *node, DisplayTexture *newTexture, CGSize contentsSize, float contentsScale) = 0;
    virtual void setNodeMaskNode(DisplayNode *node, DisplayNode *maskNode) = 0;
    virtual NSObject *getDisplayProperty(DisplayNode *node, const char *propertyName = NULL) = 0;

    virtual void setNodeTopMost(DisplayNode *node, bool topMost) = 0;
    virtual void setNodeTopWindowLevel(DisplayNode *node, float level) = 0;

    virtual DisplayTexture * GetDisplayTextureForCGImage(CGImageRef img, bool create) = 0;
    virtual DisplayTexture * CreateDisplayTextureForText() = 0;
    virtual void SetTextDisplayTextureParams(DisplayTexture *texture, id font, id text, id color, UITextAlignment alignment, UILineBreakMode lineBreak, id shadowColor,
                            const CGSize &shadowOffset, int numLines, UIEdgeInsets edgeInsets, bool centerVertically) = 0;
    virtual DisplayTexture *CreateDisplayTextureForElement(id xamlElement) = 0;

    virtual DisplayAnimation * GetBasicDisplayAnimation(id caanim, NSString *propertyName, NSObject *fromValue, NSObject *toValue, CAMediaTimingProperties *timingProperties) = 0;
    virtual DisplayAnimation * GetMoveDisplayAnimation(DisplayAnimation **secondAnimRet, id caanim, DisplayNode *animNode, NSString *type, NSString *subtype, CAMediaTimingProperties *timingProperties) = 0;

    virtual void RetainAnimation(DisplayAnimation *animation) = 0;
    virtual void ReleaseAnimation(DisplayAnimation *animation) = 0;

    virtual void RetainNode(DisplayNode *node) = 0;
    virtual void ReleaseNode(DisplayNode *node) = 0;

    virtual void RetainDisplayTexture(DisplayTexture *tex) = 0;
    virtual void ReleaseDisplayTexture(DisplayTexture *tex) = 0;

    //virtual CGPoint ConvertPoint(CGPoint point, CALayer *fromLayer, CALayer *toLayer) = 0;

    virtual void SortWindowLevels() = 0;
    virtual bool isTablet() = 0;
    virtual float screenWidth() = 0;
    virtual float screenHeight() = 0;
    virtual float screenScale() = 0;
    virtual int deviceWidth() = 0;
    virtual int deviceHeight() = 0;
    virtual float screenXDpi() = 0;
    virtual float screenYDpi() = 0;

    virtual void setScreenSize(float width, float height, float scale, float rotationClockwise) = 0;
    virtual void setDeviceSize(int width, int height) = 0;
    virtual void setScreenDpi(int xDpi, int yDpi) = 0;
    virtual void setTablet(bool isTablet) = 0;

    virtual DisplayTexture *CreateWritableBitmapTexture32(int width, int height) = 0;
    virtual void *LockWritableBitmapTexture(DisplayTexture *tex, int *stride) = 0;
    virtual void UnlockWritableBitmapTexture(DisplayTexture *tex) = 0;

    virtual void EnableDisplaySyncNotification() = 0;
    virtual void DisableDisplaySyncNotification() = 0;

    virtual void IncrementCounter(const char *name) = 0;
    virtual void DecrementCounter(const char *name) = 0;
};

extern CACompositorInterface *_globalCompositor;

#ifndef CA_EXPORT
 #define CA_EXPORT
#endif

CA_EXPORT CACompositorInterface *GetCACompositor();
CA_EXPORT void SetCACompositor(CACompositorInterface *compositorInterface);

CA_EXPORT bool CASignalDisplayLink();
#endif