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

// WindowsUIXamlControlsMaps.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Controls.Maps.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlControlsMaps.h"
#include "WindowsUIXamlControlsMaps_priv.h"

@implementation WUXCMMapActualCameraChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapActualCameraChangedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapActualCameraChangedEventArgs>(out.Get()) retain];
}

- (WUXCMMapCamera*)camera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Camera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (WUXCMMapCameraChangeReason)changeReason {
    ABI::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeReason(&unmarshalledReturn));
    return (WUXCMMapCameraChangeReason)unmarshalledReturn;
}

@end

@implementation WUXCMMapActualCameraChangingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapActualCameraChangingEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapActualCameraChangingEventArgs>(out.Get()) retain];
}

- (WUXCMMapCamera*)camera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Camera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (WUXCMMapCameraChangeReason)changeReason {
    ABI::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeReason(&unmarshalledReturn));
    return (WUXCMMapCameraChangeReason)unmarshalledReturn;
}

@end

@implementation WUXCMMapCustomExperienceChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapCustomExperienceChangedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapCustomExperienceChangedEventArgs>(out.Get()) retain];
}

@end

@implementation WUXCMMapElementClickEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElementClickEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXCMMapElementClickEventArgs>(out.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUXCMMapElement* */)mapElements {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapElements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXCMMapElement_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapElementPointerEnteredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElementPointerEnteredEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapElementPointerEnteredEventArgs>(out.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (WUXCMMapElement*)mapElement {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapElement>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapElementPointerExitedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElementPointerExitedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapElementPointerExitedEventArgs>(out.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (WUXCMMapElement*)mapElement {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapElement>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapRightTappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapRightTappedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXCMMapRightTappedEventArgs>(out.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapTargetCameraChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTargetCameraChangedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapTargetCameraChangedEventArgs>(out.Get()) retain];
}

- (WUXCMMapCamera*)camera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Camera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (WUXCMMapCameraChangeReason)changeReason {
    ABI::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeReason(&unmarshalledReturn));
    return (WUXCMMapCameraChangeReason)unmarshalledReturn;
}

@end

@implementation WUXCMMapTileBitmapRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestDeferral").Get(),
                                              &out));
    return [_createRtProxy<WUXCMMapTileBitmapRequestDeferral>(out.Get()) retain];
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUXCMMapTileBitmapRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequest").Get(), &out));
    return [_createRtProxy<WUXCMMapTileBitmapRequest>(out.Get()) retain];
}

- (RTObject<WSSIRandomAccessStreamReference>*)pixelData {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setPixelData:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_PixelData(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WUXCMMapTileBitmapRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapTileBitmapRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapTileBitmapRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapTileBitmapRequestedEventArgs>(out.Get()) retain];
}

- (int)x {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_X(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)y {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)zoomLevel {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCMMapTileBitmapRequest*)request {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapTileBitmapRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapTileUriRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequestDeferral").Get(),
                                              &out));
    return [_createRtProxy<WUXCMMapTileUriRequestDeferral>(out.Get()) retain];
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUXCMMapTileUriRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequest").Get(), &out));
    return [_createRtProxy<WUXCMMapTileUriRequest>(out.Get()) retain];
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WUXCMMapTileUriRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapTileUriRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapTileUriRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequestedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXCMMapTileUriRequestedEventArgs>(out.Get()) retain];
}

- (int)x {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_X(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)y {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)zoomLevel {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCMMapTileUriRequest*)request {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapTileUriRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapCamera

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCameraFactory> WUXCMIMapCameraFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCameraFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapCamera").Get(), &inst));
    return inst;
}

+ (WUXCMMapCamera*)makeInstanceWithLocation:(WDGGeopoint*)location {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = WUXCMIMapCameraFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithLocation(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get()) retain];
}

+ (WUXCMMapCamera*)makeInstanceWithLocationAndHeading:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = WUXCMIMapCameraFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstanceWithLocationAndHeading(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                       headingInDegrees,
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get()) retain];
}

+ (WUXCMMapCamera*)makeInstanceWithLocationHeadingAndPitch:(WDGGeopoint*)location
                                          headingInDegrees:(double)headingInDegrees
                                            pitchInDegrees:(double)pitchInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = WUXCMIMapCameraFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstanceWithLocationHeadingAndPitch(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                            headingInDegrees,
                                                            pitchInDegrees,
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get()) retain];
}

+ (WUXCMMapCamera*)makeInstanceWithLocationHeadingPitchRollAndFieldOfView:(WDGGeopoint*)location
                                                         headingInDegrees:(double)headingInDegrees
                                                           pitchInDegrees:(double)pitchInDegrees
                                                            rollInDegrees:(double)rollInDegrees
                                                     fieldOfViewInDegrees:(double)fieldOfViewInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = WUXCMIMapCameraFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
        headingInDegrees,
        pitchInDegrees,
        rollInDegrees,
        fieldOfViewInDegrees,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get()) retain];
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (void)setLocation:(WDGGeopoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(value).Get()));
}

- (double)heading {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_Heading(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeading:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_Heading(value));
}

- (double)pitch {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pitch(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPitch:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_Pitch(value));
}

- (double)roll {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_Roll(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRoll:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_Roll(value));
}

- (double)fieldOfView {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_FieldOfView(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFieldOfView:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_FieldOfView(value));
}

@end

@implementation WUXCMMapCustomExperience

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapCustomExperience").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMMapCustomExperience* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

@end

