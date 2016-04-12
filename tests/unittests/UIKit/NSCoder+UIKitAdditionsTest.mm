//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporatiuon. All rights reserved.
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

#import <Starboard.h>
#import <TestFramework.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <windows.h>

// Test UI Kit extensions for NSCoder
// NSCoder is abstract class. NSKeyedArchiver & NSKeyedUnarchiver is its subclass.

TEST(NSCoder_UIKit, encodeCGSize) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGSize size = CGSizeMake(10, 18);
    [archiver encodeCGSize:size forKey:@"CGSize"];
    [archiver finishEncoding];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGSize newSize = [unarchiver decodeCGSizeForKey:@"CGSize"];

    EXPECT_TRUE(CGSizeEqualToSize(newSize, size));
}

TEST(NSCoder_UIKit, encodeCGPoint) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGPoint point = CGPointMake(10, 18);
    [archiver encodeCGPoint:point forKey:@"CGPoint"];
    [archiver finishEncoding];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGPoint newPoint = [unarchiver decodeCGPointForKey:@"CGPoint"];

    EXPECT_TRUE(CGPointEqualToPoint(newPoint, point));
}

TEST(NSCoder_UIKit, encodeCGRect) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGRect rect = CGRectMake(10, 18, 5, 5);
    [archiver encodeCGRect:rect forKey:@"CGRect"];
    [archiver finishEncoding];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGRect newRect = [unarchiver decodeCGRectForKey:@"CGRect"];

    EXPECT_TRUE(CGRectEqualToRect(newRect, rect));
}