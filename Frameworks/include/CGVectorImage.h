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

#pragma once

class CGVectorImageBacking;

class CGVectorImage : public __CGImage {
public:
    CGVectorImage(DWORD width, DWORD height, surfaceFormat fmt);
    CGImageRef Rasterize(CGRect* insets);

    inline CGVectorImageBacking* VectorBacking() {
        return (CGVectorImageBacking*)Backing();
    }
};

enum VectorDrawingCommandType { vectorDrawingImage, vectorDrawingLine };

class CGVectorDrawingCommand {
public:
    VectorDrawingCommandType _type;
    CGImageRef _image;
    CGRect _src, _dest;
    CGPoint _start, _end;
    float _lineWidth;
    ColorQuad _color;

    CGVectorDrawingCommand(CGImageRef image, CGRect src, CGRect dst);
    CGVectorDrawingCommand(CGPoint lineStart, CGPoint lineEnd, ColorQuad color, float lineWidth);
    ~CGVectorDrawingCommand();
};

class CGVectorImageBacking : public CGImageBacking {
private:
    int _width, _height;
    surfaceFormat _surfaceFmt;
    CGVectorDrawingCommand* _drawCommand;

public:
    CGVectorImageBacking(DWORD width, DWORD height, surfaceFormat fmt);

    ~CGVectorImageBacking();

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

    void DrawImage(CGImageRef image, CGRect src, CGRect dst);
    void StrokePath(id path, ColorQuad color, float lineWidth, CGAffineTransform* t);
};
