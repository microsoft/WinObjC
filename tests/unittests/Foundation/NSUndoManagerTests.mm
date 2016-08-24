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

@interface SomeObject : NSObject
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

@implementation SomeObject

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

    SomeObject* object = [[[SomeObject alloc] initWithValue:oldValue] autorelease];
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

    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];
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

    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];
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

    SomeObject* object = [[[SomeObject alloc] initWithEmptyArray] autorelease];
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

    SomeObject* object = [[[SomeObject alloc] initWithValue:oldValue] autorelease];

    [object updateNumber:newValue];
    EXPECT_EQ(object.value.intValue, newValue.intValue);

    [object.undoManager undo];
    EXPECT_EQ(object.value.intValue, oldValue.intValue);
    EXPECT_NO_THROW([object.undoManager undo]);
    EXPECT_EQ(object.value.intValue, oldValue.intValue);
}

TEST(NSUndoManager, IndividualUndoOperations) {
    NSNumber* val1 = [NSNumber numberWithInt:5];
    NSNumber* val2 = [NSNumber numberWithInt:6];
    NSNumber* val3 = [NSNumber numberWithInt:7];
    NSNumber* val4 = [NSNumber numberWithInt:8];

    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];

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
    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];

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

TEST(NSUndoManager, InternalInconsistencyExceptions) {
    NSNumber* val1 = [NSNumber numberWithInt:5];

    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];
    EXPECT_ANY_THROW([object.undoManager endUndoGrouping]);

    object = [[[SomeObject alloc] initWithValue:val1] autorelease];
    [object.undoManager beginUndoGrouping];
    EXPECT_ANY_THROW([object.undoManager undo]);
}

TEST(NSUndoManager, IsRegistrationEnabled) {
    NSNumber* val1 = [NSNumber numberWithInt:5];

    SomeObject* object = [[[SomeObject alloc] initWithValue:val1] autorelease];
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