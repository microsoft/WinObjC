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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSExpression, NSExpressionFunction_Now) {
    NSExpression* expression = [NSExpression expressionForFunction:@"now" arguments:nil];
    ASSERT_TRUE_MSG(expression != nil, "FAILED: expression should be non-null!");

    id value = [expression expressionValueWithObject:nil context:nil];
    ASSERT_TRUE_MSG(value != nil, "FAILED: value should be non-null!");

    ASSERT_TRUE_MSG([value isKindOfClass:[NSDate class]], "FAILED: value is not NSDate type.");
}

TEST(NSExpression, NSExpressionFunction_format) {
    NSExpression* expression = [NSExpression expressionWithFormat:@"4 + 3"];
    NSNumber* result = [expression expressionValueWithObject:nil context:nil];
    ASSERT_EQ_MSG(7, [result intValue], @"Failed: 4+3");

    expression = [NSExpression expressionWithFormat:@"%d*%f", 3, 3.5];
    result = [expression expressionValueWithObject:nil context:nil];
    ASSERT_EQ_MSG(10.5, [result doubleValue], @"Failed: 3*3.5");
}

TEST(NSExpression, NSExpressionFunction_format2) {
    NSExpression* expression = [NSExpression expressionWithFormat:@"4 + 3 - 1 + 2"];
    NSNumber* result = [expression expressionValueWithObject:nil context:nil];
    ASSERT_EQ_MSG(8, [result intValue], @"Failed: 4 + 3 - 1 + 2");
}

TEST(NSExpression, NSExpressionFunction_format3) {
    NSExpression* expression = [NSExpression expressionWithFormat:@"(4 + 3 - 1 + 2) * 10**2"];
    NSNumber* result = [expression expressionValueWithObject:nil context:nil];
    ASSERT_EQ_MSG(800, [result intValue], @"Failed: (4 + 3 - 1 + 2) * 10");
}