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
// clang-format does not like C++/CX
// clang-format off

#include <wrl/client.h>
#include <memory>
#include <agile.h>
#include <ppltasks.h>
#include <robuffer.h>
#include <collection.h>
#include <assert.h>
#include "CALayerXaml.h"

#include <windows.ui.xaml.automation.peers.h>
#include <windows.ui.xaml.media.h>

using namespace concurrency;
using namespace Windows::Storage::Streams;
using namespace Microsoft::WRL;

#include "winobjc\winobjc.h"
#include "ApplicationCompositor.h"
#include "CompositorInterface.h"
#include <StringHelpers.h>

Windows::UI::Xaml::Controls::Grid^ rootNode;
Windows::UI::Xaml::Controls::Canvas^ windowCollection;
extern float screenWidth, screenHeight;
void GridSizeChanged(float newWidth, float newHeight);

void OnGridSizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e) {
    Windows::Foundation::Size newSize = e->NewSize;
    GridSizeChanged(newSize.Width, newSize.Height);
}

void SetRootGrid(winobjc::Id& root) {
    rootNode = (Windows::UI::Xaml::Controls::Grid^)(Platform::Object^)root;

    // canvas serves as the container for UI windows, thus named as windowCollection
    windowCollection = ref new Windows::UI::Xaml::Controls::Canvas();
    windowCollection->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
    windowCollection->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

    // for the canvas servering window collection, we give it a special name
    // useful for later when we try to locate this canvas
    windowCollection->Name = L"windowCollection";

    rootNode->Children->Append(windowCollection);
    rootNode->InvalidateArrange();

    rootNode->SizeChanged += ref new Windows::UI::Xaml::SizeChangedEventHandler(&OnGridSizeChanged);
}

void (*RenderCallback)();

