#include "../lib/TypeInfo.h"
#include "stdafx.h"
#include <gtest/gtest.h>

TEST(TypeInfo, NamespaceMangleTest) {
    // Test the builtin overrides, which should eventually be scriptable:
    ASSERT_EQ(L"WSSomeClass", mapNamespacedType(L"Windows.ApplicationModel.Store.SomeClass"));
    ASSERT_EQ(L"WXSomeUiFeature", mapNamespacedType(L"Windows.UI.Xaml.SomeUiFeature"));
    ASSERT_EQ(L"WXCSomeWidget", mapNamespacedType(L"Windows.UI.Xaml.Controls.SomeWidget"));

    ASSERT_EQ(L"FBBNBBSomeClassName", mapNamespacedType(L"Foo.Bar.Baz.Narf.Buzz.Blech.SomeClassName"));
}
