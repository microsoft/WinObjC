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

#import <Foundation/Foundation.h>
#import <Metal/MetalExport.h>
#import <Metal/MetalDataTypes.h>

@protocol MTLDevice;

METAL_EXPORT id<MTLDevice> MTLCreateSystemDefaultDevice() STUB_METHOD;
METAL_EXPORT MTLOrigin MTLOriginMake(NSUInteger x, NSUInteger y, NSUInteger z) STUB_METHOD;
METAL_EXPORT MTLRegion MTLRegionMake1D(NSUInteger x, NSUInteger width) STUB_METHOD;
METAL_EXPORT MTLRegion MTLRegionMake2D(NSUInteger x, NSUInteger y, NSUInteger width, NSUInteger height) STUB_METHOD;
METAL_EXPORT MTLRegion MTLRegionMake3D(NSUInteger x, NSUInteger y, NSUInteger z, NSUInteger width, NSUInteger height, NSUInteger depth)
    STUB_METHOD;
METAL_EXPORT MTLSize MTLSizeMake(NSUInteger width, NSUInteger height, NSUInteger depth) STUB_METHOD;
METAL_EXPORT MTLClearColor MTLClearColorMake(double red, double green, double blue, double alpha) STUB_METHOD;
