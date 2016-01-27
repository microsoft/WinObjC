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

#import <MapKit/MapKitExport.h>
#import <MapKit/MKAnnotation.h>
#import <Foundation/NSObject.h>

@class CLLocation;
@class CLHeading;
@class NSString;

MAPKIT_EXPORT_CLASS
@interface MKUserLocation : NSObject <MKAnnotation, NSObject>
@property (readonly, nonatomic) CLLocation* location STUB_PROPERTY;
@property (readonly, getter=isUpdating, nonatomic) BOOL updating STUB_PROPERTY;
@property (readonly, nonatomic) CLHeading* heading STUB_PROPERTY;
@property (copy, nonatomic) NSString* title STUB_PROPERTY;
@property (copy, nonatomic) NSString* subtitle STUB_PROPERTY;
@end
