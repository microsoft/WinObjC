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

#import <EventKit/EKObject.h>
#import <EventKit/EventKitExport.h>

#import <Foundation/NSObject.h>

@class NSString;
@class NSSet;

typedef enum {
    EKSourceTypeLocal,
    EKSourceTypeExchange,
    EKSourceTypeCalDAV,
    EKSourceTypeMobileMe,
    EKSourceTypeSubscribed,
    EKSourceTypeBirthdays
} EKSourceType;

enum EKEntities { EKEntityTypeEvent, EKEntityTypeReminder };
typedef enum EKEntities EKEntityType;
typedef enum EKEntities EKEntityMask;

EVENTKIT_EXPORT_CLASS
@interface EKSource : EKObject <NSObject>
@property (readonly, nonatomic) NSString* sourceIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) EKSourceType sourceType STUB_PROPERTY;
@property (readonly, nonatomic) NSString* title STUB_PROPERTY;
@property (readonly, nonatomic) NSSet* calendars STUB_PROPERTY;
- (NSSet*)calendarsForEntityType:(EKEntityType)entityType STUB_METHOD;
@end
