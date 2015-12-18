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

#include "Starboard.h"

#include "Foundation/NSString.h"
#include "Foundation/NSUserDefaults.h"
#include "UIKit/UIDevice.h"
#include "UIKit/UIApplication.h"
#include "UIKit/UIViewController.h"
#include "UIKit/UIView.h"
using WCHAR = wchar_t;
#include "UWP/WindowsApplicationModel.h"
#include "MurmurHash3.h"

static UIDevice* _currentDevice;

bool g_bLandscape = true;
extern UIDeviceOrientation newDeviceOrientation;

DWORD uuid_unparse(BYTE* uuid, char* out);
DWORD uuid_generate(BYTE* uuid);

@implementation UIDevice : NSObject
@synthesize systemVersion = _systemVersion;
@synthesize identifierForVendor = _identifierForVendor;

/**
 @Status Interoperable
*/
+ (id) /* use typed version */ currentDevice {
    if (_currentDevice == nil) {
        _currentDevice = [UIDevice new];

        _currentDevice->_curOrientation = UIDeviceOrientationPortrait;
    }

    return _currentDevice;
}

- (id)init {
    self = [super init];
    if (self) {
        _systemVersion = @"7.0";
        _identifierForVendor = [self _newIdentifierForVendor];
    }
    return self;
}

- (NSUUID*)_newIdentifierForVendor {
    WAPackage* currentPackage = [WAPackage current];
    WAPackageId* packageid = currentPackage.id;
    NSString* famName = packageid.familyName;
    return [[NSUUID alloc] initWithUUIDString:famName];
}

/**
 @Status Interoperable
*/
- (void) /* use typed version */ beginGeneratingDeviceOrientationNotifications {
    _isGeneratingEvents++;
}

/**
 @Status Interoperable
*/
- (BOOL)isGeneratingDeviceOrientationNotifications {
    return _isGeneratingEvents > 0;
}

/**
 @Status Interoperable
*/
- (void) /* use typed version */ endGeneratingDeviceOrientationNotifications {
    _isGeneratingEvents--;
}

/**
 @Status Stub
*/
- (void)setBatteryMonitoringEnabled:(BOOL)enable {
    UNIMPLEMENTED();
    _batteryMonitoringEnabled = enable != 0;
}

/**
 @Status Stub
*/
- (BOOL)isBatteryMonitoringEnabled {
    UNIMPLEMENTED();
    return _batteryMonitoringEnabled;
}

- (id)setProximityMonitoringEnabled:(DWORD)enable {
    return self;
}

- (id)setOrientation:(UIDeviceOrientation)orientation {
    return [self setOrientation:orientation animated:TRUE];
}

- (id)setOrientation:(UIDeviceOrientation)orientation animated:(BOOL)animated {
    _curOrientation = orientation;

    if (_curOrientation != UIDeviceOrientationUnknown) {
        //[[UIApplication sharedApplication] setStatusBarOrientation:orientation];
        id windows = [[UIApplication sharedApplication] windows];
        int windowCount = [windows count];

        for (int i = 0; i < windowCount; i++) {
            id curWindow = [windows objectAtIndex:i];

            id subviews = [curWindow subviews];
            int subviewCount = [subviews count];

            for (int j = subviewCount - 1; j >= 0; j--) {
                if ((unsigned int)j >= [subviews count]) {
                    continue;
                }
                bool didRotate = false;

                id curView = [subviews objectAtIndex:j];

                id controller = [UIViewController controllerForView:curView];

                if (controller != nil) {
                    id modal = [controller modalViewController];

                    if (modal != nil) {
                        [modal setRotation:orientation animated:animated];
                        didRotate = true;
                    } else {
                        [controller setRotation:orientation animated:animated];
                    }
                }
                if (didRotate) {
                    break;
                }
            }

#if 0
id popoverClass = [__UIPopoverView class];

for ( int j = subviewCount - 1; j >= 0; j -- ) {
if ( (unsigned int)j >= [subviews count] ) continue;
id curView = [subviews objectAtIndex:j];

if ( [curView isKindOfClass:popoverClass] ) {
[curView setRotation:orientation animated:animated];
}
}
#endif
        }
    }

    if (_isGeneratingEvents) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIDeviceOrientationDidChangeNotification" object:self];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (UIDeviceOrientation)orientation {
    if (_isGeneratingEvents) {
        return _curOrientation;
    } else {
        return UIDeviceOrientationUnknown;
    }
}

/**
 @Status Interoperable
*/
- (UIUserInterfaceIdiom)userInterfaceIdiom {
    if (!GetCACompositor()->isTablet()) {
        return UIUserInterfaceIdiomPhone;
    } else {
        return UIUserInterfaceIdiomPad;
    }
}

/**
 @Status Stub
*/
- (id) /* use typed version */ model {
    UNIMPLEMENTED();
#ifdef REPORT_STARBOARD_METRICS
    static id ret;
    if (ret == nil) {
        char combinedName[256];
        sprintf_s(combinedName, sizeof(combinedName), "%s %s", EbrGetDeviceInfo()->manufacturer, EbrGetDeviceInfo()->model);
        ret = EbrBuildCFConstantString(combinedName);
    }
    return ret;
#else
    if (!GetCACompositor()->isTablet()) {
        return @"iPhone";
    } else {
        return @"iPad";
    }
#endif
}

