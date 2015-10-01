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

#define STARBOARD_PORT

#include "Starboard.h"
#include "CACompositor.h"
#include "CACompositorClient.h"
#include "winobjc\winobjc.h"
#include "QuartzCore\CALayer.h"
#include "CGContextInternal.h"
#include "UIInterface.h"
#include "QuartzCore\CATransform3D.h"
#include "Quaternion.h"
#include <deque>
#include <map>
#include <memory>
#include "CompositorInterface.h"
#include "CAAnimationInternal.h"

@class RTObject;

CACompositorClientInterface* _client;
void UpdateRootNode();

bool dxLandscape = false;

float screenWidth = 320.0f;
float screenHeight = 480.0f;
float screenMagnification = 1.0f;

bool tabletMode = false;

float screenXDpi = 180, screenYDpi = 180;
int deviceWidth = 640, deviceHeight = 1136;

winobjc::Id CreateBitmapFromBits(void* ptr, int width, int height, int stride);
winobjc::Id CreateBitmapFromImageData(const void* ptr, int len);
winobjc::Id CreateWritableBitmap(int width, int height);
void* LockWritableBitmap(winobjc::Id& bitmap, void** ptr, int* stride);
void UnlockWritableBitmap(winobjc::Id& bitmap, void* byteAccess);
void SetSwapchainScale(winobjc::Id& panel, float scale);

void SetScreenParameters(float width, float height, float magnification, float rotation);
void SetRootGrid(winobjc::Id& root);

void EnableRenderingListener(void (*callback)());
void DisableRenderingListener();

void OnRenderedFrame() {
    CASignalDisplayLink();
}

#include <mutex>

std::mutex _displayTextureCacheLock;
std::map<CGImageRef, DisplayTextureRef> _displayTextureCache;

DisplayTextureRef CachedDisplayTextureForImage(CGImageRef img) {
    DisplayTextureRef ret = NULL;
    _displayTextureCacheLock.lock();
    auto texRef = _displayTextureCache.find(img);
    if (texRef != _displayTextureCache.end()) {
        ret = texRef->second;
    }
    _displayTextureCacheLock.unlock();

    return ret;
}

void SetCachedDisplayTextureForImage(CGImageRef img, DisplayTexture* texture) {
    _displayTextureCacheLock.lock();
    if (!texture) {
        auto texRef = _displayTextureCache.find(img);
        if (texRef != _displayTextureCache.end()) {
            _displayTextureCache.erase(texRef);
        }
    } else {
        _displayTextureCache[img] = texture;
    }
    _displayTextureCacheLock.unlock();
}

void UIReleaseDisplayTextureForCGImage(CGImageRef img) {
    SetCachedDisplayTextureForImage(img, NULL);
}

void SetImageDestructionCallbacks() {
    CGImageAddDestructionListener(UIReleaseDisplayTextureForCGImage);
}

void RefCountedType::AddRef() {
    assert(refCount > 0 && refCount != 0xDDDDDDDD);
    EbrIncrement(&refCount);
}

void RefCountedType::Release() {
    assert(refCount > 0 && refCount != 0xDDDDDDDD);
    if (EbrDecrement(&refCount) == 0) {
        delete this;
    }
}

RefCountedType::RefCountedType() {
    refCount = 1;
}

RefCountedType::~RefCountedType() {
}

DisplayTexture::DisplayTexture() {
}

DisplayTexture::~DisplayTexture() {
}

class GenericControlXaml : public DisplayTexture {
public:
    winobjc::Id _xamlView;

    GenericControlXaml(id view) {
        _xamlView = view;
    }

    ~GenericControlXaml() {
    }

    void SetNodeContent(DisplayNode* node, float width, float height, float scale) {
        node->SetContentsElement(_xamlView);
    }
};

class DisplayTextureContent : public DisplayTexture {
    winobjc::Id _xamlImage;
    const char* name;

public:
    ~DisplayTextureContent() {
        DecrementCounter(name);
    }

