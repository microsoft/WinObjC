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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

@interface UndoTestObject : NSObject
@property (retain) NSUndoManager* undoManager;
@property (retain) NSNumber* value;
@property (retain) NSMutableArray* arrayOfNumbers;
- (id)initWithValue:(NSNumber*)num;
- (id)initWithEmptyArray;
- (void)updateNumber:(NSNumber*)value;
- (void)updateNumberSingleUndoStep:(NSNumber*)value;
- (void)addToMutableArray:(NSNumber*)value;
- (void)removeFromMutableArray:(NSNumber*)value;
@end

@implementation UndoTestObject

- (id)initWithValue:(NSNumber*)num {
    self = [super init];
    _undoManager = [[NSUndoManager alloc] init];
    _value = [num retain];
    _arrayOfNumbers = nil;
    return self;
}

- (id)initWithEmptyArray {
    self = [super init];
    _undoManager = [[NSUndoManager alloc] init];
    _value = nil;
    _arrayOfNumbers = [[NSMutableArray array] retain];
    return self;
}

- (void)dealloc {
    [_undoManager release];
    [_value release];
    [_arrayOfNumbers release];
    [super dealloc];
}

- (void)updateNumber:(NSNumber*)newValue {
    [self.undoManager registerUndoWithTarget:self selector:@selector(updateNumber:) object:self.value];
    self.value = newValue;
}

- (void)updateNumberSingleUndoStep:(NSNumber*)value {
    [self.undoManager beginUndoGrouping];
    [self updateNumber:value];
    [self.undoManager endUndoGrouping];
}

- (void)addToMutableArray:(NSNumber*)value {
    [self.undoManager registerUndoWithTarget:self selector:@selector(removeFromMutableArray:) object:value];
    [self.arrayOfNumbers addObject:value];
}

- (void)removeFromMutableArray:(NSNumber*)value {
    [self.undoManager registerUndoWithTarget:self selector:@selector(addToMutableArray:) object:value];
    [self.arrayOfNumbers removeObject:value];
}

@end

TEST(NSUndoManager, BasicUndoTest) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:oldValue] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    EXPECT_OBJCEQ(object.value, oldValue);
    [object updateNumber:newValue];

    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_OBJCEQ(object.value, newValue);

    [object.undoManager undo];

    EXPECT_OBJCEQ(object.value, oldValue);
    EXPECT_EQ([object.undoManager canUndo], NO);
}

TEST(NSUndoManager, MultipleUndoTests) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    // Each undo operation here gets added to the single default undo group.
    [object updateNumber:val2];
    [object updateNumber:val3];
    [object updateNumber:val4];
    EXPECT_OBJCEQ(object.value, val4);
    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val1);
    EXPECT_EQ([object.undoManager canUndo], NO);
}

TEST(NSUndoManager, UndoRedoTests) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    [object updateNumber:val2];
    [object updateNumber:val3];
    [object updateNumber:val4];
    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_OBJCEQ(object.value, val4);
    [object.undoManager undo];
    EXPECT_EQ([object.undoManager canRedo], YES);
    EXPECT_OBJCEQ(object.value, val1);
    [object.undoManager redo];
    EXPECT_OBJCEQ(object.value, val4);
    EXPECT_EQ([object.undoManager canRedo], NO);
    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val1);
    EXPECT_EQ([object.undoManager canRedo], YES);
}

TEST(NSUndoManager, UndoRedoTestsWithMutableObject) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithEmptyArray] autorelease];
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

TEST(NSUndoManager, UndoWithoutAnyUndoableActions) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:oldValue] autorelease];

    [object updateNumber:newValue];
    EXPECT_OBJCEQ(object.value, newValue);

    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, oldValue);

    // Attempt to call undo without an undo action available.
    EXPECT_NO_THROW([object.undoManager undo]);
    EXPECT_OBJCEQ(object.value, oldValue);
}

TEST(NSUndoManager, IndividualUndoOperations) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];

    [object updateNumberSingleUndoStep:val1];
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];

    EXPECT_OBJCEQ(object.value, val4);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val2);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val1);
}

// Similar test as above, but call undo instead of nested group as each undo operation should be
// it's own top level undo group.
TEST(NSUndoManager, IndividualUndoOperationsWithUndoCallAndGroupsByEventOff) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    object.undoManager.groupsByEvent = NO;

    [object updateNumberSingleUndoStep:val1];
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];
    EXPECT_OBJCEQ(object.value, val4);

    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val2);

    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val1);
}

TEST(NSUndoManager, IndividualUndoRedoOperations) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];
    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];

    [object updateNumberSingleUndoStep:val1];
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];

    EXPECT_OBJCEQ(object.value, val4);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val2);

    [object.undoManager redo];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager redo];
    EXPECT_OBJCEQ(object.value, val4);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val2);
}

