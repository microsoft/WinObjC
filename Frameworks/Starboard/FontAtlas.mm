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

#include "Starboard.h"
#include "EbrGLES.h"
#include "UIKit/UIImage.h"
#include "CGContextInternal.h"
#include "CGFontInternal.h"
#include "Foundation/NSString.h"
#include "Etc.h"
#include "Types.h"
#include "SDF/AlphaFontGenerator.h"
#if USE_SDF_FONTS
#include "SDF/SDFFontPreprocessor.h"
#endif
#include "FontAtlas.h"
#include "NativeUI/NativeUI.h"

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
}

#include <vector>
#include <algorithm>

static IWLazyClassLookup _LazyUIFont("UIFont");
static IWLazyIvarLookup<float> _LazyUIFontHorizontalScale(_LazyUIFont, "_horizontalScale");

#define REPORT_FONT_STATISTICS 1

#define BORDER_WIDTH 2

#define CHAR_X_EXTRA_SPACING ((float)BORDER_WIDTH * 3.f)

// Helpful bitmap parameters.
#define BITMAP_WIDTH 1024
#define MIN_BITMAP_HEIGHT 32
#define ROWS_PER_BITMAP 4

#define SDF_THRESHOLD_SIZE 30

static int totalAtlasBytes = 0;

#if USE_SDF_FONTS

#define SDF_FONT_GEN_SIZE 256 // in points.

// Extra mem required for SDF fonts.

#define MAX_SDF_CHAR_WIDTH 384
#define MAX_SDF_CHAR_HEIGHT 512

static char sdfResultsMem[MAX_SDF_CHAR_WIDTH * MAX_SDF_CHAR_HEIGHT];

#endif

// FontArea class, stores where a font is located in the list of textures.
class FontCharArea {
public:
    inline FontCharArea()
        : fontChar(0),
          bearingX(0.f),
          bearingY(0.f),
          x(0),
          y(0),
          pointWidth(0),
          pointHeight(0),
          pixWidth(0),
          pixHeight(0),
          rendered(false),
          texture(NULL) {
    }

    explicit inline FontCharArea(WORD fontChar)
        : fontChar(fontChar),
          bearingX(0.f),
          bearingY(0.f),
          x(0),
          y(0),
          pointWidth(0),
          pointHeight(0),
          pixWidth(0),
          pixHeight(0),
          rendered(false),
          texture(NULL) {
    }

    WORD fontChar;
    int glyphIndex;
    float bearingX;
    float bearingY;
    short x;
    short y;
    short pixWidth, pixHeight;
    float pointWidth;
    float pointHeight;

    EbrTexture* texture;
    bool rendered;
};

static int FontCharAreaCompare(const void* a, const void* b) {
    return (((int)((const FontCharArea*)a)->fontChar) - ((int)((const FontCharArea*)b)->fontChar));
}

static float roundPointSize(float size) {
    // return ceilf(size / 18.0f) * 18.0f;
    return size;
}

class FontCacheInfo {
public:
    inline FontCacheInfo()
        : font(nil),
          currentTextureX((int)CHAR_X_EXTRA_SPACING),
          currentTextureY(0),
          bitmapWidth(0),
          bitmapHeight(0),
          fontHeight(0),
          numAreas(0),
          areas(NULL),
          glyphsToBeRendered(NULL),
          glyphsToBeRenderedCount(0),
          currentTexture(NULL),

          refCount(0),
          permanent(false),
          sdf(false) {
        containedChars = [NSMutableCharacterSet new];
        addChars = [NSMutableCharacterSet new];

        [addChars addCharactersInString:@"."];
    }

    ~FontCacheInfo() {
        [containedChars release];
        [addChars release];
        if (areas)
            delete[] areas;
        if (glyphsToBeRendered)
            delete[] glyphsToBeRendered;
        [font release];

        EbrFree(fontName);
    }

    bool renderNewGlyphs(ID3D11Device1* device, ID3D11DeviceContext* context);
    void getDrawList(FontAtlasOutputGlyph* outputGlyphs, id string, float pointSize, bool& sdfFont);

    inline int getBitmapWidth() const {
        return bitmapWidth;
    }
    inline int getBitmapHeight() const {
        return bitmapHeight;
    }

    id font;
    FT_Face face;

    std::vector<EbrTexture*> fontTextures;
    EbrTextureFontAtlas* currentTexture;
    int currentTextureX;
    int currentTextureY;
    int bitmapWidth;
    int bitmapHeight;
    int fontHeight;

    int numAreas;
    FontCharArea* areas;

    float ascender;
    float pointSize;
    float renderedSize;
    float screenScale;

    int refCount;
    bool permanent;
    bool sdf;

    char* fontName;

    NSMutableCharacterSet *containedChars, *addChars;
    FontCharArea** glyphsToBeRendered;
    int glyphsToBeRenderedCount;

    void disconnect() {
        for (size_t i = 0; i < fontTextures.size(); i++) {
            EbrTexture* curTexture = fontTextures[i];
            curTexture->Disconnect();
            delete curTexture;
        }

        fontTextures.clear();
        currentTexture = 0;

        for (int i = 0; i < numAreas; i++) {
            areas[i].rendered = false;
            areas[i].texture = NULL;
        }
        [addChars formUnionWithCharacterSet:containedChars];
        [containedChars removeAllCharacters];

        totalAtlasBytes = 0;
    }

