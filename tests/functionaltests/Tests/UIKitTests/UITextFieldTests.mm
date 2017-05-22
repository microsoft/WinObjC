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
#include <TestFramework.h>
#import <UIKit/UITextField.h>
#import "UIViewInternal.h"

#import "FunctionalTestHelpers.h"
#import "UXTestHelpers.h"
#import "CppWinRTHelpers.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#include <COMIncludes_end.h>

#import "UIKitControls/UITextFieldViewController2.h"
#include "ObjCXamlControls.h"

using namespace winrt::Windows::UI::Xaml;

class UIKitTextFieldTests {
public:
    BEGIN_TEST_CLASS(UIKitTextFieldTests)
    END_TEST_CLASS()

    TEST_CLASS_SETUP(UIKitTestsSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(UIKitTestsCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    TEST_METHOD(UITextField_VerifyText) {
        // verify setting UITextField text property is reflected on xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        __block UITextField* textField = [textFieldlVC textField];
        auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
        Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
        auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
        EXPECT_TRUE(textBox);

        __block auto uxEvent = UXTestAPI::UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

        __block NSString* expectedText = @"short string";
        dispatch_sync(dispatch_get_main_queue(), ^{

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::TextBox::TextProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    NSString* text = UXTestAPI::NSStringFromPropertyValue(sender.GetValue(dp));
                                    LOG_INFO("XAML text: %@", text);

                                    // Validation
                                    if ([expectedText isEqualToString:objcwinrt::string(textBox.Text())]) {
                                        uxEvent->Set();
                                    }
                                });

            textField.text = expectedText;
        });
        EXPECT_TRUE_MSG(uxEvent->Wait(2), "FAILED: Waiting for property changed event state timed out!");

        uxEvent->Reset();
        xamlSubscriber->Reset();
        expectedText = @"this is a long string for testing";

        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::TextBox::TextProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    NSString* text = UXTestAPI::NSStringFromPropertyValue(sender.GetValue(dp));
                                    LOG_INFO("XAML text: %@", text);
                                    // Validation
                                    if ([expectedText isEqualToString:objcwinrt::string(textBox.Text())]) {
                                        uxEvent->Set();
                                    }
                                });

            textField.text = expectedText;
        });
        EXPECT_TRUE_MSG(uxEvent->Wait(2), "FAILED: Waiting for property changed event state timed out!");

        uxEvent->Reset();
        xamlSubscriber->Reset();
        dispatch_sync(dispatch_get_main_queue(), ^{
            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::TextBox::TextProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    NSString* text = UXTestAPI::NSStringFromPropertyValue(sender.GetValue(dp));
                                    // Validation
                                    if (textBox.Text().empty()) {
                                        uxEvent->Set();
                                    }
                                });

            textField.text = nil;
        });
        EXPECT_TRUE_MSG(uxEvent->Wait(2), "FAILED: Waiting for property changed event state timed out!");
    }

    TEST_METHOD(UITextField_VerifyPlaceholder) {
        // verify setting UITextField placeholder property is reflected on xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            textField.placeholder = @"placeholder";
            EXPECT_OBJCEQ(objcwinrt::string(textBox.PlaceholderText()), textField.placeholder);

            textField.placeholder = @"this is a long placeholder for testing.";
            EXPECT_OBJCEQ(objcwinrt::string(textBox.PlaceholderText()), textField.placeholder);

            textField.placeholder = nil;
            EXPECT_TRUE(textBox.PlaceholderText().empty());
        });
    }

    TEST_METHOD(UITextField_VerifySecureTextEntry) {
        // verify setting UITextField SeucreTextEntry results backing xaml element change
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // by default, non-secure mode, verify textbox exists
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            // switching to secure entry mode
            textField.secureTextEntry = YES;
            Microsoft::WRL::ComPtr<IInspectable> inspectable2(XamlGetTextFieldPasswordBox(objcwinrt::to_insp(grid)));

            // get the backing passwordBox, which should not be nil
            auto passwordBox = objcwinrt::from_insp<Controls::PasswordBox>(inspectable2);
            EXPECT_TRUE(passwordBox);

            // get the backing textbox, which should be nil
            textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable2);
            EXPECT_TRUE(textBox == nullptr);

            // switching back to non-secure entry mode, make sure textbox exist
            textField.secureTextEntry = NO;
            Microsoft::WRL::ComPtr<IInspectable> inspectable3(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable3);
            EXPECT_TRUE(textBox);

            passwordBox = objcwinrt::from_insp<Controls::PasswordBox>(inspectable3);
            EXPECT_TRUE(passwordBox == nullptr);
        });
    }

    TEST_METHOD(UITextField_VerifyTextAlignment) {
        // verify setting UITextField TextAlignment is reflected on backing xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element, which is Grid contains TextBox or passwordBox
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            // verify default value is left
            EXPECT_TRUE(textBox.TextAlignment() == TextAlignment::Left);

            // verify setting alignment to others
            textField.textAlignment = UITextAlignmentRight;
            EXPECT_TRUE(textBox.TextAlignment() == TextAlignment::Right);

            textField.textAlignment = UITextAlignmentCenter;
            EXPECT_TRUE(textBox.TextAlignment() == TextAlignment::Center);

            textField.textAlignment = UITextAlignmentLeft;
            EXPECT_TRUE(textBox.TextAlignment() == TextAlignment::Left);
        });
    }

    TEST_METHOD(UITextField_VerifyTextColor) {
        // verify setting UITextField TextColor is reflected on backing xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            // Verify default textcolor
            auto colorBrush = textBox.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(colorBrush, textField.textColor));

            // Verify changing textcolor to blue
            textField.textColor = [UIColor blueColor];
            colorBrush = textBox.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(colorBrush, textField.textColor));

            // Verify changing textcolor to red
            textField.textColor = [UIColor redColor];
            colorBrush = textBox.Foreground().as<Media::SolidColorBrush>();
            EXPECT_TRUE(UXTestAPI::IsRGBAEqual(colorBrush, textField.textColor));

        });
    }

    TEST_METHOD(UITextField_VerifyBackgroundColor) {
        // verify setting UITextField backgroundColor is reflected on backing xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        __block auto uxEvent = UXTestAPI::UXEvent::CreateManual();
        __block auto xamlSubscriber = std::make_shared<UXTestAPI::XamlEventSubscription>();

        dispatch_sync(dispatch_get_main_queue(), ^{
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::Control::BackgroundProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    // Validation
                                    auto colorBrush = textBox.Background().as<Media::SolidColorBrush>();
                                    if (UXTestAPI::IsRGBAEqual(colorBrush, textField.backgroundColor)) {
                                        uxEvent->Set();
                                    }
                                });

            LOG_INFO("set background to red");
            textField.backgroundColor = [UIColor redColor];
        });
        EXPECT_TRUE_MSG(uxEvent->Wait(2), "FAILED: Waiting for property changed event state timed out!");
        uxEvent->Reset();
        xamlSubscriber->Reset();

        dispatch_sync(dispatch_get_main_queue(), ^{
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::Control::BackgroundProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    // Validation
                                    auto colorBrush = textBox.Background().as<Media::SolidColorBrush>();
                                    if (UXTestAPI::IsRGBAEqual(colorBrush, textField.backgroundColor)) {
                                        uxEvent->Set();
                                    }
                                });

            LOG_INFO("set background to blue");
            textField.backgroundColor = [UIColor blueColor];
        });
        EXPECT_TRUE_MSG(uxEvent->Wait(2), "FAILED: Waiting for property changed event state timed out!");
        uxEvent->Reset();
        xamlSubscriber->Reset();

        dispatch_sync(dispatch_get_main_queue(), ^{
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);

            // Register RAII event subscription handler
            xamlSubscriber->Set(textBox,
                                Controls::Control::BackgroundProperty(),
                                ^(const DependencyObject& sender, const DependencyProperty& dp) {
                                    // Validation
                                    auto colorBrush = textBox.Background().as<Media::SolidColorBrush>();
                                    if (UXTestAPI::IsRGBAEqual(colorBrush, textField.backgroundColor)) {
                                        uxEvent->Set();
                                    }
                                });

            LOG_INFO("set background to Green");
            textField.backgroundColor = [UIColor greenColor];
        });
    }

    TEST_METHOD(UITextField_VerifyEditingState) {
        // verify UITextField Editing state
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            EXPECT_TRUE([textField becomeFirstResponder]);
            EXPECT_TRUE(textField.editing);
            EXPECT_TRUE([textField resignFirstResponder]);
            EXPECT_TRUE(!textField.editing);
        });
    }

    TEST_METHOD(UITextField_VerifyBorderStyle) {
        // verify setting UITextField borderStyle is reflected on backing xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element, which is Grid contains TextBox or passwordBox
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            // setting borerstyle to No border
            textField.borderStyle = UITextBorderStyleNone;
            Thickness actualThickness = textBox.BorderThickness();
            LOG_INFO("Actual border width top=%f, left=%f, bottom=%f, right=%f",
                     actualThickness.Top,
                     actualThickness.Left,
                     actualThickness.Bottom,
                     actualThickness.Right);

            Thickness expectedThickness = ThicknessHelper::FromUniformLength(0.0f);
            EXPECT_TRUE(actualThickness.Left == expectedThickness.Left && actualThickness.Top == expectedThickness.Top &&
                        actualThickness.Bottom == expectedThickness.Bottom && actualThickness.Right == expectedThickness.Right);

            textField.borderStyle = UITextBorderStyleLine;
            actualThickness = textBox.BorderThickness();
            LOG_INFO("Actual border width top=%f, left=%f, bottom=%f, right=%f",
                     actualThickness.Top,
                     actualThickness.Left,
                     actualThickness.Bottom,
                     actualThickness.Right);

            expectedThickness = ThicknessHelper::FromUniformLength(1.0f);
            EXPECT_TRUE(actualThickness.Left == expectedThickness.Left && actualThickness.Top == expectedThickness.Top &&
                        actualThickness.Bottom == expectedThickness.Bottom && actualThickness.Right == expectedThickness.Right);

        });
    }

    TEST_METHOD(UITextField_VerifyKeyboardType) {
        // verify setting UITextField keyboardType is reflected on backing xaml element
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // get the backing xaml element, which is Grid contains TextBox or passwordBox
            auto grid = [textField _winrtXamlElement].as<Controls::Grid>();
            Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(grid)));
            auto textBox = objcwinrt::from_insp<Controls::TextBox>(inspectable);
            EXPECT_TRUE(textBox);

            // verify default keyboard type
            EXPECT_TRUE(textField.keyboardType == UIKeyboardTypeDefault);

            // set keyboardtype to UIKeyboardTypeURL
            textField.keyboardType = UIKeyboardTypeURL;
            EXPECT_TRUE(textBox.InputScope().Names().GetAt(0).NameValue() == Input::InputScopeNameValue::Url);

            // set keyboardtype to UIKeyboardTypeNumberPad
            textField.keyboardType = UIKeyboardTypeNumberPad;
            EXPECT_TRUE(textBox.InputScope().Names().GetAt(0).NameValue() == Input::InputScopeNameValue::Digits);

            // set keyboardtype to UIKeyboardTypePhonePad
            textField.keyboardType = UIKeyboardTypePhonePad;
            EXPECT_TRUE(textBox.InputScope().Names().GetAt(0).NameValue() == Input::InputScopeNameValue::TelephoneNumber);

            // set keyboardtype to UIKeyboardTypeDecimalPad
            textField.keyboardType = UIKeyboardTypeDecimalPad;
            EXPECT_TRUE(textBox.InputScope().Names().GetAt(0).NameValue() == Input::InputScopeNameValue::Number);
        });
    }

    TEST_METHOD(UITextField_VerifyFontSize) {
        StrongId<UITextFieldViewController2> textFieldlVC;
        textFieldlVC.attach([[UITextFieldViewController2 alloc] init]);
        UXTestAPI::ViewControllerPresenter testHelper(textFieldlVC, 2);

        UITextField* textField = [textFieldlVC textField];

        dispatch_sync(dispatch_get_main_queue(), ^{
            // change font size and verify label font has changed
            textField.font = [textField.font fontWithSize:100];
            ASSERT_TRUE([textField.font pointSize] == 100);

            // set adjust font size to be TRUE, verify font size didn't change
            [textField setAdjustsFontSizeToFitWidth:YES];
            ASSERT_TRUE([textField.font pointSize] == 100);

            // turn off auto-fit and change font size to be very small
            [textField setAdjustsFontSizeToFitWidth:NO];
            textField.font = [textField.font fontWithSize:1];

            // verify font didn't scale up when turn on autofit again
            [textField setAdjustsFontSizeToFitWidth:YES];
            ASSERT_TRUE([textField.font pointSize] == 1);
        });
    }
};