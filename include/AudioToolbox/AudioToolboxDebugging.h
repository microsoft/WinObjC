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

#import <stdio.h>
#import <AudioToolbox/AudioToolboxExport.h>
#import <CoreFoundation/CFFileDescriptor.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFURL.h>
#import <AudioToolbox/AudioConverter.h>

AUDIOTOOLBOX_EXPORT void CAShow(void* inObject) STUB_METHOD;
// Bug 6355061
// Using void* here instead of FILE* until the root cause is found.
// AUDIOTOOLBOX_EXPORT void CAShowFile(void* inObject, FILE* inFile) STUB_METHOD;
AUDIOTOOLBOX_EXPORT void CAShowFile(void* inObject, void* inFile) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus CopyNameFromSoundBank(CFURLRef inURL, CFStringRef _Nullable* outName) STUB_METHOD;