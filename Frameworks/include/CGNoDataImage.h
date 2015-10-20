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

class CGNoDataImage : public __CGImage {
public:
    CGNoDataImage(DWORD width, DWORD height, surfaceFormat fmt);
};

class CGNoDataImageBacking : public CGImageBacking {
private:
    surfaceFormat _bitmapFmt;
    DWORD _width, _height;

public:
    DisplayTexture* _generatedTexture;
    CGNoDataImageBacking(DWORD width, DWORD height, surfaceFormat fmt);

    ~CGNoDataImageBacking();

    CGImageRef Copy();

    CGContextImpl* CreateDrawingContext(CGContextRef base);
    DisplayTexture* GetTexture();
    void SetTexture(DisplayTexture* tex);
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
    EbrFastTexture* FastTexture();
};