    const FontCharArea* fontCharForChar(WORD character) {
        FontCharArea searchChar(character);
        const void* res = bsearch(&searchChar, areas, numAreas, sizeof(FontCharArea), FontCharAreaCompare);
        return (const FontCharArea*)res;
    }

    void buildCharAreas();
    void addStringToRender(id str) {
        [addChars addCharactersInString:(NSString*)str];
    }

    void setFont(id newFont);
    void processNewCharacters(ID3D11Device1* device, ID3D11DeviceContext* context) {
        if ([addChars count] > 0) {
            //  Figure out which characters are new to the set
            NSMutableCharacterSet* newChars = [addChars mutableCopy];
            [newChars removeCharactersInSet:containedChars];

            int newCharCount = [newChars count];
            if (newCharCount > 0) {
                if (glyphsToBeRendered)
                    delete[] glyphsToBeRendered;
                glyphsToBeRendered = new FontCharArea*[newCharCount];
                glyphsToBeRenderedCount = 0;

                //  Go through each new character
                for (int i = 0; i < newCharCount; i++) {
                    unichar newChar = [newChars characterAtIndex:i];

                    //  Check if it's a new character
                    const FontCharArea* ca = fontCharForChar(newChar);
                    if (ca && !ca->rendered) {
                        //  Add this character to be rendered
                        glyphsToBeRendered[glyphsToBeRenderedCount++] = (FontCharArea*)ca;
                    }
                }

                renderNewGlyphs(device, context);
            }

            [containedChars formUnionWithCharacterSet:newChars];
            [addChars removeAllCharacters];
        }
    }
};

class FontAtlasManImpl : public FontAtlasMan {
    std::vector<FontCacheInfo*> fonts;
    int _generationCount;

protected:
    FontCacheInfo* add(id font, bool permanent);

public:
    FontAtlasManImpl();
    virtual ~FontAtlasManImpl();

    FontCacheInfo* findCachedFont(id font);

    virtual bool addPermanent(id font); // make a font permanently cached.
    virtual bool addFontRef(id font); // add a font, refcount-based caching.
    virtual bool releaseFontRef(id font); // release a font reference.  cleared if # of references is 0.

    virtual void addStringToRender(id font, id string) {
        FontCacheInfo* fontInfo = findCachedFont(font);
        if (fontInfo) {
            fontInfo->addStringToRender(string);
        }
    }

    int generationCount() {
        return _generationCount;
    }

    void disconnect() {
        _generationCount++;
        for (size_t i = 0; i < fonts.size(); i++) {
            fonts[i]->disconnect();
        }
    }

    // get a list of quads to draw (as tri strips) for the given string.  will not add
    // a new font if it is not present.
    virtual bool getDrawList(FontAtlasOutputGlyph* outputGlyphs, id font, id string, bool& sdfFont);

    virtual void process(ID3D11Device1* device, ID3D11DeviceContext* context) {
        for (size_t i = 0; i < fonts.size(); i++) {
            if (fonts[i]->refCount == 0 && !fonts[i]->permanent) {
                delete fonts[i];
                fonts.erase(fonts.begin() + i);
                i--;
                continue;
            }

            fonts[i]->processNewCharacters(device, context);
        }
    }
};

FontAtlasMan::FontAtlasMan() {
}

FontAtlasMan::~FontAtlasMan() {
}

FontAtlasMan* FontAtlasMan::get() {
    static FontAtlasManImpl* impl = NULL;
    if (!impl)
        impl = new FontAtlasManImpl();

    return impl;
}

FontAtlasManImpl::FontAtlasManImpl() {
    _generationCount = 0;
}

FontAtlasManImpl::~FontAtlasManImpl() {
    assert(!"Font atlas manager should never be destroyed");
}

static void getFontName(UIFont* font, FT_Face face, char* out) {
    strcpy(out, face->family_name);
    if (face->style_name) {
        strcat(out, " ");
        strcat(out, face->style_name);
    }
    if (_LazyUIFontHorizontalScale.member(font) != 1.0f) {
        strcat(out, " Condensed");
    }
}

FontCacheInfo* FontAtlasManImpl::findCachedFont(id font) {
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    if (face == NULL)
        return NULL;

    _CGFontLock();

    char fontName[255];
    getFontName(font, face, fontName);
    _CGFontUnlock();

    float size = [font pointSize];
    size = roundPointSize(size);

    // Find an existing texture.
    for (size_t i = 0; i < fonts.size(); i++) {
        FontCacheInfo* ci = fonts[i];
        if (ci && ci->face && strcmp(fontName, ci->fontName) == 0 && ci->pointSize == size) {
            return ci;
        }
    }

    return NULL;
}

FontCacheInfo* FontAtlasManImpl::add(id font, bool permanent) {
    if (font == nil)
        return NULL;

    // Existing texture.
    FontCacheInfo* existing = findCachedFont(font);
    if (existing) {
        existing->permanent = (existing->permanent || permanent); // don't turn permanent off.
        existing->refCount++;
        return existing;
    }

    // New texture.
    FontCacheInfo* ci = new FontCacheInfo();

    ci->setFont(font);
    ci->refCount = 1;
    ci->permanent = permanent;

    fonts.push_back(ci);

    return ci;
}

bool FontAtlasManImpl::addPermanent(id font) {
    return add(font, true) ? true : false;
}

bool FontAtlasManImpl::addFontRef(id font) {
    return add(font, false) ? true : false;
}

