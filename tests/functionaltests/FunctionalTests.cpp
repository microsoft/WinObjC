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

#include "pch.h"
#include <gtest-api.h>
#include "Framework/Framework.h"
#include "FunctionalTestHelpers.h"
#include "Tests/AssetsLibraryTests/AssetsLibraryTestHelpers.h"
#include <WexTestClass.h>
#include <ErrorHandling.h>

// This is a method that UIKit exposes for the test frameworks to use.
extern "C" void UIApplicationInitialize(const wchar_t*, const wchar_t*);

static void UIApplicationDefaultInitialize() {
    // Pass null to indicate default app and app delegate classes
    UIApplicationInitialize(nullptr, nullptr);
}

//
// How is functional test organized?
//
// Functional test works on top of googletest framework by intercepting googletest result logging and diverting them to Microsoft TAEF
// framework for result reporting and logging from a UWP container. This lets developers to write test using googletest logging and assert
// macros (i.e. similar to Unit Tests).
// Today because Microsoft TAEF headers cannot be directly included in ObjC files (this is WIP), functional test imposes keeping the TAEF
// test case markup and the actual test code (written in ObjC) in two seperate files.
//     FunctionalTests.cpp - contains all the function test case markups that are essential for TAEF reporting.
//     SampleTest.mm - contains the actual test.
//
// These individual files have detailed comments on how to add new test cases or new test categories.
//

MODULE_SETUP(ModuleSetup) {
    // Initialize GTest framework.
    int argc = 1;
    char* argv[] = { "FunctionalTests" };
    testing::InitGoogleTest(&argc, argv);

    // Keep the device active
    return SUCCEEDED(FrameworkHelper::DisplayRequest(true));
}

MODULE_CLEANUP(ModuleCleanup) {
    return SUCCEEDED(FrameworkHelper::DisplayRequest(false));
}

//
// ****************************************************************************************************************************************
// Start Copy
// Start copying from here to add a new test category e.g. Location, URI etc.
// ****************************************************************************************************************************************
//

// Exported test function to call.
// Notes:
//     1. The macro 'TEST(SampleTest, Sanity)' in WinObjC test file translates to 'extern void SampleTestSanity()'.
//     2. Export all test methods that needs to be called here.

extern void SampleTestSanity();
extern void SampleTestFailure();

// Start of SampleTest.
// Notes:
//     1. Give a unique test class name for every test category e.g. Location, URI etc.
//     2. Use the same name in the BEGIN_TEST_CLASS macro.
//     3. Use the appropriate TEST_CLASS_PROPERTY for your test and remember to remove the "Ignore" property.
//
class SampleTest {
public:
    BEGIN_TEST_CLASS(SampleTest)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    // Note: TAEF automatically generates a default manifest with no capabilities at runtime. If your test
    // requires special capabilities, add your own custom manifest with the required capabilities.
    // TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"xyz.AppxManifest.xml")
    TEST_CLASS_PROPERTY(L"Ignore", L"true")
    END_TEST_CLASS()

    // SampleTest test class setup.
    // Notes:
    //     1. Perform any class test level initialization here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_SETUP(SampleTestClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    // SampleTest test class cleanup.
    // Notes:
    //     1. Perform any class test level cleanup here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_CLEANUP(SampleTestClassCleanup) {
        return true;
    }

    // SampleTest test method setup.
    // Notes:
    //     1. Perform any class test level initialization here. This is will run once before every test method in this class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_METHOD_SETUP(SampleTestSetup) {
        return true;
    }

    // SampleTest test method cleanup.
    // Notes:
    //     1. Perform any class test level cleanup here. This is will run once after every test method in this class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_METHOD_CLEANUP(SampleTestCleanup) {
        return true;
    }

    // SampleTest sanity test.
    // Notes:
    //     1. Give a unique test method name for every test. They should meaningfully describe the test being run.
    //     2. Do not add any test specific logic/verification in this file. Just call the test function exported from the WinObjC file here.
    //        (For details on how test functions from WinObjC test file is exported refer to FunctionalTest.h file)
    TEST_METHOD(SampleTest_Sanity) {
        // Call the actual test function.
        SampleTestSanity();
    }

    TEST_METHOD(SampleTest_Failure) {
        // Call the actual test function.
        SampleTestFailure();
    }

}; /* class SampleTest */

//
// End of SampleTest.
//

//
// ****************************************************************************************************************************************
// End Copy
// ****************************************************************************************************************************************
//

//
// NSURL Tests
//

extern void NSURLConnectionRequestWithURL();
extern void NSURLConnectionRequestWithURL_Failure();

extern void NSURLSessionTaskIdentifiers();
extern void NSURLSessionDataTaskWithURL();
extern void NSURLSessionDataTaskWithURL_Failure();
extern void NSURLSessionDataTaskWithURL_WithCompletionHandler();
extern void NSURLSessionDataTaskWithURL_WithCompletionHandler_Failure();
extern void NSURLSessionDownloadTaskWithURL();
extern void NSURLSessionDownloadTaskWithURL_Failure();
extern void NSURLSessionDownloadTaskWithURL_WithCompletionHandler();
extern void NSURLSessionDownloadTaskWithURL_WithCancelResume();

