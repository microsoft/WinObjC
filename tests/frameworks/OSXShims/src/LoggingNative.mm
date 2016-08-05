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
#import <Foundation/NSString.h>

#import <cstdarg>

void TraceVerbose(const wchar_t* tag, const wchar_t* format, ...) {
    NSString* formatString = [NSString stringWithFormat:@"[%ls] %ls", tag, format];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceInfo(const wchar_t* tag, const wchar_t* format, ...) {
    NSString* formatString = [NSString stringWithFormat:@"[%ls] %ls", tag, format];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceWarning(const wchar_t* tag, const wchar_t* format, ...) {
    NSString* formatString = [NSString stringWithFormat:@"[%ls] %ls", tag, format];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceError(const wchar_t* tag, const wchar_t* format, ...) {
    NSString* formatString = [NSString stringWithFormat:@"[%ls] %ls", tag, format];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}

void TraceCritical(const wchar_t* tag, const wchar_t* format, ...) {
    NSString* formatString = [NSString stringWithFormat:@"[%ls] %ls", tag, format];
    va_list varArgs;
    va_start(varArgs, format);
    NSLogv(formatString, varArgs);
    va_end(varArgs);
}