bool FontAtlasManImpl::releaseFontRef(id font) {
    if (font == nil)
        return false;

    FontCacheInfo* existing = findCachedFont(font);
    if (existing) {
        assert(existing->refCount);
        if (existing->refCount)
            existing->refCount--;
        return true;
    }

    return false;
}

bool FontAtlasManImpl::getDrawList(FontAtlasOutputGlyph* outputGlyphs, id font, id string, bool& sdfFont) {
    if (font == nil || string == nil) {
        return true;
    }

    // Get/allocate the font bitmap.
    FontCacheInfo* existing = findCachedFont(font);
    if (existing) {
        float pointSize = [font pointSize];
        existing->getDrawList(outputGlyphs, string, pointSize, sdfFont);
        return true;
    }

    sdfFont = false;
    return false;
}

void FontCacheInfo::buildCharAreas() {
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    int numSrc = 0;
    FT_UInt glyphIndex;

    for (FT_ULong cc = FT_Get_First_Char(face, &glyphIndex); glyphIndex != 0; cc = FT_Get_Next_Char(face, cc, &glyphIndex)) {
        numSrc++;
    }

    numSrc++;

    areas = new FontCharArea[numSrc];
    numAreas = 0;
    FontCharArea* ca = areas;

    for (FT_ULong cc = FT_Get_First_Char(face, &glyphIndex); glyphIndex != 0; cc = FT_Get_Next_Char(face, cc, &glyphIndex)) {
        WORD gindex = FT_Get_Char_Index(face, cc);

        ca->rendered = false;
        ca->fontChar = (WORD)cc;
        ca->glyphIndex = gindex;

        ca++;
        numAreas++;
    }

    glyphIndex = FT_Get_Char_Index(face, 9);

    ca->rendered = false;
    ca->fontChar = (WORD)9;
    ca->glyphIndex = glyphIndex;

    ca++;
    numAreas++;

    qsort(areas, numAreas, sizeof(FontCharArea), FontCharAreaCompare);
}

void FontCacheInfo::setFont(id newFont) {
    font = [newFont retain];
    pointSize = [font pointSize];
    pointSize = roundPointSize(pointSize);

#if USE_SDF_FONTS
    if (pointSize < SDF_THRESHOLD_SIZE) {
        sdf = false;
    } else {
        sdf = true;
    }
#endif

    face = (FT_Face)(DWORD)[font _sizingFontHandle];
    if (face == nil) {
        return;
    }

    _CGFontLock();
    screenScale = (GetCACompositor()->deviceWidth() / GetCACompositor()->screenWidth());

    // renderedSize = pointSize * min(GetCACompositor()->deviceWidth() / GetCACompositor()->screenWidth(), deviceHeight
    // / screenHeight);
    // renderedSize = ceilf(renderedSize);
    renderedSize = pointSize;
    CGFontSetFTFontSize(font, face, renderedSize, screenScale);

    ascender = ((float)(face->size->metrics.ascender)) / 64.0f;

    fontHeight = (int)(face->size->metrics.y_ppem * 1.5f + BORDER_WIDTH);

    bitmapWidth = BITMAP_WIDTH;
    bitmapHeight = 1 << log2Ceil(ROWS_PER_BITMAP * fontHeight);
    if (bitmapHeight < MIN_BITMAP_HEIGHT)
        bitmapHeight = MIN_BITMAP_HEIGHT;

    fontName = (char*)EbrMalloc(255);
    getFontName(font, face, fontName);

    buildCharAreas();

    _CGFontUnlock();
}

DWORD UIImagePNGRepresentation(id img);

