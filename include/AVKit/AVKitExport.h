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

#ifndef AVKIT_IMPEXP
#define AVKIT_IMPEXP __declspec(dllimport)
#endif

#ifndef AVKIT_EXPORT
#ifdef __cplusplus
#define AVKIT_EXPORT AVKIT_IMPEXP extern "C"
#define AVKIT_EXPORT_CLASS AVKIT_IMPEXP
#else
#define AVKIT_EXPORT AVKIT_IMPEXP extern
#define AVKIT_EXPORT_CLASS AVKIT_IMPEXP
#endif
#endif

#ifndef AVKIT_EXTERNC_BEGIN
#if defined(__cplusplus)
#define AVKIT_EXTERNC_BEGIN extern "C" {
#define AVKIT_EXTERNC_END }
#else
#define AVKIT_EXTERNC_BEGIN
#define AVKIT_EXTERNC_END
#endif
#endif