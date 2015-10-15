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

class CGImageData {
public:
    cairo_surface_t* _surface;
    BOOL _freeWhenDone;
    void* _imageData;
    DWORD _pixmanFmt;
    surfaceFormat _bitmapFmt;
    DWORD _width, _height;
    DWORD _internalWidth, _internalHeight;
    DWORD _bytesPerRow;
    DWORD _bytesPerPixel;
    DWORD _refCount;
    BOOL _bottomOrientation;

    CGImageData* Duplicate();
    CGImageData(DWORD width, DWORD height, surfaceFormat fmt, void* Data);
    ~CGImageData();
};

class CGBitmapImage : public __CGImage {
public:
    CGBitmapImage(DWORD width, DWORD height, surfaceFormat fmt);
    CGBitmapImage(DWORD width, DWORD height, surfaceFormat fmt, void* Data);
    CGBitmapImage(CGImageRef pImg);
};

class CGBitmapImageBacking : public CGImageBacking {
private:
    CGImageData* _data;

public:
    CGBitmapImageBacking(DWORD width, DWORD height, surfaceFormat fmt);
    CGBitmapImageBacking(DWORD width, DWORD height, surfaceFormat fmt, void* Data);
    CGBitmapImageBacking(CGImageRef pImg);

    ~CGBitmapImageBacking();

    CGImageRef Copy();
    CGImageRef CopyOnWrite();

    CGContextImpl* CreateDrawingContext(CGContextRef base);
    void GetPixel(int x, int y, float& r, float& g, float& b, float& a);
    int InternalWidth();
    int InternalHeight();
    int Width();
    int Height();
    int BytesPerRow();
    int BytesPerPixel();
    surfaceFormat SurfaceFormat();
    void* StaticImageData();
    void* LockImageData();
    void ReleaseImageData();
    cairo_surface_t* LockCairoSurface();
    void ReleaseCairoSurface();
    void SetFreeWhenDone(bool freeWhenDone);
};