bool FontCacheInfo::renderNewGlyphs(ID3D11Device1* device, ID3D11DeviceContext* context) {
#if REPORT_FONT_STATISTICS
    double start = EbrGetMediaTime();
#endif

    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    if (currentTexture == NULL) {
        currentTexture = new EbrTextureFontAtlas();

        // New bitmap page.
        currentTexture->Initialize(device, bitmapWidth, bitmapHeight, NULL);
        totalAtlasBytes += bitmapWidth * bitmapHeight;

        fontTextures.push_back(currentTexture);

        currentTextureX = (int)CHAR_X_EXTRA_SPACING;
        currentTextureY = 0;
    }

    FontGenerator* fontGen = NULL;

    _CGFontLock();

#if !USE_SDF_FONTS
    CGFontSetFTFontSize(font, face, renderedSize, screenScale);

    AlphaFontGenerator alphaFontGen;
    alphaFontGen.init(face, (size_t)pointSize);
    fontGen = &alphaFontGen;
#else
    AlphaFontGenerator alphaFontGen;
    SDFFontPreprocessor sdfFontGen(sdfResultsMem, &alphaFontGen);
    if (sdf) {
        alphaFontGen.init(face, SDF_FONT_GEN_SIZE);
        sdfFontGen.init(face, (SDF_THRESHOLD_SIZE * screenScale)); // TODO: need to determine actual size for metrics.
        fontGen = &sdfFontGen;
    } else {
        CGFontSetFTFontSize(font, face, renderedSize, screenScale);

        alphaFontGen.init(face, (size_t)pointSize);
        fontGen = &alphaFontGen;
    }
#endif

    //  Render all glyphs to as many atlas texture strips as we need
    for (int curCharIdx = 0; curCharIdx < glyphsToBeRenderedCount; curCharIdx++) {
        int texWidthI = getBitmapWidth() - currentTextureX;
        int texHeightI = getBitmapHeight() - currentTextureY;

        // is char available?
        FontCharArea* ca = glyphsToBeRendered[curCharIdx];
        if (ca->glyphIndex == 0)
            continue;

// Render char.
#if !USE_SDF_FONTS
        fontGen->renderGlyph(ca->fontChar);
#else
        CGFontSetFTFontSize(font, face, SDF_FONT_GEN_SIZE, 1.f);
        fontGen->renderGlyph(ca->fontChar);

        CGFontSetFTFontSize(font, face, renderedSize, screenScale); // UGH:  re-render, need metrics.
        alphaFontGen.renderGlyph(ca->fontChar);
#endif
        const CharMatrix& rep = fontGen->representation();

        // Does it fit?
        float width = (float)static_cast<short>(rep.width()) + (int)face->glyph->bitmap_left + 1.0f;
        if ((currentTextureX + width + CHAR_X_EXTRA_SPACING) > (float)texWidthI) {
            if (currentTextureY + fontHeight >= getBitmapHeight()) {
                currentTexture = new EbrTextureFontAtlas();

                // New bitmap page.
                currentTexture->Initialize(device, bitmapWidth, bitmapHeight, NULL);
                totalAtlasBytes += bitmapWidth * bitmapHeight;

                fontTextures.push_back(currentTexture);

                currentTextureX = (int)CHAR_X_EXTRA_SPACING;
                currentTextureY = 0;
            } else {
                // New line in cur bitmap.
                currentTextureX = (int)CHAR_X_EXTRA_SPACING;
                currentTextureY += fontHeight;
            }
        }

        if (rep.mem()) { // some stuff (ie, spaces) don't want to render but we need the metrics.
            int startx = currentTextureX + face->glyph->bitmap_left;
            int starty = currentTextureY + ((int)(face->size->metrics.ascender / 64.0f)) - face->glyph->bitmap_top;
            if (starty < 0)
                starty = 0;

            assert(startx >= 0);
            assert(starty >= 0);

            currentTexture->UpdateSubrect(context, startx, starty, rep.width(), rep.height(), (void*)rep.mem());
        }

        ca->texture = currentTexture;
        ca->rendered = true;
        ca->bearingX = 0; //(face->glyph->metrics.horiBearingX / 64.f - ((float)BORDER_WIDTH));
        ca->bearingY = 0; //(face->glyph->metrics.horiBearingY / 64.f + ((float)BORDER_WIDTH));

        ca->x = static_cast<short>(currentTextureX);
        ca->y = static_cast<short>(currentTextureY);
        ca->pixWidth = static_cast<short>(face->glyph->bitmap.width) + (int)face->glyph->bitmap_left;
        ca->pixHeight = static_cast<short>((face->size->metrics.ascender - face->size->metrics.descender) / 64.f);

        ca->pixWidth++;
        ca->pixHeight++;

        ca->pointWidth = (ca->pixWidth / screenScale);
        ca->pointHeight = (ca->pixHeight / screenScale);

        currentTextureX += (int)(width + CHAR_X_EXTRA_SPACING);
    }

#if REPORT_FONT_STATISTICS
    double end = EbrGetMediaTime();

    int ms = (int)((end - start) * 1000.0f);
    static int totalOps = 0;
    static int totalMS = 0;

    totalOps++;
    totalMS += ms;

    EbrDebugLog("------ %d glyphs added in %dms. Total %d ops, %d ms.  Atlas chars: %d, size: %dK\n",
                glyphsToBeRenderedCount,
                ms,
                totalOps,
                totalMS,
                (int)[containedChars count],
                (int)(totalAtlasBytes / 1024));
#endif

    //  Clean up
    _CGFontUnlock();
    if (glyphsToBeRendered) {
        delete[] glyphsToBeRendered;
        glyphsToBeRendered = NULL;
    }
    glyphsToBeRenderedCount = 0;

    return true;
}

