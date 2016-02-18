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

#import <UIKit/UIKitExport.h>
#import <UIKit/NSTextAttachmentContainer.h>
#import <Foundation/NSObject.h>

@class NSData;
@class NSString;
@class UIImage;
@class NSFileWrapper;

enum { NSAttachmentCharacter = 0xFFFC };

UIKIT_EXPORT_CLASS
@interface NSTextAttachment : NSObject <NSCoding, NSObject, NSTextAttachmentContainer>
- (instancetype)initWithData:(NSData*)contentData ofType:(NSString*)uti STUB_METHOD;
@property (nonatomic) CGRect bounds STUB_PROPERTY;
@property (copy, nonatomic) NSData* contents STUB_PROPERTY;
@property (copy, nonatomic) NSString* fileType STUB_PROPERTY;
@property (nonatomic, strong) UIImage* image STUB_PROPERTY;
@property (nonatomic, strong) NSFileWrapper* fileWrapper STUB_PROPERTY;
@end
