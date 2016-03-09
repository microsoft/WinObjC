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
#pragma once

#import <CFNetwork/CFNetworkExport.h>
#import <CoreFoundation/CoreFoundation.h>

typedef void (*CFProxyAutoConfigurationResultCallback)(void* client, CFArrayRef proxyList, CFErrorRef error);

CFNETWORK_EXPORT CFArrayRef CFNetworkCopyProxiesForURL(CFURLRef url, CFDictionaryRef proxySettings) STUB_METHOD;

CFNETWORK_EXPORT CFArrayRef CFNetworkCopyProxiesForAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript,
                                                                           CFURLRef targetURL,
                                                                           CFErrorRef _Nullable* error) STUB_METHOD;

CFNETWORK_EXPORT CFRunLoopSourceRef CFNetworkExecuteProxyAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript,
                                                                                 CFURLRef targetURL,
                                                                                 CFProxyAutoConfigurationResultCallback cb,
                                                                                 CFStreamClientContext* clientContext) STUB_METHOD;

CFNETWORK_EXPORT CFRunLoopSourceRef CFNetworkExecuteProxyAutoConfigurationURL(CFURLRef proxyAutoConfigURL,
                                                                              CFURLRef targetURL,
                                                                              CFProxyAutoConfigurationResultCallback cb,
                                                                              CFStreamClientContext* clientContext) STUB_METHOD;

CFNETWORK_EXPORT CFDictionaryRef CFNetworkCopySystemProxySettings() STUB_METHOD;

CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationHTTPResponseKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationJavaScriptKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationURLKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyHostNameKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyPasswordKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyPortNumberKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyUsernameKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeNone;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeAutoConfigurationURL;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeAutoConfigurationJavaScript;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeFTP;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeHTTP;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeHTTPS;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeSOCKS;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesHTTPEnable;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesHTTPPort;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesHTTPProxy;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesProxyAutoConfigEnable;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesProxyAutoConfigJavaScript;
CFNETWORK_EXPORT const CFStringRef kCFNetworkProxiesProxyAutoConfigURLString;
