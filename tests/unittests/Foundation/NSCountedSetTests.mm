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
#import <Foundation/Foundation.h>

TEST(Foundation, NSCountedSet_SanityTest) {
    LOG_INFO("NSCountedSet sanity test: ");

    LOG_INFO("Basic set compare test");

    NSCountedSet* countedSet1 = [[NSCountedSet alloc] initWithCapacity:2];
    [countedSet1 addObject:@1];
    [countedSet1 addObject:@2];
    NSSet* countedSet2 = [NSCountedSet setWithObjects:@1, @2, nil];

    ASSERT_TRUE_MSG([countedSet1 isEqualToSet:countedSet2], "FAILED: countedSet1 and countedSet2 should be equal!\n");

    [countedSet1 release];
    [countedSet2 release];

    LOG_INFO("Basic count test");

    NSCountedSet* carSet = [NSCountedSet setWithObjects:@"Honda Civic", @"Nissan Versa", @"BMW M1", nil];
    NSUInteger carCount = [carSet countForObject:@"BMW M1"];
    ASSERT_EQ_MSG(1, carCount, "FAILED: carCount should be 1!\n");

    carCount = [carSet countForObject:@"AUDI Q5"];
    ASSERT_EQ_MSG(0, carCount, "FAILED: carCount should be 0!\n");

    [carSet release];
}

TEST(Foundation, NSCountedSet_AddToSetTest) {
    LOG_INFO("NSCountedSet add to set test: ");

    NSCountedSet* colorSet = [[NSCountedSet alloc] initWithCapacity:1];
    [colorSet addObject:@"Red"];
    [colorSet addObject:@"Blue"];
    [colorSet addObject:@"Green"];

    NSUInteger redColorCount = [colorSet countForObject:@"Red"];
    ASSERT_EQ_MSG(1, redColorCount, "FAILED: redColorCount should be 1!\n");
    NSUInteger blueColorCount = [colorSet countForObject:@"Blue"];
    ASSERT_EQ_MSG(1, blueColorCount, "FAILED: blueColorCount should be 1!\n");
    NSUInteger greenColorCount = [colorSet countForObject:@"Green"];
    ASSERT_EQ_MSG(1, greenColorCount, "FAILED: greenColorCount should be 1!\n");

    [colorSet addObjectsFromArray:@[ @"Blue", @"Blue", @"Red" ]];

    redColorCount = [colorSet countForObject:@"Red"];
    ASSERT_EQ_MSG(2, redColorCount, "FAILED: redColorCount should be 2!\n");
    blueColorCount = [colorSet countForObject:@"Blue"];
    ASSERT_EQ_MSG(3, blueColorCount, "FAILED: blueColorCount should be 3!\n");
    greenColorCount = [colorSet countForObject:@"Green"];
    ASSERT_EQ_MSG(1, greenColorCount, "FAILED: greenColorCount should be 1!\n");

    [colorSet addObject:@"Green"];
    [colorSet addObject:@"Green"];
    [colorSet addObject:@"Green"];

    redColorCount = [colorSet countForObject:@"Red"];
    ASSERT_EQ_MSG(2, redColorCount, "FAILED: redColorCount should be 2!\n");
    blueColorCount = [colorSet countForObject:@"Blue"];
    ASSERT_EQ_MSG(3, blueColorCount, "FAILED: blueColorCount should be 3!\n");
    greenColorCount = [colorSet countForObject:@"Green"];
    ASSERT_EQ_MSG(4, greenColorCount, "FAILED: greenColorCount should be 4!\n");

    [colorSet release];
}

TEST(Foundation, NSCountedSet_RemoveFromSetTest) {
    LOG_INFO("NSCountedSet remove from set test: ");

    NSCountedSet* shapeSet = [[NSCountedSet alloc] initWithCapacity:5];

    NSUInteger squareShapeCount = [shapeSet countForObject:@"Square"];
    ASSERT_EQ_MSG(0, squareShapeCount, "FAILED: squareShapeCount should be 0!\n");
    NSUInteger roundShapeCount = [shapeSet countForObject:@"Round"];
    ASSERT_EQ_MSG(0, roundShapeCount, "FAILED: roundShapeCount should be 0!\n");

    [shapeSet addObjectsFromArray:@[ @"Square", @"Round" ]];

    squareShapeCount = [shapeSet countForObject:@"Square"];
    ASSERT_EQ_MSG(1, squareShapeCount, "FAILED: squareShapeCount should be 1!\n");
    roundShapeCount = [shapeSet countForObject:@"Round"];
    ASSERT_EQ_MSG(1, roundShapeCount, "FAILED: roundShapeCount should be 1!\n");

    [shapeSet addObjectsFromArray:@[ @"Square", @"Round", @"Square", @"Square" ]];

    squareShapeCount = [shapeSet countForObject:@"Square"];
    ASSERT_EQ_MSG(4, squareShapeCount, "FAILED: squareShapeCount should be 4!\n");
    roundShapeCount = [shapeSet countForObject:@"Round"];
    ASSERT_EQ_MSG(2, roundShapeCount, "FAILED: roundShapeCount should be 2!\n");

    [shapeSet removeObject:@"Square"];
    [shapeSet removeObject:@"Square"];

    squareShapeCount = [shapeSet countForObject:@"Square"];
    ASSERT_EQ_MSG(2, squareShapeCount, "FAILED: squareShapeCount should be 2!\n");
    roundShapeCount = [shapeSet countForObject:@"Round"];
    ASSERT_EQ_MSG(2, roundShapeCount, "FAILED: roundShapeCount should be 2!\n");

    [shapeSet removeAllObjects];

    squareShapeCount = [shapeSet countForObject:@"Square"];
    ASSERT_EQ_MSG(0, squareShapeCount, "FAILED: squareShapeCount should be 0!\n");
    roundShapeCount = [shapeSet countForObject:@"Round"];
    ASSERT_EQ_MSG(0, roundShapeCount, "FAILED: roundShapeCount should be 0!\n");

    [shapeSet release];
}