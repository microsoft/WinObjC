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

@class NSArray;
@class NSString;

@protocol MTLFunction;
@protocol MTLDevice;

typedef NS_ENUM(NSUInteger, MTLLibraryError) {
    MTLLibraryErrorUnsupported = 1,
    MTLLibraryErrorInternal = 2,
    MTLLibraryErrorCompileFailure = 3,
    MTLLibraryErrorCompileWarning = 4
};

typedef NS_ENUM(NSUInteger, MTLRenderPipelineError) {
    MTLRenderPipelineErrorInternal = 1,
    MTLRenderPipelineErrorUnsupported = 2,
    MTLRenderPipelineErrorInvalidInput = 3
};

typedef NS_ENUM(NSUInteger, MTLLanguageVersion) {
    MTLLanguageVersion1_0 = (1 << 16),
    MTLLanguageVersion1_1 = (1 << 16) + 1,
};

METAL_EXPORT NSString* const MTLLibraryErrorDomain;
METAL_EXPORT NSString* const MTLRenderPipelineErrorDomain;

@protocol MTLLibrary <NSObject>

@property (readonly)NSArray* functionNames;
@property (readonly)id<MTLDevice> device;
@property (copy, atomic) NSString* label;

- (id<MTLFunction>)newFunctionWithName:(NSString*)functionName;

@end
