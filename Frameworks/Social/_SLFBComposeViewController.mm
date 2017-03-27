//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <Social/Social.h>
#import <Security/Security.h>
#import <UIKit/UIKit.h>
#import <UWP/WindowsUIXaml.h>
#import "_SLFBComposeViewController.h"
#import "ShareSheetControl.h"
#import "CACompositor.h"
#import "StringHelpers.h"
#import "ErrorHandling.h"
#import "NSLogging.h"

#include "COMIncludes.h"
#import <wrl/client.h>
#import <windows.ui.xaml.controls.h>
#include "COMIncludes_End.h"

static const wchar_t* TAG = L"_SLFBComposeViewController";

using namespace Microsoft::WRL;

static NSString* const kFBSDKAccessTokenUserDefaultsKey = @"com.facebook.sdk.v4.FBSDKAccessTokenInformationKey";
static NSString* const kFBSDKAccessTokenKeychainKey = @"com.facebook.sdk.v4.FBSDKAccessTokenInformationKeychainKey";
static NSString* const kFBSDKAccessTokenUUIDKey = @"tokenUUID";
static NSString* const kFBSDKAccessTokenEncodedKey = @"tokenEncoded";

static NSString* _getAccessToken() {
    // Look for an access token cached in the security database
    NSString* service = [NSString stringWithFormat:@"com.facebook.sdk.tokencache.%@", [[NSBundle mainBundle] bundleIdentifier]];

    NSDictionary* query = @{
        (__bridge id)kSecClass : (__bridge id)kSecClassGenericPassword,
        (__bridge id)kSecAttrService : service,
        (__bridge id)kSecAttrAccount : (__bridge id)kFBSDKAccessTokenKeychainKey,
        (__bridge id)kSecReturnData : @YES,
        (__bridge id)kSecMatchLimit : (__bridge id)kSecMatchLimitOne
    };

    woc::unique_cf<CFTypeRef> data;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, &data);
    if (status != errSecSuccess) {
        TraceError(TAG, L"Cached token not found, error = %u", (unsigned)status);
        return nil;
    }

    if (!data) {
        TraceError(TAG, L"Cached token not set");
        return nil;
    }

    if (CFGetTypeID(data) != CFDataGetTypeID()) {
        TraceError(TAG, L"Cached token unexpected type: %lu", (unsigned long)CFGetTypeID(data));
        return nil;
    }

    NSDictionary* dict = [NSKeyedUnarchiver unarchiveObjectWithData:(__bridge NSData*)data.get()];

    if (![dict isKindOfClass:[NSDictionary class]]) {
        NSTraceError(TAG, @"Cached token data unexpected type: %@", [dict class]);
        return nil;
    }

    // Pull the token out of the cached data we found
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    NSString* uuid = [defaults objectForKey:kFBSDKAccessTokenUserDefaultsKey];
    id uuidFound = dict[kFBSDKAccessTokenUUIDKey];

    if ([uuidFound isKindOfClass:[NSString class]]) {
        if ([uuidFound isEqualToString:uuid]) {
            id tokenData = dict[kFBSDKAccessTokenEncodedKey];
            if ([tokenData isKindOfClass:[NSData class]]) {
                // The access token will be a serialized form of some Facebook object.
                // The unarchiving will fail if the object class is not registered,
                // meaning that the Facebook SDK hasn't been loaded into this process.
                // It would be preferable if the token were stored in some documented
                // format so that the Social kit is usable even by callers that haven't
                // loaded the Facebook SDK.
                id token = [NSKeyedUnarchiver unarchiveObjectWithData:tokenData];
                if ([token respondsToSelector:@selector(tokenString)]) {
                    id tokenString = [token performSelector:@selector(tokenString)];
                    if ([tokenString isKindOfClass:[NSString class]]) {
                        return tokenString;
                    }
                }
            }
        }
    }

    return nil;
}

@implementation _SLFBComposeViewController {
    ComPtr<ShareSheetControl> _shareSheet;
}

- (instancetype)init {
    if (self = [super init]) {
        NSString* token = _getAccessToken();

        if (token == nil) {
            [self release];
            return nil;
        }

        std::wstring wtoken = Strings::NarrowToWide<std::wstring>(token);

        if (FAILED(XamlCreateShareSheet(wtoken.c_str(), &_shareSheet))) {
            [self release];
            return nil;
        }
    }

    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (void)loadView {
    (void)_shareSheet->show();
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)addURL:(NSURL*)url {
    if (self.isViewLoaded) {
        TraceError(TAG, L"Can't add URL after view controller is presented");
        return NO;
    }

    std::wstring urlText = Strings::NarrowToWide<std::wstring>(url.absoluteString);
    if (FAILED(_shareSheet->addLink(urlText.c_str()))) {
        return NO;
    }

    return YES;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)addImage:(UIImage*)image {
    if (self.isViewLoaded) {
        TraceError(TAG, L"Can't add image after view controller is presented");
        return NO;
    }

    auto texture = GetCACompositor()->GetDisplayTextureForCGImage(image.CGImage);
    if (FAILED(_shareSheet->addImage(texture->GetContent().Get()))) {
        return NO;
    }

    return YES;
}

/**
@Status Interoperable
@Notes
*/
- (BOOL)setInitialText:(NSString*)text {
    if (self.isViewLoaded) {
        TraceError(TAG, L"Can't set initial text after view controller is presented");
        return NO;
    }

    std::wstring wtext = Strings::NarrowToWide<std::wstring>(text);
    if (FAILED(_shareSheet->setInitialText(wtext.c_str()))) {
        return NO;
    }

    return YES;
}

@end
