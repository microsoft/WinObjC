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

#ifndef COREMEDIA_IMPEXP
#define COREMEDIA_IMPEXP __declspec(dllimport)
#endif

#ifndef COREMEDIA_EXPORT
#ifdef __cplusplus
#define COREMEDIA_EXPORT COREMEDIA_IMPEXP extern "C"
#define COREMEDIA_EXPORT_CLASS COREMEDIA_IMPEXP
#else
#define COREMEDIA_EXPORT COREMEDIA_IMPEXP extern
#define COREMEDIA_EXPORT_CLASS COREMEDIA_IMPEXP
#endif
#endif

#ifndef COREMEDIA_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREMEDIA_EXTERNC_BEGIN extern "C" {
#define COREMEDIA_EXTERNC_END }
#else
#define COREMEDIA_EXTERNC_BEGIN
#define COREMEDIA_EXTERNC_END
#endif
#endif