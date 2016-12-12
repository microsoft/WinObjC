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
#include <WexTestClass.h>
#include <ErrorHandling.h>

BEGIN_MODULE()
MODULE_PROPERTY(L"RunAs", L"UAP")
MODULE_PROPERTY(L"UAP:Host", L"Xaml")
MODULE_PROPERTY(L"UAP:AppXManifest", L"Default.AppxManifest.xml")
END_MODULE()

// This is a method that UIKit exposes for the test frameworks to use.
extern "C" void UIApplicationInitialize(const wchar_t*, const wchar_t*);

void UIApplicationDefaultInitialize() {
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
    // Note: We automatically set a default AppXManifest at the top of this file, but it provides no UWP capabilities. If your test
    // requires special capabilities, add your own custom manifest with the required capabilities, and specify it as such:
    // TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"xyz.AppxManifest.xml")
    TEST_CLASS_PROPERTY(L"Ignore", L"true")
    END_TEST_CLASS()

    // SampleTest test class setup.
    // Notes:
    //    Perform any class test level initialization here. This is will run once for every class.
    TEST_CLASS_SETUP(SampleTestClassSetup) {
        return SUCCEEDED(FrameworkHelper::RunOnUIThread(&UIApplicationDefaultInitialize));
    }

    // SampleTest test class cleanup.
    // Notes:
    //     Perform any class test level cleanup here. This is will run once for every class.
    TEST_CLASS_CLEANUP(SampleTestClassCleanup) {
        return true;
    }

    // SampleTest test method setup.
    // Notes:
    //     Perform any class test level initialization here. This is will run once before every test method in this class.
    TEST_METHOD_SETUP(SampleTestSetup) {
        return true;
    }

    // SampleTest test method cleanup.
    // Notes:
    //     Perform any class test level cleanup here. This is will run once after every test method in this class.
    TEST_METHOD_CLEANUP(SampleTestCleanup) {
        return true;
    }

    TEST_METHOD(SampleTestSanity) {
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
