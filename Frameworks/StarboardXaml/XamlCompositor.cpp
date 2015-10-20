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

// XamlCompositor.cpp : Defines the exported functions for the DLL application.
//

#include <wrl/client.h>
#include <memory>
#include <agile.h>
#include <ppltasks.h>
#include <robuffer.h>
#include <collection.h>
#include <assert.h>
using namespace Windows::Storage::Streams;
using namespace Microsoft::WRL;

#include "winobjc\winobjc.h"
#include "CompositorInterface.h"

Windows::UI::Xaml::Controls::Grid ^ rootNode;
Windows::UI::Xaml::Controls::Canvas ^ windowCollection;
XamlCompositorCS::Controls::CAXamlDebugCounters ^ debugCounters;
extern float screenWidth, screenHeight;
void GridSizeChanged(float newWidth, float newHeight);

void IncrementCounter(const char* name) {
    return;
    std::string sname(name);
    std::wstring wname(sname.begin(), sname.end());
    XamlCompositorCS::Controls::CAXamlDebugCounters::IncCounter(ref new Platform::String(wname.data()));
}

void DecrementCounter(const char* name) {
    return;
    std::string sname(name);
    std::wstring wname(sname.begin(), sname.end());
    XamlCompositorCS::Controls::CAXamlDebugCounters::DecCounter(ref new Platform::String(wname.data()));
}

void OnGridSizeChanged(Platform::Object ^ sender, Windows::UI::Xaml::SizeChangedEventArgs ^ e) {
    Windows::Foundation::Size newSize = e->NewSize;
    GridSizeChanged(newSize.Width, newSize.Height);
}

void SetRootGrid(winobjc::Id& root) {
    rootNode = (Windows::UI::Xaml::Controls::Grid ^ )(Platform::Object ^ )root;
    windowCollection = ref new Windows::UI::Xaml::Controls::Canvas();
    windowCollection->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
    windowCollection->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

    debugCounters = ref new XamlCompositorCS::Controls::CAXamlDebugCounters();
    debugCounters->SetValue(Windows::UI::Xaml::Controls::Grid::ColumnProperty, 1);
    rootNode->Children->Append(debugCounters);
    rootNode->Children->Append(windowCollection);
    rootNode->InvalidateArrange();

    rootNode->SizeChanged += ref new Windows::UI::Xaml::SizeChangedEventHandler(&OnGridSizeChanged);
}

void IWXamlTouch(float x, float y, unsigned int touchID, int event, unsigned __int64 timestampMicro);
void IWXamlKeyInput(int key);
#define EVENT_DOWN 0x64
#define EVENT_MOVE 0x65
#define EVENT_UP 0x66

void (*RenderCallback)();

ref class XamlRenderingListener sealed {
private:
    bool _isListening = false;
    Windows::Foundation::EventHandler<Platform::Object ^> ^ listener;
    Windows::Foundation::EventRegistrationToken listenerToken;
    internal : void RenderedFrame(Object ^ sender, Object ^ args) {
        if (RenderCallback)
            RenderCallback();
    }

    XamlRenderingListener() {
        listener = ref new Windows::Foundation::EventHandler<Platform::Object ^>(this, &XamlRenderingListener::RenderedFrame);
    }

    void Start() {
        if (!_isListening) {
            _isListening = true;
            listenerToken = Windows::UI::Xaml::Media::CompositionTarget::Rendering += listener;
        }
    }

    void Stop() {
        if (!_isListening) {
            _isListening = false;
            Windows::UI::Xaml::Media::CompositionTarget::Rendering -= listenerToken;
        }
    }
};

XamlRenderingListener ^ renderListener;

void EnableRenderingListener(void (*callback)()) {
    RenderCallback = callback;
    if (renderListener == nullptr) {
        renderListener = ref new XamlRenderingListener();
    }
    renderListener->Start();
}

void DisableRenderingListener() {
    renderListener->Stop();
}

