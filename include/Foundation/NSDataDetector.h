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

#import <Foundation/NSRegularExpression.h>
#import <Foundation/NSTextCheckingResult.h>
@class NSError;

FOUNDATION_EXPORT_CLASS
@interface NSDataDetector : NSRegularExpression <NSCoding, NSCopying>
+ (NSDataDetector*)dataDetectorWithTypes:(NSTextCheckingTypes)checkingTypes error:(NSError* _Nullable*)error STUB_METHOD;
- (instancetype)initWithTypes:(NSTextCheckingTypes)checkingTypes error:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly) NSTextCheckingTypes checkingTypes STUB_PROPERTY;
@end