ref class XamlRenderingListener sealed {
private:
    bool _isListening = false;
    Windows::Foundation::EventHandler<Platform::Object^>^ listener;
    Windows::Foundation::EventRegistrationToken listenerToken;
    internal : void RenderedFrame(Object^ sender, Object^ args) {
        if (RenderCallback)
            RenderCallback();
    }

    XamlRenderingListener() {
        listener = ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &XamlRenderingListener::RenderedFrame);
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

XamlRenderingListener^ renderListener;

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

XamlCompositor::Controls::CALayerXaml^ GetLayoutElement(DisplayNode* node) {
    return (XamlCompositor::Controls::CALayerXaml^)(Platform::Object^)node->_layoutElement;
};

Windows::UI::Xaml::Controls::Panel^ GetContentElement(DisplayNode* node) {
    return (Windows::UI::Xaml::Controls::Panel^)(Platform::Object^)node->_contentElement;
};

static XamlCompositor::Controls::EventedStoryboard^ GetStoryboard(DisplayAnimation* anim) {
    return (XamlCompositor::Controls::EventedStoryboard^)(Platform::Object^)anim->_xamlAnimation;
}

void DisplayNode::SetScrollviewerControls(IInspectable* rootControl, IInspectable* contentControl) {

    // append the rootElement as the first (and the only) child of the layoutElement
    XamlCompositor::Controls::CALayerXaml^ layoutPanel = (XamlCompositor::Controls::CALayerXaml^)(Platform::Object^)_layoutElement;

    winobjc::Id root = rootControl;
    Windows::UI::Xaml::Controls::ContentControl^ rootContentControl = (Windows::UI::Xaml::Controls::ContentControl^)(Platform::Object^)root;
    rootContentControl->Name = L"ContentControl";
    layoutPanel->Children->Append(rootContentControl);

    _contentElement = contentControl;
}

DisplayAnimation::DisplayAnimation() {
    easingFunction = EaseInEaseOut;
}

DisplayAnimation::~DisplayAnimation() {
}

void DisplayAnimation::CreateXamlAnimation() {
    auto xamlAnimation = ref new XamlCompositor::Controls::EventedStoryboard(
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

    _xamlAnimation = (Platform::Object^)xamlAnimation;
}

void DisplayAnimation::Start() {
    auto xamlAnimation = (XamlCompositor::Controls::EventedStoryboard^)(Platform::Object^)_xamlAnimation;

    AddRef();
    xamlAnimation->Completed = ref new XamlCompositor::Controls::AnimationMethod([this](Platform::Object^ sender) {
        this->Completed();
        auto xamlAnimation = (XamlCompositor::Controls::EventedStoryboard^)(Platform::Object^)this->_xamlAnimation;
        xamlAnimation->Completed = nullptr;
        this->Release();
    });
    xamlAnimation->Start();
}

void DisplayAnimation::Stop() {
    auto xamlAnimation = (XamlCompositor::Controls::EventedStoryboard^)(Platform::Object^)_xamlAnimation;
    auto storyboard = (Windows::UI::Xaml::Media::Animation::Storyboard^)(Platform::Object^)xamlAnimation->GetStoryboard();
    storyboard->Stop();
}

concurrency::task<void> DisplayAnimation::AddAnimation(DisplayNode* node, const wchar_t* propertyName, bool fromValid, float from, bool toValid, float to) {
    auto xamlNode = GetLayoutElement(node);
    auto xamlAnimation = GetStoryboard(this);

    xamlAnimation->Animate(xamlNode,
                           ref new Platform::String(propertyName),
                           fromValid ? (Platform::Object^)(double)from : nullptr,
                           toValid ? (Platform::Object^)(double)to : nullptr);

    return concurrency::task_from_result();
}

concurrency::task<void> DisplayAnimation::AddTransitionAnimation(DisplayNode* node, const char* type, const char* subtype) {
    auto xamlNode = GetLayoutElement(node);
    auto xamlAnimation = GetStoryboard(this);

    std::string stype(type);
    std::wstring wtype(stype.begin(), stype.end());
    std::string ssubtype(subtype);
    std::wstring wsubtype(ssubtype.begin(), ssubtype.end());

    // Render a layer snapshot, then kick off the animation
    return xamlAnimation->SnapshotLayer(xamlNode)
        .then([this, xamlAnimation, xamlNode, wtype, wsubtype](XamlCompositor::Controls::CALayerXaml^ snapshotLayer) noexcept {

        xamlAnimation->AddTransition(
            xamlNode,
            snapshotLayer,
            ref new Platform::String(wtype.data()),
            ref new Platform::String(wsubtype.data()));

        Start();
    } , concurrency::task_continuation_context::use_current());
}

DisplayNode::DisplayNode()
{
    _layoutElement = (Platform::Object^)XamlCompositor::Controls::CALayerXaml::CreateLayer();
    _contentElement = _layoutElement;

    isRoot = false;
    parent = NULL;
    currentTexture = NULL;
    topMost = false;
}

DisplayNode::~DisplayNode() {
    XamlCompositor::Controls::CALayerXaml^ xamlLayer = GetLayoutElement(this);
    XamlCompositor::Controls::CALayerXaml::DestroyLayer(xamlLayer);
    for (auto curNode : _subnodes) {
        curNode->parent = NULL;
    }
}

void DisplayNode::AddToRoot() {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    windowCollection->Children->Append(xamlNode);

    SetMasksToBounds(true);
    xamlNode->SetTopMost();

    isRoot = true;
}

void DisplayNode::SetNodeZIndex(int zIndex) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    xamlNode->SetZIndex(zIndex);
}

void DisplayNode::SetProperty(const wchar_t* name, float value) {
    auto xamlNode = GetLayoutElement(this);
    xamlNode->Set(ref new Platform::String(name), (double)value);
}

void DisplayNode::SetPropertyInt(const wchar_t* name, int value) {
    auto xamlNode = GetLayoutElement(this);
    xamlNode->Set(ref new Platform::String(name), (int)value);
}

void DisplayNode::SetHidden(bool hidden) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    xamlNode->Hidden = hidden;
}

void DisplayNode::SetMasksToBounds(bool masksToBounds) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    xamlNode->Set("masksToBounds", (bool)masksToBounds);
}

float DisplayNode::GetPresentationPropertyValue(const char* name) {
    auto xamlNode = (XamlCompositor::Controls::CALayerXaml^)(Platform::Object^)_layoutElement;
    std::string str(name);
    std::wstring wstr(str.begin(), str.end());
    return (float)(double)xamlNode->Get(ref new Platform::String(wstr.data()));
}

