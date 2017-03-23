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
#import <vector>
#import "CoreGraphicsInternal.h"
#include <objc/runtime.h>

size_t _CGGradientGetCount(CGGradientRef gradient);

const std::vector<CGFloat>& _CGGradientGetStopLocations(CGGradientRef gradient);

const std::vector<CGFloat>& _CGGradientGetColorComponents(CGGradientRef gradient);

CGColorSpaceRef _CGGradientGetColorSpace(CGGradientRef gradient);