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

bool fixPath(char* outPath, const char* relativePath);
bool convertPath(char* filePath, const char* relativePath);

TEST(PathMapper, fixPathNegativeTests) {
    char outPath[4096];
    EXPECT_FALSE(fixPath(outPath, "must start with /"));
    EXPECT_EQ_MSG(outPath[0], 0, outPath);

    EXPECT_FALSE(fixPath(outPath, "/.."));
    EXPECT_EQ_MSG(outPath[0], 0, outPath);

    EXPECT_FALSE(fixPath(outPath, "/./.."));
    EXPECT_EQ_MSG(outPath[0], 0, outPath);

    EXPECT_FALSE(fixPath(outPath, "/./src/../../.."));
    // this test was failing before, it is a bug
    EXPECT_EQ_MSG(outPath[0], 0, outPath);

    EXPECT_FALSE(fixPath(outPath, "/src/../.."));
    // this test was failing before, it is a bug
    EXPECT_EQ_MSG(outPath[0], 0, outPath);
}

TEST(PathMapper, fixPathPositiveTests) {
    char outPath[4096];
    EXPECT_TRUE(fixPath(outPath, "/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "//src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "///src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "/./src"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "/d:/src"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/d:/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "/./src/../src/"));
    // fails, returns //src
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "/./src/winobjc/.."));
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);

    EXPECT_TRUE(fixPath(outPath, "/./././src/winobjc/../winobjc/.././../src/winobjc/.."));
    // fails, returns //src
    EXPECT_EQ_MSG(0, strcmp(outPath, "/src"), outPath);
}

extern "C" void EbrSetWritableFolder(const char*);

TEST(PathMapper, mapPathPositiveTests) {
    EbrSetWritableFolder("d:\\temp");

    char outPath[4096];
    EXPECT_TRUE(convertPath(outPath, "/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, ".\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, ""));
    EXPECT_EQ_MSG(0, strcmp(outPath, "."), outPath);

    EXPECT_TRUE(convertPath(outPath, "src"));
    EXPECT_EQ_MSG(0, strcmp(outPath, ".\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, "c:/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "c:\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/c:/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "c:\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/X:/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "X:\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/Documents/src/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\Documents\\src"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/Documents/./"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\Documents"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/Cache/test/."));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\cache\\test"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/library"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\Library"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/AppSupport/././"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\AppSupport"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/tmp"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\tmp"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/shared"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\shared"), outPath);

    EXPECT_TRUE(convertPath(outPath, "/AppSupport/.\\?/"));
    EXPECT_EQ_MSG(0, strcmp(outPath, "d:\\temp\\AppSupport\\+"), outPath);
}

TEST(PathMapper, mapPathNegativeTests) {
    char outPath[4096];

    // first slash must be / slash, is this just an artifact?
    EXPECT_TRUE(convertPath(outPath, "\\AppSupport\\.\\?/"));
    // fails previously
    EXPECT_EQ_MSG(0, strcmp(outPath, ".\\AppSupport\\+"), outPath);
}

TEST(PathMapper, pathMapper) {
    CPathMapper mapper1("c:/users/winobjc-bot");
    EXPECT_EQ_MSG(0, strcmp(mapper1, "c:\\users\\winobjc-bot"), (const char*)mapper1);
    EXPECT_EQ_MSG(0, strcmp(mapper1.fixedPath, "/c:/users/winobjc-bot"), (const char*)mapper1.fixedPath);

    CPathMapper mapper2("~/winobjc-bot");
    EXPECT_EQ_MSG(0, strcmp(mapper2, ".\\home\\winobjc-bot"), (const char*)mapper2);
}
