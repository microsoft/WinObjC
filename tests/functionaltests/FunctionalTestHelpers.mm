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

#import <Logger.h>
#import <FunctionalTestHelpers.h>
#import <AppDelegate.h>

#include "UIKit/UIApplication.h"
#include "UIViewInternal.h"
#import <Starboard/SmartTypes.h>
#import <StringHelpers.h>
#import <UWP/WindowsApplicationModel.h>

// This is a method that UIKit exposes for the test frameworks to use.
extern "C" void UIApplicationInitialize(const wchar_t*, const wchar_t*);

static bool g_appRunning = false;

// Launches the functional test app
void FunctionalTestSetupUIApplication() {
    if (g_appRunning) {
        FunctionalTestLog::LogErrorAndAbort(
            "Mismatched calls to FunctionalTestSetupUIApplication/FunctionalTestCleanupUIApplication!", 
            __FILE__, 
            __FUNCTION__, 
            __LINE__);
    }

    RunSynchronouslyOnMainThread(^{
        // The name of our default 'AppDelegate' class
        UIApplicationInitialize(nullptr, Strings::NarrowToWide<std::wstring>(NSStringFromClass([AppDelegate class])).c_str());
        g_appRunning = true;
    });
}

// Terminates the functional test app
void FunctionalTestCleanupUIApplication() {
    RunSynchronouslyOnMainThread(^{
        [[UIApplication sharedApplication] _destroy];
        g_appRunning = false;
    });
}

// Gets the path to the app installation location
// Returned path is formatted with double backslashes
NSString* getModulePath() {
    return [[[WAPackage current] installedLocation] path];
}

// Gets path to functional test module and appends path component
// Returned path is formatted with double backslashes
NSString* appendPathRelativeToFTModule(NSString* pathAppendage) {
    StrongId<NSString> refPath = getModulePath();
    refPath = [refPath stringByAppendingPathComponent:pathAppendage];
    return [refPath stringByReplacingOccurrencesOfString:@"/" withString:@"\\"];
}
