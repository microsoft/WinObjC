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
#import "LayerProxy.h"

#import <UIKit/NSValue+UIKitAdditions.h>
#import <UIKit/UIImage.h>

#import <QuartzCore/CATransform3D.h>

#import "Quaternion.h"
#import "UIColorInternal.h"

static const wchar_t* TAG = L"LayerProxy";

void LayerProxy::SetTexture(const std::shared_ptr<IDisplayTexture>& texture, float width, float height, float contentScale) {
    _currentTexture = texture;
    _SetContents((texture ? texture->GetContent() : nullptr), width, height, contentScale);
}

void* LayerProxy::GetPropertyValue(const char* name) {
    if (strcmp(name, "position") == 0) {
        CGPoint pos;

        pos.x = _GetPresentationPropertyValue("position.x");
        pos.y = _GetPresentationPropertyValue("position.y");

        return [NSValue valueWithCGPoint:pos];
    } else if (strcmp(name, "bounds.origin") == 0) {
        CGPoint pos;

        pos.x = _GetPresentationPropertyValue("origin.x");
        pos.y = _GetPresentationPropertyValue("origin.y");

        return [NSValue valueWithCGPoint:pos];
    } else if (strcmp(name, "bounds.size") == 0) {
        CGSize size;

        size.width = _GetPresentationPropertyValue("size.width");
        size.height = _GetPresentationPropertyValue("size.height");

        return [NSValue valueWithCGSize:size];
    } else if (strcmp(name, "bounds") == 0) {
        CGRect rect;

        rect.size.width = _GetPresentationPropertyValue("size.width");
        rect.size.height = _GetPresentationPropertyValue("size.height");
        rect.origin.x = _GetPresentationPropertyValue("origin.x");
        rect.origin.y = _GetPresentationPropertyValue("origin.y");

        return [NSValue valueWithCGRect:rect];
    } else if (strcmp(name, "opacity") == 0) {
        float value = _GetPresentationPropertyValue("opacity");
        return [NSNumber numberWithFloat:value];
    } else if (strcmp(name, "transform") == 0) {
        float angle = _GetPresentationPropertyValue("transform.rotation");
        float scale[2];
        float translation[2];

        scale[0] = _GetPresentationPropertyValue("transform.scale.x");
        scale[1] = _GetPresentationPropertyValue("transform.scale.y");

        translation[0] = _GetPresentationPropertyValue("transform.translation.x");
        translation[1] = _GetPresentationPropertyValue("transform.translation.y");

        CATransform3D trans = CATransform3DMakeRotation(-angle * M_PI / 180.0f, 0, 0, 1.0f);
        trans = CATransform3DScale(trans, scale[0], scale[1], 0.0f);
        trans = CATransform3DTranslate(trans, translation[0], translation[1], 0.0f);

        return [NSValue valueWithCATransform3D:trans];
    } else if (strcmp(name, "borderColor") == 0) {
        LayerColor color = _GetBorderColor();
        CGColorRef colorRef = CGColorCreateGenericRGB(color.r, color.g, color.b, color.a);
        CFAutorelease(colorRef);
        return static_cast<void*>(colorRef);
    } else if (strcmp(name, "borderWidth") == 0) {
        return [NSNumber numberWithFloat:_GetBorderWidth()];
    }

    FAIL_FAST_HR(E_NOTIMPL);
    return nil;
}

