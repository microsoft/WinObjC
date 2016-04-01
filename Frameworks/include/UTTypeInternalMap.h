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

#import <MobileCoreServices/MobileCoreServicesExport.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFArray.h>

MOBILECORESERVICES_EXPORT void _UTInitializeSystemUTIMaps();
MOBILECORESERVICES_EXPORT CFArrayRef _UTGetUTIsForFileNameExtension(CFStringRef fileNameExtension);
MOBILECORESERVICES_EXPORT CFArrayRef _UTGetUTIsForMIMEType(CFStringRef fileNameExtension);
MOBILECORESERVICES_EXPORT CFStringRef _UTGetMimeTypeForUTI(CFStringRef UTI);
MOBILECORESERVICES_EXPORT CFStringRef _UTGetFileNameExtensionForUTI(CFStringRef UTI);
