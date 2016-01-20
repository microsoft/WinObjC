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

#ifndef __Require_Quiet
#define __Require_Quiet(assertion, exceptionLabel) \
    do {                                           \
        if (__builtin_expect(!(assertion), 0)) {   \
            goto exceptionLabel;                   \
        }                                          \
    } while (0)
#endif

#ifndef __Require_noErr_Quiet
#define __Require_noErr_Quiet(errorCode, exceptionLabel) \
    do {                                                 \
        if (__builtin_expect(0 != (errorCode), 0)) {     \
            goto exceptionLabel;                         \
        }                                                \
    } while (0)
#endif