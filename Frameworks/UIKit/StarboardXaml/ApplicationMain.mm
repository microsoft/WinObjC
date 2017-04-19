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

#import <UIKit/UIWindow.h>

#include <COMIncludes.h>
#import "ApplicationMain.h"
#import <winrt/Windows.Storage.h>
#import <winrt/Windows.ApplicationModel.Activation.h>
#import <winrt/Windows.UI.Xaml.h>
#include <COMIncludes_End.h>

#import <assert.h>
#import <math.h>
#import <malloc.h>
#import <string>

#import <vector>
#import <algorithm>

#import <d3d11.h>
#import <d3d11_2.h>

#import <Starboard.h>
#import <StringHelpers.h>
#import <CollectionHelpers.h>
#import <UIInterface.h>
#import <UIApplicationInternal.h>
#import <MainDispatcher.h>
#import <_UIPopupViewController.h>
#import "CppWinRTHelpers.h"

using namespace Microsoft::WRL;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::ApplicationModel::Activation;
namespace WF = winrt::Windows::Foundation;
namespace WFC = winrt::Windows::Foundation::Collections;

void _SetTemporaryFolder(const wchar_t* folder) {
    NSSetTemporaryDirectory([NSString stringWithCharacters:reinterpret_cast<const unichar*>(folder) length:wcslen(folder)]);
}

void _InitializeApp() {
    // Only init once.
    // No lock needed as this is only called from the UI thread.
    static bool initialized = false;
    if (initialized) {
        return;
    }
    initialized = true;

    // Set our writable and temp folders
    IwSetWritableFolder(winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().data());
    _SetTemporaryFolder(winrt::Windows::Storage::ApplicationData::Current().TemporaryFolder().Path().data());

    // Set the waiter routine for the main runloop to yield
    SetupMainRunLoopTimedMultipleWaiter();
}

void RunApplicationMain(const char* principalName, const char* delegateName, ActivationType activationType, IInspectable* activationArg) {
    // Perform initialization
    _InitializeApp();

    // Note: We must use nil rather than an empty string for these class names
    NSString* principalClassName = Strings::IsEmpty<const char*>(principalName) ? nil : [[NSString alloc] initWithCString:principalName];
    NSString* delegateClassName = Strings::IsEmpty<const char*>(delegateName) ? nil : [[NSString alloc] initWithCString:delegateName];

    id activationArgument = nil;

    // Populate Objective C equivalent of activation argument
    switch (activationType) {
        case ActivationTypeToast: {
            auto toastArgument = objcwinrt::from_insp<ToastNotificationActivatedEventArgs>(activationArg);

            // Convert to NSDictionary with NSStrings
            WFC::IPropertySet map = toastArgument.UserInput();
            auto mapAbi = reinterpret_cast<ABI::Windows::Foundation::Collections::IPropertySet*>(winrt::get_abi(map));

            NSMutableDictionary* userInput = nil;
            THROW_NS_IF_FAILED(::Collections::WRLToNSCollection(mapAbi, &userInput));

            NSDictionary* toastAction = @{
                UIApplicationLaunchOptionsToastActionArgumentKey:objcwinrt::string(toastArgument.Argument()),
                UIApplicationLaunchOptionsToastActionUserInputKey:userInput
            };
            activationArgument = toastAction;
            break;
        }
        case ActivationTypeProtocol:
            activationArgument = _createProjectionObject("WFUri", activationArg, "protocol activation");
            break;

        case ActivationTypeVoiceCommand:
            activationArgument = _createProjectionObject("WMSSpeechRecognitionResult", activationArg, "voice commands");
            break;

        case ActivationTypeFile:
            activationArgument = _createProjectionObject("WAAFileActivatedEventArgs", activationArg, "file activation");
            break;

        default:
            break;
    }

    // Grab window dimensions from CPP/WinRT and initialize our display accordingly
    auto windowBounds = Window::Current().Bounds();
    WOCDisplayMode* displayMode = [UIApplication displayMode];
    [displayMode _setWindowSize:CGSizeMake(windowBounds.Width, windowBounds.Height)];

    if (activationType == ActivationTypeLibrary) {
        // In library mode, honor app's native display size
        [displayMode setDisplayPreset:WOCDisplayPresetNative];
    }

    //  Figure out what our initial default orientation should be from Info.plist
    // TODO: #2438 UIApplication/UIWindow/UIScreen/UIDevice orientation/rotation needs some work
    UIInterfaceOrientation defaultOrientation = UIInterfaceOrientationUnknown;
    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];
    if (infoDict != nil) {
        defaultOrientation = EbrGetWantedOrientation();

        id orientation = [infoDict objectForKey:@"UISupportedInterfaceOrientations"];

        if (orientation == nil) {
            orientation = [infoDict objectForKey:@"UIInterfaceOrientation"];
        }

        if ([orientation isKindOfClass:[NSString class]]) {
            defaultOrientation = UIOrientationFromString(defaultOrientation, (NSString*)orientation);
        } else if ([orientation isKindOfClass:[NSArray class]]) {
            bool found = false;

            for (NSString* curstr in orientation) {
                UIInterfaceOrientation newOrientation = UIOrientationFromString(defaultOrientation, curstr);
                if (newOrientation == defaultOrientation) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                if ([(NSArray*)orientation count] > 0) {
                    defaultOrientation = UIOrientationFromString(defaultOrientation, [(NSArray*)orientation objectAtIndex:0]);
                } else {
                    defaultOrientation = UIInterfaceOrientationPortrait;
                }
            }
        } else {
            defaultOrientation = UIInterfaceOrientationPortrait;
        }
    }

//  Setup default landscape presentation transform on desktop only,
//  based on the declared default application orientations
#if WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP
    if (defaultOrientation == UIInterfaceOrientationLandscapeLeft || defaultOrientation == UIInterfaceOrientationLandscapeRight) {
        displayMode.presentationTransform = defaultOrientation;
    }
#endif

    if ([UIApplication respondsToSelector:@selector(setStartupDisplayMode:)]) {
        [UIApplication setStartupDisplayMode:displayMode];
    }

    [displayMode _updateDisplaySettings];

    _UIApplicationMainInit(principalClassName, delegateClassName, (int)activationType, activationArgument);

    if (activationType == ActivationTypeLibrary) {
        // Create a top-level UIWindow with popup view controller, which will not normally be visible.
        // If some other view controller tries to present to it, the popup view controller will make
        // the desired UI visible inside a XAML Popup.
        WF::Rect appFrame = Window::Current().Bounds();
        CGRect windowFrame = CGRectMake(0, 0, appFrame.Width, appFrame.Height);

        UIWindow* keyWindow = [[UIWindow alloc] initWithFrame:windowFrame];
        keyWindow.rootViewController = [[_UIPopupViewController alloc] init];
        [keyWindow makeKeyWindow];
    }

    // The main runloop has to be started asynchronously, so we return as soon as possible from application activate.
    // The apps can (and do) handle application launch delegate from the first tine NSRunloop run is called, and that can
    // take a REALLY long time to complete, causing PLM to terminate us.  We were getting lucky in some cases and the app would launch.
    // This will also fix the number of sporadic launch test failures that we have seen in the labs.
    ScheduleMainRunLoopAsync();
}
