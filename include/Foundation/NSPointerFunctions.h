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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;

typedef NS_OPTIONS(NSUInteger, NSPointerFunctionsOptions) {
    NSPointerFunctionsStrongMemory = (0 << 0),
    NSPointerFunctionsOpaqueMemory = (2 << 0),
    NSPointerFunctionsMallocMemory = (3 << 0),
    NSPointerFunctionsMachVirtualMemory = (4 << 0),
    NSPointerFunctionsWeakMemory = (5UL << 0),
    NSPointerFunctionsObjectPersonality = (0 << 8),
    NSPointerFunctionsOpaquePersonality = (1 << 8),
    NSPointerFunctionsObjectPointerPersonality = (2 << 8),
    NSPointerFunctionsCStringPersonality = (3 << 8),
    NSPointerFunctionsStructPersonality = (4 << 8),
    NSPointerFunctionsIntegerPersonality = (5 << 8),
    NSPointerFunctionsCopyIn = (1 << 16),
};

FOUNDATION_EXPORT_CLASS
@interface NSPointerFunctions : NSObject <NSCopying>

- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options;
+ (NSPointerFunctions*)pointerFunctionsWithOptions:(NSPointerFunctionsOptions)options;

@property (nonnull) NSUInteger (*hashFunction)(const void*, NSUInteger (*)(const void*));
@property (nonnull) BOOL (*isEqualFunction)(const void*, const void*, NSUInteger (*)(const void*));
@property (nonnull) NSUInteger (*sizeFunction)(const void*);
@property (nullable) NSString* (*descriptionFunction)(const void*);
@property (nonnull) void* (*acquireFunction)(const void*, NSUInteger (*)(const void*), BOOL);
@property (nonnull) void (*relinquishFunction)(const void*, NSUInteger (*)(const void*));
@property BOOL usesStrongWriteBarrier;
@property BOOL usesWeakReadAndWriteBarriers;

@end