ref class XamlUIEventHandler sealed : XamlCompositorCS::Controls::CALayerXamlInputEvents {
public:
    virtual void PointerDown(float x, float y, unsigned int pointerId, unsigned __int64 timestampMicro) {
        IWXamlTouch(x, y, pointerId, EVENT_DOWN, timestampMicro);
    }

    virtual void PointerUp(float x, float y, unsigned int pointerId, unsigned __int64 timestampMicro) {
        IWXamlTouch(x, y, pointerId, EVENT_UP, timestampMicro);
    }

    virtual void PointerMoved(float x, float y, unsigned int pointerId, unsigned __int64 timestampMicro) {
        IWXamlTouch(x, y, pointerId, EVENT_MOVE, timestampMicro);
    }

    virtual void KeyDown(unsigned int key) {
        IWXamlKeyInput((int)key);
    }
};

static XamlUIEventHandler ^ uiHandlerSingleton;

void SetUIHandlers() {
    uiHandlerSingleton = ref new XamlUIEventHandler();
    XamlCompositorCS::Controls::CALayerInputHandler::SetInputHandler(uiHandlerSingleton);
}

static XamlCompositorCS::Controls::CALayerXaml ^
    GetCALayer(DisplayNode* node) { return (XamlCompositorCS::Controls::CALayerXaml ^ )(Platform::Object ^ )node->_xamlNode; };

static XamlCompositorCS::Controls::EventedStoryboard ^
    GetStoryboard(DisplayAnimation* anim) {
        return (XamlCompositorCS::Controls::EventedStoryboard ^ )(Platform::Object ^ )anim->_xamlAnimation;
    }

    DisplayNode::DisplayNode() {
    _xamlNode = (Platform::Object ^ )XamlCompositorCS::Controls::CALayerXaml::CreateLayer();
    isRoot = false;
    parent = NULL;
    currentTexture = NULL;
    topMost = false;
}

DisplayNode::~DisplayNode() {
    auto xamlLayer = GetCALayer(this);
    XamlCompositorCS::Controls::CALayerXaml::DestroyLayer(xamlLayer);
    for (auto curNode : _subnodes) {
        curNode->parent = NULL;
    }
}

DisplayAnimation::DisplayAnimation() {
    easingFunction = EaseInEaseOut;
}

DisplayAnimation::~DisplayAnimation() {
}

void DisplayAnimation::CreateXamlAnimation() {
    auto xamlAnimation = ref new XamlCompositorCS::Controls::EventedStoryboard(
        beginTime, duration, autoReverse, repeatCount, repeatDuration, speed, timeOffset);

    switch (easingFunction) {
        case Easing::EaseInEaseOut: {
            auto easing = ref new Windows::UI::Xaml::Media::Animation::QuadraticEase();
            easing->EasingMode = Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
            xamlAnimation->AnimationEase = easing;
        } break;

        case Easing::EaseIn: {
            auto easing = ref new Windows::UI::Xaml::Media::Animation::QuadraticEase();
            easing->EasingMode = Windows::UI::Xaml::Media::Animation::EasingMode::EaseIn;
            xamlAnimation->AnimationEase = easing;
        } break;

        case Easing::EaseOut: {
            auto easing = ref new Windows::UI::Xaml::Media::Animation::QuadraticEase();
            easing->EasingMode = Windows::UI::Xaml::Media::Animation::EasingMode::EaseOut;
            xamlAnimation->AnimationEase = easing;
        } break;

        case Easing::Default: {
            auto easing = ref new Windows::UI::Xaml::Media::Animation::QuadraticEase();
            easing->EasingMode = Windows::UI::Xaml::Media::Animation::EasingMode::EaseInOut;
            xamlAnimation->AnimationEase = easing;
        } break;

        case Easing::Linear: {
            xamlAnimation->AnimationEase = nullptr;
        } break;
    }

    _xamlAnimation = (Platform::Object ^ )xamlAnimation;
}

