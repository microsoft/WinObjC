//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsUIXamlMediaImaging.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Media.Imaging.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlMediaImaging.h"
#include "WindowsUIXamlMediaImaging_priv.h"

@implementation WUXMIDownloadProgressEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)progress {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProgress:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Progress(value));
}

@end

@implementation WUXMIBitmapSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics> WUXMIIBitmapSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapSource").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pixelWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PixelWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pixelHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PixelHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)pixelWidth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)pixelHeight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSource:(RTObject<WSSIRandomAccessStream>*)streamSource {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetSource(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(streamSource).Get()));
}

- (RTObject<WFIAsyncAction>*)setSourceAsync:(RTObject<WSSIRandomAccessStream>*)streamSource {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetSourceAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(streamSource).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WUXMIRenderTargetBitmap

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.RenderTargetBitmap").Get(), &out));
    return [_createRtProxy<WUXMIRenderTargetBitmap>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics> WUXMIIRenderTargetBitmapStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.RenderTargetBitmap").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)pixelWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIRenderTargetBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PixelWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pixelHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIRenderTargetBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PixelHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)pixelWidth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)pixelHeight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)renderAsync:(WXUIElement*)element {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>(self);
    THROW_NS_IF_FAILED(
        _comInst->RenderAsync(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)renderToSizeAsync:(WXUIElement*)element scaledWidth:(int)scaledWidth scaledHeight:(int)scaledHeight {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->RenderToSizeAsync(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(),
                                                   scaledWidth,
                                                   scaledHeight,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getPixelsAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetPixelsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WUXMISurfaceImageSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXMISurfaceImageSource*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.SurfaceImageSource").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithDimensions(pixelWidth, pixelHeight, outer.Get(), &inner, &instance));
    WUXMISurfaceImageSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

+ (WUXMISurfaceImageSource*)makeInstanceWithDimensionsAndOpacity:(int)pixelWidth pixelHeight:(int)pixelHeight isOpaque:(BOOL)isOpaque {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.SurfaceImageSource").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, (boolean)isOpaque, outer.Get(), &inner, &instance));
    WUXMISurfaceImageSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

@end

@implementation WUXMIBitmapImage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory> WUXMIIBitmapImageFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapImage").Get(), &inst));
    return inst;
}

+ (WUXMIBitmapImage*)makeInstanceWithUriSource:(WFUri*)uriSource {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithUriSource(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uriSource).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMIBitmapImage>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapImage").Get(), &out));
    return [_createRtProxy<WUXMIBitmapImage>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics> WUXMIIBitmapImageStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapImage").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)createOptionsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CreateOptionsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)uriSourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UriSourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)decodePixelWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)decodePixelHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3> WUXMIIBitmapImageStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapImage").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isAnimatedBitmapProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsAnimatedBitmapProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isPlayingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPlayingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)autoPlayProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoPlayProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2> WUXMIIBitmapImageStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.BitmapImage").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)decodePixelTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIIBitmapImageStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMIBitmapCreateOptions)createOptions {
    ABI::Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_CreateOptions(&unmarshalledReturn));
    return (WUXMIBitmapCreateOptions)unmarshalledReturn;
}

- (void)setCreateOptions:(WUXMIBitmapCreateOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->put_CreateOptions((ABI::Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions)value));
}

- (WFUri*)uriSource {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_UriSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUriSource:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->put_UriSource(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (int)decodePixelWidth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDecodePixelWidth:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->put_DecodePixelWidth(value));
}

- (int)decodePixelHeight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDecodePixelHeight:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->put_DecodePixelHeight(value));
}

- (EventRegistrationToken)addDownloadProgressEvent:(WUXMIDownloadProgressEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadProgress(Make<WUXMIDownloadProgressEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadProgressEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadProgress(token));
}

- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->add_ImageOpened(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeImageOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ImageOpened(token));
}

- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->add_ImageFailed(Make<WXExceptionRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeImageFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ImageFailed(token));
}

- (WUXMIDecodePixelType)decodePixelType {
    ABI::Windows::UI::Xaml::Media::Imaging::DecodePixelType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecodePixelType(&unmarshalledReturn));
    return (WUXMIDecodePixelType)unmarshalledReturn;
}

- (void)setDecodePixelType:(WUXMIDecodePixelType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DecodePixelType((ABI::Windows::UI::Xaml::Media::Imaging::DecodePixelType)value));
}

- (BOOL)isAnimatedBitmap {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAnimatedBitmap(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPlaying {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPlaying(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)autoPlay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoPlay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoPlay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoPlay((boolean)value));
}

- (void)play {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->Play());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WUXMIVirtualSurfaceImageSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory> WUXMIIVirtualSurfaceImageSourceFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.VirtualSurfaceImageSource").Get(), &inst));
    return inst;
}

+ (WUXMIVirtualSurfaceImageSource*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> unmarshalledReturn;
    auto _comInst = WUXMIIVirtualSurfaceImageSourceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithDimensions(pixelWidth, pixelHeight, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMIVirtualSurfaceImageSource>(unmarshalledReturn.Get()) retain];
}

+ (WUXMIVirtualSurfaceImageSource*)makeInstanceWithDimensionsAndOpacity:(int)pixelWidth
                                                            pixelHeight:(int)pixelHeight
                                                               isOpaque:(BOOL)isOpaque {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> unmarshalledReturn;
    auto _comInst = WUXMIIVirtualSurfaceImageSourceFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, (boolean)isOpaque, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMIVirtualSurfaceImageSource>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WUXMIWriteableBitmap

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory> WUXMIIWriteableBitmapFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.WriteableBitmap").Get(),
                                                       &inst));
    return inst;
}

+ (WUXMIWriteableBitmap*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmap> unmarshalledReturn;
    auto _comInst = WUXMIIWriteableBitmapFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithDimensions(pixelWidth, pixelHeight, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMIWriteableBitmap>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WSSIBuffer>*)pixelBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)invalidate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->Invalidate());
}

@end

@implementation WUXMIXamlRenderingBackgroundTask

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)onRun:(RTObject<WABIBackgroundTaskInstance>*)taskInstance {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>(self);
    THROW_NS_IF_FAILED(
        _comInst->OnRun(_getRtInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(taskInstance).Get()));
}

@end

@implementation WUXMISoftwareBitmapSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Imaging.SoftwareBitmapSource").Get(), &out));
    return [_createRtProxy<WUXMISoftwareBitmapSource>(out.Get()) retain];
}

- (RTObject<WFIAsyncAction>*)setBitmapAsync:(WGISoftwareBitmap*)softwareBitmap {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetBitmapAsync(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end
