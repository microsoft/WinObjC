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

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

FOUNDATION_EXPORT_CLASS
@interface NSValue : NSObject <NSCopying, NSSecureCoding>
@property(readonly) NSRange rangeValue;
@property(readonly) __unsafe_unretained id nonretainedObjectValue;
@property(readonly) void* pointerValue;
@property(readonly) const char* objCType;

- (NSValue*)initWithBytes:(const void*)value objCType:(const char*)type;
+ (NSValue*)valueWithBytes:(const void*)value objCType:(const char*)type;
+ (NSValue*)value:(const void*)value withObjCType:(const char*)type;
- (void)getValue:(void*)value;

/* Pointer Values */
+ (NSValue*)valueWithPointer:(const void*)pointer;
+ (NSValue*)valueWithNonretainedObject:(__unsafe_unretained id)object;

/* Range Values */
+ (NSValue*)valueWithRange:(NSRange)range;
- (BOOL)isEqualToValue:(NSValue*)other;

@end
