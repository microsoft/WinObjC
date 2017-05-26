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

// WindowsGraphicsPrinting3D.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Printing3D.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsPrinting3D.h"
#include "WindowsGraphicsPrinting3D_priv.h"

@implementation WGPPrint3DTaskCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrint3DTaskCompletion)completion {
    ABI::Windows::Graphics::Printing3D::Print3DTaskCompletion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completion(&unmarshalledReturn));
    return (WGPPrint3DTaskCompletion)unmarshalledReturn;
}

- (WGPPrint3DTaskDetail)extendedStatus {
    ABI::Windows::Graphics::Printing3D::Print3DTaskDetail unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return (WGPPrint3DTaskDetail)unmarshalledReturn;
}

@end

@implementation WGPPrint3DTaskSourceChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrinting3D3MFPackage*)source {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3D3MFPackage>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrint3DTask

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrinting3D3MFPackage*)source {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3D3MFPackage>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addSubmittingEvent:(void (^)(WGPPrint3DTask*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Submitting(Make<ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_System_Object>(eventHandler).Get(),
                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSubmittingEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Submitting(eventCookie));
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WGPPrint3DTask*, WGPPrint3DTaskCompletedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskCompletedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(eventCookie));
}

- (EventRegistrationToken)addSourceChangedEvent:(void (^)(WGPPrint3DTask*, WGPPrint3DTaskSourceChangedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceChanged(
        Make<ITypedEventHandler_Windows_Graphics_Printing3D_Print3DTask_Windows_Graphics_Printing3D_Print3DTaskSourceChangedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceChanged(eventCookie));
}

@end

@implementation WGPPrint3DTaskSourceRequestedArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setSource:(WGPPrinting3D3MFPackage*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetSource(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(source).Get()));
}

@end

@implementation WGPPrint3DTaskRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrint3DTask*)createTask:(NSString*)title printerId:(NSString*)printerId handler:(WGPPrint3DTaskSourceRequestedHandler)handler {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTask> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequest>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTask(nsStrToHstr(title).Get(),
                                            nsStrToHstr(printerId).Get(),
                                            Make<WGPPrint3DTaskSourceRequestedHandler_shim>(handler).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrint3DTask>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrint3DTaskRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrint3DTaskRequest*)request {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrint3DTaskRequest>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrint3DManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DManagerStatics> WGPIPrint3DManagerStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing3D.Print3DManager").Get(), &inst));
    return inst;
}

+ (WGPPrint3DManager*)getForCurrentView {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrint3DManager> unmarshalledReturn;
    auto _comInst = WGPIPrint3DManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrint3DManager>(unmarshalledReturn.Get());
}

+ (void)showPrintUIAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WGPIPrint3DManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPrintUIAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (EventRegistrationToken)addTaskRequestedEvent:(void (^)(WGPPrint3DManager*, WGPPrint3DTaskRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_TaskRequested(
        Make<ITypedEventHandler_Windows_Graphics_Printing3D_Print3DManager_Windows_Graphics_Printing3D_Print3DTaskRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTaskRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrint3DManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TaskRequested(token));
}

@end

@implementation WGPPrinting3DMeshVerificationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isValid {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsValid(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)nonmanifoldTriangles {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonmanifoldTriangles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

- (NSArray* /* unsigned int */)reversedNormalTriangles {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReversedNormalTriangles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WGPPrinting3DTextureResource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DTextureResource").Get(),
                                              &out));
    return [_createRtProxy<WGPPrinting3DTextureResource>(out.Get()) retain];
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)textureData {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextureData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

- (void)setTextureData:(RTObject<WSSIRandomAccessStreamWithContentType>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_TextureData(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType>(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

@end

@implementation WGPPrinting3DComponent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DComponent").Get(), &out));
    return [_createRtProxy<WGPPrinting3DComponent>(out.Get()) retain];
}

- (WGPPrinting3DMesh*)mesh {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mesh(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DMesh>(unmarshalledReturn.Get());
}

- (void)setMesh:(WGPPrinting3DMesh*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mesh(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(value).Get()));
}

- (NSMutableArray* /* WGPPrinting3DComponentWithMatrix* */)components {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponentWithMatrix*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Components(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DComponentWithMatrix_create(unmarshalledReturn.Get());
}

- (WGPPrinting3DTextureResource*)thumbnail {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DTextureResource>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(WGPPrinting3DTextureResource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(value).Get()));
}

- (WGPPrinting3DObjectType)type {
    ABI::Windows::Graphics::Printing3D::Printing3DObjectType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WGPPrinting3DObjectType)unmarshalledReturn;
}

- (void)setType:(WGPPrinting3DObjectType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::Graphics::Printing3D::Printing3DObjectType)value));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)partNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPartNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(self);
    THROW_NS_IF_FAILED(_comInst->put_PartNumber(nsStrToHstr(value).Get()));
}