void DisplayAnimation::Start() {
    XamlCompositorCS::Controls::EventedStoryboard ^ xamlAnimation =
        (XamlCompositorCS::Controls::EventedStoryboard ^ )(Platform::Object ^ )_xamlAnimation;

    AddRef();
    xamlAnimation->Completed = ref new XamlCompositorCS::Controls::AnimationMethod([this](Platform::Object ^ sender) {
        this->Completed();
        XamlCompositorCS::Controls::EventedStoryboard ^ xamlAnimation =
            (XamlCompositorCS::Controls::EventedStoryboard ^ )(Platform::Object ^ ) this->_xamlAnimation;
        xamlAnimation->Completed = nullptr;
        this->Release();
    });
    xamlAnimation->Start();
}

void DisplayAnimation::Stop() {
    XamlCompositorCS::Controls::EventedStoryboard ^ xamlAnimation =
        (XamlCompositorCS::Controls::EventedStoryboard ^ )(Platform::Object ^ )_xamlAnimation;

    Windows::UI::Xaml::Media::Animation::Storyboard ^ storyboard =
        (Windows::UI::Xaml::Media::Animation::Storyboard ^ )(Platform::Object ^ )xamlAnimation->GetStoryboard();
    storyboard->Stop();
}

void DisplayAnimation::AddAnimation(DisplayNode* node, const wchar_t* propertyName, bool fromValid, float from, bool toValid, float to) {
    auto xamlNode = GetCALayer(node);
    auto xamlAnimation = GetStoryboard(this);

    xamlAnimation->Animate(xamlNode,
                           ref new Platform::String(propertyName),
                           fromValid ? (Platform::Object ^ )(double)from : nullptr,
                           toValid ? (Platform::Object ^ )(double)to : nullptr);
}

unsigned int XamlWaitHandle(uintptr_t hEvent, unsigned int timeout);

void DisplayAnimation::AddTransitionAnimation(DisplayNode* node, const char* type, const char* subtype) {
    auto xamlNode = GetCALayer(node);
    auto xamlAnimation = GetStoryboard(this);

    std::string stype(type);
    std::wstring wtype(stype.begin(), stype.end());
    std::string ssubtype(subtype);
    std::wstring wsubtype(ssubtype.begin(), ssubtype.end());
    auto async = xamlAnimation->AddTransition(xamlNode, ref new Platform::String(wtype.data()), ref new Platform::String(wsubtype.data()));
    HANDLE newEvent = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
    async->Completed = ref new Windows::Foundation::AsyncOperationCompletedHandler<int>(
        [newEvent](Platform::Object ^ sender, Windows::Foundation::AsyncStatus result) { SetEvent(newEvent); });
    XamlWaitHandle((uintptr_t)newEvent, INFINITE);
    CloseHandle(newEvent);
}

void DisplayNode::AddToRoot() {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    windowCollection->Children->Append(xamlNode);

    SetMasksToBounds(true);
    xamlNode->SetTopMost();

    isRoot = true;
}

void DisplayNode::SetProperty(const wchar_t* name, float value) {
    auto xamlNode = GetCALayer(this);
    xamlNode->Set(ref new Platform::String(name), (double)value);
}

void DisplayNode::SetPropertyInt(const wchar_t* name, int value) {
    auto xamlNode = GetCALayer(this);
    xamlNode->Set(ref new Platform::String(name), (int)value);
}

void DisplayNode::SetHidden(bool hidden) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    xamlNode->hidden = hidden;
}

void DisplayNode::SetMasksToBounds(bool masksToBounds) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    xamlNode->Set("masksToBounds", (bool)masksToBounds);
}

float DisplayNode::GetPresentationPropertyValue(const char* name) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = (XamlCompositorCS::Controls::CALayerXaml ^ )(Platform::Object ^ )_xamlNode;
    std::string str(name);
    std::wstring wstr(str.begin(), str.end());

    return (float)(double)xamlNode->Get(ref new Platform::String(wstr.data()));
}

void DisplayNode::SetContentsCenter(float x, float y, float width, float height) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    xamlNode->SetContentsCenter(Windows::Foundation::Rect(x, y, width, height));
}

