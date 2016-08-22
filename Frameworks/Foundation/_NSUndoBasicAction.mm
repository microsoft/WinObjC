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

#import <Starboard.h>
#import <StubReturn.h>
#import "_NSUndoManagerInternal.h"
#import <objc/objc-arc.h>

@implementation _NSUndoBasicAction {
    StrongId<id> _object;
    id _target;
    SEL _undoAction;
}

- (id)_initWithTarget:(id)target selector:(SEL)aSelector object:(id)anObject {
    if (self = [super init]) {
        _undoAction = aSelector;
        _target = objc_storeWeak(&_target, target);
        _object = [anObject retain];
    }
    return self;
}

- (void)undo {
    [objc_loadWeak(&_target) performSelector:_undoAction withObject:_object];
}

- (BOOL)canUndo {
    return YES;
}

- (void)dealloc {
    [_object release];
    objc_destroyWeak(&_target);
}

- (bool)isClosed {
    return YES;
}

@end
