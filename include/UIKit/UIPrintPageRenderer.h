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
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/Foundation.h>

@class UIPrintFormatter;

UIKIT_EXPORT_CLASS
@interface UIPrintPageRenderer : NSObject
- (NSInteger)numberOfPages STUB_METHOD;
@property (readonly, nonatomic) CGRect paperRect STUB_PROPERTY;
@property (readonly, nonatomic) CGRect printableRect STUB_PROPERTY;
@property (nonatomic) CGFloat headerHeight STUB_PROPERTY;
@property (nonatomic) CGFloat footerHeight STUB_PROPERTY;
- (void)addPrintFormatter:(UIPrintFormatter*)formatter startingAtPageAtIndex:(NSInteger)pageIndex STUB_METHOD;
- (NSArray*)printFormattersForPageAtIndex:(NSInteger)pageIndex STUB_METHOD;
@property (copy, nonatomic) NSArray* printFormatters STUB_PROPERTY;
- (void)prepareForDrawingPages:(NSRange)range STUB_METHOD;
- (void)drawPageAtIndex:(NSInteger)index inRect:(CGRect)pageRect STUB_METHOD;
- (void)drawHeaderForPageAtIndex:(NSInteger)index inRect:(CGRect)headerRect STUB_METHOD;
- (void)drawContentForPageAtIndex:(NSInteger)index inRect:(CGRect)contentRect STUB_METHOD;
- (void)drawPrintFormatter:(UIPrintFormatter*)printFormatter forPageAtIndex:(NSInteger)index STUB_METHOD;
- (void)drawFooterForPageAtIndex:(NSInteger)index inRect:(CGRect)footerRect STUB_METHOD;
@end
