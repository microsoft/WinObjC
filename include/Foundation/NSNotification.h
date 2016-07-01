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
@class NSDictionary;

FOUNDATION_EXPORT_CLASS
@interface NSNotification : NSObject <NSCoding, NSCopying>
+ (instancetype)notificationWithName:(NSString*)aName object:(id)anObject;
+ (instancetype)notificationWithName:(NSString*)aName object:(id)anObject userInfo:(NSDictionary*)userInfo;
- (instancetype)initWithName:(NSString*)aName object:(id)object userInfo:(NSDictionary*)userInfo;
@property (readonly, copy) NSString* name;
@property (readonly, retain) id object;
@property (readonly, copy) NSDictionary* userInfo;
@end
