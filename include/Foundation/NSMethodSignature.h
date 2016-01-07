//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

FOUNDATION_EXPORT_CLASS
@interface NSMethodSignature : NSObject
+ (NSMethodSignature*)signatureWithObjCTypes:(const char*)types;

- (const char*)getArgumentTypeAtIndex:(NSUInteger)index;

@property (readonly) NSUInteger numberOfArguments;
@property (readonly) NSUInteger frameLength;
@property (readonly) const char* methodReturnType;
@property (readonly) NSUInteger methodReturnLength;

- (BOOL)isOneway STUB_METHOD;
@end
