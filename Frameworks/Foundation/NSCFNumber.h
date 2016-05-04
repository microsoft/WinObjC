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

#import <Foundation/NSNumber.h>

@interface NSNumberPrototype : NSNumber

- (_Nullable instancetype)initWithBool:(BOOL)value;
- (_Nullable instancetype)initWithChar:(char)value;
- (_Nullable instancetype)initWithDouble:(double)value;
- (_Nullable instancetype)initWithFloat:(float)value;
- (_Nullable instancetype)initWithInt:(int)value;
- (_Nullable instancetype)initWithInteger:(NSInteger)value;
- (_Nullable instancetype)initWithLong:(long)value;
- (_Nullable instancetype)initWithLongLong:(long long)value;
- (_Nullable instancetype)initWithShort:(short)value;
- (_Nullable instancetype)initWithUnsignedChar:(unsigned char)value;
- (_Nullable instancetype)initWithUnsignedInt:(unsigned int)value;
- (_Nullable instancetype)initWithUnsignedInteger:(NSUInteger)value;
- (_Nullable instancetype)initWithUnsignedLong:(unsigned long)value;
- (_Nullable instancetype)initWithUnsignedLongLong:(unsigned long long)value;
- (_Nullable instancetype)initWithUnsignedShort:(unsigned short)value;

@end
