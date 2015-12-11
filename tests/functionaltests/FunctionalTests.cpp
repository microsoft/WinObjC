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

#include "pch.h"
#include <gtest-api.h>
#include <WexTestClass.h>

using namespace WEX::Logging;
using namespace WEX::TestExecution;

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

    return true;
}

MODULE_CLEANUP(ModuleCleanup) {
    return true;
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
//
class SampleTest {
public:
    BEGIN_TEST_CLASS(SampleTest)
    TEST_CLASS_PROPERTY(L"RunAs", L"UAP")
    END_TEST_CLASS()

    // SampleTest test class setup.
    // Notes:
    //     1. Perform any class test level initialization here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_SETUP(SampleTestClassSetup) {
        return true;
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