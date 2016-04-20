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

#import <Foundation/NSNumber.h>
#import <Foundation/NSDate.h>

@interface NSExpressionDefaultFunctions : NSObject
- (NSNumber*)sum:(NSArray*)values;
- (NSDate*)now;
- (NSNumber*)plus:(NSNumber*)first second:(NSNumber*)second;
- (NSNumber*)minus:(NSNumber*)first second:(NSNumber*)second;
- (NSNumber*)multiply:(NSNumber*)first second:(NSNumber*)second;
- (NSNumber*)divideBy:(NSNumber*)first second:(NSNumber*)second;
- (NSNumber*)exp:(NSNumber*)base to:(NSNumber*)power;
/*TODO: Add rest of the supported functions in documentation of + (NSExpression *)expressionForFunction:(NSString *)name
                              arguments:(NSArray *)parameters */
@end