@implementation WUXCMMapElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElement").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMMapElement* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics2> WUXCMIMapElementStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)mapTabIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapElementStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MapTabIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics> WUXCMIMapElementStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)zIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)visibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)zIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setZIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZIndex(value));
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visible((boolean)value));
}

- (int)mapTabIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapTabIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMapTabIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MapTabIndex(value));
}

@end

@implementation WUXCMMapInputEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapInputEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapInputEventArgs>(out.Get()) retain];
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapItemsControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapItemsControl").Get(), &out));
    return [_createRtProxy<WUXCMMapItemsControl>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics> WUXCMIMapItemsControlStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapItemsControl").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)itemsSourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapItemsControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemsSourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapItemsControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemTemplateProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapItemsControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemTemplateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (RTObject*)itemsSource {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemsSource(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setItemsSource:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemsSource([value comObj].Get()));
}

- (NSMutableArray* /* WXDependencyObject* */)items {
    ComPtr<IVector<ABI::Windows::UI::Xaml::DependencyObject*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXDependencyObject_create(unmarshalledReturn.Get());
}

- (WXDataTemplate*)itemTemplate {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemTemplate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDataTemplate>(unmarshalledReturn.Get());
}

- (void)setItemTemplate:(WXDataTemplate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemTemplate(_getRtInterface<ABI::Windows::UI::Xaml::IDataTemplate>(value).Get()));
}

@end

@implementation WUXCMMapRouteView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXCMMapRouteView*)makeInstanceWithMapRoute:(WSMMapRoute*)route {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteViewFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapRouteView").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithMapRoute(_getRtInterface<ABI::Windows::Services::Maps::IMapRoute>(route).Get(),
                                                           outer.Get(),
                                                           &inner,
                                                           &instance));
    WUXCMMapRouteView* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WUColor*)routeColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView>(self);
    THROW_NS_IF_FAILED(_comInst->get_RouteColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setRouteColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView>(self);
    THROW_NS_IF_FAILED(_comInst->put_RouteColor(*[value internalStruct]));
}

- (WUColor*)outlineColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutlineColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setOutlineColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutlineColor(*[value internalStruct]));
}

- (WSMMapRoute*)route {
    ComPtr<ABI::Windows::Services::Maps::IMapRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Route(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMMapRoute>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapScene

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapSceneStatics> WUXCMIMapSceneStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapSceneStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapScene").Get(), &inst));
    return inst;
}

+ (WUXCMMapScene*)createFromBoundingBox:(WDGGeoboundingBox*)bounds {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBoundingBox(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(bounds).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromBoundingBoxWithHeadingAndPitch:(WDGGeoboundingBox*)bounds
                                          headingInDegrees:(double)headingInDegrees
                                            pitchInDegrees:(double)pitchInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBoundingBoxWithHeadingAndPitch(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(bounds).Get(),
        headingInDegrees,
        pitchInDegrees,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromCamera:(WUXCMMapCamera*)camera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromCamera(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera>(camera).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocation:(WDGGeopoint*)location {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLocation(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocationWithHeadingAndPitch:(WDGGeopoint*)location
                                       headingInDegrees:(double)headingInDegrees
                                         pitchInDegrees:(double)pitchInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromLocationWithHeadingAndPitch(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                        headingInDegrees,
                                                        pitchInDegrees,
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocationAndRadius:(WDGGeopoint*)location radiusInMeters:(double)radiusInMeters {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLocationAndRadius(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                             radiusInMeters,
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocationAndRadiusWithHeadingAndPitch:(WDGGeopoint*)location
                                                  radiusInMeters:(double)radiusInMeters
                                                headingInDegrees:(double)headingInDegrees
                                                  pitchInDegrees:(double)pitchInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLocationAndRadiusWithHeadingAndPitch(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
        radiusInMeters,
        headingInDegrees,
        pitchInDegrees,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocations:(id<NSFastEnumeration> /* WDGGeopoint* */)locations {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLocations(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(locations)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

+ (WUXCMMapScene*)createFromLocationsWithHeadingAndPitch:(id<NSFastEnumeration> /* WDGGeopoint* */)locations
                                        headingInDegrees:(double)headingInDegrees
                                          pitchInDegrees:(double)pitchInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = WUXCMIMapSceneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLocationsWithHeadingAndPitch(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(locations)
                .Get()),
        headingInDegrees,
        pitchInDegrees,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

- (WUXCMMapCamera*)targetCamera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetCamera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addTargetCameraChangedEvent:(void (^)(WUXCMMapScene*, WUXCMMapTargetCameraChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(self);
    THROW_NS_IF_FAILED(_comInst->add_TargetCameraChanged(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapScene_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs>(value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TargetCameraChanged(token));
}

@end

@implementation WUXCMMapTileDataSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileDataSource").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMMapTileDataSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

@end

@implementation WUXCMMapTileSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileSource").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMMapTileSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics> WUXCMIMapTileSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapTileSource").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)dataSourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataSourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)layerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LayerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)zoomLevelRangeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevelRangeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)boundsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BoundsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)allowOverstretchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowOverstretchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isFadingEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsFadingEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isTransparencyEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsTransparencyEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isRetryEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsRetryEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)zIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)tilePixelSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TilePixelSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)visibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapTileSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXCMMapTileDataSource*)dataSource {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapTileDataSource>(unmarshalledReturn.Get());
}

- (void)setDataSource:(WUXCMMapTileDataSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataSource(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>(value).Get()));
}

- (WUXCMMapTileLayer)layer {
    ABI::Windows::UI::Xaml::Controls::Maps::MapTileLayer unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Layer(&unmarshalledReturn));
    return (WUXCMMapTileLayer)unmarshalledReturn;
}

- (void)setLayer:(WUXCMMapTileLayer)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Layer((ABI::Windows::UI::Xaml::Controls::Maps::MapTileLayer)value));
}

- (WUXCMMapZoomLevelRange*)zoomLevelRange {
    ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevelRange(&unmarshalledReturn));
    return WUXCMMapZoomLevelRange_create(unmarshalledReturn);
}

- (void)setZoomLevelRange:(WUXCMMapZoomLevelRange*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZoomLevelRange(*[value internalStruct]));
}

