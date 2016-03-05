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

#import <CoreMIDI/CoreMIDIExport.h>
#import <Foundation/NSObject.h>
#import <CoreMIDI/MIDIServices.h>

@class NSString;
@class NSSet;
@class MIDINetworkHost;
@class MIDINetworkConnection;

typedef NSUInteger MIDINetworkConnectionPolicy;
enum { MIDINetworkConnectionPolicy_NoOne = 0, MIDINetworkConnectionPolicy_HostsInContactList = 1, MIDINetworkConnectionPolicy_Anyone = 2 };
enum { MIDINetworkNotificationContactsDidChange = 1, MIDINetworkNotificationSessionDidChange = 2 };

COREMIDI_EXPORT_CLASS
@interface MIDINetworkSession : NSObject
+ (MIDINetworkSession*)defaultSession STUB_METHOD;
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger networkPort STUB_PROPERTY;
@property (readonly, nonatomic) NSString* networkName STUB_PROPERTY;
@property (readonly, nonatomic) NSString* localName STUB_PROPERTY;
@property (nonatomic) MIDINetworkConnectionPolicy connectionPolicy STUB_PROPERTY;
- (MIDIEndpointRef)sourceEndpoint STUB_METHOD;
- (MIDIEndpointRef)destinationEndpoint STUB_METHOD;
- (NSSet*)contacts STUB_METHOD;
- (BOOL)addContact:(MIDINetworkHost*)contact STUB_METHOD;
- (BOOL)removeContact:(MIDINetworkHost*)contact STUB_METHOD;
- (NSSet*)connections STUB_METHOD;
- (BOOL)addConnection:(MIDINetworkConnection*)connection STUB_METHOD;
- (BOOL)removeConnection:(MIDINetworkConnection*)connection STUB_METHOD;
@end