TEST(NSUndoManager, InternalInconsistencyExceptions) {
    NSNumber* val1 = [NSNumber numberWithInt:5];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_ANY_THROW([object.undoManager endUndoGrouping]);

    object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    [object.undoManager beginUndoGrouping];
    EXPECT_ANY_THROW([object.undoManager undo]);
}

TEST(NSUndoManager, IsRegistrationEnabled) {
    NSNumber* val1 = [NSNumber numberWithInt:5];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    [object.undoManager disableUndoRegistration];
    EXPECT_EQ(object.undoManager.isUndoRegistrationEnabled, NO);
    [object.undoManager disableUndoRegistration];
    EXPECT_EQ(object.undoManager.isUndoRegistrationEnabled, NO);
    [object.undoManager enableUndoRegistration];
    EXPECT_EQ(object.undoManager.isUndoRegistrationEnabled, NO);
    [object.undoManager enableUndoRegistration];
    EXPECT_EQ(object.undoManager.isUndoRegistrationEnabled, YES);
    EXPECT_ANY_THROW([object.undoManager enableUndoRegistration]);
}

TEST(NSUndoManager, GroupingLevel) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);
    [object updateNumber:val2];
    [object updateNumber:val3];
    [object updateNumber:val4];

    EXPECT_EQ(object.undoManager.groupingLevel, 1);

    [object.undoManager undo];
    [object.undoManager redo];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);

    [object.undoManager undo];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);

    object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);
    [object.undoManager beginUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 2);
    [object updateNumber:val2];
    [object.undoManager endUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 1);
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];
    EXPECT_EQ(object.undoManager.groupingLevel, 1);

    [object.undoManager undo];

    EXPECT_EQ(object.undoManager.groupingLevel, 0);
    EXPECT_OBJCEQ(object.value, val1);

    [object.undoManager beginUndoGrouping];
    [object updateNumberSingleUndoStep:val2];
    [object.undoManager beginUndoGrouping];
    [object updateNumberSingleUndoStep:val3];
    [object.undoManager beginUndoGrouping];
    [object updateNumberSingleUndoStep:val4];
    EXPECT_EQ(object.undoManager.groupingLevel, 4);
    [object.undoManager endUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 3);
    [object.undoManager endUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 2);
    [object.undoManager beginUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 3);
    [object.undoManager endUndoGrouping];
    [object.undoManager endUndoGrouping];
    [object.undoManager undo];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);
    [object.undoManager redo];
    EXPECT_EQ(object.undoManager.groupingLevel, 0);

    [object.undoManager beginUndoGrouping];
    [object.undoManager beginUndoGrouping];
    [object.undoManager beginUndoGrouping];
    EXPECT_EQ(object.undoManager.groupingLevel, 4);
}

TEST(NSUndoManager, UndoNestedGroup) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];
    NSNumber* newValue2 = [NSNumber numberWithInt:7];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:oldValue] autorelease];
    EXPECT_EQ([object.undoManager canUndo], NO);

    EXPECT_OBJCEQ(object.value, oldValue);
    [object updateNumber:newValue];
    [object updateNumber:newValue2];
    EXPECT_EQ(object.undoManager.groupingLevel, 1);

    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_OBJCEQ(object.value, newValue2);
    [object.undoManager endUndoGrouping];

    [object.undoManager undoNestedGroup];

    EXPECT_OBJCEQ(object.value, oldValue);
}

TEST(NSUndoManager, BasicUndoNotAutomaticGroups) {
    NSNumber* oldValue = [NSNumber numberWithInt:5];
    NSNumber* newValue = [NSNumber numberWithInt:6];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:oldValue] autorelease];
    object.undoManager.groupsByEvent = NO;
    [object.undoManager beginUndoGrouping];

    EXPECT_OBJCEQ(object.value, oldValue);

    [object updateNumber:newValue];

    EXPECT_EQ([object.undoManager canUndo], YES);
    EXPECT_OBJCEQ(object.value, newValue);

    [object.undoManager endUndoGrouping];
    [object.undoManager undo];

    EXPECT_OBJCEQ(object.value, oldValue);
    EXPECT_EQ([object.undoManager canUndo], NO);
}

TEST(NSUndoManager, NestedUndoGroupsAndActionsNoAuto) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];
    NSNumber* val5 = [NSNumber numberWithInt:9];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    object.undoManager.groupsByEvent = NO;

    [object.undoManager beginUndoGrouping];
    [object updateNumber:val2];
    [object.undoManager endUndoGrouping];

    EXPECT_OBJCEQ(object.value, val2);

    [object.undoManager beginUndoGrouping];
    [object.undoManager beginUndoGrouping];
    [object updateNumber:val3];
    [object.undoManager endUndoGrouping];
    [object updateNumber:val4];
    [object.undoManager endUndoGrouping];

    EXPECT_OBJCEQ(object.value, val4);

    [object.undoManager undo];

    EXPECT_OBJCEQ(object.value, val2);
    [object.undoManager undo];
    EXPECT_OBJCEQ(object.value, val1);
}