- (WDGGeoboundingBox*)bounds {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

- (void)setBounds:(WDGGeoboundingBox*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bounds(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(value).Get()));
}

- (BOOL)allowOverstretch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowOverstretch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowOverstretch:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowOverstretch((boolean)value));
}

- (BOOL)isFadingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFadingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsFadingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsFadingEnabled((boolean)value));
}

- (BOOL)isTransparencyEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTransparencyEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsTransparencyEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTransparencyEnabled((boolean)value));
}

- (BOOL)isRetryEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRetryEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRetryEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRetryEnabled((boolean)value));
}

- (int)zIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setZIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZIndex(value));
}

- (int)tilePixelSize {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_TilePixelSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTilePixelSize:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_TilePixelSize(value));
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visible((boolean)value));
}

@end

@implementation WUXCMStreetsidePanorama

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics> WUXCMIStreetsidePanoramaStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.StreetsidePanorama").Get(),
                                                       &inst));
    return inst;
}

+ (void)findNearbyWithLocationAsync:(WDGGeopoint*)location
                            success:(void (^)(WUXCMStreetsidePanorama*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>> unmarshalledReturn;
    auto _comInst = WUXCMIStreetsidePanoramaStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindNearbyWithLocationAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUXCMStreetsidePanorama>(result.Get()));
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

+ (void)findNearbyWithLocationAndRadiusAsync:(WDGGeopoint*)location
                              radiusInMeters:(double)radiusInMeters
                                     success:(void (^)(WUXCMStreetsidePanorama*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>> unmarshalledReturn;
    auto _comInst = WUXCMIStreetsidePanoramaStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindNearbyWithLocationAndRadiusAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                       radiusInMeters,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUXCMStreetsidePanorama>(result.Get()));
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

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMCustomMapTileDataSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSourceFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.CustomMapTileDataSource").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMCustomMapTileDataSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (EventRegistrationToken)addBitmapRequestedEvent:(void (^)(WUXCMCustomMapTileDataSource*, WUXCMMapTileBitmapRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_BitmapRequested(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_CustomMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileBitmapRequestedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBitmapRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BitmapRequested(token));
}

@end

@implementation WUXCMHttpMapTileDataSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.HttpMapTileDataSource").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMHttpMapTileDataSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (NSString*)uriFormatString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_UriFormatString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUriFormatString:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_UriFormatString(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSString * */)additionalRequestHeaders {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalRequestHeaders(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)allowCaching {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowCaching(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowCaching:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowCaching((boolean)value));
}

- (EventRegistrationToken)addUriRequestedEvent:(void (^)(WUXCMHttpMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_UriRequested(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_HttpMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUriRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UriRequested(token));
}

@end

@implementation WUXCMLocalMapTileDataSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSourceFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.LocalMapTileDataSource").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCMLocalMapTileDataSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (NSString*)uriFormatString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_UriFormatString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUriFormatString:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_UriFormatString(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addUriRequestedEvent:(void (^)(WUXCMLocalMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_UriRequested(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_LocalMapTileDataSource_Windows_UI_Xaml_Controls_Maps_MapTileUriRequestedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUriRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UriRequested(token));
}

@end

@implementation WUXCMMapIcon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapIcon").Get(), &out));
    return [_createRtProxy<WUXCMMapIcon>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics2> WUXCMIMapIconStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapIcon").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)collisionBehaviorDesiredProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapIconStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CollisionBehaviorDesiredProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics> WUXCMIMapIconStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapIcon").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)locationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapIconStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)titleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapIconStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TitleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)normalizedAnchorPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapIconStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NormalizedAnchorPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (void)setLocation:(WDGGeopoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(value).Get()));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (WFPoint*)normalizedAnchorPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedAnchorPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setNormalizedAnchorPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_NormalizedAnchorPoint(*[value internalStruct]));
}

- (RTObject<WSSIRandomAccessStreamReference>*)image {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Image(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Image(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WUXCMMapElementCollisionBehavior)collisionBehaviorDesired {
    ABI::Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CollisionBehaviorDesired(&unmarshalledReturn));
    return (WUXCMMapElementCollisionBehavior)unmarshalledReturn;
}

- (void)setCollisionBehaviorDesired:(WUXCMMapElementCollisionBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CollisionBehaviorDesired((ABI::Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior)value));
}

@end

@implementation WUXCMMapPolygon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapPolygon").Get(), &out));
    return [_createRtProxy<WUXCMMapPolygon>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics> WUXCMIMapPolygonStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapPolygon").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pathProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapPolygonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PathProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapPolygonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeDashedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapPolygonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (void)setPath:(WDGGeopath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Path(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopath>(value).Get()));
}

