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
#include "_NSCFTemporaryRootObject.h"

#include <Windows.h>

@implementation _NSCFTemporaryRootObject
- (void)doesNotRecognizeSelector:(SEL)selector {
    // According to the reference platform documentation, this method must never return.
    EXCEPTION_RECORD record{
        EXCEPTION_NONCONTINUABLE_EXCEPTION,
        EXCEPTION_NONCONTINUABLE,
        nullptr,
        nullptr,
        0,
        {0}
    };
    RaiseFailFastException(&record, nullptr, FAIL_FAST_GENERATE_EXCEPTION_ADDRESS);
}
@end
