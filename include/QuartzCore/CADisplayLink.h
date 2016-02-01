//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <QuartzCore/CoreAnimationExport.h>
#import <Foundation/NSObject.h>
#import <CoreFoundation/CFDate.h>

enum CADisplayLinkRunMode {
    CADisplayLinkSyncMode,
    CADisplayLinkTimerMode,
};

@class NSRunLoop;
@class NSRunLoopSource;

CA_EXPORT_CLASS
@interface CADisplayLink : NSObject

+ (CADisplayLink*)displayLinkWithTarget:(id)target selector:(SEL)sel;
- (void)addToRunLoop:(NSRunLoop*)runloop forMode:(NSString*)mode;
- (void)removeFromRunLoop:(NSRunLoop*)runloop forMode:(NSString*)mode;
- (void)invalidate;
@property (readonly, nonatomic) CFTimeInterval duration;
@property (nonatomic) NSInteger frameInterval;
@property (getter=isPaused, nonatomic) BOOL paused;
@property (readonly, nonatomic) CFTimeInterval timestamp;

@end