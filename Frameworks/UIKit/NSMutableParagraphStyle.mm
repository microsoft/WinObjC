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
    return [self mutableCopyWithZone:zone];
}

/**
 @Status Interoperable
 @Notes
*/
- (void)setParagraphStyle:(NSParagraphStyle*)obj {
    self.alignment = obj.alignment;
    self.firstLineHeadIndent = obj.firstLineHeadIndent;
    self.headIndent = obj.headIndent;
    self.tailIndent = obj.tailIndent;
    self.lineBreakMode = obj.lineBreakMode;
    self.maximumLineHeight = obj.maximumLineHeight;
    self.minimumLineHeight = obj.minimumLineHeight;
    self.lineSpacing = obj.lineSpacing;
    self.paragraphSpacing = obj.paragraphSpacing;
    self.paragraphSpacingBefore = obj.paragraphSpacingBefore;
    self.baseWritingDirection = obj.baseWritingDirection;
    self.lineHeightMultiple = obj.lineHeightMultiple;
    self.tabStops = obj.tabStops;
    self.defaultTabInterval = obj.defaultTabInterval;
    self.hyphenationFactor = obj.hyphenationFactor;
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