void DisplayNode::SetContentsCenter(float x, float y, float width, float height) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    xamlNode->SetContentsCenter(Windows::Foundation::Rect(x, y, width, height));
}

void DisplayNode::SetTopMost() {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    topMost = true;
    xamlNode->SetTopMost();
}

void DisplayNode::SetBackgroundColor(float r, float g, float b, float a) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    if (!isRoot && !topMost) {
        xamlNode->SetBackgroundColor(r, g, b, a);
    }
}

void DisplayNode::SetShouldRasterize(bool rasterize) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    if (rasterize) {
        xamlNode->CacheMode = ref new Windows::UI::Xaml::Media::BitmapCache();
    } else {
        if (xamlNode->CacheMode) {
            delete xamlNode->CacheMode;
            xamlNode->CacheMode = nullptr;
        }
    }
}

void DisplayNode::AddSubnode(DisplayNode* subNode, DisplayNode* before, DisplayNode* after) {
    assert(subNode->parent == NULL);
    subNode->parent = this;
    _subnodes.insert(subNode);

    XamlCompositor::Controls::CALayerXaml^ layoutElementForSubNode = GetLayoutElement(subNode);
    Windows::UI::Xaml::Controls::Panel^ contentElementForThisNode = GetContentElement(this);

    if (before == NULL && after == NULL) {
        contentElementForThisNode->Children->Append(layoutElementForSubNode);
    } else if (before != NULL) {
        XamlCompositor::Controls::CALayerXaml^ xamlBeforeNode = GetLayoutElement(before);
        unsigned int idx = 0;
        if (contentElementForThisNode->Children->IndexOf(xamlBeforeNode, &idx) == true) {
            contentElementForThisNode->Children->InsertAt(idx, layoutElementForSubNode);
        } else {
            assert(0);
        }
    } else if (after != NULL) {
        XamlCompositor::Controls::CALayerXaml^ xamlAfterNode = GetLayoutElement(after);
        unsigned int idx = 0;
        if (contentElementForThisNode->Children->IndexOf(xamlAfterNode, &idx) == true) {
            contentElementForThisNode->Children->InsertAt(idx + 1, layoutElementForSubNode);
        } else {
            assert(0);
        }
    }
    contentElementForThisNode->InvalidateArrange();
}

