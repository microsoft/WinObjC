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

// WindowsDevicesGeolocation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Geolocation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsDevicesGeolocation_priv.h"

@implementation WDGIGeoshape

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoshape> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeoshapeType)geoshapeType {
    ABI::Windows::Devices::Geolocation::GeoshapeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeoshapeType(&unmarshalledReturn));
    return (WDGGeoshapeType)unmarshalledReturn;
}

- (unsigned int)spatialReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeReferenceSystem(&unmarshalledReturn));
    return (WDGAltitudeReferenceSystem)unmarshalledReturn;
}

@end

@implementation WDGGeopoint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Geolocation::IGeopointFactory> WDGIGeopointFactory_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopointFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geopoint").Get(), &inst));
    return inst;
}

+ (WDGGeopoint*)make:(WDGBasicGeoposition*)position {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = WDGIGeopointFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[position internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopoint>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeopoint*)makeWithAltitudeReferenceSystem:(WDGBasicGeoposition*)position
                        altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = WDGIGeopointFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReferenceSystem(*[position internalStruct],
                                                    (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeReferenceSystem,
                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopoint>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeopoint*)makeWithAltitudeReferenceSystemAndSpatialReferenceId:(WDGBasicGeoposition*)position
                                             altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                  spatialReferenceId:(unsigned int)spatialReferenceId {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = WDGIGeopointFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*[position internalStruct],
                                                                         (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)
                                                                             altitudeReferenceSystem,
                                                                         spatialReferenceId,
                                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopoint>(unmarshalledReturn.Get()) retain];
}

- (WDGBasicGeoposition*)position {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (WDGGeoshapeType)geoshapeType {
    ABI::Windows::Devices::Geolocation::GeoshapeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeoshapeType(&unmarshalledReturn));
    return (WDGGeoshapeType)unmarshalledReturn;
}

- (unsigned int)spatialReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeReferenceSystem(&unmarshalledReturn));
    return (WDGAltitudeReferenceSystem)unmarshalledReturn;
}

@end

@implementation WDGGeopath

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Geolocation::IGeopathFactory> WDGIGeopathFactory_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopathFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geopath").Get(), &inst));
    return inst;
}

+ (WDGGeopath*)make:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = WDGIGeopathFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopath>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeopath*)makeWithAltitudeReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                 altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = WDGIGeopathFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithAltitudeReference(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeReferenceSystem,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopath>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeopath*)makeWithAltitudeReferenceAndSpatialReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                    altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                         spatialReferenceId:(unsigned int)spatialReferenceId {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = WDGIGeopathFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithAltitudeReferenceAndSpatialReference(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeReferenceSystem,
        spatialReferenceId,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeopath>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* WDGBasicGeoposition* */)positions {
    ComPtr<IVectorView<ABI::Windows::Devices::Geolocation::BasicGeoposition>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeopath>(self);
    THROW_NS_IF_FAILED(_comInst->get_Positions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDGBasicGeoposition_create(unmarshalledReturn.Get());
}

- (WDGGeoshapeType)geoshapeType {
    ABI::Windows::Devices::Geolocation::GeoshapeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeoshapeType(&unmarshalledReturn));
    return (WDGGeoshapeType)unmarshalledReturn;
}

- (unsigned int)spatialReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeReferenceSystem(&unmarshalledReturn));
    return (WDGAltitudeReferenceSystem)unmarshalledReturn;
}

@end

@implementation WDGGeoboundingBox

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxFactory> WDGIGeoboundingBoxFactory_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.GeoboundingBox").Get(), &inst));
    return inst;
}

