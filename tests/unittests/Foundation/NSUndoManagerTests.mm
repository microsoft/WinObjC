//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

@interface someObject : NSObject
@property NSUndoManager* undoManager;
@property NSNumber* value;
@property NSMutableArray* arrayOfNumbers;
- (id)init;
- (double)doubleValue;
- (void)undo;
@end

@implementation someObject

- (id)initWithValue:(NSNumber*)num {
    self = [super init];
    self.undoManager = [[[NSUndoManager alloc] init] autorelease];
    self.value = num;
    self.arrayOfNumbers = nil;
    return self;
}

- (id)initWithEmptyArray {
    self = [super init];
    self.undoManager = [[[NSUndoManager alloc] init] autorelease];
    self.value = nil;
    self.arrayOfNumbers = [NSMutableArray array];
    return self;
}

- (void)updateNumber:(NSNumber*)value {
    [self.undoManager registerUndoWithTarget:self selector:@selector(updateNumber:) object:self.value];
    self.value = value;
}

- (void)addToMutableArray:(NSNumber*)value {
    [self.undoManager registerUndoWithTarget:self selector:@selector(removeFromMutableArray:) object:value];
    [self.arrayOfNumbers addObject:value];
}

- (void)removeFromMutableArray:(NSNumber*)value {
    [self.undoManager registerUndoWithTarget:self selector:@selector(addToMutableArray:) object:value];
    [self.arrayOfNumbers removeObject:value];
}

- (void)undo {
    [self.undoManager undo];
}

- (void)redo {
    [self.undoManager redo];
}

@end

TEST(NSUndoManager, BasicUndoTest) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];

    someObject* object = [[[someObject alloc] initWithValue:oldValue] autorelease];

    EXPECT_EQ([object.undoManager canUndo], NO);

    EXPECT_EQ(object.value.intValue, oldValue.intValue);
    [object updateNumber:newValue];
    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_EQ(object.value.intValue, newValue.intValue);

    [object undo];
    EXPECT_EQ(object.value.intValue, oldValue.intValue);
    EXPECT_EQ([object.undoManager canUndo], NO);
}

TEST(NSUndoManager, undoTests) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    someObject* object = [[[someObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    // Each undo operation here gets added to the single default undo group.
    [object updateNumber:val2];
    [object updateNumber:val3];
    [object updateNumber:val4];
    EXPECT_EQ(object.value.intValue, val4.intValue);
    [object undo];
    EXPECT_EQ(object.value.intValue, val1.intValue);
    EXPECT_EQ([object.undoManager canUndo], NO);
}

TEST(NSUndoManager, undoRedoTests) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    someObject* object = [[[someObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    [object updateNumber:val2];
    [object updateNumber:val3];
    [object updateNumber:val4];
    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_EQ(object.value.intValue, val4.intValue);
    [object undo];
    EXPECT_EQ([object.undoManager canRedo], YES);
    EXPECT_EQ(object.value.intValue, val1.intValue);
    [object redo];
    EXPECT_EQ(object.value.intValue, val4.intValue);
    EXPECT_EQ([object.undoManager canRedo], NO);
    [object undo];
    EXPECT_EQ(object.value.intValue, val1.intValue);
    EXPECT_EQ([object.undoManager canRedo], YES);
}

TEST(NSUndoManager, undoRedoTestsWithMutableObject) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    someObject* object = [[[someObject alloc] initWithEmptyArray] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    NSMutableArray* comparisonArray = [NSMutableArray array];
    [comparisonArray addObject:val1];
    [comparisonArray addObject:val2];
    [comparisonArray addObject:val3];

    [object addToMutableArray:val1];
    [object addToMutableArray:val2];
    [object addToMutableArray:val3];

    EXPECT_OBJCEQ(comparisonArray, object.arrayOfNumbers);

    [object undo];

    EXPECT_OBJCEQ([NSMutableArray array], object.arrayOfNumbers);

    [object redo];

    EXPECT_OBJCEQ(comparisonArray, object.arrayOfNumbers);
}