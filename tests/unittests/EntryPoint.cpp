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

#include <gtest-api.h>

#ifdef WIN32
#include "pch.h"
#include <roapi.h>
#include <WexTestClass.h>
#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.storage.h>

using namespace ABI::Windows::Storage;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;

Wrappers::HString GetAppDataPath() {
    Wrappers::HString toReturn;
    ComPtr<IStorageFolder> folder;
    ComPtr<IApplicationDataStatics> applicationDataStatics;
    ComPtr<IApplicationData> applicationData;
    ComPtr<IStorageItem> storageItem;

    if (FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Storage_ApplicationData).Get(),
                                    &applicationDataStatics))) {
        return toReturn;
    }

    if (FAILED(applicationDataStatics->get_Current(&applicationData))) {
        return toReturn;
    }

    if (FAILED(applicationData->get_LocalFolder(&folder))) {
        return toReturn;
    }

    if (FAILED(folder.As<IStorageItem>(&storageItem))) {
        return toReturn;
    }

    if (FAILED(storageItem->get_Path(toReturn.GetAddressOf()))) {
        return toReturn;
    }

    return toReturn;
}

#endif

#ifdef WIN32
BEGIN_MODULE()
MODULE_PROPERTY(L"RunAs", L"UAP")
MODULE_PROPERTY(L"UAP:AppXManifest", L"Default.AppxManifest.xml")
END_MODULE()

MODULE_SETUP(ModuleSetup) {
    // Initialize GTest framework.
    int _argc = 1;
    char* _argv[] = { "UnitTests" };
    testing::InitGoogleTest(&_argc, _argv);
#else
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
#endif

#ifdef WIN32
    if (FAILED(RoInitialize(RO_INIT_MULTITHREADED))) {
        return FALSE;
    }

    Wrappers::HString path = GetAppDataPath();
    if (path.IsValid()) {
        unsigned int rawLength;
        _wchdir(WindowsGetStringRawBuffer(path.Get(), &rawLength));
    }

    return TRUE;
#else
    auto result = RUN_ALL_TESTS();
    return result;
#endif
}

#ifdef WIN32
MODULE_CLEANUP(ModuleCleanup) {
    RoUninitialize();
    return true;
}
#endif
