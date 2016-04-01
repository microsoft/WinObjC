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

#include "Starboard.h"
#include "dns_sd.h"

extern "C" {

/**
 @Status Stub
*/
void DNSServiceRefDeallocate(DNSServiceRef sdRef) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
DNSServiceErrorType DNSServiceSetDispatchQueue(DNSServiceRef service, dispatch_queue_t queue) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
DNSServiceErrorType DNSServiceBrowse(DNSServiceRef* sdRef,
                                     DNSServiceFlags flags,
                                     uint32_t interfaceIndex,
                                     const char* regtype,
                                     const char* domain,
                                     DNSServiceBrowseReply callBack,
                                     void* context) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
DNSServiceErrorType DNSServiceGetAddrInfo(DNSServiceRef* sdRef,
                                          DNSServiceFlags flags,
                                          uint32_t interfaceIndex,
                                          DNSServiceProtocol protocol,
                                          const char* hostname,
                                          DNSServiceGetAddrInfoReply callBack,
                                          void* context) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
DNSServiceErrorType DNSServiceResolve(DNSServiceRef* sdRef,
                                      DNSServiceFlags flags,
                                      uint32_t interfaceIndex,
                                      const char* name,
                                      const char* regtype,
                                      const char* domain,
                                      DNSServiceResolveReply callBack,
                                      void* context) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
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
                                       void* context) {
    UNIMPLEMENTED();
    return 0;
}

}