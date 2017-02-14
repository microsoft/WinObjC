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