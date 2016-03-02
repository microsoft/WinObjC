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
#import <CFNetwork/CFProxySupport.h>

const CFStringRef kCFProxyAutoConfigurationHTTPResponseKey = static_cast<CFStringRef>(@"kCFProxyAutoConfigurationHTTPResponseKey");
const CFStringRef kCFProxyAutoConfigurationJavaScriptKey = static_cast<CFStringRef>(@"kCFProxyAutoConfigurationJavaScriptKey");
const CFStringRef kCFProxyAutoConfigurationURLKey = static_cast<CFStringRef>(@"kCFProxyAutoConfigurationURLKey");
const CFStringRef kCFProxyHostNameKey = static_cast<CFStringRef>(@"kCFProxyHostNameKey");
const CFStringRef kCFProxyPasswordKey = static_cast<CFStringRef>(@"kCFProxyPasswordKey");
const CFStringRef kCFProxyPortNumberKey = static_cast<CFStringRef>(@"kCFProxyPortNumberKey");
const CFStringRef kCFProxyTypeKey = static_cast<CFStringRef>(@"kCFProxyTypeKey");
const CFStringRef kCFProxyUsernameKey = static_cast<CFStringRef>(@"kCFProxyUsernameKey");
const CFStringRef kCFProxyTypeNone = static_cast<CFStringRef>(@"kCFProxyTypeNone");
const CFStringRef kCFProxyTypeAutoConfigurationURL = static_cast<CFStringRef>(@"kCFProxyTypeAutoConfigurationURL");
const CFStringRef kCFProxyTypeAutoConfigurationJavaScript = static_cast<CFStringRef>(@"kCFProxyTypeAutoConfigurationJavaScript");
const CFStringRef kCFProxyTypeFTP = static_cast<CFStringRef>(@"kCFProxyTypeFTP");
const CFStringRef kCFProxyTypeHTTP = static_cast<CFStringRef>(@"kCFProxyTypeHTTP");
const CFStringRef kCFProxyTypeHTTPS = static_cast<CFStringRef>(@"kCFProxyTypeHTTPS");
const CFStringRef kCFProxyTypeSOCKS = static_cast<CFStringRef>(@"kCFProxyTypeSOCKS");
const CFStringRef kCFNetworkProxiesHTTPEnable = static_cast<CFStringRef>(@"kCFNetworkProxiesHTTPEnable");
const CFStringRef kCFNetworkProxiesHTTPPort = static_cast<CFStringRef>(@"kCFNetworkProxiesHTTPPort");
const CFStringRef kCFNetworkProxiesHTTPProxy = static_cast<CFStringRef>(@"kCFNetworkProxiesHTTPProxy");
const CFStringRef kCFNetworkProxiesProxyAutoConfigEnable = static_cast<CFStringRef>(@"kCFNetworkProxiesProxyAutoConfigEnable");
const CFStringRef kCFNetworkProxiesProxyAutoConfigJavaScript = static_cast<CFStringRef>(@"kCFNetworkProxiesProxyAutoConfigJavaScript");
const CFStringRef kCFNetworkProxiesProxyAutoConfigURLString = static_cast<CFStringRef>(@"kCFNetworkProxiesProxyAutoConfigURLString");

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFNetworkCopyProxiesForURL(CFURLRef url, CFDictionaryRef proxySettings) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CFNetworkCopyProxiesForAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript,
                                                          CFURLRef targetURL,
                                                          CFErrorRef _Nullable* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFRunLoopSourceRef CFNetworkExecuteProxyAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript,
                                                                CFURLRef targetURL,
                                                                CFProxyAutoConfigurationResultCallback cb,
                                                                CFStreamClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFRunLoopSourceRef CFNetworkExecuteProxyAutoConfigurationURL(CFURLRef proxyAutoConfigURL,
                                                             CFURLRef targetURL,
                                                             CFProxyAutoConfigurationResultCallback cb,
                                                             CFStreamClientContext* clientContext) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CFNetworkCopySystemProxySettings() {
    UNIMPLEMENTED();
    return StubReturn();
}