void FontCacheInfo::getDrawList(FontAtlasOutputGlyph* outputGlyphs, id string, float drawPointSize, bool& sdfFont) {
    int np = 0;
    sdfFont = sdf;

    //  Calculate the total font line height using freetype so that it will exactly match
    //  what CGFont returns ..
    _CGFontLock();
    CGFontSetFTFontSize(font, face, drawPointSize, 1.0f);
    float fontHeight = (face->size->metrics.ascender - face->size->metrics.descender) / 64.0f;

    // Spin through the string, generate points and uvs.
    int len = [string length];

    float texWidth = (float)(getBitmapWidth());
    float texWidthInv = 1.f / (texWidth - 1.f);
    float texHeight = (float)(getBitmapHeight());
    float texHeightInv = 1.f / (texHeight - 1.f);

    float xPos = 0.0f;

    float pointScaler = drawPointSize / renderedSize;
    float fontSize = ascender * pointScaler;

    for (int i = 0; i < len; i++) {
        FontAtlasOutputGlyph* curOutput = &outputGlyphs[i];
        curOutput->character = [string characterAtIndex:i];
        curOutput->hasSize = false;
        curOutput->hasTexture = false;

        const FontCharArea* ca = fontCharForChar(curOutput->character);
        if (ca) {
            if (FT_Load_Glyph(face, ca->glyphIndex, FT_LOAD_NO_HINTING) == 0) {
                curOutput->glyphSize.width = face->glyph->advance.x / 64.f;
                curOutput->glyphSize.height = ceilf(fontHeight);
                curOutput->hasSize = true;
            }
        }
        if (!ca || !ca->rendered) {
            continue;
        }

        float rectLocX = xPos;
        float rectLocY = 0.0f;
        float rectW = ca->pointWidth;
        float rectH = ca->pointHeight;
        float uvW = static_cast<float>(ca->pixWidth);
        float uvH = static_cast<float>(ca->pixHeight);

        float u = static_cast<float>(ca->x - 1) / texWidth;
        float v = static_cast<float>(ca->y - 1) / texHeight;
        float uDiff = uvW / texWidth;
        float vDiff = uvH / texHeight;

        curOutput->hasTexture = true;
        curOutput->texture = ca->texture;

        curOutput->drawQuad[0].x = rectLocX;
        curOutput->drawQuad[0].y = rectLocY;
        curOutput->uvQuad[0].x = u;
        curOutput->uvQuad[0].y = v;

        curOutput->drawQuad[1].x = rectLocX + rectW;
        curOutput->drawQuad[1].y = rectLocY;
        curOutput->uvQuad[1].x = u + uDiff;
        curOutput->uvQuad[1].y = v;

        curOutput->drawQuad[2].x = rectLocX;
        curOutput->drawQuad[2].y = rectLocY + rectH;
        curOutput->uvQuad[2].x = u;
        curOutput->uvQuad[2].y = v + vDiff;

        curOutput->drawQuad[3].x = rectLocX + rectW;
        curOutput->drawQuad[3].y = rectLocY + rectH;
        curOutput->uvQuad[3].x = u + uDiff;
        curOutput->uvQuad[3].y = v + vDiff;
    }

    _CGFontUnlock();
}

#define FORGIVENESS_MARGIN 4.f // for regular Helvetica vs ios helvetica issues.
#define VERTICAL_FORGIVENESS_MARGIN 3.f // for regular Helvetica vs ios helvetica issues.

DisplayTextureFontAtlas::DisplayTextureFontAtlas()
    : DisplayTexture(0, 0),
      _outputLines(NULL),
      _maxOutputLines(0),
      _numOutputLines(0),
      _atlasGlyphs(NULL),
      _numAtlasGlyphs(0),
      _quadOut(NULL),
      _shadowQuadOut(NULL),
      _texQuadOut(NULL),
      _texPtrs(NULL),
      _numQuads(0),
      _lineHeight(0.0f),
      _linesDirty(true),
      _glyphsDirty(true),
      _fontRealized(false),
      _curFontGeneration(0),
      _sdfFont(false) {
    memset(&_lastRenderedRect, 0, sizeof(_lastRenderedRect));
    _ellipsis = new FontAtlasOutputGlyph();
}

void DisplayTextureFontAtlas::SetParams(id font,
                                        id text,
                                        id color,
                                        DWORD alignment,
                                        DWORD lineBreak,
                                        id shadowColor,
                                        const CGSize& shadowOffset,
                                        int numLines,
                                        UIEdgeInsets edgeInsets,
                                        bool centerVertically) {
    _font = font;
    _text = text;
    _color = color;
    _alignment = alignment;
    _lineBreakMode = lineBreak;
    _shadowColor = shadowColor;
    _shadowOffset = shadowOffset;
    _numLines = numLines;
    _edgeInsets = edgeInsets;
    _centerVertically = centerVertically;
}

DisplayTextureFontAtlas::~DisplayTextureFontAtlas() {
    if (_font != nil) {
        if (_fontRealized)
            FontAtlasMan::get()->releaseFontRef(_font);
        _font = nil;
    }
    _text = nil;
    _color = nil;
    _shadowColor = nil;

    if (_outputLines)
        EbrFree(_outputLines);
    if (_atlasGlyphs)
        EbrFree(_atlasGlyphs);
    if (_quadOut)
        EbrFree(_quadOut);
    if (_shadowQuadOut)
        EbrFree(_shadowQuadOut);
    if (_texQuadOut)
        EbrFree(_texQuadOut);
    if (_texPtrs)
        EbrFree(_texPtrs);
    delete _ellipsis;
}

void DisplayTextureFontAtlas::realize() {
    FontAtlasMan* fontMan = FontAtlasMan::get();
    if (!_fontRealized) {
        fontMan->addPermanent(_font);
        fontMan->addStringToRender(_font, _text);
        _fontRealized = true;
    }
}

bool DisplayTextureFontAtlas::hasAlpha() const {
    return true;
}

bool DisplayTextureFontAtlas::flipped() const {
    return false;
}

static int fontAtlasGetCharWidth(WORD* str, void* opaque, unsigned idx) {
    FontAtlasOutputGlyph* glyphs = (FontAtlasOutputGlyph*)opaque;

    return (int)(glyphs[idx].glyphSize.width * 64.f);
}

float DisplayTextureFontAtlas::measureWidth(int glyphStart, int numGlyphs) {
    float curWidth = 0.0f;

    for (int i = glyphStart; i < glyphStart + numGlyphs; i++) {
        if (!_atlasGlyphs[i].hasSize)
            continue;

        curWidth += _atlasGlyphs[i].glyphSize.width;
    }

    return curWidth;
}

