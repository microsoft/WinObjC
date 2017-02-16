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
    static HRESULT sHr = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, __uuidof(ID2D1Factory), &sFactory);
    sFactory.CopyTo(factory);
    RETURN_HR(sHr);
}

HRESULT _CGGetWICFactory(IWICImagingFactory** factory) {
    static ComPtr<IWICImagingFactory> sWicFactory;
    static HRESULT sHr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&sWicFactory));
    sWicFactory.CopyTo(factory);
    RETURN_HR(sHr);
}