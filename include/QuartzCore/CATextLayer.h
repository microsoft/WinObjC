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
#pragma once

#import <QuartzCore/CoreAnimationExport.h>
#import <QuartzCore/CALayer.h>

CA_EXPORT NSString* const kCATruncationNone;
CA_EXPORT NSString* const kCATruncationStart;
CA_EXPORT NSString* const kCATruncationEnd;
CA_EXPORT NSString* const kCATruncationMiddle;
CA_EXPORT NSString* const kCAAlignmentNatural;
CA_EXPORT NSString* const kCAAlignmentLeft;
CA_EXPORT NSString* const kCAAlignmentRight;
CA_EXPORT NSString* const kCAAlignmentCenter;
CA_EXPORT NSString* const kCAAlignmentJustified;

CA_EXPORT_CLASS
@interface CATextLayer : CALayer <CAMediaTiming, NSCoding>

@property (copy) id string STUB_PROPERTY;
@property CFTypeRef font STUB_PROPERTY;
@property CGFloat fontSize STUB_PROPERTY;
@property CGColorRef foregroundColor STUB_PROPERTY;
@property (getter=isWrapped) BOOL wrapped STUB_PROPERTY;
@property (copy) NSString* alignmentMode STUB_PROPERTY;
@property (copy) NSString* truncationMode STUB_PROPERTY;

@end
