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

#import <UIKit/NSMutableParagraphStyle.h>
#import <StubReturn.h>
#import "NSParagraphStyleInternal.h"

@implementation NSMutableParagraphStyle

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSParagraphStyle* ret = [NSParagraphStyle new];
    [ret _setParagraphStyle:self];
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (void)setParagraphStyle:(NSParagraphStyle*)obj {
    [self _setParagraphStyle:obj];
}

/**
 @Status Stub
 @Notes
*/
- (void)addTabStop:(NSTextTab*)anObject {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTabStop:(NSTextTab*)anObject {
    UNIMPLEMENTED();
}

@end