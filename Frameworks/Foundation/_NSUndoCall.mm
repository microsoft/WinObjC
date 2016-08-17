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

#import <StubReturn.h>
#import <Foundation/NSUndoManager.h>
#import "_NSUndoCall.h"
#import "_NSUndoObject.h"

NSString* const NSUndoManagerGroupIsDiscardableKey = @"NSUndoManagerGroupIsDiscardableKey";

@implementation _NSUndoCall : _NSUndoObject

- (id)_initWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (self = [super init]) {
        self.undoAction = aSelector;
        self.target = target;
        self.object = [[anObject retain] autorelease];
    }
    return self;
}

- (void)_invokeBasicUndo {
    [self.target performSelector:self.undoAction withObject:self.object];
}

- (BOOL)canUndo {
    return YES;
}

@end
