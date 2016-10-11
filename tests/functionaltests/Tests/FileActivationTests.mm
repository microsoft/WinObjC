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

#include <TestFramework.h>
#include <Foundation/Foundation.h>

#include <COMIncludes.h>
#include "MockClass.h"
#include <windows.applicationModel.activation.h>
#include <windows.foundation.collections.h>
#include <windows.foundation.h>
#include <windows.storage.h>
#include <COMIncludes_End.h>

#include <UWP/WindowsApplicationModelActivation.h>
#include <UWP/WindowsStorage.h>
#include <UWP/WindowsUIXaml.h>
#include "StringHelpers.h"
#include "UIKit/UIApplication.h"

using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage;
using namespace ABI::Windows::Foundation::Collections;
using namespace Microsoft::WRL;

// Method to call in tests to activate app
extern "C" void UIApplicationActivationTest(IInspectable* args, void* delegateClassName);

// This is not a complete list of interfaces implemented by the real FileActivatedEventArgs but should be a
// sufficient stand in for how it will be used.
MOCK_CLASS(MockFileActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IFileActivatedEventArgs, IActivatedEventArgs> {

               // Claim to be the implementation for the real system RuntimeClass for FileActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_FileActivatedEventArgs, BaseTrust);

           public:
               // IActivatedEventArgs
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);

               // IFileActivatedEventArgs
               MOCK_STDCALL_METHOD_1(get_Files);
               MOCK_STDCALL_METHOD_1(get_Verb);
           });

MOCK_CLASS(MockFileVectorView,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IVectorView<IStorageItem*>> {

               InspectableClass(L"MockVectorView", BaseTrust);

               MOCK_STDCALL_METHOD_2(GetAt);
               MOCK_STDCALL_METHOD_1(get_Size);
               MOCK_STDCALL_METHOD_3(IndexOf);
           });

MOCK_CLASS(MockStorageItem,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IStorageItem> {

               InspectableClass(RuntimeClass_Windows_Storage_StorageFile, BaseTrust);

               MOCK_STDCALL_METHOD_2(RenameAsyncOverloadDefaultOptions);
               MOCK_STDCALL_METHOD_3(RenameAsync);
               MOCK_STDCALL_METHOD_1(DeleteAsyncOverloadDefaultOptions);
               MOCK_STDCALL_METHOD_2(DeleteAsync);
               MOCK_STDCALL_METHOD_1(GetBasicPropertiesAsync);
               MOCK_STDCALL_METHOD_1(get_Name);
               MOCK_STDCALL_METHOD_1(get_Path);
               MOCK_STDCALL_METHOD_1(get_Attributes);
               MOCK_STDCALL_METHOD_1(get_DateCreated);
               MOCK_STDCALL_METHOD_2(IsOfType);
           });

// Delegate for testing File foreground activation
@interface FileActivationForegroundTestDelegate : NSObject <UIApplicationDelegate>
@property (nonatomic, readonly) StrongId<NSMutableDictionary> methodsCalled;
@end

@implementation FileActivationForegroundTestDelegate
- (id)init {
    if (self = [super init]) {
        _methodsCalled.attach([NSMutableDictionary new]);
    }
    return self;
}

- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_NE(nullptr, launchOptions[UIApplicationLaunchOptionsFileKey]);
    WAAFileActivatedEventArgs* result = launchOptions[UIApplicationLaunchOptionsFileKey];
    EXPECT_EQ(1, result.files.count);

    // TODO 1091: dynamic cast shouldn't be necessary but returned projected type is incorrect.
    EXPECT_OBJCEQ(@"FILEACTIVATED_TEST", [rt_dynamic_cast<WSIStorageItem>(result.files[0]) name]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_NE(nullptr, launchOptions[UIApplicationLaunchOptionsFileKey]);
    WAAFileActivatedEventArgs* result = launchOptions[UIApplicationLaunchOptionsFileKey];
    EXPECT_EQ(1, result.files.count);

    // TODO 1091: dynamic cast shouldn't be necessary but returned projected type is incorrect.
    EXPECT_OBJCEQ(@"FILEACTIVATED_TEST", [rt_dynamic_cast<WSIStorageItem>(result.files[0]) name]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return true;
}

- (void)application:(UIApplication*)application didReceiveFile:(WAAFileActivatedEventArgs*)result {
    // Delegate method should only be called once
    EXPECT_EQ([[self methodsCalled] objectForKey:NSStringFromSelector(_cmd)], nil);
    EXPECT_EQ(1, result.files.count);

    // TODO 1091: dynamic cast shouldn't be necessary but returned projected type is incorrect.
    EXPECT_OBJCEQ(@"FILEACTIVATED_TEST", [rt_dynamic_cast<WSIStorageItem>(result.files[0]) name]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return;
}

@end

// Creates test method which we call in TEST_CLASS_SETUP to activate app
void FileActivatedTestForegroundActivation() {
    LOG_INFO("FileActivatedTest Foreground Activation Test: ");

    auto fakeArgs = Make<MockFileActivatedEventArgs>();
    fakeArgs->Setget_Files([](IVectorView<IStorageItem*>** files) {
        auto mockVector = Make<MockFileVectorView>();

        mockVector->SetGetAt([](unsigned index, IStorageItem** item) {
            if (index != 0) {
                return E_BOUNDS;
            }

            auto mockItem = Make<MockStorageItem>();
            mockItem->Setget_Name([](HSTRING* name) {
                Wrappers::HStringReference nameWrapper(L"FILEACTIVATED_TEST");
                nameWrapper.CopyTo(name);
                return S_OK;
            });

            mockItem.CopyTo(item);

            return S_OK;
        });

        mockVector->Setget_Size([](unsigned* size) {
            *size = 1;
            return S_OK;
        });

        mockVector.CopyTo(files);
        return S_OK;
    });

    fakeArgs->Setget_Kind([](ActivationKind* kind) {
        *kind = ActivationKind_File;
        return S_OK;
    });

    fakeArgs->Setget_PreviousExecutionState([](ApplicationExecutionState* state) {
        *state = ApplicationExecutionState_NotRunning;
        return S_OK;
    });

    // Pass activation argument to method which activates the app
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(fakeArgs.Get()),
                                NSStringFromClass([FileActivationForegroundTestDelegate class]));
}

void FileActivatedTestForegroundActivationDelegateMethodsCalled() {
    FileActivationForegroundTestDelegate* testDelegate = [[UIApplication sharedApplication] delegate];
    NSDictionary* methodsCalled = [testDelegate methodsCalled];
    EXPECT_TRUE(methodsCalled);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:willFinishLaunchingWithOptions:"]);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didFinishLaunchingWithOptions:"]);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didReceiveFile:"]);
}