CATextLayerLine* DisplayTextureFontAtlas::createNewLine() {
    if (_numOutputLines + 1 > _maxOutputLines) {
        _maxOutputLines += 16;
        _outputLines = (CATextLayerLine*)EbrRealloc(_outputLines, _maxOutputLines * sizeof(CATextLayerLine));
    }
    CATextLayerLine* ret = &_outputLines[_numOutputLines];
    _numOutputLines++;

    return ret;
}

void DisplayTextureFontAtlas::addOutputLine(float x, float y, float maxWidth, int glyphStart, int numGlyphs, CGSize* sizeRet) {
    //  Skip any trailng whitespace
    for (int i = glyphStart + numGlyphs - 1; i >= glyphStart; i--) {
        if (_atlasGlyphs[i].character != ' ')
            break;
        numGlyphs--;
    }

    float curX = x;
    CATextLayerLine* outputLine = createNewLine();

    outputLine->startQuad = _numQuads;
    outputLine->totalSize.width = 0.0f;
    outputLine->totalSize.height = _lineHeight;

    sizeRet->width = 0.0f;
    sizeRet->height = _lineHeight;

    float curWidth = 0.0f;
    bool addEllipse = false;

    if (_lineBreakMode == UILineBreakModeTailTruncation || _lineBreakMode == UILineBreakModeMiddleTruncation) {
        addEllipse = measureWidth(glyphStart, numGlyphs) > (maxWidth + FORGIVENESS_MARGIN);
    }

    float ellipseWidth = 0.0f;
    if (addEllipse) {
        ellipseWidth = _ellipsis->glyphSize.width * 3;
    }

    int leftChar = glyphStart;
    int rightChar = glyphStart + numGlyphs;
    int numLeft = 0;
    int numRight = 0;

    for (;;) {
        if (leftChar == rightChar)
            break;

        if (_atlasGlyphs[leftChar].hasSize) {
            if (curWidth + _atlasGlyphs[leftChar].glyphSize.width > maxWidth - ellipseWidth)
                break;

            curWidth += _atlasGlyphs[leftChar].glyphSize.width;
        }
        leftChar++;
        numLeft++;

        if (_lineBreakMode == UILineBreakModeMiddleTruncation) {
            if (leftChar == rightChar)
                break;

            if (_atlasGlyphs[rightChar - 1].hasSize) {
                if (curWidth + _atlasGlyphs[rightChar - 1].glyphSize.width > maxWidth - ellipseWidth)
                    break;

                curWidth += _atlasGlyphs[rightChar - 1].glyphSize.width;
            }
            rightChar--;
            numRight++;
        }
    }

    curWidth = 0.0f;
    for (int i = glyphStart; i < glyphStart + numLeft; i++) {
        if (!_atlasGlyphs[i].hasSize)
            continue;
        if (curWidth + _atlasGlyphs[i].glyphSize.width > maxWidth)
            break;

        if (_atlasGlyphs[i].hasTexture) {
            for (int j = 0; j < 4; j++) {
                _quadOut[_numQuads + j].x = _atlasGlyphs[i].drawQuad[j].x + curX;
                _quadOut[_numQuads + j].y = _atlasGlyphs[i].drawQuad[j].y + y;
                _quadOut[_numQuads + j].z = 0.0f;
                _texQuadOut[_numQuads + j] = _atlasGlyphs[i].uvQuad[j];
                _texPtrs[_numQuads + j] = _atlasGlyphs[i].texture;
            }
        }

        curX += _atlasGlyphs[i].glyphSize.width;
        curWidth += _atlasGlyphs[i].glyphSize.width;

        if (curX > outputLine->totalSize.width) {
            outputLine->totalSize.width = curX;
        }
        _numQuads += 4;
    }

    if (addEllipse) {
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 4; j++) {
                _quadOut[_numQuads + j].x = _ellipsis->drawQuad[j].x + curX;
                _quadOut[_numQuads + j].y = _ellipsis->drawQuad[j].y + y;
                _quadOut[_numQuads + j].z = 0.0f;
                _texQuadOut[_numQuads + j] = _ellipsis->uvQuad[j];
                _texPtrs[_numQuads + j] = _ellipsis->texture;
            }

            curX += _ellipsis->glyphSize.width;

            if (curX > outputLine->totalSize.width) {
                outputLine->totalSize.width = curX;
            }
            _numQuads += 4;
        }
    }

    for (int i = rightChar; i < rightChar + numRight; i++) {
        if (!_atlasGlyphs[i].hasSize)
            continue;
        if (curWidth + _atlasGlyphs[i].glyphSize.width > maxWidth)
            break;

        if (_atlasGlyphs[i].hasTexture) {
            for (int j = 0; j < 4; j++) {
                _quadOut[_numQuads + j].x = _atlasGlyphs[i].drawQuad[j].x + curX;
                _quadOut[_numQuads + j].y = _atlasGlyphs[i].drawQuad[j].y + y;
                _quadOut[_numQuads + j].z = 0.0f;
                _texQuadOut[_numQuads + j] = _atlasGlyphs[i].uvQuad[j];
                _texPtrs[_numQuads + j] = _atlasGlyphs[i].texture;
            }
        }

        curX += _atlasGlyphs[i].glyphSize.width;
        curWidth += _atlasGlyphs[i].glyphSize.width;

        if (curX > outputLine->totalSize.width) {
            outputLine->totalSize.width = curX;
        }
        _numQuads += 4;
    }

    *sizeRet = outputLine->totalSize;

    outputLine->numQuads = _numQuads - outputLine->startQuad;
}

