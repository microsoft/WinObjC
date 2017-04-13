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
#import <Foundation/NSObject.h>

#import <Foundation/NSOperation.h>
@class NSString;
@class NSInvocation;

FOUNDATION_EXPORT NSString* const NSInvocationOperationVoidResultException;
FOUNDATION_EXPORT NSString* const NSInvocationOperationCancelledException;

FOUNDATION_EXPORT_CLASS
@interface NSInvocationOperation : NSOperation
- (instancetype)initWithTarget:(id)target selector:(SEL)sel object:(id)arg;
- (instancetype)initWithInvocation:(NSInvocation*)invocation;
@property (readonly, retain) NSInvocation* invocation;
@property (readonly, retain) id result;
@end