@end

@implementation WGPPrinting3DMesh

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DMesh").Get(), &out));
    return [_createRtProxy<WGPPrinting3DMesh>(out.Get()) retain];
}

- (unsigned int)vertexCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVertexCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_VertexCount(value));
}

- (unsigned int)indexCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_IndexCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIndexCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_IndexCount(value));
}

- (WGPPrinting3DBufferDescription*)vertexPositionsDescription {
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexPositionsDescription(&unmarshalledReturn));
    return WGPPrinting3DBufferDescription_create(unmarshalledReturn);
}

- (void)setVertexPositionsDescription:(WGPPrinting3DBufferDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_VertexPositionsDescription(*[value internalStruct]));
}

- (WGPPrinting3DBufferDescription*)vertexNormalsDescription {
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexNormalsDescription(&unmarshalledReturn));
    return WGPPrinting3DBufferDescription_create(unmarshalledReturn);
}

- (void)setVertexNormalsDescription:(WGPPrinting3DBufferDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_VertexNormalsDescription(*[value internalStruct]));
}

- (WGPPrinting3DBufferDescription*)triangleIndicesDescription {
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriangleIndicesDescription(&unmarshalledReturn));
    return WGPPrinting3DBufferDescription_create(unmarshalledReturn);
}

- (void)setTriangleIndicesDescription:(WGPPrinting3DBufferDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_TriangleIndicesDescription(*[value internalStruct]));
}

- (WGPPrinting3DBufferDescription*)triangleMaterialIndicesDescription {
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriangleMaterialIndicesDescription(&unmarshalledReturn));
    return WGPPrinting3DBufferDescription_create(unmarshalledReturn);
}

- (void)setTriangleMaterialIndicesDescription:(WGPPrinting3DBufferDescription*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->put_TriangleMaterialIndicesDescription(*[value internalStruct]));
}

- (RTObject<WSSIBuffer>*)getVertexPositions {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->GetVertexPositions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)createVertexPositions:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVertexPositions(value));
}

- (RTObject<WSSIBuffer>*)getVertexNormals {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->GetVertexNormals(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)createVertexNormals:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVertexNormals(value));
}

- (RTObject<WSSIBuffer>*)getTriangleIndices {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->GetTriangleIndices(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)createTriangleIndices:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTriangleIndices(value));
}

- (RTObject<WSSIBuffer>*)getTriangleMaterialIndices {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->GetTriangleMaterialIndices(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)createTriangleMaterialIndices:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTriangleMaterialIndices(value));
}

- (RTObject<WFCIPropertySet>*)bufferDescriptionSet {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferDescriptionSet(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (RTObject<WFCIPropertySet>*)bufferSet {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferSet(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (void)verifyAsync:(WGPPrinting3DMeshVerificationMode)value
            success:(void (^)(WGPPrinting3DMeshVerificationResult*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3DMeshVerificationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh>(self);
    THROW_NS_IF_FAILED(
        _comInst->VerifyAsync((ABI::Windows::Graphics::Printing3D::Printing3DMeshVerificationMode)value, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Printing3D::Printing3DMeshVerificationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3DMeshVerificationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WGPPrinting3DMeshVerificationResult>(result.Get()));
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

@implementation WGPPrinting3DComponentWithMatrix

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DComponentWithMatrix").Get(),
                                              &out));
    return [_createRtProxy<WGPPrinting3DComponentWithMatrix>(out.Get()) retain];
}

- (WGPPrinting3DComponent*)component {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_Component(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DComponent>(unmarshalledReturn.Get());
}

- (void)setComponent:(WGPPrinting3DComponent*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->put_Component(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(value).Get()));
}

- (WFNMatrix4x4*)matrix {
    ABI::Windows::Foundation::Numerics::Matrix4x4 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_Matrix(&unmarshalledReturn));
    return WFNMatrix4x4_create(unmarshalledReturn);
}

- (void)setMatrix:(WFNMatrix4x4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->put_Matrix(*[value internalStruct]));
}

@end

@implementation WGPPrinting3DColorMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DColorMaterial").Get(), &out));
    return [_createRtProxy<WGPPrinting3DColorMaterial>(out.Get()) retain];
}

- (unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

@end

@implementation WGPPrinting3DModelTexture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DModelTexture").Get(), &out));
    return [_createRtProxy<WGPPrinting3DModelTexture>(out.Get()) retain];
}

- (WGPPrinting3DTextureResource*)textureResource {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextureResource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DTextureResource>(unmarshalledReturn.Get());
}

- (void)setTextureResource:(WGPPrinting3DTextureResource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_TextureResource(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(value).Get()));
}