    DisplayTextureContent(CGImageRef img) : name("TextureBitmap") {
        IncrementCounter(name);

        if (img->_imgType == CGImageTypePNG || img->_imgType == CGImageTypeJPEG) {
            const void* data = NULL;
            bool freeData = false;
            int len = 0;

            switch (img->_imgType) {
                case CGImageTypePNG: {
                    CGPNGImageBacking* pngImg = (CGPNGImageBacking*)img->Backing();

                    if (pngImg->_fileName) {
                        EbrFile* fpIn;
                        fpIn = EbrFopen(pngImg->_fileName, "rb");
                        if (!fpIn) {
                            assert(0);
                        }
                        EbrFseek(fpIn, 0, SEEK_END);
                        int fileLen = EbrFtell(fpIn);
                        EbrFseek(fpIn, 0, SEEK_SET);
                        void* pngData = (void*)malloc(fileLen);
                        len = EbrFread(pngData, 1, fileLen, fpIn);
                        EbrFclose(fpIn);

                        data = pngData;
                        freeData = true;
                    } else {
                        data = [(NSData*)pngImg->_data bytes];
                        len = [(NSData*)pngImg->_data length];
                    }
                } break;

                case CGImageTypeJPEG: {
                    CGJPEGImageBacking* jpgImg = (CGJPEGImageBacking*)img->Backing();

                    if (jpgImg->_fileName) {
                        EbrFile* fpIn;
                        fpIn = EbrFopen(jpgImg->_fileName, "rb");
                        if (!fpIn) {
                            assert(0);
                        }
                        EbrFseek(fpIn, 0, SEEK_END);
                        int fileLen = EbrFtell(fpIn);
                        EbrFseek(fpIn, 0, SEEK_SET);
                        void* imgData = (void*)malloc(fileLen);
                        len = EbrFread(imgData, 1, fileLen, fpIn);
                        EbrFclose(fpIn);

                        data = imgData;
                        freeData = true;
                    } else {
                        data = [(NSData*)jpgImg->_data bytes];
                        len = [(NSData*)jpgImg->_data length];
                    }
                } break;
            }
            _xamlImage = CreateBitmapFromImageData(data, len);
            if (freeData)
                free((void*)data);
            return;
        }
        lockPtr = NULL;

        int texWidth = img->Backing()->Width();
        int texHeight = img->Backing()->Height();
        int imageWidth = texWidth;
        int imageHeight = texHeight;
        int imageX = 0;
        int imageY = 0;
        CGImageRef pNewImage = 0;
        CGImageRef pTexImage = img;

        bool matched = false;
        if (img->Backing()->SurfaceFormat() == _ColorARGB) {
            matched = true;
        }

        // Unrecognized, make 8888 RGBA:
        if (!matched) {
            CGContextRef ctx = CGBitmapContextCreate32(texWidth, texHeight);
            pNewImage = CGBitmapContextGetImage(ctx);
            CGImageRetain(pNewImage);

            pTexImage = pNewImage;

            CGRect rect, destRect;

            int w = fmin(imageWidth, texWidth), h = fmin(imageHeight, texHeight);

            rect.origin.x = float(imageX);
            rect.origin.y = float(imageY);
            rect.size.width = float(w);
            rect.size.height = float(h);

            destRect.origin.x = 0;
            destRect.origin.y = float(texHeight - imageHeight);
            destRect.size.width = float(w);
            destRect.size.height = float(h);

            CGContextDrawImageRect(ctx, img, rect, destRect);
            CGContextRelease(ctx);
        }

        void* data = (void*)pTexImage->Backing()->LockImageData();
        int bytesPerRow = pTexImage->Backing()->BytesPerRow();

        int width = pTexImage->Backing()->Width();
        int height = pTexImage->Backing()->Height();

        _xamlImage = CreateBitmapFromBits(data, width, height, bytesPerRow);

        pTexImage->Backing()->ReleaseImageData();
        img->Backing()->DiscardIfPossible();

        CGImageRelease(pNewImage);
    }

    DisplayTextureContent(int width, int height) : name("TextureDirect") {
        IncrementCounter(name);
        lockPtr = NULL;
        _xamlImage = CreateWritableBitmap(width, height);
    }

    void* lockPtr;

    void* LockWritableBitmap(int* stride) {
        void* ret = NULL;
        lockPtr = ::LockWritableBitmap(_xamlImage, &ret, stride);
        return ret;
    }

    void UnlockWritableBitmap() {
        ::UnlockWritableBitmap(_xamlImage, lockPtr);
        lockPtr = NULL;
    }

    void SetNodeContent(DisplayNode* node, float width, float height, float scale) {
        node->SetContents(_xamlImage, width, height, scale);
    }
};

class DisplayTextureText : public DisplayTextureXamlGlyphs {
public:
    DisplayTextureText() {
        IncrementCounter("TextureText");
    }

    ~DisplayTextureText() {
        DecrementCounter("TextureText");
    }

    void SetParams(UIFont* font,
                   NSString* text,
                   UIColor* color,
                   UITextAlignment alignment,
                   UILineBreakMode lineBreak,
                   UIColor* shadowColor,
                   const CGSize& shadowOffset,
                   int numLines,
                   UIEdgeInsets edgeInsets,
                   bool centerVertically) {
        switch (alignment) {
            case UITextAlignmentLeft:
                _horzAlignment = alignLeft;
                break;

            case UITextAlignmentCenter:
                _horzAlignment = alignCenter;
                break;

            case UITextAlignmentRight:
                _horzAlignment = alignRight;
                break;
        }

        _insets[0] = edgeInsets.left;
        _insets[1] = edgeInsets.top;
        _insets[2] = edgeInsets.right;
        _insets[3] = edgeInsets.bottom;

        [color getColors:_color];
        _fontSize = [font pointSize];
        _centerVertically = centerVertically;
        _lineHeight = [font ascender] - [font descender];

        ConstructGlyphs([[font fontName] UTF8String], (const wchar_t*)[text rawCharacters], [text length]);
    }
};

class DisplayAnimationTransition : public DisplayAnimation {
public:
    id _animHandler;
    NSString *_type, *_subType;

    void Completed() {
        id animHandler = _animHandler; // Save in a local for the block to retain.
        dispatch_async(dispatch_get_main_queue(), ^{
            [animHandler animationDidStop:TRUE];
            [animHandler _removeAnimationsFromLayer];
        });
    }

    DisplayAnimationTransition(id animHandler, NSString* type, NSString* subType) {
        IncrementCounter("TransitionAnimation");

        _animHandler = [animHandler retain];

        _type = [type retain];
        _subType = [subType retain];
        beginTime = 0;
        duration = 1.0f;
        autoReverse = false;
        repeatCount = 0;
        repeatDuration = 0;
        speed = 1.0;
        timeOffset = 0;
    }

    ~DisplayAnimationTransition() {
        DecrementCounter("TransitionAnimation");

        [_animHandler release];
        [_type release];
        [_subType release];
    }

