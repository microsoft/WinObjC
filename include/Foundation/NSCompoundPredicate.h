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

#ifndef _NSCOMPOUNDPREDICATE_H_
#define _NSCOMPOUNDPREDICATE_H_

#import <Foundation/NSPredicate.h>

typedef NS_ENUM(NSInteger, NSCompoundPredicateType) {
    NSNotPredicateType = 0,
    NSAndPredicateType,
    NSOrPredicateType,
};

FOUNDATION_EXPORT_CLASS
@interface NSCompoundPredicate : NSPredicate <NSSecureCoding, NSCopying>

- (instancetype)initWithType:(NSCompoundPredicateType)type subpredicates:(NSArray*)subpredicates;

+ (NSCompoundPredicate*)notPredicateWithSubpredicate:(NSPredicate*)predicate;
+ (NSCompoundPredicate*)andPredicateWithSubpredicates:(NSArray*)subpredicates;
+ (NSCompoundPredicate*)orPredicateWithSubpredicates:(NSArray*)subpredicates;

@property (readonly) NSCompoundPredicateType compoundPredicateType;
@property (readonly, copy) NSArray* subpredicates;

@end

#endif /* _NSCOMPOUNDPREDICATE_H_ */