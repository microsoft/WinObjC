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
#include "pathmapper.h"

extern "C" void IwSetWritableFolder(const wchar_t*);
extern "C" const wchar_t* IwGetWritableFolder();

TEST(PathMapper, pathMapper) {
    std::wstring writableFolder = IwGetWritableFolder();
    IwSetWritableFolder(L"d:\\temp");

    CPathMapper mapper1("c:/users/winobjc-bot");
    EXPECT_STREQ(mapper1, L"c:\\users\\winobjc-bot");

    CPathMapper mapper2("~/winobjc-bot");
    EXPECT_STREQ(mapper2, L".\\home\\winobjc-bot");

    CPathMapper mapper3("Documents\\mydocuments/subfolder/.././");
    EXPECT_STREQ(mapper3, L"d:\\temp\\Documents\\mydocuments");

    CPathMapper mapper4("");
    EXPECT_STREQ(mapper4, L".");

    CPathMapper mapper5("src");
    EXPECT_STREQ(mapper5, L".\\src");

    CPathMapper mapper6("c:/src/");
    EXPECT_STREQ(mapper6, L"c:\\src");

    CPathMapper mapper7("/c:/src/");
    EXPECT_STREQ(mapper7, L"c:\\src");

    CPathMapper mapper8("X:/src/");
    EXPECT_STREQ(mapper8, L"X:\\src");

    CPathMapper mapper9("/Documents/src/");
    EXPECT_STREQ(mapper9, L"d:\\temp\\Documents\\src");

    CPathMapper mapper10("/Documents/./");
    EXPECT_STREQ(mapper10, L"d:\\temp\\Documents");

    CPathMapper mapper11("/Cache/test/.");
    EXPECT_STREQ(mapper11, L"d:\\temp\\cache\\test");

    CPathMapper mapper12("/library");
    EXPECT_STREQ(mapper12, L"d:\\temp\\Library");

    CPathMapper mapper13("/AppSupport/././");
    EXPECT_STREQ(mapper13, L"d:\\temp\\AppSupport");

    CPathMapper mapper14("tmp");
    EXPECT_STREQ(mapper14, L"d:\\temp\\tmp");

    CPathMapper mapper15("/shared");
    EXPECT_STREQ(mapper15, L"d:\\temp\\shared");

    CPathMapper mapper16("/AppSupport/.\\?/");
    EXPECT_STREQ(mapper16, L"d:\\temp\\AppSupport\\+");

    IwSetWritableFolder(writableFolder.c_str());
}

TEST(PathMapper, RelativePathTests) {
    CPathMapper mapper1("/..");
    EXPECT_STREQ(mapper1, L".");

    CPathMapper mapper2("/./..");
    EXPECT_STREQ(mapper2, L".");

    CPathMapper mapper3("/./src/../../..");
    // this test was failing before, it is a bug
    EXPECT_STREQ(mapper3, L".");

    CPathMapper mapper4("/src/../..");
    // this test was failing before, it is a bug
    EXPECT_STREQ(mapper4, L".");

    CPathMapper mapper5("/./src/../src/");
    // fails, returns //src
    EXPECT_STREQ(mapper5, L".\\src");

    CPathMapper mapper6("/./src/winobjc/..");
    EXPECT_STREQ(mapper6, L".\\src");

    CPathMapper mapper7("/./././src/winobjc/../winobjc/.././../src/winobjc/..");
    // fails, returns //src
    EXPECT_STREQ(mapper7, L".\\src");
}
