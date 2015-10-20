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

class CGDiscardableImageBacking : public CGImageBacking {
protected:
    CGImageBacking* _forward;
    bool _hasCachedInfo;
    int _cachedWidth, _cachedHeight;
    surfaceFormat _cachedSurfaceFormat;

public:
    CGDiscardableImageBacking();
    ~CGDiscardableImageBacking();

    CGImageRef Copy();

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
    void DiscardIfPossible();

    void ConstructIfNeeded();
    virtual CGImageBacking* ConstructBacking() = 0;
};

class ImageDataStream {
public:
    virtual int readData(void* in, int len) = 0;
    virtual ~ImageDataStream() {
    }
};

class ImageDataStreamFile : public ImageDataStream {
private:
    EbrFile* fpIn;

public:
    ImageDataStreamFile(EbrFile* in);
    int readData(void* in, int len);
    ~ImageDataStreamFile();
};

class ImageDataStreamMemory : public ImageDataStream {
private:
    const char* data;
    int dataLeft;

public:
    ImageDataStreamMemory(const void* in, int len);
    int readData(void* in, int len);
};
