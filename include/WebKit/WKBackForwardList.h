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

#import <WebKit/WebKitExport.h>
#import <Foundation/NSObject.h>

@class WKBackForwardListItem;
@class NSArray;

WEBKIT_EXPORT_CLASS
@interface WKBackForwardList : NSObject
@property (nonatomic, readonly, strong) WKBackForwardListItem* backItem;
@property (nonatomic, readonly, strong) WKBackForwardListItem* currentItem;
@property (nonatomic, readonly, strong) WKBackForwardListItem* forwardItem;
- (WKBackForwardListItem*)itemAtIndex:(NSInteger)index;
@property (nonatomic, readonly, copy) NSArray* backList;
@property (nonatomic, readonly, copy) NSArray* forwardList;
@end