void LayerProxy::UpdateProperty(const char* name, void* value) {
    NSObject* newValue = (NSObject*)value;
    if (name == NULL)
        return;
    if ([NSThread currentThread] != [NSThread mainThread]) {
        return;
    }

    if (strcmp(name, "contentsCenter") == 0) {
        CGRect value = [(NSValue*)newValue CGRectValue];
        _SetContentsCenter(value.origin.x, value.origin.y, value.size.width, value.size.height);
    } else if (strcmp(name, "anchorPoint") == 0) {
        CGPoint value = [(NSValue*)newValue CGPointValue];
        _SetProperty("anchorPoint.x", value.x);
        _SetProperty("anchorPoint.y", value.y);
    } else if (strcmp(name, "position") == 0) {
        CGPoint position = [(NSValue*)newValue CGPointValue];
        _SetProperty("position.x", position.x);
        _SetProperty("position.y", position.y);
    } else if (strcmp(name, "bounds.origin") == 0) {
        CGPoint value = [(NSValue*)newValue CGPointValue];
        _SetProperty("origin.x", value.x);
        _SetProperty("origin.y", value.y);
    } else if (strcmp(name, "bounds.size") == 0) {
        CGSize size = [(NSValue*)newValue CGSizeValue];
        _SetProperty("size.width", size.width);
        _SetProperty("size.height", size.height);
    } else if (strcmp(name, "opacity") == 0) {
        float value = [(NSNumber*)newValue floatValue];
        _SetProperty("opacity", value);
    } else if (strcmp(name, "hidden") == 0) {
        bool value = [(NSNumber*)newValue boolValue];
        _SetHidden(value);
    } else if (strcmp(name, "masksToBounds") == 0) {
        if (!_isRoot) {
            bool value = [(NSNumber*)newValue boolValue];
            _SetMasksToBounds(value);
        } else {
            _SetMasksToBounds(true);
        }
    } else if (strcmp(name, "transform") == 0) {
        CATransform3D value = [(NSValue*)newValue CATransform3DValue];
        float translation[3] = { 0 };
        float scale[3] = { 0 };

        Quaternion qFrom;
        qFrom.CreateFromMatrix((float*)&(value));

        CATransform3DGetScale(value, scale);
        CATransform3DGetPosition(value, translation);

        _SetProperty("transform.rotation", (float)-qFrom.roll() * 180.0f / M_PI);
        _SetProperty("transform.scale.x", scale[0]);
        _SetProperty("transform.scale.y", scale[1]);
        _SetProperty("transform.translation.x", translation[0]);
        _SetProperty("transform.translation.y", translation[1]);
    } else if (strcmp(name, "contentsScale") == 0) {
        UNIMPLEMENTED_WITH_MSG("contentsScale not implemented");
    } else if (strcmp(name, "contentsOrientation") == 0) {
        int position = [(NSNumber*)newValue intValue];
        float toPosition = 0;
        if (position == UIImageOrientationUp) {
            toPosition = 0;
        } else if (position == UIImageOrientationDown) {
            toPosition = 180;
        } else if (position == UIImageOrientationLeft) {
            toPosition = 270;
        } else if (position == UIImageOrientationRight) {
            toPosition = 90;
        }
        _SetProperty("transform.rotation", toPosition);
    } else if (strcmp(name, "zIndex") == 0) {
        // TODO: We should remove this and just do it on UIWindow's backing element since that's the only place it's used
        int value = [(NSNumber*)newValue intValue];
        _SetZIndex(value);
    } else if (strcmp(name, "gravity") == 0) {
        _SetPropertyInt("gravity", [(NSNumber*)newValue intValue]);
    } else if (strcmp(name, "backgroundColor") == 0) {
        LayerColor layerColor;
        if (newValue) {
            const CGFloat* color = CGColorGetComponents(static_cast<CGColorRef>(newValue));
            layerColor.r = color[0];
            layerColor.g = color[1];
            layerColor.b = color[2];
            layerColor.a = color[3];
        }

        _SetBackgroundColor(layerColor);
    } else if (strcmp(name, "borderColor") == 0) {
        LayerColor layerColor;
        if (newValue) {
            const CGFloat* color = CGColorGetComponents(static_cast<CGColorRef>(newValue));
            layerColor.r = color[0];
            layerColor.g = color[1];
            layerColor.b = color[2];
            layerColor.a = color[3];
        }

        _SetBorderColor(layerColor);
    } else if (strcmp(name, "borderWidth") == 0) {
        float value = [(NSNumber*)newValue floatValue];
        _SetBorderWidth(value);
    } else {
        FAIL_FAST_HR(E_NOTIMPL);
    }
}
