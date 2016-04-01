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

#import <Metal/MetalExport.h>
#import <Foundation/NSObject.h>

@protocol MTLDevice;
@class NSString;

#define MTLResourceCPUCacheModeShift 0
#define MTLResourceStorageModeShift 4

typedef NS_ENUM(NSUInteger, MTLCPUCacheMode) { MTLCPUCacheModeDefaultCache = 0, MTLCPUCacheModeWriteCombined = 1 };

typedef NS_ENUM(NSUInteger, MTLStorageMode) {
    MTLStorageModeShared = 0,
    MTLStorageModePrivate = 2,
};

typedef NS_ENUM(NSUInteger, MTLResourceOptions) {
    MTLResourceCPUCacheModeDefaultCache = MTLCPUCacheModeDefaultCache << MTLResourceCPUCacheModeShift,
    MTLResourceCPUCacheModeWriteCombined = MTLCPUCacheModeWriteCombined << MTLResourceCPUCacheModeShift,
    MTLResourceStorageModeShared = MTLStorageModeShared << MTLResourceStorageModeShift,
    MTLResourceStorageModePrivate = MTLStorageModePrivate << MTLResourceStorageModeShift,
    MTLResourceOptionCPUCacheModeDefault = MTLResourceCPUCacheModeDefaultCache,
    MTLResourceOptionCPUCacheModeWriteCombined = MTLResourceCPUCacheModeWriteCombined,
};

typedef NS_ENUM(NSUInteger, MTLPurgeableState) {
    MTLPurgeableStateKeepCurrent = 1,
    MTLPurgeableStateNonVolatile = 2,
    MTLPurgeableStateVolatile = 3,
    MTLPurgeableStateEmpty = 4
};

@protocol MTLResource <NSObject>

@property (readonly) MTLCPUCacheMode cpuCacheMode;
@property (readonly) MTLStorageMode storageMode;
@property (readonly) id<MTLDevice> device;
@property (copy, atomic) NSString* label;

- (MTLPurgeableState)setPurgeableState:(MTLPurgeableState)state;

@end
