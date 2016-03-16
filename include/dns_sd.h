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

#ifndef __DNS_SD_H
#define __DNS_SD_H

#include <stdint.h>
#include <dispatch/dispatch.h>
#include "StarboardExport.h"

typedef uint32_t DNSServiceErrorType;
typedef uint32_t DNSServiceProtocol;
typedef uint32_t DNSServiceFlags;

typedef struct __DNSService* DNSServiceRef;

#define kDNSServiceErr_NoError 0

#define kDNSServiceFlagsIncludeP2P 0x01
#define kDNSServiceFlagsMoreComing 0x02
#define kDNSServiceFlagsAdd 0x04
#define kDNSServiceInterfaceIndexAny 0
#define kDNSServiceProtocol_IPv4 0x04

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
                                       uint16_t txtLen,
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

/**
 @Status Stub
*/
SB_EXPORT
DNSServiceErrorType DNSServiceRegister(DNSServiceRef* sdRef,
    DNSServiceFlags flags,
    uint32_t interfaceIndex,
    const char* name,
    const char* regtype,
    const char* domain,
    const char* host,
    uint16_t port,
    uint16_t txtLen,
    const void* txtRecord,
    DNSServiceRegisterReply callBack,
    void* context);

/**
 @Status Stub
*/
SB_EXPORT
void DNSServiceRefDeallocate(DNSServiceRef sdRef);

/**
 @Status Stub
*/
SB_EXPORT
DNSServiceErrorType DNSServiceSetDispatchQueue(DNSServiceRef service, dispatch_queue_t queue);

/**
 @Status Stub
*/
SB_EXPORT
DNSServiceErrorType DNSServiceBrowse(DNSServiceRef* sdRef,
                                     DNSServiceFlags flags,
                                     uint32_t interfaceIndex,
                                     const char* regtype,
                                     const char* domain,
                                     DNSServiceBrowseReply callBack,
                                     void* context);

/**
 @Status Stub
*/
SB_EXPORT
DNSServiceErrorType DNSServiceGetAddrInfo(DNSServiceRef* sdRef,
                                          DNSServiceFlags flags,
                                          uint32_t interfaceIndex,
                                          DNSServiceProtocol protocol,
                                          const char* hostname,
                                          DNSServiceGetAddrInfoReply callBack,
                                          void* context);

/**
 @Status Stub
*/
SB_EXPORT
DNSServiceErrorType DNSServiceResolve(DNSServiceRef* sdRef,
    DNSServiceFlags flags,
    uint32_t interfaceIndex,
    const char* name,
    const char* regtype,
    const char* domain,
    DNSServiceResolveReply callBack,
    void* context);

#endif