//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _CFPROXYSUPPORT_H_
#define _CFPROXYSUPPORT_H_

#import <CFNetwork/CFNetworkExport.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFURL.h>
#import <CoreFoundation/CFError.h>

CFNETWORK_EXPORT const CFStringRef kCFProxyTypeNone;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeAutoConfigurationURL;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeAutoConfigurationJavaScript;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeFTP;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeHTTP;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeHTTPS;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeSOCKS;

CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationHTTPResponseKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationJavaScriptKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyAutoConfigurationURLKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyHostNameKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyPasswordKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyPortNumberKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyTypeKey;
CFNETWORK_EXPORT const CFStringRef kCFProxyUsernameKey;

CFNETWORK_EXPORT CFDictionaryRef CFNetworkCopySystemProxySettings();
CFNETWORK_EXPORT CFArrayRef CFNetworkCopyProxiesForAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript,
                                                                           CFURLRef targetURL,
                                                                           CFErrorRef* err);
CFNETWORK_EXPORT CFArrayRef CFNetworkCopyProxiesForURL(CFURLRef url, CFDictionaryRef proxySettings);

#endif // _CFPROXYSUPPORT_H_