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
#include "RuntimeTestHelpers.h"

@interface IVarTestDerived : IVarTestBase {
    bool kaboom;
}
@end

@implementation IVarTestDerived
- init {
    kaboom = YES;
    LOG_INFO("%x", self.state); // Should not segfault
    return self;
}
@end

TEST(Runtime, Runtime_IVarOffsets) {
    // This will AV if the runtime/compiler don't handle ivar offsets properly
    [[IVarTestDerived alloc] init];
}