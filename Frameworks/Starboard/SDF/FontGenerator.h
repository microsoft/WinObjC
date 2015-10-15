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

#include "Matrix.h"
#include "SDFFontDefs.h"

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
};

class FontGenerator {
protected:
    FT_Face face;
    size_t faceSize;
    CharMatrix rep;

public:
    inline FontGenerator() : face(0), faceSize(0), rep(NULL) {
    }
    virtual ~FontGenerator() {
    }

    void init(void* mem, FT_Face face, size_t size);
    void init(FT_Face face, size_t size);

    virtual void renderGlyph(int c) = 0;

    inline const CharMatrix& representation() const {
        return rep;
    }
    inline size_t size() const {
        return faceSize;
    }
};
