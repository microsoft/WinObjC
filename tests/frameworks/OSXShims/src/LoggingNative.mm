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

#import <LoggingNative.h>
#import <Starboard/SmartTypes.h>
#import <Foundation/NSString.h>

#import <cstdarg>

// NOTE: this function is assumed to only run in Little Endian environments like OSX
static NSStringEncoding _getWcharEncoding() {
    switch (sizeof(wchar_t)) {
        case 2:
            return NSUTF16LittleEndianStringEncoding;
        case 4:
            return NSUTF32LittleEndianStringEncoding;
        default:
            assert(false);
    }
}

static NSStringEncoding getWcharEncoding() {
    static NSStringEncoding encoding = _getWcharEncoding();
    return encoding;
}

void TraceVerbose(const wchar_t* tag, const wchar_t* format, ...) {
    StrongId<NSString> nsTag;
    nsTag.attach([[NSString alloc] initWithBytes:tag length:sizeof(wchar_t) * wcslen(tag) encoding:getWcharEncoding()]);

    StrongId<NSString> nsFormat;
    nsFormat.attach([[NSString alloc] initWithBytes:format length:sizeof(wchar_t) * wcslen(format) encoding:getWcharEncoding()]);

    NSString* formatString = [NSString stringWithFormat:@"[%@] %@", static_cast<NSString*>(nsTag), static_cast<NSString*>(nsFormat)];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceInfo(const wchar_t* tag, const wchar_t* format, ...) {
    StrongId<NSString> nsTag;
    nsTag.attach([[NSString alloc] initWithBytes:tag length:sizeof(wchar_t) * wcslen(tag) encoding:getWcharEncoding()]);

    StrongId<NSString> nsFormat;
    nsFormat.attach([[NSString alloc] initWithBytes:format length:sizeof(wchar_t) * wcslen(format) encoding:getWcharEncoding()]);

    NSString* formatString = [NSString stringWithFormat:@"[%@] %@", static_cast<NSString*>(nsTag), static_cast<NSString*>(nsFormat)];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceWarning(const wchar_t* tag, const wchar_t* format, ...) {
    StrongId<NSString> nsTag;
    nsTag.attach([[NSString alloc] initWithBytes:tag length:sizeof(wchar_t) * wcslen(tag) encoding:getWcharEncoding()]);

    StrongId<NSString> nsFormat;
    nsFormat.attach([[NSString alloc] initWithBytes:format length:sizeof(wchar_t) * wcslen(format) encoding:getWcharEncoding()]);

    NSString* formatString = [NSString stringWithFormat:@"[%@] %@", static_cast<NSString*>(nsTag), static_cast<NSString*>(nsFormat)];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceError(const wchar_t* tag, const wchar_t* format, ...) {
    StrongId<NSString> nsTag;
    nsTag.attach([[NSString alloc] initWithBytes:tag length:sizeof(wchar_t) * wcslen(tag) encoding:getWcharEncoding()]);

    StrongId<NSString> nsFormat;
    nsFormat.attach([[NSString alloc] initWithBytes:format length:sizeof(wchar_t) * wcslen(format) encoding:getWcharEncoding()]);

    NSString* formatString = [NSString stringWithFormat:@"[%@] %@", static_cast<NSString*>(nsTag), static_cast<NSString*>(nsFormat)];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceCritical(const wchar_t* tag, const wchar_t* format, ...) {
    StrongId<NSString> nsTag;
    nsTag.attach([[NSString alloc] initWithBytes:tag length:sizeof(wchar_t) * wcslen(tag) encoding:getWcharEncoding()]);

    StrongId<NSString> nsFormat;
    nsFormat.attach([[NSString alloc] initWithBytes:format length:sizeof(wchar_t) * wcslen(format) encoding:getWcharEncoding()]);

    NSString* formatString = [NSString stringWithFormat:@"[%@] %@", static_cast<NSString*>(nsTag), static_cast<NSString*>(nsFormat)];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}
