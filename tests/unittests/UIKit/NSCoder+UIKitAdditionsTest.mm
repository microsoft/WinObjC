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

#import <Starboard/SmartTypes.h>
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
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGSize newSize = [unarchiver decodeCGSizeForKey:@"CGSize"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(CGSizeEqualToSize(newSize, size));
}

TEST(NSCoder_UIKit, encodeCGPoint) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGPoint point = CGPointMake(10, 18);
    [archiver encodeCGPoint:point forKey:@"CGPoint"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGPoint newPoint = [unarchiver decodeCGPointForKey:@"CGPoint"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(CGPointEqualToPoint(newPoint, point));
}

TEST(NSCoder_UIKit, encodeCGRect) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGRect rect = CGRectMake(10, 18, 5, 5);
    [archiver encodeCGRect:rect forKey:@"CGRect"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGRect newRect = [unarchiver decodeCGRectForKey:@"CGRect"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(CGRectEqualToRect(newRect, rect));
}

TEST(NSCoder_UIKit, encodeCGVector) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGVector vector = CGVectorMake(10, 18);
    [archiver encodeCGVector:vector forKey:@"CGVector"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGVector newVector = [unarchiver decodeCGVectorForKey:@"CGVector"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE((vector.dx == newVector.dx) && (vector.dy == newVector.dy));
}

TEST(NSCoder_UIKit, encodeUIEdgeInsets) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    UIEdgeInsets edgeInsets = UIEdgeInsetsMake(10, 18, 5, 5);
    [archiver encodeUIEdgeInsets:edgeInsets forKey:@"UIEdgeInsets"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    UIEdgeInsets newEdgeInsets = [unarchiver decodeUIEdgeInsetsForKey:@"UIEdgeInsets"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(UIEdgeInsetsEqualToEdgeInsets(edgeInsets, newEdgeInsets));
}

TEST(NSCoder_UIKit, encodeUIOffset) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    UIOffset offset = UIOffsetMake(10, 18);
    [archiver encodeUIOffset:offset forKey:@"UIOffset"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    UIOffset newOffset = [unarchiver decodeUIOffsetForKey:@"UIOffset"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(UIOffsetEqualToOffset(offset, newOffset));
}

TEST(NSCoder_UIKit, encodeCGAffineTransform) {
    NSMutableData* data = [[[NSMutableData alloc] init] autorelease];
    NSKeyedArchiver* archiver = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    CGAffineTransform transform = CGAffineTransformMake(10, 18, 17, 15, 3, 2);
    [archiver encodeCGAffineTransform:transform forKey:@"CGAffineTransform"];
    [archiver finishEncoding];
    [archiver release];

    NSKeyedUnarchiver* unarchiver = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    CGAffineTransform newTransform = [unarchiver decodeCGAffineTransformForKey:@"CGAffineTransform"];
    [unarchiver finishDecoding];
    [unarchiver release];

    EXPECT_TRUE(CGAffineTransformEqualToTransform(transform, newTransform));
}