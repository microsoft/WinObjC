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

#import <CoreFoundation/CFBase.h>
#import <Foundation/NSObjCRuntime.h>
#import <Metal/MetalExport.h>

typedef struct {
    NSUInteger width;
    NSUInteger height;
    NSUInteger depth;
} MTLSize;

typedef struct {
    double red;
    double green;
    double blue;
    double alpha;
} MTLClearColor;

typedef struct {
    NSUInteger x;
    NSUInteger y;
    NSUInteger z;
} MTLOrigin;

typedef struct {
    MTLOrigin origin;
    MTLSize size;
} MTLRegion;

typedef struct {
    NSUInteger x;
    NSUInteger y;
    NSUInteger width;
    NSUInteger height;
} MTLScissorRect;

typedef struct {
    double originX;
    double originY;
    double width;
    double height;
    double znear;
    double zfar;
} MTLViewport;

typedef struct {
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t vertexStart;
    uint32_t baseInstance;
} MTLDrawPrimitivesIndirectArguments;

typedef struct {
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t indexStart;
    int32_t baseVertex;
    uint32_t baseInstance;
} MTLDrawIndexedPrimitivesIndirectArguments;

typedef struct { uint32_t threadgroupsPerGrid[3]; } MTLDispatchThreadgroupsIndirectArguments;
