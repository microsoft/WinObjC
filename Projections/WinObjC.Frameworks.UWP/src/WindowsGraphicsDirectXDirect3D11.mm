//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsGraphicsDirectXDirect3D11.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.DirectX.Direct3D11.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"

@implementation WGDDIDirect3DDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)trim {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Trim());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WGDDIDirect3DSurface

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGDDDirect3DSurfaceDescription*)Description {
    ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return WGDDDirect3DSurfaceDescription_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WGDDDirect3DMultisampleDescription {
    ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription)s {
    WGDDDirect3DMultisampleDescription* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription*)internalStruct {
    return &structVal;
}
- (int)count {
    return structVal.Count;
}
- (void)setCount:(int)val {
    structVal.Count = val;
}
- (int)quality {
    return structVal.Quality;
}
- (void)setQuality:(int)val {
    structVal.Quality = val;
}
@end
@implementation WGDDDirect3DSurfaceDescription {
    ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription)s {
    WGDDDirect3DSurfaceDescription* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription*)internalStruct {
    return &structVal;
}
- (int)width {
    return structVal.Width;
}
- (void)setWidth:(int)val {
    structVal.Width = val;
}
- (int)height {
    return structVal.Height;
}
- (void)setHeight:(int)val {
    structVal.Height = val;
}
- (WGDDirectXPixelFormat)format {
    return (WGDDirectXPixelFormat)structVal.Format;
}
- (void)setFormat:(WGDDirectXPixelFormat)val {
    structVal.Format = (ABI::Windows::Graphics::DirectX::DirectXPixelFormat)val;
}
- (WGDDDirect3DMultisampleDescription*)multisampleDescription {
    return WGDDDirect3DMultisampleDescription_create(structVal.MultisampleDescription);
}
- (void)setMultisampleDescription:(WGDDDirect3DMultisampleDescription*)val {
    structVal.MultisampleDescription = *[val internalStruct];
}
@end
