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

#import <Starboard/SmartTypes.h>
#import <Foundation/Foundation.h>

#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#pragma push_macro("__alignof")
#define __alignof alignof
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmicrosoft"
#endif

#include <Windows.UI.Xaml.Media.h>
#include <UWP/RTHelpers.h>

#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#pragma pop_macro("__alignof")
#pragma clang diagnostic pop
#endif

#import <UWP/WindowsUIXamlMedia.h>

class ProjectionsSanityTest {
public:
    BEGIN_TEST_CLASS(ProjectionsSanityTest)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ProjectionTestClassSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(ProjectionTestCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    // This file has ARC disabled as for some reason ARC
    // cannot be used with ASSERT_OBJCEQ_MSG macro.
    TEST_METHOD(HStringTest) {
        LOG_INFO("Projection HString Sanity Test: ");
        StrongId<WUXITypeName> typeName = [WUXITypeName new];
        NSString* expectedString = @"Test";
        [typeName setName:expectedString];
        ASSERT_OBJCEQ_MSG(expectedString, [typeName name], "FAILED: HString mismatch\n");
    }

    TEST_METHOD(CreateWithTest) {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyFactory> fontFamilyFactory;
        ASSERT_HRESULT_SUCCEEDED_MSG(ABI::Windows::Foundation::GetActivationFactory(
                                         Microsoft::WRL::Wrappers::HString::MakeReference(L"Windows.UI.Xaml.Media.FontFamily").Get(),
                                         &fontFamilyFactory),
                                     "Failed: Could not get activation factory");

        // Get the dispatcher for the main thread.
        dispatch_sync(dispatch_get_main_queue(), ^{
            ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> fontFamilyInstance;
            HString hstr;
            ASSERT_HRESULT_SUCCEEDED_MSG(hstr.Set(L"Comic Sans MS"), "Failed: HString::Set failed");
            HRESULT hr = fontFamilyFactory->CreateInstanceWithName(hstr.Get(), nullptr, nullptr, fontFamilyInstance.GetAddressOf());
            ASSERT_HRESULT_SUCCEEDED_MSG(hr, "Failed: CreateInstanceWithName failed");
            StrongId<WUXMFontFamily> fontFamily;
            ASSERT_NO_THROW_MSG(fontFamily = [WUXMFontFamily createWith:fontFamilyInstance.Get()], "Failed: createWith failed");
            ASSERT_NE_MSG(fontFamily, nil, "Failed: CreateWithTest failed");
        });

        // createWith method returns autoreleased object.
        // So draining the pool should not throw.
        EXPECT_NO_THROW([pool release]);
    }

    TEST_METHOD(ComposableAttrClass) {
        dispatch_sync(dispatch_get_main_queue(), ^{
            StrongId<WUXMFontFamily> fontFamily;
            EXPECT_NO_THROW(fontFamily = [WUXMFontFamily makeInstanceWithName:@"Comic Sans MS"]);
            ASSERT_NE_MSG(fontFamily, nil, "FAILED: ComposableAttrClass Test failed\n");
        });
    }

}; /* class ProjectionTest */