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
#include "BridgeHelpers.h"
#include <Foundation/NSMutableCharacterSet.h>

#pragma region NSCharacterSetConcrete

@interface NSCharacterSetConcrete : NSMutableCharacterSet

- (instancetype)init;

// NSCharacterSet
- (BOOL)characterIsMember:(unichar)aCharacter;
- (BOOL)hasMemberInPlane:(uint8_t)thePlane;
- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet;
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;
@property (readonly, copy) NSCharacterSet* invertedSet;
@property (readonly, copy) NSData* bitmapRepresentation;

@end

#pragma endregion

#pragma region NSMutableCharacterSetConcrete

@interface NSMutableCharacterSetConcrete : NSMutableCharacterSet

- (instancetype)init;

// NSCharacterSet
- (BOOL)characterIsMember:(unichar)aCharacter;
- (BOOL)hasMemberInPlane:(uint8_t)thePlane;
- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet;
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;
@property (readonly, copy) NSCharacterSet* invertedSet;
@property (readonly, copy) NSData* bitmapRepresentation;

// NSMutableCharacterSet
- (void)addCharactersInRange:(NSRange)aRange;
- (void)removeCharactersInRange:(NSRange)aRange;
- (void)addCharactersInString:(NSString*)aString;
- (void)removeCharactersInString:(NSString*)aString;
- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)otherSet;
- (void)formUnionWithCharacterSet:(NSCharacterSet*)otherSet;
- (void)invert;

@end

#pragma endregion

#pragma region NSCFCharacterSet

@interface NSCFCharacterSet : NSMutableCharacterSet

BRIDGED_CLASS_REQUIRED_DECLS

// NSCharacterSet
- (BOOL)characterIsMember:(unichar)aCharacter;
- (BOOL)hasMemberInPlane:(uint8_t)thePlane;
- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet;
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;
@property (readonly, copy) NSCharacterSet* invertedSet;
@property (readonly, copy) NSData* bitmapRepresentation;

// NSMutableCharacterSet
- (void)addCharactersInRange:(NSRange)aRange;
- (void)removeCharactersInRange:(NSRange)aRange;
- (void)addCharactersInString:(NSString*)aString;
- (void)removeCharactersInString:(NSString*)aString;
- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)otherSet;
- (void)formUnionWithCharacterSet:(NSCharacterSet*)otherSet;
- (void)invert;

@end

#pragma endregion