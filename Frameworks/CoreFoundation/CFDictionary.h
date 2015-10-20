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

#pragma once

typedef struct {
    DWORD version;
    DWORD retain;
    DWORD release;
    DWORD copyDescription;
    DWORD equal;
    DWORD hash;
} CFDictionaryKeyCallBacks;

typedef struct {
    DWORD version;
    DWORD retain;
    DWORD release;
    DWORD copyDescription;
    DWORD equal;
} CFDictionaryValueCallBacks;

extern CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;
extern CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;
extern CFDictionaryKeyCallBacks kNSTypeDictionaryKeyCallBacks;
extern CFDictionaryValueCallBacks kNSTypeDictionaryValueCallBacks;

typedef id CFDictionaryRef;
typedef id CFMutableDictionaryRef;
typedef uint32_t CFHashCode;

void _CFDictionaryInitInternal(CFDictionaryRef dict);
void _CFDictionaryDestroyInternal(CFDictionaryRef dict);
void _CFDictionaryCopyInternal(CFDictionaryRef dict, CFDictionaryRef fromDict);
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator,
                                                 CFIndex max,
                                                 const CFDictionaryKeyCallBacks* keyCallbacks,
                                                 const CFDictionaryValueCallBacks* valueCallbacks);
void CFDictionarySetValue(CFMutableDictionaryRef dict, const void* key, const void* value);
void CFDictionarySetValueUnretained(CFMutableDictionaryRef dict, const void* key, const void* value);
void CFDictionaryRemoveValue(CFMutableDictionaryRef dict, const void* key);
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef dict);
CFIndex CFDictionaryGetCount(CFDictionaryRef dict);
const void* CFDictionaryGetValue(CFDictionaryRef dict, const void* key);
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef dict, const void* key, const void** valRet);
void CFDictionaryGetKeysAndValues(CFDictionaryRef dict, const void** pKeys, const void** pValues);

void CFDictionaryGetKeyEnumerator(CFDictionaryRef dict, void* enumeratorHolder);
int CFDictionaryGetNextKey(CFDictionaryRef dict, void* enumeratorHolder, id* ret, int count);
void CFDictionaryGetValueEnumerator(CFDictionaryRef dict, void* enumeratorHolder);
int CFDictionaryGetNextValue(CFDictionaryRef dict, void* enumeratorHolder, id* ret, int count);

void InitCFDict();
