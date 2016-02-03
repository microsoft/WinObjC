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

#ifndef COREAUDIO_IMPEXP
#define COREAUDIO_IMPEXP __declspec(dllimport)
#endif

#ifndef COREAUDIO_EXPORT
#ifdef __cplusplus
#define COREAUDIO_EXPORT COREAUDIO_IMPEXP extern "C"
#define COREAUDIO_EXPORT_CLASS COREAUDIO_IMPEXP
#else
#define COREAUDIO_EXPORT COREAUDIO_IMPEXP extern
#define COREAUDIO_EXPORT_CLASS COREAUDIO_IMPEXP
#endif
#endif

#ifndef COREAUDIO_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREAUDIO_EXTERNC_BEGIN extern "C" {
#define COREAUDIO_EXTERNC_END }
#else
#define COREAUDIO_EXTERNC_BEGIN
#define COREAUDIO_EXTERNC_END
#endif
#endif
