//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// Windows-only:
//      THROW_NS_HR
//      HRESULT_FROM_WIN32
//      anything else involving an hresult

#include <TestFramework.h>

#import <Foundation/Foundation.h>
#include "ErrorHandling.h"

ARM_DISABLED_TEST(ErrorHandling, NormalizeExceptions) {
    const char message1[] = "Message1";
    const char message2[] = "Message2";
    const HRESULT hr = HRESULT_FROM_WIN32(ERROR_OUT_OF_PAPER);

    bool caught = false;
    try {
        try {
            THROW_NS_HR_MSG(hr, message1);
        }
        CATCH_THROW_NORMALIZED_MSG(message2)
    } catch (NSException* e) {
        ASSERT_STREQ([[e reason] UTF8String], message1);
        ASSERT_EQ([e _hresult], hr);
        caught = true;
    }
    ASSERT_TRUE(caught);

    caught = false;
    try {
        try {
            THROW_NS_HR_MSG(hr, message1);
        }
        CATCH_THROW_NORMALIZED()
    } catch (NSException* e) {
        ASSERT_STREQ([[e reason] UTF8String], message1);
        ASSERT_EQ([e _hresult], hr);
        caught = true;
    }
    ASSERT_TRUE(caught);

    caught = false;
    try {
        try {
            THROW_HR_MSG(hr, message1);
        }
        CATCH_THROW_NORMALIZED_MSG(message2)
    } catch (NSException* e) {
        ASSERT_STREQ([[e reason] UTF8String], message1);
        ASSERT_EQ([e _hresult], hr);
        caught = true;
    }
    ASSERT_TRUE(caught);

    caught = false;
    try {
        try {
            THROW_HR_MSG(hr, message1);
        }
        CATCH_THROW_NORMALIZED()
    } catch (NSException* e) {
        ASSERT_STREQ([[e reason] UTF8String], message1);
        ASSERT_EQ([e _hresult], hr);
        caught = true;
    }
    ASSERT_TRUE(caught);
}