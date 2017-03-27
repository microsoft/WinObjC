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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/DWriteWrapper.h>

TEST(DWriteWrapper, FontToFamilyName) {
    EXPECT_OBJCEQ(@"Arial", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Arial"), nullptr));
    EXPECT_OBJCEQ(@"Arial", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Arial Italic"), nullptr));
    EXPECT_OBJCEQ(@"Arial", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Arial Bold"), nullptr));
    EXPECT_OBJCEQ(@"Arial", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Arial Bold Italic"), nullptr));
    EXPECT_OBJCEQ(@"Arial", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Arial Black"), nullptr));
    EXPECT_OBJCEQ(@"Times New Roman", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Times New Roman"), nullptr));
    EXPECT_OBJCEQ(@"Times New Roman", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Times New Roman Italic"), nullptr));
    EXPECT_OBJCEQ(@"Times New Roman", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Times New Roman Bold"), nullptr));
    EXPECT_OBJCEQ(@"Times New Roman", (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("Times New Roman Bold Italic"), nullptr));
    EXPECT_OBJCEQ(nil, (id)_DWriteGetXamlCompatibleFamilyName(CFSTR("NotAFont"), nullptr));
}