    void AddToNode(DisplayNode* node) {
        CreateXamlAnimation();
        AddTransitionAnimation(node, [_type UTF8String], [_subType UTF8String]);
        Start();
    }
};

class DisplayAnimationBasic : public DisplayAnimation {
public:
    NSString* _propertyName;
    NSObject *_fromValue, *_toValue;
    id _animHandler;

    void Completed() {
        id animHandler = _animHandler; // Save in a local for the block to retain.
        dispatch_async(dispatch_get_main_queue(), ^{
            [animHandler animationDidStop:TRUE];
            [animHandler _removeAnimationsFromLayer];
        });
    }

    DisplayAnimationBasic(id animHandler,
                          NSString* propertyName,
                          NSObject* fromValue,
                          NSObject* toValue,
                          CAMediaTimingProperties* timingProperties) {
        IncrementCounter("BasicAnimation");

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

        beginTime = timingProperties->_beginTime;
        duration = timingProperties->_duration;
        autoReverse = (bool)timingProperties->_autoReverses;
        repeatCount = timingProperties->_repeatCount;
        repeatDuration = timingProperties->_repeatDuration;
        speed = timingProperties->_speed;
        timeOffset = timingProperties->_timeOffset;
    }

    ~DisplayAnimationBasic() {
        DecrementCounter("BasicAnimation");
        [_animHandler release];
        [_propertyName release];
        [_fromValue release];
        [_toValue release];
    }

    void AddToNode(DisplayNode* node) {
        CreateXamlAnimation();

        const char* propName = [_propertyName UTF8String];
        if (strcmp(propName, "transform.scale") == 0) {
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            AddAnimation(node, L"transform.scale.x", _fromValue != nil, fromValue, _toValue != nil, toValue);
            AddAnimation(node, L"transform.scale.y", _fromValue != nil, fromValue, _toValue != nil, toValue);
            Start();
        } else if (strcmp(propName, "transform.rotation.z") == 0) {
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];

            fromValue = fromValue * 180.0f / M_PI;
            toValue = toValue * 180.0f / M_PI;

            AddAnimation(node, L"transform.rotation", _fromValue != nil, fromValue, _toValue != nil, toValue);
            Start();
        } else if (strcmp(propName, "position") == 0) {
            CGPoint fromValue = [(NSValue*)_fromValue CGPointValue];
            CGPoint toValue = [(NSValue*)_toValue CGPointValue];

            AddAnimation(node, L"position.x", _fromValue != nil, fromValue.x, _toValue != nil, toValue.x);
            AddAnimation(node, L"position.y", _fromValue != nil, fromValue.y, _toValue != nil, toValue.y);
            Start();
        } else if (strcmp(propName, "bounds.size") == 0) {
            CGSize fromValue = [(NSValue*)_fromValue CGSizeValue];
            CGSize toValue = [(NSValue*)_toValue CGSizeValue];

            AddAnimation(node, L"size.width", _fromValue != nil, fromValue.width, _toValue != nil, toValue.width);
            AddAnimation(node, L"size.height", _fromValue != nil, fromValue.height, _toValue != nil, toValue.height);
            Start();
        } else if (strcmp(propName, "bounds.origin") == 0) {
            CGPoint fromValue = [(NSValue*)_fromValue CGPointValue];
            CGPoint toValue = [(NSValue*)_toValue CGPointValue];

            AddAnimation(node, L"origin.x", _fromValue != nil, fromValue.x, _toValue != nil, toValue.x);
            AddAnimation(node, L"origin.y", _fromValue != nil, fromValue.y, _toValue != nil, toValue.y);
            Start();
        } else if (strcmp(propName, "bounds") == 0) {
            CGRect fromValue = [(NSValue*)_fromValue CGRectValue];
            CGRect toValue = [(NSValue*)_toValue CGRectValue];

            AddAnimation(node, L"origin.x", _fromValue != nil, fromValue.origin.x, _toValue != nil, toValue.origin.x);
            AddAnimation(node, L"origin.y", _fromValue != nil, fromValue.origin.y, _toValue != nil, toValue.origin.y);
            AddAnimation(
                node, L"size.width", _fromValue != nil, fromValue.size.width, _toValue != nil, toValue.size.width);
            AddAnimation(
                node, L"size.height", _fromValue != nil, fromValue.size.height, _toValue != nil, toValue.size.height);
            Start();
        } else if (strcmp(propName, "opacity") == 0) {
            float fromValue = [(NSNumber*)_fromValue floatValue];
            float toValue = [(NSNumber*)_toValue floatValue];
            AddAnimation(node, L"opacity", _fromValue != nil, fromValue, _toValue != nil, toValue);
            Start();
        } else if (strcmp(propName, "transform") == 0) {
            CATransform3D fromValue = [(NSValue*)_fromValue CATransform3DValue];
            CATransform3D toValue = [(NSValue*)_toValue CATransform3DValue];
            float translationFrom[3] = { 0 };
            float scaleFrom[3] = { 1.0f, 1.0f, 1.0f };
            float angleFrom = 0.0f;
            float translationTo[3] = { 0 };
            float scaleTo[3] = { 1.0f, 1.0f, 1.0f };
            float angleTo = 0.0f;

            if (_fromValue != nil) {
                Quaternion qval;
                qval.CreateFromMatrix((float*)&(fromValue));
                angleFrom = (float)-qval.roll() * 180.0f / M_PI;
                CATransform3DGetScale(fromValue, scaleFrom);
                CATransform3DGetPosition(fromValue, translationFrom);
            }
            if (_toValue != nil) {
                Quaternion qval;
                qval.CreateFromMatrix((float*)&(toValue));
                angleTo = (float)-qval.roll() * 180.0f / M_PI;
                CATransform3DGetScale(toValue, scaleTo);
                CATransform3DGetPosition(toValue, translationTo);
            }

            if (scaleFrom[0] != 1.0f || scaleFrom[1] != 1.0f || scaleTo[0] != 1.0f || scaleTo[1] != 1.0f) {
                AddAnimation(node, L"transform.scale.x", _fromValue != nil, scaleFrom[0], _toValue != nil, scaleTo[0]);
                AddAnimation(node, L"transform.scale.y", _fromValue != nil, scaleFrom[1], _toValue != nil, scaleTo[1]);
            }
            if (translationFrom[0] != 0.0f || translationFrom[1] != 0.0f || translationTo[0] != 0.0f ||
                translationTo[1] != 0.0f) {
                AddAnimation(node,
                             L"transform.translation.x",
                             _fromValue != nil,
                             translationFrom[0],
                             _toValue != nil,
                             translationTo[0]);
                AddAnimation(node,
                             L"transform.translation.y",
                             _fromValue != nil,
                             translationFrom[1],
                             _toValue != nil,
                             translationTo[1]);
            }
            if (angleFrom != 0.0f || angleTo != 0.0f) {
                AddAnimation(node, L"transform.rotation", _fromValue != nil, angleFrom, _toValue != nil, angleTo);
            }
            Start();
        } else if (strcmp(propName, "contents") == 0) {
        } else {
            assert(0);
        }
    }
};

