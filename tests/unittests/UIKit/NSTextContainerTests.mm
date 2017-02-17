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

    // Exclusion paths not in horizontal order to make sure non-ordered are sorted properly
    textContainer.exclusionPaths = @[
        [UIBezierPath bezierPathWithRect:CGRectMake(100, 0, 100, 100)],
        [UIBezierPath bezierPathWithRect:CGRectMake(700, 0, 150, 300)],
        [UIBezierPath bezierPathWithRect:CGRectMake(300, 0, 200, 150)],
        [UIBezierPath bezierPathWithRect:CGRectMake(950, 0, 1000, 300)]
    ];

    // First rect starts at beginning of area, ends before first exclusion
    // Remaining rect starts after first exclusion, ends before second
    CGRect remaining = CGRectInfinite;
    CGRect fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 0, 1000, 10)
                                                                 atIndex:0
                                                        writingDirection:NSWritingDirectionNatural
                                                           remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 0, 95, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(205, 0, 90, 10), remaining);

    // First rect starts at beginning area given, ends before second exlusion
    // Remaining rect starts after second exclusion, ends before third
    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(250, 0, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(250, 0, 45, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(505, 0, 190, 10), remaining);

    // First rect starts at beginning area given, ends before third exlusion
    // Remaining rect starts after third exclusion, ends at end of container
    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(550, 0, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(550, 0, 145, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(855, 0, 90, 10), remaining);

    // First rect starts at beginning of text container, passes under first exclusion and ends before second
    // Remaining rect starts after second exclusion, ends before third
    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 120, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 120, 295, 10), fragmentRect);
    EXPECT_EQ(CGRectMake(505, 120, 190, 10), remaining);

    // First rect passes under all exclusion zones, going from beginning to end of text container
    // There is no remaining rect
    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(0, 400, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(0, 400, 1000, 10), fragmentRect);
    EXPECT_EQ(CGRectZero, remaining);

    // First rect starts at end of text container, has width of 0
    // There is no remaining rect
    fragmentRect = [textContainer lineFragmentRectForProposedRect:CGRectMake(975, 0, 1000, 10)
                                                          atIndex:0
                                                 writingDirection:NSWritingDirectionNatural
                                                    remainingRect:&remaining];
    EXPECT_EQ(CGRectMake(1000, 0, 0, 10), fragmentRect);
    EXPECT_EQ(CGRectZero, remaining);
}