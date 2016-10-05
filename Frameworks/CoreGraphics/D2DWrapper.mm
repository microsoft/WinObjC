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

// Private helper for creating a D2DFactory
static ComPtr<ID2D1Factory> __CreateD2DFactoryInstance() {
    ComPtr<ID2D1Factory> d2dFactory;
    THROW_IF_FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, __uuidof(ID2D1Factory), &d2dFactory));
    return d2dFactory;
}

// Helper for accessing a single static multithreaded D2DFactory instance
ComPtr<ID2D1Factory> _GetD2DFactoryInstance() {
    static ComPtr<ID2D1Factory> s_d2dFactory = __CreateD2DFactoryInstance();
    return s_d2dFactory;
}