void DisplayNode::AddAnimation(DisplayAnimation* anim) {
    if (anim)
        anim->AddToNode(this);
}

void DisplayNode::SetContents(DisplayTexture* tex, float width, float height, float contentScale) {
    currentTexture = tex;

    if (tex) {
        tex->SetNodeContent(this, width, height, contentScale);
    } else {
        winobjc::Id nullContents;

        SetContents(nullContents, width, height, contentScale);
    }
}

class DisplayNodeXaml : public DisplayNode {
public:
    DisplayNodeXaml() {
        IncrementCounter("DisplayNodeXaml");
    }

    ~DisplayNodeXaml() {
        DecrementCounter("DisplayNodeXaml");
    }

    void* GetProperty(const char* name) {
        NSObject* ret = nil;

        if (strcmp(name, "position") == 0) {
            CGPoint pos;

            pos.x = GetPresentationPropertyValue("position.x");
            pos.y = GetPresentationPropertyValue("position.y");

            ret = [NSValue valueWithCGPoint:pos];
        } else if (strcmp(name, "bounds.origin") == 0) {
            CGPoint pos;

            pos.x = GetPresentationPropertyValue("origin.x");
            pos.y = GetPresentationPropertyValue("origin.y");

            ret = [NSValue valueWithCGPoint:pos];
        } else if (strcmp(name, "bounds.size") == 0) {
            CGSize size;

            size.width = GetPresentationPropertyValue("size.width");
            size.height = GetPresentationPropertyValue("size.height");

            ret = [NSValue valueWithCGSize:size];
        } else if (strcmp(name, "bounds") == 0) {
            CGRect rect;

            rect.size.width = GetPresentationPropertyValue("size.width");
            rect.size.height = GetPresentationPropertyValue("size.height");
            rect.origin.x = GetPresentationPropertyValue("origin.x");
            rect.origin.y = GetPresentationPropertyValue("origin.y");

            ret = [NSValue valueWithCGRect:rect];
        } else if (strcmp(name, "opacity") == 0) {
            float value = GetPresentationPropertyValue("opacity");

            ret = [NSNumber numberWithFloat:value];
        } else if (strcmp(name, "transform") == 0) {
            float angle = GetPresentationPropertyValue("transform.rotation");
            float scale[2];
            float translation[2];

            scale[0] = GetPresentationPropertyValue("transform.scale.x");
            scale[1] = GetPresentationPropertyValue("transform.scale.y");

            translation[0] = GetPresentationPropertyValue("transform.translation.x");
            translation[1] = GetPresentationPropertyValue("transform.translation.y");

            CATransform3D trans = CATransform3DMakeRotation(-angle * M_PI / 180.0f, 0, 0, 1.0f);
            trans = CATransform3DScale(trans, scale[0], scale[1], 0.0f);
            trans = CATransform3DTranslate(trans, translation[0], translation[1], 0.0f);

            ret = [NSValue valueWithCATransform3D:trans];
        } else {
            assert(0);
        }

        return ret;
    }