TEST(NSUndoManager, NestedUndoNestedGroupsAndActionsNoAuto) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];
    NSNumber* val5 = [NSNumber numberWithInt:9];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    object.undoManager.groupsByEvent = NO;

    [object.undoManager beginUndoGrouping];
    [object updateNumber:val2];
    [object.undoManager endUndoGrouping];

    [object.undoManager beginUndoGrouping];
    [object updateNumber:val3];
    [object.undoManager endUndoGrouping];

    [object.undoManager beginUndoGrouping];
    [object updateNumber:val4];
    [object.undoManager endUndoGrouping];

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val3);

    [object.undoManager undoNestedGroup];
    EXPECT_OBJCEQ(object.value, val2);
}

// Undo test object that references an externally owned undo manager.
@interface UndoTestObjectWithSharedManager : NSObject
@property (retain) NSUndoManager* undoManager;
@property (retain) NSNumber* value;
- (id)initWithValue:(NSNumber*)num;
- (void)updateTarget:(NSNumber*)value;
@end

@implementation UndoTestObjectWithSharedManager
- (id)initWithValue:(NSNumber*)num undoManager:(NSUndoManager*)manager {
    self = [super init];
    _undoManager = [manager retain];
    _value = [num retain];
    return self;
}

// Each update call is wrapped in its own group.
- (void)updateValue:(NSNumber*)value {
    [self.undoManager beginUndoGrouping];
    [self.undoManager registerUndoWithTarget:self selector:@selector(updateValue:) object:self.value];
    self.value = value;
    [self.undoManager endUndoGrouping];
}

- (void)dealloc {
    [_undoManager release];
    [_value release];
    [super dealloc];
}

@end

TEST(NSUndoManager, MultipleUndoTargets) {
    NSNumber* target1val1 = [NSNumber numberWithInt:15];
    NSNumber* target1val2 = [NSNumber numberWithInt:16];
    NSNumber* target1val3 = [NSNumber numberWithInt:17];
    NSNumber* target2val1 = [NSNumber numberWithInt:25];
    NSNumber* target2val2 = [NSNumber numberWithInt:26];
    NSNumber* target2val3 = [NSNumber numberWithInt:27];
    NSNumber* target3val1 = [NSNumber numberWithInt:35];
    NSNumber* target3val2 = [NSNumber numberWithInt:36];
    NSNumber* target3val3 = [NSNumber numberWithInt:37];

    NSUndoManager* manager = [[[NSUndoManager alloc] init] autorelease];

    UndoTestObjectWithSharedManager* firstTargetWithNumbers =
        [[UndoTestObjectWithSharedManager alloc] initWithValue:target1val1 undoManager:manager];
    UndoTestObjectWithSharedManager* secondTargetWithNumbers =
        [[UndoTestObjectWithSharedManager alloc] initWithValue:target2val1 undoManager:manager];
    UndoTestObjectWithSharedManager* thirdTargetWithNumbers =
        [[UndoTestObjectWithSharedManager alloc] initWithValue:target3val1 undoManager:manager];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val1); // 15
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val1); // 25
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [firstTargetWithNumbers updateValue:target1val2];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val1); // 25
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [secondTargetWithNumbers updateValue:target2val2];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 26
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [firstTargetWithNumbers updateValue:target1val3];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 26
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [manager undoNestedGroup]; // Undo the most recent update, revert first target to target1val2

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 26
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [thirdTargetWithNumbers updateValue:target3val2];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 26
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val2); // 36

    // Update all to their third values as a single operation.
    [manager beginUndoGrouping];
    [firstTargetWithNumbers updateValue:target1val3];
    [secondTargetWithNumbers updateValue:target2val3];
    [thirdTargetWithNumbers updateValue:target3val3];
    [manager endUndoGrouping];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 27
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val3); // 37

    [manager undoNestedGroup]; // Revert all values to their targetxvalue2 in a single call.

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 26
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val2); // 36

    [manager redo]; // Bring them back to their third values.

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 27
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val3); // 37

    // Remove all undo operations targeting the second object.
    [manager removeAllActionsWithTarget:secondTargetWithNumbers];

    [manager undoNestedGroup]; // Revert all values to their targetxvalue2 in a single call except for the removed target, target 2

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 36
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val2); // 36

    [manager undoNestedGroup];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value,
                  target2val3); // 27 (secondTarget should not ever be changed as all of its actions have been removed.)
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35

    [manager undo];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val1); // 15
    EXPECT_OBJCEQ(secondTargetWithNumbers.value,
                  target2val3); // 27 (secondTarget should not ever be changed as all of its actions have been removed.)
    EXPECT_OBJCEQ(thirdTargetWithNumbers.value, target3val1); // 35
}