- (WGPPrinting3DTextureEdgeBehavior)tileStyleU {
    ABI::Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileStyleU(&unmarshalledReturn));
    return (WGPPrinting3DTextureEdgeBehavior)unmarshalledReturn;
}

- (void)setTileStyleU:(WGPPrinting3DTextureEdgeBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(_comInst->put_TileStyleU((ABI::Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior)value));
}

- (WGPPrinting3DTextureEdgeBehavior)tileStyleV {
    ABI::Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileStyleV(&unmarshalledReturn));
    return (WGPPrinting3DTextureEdgeBehavior)unmarshalledReturn;
}

- (void)setTileStyleV:(WGPPrinting3DTextureEdgeBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(self);
    THROW_NS_IF_FAILED(_comInst->put_TileStyleV((ABI::Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior)value));
}

@end

@implementation WGPPrinting3DBaseMaterialGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> WGPIPrinting3DBaseMaterialGroupFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DBaseMaterialGroup").Get(), &inst));
    return inst;
}

+ (WGPPrinting3DBaseMaterialGroup*)make:(unsigned int)MaterialGroupId {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> unmarshalledReturn;
    auto _comInst = WGPIPrinting3DBaseMaterialGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(MaterialGroupId, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPrinting3DBaseMaterialGroup>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DBaseMaterial* */)bases {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterial*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bases(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DBaseMaterial_create(unmarshalledReturn.Get());
}

- (unsigned int)materialGroupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPPrinting3DBaseMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DBaseMaterial").Get(), &out));
    return [_createRtProxy<WGPPrinting3DBaseMaterial>(out.Get()) retain];
}

ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> WGPIPrinting3DBaseMaterialStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DBaseMaterial").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)abs {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIPrinting3DBaseMaterialStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Abs(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pla {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIPrinting3DBaseMaterialStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pla(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WGPPrinting3DColorMaterial*)color {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DColorMaterial>(unmarshalledReturn.Get());
}

- (void)setColor:(WGPPrinting3DColorMaterial*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial>(value).Get()));
}

@end

@implementation WGPPrinting3DColorMaterialGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> WGPIPrinting3DColorMaterialGroupFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DColorMaterialGroup").Get(), &inst));
    return inst;
}

+ (WGPPrinting3DColorMaterialGroup*)make:(unsigned int)MaterialGroupId {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup> unmarshalledReturn;
    auto _comInst = WGPIPrinting3DColorMaterialGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(MaterialGroupId, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPrinting3DColorMaterialGroup>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DColorMaterial* */)colors {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterial*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Colors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DColorMaterial_create(unmarshalledReturn.Get());
}

- (unsigned int)materialGroupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPPrinting3DTexture2CoordMaterialGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory>
WGPIPrinting3DTexture2CoordMaterialGroupFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DTexture2CoordMaterialGroup").Get(), &inst));
    return inst;
}

+ (WGPPrinting3DTexture2CoordMaterialGroup*)make:(unsigned int)MaterialGroupId {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> unmarshalledReturn;
    auto _comInst = WGPIPrinting3DTexture2CoordMaterialGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(MaterialGroupId, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPrinting3DTexture2CoordMaterialGroup>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DTexture2CoordMaterial* */)texture2Coords {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Texture2Coords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterial_create(unmarshalledReturn.Get());
}

- (unsigned int)materialGroupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGPPrinting3DModelTexture*)texture {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Texture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DModelTexture>(unmarshalledReturn.Get());
}

- (void)setTexture:(WGPPrinting3DModelTexture*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Texture(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(value).Get()));
}

@end

@implementation WGPPrinting3DTexture2CoordMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DTexture2CoordMaterial").Get(),
                                              &out));
    return [_createRtProxy<WGPPrinting3DTexture2CoordMaterial>(out.Get()) retain];
}

