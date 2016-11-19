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
    public class SliderTest
    {
        [ClassInitialize]
        public static void Setup(TestContext context)
        {
            TestCommon.LaunchApp();

            // Find the text fields list entry
            var sliders = TestCommon.XAMLCatalogSession.FindElementsByName("UISlider");
            Assert.IsTrue(sliders.Count > 0);

            TestCommon.XAMLCatalogSession.Mouse.ContextClick(sliders[0].Coordinates);
        }

        [ClassCleanup]
        public static void TearDown()
        {
            TestCommon.ReturnToMainPage();
            TestCommon.QuitApp();
        }

        [Ignore]
        [TestMethod]
        public void Slider_Simple()
        {
            // Action
            var sliderSimple = TestCommon.XAMLCatalogSession.FindElementByAccessibilityId("slider_Simple"); // simpleSlider

            // TODO: Change via UISlider API; verify via XAML backing element - GetAttribute() support needed
            sliderSimple.SetImmediateValue("50%");
            Assert.AreEqual("0%", sliderSimple.GetAttribute("value"));
        }
    }
}
