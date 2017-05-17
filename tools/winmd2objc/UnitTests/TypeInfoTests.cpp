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

#include <stdafx.h>
#include <gtest/gtest.h>
#include <TypeInfo.h>

TEST(TypeInfo, NamespaceMangleTest) {
    // Test the builtin overrides, which should eventually be scriptable:
    ASSERT_EQ(L"WSSomeClass", mapNamespacedType(L"Windows.ApplicationModel.Store.SomeClass"));
    ASSERT_EQ(L"WXSomeUiFeature", mapNamespacedType(L"Windows.UI.Xaml.SomeUiFeature"));
    ASSERT_EQ(L"WXCSomeWidget", mapNamespacedType(L"Windows.UI.Xaml.Controls.SomeWidget"));

    ASSERT_EQ(L"FBBNBBSomeClassName", mapNamespacedType(L"Foo.Bar.Baz.Narf.Buzz.Blech.SomeClassName"));
}
