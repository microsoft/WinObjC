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

#include <windows.h>
#include <TestFramework.h>
#include <FrameworkTestUtil.h>

#define SCOPE_UNINITIALIZE(hResult) \
    \
_SCOPE_GUARD([hResult](void*) {     \
        if (SUCCEEDED(hResult)) {   \
            ::CoUninitialize();     \
        }                           \
    })

int main(int argc, char** argv) {
// ::CoInitialize, Uninitialize, don't exist on OSX, aren't needed
#ifdef WIN32
    // Initialize COM for all of the tests
    HRESULT hResult = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
    SCOPE_UNINITIALIZE(hResult);

    testing::InitGoogleTest(&argc, argv);
    LOG_INFO("Starting unit tests...");
    auto result = RUN_ALL_TESTS();
#else
    testing::InitGoogleTest(&argc, argv);
    printf("Starting unit tests...\n");
    auto result = RUN_ALL_TESTS();

#endif

    return result;
}