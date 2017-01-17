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

#include "pch.h"
#include <gtest-api.h>
#include "Framework/Framework.h"
#include "FunctionalTestHelpers.h"
#include "Tests/AssetsLibraryTests/AssetsLibraryTestHelpers.h"
#include <WexTestClass.h>
#include <ErrorHandling.h>

BEGIN_MODULE()
MODULE_PROPERTY(L"RunAs", L"UAP")
MODULE_PROPERTY(L"UAP:Host", L"Xaml")
MODULE_PROPERTY(L"UAP:AppXManifest", L"Default.AppxManifest.xml")
END_MODULE()

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
    // Note: We automatically set a default AppXManifest at the top of this file, but it provides no UWP capabilities. If your test
    // requires special capabilities, add your own custom manifest with the required capabilities, and specify it as such:
    // TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"xyz.AppxManifest.xml")
    TEST_CLASS_PROPERTY(L"Ignore", L"true")
    END_TEST_CLASS()

    // SampleTest test class setup.
    // Notes:
    //     1. Perform any class test level initialization here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_SETUP(SampleTestClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    // SampleTest test class cleanup.
    // Notes:
    //     1. Perform any class test level cleanup here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_CLEANUP(SampleTestClassCleanup) {
        FunctionalTestCleanupUIApplication();
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
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"NSURL.AppxManifest.xml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(NSURLClassCleanup) {
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
// Disable Test on ARM as it tries to hit a real endpoint and download significant data
// and arm machines may not have a stable ethernet connection like a build server does.
#ifdef _M_ARM
        BEGIN_TEST_METHOD_PROPERTIES()
        TEST_METHOD_PROPERTY(L"ignore", L"true")
        END_TEST_METHOD_PROPERTIES()
#endif
        NSURLSessionDownloadTaskWithURL();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL_Failure) {
        NSURLSessionDownloadTaskWithURL_Failure();
    }

    TEST_METHOD(NSURLSession_DownloadTaskWithURL_WithCompletionHandler) {
// Disable Test on ARM as it tries to hit a real endpoint and download significant data
// and arm machines may not have a stable ethernet connection like a build server does.
#ifdef _M_ARM
        BEGIN_TEST_METHOD_PROPERTIES()
        TEST_METHOD_PROPERTY(L"ignore", L"true")
        END_TEST_METHOD_PROPERTIES()
#endif
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSUserDefaultsClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(NSUserDefaultsClassCleanup) {
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSBundleClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(NSBundleClassCleanup) {
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
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"AssetsLibrary.AppxManifest.xml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(AssetsLibraryClassSetup) {
        bool success = AssetsLibraryTestVideoSetup("AssetsLibraryTestVideo.mp4");
        FunctionalTestSetupUIApplication();
        return success;
    }

    TEST_CLASS_CLEANUP(AssetsLibraryClassCleanup) {
        bool success = AssetsLibraryTestVideoCleanup("AssetsLibraryTestVideo.mp4");
        FunctionalTestCleanupUIApplication();
        return success;
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CortanaVoiceCommandForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&CortanaTestVoiceCommandForegroundActivation));
    }

    TEST_CLASS_CLEANUP(CortanaVoiceCommandForegroundTestClassCleanup) {
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CortanaProtocolForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&CortanaTestProtocolForegroundActivation));
    }

    TEST_CLASS_CLEANUP(CortanaProtocolForegroundTestClassCleanup) {
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ToastNotificationForegroundTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&ToastNotificationTestForegroundActivation));
    }

    TEST_CLASS_CLEANUP(ToastNotificationForegroundTestClassCleanup) {
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
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ActivatedAppReceivesToastNotificationTestClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(ActivatedAppReceivesToastNotificationTestClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(ToastNotification_ActivatedAppReceivesToastNotification) {
        ToastNotificationTestActivatedAppReceivesToastNotification();
    }
}; /* class ActivatedAppReceivesToastNotification */

//
// File Activation Tests
//

extern void FileActivatedTestForegroundActivation();
extern void FileActivatedTestForegroundActivationDelegateMethodsCalled();

class FileActivationForegroundActivation {
public:
    BEGIN_TEST_CLASS(FileActivationForegroundActivation)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(FileActivationForegroundActivationClassSetup) {
        // The class setup allows us to activate the app in our test method, but can only be done once per class
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&FileActivatedTestForegroundActivation));
    }

    TEST_CLASS_CLEANUP(FileActivationForegroundActivationClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(FileActivation_TestForegroundActivationDelegateMethodsCalled) {
        FileActivatedTestForegroundActivationDelegateMethodsCalled();
    }
}; /* class FileActivatedTestForegroundActivation */

