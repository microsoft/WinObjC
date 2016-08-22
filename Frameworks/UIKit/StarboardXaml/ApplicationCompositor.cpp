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
// clang-format does not play well with C++/CX
// clang-format off

#include "ApplicationMain.h"
#include "StringHelpers.h"
#include "ApplicationCompositor.h"
#include "ApplicationMain.h"
#include <MainDispatcher.h>

#include <assert.h>
#include <string>

using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::System::Threading;

void InitializeApp() {
    // Only init once.
    // No lock needed as this is only called from the UI thread.
    static bool initialized = false;
    if (initialized) {
        return;
    }
    initialized = true;

    // Set our writable and temp folders
    char writableFolder[2048];
    size_t outLen;
    auto pathData = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
    wcstombs_s(&outLen, writableFolder, pathData->Data(), sizeof(writableFolder) - 1);
    EbrSetWritableFolder(writableFolder);

    auto tempPathData = Windows::Storage::ApplicationData::Current->TemporaryFolder->Path;
    wcstombs_s(&outLen, writableFolder, tempPathData->Data(), sizeof(writableFolder) - 1);
    SetTemporaryFolder(writableFolder);

    // Set the waiter routine for the main runloop to yield
    SetupMainRunLoopTimedMultipleWaiter();
}

extern "C" void RunApplicationMain(Platform::String^ principalClassName,
                                   Platform::String^ delegateClassName,
                                   float windowWidth,
                                   float windowHeight,
                                   ActivationType activationType,
                                   Platform::Object^ activationArg) {

    // Perform initialization
    InitializeApp();

    // Kick off iOS application main startup
    // Convert Object^ to IInspectable* so it can be passed into Objective C and there converted to its projection
    ApplicationMainStart(
            Strings::WideToNarrow(principalClassName->Data()).c_str(),
            Strings::WideToNarrow(delegateClassName->Data()).c_str(),
            windowWidth,
            windowHeight,
            activationType,
            reinterpret_cast<IInspectable*>(activationArg));
}

// clang-format off
