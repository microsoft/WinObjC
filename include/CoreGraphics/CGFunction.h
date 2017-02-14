//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreGraphics/CoreGraphicsExport.h>

typedef struct __CGFunction* CGFunctionRef;

#import <CoreGraphics/CGGeometry.h>

typedef void (*CGFunctionEvaluateCallback)(void* info, const float* inData, float* outData);
typedef void (*CGFunctionReleaseInfoCallback)(void* info);
typedef struct {
    unsigned int version;
    CGFunctionEvaluateCallback evaluate;
    CGFunctionReleaseInfoCallback releaseInfo;
} CGFunctionCallbacks;

COREGRAPHICS_EXPORT CGFunctionRef CGFunctionCreate(void* info,
                                                   size_t domainDimension,
                                                   const CGFloat* domain,
                                                   size_t rangeDimension,
                                                   const CGFloat* range,
                                                   const CGFunctionCallbacks* callbacks) STUB_METHOD;
COREGRAPHICS_EXPORT void CGFunctionRelease(CGFunctionRef function) STUB_METHOD;
COREGRAPHICS_EXPORT CGFunctionRef CGFunctionRetain(CGFunctionRef function) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGFunctionGetTypeID() STUB_METHOD;