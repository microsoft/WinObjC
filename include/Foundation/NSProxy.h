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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSInvocation;
@class NSMethodSignature;
@class NSString;

// clang format doesn't play well with the first three lines here, so turn it off
// clang-format off
__attribute__((objc_root_class))
FOUNDATION_EXPORT_CLASS
@interface NSProxy <NSObject> {
@public
    Class isa;
}

- (instancetype)init NS_UNAVAILABLE;
+ (id)alloc;
+ (id)allocWithZone:(NSZone*)zone;
- (void)dealloc;
- (void)finalize;
- (void)forwardInvocation:(NSInvocation*)anInvocation;
- (NSMethodSignature*)methodSignatureForSelector:(SEL)aSelector;
+ (BOOL)respondsToSelector:(SEL)aSelector;
+ (Class)class;
+ (Class)superclass; // Not in doc, but is supported
@property (readonly, copy) NSString* description;
@property (readonly, copy) NSString* debugDescription;
@end
