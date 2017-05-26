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

// WindowsUIStartScreen.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.StartScreen.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIStartScreen.h"
#include "WindowsUIStartScreen_priv.h"

@implementation WUSJumpListItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpListItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::StartScreen::IJumpListItemStatics> WUSIJumpListItemStatics_inst() {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpListItemStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.StartScreen.JumpListItem").Get(), &inst));
    return inst;
}

+ (WUSJumpListItem*)createWithArguments:(NSString*)arguments displayName:(NSString*)displayName {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpListItem> unmarshalledReturn;
    auto _comInst = WUSIJumpListItemStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithArguments(nsStrToHstr(arguments).Get(), nsStrToHstr(displayName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSJumpListItem>(unmarshalledReturn.Get());
}

+ (WUSJumpListItem*)createSeparator {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpListItem> unmarshalledReturn;
    auto _comInst = WUSIJumpListItemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSeparator(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSJumpListItem>(unmarshalledReturn.Get());
}

- (WUSJumpListItemKind)kind {
    ABI::Windows::UI::StartScreen::JumpListItemKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUSJumpListItemKind)unmarshalledReturn;
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)removedByUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemovedByUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)groupName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_GroupName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroupName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_GroupName(nsStrToHstr(value).Get()));
}

- (WFUri*)logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setLogo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpListItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WUSJumpList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::StartScreen::IJumpListStatics> WUSIJumpListStatics_inst() {
    ComPtr<ABI::Windows::UI::StartScreen::IJumpListStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.StartScreen.JumpList").Get(), &inst));
    return inst;
}

+ (void)loadCurrentAsyncWithSuccess:(void (^)(WUSJumpList*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::StartScreen::JumpList*>> unmarshalledReturn;
    auto _comInst = WUSIJumpListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadCurrentAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::StartScreen::JumpList*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::StartScreen::JumpList*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::StartScreen::IJumpList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUSJumpList>(result.Get()));
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

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WUSIJumpListStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WUSJumpListItem* */)items {
    ComPtr<IVector<ABI::Windows::UI::StartScreen::JumpListItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUSJumpListItem_create(unmarshalledReturn.Get());
}

- (WUSJumpListSystemGroupKind)systemGroupKind {
    ABI::Windows::UI::StartScreen::JumpListSystemGroupKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemGroupKind(&unmarshalledReturn));
    return (WUSJumpListSystemGroupKind)unmarshalledReturn;
}

- (void)setSystemGroupKind:(WUSJumpListSystemGroupKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpList>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemGroupKind((ABI::Windows::UI::StartScreen::JumpListSystemGroupKind)value));
}

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IJumpList>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WUSSecondaryTileVisualElements

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setSquare30x30Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square30x30Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square30x30Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square30x30Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSquare70x70Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square70x70Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square70x70Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square70x70Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSquare150x150Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square150x150Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square150x150Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square150x150Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setWide310x150Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_Wide310x150Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)wide310x150Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_Wide310x150Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSquare310x310Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square310x310Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square310x310Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square310x310Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setForegroundText:(WUSForegroundText)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundText((ABI::Windows::UI::StartScreen::ForegroundText)value));
}

- (WUSForegroundText)foregroundText {
    ABI::Windows::UI::StartScreen::ForegroundText unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundText(&unmarshalledReturn));
    return (WUSForegroundText)unmarshalledReturn;
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setShowNameOnSquare150x150Logo:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowNameOnSquare150x150Logo((boolean)value));
}

- (BOOL)showNameOnSquare150x150Logo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowNameOnSquare150x150Logo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShowNameOnWide310x150Logo:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowNameOnWide310x150Logo((boolean)value));
}

- (BOOL)showNameOnWide310x150Logo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowNameOnWide310x150Logo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShowNameOnSquare310x310Logo:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowNameOnSquare310x310Logo((boolean)value));
}

