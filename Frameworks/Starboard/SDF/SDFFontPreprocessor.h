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

#if USE_SDF_FONTS

#include "FontGenerator.h"
#include "AlphaFontGenerator.h"

class SDFFontPreprocessor : public FontGenerator {
    AlphaFontGenerator* src;
    float sampleDist;

public:
    inline SDFFontPreprocessor(void* mem, AlphaFontGenerator* src) : FontGenerator(), src(src), sampleDist(0.f) {
        FontGenerator::init(mem, NULL, 0);
    }
    virtual ~SDFFontPreprocessor() {
    }

    void init(FT_Face face, size_t fontSize, float sampleDist = 1.f / 16.f);

    virtual void renderGlyph(int c);
};

#endif
