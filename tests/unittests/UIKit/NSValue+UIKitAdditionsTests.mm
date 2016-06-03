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

#include <TestFramework.h>
#include <UIKit/NSValue+UIKitAdditions.h>

TEST(NSValue, storedRectCanBeAccessAsARect) {
    id val = [NSValue valueWithCGRect:(CGRect){ 10, 20, 30, 40 }];
    ASSERT_NO_THROW([val CGRectValue]);
}

TEST(NSValue, rectStoredThroughGenericPointerCanBeAccessedAsARect) {
    CGRect r = CGRectMake(10, 20, 30, 40);
    id val = [NSValue valueWithBytes:&r objCType:@encode(CGRect)];
    ASSERT_NO_THROW([val CGRectValue]);
}

TEST(NSValue, rectStoredThroughGenericPointerComparesFavorablyToARectStoredViaNormalSetter) {
    CGRect r = CGRectMake(10, 20, 30, 40);
    id val = [NSValue valueWithBytes:&r objCType:@encode(CGRect)];
    id val2 = [NSValue valueWithCGRect:CGRectMake(10, 20, 30, 40)];
    ASSERT_EQ(YES, [val isEqualToValue:val2]);
}

TEST(NSValue, rectStoredViaNormalSetterMemcpsRectThatWeCreate) {
    CGRect r = CGRectMake(10, 20, 30, 40);
    id val2 = [NSValue valueWithCGRect:CGRectMake(10, 20, 30, 40)];
    CGRect bytes;
    [val2 getValue:&bytes];
    ASSERT_EQ(0, memcmp(&r, &bytes, sizeof(CGRect)));
}