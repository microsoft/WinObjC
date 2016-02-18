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
#import <StubReturn.h>

@implementation UIPushBehavior
/**
 @Status Stub
 @Notes
*/
- (void)addItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItems:(NSArray*)items mode:(UIPushBehaviorMode)mode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setAngle:(CGFloat)angle magnitude:(CGFloat)magnitude {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setTargetOffsetFromCenter:(UIOffset)o forItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIOffset)targetOffsetFromCenterForItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
