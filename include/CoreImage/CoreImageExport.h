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

#ifndef COREIMAGE_IMPEXP
#define COREIMAGE_IMPEXP __declspec(dllimport)
#endif

#ifndef COREIMAGE_EXPORT
#ifdef __cplusplus
#define COREIMAGE_EXPORT COREIMAGE_IMPEXP extern "C"
#define COREIMAGE_EXPORT_CLASS COREIMAGE_IMPEXP
#else
#define COREIMAGE_EXPORT COREIMAGE_IMPEXP extern
#define COREIMAGE_EXPORT_CLASS COREIMAGE_IMPEXP
#endif
#endif

#ifndef COREIMAGE_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREIMAGE_EXTERNC_BEGIN extern "C" {
#define COREIMAGE_EXTERNC_END }
#else
#define COREIMAGE_EXTERNC_BEGIN
#define COREIMAGE_EXTERNC_END
#endif
#endif