    void UpdateProperty(const char* name, void* value) {
        NSObject* newValue = (NSObject*)value;
        if (name == NULL)
            return;
        if ([NSThread currentThread] != [NSThread mainThread]) {
            return;
        }

        if (strcmp(name, "contentsCenter") == 0) {
            CGRect value = [(NSValue*)newValue CGRectValue];
            SetContentsCenter(value.origin.x, value.origin.y, value.size.width, value.size.height);
        } else if (strcmp(name, "anchorPoint") == 0) {
            CGPoint value = [(NSValue*)newValue CGPointValue];
            SetProperty(L"anchorPoint.x", value.x);
            SetProperty(L"anchorPoint.y", value.y);
        } else if (strcmp(name, "position") == 0) {
            CGPoint position = [(NSValue*)newValue CGPointValue];
            SetProperty(L"position.x", position.x);
            SetProperty(L"position.y", position.y);
        } else if (strcmp(name, "bounds.origin") == 0) {
            CGPoint value = [(NSValue*)newValue CGPointValue];
            SetProperty(L"origin.x", value.x);
            SetProperty(L"origin.y", value.y);
        } else if (strcmp(name, "bounds.size") == 0) {
            CGSize size = [(NSValue*)newValue CGSizeValue];
            SetProperty(L"size.width", size.width);
            SetProperty(L"size.height", size.height);
        } else if (strcmp(name, "opacity") == 0) {
            float value = [(NSNumber*)newValue floatValue];
            SetProperty(L"opacity", value);
        } else if (strcmp(name, "hidden") == 0) {
            bool value = [(NSNumber*)newValue boolValue];
            SetHidden(value);
        } else if (strcmp(name, "masksToBounds") == 0) {
            if (!isRoot) {
                bool value = [(NSNumber*)newValue boolValue];
                SetMasksToBounds(value);
            } else {
                SetMasksToBounds(true);
            }
        } else if (strcmp(name, "transform") == 0) {
            CATransform3D value = [(NSValue*)newValue CATransform3DValue];
            float translation[3] = { 0 };
            float scale[3] = { 0 };

            Quaternion qFrom;
            qFrom.CreateFromMatrix((float*)&(value));

            CATransform3DGetScale(value, scale);
            CATransform3DGetPosition(value, translation);

            SetProperty(L"transform.rotation", (float)-qFrom.roll() * 180.0f / M_PI);
            SetProperty(L"transform.scale.x", scale[0]);
            SetProperty(L"transform.scale.y", scale[1]);
            SetProperty(L"transform.translation.x", translation[0]);
            SetProperty(L"transform.translation.y", translation[1]);
        } else if (strcmp(name, "contentsScale") == 0) {
            //  [TODO: Update contents scale in Xaml node]
            // contentScale = [(NSNumber *) newValue floatValue];
        } else if (strcmp(name, "contentsOrientation") == 0) {
        } else if (strcmp(name, "contentsSize") == 0) {
        } else if (strcmp(name, "gravity") == 0) {
            SetPropertyInt(L"gravity", [newValue intValue]);
        } else if (strcmp(name, "zPosition") == 0) {
        } else if (strcmp(name, "contentColor") == 0) {
        } else if (strcmp(name, "sublayerTransform") == 0) {
        } else if (strcmp(name, "backgroundColor") == 0) {
            float color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
            [(UIColor*)newValue getColors:&color];
            SetBackgroundColor(color[0], color[1], color[2], color[3]);
        } else {
            assert(0);
        }

        if (isRoot)
            ::UpdateRootNode();
    }
};

class Transaction {
public:
    Transaction() {
    }

    virtual ~Transaction() {
    }

    virtual void Process() = 0;
};

class QueuedAnimation : public Transaction {
public:
    id _layer, _animation, _key;
    DisplayAnimationRef abortAnimation;
    bool _abort;

    QueuedAnimation(id layer, id anim, id key) {
        abortAnimation = NULL;
        _abort = false;
        _layer = [layer retain];
        _animation = [anim retain];
        _key = [key retain];
    }

    QueuedAnimation(DisplayAnimation* animToAbort) {
        _abort = true;
        abortAnimation = animToAbort;
        _layer = nil;
        _animation = nil;
        _key = nil;
    }

    ~QueuedAnimation() {
        [_layer release];
        [_animation release];
        [_key release];
    }

    void Process() {
        if (_abort) {
            abortAnimation->Stop();
        } else {
            if (![_animation wasRemoved] && ![_animation wasAborted]) {
                DisplayAnimation* newAnimation = (DisplayAnimation*)[_animation _createAnimation:_layer forKey:_key];
                [_animation animationDidStart];
                [_animation animationHasStarted];

                if (newAnimation) {
                    DisplayNode* node = (DisplayNode*)[_layer _presentationNode];
                    node->AddAnimation(newAnimation);
                } else {
                    [_animation animationDidStop:FALSE];
                }
            }
        }
    }
};

class QueuedProperty : public Transaction {
public:
    DisplayNodeRef _node;
    char* _propertyName;
    NSObject* _propertyValue;
    DisplayTextureRef _newTexture;
    CGSize _contentsSize;
    float _contentsScale;
    bool _applyingTexture;

    QueuedProperty(DisplayNode* node, DisplayTexture* newTexture, CGSize contentsSize, float contentsScale) {
        IncrementCounter("QueuedProperty");
        _node = node;
        _propertyName = _strdup("contents");
        _propertyValue = NULL;
        _newTexture = newTexture;
        _contentsScale = contentsScale;
        _contentsSize = contentsSize;
        _applyingTexture = true;
    }

    QueuedProperty(DisplayNode* node, const char* propertyName, NSObject* propertyValue) {
        IncrementCounter("QueuedProperty");
        _node = node;
        _propertyName = _strdup(propertyName);
        _propertyValue = [propertyValue retain];
        _newTexture = NULL;
        _applyingTexture = false;
    }

    ~QueuedProperty() {
        DecrementCounter("QueuedProperty");
        if (_propertyName)
            free(_propertyName);
        [_propertyValue release];

        _propertyName = nil;
        _propertyValue = nil;
    }

