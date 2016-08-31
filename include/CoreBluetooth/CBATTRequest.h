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

#import <CoreBluetooth/CoreBluetoothExport.h>

#import <Foundation/Foundation.h>

@class CBCentral;
@class CBCharacteristic;
@class NSData;

COREBLUETOOTH_EXPORT_CLASS
@interface CBATTRequest : NSObject <NSObject>
@property (readonly, retain, nonatomic) CBCentral* central STUB_PROPERTY;
@property (readonly, retain, nonatomic) CBCharacteristic* characteristic STUB_PROPERTY;
@property (readwrite, copy) NSData* value STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger offset STUB_PROPERTY;
@end
