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

// Windows-only:
//      WinObjC_SetMissingSelectorFatal

#import <TestFramework.h>
#import <Foundation/Foundation.h>

@interface NSObject (Nonexistent)
+ (void)nonexistentSelector;
+ (id)tryToReturnANonexistentThing;
@end

TEST(Sanity, NonFatalSelectors) {
    WinObjC_SetMissingSelectorFatal(NO);
    EXPECT_NO_THROW([NSObject nonexistentSelector]);
    EXPECT_OBJCEQ(nil, [NSObject tryToReturnANonexistentThing]);
    WinObjC_SetMissingSelectorFatal(YES);
    EXPECT_ANY_THROW([NSObject nonexistentSelector]);
}