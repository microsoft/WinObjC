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

#ifndef __CGPATHINTERNAL_H
#define __CGPATHINTERNAL_H

#include "CoreGraphics/CGContext.h"
#include "CoreGraphics/CGPath.h"
#include "CFBridgeBase.h"


struct __CGPath : public CFBridgeBase<__CGPath> {
	CGPathElement* _components;
    NSUInteger _count;
    NSUInteger _max;

    ~__CGPath();
    void _getBoundingBox(CGRect* rectOut);
	void _applyPath(CGContextRef context);
};

COREGRAPHICS_EXPORT CGRect _CGPathFitRect(CGPathRef pathref, CGRect rect, CGSize maxSize, float padding);
COREGRAPHICS_EXPORT void _CGPathApplyPath(CGPathRef pathref, CGContextRef context);
COREGRAPHICS_EXPORT void _CGPathGetBoundingBoxInternal(CGPathRef pathref, CGRect* rectOut);

#endif
