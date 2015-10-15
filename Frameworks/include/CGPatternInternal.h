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

#ifndef __CGPATTERNINTERNAL_H
#define __CGPATTERNINTERNAL_H

#include "CoreGraphics/CGPattern.h"

@interface CGPattern : NSObject {
@public
    void* info;
    CGRect bounds;
    CGAffineTransform matrix;
    float xStep, yStep;
    DWORD tiling;
    BOOL isColored;
    CGPatternCallbacks callbacks;
    surfaceFormat surfaceFmt;
}
- (CGImageRef)getPatternImage;
- (CGAffineTransform)getPatternTransform;
+ (instancetype)patternWithImage:(CGImageRef)img;
@end

#endif