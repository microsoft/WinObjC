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

#import <Foundation/NSObject.h>
#import <Metal/MetalExport.h>
#import <Metal/MTLTexture.h>

@class NSString;
@class MTLStructType;

typedef NS_ENUM(NSUInteger, MTLArgumentAccess) {
    MTLArgumentAccessReadOnly = 0,
    MTLArgumentAccessReadWrite = 1,
    MTLArgumentAccessWriteOnly = 2
};

typedef NS_ENUM(NSUInteger, MTLArgumentType) {
    MTLArgumentTypeBuffer = 0,
    MTLArgumentTypeThreadgroupMemory = 1,
    MTLArgumentTypeTexture = 2,
    MTLArgumentTypeSampler = 3
};

typedef NS_ENUM(NSUInteger, MTLDataType) {
    MTLDataTypeNone = 0,
    MTLDataTypeStruct = 1,
    MTLDataTypeArray = 2,
    MTLDataTypeFloat = 3,
    MTLDataTypeFloat2 = 4,
    MTLDataTypeFloat3 = 5,
    MTLDataTypeFloat4 = 6,
    MTLDataTypeFloat2x2 = 7,
    MTLDataTypeFloat2x3 = 8,
    MTLDataTypeFloat2x4 = 9,
    MTLDataTypeFloat3x2 = 10,
    MTLDataTypeFloat3x3 = 11,
    MTLDataTypeFloat3x4 = 12,
    MTLDataTypeFloat4x2 = 13,
    MTLDataTypeFloat4x3 = 14,
    MTLDataTypeFloat4x4 = 15,
    MTLDataTypeHalf = 16,
    MTLDataTypeHalf2 = 17,
    MTLDataTypeHalf3 = 18,
    MTLDataTypeHalf4 = 19,
    MTLDataTypeHalf2x2 = 20,
    MTLDataTypeHalf2x3 = 21,
    MTLDataTypeHalf2x4 = 22,
    MTLDataTypeHalf3x2 = 23,
    MTLDataTypeHalf3x3 = 24,
    MTLDataTypeHalf3x4 = 25,
    MTLDataTypeHalf4x2 = 26,
    MTLDataTypeHalf4x3 = 27,
    MTLDataTypeHalf4x4 = 28,
    MTLDataTypeInt = 29,
    MTLDataTypeInt2 = 30,
    MTLDataTypeInt3 = 31,
    MTLDataTypeInt4 = 32,
    MTLDataTypeUInt = 33,
    MTLDataTypeUInt2 = 34,
    MTLDataTypeUInt3 = 35,
    MTLDataTypeUInt4 = 36,
    MTLDataTypeShort = 37,
    MTLDataTypeShort2 = 38,
    MTLDataTypeShort3 = 39,
    MTLDataTypeShort4 = 40,
    MTLDataTypeUShort = 41,
    MTLDataTypeUShort2 = 42,
    MTLDataTypeUShort3 = 43,
    MTLDataTypeUShort4 = 44,
    MTLDataTypeChar = 45,
    MTLDataTypeChar2 = 46,
    MTLDataTypeChar3 = 47,
    MTLDataTypeChar4 = 48,
    MTLDataTypeUChar = 49,
    MTLDataTypeUChar2 = 50,
    MTLDataTypeUChar3 = 51,
    MTLDataTypeUChar4 = 52,
    MTLDataTypeBool = 53,
    MTLDataTypeBool2 = 54,
    MTLDataTypeBool3 = 55,
    MTLDataTypeBool4 = 56
};

METAL_EXPORT_CLASS
@interface MTLArgument : NSObject

@property (readonly) NSString* name STUB_PROPERTY;
@property (readonly) MTLArgumentAccess access STUB_PROPERTY;
@property (readonly, getter=isActive) BOOL active STUB_PROPERTY;
@property (readonly) NSUInteger index STUB_PROPERTY;
@property (readonly) MTLArgumentType type STUB_PROPERTY;
@property (readonly) NSUInteger bufferAlignment STUB_PROPERTY;
@property (readonly) NSUInteger bufferDataSize STUB_PROPERTY;
@property (readonly) MTLDataType bufferDataType STUB_PROPERTY;
@property (readonly) MTLStructType* bufferStructType STUB_PROPERTY;
@property (readonly) MTLDataType textureDataType STUB_PROPERTY;
@property (readonly) MTLTextureType textureType STUB_PROPERTY;
@property (readonly) NSUInteger threadgroupMemoryAlignment STUB_PROPERTY;
@property (readonly) NSUInteger threadgroupMemoryDataSize STUB_PROPERTY;

@end
