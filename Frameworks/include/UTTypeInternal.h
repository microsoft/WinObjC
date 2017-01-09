//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Foundation/FoundationExport.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFArray.h>

FOUNDATION_EXPORT CFStringRef _UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass,
                                                                     CFStringRef inTag,
                                                                     CFStringRef inConformingToUTI);
FOUNDATION_EXPORT CFArrayRef _UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI);
FOUNDATION_EXPORT CFStringRef _UTTypeCopyPreferredTagWithClass(CFStringRef inUTI, CFStringRef inTagClass);
FOUNDATION_EXPORT Boolean _UTTypeEqual(CFStringRef inUTI1, CFStringRef inUTI2);
FOUNDATION_EXPORT Boolean _UTTypeConformsTo(CFStringRef inUTI, CFStringRef inConformsToUTI);
