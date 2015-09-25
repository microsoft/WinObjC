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

#include <algorithm>

#include "Starboard.h"
#include "CGFontInternal.h"
#include "AlphaFontGenerator.h"

void AlphaFontGenerator::init(FT_Face face, size_t size) {
    FontGenerator::init(NULL, face, size);
}

void AlphaFontGenerator::renderGlyph(int c) {
    rep.clear();

    int ci = FT_Get_Char_Index(face, c);
    int error = FT_Load_Glyph(face, ci, FT_LOAD_DEFAULT);
    if (error)
        return;
    error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
    if (error)
        return;

    rep.reinit(face->glyph->bitmap.buffer, face->glyph->bitmap.width, face->glyph->bitmap.rows);
}
