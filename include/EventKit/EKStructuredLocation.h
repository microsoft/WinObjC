//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <EventKit/EventKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class CLLocation;

EVENTKIT_EXPORT_CLASS
@interface EKStructuredLocation : NSObject <NSObject, NSCopying>
+ (EKStructuredLocation*)locationWithTitle:(NSString*)title STUB_METHOD;
@property (retain, nonatomic) NSString* title STUB_PROPERTY;
@property (retain, nonatomic) CLLocation* geoLocation STUB_PROPERTY;
@property (nonatomic) double radius STUB_PROPERTY;
@end
