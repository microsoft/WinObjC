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
#import <UIKit/UIActionSheet.h>

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#include <COMIncludes_end.h>

#include "ObjCXamlControls.h"
#import "UWP/WindowsUIXamlControls.h"

TEST(UIActionSheet, CreateXamlElement) {
    dispatch_sync(dispatch_get_main_queue(),
                  ^{
                      // TODO: Switch to UIKit.Xaml projections when they're available.
                      Microsoft::WRL::ComPtr<IInspectable> xamlElement(XamlCreateContentDialog());
                      ASSERT_TRUE(xamlElement);
                  });
}

TEST(UIActionSheet, GetXamlElement) {
    dispatch_sync(dispatch_get_main_queue(),
                  ^{
                      UIActionSheet* actionSheet = [[[UIActionSheet alloc] init] autorelease];
                      WXFrameworkElement* backingElement = [actionSheet xamlElement];
                      ASSERT_TRUE(backingElement);

                      ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
                  });
}

TEST(UIActionSheet, NilParameters) {
    dispatch_sync(dispatch_get_main_queue(),
                  ^{
                      UIActionSheet* actionSheet = [[[UIActionSheet alloc] initWithTitle:nil
                                                                                delegate:nil
                                                                       cancelButtonTitle:nil
                                                                  destructiveButtonTitle:nil
                                                                       otherButtonTitles:nil] autorelease];
                      WXFrameworkElement* backingElement = [actionSheet xamlElement];
                      ASSERT_TRUE(backingElement);

                      // Check that cancel button index, destructive button index, other button index are correct
                      NSInteger numButtons = [actionSheet numberOfButtons];
                      ASSERT_TRUE(numButtons == 0);

                      NSInteger cancelIndex = [actionSheet cancelButtonIndex];
                      ASSERT_TRUE(cancelIndex == -1);
                      
                      NSInteger destructiveIndex = [actionSheet destructiveButtonIndex];
                      ASSERT_TRUE(cancelIndex == -1);
                      
                      NSInteger otherIndex = [actionSheet firstOtherButtonIndex];
                      ASSERT_TRUE(otherIndex == -1);
                  });
}