void DisplayTextureFontAtlas::emitOperations(
    CAPoint3D* quads, int numPoints, float alpha, float r, float g, float b, float a, DrawingObserver* observer, bool sdfFont) {
    EbrTexture* texPtr = NULL;
    int basePoint = 0;
    int curPoint = 0;

    while (curPoint < numPoints) {
        if (texPtr == NULL)
            texPtr = _texPtrs[curPoint];
        if (texPtr != _texPtrs[curPoint]) {
            int count = (curPoint - basePoint) / 4;
            _drawingList.AddOperation(&quads[basePoint],
                                      &_texQuadOut[basePoint],
                                      count,
                                      texPtr,
                                      alpha,
                                      ADM_FONT_BLEND,
                                      r / alpha,
                                      g / alpha,
                                      b / alpha,
                                      a,
                                      observer,
                                      sdfFont);

            texPtr = _texPtrs[curPoint];
            basePoint = curPoint;
        }

        curPoint++;
    }

    int count = (curPoint - basePoint) / 4;
    if (count > 0) {
        _drawingList.AddOperation(&quads[basePoint],
                                  &_texQuadOut[basePoint],
                                  count,
                                  texPtr,
                                  alpha,
                                  ADM_FONT_BLEND,
                                  r / alpha,
                                  g / alpha,
                                  b / alpha,
                                  a,
                                  observer,
                                  sdfFont);
    }
}

bool DisplayTextureFontAtlas::reflowText(CGSize maxSize, CGSize* totalSizeRet) {
    totalSizeRet->width = 0.0f;
    totalSizeRet->height = 0.0f;

    switch (_lineBreakMode) {
        case UILineBreakModeCharacterWrap:
        case UILineBreakModeWordWrap: {
            CGFontWrapState state;

            memset(&state, 0, sizeof(state));

            state.count = _numAtlasGlyphs;
            state.chars = (WORD*)alloca(state.count * sizeof(WORD));
            [_text getCharacters:state.chars];

            state.curIndex = 0;
            CGSize fitSize;

            float curY = 0.0f;

            //  Keep drawing lines of text until we're out of characters
            while (CGFontWrapFunc(
                &state, maxSize.width, &fitSize, fontAtlasGetCharWidth, _atlasGlyphs, _lineBreakMode == UILineBreakModeCharacterWrap)) {
                CGSize retSize;
                addOutputLine(0, curY, maxSize.width, state.lineStart - state.chars, state.lineLen, &retSize);
                if (retSize.width > totalSizeRet->width) {
                    totalSizeRet->width = retSize.width;
                }
                if (curY + retSize.height > totalSizeRet->height + VERTICAL_FORGIVENESS_MARGIN) {
                    totalSizeRet->height = curY + retSize.height;
                }

                curY += _lineHeight;
            }
            break;
        }

        case UILineBreakModeMiddleTruncation:
        case UILineBreakModeTailTruncation: {
            CGFontWrapState state;

            memset(&state, 0, sizeof(state));

            state.count = _numAtlasGlyphs;
            state.chars = (WORD*)alloca(state.count * sizeof(WORD));
            [_text getCharacters:state.chars];

            state.curIndex = 0;
            CGSize fitSize;

            float curY = 0.0f;

            //  Keep drawing lines of text until we're out of characters
            while (CGFontWrapFunc(&state, maxSize.width, &fitSize, fontAtlasGetCharWidth, _atlasGlyphs)) {
                fitSize.height = _lineHeight;

                if (curY + (fitSize.height * 2) > maxSize.height + VERTICAL_FORGIVENESS_MARGIN) {
                    CGSize retSize;
                    addOutputLine(0,
                                  curY,
                                  maxSize.width,
                                  state.lineStart - state.chars,
                                  state.chars + state.count - state.lineStart,
                                  &retSize);
                    if (retSize.width > totalSizeRet->width) {
                        totalSizeRet->width = retSize.width;
                    }
                    if (curY + retSize.height > totalSizeRet->height) {
                        totalSizeRet->height = curY + retSize.height;
                    }
                    break;
                } else {
                    CGSize retSize;
                    addOutputLine(0, curY, maxSize.width, state.lineStart - state.chars, state.lineLen, &retSize);
                    if (retSize.width > totalSizeRet->width) {
                        totalSizeRet->width = retSize.width;
                    }
                    if (curY + retSize.height > totalSizeRet->height) {
                        totalSizeRet->height = curY + retSize.height;
                    }

                    curY += _lineHeight;
                }
            }
        } break;

        default: {
            CGSize retSize;
            addOutputLine(0, 0, maxSize.width, 0, _numAtlasGlyphs, &retSize);
            if (retSize.width > totalSizeRet->width) {
                totalSizeRet->width = retSize.width;
            }
            if (retSize.height > totalSizeRet->height) {
                totalSizeRet->height = retSize.height;
            }
        } break;
    }

    return true;
}

