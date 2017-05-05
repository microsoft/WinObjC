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

#import "Starboard.h"
#import "Foundation/NSString.h"
#import "Foundation/NSUserDefaults.h"
#import "UIKit/UIDevice.h"
#import "UIKit/UIApplication.h"
#import "UIKit/UIViewController.h"
#import "UIKit/UIView.h"
#import "UIViewControllerInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "CppWinRTHelpers.h"
#import <CommonCrypto/CommonDigest.h>

#include "COMIncludes.h"
#import <winrt/Windows.ApplicationModel.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::ApplicationModel;

NSString* const UIDeviceBatteryLevelDidChangeNotification = @"UIDeviceBatteryLevelDidChangeNotification";
NSString* const UIDeviceBatteryStateDidChangeNotification = @"UIDeviceBatteryStateDidChangeNotification";
NSString* const UIDeviceOrientationDidChangeNotification = @"UIDeviceOrientationDidChangeNotification";
NSString* const UIDeviceProximityStateDidChangeNotification = @"UIDeviceProximityStateDidChangeNotification";

static UIDevice* _currentDevice;

bool g_bLandscape = true;
extern UIDeviceOrientation newDeviceOrientation;

@implementation UIDevice
@synthesize systemVersion = _systemVersion;
@synthesize identifierForVendor = _identifierForVendor;

/**
 @Status Interoperable
*/
+ (id)currentDevice {
    if (_currentDevice == nil) {
        _currentDevice = [UIDevice new];

        _currentDevice->_curOrientation = UIDeviceOrientationPortrait;
    }

    return _currentDevice;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    self = [super init];
    if (self) {
        _systemVersion = @"7.0";
        _identifierForVendor = [self _newIdentifierForVendor];
    }
    return self;
}

- (NSUUID*)_newIdentifierForVendor {
    // {CDDDAE31-5BB5-42A7-A8E8-63A3EF6A486C} is the UUID v5 namespace identifier for UUIDs created by WinObjC
    // for publisher IDs.
    //
    // Publisher IDs are generated by following the UUID v5 standard (https://tools.ietf.org/html/rfc4122)
    // INVARIANTS
    // - Namespace = as above
    // - Payload = UTF-16LE publisher name from signing certificate
    // CALCULATIONS
    // - hash = SHA1(Namespace Bytes + Publisher Name)
    // - uuid[0-15] = hash[0-15]
    // - uuid[6] = (uuid[6] & 0xF) | 0x50 -- clear the top 4 bits in the version field and set them to 5.
    // - uuid[8] = (uuid[8] & 0x3F) | 0xC0 -- clear the top 2 bits in the variant field and set them to 2.
    static constexpr GUID sc_wocPublisherNamespace = { 0xcdddae31, 0x5bb5, 0x42a7, { 0xa8, 0xe8, 0x63, 0xa3, 0xef, 0x6a, 0x48, 0x6c } };

    Package currentPackage = Package::Current();
    PackageId packageId = currentPackage.Id();
    winrt::hstring publisher = packageId.Publisher();

    CC_SHA1_CTX sha1Ctx;
    CC_SHA1_Init(&sha1Ctx);

    CC_SHA1_Update(&sha1Ctx, &sc_wocPublisherNamespace, sizeof(GUID));
    CC_SHA1_Update(&sha1Ctx, publisher.c_str(), sizeof(*publisher.c_str()) * publisher.size());

    uint8_t hash[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1_Final(&hash[0], &sha1Ctx);

    hash[6] = (hash[6] & 0xF) | 0x50; // set the uuid version to 5
    hash[8] = (hash[8] & 0x3F) | 0x80; // set the variant to 2 (RFC4122)

    return [[NSUUID alloc] initWithUUIDBytes:hash /* only consumes 16/20 bytes from hash */];
}

/**
 @Status Interoperable
*/
- (void)beginGeneratingDeviceOrientationNotifications {
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
- (void)endGeneratingDeviceOrientationNotifications {
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

- (id)_setOrientation:(UIDeviceOrientation)orientation {
    return [self _setOrientation:orientation animated:TRUE];
}

- (id)_setOrientation:(UIDeviceOrientation)orientation animated:(BOOL)animated {
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
                        [modal _setRotation:orientation animated:animated];
                        didRotate = true;
                    } else {
                        [controller _setRotation:orientation animated:animated];
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
[curView _setRotation:orientation animated:animated];
}
}
#endif
        }
    }

    if (_isGeneratingEvents) {
        [[NSNotificationCenter defaultCenter] postNotificationName:UIDeviceOrientationDidChangeNotification object:self];
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
    if (!DisplayProperties::IsTablet()) {
        return UIUserInterfaceIdiomPhone;
    } else {
        return UIUserInterfaceIdiomPad;
    }
}

/**
 @Status Stub
*/
- (id)model {
    UNIMPLEMENTED();
    if (!DisplayProperties::IsTablet()) {
        return @"iPhone";
    } else {
        return @"iPad";
    }
}

/**
 @Status Interoperable
*/
- (id)name {
    return @"Starboard";
}

- (id)localizedModel {
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
- (id)systemName {
    UNIMPLEMENTED();
    return @"iPhone OS";
}

/**
 @Status Stub
*/
- (id)uniqueIdentifier {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
 @Notes This identifier is based on the package's signing certificat's publisher name. It will
        not change if the application is uninstalled and reinstalled.
        In contravention to the reference platform's documentation, however, removing _every_
        package by a single publisher will _not_ roll this ID.
*/
- (NSUUID*)identifierForVendor {
    return _identifierForVendor;
}

/**
 @Status Stub
*/
- (void)playInputClick {
    UNIMPLEMENTED();
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

- (id)hardware {
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

- (void)_setInitialOrientation {
    [self _setOrientation:UIDeviceOrientationPortrait animated:FALSE];
}

- (id)submitRotation {
    return [self _setOrientation:newDeviceOrientation];
}

@end
