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
#import <Foundation/NSThread.h>
#import <UIKit/UIView.h>
#import "UWP/WindowsUIXamlControls.h"

TEST(UIView, Create) {
    EXPECT_FALSE([NSThread isMainThread]);

    // Try to create and destroy a UIView on a non-UI thread
    [[[UIView alloc] initWithFrame:CGRectMake(0, 0, 10, 10)] release];
}

TEST(UIView, GetXamlElement) {
    dispatch_sync(dispatch_get_main_queue(),
                  ^{
                      UIView* view = [[[UIView alloc] init] autorelease];
                      WXFrameworkElement* backingElement = [view xamlElement];
                      ASSERT_TRUE(backingElement);
                      ASSERT_TRUE([backingElement isKindOfClass:[WXFrameworkElement class]]);
                      ASSERT_TRUE([backingElement.name isEqualToString:@"UIView"]);
                  });
}