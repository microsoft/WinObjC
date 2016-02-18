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

#import <UIKit/UIKit.h>
#import <StubReturn.h>

@implementation UIPrintPageRenderer
/**
 @Status Stub
 @Notes
*/
- (NSInteger)numberOfPages {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addPrintFormatter:(UIPrintFormatter*)formatter startingAtPageAtIndex:(NSInteger)pageIndex {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)printFormattersForPageAtIndex:(NSInteger)pageIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)prepareForDrawingPages:(NSRange)range {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawPageAtIndex:(NSInteger)index inRect:(CGRect)pageRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawHeaderForPageAtIndex:(NSInteger)index inRect:(CGRect)headerRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawContentForPageAtIndex:(NSInteger)index inRect:(CGRect)contentRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawPrintFormatter:(UIPrintFormatter*)printFormatter forPageAtIndex:(NSInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawFooterForPageAtIndex:(NSInteger)index inRect:(CGRect)footerRect {
    UNIMPLEMENTED();
}

@end
