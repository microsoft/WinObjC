/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSENUMERATOR_H_
#define _NSENUMERATOR_H_

#import <Foundation/NSObject.h>

@class NSArray;

// NSFastEnumerationState stores the state of a given reentrant NSFastEnumeration-compliant method call.
typedef struct {
    // State that is unique to the collection being enumerated.
    unsigned long state;
    // Contiguous storage for N objects, where N is provided by a call to countByEnumeratingWithState:objects:count:.
    id __unsafe_unretained *itemsPtr;
    // A pointer to track mutations to the underlying collection. During a ranged for, the compiler will compare this across iterations.
    // If it changes, an exception will be thrown.
    unsigned long *mutationsPtr;
    // Extra storage unique to the collection that is being enumerated.
    unsigned long extra[5];
} NSFastEnumerationState;

@protocol NSFastEnumeration
// Returns via the passed-in NSFastEnumerationState a buffer containing N Objective-C contiguous object pointers. The provided buffer and count are used only as temporary storage
// when the NSFastEnumeration-conforming object cannot provide its own contiguous storage. The return value of this method is the number of objects in (id[])state->itemsPtr.
//
// This method should, at the very least, populate state->itemsPtr and return the number of objects in contiguous storage there.
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained [])stackbuf count:(NSUInteger)length;
@end

typedef void (*initIteratorFunc)(id obj, void *enumeratorHolder);
typedef int (*nextValueFunc)(id obj, void *enumeratorHolder, id *ret, int count);

FOUNDATION_EXPORT_CLASS
@interface NSEnumerator : NSObject <NSFastEnumeration> {
    NSArray* objArray;
    int curIndex;
    int dir;

    nextValueFunc getNextValueFunction;
    id iteratorObj;
    NSUInteger iteratorState[5];
}

- (id)nextObject;
- (NSArray *)allObjects;

@end

#endif /* _NSENUMERATOR_H_ */
