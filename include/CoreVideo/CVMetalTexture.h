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
#import <CoreFoundation/CFBase.h>

#import <CoreVideo/CVImageBuffer.h>

@protocol MTLTexture;

typedef CVImageBufferRef CVMetalTextureRef;

COREVIDEO_EXPORT CFTypeID CVMetalTextureGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT id<MTLTexture> CVMetalTextureGetTexture(CVMetalTextureRef image) STUB_METHOD;
COREVIDEO_EXPORT Boolean CVMetalTextureIsFlipped(CVMetalTextureRef image) STUB_METHOD;
COREVIDEO_EXPORT void CVMetalTextureGetCleanTexCoords(
    CVMetalTextureRef image, float lowerLeft[2], float lowerRight[2], float upperRight[2], float upperLeft[2]) STUB_METHOD;