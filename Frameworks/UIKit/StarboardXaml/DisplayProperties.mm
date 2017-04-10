//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) Microsoft Corporation. All rights reserved.
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
#import "DisplayProperties.h"
#import "XamlCompositor.h"

#import "UIApplicationInternal.h"

#import <algorithm>

#include "COMIncludes.h"
#import "winrt/Windows.UI.Core.h"
#import "winrt/Windows.Devices.Input.h"
#include "COMIncludes_End.h"

using namespace winrt::Windows::Devices::Input;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"DisplayProperties";

static float s_screenWidth = 320.0f;
static float s_screenHeight = 480.0f;
static float s_screenMagnification = 1.0f;

static bool s_tabletMode = false;

static float s_screenXDpi = 180;
static float s_screenYDpi = 180;

static int s_deviceWidth = 640;
static int s_deviceHeight = 1136;

namespace DisplayProperties {

bool IsTablet() {
    return s_tabletMode;
}

void SetTablet(bool isTablet) {
    TraceVerbose(TAG, L"SetTablet=%d", isTablet);
    s_tabletMode = isTablet;
}

float ScreenWidth() {
    return s_screenWidth;
}

float ScreenHeight() {
    return s_screenHeight;
}

float ScreenScale() {
    float scale = s_screenMagnification;

    // If we're not running in a UWP, return the default scale factor
    if (!winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread()) {
        return scale;
    }

    if ([[UIApplication displayMode] useHostScaleFactor]) {
        scale *= [UIApplication displayMode].hostScreenScale;
    }

    // On an iOS device, the only expected values for UIScreen.scale is 1, or 2 for retina displays.
    // Some code paths rely on this.
    if ([[UIApplication displayMode] clampScaleToClosestExpected]) {
        // If we've set a fixed width or height, we're also expecting a fixed screenScale.
        if ([UIApplication displayMode].autoMagnification &&
            (([UIApplication displayMode].fixedWidth != 0) || ([UIApplication displayMode].fixedHeight != 0))) {
            static float fixedScreenScale = 0;
            static float prevWidth = 0;
            static float prevHeight = 0;

            if (fixedScreenScale &&
                (([UIApplication displayMode].fixedWidth == prevWidth) && ([UIApplication displayMode].fixedHeight == prevHeight))) {
                return fixedScreenScale;
            }

            prevWidth = [UIApplication displayMode].fixedWidth;
            prevHeight = [UIApplication displayMode].fixedHeight;

            float maxDimension = 0;
            WF::Collections::IVectorView<PointerDevice> pointerDevices = PointerDevice::GetPointerDevices();

            for (int i = 0; i < pointerDevices.Size(); i++) {
                WF::Rect screenRect = pointerDevices.GetAt(i).ScreenRect();
                float hostScreenScale = [UIApplication displayMode].hostScreenScale;
                maxDimension = std::max(maxDimension, std::max(screenRect.Width * hostScreenScale, screenRect.Height * hostScreenScale));
            }

            // We can't know whether the app will be rotated, or moved from screen to screen. We have to take the
            // worst case scenario, and set the scale using the maximum possible dimension.

            float maxScreenDimension = std::max([UIApplication displayMode].fixedWidth, [UIApplication displayMode].fixedHeight);

            if (maxDimension == 0) {
                TraceWarning(TAG, L"Could not determine screen size, defaulting to a screenScale of 2!");
                fixedScreenScale = 2.0f;
            } else if (maxDimension > maxScreenDimension) {
                fixedScreenScale = 2.0f;
            } else {
                fixedScreenScale = 1.0f;
            }

            return fixedScreenScale;
        } else {
            // Round to nearest int
            scale = static_cast<float>(static_cast<int>(scale + 0.5f));

            // Clamp
            if (scale > 2.0f) {
                scale = 2.0f;
            }
            if (scale < 1.0f) {
                scale = 1.0f;
            }
        }
    }

    return scale;
}

float RawScreenScale() {
    return s_screenMagnification;
}

void SetScreenSize(float width, float height, float scale, ScreenRotation rotation) {
    TraceVerbose(TAG,
                 L"SetScreenSize width=%f, height=%f, scale=%f, rotationClockwise=%f",
                 width,
                 height,
                 scale,
                 static_cast<float>(rotation));
    s_screenWidth = width;
    s_screenHeight = height;
    s_screenMagnification = scale;
    XamlCompositor::Internal::SetScreenParameters(s_screenWidth, s_screenHeight, s_screenMagnification, static_cast<float>(rotation));
}

float ScreenXDpi() {
    return s_screenXDpi;
}

float ScreenYDpi() {
    return s_screenYDpi;
}

void SetScreenDpi(int xDpi, int yDpi) {
    TraceVerbose(TAG, L"SetScreenDpi xDpi=%f, yDpi=%f", xDpi, yDpi);
    s_screenXDpi = xDpi;
    s_screenYDpi = yDpi;
}

int DeviceWidth() {
    return s_deviceWidth;
}

int DeviceHeight() {
    return s_deviceHeight;
}

void SetDeviceSize(int width, int height) {
    TraceVerbose(TAG, L"SetDeviceSize width=%d, height=%d", width, height);
    s_deviceWidth = width;
    s_deviceHeight = height;
}
}