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

#import <vector>
#import "Foundation/NSMutableIndexSet.h"

@interface NSMutableIndexSet (Internal)

- (unsigned)_positionOfRangeGreaterThanOrEqualToLocation:(NSUInteger)location;
- (unsigned)_positionOfRangeLessThanOrEqualToLocation:(NSUInteger)location;
- (unsigned)_count;
- (NSRange)_itemAtIndex:(unsigned)index;
- (NSRange&)_itemReferenceAtIndex:(unsigned)index;
- (void)_insertItem:(NSRange)range AtIndex:(unsigned)position;
- (void)_addItem:(NSRange)range;
- (void)_removeItemAtIndex:(unsigned)position;
- (void)_removeRanges:(NSRange)ranges;
- (NSRangePointer)_allRanges;
@end
