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

// Windows-only:
//      THROW_NS_HR, CATCH_POPULATE_NSERROR

#include <TestFramework.h>
#include <Foundation/Foundation.h>
#include <ErrorHandling.h>

ARM_DISABLED_TEST(NSError, NSErrorCatchPopulate) {
    NSError* error;
    try {
        THROW_NS_HR(E_INVALIDARG);
    }
    CATCH_POPULATE_NSERROR(&error);
    LOG_INFO(@"The error is %@", [error description]);
}