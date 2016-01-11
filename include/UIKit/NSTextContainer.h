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

#ifndef _NSTEXTCONTAINER_H_
#define _NSTEXTCONTAINER_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <UIKit/NSStringDrawing.h>
#import <UIKit/NSParagraphStyle.h>

@class NSArray;
@class NSLayoutManager;

UIKIT_EXPORT_CLASS
@interface NSTextContainer : NSObject

@property (copy, nonatomic) NSArray* exclusionPaths;
@property (nonatomic) NSInteger maximumNumberOfLines;
@property (nonatomic) CGFloat lineFragmentPadding;
@property (nonatomic) NSLineBreakMode lineBreakMode;
@property (assign, nonatomic) NSLayoutManager* layoutManager;
@property (nonatomic) CGSize size;

- (instancetype)initWithSize:(CGSize)size;
- (CGRect)lineFragmentRectForProposedRect:(CGRect)proposed
                                  atIndex:(NSUInteger)idx
                         writingDirection:(NSWritingDirection)direction
                            remainingRect:(CGRect*)remainingRect;
@end

#endif /* _NSTEXTCONTAINER_H_ */
