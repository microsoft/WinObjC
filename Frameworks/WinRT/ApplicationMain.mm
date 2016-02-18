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

#include "ApplicationMain.h"

#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <string>

#include <vector>
#include <algorithm>

#include <d3d11.h>
#include <d3d11_2.h>

#include "Starboard.h"
#include "UIInterface.h"
#include "CACompositorClient.h"
#include "UIApplicationInternal.h"
#include "winobjc\winobjc.h"

static CACompositorClientInterface* _compositorClient = NULL;

void SetCACompositorClient(CACompositorClientInterface* client) {
    _compositorClient = client;
}

struct ApplicationProperties {
    float width;
    float height;
    float scale;
    std::string name;
    bool isTablet;
    bool isLandscape;
};

ApplicationProperties g_applicationProperties;

std::string GetAppNameFromPList() {
    NSString* appName = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"];
    if (appName != nil) {
        return [appName UTF8String];
    }

    return "Starboard";
}

int ApplicationMainStart(
    int argc, char* argv[], const char* principalName, const char* delegateName, float windowWidth, float windowHeight) {

    // Note: We must use nil rather than an empty string for these class names
    NSString* principalClassName = 
        (principalName && *principalName != '\0') ? [[NSString alloc] initWithCString:principalName] : nil;
    NSString* delegateClassName = 
        (delegateName && *delegateName != '\0') ? [[NSString alloc] initWithCString:delegateName] : nil;

    WOCDisplayMode* displayMode = [UIApplication displayMode];
    [displayMode _setWindowSize:CGSizeMake(windowWidth, windowHeight)];

    float defaultWidth = GetCACompositor()->screenWidth();
    float defaultHeight = GetCACompositor()->screenHeight();
    float defaultScale = GetCACompositor()->screenScale();
    bool defaultTablet = false;

    [NSBundle setMainBundlePath:@"."];

    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];

    //  Figure out what our initial default orientation should be from Info.plist
    UIInterfaceOrientation defaultOrientation = UIInterfaceOrientationUnknown;
    if (infoDict != nil) {
        defaultOrientation = EbrGetWantedOrientation();

        NSObject* orientation;
        orientation = [infoDict objectForKey:@"UISupportedInterfaceOrientations"];
        if (orientation == nil)
            orientation = [infoDict objectForKey:@"UIInterfaceOrientation"];

        if ([orientation isKindOfClass:[NSString class]]) {
            defaultOrientation = UIOrientationFromString(defaultOrientation, orientation);
        } else if ([orientation isKindOfClass:[NSArray class]]) {
            bool found = false;

            for (NSString* curstr in(NSArray*)orientation) {
                UIInterfaceOrientation newOrientation = UIOrientationFromString(defaultOrientation, curstr);
                if (newOrientation == defaultOrientation) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                if ([orientation count] > 0) {
                    defaultOrientation = UIOrientationFromString(defaultOrientation, [orientation objectAtIndex:0]);
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

    g_applicationProperties.width = defaultWidth;
    g_applicationProperties.height = defaultHeight;
    g_applicationProperties.scale = defaultScale;
    g_applicationProperties.name = GetAppNameFromPList();
    g_applicationProperties.isTablet = defaultTablet;

    [displayMode _updateDisplaySettings];
    GetCACompositor()->setTablet(g_applicationProperties.isTablet);

    UIApplicationMainInit(argc, argv, principalClassName, delegateClassName, defaultOrientation);
    return UIApplicationMainLoop();
}

void IWSetTemporaryFolder(const char* folder) {
    NSSetTemporaryDirectory([NSString stringWithCString:folder]);
}