TEST(NSUndoManager, LimitUndoActions) {
    NSNumber* val1 = [NSNumber numberWithInt:1];
    NSNumber* val2 = [NSNumber numberWithInt:2];
    NSNumber* val3 = [NSNumber numberWithInt:3];
    NSNumber* val4 = [NSNumber numberWithInt:4];
    NSNumber* val5 = [NSNumber numberWithInt:5];

    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    object.undoManager.groupsByEvent = NO;
    // Can only hold 3 top level undo actions.
    object.undoManager.levelsOfUndo = 3;

    EXPECT_OBJCEQ(object.value, val1);

    // Add operations that never return to val1
    [object updateNumberSingleUndoStep:val2];
    [object updateNumberSingleUndoStep:val3];
    [object updateNumberSingleUndoStep:val4];
    [object updateNumberSingleUndoStep:val5];

    EXPECT_OBJCEQ(object.value, val5);

    // Undo should undo everything possible.
    EXPECT_EQ([object.undoManager canUndo], YES);
    [object.undoManager undo];
    EXPECT_EQ([object.undoManager canUndo], YES);
    [object.undoManager undo];
    EXPECT_EQ([object.undoManager canUndo], YES);
    [object.undoManager undo];
    EXPECT_EQ([object.undoManager canUndo], NO);

    // Should do nothing.
    EXPECT_NO_THROW([object.undoManager undo]);
    EXPECT_OBJCEQ(object.value, val2);
}

TEST(NSUndoManager, RunLoopModes) {
    NSNumber* val1 = [NSNumber numberWithInt:1];
    UndoTestObject* object = [[[UndoTestObject alloc] initWithValue:val1] autorelease];
    EXPECT_EQ([object.undoManager.runLoopModes count], 1);
    EXPECT_OBJCEQ([object.undoManager.runLoopModes objectAtIndex:0], NSDefaultRunLoopMode);
}

TEST(NSUndoManager, EmptyUndoGroup) {
    NSUndoManager* manager = [[[NSUndoManager alloc] init] autorelease];
    manager.groupsByEvent = NO;
    [manager beginUndoGrouping];
    [manager endUndoGrouping];

    // An empty undo group will remain in the stack even when closed. This is why canUndo reports yes.
    EXPECT_EQ(manager.canUndo, YES);
}

// Test that when a target is removed, all undo groups are updated properly. If an undo group remains,
// canUndo will be incorrect as an empty undo group results in canUndo being YES.
TEST(NSUndoManager, RemovingOneTarget) {
    NSNumber* target1val1 = [NSNumber numberWithInt:15];
    NSNumber* target1val2 = [NSNumber numberWithInt:16];
    NSNumber* target1val3 = [NSNumber numberWithInt:17];
    NSNumber* target2val1 = [NSNumber numberWithInt:25];
    NSNumber* target2val2 = [NSNumber numberWithInt:26];
    NSNumber* target2val3 = [NSNumber numberWithInt:27];

    NSUndoManager* manager = [[[NSUndoManager alloc] init] autorelease];
    manager.groupsByEvent = NO;

    UndoTestObjectWithSharedManager* firstTargetWithNumbers =
        [[UndoTestObjectWithSharedManager alloc] initWithValue:target1val1 undoManager:manager];
    UndoTestObjectWithSharedManager* secondTargetWithNumbers =
        [[UndoTestObjectWithSharedManager alloc] initWithValue:target2val1 undoManager:manager];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val1); // 15
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val1); // 25

    [manager beginUndoGrouping];
    [secondTargetWithNumbers updateValue:target2val2];
    [manager endUndoGrouping];

    [manager beginUndoGrouping];
    [secondTargetWithNumbers updateValue:target2val3];
    [manager endUndoGrouping];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val1); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 27

    [manager beginUndoGrouping];
    [manager beginUndoGrouping];
    [firstTargetWithNumbers updateValue:target1val2];
    [manager endUndoGrouping];
    [manager endUndoGrouping];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val2); // 16
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 27

    [manager beginUndoGrouping];
    [firstTargetWithNumbers updateValue:target1val3];
    [manager endUndoGrouping];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val3); // 27

    // Should remove the groups containing firstTarget making undo
    [manager removeAllActionsWithTarget:firstTargetWithNumbers];

    [manager undo];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val2); // 27
    EXPECT_EQ(manager.canUndo, YES);

    [manager undo];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val1); // 27
    EXPECT_EQ(manager.canUndo, NO);

    [manager undo];

    EXPECT_OBJCEQ(firstTargetWithNumbers.value, target1val3); // 17
    EXPECT_OBJCEQ(secondTargetWithNumbers.value, target2val1); // 27
}