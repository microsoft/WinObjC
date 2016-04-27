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

@class NSString;
@class NSArray<ObjectType>;
@class NSDictionary<KeyType, ObjectType>;

FOUNDATION_EXPORT_CLASS
@interface NSPredicate : NSObject <NSCopying, NSSecureCoding>
+ (NSPredicate*)predicateWithFormat:(NSString*)format, ...;
+ (NSPredicate*)predicateWithFormat:(NSString*)predicateFormat argumentArray:(NSArray*)arguments;
+ (NSPredicate*)predicateWithFormat:(NSString*)format arguments:(va_list)argList;
- (instancetype)predicateWithSubstitutionVariables:(NSDictionary*)variables;
+ (NSPredicate*)predicateWithValue:(BOOL)value;
+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id, NSDictionary<NSString*, id>*))block;
- (BOOL)evaluateWithObject:(id)object;
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary<NSString*, id>*)variables;
- (void)allowEvaluation;
@property (readonly, copy) NSString* predicateFormat;
@end
