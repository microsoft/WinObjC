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
#import <Foundation/Foundation.h>

TEST(NSObjectTest, AllocationSanity) {
    NSObject *obj1 = [NSObject new];
    NSObject *obj2 = [NSObject new];

    //obj1 and obj2 should be distinct pointers!
    EXPECT_NE_MSG(obj1, obj2, "obj1 and obj2 should be distinct pointers!");

    [obj1 release];
    [obj2 release];
}

// TODO: Switch to ARC and make sure the object is destructed when
// it goes out of scope