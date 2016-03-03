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

#include "Starboard.h"

typedef void* DNSServiceRef;
typedef unsigned DNSServiceErrorType;
typedef unsigned DNSServiceFlags;
typedef unsigned DNSServiceProtocol;
typedef void (*DNSServiceBrowseReply)(DNSServiceRef sdRef,
                                      DNSServiceFlags flags,
                                      unsigned interfaceIndex,
                                      DNSServiceErrorType errorCode,
                                      const char* serviceName,
                                      const char* regtype,
                                      const char* replyDomain,
                                      void* context);
typedef void (*DNSServiceResolveReply)(DNSServiceRef sdRef,
                                       DNSServiceFlags flags,
                                       uint32_t interfaceIndex,
                                       DNSServiceErrorType errorCode,
                                       const char* fullname,
                                       const char* hosttarget,
                                       uint16_t port,
                                       /* In network byte order */ uint16_t txtLen,
                                       const unsigned char* txtRecord,
                                       void* context);
typedef void (*DNSServiceGetAddrInfoReply)(DNSServiceRef sdRef,
                                           DNSServiceFlags flags,
                                           uint32_t interfaceIndex,
                                           DNSServiceErrorType errorCode,
                                           const char* hostname,
                                           const struct sockaddr* address,
                                           uint32_t ttl,
                                           void* context);
typedef void (*DNSServiceRegisterReply)(DNSServiceRef sdRef,
                                        DNSServiceFlags flags,
                                        DNSServiceErrorType errorCode,
                                        const char* name,
                                        const char* regtype,
                                        const char* domain,
                                        void* context);

UIKIT_EXPORT
void DNSServiceRefDeallocate(DNSServiceRef sdRef) {
    [sdRef dealloc];
}

UIKIT_EXPORT
DNSServiceErrorType DNSServiceSetDispatchQueue(DNSServiceRef service, dispatch_queue_t queue) {
    UNIMPLEMENTED_WITH_MSG("DNSServiceSetDispatchQueue");
    return 0;
}

UIKIT_EXPORT
DNSServiceErrorType DNSServiceBrowse(DNSServiceRef* sdRef,
                                     DNSServiceFlags flags,
                                     uint32_t interfaceIndex,
                                     const char* regtype,
                                     const char* domain,
                                     /* may be NULL */ DNSServiceBrowseReply callBack,
                                     void* context /* may be NULL */) {
    UNIMPLEMENTED_WITH_MSG("DNSServiceBrowse");
    return 0;
}

UIKIT_EXPORT
DNSServiceErrorType DNSServiceGetAddrInfo(DNSServiceRef* sdRef,
                                          DNSServiceFlags flags,
                                          uint32_t interfaceIndex,
                                          DNSServiceProtocol protocol,
                                          const char* hostname,
                                          DNSServiceGetAddrInfoReply callBack,
                                          void* context /* may be NULL */) {
    UNIMPLEMENTED_WITH_MSG("DNSServiceGetAddrInfo");
    return 0;
}

UIKIT_EXPORT
DNSServiceErrorType DNSServiceResolve(DNSServiceRef* sdRef,
                                      DNSServiceFlags flags,
                                      uint32_t interfaceIndex,
                                      const char* name,
                                      const char* regtype,
                                      const char* domain,
                                      DNSServiceResolveReply callBack,
                                      void* context /* may be NULL */) {
    UNIMPLEMENTED_WITH_MSG("DNSServiceResolve");
    return 0;
}

UIKIT_EXPORT DNSServiceErrorType DNSServiceRegister(DNSServiceRef* sdRef,
                                                    DNSServiceFlags flags,
                                                    uint32_t interfaceIndex,
                                                    const char* name,
                                                    /* may be NULL */ const char* regtype,
                                                    const char* domain,
                                                    /* may be NULL */ const char* host,
                                                    /* may be NULL */ uint16_t port,
                                                    /* In network byte order */ uint16_t txtLen,
                                                    const void* txtRecord,
                                                    /* may be NULL */ DNSServiceRegisterReply callBack,
                                                    /* may be NULL */ void* context /* may be NULL */) {
    UNIMPLEMENTED_WITH_MSG("DNSServiceRegister");
    return 0;
}
