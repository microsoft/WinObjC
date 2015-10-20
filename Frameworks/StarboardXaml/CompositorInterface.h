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

#include "winobjc\winobjc.h"

class DisplayNode;
class DisplayTexture;
class DisplayAnimation;
template <class T>
class RefCounted;

class RefCountedType {
    template <class T>
    friend class RefCounted;
    int refCount;

protected:
    void AddRef();
    void Release();

    RefCountedType();
    virtual ~RefCountedType();
};

void IncrementCounter(const char* name);
void DecrementCounter(const char* name);

template <class T>
class RefCounted {
private:
    T* _ptr;

public:
    RefCounted() {
        _ptr = NULL;
    }
    RefCounted(T* ptr) {
        _ptr = ptr;
        if (_ptr)
            _ptr->AddRef();
    }

    RefCounted(const RefCounted& copy) {
        _ptr = copy._ptr;
        if (_ptr)
            _ptr->AddRef();
    }

    ~RefCounted() {
        if (_ptr)
            _ptr->Release();
        _ptr = NULL;
    }
    RefCounted& operator=(const RefCounted& val) {
        if (_ptr == val._ptr)
            return *this;
        T* oldPtr = _ptr;
        _ptr = val._ptr;
        if (_ptr)
            _ptr->AddRef();
        if (oldPtr)
            oldPtr->Release();

        return *this;
    }

    T* operator->() {
        return _ptr;
    }

    T* Get() {
        return _ptr;
    }

    operator bool() {
        return _ptr != NULL;
    }

    bool operator<(const RefCounted& other) const {
        return _ptr < other._ptr;
    }
};

typedef RefCounted<DisplayNode> DisplayNodeRef;
typedef RefCounted<DisplayTexture> DisplayTextureRef;
typedef RefCounted<DisplayAnimation> DisplayAnimationRef;

class DisplayAnimation : public RefCountedType {
    friend class CAXamlCompositor;

public:
    winobjc::Id _xamlAnimation;
    enum Easing { EaseInEaseOut, EaseIn, EaseOut, Linear, Default };

    double beginTime;
    double duration;
    bool autoReverse;
    float repeatCount;
    float repeatDuration;
    float speed;
    double timeOffset;
    Easing easingFunction;

    DisplayAnimation();
    virtual ~DisplayAnimation();

    virtual void Completed() = 0;
    virtual void AddToNode(DisplayNode* node) = 0;

    void CreateXamlAnimation();
    void Start();
    void Stop();

    void AddAnimation(DisplayNode* node, const wchar_t* propertyName, bool fromValid, float from, bool toValid, float to);
    void AddTransitionAnimation(DisplayNode* node, const char* type, const char* subtype);
};

class DisplayTexture : public RefCountedType {
    friend class CAXamlCompositor;

public:
    DisplayTexture();
    virtual ~DisplayTexture();

    virtual void SetNodeContent(DisplayNode* node, float contentWidth, float contentHeight, float contentScale) = 0;
};

class DisplayTextureXamlGlyphs : public DisplayTexture {
public:
    winobjc::Id _xamlTextbox;

    enum DisplayTextureTextHAlignment { alignLeft, alignCenter, alignRight };

    DisplayTextureTextHAlignment _horzAlignment;
    float _insets[4];
    float _color[4];
    float _fontSize;
    float _lineHeight;
    bool _centerVertically;

    DisplayTextureXamlGlyphs();
    ~DisplayTextureXamlGlyphs();

    float _desiredWidth, _desiredHeight;
    void Measure(float width, float height);
    void ConstructGlyphs(const char* fontName, const wchar_t* str, int len);
    void SetNodeContent(DisplayNode* node, float width, float height, float scale);
};

#include <set>

class CAXamlCompositor;

class DisplayNode : public RefCountedType {
    friend class CAXamlCompositor;

public:
    winobjc::Id _xamlNode;
    bool isRoot;
    DisplayNode* parent;
    std::set<DisplayNodeRef> _subnodes;
    DisplayTextureRef currentTexture;
    bool topMost;

public:
    DisplayNode();
    virtual ~DisplayNode();

    void SetTopMost();
    void AddAnimation(DisplayAnimation* animation);
    void SetProperty(const wchar_t* name, float value);
    void SetPropertyInt(const wchar_t* name, int value);
    void SetHidden(bool hidden);
    void SetMasksToBounds(bool masksToBounds);
    void SetBackgroundColor(float r, float g, float b, float a);
    void SetContentsCenter(float x, float y, float width, float height);
    void SetContents(winobjc::Id& bitmap, float width, float height, float scale);
    void SetContents(DisplayTexture* tex, float width, float height, float scale);
    void SetContentsElement(winobjc::Id& elem, float width, float height, float scale);
    void SetContentsElement(winobjc::Id& elem);

    float GetPresentationPropertyValue(const char* name);
    void AddToRoot();

    virtual void* GetProperty(const char* name) = 0;
    virtual void UpdateProperty(const char* name, void* value) = 0;
    void AddSubnode(DisplayNode* node, DisplayNode* before, DisplayNode* after);
    void MoveNode(DisplayNode* before, DisplayNode* after);
    void RemoveFromSupernode();
};

void IncrementCounter(const char* name);
void DecrementCounter(const char* name);
