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
- (id)initWithValue:(NSNumber*)num;
- (id)initWithEmptyArray;
- (void)updateNumber:(NSNumber*)value;
- (void)updateNumberSingleUndoStep:(NSNumber*)value;
- (void)addToMutableArray:(NSNumber*)value;
- (void)removeFromMutableArray:(NSNumber*)value;
@end

@implementation someObject

- (id)initWithValue:(NSNumber*)num {
    self = [super init];
    _undoManager = [[[NSUndoManager alloc] init] autorelease];
    _value = num;
    _arrayOfNumbers = nil;
    return self;
}

- (id)initWithEmptyArray {
    self = [super init];
    _undoManager = [[[NSUndoManager alloc] init] autorelease];
    _value = nil;
    _arrayOfNumbers = [NSMutableArray array];
    return self;
}

- (void)updateNumber:(NSNumber*)value {
    [_undoManager registerUndoWithTarget:self selector:@selector(updateNumber:) object:_value];
    _value = value;
}

- (void)updateNumberSingleUndoStep:(NSNumber*)value {
    [_undoManager beginUndoGrouping];
    [self updateNumber:value];
    [_undoManager endUndoGrouping];
}

- (void)addToMutableArray:(NSNumber*)value {
    [_undoManager registerUndoWithTarget:self selector:@selector(removeFromMutableArray:) object:value];
    [_arrayOfNumbers addObject:value];
}

- (void)removeFromMutableArray:(NSNumber*)value {
    [_undoManager registerUndoWithTarget:self selector:@selector(addToMutableArray:) object:value];
    [_arrayOfNumbers removeObject:value];
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

    [object.undoManager undo];
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
    [object.undoManager undo];
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
    [object.undoManager undo];
    EXPECT_EQ([object.undoManager canRedo], YES);
    EXPECT_EQ(object.value.intValue, val1.intValue);
    [object.undoManager redo];
    EXPECT_EQ(object.value.intValue, val4.intValue);
    EXPECT_EQ([object.undoManager canRedo], NO);
    [object.undoManager undo];
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

    [object.undoManager undo];

    EXPECT_OBJCEQ([NSMutableArray array], object.arrayOfNumbers);

    [object.undoManager redo];

    EXPECT_OBJCEQ(comparisonArray, object.arrayOfNumbers);
}

TEST(NSUndoManager, ExtraUndoOperations) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];

    someObject* object = [[[someObject alloc] initWithValue:oldValue] autorelease];

    [object updateNumber:newValue];
    EXPECT_EQ(object.value.intValue, newValue.intValue);

    [object.undoManager undo];
    EXPECT_EQ(object.value.intValue, oldValue.intValue);
    [object.undoManager undo];
    EXPECT_EQ(object.value.intValue, oldValue.intValue);

    [object.undoManager redo];
    EXPECT_EQ(object.value.intValue, newValue.intValue);
    [object.undoManager redo];
    EXPECT_EQ(object.value.intValue, newValue.intValue);
}

TEST(NSUndoManager, IndividualUndoOperations) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    someObject* object = [[[someObject alloc] initWithValue:val1] autorelease];

    [object updateNumberSingleUndoStep:val1];
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];
    EXPECT_EQ(object.value.intValue, val4.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val3.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val2.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val1.intValue);
}

TEST(NSUndoManager, IndividualUndoRedoOperations) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];
    someObject* object = [[[someObject alloc] initWithValue:val1] autorelease];

    [object updateNumberSingleUndoStep:val1];
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];

    EXPECT_EQ(object.value.intValue, val4.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val3.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val2.intValue);

    [object.undoManager redo];
    EXPECT_EQ(object.value.intValue, val3.intValue);

    [object.undoManager redo];
    EXPECT_EQ(object.value.intValue, val4.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val3.intValue);

    [object.undoManager undoNestedGroup];
    EXPECT_EQ(object.value.intValue, val2.intValue);
}