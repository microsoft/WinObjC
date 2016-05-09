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

// These tests are in here pending more Projections tests, warranting a separate project for them.

#include <UWP/WindowsGraphicsImaging.h>
#include <UWP/WindowsDataXmlDom.h>
#include <UWP/WindowsUINotifications.h>

TEST(Projections, BasicTests) {
    // This used to crash so keep this as a regression test:
    ASSERT_TRUE_MSG([WGIBitmapDecoder jpegDecoderId] != nil, "jpegDecoderId must return a non-nil value!");

    WDXDXmlDocument* doc = [WUNBadgeUpdateManager getTemplateContent:WUNBadgeTemplateTypeBadgeNumber];
    WDXDXmlNodeList* badges = [doc getElementsByTagName:@"badge"];
    ASSERT_TRUE_MSG(badges != nil, "Could not find our element!");

    id badge = [badges objectAtIndex:0];
    ASSERT_TRUE_MSG(rt_dynamic_cast<WDXDXmlElement>(badge) != nil, "Our XML element isn't an element!");
}

// TODO 7143070:
// Projections is depending on an older version of Foundation.dll where NSConstantString was named
// CFConstantString. Despite the new version exporting an alias to CFConstantString, it appears that
// the old stamped in string from here cannot be used interchanagably.
// Re-enable test when projections no longer uses the old name.
TEST(Projections, DISABLED_BadCastTests) {
    WDXDXmlDocument* doc = [WUNBadgeUpdateManager getTemplateContent:WUNBadgeTemplateTypeBadgeNumber];
    WDXDXmlNodeList* badges = [doc getElementsByTagName:@"badge"];
    ASSERT_TRUE_MSG(badges != nil, "Could not find our element!");

    id badge = [badges objectAtIndex:0];

    // Make sure invalid casts throw:
    bool exceptionThrown = false;
    try {
        rt_dynamic_cast<WDXDXmlDocument>(badge);
    } catch (NSException* e) {
        exceptionThrown = true;
    }
    ASSERT_TRUE_MSG(exceptionThrown, "Bad cast didn't throw exception!");
}
