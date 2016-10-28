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

namespace XAMLCatalogTest
{
    [TestClass]
    public class TextFieldsTest
    {
        [ClassInitialize]
        public static void Setup(TestContext context)
        {
            TestCommon.LaunchApp();

            // Find the text fields list entry
            var textFields = TestCommon.XAMLCatalogSession.FindElementsByName("UITextField");
            Assert.IsTrue(textFields.Count > 0);

            TestCommon.XAMLCatalogSession.Mouse.ContextClick(textFields[0].Coordinates);
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
            var passwordTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_0"); // password

            var newText = "MySecretPassword";
            passwordTextField.SendKeys(newText);

            // Verify
            //var currentHiddenText = passwordTextField[0].Text;
            //Assert.AreNotSame(newText, currentHiddenText);
        }

        [TestMethod]
        public void TextFields_BlueBackground_RightAligned()
        {
            // Action
            var blueTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_1"); // blue background, right aligned

            // Verify
            Assert.IsNotNull(blueTextField);
        }

        [TestMethod]
        public void TextFields_RedText_CenteredAligned()
        {
            // Action
            var redTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_2"); // red text, alignment center

            Assert.IsNotNull(redTextField);
        }

        [TestMethod]
        public void TextFields_RejectFocus()
        {
            // Action
            var readonlyTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_3"); // This control rejects focus

            // Verify
            Assert.IsNotNull(readonlyTextField);

            var originalText = readonlyTextField.Text;
            var newText = "This text should be rejected";
            readonlyTextField.SendKeys(newText);

            // Verify
            Assert.AreSame(readonlyTextField.Text, originalText);
        }

        [TestMethod]
        public void TextFields_Url()
        {
            // Action
            var urlTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_4"); // type in URL

            // Verify
            Assert.IsNotNull(urlTextField);

            var originalText = urlTextField.Text;
            var newText = "http://github.com/Microsoft/WinObjC";
            urlTextField.SendKeys(newText);

            // Verify
            Assert.AreNotSame(urlTextField.Text, originalText);
            Assert.AreEqual(urlTextField.Text, newText);
        }

        [TestMethod]
        public void TextFields_NameAndPhone()
        {
            // Action
            var nameAndPhoneTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_5"); // type in your Name and Phone

            // Verify
            Assert.IsNotNull(nameAndPhoneTextField);

            var originalText = nameAndPhoneTextField.Text;
            var newText = "Jenny McCool 425-867-9305";
            nameAndPhoneTextField.SendKeys(newText);

            // Verify
            Assert.AreNotSame(nameAndPhoneTextField.Text, originalText);
        }

        [TestMethod]
        public void TextFields_EmailAddress()
        {
            // Action
            var emailTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_6"); // type in your email address
            Assert.IsNotNull(emailTextField);

            var originalText = emailTextField.Text;
            var newText = "someemail@bogus.net";
            emailTextField.SendKeys(newText);

            // Verify
            Assert.AreNotSame(emailTextField.Text, originalText);
        }

        [TestMethod]
        public void TextFields_Decimal()
        {
            // Action
            var decimalTextField = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("textField_7"); // Decimal
            Assert.IsNotNull(decimalTextField);

            var originalText = decimalTextField.Text;
            var newText = "3.1415926535";
            decimalTextField.SendKeys(newText);

            // Verify
            Assert.AreNotSame(decimalTextField.Text, originalText);
        }
    }
}
