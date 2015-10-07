//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef __COREBLUETOOTH_H
#define __COREBLUETOOTH_H

#import <CoreBluetooth/CoreBluetoothExport.h>
#import <Foundation/NSObject.h>

typedef uint32_t CBCentralManagerState;

typedef enum
{
    CBCentralManagerStateUnsupported,
    CBCentralManagerStatePoweredOn,
    CBCentralManagerStatePoweredOff
};

@protocol CBCentralManagerDelegate
@end

COREBLUETOOTH_EXPORT
@interface CBCentralManager : NSObject {
}
@property(readonly) CBCentralManagerState state;

-(instancetype) initWithDelegate: (id) delegate queue: (id) queue;
@end

#endif