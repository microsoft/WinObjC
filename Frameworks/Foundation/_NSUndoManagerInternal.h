//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
- (void)undo;
- (BOOL)canUndo;

@end

@interface _NSUndoBasicAction : NSObject <_NSUndoable>

- (id)_initWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject;

@end

@interface _NSUndoGroup : NSObject <_NSUndoable>

- (id)initWithLevel:(NSUInteger)level;
- (id)initWithOwner:(NSUndoManager*)manager;
- (void)addUndoCallToUndoGroup:(_NSUndoBasicAction*)undoCall;
- (NSUInteger)createUndoGroup;
- (BOOL)closeUndoGroup;

@end