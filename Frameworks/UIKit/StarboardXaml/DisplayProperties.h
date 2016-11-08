//******************************************************************************
//
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
#pragma once

namespace DisplayProperties {

bool IsTablet();
void SetTablet(bool isTablet);

float ScreenWidth();
float ScreenHeight();

enum ScreenRotation {
    ScreenRotationNone = 0,
    ScreenRotation90Clockwise = 90,
    ScreenRotation180 = 180,
    ScreenRotation90CounterClockwise = 270
};

void SetScreenSize(float width, float height, float scale, ScreenRotation rotation);

// Returns a calculated scale/magnification value based upon various app settings
float ScreenScale();

// Returns the raw scale/magnification factor that was set via a call to 'SetScreenSize'
float RawScreenScale();

float ScreenXDpi();
float ScreenYDpi();
void SetScreenDpi(int xDpi, int yDpi);

int DeviceWidth();
int DeviceHeight();
void SetDeviceSize(int width, int height);
}