- (WGPPrinting3DModelTexture*)texture {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Texture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DModelTexture>(unmarshalledReturn.Get());
}

- (void)setTexture:(WGPPrinting3DModelTexture*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_Texture(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture>(value).Get()));
}

- (double)u {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_U(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setU:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_U(value));
}

- (double)v {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_V(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setV:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->put_V(value));
}

@end

@implementation WGPPrinting3DCompositeMaterialGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory>
WGPIPrinting3DCompositeMaterialGroupFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DCompositeMaterialGroup").Get(), &inst));
    return inst;
}

+ (WGPPrinting3DCompositeMaterialGroup*)make:(unsigned int)MaterialGroupId {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> unmarshalledReturn;
    auto _comInst = WGPIPrinting3DCompositeMaterialGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(MaterialGroupId, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPrinting3DCompositeMaterialGroup>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DCompositeMaterial* */)composites {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterial*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Composites(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterial_create(unmarshalledReturn.Get());
}

- (unsigned int)materialGroupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSMutableArray* /* unsigned int */)materialIndices {
    ComPtr<IVector<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialIndices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_UInt32_create(unmarshalledReturn.Get());
}

- (WGPPrinting3DBaseMaterialGroup*)baseMaterialGroup {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseMaterialGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DBaseMaterialGroup>(unmarshalledReturn.Get());
}

- (void)setBaseMaterialGroup:(WGPPrinting3DBaseMaterialGroup*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_BaseMaterialGroup(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup>(value).Get()));
}

@end

@implementation WGPPrinting3DCompositeMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DCompositeMaterial").Get(),
                                              &out));
    return [_createRtProxy<WGPPrinting3DCompositeMaterial>(out.Get()) retain];
}

- (NSMutableArray* /* double */)values {
    ComPtr<IVector<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Values(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_Double_create(unmarshalledReturn.Get());
}

@end

@implementation WGPPrinting3DMultiplePropertyMaterialGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory>
WGPIPrinting3DMultiplePropertyMaterialGroupFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DMultiplePropertyMaterialGroup").Get(), &inst));
    return inst;
}

+ (WGPPrinting3DMultiplePropertyMaterialGroup*)make:(unsigned int)MaterialGroupId {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> unmarshalledReturn;
    auto _comInst = WGPIPrinting3DMultiplePropertyMaterialGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(MaterialGroupId, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPrinting3DMultiplePropertyMaterialGroup>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DMultiplePropertyMaterial* */)multipleProperties {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MultipleProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterial_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* unsigned int */)materialGroupIndices {
    ComPtr<IVector<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupIndices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_UInt32_create(unmarshalledReturn.Get());
}

- (unsigned int)materialGroupId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialGroupId(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPPrinting3DMultiplePropertyMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DMultiplePropertyMaterial").Get(), &out));
    return [_createRtProxy<WGPPrinting3DMultiplePropertyMaterial>(out.Get()) retain];
}

- (NSMutableArray* /* unsigned int */)materialIndices {
    ComPtr<IVector<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaterialIndices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WGPPrinting3DMaterial

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DMaterial").Get(), &out));
    return [_createRtProxy<WGPPrinting3DMaterial>(out.Get()) retain];
}

- (NSMutableArray* /* WGPPrinting3DBaseMaterialGroup* */)baseGroups {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DBaseMaterialGroup_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DColorMaterialGroup* */)colorGroups {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterialGroup*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DColorMaterialGroup_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DTexture2CoordMaterialGroup* */)texture2CoordGroups {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_Texture2CoordGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterialGroup_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DCompositeMaterialGroup* */)compositeGroups {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompositeGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterialGroup_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DMultiplePropertyMaterialGroup* */)multiplePropertyGroups {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(self);
    THROW_NS_IF_FAILED(_comInst->get_MultiplePropertyGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterialGroup_create(unmarshalledReturn.Get());
}

@end

@implementation WGPPrinting3DModel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DModel").Get(), &out));
    return [_createRtProxy<WGPPrinting3DModel>(out.Get()) retain];
}

- (WGPPrinting3DModelUnit)unit {
    ABI::Windows::Graphics::Printing3D::Printing3DModelUnit unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unit(&unmarshalledReturn));
    return (WGPPrinting3DModelUnit)unmarshalledReturn;
}