+ (WDGGeoboundingBox*)make:(WDGBasicGeoposition*)northwestCorner southeastCorner:(WDGBasicGeoposition*)southeastCorner {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(*[northwestCorner internalStruct], *[southeastCorner internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeoboundingBox*)makeWithAltitudeReference:(WDGBasicGeoposition*)northwestCorner
                                southeastCorner:(WDGBasicGeoposition*)southeastCorner
                        altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReference(*[northwestCorner internalStruct],
                                              *[southeastCorner internalStruct],
                                              (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeReferenceSystem,
                                              unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeoboundingBox*)makeWithAltitudeReferenceAndSpatialReference:(WDGBasicGeoposition*)northwestCorner
                                                   southeastCorner:(WDGBasicGeoposition*)southeastCorner
                                           altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                spatialReferenceId:(unsigned int)spatialReferenceId {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReferenceAndSpatialReference(*[northwestCorner internalStruct],
                                                                 *[southeastCorner internalStruct],
                                                                 (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)
                                                                     altitudeReferenceSystem,
                                                                 spatialReferenceId,
                                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxStatics> WDGIGeoboundingBoxStatics_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.GeoboundingBox").Get(), &inst));
    return inst;
}

+ (WDGGeoboundingBox*)tryCompute:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCompute(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

+ (WDGGeoboundingBox*)tryComputeWithAltitudeReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                    altitudeRefSystem:(WDGAltitudeReferenceSystem)altitudeRefSystem {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryComputeWithAltitudeReference(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeRefSystem,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

+ (WDGGeoboundingBox*)tryComputeWithAltitudeReferenceAndSpatialReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                                       altitudeRefSystem:(WDGAltitudeReferenceSystem)altitudeRefSystem
                                                      spatialReferenceId:(unsigned int)spatialReferenceId {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = WDGIGeoboundingBoxStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryComputeWithAltitudeReferenceAndSpatialReference(
        static_cast<IIterable<
            typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Devices::Geolocation::BasicGeoposition>::type>*>(
            ConvertToIterable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>(positions).Get()),
        (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeRefSystem,
        spatialReferenceId,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

- (WDGBasicGeoposition*)northwestCorner {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_NorthwestCorner(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (WDGBasicGeoposition*)southeastCorner {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoutheastCorner(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (WDGBasicGeoposition*)center {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_Center(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (double)minAltitude {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinAltitude(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxAltitude {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoboundingBox>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAltitude(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGGeoshapeType)geoshapeType {
    ABI::Windows::Devices::Geolocation::GeoshapeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeoshapeType(&unmarshalledReturn));
    return (WDGGeoshapeType)unmarshalledReturn;
}

- (unsigned int)spatialReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeReferenceSystem(&unmarshalledReturn));
    return (WDGAltitudeReferenceSystem)unmarshalledReturn;
}

@end

@implementation WDGGeocoordinateSatelliteData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* double */)positionDilutionOfPrecision {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionDilutionOfPrecision(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)horizontalDilutionOfPrecision {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalDilutionOfPrecision(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)verticalDilutionOfPrecision {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalDilutionOfPrecision(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

@end

@implementation WDGVenueData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IVenueData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IVenueData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)level {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IVenueData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Level(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDGGeocoordinate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocoordinate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)latitude {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Latitude(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)longitude {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Longitude(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* double */)altitude {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Altitude(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (double)accuracy {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Accuracy(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* double */)altitudeAccuracy {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeAccuracy(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)heading {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Heading(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)speed {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Speed(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDGPositionSource)positionSource {
    ABI::Windows::Devices::Geolocation::PositionSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateWithPositionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionSource(&unmarshalledReturn));
    return (WDGPositionSource)unmarshalledReturn;
}

- (WDGGeocoordinateSatelliteData*)satelliteData {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateWithPositionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_SatelliteData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeocoordinateSatelliteData>(unmarshalledReturn.Get());
}

- (WDGGeopoint*)point {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateWithPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)positionSourceTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionSourceTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

@end

@implementation WDGCivicAddress

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::ICivicAddress> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)country {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::ICivicAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Country(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)state {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::ICivicAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)city {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::ICivicAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_City(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::ICivicAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::ICivicAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WDGGeoposition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeocoordinate*)coordinate {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocoordinate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Coordinate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeocoordinate>(unmarshalledReturn.Get());
}

- (WDGCivicAddress*)civicAddress {
    ComPtr<ABI::Windows::Devices::Geolocation::ICivicAddress> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoposition>(self);
    THROW_NS_IF_FAILED(_comInst->get_CivicAddress(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGCivicAddress>(unmarshalledReturn.Get());
}

- (WDGVenueData*)venueData {
    ComPtr<ABI::Windows::Devices::Geolocation::IVenueData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoposition2>(self);
    THROW_NS_IF_FAILED(_comInst->get_VenueData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGVenueData>(unmarshalledReturn.Get());
}

@end

@implementation WDGPositionChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IPositionChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeoposition*)position {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IPositionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoposition>(unmarshalledReturn.Get());
}

@end

@implementation WDGStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGPositionStatus)status {
    ABI::Windows::Devices::Geolocation::PositionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDGPositionStatus)unmarshalledReturn;
}

@end

@implementation WDGGeolocator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeolocator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Geolocation.Geolocator").Get(), &out));
    return [_createRtProxy<WDGGeolocator>(out.Get()) retain];
}

ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics2> WDGIGeolocatorStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geolocator").Get(), &inst));
    return inst;
}

+ (BOOL)isDefaultGeopositionRecommended {
    boolean unmarshalledReturn;
    auto _comInst = WDGIGeolocatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDefaultGeopositionRecommended(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setDefaultGeoposition:(id /* WDGBasicGeoposition* */)value {
    auto _comInst = WDGIGeolocatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->put_DefaultGeoposition(BuildNullable<ABI::Windows::Devices::Geolocation::BasicGeoposition>(value)));
}

+ (id /* WDGBasicGeoposition* */)defaultGeoposition {
    ComPtr<IReference<ABI::Windows::Devices::Geolocation::BasicGeoposition>> unmarshalledReturn;
    auto _comInst = WDGIGeolocatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DefaultGeoposition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WDGBasicGeoposition, ABI::Windows::Devices::Geolocation::BasicGeoposition>::convert(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics> WDGIGeolocatorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geolocator").Get(), &inst));
    return inst;
}

+ (void)requestAccessAsyncWithSuccess:(void (^)(WDGGeolocationAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::GeolocationAccessStatus>> unmarshalledReturn;
    auto _comInst = WDGIGeolocatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Geolocation::GeolocationAccessStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::GeolocationAccessStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::Geolocation::GeolocationAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDGGeolocationAccessStatus)result);
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

+ (void)getGeopositionHistoryAsync:(WFDateTime*)startTime
                           success:(void (^)(NSArray* /* WDGGeoposition* */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>> unmarshalledReturn;
    auto _comInst = WDGIGeolocatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetGeopositionHistoryAsync(*[startTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WDGGeoposition_create(result.Get()));
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

+ (void)getGeopositionHistoryWithDurationAsync:(WFDateTime*)startTime
                                      duration:(WFTimeSpan*)duration
                                       success:(void (^)(NSArray* /* WDGGeoposition* */))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>> unmarshalledReturn;
    auto _comInst = WDGIGeolocatorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetGeopositionHistoryWithDurationAsync(*[startTime internalStruct], *[duration internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WDGGeoposition_create(result.Get()));
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

- (WDGPositionAccuracy)desiredAccuracy {
    ABI::Windows::Devices::Geolocation::PositionAccuracy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredAccuracy(&unmarshalledReturn));
    return (WDGPositionAccuracy)unmarshalledReturn;
}

- (void)setDesiredAccuracy:(WDGPositionAccuracy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredAccuracy((ABI::Windows::Devices::Geolocation::PositionAccuracy)value));
}

- (double)movementThreshold {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->get_MovementThreshold(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMovementThreshold:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->put_MovementThreshold(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (WDGPositionStatus)locationStatus {
    ABI::Windows::Devices::Geolocation::PositionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocationStatus(&unmarshalledReturn));
    return (WDGPositionStatus)unmarshalledReturn;
}

- (void)getGeopositionAsyncWithSuccess:(void (^)(WDGGeoposition*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geoposition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->GetGeopositionAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Geolocation::Geoposition*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geoposition*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDGGeoposition>(result.Get()));
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

- (void)getGeopositionAsyncWithAgeAndTimeout:(WFTimeSpan*)maximumAge
                                     timeout:(WFTimeSpan*)timeout
                                     success:(void (^)(WDGGeoposition*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geoposition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetGeopositionAsyncWithAgeAndTimeout(*[maximumAge internalStruct], *[timeout internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Geolocation::Geoposition*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geoposition*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDGGeoposition>(result.Get()));
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

- (EventRegistrationToken)addPositionChangedEvent:(void (^)(WDGGeolocator*, WDGPositionChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->add_PositionChanged(
        Make<ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePositionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PositionChanged(token));
}

- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDGGeolocator*, WDGStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusChanged(
        Make<ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusChanged(token));
}

- (id /* unsigned int */)desiredAccuracyInMeters {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredAccuracyInMeters(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setDesiredAccuracyInMeters:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredAccuracyInMeters(BuildNullable<unsigned int>(value)));
}

- (void)allowFallbackToConsentlessPositions {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeolocator2>(self);
    THROW_NS_IF_FAILED(_comInst->AllowFallbackToConsentlessPositions());
}

@end

@implementation WDGGeocircle

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocircle> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Geolocation::IGeocircleFactory> WDGIGeocircleFactory_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocircleFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geocircle").Get(), &inst));
    return inst;
}

+ (WDGGeocircle*)make:(WDGBasicGeoposition*)position radius:(double)radius {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocircle> unmarshalledReturn;
    auto _comInst = WDGIGeocircleFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[position internalStruct], radius, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeocircle>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeocircle*)makeWithAltitudeReferenceSystem:(WDGBasicGeoposition*)position
                                          radius:(double)radius
                         altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocircle> unmarshalledReturn;
    auto _comInst = WDGIGeocircleFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReferenceSystem(*[position internalStruct],
                                                    radius,
                                                    (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)altitudeReferenceSystem,
                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeocircle>(unmarshalledReturn.Get()) retain];
}

+ (WDGGeocircle*)makeWithAltitudeReferenceSystemAndSpatialReferenceId:(WDGBasicGeoposition*)position
                                                               radius:(double)radius
                                              altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                   spatialReferenceId:(unsigned int)spatialReferenceId {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeocircle> unmarshalledReturn;
    auto _comInst = WDGIGeocircleFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*[position internalStruct],
                                                                         radius,
                                                                         (ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem)
                                                                             altitudeReferenceSystem,
                                                                         spatialReferenceId,
                                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGeocircle>(unmarshalledReturn.Get()) retain];
}

- (WDGBasicGeoposition*)center {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocircle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Center(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (double)radius {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeocircle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Radius(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGGeoshapeType)geoshapeType {
    ABI::Windows::Devices::Geolocation::GeoshapeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeoshapeType(&unmarshalledReturn));
    return (WDGGeoshapeType)unmarshalledReturn;
}

- (unsigned int)spatialReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGAltitudeReferenceSystem)altitudeReferenceSystem {
    ABI::Windows::Devices::Geolocation::AltitudeReferenceSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeReferenceSystem(&unmarshalledReturn));
    return (WDGAltitudeReferenceSystem)unmarshalledReturn;
}

@end

@implementation WDGBasicGeoposition {
    ABI::Windows::Devices::Geolocation::BasicGeoposition structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::Geolocation::BasicGeoposition)s {
    WDGBasicGeoposition* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::Geolocation::BasicGeoposition*)internalStruct {
    return &structVal;
}
- (double)latitude {
    return structVal.Latitude;
}
- (void)setLatitude:(double)val {
    structVal.Latitude = val;
}
- (double)longitude {
    return structVal.Longitude;
}
- (void)setLongitude:(double)val {
    structVal.Longitude = val;
}
- (double)altitude {
    return structVal.Altitude;
}
- (void)setAltitude:(double)val {
    structVal.Altitude = val;
}
@end
id RTProxiedIterableNSArray_WDGBasicGeoposition_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::Geolocation::BasicGeoposition>,
                                                 RTIterableObj<ABI::Windows::Devices::Geolocation::BasicGeoposition,
                                                               IIterable<ABI::Windows::Devices::Geolocation::BasicGeoposition>,
                                                               WDGBasicGeoposition,
                                                               ABI::Windows::Devices::Geolocation::BasicGeoposition,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDGBasicGeoposition_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Geolocation::BasicGeoposition>,
                                         RTArrayObj<ABI::Windows::Devices::Geolocation::BasicGeoposition,
                                                    IVectorView<ABI::Windows::Devices::Geolocation::BasicGeoposition>,
                                                    WDGBasicGeoposition,
                                                    ABI::Windows::Devices::Geolocation::BasicGeoposition,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDGGeoposition_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>,
                                         RTArrayObj<ABI::Windows::Devices::Geolocation::IGeoposition*,
                                                    IVectorView<ABI::Windows::Devices::Geolocation::Geoposition*>,
                                                    WDGGeoposition,
                                                    ABI::Windows::Devices::Geolocation::Geoposition*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
