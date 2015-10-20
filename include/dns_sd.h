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

typedef uint32_t DNSServiceErrorType;
typedef uint32_t DNSServiceFlags;
typedef void* DNSServiceRef;

#define kDNSServiceErr_NoError 0

#define kDNSServiceFlagsIncludeP2P 0x01
#define kDNSServiceFlagsMoreComing 0x02
#define kDNSServiceFlagsAdd 0x04
#define kDNSServiceInterfaceIndexAny 0
#define kDNSServiceProtocol_IPv4 0x04

#endif