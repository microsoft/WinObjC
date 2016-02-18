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
#pragma once

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/FoundationExport.h>

// NSFastEnumerationState stores the state of a given reentrant NSFastEnumeration-compliant method call.
typedef struct {
    // State that is unique to the collection being enumerated.
    unsigned long state;
    // Contiguous storage for N objects, where N is provided by a call to countByEnumeratingWithState:objects:count:.
    id __unsafe_unretained* itemsPtr;
    // A pointer to track mutations to the underlying collection. During a ranged for, the compiler will compare this across iterations.
    // If it changes, an exception will be thrown.
    unsigned long* mutationsPtr;
    // Extra storage unique to the collection that is being enumerated.
    unsigned long extra[5];
} NSFastEnumerationState;

@protocol NSFastEnumeration
// Returns via the passed-in NSFastEnumerationState a buffer containing N Objective-C contiguous object pointers. The provided buffer and count are used only as temporary storage
// when the NSFastEnumeration-conforming object cannot provide its own contiguous storage. The return value of this method is the number of objects in (id[])state->itemsPtr.
//
// This method should, at the very least, populate state->itemsPtr and return the number of objects in contiguous storage there.
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained _Nonnull [])stackbuf count:(NSUInteger)length;
@end
