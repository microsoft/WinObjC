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
#endif

#include <Windows.UI.Xaml.Media.h>
#include <RTHelpers.h>

#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#endif

#import <UWP/WindowsUIXamlMedia.h>

static const NSTimeInterval c_testTimeoutInSec = 5;

TEST(Projection, CreateWithARCEnabled) {
    EXPECT_NO_THROW(
        @autoreleasepool {
            StrongId<NSAutoreleasePool> pool = [[NSAutoreleasePool alloc] init];
            ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyFactory> fontFamilyFactory;
            ASSERT_HRESULT_SUCCEEDED_MSG(ABI::Windows::Foundation::GetActivationFactory(
                Microsoft::WRL::Wrappers::HString::MakeReference(L"Windows.UI.Xaml.Media.FontFamily").Get(), 
                &fontFamilyFactory),
                "Failed: Could not get activation factory");

            // Get the dispatcher for the main thread.
            dispatch_sync(dispatch_get_main_queue(),
                ^{
                    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> fontFamilyInstance;
                    HString hstr;
                    ASSERT_HRESULT_SUCCEEDED_MSG(hstr.Set(L"Comic Sans MS"), "Failed: HString::Set failed");
                    HRESULT hr = fontFamilyFactory->CreateInstanceWithName(hstr.Get(),
                        nullptr,
                        nullptr,
                        fontFamilyInstance.GetAddressOf());
                    ASSERT_HRESULT_SUCCEEDED_MSG(hr, "Failed: CreateInstanceWithName failed");
                    StrongId<WUXMFontFamily> fontFamily;
                    ASSERT_NO_THROW_MSG(fontFamily = [WUXMFontFamily createWith:fontFamilyInstance.Get()], "Failed: createWith failed");
                });
        } // autoreleasepool
    );
}