//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreGraphics/CGGradient.h>
#import "CoreGraphicsInternal.h"
#include <objc/runtime.h>

class __CGGradient : private objc_object {
public:
    __CGSurfaceFormat _format;
    CGColorSpaceModel _colorSpaceModel;
    float* _components;
    float* _locations;
    DWORD _count;

    __CGGradient();
    ~__CGGradient();
    void initWithColorComponents(const float* components, const float* locations, size_t count, CGColorSpaceRef colorspace);
    void initWithColors(CFArrayRef components, const float* locations, CGColorSpaceRef colorspace);
};

COREGRAPHICS_EXPORT unsigned long _CGGradientGetCount(CGGradientRef gradient);

COREGRAPHICS_EXPORT float* _CGGradientGetStopLocation(CGGradientRef gradient);

COREGRAPHICS_EXPORT float* _CGGradientGetColorComponents(CGGradientRef gradient);

COREGRAPHICS_EXPORT CGColorSpaceModel _CGGradientGetColorSpaceModel(CGGradientRef gradient);