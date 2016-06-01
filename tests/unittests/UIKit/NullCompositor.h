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
#pragma once

#import "CACompositor.h"

class NullCompositor : public CACompositorInterface {
public:
    void DisplayTreeChanged() override {
    }
    void ProcessTransactions() override {
    }
    void RequestRedraw() override {
    }
    DisplayNode* CreateDisplayNode() override {
        return nullptr;
    }
    Microsoft::WRL::ComPtr<IInspectable> GetXamlLayoutElement(DisplayNode*) override {
        return nullptr;
    }
    std::shared_ptr<DisplayTransaction> CreateDisplayTransaction() override {
        return nullptr;
    }
    void QueueDisplayTransaction(const std::shared_ptr<DisplayTransaction>& transaction,
                                 const std::shared_ptr<DisplayTransaction>& onTransaction) override {
    }

    void addNode(const std::shared_ptr<DisplayTransaction>& transaction,
                 DisplayNode* node,
                 DisplayNode* superNode,
                 DisplayNode* beforeNode,
                 DisplayNode* afterNode) override {
    }
    void moveNode(const std::shared_ptr<DisplayTransaction>& transaction,
                  DisplayNode* node,
                  DisplayNode* beforeNode,
                  DisplayNode* afterNode) override {
    }
    void removeNode(const std::shared_ptr<DisplayTransaction>& transaction, DisplayNode* pNode) override {
    }

    void addAnimation(const std::shared_ptr<DisplayTransaction>& transaction, id layer, id animation, id forKey) override {
    }

    void setDisplayProperty(const std::shared_ptr<DisplayTransaction>& transaction,
                            DisplayNode* node,
                            const char* propertyName,
                            NSObject* newValue) override {
    }

    void setNodeTexture(const std::shared_ptr<DisplayTransaction>& transaction,
                        DisplayNode* node,
                        DisplayTexture* newTexture,
                        CGSize contentsSize,
                        float contentsScale) override {
    }
    void setNodeMaskNode(DisplayNode* node, DisplayNode* maskNode) override {
    }
    NSObject* getDisplayProperty(DisplayNode* node, const char* propertyName = NULL) override {
        return nil;
    }

    void setNodeTopMost(DisplayNode* node, bool topMost) override {
    }
    void setNodeTopWindowLevel(DisplayNode* node, float level) override {
    }

    DisplayTexture* GetDisplayTextureForCGImage(CGImageRef img, bool create) override {
        return nullptr;
    }
    DisplayTexture* CreateDisplayTextureForText() override {
        return nullptr;
    }
    void SetTextDisplayTextureParams(DisplayTexture* texture,
                                     id font,
                                     id text,
                                     id color,
                                     UITextAlignment alignment,
                                     UILineBreakMode lineBreak,
                                     id shadowColor,
                                     const CGSize& shadowOffset,
                                     int numLines,
                                     UIEdgeInsets edgeInsets,
                                     bool centerVertically) override {
    }
    DisplayTexture* CreateDisplayTextureForElement(id xamlElement) override {
        return nullptr;
    }

    DisplayAnimation* GetBasicDisplayAnimation(id caanim,
                                               NSString* propertyName,
                                               NSObject* fromValue,
                                               NSObject* toValue,
                                               NSObject* byValue,
                                               CAMediaTimingProperties* timingProperties) override {
        return nullptr;
    }
    DisplayAnimation* GetMoveDisplayAnimation(DisplayAnimation** secondAnimRet,
                                              id caanim,
                                              DisplayNode* animNode,
                                              NSString* type,
                                              NSString* subtype,
                                              CAMediaTimingProperties* timingProperties) override {
        return nullptr;
    }

    void RetainAnimation(DisplayAnimation* animation) override {
    }
    void ReleaseAnimation(DisplayAnimation* animation) override {
    }

    void RetainNode(DisplayNode* node) override {
    }
    void ReleaseNode(DisplayNode* node) override {
    }

    void RetainDisplayTexture(DisplayTexture* tex) override {
    }
    void ReleaseDisplayTexture(DisplayTexture* tex) override {
    }

    bool isTablet() override {
        return false;
    }
    float screenWidth() override {
        return 100.0f;
    }
    float screenHeight() override {
        return 100.0f;
    }
    float screenScale() override {
        return 1.0f;
    }
    int deviceWidth() override {
        return 100;
    }
    int deviceHeight() override {
        return 100;
    }
    float screenXDpi() override {
        return 100;
    }
    float screenYDpi() override {
        return 100;
    }

    void setScreenSize(float width, float height, float scale, float rotationClockwise) override {
    }
    void setDeviceSize(int width, int height) override {
    }
    void setScreenDpi(int xDpi, int yDpi) override {
    }
    void setTablet(bool isTablet) override {
    }

    DisplayTexture* CreateWritableBitmapTexture32(int width, int height) override {
        return nullptr;
    }
    void* LockWritableBitmapTexture(DisplayTexture* tex, int* stride) override {
        return nullptr;
    }
    void UnlockWritableBitmapTexture(DisplayTexture* tex) override {
    }

    void EnableDisplaySyncNotification() override {
    }
    void DisableDisplaySyncNotification() override {
    }

    virtual void SetAccessibilityInfo(DisplayNode* node, const IWAccessibilityInfo& info) override {
    }

    virtual void SetShouldRasterize(DisplayNode* node, bool rasterize) override {
    }
};