- (void)setUnit:(WGPPrinting3DModelUnit)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->put_Unit((ABI::Windows::Graphics::Printing3D::Printing3DModelUnit)value));
}

- (NSMutableArray* /* WGPPrinting3DModelTexture* */)textures {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DModelTexture*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Textures(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DModelTexture_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DMesh* */)meshes {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMesh*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Meshes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DMesh_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WGPPrinting3DComponent* */)components {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponent*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Components(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DComponent_create(unmarshalledReturn.Get());
}

- (WGPPrinting3DMaterial*)material {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Material(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DMaterial>(unmarshalledReturn.Get());
}

- (void)setMaterial:(WGPPrinting3DMaterial*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->put_Material(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DMaterial>(value).Get()));
}

- (WGPPrinting3DComponent*)build {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Build(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DComponent>(unmarshalledReturn.Get());
}

- (void)setBuild:(WGPPrinting3DComponent*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->put_Build(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent>(value).Get()));
}

- (NSString*)Version {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)SetVersion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->put_Version(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)requiredExtensions {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequiredExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, NSString * */)metadata {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Metadata(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)repairAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->RepairAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WGPPrinting3DModel*)clone {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModel> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DModel>(unmarshalledReturn.Get());
}

- (void)tryPartialRepairAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->TryPartialRepairAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryPartialRepairWithTimeAsync:(WFTimeSpan*)maxWaitTime success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->TryPartialRepairWithTimeAsync(*[maxWaitTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryReduceFacesAsyncWithSuccess:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->TryReduceFacesAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<bool, double>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, double status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<bool, double>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    boolean result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((BOOL)result);
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

- (void)tryReduceFacesWithOptionsAsync:(WGPPrinting3DFaceReductionOptions*)printing3DFaceReductionOptions
                               success:(void (^)(BOOL))success
                              progress:(void (^)(double))progress
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->TryReduceFacesWithOptionsAsync(
        _getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(printing3DFaceReductionOptions).Get(),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<bool, double>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, double status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<bool, double>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    boolean result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((BOOL)result);
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

- (void)tryReduceFacesWithOptionsAndTimeAsync:(WGPPrinting3DFaceReductionOptions*)printing3DFaceReductionOptions
                                      maxWait:(WFTimeSpan*)maxWait
                                      success:(void (^)(BOOL))success
                                     progress:(void (^)(double))progress
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->TryReduceFacesWithOptionsAndTimeAsync(
        _getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(printing3DFaceReductionOptions).Get(),
        *[maxWait internalStruct],
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<bool, double>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, double status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<bool, double>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    boolean result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((BOOL)result);
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

- (void)repairWithProgressAsyncWithSuccess:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel2>(self);
    THROW_NS_IF_FAILED(_comInst->RepairWithProgressAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<bool, double>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, double status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<bool, double>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<bool, double>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    boolean result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((BOOL)result);
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

@implementation WGPPrinting3DFaceReductionOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3DFaceReductionOptions").Get(),
                                              &out));
    return [_createRtProxy<WGPPrinting3DFaceReductionOptions>(out.Get()) retain];
}

- (double)maxReductionArea {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxReductionArea(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxReductionArea:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxReductionArea(value));
}

- (unsigned int)targetTriangleCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetTriangleCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTargetTriangleCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetTriangleCount(value));
}

- (double)maxEdgeLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxEdgeLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxEdgeLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxEdgeLength(value));
}

@end

@implementation WGPPrinting3D3MFPackage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3D3MFPackage").Get(), &out));
    return [_createRtProxy<WGPPrinting3D3MFPackage>(out.Get()) retain];
}

ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackageStatics> WGPIPrinting3D3MFPackageStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackageStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing3D.Printing3D3MFPackage").Get(),
                                                       &inst));
    return inst;
}

+ (void)loadAsync:(RTObject<WSSIRandomAccessStream>*)value
          success:(void (^)(WGPPrinting3D3MFPackage*))success
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3D3MFPackage*>> unmarshalledReturn;
    auto _comInst = WGPIPrinting3D3MFPackageStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Printing3D::Printing3D3MFPackage*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3D3MFPackage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WGPPrinting3D3MFPackage>(result.Get()));
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

