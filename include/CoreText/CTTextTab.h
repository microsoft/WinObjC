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

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTParagraphStyle.h>

#import <CoreFoundation/CFDictionary.h>

#import <CoreFoundation/CFString.h>

typedef const struct __CTTextTab* CTTextTabRef;

CORETEXT_EXPORT const CFStringRef kCTTabColumnTerminatorsAttributeName;

CORETEXT_EXPORT CTTextTabRef CTTextTabCreate(CTTextAlignment alignment, double location, CFDictionaryRef options) STUB_METHOD;
CORETEXT_EXPORT CTTextAlignment CTTextTabGetAlignment(CTTextTabRef tab) STUB_METHOD;
CORETEXT_EXPORT double CTTextTabGetLocation(CTTextTabRef tab) STUB_METHOD;
CORETEXT_EXPORT CFDictionaryRef CTTextTabGetOptions(CTTextTabRef tab) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTTextTabGetTypeID() STUB_METHOD;
