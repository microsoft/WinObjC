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

#ifndef COREVIDEO_IMPEXP
#define COREVIDEO_IMPEXP __declspec(dllimport)
#endif

#ifndef COREVIDEO_EXPORT
#ifdef __cplusplus
#define COREVIDEO_EXPORT COREVIDEO_IMPEXP extern "C"
#define COREVIDEO_EXPORT_CLASS COREVIDEO_IMPEXP
#else
#define COREVIDEO_EXPORT COREVIDEO_IMPEXP extern
#define COREVIDEO_EXPORT_CLASS COREVIDEO_IMPEXP
#endif
#endif

#ifndef COREVIDEO_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREVIDEO_EXTERNC_BEGIN extern "C" {
#define COREVIDEO_EXTERNC_END }
#else
#define COREVIDEO_EXTERNC_BEGIN
#define COREVIDEO_EXTERNC_END
#endif
#endif
