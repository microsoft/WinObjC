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

#import <UIKit/NSIndexPath+UITableView.h>

void NSIndexPathForceInclude() {
    [NSIndexPath class];
}

@implementation NSIndexPath (UITableView)

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathForRow:(NSInteger)row inSection:(NSInteger)section {
    if (row < 0 || section < 0) {
        return [[[self alloc] initWithIndexes:nullptr length:0] autorelease];
    }

    NSUInteger indexes[] = { section, row };
    return [[[self alloc] initWithIndexes:indexes length:2] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathForItem:(NSInteger)item inSection:(NSInteger)section {
    if (item < 0 || section < 0) {
        return [[[self alloc] initWithIndexes:nullptr length:0] autorelease];
    }

    NSUInteger indexes[] = { section, item };
    return [[[self alloc] initWithIndexes:indexes length:2] autorelease];
}

/**
 @Status Interoperable
*/
- (NSInteger)item {
    return [self indexAtPosition:1];
}

/**
 @Status Interoperable
*/
- (NSInteger)row {
    return [self indexAtPosition:1];
}

/**
 @Status Interoperable
*/
- (NSInteger)section {
    return [self indexAtPosition:0];
}

@end