- (WUColor*)strokeColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setStrokeColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeColor(*[value internalStruct]));
}

- (double)strokeThickness {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeThickness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStrokeThickness:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeThickness(value));
}

- (BOOL)strokeDashed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStrokeDashed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeDashed((boolean)value));
}

- (WUColor*)fillColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setFillColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillColor(*[value internalStruct]));
}

- (NSMutableArray* /* WDGGeopath* */)paths {
    ComPtr<IVector<ABI::Windows::Devices::Geolocation::Geopath*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Paths(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDGGeopath_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapPolyline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapPolyline").Get(), &out));
    return [_createRtProxy<WUXCMMapPolyline>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics> WUXCMIMapPolylineStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapPolyline").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pathProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapPolylineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PathProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeDashedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapPolylineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (void)setPath:(WDGGeopath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_Path(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopath>(value).Get()));
}

- (WUColor*)strokeColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setStrokeColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeColor(*[value internalStruct]));
}

- (double)strokeThickness {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeThickness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStrokeThickness:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeThickness(value));
}

- (BOOL)strokeDashed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStrokeDashed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeDashed((boolean)value));
}

@end

@implementation WUXCMStreetsideExperience

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory> WUXCMIStreetsideExperienceFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.StreetsideExperience").Get(),
                                                       &inst));
    return inst;
}

+ (WUXCMStreetsideExperience*)makeInstanceWithPanorama:(WUXCMStreetsidePanorama*)panorama {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> unmarshalledReturn;
    auto _comInst = WUXCMIStreetsideExperienceFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstanceWithPanorama(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama>(panorama).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMStreetsideExperience>(unmarshalledReturn.Get()) retain];
}

+ (WUXCMStreetsideExperience*)makeInstanceWithPanoramaHeadingPitchAndFieldOfView:(WUXCMStreetsidePanorama*)panorama
                                                                headingInDegrees:(double)headingInDegrees
                                                                  pitchInDegrees:(double)pitchInDegrees
                                                            fieldOfViewInDegrees:(double)fieldOfViewInDegrees {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> unmarshalledReturn;
    auto _comInst = WUXCMIStreetsideExperienceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(
        _getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama>(panorama).Get(),
        headingInDegrees,
        pitchInDegrees,
        fieldOfViewInDegrees,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMStreetsideExperience>(unmarshalledReturn.Get()) retain];
}

- (BOOL)addressTextVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_AddressTextVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAddressTextVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_AddressTextVisible((boolean)value));
}

- (BOOL)cursorVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_CursorVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCursorVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_CursorVisible((boolean)value));
}

- (BOOL)overviewMapVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverviewMapVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setOverviewMapVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_OverviewMapVisible((boolean)value));
}

- (BOOL)streetLabelsVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreetLabelsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStreetLabelsVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreetLabelsVisible((boolean)value));
}

- (BOOL)exitButtonVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitButtonVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setExitButtonVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitButtonVisible((boolean)value));
}

- (BOOL)zoomButtonsVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomButtonsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setZoomButtonsVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZoomButtonsVisible((boolean)value));
}

@end

@implementation WUXCMMapControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControl").Get(), &out));
    return [_createRtProxy<WUXCMMapControl>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics4> WUXCMIMapControlStatics4_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControl").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)businessLandmarksEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_BusinessLandmarksEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)transitFeaturesEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransitFeaturesEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics2> WUXCMIMapControlStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControl").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)businessLandmarksVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_BusinessLandmarksVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)transitFeaturesVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransitFeaturesVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)panInteractionModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PanInteractionModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotateInteractionModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotateInteractionModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)tiltInteractionModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TiltInteractionModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)zoomInteractionModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZoomInteractionModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)is3DSupportedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Is3DSupportedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isStreetsideSupportedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsStreetsideSupportedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)sceneProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SceneProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics> WUXCMIMapControlStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControl").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)childrenProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChildrenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)colorSchemeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorSchemeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)desiredPitchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesiredPitchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)headingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeadingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)landmarksVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LandmarksVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)loadingStatusProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LoadingStatusProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)mapServiceTokenProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MapServiceTokenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pedestrianFeaturesVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PedestrianFeaturesVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pitchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PitchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)styleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)trafficFlowVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TrafficFlowVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)transformOriginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransformOriginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)watermarkModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WatermarkModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)zoomLevelProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevelProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)mapElementsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MapElementsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)routesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RoutesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)tileSourcesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TileSourcesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)locationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WDGGeopoint*)getLocation:(WXDependencyObject*)element {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLocation(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

+ (void)setLocation:(WXDependencyObject*)element value:(WDGGeopoint*)value {
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetLocation(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                             _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(value).Get()));
}

+ (WXDependencyProperty*)normalizedAnchorPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NormalizedAnchorPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WFPoint*)getNormalizedAnchorPoint:(WXDependencyObject*)element {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetNormalizedAnchorPoint(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

+ (void)setNormalizedAnchorPoint:(WXDependencyObject*)element value:(WFPoint*)value {
    auto _comInst = WUXCMIMapControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetNormalizedAnchorPoint(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                          *[value internalStruct]));
}

- (WDGGeopoint*)center {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Center(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (void)setCenter:(WDGGeopoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Center(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(value).Get()));
}

- (NSMutableArray* /* WXDependencyObject* */)children {
    ComPtr<IVector<ABI::Windows::UI::Xaml::DependencyObject*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Children(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXDependencyObject_create(unmarshalledReturn.Get());
}

- (WUXCMMapColorScheme)colorScheme {
    ABI::Windows::UI::Xaml::Controls::Maps::MapColorScheme unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorScheme(&unmarshalledReturn));
    return (WUXCMMapColorScheme)unmarshalledReturn;
}

- (void)setColorScheme:(WUXCMMapColorScheme)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorScheme((ABI::Windows::UI::Xaml::Controls::Maps::MapColorScheme)value));
}

