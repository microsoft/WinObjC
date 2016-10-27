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

using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using OpenQA.Selenium.Appium;
using OpenQA.Selenium.Appium.iOS; // Temporary placeholder until Windows namespace exists
using OpenQA.Selenium.Remote;

namespace XAMLCatalogTest
{
    class TestCommon
    {
        public static Uri RemoteHarnessUrl = new Uri("http://127.0.0.1:4723");
        public static IOSDriver<IOSElement> XAMLCatalogSession; // Temporary placeholder until Windows namespace exists

        static public void LaunchApp()
        {
            if (XAMLCatalogSession != null)
            {
                XAMLCatalogSession.Quit();
            }

            // Launch the XAMLCatalog app
            DesiredCapabilities appCapabilities = new DesiredCapabilities();
            appCapabilities.SetCapability("app", "0b75acd0-df3e-4edb-bebc-847b0ca4bffb_vddemm0nz1wmr!App");

            XAMLCatalogSession = new IOSDriver<IOSElement>(RemoteHarnessUrl, appCapabilities);
            Assert.IsNotNull(XAMLCatalogSession);

            XAMLCatalogSession.Manage().Timeouts().ImplicitlyWait(TimeSpan.FromSeconds(2));
        }

        static public void ReturnToMainPage()
        {
            // Try to return to main page in case application is started in nested view
            try
            {
                AppiumWebElement backButton = null;
                do
                {
                    backButton = XAMLCatalogSession.FindElementByAccessibilityId("Back");
                    backButton.Click();
                }
                while (backButton != null);
            }
            catch {}
        }

        static public void QuitApp()
        {
            if (XAMLCatalogSession != null)
            {
                // Appium has CloseApp() API  but it's not part of the W3C Selenium Protocol. Quit() is compliant and it will
                // close the active application and discard the session.
                XAMLCatalogSession.Quit();
            }
        }
    }
}
