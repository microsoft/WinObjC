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

#ifndef HEALTHKIT_IMPEXP
#define HEALTHKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef HEALTHKIT_EXPORT
#ifdef __cplusplus
#define HEALTHKIT_EXPORT HEALTHKIT_IMPEXP extern "C"
#define HEALTHKIT_EXPORT_CLASS HEALTHKIT_IMPEXP
#else
#define HEALTHKIT_EXPORT HEALTHKIT_IMPEXP extern
#define HEALTHKIT_EXPORT_CLASS HEALTHKIT_IMPEXP
#endif
#endif

#ifndef HEALTHKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define HEALTHKIT_EXTERNC_BEGIN extern "C" {
#define HEALTHKIT_EXTERNC_END }
#else
#define HEALTHKIT_EXTERNC_BEGIN
#define HEALTHKIT_EXTERNC_END
#endif
#endif
