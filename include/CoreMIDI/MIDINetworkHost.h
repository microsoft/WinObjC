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

@class NSString;
@class NSNetService;

COREMIDI_EXPORT NSString* const MIDINetworkBonjourServiceType;
COREMIDI_EXPORT_CLASS
@interface MIDINetworkHost : NSObject
@property (readonly, retain, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* address STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger port STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* netServiceName STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* netServiceDomain STUB_PROPERTY;
+ (instancetype)hostWithName:(NSString*)name address:(NSString*)address port:(NSUInteger)port STUB_METHOD;
+ (instancetype)hostWithName:(NSString*)name netService:(NSNetService*)netService STUB_METHOD;
+ (instancetype)hostWithName:(NSString*)name
              netServiceName:(NSString*)netServiceName
            netServiceDomain:(NSString*)netServiceDomain STUB_METHOD;
- (BOOL)hasSameAddressAs:(MIDINetworkHost*)other STUB_METHOD;
@end
