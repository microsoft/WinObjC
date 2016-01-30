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

#import <CoreBluetooth/CoreBluetoothExport.h>
#import <CoreBluetooth/CBService.h>

#import <Foundation/NSObject.h>

@class CBUUID;
@class NSArray;

COREBLUETOOTH_EXPORT_CLASS
@interface CBMutableService : CBService
- (instancetype)initWithType:(CBUUID*)UUID primary:(BOOL)isPrimary STUB_METHOD;
@property (readwrite, retain, nonatomic) CBUUID* UUID STUB_PROPERTY;
@property (readwrite, nonatomic) BOOL isPrimary STUB_PROPERTY;
@property (readwrite, retain) NSArray* characteristics STUB_PROPERTY;
@property (readwrite, retain) NSArray* includedServices STUB_PROPERTY;
@end