/**
 @Status Interoperable
*/
- (id) /* use typed version */ name {
    return @"Starboard";
}

- (id) /* use typed version */ localizedModel {
    return [self model];
}

/**
 @Status Caveat
 @Notes We allow this value to be editted so the developer can get the value back that they expect on the Windows Platform.
 Currently it returns '7.0' by default.
*/
- (NSString*)systemVersion {
    return _systemVersion;
}

/**
 @Status Caveat
 @Notes We allow this value to be editted so the developer can get the value back that they expect on the Windows Platform.
  Currently it returns '7.0' by default.
*/
- (void)setSystemVersion:(NSString*)version {
    _systemVersion = [version retain];
}

/**
 @Status Stub
*/
- (id) /* use typed version */ systemName {
    UNIMPLEMENTED();
#ifdef REPORT_STARBOARD_METRICS
    static id ret;
    if (ret == nil)
        ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->platformName);
    return ret;
#else
    return @"iPhone OS";
#endif
}

/**
 @Status Stub
*/
- (id) /* use typed version */ uniqueIdentifier {
    UNIMPLEMENTED();
#if 0
static id ret = nil;
if (ret == nil) {
id uniqueIdData = [UIDevice sbExt_DeviceUniqueId];
if (uniqueIdData == nil) {  //  Permission denied error - needs ID_CAP_IDENTITY_DEVICE
ret = LocalUIDForName(@"__Starboard_ID");
}
else {
char *bytes = (char *)[uniqueIdData bytes];
int len = (int)[uniqueIdData length];

MD5_CTX ctx;

MD5Init(&ctx);
MD5Update(&ctx, (unsigned char *)bytes, len);
MD5Final(&ctx);

char szUUID[64];
uuid_unparse((BYTE *)ctx.digest, szUUID);

ret = EbrBuildCFConstantString(szUUID);
}
}

return ret;
#else
    return nil;
#endif
}

/**
 @Status Caveat
 @Notes Returns the FamilyName from the package utilizing a WinRT api.
*/
- (NSUUID*)identifierForVendor {
    return _identifierForVendor;
}

/**
 @Status Stub
*/
- (float)screenPhysicalWidth {
    UNIMPLEMENTED();
    return EbrGetDeviceInfo()->devicePhysWidth;
}

/**
 @Status Stub
*/
- (float)screenPhysicalHeight {
    UNIMPLEMENTED();
    return EbrGetDeviceInfo()->devicePhysHeight;
}

- (id)playInputClick {
    return self;
}

/**
 @Status Stub
*/
- (float)batteryLevel {
    UNIMPLEMENTED();
    return 1.f;
}

/**
 @Status Stub
*/
- (UIDeviceBatteryState)batteryState {
    UNIMPLEMENTED();
    return UIDeviceBatteryStateFull;
}

- (id) /* use typed version */ hardware {
    return @"Starboard";
}

/**
 @Status Stub
 @Notes Always returns YES
*/
- (BOOL)isMultitaskingSupported {
    UNIMPLEMENTED();
    return TRUE;
}

- (BOOL)isProximityMonitoringEnabled {
    return FALSE;
}

- (id) /* use typed version */ _setInitialOrientation {
    UIDeviceOrientation def = UIDeviceOrientationPortrait;
#if 0
def = (UIDeviceOrientation) EbrGetWantedOrientation();
#endif

    return [self setOrientation:def animated:FALSE];
}

- (id) /* use typed version */ submitRotation {
    return [self setOrientation:newDeviceOrientation];
}

#if 0
static id LocalUIDForName(id name)
{
id userDefaults = [NSUserDefaults standardUserDefaults];
id obj = [userDefaults objectForKey:name];
if ( obj == nil ) {
BYTE uuid[32];
char szUUID[64];
uuid_generate(uuid);
uuid_unparse(uuid, szUUID);

obj = EbrBuildCFConstantString(szUUID);
[userDefaults setObject:obj forKey:name];
}

return obj;
}

-(id) nativePlatformName {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->platformName);
return ret;
}

-(id) nativeManufacturer {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->manufacturer);
return ret;
}

-(id) nativeModel {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->model);
return ret;
}

-(id) nativeProductName {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->deviceProductName);
return ret;
}

-(id) nativeSerialNo {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->serialNo);
return ret;
}

-(id) nativeCarrier {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->carrier);
return ret;
}

-(id) nativeOSVersion {
static id ret;
if ( ret == nil ) ret = EbrBuildCFConstantString(EbrGetDeviceInfo()->osVersion);
return ret;
}

-(id) nativeResolutionWidth {
return EbrGetDeviceInfo()->deviceResX;
}

-(id) nativeResolutionHeight {
return EbrGetDeviceInfo()->deviceResY;
}

#endif

@end