class NSURL {
public:
    BEGIN_TEST_CLASS(NSURL)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"NSURL.AppxManifest.xml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(NSURLCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    //
    // NSURLConnection
    //

    TEST_METHOD(NSURLConnection_RequestWithURL) {
        NSURLConnectionRequestWithURL();
    }

    TEST_METHOD(NSURLConnection_RequestWithURL_Failure) {
        NSURLConnectionRequestWithURL_Failure();
    }

    //
    // NSURLSession
    //

    TEST_METHOD(NSURLSession_TaskIdentifiers) {
        NSURLSessionTaskIdentifiers();
    }

    TEST_METHOD(NSURLSession_DataTaskWithURL) {
        NSURLSessionDataTaskWithURL();
    }

    TEST_METHOD(NSURLSession_DataTaskWithURL_Failure) {
        NSURLSessionDataTaskWithURL_Failure();
    }

    TEST_METHOD(NSURLSession_DataTaskWithURL_WithCompletionHandler) {
        NSURLSessionDataTaskWithURL_WithCompletionHandler();
    }

    TEST_METHOD(NSURLSession_DataTaskWithURL_WithCompletionHandler_Failure) {
        NSURLSessionDataTaskWithURL_WithCompletionHandler_Failure();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL) {
        NSURLSessionDownloadTaskWithURL();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL_Failure) {
        NSURLSessionDownloadTaskWithURL_Failure();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL_WithCompletionHandler) {
        NSURLSessionDownloadTaskWithURL_WithCompletionHandler();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL_WithCancelResume) {
        NSURLSessionDownloadTaskWithURL_WithCancelResume();
    }
}; /* class NSURL */

//
// NSUserDefaults Tests
//
extern void NSUserDefaultsBasic();
extern void NSUserDefaultsKVCArray();
extern void NSUserDefaultsRemove();
extern void NSUserDefaultsPerf();

class NSUserDefaults {
public:
    BEGIN_TEST_CLASS(NSUserDefaults)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(NSUserDefaultsCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(NSUserDefaults_Basic) {
        NSUserDefaultsBasic();
    }

    TEST_METHOD(NSUserDefaults_KVCArray) {
        NSUserDefaultsKVCArray();
    }

    TEST_METHOD(NSUserDefaults_Remove) {
        NSUserDefaultsRemove();
    }

    TEST_METHOD(NSUserDefaults_Perf) {
        NSUserDefaultsPerf();
    }

}; /* class NSUserDefaults */

//
// NSBundle Tests
//
extern void NSBundleMSAppxURL();

class NSBundle {
public:
    BEGIN_TEST_CLASS(NSBundle)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(NSBundleCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(NSBundle_MSAppxURL) {
        NSBundleMSAppxURL();
    }
}; /* class NSBundle */

//
// AssetsLibrary Tests
//
extern void AssetsLibraryGetVideoAsset();

class AssetsLibrary {
public:
    BEGIN_TEST_CLASS(AssetsLibrary)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"AssetsLibrary.AppxManifest.xml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(AssetsLibraryClassSetup) {
        bool success = AssetsLibraryTestVideoSetup("AssetsLibraryTestVideo.mp4");
        return (success & SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize)));
    }

    TEST_CLASS_CLEANUP(AssetsLibraryClassCleanup) {
        return AssetsLibraryTestVideoCleanup("AssetsLibraryTestVideo.mp4");
    }

    TEST_METHOD_CLEANUP(AssetsLibraryCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(AssetsLibrary_GetVideoAsset) {
        AssetsLibraryGetVideoAsset();
    }
}; /* class AssetsLibrary */

//
// Cortana Activation Tests
//

extern void CortanaTestVoiceCommandForegroundActivation();
extern void CortanaTestVoiceCommandForegroundActivationDelegateMethodsCalled();

class CortanaVoiceCommandForegroundActivation {
public:
    BEGIN_TEST_CLASS(CortanaVoiceCommandForegroundActivation)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CortanaVoiceCommandForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&CortanaTestVoiceCommandForegroundActivation));
    }

    TEST_METHOD_CLEANUP(CortanaVoiceCommandForegroundCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(Cortana_VoiceCommandForegroundActivationDelegateMethodsCalled) {
        CortanaTestVoiceCommandForegroundActivationDelegateMethodsCalled();
    }
}; /* class CortanaVoiceCommandForegroundActivation */

extern void CortanaTestProtocolForegroundActivation();
extern void CortanaTestProtocolForegroundActivationDelegateMethodsCalled();

class CortanaProtocolForegroundActivation {
public:
    BEGIN_TEST_CLASS(CortanaProtocolForegroundActivation)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CortanaProtocolForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&CortanaTestProtocolForegroundActivation));
    }

    TEST_METHOD_CLEANUP(CortanaProtocolForegroundCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(Cortana_ProtocolForegroundActivationDelegateMethodsCalled) {
        CortanaTestProtocolForegroundActivationDelegateMethodsCalled();
    }
}; /* class CortanaProtocolForegroundActivation */

