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

#import <Foundation/Foundation.h>

@interface THRunLoopSpinner : NSObject
@property (nonatomic, readonly) NSRunLoop* runLoop;
- (void)scheduleAndAwaitBlock:(void (^)())block;
@end

// Convenience class that wraps an NSCondition and an associated boolean, and implements the NSCondition usage pattern documented in:
// https://developer.apple.com/reference/foundation/nscondition?language=objc
// This can be replaced/re-implemented based on NSConditionLock once that has a stable implementation
@interface THBooleanCondition : NSObject
- (BOOL)waitUntilDate:(NSDate*)limit;
- (void)broadcast;
- (void)signal;
@property (readonly) NSCondition* condition;
@property (readonly) bool isOpen;
@end