// UIKitTests
//
extern void UIViewCreate();
extern void UIViewGetXamlElement();
extern void UIViewInsertSubviewAtIndex0();
extern void UIViewInsertSubviewAtIndex1();
extern void UIViewInsertSubviewAtIndex2();
extern void UIViewInsertSubviewAtIndex3();
extern void UIViewInsertSubviewBelowSubview0();
extern void UIViewInsertSubviewBelowSubview1();
extern void UIViewInsertSubviewBelowSubview2();
extern void UIViewInsertSubviewBelowSubview3();
extern void UIViewInsertSubviewAboveSubview0();
extern void UIViewInsertSubviewAboveSubview1();
extern void UIViewInsertSubviewAboveSubview2();
extern void UIViewInsertSubviewAboveSubview3();
extern void UIViewInsertSubviewBelowSubviewNonSibling();
extern void UIViewInsertSubviewAboveSubviewNonSibling();
extern void UIViewInsertSubviewBelowSubviewNil();
extern void UIViewInsertSubviewAboveSubviewNil();

extern void UIActionSheetCreateXamlElement();
extern void UIActionSheetGetXamlElement();
extern void UIActionSheetNilParameters();

extern void UIActivityIndicatorViewCreateXamlElement();
extern void UIActivityIndicatorViewGetXamlElement();

extern void UIButtonCreateXamlElement();
extern void UIButtonGetXamlElement();
extern void UIButtonBackgroundColorChanged();

extern void UIScrollViewCreateXamlElement();
extern void UIScrollViewGetXamlElement();

extern void UISliderCreateXamlElement();
extern void UISliderGetXamlElement();

extern void UITextFieldCreateXamlElement();
extern void UITextFieldGetXamlElement();

extern void NSLayoutConstraintVisualFormatLanguage();
extern void NSLayoutConstraintVisualFormatLanguageSyntax();
extern void NSLayoutConstraintAddConstraints();