- (double)desiredPitch {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredPitch(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredPitch:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredPitch(value));
}

- (double)heading {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Heading(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeading:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Heading(value));
}

- (BOOL)landmarksVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_LandmarksVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setLandmarksVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_LandmarksVisible((boolean)value));
}

- (WUXCMMapLoadingStatus)loadingStatus {
    ABI::Windows::UI::Xaml::Controls::Maps::MapLoadingStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_LoadingStatus(&unmarshalledReturn));
    return (WUXCMMapLoadingStatus)unmarshalledReturn;
}

- (NSString*)mapServiceToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapServiceToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMapServiceToken:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_MapServiceToken(nsStrToHstr(value).Get()));
}

- (double)maxZoomLevel {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minZoomLevel {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)pedestrianFeaturesVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PedestrianFeaturesVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPedestrianFeaturesVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PedestrianFeaturesVisible((boolean)value));
}

- (double)pitch {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pitch(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCMMapStyle)style {
    ABI::Windows::UI::Xaml::Controls::Maps::MapStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Style(&unmarshalledReturn));
    return (WUXCMMapStyle)unmarshalledReturn;
}

- (void)setStyle:(WUXCMMapStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Style((ABI::Windows::UI::Xaml::Controls::Maps::MapStyle)value));
}

- (BOOL)trafficFlowVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrafficFlowVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTrafficFlowVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrafficFlowVisible((boolean)value));
}

- (WFPoint*)transformOrigin {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransformOrigin(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setTransformOrigin:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransformOrigin(*[value internalStruct]));
}

- (WUXCMMapWatermarkMode)watermarkMode {
    ABI::Windows::UI::Xaml::Controls::Maps::MapWatermarkMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_WatermarkMode(&unmarshalledReturn));
    return (WUXCMMapWatermarkMode)unmarshalledReturn;
}

- (void)setWatermarkMode:(WUXCMMapWatermarkMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_WatermarkMode((ABI::Windows::UI::Xaml::Controls::Maps::MapWatermarkMode)value));
}

- (double)zoomLevel {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setZoomLevel:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZoomLevel(value));
}

- (NSMutableArray* /* WUXCMMapElement* */)mapElements {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapElements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXCMMapElement_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUXCMMapRouteView* */)routes {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapRouteView*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Routes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXCMMapRouteView_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUXCMMapTileSource* */)tileSources {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapTileSource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileSources(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXCMMapTileSource_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCenterChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CenterChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCenterChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CenterChanged(token));
}

- (EventRegistrationToken)addHeadingChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_HeadingChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadingChanged(token));
}

- (EventRegistrationToken)addLoadingStatusChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LoadingStatusChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLoadingStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LoadingStatusChanged(token));
}

- (EventRegistrationToken)addMapDoubleTappedEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapDoubleTapped(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapDoubleTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapDoubleTapped(token));
}

- (EventRegistrationToken)addMapHoldingEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapHolding(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapHoldingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapHolding(token));
}

- (EventRegistrationToken)addMapTappedEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapTapped(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapInputEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapTapped(token));
}

- (EventRegistrationToken)addPitchChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PitchChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePitchChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PitchChanged(token));
}

- (EventRegistrationToken)addTransformOriginChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_TransformOriginChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransformOriginChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TransformOriginChanged(token));
}

- (EventRegistrationToken)addZoomLevelChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ZoomLevelChanged(Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_System_Object>(value).Get(),
                                       &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeZoomLevelChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ZoomLevelChanged(token));
}

- (NSArray* /* WUXCMMapElement* */)findMapElementsAtOffset:(WFPoint*)offset {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->FindMapElementsAtOffset(*[offset internalStruct], unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXCMMapElement_create(unmarshalledReturn.Get());
}

- (void)getLocationFromOffset:(WFPoint*)offset location:(WDGGeopoint**)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> locationOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetLocationFromOffset(*[offset internalStruct], locationOutUnmarshaled.GetAddressOf()));
    *location = _createRtProxy<WDGGeopoint>(locationOutUnmarshaled.Get());
}

- (void)getOffsetFromLocation:(WDGGeopoint*)location offset:(WFPoint**)offset {
    ABI::Windows::Foundation::Point offsetOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetOffsetFromLocation(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                       &offsetOutUnmarshaled));
    *offset = WFPoint_create(offsetOutUnmarshaled);
}

- (void)isLocationInView:(WDGGeopoint*)location isInView:(BOOL*)isInView {
    boolean isInViewOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->IsLocationInView(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(location).Get(),
                                                  &isInViewOutUnmarshaled));
    *isInView = (BOOL)isInViewOutUnmarshaled;
}

