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

#import <iAd/ADBannerView.h>
#import <StubReturn.h>

NSString* const ADBannerContentSizeIdentifier320x50 = @"ADBannerContentSizeIdentifier320x50";
NSString* const ADBannerContentSizeIdentifier480x32 = @"ADBannerContentSizeIdentifier480x32";
NSString* const ADBannerContentSizeIdentifierPortrait = @"ADBannerContentSizeIdentifierPortrait";
NSString* const ADBannerContentSizeIdentifierLandscape = @"ADBannerContentSizeIdentifierLandscape";
NSString* const ADErrorDomain = @"ADErrorDomain";

@implementation ADBannerView
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithAdType:(ADAdType)type {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CGSize)sizeFromBannerContentSizeIdentifier:(NSString*)contentSizeIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelBannerViewAction {
    UNIMPLEMENTED();
}

@end
