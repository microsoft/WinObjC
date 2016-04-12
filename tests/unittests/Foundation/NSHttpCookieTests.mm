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
#import <Foundation/Foundation.h>

// Implemented in NSHTTPCookie.mm
extern void parseCookies(const char* lineptr, id dict);

TEST(NSHTTPCookie, ParseCookies) {
    NSMutableDictionary* cookies = [[NSMutableDictionary alloc] initWithCapacity:0];
    const char line[] =
        "__cfduid=d1abe44e4920d4f908a73c981d32b74131454529278; expires=Thu, 02-Feb-17 19:54:38 GMT; path=/; domain=.reddit.com; HttpOnly";
    parseCookies(line, cookies);

    ASSERT_EQ([cookies count], 4);
    ASSERT_TRUE([[cookies valueForKey:@"NSHTTPCookieValue"] isEqual:@"d1abe44e4920d4f908a73c981d32b74131454529278"]);
    ASSERT_TRUE([[cookies valueForKey:@"NSHTTPCookieName"] isEqual:@"__cfduid"]);
    ASSERT_TRUE([[cookies valueForKey:@"NSHTTPCookiePath"] isEqual:@"/"]);
    ASSERT_TRUE([[cookies valueForKey:@"NSHTTPCookieDomain"] isEqual:@"reddit.com"]);
}