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

#ifdef WIN32
#define NOMINMAX
#include <Windows.h>
#endif
#include <pthread.h>
#include "List.h"
#include "LinkedList.h"
#include "Types.h"
#include "Hash.h"

#include "QuartzCore/CALayer.h"
#include "CALayerInternal.h"
#include "QuartzCore/CAAnimation.h"

#include "NativeUIBase.h"
#include "DisplayNode.h"
#include "Animations.h"

class DisplayShape
{
public:
    virtual void RenderShape(CADisplayProperties *properties);
    virtual ~DisplayShape();
};

class DrawingObserver;
class DisplayNode;
class EbrTexture;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;
struct ID3D11DepthStencilView;
struct ID3D11Device1;

// A logical texture as it appears on the screen:
class DisplayTexture
{
public:
    uint32_t refCount;
    DisplayShape *_shapeRenderer;
    int _width, _height;
    CGImageRef _cachedForImage;

    DisplayTexture(int width, int height)
        : refCount(0), _shapeRenderer(0), _width(width), _height(height) {}
    virtual ~DisplayTexture() {}

    void Release();
    void AddRef();

    virtual void realize() = 0;
    virtual bool hasAlpha() const = 0;
    virtual void setOpaque(bool opaque) {};
    virtual bool flipped() const = 0;
    virtual bool renderAfterChildren() { return false; };

    virtual void addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer) = 0;
    virtual void addOperationAfter(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer) { }

    virtual EbrFastTexture *khrBuffer() = 0;

    static EbrLock _displayTextureCacheLock;
    static HashMap<CGImageRef, DisplayTexture *> _displayTextureCache;
    static DisplayTexture *CachedDisplayTextureForImage(CGImageRef img);
    static void SetCachedDisplayTextureForImage(CGImageRef img, DisplayTexture *texture);
};

class DisplayTexturePregen : public DisplayTexture
{
    bool _hasAlpha;
    EbrTexture *_tex;

    int _texWidth, _texHeight;

public:
    bool _flipped;
    DisplayTexturePregen(EbrTexture *tex, int width, int height, bool hasAlpha);
    ~DisplayTexturePregen();

    virtual void realize();
    virtual bool hasAlpha() const;
    virtual void setOpaque(bool opaque);
    virtual bool flipped() const;

    virtual void addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer);

    virtual EbrFastTexture *khrBuffer();
};

class DisplayTextureKHRDoubleBuffered : public DisplayTexture
{
    bool _hasAlpha, _flipped;

    EbrFastTexture *_tex1, *_tex2;
    EbrFastTexture *_curDrawTex;
    int _texWidth, _texHeight;

public:
    DisplayTextureKHRDoubleBuffered(EbrFastTexture *tex1, EbrFastTexture *tex2, int width, int height, int texWidth, int texHeight, bool hasAlpha);
    ~DisplayTextureKHRDoubleBuffered();

    void setActiveDrawTex(EbrFastTexture *tex);

    virtual void realize();
    virtual bool hasAlpha() const;
    virtual void setOpaque(bool opaque);
    virtual bool flipped() const;

    virtual void addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer);

    virtual EbrFastTexture *khrBuffer() { return NULL; }
};

class DisplayTextureFontAtlas;

class DisplayTextureTiled : public DisplayTexture
{
    friend class DisplayTextureFontAtlas; // TODO: BK: fixme
    // The hardware backing to a part (possibly the entirity) of the image:
    struct SubImage
    {
        EbrTexture *_tex;
        int _x, _y, _width, _height;
        int _imageWidth, _imageHeight;

        SubImage(CGImageRef pContents, int x, int y, int width, int height);
        ~SubImage();

        void addOperation(CAPoint3D quad[], CGPoint texCoords[], bool hasAlpha, float alpha, float r, float g, float b, float a, DrawingObserver *observer);
        void realize();
    };
    List<SubImage*> _subImages;

    bool _hasAlpha;
    bool _realized;

public:
    DisplayTextureTiled(CGImageRef image);

    EbrTexture *getTex();
    virtual ~DisplayTextureTiled();

    virtual void realize();
    virtual bool hasAlpha() const;
    virtual bool flipped() const;

    virtual void addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer);

    virtual EbrFastTexture *khrBuffer();
};

struct CATextLayerLine;

struct CATextLayerLine
{
    int startQuad, numQuads;
    CGSize totalSize;
};

class FontAtlasOutputGlyph;

class DisplayTextureFontAtlas : public DisplayTexture
{
    idretain _font;
    idretain _text;
    idretain _color;
    idretain _shadowColor;
    CGSize   _shadowOffset;
    DWORD    _alignment, _lineBreakMode;
    int      _numLines;
    int      _curFontGeneration;
    bool     _sdfFont;

    CATextLayerLine *_outputLines;
    int              _numOutputLines, _maxOutputLines;
    bool             _linesDirty;

