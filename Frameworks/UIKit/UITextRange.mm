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

#import <UIKit/UIKit.h>
#import <Starboard.h>

@interface UITextRange () {
    StrongId<UITextPosition> _start, _end;
    BOOL _empty;
}
@end

@implementation UITextRange
+ (instancetype)textRangeWithPositon:(int)position length:(int)length {
    UITextRange* ret = [self alloc];

    ret->_start.attach([UITextPosition new]);
    ret->_end.attach([UITextPosition new]);
    ret->_empty = length == 0;

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (BOOL)isEmpty {
    return _empty;
}

/**
 @Status Interoperable
*/
- (UITextPosition*)start {
    return _start;
}

/**
 @Status Interoperable
*/
- (UITextPosition*)end {
    return _end;
}
@end
