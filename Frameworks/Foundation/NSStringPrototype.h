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
#include <Foundation/NSString.h>
#include "NSStringAdditionsForCF.h"

@interface NSStringPrototype : NSString

- (instancetype)init;
- (instancetype)initWithCString:(const char*)cStr length:(NSUInteger)length;
- (instancetype)initWithUTF8String:(const char*)utf8str;
- (instancetype)initWithFormat:(id)formatStr arguments:(va_list)pReader;
- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding;
- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                           encoding:(NSStringEncoding)encoding
                       freeWhenDone:(BOOL)freeWhenDone;
- (instancetype)initWithCharacters:(const unichar*)bytes length:(NSUInteger)length;
- (instancetype)initWithCharactersNoCopy:(unichar*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone;
- (instancetype)initWithCString:(const char*)bytes encoding:(NSStringEncoding)encoding;
- (instancetype)initWithString:(NSString*)otherStr;

@end