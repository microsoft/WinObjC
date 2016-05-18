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
#import "UWP/WindowsApplicationModel.h"
#import "UIViewControllerInternal.h"
#import "CACompositor.h"

NSString* const UIDeviceBatteryLevelDidChangeNotification = @"UIDeviceBatteryLevelDidChangeNotification";
NSString* const UIDeviceBatteryStateDidChangeNotification = @"UIDeviceBatteryStateDidChangeNotification";
NSString* const UIDeviceOrientationDidChangeNotification = @"UIDeviceOrientationDidChangeNotification";
NSString* const UIDeviceProximityStateDidChangeNotification = @"UIDeviceProximityStateDidChangeNotification";

static UIDevice* _currentDevice;

bool g_bLandscape = true;
extern UIDeviceOrientation newDeviceOrientation;

DWORD uuid_unparse(BYTE* uuid, char* out);
DWORD uuid_generate(BYTE* uuid);

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
    WAPackage* currentPackage = [WAPackage current];
    WAPackageId* packageid = currentPackage.id;
    NSString* famName = packageid.familyName;
    return [[NSUUID alloc] initWithUUIDString:famName];
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
    if (!GetCACompositor()->isTablet()) {
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
    if (!GetCACompositor()->isTablet()) {
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
 @Status Caveat
 @Notes Returns the FamilyName from the package utilizing a WinRT api.
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
