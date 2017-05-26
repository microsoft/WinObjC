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

// WindowsGraphicsDirectXDirect3D11_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsDirectX_priv.h"
@interface WGDDDirect3DMultisampleDescription (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription*)internalStruct;
@end
inline WGDDDirect3DMultisampleDescription* WGDDDirect3DMultisampleDescription_create(
    ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription val) {
    return [WGDDDirect3DMultisampleDescription createWith:val];
}
@interface WGDDDirect3DSurfaceDescription (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription*)internalStruct;
@end
inline WGDDDirect3DSurfaceDescription* WGDDDirect3DSurfaceDescription_create(
    ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription val) {
    return [WGDDDirect3DSurfaceDescription createWith:val];
}
