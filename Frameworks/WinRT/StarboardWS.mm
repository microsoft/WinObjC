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

#include <math.h>
#include <malloc.h>
#include <assert.h>

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

__declspec(dllexport) void SetCACompositorClient(CACompositorClientInterface* client) {
    _compositorClient = client;
}

struct ApplicationProperties {
public:
    float appWidth, appHeight, appScale;
    const char* appName;
    bool isTablet;
    bool bLandscape;
};

ApplicationProperties applicationProperties;

const char* GetAppNameFromPList() {
    NSString* appName = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"];
    if (appName != nil) {
        return [appName UTF8String];
    }

    return "Starboard";
}

const char* _StringFromNSString(void* str) {
    return [(NSString*)str UTF8String];
}

extern "C" void* _WideStringFromNSString(void* str) {
    NSString* _str = (NSString*)str;
    wchar_t* ret = (wchar_t*)malloc(([_str length] + 1) * sizeof(wchar_t));
    memcpy(ret, (void*)[_str rawCharacters], [_str length] * sizeof(wchar_t));
    ret[[_str length]] = 0;

    return ret;
}

int UIApplicationMainStart(int argc, char* argv[], const char* pName, const char* dName, float windowWidth, float windowHeight) {
    NSString* principalClassName = pName ? [[NSString alloc] initWithCString:pName] : nil;
    NSString* delegateClassName = dName ? [[NSString alloc] initWithCString:dName] : nil;

    WOCDisplayMode* displayMode = [UIApplication displayMode];
    [displayMode _setWindowSize:CGSizeMake(windowWidth, windowHeight)];

    float defaultWidth = GetCACompositor()->screenWidth();
    float defaultHeight = GetCACompositor()->screenHeight();
    float defaultScale = GetCACompositor()->screenScale();
    bool defaultTablet = false;

    [NSBundle setMainBundlePath:@"."];

    NSDictionary* infoDict = [[NSBundle mainBundle] infoDictionary];

    //  Figure out what our initial default orientation should be from Info.plist
    int defaultOrientation = UIInterfaceOrientationUnknown;
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

            for (NSString* curstr in (NSArray*)orientation) {
                int newOrientation = UIOrientationFromString(defaultOrientation, curstr);
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

    applicationProperties.appWidth = defaultWidth;
    applicationProperties.appHeight = defaultHeight;
    applicationProperties.appScale = defaultScale;
    applicationProperties.appName = strdup(GetAppNameFromPList());
    applicationProperties.isTablet = defaultTablet;

    [displayMode _updateDisplaySettings];
    GetCACompositor()->setTablet(applicationProperties.isTablet);

    UIApplicationMainInit(argc, argv, principalClassName, delegateClassName, defaultOrientation);
    return UIApplicationMainLoop();
}

void IWSetTemporaryFolder(const char* folder) {
    NSSetTemporaryDirectory([NSString stringWithCString:folder]);
}
