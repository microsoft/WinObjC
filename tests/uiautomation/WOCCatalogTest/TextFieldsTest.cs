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

using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace WOCCatalogTest
{
    [TestClass]
    public class TextFieldsTest
    {
        [ClassInitialize]
        public static void Setup(TestContext context)
        {
            TestCommon.LaunchApp();

            // TODO: Ensure WOCCatalog is not running

            // Find the text fields list entry
            var textFields = TestCommon.WOCCatalogSession.FindElementsByName("TextFields");
            Assert.IsTrue(textFields.Count > 0);
            TestCommon.WOCCatalogSession.Mouse.ContextClick(textFields[0].Coordinates);
        }

        [ClassCleanup]
        public static void TearDown()
        {
            TestCommon.ReturnToMainPage();
            TestCommon.QuitApp();
        }

        [TestMethod]
        public void TextFields_Password()
        {
            // Action
            var passwordTextField = TestCommon.WOCCatalogSession.FindElementByAccessibilityId("textField_0");

            var newText = "MySecretPassword";
            passwordTextField.SendKeys(newText);

            // Verify
            try
            {
                var currentHiddenText = passwordTextField.Text;
                Assert.AreEqual(newText, currentHiddenText);
            }
            catch (Exception ex)
            {
                // Verify that the text of a password box generated an exception with this result
                Assert.AreEqual(ex.HResult, -2146233088);
            }
        }

        [TestMethod]
        public void TextFields_BlueBackground_RightAligned()
        {
            // Action
            var blueTextField = TestCommon.WOCCatalogSession.FindElementsByName("blue background, right aligned");

            // Verify
            Assert.IsTrue(blueTextField.Count > 0);
        }

        [TestMethod]
        public void TextFields_RedText_CenteredAligned()
        {
            // Action
            var redTextField = TestCommon.WOCCatalogSession.FindElementsByName("red text, alignment center");

            // Verify
            Assert.IsTrue(redTextField.Count > 0);
        }

        [TestMethod]
        public void TextFields_RejectFocus()
        {
            // Action
            var readonlyTextField = TestCommon.WOCCatalogSession.FindElementsByName("This control reject focus");

            // Verify
            Assert.IsTrue(readonlyTextField.Count > 0);

            var originalText = readonlyTextField[0].Text;
            var newText = "This text should be rejected";
            readonlyTextField[0].SendKeys(newText);

            // Verify
            Assert.AreSame(readonlyTextField[0].Text, originalText);
        }

        [TestMethod]
        public void TextFields_Url()
        {
            // Action
            var urlTextField = TestCommon.WOCCatalogSession.FindElementsByName("type in URL");

            // Verify
            Assert.IsTrue(urlTextField.Count > 0);

            var originalText = urlTextField[0].Text;
            var newText = "http://github.com/Microsoft/WinObjC";
            urlTextField[0].SendKeys(newText);

            // Verify
            Assert.AreNotSame(urlTextField[0].Text, originalText);
            Assert.AreEqual(urlTextField[0].Text, newText);
        }

        [TestMethod]
        public void TextFields_NameAndPhone()
        {
            // Action
            var nameAndPhoneTextField = TestCommon.WOCCatalogSession.FindElementsByName("type in your Name and Phone");

            // Verify
            Assert.IsTrue(nameAndPhoneTextField.Count > 0);

            var originalText = nameAndPhoneTextField[0].Text;
            var newText = "Jenny McCool 425-867-9305";
            nameAndPhoneTextField[0].SendKeys(newText);

            // Verify
            Assert.AreNotSame(nameAndPhoneTextField[0].Text, originalText);
        }

        [TestMethod]
        public void TextFields_EmailAddress()
        {
            // Action
            var emailTextField = TestCommon.WOCCatalogSession.FindElementsByName("type in your email address");
            Assert.IsTrue(emailTextField.Count > 1);

            var placeholderText = emailTextField[1].Text;
            var originalText = emailTextField[0].Text;
            var newText = "someemail@bogus.net";
            emailTextField[0].SendKeys(newText);

            // Verify
            Assert.AreNotSame(emailTextField[0].Text, placeholderText);
            Assert.AreNotSame(emailTextField[0].Text, originalText);
        }

        [TestMethod]
        public void TextFields_Decimal()
        {
            // Action
            var decimalTextField = TestCommon.WOCCatalogSession.FindElementsByName("Decimal");
            Assert.IsTrue(decimalTextField.Count > 1);

            var originalText = decimalTextField[0].Text;
            var newText = "3.1415926535";
            decimalTextField[0].SendKeys(newText);

            // Verify
            Assert.AreNotSame(decimalTextField[0].Text, originalText);
        }
    }
}