- (void)trySetViewBoundsAsync:(WDGGeoboundingBox*)bounds
                       margin:(id /* WXThickness* */)margin
                    animation:(WUXCMMapAnimationKind)animation
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetViewBoundsAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(bounds).Get(),
                                                       BuildNullable<ABI::Windows::UI::Xaml::Thickness>(margin),
                                                       (ABI::Windows::UI::Xaml::Controls::Maps::MapAnimationKind)animation,
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

- (void)trySetViewWithCenterAsync:(WDGGeopoint*)center success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetViewWithCenterAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(center).Get(),
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

- (void)trySetViewWithCenterAndZoomAsync:(WDGGeopoint*)center
                               zoomLevel:(id /* double */)zoomLevel
                                 success:(void (^)(BOOL))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetViewWithCenterAndZoomAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(center).Get(),
                                                   BuildNullable<double>(zoomLevel),
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

- (void)trySetViewWithCenterZoomHeadingAndPitchAsync:(WDGGeopoint*)center
                                           zoomLevel:(id /* double */)zoomLevel
                                             heading:(id /* double */)heading
                                        desiredPitch:(id /* double */)desiredPitch
                                             success:(void (^)(BOOL))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetViewWithCenterZoomHeadingAndPitchAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(center).Get(),
                                                               BuildNullable<double>(zoomLevel),
                                                               BuildNullable<double>(heading),
                                                               BuildNullable<double>(desiredPitch),
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

- (void)trySetViewWithCenterZoomHeadingPitchAndAnimationAsync:(WDGGeopoint*)center
                                                    zoomLevel:(id /* double */)zoomLevel
                                                      heading:(id /* double */)heading
                                                 desiredPitch:(id /* double */)desiredPitch
                                                    animation:(WUXCMMapAnimationKind)animation
                                                      success:(void (^)(BOOL))success
                                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetViewWithCenterZoomHeadingPitchAndAnimationAsync(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(center).Get(),
        BuildNullable<double>(zoomLevel),
        BuildNullable<double>(heading),
        BuildNullable<double>(desiredPitch),
        (ABI::Windows::UI::Xaml::Controls::Maps::MapAnimationKind)animation,
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

- (BOOL)businessLandmarksVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusinessLandmarksVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBusinessLandmarksVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_BusinessLandmarksVisible((boolean)value));
}

- (BOOL)transitFeaturesVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitFeaturesVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTransitFeaturesVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransitFeaturesVisible((boolean)value));
}

- (WUXCMMapPanInteractionMode)panInteractionMode {
    ABI::Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PanInteractionMode(&unmarshalledReturn));
    return (WUXCMMapPanInteractionMode)unmarshalledReturn;
}

- (void)setPanInteractionMode:(WUXCMMapPanInteractionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PanInteractionMode((ABI::Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode)value));
}

- (WUXCMMapInteractionMode)rotateInteractionMode {
    ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotateInteractionMode(&unmarshalledReturn));
    return (WUXCMMapInteractionMode)unmarshalledReturn;
}

- (void)setRotateInteractionMode:(WUXCMMapInteractionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotateInteractionMode((ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode)value));
}

- (WUXCMMapInteractionMode)tiltInteractionMode {
    ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TiltInteractionMode(&unmarshalledReturn));
    return (WUXCMMapInteractionMode)unmarshalledReturn;
}

- (void)setTiltInteractionMode:(WUXCMMapInteractionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TiltInteractionMode((ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode)value));
}

- (WUXCMMapInteractionMode)zoomInteractionMode {
    ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomInteractionMode(&unmarshalledReturn));
    return (WUXCMMapInteractionMode)unmarshalledReturn;
}

- (void)setZoomInteractionMode:(WUXCMMapInteractionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZoomInteractionMode((ABI::Windows::UI::Xaml::Controls::Maps::MapInteractionMode)value));
}

- (BOOL)is3DSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Is3DSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStreetsideSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStreetsideSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXCMMapScene*)scene {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scene(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapScene>(unmarshalledReturn.Get());
}

- (void)setScene:(WUXCMMapScene*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Scene(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(value).Get()));
}

- (WUXCMMapCamera*)actualCamera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualCamera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (WUXCMMapCamera*)targetCamera {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetCamera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCamera>(unmarshalledReturn.Get());
}

- (WUXCMMapCustomExperience*)customExperience {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomExperience(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCMMapCustomExperience>(unmarshalledReturn.Get());
}

- (void)setCustomExperience:(WUXCMMapCustomExperience*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_CustomExperience(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>(value).Get()));
}

- (EventRegistrationToken)addMapElementClickEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementClickEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapElementClick(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementClickEventArgs>(value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapElementClickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapElementClick(token));
}

- (EventRegistrationToken)addMapElementPointerEnteredEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementPointerEnteredEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapElementPointerEntered(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerEnteredEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapElementPointerEnteredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapElementPointerEntered(token));
}

- (EventRegistrationToken)addMapElementPointerExitedEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementPointerExitedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapElementPointerExited(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapElementPointerExitedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapElementPointerExitedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapElementPointerExited(token));
}

- (EventRegistrationToken)addActualCameraChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapActualCameraChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActualCameraChanged(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActualCameraChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActualCameraChanged(token));
}

- (EventRegistrationToken)addActualCameraChangingEvent:(void (^)(WUXCMMapControl*, WUXCMMapActualCameraChangingEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ActualCameraChanging(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapActualCameraChangingEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActualCameraChangingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ActualCameraChanging(token));
}

- (EventRegistrationToken)addTargetCameraChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapTargetCameraChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_TargetCameraChanged(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapTargetCameraChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TargetCameraChanged(token));
}

