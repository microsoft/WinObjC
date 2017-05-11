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

#include "stdafx.h"
#include <gtest/gtest.h>
#include <CodeGenModel.h>

using namespace std;

template <typename T>
std::wstring makeStr(const T& val) {
    wstringstream ss;
    ss << val;
    return ss.str();
}

struct TestStruct {
    int testData;
    TestStruct(int testData) : testData(testData) {
    }
};

template <>
std::wstring makeStr(const TestStruct& val) {
    return makeStr(val.testData);
}

TEST(Helpers, SeparationAdder) {
    // Standard use case:
    vector<int> testData = { 1, 2, 3 };
    ASSERT_EQ(L"1, 2, 3", addSeparators(testData, &makeStr<int>));
    ASSERT_EQ(L"1 2 3", addSeparators(testData, &makeStr<int>, L" "));
    ASSERT_EQ(L"123", addSeparators(testData, &makeStr<int>, L""));

    // Test empty strings:
    ASSERT_EQ(L"", addSeparators(vector<int>(), &makeStr<int>, L""));
    ASSERT_EQ(L"", addSeparators(vector<int>(), &makeStr<int>, L","));

    // Test single element:
    vector<int> single = { 5 };
    ASSERT_EQ(L"5", addSeparators(single, &makeStr<int>, L""));
    ASSERT_EQ(L"5", addSeparators(single, &makeStr<int>, L","));

    vector<wstring> someStrings = { L"abc", L"def" };
    ASSERT_EQ(L"abc, def", addSeparators(someStrings, identity<wstring>()));

    vector<TestStruct> someStructs = { { 1 }, { 2 }, { 3 } };
    ASSERT_EQ(L"1, 2, 3", addSeparators(someStructs, &makeStr<TestStruct>));

    vector<int> bigData = { 1, 2, 3, 4, 5, 6 };
    ASSERT_EQ(L"2,3,4,5,6", addSeparators(bigData, &makeStr<int>, L",", [](int num) { return num != 1; }));
    ASSERT_EQ(L"2,4,6", addSeparators(bigData, &makeStr<int>, L",", [](int num) { return num % 2 == 0; }));
    ASSERT_EQ(L"", addSeparators(bigData, &makeStr<int>, L",", [](int num) { return false; }));
}

TEST(MethodSig, Simple) {
    ASSERT_EQ(L"+ (void)f", ObjC::MethodSig(true, L"void", L"f").emit());
    ASSERT_EQ(L"- (void)f", ObjC::MethodSig(false, L"void", L"f").emit());

    vector<ObjC::MethodSig::NameTypeVar> empty;
    ASSERT_THROW(ObjC::MethodSig(true, L"void", empty), invalid_argument);

    ASSERT_EQ(L"- (newts)name:(type)var", ObjC::MethodSig(false, L"newts", { { L"name", L"type", L"var" } }).emit());
    ASSERT_EQ(L"- (newts)name:(type)var name2:(type2)var2",
              ObjC::MethodSig(false, L"newts", { { L"name", L"type", L"var" }, { L"name2", L"type2", L"var2" } }).emit());
}
