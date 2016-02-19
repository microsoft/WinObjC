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

@class NSString;

typedef enum {
    CBErrorUnknown = 0,
    CBErrorInvalidParameters = 1,
    CBErrorInvalidHandle = 2,
    CBErrorNotConnected = 3,
    CBErrorOutOfSpace = 4,
    CBErrorOperationCancelled = 5,
    CBErrorConnectionTimeout = 6,
    CBErrorPeripheralDisconnected = 7,
    CBErrorUUIDNotAllowed = 8,
    CBErrorAlreadyAdvertising = 9,
    CBErrorConnectionFailed = 10
} CBError;
typedef enum {
    CBATTErrorSuccess = 0x00,
    CBATTErrorInvalidHandle = 0x01,
    CBATTErrorReadNotPermitted = 0x02,
    CBATTErrorWriteNotPermitted = 0x03,
    CBATTErrorInvalidPdu = 0x04,
    CBATTErrorInsufficientAuthentication = 0x05,
    CBATTErrorRequestNotSupported = 0x06,
    CBATTErrorInvalidOffset = 0x07,
    CBATTErrorInsufficientAuthorization = 0x08,
    CBATTErrorPrepareQueueFull = 0x09,
    CBATTErrorAttributeNotFound = 0x0A,
    CBATTErrorAttributeNotLong = 0x0B,
    CBATTErrorInsufficientEncryptionKeySize = 0x0C,
    CBATTErrorInvalidAttributeValueLength = 0x0D,
    CBATTErrorUnlikelyError = 0x0E,
    CBATTErrorInsufficientEncryption = 0x0F,
    CBATTErrorUnsupportedGroupType = 0x10,
    CBATTErrorInsufficientResources = 0x11,
} CBATTError;

COREBLUETOOTH_EXPORT NSString* const CBErrorDomain;
COREBLUETOOTH_EXPORT NSString* const CBATTErrorDomain;
