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

#import <MediaPlayer/MediaPlayerExport.h>
#import <MediaPlayer/MPMediaPredicate.h>

@class NSString;

typedef NS_ENUM(NSUInteger, MPMediaPredicateComparison) { MPMediaPredicateComparisonEqualTo, MPMediaPredicateComparisonContains };

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaPropertyPredicate : MPMediaPredicate <NSSecureCoding>

+ (MPMediaPropertyPredicate*)predicateWithValue:(id)predicateWithValue forProperty:(NSString*)forProperty STUB_METHOD;
+ (MPMediaPropertyPredicate*)predicateWithValue:(id)predicateWithValue
                                    forProperty:(NSString*)forProperty
                                 comparisonType:(MPMediaPredicateComparison)comparisonType STUB_METHOD;

@property (readonly, copy, nonatomic) NSString* property STUB_PROPERTY;
@property (readonly, copy, nonatomic) id value STUB_PROPERTY;
@property (readonly, nonatomic) MPMediaPredicateComparison comparisonType STUB_PROPERTY;

@end