- (void)saveAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (RTObject<WSSIRandomAccessStream>*)printTicket {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintTicket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (void)setPrintTicket:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrintTicket(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (RTObject<WSSIRandomAccessStream>*)modelPart {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelPart(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (void)setModelPart:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->put_ModelPart(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (WGPPrinting3DTextureResource*)thumbnail {
    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrinting3DTextureResource>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(WGPPrinting3DTextureResource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource>(value).Get()));
}

- (NSMutableArray* /* WGPPrinting3DTextureResource* */)textures {
    ComPtr<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTextureResource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Textures(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WGPPrinting3DTextureResource_create(unmarshalledReturn.Get());
}

- (void)loadModelFromPackageAsync:(RTObject<WSSIRandomAccessStream>*)value
                          success:(void (^)(WGPPrinting3DModel*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3DModel*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(
        _comInst->LoadModelFromPackageAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get(),
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Printing3D::Printing3DModel*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Printing3D::Printing3DModel*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Graphics::Printing3D::IPrinting3DModel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WGPPrinting3DModel>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)saveModelToPackageAsync:(WGPPrinting3DModel*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing3D::IPrinting3D3MFPackage>(self);
    THROW_NS_IF_FAILED(_comInst->SaveModelToPackageAsync(_getRtInterface<ABI::Windows::Graphics::Printing3D::IPrinting3DModel>(value).Get(),
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrinting3DBufferDescription {
    ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription)s {
    WGPPrinting3DBufferDescription* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Printing3D::Printing3DBufferDescription*)internalStruct {
    return &structVal;
}
- (WGPPrinting3DBufferFormat)format {
    return (WGPPrinting3DBufferFormat)structVal.Format;
}
- (void)setFormat:(WGPPrinting3DBufferFormat)val {
    structVal.Format = (ABI::Windows::Graphics::Printing3D::Printing3DBufferFormat)val;
}
- (unsigned int)stride {
    return structVal.Stride;
}
- (void)setStride:(unsigned int)val {
    structVal.Stride = val;
}
@end
id RTProxiedNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<unsigned int>,
        RTArrayObj<unsigned int, IVectorView<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_Double_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<double>,
                               RTMutableArrayObj<double, IVector<double>, double, double, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<MutableArrayAdapterObj<
        IVector<unsigned int>,
        RTMutableArrayObj<unsigned int, IVector<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DBaseMaterial_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterial*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterial*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterial*>,
                                                                  WGPPrinting3DBaseMaterial,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterial*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DBaseMaterialGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup*>,
                                                                  WGPPrinting3DBaseMaterialGroup,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DColorMaterial_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterial*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterial*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterial*>,
                                                                  WGPPrinting3DColorMaterial,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DColorMaterial*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DColorMaterialGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterialGroup*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DColorMaterialGroup*>,
                                                 WGPPrinting3DColorMaterialGroup,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DColorMaterialGroup*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DComponent_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponent*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DComponent*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponent*>,
                                                                  WGPPrinting3DComponent,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DComponent*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DComponentWithMatrix_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponentWithMatrix*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DComponentWithMatrix*>,
                                                 WGPPrinting3DComponentWithMatrix,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DComponentWithMatrix*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterial_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterial*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterial*>,
                                                                  WGPPrinting3DCompositeMaterial,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterial*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DCompositeMaterialGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup*>,
                                                 WGPPrinting3DCompositeMaterialGroup,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DMesh_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMesh*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DMesh*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DMesh*>,
                                                                  WGPPrinting3DMesh,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DMesh*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DModelTexture_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DModelTexture*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DModelTexture*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DModelTexture*>,
                                                                  WGPPrinting3DModelTexture,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DModelTexture*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterial_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial*>,
                                                 WGPPrinting3DMultiplePropertyMaterial,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DMultiplePropertyMaterialGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup*>,
                                                 WGPPrinting3DMultiplePropertyMaterialGroup,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterial_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial*>,
                                                 WGPPrinting3DTexture2CoordMaterial,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DTexture2CoordMaterialGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup*>,
                               RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup*,
                                                 IVector<ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup*>,
                                                 WGPPrinting3DTexture2CoordMaterialGroup,
                                                 ABI::Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WGPPrinting3DTextureResource_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Graphics::Printing3D::Printing3DTextureResource*>,
                                                RTMutableArrayObj<ABI::Windows::Graphics::Printing3D::IPrinting3DTextureResource*,
                                                                  IVector<ABI::Windows::Graphics::Printing3D::Printing3DTextureResource*>,
                                                                  WGPPrinting3DTextureResource,
                                                                  ABI::Windows::Graphics::Printing3D::Printing3DTextureResource*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
