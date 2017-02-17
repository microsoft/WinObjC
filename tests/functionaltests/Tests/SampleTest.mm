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

#include <TestFramework.h>
#include <Foundation/Foundation.h>

//
// ****************************************************************************************************************************************
// Start Copy
// Start copying from here to add a new test category e.g. Location, URI etc.
// ****************************************************************************************************************************************
//

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
        return FunctionalTestSetupUIApplication();
    }

    // SampleTest test class cleanup.
    // Notes:
    //     1. Perform any class test level cleanup here. This is will run once for every class.
    //     2. Use the same mechanism as in TEST_METHOD below to export a method from the WinObjC test file and call it here.
    //     3. If you do not need this functionality feel free to remove this for your test class.
    TEST_CLASS_CLEANUP(SampleTestClassCleanup) {
        return FunctionalTestCleanupUIApplication();
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

    TEST_METHOD(Sanity) {
        LOG_INFO("SampleTest sanity test: ");

        NSArray* arr1 = [NSArray arrayWithObject:@1];
        NSArray* arr2 = [NSArray arrayWithObject:@1];

        ASSERT_OBJCEQ(arr1, arr2);
    }

    TEST_METHOD(Failure) {
        LOG_INFO("SampleTest failure test: ");

        NSArray* arr1 = [NSArray arrayWithObject:@5];
        NSArray* arr2 = [NSArray arrayWithObject:@10];

        ASSERT_OBJCNE(arr1, arr2);
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