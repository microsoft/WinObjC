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

#import <StubReturn.h>
#import <WebKit/WKWebView.h>

@implementation WKWebView
/**
@Status Stub
@Notes
*/
- (instancetype)initWithFrame:(CGRect)frame configuration:(WKWebViewConfiguration*)configuration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)reload {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)reloadFromOrigin {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)stopLoading {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)loadData:(NSData*)data
                 MIMEType:(NSString*)MIMEType
    characterEncodingName:(NSString*)characterEncodingName
                  baseURL:(NSURL*)baseURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)loadFileURL:(NSURL*)URL allowingReadAccessToURL:(NSURL*)readAccessURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)goBack {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)goForward {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)goToBackForwardListItem:(WKBackForwardListItem*)item {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (WKNavigation*)loadRequest:(NSURLRequest*)request {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^)(id, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setNeedsFocusUpdate {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)updateFocusIfNeeded {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)shouldUpdateFocusInContext:(UIFocusUpdateContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)didUpdateFocusInContext:(UIFocusUpdateContext*)context withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (CGPoint)convertPoint:(CGPoint)point toCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (CGPoint)convertPoint:(CGPoint)point fromCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (CGRect)convertRect:(CGRect)rect toCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (CGRect)convertRect:(CGRect)rect fromCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
    UNIMPLEMENTED();
}
@end
