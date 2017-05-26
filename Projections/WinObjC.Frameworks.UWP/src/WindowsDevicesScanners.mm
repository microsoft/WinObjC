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

// WindowsDevicesScanners.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Scanners.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesScanners.h"
#include "WindowsDevicesScanners_priv.h"

@implementation WDSIImageScannerFormatConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSImageScannerFormat)defaultFormat {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFormat(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSImageScannerFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Scanners::ImageScannerFormat)value));
}

- (BOOL)isFormatSupported:(WDSImageScannerFormat)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsFormatSupported((ABI::Windows::Devices::Scanners::ImageScannerFormat)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDSIImageScannerSourceConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFSize*)minScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)maxScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)selectedScanRegion {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedScanRegion(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setSelectedScanRegion:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedScanRegion(*[value internalStruct]));
}

- (WDSImageScannerAutoCroppingMode)autoCroppingMode {
    ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoCroppingMode(&unmarshalledReturn));
    return (WDSImageScannerAutoCroppingMode)unmarshalledReturn;
}

- (void)setAutoCroppingMode:(WDSImageScannerAutoCroppingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoCroppingMode((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value));
}

- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsAutoCroppingModeSupported((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSImageScannerResolution*)minResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)maxResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)opticalResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpticalResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)desiredResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (void)setDesiredResolution:(WDSImageScannerResolution*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredResolution(*[value internalStruct]));
}

- (WDSImageScannerResolution*)actualResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerColorMode)defaultColorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (WDSImageScannerColorMode)colorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (void)setColorMode:(WDSImageScannerColorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorMode((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value));
}

- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsColorModeSupported((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)minBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)brightnessStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_BrightnessStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)brightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Brightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBrightness:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Brightness(value));
}

- (int)minContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)contrastStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContrastStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)contrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setContrast:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Contrast(value));
}

- (WDSImageScannerFormat)defaultFormat {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFormat(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSImageScannerFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Scanners::ImageScannerFormat)value));
}

- (BOOL)isFormatSupported:(WDSImageScannerFormat)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsFormatSupported((ABI::Windows::Devices::Scanners::ImageScannerFormat)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDSImageScannerAutoConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSImageScannerFormat)defaultFormat {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFormat(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSImageScannerFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Scanners::ImageScannerFormat)value));
}

- (BOOL)isFormatSupported:(WDSImageScannerFormat)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsFormatSupported((ABI::Windows::Devices::Scanners::ImageScannerFormat)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDSImageScannerFlatbedConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSImageScannerFormat)defaultFormat {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFormat(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSImageScannerFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Scanners::ImageScannerFormat)value));
}

- (BOOL)isFormatSupported:(WDSImageScannerFormat)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsFormatSupported((ABI::Windows::Devices::Scanners::ImageScannerFormat)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFSize*)minScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)maxScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)selectedScanRegion {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedScanRegion(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setSelectedScanRegion:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedScanRegion(*[value internalStruct]));
}

- (WDSImageScannerAutoCroppingMode)autoCroppingMode {
    ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoCroppingMode(&unmarshalledReturn));
    return (WDSImageScannerAutoCroppingMode)unmarshalledReturn;
}

- (void)setAutoCroppingMode:(WDSImageScannerAutoCroppingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoCroppingMode((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value));
}

- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsAutoCroppingModeSupported((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSImageScannerResolution*)minResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)maxResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)opticalResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpticalResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)desiredResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (void)setDesiredResolution:(WDSImageScannerResolution*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredResolution(*[value internalStruct]));
}

- (WDSImageScannerResolution*)actualResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerColorMode)defaultColorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (WDSImageScannerColorMode)colorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (void)setColorMode:(WDSImageScannerColorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorMode((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value));
}

- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsColorModeSupported((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)minBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)brightnessStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_BrightnessStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)brightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Brightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBrightness:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Brightness(value));
}

- (int)minContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)contrastStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContrastStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)contrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setContrast:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Contrast(value));
}

@end

@implementation WDSImageScannerFeederConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSImageScannerFormat)defaultFormat {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFormat(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSImageScannerFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Scanners::ImageScannerFormat)value));
}

