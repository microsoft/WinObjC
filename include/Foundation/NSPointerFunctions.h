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

#import <StubIncludes.h>
#import <Foundation/FoundationExport.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSObject.h>

@class NSString;

typedef NSUInteger NSPointerFunctionsOptions;
enum {
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
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options STUB_METHOD;
+ (NSPointerFunctions*)pointerFunctionsWithOptions:(NSPointerFunctionsOptions)options STUB_METHOD;
@property (nonnull) NSUInteger (*hashFunction)(const void*, NSUInteger (*)(const void*)) STUB_PROPERTY;
@property (nonnull) BOOL (*isEqualFunction)(const void*, const void*, NSUInteger (*)(const void*)) STUB_PROPERTY;
@property (nonnull) NSUInteger (*sizeFunction)(const void*) STUB_PROPERTY;
@property (nullable) NSString* (*descriptionFunction)(const void*)STUB_PROPERTY;
@property (nonnull) void* (*acquireFunction)(const void*, NSUInteger (*)(const void*), BOOL)STUB_PROPERTY;
@property (nonnull) void (*relinquishFunction)(const void*, NSUInteger (*)(const void*)) STUB_PROPERTY;
@property BOOL usesStrongWriteBarrier STUB_PROPERTY;
@property BOOL usesWeakReadAndWriteBarriers STUB_PROPERTY;
@end
