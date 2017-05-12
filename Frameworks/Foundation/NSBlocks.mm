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

#import <Foundation/NSObject.h>
#import <objc/blocks_runtime.h>
#import "objc-private.h"
#import "NSBlocksInternal.h"

@implementation _NSBlockAdapter
- (id)copyWithZone:(NSZone*)zone {
    return Block_copy(self);
}

- (id)retain {
    return Block_copy(self);
}

- (oneway void)release {
    Block_release(self);
}

- (void)invoke {
    void (^selfAsBlock)(void) = reinterpret_cast<void (^)(void)>(static_cast<void*>(self));
    selfAsBlock();
}

+ (void)load {
    objc_create_block_classes_as_subclasses_of(self);
}
@end