void DisplayNode::SetTopMost() {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    topMost = true;
    xamlNode->SetTopMost();
}

void DisplayNode::SetBackgroundColor(float r, float g, float b, float a) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    if (!isRoot && !topMost) {
        xamlNode->SetBackgroundColor(r, g, b, a);
    }
}

void UpdateRootNode() {
}

void DisplayNode::AddSubnode(DisplayNode* node, DisplayNode* before, DisplayNode* after) {
    assert(node->parent == NULL);
    node->parent = this;
    _subnodes.insert(node);

    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(node);
    Windows::UI::Xaml::Controls::Panel ^ xamlSuperNode = GetCALayer(this);

    if (before == NULL && after == NULL) {
        xamlSuperNode->Children->Append(xamlNode);
    } else if (before != NULL) {
        XamlCompositorCS::Controls::CALayerXaml ^ xamlBeforeNode = GetCALayer(before);
        unsigned int idx = 0;
        if (xamlSuperNode->Children->IndexOf(xamlBeforeNode, &idx) == true) {
            xamlSuperNode->Children->InsertAt(idx, xamlNode);
        } else {
            assert(0);
        }
    } else if (after != NULL) {
        XamlCompositorCS::Controls::CALayerXaml ^ xamlAfterNode = GetCALayer(after);
        unsigned int idx = 0;
        if (xamlSuperNode->Children->IndexOf(xamlAfterNode, &idx) == true) {
            xamlSuperNode->Children->InsertAt(idx + 1, xamlNode);
        } else {
            assert(0);
        }
    }
    xamlSuperNode->InvalidateArrange();
}

void DisplayNode::MoveNode(DisplayNode* before, DisplayNode* after) {
    assert(parent != NULL);

    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    Windows::UI::Xaml::Controls::Panel ^ xamlSuperNode = GetCALayer(parent);

    if (before != NULL) {
        XamlCompositorCS::Controls::CALayerXaml ^ xamlBeforeNode = GetCALayer(before);

        unsigned int srcIdx = 0;
        if (xamlSuperNode->Children->IndexOf(xamlNode, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (xamlSuperNode->Children->IndexOf(xamlBeforeNode, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                xamlSuperNode->Children->RemoveAt(srcIdx);
                xamlSuperNode->Children->InsertAt(destIdx, xamlNode);
            } else {
                assert(0);
            }
        } else {
            assert(0);
        }
    } else {
        assert(after != NULL);

        XamlCompositorCS::Controls::CALayerXaml ^ xamlAfterNode = GetCALayer(after);
        unsigned int srcIdx = 0;
        if (xamlSuperNode->Children->IndexOf(xamlNode, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (xamlSuperNode->Children->IndexOf(xamlAfterNode, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                xamlSuperNode->Children->RemoveAt(srcIdx);
                xamlSuperNode->Children->InsertAt(destIdx + 1, xamlNode);
            } else {
                assert(0);
            }
        } else {
            assert(0);
        }
    }
}

void DisplayNode::RemoveFromSupernode() {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);

    Windows::UI::Xaml::Controls::Panel ^ xamlSuperNode;
    if (isRoot) {
        xamlSuperNode = (Windows::UI::Xaml::Controls::Panel ^ )(Platform::Object ^ )windowCollection;
    } else {
        if (parent == NULL)
            return;
        assert(parent != NULL);
        xamlSuperNode = GetCALayer(parent);
        parent->_subnodes.erase(this);
    }

    parent = NULL;

    unsigned int idx = 0;
    if (xamlSuperNode->Children->IndexOf(xamlNode, &idx) == true) {
        xamlSuperNode->Children->RemoveAt(idx);
    } else {
        assert(0);
    }
}

winobjc::Id CreateBitmapFromImageData(const void* ptr, int len) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage;
    Windows::Storage::Streams::InMemoryRandomAccessStream ^ stream = ref new Windows::Storage::Streams::InMemoryRandomAccessStream();
    Windows::Storage::Streams::DataWriter ^ rw = ref new Windows::Storage::Streams::DataWriter(stream->GetOutputStreamAt(0));
    auto var = ref new Platform::Array<unsigned char, 1>(len);

    memcpy(var->Data, ptr, len);
    rw->WriteBytes(var);
    rw->StoreAsync();

    auto loadImage = bitmap->SetSourceAsync(stream);

    return (Platform::Object ^ )bitmap;
}

winobjc::Id CreateBitmapFromBits(void* ptr, int width, int height, int stride) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::WriteableBitmap(width, height);
    Windows::Storage::Streams::IBuffer ^ pixelData = bitmap->PixelBuffer;

    ComPtr<IBufferByteAccess> bufferByteAccess;
    reinterpret_cast<IInspectable*>(pixelData)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));

    // Retrieve the buffer data.
    byte* pixels = nullptr;
    bufferByteAccess->Buffer(&pixels);

    byte* in = (byte*)ptr;
    for (int y = 0; y < height; y++) {
        memcpy(pixels, in, stride);
        pixels += width * 4;
        in += stride;
    }

    return bitmap;
}

