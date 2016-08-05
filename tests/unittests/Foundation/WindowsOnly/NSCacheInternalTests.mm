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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <Starboard.h>

// Windows-only:
//      WinObjC_SetZombiesEnabled

TEST(NSCache, AutoreleasedKeys) {
    WinObjC_SetZombiesEnabled(YES);
    auto defer = wil::ScopeExit([]() { WinObjC_SetZombiesEnabled(NO); });

    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        for (unsigned int i = 0; i < 100; ++i) {
            NSString* key = [[NSString alloc] initWithFormat:@"key-%u", i]; // +1 (1)
            EXPECT_NO_THROW([cache setObject:@"whatever" forKey:key]); // +1 (2)
            [key release]; // -1 (1)
        }
        [pool release];
    }

    {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        ASSERT_NO_THROW([cache setObject:@"stomp" forKey:@"key-0"]);
        [pool release];
    }

    ASSERT_NO_THROW([cache removeObjectForKey:@"key-0"]);

    ASSERT_NO_THROW([cache setObject:@"stomp" forKey:@"key-1"]);
    ASSERT_NO_THROW([cache removeObjectForKey:@"key-1"]);
}