void DisplayNode::MoveNode(DisplayNode* before, DisplayNode* after) {
    assert(parent != NULL);

    XamlCompositor::Controls::CALayerXaml^ layoutElementForThisNode = GetLayoutElement(this);
    Windows::UI::Xaml::Controls::Panel^ contentElementForParentNode = GetContentElement(parent);

    if (before != NULL) {
        XamlCompositor::Controls::CALayerXaml^ xamlBeforeNode = GetLayoutElement(before);

        unsigned int srcIdx = 0;
        if (contentElementForParentNode->Children->IndexOf(layoutElementForThisNode, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (contentElementForParentNode->Children->IndexOf(xamlBeforeNode, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                contentElementForParentNode->Children->RemoveAt(srcIdx);
                contentElementForParentNode->Children->InsertAt(destIdx, layoutElementForThisNode);
            } else {
                assert(0);
            }
        } else {
            assert(0);
        }
    } else {
        assert(after != NULL);

        XamlCompositor::Controls::CALayerXaml^ xamlAfterNode = GetLayoutElement(after);
        unsigned int srcIdx = 0;
        if (contentElementForParentNode->Children->IndexOf(layoutElementForThisNode, &srcIdx) == true) {
            unsigned int destIdx = 0;
            if (contentElementForParentNode->Children->IndexOf(xamlAfterNode, &destIdx) == true) {
                if (srcIdx == destIdx)
                    return;

                if (srcIdx < destIdx)
                    destIdx--;

                contentElementForParentNode->Children->RemoveAt(srcIdx);
                contentElementForParentNode->Children->InsertAt(destIdx + 1, layoutElementForThisNode);
            } else {
                assert(0);
            }
        } else {
            assert(0);
        }
    }
}

void DisplayNode::RemoveFromSupernode() {
    XamlCompositor::Controls::CALayerXaml^ layoutElementForThisNode = GetLayoutElement(this);

    Windows::UI::Xaml::Controls::Panel^ contentElementForParentNode;
    if (isRoot) {
        contentElementForParentNode = (Windows::UI::Xaml::Controls::Panel^)(Platform::Object^)windowCollection;
    } else {
        if (parent == NULL)
            return;
        assert(parent != NULL);
        contentElementForParentNode = GetContentElement(parent);
        parent->_subnodes.erase(this);
    }

    parent = NULL;

    unsigned int idx = 0;
    if (contentElementForParentNode->Children->IndexOf(layoutElementForThisNode, &idx) == true) {
        contentElementForParentNode->Children->RemoveAt(idx);
    } else {
        assert(0);
    }
}

winobjc::Id CreateBitmapFromImageData(const void* ptr, int len) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage;
    auto stream = ref new Windows::Storage::Streams::InMemoryRandomAccessStream();
    auto rw = ref new Windows::Storage::Streams::DataWriter(stream->GetOutputStreamAt(0));
    auto var = ref new Platform::Array<unsigned char, 1>(len);

    memcpy(var->Data, ptr, len);
    rw->WriteBytes(var);
    rw->StoreAsync();

    auto loadImage = bitmap->SetSourceAsync(stream);

    return (Platform::Object^)bitmap;
}

winobjc::Id CreateBitmapFromBits(void* ptr, int width, int height, int stride) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::WriteableBitmap(width, height);
    Windows::Storage::Streams::IBuffer^ pixelData = bitmap->PixelBuffer;

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

void DisplayNode::SetContents(winobjc::Id& bitmap, float width, float height, float scale) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    if (((void*)bitmap) != NULL) {
        auto contents = (Windows::UI::Xaml::Media::ImageSource^)(Platform::Object^)bitmap;
        xamlNode->SetContentImage(contents, width, height, scale);
    } else {
        xamlNode->SetContentImage(nullptr, width, height, scale);
    }
}

void DisplayNode::SetContentsElement(winobjc::Id& elem, float width, float height, float scale) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    Windows::UI::Xaml::FrameworkElement^ contents = (Windows::UI::Xaml::FrameworkElement^)(Platform::Object^)elem;
    xamlNode->SetContentElement(contents, width, height, scale);
}

void DisplayNode::SetContentsElement(winobjc::Id& elem) {
    XamlCompositor::Controls::CALayerXaml^ xamlNode = GetLayoutElement(this);
    auto contents = (Windows::UI::Xaml::FrameworkElement^)(Platform::Object^)elem;
    float width = static_cast<float>(contents->Width);
    float height = static_cast<float>(contents->Height);
    float scale = 1.0f;
    xamlNode->SetContentElement(contents, width, height, scale);
}

winobjc::Id CreateWritableBitmap(int width, int height) {
    auto bitmap = ref new Windows::UI::Xaml::Media::Imaging::WriteableBitmap(width, height);
    return bitmap;
}

void* LockWritableBitmap(winobjc::Id& bitmap, void** ptr, int* stride) {
    auto writableBitmap = (Windows::UI::Xaml::Media::Imaging::WriteableBitmap^)(Platform::Object^)bitmap;
    ComPtr<IBufferByteAccess> bufferByteAccess;
    Windows::Storage::Streams::IBuffer^ pixelData = writableBitmap->PixelBuffer;

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

    auto textControl = XamlCompositor::Controls::CATextLayerXaml::CreateTextLayer();
    textControl->TextBlock->IsHitTestVisible = false; // Our content should never be HitTestVisible as they are always leaf nodes.
    _xamlTextbox = (Platform::Object^)textControl;
}

DisplayTextureXamlGlyphs::~DisplayTextureXamlGlyphs() {
    auto textControl = (XamlCompositor::Controls::CATextLayerXaml^)(Platform::Object^)_xamlTextbox;
    XamlCompositor::Controls::CATextLayerXaml::DestroyTextLayer(textControl);
    _xamlTextbox = nullptr;
}

Platform::String^ charToPlatformString(const char* str) {
    if (!str) {
        return nullptr;
    }

    std::wstring widStr(str, str + strlen(str));
    return ref new Platform::String(widStr.c_str());
}

