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
//      WinObjC_SetZombiesEnabled

#import <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSObject, NSZombie) { // This test will fail with an AV if zombies do not work.
    WinObjC_SetZombiesEnabled(YES);

    NSObject* object = [[NSObject alloc] init];
    [object release];
    EXPECT_ANY_THROW([object self]);

    WinObjC_SetZombiesEnabled(NO);
}

TEST(NSCFObject, NSZombie) {
    WinObjC_SetZombiesEnabled(YES);

    NSString* string = [[NSMutableString alloc] initWithString:@"Hello"];
    [string release];
    EXPECT_ANY_THROW([string self]);

    EXPECT_ANY_THROW(CFStringGetLength(static_cast<CFStringRef>(string)));

    WinObjC_SetZombiesEnabled(NO);
}