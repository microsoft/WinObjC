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

#import "D2DWrapper.h"
#import <Starboard.h>

using namespace Microsoft::WRL;

HRESULT _CGGetD2DFactory(ID2D1Factory** factory) {
    static ComPtr<ID2D1Factory> sFactory;
    static HRESULT sHr;
    static dispatch_once_t dispatchToken;

    dispatch_once(&dispatchToken, ^{
        sHr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory), &sFactory);
    });

    sFactory.Get()->AddRef();
    sFactory.CopyTo(factory);
    return sHr;
}

static ComPtr<IWICImagingFactory> __createWICFactory() {
    ComPtr<IWICImagingFactory> wicFactory;
    FAIL_FAST_IF_FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&wicFactory)));
    return wicFactory;
}

ComPtr<IWICImagingFactory> _GetWICFactory() {
    static ComPtr<IWICImagingFactory> s_WICFactory = __createWICFactory();
    return s_WICFactory;
}