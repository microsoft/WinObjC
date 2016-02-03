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

#import <CoreData/CoreDataExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSExpression.h>

enum { NSFetchRequestExpressionType = 50 };

COREDATA_EXPORT_CLASS
@interface NSFetchRequestExpression : NSExpression <NSCopying, NSObject, NSSecureCoding>
+ (NSExpression*)expressionForFetch:(NSExpression*)fetch context:(NSExpression*)context countOnly:(BOOL)countFlag STUB_METHOD;
@property (readonly, strong) NSExpression* requestExpression STUB_PROPERTY;
@property (readonly, strong) NSExpression* contextExpression STUB_PROPERTY;
@property (readonly, getter=isCountOnlyRequest) BOOL countOnlyRequest STUB_PROPERTY;
@end