- (EventRegistrationToken)addCustomExperienceChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapCustomExperienceChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->add_CustomExperienceChanged(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapCustomExperienceChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCustomExperienceChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CustomExperienceChanged(token));
}

- (void)startContinuousRotate:(double)rateInDegreesPerSecond {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StartContinuousRotate(rateInDegreesPerSecond));
}

- (void)stopContinuousRotate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StopContinuousRotate());
}

- (void)startContinuousTilt:(double)rateInDegreesPerSecond {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StartContinuousTilt(rateInDegreesPerSecond));
}

- (void)stopContinuousTilt {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StopContinuousTilt());
}

- (void)startContinuousZoom:(double)rateOfChangePerSecond {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StartContinuousZoom(rateOfChangePerSecond));
}

- (void)stopContinuousZoom {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->StopContinuousZoom());
}

- (void)tryRotateAsync:(double)degrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryRotateAsync(degrees, &unmarshalledReturn));

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

- (void)tryRotateToAsync:(double)angleInDegrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryRotateToAsync(angleInDegrees, &unmarshalledReturn));

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

- (void)tryTiltAsync:(double)degrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryTiltAsync(degrees, &unmarshalledReturn));

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

- (void)tryTiltToAsync:(double)angleInDegrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryTiltToAsync(angleInDegrees, &unmarshalledReturn));

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

- (void)tryZoomInAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryZoomInAsync(&unmarshalledReturn));

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

- (void)tryZoomOutAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryZoomOutAsync(&unmarshalledReturn));

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

- (void)tryZoomToAsync:(double)zoomLevel success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(_comInst->TryZoomToAsync(zoomLevel, &unmarshalledReturn));

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

- (void)trySetSceneAsync:(WUXCMMapScene*)scene success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetSceneAsync(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(scene).Get(), &unmarshalledReturn));

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

- (void)trySetSceneWithAnimationAsync:(WUXCMMapScene*)scene
                        animationKind:(WUXCMMapAnimationKind)animationKind
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetSceneWithAnimationAsync(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapScene>(scene).Get(),
                                                (ABI::Windows::UI::Xaml::Controls::Maps::MapAnimationKind)animationKind,
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

- (EventRegistrationToken)addMapRightTappedEvent:(void (^)(WUXCMMapControl*, WUXCMMapRightTappedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl3>(self);
    THROW_NS_IF_FAILED(_comInst->add_MapRightTapped(
        Make<ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapRightTappedEventArgs>(value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMapRightTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MapRightTapped(token));
}

- (BOOL)businessLandmarksEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusinessLandmarksEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBusinessLandmarksEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4>(self);
    THROW_NS_IF_FAILED(_comInst->put_BusinessLandmarksEnabled((boolean)value));
}

- (BOOL)transitFeaturesEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitFeaturesEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTransitFeaturesEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransitFeaturesEnabled((boolean)value));
}

- (WDGGeopath*)getVisibleRegion:(WUXCMMapVisibleRegionKind)region {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4>(self);
    THROW_NS_IF_FAILED(_comInst->GetVisibleRegion((ABI::Windows::UI::Xaml::Controls::Maps::MapVisibleRegionKind)region,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlBusinessLandmarkClickEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkClickEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlBusinessLandmarkClickEventArgs>(out.Get()) retain];
}

- (NSArray* /* WSMLLocalLocation* */)localLocations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlTransitFeatureClickEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureClickEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlTransitFeatureClickEventArgs>(out.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)transitProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlBusinessLandmarkRightTappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkRightTappedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlBusinessLandmarkRightTappedEventArgs>(out.Get()) retain];
}

- (NSArray* /* WSMLLocalLocation* */)localLocations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlTransitFeatureRightTappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureRightTappedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlTransitFeatureRightTappedEventArgs>(out.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)transitProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerEnteredEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs>(out.Get()) retain];
}

- (NSArray* /* WSMLLocalLocation* */)localLocations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlTransitFeaturePointerEnteredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerEnteredEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlTransitFeaturePointerEnteredEventArgs>(out.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)transitProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlBusinessLandmarkPointerExitedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerExitedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlBusinessLandmarkPointerExitedEventArgs>(out.Get()) retain];
}

- (NSArray* /* WSMLLocalLocation* */)localLocations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlTransitFeaturePointerExitedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerExitedEventArgs").Get(), &out));
    return [_createRtProxy<WUXCMMapControlTransitFeaturePointerExitedEventArgs>(out.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)transitProperties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransitProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WUXCMMapControlDataHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory> WUXCMIMapControlDataHelperFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Maps.MapControlDataHelper").Get(),
                                                       &inst));
    return inst;
}