void DisplayTextureFontAtlas::addOperation(CADisplayProperties* presentationProperties,
                                           CAPoint3D* quad,
                                           CGPoint* texquad,
                                           int numQuads,
                                           float alpha,
                                           float r,
                                           float g,
                                           float b,
                                           float a,
                                           DrawingObserver* observer) {
    if (alpha >= 0.1f) {
        if (presentationProperties->backgroundColor.a != 0.0f) {
            float aOut = presentationProperties->backgroundColor.a * alpha;
            _drawingList.AddOperation(quad,
                                      NULL,
                                      1,
                                      NULL,
                                      alpha,
                                      ADM_NO_ALPHA,
                                      presentationProperties->backgroundColor.r,
                                      presentationProperties->backgroundColor.g,
                                      presentationProperties->backgroundColor.b,
                                      aOut,
                                      observer);
        }
    }

    if (_font == nil || _text == nil)
        return;

    FontAtlasMan* fontMan = FontAtlasMan::get();

    CAPoint3D loc = quad[0];

    int len = [_text length];

    if (fontMan->generationCount() > _curFontGeneration) {
        _curFontGeneration = fontMan->generationCount();
        _glyphsDirty = true;
    }

    if (_glyphsDirty) {
        if (_atlasGlyphs)
            EbrFree(_atlasGlyphs);
        _atlasGlyphs = (FontAtlasOutputGlyph*)EbrMalloc(len * sizeof(FontAtlasOutputGlyph));
        if (_quadOut)
            EbrFree(_quadOut);
        _quadOut = (CAPoint3D*)EbrMalloc(4 * (len + 16) * sizeof(CAPoint3D));
        if (_shadowQuadOut)
            EbrFree(_shadowQuadOut);
        _shadowQuadOut = (CAPoint3D*)EbrMalloc(4 * (len + 16) * sizeof(CAPoint3D));
        if (_texQuadOut)
            EbrFree(_texQuadOut);
        _texQuadOut = (CGPoint*)EbrMalloc(4 * (len + 16) * sizeof(CGPoint));
        if (_texPtrs)
            EbrFree(_texPtrs);
        _texPtrs = (EbrTexture**)EbrMalloc(4 * (len + 16) * sizeof(EbrTexture*));

        _numAtlasGlyphs = len;

        fontMan->getDrawList(_atlasGlyphs, _font, _text, _sdfFont);
        fontMan->getDrawList(_ellipsis, _font, @".", _sdfFont);

        _lineHeight = _ellipsis->glyphSize.height;

        _glyphsDirty = false;
        _linesDirty = true;
    }

    CGRect rect;
    rect.origin.x = quad[0].x;
    rect.origin.y = quad[0].y;
    rect.size.width = quad[1].x - quad[0].x;
    rect.size.height = quad[3].y - quad[0].y;

    rect.origin.x -= presentationProperties->bounds.origin.x;
    rect.origin.y -= presentationProperties->bounds.origin.y;

    if (memcmp(&_lastRenderedRect, &rect, sizeof(CGRect)) != 0) {
        memcpy(&_lastRenderedRect, &rect, sizeof(CGRect));
        _linesDirty = true;
    }

    if (_linesDirty) {
        _linesDirty = false;

        _numQuads = 0;
        _numOutputLines = 0;

        rect.origin.x += _edgeInsets.left;
        rect.origin.y += _edgeInsets.top;
        rect.size.width -= _edgeInsets.left + _edgeInsets.right;
        rect.size.height -= _edgeInsets.top + _edgeInsets.bottom;

        CGSize sizeOut;
        CGSize maxSize = rect.size;
        if (_numLines == 1)
            maxSize.height = _lineHeight;

        reflowText(maxSize, &sizeOut);

        if (_centerVertically) {
            EbrCenterTextInRectVertically(&rect, &sizeOut, _font);
        } else {
            CGRect centerRect;
            centerRect.origin.x = 0;
            centerRect.origin.y = 0;
            centerRect.size = sizeOut;
            EbrCenterTextInRectVertically(&centerRect, &sizeOut, _font);
            rect.origin.y += centerRect.origin.y;
        }

        for (int i = 0; i < _numOutputLines; i++) {
            CGRect alignedRect = rect;
            switch (_alignment) {
                case UITextAlignmentLeft:
                    break;

                case UITextAlignmentCenter:
                    alignedRect.origin.x += maxSize.width / 2.0f - _outputLines[i].totalSize.width / 2.0f;
                    break;

                case UITextAlignmentRight:
                    alignedRect.origin.x += maxSize.width - _outputLines[i].totalSize.width;
                    break;
            }

            for (int j = _outputLines[i].startQuad; j < _outputLines[i].startQuad + _outputLines[i].numQuads; j++) {
                _quadOut[j].x += alignedRect.origin.x;
                _quadOut[j].y += alignedRect.origin.y;
                _quadOut[j].z += loc.z;
            }
        }

        if (_shadowColor != nil && (_shadowOffset.width || _shadowOffset.height)) {
            for (int i = 0; i < _numQuads; i++) {
                _shadowQuadOut[i].x = _quadOut[i].x + _shadowOffset.width;
                _shadowQuadOut[i].y = _quadOut[i].y + _shadowOffset.height;
                _shadowQuadOut[i].z = _quadOut[i].z;
            }
        }
    }

    if (_shadowColor != nil && (_shadowOffset.width || _shadowOffset.height)) {
        [_shadowColor getRed:&r green:&g blue:&b alpha:&a];
        emitOperations(_shadowQuadOut, _numQuads, alpha, r, g, b, a, observer, _sdfFont);
    }

    [_color getRed:&r green:&g blue:&b alpha:&a];
    emitOperations(_quadOut, _numQuads, alpha, r, g, b, a, observer, _sdfFont);
}

EbrFastTexture* DisplayTextureFontAtlas::khrBuffer() {
    return NULL;
}