extern void ToastNotificationTestForegroundActivation();
extern void ToastNotificationTestForegroundActivationDelegateMethodsCalled();

class ToastNotificationForegroundActivation {
    BEGIN_TEST_CLASS(ToastNotificationForegroundActivation)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ToastNotificationForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&ToastNotificationTestForegroundActivation));
    }

    TEST_METHOD_CLEANUP(ToastNotificationForegroundCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(ToastNotification_ForegroundActivationDelegateMethodsCalled) {
        ToastNotificationTestForegroundActivationDelegateMethodsCalled();
    }
}; /* class ToastNotificationForeground */

extern void ToastNotificationTestActivatedAppReceivesToastNotification();

class ActivatedAppReceivesToastNotification {
    BEGIN_TEST_CLASS(ActivatedAppReceivesToastNotification)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ActivatedAppReceivesToastNotificationTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(ActivatedAppReceivesToastNotificationCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(ToastNotification_ActivatedAppReceivesToastNotification) {
        ToastNotificationTestActivatedAppReceivesToastNotification();
    }
}; /* class ActivatedAppReceivesToastNotification */

// UIKitTests
//
extern void UIViewCreate();
extern void UIViewGetXamlElement();
extern void UIActivityIndicatorViewCreateXamlElement();
extern void UIActivityIndicatorViewGetXamlElement();
extern void UIButtonCreateXamlElement();
extern void UIButtonGetXamlElement();
extern void UIScrollViewCreateXamlElement();
extern void UIScrollViewGetXamlElement();
extern void UISliderCreateXamlElement();
extern void UISliderGetXamlElement();
extern void UITextFieldCreateXamlElement();
extern void UITextFieldGetXamlElement();

class UIKitTests {
public:
    BEGIN_TEST_CLASS(UIKitTests)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(UIKitTestsCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(UIView_Create) {
        UIViewCreate();
    }

    TEST_METHOD(UIView_GetXamlElement) {
        UIViewGetXamlElement();
    }

    TEST_METHOD(UIActivityIndicatorView_CreateXamlElement) {
        UIActivityIndicatorViewCreateXamlElement();
    }

    TEST_METHOD(UIActivityIndicatorView_GetXamlElement) {
        UIActivityIndicatorViewGetXamlElement();
    }

    TEST_METHOD(UIButton_CreateXamlElement) {
        UIButtonCreateXamlElement();
    }

    TEST_METHOD(UIButton_GetXamlElement) {
        UIButtonGetXamlElement();
    }

    TEST_METHOD(UIScrollView_CreateXamlElement) {
        UIScrollViewCreateXamlElement();
    }

    TEST_METHOD(UIScrollView_GetXamlElement) {
        UIScrollViewGetXamlElement();
    }

    TEST_METHOD(UISlider_CreateXamlElement) {
        UISliderCreateXamlElement();
    }

    TEST_METHOD(UISlider_GetXamlElement) {
        UISliderGetXamlElement();
    }

    TEST_METHOD(UITextField_CreateXamlElement) {
        UITextFieldCreateXamlElement();
    }

    TEST_METHOD(UITextField_GetXamlElement) {
        UITextFieldGetXamlElement();
    }
}; /* class UIKitTests */

// Projection Tests
//
extern void ProjectionWUCCoreDispatcherSanity();
extern void ProjectionHStringTest();
extern void ProjectionCreateWithTest();
extern void ProjectionAsyncOnUIThread();
extern void ProjectionAsyncOnBackgroundThread();
extern void ProjectionCreateWithARCEnabled();

class ProjectionTest {
public:
    BEGIN_TEST_CLASS(ProjectionTest)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ProjectionTestClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD_CLEANUP(ProjectionTestCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(ProjectionTest_WUCCoreDispatcherSanity) {
        ProjectionWUCCoreDispatcherSanity();
    }

    TEST_METHOD(ProjectionTest_HStringTest) {
        ProjectionHStringTest();
    }

    TEST_METHOD(ProjectionTest_CreateWithTest) {
        ProjectionCreateWithTest();
    }

    TEST_METHOD(ProjectionTest_AsyncOnBackgroundThread) {
        ProjectionAsyncOnBackgroundThread();
    }

    TEST_METHOD(ProjectionTest_CreateWithARCEnabled) {
        ProjectionCreateWithARCEnabled();
    }

}; /* class ProjectionTest */

//
// UIApplicationTests
//
extern void UIApplicationTestsOpenURL();

class UIApplicationTests {
public:
    BEGIN_TEST_CLASS(UIApplicationTests)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    TEST_CLASS_PROPERTY(L"UAP:Host", L"Xaml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIApplicationTestsSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    TEST_METHOD(UIApplicationTests_OpenURL) {
        UIApplicationTestsOpenURL();
    }
}; /* class UIApplicationTests */
