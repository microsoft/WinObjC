//******************************************************************************
//
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

#import <UIKit/UIColor.h>
#import <CFCppBase.h>
#import "CGColorInternal.h"
#import <CoreGraphics/CoreGraphics.h>

typedef struct {
    double r; // percent
    double g; // percent
    double b; // percent
} rgb;

typedef struct {
    double h; // angle in degrees
    double s; // percent
    double v; // percent
} hsv;

hsv rgb2hsv(rgb in);
rgb hsv2rgb(hsv in);

@interface UIColor (Internal)
+ (UIColor*)_windowsTableViewCellSelectionBackgroundColor;
@end
