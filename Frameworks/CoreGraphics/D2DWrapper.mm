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

#import <CoreGraphics/D2DWrapper.h>
#import <Starboard.h>

using namespace Microsoft::WRL;

namespace {
template <typename T>
// HRComPtr is a ComPtr bundled with an HRESULT. Since the below factory functions
// have two effective return values, both of which are statically computed on first
// request, we need to use this to ensure defined behaviour.
//
// Contrast HRComPtr with this approach:
// static ComPtr<IUnknown> x;
// static HRESULT y = CoCreateInstance(... &x ...);
//
// It cannot safely be said that ComPtr::ComPtr() has been called before CoCreateInstance,
// especially when multiple threads contend for the lock on x.
struct HRComPtr {
    HRESULT hr;
    ComPtr<T> ptr;
};
}

HRESULT _CGGetD2DFactory(ID2D1Factory** factory) {
    static auto sFactory = []() -> HRComPtr<ID2D1Factory> {
        ComPtr<ID2D1Factory> factory;
        HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, factory.ReleaseAndGetAddressOf());
        return { hr, std::move(factory) };
    }();
    sFactory.ptr.CopyTo(factory);
    return sFactory.hr;
}

HRESULT _CGGetWICFactory(IWICImagingFactory** factory) {
    static auto sFactory = []() -> HRComPtr<IWICImagingFactory> {
        ComPtr<IWICImagingFactory> factory;
        HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));
        return { hr, std::move(factory) };
    }();
    sFactory.ptr.CopyTo(factory);
    return sFactory.hr;
}

// TODO GH#1375: Remove this when CGPath's fill mode has been worked out.
HRESULT _CGConvertD2DGeometryToFillMode(ID2D1Geometry* geometry, D2D1_FILL_MODE fillMode, ID2D1Geometry** pNewGeometry) {
    ComPtr<ID2D1Factory> factory;
    geometry->GetFactory(&factory);

    ComPtr<ID2D1GeometryGroup> geometryGroup;
    RETURN_IF_FAILED(factory->CreateGeometryGroup(fillMode, &geometry, 1, &geometryGroup));

    ComPtr<ID2D1Geometry> outGeometry;
    RETURN_IF_FAILED(geometryGroup.As(&outGeometry));

    *pNewGeometry = outGeometry.Detach();
    return S_OK;
}