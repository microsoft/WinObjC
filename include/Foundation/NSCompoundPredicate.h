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

#import <Foundation/NSPredicate.h>
@class NSArray<ObjectType>;

typedef enum {
    NSNotPredicateType = 0,
    NSAndPredicateType,
    NSOrPredicateType,
} NSCompoundPredicateType;

FOUNDATION_EXPORT_CLASS
@interface NSCompoundPredicate : NSPredicate <NSCopying, NSSecureCoding>
+ (NSCompoundPredicate*)andPredicateWithSubpredicates:(NSArray<NSPredicate*>*)subpredicates;
+ (NSCompoundPredicate*)notPredicateWithSubpredicate:(NSPredicate*)predicate;
+ (NSCompoundPredicate*)orPredicateWithSubpredicates:(NSArray<NSPredicate*>*)subpredicates;
- (instancetype)initWithType:(NSCompoundPredicateType)type subpredicates:(NSArray<NSPredicate*>*)subpredicates;
@property (readonly) NSCompoundPredicateType compoundPredicateType;
@property (readonly, copy) NSArray<NSPredicate*>* subpredicates;
@end
