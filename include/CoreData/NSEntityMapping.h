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

@class NSString;
@class NSData;
@class NSExpression;
@class NSArray;
@class NSDictionary;

typedef NS_ENUM(NSUInteger, NSEntityMappingType) {
    NSUndefinedEntityMappingType = 0x00,
    NSCustomEntityMappingType = 0x01,
    NSAddEntityMappingType = 0x02,
    NSRemoveEntityMappingType = 0x03,
    NSCopyEntityMappingType = 0x04,
    NSTransformEntityMappingType = 0x05
};

COREDATA_EXPORT_CLASS
@interface NSEntityMapping : NSObject
@property (copy) NSString* sourceEntityName STUB_PROPERTY;
@property (copy) NSData* sourceEntityVersionHash STUB_PROPERTY;
@property (strong) NSExpression* sourceExpression STUB_PROPERTY;
@property (copy) NSString* destinationEntityName STUB_PROPERTY;
@property (copy) NSData* destinationEntityVersionHash STUB_PROPERTY;
@property (copy) NSString* name STUB_PROPERTY;
@property NSEntityMappingType mappingType STUB_PROPERTY;
@property (copy) NSString* entityMigrationPolicyClassName STUB_PROPERTY;
@property (strong) NSArray* attributeMappings STUB_PROPERTY;
@property (strong) NSArray* relationshipMappings STUB_PROPERTY;
@property (nonatomic, strong) NSDictionary* userInfo STUB_PROPERTY;
@end
