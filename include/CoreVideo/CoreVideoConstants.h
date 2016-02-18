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
#import <CoreVideo/CoreVideoExport.h>

enum {
    kCVReturnSuccess = 0,
    kCVReturnFirst = -6660,
    kCVReturnError = -6660,
    kCVReturnInvalidArgument = -6661,
    kCVReturnAllocationFailed = -6662,
    kCVReturnInvalidDisplay = -6670,
    kCVReturnDisplayLinkAlreadyRunning = -6671,
    kCVReturnDisplayLinkNotRunning = -6672,
    kCVReturnDisplayLinkCallbacksNotSet = -6673,
    kCVReturnInvalidPixelFormat = -6680,
    kCVReturnInvalidSize = -6681,
    kCVReturnInvalidPixelBufferAttributes = -6682,
    kCVReturnPixelBufferNotOpenGLCompatible = -6683,
    kCVReturnPixelBufferNotMetalCompatible = -6684,
    kCVReturnWouldExceedAllocationThreshold = -6689,
    kCVReturnPoolAllocationFailed = -6690,
    kCVReturnInvalidPoolAttributes = -6691,
    kCVReturnLast = -6699
};