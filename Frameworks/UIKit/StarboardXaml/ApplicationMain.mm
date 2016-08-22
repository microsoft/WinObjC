//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include <COMIncludes.h>
#import "ApplicationMain.h"
#import <windows.foundation.h>
#import <windows.applicationmodel.activation.h>
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
#import <CACompositorClient.h>
#import <UIApplicationInternal.h>
#import <MainDispatcher.h>
#import <UWP/WindowsApplicationModelActivation.h>

using namespace Microsoft::WRL;

static CACompositorClientInterface* _compositorClient = NULL;

void SetCACompositorClient(CACompositorClientInterface* client) {
    _compositorClient = client;
}

int ApplicationMainStart(const char* principalName,
                         const char* delegateName,
                         float windowWidth,
                         float windowHeight,
                         ActivationType activationType,
                         IInspectable* activationArg) {
    // Note: We must use nil rather than an empty string for these class names
    NSString* principalClassName = Strings::IsEmpty<const char*>(principalName) ? nil : [[NSString alloc] initWithCString:principalName];
    NSString* delegateClassName = Strings::IsEmpty<const char*>(delegateName) ? nil : [[NSString alloc] initWithCString:delegateName];

    id activationArgument = nil;

    // Populate Objective C equivalent of activation argument
    if (activationType == ActivationTypeToast) {
        WAAToastNotificationActivatedEventArgs* toastArgument = [WAAToastNotificationActivatedEventArgs createWith:activationArg];

        // Convert to NSDictionary with NSStrings
        ComPtr<IInspectable> comPtr = activationArg;
        ComPtr<ABI::Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs> args;
        THROW_NS_IF_FAILED(comPtr.As(&args));

        ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> map;
        THROW_NS_IF_FAILED(args->get_UserInput(&map));

        NSMutableDictionary* userInput = nil;
        THROW_NS_IF_FAILED(Collections::WRLToNSCollection(map, &userInput));

        NSDictionary* toastAction = @{
            UIApplicationLaunchOptionsToastActionArgumentKey : toastArgument.argument,
            UIApplicationLaunchOptionsToastActionUserInputKey : userInput
        };
        activationArgument = toastAction;
    } else if (activationType == ActivationTypeVoiceCommand) {
        WMSSpeechRecognitionResult* result = [WMSSpeechRecognitionResult createWith:activationArg];
        activationArgument = result;
    } else if (activationType == ActivationTypeProtocol) {
        WFUri* uri = [WFUri createWith:activationArg];
        activationArgument = uri;
    }

    WOCDisplayMode* displayMode = [UIApplication displayMode];
    [displayMode _setWindowSize:CGSizeMake(windowWidth, windowHeight)];

    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];

    //  Figure out what our initial default orientation should be from Info.plist
    UIInterfaceOrientation defaultOrientation = UIInterfaceOrientationUnknown;
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

    UIApplicationMainInit(principalClassName, delegateClassName, defaultOrientation, (int)activationType, activationArgument);
    ScheduleMainRunLoop();

    return 0;
}

void SetTemporaryFolder(const char* folder) {
    NSSetTemporaryDirectory([NSString stringWithCString:folder]);
}
