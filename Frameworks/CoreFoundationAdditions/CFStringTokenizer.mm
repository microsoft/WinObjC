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

#include <CoreFoundation/CFStringTokenizer.h>
#include <unicode/ubrk.h>
#include <IwMalloc.h>
#include <memory>
#include <Starboard/SmartTypes.h>
#include <CFInternal.h>
#include <LoggingNative.h>

static const wchar_t* TAG = L"CFStringTokenizer";

typedef struct __CFStringTokenizer {
    CFRuntimeBase _base;
    woc::unique_iw<UChar> _str;
    woc::unique_cf<CFLocaleRef> _locale;
    std::unique_ptr<UBreakIterator, decltype(&ubrk_close)> _iterator;
} __CFStringTokenizer;

static void __CFStringTokenizerInit(CFTypeRef cf) {
    __CFStringTokenizer* tokenizer = (__CFStringTokenizer*)cf;
    new (&tokenizer->_str) woc::unique_iw<UChar>(nullptr);
    new (&tokenizer->_locale) woc::unique_cf<CFLocaleRef>(nullptr);
    new (&tokenizer->_iterator) std::unique_ptr<UBreakIterator, decltype(&ubrk_close)>(nullptr, ubrk_close);
}

static void __CFStringTokenizerDeallocate(CFTypeRef cf) {
    __CFStringTokenizer* tokenizer = (__CFStringTokenizer*)cf;
    tokenizer->_str.~unique_iw();
    tokenizer->_locale.~unique_cf();
    tokenizer->_iterator.~unique_ptr();
}

static const CFRuntimeClass __CFStringTokenizerClass = {
    0,
    "CFStringTokenizer",
    __CFStringTokenizerInit, // init
    nullptr, // copy
    __CFStringTokenizerDeallocate, // dealloc
    nullptr, // equal
    nullptr, // hash
    nullptr, // format description
    nullptr // description
};

static CFTypeID __kCFStringTokenizerTypeID = _kCFRuntimeNotATypeID;

CFTypeID CFStringTokenizerGetTypeID(void) {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce,
                  ^{
                      __kCFStringTokenizerTypeID = _CFRuntimeRegisterClass(&__CFStringTokenizerClass);
                  });
    return __kCFStringTokenizerTypeID;
}

CFStringTokenizerRef CFStringTokenizerCreate(
    CFAllocatorRef allocator, CFStringRef string, CFRange range, CFOptionFlags options, CFLocaleRef locale) {
    UBreakIteratorType type;
    switch (options) {
        case kCFStringTokenizerUnitSentence:
            type = UBRK_SENTENCE;
            break;
        case kCFStringTokenizerUnitWordBoundary:
            type = UBRK_WORD;
            break;
        case kCFStringTokenizerUnitLineBreak:
            type = UBRK_LINE;
            break;
        default:
            return nullptr;
    }

    woc::unique_cf<__CFStringTokenizer*> cfTokenizer(
        (__CFStringTokenizer*)_CFRuntimeCreateInstance(allocator,
                                                       CFStringTokenizerGetTypeID(),
                                                       sizeof(__CFStringTokenizer) - sizeof(CFRuntimeBase),
                                                       nullptr));

    if (!cfTokenizer.get()) {
        return nullptr;
    }

    cfTokenizer->_locale.reset(((locale != nullptr) ? (CFLocaleRef)CFRetain(locale) : CFLocaleCopyCurrent()));

    const char* localeCStr = CFStringGetCStringPtr(CFLocaleGetIdentifier(cfTokenizer->_locale.get()), kCFStringEncodingASCII);
    if (localeCStr == nullptr) {
        return nullptr;
    }

    UErrorCode err = U_ZERO_ERROR;
    cfTokenizer->_iterator.reset(ubrk_open(type, localeCStr, nullptr, -1, &err));
    if (!cfTokenizer->_iterator.get()) {
        return nullptr;
    }

    if (err != U_ZERO_ERROR) {
        TraceVerbose(TAG, L"Create:UErrorCode:%d", err);
    }

    CFStringTokenizerSetString((CFStringTokenizerRef)cfTokenizer.get(), string, range);

    return (CFStringTokenizerRef)cfTokenizer.release();
}

void CFStringTokenizerSetString(CFStringTokenizerRef tokenizer, CFStringRef string, CFRange range) {
    if (tokenizer == nullptr) {
        return;
    }

    __CFStringTokenizer* cfTokenizer = ((__CFStringTokenizer*)tokenizer);
    CFIndex numBytes;
    CFStringGetBytes(string, range, kCFStringEncodingUTF16, 0, false, nullptr, 0, &numBytes);

    if (numBytes > 0) {
        cfTokenizer->_str = woc::unique_iw<UChar>(static_cast<UChar*>(IwMalloc(numBytes)));
        if (!cfTokenizer->_str.get()) {
            return;
        }
        if (CFStringGetBytes(string, range, kCFStringEncodingUTF16, 0, false, (UInt8*)cfTokenizer->_str.get(), numBytes, nullptr) <= 0) {
            return;
        }
    } else {
        cfTokenizer->_str.reset(nullptr);
    }
    UErrorCode err = U_ZERO_ERROR;
    ubrk_setText(cfTokenizer->_iterator.get(), cfTokenizer->_str.get(), range.length, &err);
    if (err != U_ZERO_ERROR) {
        TraceVerbose(TAG, L"setString:UErrorCode:%d", err);
    }
}

CFStringTokenizerTokenType CFStringTokenizerAdvanceToNextToken(CFStringTokenizerRef tokenizer) {
    if (tokenizer == nullptr) {
        return kCFStringTokenizerTokenNone;
    }
    return (ubrk_next(((__CFStringTokenizer*)tokenizer)->_iterator.get()) == UBRK_DONE) ? kCFStringTokenizerTokenNone :
                                                                                          kCFStringTokenizerTokenNormal;
}

CFRange CFStringTokenizerGetCurrentTokenRange(CFStringTokenizerRef tokenizer) {
    if (tokenizer == nullptr) {
        return CFRangeMake(0, -1);
    }
    int32_t last = ubrk_previous(((__CFStringTokenizer*)tokenizer)->_iterator.get());
    int32_t current = ubrk_next(((__CFStringTokenizer*)tokenizer)->_iterator.get());

    if (current == UBRK_DONE) {
        return CFRangeMake(0, -1);
    }

    return CFRangeMake(last, current - last);
}

CFStringTokenizerTokenType CFStringTokenizerGoToTokenAtIndex(CFStringTokenizerRef tokenizer, CFIndex index) {
    if (tokenizer == nullptr) {
        return kCFStringTokenizerTokenNone;
    }
    if (ubrk_following(((__CFStringTokenizer*)tokenizer)->_iterator.get(), index) != UBRK_DONE) {
        return kCFStringTokenizerTokenNormal;
    }

    return kCFStringTokenizerTokenNone;
}