class UIKitTests {
public:
    BEGIN_TEST_CLASS(UIKitTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(UIKitTestsClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(UIView_Create) {
        // Note: Intentionally not dispatched to the UI thread for testing purposes
        UIViewCreate();
    }

    TEST_METHOD(UIView_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIViewGetXamlElement);
    }

    TEST_METHOD(UIView_InsertSubviewAtIndex0) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAtIndex0);
    }

    TEST_METHOD(UIView_InsertSubviewAtIndex1) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAtIndex1);
    }

    TEST_METHOD(UIView_InsertSubviewAtIndex2) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAtIndex2);
    }

    TEST_METHOD(UIView_InsertSubviewAtIndex3) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAtIndex3);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubview0) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubview0);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubview1) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubview1);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubview2) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubview2);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubview3) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubview3);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubview0) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubview0);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubview1) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubview1);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubview2) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubview2);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubview3) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubview3);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubviewNonSibling) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubviewNonSibling);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubviewNonSibling) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubviewNonSibling);
    }

    TEST_METHOD(UIView_InsertSubviewBelowSubviewNil) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewBelowSubviewNil);
    }

    TEST_METHOD(UIView_InsertSubviewAboveSubviewNil) {
        FrameworkHelper::RunOnUIThread(&UIViewInsertSubviewAboveSubviewNil);
    }

    TEST_METHOD(UIActionSheet_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIActionSheetCreateXamlElement);
    }

    TEST_METHOD(UIActionSheet_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIActionSheetGetXamlElement);
    }

    TEST_METHOD(UIActionSheet_NilParameters) {
        FrameworkHelper::RunOnUIThread(&UIActionSheetNilParameters);
    }

    TEST_METHOD(UIActivityIndicatorView_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIActivityIndicatorViewCreateXamlElement);
    }

    TEST_METHOD(UIActivityIndicatorView_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIActivityIndicatorViewGetXamlElement);
    }

    TEST_METHOD(UIButton_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIButtonCreateXamlElement);
    }

    TEST_METHOD(UIButton_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIButtonGetXamlElement);
    }

    TEST_METHOD(UIButton_BackgroundColorChanged) {
        // Disable this test for now since it previously relied on the async delay between setting a UI property
        // and seeing the change applied to the backing XAML element during the next tick on the runloop
        BEGIN_TEST_METHOD_PROPERTIES()
        TEST_METHOD_PROPERTY(L"ignore", L"true")
        END_TEST_METHOD_PROPERTIES()

        UIButtonBackgroundColorChanged();
    }

    TEST_METHOD(UIScrollView_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIScrollViewCreateXamlElement);
    }

    TEST_METHOD(UIScrollView_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UIScrollViewGetXamlElement);
    }

    TEST_METHOD(UISlider_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UISliderCreateXamlElement);
    }

    TEST_METHOD(UISlider_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UISliderGetXamlElement);
    }

    TEST_METHOD(UITextField_CreateXamlElement) {
        FrameworkHelper::RunOnUIThread(&UITextFieldCreateXamlElement);
    }

    TEST_METHOD(UITextField_GetXamlElement) {
        FrameworkHelper::RunOnUIThread(&UITextFieldGetXamlElement);
    }

    TEST_METHOD(NSLayoutConstraint_VisualFormatLanguage) {
        FrameworkHelper::RunOnUIThread(&NSLayoutConstraintVisualFormatLanguage);
    }

    TEST_METHOD(NSLayoutConstraint_VisualFormatLanguageSyntax) {
        FrameworkHelper::RunOnUIThread(&NSLayoutConstraintVisualFormatLanguageSyntax);
    }

    TEST_METHOD(NSLayoutConstraint_AddConstraints) {
        FrameworkHelper::RunOnUIThread(&NSLayoutConstraintAddConstraints);
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
extern void ProjectionComposableAttrClass();
extern void ProjectionContainerOfContainers();

class ProjectionTest {
public:
    BEGIN_TEST_CLASS(ProjectionTest)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ProjectionTestClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(ProjectionTestClassCleanup) {
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

    TEST_METHOD(ProjectionTest_ComposableAttrClass) {
        ProjectionComposableAttrClass();
    }

    TEST_METHOD(ProjectionTest_ContainerOfContainers) {
        ProjectionContainerOfContainers();
    }

}; /* class ProjectionTest */

//
// UIApplicationTests
//
extern void UIApplicationTestsOpenURL();

class UIApplicationTests {
public:
    BEGIN_TEST_CLASS(UIApplicationTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIApplicationTestsClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(UIApplicationTestsClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(UIApplicationTests_OpenURL) {
        UIApplicationTestsOpenURL();
    }
}; /* class UIApplicationTests */

//
// NSURLStorageFileTests
//
extern void NSURLStorageFileURL();

class NSURLStorageFileTests {
public:
    BEGIN_TEST_CLASS(NSURLStorageFileTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLStorageFileTestsClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(NSURLStorageFileTestsClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(NSURLTests_StorageFileURL) {
        NSURLStorageFileURL();
    }
}; /* class NSURLStorageFileTests */

//
// CoreAnimationTests
//
extern void CALayerAppearanceOpacityChanged();
extern void CALayerAppearanceBackgroundColorChanged();

class CoreAnimationTests {
public:
    BEGIN_TEST_CLASS(CoreAnimationTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(CoreAnimationTestsClassSetup) {
        FunctionalTestSetupUIApplication();
        return true;
    }

    TEST_CLASS_CLEANUP(CoreAnimationTestsClassCleanup) {
        FunctionalTestCleanupUIApplication();
        return true;
    }

    TEST_METHOD(CALayerAppearance_OpacityChanged) {
        // NOTE: We are not using the FrameworkHelper::RunOnUIThread because we need to set a waitable condition outside of it
        CALayerAppearanceOpacityChanged();
    }

    TEST_METHOD(CALayerAppearance_BackgroundColorChanged) {
        // NOTE: We are not using the FrameworkHelper::RunOnUIThread because we need to set a waitable condition outside of it
        CALayerAppearanceBackgroundColorChanged();
    }
}; /* class CoreAnimationTests */