- (BOOL)showNameOnSquare310x310Logo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowNameOnSquare310x310Logo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSquare71x71Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square71x71Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square71x71Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square71x71Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSquare44x44Logo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements3>(self);
    THROW_NS_IF_FAILED(_comInst->put_Square44x44Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)square44x44Logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Square44x44Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WUSSecondaryTile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.StartScreen.SecondaryTile").Get(), &out));
    return [_createRtProxy<WUSSecondaryTile>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory> WUSISecondaryTileFactory_inst() {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.StartScreen.SecondaryTile").Get(), &inst));
    return inst;
}

+ (WUSSecondaryTile*)makeTile:(NSString*)tileId
                    shortName:(NSString*)shortName
                  displayName:(NSString*)displayName
                    arguments:(NSString*)arguments
                  tileOptions:(WUSTileOptions)tileOptions
                logoReference:(WFUri*)logoReference {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTile> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTile(nsStrToHstr(tileId).Get(),
                                            nsStrToHstr(shortName).Get(),
                                            nsStrToHstr(displayName).Get(),
                                            nsStrToHstr(arguments).Get(),
                                            (ABI::Windows::UI::StartScreen::TileOptions)tileOptions,
                                            _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(logoReference).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUSSecondaryTile>(unmarshalledReturn.Get()) retain];
}

+ (WUSSecondaryTile*)makeWideTile:(NSString*)tileId
                        shortName:(NSString*)shortName
                      displayName:(NSString*)displayName
                        arguments:(NSString*)arguments
                      tileOptions:(WUSTileOptions)tileOptions
                    logoReference:(WFUri*)logoReference
                wideLogoReference:(WFUri*)wideLogoReference {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTile> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWideTile(nsStrToHstr(tileId).Get(),
                                                nsStrToHstr(shortName).Get(),
                                                nsStrToHstr(displayName).Get(),
                                                nsStrToHstr(arguments).Get(),
                                                (ABI::Windows::UI::StartScreen::TileOptions)tileOptions,
                                                _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(logoReference).Get(),
                                                _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(wideLogoReference).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUSSecondaryTile>(unmarshalledReturn.Get()) retain];
}

+ (WUSSecondaryTile*)makeWithId:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTile> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithId(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUSSecondaryTile>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory2> WUSISecondaryTileFactory2_inst() {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.StartScreen.SecondaryTile").Get(), &inst));
    return inst;
}

+ (WUSSecondaryTile*)makeMinimalTile:(NSString*)tileId
                         displayName:(NSString*)displayName
                           arguments:(NSString*)arguments
                   square150x150Logo:(WFUri*)square150x150Logo
                         desiredSize:(WUSTileSize)desiredSize {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTile> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileFactory2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMinimalTile(nsStrToHstr(tileId).Get(),
                                                   nsStrToHstr(displayName).Get(),
                                                   nsStrToHstr(arguments).Get(),
                                                   _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(square150x150Logo).Get(),
                                                   (ABI::Windows::UI::StartScreen::TileSize)desiredSize,
                                                   unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUSSecondaryTile>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileStatics> WUSISecondaryTileStatics_inst() {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.StartScreen.SecondaryTile").Get(), &inst));
    return inst;
}

+ (BOOL)exists:(NSString*)tileId {
    boolean unmarshalledReturn;
    auto _comInst = WUSISecondaryTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Exists(nsStrToHstr(tileId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WUSSecondaryTile* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUSSecondaryTile_create(result.Get()));
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

+ (void)findAllForApplicationAsync:(NSString*)applicationId
                           success:(void (^)(NSArray* /* WUSSecondaryTile* */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllForApplicationAsync(nsStrToHstr(applicationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUSSecondaryTile_create(result.Get()));
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

+ (void)findAllForPackageAsyncWithSuccess:(void (^)(NSArray* /* WUSSecondaryTile* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>> unmarshalledReturn;
    auto _comInst = WUSISecondaryTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllForPackageAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUSSecondaryTile_create(result.Get()));
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

- (void)setTileId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TileId(nsStrToHstr(value).Get()));
}

- (NSString*)tileId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setArguments:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Arguments(nsStrToHstr(value).Get()));
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setShortName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShortName(nsStrToHstr(value).Get()));
}

- (NSString*)shortName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShortName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLogo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Logo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSmallLogo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmallLogo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)smallLogo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallLogo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setWideLogo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_WideLogo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)wideLogo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_WideLogo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setLockScreenBadgeLogo:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_LockScreenBadgeLogo(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WFUri*)lockScreenBadgeLogo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_LockScreenBadgeLogo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setLockScreenDisplayBadgeAndTileText:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_LockScreenDisplayBadgeAndTileText((boolean)value));
}

- (BOOL)lockScreenDisplayBadgeAndTileText {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_LockScreenDisplayBadgeAndTileText(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTileOptions:(WUSTileOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TileOptions((ABI::Windows::UI::StartScreen::TileOptions)value));
}

- (WUSTileOptions)tileOptions {
    ABI::Windows::UI::StartScreen::TileOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileOptions(&unmarshalledReturn));
    return (WUSTileOptions)unmarshalledReturn;
}

- (void)setForegroundText:(WUSForegroundText)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundText((ABI::Windows::UI::StartScreen::ForegroundText)value));
}

- (WUSForegroundText)foregroundText {
    ABI::Windows::UI::StartScreen::ForegroundText unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundText(&unmarshalledReturn));
    return (WUSForegroundText)unmarshalledReturn;
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)requestCreateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCreateAsync(&unmarshalledReturn));

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

- (void)requestCreateAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCreateAsyncWithPoint(*[invocationPoint internalStruct], &unmarshalledReturn));

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

- (void)requestCreateAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCreateAsyncWithRect(*[selection internalStruct], &unmarshalledReturn));

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

- (void)requestCreateAsyncWithRectAndPlacement:(WFRect*)selection
                            preferredPlacement:(WUPPlacement)preferredPlacement
                                       success:(void (^)(BOOL))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCreateAsyncWithRectAndPlacement(*[selection internalStruct],
                                                                        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                        &unmarshalledReturn));

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

- (void)requestDeleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDeleteAsync(&unmarshalledReturn));

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

- (void)requestDeleteAsyncWithPoint:(WFPoint*)invocationPoint success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDeleteAsyncWithPoint(*[invocationPoint internalStruct], &unmarshalledReturn));

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

- (void)requestDeleteAsyncWithRect:(WFRect*)selection success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDeleteAsyncWithRect(*[selection internalStruct], &unmarshalledReturn));

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

- (void)requestDeleteAsyncWithRectAndPlacement:(WFRect*)selection
                            preferredPlacement:(WUPPlacement)preferredPlacement
                                       success:(void (^)(BOOL))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDeleteAsyncWithRectAndPlacement(*[selection internalStruct],
                                                                        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                        &unmarshalledReturn));

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

- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAsync(&unmarshalledReturn));

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

- (void)setPhoneticName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PhoneticName(nsStrToHstr(value).Get()));
}

- (NSString*)phoneticName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneticName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUSSecondaryTileVisualElements*)visualElements {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualElements(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSSecondaryTileVisualElements>(unmarshalledReturn.Get());
}

- (void)setRoamingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoamingEnabled((boolean)value));
}

- (BOOL)roamingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addVisualElementsRequestedEvent:(void (^)(WUSSecondaryTile*, WUSVisualElementsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->add_VisualElementsRequested(
        Make<ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisualElementsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::ISecondaryTile2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisualElementsRequested(token));
}

@end

@implementation WUSVisualElementsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::IVisualElementsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUSVisualElementsRequest*)request {
    ComPtr<ABI::Windows::UI::StartScreen::IVisualElementsRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSVisualElementsRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUSVisualElementsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::IVisualElementsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUSSecondaryTileVisualElements*)visualElements {
    ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualElements(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSSecondaryTileVisualElements>(unmarshalledReturn.Get());
}

- (NSArray* /* WUSSecondaryTileVisualElements* */)alternateVisualElements {
    ComPtr<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTileVisualElements*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateVisualElements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUSSecondaryTileVisualElements_create(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WUSVisualElementsRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::StartScreen::IVisualElementsRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUSVisualElementsRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUSVisualElementsRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::StartScreen::IVisualElementsRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::StartScreen::IVisualElementsRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

id RTProxiedNSArray_WUSSecondaryTile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>,
                                         RTArrayObj<ABI::Windows::UI::StartScreen::ISecondaryTile*,
                                                    IVectorView<ABI::Windows::UI::StartScreen::SecondaryTile*>,
                                                    WUSSecondaryTile,
                                                    ABI::Windows::UI::StartScreen::SecondaryTile*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUSSecondaryTileVisualElements_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::StartScreen::SecondaryTileVisualElements*>,
                                         RTArrayObj<ABI::Windows::UI::StartScreen::ISecondaryTileVisualElements*,
                                                    IVectorView<ABI::Windows::UI::StartScreen::SecondaryTileVisualElements*>,
                                                    WUSSecondaryTileVisualElements,
                                                    ABI::Windows::UI::StartScreen::SecondaryTileVisualElements*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUSJumpListItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::StartScreen::JumpListItem*>,
                                                RTMutableArrayObj<ABI::Windows::UI::StartScreen::IJumpListItem*,
                                                                  IVector<ABI::Windows::UI::StartScreen::JumpListItem*>,
                                                                  WUSJumpListItem,
                                                                  ABI::Windows::UI::StartScreen::JumpListItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