- (BOOL)isFormatSupported:(WDSImageScannerFormat)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsFormatSupported((ABI::Windows::Devices::Scanners::ImageScannerFormat)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFSize*)minScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)maxScanArea {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxScanArea(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)selectedScanRegion {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedScanRegion(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setSelectedScanRegion:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedScanRegion(*[value internalStruct]));
}

- (WDSImageScannerAutoCroppingMode)autoCroppingMode {
    ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoCroppingMode(&unmarshalledReturn));
    return (WDSImageScannerAutoCroppingMode)unmarshalledReturn;
}

- (void)setAutoCroppingMode:(WDSImageScannerAutoCroppingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoCroppingMode((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value));
}

- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsAutoCroppingModeSupported((ABI::Windows::Devices::Scanners::ImageScannerAutoCroppingMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSImageScannerResolution*)minResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)maxResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)opticalResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpticalResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerResolution*)desiredResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (void)setDesiredResolution:(WDSImageScannerResolution*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredResolution(*[value internalStruct]));
}

- (WDSImageScannerResolution*)actualResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualResolution(&unmarshalledReturn));
    return WDSImageScannerResolution_create(unmarshalledReturn);
}

- (WDSImageScannerColorMode)defaultColorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (WDSImageScannerColorMode)colorMode {
    ABI::Windows::Devices::Scanners::ImageScannerColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return (WDSImageScannerColorMode)unmarshalledReturn;
}

- (void)setColorMode:(WDSImageScannerColorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorMode((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value));
}

- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsColorModeSupported((ABI::Windows::Devices::Scanners::ImageScannerColorMode)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)minBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)brightnessStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_BrightnessStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultBrightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultBrightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)brightness {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Brightness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBrightness:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Brightness(value));
}

- (int)minContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)contrastStep {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContrastStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)defaultContrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultContrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)contrast {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contrast(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setContrast:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerSourceConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Contrast(value));
}

- (BOOL)canAutoDetectPageSize {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanAutoDetectPageSize(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)autoDetectPageSize {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoDetectPageSize(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoDetectPageSize:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoDetectPageSize((boolean)value));
}

- (WGPPrintMediaSize)pageSize {
    ABI::Windows::Graphics::Printing::PrintMediaSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageSize(&unmarshalledReturn));
    return (WGPPrintMediaSize)unmarshalledReturn;
}

- (void)setPageSize:(WGPPrintMediaSize)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_PageSize((ABI::Windows::Graphics::Printing::PrintMediaSize)value));
}

- (WGPPrintOrientation)pageOrientation {
    ABI::Windows::Graphics::Printing::PrintOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageOrientation(&unmarshalledReturn));
    return (WGPPrintOrientation)unmarshalledReturn;
}

- (void)setPageOrientation:(WGPPrintOrientation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_PageOrientation((ABI::Windows::Graphics::Printing::PrintOrientation)value));
}

- (WFSize*)pageSizeDimensions {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageSizeDimensions(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (BOOL)isPageSizeSupported:(WGPPrintMediaSize)pageSize pageOrientation:(WGPPrintOrientation)pageOrientation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->IsPageSizeSupported((ABI::Windows::Graphics::Printing::PrintMediaSize)pageSize,
                                                     (ABI::Windows::Graphics::Printing::PrintOrientation)pageOrientation,
                                                     &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)maxNumberOfPages {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxNumberOfPages(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxNumberOfPages:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxNumberOfPages(value));
}

- (BOOL)canScanDuplex {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanScanDuplex(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)duplex {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duplex(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDuplex:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duplex((boolean)value));
}

- (BOOL)canScanAhead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanScanAhead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)scanAhead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanAhead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setScanAhead:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerFeederConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScanAhead((boolean)value));
}

@end

@implementation WDSImageScannerScanResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerScanResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSStorageFile* */)scannedFiles {
    ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerScanResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScannedFiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSStorageFile_create(unmarshalledReturn.Get());
}

@end

@implementation WDSImageScannerPreviewResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerPreviewResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)succeeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerPreviewResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Succeeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSImageScannerFormat)format {
    ABI::Windows::Devices::Scanners::ImageScannerFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScannerPreviewResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSImageScannerFormat)unmarshalledReturn;
}

@end

@implementation WDSImageScanner

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScanner> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Scanners::IImageScannerStatics> WDSIImageScannerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Scanners.ImageScanner").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSImageScanner*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Scanners::ImageScanner*>> unmarshalledReturn;
    auto _comInst = WDSIImageScannerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Scanners::ImageScanner*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Scanners::ImageScanner*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Scanners::IImageScanner> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSImageScanner>(result.Get()));
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

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSIImageScannerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSImageScannerScanSource)defaultScanSource {
    ABI::Windows::Devices::Scanners::ImageScannerScanSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultScanSource(&unmarshalledReturn));
    return (WDSImageScannerScanSource)unmarshalledReturn;
}

- (BOOL)isScanSourceSupported:(WDSImageScannerScanSource)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsScanSourceSupported((ABI::Windows::Devices::Scanners::ImageScannerScanSource)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSImageScannerFlatbedConfiguration*)flatbedConfiguration {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlatbedConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSImageScannerFlatbedConfiguration>(unmarshalledReturn.Get());
}

- (WDSImageScannerFeederConfiguration*)feederConfiguration {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_FeederConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSImageScannerFeederConfiguration>(unmarshalledReturn.Get());
}

- (WDSImageScannerAutoConfiguration*)autoConfiguration {
    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerFormatConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoConfiguration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSImageScannerAutoConfiguration>(unmarshalledReturn.Get());
}

- (BOOL)isPreviewSupported:(WDSImageScannerScanSource)scanSource {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsPreviewSupported((ABI::Windows::Devices::Scanners::ImageScannerScanSource)scanSource, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)scanPreviewToStreamAsync:(WDSImageScannerScanSource)scanSource
                    targetStream:(RTObject<WSSIRandomAccessStream>*)targetStream
                         success:(void (^)(WDSImageScannerPreviewResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Scanners::ImageScannerPreviewResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->ScanPreviewToStreamAsync((ABI::Windows::Devices::Scanners::ImageScannerScanSource)scanSource,
                                           _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(targetStream).Get(),
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Scanners::ImageScannerPreviewResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Scanners::ImageScannerPreviewResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Scanners::IImageScannerPreviewResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSImageScannerPreviewResult>(result.Get()));
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

- (void)scanFilesToFolderAsync:(WDSImageScannerScanSource)scanSource
                 storageFolder:(WSStorageFolder*)storageFolder
                       success:(void (^)(WDSImageScannerScanResult*))success
                      progress:(void (^)(unsigned int))progress
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Devices::Scanners::ImageScannerScanResult*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Scanners::IImageScanner>(self);
    THROW_NS_IF_FAILED(_comInst->ScanFilesToFolderAsync((ABI::Windows::Devices::Scanners::ImageScannerScanSource)scanSource,
                                                        _getRtInterface<ABI::Windows::Storage::IStorageFolder>(storageFolder).Get(),
                                                        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Devices::Scanners::ImageScannerScanResult*,
                                                                     unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Devices::Scanners::ImageScannerScanResult*,
                                                                               unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Devices::Scanners::ImageScannerScanResult*,
                                                                              unsigned int>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Devices::Scanners::ImageScannerScanResult*, unsigned int>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Scanners::IImageScannerScanResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSImageScannerScanResult>(result.Get()));
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

@implementation WDSImageScannerResolution {
    ABI::Windows::Devices::Scanners::ImageScannerResolution structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::Scanners::ImageScannerResolution)s {
    WDSImageScannerResolution* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::Scanners::ImageScannerResolution*)internalStruct {
    return &structVal;
}
- (float)dpiX {
    return structVal.DpiX;
}
- (void)setDpiX:(float)val {
    structVal.DpiX = val;
}
- (float)dpiY {
    return structVal.DpiY;
}
- (void)setDpiY:(float)val {
    structVal.DpiY = val;
}
@end
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageFile*,
                                                                                        IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                                        WSStorageFile,
                                                                                        ABI::Windows::Storage::StorageFile*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
