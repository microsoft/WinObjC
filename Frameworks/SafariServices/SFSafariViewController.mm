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

#import "Starboard.h"
#import "NSLogging.h"
#import "NSRaise.h"
#import <StubReturn.h>
#import <SafariServices/SFSafariViewController.h>
#import "SFSafariViewControllerInternal.h"
#import "SFSafariWebViewController.h"
#import "SFSafariOAuthViewController.h"

//
// This implementation of SFSafariViewController is not Safari and is not a view controller.
// It has only one function, and that is to handle OAuth requests. It is not suitable
// for any other purpose.
//

static const wchar_t* TAG = L"SFSafariViewController";

@implementation SFSafariViewController
/**
 @Status Interoperable
*/
- (instancetype)initWithNibName:(NSString*)nibName bundle:(NSBundle*)nibBundle {
    THROW_NS_HR_MSG(E_NOTIMPL, "initWithNibName:bundle: is unavailable");
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithURL:(NSURL*)URL {
    return [self initWithURL:URL entersReaderIfAvailable:NO];
}

/**
 @Status Caveat
 @Notes Reader is not available
*/
- (instancetype)initWithURL:(NSURL*)URL entersReaderIfAvailable:(BOOL)entersReaderIfAvailable {
    if ([self isMemberOfClass:SFSafariViewController.class]) {
        self = [[SFSafariWebViewController alloc] initWithURL:URL entersReaderIfAvailable:entersReaderIfAvailable];
    } else {
        self = [super initWithNibName:nil bundle:nil];
    }

    return self;
}

- (instancetype)initWithOAuthURL:(NSURL*)URL substituteRedirectURL:(NSURL*)redirectURL {
    if ([self isMemberOfClass:SFSafariViewController.class]) {
        self = [[SFSafariOAuthViewController alloc] initWithOAuthURL:URL substituteRedirectURL:redirectURL];
    } else {
        self = [super initWithNibName:nil bundle:nil];
    }

    return self;
}

- (void)loadView {
    NSInvalidAbstractInvocation();
}

- (NSString*)_sourceApplication {
    return @"com.apple.SafariViewService";
}
@end
