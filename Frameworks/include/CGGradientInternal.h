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

#ifndef __CGGRADIENTINTERNAL_H
#define __CGGRADIENTINTERNAL_H

#include "CoreGraphics/CGGradient.h"

class __CGGradient {
public:
    id isa;
    surfaceFormat _colorSpace;
    float* _components;
    float* _locations;
    DWORD _count;

    __CGGradient();
    ~__CGGradient();
    void initWithColorComponents(const float* components, const float* locations, size_t count, CGColorSpaceRef colorspace);
    void initWithColors(CFArrayRef components, const float* locations, CGColorSpaceRef colorspace);
};
#endif
