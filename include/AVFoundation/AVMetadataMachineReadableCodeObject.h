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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVMetadataObject.h>

@class NSString;
@class NSArray;

AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeUPCECode;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeCode39Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeCode39Mod43Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeEAN13Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeEAN8Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeCode93Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeCode128Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypePDF417Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeQRCode;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeAztecCode;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeInterleaved2of5Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeITF14Code;
AVFOUNDATION_EXPORT NSString* const AVMetadataObjectTypeDataMatrixCode;

AVFOUNDATION_EXPORT_CLASS
@interface AVMetadataMachineReadableCodeObject : AVMetadataObject
@property (readonly) NSArray* corners STUB_PROPERTY;
@property (readonly) NSString* stringValue STUB_PROPERTY;
@end
