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
    std::wstring writableFolder = EbrGetWritableFolder();
    IwSetWritableFolder(L"d:\\temp");

    CPathMapper mapper1("c:/users/winobjc-bot");
    EXPECT_EQ_MSG(0, wcscmp(mapper1, L"c:\\users\\winobjc-bot"), "%S", (const wchar_t*)mapper1);

    CPathMapper mapper2("~/winobjc-bot");
    EXPECT_EQ_MSG(0, wcscmp(mapper2, L".\\home\\winobjc-bot"), "%S", (const wchar_t*)mapper2);

    CPathMapper mapper3("Documents\\mydocuments/subfolder/.././");
    EXPECT_EQ_MSG(0, wcscmp(mapper3, L"d:\\temp\\Documents\\mydocuments"), "%S", (const wchar_t*)mapper3);

    CPathMapper mapper4("");
    EXPECT_EQ_MSG(0, wcscmp(mapper4, L"."), "%S", (const wchar_t*)mapper4);

    CPathMapper mapper5("src");
    EXPECT_EQ_MSG(0, wcscmp(mapper5, L".\\src"), "%S", (const wchar_t*)mapper5);

    CPathMapper mapper6("c:/src/");
    EXPECT_EQ_MSG(0, wcscmp(mapper6, L"c:\\src"), "%S", (const wchar_t*)mapper6);

    CPathMapper mapper7("/c:/src/");
    EXPECT_EQ_MSG(0, wcscmp(mapper7, L"c:\\src"), "%S", (const wchar_t*)mapper7);

    CPathMapper mapper8("X:/src/");
    EXPECT_EQ_MSG(0, wcscmp(mapper8, L"X:\\src"), "%S", (const wchar_t*)mapper8);

    CPathMapper mapper9("/Documents/src/");
    EXPECT_EQ_MSG(0, wcscmp(mapper9, L"d:\\temp\\Documents\\src"), "%S", (const wchar_t*)mapper9);

    CPathMapper mapper10("/Documents/./");
    EXPECT_EQ_MSG(0, wcscmp(mapper10, L"d:\\temp\\Documents"), "%S", (const wchar_t*)mapper10);

    CPathMapper mapper11("/Cache/test/.");
    EXPECT_EQ_MSG(0, wcscmp(mapper11, L"d:\\temp\\cache\\test"), "%S", (const wchar_t*)mapper11);

    CPathMapper mapper12("/library");
    EXPECT_EQ_MSG(0, wcscmp(mapper12, L"d:\\temp\\Library"), "%S", (const wchar_t*)mapper12);

    CPathMapper mapper13("/AppSupport/././");
    EXPECT_EQ_MSG(0, wcscmp(mapper13, L"d:\\temp\\AppSupport"), "%S", (const wchar_t*)mapper13);

    CPathMapper mapper14("tmp");
    EXPECT_EQ_MSG(0, wcscmp(mapper14, L"d:\\temp\\tmp"), "%S", (const wchar_t*)mapper14);

    CPathMapper mapper15("/shared");
    EXPECT_EQ_MSG(0, wcscmp(mapper15, L"d:\\temp\\shared"), "%S", (const wchar_t*)mapper15);

    CPathMapper mapper16("/AppSupport/.\\?/");
    EXPECT_EQ_MSG(0, wcscmp(mapper16, L"d:\\temp\\AppSupport\\+"), "%S", (const wchar_t*)mapper16);

    IwSetWritableFolder(writableFolder.c_str());
}

TEST(PathMapper, RelativePathTests) {
    CPathMapper mapper1("/..");
    EXPECT_EQ_MSG(0, wcscmp(mapper1, L"."), "%S", (const wchar_t*)mapper1);

    CPathMapper mapper2("/./..");
    EXPECT_EQ_MSG(0, wcscmp(mapper2, L"."), "%S", (const wchar_t*)mapper2);

    CPathMapper mapper3("/./src/../../..");
    // this test was failing before, it is a bug
    EXPECT_EQ_MSG(0, wcscmp(mapper3, L"."), "%S", (const wchar_t*)mapper3);

    CPathMapper mapper4("/src/../..");
    // this test was failing before, it is a bug
    EXPECT_EQ_MSG(0, wcscmp(mapper4, L"."), "%S", (const wchar_t*)mapper4);

    CPathMapper mapper5("/./src/../src/");
    // fails, returns //src
    EXPECT_EQ_MSG(0, wcscmp(mapper5, L".\\src"), "%S", (const wchar_t*)mapper5);

    CPathMapper mapper6("/./src/winobjc/..");
    EXPECT_EQ_MSG(0, wcscmp(mapper6, L".\\src"), "%S", (const wchar_t*)mapper6);

    CPathMapper mapper7("/./././src/winobjc/../winobjc/.././../src/winobjc/..");
    // fails, returns //src
    EXPECT_EQ_MSG(0, wcscmp(mapper7, L".\\src"), "%S", (const wchar_t*)mapper7);
}
