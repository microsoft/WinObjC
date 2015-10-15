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

class CGJPEGDecoderImage : public __CGImage {
public:
    CGJPEGDecoderImage(const char* filename);
    CGJPEGDecoderImage(id data);
};

class CGJPEGImageBacking : public CGDiscardableImageBacking {
public:
    char* _fileName;
    idretain _data;

    int _orientation;

    CGJPEGImageBacking(const char* filename);
    CGJPEGImageBacking(id data);
    ~CGJPEGImageBacking();

    void DiscardIfPossible();
    CGImageBacking* ConstructBacking();
    void Decode(void* imgDest, int stride);
    bool DrawDirectlyToContext(CGContextImpl* ctx, CGRect src, CGRect dest);
};
