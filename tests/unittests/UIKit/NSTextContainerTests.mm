//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <UIKit/UIKit.h>
#import <Starboard/SmartTypes.h>
#import "CppUtils.h"

TEST(NSTextContainer, LineFragmentRectForProposedRect) {
    NSTextContainer* textContainer = [[[NSTextContainer alloc] initWithSize:CGSizeMake(1000, FLT_MAX)] autorelease];
    textContainer.exclusionPaths = @[
        [UIBezierPath bezierPathWithRect:CGRectMake(100, 0, 100, 100)],
        [UIBezierPath bezierPathWithRect:CGRectMake(300, 0, 200, 150)],
        [UIBezierPath bezierPathWithRect:CGRectMake(700, 0, 150, 300)]
    ];

    CGRect remaining = CGRectInfinite;
    CGRect fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 0, 1000, 10)
                                                                 atIndex:0
                                                        writingDirection:NSWritingDirectionNatural
                                                           remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 0, 95, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(205, 0, 90, 10), remaining);

    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(250, 0, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(250, 0, 45, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(505, 0, 190, 10), remaining);

    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(550, 0, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(550, 0, 145, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(855, 0, 145, 10), remaining);

    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 120, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 120, 295, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(505, 120, 190, 10), remaining);

    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 400, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 400, 1000, 10), fragmentRect);
    EXPECT_EQ(CGRectZero, remaining);
}