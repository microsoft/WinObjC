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

#import <Social/SocialExport.h>
#import <Foundation/NSObject.h>

@class NSString;

typedef void (^SLComposeSheetConfigurationItemTapHandler)(void);

SOCIAL_EXPORT_CLASS
@interface SLComposeSheetConfigurationItem : NSObject
@property (copy, nonatomic) SLComposeSheetConfigurationItemTapHandler tapHandler STUB_PROPERTY;
@property (copy, nonatomic) NSString* title STUB_PROPERTY;
@property (copy, nonatomic) NSString* value STUB_PROPERTY;
@property (assign, nonatomic) BOOL valuePending STUB_PROPERTY;
- (instancetype)init STUB_METHOD;
@end