winobjc::Id CreateWritableBitmap(int width, int height) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::WriteableBitmap(width, height);

    return bitmap;
}

void* LockWritableBitmap(winobjc::Id& bitmap, void** ptr, int* stride) {
    Windows::UI::Xaml::Media::Imaging::WriteableBitmap ^ writableBitmap =
        (Windows::UI::Xaml::Media::Imaging::WriteableBitmap ^ )(Platform::Object ^ )bitmap;
    ComPtr<IBufferByteAccess> bufferByteAccess;
    Windows::Storage::Streams::IBuffer ^ pixelData = writableBitmap->PixelBuffer;

    *stride = writableBitmap->PixelWidth * 4;

    reinterpret_cast<IInspectable*>(pixelData)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));
    byte* pixels = nullptr;
    bufferByteAccess->Buffer(&pixels);
    *ptr = pixels;

    return bufferByteAccess.Detach();
}

void UnlockWritableBitmap(winobjc::Id& bitmap, void* byteAccess) {
    IUnknown* pUnk = (IUnknown*)byteAccess;
    pUnk->Release();
}

void DisplayNode::SetContents(winobjc::Id& bitmap, float width, float height, float scale) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    if (((void*)bitmap) != NULL) {
        Windows::UI::Xaml::Media::ImageSource ^ contents = (Windows::UI::Xaml::Media::ImageSource ^ )(Platform::Object ^ )bitmap;

        xamlNode->setContentImage(contents, width, height, scale);
    } else {
        xamlNode->setContentImage(nullptr, width, height, scale);
    }
}

void DisplayNode::SetContentsElement(winobjc::Id& elem, float width, float height, float scale) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    Windows::UI::Xaml::FrameworkElement ^ contents = (Windows::UI::Xaml::FrameworkElement ^ )(Platform::Object ^ )elem;
    xamlNode->setContentElement(contents, width, height, scale);
}

void DisplayNode::SetContentsElement(winobjc::Id& elem) {
    XamlCompositorCS::Controls::CALayerXaml ^ xamlNode = GetCALayer(this);
    Windows::UI::Xaml::FrameworkElement ^ contents = (Windows::UI::Xaml::FrameworkElement ^ )(Platform::Object ^ )elem;
    float width = contents->Width;
    float height = contents->Height;
    float scale = 1.0f;
    xamlNode->setContentElement(contents, width, height, scale);
}

DisplayTextureXamlGlyphs::DisplayTextureXamlGlyphs() {
    _horzAlignment = alignLeft;
    _insets[0] = 0.0f;
    _insets[1] = 0.0f;
    _insets[2] = 0.0f;
    _insets[3] = 0.0f;
    _color[0] = 0.0f;
    _color[1] = 0.0f;
    _color[2] = 0.0f;
    _color[3] = 1.0f;
    _fontSize = 14.0f;

    auto textControl = XamlCompositorCS::Controls::CATextLayerXaml::CreateTextLayer();
    _xamlTextbox = (Platform::Object ^ )textControl;
}

