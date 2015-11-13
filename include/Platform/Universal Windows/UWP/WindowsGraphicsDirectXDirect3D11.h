//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsGraphicsDirectXDirect3D11.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGDDDirect3DMultisampleDescription, WGDDDirect3DSurfaceDescription;
@protocol WGDDIDirect3DDevice
, WGDDIDirect3DSurface;

// Windows.Graphics.DirectX.Direct3D11.Direct3DUsage
enum _WGDDDirect3DUsage {
    WGDDDirect3DUsageDefault = 0,
    WGDDDirect3DUsageImmutable = 1,
    WGDDDirect3DUsageDynamic = 2,
    WGDDDirect3DUsageStaging = 3,
};
typedef unsigned WGDDDirect3DUsage;

// Windows.Graphics.DirectX.Direct3D11.Direct3DBindings
enum _WGDDDirect3DBindings {
    WGDDDirect3DBindingsVertexBuffer = 1,
    WGDDDirect3DBindingsIndexBuffer = 2,
    WGDDDirect3DBindingsConstantBuffer = 4,
    WGDDDirect3DBindingsShaderResource = 8,
    WGDDDirect3DBindingsStreamOutput = 16,
    WGDDDirect3DBindingsRenderTarget = 32,
    WGDDDirect3DBindingsDepthStencil = 64,
    WGDDDirect3DBindingsUnorderedAccess = 128,
    WGDDDirect3DBindingsDecoder = 512,
    WGDDDirect3DBindingsVideoEncoder = 1024,
};
typedef unsigned WGDDDirect3DBindings;

#include "WindowsFoundation.h"
#include "WindowsGraphicsDirectX.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.DirectX.Direct3D11.Direct3DMultisampleDescription
WINRT_EXPORT
@interface WGDDDirect3DMultisampleDescription : NSObject
+ (instancetype) new;
@property int count;
@property int quality;
@end

// [struct] Windows.Graphics.DirectX.Direct3D11.Direct3DSurfaceDescription
WINRT_EXPORT
@interface WGDDDirect3DSurfaceDescription : NSObject
+ (instancetype) new;
@property int width;
@property int height;
@property WGDDirectXPixelFormat format;
@property (copy) WGDDDirect3DMultisampleDescription* multisampleDescription;
@end

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Graphics.DirectX.Direct3D11.IDirect3DDevice
#ifndef __WGDDIDirect3DDevice_DEFINED__
#define __WGDDIDirect3DDevice_DEFINED__

@protocol WGDDIDirect3DDevice <WFIClosable>
- (void)trim;
- (void)close;
@end

#endif // __WGDDIDirect3DDevice_DEFINED__

// Windows.Graphics.DirectX.Direct3D11.IDirect3DSurface
#ifndef __WGDDIDirect3DSurface_DEFINED__
#define __WGDDIDirect3DSurface_DEFINED__

@protocol WGDDIDirect3DSurface <WFIClosable>
@property (readonly) WGDDDirect3DSurfaceDescription* description;
- (void)close;
@end

#endif // __WGDDIDirect3DSurface_DEFINED__
