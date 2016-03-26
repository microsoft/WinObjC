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

#import "Starboard.h"
#import "NSLogging.h"
#import "LoggingNative.h"
#import "NSStringInternal.h"

static const wchar_t* g_TraceFormat = L"%ws";

void NSTraceVerbose(const wchar_t* tag, NSString* format, ...) {
    va_list list;
    va_start(list, format);
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    TraceVerbose(tag, g_TraceFormat, (const wchar_t*)[formattedString _rawTerminatedCharacters]);
    va_end(list);
}

void NSTraceInfo(const wchar_t* tag, NSString* format, ...) {
    va_list list;
    va_start(list, format);
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    TraceInfo(tag, g_TraceFormat, (const wchar_t*)[formattedString _rawTerminatedCharacters]);
    va_end(list);
}

void NSTraceWarning(const wchar_t* tag, NSString* format, ...) {
    va_list list;
    va_start(list, format);
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    TraceWarning(tag, g_TraceFormat, (const wchar_t*)[formattedString _rawTerminatedCharacters]);
    va_end(list);
}

void NSTraceError(const wchar_t* tag, NSString* format, ...) {
    va_list list;
    va_start(list, format);
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    TraceError(tag, g_TraceFormat, (const wchar_t*)[formattedString _rawTerminatedCharacters]);
    va_end(list);
}

void NSTraceCritical(const wchar_t* tag, NSString* format, ...) {
    va_list list;
    va_start(list, format);
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    TraceCritical(tag, g_TraceFormat, (const wchar_t*)[formattedString _rawTerminatedCharacters]);
    va_end(list);
}
