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
#include "PathMapper.h"
#include "EbrPlatform.h"

TEST(PathMapper, pathMapper) {
    std::wstring writableFolder = IwGetWritableFolder();

    CPathMapper mapper1("c:/users/winobjc-bot");
    EXPECT_STREQ(mapper1, L"c:\\users\\winobjc-bot");

    CPathMapper mapper2("~/winobjc-bot");
    EXPECT_STREQ(mapper2, L".\\home\\winobjc-bot");

    CPathMapper mapper3("Documents\\mydocuments/subfolder/.././");
    EXPECT_STREQ(mapper3, (writableFolder + L"\\Documents\\mydocuments").c_str());

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
    EXPECT_STREQ(mapper9, (writableFolder + L"\\Documents\\src").c_str());

    CPathMapper mapper10("/Documents/./");
    EXPECT_STREQ(mapper10, (writableFolder + L"\\Documents").c_str());

    CPathMapper mapper11("/Cache/test/.");
    EXPECT_STREQ(mapper11, (writableFolder + L"\\cache\\test").c_str());

    CPathMapper mapper12("/library");
    EXPECT_STREQ(mapper12, (writableFolder + L"\\Library").c_str());

    CPathMapper mapper13("/AppSupport/././");
    EXPECT_STREQ(mapper13, (writableFolder + L"\\AppSupport").c_str());

    CPathMapper mapper14("tmp");
    EXPECT_STREQ(mapper14, (writableFolder + L"\\tmp").c_str());

    CPathMapper mapper15("/shared");
    EXPECT_STREQ(mapper15, (writableFolder + L"\\shared").c_str());

    CPathMapper mapper16("/AppSupport/.\\?/");
    EXPECT_STREQ(mapper16, (writableFolder + L"\\AppSupport\\+").c_str());
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