void DisplayTextureXamlGlyphs::ConstructGlyphs(const Microsoft::WRL::Wrappers::HString& fontFamilyName, const wchar_t* str, int length) {
    auto textLayer = (XamlCompositor::Controls::CATextLayerXaml^)(Platform::Object^)_xamlTextbox;
    Windows::UI::Xaml::Controls::TextBlock^ textControl = textLayer->TextBlock;
    textControl->Text = ref new Platform::String(str, length);
    textControl->FontSize = _fontSize;
    Windows::UI::Color textColor;
    textColor.R = (unsigned char)(_color[0] * 255.0f);
    textColor.G = (unsigned char)(_color[1] * 255.0f);
    textColor.B = (unsigned char)(_color[2] * 255.0f);
    textColor.A = (unsigned char)(_color[3] * 255.0f);
    textControl->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(textColor);
    textControl->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(reinterpret_cast<Platform::String^>(fontFamilyName.Get()));

    textControl->FontWeight = Windows::UI::Text::FontWeight{ static_cast<unsigned short>(_fontWeight) };
    textControl->FontStretch = static_cast<Windows::UI::Text::FontStretch>(_fontStretch);
    textControl->FontStyle = static_cast<Windows::UI::Text::FontStyle>(_fontStyle);

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
    auto textLayer = (XamlCompositor::Controls::CATextLayerXaml^)(Platform::Object^)_xamlTextbox;
    Windows::UI::Xaml::Controls::TextBlock^ textControl = textLayer->TextBlock;

    textControl->Measure(Windows::Foundation::Size(width, height));

    _desiredWidth = textControl->DesiredSize.Width;
    if (_centerVertically) {
        _desiredHeight = textControl->DesiredSize.Height;
    } else {
        _desiredHeight = height;
    }
}

void DisplayTextureXamlGlyphs::SetNodeContent(DisplayNode* node, float width, float height, float scale) {
    auto textLayer = (XamlCompositor::Controls::CATextLayerXaml^)(Platform::Object^)_xamlTextbox;
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
    XamlCompositor::Controls::CALayerXaml::ApplyMagnificationFactor(windowCollection, magnification, rotation);
}

extern "C" void SetXamlRoot(Windows::UI::Xaml::Controls::Grid^ grid, ActivationType activationType) {
    winobjc::Id gridObj((Platform::Object^)grid);
    CreateXamlCompositor(gridObj, ((activationType == ActivationTypeLibrary) ? CompositionModeLibrary : CompositionModeDefault));
}

void DispatchCompositorTransactions(
    std::deque<std::shared_ptr<ICompositorTransaction>>&& subTransactions,
    std::deque<std::shared_ptr<ICompositorAnimationTransaction>>&& animationTransactions,
    std::map<DisplayNode*, std::map<std::string, std::shared_ptr<ICompositorTransaction>>>&& propertyTransactions,
    std::deque<std::shared_ptr<ICompositorTransaction>>&& movementTransactions) {

    // Walk and process the list of subtransactions
    for (auto& transaction : subTransactions) {
        transaction->Process();
    }

    // Static composition transaction task chain
    static concurrency::task<void> s_compositorTransactions = concurrency::task_from_result();

    // Walk the list of animations and chain each animation task together
    for (auto& animation : animationTransactions) {
        s_compositorTransactions = s_compositorTransactions.then([animation]() noexcept {
            return animation->Process();
        }, concurrency::task_continuation_context::use_current());
    }

    // Walk and process the map of queued properties per DisplayNode and the list of node movements as a single distinct task
    s_compositorTransactions = s_compositorTransactions
        .then([movementTransactions = std::move(movementTransactions),
            propertyTransactions = std::move(propertyTransactions)]() noexcept {
        for (auto& nodeMovement : movementTransactions) {
            nodeMovement->Process();
        }

        for (auto& nodeProperties : propertyTransactions) {
            // Walk the map of queued properties for this DisplayNode
            for (auto& nodeProperty : nodeProperties.second) {
                nodeProperty.second->Process();
            }
        }
    }, concurrency::task_continuation_context::use_current());
}