    void Process() {
        if (_applyingTexture) {
            _node->SetContents(_newTexture.Get(), _contentsSize.width, _contentsSize.height, _contentsScale);
        } else {
            _node->UpdateProperty(_propertyName, _propertyValue);
        }
    }
};

class QueuedNodeMovement : public Transaction {
public:
    DisplayNodeRef _node;
    DisplayNodeRef _before, _after;
    DisplayNodeRef _supernode;

    enum MovementType { Add, Move, Remove };

    MovementType _type;

    QueuedNodeMovement(
        MovementType type, DisplayNode* node, DisplayNode* before, DisplayNode* after, DisplayNode* supernode) {
        IncrementCounter("QueuedNodeMovement");
        _type = type;
        _node = node;
        _before = before;
        _after = after;
        _supernode = supernode;
    }

    ~QueuedNodeMovement() {
        DecrementCounter("QueuedNodeMovement");
    }

    void Process() {
        switch (_type) {
            case Add:
                if (!_supernode) {
                    _node->AddToRoot();
                } else {
                    _supernode->AddSubnode(_node.Get(), _before.Get(), _after.Get());
                }
                break;

            case Move:
                _node->MoveNode(_before.Get(), _after.Get());
                break;

            case Remove:
                _node->RemoveFromSupernode();
                break;
        }
    }
};

using namespace std;

typedef shared_ptr<map<std::string, QueuedProperty*>> NodeUpdates;
typedef deque<QueuedAnimation*> AnimationQueue;
typedef map<DisplayNode*, NodeUpdates> PropertyQueue;
typedef deque<QueuedNodeMovement*> NodeMovementQueue;
typedef deque<Transaction*> TransactionQueue;

class DisplayTransaction : public Transaction {
    AnimationQueue* _queuedAnimations;
    PropertyQueue* _queuedProperties;
    NodeMovementQueue* _queuedNodeMovements;
    TransactionQueue* _queuedTransactions;

public:
    DisplayTransaction() {
        _queuedAnimations = NULL;
        _queuedProperties = NULL;
        _queuedNodeMovements = NULL;
        _queuedTransactions = NULL;
    }

    ~DisplayTransaction() {
        if (_queuedAnimations)
            delete _queuedAnimations;
        if (_queuedProperties)
            delete _queuedProperties;
        if (_queuedNodeMovements)
            delete _queuedNodeMovements;
        if (_queuedTransactions)
            delete _queuedTransactions;
    }

    void QueueProperty(QueuedProperty* prop) {
        if (_queuedProperties == NULL) {
            _queuedProperties = new PropertyQueue();
        }

        NodeUpdates curUpdates = (*_queuedProperties)[prop->_node.Get()];
        std::string propName(prop->_propertyName);
        if (curUpdates != NULL) {
            auto existingProperty = curUpdates->find(propName);
            if (existingProperty != curUpdates->end()) {
                QueuedProperty* cur = existingProperty->second;
                curUpdates->erase(existingProperty);
                delete cur;
            }
        } else {
            curUpdates = make_shared<map<std::string, QueuedProperty*>>();
            (*_queuedProperties)[prop->_node.Get()] = curUpdates;
        }
        (*curUpdates)[propName] = prop;
    }

    void QueueNodeMovement(QueuedNodeMovement* movement) {
        if (_queuedNodeMovements == NULL) {
            _queuedNodeMovements = new NodeMovementQueue();
        }
        _queuedNodeMovements->push_back(movement);
    }

    void QueueAnimation(QueuedAnimation* anim) {
        if (_queuedAnimations == NULL) {
            _queuedAnimations = new AnimationQueue();
        }
        _queuedAnimations->push_back(anim);
    }

    void Process() {
        if (_queuedTransactions) {
            for (auto& curTransaction : *_queuedTransactions) {
                curTransaction->Process();
                delete curTransaction;
            }
        }
        if (_queuedAnimations) {
            for (auto& curAnimation : *_queuedAnimations) {
                curAnimation->Process();
                delete curAnimation;
            }
        }
        if (_queuedNodeMovements) {
            for (auto& curMovement : *_queuedNodeMovements) {
                curMovement->Process();
                delete curMovement;
            }
        }
        if (_queuedProperties) {
            for (auto& curNode : *_queuedProperties) {
                for (auto& curProperty : *(curNode.second)) {
                    curProperty.second->Process();
                    delete curProperty.second;
                }
            }
        }
    }

    void QueueTransaction(Transaction* transaction) {
        if (_queuedTransactions == NULL) {
            _queuedTransactions = new TransactionQueue();
        }
        //  Move all of our existing queues into a new transaction
        if (_queuedAnimations != NULL || _queuedProperties != NULL || _queuedNodeMovements != NULL) {
            DisplayTransaction* currentPropChanges = new DisplayTransaction();
            currentPropChanges->_queuedAnimations = _queuedAnimations;
            currentPropChanges->_queuedProperties = _queuedProperties;
            currentPropChanges->_queuedNodeMovements = _queuedNodeMovements;

            _queuedAnimations = NULL;
            _queuedProperties = NULL;
            _queuedNodeMovements = NULL;

            _queuedTransactions->push_back(currentPropChanges);
        }

        _queuedTransactions->push_back(transaction);
    }
};

deque<DisplayTransaction*> _queuedTransactions;

