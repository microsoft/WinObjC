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

TEST(NSString, NSStringTests) {

    // NSString* PercentEncoding methods.
    NSString* decodedString = @"Space DoubleQuotes\"Hash#Percent%LessThan<GreaterThan>OpeningBracket[Backslash\\ClosingBracket]Caret^GraveAccent`OpeningBrace{VerticalBar|ClosingBrace}";
    NSString* encodedString = @"Space%20DoubleQuotes%22Hash%23Percent%25LessThan%3CGreaterThan%3EOpeningBracket%5BBackslash%5CClosingBracket%5DCaret%5EGraveAccent%60OpeningBrace%7BVerticalBar%7CClosingBrace%7D";

    NSString* testString = [decodedString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    ASSERT_TRUE_MSG([testString isEqualToString:encodedString], 
        "FAILED: [stringByAddingPercentEscapesUsingEncoding] testString and encodedString should be equal!\ntestString: %s\n", 
        [testString UTF8String]);
        
    
    testString = [encodedString stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    ASSERT_TRUE_MSG([testString isEqualToString:decodedString],
        "FAILED: [stringByReplacingPercentEscapesUsingEncoding] testString and encodedString should be equal!\ntestString: %s\n", 
        [testString UTF8String]);

    testString = [encodedString stringByRemovingPercentEncoding];
    ASSERT_TRUE_MSG([testString isEqualToString:decodedString],
        "FAILED: [stringByRemovingPercentEncoding] testString and decodedString should be equal!\ntestString: %s\n", 
        [testString UTF8String]);
}
