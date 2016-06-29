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

#include "CFBridgeBase.h"
#include "CoreGraphics/CGContext.h"
#include "CoreGraphics/CGPath.h"

const int kCGPathMaxPointCount = 3;

struct CGPathElementInternal : CGPathElement {
    // Internal representation of points used to simplify size calculations
    // CGPoint* points in CGPathElement should always point to this array
    CGPoint internalPoints[kCGPathMaxPointCount];

    // Constructor. Used to adjust array pointer after creation.
    CGPathElementInternal() : CGPathElement() {
        this->init();
    }
    // Copy Constructor. Used to adjust array pointer after copy.
    CGPathElementInternal(const CGPathElementInternal& copy) : CGPathElement(copy) {
        memcpy(this->internalPoints, copy.internalPoints, sizeof(internalPoints));
        this->init();
    }
    // Assignment operator. Used to adjust array pointer after assignment.
    CGPathElementInternal& operator=(const CGPathElementInternal& copy) {
        CGPathElement::operator=(copy);
        memcpy(this->internalPoints, copy.internalPoints, sizeof(internalPoints));
        this->init();
        return *this;
    }
    // This should be called when elements are created with alloc/memcpy
    void init() {
        this->points = internalPoints;
    }
};
typedef struct CGPathElementInternal CGPathElementInternal;

struct __CGPath : public CFBridgeBase<__CGPath> {
    CGPathElementInternal* _elements;
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
