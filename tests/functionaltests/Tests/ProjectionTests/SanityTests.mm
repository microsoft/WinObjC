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

#import <Starboard/SmartTypes.h>
#import <Foundation/Foundation.h>
#import <UWP/WindowsUIXamlInterop.h>

// This file has ARC disabled as for some reason ARC 
// cannot be used with ASSERT_OBJCEQ_MSG macro.
TEST(Projection, HStringTest) {
    LOG_INFO("Projection HString Sanity Test: ");
    StrongId<WUXITypeName> typeName = [WUXITypeName new];
    NSString* expectedString = @"Test";
    [typeName setName:expectedString];
    ASSERT_OBJCEQ_MSG(expectedString, [typeName name], "FAILED: HString mismatch\n");
}