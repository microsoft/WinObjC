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
#import <StubReturn.h>
#import <SafariServices/SFSafariViewController.h>
#import <Foundation/NSURLRequest.h>
#import <UWP/WindowsSecurityAuthenticationWeb.h>

//
// This implementation of SFSafariViewController is not Safari and is not a view controller.
// It has only one function, and that is to handle OAuth requests. It is not suitable
// for any other purpose.
//

static const wchar_t* TAG = L"SFSafariViewController";

@implementation SFSafariViewController {
    NSURL* _url;
    NSString* _originalRedirectURL;
    NSString* _substituteRedirectURL;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithURL:(NSURL*)URL entersReaderIfAvailable:(BOOL)entersReaderIfAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 This method initializes SFSafariViewController for an OAuth request. The OAuth URL
 will typically contain a redirect URL embedded within it, but you may specify an
 alternate redirect URL that will be sent to the server. The server will see only the
 substitute redirect URL, but the callback received by the client will be as if the
 original redirect URL had been used.

 Some clients, such as the Facebook SDK, have need of this alternate redirect URL
 functionality, but most should not.
*/
- (instancetype)initWithOAuthURL:(NSURL*)URL substituteRedirectURL:(NSURL*)redirectURL {
    if (self = [super init]) {
        _url = [URL copy];
        _substituteRedirectURL = redirectURL.absoluteString;
    }

    return self;
}

/*
 If the client has specified a substitute callback URL to use, replace the original
 callback URL with the substitute and return the modified URL string.
*/
- (NSString*)_replaceCallbackURL {
    if (_substituteRedirectURL == nil) {
        return _url.absoluteString;
    }

    NSURLComponents* components = [NSURLComponents componentsWithURL:_url resolvingAgainstBaseURL:NO];
    NSArray<NSURLQueryItem*>* queryItems = components.queryItems;

    // Find the callback URL inside the given URL's query string
    NSUInteger redirectIdx = [queryItems indexOfObjectPassingTest:^BOOL(NSURLQueryItem* item, NSUInteger, BOOL*) {
        return [item.name isEqualToString:@"redirect_uri"];
    }];

    if (redirectIdx == NSNotFound) {
        return _url.absoluteString;
    }

    NSURLQueryItem* originalItem = queryItems[redirectIdx];
    NSURLQueryItem* newItem = [NSURLQueryItem queryItemWithName:originalItem.name value:_substituteRedirectURL];

    // Stash the original callback URL
    _originalRedirectURL = originalItem.value;

    // Replace the callback URL with our new one
    NSMutableArray* newQueryItems = [NSMutableArray arrayWithArray:components.queryItems];
    [newQueryItems replaceObjectAtIndex:redirectIdx withObject:newItem];
    components.queryItems = newQueryItems;

    return [components.URL absoluteString];
}

- (NSString*)_sourceApplication {
    // When an app is asked to open a URL, we must provide the identity of the
    // "source application". If the request originates from another app on the
    // machine, the source application would be its bundle ID. In the case where
    // the URL is coming from the web, however, the behavior is undocumented but
    // in practice seems to be the host name of the source, in reverse order.

    NSArray* hostParts = [_url.host componentsSeparatedByString:@"."];
    NSArray* reverseHostParts = [[hostParts reverseObjectEnumerator] allObjects];

    return [reverseHostParts componentsJoinedByString:@"."];
}

- (void)loadView {
    // Replace the caller's callback URL with our own
    NSString* mangledURL = [self _replaceCallbackURL];

    WFUri* requestUri = [WFUri makeUri:mangledURL];
    WFUri* callbackUri = [WFUri makeUri:_substituteRedirectURL];

    void (^success)(WSAWWebAuthenticationResult*) = ^void(WSAWWebAuthenticationResult* result) {
        switch (result.responseStatus) {
            case WSAWWebAuthenticationStatusSuccess:
                break;

            case WSAWWebAuthenticationStatusUserCancel:
                NSTraceWarning(TAG, @"User cancelled web authentication");
                return;

            case WSAWWebAuthenticationStatusErrorHttp:
                NSTraceError(TAG, @"Web authentication failed with HTTP code %u", result.responseErrorDetail);
                return;

            default:
                NSTraceError(TAG, @"Unrecognized web authentication status");
                return;
        }

        NSString* redirectUri = result.responseData;

        if (_substituteRedirectURL != nil) {
            // Substitute the caller's original callback URL
            redirectUri = [redirectUri stringByReplacingOccurrencesOfString:_substituteRedirectURL
                                                                 withString:_originalRedirectURL
                                                                    options:NSLiteralSearch
                                                                      range:NSMakeRange(0, _substituteRedirectURL.length)];
        }

        // Let the client see the response from the server
        id delegate = [[UIApplication sharedApplication] delegate];
        if ([delegate respondsToSelector:@selector(application:openURL:sourceApplication:annotation:)]) {
            [delegate application:[UIApplication sharedApplication]
                          openURL:[NSURL URLWithString:redirectUri]
                sourceApplication:[self _sourceApplication]
                       annotation:nil];
        }
    };

    void (^failure)(NSError*) = ^void(NSError* error) {
        NSTraceError(TAG, @"Web authentication failed: %@", error.localizedDescription);
    };

    [WSAWWebAuthenticationBroker authenticateWithCallbackUriAsync:WSAWWebAuthenticationOptionsNone
                                                       requestUri:requestUri
                                                      callbackUri:callbackUri
                                                          success:success
                                                          failure:failure];
}

@end
