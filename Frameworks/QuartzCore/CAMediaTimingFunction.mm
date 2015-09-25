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

#include "Starboard.h"
#include "Etc.h"
#include "QuartzCore/CAMediaTimingFunction.h"
#include "QuartzCore/CALayer.h"

__declspec(dllexport) float applyMediaTimingFunction(id function, float t) {
    if (function == nil)
        return t;
    float cp1[2];
    float cp2[2];

    CAMediaTimingFunction* pFunc = (CAMediaTimingFunction*)function;

    cp1[0] = pFunc->_c1x;
    cp1[1] = pFunc->_c1y;
    cp2[0] = pFunc->_c2x;
    cp2[1] = pFunc->_c2y;

    double x =
        cubed(1.0 - t) * 0.0 + 3 * squared(1 - t) * t * cp1[0] + 3 * (1 - t) * squared(t) * cp2[0] + cubed(t) * 1.0;
    double y =
        cubed(1.0 - t) * 0.0 + 3 * squared(1 - t) * t * cp1[1] + 3 * (1 - t) * squared(t) * cp2[1] + cubed(t) * 1.0;

    // this is wrong
    return (float)y;
}

@implementation CAMediaTimingFunction : NSObject
+ (CAMediaTimingFunction*)functionWithName:(NSString*)function {
    char* name = (char*)[function UTF8String];

    if (strcmp(name, "kCAMediaTimingFunctionLinear") == 0)
        return [self functionWithControlPoints:0:0:1:1];
    if (strcmp(name, "kCAMediaTimingFunctionEaseIn") == 0)
        return [self functionWithControlPoints:0.5:0:1:1];
    if (strcmp(name, "kCAMediaTimingFunctionEaseOut") == 0)
        return [self functionWithControlPoints:0:0:0.5:1];
    if (strcmp(name, "kCAMediaTimingFunctionEaseInEaseOut") == 0)
        return [self functionWithControlPoints:0.5:0:0.5:1];
    if (strcmp(name, "kCAMediaTimingFunctionDefault") == 0)
        return [self functionWithControlPoints:0.25f:0.1f:0.25f:1.0f];

    return nil;
}

+ (CAMediaTimingFunction*)functionWithControlPoints:(float)c1x:(float)c1y:(float)c2x:(float)c2y {
    return [[[self alloc] initWithControlPoints:c1x:c1y:c2x:c2y] autorelease];
}

- (instancetype)initWithControlPoints:(float)c1x:(float)c1y:(float)c2x:(float)c2y {
    _c1x = c1x;
    _c1y = c1y;
    _c2x = c2x;
    _c2y = c2y;
    return self;
}

- (void)getControlPointAtIndex:(size_t)index values:(float[2])ptr {
    if (index == 0) {
        ptr[0] = _c1x;
        ptr[1] = _c1y;
    } else {
        ptr[0] = _c2x;
        ptr[1] = _c2y;
    }
}

@end