class CAXamlCompositor : public CACompositorInterface {
public:
    virtual void DisplayTreeChanged() {
        _client->RequestTransactionProcessing();
    }
    virtual DisplayNode* CreateDisplayNode() {
        DisplayNode* ret = new DisplayNodeXaml();
        return ret;
    }

    DisplayTransaction* CreateDisplayTransaction() {
        return new DisplayTransaction();
    }

    void QueueDisplayTransaction(DisplayTransaction* transaction, DisplayTransaction* onTransaction) {
        if (onTransaction) {
            onTransaction->QueueTransaction(transaction);
        } else {
            _queuedTransactions.push_back(transaction);
        }
    }

    void CommitDisplayTransaction(DisplayTransaction* transaction) {
    }

    virtual void addNode(DisplayTransaction* transaction,
                         DisplayNode* node,
                         DisplayNode* superNode,
                         DisplayNode* beforeNode,
                         DisplayNode* afterNode) {
        QueuedNodeMovement* newNode =
            new QueuedNodeMovement(QueuedNodeMovement::Add, node, beforeNode, afterNode, superNode);
        transaction->QueueNodeMovement(newNode);
    }

    virtual void sortWindowLevels() {
    }

    virtual void
    moveNode(DisplayTransaction* transaction, DisplayNode* node, DisplayNode* beforeNode, DisplayNode* afterNode) {
        QueuedNodeMovement* newNode =
            new QueuedNodeMovement(QueuedNodeMovement::Move, node, beforeNode, afterNode, NULL);
        transaction->QueueNodeMovement(newNode);
    }

    virtual void removeNode(DisplayTransaction* transaction, DisplayNode* node) {
        QueuedNodeMovement* newNode = new QueuedNodeMovement(QueuedNodeMovement::Remove, node, NULL, NULL, NULL);
        transaction->QueueNodeMovement(newNode);
    }

    virtual void addAnimation(DisplayTransaction* transaction, id layer, id animation, id forKey) {
        QueuedAnimation* newAnim = new QueuedAnimation(layer, animation, forKey);

        transaction->QueueAnimation(newAnim);
        DisplayTreeChanged();
    }

    virtual void addAnimationRaw(DisplayTransaction* transaction, DisplayNode* pNode, DisplayAnimation* pAnimation) {
    }

    virtual void removeAnimationRaw(DisplayTransaction* transaction, DisplayNode* pNode, DisplayAnimation* pAnimation) {
        //  Removing animations while they're playing doesn't jibe well with the xaml compositor
        /*
        QueuedAnimation *newAnim = new QueuedAnimation(pAnimation);

        transaction->QueueAnimation(newAnim);
        DisplayTreeChanged();
        */
    }

    virtual void setNodeTexture(DisplayTransaction* transaction,
                                DisplayNode* node,
                                DisplayTexture* newTexture,
                                CGSize contentsSize,
                                float contentsScale) {
        QueuedProperty* newPropChange = new QueuedProperty(node, newTexture, contentsSize, contentsScale);

        transaction->QueueProperty(newPropChange);
        DisplayTreeChanged();
    }

    virtual void setNodeMaskNode(DisplayNode* node, DisplayNode* maskNode) {
    }

    virtual void setNewPatternBackground(id layer) {
    }

    virtual void setDisplayProperty(DisplayTransaction* transaction,
                                    DisplayNode* node,
                                    const char* propertyName,
                                    NSObject* newValue) {
        QueuedProperty* newPropChange = new QueuedProperty(node, propertyName, newValue);

        transaction->QueueProperty(newPropChange);
        DisplayTreeChanged();
    }

    virtual void setNodeTopMost(DisplayNode* node, bool topMost) {
        node->SetTopMost();
    }

    virtual void setNodeTopWindowLevel(DisplayNode* node, float level) {
    }

    virtual DisplayTexture* GetDisplayTextureForCGImage(CGImageRef img, bool create) {
        CGImageRetain(img);
        DisplayTexture* ret = img->Backing()->GetDisplayTexture();
        if (ret) {
            ret->AddRef();
            CGImageRelease(img);
            return ret;
        }
        DisplayTextureRef cached = CachedDisplayTextureForImage(img);
        if (cached) {
            cached->AddRef();
            return cached.Get();
        }

        ret = new DisplayTextureContent(img);
        SetCachedDisplayTextureForImage(img, ret);
        CGImageRelease(img);
        return ret;
    }

    DisplayTexture* CreateWritableBitmapTexture32(int width, int height) {
        DisplayTexture* ret = new DisplayTextureContent(width, height);
        return ret;
    }

    void* LockWritableBitmapTexture(DisplayTexture* tex, int* stride) {
        return ((DisplayTextureContent*)tex)->LockWritableBitmap(stride);
    }

    void UnlockWritableBitmapTexture(DisplayTexture* tex) {
        ((DisplayTextureContent*)tex)->UnlockWritableBitmap();
    }

    virtual DisplayTexture* CreateDisplayTextureForText() {
        DisplayTextureText* texRet = new DisplayTextureText();
        return texRet;
    }

    virtual void SetTextDisplayTextureParams(DisplayTexture* texture,
                                             id font,
                                             id text,
                                             id color,
                                             UITextAlignment alignment,
                                             UILineBreakMode lineBreak,
                                             id shadowColor,
                                             const CGSize& shadowOffset,
                                             int numLines,
                                             UIEdgeInsets edgeInsets,
                                             bool centerVertically) {
        if (!texture)
            return;

        ((DisplayTextureText*)texture)
            ->SetParams(font,
                        text,
                        color,
                        alignment,
                        lineBreak,
                        shadowColor,
                        shadowOffset,
                        numLines,
                        edgeInsets,
                        centerVertically);
    }

