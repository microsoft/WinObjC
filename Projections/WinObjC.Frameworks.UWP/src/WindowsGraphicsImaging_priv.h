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

// WindowsGraphicsImaging_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
static ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTypedValueFactory> WGIIBitmapTypedValueFactory_inst();
ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoderStatics> WGIIBitmapDecoderStatics_inst();
ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoderStatics> WGIIBitmapEncoderStatics_inst();
static ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapFactory> WGIISoftwareBitmapFactory_inst();
ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapStatics> WGIISoftwareBitmapStatics_inst();
@interface WGIBitmapBounds (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapBounds)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Imaging::BitmapBounds*)internalStruct;
@end
inline WGIBitmapBounds* WGIBitmapBounds_create(ABI::Windows::Graphics::Imaging::BitmapBounds val) {
    return [WGIBitmapBounds createWith:val];
}
@interface WGIBitmapSize (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapSize)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Imaging::BitmapSize*)internalStruct;
@end
inline WGIBitmapSize* WGIBitmapSize_create(ABI::Windows::Graphics::Imaging::BitmapSize val) {
    return [WGIBitmapSize createWith:val];
}
@interface WGIBitmapPlaneDescription (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapPlaneDescription)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Imaging::BitmapPlaneDescription*)internalStruct;
@end
inline WGIBitmapPlaneDescription* WGIBitmapPlaneDescription_create(ABI::Windows::Graphics::Imaging::BitmapPlaneDescription val) {
    return [WGIBitmapPlaneDescription createWith:val];
}

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create(IInspectable* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WGIBitmapCodecInformation_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue,
    RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue;
@class RTProxiedNSArray_C_UInt8, RTProxiedNSArray_NSString, RTProxiedNSArray_WGIBitmapCodecInformation;

typedef IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*
    IKeyValuePair_HSTRING_Graphics_Imaging_BitmapTypedValuePtr_Ptr;
