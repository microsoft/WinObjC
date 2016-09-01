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
#pragma once

#import <Foundation/Foundation.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSUndoManager.h>

@protocol _NSUndoable
@required
- (void)undo:(BOOL)undoAll;
- (BOOL)targets:(id)target;
- (void)removeAllWithTarget:(id)target;
- (NSUInteger)count;
- (BOOL)isClosed;
- (NSUInteger)getNumberOfOpenGroups;

@end

@interface _NSUndoBasicAction : NSObject <_NSUndoable>

- (id)_initWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject modes:(NSArray<NSString*>*)runLoopModes;

@end

@interface _NSUndoGroup : NSObject <_NSUndoable>

- (id)init;
- (void)addUndoable:(id<_NSUndoable>)undoCall;
- (void)createUndoSubGroup;
- (void)closeUndoGroup;
- (BOOL)hasNestedGroup;

@end

@interface _NSUndoManagerStack : NSObject

- (void)pop;
- (void)popBack;
- (id<_NSUndoable>)peek;
- (void)push:(id<_NSUndoable>)undoObject;
- (NSUInteger)count;

@end