    FontAtlasOutputGlyph *_ellipsis;
    FontAtlasOutputGlyph *_atlasGlyphs;
    int                   _numAtlasGlyphs;
    bool                  _glyphsDirty;

    float      _lineHeight;

    CAPoint3D *_quadOut;
    CAPoint3D *_shadowQuadOut;
    CGPoint   *_texQuadOut;
    EbrTexture **_texPtrs;

    int        _numQuads;

    bool       _fontRealized;
    UIEdgeInsets _edgeInsets;
    bool         _centerVertically;

    CGRect      _lastRenderedRect;

public:
    DisplayTextureFontAtlas();
    void SetParams(id font, id text, id color, DWORD alignment, DWORD lineBreak, id shadowColor,
                            const CGSize &shadowOffset, int numLines, UIEdgeInsets edgeInsets, bool centerVertically);
    virtual ~DisplayTextureFontAtlas();
    
    virtual void realize();
    virtual bool hasAlpha() const;
    virtual bool flipped() const;

    virtual void addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer);
    virtual EbrFastTexture *khrBuffer();

    CATextLayerLine *createNewLine();

    void emitOperations(CAPoint3D *quads, int numPoints, float alpha, float r, float g, float b, float a, DrawingObserver *observer, bool sdfFont);
    bool reflowText(CGSize maxSize, CGSize *totalSizeRet);

    float measureWidth(int glyphStart, int numGlyphs);
    void addOutputLine(float x, float y, float maxWidth, int glyphStart, int numGlyphs, CGSize *sizeRet);
};

class DisplayTransaction;

class TransactionList
{
private:
    EbrLock crit;

public:
    TransactionList();
    ~TransactionList();

    void Lock();
    void Unlock();

    void AddTransaction(DisplayTransaction *pTransaction, bool issueRefresh = false);

    DisplayTransaction **_transactions;
    int                  _numTransactions, _maxTransactions;

    int  GetNumTransactions();
    void prepareAndAddToList(TransactionList *preparedList);
    void processTransactions(ID3D11Device1 *device);
};

class DisplayTransaction
{
public:
    typedef enum
    {
        //  Node-tree modifications
        addNodeTransaction,
        removeNodeTransaction,
        moveNodeTransaction,
        sortWindowLevelsTransaction,

        //  Node modifications
        applyDisplayTextureTransaction,
        applyMaskNodeTransaction,
        applyPropertiesTransaction,
        applyBackgroundPatternTransaction,
        releaseBackgroundPatternTransaction,

        addAnimationTransaction,
        removeAnimationTransaction
    } TransactionType;

    TransactionType _transaction;

    typedef struct
    {
        id           layer;
        const char *propertyName;
        NSObject    *newPropertyValue;

        DisplayNode *node;
        DisplayNode *parentNode;
        DisplayNode *addToNode;
        DisplayNode *addBefore;
        DisplayNode *addAfter;

        DisplayNode *maskNode;

        DisplayTexture     *newDisplayTexture;
        DisplayTexture     *newPatternTexture;
        CGColorRef          newPatternBackground;
        CGSize              contentSize;
        float               contentScale;

        id                  animation, animationKey;
        DisplayAnimation   *displayAnimation;
    } transactionParams;

    transactionParams _params;

    static TransactionList *_pendingTransactions;

public:
    DisplayTransaction();
    ~DisplayTransaction();

    void RetainParams();

    static void addNode(DisplayNode *node, DisplayNode *superNode);
    static void addNodeBefore(DisplayNode *node, DisplayNode *before, DisplayNode *superlayer);
    static void addNodeAfter(DisplayNode *layer, DisplayNode *after, DisplayNode *superlayer);

    static void sortWindowLevels();

    static void moveNodeBefore(DisplayNode *node, DisplayNode *beforeNode);
    static void moveNodeAfter(DisplayNode *node, DisplayNode *afterNode);

    static void removeNode(DisplayNode *node);

    static void addAnimation(id layer, id animation, id forKey);
    static void addAnimationRaw(DisplayNode *pNode, DisplayAnimation *pAnimation);
    static void removeAnimationRaw(DisplayNode *pNode, DisplayAnimation *pAnimation);

    static void setNodeTexture(DisplayNode *node, DisplayTexture *newTexture, CGSize contentSize, float contentsScale);
    static void setNodeMaskNode(DisplayNode *node, DisplayNode *maskNode);
    static void setNewPatternBackground(DisplayNode *node, CGColorRef pattern);
    static void setNewProperty(DisplayNode *node, const char *propName, NSObject *newPropValue);
};

void EbrAddDrawingObserver(DrawingObserver *observer);
void EbrRemoveDrawingObserver(DrawingObserver *observer);
void StartNativeUI();
void CreateDisplayList();
void EbrInitCompositor();
bool EbrComposite(ID3D11Device1 *device, ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget);
DisplayTexture * UIGetDisplayTextureForCGImage(CGImageRef img, bool create);

extern int g_numActiveAnimations, g_numQuads;
