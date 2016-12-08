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

#include <COMIncludes.h>
#include <d2d1.h>
#import <WRLHelpers.h>
#include <COMIncludes_End.h>

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

HRESULT _CGPathGetGeometry(CGPathRef path, ID2D1Geometry** pGeometry);
HRESULT _CGPathApplyInternal(Microsoft::WRL::ComPtr<ID2D1PathGeometry> pathGeometry, void* info, CGPathApplierFunction function);

#endif