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

#include "gtest-api.h"
#import <mach/mach.h>
#include <mach/mach_defs.h>

TEST(Starboard, MachInterfaceSanity) {
    vm_size_t pageSize = 0;

    // We pass a value of '0' as the first parameter to host_page_size, as it ignores its first parameter.
    kern_return_t retVal = host_page_size(0, &pageSize);
    
    ASSERT_EQ_MSG(retVal, KERN_SUCCESS, "FAILED: host_page_size failed");
    ASSERT_GT_MSG(pageSize, 0, "FAILED: Reported page size is invalid");
}