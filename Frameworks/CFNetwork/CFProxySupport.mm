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

const CFStringRef kCFProxyAutoConfigurationHTTPResponseKey = CFSTR("kCFProxyAutoConfigurationHTTPResponseKey");
const CFStringRef kCFProxyAutoConfigurationJavaScriptKey = CFSTR("kCFProxyAutoConfigurationJavaScriptKey");
const CFStringRef kCFProxyAutoConfigurationURLKey = CFSTR("kCFProxyAutoConfigurationURLKey");
const CFStringRef kCFProxyHostNameKey = CFSTR("kCFProxyHostNameKey");
const CFStringRef kCFProxyPasswordKey = CFSTR("kCFProxyPasswordKey");
const CFStringRef kCFProxyPortNumberKey = CFSTR("kCFProxyPortNumberKey");
const CFStringRef kCFProxyTypeKey = CFSTR("kCFProxyTypeKey");
const CFStringRef kCFProxyUsernameKey = CFSTR("kCFProxyUsernameKey");
const CFStringRef kCFProxyTypeNone = CFSTR("kCFProxyTypeNone");
const CFStringRef kCFProxyTypeAutoConfigurationURL = CFSTR("kCFProxyTypeAutoConfigurationURL");
const CFStringRef kCFProxyTypeAutoConfigurationJavaScript = CFSTR("kCFProxyTypeAutoConfigurationJavaScript");
const CFStringRef kCFProxyTypeFTP = CFSTR("kCFProxyTypeFTP");
const CFStringRef kCFProxyTypeHTTP = CFSTR("kCFProxyTypeHTTP");
const CFStringRef kCFProxyTypeHTTPS = CFSTR("kCFProxyTypeHTTPS");
const CFStringRef kCFProxyTypeSOCKS = CFSTR("kCFProxyTypeSOCKS");
const CFStringRef kCFNetworkProxiesHTTPEnable = CFSTR("kCFNetworkProxiesHTTPEnable");
const CFStringRef kCFNetworkProxiesHTTPPort = CFSTR("kCFNetworkProxiesHTTPPort");
const CFStringRef kCFNetworkProxiesHTTPProxy = CFSTR("kCFNetworkProxiesHTTPProxy");
const CFStringRef kCFNetworkProxiesProxyAutoConfigEnable = CFSTR("kCFNetworkProxiesProxyAutoConfigEnable");
const CFStringRef kCFNetworkProxiesProxyAutoConfigJavaScript = CFSTR("kCFNetworkProxiesProxyAutoConfigJavaScript");
const CFStringRef kCFNetworkProxiesProxyAutoConfigURLString = CFSTR("kCFNetworkProxiesProxyAutoConfigURLString");

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