    virtual DisplayAnimation* GetBasicDisplayAnimation(id animobj,
                                                       NSString* propertyName,
                                                       NSObject* fromValue,
                                                       NSObject* toValue,
                                                       CAMediaTimingProperties* timingProperties) {
        DisplayAnimationBasic* basicAnim =
            new DisplayAnimationBasic(animobj, propertyName, fromValue, toValue, timingProperties);
        return basicAnim;
    }

    virtual DisplayAnimation* GetMoveDisplayAnimation(DisplayAnimation** secondAnimRet,
                                                      id animobj,
                                                      DisplayNode* animNode,
                                                      NSString* typeStr,
                                                      NSString* subtypeStr,
                                                      CAMediaTimingProperties* timingProperties) {
        DisplayAnimationTransition* transitionAnim = new DisplayAnimationTransition(animobj, typeStr, subtypeStr);
        return transitionAnim;
    }

    virtual void RetainAnimation(DisplayAnimation* animation) {
        if (animation)
            animation->AddRef();
    }

    virtual void ReleaseAnimation(DisplayAnimation* animation) {
        if (animation)
            animation->Release();
    }

    virtual void RetainNode(DisplayNode* node) {
        node->AddRef();
    }

    virtual void ReleaseNode(DisplayNode* node) {
        node->Release();
    }

    virtual void RetainDisplayTexture(DisplayTexture* tex) {
        tex->AddRef();
    }

    virtual void ReleaseDisplayTexture(DisplayTexture* tex) {
        tex->Release();
    }

    void SortWindowLevels() {
    }

    virtual bool isTablet() {
        return tabletMode;
    }
    virtual float screenWidth() {
        return ::screenWidth;
    }
    virtual float screenHeight() {
        return ::screenHeight;
    }
    virtual float screenScale() {
        return ::screenMagnification * [[UIApplication displayMode] hostScreenScale];
    }
    virtual int deviceWidth() {
        return ::deviceWidth;
    }
    virtual int deviceHeight() {
        return ::deviceHeight;
    }
    virtual float screenXDpi() {
        return ::screenXDpi;
    }
    virtual float screenYDpi() {
        return ::screenYDpi;
    }

    virtual void ProcessTransactions() {
        for (auto& cur : _queuedTransactions) {
            cur->Process();
            delete cur;
        }
        _queuedTransactions.clear();
    }

    virtual void RequestRedraw() {
        _client->RequestRedraw();
        CASignalDisplayLink();
    }

    virtual void setScreenSize(float width, float height, float scale, float rotation) {
        ::screenWidth = width;
        ::screenHeight = height;
        ::screenMagnification = scale;
        SetScreenParameters(::screenWidth, ::screenHeight, ::screenMagnification, rotation);
    }

    virtual void setDeviceSize(int width, int height) {
        ::deviceWidth = width;
        ::deviceHeight = height;
    }

    virtual void setScreenDpi(int xDpi, int yDpi) {
        ::screenXDpi = xDpi;
        ::screenYDpi = yDpi;
    }

    virtual void setTablet(bool isTablet) {
        ::tabletMode = isTablet;
    }

    void EnableDisplaySyncNotification() {
        EnableRenderingListener(OnRenderedFrame);
    }

    void DisableDisplaySyncNotification() {
        DisableRenderingListener();
    }

    NSObject* getDisplayProperty(DisplayNode* node, const char* propertyName) {
        return (NSObject*)node->GetProperty(propertyName);
    }

    void IncrementCounter(const char* name) {
        ::IncrementCounter(name);
    }

    void DecrementCounter(const char* name) {
        ::DecrementCounter(name);
    }

    DisplayTexture* CreateDisplayTextureForElement(id xamlElement) {
        GenericControlXaml* genericControlTexture = new GenericControlXaml([(RTObject*)xamlElement internalObject]);
        return genericControlTexture;
    }
};

void SetUIHandlers();

class XamlCompositorClient : public CACompositorClientInterface {
public:
    XamlCompositorClient() {
    }

    void RequestRedraw() {
    }

    void RequestTransactionProcessing() {
        UIRequestTransactionProcessing();
    }

    void SetLandscape(bool isLandscape) {
    }
};

void SetCACompositorClient(CACompositorClientInterface* client);

void CreateXamlCompositor(winobjc::Id& root) {
    CGImageAddDestructionListener(UIReleaseDisplayTextureForCGImage);
    static CAXamlCompositor* compIntr = new CAXamlCompositor();
    static XamlCompositorClient* client = new XamlCompositorClient();

    SetCACompositor(compIntr);
    SetCACompositorClient(client);

    EbrGetMediaTime();
    SetUIHandlers();
    _client = client;
    SetRootGrid(root);
}

void IWXamlTouch(float x, float y, unsigned int touchID, int event, unsigned __int64 timestampMicro) {
    UIQueueTouchInput(x, y, touchID, event, screenWidth, screenHeight, timestampMicro * 1000);
}

void IWXamlKeyInput(int key) {
    UIQueueKeyInput(key);
}

void GridSizeChanged(float newWidth, float newHeight) {
    [[UIApplication displayMode] _setWindowSize:CGSizeMake(newWidth, newHeight)];
    [[UIApplication displayMode] _updateDisplaySettings];
}