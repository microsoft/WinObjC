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

#include <TestFramework.h>

#include <windows.h>
#include "Starboard.h"

namespace {
HRESULT catchReturnHrTest() {
    try {
        THROW_NS_HR(E_NOTIMPL);
    }
    CATCH_RETURN();
    return S_OK;
}
}

TEST(Core, ErrorHandling) {
    NSError* error = nil;

    try {
        THROW_NS_HR(E_NOTIMPL);
    }
    CATCH_POPULATE_NSERROR(&error);

    ASSERT_EQ_MSG(error.code, E_NOTIMPL, "NSError code did not percolate through from exception");

    @try {
        try {
            THROW_NS_HR(E_ABORT);
        }
        CATCH_THROW_NSEXCEPTION();
    } @
    CATCH_POPULATE_NSERROR(&error);

    ASSERT_EQ_MSG(error.code, E_ABORT, "NSException did not correctly sift through CATCH_THROW_NSEXCEPTION");

    ASSERT_EQ_MSG(catchReturnHrTest(), E_NOTIMPL, "CATCH_RETURN from THROW_HS_NR inconsistent");

    try {
        try {
            THROW_HR(E_NOTIMPL);
        }
        CATCH_THROW_NSEXCEPTION();
    }
    CATCH_POPULATE_NSERROR(&error);
    ASSERT_EQ_MSG(error.code, E_NOTIMPL, "Exception renormalization to NSExceptions not working correctly!");

    NSString* actualExceptionName = @"";
    @try {
        try {
            THROW_NS_HR(E_INVALIDARG);
        }
        CATCH_THROW_NSEXCEPTION();
    } @catch (NSException* exception) {
        actualExceptionName = exception.name;
    }

    ASSERT_OBJCEQ(actualExceptionName, NSInvalidArgumentException);
}