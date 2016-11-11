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

HRESULT _CGGetD2DFactory(ID2D1Factory** factory) {
    static ComPtr<ID2D1Factory> sFactory;
    static HRESULT sHr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory), &sFactory);

    sFactory.CopyTo(factory);
    RETURN_HR(sHr);
}

HRESULT _CGGetWICFactory(IWICImagingFactory** factory) {
    static ComPtr<IWICImagingFactory> sWicFactory;
    static HRESULT sHr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&sWicFactory));
    sWicFactory.CopyTo(factory);
    RETURN_HR(sHr);
}

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