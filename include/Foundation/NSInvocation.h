//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#import <Foundation/NSObject.h>

@class NSMethodSignature;

FOUNDATION_EXPORT_CLASS
@interface NSInvocation : NSObject

+ (NSInvocation*)invocationWithMethodSignature:(NSMethodSignature*)signature;
@property SEL selector;
@property (assign) id target;
- (void)setArgument:(void*)buffer atIndex:(NSInteger)index;
- (void)getArgument:(void*)buffer atIndex:(NSInteger)index;
@property (readonly) BOOL argumentsRetained;
- (void)retainArguments;
- (void)setReturnValue:(void*)buffer;
- (void)getReturnValue:(void*)buffer;
- (void)invoke;
- (void)invokeWithTarget:(id)anObject;
@property (readonly, retain) NSMethodSignature* methodSignature;
@end
