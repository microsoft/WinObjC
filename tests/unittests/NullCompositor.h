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

class NullCompositor : public CACompositorInterface
{
public:
    void DisplayTreeChanged() override { }
    void ProcessTransactions() override { }
    void RequestRedraw() override { }
    DisplayNode* CreateDisplayNode() override { return nullptr; }
    DisplayTransaction* CreateDisplayTransaction() override { return nullptr; }
    void QueueDisplayTransaction(DisplayTransaction* transaction, DisplayTransaction* onTransaction) override { }

    void sortWindowLevels() override { }

    void addNode(DisplayTransaction* transaction, DisplayNode* node, DisplayNode* superNode, DisplayNode* beforeNode, DisplayNode* afterNode) override { }
    void moveNode(DisplayTransaction* transaction, DisplayNode* node, DisplayNode* beforeNode, DisplayNode* afterNode) override { }
    void removeNode(DisplayTransaction* transaction, DisplayNode* pNode) override { }

    void addAnimation(DisplayTransaction* transaction, id layer, id animation, id forKey) override { }
    void addAnimationRaw(DisplayTransaction* transaction, DisplayNode* pNode, DisplayAnimation* pAnimation) override { }
    void removeAnimationRaw(DisplayTransaction* transaction, DisplayNode* pNode, DisplayAnimation* pAnimation) override { }

    void setDisplayProperty(DisplayTransaction* transaction, DisplayNode* node, const char* propertyName, NSObject* newValue) override { }

    void setNodeTexture(DisplayTransaction* transaction, DisplayNode* node, DisplayTexture* newTexture, CGSize contentsSize, float contentsScale) override { }
    void setNodeMaskNode(DisplayNode* node, DisplayNode* maskNode) override { }
    NSObject* getDisplayProperty(DisplayNode* node, const char* propertyName = NULL) override { return nil; }

    void setNodeTopMost(DisplayNode* node, bool topMost) override { }
    void setNodeTopWindowLevel(DisplayNode* node, float level) override { }

    DisplayTexture* GetDisplayTextureForCGImage(CGImageRef img, bool create) override { return nullptr; }
    DisplayTexture* CreateDisplayTextureForText() override { return nullptr; }
    void SetTextDisplayTextureParams(DisplayTexture* texture, id font, id text, id color, UITextAlignment alignment, UILineBreakMode lineBreak, id shadowColor,
                                     const CGSize &shadowOffset, int numLines, UIEdgeInsets edgeInsets, bool centerVertically) override { }
    DisplayTexture* CreateDisplayTextureForElement(id xamlElement) override { return nullptr; }

    DisplayAnimation*  GetBasicDisplayAnimation(id caanim, NSString* propertyName, NSObject* fromValue, NSObject* toValue, CAMediaTimingProperties* timingProperties) override { return nullptr; }
    DisplayAnimation*  GetMoveDisplayAnimation(DisplayAnimation** secondAnimRet, id caanim, DisplayNode* animNode, NSString* type, NSString* subtype, CAMediaTimingProperties* timingProperties) override { return nullptr; }

    void RetainAnimation(DisplayAnimation* animation) override { }
    void ReleaseAnimation(DisplayAnimation* animation) override { }

    void RetainNode(DisplayNode* node) override { }
    void ReleaseNode(DisplayNode* node) override { }

    void RetainDisplayTexture(DisplayTexture* tex) override { }
    void ReleaseDisplayTexture(DisplayTexture* tex) override { }

    void SortWindowLevels() override { }
    bool isTablet() override { return false; }
    float screenWidth() override { return 100.0f; }
    float screenHeight() override { return 100.0f; }
    float screenScale() override { return 1.0f; }
    int deviceWidth() override { return 100; }
    int deviceHeight() override { return 100; }
    float screenXDpi() override { return 100; }
    float screenYDpi() override { return 100; }

    void setScreenSize(float width, float height, float scale, float rotationClockwise) override { }
    void setDeviceSize(int width, int height) override { }
    void setScreenDpi(int xDpi, int yDpi) override { }
    void setTablet(bool isTablet) override { }

    DisplayTexture* CreateWritableBitmapTexture32(int width, int height) override { return nullptr; }
    void* LockWritableBitmapTexture(DisplayTexture* tex, int* stride) override { return nullptr; }
    void UnlockWritableBitmapTexture(DisplayTexture* tex) override { }

    void EnableDisplaySyncNotification() override { }
    void DisableDisplaySyncNotification() override { }

    void IncrementCounter(const char* name) override { }
    void DecrementCounter(const char* name) override { }

    virtual void SetAccessibilityInfo(DisplayNode* node, const IWAccessibilityInfo& info) override {}
};