+ (WUXCMMapControlDataHelper*)makeInstance:(WUXCMMapControl*)map {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper> unmarshalledReturn;
    auto _comInst = WUXCMIMapControlDataHelperFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControl>(map).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXCMMapControlDataHelper>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addBusinessLandmarkClickEvent:(void (^)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkClickEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->add_BusinessLandmarkClick(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkClickEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBusinessLandmarkClickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BusinessLandmarkClick(token));
}

- (EventRegistrationToken)addTransitFeatureClickEvent:(void (^)(WUXCMMapControl*, WUXCMMapControlTransitFeatureClickEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->add_TransitFeatureClick(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureClickEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransitFeatureClickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TransitFeatureClick(token));
}

- (EventRegistrationToken)addBusinessLandmarkRightTappedEvent:(void (^)(WUXCMMapControl*,
                                                                        WUXCMMapControlBusinessLandmarkRightTappedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->add_BusinessLandmarkRightTapped(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkRightTappedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBusinessLandmarkRightTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BusinessLandmarkRightTapped(token));
}

- (EventRegistrationToken)addTransitFeatureRightTappedEvent:(void (^)(WUXCMMapControl*,
                                                                      WUXCMMapControlTransitFeatureRightTappedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->add_TransitFeatureRightTapped(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeatureRightTappedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransitFeatureRightTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TransitFeatureRightTapped(token));
}

- (EventRegistrationToken)addBusinessLandmarkPointerEnteredEvent:(void (^)(WUXCMMapControl*,
                                                                           WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->add_BusinessLandmarkPointerEntered(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerEnteredEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBusinessLandmarkPointerEnteredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BusinessLandmarkPointerEntered(token));
}

- (EventRegistrationToken)addTransitFeaturePointerEnteredEvent:(void (^)(WUXCMMapControl*,
                                                                         WUXCMMapControlTransitFeaturePointerEnteredEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->add_TransitFeaturePointerEntered(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerEnteredEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransitFeaturePointerEnteredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TransitFeaturePointerEntered(token));
}

- (EventRegistrationToken)addBusinessLandmarkPointerExitedEvent:(void (^)(WUXCMMapControl*,
                                                                          WUXCMMapControlBusinessLandmarkPointerExitedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->add_BusinessLandmarkPointerExited(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlBusinessLandmarkPointerExitedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBusinessLandmarkPointerExitedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BusinessLandmarkPointerExited(token));
}

- (EventRegistrationToken)addTransitFeaturePointerExitedEvent:(void (^)(WUXCMMapControl*,
                                                                        WUXCMMapControlTransitFeaturePointerExitedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->add_TransitFeaturePointerExited(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Maps_MapControl_Windows_UI_Xaml_Controls_Maps_MapControlTransitFeaturePointerExitedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransitFeaturePointerExitedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TransitFeaturePointerExited(token));
}

@end

@implementation WUXCMMapZoomLevelRange {
    ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange)s {
    WUXCMMapZoomLevelRange* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange*)internalStruct {
    return &structVal;
}
- (double)min {
    return structVal.Min;
}
- (void)setMin:(double)val {
    structVal.Min = val;
}
- (double)max {
    return structVal.Max;
}
- (void)setMax:(double)val {
    structVal.Max = val;
}
@end
id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
        RTIterableObj<IIterable<ABI::Windows::Foundation::Point>*,
                      IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
                      RTProxiedIterableNSArray,
                      IIterable<ABI::Windows::Foundation::Point>*,
                      RTProxiedIterableNSArray_WFPoint_create,
                      ConvertToIterable<RTProxiedIterableNSArray,
                                        ABI::Windows::Foundation::Internal::AggregateType<IIterable<ABI::Windows::Foundation::Point>*,
                                                                                          IIterable<ABI::Windows::Foundation::Point>*>,
                                        RTProxiedIterableNSArray_WFPoint_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WDGGeopoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::Geolocation::Geopoint*>,
                                                 RTIterableObj<ABI::Windows::Devices::Geolocation::IGeopoint*,
                                                               IIterable<ABI::Windows::Devices::Geolocation::Geopoint*>,
                                                               WDGGeopoint,
                                                               ABI::Windows::Devices::Geolocation::Geopoint*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Point>,
                                                 RTIterableObj<ABI::Windows::Foundation::Point,
                                                               IIterable<ABI::Windows::Foundation::Point>,
                                                               WFPoint,
                                                               ABI::Windows::Foundation::Point,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMLLocalLocation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation*,
                                                    IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>,
                                                    WSMLLocalLocation,
                                                    ABI::Windows::Services::Maps::LocalSearch::LocalLocation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXCMMapElement_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>,
                                                    WUXCMMapElement,
                                                    ABI::Windows::UI::Xaml::Controls::Maps::MapElement*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXIPointer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Input::IPointer*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                                    WUXIPointer,
                                                    ABI::Windows::UI::Xaml::Input::Pointer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDGGeopath_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Geolocation::Geopath*>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Geolocation::IGeopath*,
                                                                  IVector<ABI::Windows::Devices::Geolocation::Geopath*>,
                                                                  WDGGeopath,
                                                                  ABI::Windows::Devices::Geolocation::Geopath*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUXCMMapElement_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Controls::Maps::IMapElement*,
                                                                  IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapElement*>,
                                                                  WUXCMMapElement,
                                                                  ABI::Windows::UI::Xaml::Controls::Maps::MapElement*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUXCMMapRouteView_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapRouteView*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView*,
                                                                  IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapRouteView*>,
                                                                  WUXCMMapRouteView,
                                                                  ABI::Windows::UI::Xaml::Controls::Maps::MapRouteView*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUXCMMapTileSource_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapTileSource*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource*,
                                                                  IVector<ABI::Windows::UI::Xaml::Controls::Maps::MapTileSource*>,
                                                                  WUXCMMapTileSource,
                                                                  ABI::Windows::UI::Xaml::Controls::Maps::MapTileSource*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXDependencyObject_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::DependencyObject*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IDependencyObject*,
                                                                  IVector<ABI::Windows::UI::Xaml::DependencyObject*>,
                                                                  WXDependencyObject,
                                                                  ABI::Windows::UI::Xaml::DependencyObject*,
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