DisplayTextureXamlGlyphs::~DisplayTextureXamlGlyphs() {
    XamlCompositorCS::Controls::CATextLayerXaml ^ textControl =
        (XamlCompositorCS::Controls::CATextLayerXaml ^ )(Platform::Object ^ )_xamlTextbox;
    XamlCompositorCS::Controls::CATextLayerXaml::DestroyTextLayer(textControl);
    _xamlTextbox.Set(NULL);
}

void DisplayTextureXamlGlyphs::ConstructGlyphs(const char* fontName, const wchar_t* str, int length) {
    XamlCompositorCS::Controls::CATextLayerXaml ^ textLayer =
        (XamlCompositorCS::Controls::CATextLayerXaml ^ )(Platform::Object ^ )_xamlTextbox;
    Windows::UI::Xaml::Controls::TextBlock ^ textControl = textLayer->TextBlock;
    textControl->Text = ref new Platform::String(str, length);
    textControl->FontSize = _fontSize;
    Windows::UI::Color textColor;
    textColor.R = (unsigned char)(_color[0] * 255.0f);
    textColor.G = (unsigned char)(_color[1] * 255.0f);
    textColor.B = (unsigned char)(_color[2] * 255.0f);
    textColor.A = (unsigned char)(_color[3] * 255.0f);
    textControl->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(textColor);

    switch (_horzAlignment) {
        case alignLeft:
            textControl->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
            break;
        case alignCenter:
            textControl->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
            break;
        case alignRight:
            textControl->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
            break;
    }

    textControl->Padding = Windows::UI::Xaml::Thickness(_insets[0], _insets[1], _insets[2], _insets[3]);
    textControl->TextWrapping = Windows::UI::Xaml::TextWrapping::Wrap;
    textControl->LineStackingStrategy = Windows::UI::Xaml::LineStackingStrategy::BlockLineHeight;
    textControl->LineHeight = _lineHeight;
}

void DisplayTextureXamlGlyphs::Measure(float width, float height) {
    XamlCompositorCS::Controls::CATextLayerXaml ^ textLayer =
        (XamlCompositorCS::Controls::CATextLayerXaml ^ )(Platform::Object ^ )_xamlTextbox;
    Windows::UI::Xaml::Controls::TextBlock ^ textControl = textLayer->TextBlock;

    textControl->Measure(Windows::Foundation::Size(width, height));

    _desiredWidth = textControl->DesiredSize.Width;
    if (_centerVertically) {
        _desiredHeight = textControl->DesiredSize.Height;
    } else {
        _desiredHeight = height;
    }
}

void DisplayTextureXamlGlyphs::SetNodeContent(DisplayNode* node, float width, float height, float scale) {
    XamlCompositorCS::Controls::CATextLayerXaml ^ textLayer =
        (XamlCompositorCS::Controls::CATextLayerXaml ^ )(Platform::Object ^ )_xamlTextbox;
    winobjc::Id textControl = textLayer->TextBlock;

    float slackWidth = (width / scale) + 2.0f;
    Measure(slackWidth, height / scale);
    node->SetContentsElement(textControl, slackWidth, _desiredHeight, 1.0f);
}

void SetScreenParameters(float width, float height, float magnification, float rotation) {
    windowCollection->Width = width;
    windowCollection->Height = height;
    windowCollection->InvalidateArrange();
    windowCollection->InvalidateMeasure();
    rootNode->InvalidateArrange();
    rootNode->InvalidateMeasure();
    XamlCompositorCS::Controls::CALayerXaml::ApplyMagnificationFactor(windowCollection, magnification, rotation);
}

void CreateXamlCompositor(winobjc::Id& root);

__declspec(dllexport) void IWSetXamlRoot(Windows::UI::Xaml::Controls::Grid ^ grid) {
    winobjc::Id gridObj((Platform::Object ^ )grid);
    CreateXamlCompositor(gridObj);
}
