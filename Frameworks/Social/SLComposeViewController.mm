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
#import <Social/SLComposeViewController.h>
#import <Security/Security.h>
#import "ShareSheetControl.h"
#import "StringHelpers.h"
#import "ErrorHandling.h"

#include "COMIncludes.h"
#import <wrl/client.h>
#import <windows.ui.xaml.controls.h>
#include "COMIncludes_End.h"

using namespace Microsoft::WRL;

static NSString* const kFBSDKAccessTokenUserDefaultsKey = @"com.facebook.sdk.v4.FBSDKAccessTokenInformationKey";
static NSString* const kFBSDKAccessTokenKeychainKey = @"com.facebook.sdk.v4.FBSDKAccessTokenInformationKeychainKey";
static NSString* const kFBSDKAccessTokenUUIDKey = @"tokenUUID";
static NSString* const kFBSDKAccessTokenEncodedKey = @"tokenEncoded";

NSString* _getAccessToken() {
    NSString* service = [NSString stringWithFormat:@"com.facebook.sdk.tokencache.%@", [[NSBundle mainBundle] bundleIdentifier]];

    NSDictionary* query = @{
        (__bridge id)kSecClass       : (__bridge id)kSecClassGenericPassword,
        (__bridge id)kSecAttrService : service,
        (__bridge id)kSecAttrAccount : (__bridge id)kFBSDKAccessTokenKeychainKey,
        (__bridge id)kSecReturnData  : @YES,
        (__bridge id)kSecMatchLimit  : (__bridge id)kSecMatchLimitOne
    };

    CFTypeRef data = nil;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, &data);
    if (status != errSecSuccess) {
        // Log something
        return nil;
    }

    if (!data) {
        // Log something
        return nil;
    }

    if (CFGetTypeID(data) != CFDataGetTypeID()) {
        // Log something
        CFRelease(data);
        return nil;
    }

    NSDictionary *dict = [NSKeyedUnarchiver unarchiveObjectWithData:(__bridge NSData*)data];
    CFRelease(data);

    if (![dict isKindOfClass:[NSDictionary class]]) {
        // Log something
        return nil;
    }

    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    NSString* uuid = [defaults objectForKey:kFBSDKAccessTokenUserDefaultsKey];

    if ([dict[kFBSDKAccessTokenUUIDKey] isKindOfClass:[NSString class]]) {
        if ([dict[kFBSDKAccessTokenUUIDKey] isEqualToString:uuid]) {
            id tokenData = dict[kFBSDKAccessTokenEncodedKey];
            if ([tokenData isKindOfClass:[NSData class]]) {
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

@implementation SLComposeViewController
/**
 @Status Stub
 @Notes
*/
+ (SLComposeViewController*)composeViewControllerForServiceType:(NSString*)serviceType {
    NSString* token = _getAccessToken();
    std::wstring wtoken = Strings::NarrowToWide<std::wstring>(token);

    ComPtr<IInspectable> inspectable;
    ComPtr<ABI::Windows::UI::Xaml::Controls::IContentDialog> contentDialog;
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<enum ABI::Windows::UI::Xaml::Controls::ContentDialogResult>> async;
    XamlCreateShareSheet(wtoken.c_str(), inspectable.GetAddressOf());
    THROW_IF_FAILED(inspectable.As(&contentDialog));
    THROW_IF_FAILED(contentDialog->ShowAsync(async.GetAddressOf()));

    return nil;
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)isAvailableForServiceType:(NSString*)serviceType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)setInitialText:(NSString*)text {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)addImage:(UIImage*)image {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeAllImages {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)addURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeAllURLs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)willTransitionToTraitCollection:(UITraitCollection*)newCollection
              withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGSize)sizeForChildContentContainer:(id<UIContentContainer>)container withParentContainerSize:(CGSize)parentSize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)preferredContentSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)systemLayoutFittingSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
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
- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder *)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder *)encoder {
    UNIMPLEMENTED();
}

@end
