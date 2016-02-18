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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSLocking.h>
#import <Foundation/NSObject.h>

@class NSDate;
@class NSString;

FOUNDATION_EXPORT_CLASS
@interface NSConditionLock : NSObject <NSLocking>
- (instancetype)initWithCondition:(NSInteger)condition;
@property (readonly) NSInteger condition;
- (BOOL)lockBeforeDate:(NSDate*)limit;
- (void)lockWhenCondition:(NSInteger)condition;
- (BOOL)lockWhenCondition:(NSInteger)condition beforeDate:(NSDate*)limit;
- (BOOL)tryLock;
- (BOOL)tryLockWhenCondition:(NSInteger)condition;
- (void)unlockWithCondition:(NSInteger)condition;
@property (copy) NSString* name;
@end
