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
#import <CoreData/NSPropertyDescription.h>

@class NSEntityDescription;
@class NSData;

typedef NS_ENUM(NSUInteger, NSDeleteRule) { NSNoActionDeleteRule, NSNullifyDeleteRule, NSCascadeDeleteRule, NSDenyDeleteRule };

COREDATA_EXPORT_CLASS
@interface NSRelationshipDescription : NSPropertyDescription <NSCoding, NSCopying>
@property (assign, nonatomic) NSEntityDescription* destinationEntity;
@property (assign, nonatomic) NSRelationshipDescription* inverseRelationship;
@property NSDeleteRule deleteRule;
@property NSUInteger maxCount;
@property NSUInteger minCount;
@property (readonly, getter=isToMany) BOOL toMany;
@property (getter=isOrdered) BOOL ordered;
@property (readonly, copy) NSData* versionHash STUB_PROPERTY;
@end
